#include "machine.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>

namespace {

void fillMachineDataFromQuery(const QSqlQuery &query, MachineData *data)
{
    if (!data) return;

    data->idMachine = query.value("ID_MACHINE").toInt();
    data->nom = query.value("NOM").toString();
    data->categorie = query.value("CATEGORIE").toString();
    data->reference = query.value("REFERENCE").toString();
    data->dateAchat = query.value("DATE_ACHAT").toDate();
    data->etatAchat = query.value("ETAT_ACHAT").toString();
    data->localisation = query.value("LOCALISATION").toString();
    data->dateFinGarantie = query.value("DATE_FIN_GARENTIE").toDate();
    data->idLabo = query.value("ID_LABO").toInt();
}

static QString normalizeMachineEtat(const QString &etat)
{
    const QString value = etat.trimmed().toLower();
    if (value.isEmpty()) return {};

    if (value.contains("en service")) return "en service";
    if (value.contains("maintenance")) return "maintenance";
    if (value.contains("panne")) return "panne";
    if (value.contains("hors service")) return "hors service";
    if (value.contains("en stock")) return "en stock";
    if (value.contains("en attente")) return "en attente";

    return {};
}

static QString normalizeMachineCategorie(const QString &categorie)
{
    const QString value = categorie.trimmed().toLower();
    if (value.isEmpty()) return {};

    static const QSet<QString> allowed = {
        "presse", "moteur", "filtre", "capteur", "pompe", "compresseur", "convoyeur", "valve"
    };

    if (allowed.contains(value)) return value;
    return {};
}

static bool isMachineCategorieAllowed(const QString &categorie)
{
    return !normalizeMachineCategorie(categorie).isEmpty();
}

static bool validateMachineData(const MachineData &data, QString *errorMessage)
{
    if (data.idMachine <= 0) {
        if (errorMessage) *errorMessage = "ID Machine invalide";
        return false;
    }

    if (data.nom.trimmed().isEmpty()) {
        if (errorMessage) *errorMessage = "Nom Machine obligatoire";
        return false;
    }

    if (!isMachineCategorieAllowed(data.categorie)) {
        if (errorMessage) *errorMessage = "Categorie machine invalide";
        return false;
    }

    if (data.reference.trimmed().isEmpty()) {
        if (errorMessage) *errorMessage = "Reference machine obligatoire";
        return false;
    }

    if (data.localisation.trimmed().isEmpty()) {
        if (errorMessage) *errorMessage = "Localisation machine obligatoire";
        return false;
    }

    const QString etat = normalizeMachineEtat(data.etatAchat);
    if (etat.isEmpty()) {
        if (errorMessage) *errorMessage = "Etat machine invalide";
        return false;
    }

    if (!data.dateAchat.isValid()) {
        if (errorMessage) *errorMessage = "Date d'achat invalide";
        return false;
    }

    QDate dateFin = data.dateFinGarantie.isValid() ? data.dateFinGarantie : data.dateAchat.addYears(1);
    if (dateFin < data.dateAchat) {
        if (errorMessage) *errorMessage = "Date de fin de garantie doit être >= date d'achat";
        return false;
    }

    // idLabo can be set to a fallback value in insertion/update when not known.
    return true;
}

}

QString MachineWidget::resolveMachineTable()
{
    return "MACHINES";
}

