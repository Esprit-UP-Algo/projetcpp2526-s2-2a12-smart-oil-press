#ifndef LABO_H
#define LABO_H

#include <QList>
#include <QString>

struct LaboData
{
    int idLabo = 0;
    QString nomLabo;
    QString resultats;
    QString conformite;
    QString adresse;
    int espaceLabo = 0;
    int espaceReste = 0;
    int review = 0;
};

struct LaboFilter
{
    bool hasSearchId = false;
    int searchId = 0;
    QString searchNom;
    QString orderColumn;
    bool descending = false;
};

struct LaboStatsSummary
{
    int totalLabos = 0;
    int totalConformes = 0;
};

struct LaboSpaceUsage
{
    QString nomLabo;
    double percentageUsed = 0.0;
};

struct LaboConformiteCount
{
    QString conformite;
    int count = 0;
};

struct LaboReviewStats
{
    double averageReview = 0.0;
    int totalReviews = 0;
};

class LaboRepository
{
public:
    static bool addLabo(const LaboData &data, QString *errorMessage = nullptr);
    static bool getLaboById(int idLabo, LaboData *outData, QString *errorMessage = nullptr);
    static bool updateLabo(int idLabo, const LaboData &data, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool deleteLabo(int idLabo, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool listLabos(QList<LaboData> *outRows, QString *errorMessage = nullptr);
    static bool filterLabos(const LaboFilter &filter, QList<LaboData> *outRows, QString *errorMessage = nullptr);
    static bool getStatsSummary(LaboStatsSummary *outStats, QString *errorMessage = nullptr);
    static bool getSpaceUsageStats(QList<LaboSpaceUsage> *outStats, QString *errorMessage = nullptr);
    static bool getConformiteStats(QList<LaboConformiteCount> *outStats, QString *errorMessage = nullptr);
    static bool getReviewStats(LaboReviewStats *outStats, QString *errorMessage = nullptr);
};

#endif // LABO_H