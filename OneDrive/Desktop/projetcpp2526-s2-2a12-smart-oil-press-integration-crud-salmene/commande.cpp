#include "commande.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QStringList>
#include <QDate>
#include <QRegularExpression>
#include <QSet>

// ==============================
// CCOMMANDE IMPLEMENTATION
// ==============================
namespace {
struct ClientSchema {
    QString table;
    QString idColumn;
    QString nameColumn;

    bool isValid() const
    {
        return !table.isEmpty() && !idColumn.isEmpty();
    }
};

ClientSchema resolveClientSchema()
{
    const QStringList candidateTables = { "CLIENT", "SMARTOIL.CLIENT" };
    for (const QString &tableName : candidateTables) {
        QSqlQuery probe;
        if (!probe.exec(QString("SELECT * FROM %1 WHERE 1=0").arg(tableName))) {
            continue;
        }

        const QSqlRecord rec = probe.record();
        const bool hasIdClient = rec.indexOf("ID_CLIENT") >= 0;
        const bool hasId = rec.indexOf("ID") >= 0;
        const bool hasNomClient = rec.indexOf("NOM_CLIENT") >= 0;
        const bool hasNom = rec.indexOf("NOM") >= 0;

        if (hasIdClient || hasId) {
            ClientSchema schema;
            schema.table = tableName;
            schema.idColumn = hasIdClient ? "ID_CLIENT" : "ID";
            schema.nameColumn = hasNomClient ? "NOM_CLIENT" : (hasNom ? "NOM" : schema.idColumn);
            return schema;
        }
    }

    return {};
}

QString resolveCommandeTable()
{
    const QStringList candidateTables = { "COMMANDE", "COMMENDE", "SMARTOIL.COMMANDE", "SMARTOIL.COMMENDE" };
    for (const QString &tableName : candidateTables) {
        QSqlQuery probe;
        if (probe.exec(QString("SELECT * FROM %1 WHERE 1=0").arg(tableName))) {
            return tableName;
        }
    }
    return {};
}

void splitOwnerAndTable(const QString &qualifiedName, QString *owner, QString *table)
{
    const QStringList parts = qualifiedName.split('.');
    if (parts.size() == 2) {
        if (owner) *owner = parts[0].trimmed().toUpper();
        if (table) *table = parts[1].trimmed().toUpper();
    } else {
        if (owner) owner->clear();
        if (table) *table = qualifiedName.trimmed().toUpper();
    }
}

QStringList dedupPreserveOrder(const QStringList &values)
{
    QStringList out;
    QSet<QString> seen;
    for (const QString &v : values) {
        const QString t = v.trimmed();
        if (t.isEmpty() || seen.contains(t)) {
            continue;
        }
        seen.insert(t);
        out.append(t);
    }
    return out;
}

QStringList extractQuotedValues(const QString &condition)
{
    QStringList values;
    QRegularExpression re("'((?:''|[^'])*)'");
    QRegularExpressionMatchIterator it = re.globalMatch(condition);
    while (it.hasNext()) {
        QString v = it.next().captured(1);
        v.replace("''", "'");
        values.append(v);
    }
    return values;
}

QString latin1MojibakeOfUtf8(const QString &properUtf8)
{
    return QString::fromLatin1(properUtf8.toUtf8());
}

QStringList getEtatValuesFromConstraint(const QString &cmdTable)
{
    QString owner;
    QString table;
    splitOwnerAndTable(cmdTable, &owner, &table);

    QStringList conditions;

    {
        QSqlQuery q;
        q.prepare("SELECT uc.SEARCH_CONDITION_VC "
                  "FROM USER_CONSTRAINTS uc "
                  "JOIN USER_CONS_COLUMNS ucc ON uc.CONSTRAINT_NAME = ucc.CONSTRAINT_NAME "
                  "WHERE uc.TABLE_NAME = :table "
                  "AND uc.CONSTRAINT_TYPE = 'C' "
                  "AND ucc.COLUMN_NAME = 'ETAT'");
        q.bindValue(":table", table);
        if (q.exec()) {
            while (q.next()) {
                conditions.append(q.value(0).toString());
            }
        }
    }

    if (conditions.isEmpty() && !owner.isEmpty()) {
        QSqlQuery q;
        q.prepare("SELECT ac.SEARCH_CONDITION_VC "
                  "FROM ALL_CONSTRAINTS ac "
                  "JOIN ALL_CONS_COLUMNS acc "
                  "ON ac.OWNER = acc.OWNER AND ac.CONSTRAINT_NAME = acc.CONSTRAINT_NAME "
                  "WHERE ac.OWNER = :owner "
                  "AND ac.TABLE_NAME = :table "
                  "AND ac.CONSTRAINT_TYPE = 'C' "
                  "AND acc.COLUMN_NAME = 'ETAT'");
        q.bindValue(":owner", owner);
        q.bindValue(":table", table);
        if (q.exec()) {
            while (q.next()) {
                conditions.append(q.value(0).toString());
            }
        }
    }

    QStringList etats;
    for (const QString &condition : conditions) {
        etats.append(extractQuotedValues(condition));
    }
    return dedupPreserveOrder(etats);
}

QString normalizedEtatInternal(QString etat)
{
    etat = etat.trimmed().toLower();

    etat.replace(QChar(0x00E9), "e");
    etat.replace(QChar(0x00E8), "e");
    etat.replace(QChar(0x00EA), "e");
    etat.replace(QChar(0x00EB), "e");
    etat.replace(QChar(0x00E0), "a");
    etat.replace(QChar(0x00E2), "a");
    etat.replace(QChar(0xFFFD), "e");

    etat.replace(QString::fromLatin1("\xC3\xA9"), "e");
    etat.replace(QString::fromLatin1("\xC3\xA8"), "e");
    etat.replace(QString::fromLatin1("\xC3\xAA"), "e");
    etat.replace(QString::fromLatin1("\xC3\xAB"), "e");
    etat.replace(QString::fromLatin1("\xC3\xA0"), "a");
    etat.replace(QString::fromLatin1("\xC3\xA2"), "a");
    etat.replace(QString::fromLatin1("\xEF\xBF\xBD"), "e");

    if (etat.contains("cours")) return "en cours";
    if (etat.contains("valid")) return "validee";
    if (etat.contains("pret"))  return "prete";
    if (etat.contains("annul")) return "annulee";
    return etat.simplified();
}

QStringList fallbackEtatCandidatesForKey(const QString &key)
{
    const QString vValidee = QStringLiteral("valid") + QChar(0x00E9) + "e";
    const QString vPrete   = QStringLiteral("pr") + QChar(0x00EA) + "te";
    const QString vAnnulee = QStringLiteral("annul") + QChar(0x00E9) + "e";
    const QString vValideeRep = QStringLiteral("valid") + QChar(0xFFFD) + "e";
    const QString vPreteRep   = QStringLiteral("pr") + QChar(0xFFFD) + "te";
    const QString vAnnuleeRep = QStringLiteral("annul") + QChar(0xFFFD) + "e";

    if (key == "en cours") {
        return {"en cours"};
    }
    if (key == "validee") {
        return {"validee", vValidee, latin1MojibakeOfUtf8(vValidee),
                vValideeRep, latin1MojibakeOfUtf8(vValideeRep)};
    }
    if (key == "prete") {
        return {"prete", vPrete, latin1MojibakeOfUtf8(vPrete),
                vPreteRep, latin1MojibakeOfUtf8(vPreteRep)};
    }
    if (key == "annulee") {
        return {"annulee", vAnnulee, latin1MojibakeOfUtf8(vAnnulee),
                vAnnuleeRep, latin1MojibakeOfUtf8(vAnnuleeRep)};
    }
    return {};
}

bool isChk1Violation(const QSqlError &error)
{
    const QString text = error.text().toUpper();
    return text.contains("ORA-02290") && text.contains("CHK1");
}
}