bool MachineWidget::addMachine(const MachineData &data, QString *errorMessage)
{
    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    if (!validateMachineData(data, errorMessage)) {
        return false;
    }

    QSqlQuery existsQuery;
    existsQuery.prepare(QString("SELECT COUNT(*) FROM %1 WHERE ID_MACHINE = :id").arg(table));
    existsQuery.bindValue(":id", data.idMachine);
    if (!existsQuery.exec() || !existsQuery.next()) {
        if (errorMessage) *errorMessage = existsQuery.lastError().text();
        return false;
    }

    if (existsQuery.value(0).toInt() > 0) {
        if (errorMessage) *errorMessage = "Une machine avec cet ID existe déjà";
        return false;
    }

    const QString categorie = normalizeMachineCategorie(data.categorie);
    const QString etat = normalizeMachineEtat(data.etatAchat);
    QDate dateFin = data.dateFinGarantie.isValid() ? data.dateFinGarantie : data.dateAchat.addYears(1);

    QSqlQuery query;
    query.prepare(QString(
        "INSERT INTO %1 (ID_MACHINE, NOM, CATEGORIE, REFERENCE, DATE_ACHAT, ETAT_ACHAT, LOCALISATION, DATE_FIN_GARENTIE, ID_LABO) "
        "VALUES (:id, :nom, :categorie, :reference, :dateAchat, :etat, :localisation, :dateFinGarantie, :idLabo)").arg(table));
    query.bindValue(":id", data.idMachine);
    query.bindValue(":nom", data.nom.trimmed());
    query.bindValue(":categorie", categorie);
    query.bindValue(":reference", data.reference.trimmed());
    query.bindValue(":dateAchat", data.dateAchat);
    query.bindValue(":etat", etat);
    query.bindValue(":localisation", data.localisation.trimmed());
    query.bindValue(":dateFinGarantie", dateFin);
    query.bindValue(":idLabo", data.idLabo > 0 ? data.idLabo : 1);

    if (!query.exec()) {
        const QString dbErr = query.lastError().text();
        qDebug() << "MachineWidget::addMachine SQL failed" << dbErr << "data:" << data.idMachine << data.nom << categorie << data.reference << data.dateAchat << etat << data.localisation << dateFin << data.idLabo;
        if (errorMessage) {
            *errorMessage = dbErr + "\nDonnées: " +
                    QString("id=%1 nom='%2' categorie='%3' etat='%4' dateAchat=%5 dateFin=%6 idLabo=%7")
                    .arg(data.idMachine)
                    .arg(data.nom)
                    .arg(categorie)
                    .arg(etat)
                    .arg(data.dateAchat.toString(Qt::ISODate))
                    .arg(dateFin.toString(Qt::ISODate))
                    .arg(data.idLabo);
        }
        return false;
    }
    return true;
}

bool MachineWidget::getMachineById(int idMachine, MachineData *outData, QString *errorMessage)
{
    if (!outData) return false;

    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    query.prepare(QString("SELECT * FROM %1 WHERE ID_MACHINE = :id").arg(table));
    query.bindValue(":id", idMachine);

    if (!query.exec()) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    if (!query.next()) {
        if (errorMessage) *errorMessage = "Machine non trouvée";
        return false;
    }

    fillMachineDataFromQuery(query, outData);

    return true;
}

