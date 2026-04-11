#include "client.h"

#include <QDate>
#include <QDebug>
#include <QRegularExpression>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>

namespace {
QString normalizeToken(QString value)
{
    value = value.trimmed().toLower();
    value.replace(QChar(0x00E9), "e"); // e acute
    value.replace(QChar(0x00E8), "e"); // e grave
    value.replace(QChar(0x00EA), "e"); // e circumflex
    value.replace(QChar(0x00EB), "e"); // e diaeresis
    value.replace(QChar(0x00E0), "a"); // a grave
    value.replace(QChar(0x00E2), "a"); // a circumflex
    value.replace(QChar(0x00F9), "u"); // u grave
    value.replace(QChar(0x00FB), "u"); // u circumflex
    value.replace(QChar(0xFFFD), "e"); // replacement character
    value.remove(' ');
    value.remove('-');
    value.remove('_');
    return value;
}

bool isCheckConstraintError(const QString &errorText)
{
    const QString lowered = errorText.toLower();
    return lowered.contains("ora-02290") || lowered.contains("check constraint");
}

bool mapTypeUiToCanonical(const QString &uiType, QString *outType)
{
    if (!outType) {
        return false;
    }

    const QString token = normalizeToken(uiType);
    if (token.contains("particulier") || token.contains("beaut")) {
        *outType = "beaute";
        return true;
    }
    if (token.contains("entreprise") || token.contains("alimentaire")) {
        *outType = "alimentaire";
        return true;
    }
    return false;
}

bool mapStatutUiToCanonical(const QString &uiStatut, QString *outStatut)
{
    if (!outStatut) {
        return false;
    }

    const QString token = normalizeToken(uiStatut);
    if (token.contains("inactif") || token.contains("blacklist") || token.contains("enattente")) {
        *outStatut = "blackliste";
        return true;
    }
    if (token.contains("actif")) {
        *outStatut = "actif";
        return true;
    }
    return false;
}

QStringList typeCandidates(const QString &canonicalType)
{
    if (canonicalType == "beaute") {
        return {"beaute", QString::fromUtf8("beauté"), QString::fromLatin1("beaut\xEF\xBF\xBD")};
    }
    if (canonicalType == "alimentaire") {
        return {"alimentaire"};
    }
    return {};
}

QStringList statutCandidates(const QString &canonicalStatut)
{
    if (canonicalStatut == "actif") {
        return {"actif"};
    }
    if (canonicalStatut == "blackliste") {
        return {"blackliste", QString::fromUtf8("blacklisté"), QString::fromLatin1("blacklist\xEF\xBF\xBD")};
    }
    return {};
}
} // namespace

// Oracle DB table: CLIENT
// Columns by position: 0=ID_CLIENT, 1=NOM_CLIENT, 2=TELEPHONE(accented), 3=EMAIL,
//                      4=ADRESSE, 5=TYPE_CLIENT, 6=STATUT, 7=ID_EMPLOYE
// The TELEPHONE column has an accented name that may break over ODBC.
// Strategy: SELECT all columns and read by index; skip TELEPHONE in INSERT/UPDATE.

Client::Client(int id, QString nom, QString type, QString tel, QString email, QString statut)
{
    this->id = id;
    this->nom = nom;
    this->type = type;
    this->tel = tel;
    this->email = email;
    this->statut = statut;
}

bool Client::valider(const QString &nom, const QString &tel, const QString &email, QString *errorMessage)
{
    if (nom.trimmed().isEmpty()) {
        if (errorMessage) *errorMessage = "Le nom du client est obligatoire.";
        return false;
    }
    if (nom.trimmed().length() > 20) {
        if (errorMessage) *errorMessage = "Le nom ne doit pas depasser 20 caracteres.";
        return false;
    }

    if (!tel.trimmed().isEmpty()) {
        static const QRegularExpression reTel("^[0-9]{7,20}$");
        if (!reTel.match(tel.trimmed()).hasMatch()) {
            if (errorMessage) {
                *errorMessage = "Le numero de telephone ne doit contenir que des chiffres (7-20 caracteres).";
            }
            return false;
        }
    }

    if (!email.trimmed().isEmpty()) {
        static const QRegularExpression reEmail("^[A-Za-z0-9._%+\\-]+@[A-Za-z0-9.\\-]+\\.[A-Za-z]{2,}$");
        if (!reEmail.match(email.trimmed()).hasMatch()) {
            if (errorMessage) *errorMessage = "L'adresse email n'est pas valide.";
            return false;
        }
    }

    return true;
}

