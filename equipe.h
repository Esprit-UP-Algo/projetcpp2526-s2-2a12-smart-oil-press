#ifndef EQUIPE_H
#define EQUIPE_H

#include <QList>
#include <QMap>
#include <QString>

struct EquipeData
{
    int idEquipe = 0;
    QString nomEquipe;
    QString specialite;
    int nbreMembres = 0;
    QString etat;
    QString rate;
};

struct EquipeRateData
{
    int successCount = 0;
    int failureCount = 0;
    double rateValue = 0.0;
};

struct EquipeSpecialiteStatData
{
    QString specialite;
    int teamCount = 0;
    int activeCount = 0;
    double membersAverage = 0.0;
    double rateAverage = 0.0;
    double activeGlobalPercent = 0.0;
};

struct EquipePerformanceStatData
{
    QString categorie;
    int idEquipe = 0;
    QString nomEquipe;
    double rate = 0.0;
};

struct EquipeDetailsStatData
{
    int successCount = 0;
    int failureCount = 0;
    double rateValue = 0.0;
    QString feedback;
};

class EquipeRepository
{
public:
    static bool prochainIdEquipe(int *outId, QString *errorMessage = nullptr);
    static bool ajouterEquipe(const EquipeData &data, QString *errorMessage = nullptr);
    static bool listerEquipes(QList<EquipeData> *outRows, QString *errorMessage = nullptr);
    static bool getEquipeById(int idEquipe, EquipeData *outData, QString *errorMessage = nullptr);
    static bool modifierEquipe(const EquipeData &data, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool supprimerEquipe(int idEquipe, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool equipeNomExiste(const QString &nomEquipe, int excludeId = -1, QString *errorMessage = nullptr);

    static bool normaliserSpecialite(const QString &uiSpecialty, QString *outSpecialty, QString *errorMessage = nullptr);
    static bool normaliserEtat(const QString &uiStatus, QString *outStatus, QString *errorMessage = nullptr);
    static bool extraireRateData(const QString &rateRaw, EquipeRateData *outData, QString *errorMessage = nullptr);
    static bool calculerStatsSpecialites(
        const QList<EquipeData> &equipes,
        QList<EquipeSpecialiteStatData> *outRows,
        QMap<QString, int> *outCounts,
        QString *errorMessage = nullptr);
    static bool calculerClassement(
        const QList<EquipeData> &equipes,
        QList<EquipePerformanceStatData> *outRows,
        QString *errorMessage = nullptr);
    static bool calculerDetails(const EquipeData &equipe, EquipeDetailsStatData *outData, QString *errorMessage = nullptr);
};

#endif // EQUIPE_H