bool MachineWidget::updateMachine(int idMachine, const MachineData &data, int *rowsAffected, QString *errorMessage)
{
    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    if (!validateMachineData(data, errorMessage)) {
        return false;
    }

    const QString categorie = normalizeMachineCategorie(data.categorie);
    const QString etat = normalizeMachineEtat(data.etatAchat);
    QDate dateFin = data.dateFinGarantie.isValid() ? data.dateFinGarantie : data.dateAchat.addYears(1);

    QSqlQuery query;
    query.prepare(QString(
        "UPDATE %1 SET NOM = :nom, CATEGORIE = :categorie, REFERENCE = :reference, DATE_ACHAT = :dateAchat, "
        "ETAT_ACHAT = :etat, LOCALISATION = :localisation, DATE_FIN_GARENTIE = :dateFinGarantie, ID_LABO = :idLabo "
        "WHERE ID_MACHINE = :id").arg(table));

    query.bindValue(":nom", data.nom.trimmed());
    query.bindValue(":categorie", categorie);
    query.bindValue(":reference", data.reference.trimmed());
    query.bindValue(":dateAchat", data.dateAchat);
    query.bindValue(":etat", etat);
    query.bindValue(":localisation", data.localisation.trimmed());
    query.bindValue(":dateFinGarantie", dateFin);
    query.bindValue(":idLabo", data.idLabo > 0 ? data.idLabo : 1);
    query.bindValue(":id", idMachine);

    if (!query.exec()) {
        const QString dbErr = query.lastError().text();
        qDebug() << "MachineWidget::updateMachine SQL failed" << dbErr << "data:" << idMachine << data.nom << categorie << data.reference << data.dateAchat << etat << data.localisation << dateFin << data.idLabo;
        if (errorMessage) {
            *errorMessage = dbErr + "\nDonnées: " +
                    QString("id=%1 nom='%2' categorie='%3' etat='%4' dateAchat=%5 dateFin=%6 idLabo=%7")
                    .arg(idMachine)
                    .arg(data.nom)
                    .arg(categorie)
                    .arg(etat)
                    .arg(data.dateAchat.toString(Qt::ISODate))
                    .arg(dateFin.toString(Qt::ISODate))
                    .arg(data.idLabo);
        }
        return false;
    }

    if (rowsAffected) *rowsAffected = query.numRowsAffected();
    return true;
}

bool MachineWidget::deleteMachine(int idMachine, int *rowsAffected, QString *errorMessage)
{
    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    query.prepare(QString("DELETE FROM %1 WHERE ID_MACHINE = :id").arg(table));
    query.bindValue(":id", idMachine);

    if (!query.exec()) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    if (rowsAffected) *rowsAffected = query.numRowsAffected();
    return true;
}

bool MachineWidget::listMachines(QList<MachineData> *outRows, QString *errorMessage)
{
    if (!outRows) return false;
    outRows->clear();

    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    if (!query.exec(QString("SELECT * FROM %1 ORDER BY ID_MACHINE").arg(table))) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    while (query.next()) {
        MachineData row;
        fillMachineDataFromQuery(query, &row);
        outRows->append(row);
    }
    return true;
}

bool MachineWidget::getStatsSummary(MachineStatsSummary *outStats, QString *errorMessage)
{
    if (!outStats) {
        return false;
    }

    outStats->totalMachines = 0;
    outStats->enService = 0;
    outStats->enPanne = 0;
    outStats->maintenance = 0;
    outStats->horsService = 0;
    outStats->enStock = 0;
    outStats->enAttente = 0;

    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    const QString sql = QString(
        "SELECT COUNT(*) as total, "
        "SUM(CASE WHEN LOWER(ETAT_ACHAT) = 'en service' THEN 1 ELSE 0 END) AS en_service, "
        "SUM(CASE WHEN LOWER(ETAT_ACHAT) = 'panne' THEN 1 ELSE 0 END) AS en_panne, "
        "SUM(CASE WHEN LOWER(ETAT_ACHAT) = 'maintenance' THEN 1 ELSE 0 END) AS maintenance, "
        "SUM(CASE WHEN LOWER(ETAT_ACHAT) = 'hors service' THEN 1 ELSE 0 END) AS hors_service, "
        "SUM(CASE WHEN LOWER(ETAT_ACHAT) = 'en stock' THEN 1 ELSE 0 END) AS en_stock, "
        "SUM(CASE WHEN LOWER(ETAT_ACHAT) = 'en attente' THEN 1 ELSE 0 END) AS en_attente "
        "FROM %1").arg(table);

    if (!query.exec(sql)) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    if (query.next()) {
        outStats->totalMachines = query.value("total").toInt();
        outStats->enService = query.value("en_service").toInt();
        outStats->enPanne = query.value("en_panne").toInt();
        outStats->maintenance = query.value("maintenance").toInt();
        outStats->horsService = query.value("hors_service").toInt();
        outStats->enStock = query.value("en_stock").toInt();
        outStats->enAttente = query.value("en_attente").toInt();
    }

    return true;
}