Ccommande::Ccommande()
    : m_idCommande(0)
    , m_quantite(0)
    , m_montantTotal(0.0)
    , m_idClient(0)
    , m_seulTemperature(25.0)
    , m_temperature(0.0f)
    , m_humidite(0.0f)
{
}

Ccommande::Ccommande(int idCommande, const QString &libelle, const QDate &dateArrivage,
                     const QDate &dateSortie, const QString &etat, int quantite,
                     double montantTotal, int idClient)
    : m_idCommande(idCommande)
    , m_libelle(libelle)
    , m_dateArrivage(dateArrivage)
    , m_dateSortie(dateSortie)
    , m_etat(etat)
    , m_quantite(quantite)
    , m_montantTotal(montantTotal)
    , m_idClient(idClient)
    , m_seulTemperature(25.0)
    , m_temperature(0.0f)
    , m_humidite(0.0f)
{
}

// Getters
int Ccommande::getIdCommande() const { return m_idCommande; }
QString Ccommande::getLibelle() const { return m_libelle; }
QDate Ccommande::getDateArrivage() const { return m_dateArrivage; }
QDate Ccommande::getDateSortie() const { return m_dateSortie; }
QString Ccommande::getEtat() const { return m_etat; }
int Ccommande::getQuantite() const { return m_quantite; }
double Ccommande::getMontantTotal() const { return m_montantTotal; }
int Ccommande::getIdClient() const { return m_idClient; }
double Ccommande::getSeulTemperature() const { return m_seulTemperature; }
float Ccommande::getTemperature() const { return m_temperature; }
float Ccommande::getHumidite() const { return m_humidite; }
QString Ccommande::getAlerte() const { return m_alerte; }
QString Ccommande::getConditions() const { return m_conditions; }