bool Client::ajouter(QString *errorMessage)
{
    QString canonicalType;
    if (!mapTypeUiToCanonical(type, &canonicalType)) {
        if (errorMessage) *errorMessage = "Type client invalide. Utilisez Particulier ou Entreprise.";
        return false;
    }

    QString canonicalStatut;
    if (!mapStatutUiToCanonical(statut, &canonicalStatut)) {
        if (errorMessage) *errorMessage = "Statut invalide. Utilisez Actif ou Inactif.";
        return false;
    }

    QSqlQuery idQuery;
    int nextId = 1;
    if (idQuery.exec("SELECT NVL(MAX(ID_CLIENT), 0) + 1 FROM CLIENT")) {
        if (idQuery.next()) {
            nextId = idQuery.value(0).toInt();
        }
    } else {
        qDebug() << "[Client] ID query error:" << idQuery.lastError().text();
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO CLIENT (ID_CLIENT, NOM_CLIENT, TELEPHONE, EMAIL, TYPE_CLIENT, STATUT) "
        "VALUES (:id, :nom, :tel, :email, :type, :statut)");

    const QStringList typeTries = typeCandidates(canonicalType);
    const QStringList statutTries = statutCandidates(canonicalStatut);

    QString lastError;
    for (const QString &typeValue : typeTries) {
        for (const QString &statutValue : statutTries) {
            query.bindValue(":id", nextId);
            query.bindValue(":nom", nom.trimmed());
            query.bindValue(":tel", tel.trimmed());
            query.bindValue(":email", email.trimmed());
            query.bindValue(":type", typeValue);
            query.bindValue(":statut", statutValue);

            if (query.exec()) {
                this->id = nextId;
                return true;
            }

            lastError = query.lastError().text();
            qDebug() << "[Client] ajouter error (" << typeValue << "," << statutValue << "):" << lastError;
            if (!isCheckConstraintError(lastError)) {
                if (errorMessage) *errorMessage = lastError;
                return false;
            }
        }
    }

    if (errorMessage) {
        *errorMessage = lastError;
    }
    return false;
}

bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE ID_CLIENT = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "[Client] supprimer error:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Client::modifier(QString *errorMessage)
{
    QString canonicalType;
    if (!mapTypeUiToCanonical(type, &canonicalType)) {
        if (errorMessage) *errorMessage = "Type client invalide. Utilisez Particulier ou Entreprise.";
        return false;
    }

    QString canonicalStatut;
    if (!mapStatutUiToCanonical(statut, &canonicalStatut)) {
        if (errorMessage) *errorMessage = "Statut invalide. Utilisez Actif ou Inactif.";
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE CLIENT SET "
        "NOM_CLIENT = :nom, TELEPHONE = :tel, EMAIL = :email, TYPE_CLIENT = :type, STATUT = :statut "
        "WHERE ID_CLIENT = :id");

    const QStringList typeTries = typeCandidates(canonicalType);
    const QStringList statutTries = statutCandidates(canonicalStatut);

    QString lastError;
    for (const QString &typeValue : typeTries) {
        for (const QString &statutValue : statutTries) {
            query.bindValue(":nom", nom.trimmed());
            query.bindValue(":tel", tel.trimmed());
            query.bindValue(":email", email.trimmed());
            query.bindValue(":type", typeValue);
            query.bindValue(":statut", statutValue);
            query.bindValue(":id", id);

            if (query.exec()) {
                return true;
            }

            lastError = query.lastError().text();
            qDebug() << "[Client] modifier error (" << typeValue << "," << statutValue << "):" << lastError;
            if (!isCheckConstraintError(lastError)) {
                if (errorMessage) *errorMessage = lastError;
                return false;
            }
        }
    }

    if (errorMessage) {
        *errorMessage = lastError;
    }
    return false;
}

QSqlQueryModel *Client::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT ORDER BY ID_CLIENT");

    if (model->lastError().isValid()) {
        qDebug() << "[Client] afficher error:" << model->lastError().text();
    }

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Telephone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID Employe"));
    return model;
}

// ==============================
// METHODES STATISTIQUES METIER
// ==============================

bool Client::getStatsSummary(ClientStatsSummary *outStats, QString *errorMessage)
{
    if (!outStats) return false;

    { QSqlQuery q;
      if (!q.exec("SELECT COUNT(*) FROM CLIENT")) {
          if (errorMessage) *errorMessage = q.lastError().text(); return false;
      }
      if (q.next()) outStats->total = q.value(0).toInt(); }

    { QSqlQuery q;
      if (q.exec("SELECT UPPER(STATUT), COUNT(*) FROM CLIENT GROUP BY UPPER(STATUT)")) {
          while (q.next()) {
              QString s = q.value(0).toString().trimmed().toLower();
              int cnt   = q.value(1).toInt();
              if (s.contains("actif") && !s.contains("blacklist")) outStats->actifs    += cnt;
              else                                                   outStats->inactifs  += cnt;
          }
      } else { qDebug() << "[Client] statut group error:" << q.lastError().text(); } }

    { QSqlQuery q;
      if (q.exec("SELECT UPPER(TYPE_CLIENT), COUNT(*) FROM CLIENT GROUP BY UPPER(TYPE_CLIENT)")) {
          while (q.next()) {
              QString t = q.value(0).toString().trimmed().toLower();
              int cnt   = q.value(1).toInt();
              if (t.contains("alimentaire") || t.contains("entreprise")) outStats->entreprises += cnt;
              else                                                         outStats->particuliers += cnt;
          }
      } else { qDebug() << "[Client] type group error:" << q.lastError().text(); } }

    { QSqlQuery q;
      if (q.exec("SELECT COUNT(*), NVL(SUM(MONTANT_TOTAL), 0) FROM COMMANDE")) {
          if (q.next()) {
              outStats->nbCommandes = q.value(0).toInt();
              outStats->caTotal     = q.value(1).toDouble();
          }
      } else { qDebug() << "[Client] commande stats error:" << q.lastError().text(); } }

    return true;
}

