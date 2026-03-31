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
    // Exemple: "validée" -> "validÃ©e" si les octets UTF-8 sont relus en Latin-1.
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

    // Variantes accentuees et caracteres de remplacement.
    etat.replace(QChar(0x00E9), "e"); // é
    etat.replace(QChar(0x00E8), "e"); // è
    etat.replace(QChar(0x00EA), "e"); // ê
    etat.replace(QChar(0x00EB), "e"); // ë
    etat.replace(QChar(0x00E0), "a"); // à
    etat.replace(QChar(0x00E2), "a"); // â
    etat.replace(QChar(0xFFFD), "e"); // replacement char

    // Variantes mojibake frequentes.
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

// Setters
void Ccommande::setIdCommande(int id) { m_idCommande = id; }
void Ccommande::setLibelle(const QString &libelle) { m_libelle = libelle; }
void Ccommande::setDateArrivage(const QDate &date) { m_dateArrivage = date; }
void Ccommande::setDateSortie(const QDate &date) { m_dateSortie = date; }
void Ccommande::setEtat(const QString &etat) { m_etat = etat; }
void Ccommande::setQuantite(int quantite) { m_quantite = quantite; }
void Ccommande::setMontantTotal(double montant) { m_montantTotal = montant; }
void Ccommande::setIdClient(int id) { m_idClient = id; }

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
    if (!query.exec(QString("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                            "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM %1 ORDER BY ID_COMMANDE").arg(cmdTable))) {
        qDebug() << "Lecture commandes échouée:" << query.lastError().text();
        return list;
    }
    while (query.next()) {
        list.append(Ccommande(
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

    QString sql = QString("SELECT c.ID_COMMANDE, c.LIBELLE, c.DATE_ARRIVAGE, c.DATE_SORTIE, "
                          "c.ETAT, c.QUANTITE, c.MONTANT_TOTAL, c.ID_CLIENT "
                          "FROM %1 c").arg(cmdTable);

    if (!nomClient.isEmpty()) {
        if (!schema.isValid()) {
            qDebug() << "Impossible de filtrer par nom client: schéma CLIENT introuvable.";
            return results;
        }
        sql += QString(" JOIN %1 cl ON c.ID_CLIENT = cl.%2").arg(schema.table, schema.idColumn);
    }

    sql += " WHERE 1=1";

    if (debut.isValid())  sql += " AND c.DATE_ARRIVAGE >= TO_DATE(:debut, 'YYYY-MM-DD')";
    if (fin.isValid())    sql += " AND c.DATE_ARRIVAGE <= TO_DATE(:fin, 'YYYY-MM-DD')";
    if (!etat.isEmpty())  sql += " AND c.ETAT = :etat";
    if (idClient > 0)     sql += " AND c.ID_CLIENT = :idClient";
    if (!nomClient.isEmpty()) sql += QString(" AND cl.%1 LIKE :nomClient").arg(schema.nameColumn);
    if (!fournisseur.isEmpty()) sql += " AND c.LIBELLE LIKE :fournisseur";

    QSqlQuery query;
    query.prepare(sql);

    if (debut.isValid())  query.bindValue(":debut",    debut.toString("yyyy-MM-dd"));
    if (fin.isValid())    query.bindValue(":fin",      fin.toString("yyyy-MM-dd"));
    if (!etat.isEmpty())  query.bindValue(":etat",     etat);
    if (idClient > 0)     query.bindValue(":idClient", idClient);
    if (!nomClient.isEmpty()) query.bindValue(":nomClient", "%" + nomClient + "%");
    if (!fournisseur.isEmpty()) query.bindValue(":fournisseur", "%" + fournisseur + "%");

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