// Setters
void Ccommande::setIdCommande(int id) { m_idCommande = id; }
void Ccommande::setLibelle(const QString &libelle) { m_libelle = libelle; }
void Ccommande::setDateArrivage(const QDate &date) { m_dateArrivage = date; }
void Ccommande::setDateSortie(const QDate &date) { m_dateSortie = date; }
void Ccommande::setEtat(const QString &etat) { m_etat = etat; }
void Ccommande::setQuantite(int quantite) { m_quantite = quantite; }
void Ccommande::setMontantTotal(double montant) { m_montantTotal = montant; }
void Ccommande::setIdClient(int id) { m_idClient = id; }
void Ccommande::setSeulTemperature(double seul) 
{ 
    if (seul >= 0.0) { 
        m_seulTemperature = seul; 
        qDebug() << "[Ccommande] Temperature threshold set to" << seul << "°C"; 
    } else { 
        qDebug() << "[Ccommande] Invalid temperature threshold" << seul << ", keeping default 25°C"; 
    } 
}
void Ccommande::setTemperature(float temp) { m_temperature = temp; }
void Ccommande::setHumidite(float humid) { m_humidite = humid; }
void Ccommande::setAlerte(const QString &alerte) { m_alerte = alerte; }
void Ccommande::setConditions(const QString &conditions) { m_conditions = conditions; }

QString Ccommande::normalizeEtatKey(const QString &etat)
{
    return normalizedEtatInternal(etat);
}

QStringList Ccommande::getEtatCandidates(const QString &etatInput)
{
    const QString key = normalizedEtatInternal(etatInput);
    QStringList candidates;

    const QString cmdTable = resolveCommandeTable();
    if (!cmdTable.isEmpty()) {
        const QStringList fromConstraint = getEtatValuesFromConstraint(cmdTable);
        for (const QString &value : fromConstraint) {
            if (normalizedEtatInternal(value) == key) {
                candidates.append(value);
            }
        }
    }

    candidates.append(fallbackEtatCandidatesForKey(key));
    if (!etatInput.trimmed().isEmpty()) {
        candidates.append(etatInput.trimmed());
    }
    return dedupPreserveOrder(candidates);
}

bool Ccommande::ajouter(const Ccommande &cmd)
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return false;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare(QString("SELECT COUNT(*) FROM %1 WHERE ID_COMMANDE = :id").arg(cmdTable));
    checkQuery.bindValue(":id", cmd.getIdCommande());
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Erreur vérification ID:" << checkQuery.lastError().text();
        return false;
    }

    bool exists = (checkQuery.value(0).toInt() > 0);
    QSqlQuery query;

    if (exists) {
        query.prepare(QString("UPDATE %1 SET "
                      "LIBELLE = :libelle, "
                      "DATE_ARRIVAGE = TO_DATE(:dateArr, 'YYYY-MM-DD'), "
                      "DATE_SORTIE = TO_DATE(:dateSort, 'YYYY-MM-DD'), "
                      "ETAT = :etat, "
                      "QUANTITE = :qte, "
                      "MONTANT_TOTAL = :montant, "
                      "ID_CLIENT = :idClient "
                      "WHERE ID_COMMANDE = :id").arg(cmdTable));
    } else {
        query.prepare(QString("INSERT INTO %1 "
                      "(ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, QUANTITE, MONTANT_TOTAL, ID_CLIENT) "
                      "VALUES (:id, :libelle, TO_DATE(:dateArr,'YYYY-MM-DD'), TO_DATE(:dateSort,'YYYY-MM-DD'), :etat, :qte, :montant, :idClient)")
                          .arg(cmdTable));
    }

    query.bindValue(":id",       cmd.getIdCommande());
    query.bindValue(":libelle",  cmd.getLibelle());
    query.bindValue(":dateArr",  cmd.getDateArrivage().toString("yyyy-MM-dd"));
    query.bindValue(":dateSort", cmd.getDateSortie().toString("yyyy-MM-dd"));
    query.bindValue(":qte",      cmd.getQuantite());
    query.bindValue(":montant",  cmd.getMontantTotal());
    query.bindValue(":idClient", cmd.getIdClient());

    const QStringList etatCandidates = Ccommande::getEtatCandidates(cmd.getEtat());
    QSqlError lastError;
    for (const QString &etatValue : etatCandidates) {
        query.bindValue(":etat", etatValue);
        if (query.exec()) {
            return true;
        }
        lastError = query.lastError();
        if (!isChk1Violation(lastError)) {
            break;
        }
    }

    qDebug() << "Erreur ajouter/modifier commande:" << lastError.text()
             << "| ETAT source:" << cmd.getEtat()
             << "| ETAT candidats testés:" << etatCandidates;
    return false;
}

