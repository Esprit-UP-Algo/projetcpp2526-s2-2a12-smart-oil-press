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

    const QVariant idValue = query.value("ID_MACHINE");
    if (!idValue.isNull()) {
        data->idMachine = idValue.toInt();
    } else {
        data->idMachine = query.value("ID").toInt();
    }

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

static int getNextMachineHistoryId(QString *errorMessage = nullptr)
{
    QSqlQuery query;
    if (!query.exec("SELECT COALESCE(MAX(ID), 0) + 1 AS next_id FROM MACHINE_HISTORIQUE")) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return -1;
    }
    if (!query.next()) {
        if (errorMessage) *errorMessage = "Impossible de générer l'ID de l'historique";
        return -1;
    }
    return query.value("next_id").toInt();
}

} // namespace

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

    // Log history
    if (!logMachineHistory(data.idMachine, "ajouter")) {
        qDebug() << "MachineWidget::addMachine - historique non enregistré pour id=" << data.idMachine;
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
    query.prepare(QString("SELECT ID_MACHINE AS ID_MACHINE, NOM, CATEGORIE, REFERENCE, DATE_ACHAT, ETAT_ACHAT, LOCALISATION, DATE_FIN_GARENTIE, ID_LABO FROM %1 WHERE ID_MACHINE = :id").arg(table));
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

    // Get old machine data for history logging
    MachineData oldData;
    if (!getMachineById(idMachine, &oldData, errorMessage)) {
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

    int affectedRows = query.numRowsAffected();
    if (rowsAffected) *rowsAffected = affectedRows;

    const QString oldEtat = normalizeMachineEtat(oldData.etatAchat);
    const QString newEtat = etat;

    if (!logMachineHistory(idMachine, "modifier")) {
        qDebug() << "MachineWidget::updateMachine - historique non enregistré pour id=" << idMachine;
    }

    return true;
}

bool MachineWidget::deleteMachine(int idMachine, int *rowsAffected, QString *errorMessage)
{
    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    // Get old machine data for history logging
    MachineData oldData;
    if (!getMachineById(idMachine, &oldData, errorMessage)) {
        return false;
    }

    const QString oldEtat = normalizeMachineEtat(oldData.etatAchat);
    if (!logMachineHistory(idMachine, "supprimer")) {
        qDebug() << "MachineWidget::deleteMachine - historique non enregistré pour id=" << idMachine;
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
    if (!query.exec(QString("SELECT ID_MACHINE AS ID_MACHINE, NOM, CATEGORIE, REFERENCE, DATE_ACHAT, ETAT_ACHAT, LOCALISATION, DATE_FIN_GARENTIE, ID_LABO FROM %1 ORDER BY ID_MACHINE").arg(table))) {
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

bool MachineWidget::getMachinesByCategory(QList<MachineCategoryStats> *outStats, QString *errorMessage)
{
    if (!outStats) {
        return false;
    }
    outStats->clear();

    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    const QString sql = QString(
        "SELECT CATEGORIE, COUNT(*) as count "
        "FROM %1 "
        "GROUP BY CATEGORIE "
        "ORDER BY count DESC").arg(table);

    if (!query.exec(sql)) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    while (query.next()) {
        MachineCategoryStats stat;
        stat.category = query.value("CATEGORIE").toString();
        stat.count = query.value("count").toInt();
        outStats->append(stat);
    }

    return true;
}

bool MachineWidget::getMachinesByLab(QList<MachineLabStats> *outStats, QString *errorMessage)
{
    if (!outStats) {
        return false;
    }
    outStats->clear();

    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    const QString sql = QString(
        "SELECT l.NOM as lab_name, COUNT(m.ID_MACHINE) as machine_count "
        "FROM %1 m "
        "LEFT JOIN LABORATOIRES l ON m.ID_LABO = l.ID_LABO "
        "GROUP BY m.ID_LABO, l.NOM "
        "ORDER BY machine_count DESC").arg(table);

    if (!query.exec(sql)) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    while (query.next()) {
        MachineLabStats stat;
        stat.labName = query.value("lab_name").toString();
        if (stat.labName.isEmpty()) {
            stat.labName = "Non assigné";
        }
        stat.machineCount = query.value("machine_count").toInt();
        outStats->append(stat);
    }

    return true;
}

bool MachineWidget::getMachinesByYear(QList<MachineYearlyStats> *outStats, QString *errorMessage)
{
    if (!outStats) {
        return false;
    }
    outStats->clear();

    const QString table = resolveMachineTable();
    if (table.isEmpty()) {
        if (errorMessage) *errorMessage = "Table MACHINE introuvable";
        return false;
    }

    QSqlQuery query;
    const QString sql = QString(
        "SELECT TO_CHAR(DATE_ACHAT, 'YYYY') as year, COUNT(*) as count "
        "FROM %1 "
        "WHERE DATE_ACHAT IS NOT NULL "
        "GROUP BY TO_CHAR(DATE_ACHAT, 'YYYY') "
        "ORDER BY year DESC").arg(table);

    if (!query.exec(sql)) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    while (query.next()) {
        MachineYearlyStats stat;
        stat.year = query.value("year").toInt();
        stat.count = query.value("count").toInt();
        outStats->append(stat);
    }

    return true;
}

bool MachineWidget::listMachineHistory(QList<MachineHistoryData> *outRows, QString *errorMessage)
{
    if (!outRows) return false;
    outRows->clear();

    QSqlQuery query;
    if (!query.exec("SELECT ID, ID_MACHINE, DATE_INTERVENTION, TYPE_INTERVENTION, DESCRIPTION, RESPONSABLE, RESULTAT, NIVEAU_URGENCE, COUT_INTERVENTION, DUREE_INTERVENTION, PIECE_REMPLACEE FROM MACHINE_HISTORIQUE ORDER BY DATE_INTERVENTION DESC")) {
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }

    while (query.next()) {
        MachineHistoryData row;
        row.id = query.value("ID").toInt();
        row.idMachine = query.value("ID_MACHINE").toInt();
        row.dateIntervention = query.value("DATE_INTERVENTION").toDateTime();
        row.typeIntervention = query.value("TYPE_INTERVENTION").toString();
        row.description = query.value("DESCRIPTION").toString();
        row.responsable = query.value("RESPONSABLE").toString();
        row.resultat = query.value("RESULTAT").toString();
        row.niveauUrgence = query.value("NIVEAU_URGENCE").toString();
        row.coutIntervention = query.value("COUT_INTERVENTION").toDouble();
        row.dureeIntervention = query.value("DUREE_INTERVENTION").toInt();
        row.pieceRemplacee = query.value("PIECE_REMPLACEE").toString();
        outRows->append(row);
    }

    return true;
}

bool MachineWidget::logMachineHistory(int idMachine, const QString &typeIntervention, QString *errorMessage)
{
    const int nextId = getNextMachineHistoryId(errorMessage);
    if (nextId <= 0) {
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO MACHINE_HISTORIQUE (ID, ID_MACHINE, DATE_INTERVENTION, TYPE_INTERVENTION, DESCRIPTION, RESPONSABLE, RESULTAT, NIVEAU_URGENCE, COUT_INTERVENTION, DUREE_INTERVENTION, PIECE_REMPLACEE) "
                  "VALUES (:id, :idMachine, SYSDATE, :typeIntervention, :description, :responsable, :resultat, :niveauUrgence, :coutIntervention, :dureeIntervention, :pieceRemplacee)");
    query.bindValue(":id", nextId);
    query.bindValue(":idMachine", idMachine);
    query.bindValue(":typeIntervention", typeIntervention);
    query.bindValue(":description", QString());
    query.bindValue(":responsable", QString());
    query.bindValue(":resultat", QString());
    query.bindValue(":niveauUrgence", QString());
    query.bindValue(":coutIntervention", 0);
    query.bindValue(":dureeIntervention", 0);
    query.bindValue(":pieceRemplacee", QString());

    if (!query.exec()) {
        const QString dbErr = query.lastError().text();
        qDebug() << "MachineWidget::logMachineHistory SQL failed" << dbErr << "idMachine=" << idMachine << "typeIntervention=" << typeIntervention;
        if (errorMessage) *errorMessage = dbErr;
        return false;
    }

    return true;
}