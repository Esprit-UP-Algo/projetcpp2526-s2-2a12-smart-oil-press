#include "labo.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>

namespace {
void fillLaboDataFromQuery(const QSqlQuery &query, LaboData *data)
{
    if (!data) {
        return;
    }

    data->idLabo = query.value("ID_LABO").toInt();
    data->nomLabo = query.value("NOM_LABO").toString();
    data->resultats = query.value("RESULTATS").toString();
    data->conformite = query.value("CONFORMITE").toString();
    data->adresse = query.value("ADRESSE").toString();
    data->espaceLabo = query.value("ESPACE_LABO").toInt();
    data->espaceReste = query.value("ESPACE_RESTE").toInt();
    data->review = query.value("REVIEW").toInt();
}
}

bool LaboRepository::addLabo(const LaboData &data, QString *errorMessage)
{
    if (data.espaceLabo <= data.espaceReste) {
        if (errorMessage) *errorMessage = "L'espace labo doit être supérieur à l'espace restant.";
        return false;
    }
    if (data.review < 0 || data.review > 10) {
        if (errorMessage) *errorMessage = "La note REVIEW doit être entre 0 et 10.";
        return false;
    }

    // Get next ID
    QSqlQuery queryMaxId;
    int nextId = 1;
    if (queryMaxId.exec("SELECT MAX(ID_LABO) FROM LABO")) {
        if (queryMaxId.next()) {
            bool ok;
            int maxId = queryMaxId.value(0).toInt(&ok);
            if (ok && maxId > 0) {
                nextId = maxId + 1;
            }
        }
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO LABO "
        "(ID_LABO, NOM_LABO, RESULTATS, CONFORMITE, ADRESSE, ESPACE_LABO, ESPACE_RESTE, REVIEW) "
        "VALUES (:id_labo, :nom_labo, :resultats, :conformite, :adresse, :espace_labo, :espace_reste, :review)");

    query.bindValue(":id_labo", nextId);
    query.bindValue(":nom_labo", data.nomLabo);
    query.bindValue(":resultats", data.resultats);
    query.bindValue(":conformite", data.conformite);
    query.bindValue(":adresse", data.adresse);
    query.bindValue(":espace_labo", data.espaceLabo);
    query.bindValue(":espace_reste", data.espaceReste);
    query.bindValue(":review", data.review);

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }
    return true;
}

bool LaboRepository::getLaboById(int idLabo, LaboData *outData, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM LABO WHERE ID_LABO = :id");
    query.bindValue(":id", idLabo);

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (!query.next()) {
        if (errorMessage) {
            *errorMessage = "Aucun laboratoire trouve avec cet ID.";
        }
        return false;
    }

    fillLaboDataFromQuery(query, outData);
    return true;
}

bool LaboRepository::updateLabo(int idLabo, const LaboData &data, int *rowsAffected, QString *errorMessage)
{
    if (data.espaceLabo <= data.espaceReste) {
        if (errorMessage) *errorMessage = "L'espace labo doit être supérieur à l'espace restant.";
        return false;
    }
    if (data.review < 0 || data.review > 10) {
        if (errorMessage) *errorMessage = "La note REVIEW doit être entre 0 et 10.";
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE LABO SET NOM_LABO = :nom_labo, RESULTATS = :resultats, CONFORMITE = :conformite, "
        "ADRESSE = :adresse, ESPACE_LABO = :espace_labo, ESPACE_RESTE = :espace_reste, REVIEW = :review "
        "WHERE ID_LABO = :id");

    query.bindValue(":id", idLabo);
    query.bindValue(":nom_labo", data.nomLabo);
    query.bindValue(":resultats", data.resultats);
    query.bindValue(":conformite", data.conformite);
    query.bindValue(":adresse", data.adresse);
    query.bindValue(":espace_labo", data.espaceLabo);
    query.bindValue(":espace_reste", data.espaceReste);
    query.bindValue(":review", data.review);

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

bool LaboRepository::deleteLabo(int idLabo, int *rowsAffected, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("DELETE FROM LABO WHERE ID_LABO = :id");
    query.bindValue(":id", idLabo);

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

bool LaboRepository::listLabos(QList<LaboData> *outRows, QString *errorMessage)
{
    if (!outRows) {
        return false;
    }
    outRows->clear();

    QSqlQuery query;
    if (!query.exec(
            "SELECT ID_LABO, NOM_LABO, RESULTATS, CONFORMITE, ADRESSE, ESPACE_LABO, ESPACE_RESTE, REVIEW "
            "FROM LABO WHERE REVIEW BETWEEN 0 AND 10 ORDER BY ID_LABO")) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    while (query.next()) {
        LaboData row;
        fillLaboDataFromQuery(query, &row);
        outRows->append(row);
    }
    return true;
}

bool LaboRepository::filterLabos(const LaboFilter &filter, QList<LaboData> *outRows, QString *errorMessage)
{
    if (!outRows) {
        return false;
    }
    outRows->clear();

    QString sql =
        "SELECT ID_LABO, NOM_LABO, RESULTATS, CONFORMITE, ADRESSE, ESPACE_LABO, ESPACE_RESTE, REVIEW "
        "FROM LABO";
    QStringList whereConditions;

    if (filter.hasSearchId) {
        whereConditions << "ID_LABO = :search_id";
    }
    if (!filter.searchNom.trimmed().isEmpty()) {
        whereConditions << "UPPER(NOM_LABO) LIKE UPPER(:search_nom)";
    }

    if (!whereConditions.isEmpty()) {
        sql += " WHERE " + whereConditions.join(" AND ");
    }

    if (!filter.orderColumn.trimmed().isEmpty()) {
        sql += " ORDER BY " + filter.orderColumn + (filter.descending ? " DESC" : " ASC");
    } else {
        sql += " ORDER BY ID_LABO";
    }

    QSqlQuery query;
    query.prepare(sql);

    if (filter.hasSearchId) {
        query.bindValue(":search_id", filter.searchId);
    }
    if (!filter.searchNom.trimmed().isEmpty()) {
        query.bindValue(":search_nom", "%" + filter.searchNom.trimmed() + "%");
    }

    if (!query.exec()) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    while (query.next()) {
        LaboData row;
        fillLaboDataFromQuery(query, &row);
        outRows->append(row);
    }
    return true;
}

bool LaboRepository::getStatsSummary(LaboStatsSummary *outStats, QString *errorMessage)
{
    if (!outStats) {
        return false;
    }

    QSqlQuery query;
    if (!query.exec(
            "SELECT COUNT(*) as total, "
            "SUM(CASE WHEN CONFORMITE = 'Oui' THEN 1 ELSE 0 END) as conformes "
            "FROM LABO")) {
        if (errorMessage) {
            *errorMessage = query.lastError().text();
        }
        return false;
    }

    if (query.next()) {
        outStats->totalLabos = query.value("total").toInt();
        outStats->totalConformes = query.value("conformes").toInt();
    }
    return true;
}