bool Ccommande::supprimer(int id)
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return false;
    }

    QSqlQuery query;
    query.prepare(QString("DELETE FROM %1 WHERE ID_COMMANDE = :id").arg(cmdTable));
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur suppression commande:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Ccommande::modifier(int id, const Ccommande &newCmd)
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return false;
    }

    QSqlQuery query;
    query.prepare(QString("UPDATE %1 SET "
                  "LIBELLE = :libelle, "
                  "DATE_ARRIVAGE = TO_DATE(:dateArr, 'YYYY-MM-DD'), "
                  "DATE_SORTIE = TO_DATE(:dateSort, 'YYYY-MM-DD'), "
                  "ETAT = :etat, "
                  "QUANTITE = :qte, "
                  "MONTANT_TOTAL = :montant, "
                  "ID_CLIENT = :idClient "
                  "WHERE ID_COMMANDE = :id").arg(cmdTable));

    query.bindValue(":libelle",  newCmd.getLibelle());
    query.bindValue(":dateArr",  newCmd.getDateArrivage().toString("yyyy-MM-dd"));
    query.bindValue(":dateSort", newCmd.getDateSortie().toString("yyyy-MM-dd"));
    query.bindValue(":qte",      newCmd.getQuantite());
    query.bindValue(":montant",  newCmd.getMontantTotal());
    query.bindValue(":idClient", newCmd.getIdClient());
    query.bindValue(":id",       id);

    const QStringList etatCandidates = Ccommande::getEtatCandidates(newCmd.getEtat());
    QSqlError lastError;
    for (const QString &etatValue : etatCandidates) {
        query.bindValue(":etat", etatValue);
        if (query.exec()) {
            return true;
        }
        lastError = query.lastError();
        if (!isChk1Violation(lastError)) {
            break;
        }
    }

    qDebug() << "Erreur modification commande:" << lastError.text()
             << "| ETAT source:" << newCmd.getEtat()
             << "| ETAT candidats testés:" << etatCandidates;
    return false;
}

