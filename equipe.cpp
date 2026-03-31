#include "equipe.h"

#include <QSqlError>
#include <QSqlQuery>
#include <QStringList>
#include <QVector>

#include <algorithm>

namespace {

void setError(QString *errorMessage, const QString &message)
{
    if (errorMessage) {
        *errorMessage = message;
    }
}

void fillEquipeDataFromQuery(const QSqlQuery &query, EquipeData *data)
{
    if (!data) {
        return;
    }

    data->idEquipe = query.value("ID_EQUIPE").toInt();
    data->nomEquipe = query.value("NOM_EQUIPE").toString();
    data->specialite = query.value("SPECIALITE").toString();
    data->nbreMembres = query.value("NBRE_MEMBRES").toInt();
    data->etat = query.value("ETAT").toString();
    data->rate = query.value("RATE").toString();
}

QString feedbackForRate(double rate)
{
    if (rate < 2.5) {
        return "Les resultats sont encore insuffisants. L'equipe doit renforcer sa methode de travail.";
    }
    if (rate < 6.0) {
        return "L'equipe atteint les objectifs de base, avec une marge d'amelioration.";
    }
    if (rate <= 8.0) {
        return "Les resultats sont satisfaisants et reguliers.";
    }
    return "Excellente performance: equipe autonome et efficace.";
}

bool isEtatActif(const QString &etat)
{
    const QString normalized = etat.trimmed().toLower();
    return normalized == "active" || normalized == "disponible";
}

bool validateEquipeData(const EquipeData &data, bool isUpdate, QString *errorMessage)
{
    if (data.idEquipe <= 0) {
        setError(errorMessage, "ID equipe invalide.");
        return false;
    }

    const QString nom = data.nomEquipe.trimmed();
    if (nom.isEmpty()) {
        setError(errorMessage, "Le nom de l'equipe est obligatoire.");
        return false;
    }

    if (data.nbreMembres <= 0) {
        setError(errorMessage, "Le nombre de membres doit etre strictement positif.");
        return false;
    }

    const QString specialite = data.specialite.trimmed();
    if (specialite.isEmpty()) {
        setError(errorMessage, "La specialite de l'equipe est obligatoire.");
        return false;
    }

    const QString etat = data.etat.trimmed().toLower();
    if (etat != "active" && etat != "inactive") {
        setError(errorMessage, "L'etat de l'equipe doit etre 'active' ou 'inactive'.");
        return false;
    }

    QString dbError;
    const int excludeId = isUpdate ? data.idEquipe : -1;
    if (EquipeRepository::equipeNomExiste(nom, excludeId, &dbError)) {
        setError(errorMessage, "Ce nom d'equipe existe deja.");
        return false;
    }

    if (!dbError.isEmpty()) {
        setError(errorMessage, "Verification d'unicite impossible: " + dbError);
        return false;
    }

    return true;
}

} // namespace

bool EquipeRepository::prochainIdEquipe(int *outId, QString *errorMessage)
{
    if (!outId) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    QSqlQuery query;
    query.prepare("SELECT COALESCE(MAX(ID_EQUIPE), 0) + 1 AS NEXT_ID FROM EQUIPE");

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    if (!query.next()) {
        setError(errorMessage, "Impossible de calculer le prochain ID equipe.");
        return false;
    }

    const int nextId = query.value("NEXT_ID").toInt();
    *outId = (nextId > 0) ? nextId : 1;
    return true;
}

bool EquipeRepository::normaliserSpecialite(const QString &uiSpecialty, QString *outSpecialty, QString *errorMessage)
{
    if (!outSpecialty) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    QString value = uiSpecialty.trimmed().toLower();
    if (value.isEmpty()) {
        setError(errorMessage, "La specialite est obligatoire.");
        return false;
    }

    if (value == "back-office" || value == "back office" || value == "backoffice") {
        value = "backoffice";
    } else if (value.contains("mecanique")) {
        value = "mecanique";
    }

    *outSpecialty = value;
    return true;
}

