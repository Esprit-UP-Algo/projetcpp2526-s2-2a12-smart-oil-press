#ifndef CONNECXION_H
#define CONNECXION_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QVariantMap>
#include <QList>

class Connection
{
public:
    static Connection* instance();
    bool createConnect();
    bool createTableIfNotExists();
    bool ajouterMachine(const QString& id, const QString& nom, const QString& categorie,
                        const QString& reference, const QString& dateAchat, const QString& etat,
                        const QString& localisation);
    bool ajouterEmploye(const QString& id, const QString& nom, const QString& prenom, int age,
                        const QString& telephone);
    bool ajouterIntervention(const QString& date, const QString& machineId, const QString& type,
                             const QString& technicien, double cout, const QString& statut);
    bool getMachines(QList<QVariantMap>& machines);
    void closeConnection();
    QString lastError() const;

private:
    Connection();
    ~Connection();
    Connection(const Connection&) = delete;
    Connection& operator=(const Connection&) = delete;

    static Connection* p_instance;
    QSqlDatabase db;
    QString m_lastError;
};

#endif // CONNECXION_H