Ccommande Ccommande::getById(int id)
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return Ccommande();
    }

    QSqlQuery query;
    query.prepare(QString("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                          "QUANTITE, MONTANT_TOTAL, ID_CLIENT, TEMPERATURE_STORAGE, HUMIDITY_STORAGE, QUALITY_ALERT, STORAGE_CONDITIONS FROM %1 WHERE ID_COMMANDE = :id").arg(cmdTable));
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        Ccommande cmd(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        );
        cmd.setTemperature(query.value(8).toFloat());
        cmd.setHumidite(query.value(9).toFloat());
        cmd.setAlerte(query.value(10).toString());
        cmd.setConditions(query.value(11).toString());
        return cmd;
    }

    // Fallback if the extended columns do not exist yet
    query.clear();
    query.prepare(QString("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                          "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM %1 WHERE ID_COMMANDE = :id").arg(cmdTable));
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return Ccommande(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        );
    }
    return Ccommande();
}

QVector<Ccommande> Ccommande::getAll()
{
    QVector<Ccommande> list;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return list;
    }

    QSqlQuery query;
    
    // Try with all columns first
    if (query.exec(QString("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                           "QUANTITE, MONTANT_TOTAL, ID_CLIENT, TEMPERATURE_STORAGE, HUMIDITY_STORAGE, QUALITY_ALERT, STORAGE_CONDITIONS FROM %1 ORDER BY ID_COMMANDE").arg(cmdTable))) {
        while (query.next()) {
            Ccommande cmd(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toDate(),
                query.value(3).toDate(),
                query.value(4).toString(),
                query.value(5).toInt(),
                query.value(6).toDouble(),
                query.value(7).toInt()
            );
            cmd.setTemperature(query.value(8).toFloat());
            cmd.setHumidite(query.value(9).toFloat());
            cmd.setAlerte(query.value(10).toString());
            cmd.setConditions(query.value(11).toString());
            list.append(cmd);
        }
        return list;
    }
    
    // Try with partial columns
    query.clear();
    if (query.exec(QString("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                           "QUANTITE, MONTANT_TOTAL, ID_CLIENT, TEMPERATURE_STORAGE, HUMIDITY_STORAGE FROM %1 ORDER BY ID_COMMANDE").arg(cmdTable))) {
        while (query.next()) {
            Ccommande cmd(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toDate(),
                query.value(3).toDate(),
                query.value(4).toString(),
                query.value(5).toInt(),
                query.value(6).toDouble(),
                query.value(7).toInt()
            );
            cmd.setTemperature(query.value(8).toFloat());
            cmd.setHumidite(query.value(9).toFloat());
            list.append(cmd);
        }
        return list;
    }
    
    // Fallback: only base columns
    query.clear();
    if (!query.exec(QString("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                            "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM %1 ORDER BY ID_COMMANDE").arg(cmdTable))) {
        qDebug() << "Lecture commandes échouée:" << query.lastError().text();
        return list;
    }
    
    while (query.next()) {
        Ccommande cmd(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        );
        list.append(cmd);
    }
    return list;
}

QVector<QPair<int, QString>> Ccommande::getClientList()
{
    QVector<QPair<int, QString>> clients;
    const ClientSchema schema = resolveClientSchema();
    if (!schema.isValid()) {
        qDebug() << "Schéma CLIENT introuvable (table/colonnes).";
        return clients;
    }

    QSqlQuery q;
    const QString sql = QString("SELECT %1, %2 FROM %3 ORDER BY %2")
                            .arg(schema.idColumn, schema.nameColumn, schema.table);
    if (!q.exec(sql)) {
        qDebug() << "Lecture liste clients échouée:" << q.lastError().text();
        return clients;
    }

    while (q.next()) {
        clients.append(qMakePair(q.value(0).toInt(), q.value(1).toString()));
    }
    return clients;
}

bool Ccommande::clientExists(int idClient)
{
    const ClientSchema schema = resolveClientSchema();
    if (!schema.isValid()) {
        qDebug() << "Schéma CLIENT introuvable pour clientExists.";
        return false;
    }

    QSqlQuery q;
    q.prepare(QString("SELECT COUNT(*) FROM %1 WHERE %2 = :id")
                  .arg(schema.table, schema.idColumn));
    q.bindValue(":id", idClient);
    if (q.exec() && q.next()) {
        return q.value(0).toInt() > 0;
    }
    qDebug() << "Vérification existence client échouée:" << q.lastError().text();
    return false;
}

QVector<int> Ccommande::getClientIds()
{
    QVector<int> ids;
    const ClientSchema schema = resolveClientSchema();
    if (!schema.isValid()) {
        qDebug() << "Schéma CLIENT introuvable pour getClientIds.";
        return ids;
    }

    QSqlQuery q;
    const QString sql = QString("SELECT %1 FROM %2 ORDER BY %1")
                            .arg(schema.idColumn, schema.table);
    if (!q.exec(sql)) {
        qDebug() << "Lecture IDs clients échouée:" << q.lastError().text();
        return ids;
    }

    while (q.next()) {
        ids.append(q.value(0).toInt());
    }
    return ids;
}

QVector<Ccommande> Ccommande::rechercher(const QDate &debut, const QDate &fin,
                                         const QString &etat, int idClient,
                                         const QString &nomClient,
                                         const QString &fournisseur)
{
    QVector<Ccommande> results;
    const ClientSchema schema = resolveClientSchema();
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return results;
    }

    QString baseSql = QString("SELECT c.ID_COMMANDE, c.LIBELLE, c.DATE_ARRIVAGE, c.DATE_SORTIE, "
                              "c.ETAT, c.QUANTITE, c.MONTANT_TOTAL, c.ID_CLIENT "
                              "FROM %1 c").arg(cmdTable);

    QString joinSql = "";
    if (!nomClient.isEmpty()) {
        if (!schema.isValid()) {
            qDebug() << "Impossible de filtrer par nom client: schéma CLIENT introuvable.";
            return results;
        }
        joinSql = QString(" JOIN %1 cl ON c.ID_CLIENT = cl.%2").arg(schema.table, schema.idColumn);
    }

    QString whereSql = " WHERE 1=1";
    if (debut.isValid())  whereSql += " AND c.DATE_ARRIVAGE >= TO_DATE(:debut, 'YYYY-MM-DD')";
    if (fin.isValid())    whereSql += " AND c.DATE_ARRIVAGE <= TO_DATE(:fin, 'YYYY-MM-DD')";
    if (!etat.isEmpty())  whereSql += " AND c.ETAT = :etat";
    if (idClient > 0)     whereSql += " AND c.ID_CLIENT = :idClient";
    if (!nomClient.isEmpty()) whereSql += QString(" AND cl.%1 LIKE :nomClient").arg(schema.nameColumn);
    if (!fournisseur.isEmpty()) whereSql += " AND c.LIBELLE LIKE :fournisseur";

    auto bindValues = [&](QSqlQuery& q) {
        if (debut.isValid())  q.bindValue(":debut",    debut.toString("yyyy-MM-dd"));
        if (fin.isValid())    q.bindValue(":fin",      fin.toString("yyyy-MM-dd"));
        if (!etat.isEmpty())  q.bindValue(":etat",     etat);
        if (idClient > 0)     q.bindValue(":idClient", idClient);
        if (!nomClient.isEmpty()) q.bindValue(":nomClient", "%" + nomClient + "%");
        if (!fournisseur.isEmpty()) q.bindValue(":fournisseur", "%" + fournisseur + "%");
    };

    QSqlQuery query;
    // Try with all columns
    QString sqlFull = QString("SELECT c.ID_COMMANDE, c.LIBELLE, c.DATE_ARRIVAGE, c.DATE_SORTIE, "
                              "c.ETAT, c.QUANTITE, c.MONTANT_TOTAL, c.ID_CLIENT, "
                              "c.TEMPERATURE_STORAGE, c.HUMIDITY_STORAGE, c.QUALITY_ALERT, c.STORAGE_CONDITIONS "
                              "FROM %1 c").arg(cmdTable) + joinSql + whereSql;
    
    query.prepare(sqlFull);
    bindValues(query);

    if (query.exec()) {
        while (query.next()) {
            Ccommande cmd(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toDate(),
                query.value(3).toDate(),
                query.value(4).toString(),
                query.value(5).toInt(),
                query.value(6).toDouble(),
                query.value(7).toInt()
            );
            cmd.setTemperature(query.value(8).toFloat());
            cmd.setHumidite(query.value(9).toFloat());
            cmd.setAlerte(query.value(10).toString());
            cmd.setConditions(query.value(11).toString());
            results.append(cmd);
        }
        return results;
    }

    // Fallback if the extended columns do not exist
    query.clear();
    QString sqlBase = baseSql + joinSql + whereSql;
    query.prepare(sqlBase);
    bindValues(query);

    if (query.exec()) {
        while (query.next()) {
            results.append(Ccommande(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toDate(),
                query.value(3).toDate(),
                query.value(4).toString(),
                query.value(5).toInt(),
                query.value(6).toDouble(),
                query.value(7).toInt()
            ));
        }
    } else {
        qDebug() << "Erreur recherche avancée:" << query.lastError().text();
    }
    return results;
}

int Ccommande::getTotalCommandes()
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return 0;
    }

    QSqlQuery query(QString("SELECT COUNT(*) FROM %1").arg(cmdTable));
    if (query.next()) return query.value(0).toInt();
    return 0;
}

double Ccommande::getMontantTotalGlobal()
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return 0.0;
    }

    QSqlQuery query(QString("SELECT SUM(MONTANT_TOTAL) FROM %1").arg(cmdTable));
    if (query.next()) return query.value(0).toDouble();
    return 0.0;
}

double Ccommande::getMoyenneMontant()
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return 0.0;
    }

    QSqlQuery query(QString("SELECT AVG(MONTANT_TOTAL) FROM %1").arg(cmdTable));
    if (query.next()) return query.value(0).toDouble();
    return 0.0;
}