bool EquipeRepository::normaliserEtat(const QString &uiStatus, QString *outStatus, QString *errorMessage)
{
    if (!outStatus) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    const QString value = uiStatus.trimmed().toLower();
    if (value.isEmpty()) {
        setError(errorMessage, "L'etat est obligatoire.");
        return false;
    }

    if (value == "disponible" || value == "active") {
        *outStatus = "active";
        return true;
    }

    if (value == "n'est pas disponible" || value == "inactive") {
        *outStatus = "inactive";
        return true;
    }

    setError(errorMessage, "Etat invalide. Valeurs attendues: active/inactive.");
    return false;
}

bool EquipeRepository::extraireRateData(const QString &rateRaw, EquipeRateData *outData, QString *errorMessage)
{
    if (!outData) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    EquipeRateData parsed;
    const QString normalized = rateRaw.trimmed();
    if (normalized.isEmpty()) {
        *outData = parsed;
        return true;
    }

    const QStringList parts = normalized.split("||", Qt::KeepEmptyParts);
    if (parts.size() < 2) {
        bool ok = false;
        const double directRate = normalized.toDouble(&ok);
        if (!ok) {
            setError(errorMessage, "Format RATE invalide: " + normalized);
            return false;
        }
        parsed.rateValue = directRate;
        *outData = parsed;
        return true;
    }

    const QStringList counters = parts.at(1).split('|', Qt::SkipEmptyParts);
    for (const QString &counter : counters) {
        const QString token = counter.trimmed();
        if (token.startsWith("S:")) {
            parsed.successCount = token.mid(2).toInt();
        } else if (token.startsWith("L:")) {
            parsed.failureCount = token.mid(2).toInt();
        } else if (token.startsWith("R:")) {
            bool ok = false;
            const double rateValue = token.mid(2).trimmed().toDouble(&ok);
            if (!ok) {
                setError(errorMessage, "Valeur RATE invalide: " + token);
                return false;
            }
            parsed.rateValue = rateValue;
        }
    }

    *outData = parsed;
    return true;
}

bool EquipeRepository::calculerStatsSpecialites(
    const QList<EquipeData> &equipes,
    QList<EquipeSpecialiteStatData> *outRows,
    QMap<QString, int> *outCounts,
    QString *errorMessage)
{
    if (!outRows || !outCounts) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    outRows->clear();
    outCounts->clear();

    struct SpecialtyAggregate {
        int teamCount = 0;
        int membersSum = 0;
        double rateSum = 0.0;
        int activeCount = 0;
    };

    QMap<QString, SpecialtyAggregate> specialtyAgg;

    for (const EquipeData &team : equipes) {
        QString specialty = team.specialite.trimmed().toLower();
        if (specialty.isEmpty()) {
            specialty = "non definie";
        }

        (*outCounts)[specialty] += 1;

        SpecialtyAggregate &agg = specialtyAgg[specialty];
        agg.teamCount += 1;
        agg.membersSum += team.nbreMembres;

        EquipeRateData rateData;
        QString rateError;
        if (!extraireRateData(team.rate, &rateData, &rateError)) {
            setError(errorMessage, "Erreur RATE equipe " + QString::number(team.idEquipe) + ": " + rateError);
            return false;
        }
        agg.rateSum += rateData.rateValue;

        if (isEtatActif(team.etat)) {
            agg.activeCount += 1;
        }
    }

    const int totalTeams = equipes.size();
    for (auto it = specialtyAgg.cbegin(); it != specialtyAgg.cend(); ++it) {
        const SpecialtyAggregate &agg = it.value();

        EquipeSpecialiteStatData row;
        row.specialite = it.key();
        row.teamCount = agg.teamCount;
        row.activeCount = agg.activeCount;
        row.membersAverage = (agg.teamCount > 0)
                                 ? static_cast<double>(agg.membersSum) / static_cast<double>(agg.teamCount)
                                 : 0.0;
        row.rateAverage = (agg.teamCount > 0)
                              ? agg.rateSum / static_cast<double>(agg.teamCount)
                              : 0.0;
        row.activeGlobalPercent = (totalTeams > 0)
                                      ? (static_cast<double>(agg.activeCount) / static_cast<double>(totalTeams)) * 100.0
                                      : 0.0;

        outRows->append(row);
    }

    return true;
}

