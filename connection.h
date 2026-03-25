#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>

struct LaboData {
    int id_labo;
    QString nom_labo;
    QString resultats;
    QString conformite;
    QString observations;
    QString adresse;
    double espace_labo;
    double espace_reste;
    QString review;
};

class Connection
{
public:
    Connection();
    bool createconnect();
    QString getLastError() const;
    
    // CRUD Operations
    bool addLabo(const LaboData& labo);
    bool updateLabo(const LaboData& labo);
    bool deleteLabo(int id);
    QList<LaboData> getAllLabos();
    LaboData getLaboById(int id);

private:
    void createLaboTable();
    QString m_lastError;
};

#endif // CONNECTION_H