QMap<QString, double> Ccommande::getMontantParMois()
{
    QMap<QString, double> moisMap;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return moisMap;
    }

    QSqlQuery query(QString("SELECT TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') AS MOIS, SUM(MONTANT_TOTAL) "
                            "FROM %1 GROUP BY TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') ORDER BY MOIS").arg(cmdTable));
    while (query.next()) {
        moisMap.insert(query.value(0).toString(), query.value(1).toDouble());
    }
    return moisMap;
}

double Ccommande::getSeulByCommandeId(int idCommande, bool *ok)
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        if (ok) *ok = false;
        qDebug() << "[Ccommande] Table COMMANDE/COMMENDE not found";
        return 25.0;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT SEUL FROM %1 WHERE ID_COMMANDE = :id").arg(cmdTable));
    query.bindValue(":id", idCommande);

    if (!query.exec()) {
        QSqlQuery addColumn;
        if (addColumn.exec(QString("ALTER TABLE %1 ADD SEUL NUMBER(5,2) DEFAULT 25.0").arg(cmdTable))) {
            qDebug() << "[Ccommande] SEUL column added successfully";
        }
        if (ok) *ok = false;
        return 25.0;
    }

    if (query.next()) {
        QVariant value = query.value(0);
        if (!value.isNull()) {
            if (ok) *ok = true;
            return value.toDouble();
        }
    }

    if (ok) *ok = false;
    return 25.0;
}