bool Client::getClientInfos(int idClient, ClientInfosDetail *outInfos, QString *errorMessage)
{
    if (!outInfos) return false;

    { QSqlQuery q;
      q.prepare("SELECT COUNT(*), NVL(SUM(MONTANT_TOTAL),0), NVL(AVG(MONTANT_TOTAL),0) "
                "FROM COMMANDE WHERE ID_CLIENT = :id");
      q.bindValue(":id", idClient);
      if (!q.exec()) { if (errorMessage) *errorMessage = q.lastError().text(); return false; }
      if (q.next()) {
          outInfos->nbCommandes  = q.value(0).toInt();
          outInfos->montantTotal = q.value(1).toDouble();
          outInfos->montantMoyen = q.value(2).toDouble();
      } }

    { QSqlQuery q;
      q.prepare("SELECT COUNT(*) FROM COMMANDE WHERE ID_CLIENT = :id "
                "AND DATE_SORTIE IS NULL AND UPPER(ETAT) NOT IN ('ANNULEE','ANNULÉE')");
      q.bindValue(":id", idClient);
      if (q.exec() && q.next()) outInfos->nbRetards = q.value(0).toInt(); }

    { QSqlQuery q;
      q.prepare("SELECT COUNT(*) FROM COMMANDE WHERE ID_CLIENT = :id "
                "AND (UPPER(ETAT) = 'ANNULEE' OR UPPER(ETAT) = 'ANNULÉE')");
      q.bindValue(":id", idClient);
      if (q.exec() && q.next()) outInfos->nbAnnulees = q.value(0).toInt(); }

    { QSqlQuery q;
      q.prepare("SELECT MAX(DATE_ARRIVAGE) FROM COMMANDE WHERE ID_CLIENT = :id");
      q.bindValue(":id", idClient);
      if (q.exec() && q.next()) {
          QDate d = q.value(0).toDate();
          outInfos->derniereCommande = d.isValid() ? d.toString("dd/MM/yyyy") : "Aucune";
      } }

    return true;
}

bool Client::getAlertes(QList<ClientAlerteInfo> *outAlertes, QString *errorMessage)
{
    if (!outAlertes) return false;
    outAlertes->clear();

    QSqlQuery q;
    if (!q.exec(
            "SELECT C.ID_CLIENT, C.NOM_CLIENT, COUNT(CMD.ID_COMMANDE) AS NB_RETARDS "
            "FROM CLIENT C "
            "JOIN COMMANDE CMD ON CMD.ID_CLIENT = C.ID_CLIENT "
            "WHERE CMD.DATE_SORTIE IS NULL "
            "AND UPPER(CMD.ETAT) NOT IN ('ANNULEE','ANNULÉE') "
            "GROUP BY C.ID_CLIENT, C.NOM_CLIENT "
            "ORDER BY NB_RETARDS DESC")) {
        qDebug() << "[Client] alertes query error:" << q.lastError().text();
        if (errorMessage) *errorMessage = q.lastError().text();
        return false;
    }
    while (q.next()) {
        ClientAlerteInfo a;
        a.idClient  = q.value(0).toInt();
        a.nomClient = q.value(1).toString();
        a.nbRetards = q.value(2).toInt();
        outAlertes->append(a);
    }
    return true;
}

bool Client::getCommandesDuClient(int idClient, QList<ClientCommandeInfo> *outList, QString *errorMessage)
{
    if (!outList) return false;
    outList->clear();

    QSqlQuery q;
    q.prepare("SELECT ID_COMMANDE, LIBELLE, ETAT, MONTANT_TOTAL, DATE_ARRIVAGE, DATE_SORTIE "
              "FROM COMMANDE WHERE ID_CLIENT = :id ORDER BY DATE_ARRIVAGE DESC");
    q.bindValue(":id", idClient);
    if (!q.exec()) {
        if (errorMessage) *errorMessage = q.lastError().text();
        return false;
    }
    while (q.next()) {
        ClientCommandeInfo c;
        c.idCommande   = q.value(0).toInt();
        c.libelle      = q.value(1).toString();
        c.etat         = q.value(2).toString();
        c.montant      = q.value(3).toDouble();
        QDate da = q.value(4).toDate();
        QDate ds = q.value(5).toDate();
        c.dateArrivage = da.isValid() ? da.toString("dd/MM/yyyy") : "-";
        c.dateSortie   = ds.isValid() ? ds.toString("dd/MM/yyyy") : "-";
        outList->append(c);
    }
    return true;
}
