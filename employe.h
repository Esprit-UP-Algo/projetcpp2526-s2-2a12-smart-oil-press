#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QList>
#include <QString>

struct EmployeData
{
    int idEmploye = 0;
    QString nom;
    QString prenom;
    int age = 0;
    QString poste;
    double salaire = 0.0;
    int anciennete = 0;
    QString disponibilite;
    int heuresTravail = 0;
    int fournisseursTraites = 0;
    QString idEquipe;
    QString mdp;
};

struct EmployeFilter
{
    bool hasSearchId = false;
    int searchId = 0;
    QString searchNom;
    bool hasSearchIdEquipe = false;
    int searchIdEquipe = 0;
    QString searchSpec;
    QString orderColumn;
    bool descending = false;
};

struct EmployeStatsSummary
{
    int totalEmployes = 0;
    double masseSalariale = 0.0;
};

struct EmployeMasseByPoste
{
    QString poste;
    double masse = 0.0;
};

struct EmployeCountByPoste
{
    QString poste;
    int total = 0;
};

struct EmployeTopFournisseurs
{
    QString nom;
    QString prenom;
    int fournisseursTraites = 0;
};

class EmployeRepository
{
public:
    static QString hashPassword(const QString &plainPassword);
    static bool authenticateByIdentity(
        const QString &identity,
        const QString &plainPassword,
        QString *outRole = nullptr,
        QString *errorMessage = nullptr);
    static bool authenticateByFingerprintId(
        int fingerprintId,
        QString *outIdentity = nullptr,
        QString *outRole = nullptr,
        int *outEmployeId = nullptr,
        QString *errorMessage = nullptr);
    static bool getEmployeIdentityById(
        int idEmploye,
        QString *outIdentity = nullptr,
        QString *errorMessage = nullptr);
    static bool assignFingerprintId(
        int idEmploye,
        int fingerprintId,
        QString *outIdentity = nullptr,
        QString *errorMessage = nullptr);
    static bool isNomPrenomDisponible(
        const QString &nom,
        const QString &prenom,
        int excludeEmployeId = -1,
        QString *errorMessage = nullptr);
    static bool equipeExists(int idEquipe, QString *errorMessage = nullptr);
    static bool addEmploye(
        const EmployeData &data,
        bool hasEquipe,
        int idEquipe,
        QString *errorMessage = nullptr);
    static bool getEmployeById(int idEmploye, EmployeData *outData, QString *errorMessage = nullptr);
    static bool updateEmploye(
        int idEmploye,
        const EmployeData &data,
        bool hasEquipe,
        int idEquipe,
        bool updatePassword,
        const QString &passwordHash,
        int *rowsAffected = nullptr,
        QString *errorMessage = nullptr);
    static bool deleteEmploye(int idEmploye, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool listEmployes(QList<EmployeData> *outRows, QString *errorMessage = nullptr);
    static bool filterEmployes(const EmployeFilter &filter, QList<EmployeData> *outRows, QString *errorMessage = nullptr);
    static bool getStatsSummary(EmployeStatsSummary *outStats, QString *errorMessage = nullptr);
    static bool getMasseByPoste(QList<EmployeMasseByPoste> *outRows, QString *errorMessage = nullptr);
    static bool getCountByPoste(QList<EmployeCountByPoste> *outRows, QString *errorMessage = nullptr);
    static bool getTopFournisseurs(int limit, QList<EmployeTopFournisseurs> *outRows, QString *errorMessage = nullptr);
    static bool resolveEmployeIdByIdentity(const QString &identity, QString *resolvedEmployeeId, QString *errorMessage = nullptr);
    static bool clearExpiredResetCodes(QString *errorMessage = nullptr);
    static bool storeResetCode(const QString &employeeId, const QString &code, QString *errorMessage = nullptr);
    static bool clearResetCode(const QString &employeeId, QString *errorMessage = nullptr);
    static bool resetPasswordWithCode(
        const QString &employeeId,
        const QString &code,
        const QString &passwordHash,
        QString *errorMessage = nullptr);
};

#endif // EMPLOYE_H