bool Ccommande::setSeulByCommandeId(int idCommande, double seul)
{
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "[Ccommande] Table COMMANDE/COMMENDE not found";
        return false;
    }

    QSqlQuery checkColumn;
    if (!checkColumn.exec(QString("SELECT SEUL FROM %1 WHERE 1=0").arg(cmdTable))) {
        QSqlQuery addColumn;
        if (!addColumn.exec(QString("ALTER TABLE %1 ADD SEUL NUMBER(5,2) DEFAULT 25.0").arg(cmdTable))) {
            qDebug() << "[Ccommande] Failed to add SEUL column:" << addColumn.lastError().text();
            return false;
        }
    }

    QSqlQuery query;
    query.prepare(QString("UPDATE %1 SET SEUL = :seul WHERE ID_COMMANDE = :id").arg(cmdTable));
    query.bindValue(":seul", seul);
    query.bindValue(":id", idCommande);

    if (!query.exec()) {
        qDebug() << "[Ccommande] Failed to update SEUL:" << query.lastError().text();
        return false;
    }

    qDebug() << "[Ccommande] SEUL updated for command" << idCommande << "to" << seul;
    return true;
}

QVector<int> Ccommande::getAllCommandeIds()
{
    QVector<int> ids;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "[Ccommande] Table COMMANDE/COMMENDE not found";
        return ids;
    }

    QSqlQuery query(QString("SELECT ID_COMMANDE FROM %1 ORDER BY ID_COMMANDE ASC").arg(cmdTable));
    while (query.next()) {
        ids.append(query.value(0).toInt());
    }
    return ids;
}

QMap<QString, int> Ccommande::getNbCommandesParMois()
{
    QMap<QString, int> moisMap;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return moisMap;
    }

    QSqlQuery query(QString("SELECT TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') AS MOIS, COUNT(*) "
                            "FROM %1 GROUP BY TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') ORDER BY MOIS").arg(cmdTable));
    while (query.next()) {
        moisMap.insert(query.value(0).toString(), query.value(1).toInt());
    }
    return moisMap;
}

QMap<QString, int> Ccommande::getNbCommandesParEtat()
{
    QMap<QString, int> result;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return result;
    }

    QSqlQuery query(QString("SELECT ETAT, COUNT(*) FROM %1 GROUP BY ETAT").arg(cmdTable));
    while (query.next()) {
        result.insert(query.value(0).toString(), query.value(1).toInt());
    }
    return result;
}

QVector<QPair<QString, int>> Ccommande::getProduitsPlusCommandes(int limit)
{
    QVector<QPair<QString, int>> produits;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return produits;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT LIBELLE, SUM(QUANTITE) AS QTE_TOTALE FROM %1 "
                          "GROUP BY LIBELLE ORDER BY QTE_TOTALE DESC").arg(cmdTable));
    if (!query.exec()) {
        qDebug() << "Erreur produits plus commandés:" << query.lastError().text();
        return produits;
    }
    int count = 0;
    while (query.next() && count < limit) {
        produits.append(qMakePair(query.value(0).toString(), query.value(1).toInt()));
        ++count;
    }
    return produits;
}

QVector<QPair<QString, double>> Ccommande::getProduitsPlusRentables(int limit)
{
    QVector<QPair<QString, double>> produits;
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "Table COMMANDE/COMMENDE introuvable.";
        return produits;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT LIBELLE, SUM(MONTANT_TOTAL) AS MONTANT_TOTAL FROM %1 "
                          "GROUP BY LIBELLE ORDER BY MONTANT_TOTAL DESC").arg(cmdTable));
    if (!query.exec()) {
        qDebug() << "Erreur produits plus rentables:" << query.lastError().text();
        return produits;
    }
    int count = 0;
    while (query.next() && count < limit) {
        produits.append(qMakePair(query.value(0).toString(), query.value(1).toDouble()));
        ++count;
    }
    return produits;
}

