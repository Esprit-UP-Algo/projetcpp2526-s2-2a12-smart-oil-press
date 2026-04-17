#ifndef MACHINE_H
#define MACHINE_H

#include <QDate>
#include <QDateTime>
#include <QList>
#include <QString>

struct MachineData
{
    int idMachine = 0;
    QString nom;
    QString categorie;
    QString reference;
    QDate dateAchat;
    QString etatAchat;
    QString localisation;
    QDate dateFinGarantie;
    int idLabo = 0;
};

struct MachineFilter
{
    bool hasId = false;
    int idMachine = 0;
    QString nom;
    QString categorie;
    QString etat;
};

struct MachineStatsSummary
{
    int totalMachines = 0;
    int enService = 0;
    int enPanne = 0;
    int maintenance = 0;
    int horsService = 0;
    int enStock = 0;
    int enAttente = 0;
};

struct MachineCategoryStats
{
    QString category;
    int count = 0;
};

struct MachineLabStats
{
    QString labName;
    int machineCount = 0;
};

struct MachineHistoryData
{
    int id = 0;
    int idMachine = 0;
    QDateTime dateIntervention;
    QString typeIntervention;
    QString description;
    QString responsable;
    QString resultat;
    QString niveauUrgence;
    double coutIntervention = 0.0;
    int dureeIntervention = 0;
    QString pieceRemplacee;
};

struct MachineYearlyStats
{
    int year = 0;
    int count = 0;
};

class MachineWidget
{
public:
    static bool addMachine(const MachineData &data, QString *errorMessage = nullptr);
    static bool getMachineById(int idMachine, MachineData *outData, QString *errorMessage = nullptr);
    static bool updateMachine(int idMachine, const MachineData &data, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool deleteMachine(int idMachine, int *rowsAffected = nullptr, QString *errorMessage = nullptr);
    static bool listMachines(QList<MachineData> *outRows, QString *errorMessage = nullptr);
    static bool getStatsSummary(MachineStatsSummary *outStats, QString *errorMessage = nullptr);
    static bool getMachinesByCategory(QList<MachineCategoryStats> *outStats, QString *errorMessage = nullptr);
    static bool getMachinesByLab(QList<MachineLabStats> *outStats, QString *errorMessage = nullptr);
    static bool getMachinesByYear(QList<MachineYearlyStats> *outStats, QString *errorMessage = nullptr);
    static bool listMachineHistory(QList<MachineHistoryData> *outRows, QString *errorMessage = nullptr);
    static bool logMachineHistory(int idMachine, const QString &typeIntervention, QString *errorMessage = nullptr);
    static QString resolveMachineTable();
};

#endif // MACHINE_H