bool EquipeRepository::calculerClassement(
    const QList<EquipeData> &equipes,
    QList<EquipePerformanceStatData> *outRows,
    QString *errorMessage)
{
    if (!outRows) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    outRows->clear();

    struct TeamScore {
        EquipeData team;
        double rate = 0.0;
    };

    QVector<TeamScore> scores;
    scores.reserve(equipes.size());

    for (const EquipeData &team : equipes) {
        EquipeRateData rateData;
        QString rateError;
        if (!extraireRateData(team.rate, &rateData, &rateError)) {
            setError(errorMessage, "Erreur RATE equipe " + QString::number(team.idEquipe) + ": " + rateError);
            return false;
        }

        TeamScore score;
        score.team = team;
        score.rate = rateData.rateValue;
        scores.append(score);
    }

    if (scores.isEmpty()) {
        return true;
    }

    QVector<TeamScore> byBest = scores;
    std::sort(byBest.begin(), byBest.end(), [](const TeamScore &a, const TeamScore &b) {
        if (a.rate == b.rate) {
            return a.team.idEquipe < b.team.idEquipe;
        }
        return a.rate > b.rate;
    });

    const int topCount = std::min(3, static_cast<int>(byBest.size()));
    for (int i = 0; i < topCount; ++i) {
        EquipePerformanceStatData row;
        row.categorie = QString("Top %1").arg(i + 1);
        row.idEquipe = byBest[i].team.idEquipe;
        row.nomEquipe = byBest[i].team.nomEquipe;
        row.rate = byBest[i].rate;
        outRows->append(row);
    }

    QVector<TeamScore> byWorst = scores;
    std::sort(byWorst.begin(), byWorst.end(), [](const TeamScore &a, const TeamScore &b) {
        if (a.rate == b.rate) {
            return a.team.idEquipe < b.team.idEquipe;
        }
        return a.rate < b.rate;
    });

    const int bottomCount = std::min(3, static_cast<int>(byWorst.size()));
    for (int i = 0; i < bottomCount; ++i) {
        EquipePerformanceStatData row;
        row.categorie = QString("Bottom %1").arg(i + 1);
        row.idEquipe = byWorst[i].team.idEquipe;
        row.nomEquipe = byWorst[i].team.nomEquipe;
        row.rate = byWorst[i].rate;
        outRows->append(row);
    }

    return true;
}

bool EquipeRepository::calculerDetails(const EquipeData &equipe, EquipeDetailsStatData *outData, QString *errorMessage)
{
    if (!outData) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    EquipeRateData rateData;
    if (!extraireRateData(equipe.rate, &rateData, errorMessage)) {
        return false;
    }

    outData->successCount = rateData.successCount;
    outData->failureCount = rateData.failureCount;
    outData->rateValue = rateData.rateValue;
    outData->feedback = feedbackForRate(rateData.rateValue);
    return true;
}

bool EquipeRepository::ajouterEquipe(const EquipeData &data, QString *errorMessage)
{
    EquipeData validated = data;
    validated.nomEquipe = validated.nomEquipe.trimmed();

    if (!normaliserSpecialite(validated.specialite, &validated.specialite, errorMessage)) {
        return false;
    }

    if (!normaliserEtat(validated.etat, &validated.etat, errorMessage)) {
        return false;
    }

    if (!validateEquipeData(validated, false, errorMessage)) {
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO EQUIPE (ID_EQUIPE, NOM_EQUIPE, SPECIALITE, NBRE_MEMBRES, ETAT, RATE) "
        "VALUES (:id, :nom, :specialite, :membres, :etat, :rate)");

    query.bindValue(":id", validated.idEquipe);
    query.bindValue(":nom", validated.nomEquipe);
    query.bindValue(":specialite", validated.specialite);
    query.bindValue(":membres", validated.nbreMembres);
    query.bindValue(":etat", validated.etat);
    query.bindValue(":rate", validated.rate);

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    return true;
}

