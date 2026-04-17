#include "employe.h"

#include <QCryptographicHash>
#include <QRegularExpression>
#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>

namespace {
QString computePasswordHash(const QString &plainPassword)
{
    return QString(QCryptographicHash::hash(plainPassword.toUtf8(), QCryptographicHash::Sha256).toHex());
}

QString normalizeAllowedOrderColumn(const QString &value)
{
    const QString normalized = value.trimmed().toUpper();
    if (normalized == "SALAIRE" || normalized == "ANCIENNETE"
        || normalized == "HEURES_TRAVAIL" || normalized == "FOURNISSEURS_TRAITES") {
        return normalized;
    }
    return QString();
}

bool isSha256Hash(const QString &value)
{
    static const QRegularExpression regex("^[0-9a-fA-F]{64}$");
    return regex.match(value).hasMatch();
}

void fillEmployeDataFromQuery(const QSqlQuery &query, EmployeData *data)
{
    if (!data) {
        return;
    }

    data->idEmploye = query.value("ID_EMPLOYE").toInt();
    data->nom = query.value("NOM").toString();
    data->prenom = query.value("PRENOM").toString();
    data->age = query.value("AGE").toInt();
    data->poste = query.value("POSTE").toString();
    data->salaire = query.value("SALAIRE").toDouble();
    data->anciennete = query.value("ANCIENNETE").toInt();
    data->disponibilite = query.value("DISPONIBILITE").toString();
    data->heuresTravail = query.value("HEURES_TRAVAIL").toInt();
    data->fournisseursTraites = query.value("FOURNISSEURS_TRAITES").toInt();
    data->idEquipe = query.value("ID_EQUIPE").toString();
    data->mdp = query.value("MDP").toString();
}
}

QString EmployeRepository::hashPassword(const QString &plainPassword)
{
    return computePasswordHash(plainPassword);
}

bool EmployeRepository::authenticateByIdentity(
    const QString &identity,
    const QString &plainPassword,
    QString *outRole,
    QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("SELECT MDP, POSTE FROM EMPLOYE WHERE NOM || ' ' || PRENOM = :username");
    query.bindValue(":username", identity.trimmed());

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = "Erreur de verification de connexion.";
        }
        return false;
    }

    if (!query.next()) {
        if (errorMessage) {
            *errorMessage = "Username ou mot de passe incorrect.";
        }
        return false;
    }

    const QString dbPassword = query.value("MDP").toString().trimmed();
    const QString dbRole = query.value("POSTE").toString();

    if (query.next()) {
        if (errorMessage) {
            *errorMessage = "Identifiant ambigu. Contactez l'administrateur.";
        }
        return false;
    }

    const QString enteredHashedPassword = computePasswordHash(plainPassword);
    bool passwordOk = false;
    if (isSha256Hash(dbPassword)) {
        passwordOk = (dbPassword.compare(enteredHashedPassword, Qt::CaseInsensitive) == 0);
    } else {
        passwordOk = (dbPassword == plainPassword);
    }

    if (!passwordOk) {
        if (errorMessage) {
            *errorMessage = "Username ou mot de passe incorrect.";
        }
        return false;
    }

    if (outRole) {
        *outRole = dbRole;
    }
    return true;
}

bool EmployeRepository::equipeExists(int idEquipe, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("SELECT ID_EQUIPE FROM EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", idEquipe);
    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    const bool exists = query.next();
    if (!exists && errorMessage) {
        *errorMessage = "L'equipe avec cet ID n'existe pas.";
    }
    return exists;
}

bool EmployeRepository::isNomPrenomDisponible(
    const QString &nom,
    const QString &prenom,
    int excludeEmployeId,
    QString *errorMessage)
{
    QSqlQuery query;
    QString sql =
        "SELECT COUNT(*) FROM EMPLOYE "
        "WHERE UPPER(TRIM(NOM)) = UPPER(TRIM(:nom)) "
        "AND UPPER(TRIM(PRENOM)) = UPPER(TRIM(:prenom))";

    if (excludeEmployeId > 0) {
        sql += " AND ID_EMPLOYE <> :exclude_id";
    }

    query.prepare(sql);
    query.bindValue(":nom", nom.trimmed());
    query.bindValue(":prenom", prenom.trimmed());
    if (excludeEmployeId > 0) {
        query.bindValue(":exclude_id", excludeEmployeId);
    }

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = "Erreur SQL: " + query.lastError().text();
        }
        return false;
    }

    if (!query.next()) {
        if (errorMessage) {
            *errorMessage = "Verification d'unicite impossible.";
        }
        return false;
    }

    const int duplicates = query.value(0).toInt();
    if (duplicates > 0) {
        if (errorMessage) {
            *errorMessage = "Nom + prenom deja utilise. Choisissez un autre identifiant.";
        }
        return false;
    }

    return true;
}

