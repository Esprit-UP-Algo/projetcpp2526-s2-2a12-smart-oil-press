#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>

class Connection
{
public:
    static Connection* instance(); // Accès à l'instance unique
    bool createConnect(); // Méthode pour créer la connexion
    bool createTableIfNotExists();
    bool ajouterMachine(const QString& id, const QString& nom, const QString& categorie, const QString& reference, const QString& dateAchat, const QString& etat);
    bool getMachines(QList<QVariantMap>& machines);
    void closeConnection(); // Fermer la connexion

    // Récupère le texte de la dernière erreur SQL enregistrée
    QString lastError() const;

private:
    Connection(); // Constructeur privé
    ~Connection(); // Destructeur privé
    Connection(const Connection&) = delete; // Supprimer le constructeur de copie
    Connection& operator=(const Connection&) = delete; // Supprimer l'opérateur d'affectation

    static Connection* p_instance; // Pointeur vers l'instance unique
    QSqlDatabase db;
    QString m_lastError; // mémoire du dernier message d'erreur
};

#endif // CONNECTION_H