bool EquipeRepository::listerEquipes(QList<EquipeData> *outRows, QString *errorMessage)
{
    if (!outRows) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    outRows->clear();

    QSqlQuery query;
    query.prepare(
        "SELECT ID_EQUIPE, NOM_EQUIPE, SPECIALITE, NBRE_MEMBRES, ETAT, RATE "
        "FROM EQUIPE ORDER BY ID_EQUIPE");

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    while (query.next()) {
        EquipeData data;
        fillEquipeDataFromQuery(query, &data);
        outRows->append(data);
    }

    return true;
}

bool EquipeRepository::getEquipeById(int idEquipe, EquipeData *outData, QString *errorMessage)
{
    if (!outData) {
        setError(errorMessage, "Parametre de sortie invalide.");
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "SELECT ID_EQUIPE, NOM_EQUIPE, SPECIALITE, NBRE_MEMBRES, ETAT, RATE "
        "FROM EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", idEquipe);

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    if (!query.next()) {
        setError(errorMessage, "Aucune equipe trouvee avec cet ID.");
        return false;
    }

    fillEquipeDataFromQuery(query, outData);
    return true;
}

bool EquipeRepository::modifierEquipe(const EquipeData &data, int *rowsAffected, QString *errorMessage)
{
    EquipeData validated = data;
    validated.nomEquipe = validated.nomEquipe.trimmed();

    if (!normaliserSpecialite(validated.specialite, &validated.specialite, errorMessage)) {
        return false;
    }

    if (!normaliserEtat(validated.etat, &validated.etat, errorMessage)) {
        return false;
    }

    if (!validateEquipeData(validated, true, errorMessage)) {
        return false;
    }

    QSqlQuery query;
    query.prepare(
        "UPDATE EQUIPE SET NOM_EQUIPE = :nom, SPECIALITE = :specialite, "
        "NBRE_MEMBRES = :membres, ETAT = :etat, RATE = :rate "
        "WHERE ID_EQUIPE = :id");

    query.bindValue(":id", validated.idEquipe);
    query.bindValue(":nom", validated.nomEquipe);
    query.bindValue(":specialite", validated.specialite);
    query.bindValue(":membres", validated.nbreMembres);
    query.bindValue(":etat", validated.etat);
    query.bindValue(":rate", validated.rate);

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    if (rowsAffected) {
        *rowsAffected = query.numRowsAffected();
    }
    return true;
}

bool EquipeRepository::supprimerEquipe(int idEquipe, int *rowsAffected, QString *errorMessage)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", idEquipe);

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    if (rowsAffected) {
        *rowsAffected = query.numRowsAffected();
    }
    return true;
}

bool EquipeRepository::equipeNomExiste(const QString &nomEquipe, int excludeId, QString *errorMessage)
{
    const QString nomNettoye = nomEquipe.trimmed();
    if (nomNettoye.isEmpty()) {
        return false;
    }

    QSqlQuery query;
    if (excludeId > 0) {
        query.prepare(
            "SELECT 1 FROM EQUIPE "
            "WHERE UPPER(TRIM(NOM_EQUIPE)) = UPPER(TRIM(:nom)) AND ID_EQUIPE <> :exclude_id");
        query.bindValue(":exclude_id", excludeId);
    } else {
        query.prepare(
            "SELECT 1 FROM EQUIPE "
            "WHERE UPPER(TRIM(NOM_EQUIPE)) = UPPER(TRIM(:nom))");
    }

    query.bindValue(":nom", nomNettoye);

    if (!query.exec()) {
        setError(errorMessage, query.lastError().text());
        return false;
    }

    return query.next();
}