bool EmployeRepository::addEmploye(
    const EmployeData &data,
    bool hasEquipe,
    int idEquipe,
    QString *errorMessage)
{
    QSqlQuery query;
    if (!hasEquipe) {
        query.prepare(
            "INSERT INTO EMPLOYE "
            "(NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, MDP) "
            "VALUES (:nom, :prenom, :age, :poste, :salaire, :anciennete, :disp, :heures, :fourn, :mdp)");
    } else {
        query.prepare(
            "INSERT INTO EMPLOYE "
            "(NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE, MDP) "
            "VALUES (:nom, :prenom, :age, :poste, :salaire, :anciennete, :disp, :heures, :fourn, :id_equipe, :mdp)");
        query.bindValue(":id_equipe", idEquipe);
    }

    query.bindValue(":nom", data.nom);
    query.bindValue(":prenom", data.prenom);
    query.bindValue(":age", data.age);
    query.bindValue(":poste", data.poste);
    query.bindValue(":salaire", data.salaire);
    query.bindValue(":anciennete", data.anciennete);
    query.bindValue(":disp", data.disponibilite);
    query.bindValue(":heures", data.heuresTravail);
    query.bindValue(":fourn", data.fournisseursTraites);
    query.bindValue(":mdp", data.mdp);

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }
    return true;
}

bool EmployeRepository::getEmployeById(int idEmploye, EmployeData *outData, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", idEmploye);

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (!query.next()) {
        if (errorMessage) {
            *errorMessage = "Aucun employe trouve avec cet ID.";
        }
        return false;
    }

    fillEmployeDataFromQuery(query, outData);
    return true;
}

bool EmployeRepository::updateEmploye(
    int idEmploye,
    const EmployeData &data,
    bool hasEquipe,
    int idEquipe,
    bool updatePassword,
    const QString &passwordHash,
    int *rowsAffected,
    QString *errorMessage)
{
    QSqlQuery query;

    QString updateSql =
        "UPDATE EMPLOYE SET NOM = :nom, PRENOM = :prenom, AGE = :age, POSTE = :poste, "
        "SALAIRE = :salaire, ANCIENNETE = :anciennete, DISPONIBILITE = :disp, "
        "HEURES_TRAVAIL = :heures, FOURNISSEURS_TRAITES = :fourn, ";

    if (hasEquipe) {
        updateSql += "ID_EQUIPE = :id_equipe";
    } else {
        updateSql += "ID_EQUIPE = NULL";
    }

    if (updatePassword) {
        updateSql += ", MDP = :mdp";
    }
    updateSql += " WHERE ID_EMPLOYE = :id";

    query.prepare(updateSql);
    query.bindValue(":id", idEmploye);
    query.bindValue(":nom", data.nom);
    query.bindValue(":prenom", data.prenom);
    query.bindValue(":age", data.age);
    query.bindValue(":poste", data.poste);
    query.bindValue(":salaire", data.salaire);
    query.bindValue(":anciennete", data.anciennete);
    query.bindValue(":disp", data.disponibilite);
    query.bindValue(":heures", data.heuresTravail);
    query.bindValue(":fourn", data.fournisseursTraites);

    if (hasEquipe) {
        query.bindValue(":id_equipe", idEquipe);
    }
    if (updatePassword) {
        query.bindValue(":mdp", passwordHash);
    }

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (rowsAffected) {
        *rowsAffected = query.numRowsAffected();
    }
    return true;
}

bool EmployeRepository::deleteEmploye(int idEmploye, int *rowsAffected, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", idEmploye);

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (rowsAffected) {
        *rowsAffected = query.numRowsAffected();
    }
    return true;
}

bool EmployeRepository::listEmployes(QList<EmployeData> *outRows, QString *errorMessage)
{
    if (!outRows) {
        if (errorMessage) {
            *errorMessage = "Parametre de sortie invalide (outRows).";
        }
        return false;
    }
    outRows->clear();

    QSqlQuery query;
    if (!query.exec(
            "SELECT ID_EMPLOYE, NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, "
            "HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE, MDP "
            "FROM EMPLOYE ORDER BY ID_EMPLOYE")) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    while (query.next()) {
        EmployeData row;
        fillEmployeDataFromQuery(query, &row);
        outRows->append(row);
    }
    return true;
}