// ============================================
// ENREGISTRER DONNÉES CAPTEUR POUR UNE COMMANDE SPÉCIFIQUE
// ============================================
bool Ccommande::enregistrerDonneesCapteur(int idCommande, float temperature, 
                                          float humidite, const QString &alerte,
                                          const QString &conditions)
{
    qDebug() << "\n[Ccommande] ========================================";
    qDebug() << "[Ccommande] enregistrerDonneesCapteur() CALLED";
    qDebug() << "[Ccommande] 🎯 ID_COMMANDE =" << idCommande;
    qDebug() << "[Ccommande] 🌡️ Température =" << temperature;
    qDebug() << "[Ccommande] 💧 Humidité =" << humidite;
    qDebug() << "[Ccommande] 🚨 Alerte =" << alerte;
    qDebug() << "[Ccommande] ========================================\n";
    
    if (idCommande <= 0) {
        qDebug() << "[Ccommande] ❌ ID_COMMANDE invalide:" << idCommande;
        return false;
    }
    
    const QString cmdTable = resolveCommandeTable();
    if (cmdTable.isEmpty()) {
        qDebug() << "[Ccommande] ❌ Table COMMANDE introuvable";
        return false;
    }
    
    qDebug() << "[Ccommande] Table cible:" << cmdTable;
    
    // Vérifier si les colonnes existent
    QSqlQuery checkCol;
    QStringList columns = {"TEMPERATURE_STORAGE", "HUMIDITY_STORAGE", "QUALITY_ALERT", "STORAGE_CONDITIONS", "LAST_SENSOR_READING"};
    
    for (const QString &col : columns) {
        QSqlQuery test;
        if (!test.exec(QString("SELECT %1 FROM %2 WHERE 1=0").arg(col, cmdTable))) {
            QString colType;
            if (col == "TEMPERATURE_STORAGE" || col == "HUMIDITY_STORAGE") colType = "NUMBER(5,2)";
            else if (col == "QUALITY_ALERT") colType = "VARCHAR2(20) DEFAULT 'NORMAL'";
            else if (col == "STORAGE_CONDITIONS") colType = "VARCHAR2(100)";
            else if (col == "LAST_SENSOR_READING") colType = "DATE";
            
            QSqlQuery alter;
            if (!alter.exec(QString("ALTER TABLE %1 ADD %2 %3").arg(cmdTable, col, colType))) {
                qDebug() << "[Ccommande] ⚠️ Impossible d'ajouter" << col << ":" << alter.lastError().text();
            } else {
                qDebug() << "[Ccommande] ✅ Colonne" << col << "ajoutée";
            }
        }
    }
    
    QSqlQuery query;
    QString updateSql = QString(
        "UPDATE %1 SET "
        "TEMPERATURE_STORAGE = :temp, "
        "HUMIDITY_STORAGE = :hum, "
        "QUALITY_ALERT = :alert, "
        "STORAGE_CONDITIONS = :conditions, "
        "LAST_SENSOR_READING = SYSDATE "
        "WHERE ID_COMMANDE = :id"
    ).arg(cmdTable);
    
    qDebug() << "[Ccommande] SQL Query:" << updateSql;
    
    query.prepare(updateSql);
    
    query.bindValue(":temp", temperature);
    query.bindValue(":hum", humidite);
    query.bindValue(":alert", alerte);
    query.bindValue(":conditions", conditions);
    query.bindValue(":id", idCommande);
    
    qDebug() << "[Ccommande] Paramètres liés:";
    qDebug() << "[Ccommande]   :temp =" << temperature;
    qDebug() << "[Ccommande]   :hum =" << humidite;
    qDebug() << "[Ccommande]   :alert =" << alerte;
    qDebug() << "[Ccommande]   :conditions =" << conditions;
    qDebug() << "[Ccommande]   :id =" << idCommande;
    
    if (!query.exec()) {
        qDebug() << "[Ccommande] ❌ ERREUR SQL pour ID" << idCommande;
        qDebug() << "[Ccommande] Erreur:" << query.lastError().text();
        return false;
    }
    
    int rowsAffected = query.numRowsAffected();
    qDebug() << "[Ccommande] ✅ UPDATE exécuté pour ID" << idCommande;
    qDebug() << "[Ccommande] 📊 Lignes affectées:" << rowsAffected;
    
    if (rowsAffected == 0) {
        qDebug() << "[Ccommande] ⚠️ ATTENTION: Aucune ligne mise à jour pour ID" << idCommande;
        qDebug() << "[Ccommande]    La commande ID" << idCommande << "N'EXISTE PAS en base!";
    } else if (rowsAffected == 1) {
        qDebug() << "[Ccommande] ✅ SUCCÈS: Exactement 1 ligne mise à jour (CORRECT)";
    } else {
        qDebug() << "[Ccommande] ⚠️ ATTENTION: " << rowsAffected << "lignes mises à jour (INCORRECT!)";
    }
    
    qDebug() << "[Ccommande] ========================================\n";
    
    return rowsAffected > 0;
}