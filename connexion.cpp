



#include "connexion.h"
#include <QSqlError>
#include <QDebug>

// Initialisation du pointeur d'instance
Connection* Connection::p_instance = nullptr;

// Constructeur privé
Connection::Connection()
{
    // Initialisation de la base de données
    db = QSqlDatabase::addDatabase("QODBC");
}

// Méthode statique pour obtenir l'instance unique
Connection* Connection::instance()
{
    if (p_instance == nullptr) {
        p_instance = new Connection();
    }
    return p_instance;
}

// Méthode pour établir la connexion
bool Connection::createConnect()
{
    bool test = false;

    db.setDatabaseName("Source_Projet_2A12");//inserer le nom de la source de données
    db.setUserName("Ayoub");//inserer nom de l'utilisateur
    db.setPassword("1234");//inserer mot de passe de cet utilisateur

    if (db.open()) {
        test = true;
        qDebug() << "Connexion à la base de données réussie";
        // créer la table machines si elle n'existe pas encore
        if (!createTableIfNotExists()) {
            m_lastError = db.lastError().text();
            qDebug() << "Impossible de créer ou vérifier la table machines:" << m_lastError;
        }
    } else {
        m_lastError = db.lastError().text();
        qDebug() << "Erreur de connexion:" << m_lastError;
    }

    return test;
}

// Fermer la connexion
void Connection::closeConnection()
{
    if (db.isOpen()) {
        db.close();
    }
}

// Création de la table machines si elle n'existe pas
bool Connection::createTableIfNotExists()
{
    if (!db.isOpen()) {
        m_lastError = "Database not open";
        qDebug() << "Base de données non ouverte lors de la création de la table";
        return false;
    }

    QSqlQuery query(db);
    QString driver = db.driverName().toLower();
    bool isOracle = driver.contains("oci") || driver.contains("oracle");

    QString sql;
    if (isOracle) {
        // Oracle ne gère pas IF NOT EXISTS, on utilise un bloc PL/SQL
        sql =
            "BEGIN "
            "EXECUTE IMMEDIATE 'CREATE TABLE machines (\"id\" VARCHAR2(50) PRIMARY KEY, "
            "\"nom\" VARCHAR2(100), "
            "\"categorie\" VARCHAR2(50), "
            "\"reference\" VARCHAR2(50), "
            "\"date_achat\" VARCHAR2(20), "
            "\"etat\" VARCHAR2(50))'; "
            "EXCEPTION WHEN OTHERS THEN "
            "IF SQLCODE != -955 THEN RAISE; END IF; "
            "END;";
    } else {
        sql =
            "CREATE TABLE IF NOT EXISTS machines ("
            "\"id\" VARCHAR(50) PRIMARY KEY, "
            "\"nom\" VARCHAR(100), "
            "\"categorie\" VARCHAR(50), "
            "\"reference\" VARCHAR(50), "
            "\"date_achat\" VARCHAR(20), "
            "\"etat\" VARCHAR(50))";
    }

    if (!query.exec(sql)) {
        m_lastError = query.lastError().text();
        qDebug() << "Erreur création table machines:" << m_lastError;
        // on ne renvoie pas tout de suite false, on continue pour tenter d'ajouter colonne
    }

    // vérifier que la colonne etat existe
    if (!query.exec("SELECT \"etat\" FROM machines WHERE 1=0")) {
        QString err = query.lastError().text();
        if (err.contains("ORA-00904") || err.contains("invalid identifier")) {
            // ajouter la colonne manquante
            QSqlQuery q2(db);
            QString alter;
            if (isOracle)
                alter = "ALTER TABLE machines ADD (\"etat\" VARCHAR2(50))";
            else
                alter = "ALTER TABLE machines ADD (\"etat\" VARCHAR(50))";
            if (!q2.exec(alter)) {
                m_lastError = q2.lastError().text();
                qDebug() << "Impossible d'ajouter colonne etat:" << m_lastError;
                return false;
            }
        } else {
            m_lastError = err;
            qDebug() << "Erreur inattendue lors de la vérification de la colonne etat:" << err;
            return false;
        }
    }

    return true;
}

// Ajouter une machine dans la base
bool Connection::ajouterMachine(const QString& id, const QString& nom, const QString& categorie,
                                const QString& reference, const QString& dateAchat, const QString& etat)
{
    if (!db.isOpen()) {
        // tenter de ré-ouvrir automatiquement
        qDebug() << "Connexion perdue, tentative de reconnexion";
        if (!createConnect()) {
            m_lastError = "Impossible de rouvrir la base de données";
            return false;
        }
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO machines (\"id\", \"nom\", \"categorie\", \"reference\", \"date_achat\", \"etat\") "
                  "VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(id);
    query.addBindValue(nom);
    query.addBindValue(categorie);
    query.addBindValue(reference);
    query.addBindValue(dateAchat);
    query.addBindValue(etat);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        qDebug() << "Erreur ajout machine:" << m_lastError;
        return false;
    }
    return true;
}

// Récupérer toutes les machines
bool Connection::getMachines(QList<QVariantMap>& machines)
{
    machines.clear();
    if (!db.isOpen()) {
        m_lastError = "Database not open";
        qDebug() << "Base de données non ouverte lors de la lecture des machines";
        return false;
    }

    QSqlQuery query(db);
    if (!query.exec("SELECT \"id\", \"nom\", \"categorie\", \"reference\", \"date_achat\", \"etat\" FROM machines")) {
        m_lastError = query.lastError().text();
        qDebug() << "Erreur lecture machines:" << m_lastError;
        return false;
    }

    while (query.next()) {
        QVariantMap m;
        m["id"] = query.value(0);
        m["nom"] = query.value(1);
        m["categorie"] = query.value(2);
        m["reference"] = query.value(3);
        m["date_achat"] = query.value(4);
        m["etat"] = query.value(5);
        machines.append(m);
    }
    return true;
}

// Récupérer le dernier message d'erreur
QString Connection::lastError() const
{
    return m_lastError;
}

// Destructeur privé
Connection::~Connection()
{
    closeConnection();
}