bool EmployeRepository::filterEmployes(const EmployeFilter &filter, QList<EmployeData> *outRows, QString *errorMessage)
{
    if (!outRows) {
        if (errorMessage) {
            *errorMessage = "Parametre de sortie invalide (outRows).";
        }
        return false;
    }
    outRows->clear();

    QString sql =
        "SELECT ID_EMPLOYE, NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, "
        "HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE, MDP "
        "FROM EMPLOYE";
    QStringList whereConditions;

    if (filter.hasSearchId) {
        whereConditions << "ID_EMPLOYE = :search_id";
    }
    if (!filter.searchNom.trimmed().isEmpty()) {
        whereConditions << "UPPER(NOM) LIKE UPPER(:search_nom)";
    }
    if (filter.hasSearchIdEquipe) {
        whereConditions << "ID_EQUIPE = :search_id_equipe";
    }
    if (filter.searchSpec != "-- Tous --") {
        whereConditions << "POSTE = :search_spec";
    }

    if (!whereConditions.isEmpty()) {
        sql += " WHERE " + whereConditions.join(" AND ");
    }

    const QString safeOrderColumn = normalizeAllowedOrderColumn(filter.orderColumn);
    if (!filter.orderColumn.trimmed().isEmpty() && safeOrderColumn.isEmpty()) {
        if (errorMessage) {
            *errorMessage = "Colonne de tri non autorisee.";
        }
        return false;
    }

    if (!safeOrderColumn.isEmpty()) {
        sql += " ORDER BY " + safeOrderColumn + (filter.descending ? " DESC" : " ASC");
    } else {
        sql += " ORDER BY ID_EMPLOYE";
    }

    QSqlQuery query;
    query.prepare(sql);

    if (filter.hasSearchId) {
        query.bindValue(":search_id", filter.searchId);
    }
    if (!filter.searchNom.trimmed().isEmpty()) {
        query.bindValue(":search_nom", "%" + filter.searchNom.trimmed() + "%");
    }
    if (filter.hasSearchIdEquipe) {
        query.bindValue(":search_id_equipe", filter.searchIdEquipe);
    }
    if (filter.searchSpec != "-- Tous --") {
        query.bindValue(":search_spec", filter.searchSpec);
    }

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    while (query.next()) {
        EmployeData row;
        fillEmployeDataFromQuery(query, &row);
        outRows->append(row);
    }
    return true;
}

bool EmployeRepository::getStatsSummary(EmployeStatsSummary *outStats, QString *errorMessage)
{
    if (!outStats) {
        if (errorMessage) {
            *errorMessage = "Parametre de sortie invalide (outStats).";
        }
        return false;
    }

    QSqlQuery query;
    if (!query.exec("SELECT COUNT(*), COALESCE(SUM(SALAIRE), 0) FROM EMPLOYE") || !query.next()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    outStats->totalEmployes = query.value(0).toInt();
    outStats->masseSalariale = query.value(1).toDouble();
    return true;
}

bool EmployeRepository::getMasseByPoste(QList<EmployeMasseByPoste> *outRows, QString *errorMessage)
{
    if (!outRows) {
        if (errorMessage) {
            *errorMessage = "Parametre de sortie invalide (outRows).";
        }
        return false;
    }
    outRows->clear();

    QSqlQuery query;
    if (!query.exec("SELECT POSTE, COALESCE(SUM(SALAIRE),0) AS MASSE FROM EMPLOYE GROUP BY POSTE ORDER BY POSTE")) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    while (query.next()) {
        EmployeMasseByPoste row;
        row.poste = query.value("POSTE").toString();
        row.masse = query.value("MASSE").toDouble();
        outRows->append(row);
    }
    return true;
}

bool EmployeRepository::getCountByPoste(QList<EmployeCountByPoste> *outRows, QString *errorMessage)
{
    if (!outRows) {
        if (errorMessage) {
            *errorMessage = "Parametre de sortie invalide (outRows).";
        }
        return false;
    }
    outRows->clear();

    QSqlQuery query;
    if (!query.exec("SELECT POSTE, COUNT(*) AS TOTAL FROM EMPLOYE GROUP BY POSTE ORDER BY POSTE")) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    while (query.next()) {
        EmployeCountByPoste row;
        row.poste = query.value("POSTE").toString();
        row.total = query.value("TOTAL").toInt();
        outRows->append(row);
    }
    return true;
}

bool EmployeRepository::getTopFournisseurs(int limit, QList<EmployeTopFournisseurs> *outRows, QString *errorMessage)
{
    if (!outRows) {
        if (errorMessage) {
            *errorMessage = "Parametre de sortie invalide (outRows).";
        }
        return false;
    }
    if (limit <= 0) {
        if (errorMessage) {
            *errorMessage = "La limite doit etre strictement positive.";
        }
        return false;
    }
    outRows->clear();

    QSqlQuery query;
    if (!query.exec("SELECT NOM, PRENOM, COALESCE(FOURNISSEURS_TRAITES, 0) AS FOURNISSEURS_TRAITES "
                    "FROM EMPLOYE ORDER BY FOURNISSEURS_TRAITES DESC")) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    int count = 0;
    while (query.next() && count < limit) {
        EmployeTopFournisseurs row;
        row.nom = query.value("NOM").toString();
        row.prenom = query.value("PRENOM").toString();
        row.fournisseursTraites = query.value("FOURNISSEURS_TRAITES").toInt();
        outRows->append(row);
        ++count;
    }
    return true;
}

bool EmployeRepository::resolveEmployeIdByIdentity(const QString &identity, QString *resolvedEmployeeId, QString *errorMessage)
{
    const QString normalizedIdentity = identity.simplified();
    if (normalizedIdentity.isEmpty()) {
        if (errorMessage) {
            *errorMessage = "Veuillez saisir votre identifiant (Nom Prenom).";
        }
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT ID_EMPLOYE FROM EMPLOYE "
        "WHERE UPPER(TRIM(NOM) || ' ' || TRIM(PRENOM)) = UPPER(:identity)");
    query.bindValue(":identity", normalizedIdentity);

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = "Erreur SQL: " + query.lastError().text();
        }
        return false;
    }

    QString foundEmployeeId;
    int foundCount = 0;
    while (query.next()) {
        const QString candidateEmployeeId = query.value("ID_EMPLOYE").toString().trimmed();
        if (candidateEmployeeId.isEmpty()) {
            continue;
        }
        foundEmployeeId = candidateEmployeeId;
        ++foundCount;
        if (foundCount > 1) {
            break;
        }
    }

    if (foundCount == 0) {
        if (errorMessage) {
            *errorMessage = "Utilisateur non identifie (nom/prenom introuvable).";
        }
        return false;
    }

    if (foundCount > 1) {
        if (errorMessage) {
            *errorMessage = "Plusieurs utilisateurs correspondent a cet identifiant.";
        }
        return false;
    }

    if (resolvedEmployeeId) {
        *resolvedEmployeeId = foundEmployeeId;
    }
    return true;
}

bool EmployeRepository::clearExpiredResetCodes(QString *errorMessage)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE EMPLOYE "
        "SET RESET_CODE = NULL, RESET_CODE_EXPIRATION = NULL "
        "WHERE RESET_CODE IS NOT NULL "
        "AND RESET_CODE_EXPIRATION IS NOT NULL "
        "AND RESET_CODE_EXPIRATION <= SYSDATE");

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }
    return true;
}

bool EmployeRepository::storeResetCode(const QString &employeeId, const QString &code, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE EMPLOYE "
        "SET RESET_CODE = :code, RESET_CODE_EXPIRATION = SYSDATE + (3/1440) "
        "WHERE ID_EMPLOYE = :id_employe");
    query.bindValue(":code", code);
    query.bindValue(":id_employe", employeeId.trimmed());

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (query.numRowsAffected() <= 0) {
        if (errorMessage) {
            *errorMessage = "Aucun employe trouve avec cet identifiant.";
        }
        return false;
    }

    return true;
}

bool EmployeRepository::clearResetCode(const QString &employeeId, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE EMPLOYE "
        "SET RESET_CODE = NULL, RESET_CODE_EXPIRATION = NULL "
        "WHERE ID_EMPLOYE = :id_employe");
    query.bindValue(":id_employe", employeeId.trimmed());

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }
    return true;
}

bool EmployeRepository::resetPasswordWithCode(
    const QString &employeeId,
    const QString &code,
    const QString &passwordHash,
    QString *errorMessage)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE EMPLOYE "
        "SET MDP = :mdp, RESET_CODE = NULL, RESET_CODE_EXPIRATION = NULL "
        "WHERE ID_EMPLOYE = :id_employe "
        "AND RESET_CODE = :code "
        "AND RESET_CODE_EXPIRATION > SYSDATE");
    query.bindValue(":mdp", passwordHash);
    query.bindValue(":id_employe", employeeId.trimmed());
    query.bindValue(":code", code.trimmed());

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (query.numRowsAffected() <= 0) {
        if (errorMessage) {
            *errorMessage = "Code invalide ou expire.";
        }
        return false;
    }

    return true;
}
