#include "connexion.h"
#include <QSqlError>
#include <QDebug>
#include <QStandardPaths>
#include <QSqlDatabase>

// Initialisation du pointeur d'instance
Connection* Connection::p_instance = nullptr;

// Constructeur privé
Connection::Connection()
{
    // Utiliser ODBC pour se connecter à Oracle
    qDebug() << "Utilisation du driver QODBC pour Oracle";
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

    // Configuration ODBC/Oracle
    db.setDatabaseName("source_projet_2A12");      // DSN
    db.setUserName("yomna");                       // Utilisateur Oracle
    db.setPassword("esprit18");                    // Mot de passe Oracle
    qDebug() << "Tentative connexion ODBC Oracle (DSN: source_projet_2A12)...";

    if (db.open()) {
        qDebug() << "✓ Connexion à la base de données Oracle réussie!";
        test = true;
    } else {
        m_lastError = db.lastError().text();
        qDebug() << "✗ Erreur de connexion Oracle:" << m_lastError;
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

bool Connection::createTableIfNotExists()
{
    if (!db.isOpen()) {
        m_lastError = "Database not open";
        qDebug() << "Base de données non ouverte lors de la création des tables";
        return false;
    }

    QSqlQuery query(db);

    // SQLite uniquement
    QString sqlMachines = "CREATE TABLE IF NOT EXISTS machines (id TEXT PRIMARY KEY, nom TEXT, categorie TEXT, reference TEXT, date_achat TEXT, etat TEXT, localisation TEXT)";
    QString sqlEmployes = "CREATE TABLE IF NOT EXISTS employes (id TEXT PRIMARY KEY, nom TEXT, prenom TEXT, age INTEGER, telephone TEXT)";
    QString sqlInterventions = "CREATE TABLE IF NOT EXISTS interventions (id INTEGER PRIMARY KEY AUTOINCREMENT, date TEXT, machine_id TEXT, type TEXT, technicien TEXT, cout REAL, statut TEXT, FOREIGN KEY(machine_id) REFERENCES machines(id))";

    auto execCreate = [&](const QString& sql, const QString& tableName) {
        if (sql.isEmpty()) {
            return true;
        }
        if (!query.exec(sql)) {
            QString err = query.lastError().text();
            if (err.contains("ORA-00955") || err.contains("already exists")) {
                qDebug() << "Table" << tableName << "déjà existante (OK)";
                return true;
            }
            m_lastError = err;
            qDebug() << "Erreur création table" << tableName << ":" << err;
            return false;
        }
        qDebug() << "Création de la table" << tableName << "réussie ou déjà existante.";
        return true;
    };

    if (!execCreate(sqlMachines, "machines")) return false;
    if (!execCreate(sqlEmployes, "employes")) return false;
    if (!execCreate(sqlInterventions, "interventions")) return false;

    return true;
}

bool Connection::ajouterMachine(const QString& id, const QString& nom, const QString& categorie,
                                const QString& reference, const QString& dateAchat, const QString& etat,
                                const QString& localisation)
{
    if (!db.isOpen() && !createConnect()) {
        m_lastError = "DB non ouverte";
        return false;
    }

    QSqlQuery query(db);
    // Oracle: ID_MACHINE doit être numérique
    // Convertir id (ex: "MCH-001") en nombre (ex: 1)
    bool idOk = false;
    int idMachine = 0;
    if (id.contains("-")) {
        // Format "MCH-001" -> extraire le numéro
        idMachine = id.split("-").at(1).toInt(&idOk);
    } else {
        idMachine = id.toInt(&idOk);
    }
    
    if (!idOk) {
        // Si pas numérique, générer automatiquement
        QSqlQuery countQuery(db);
        if (countQuery.exec("SELECT MAX(ID_MACHINE) FROM MACHINES")) {
            if (countQuery.next()) {
                idMachine = countQuery.value(0).toInt() + 1;
            } else {
                idMachine = 1;
            }
        } else {
            idMachine = 1;
        }
    }

    // Insérer avec ID numérique et date convertie
    query.prepare("INSERT INTO MACHINES (ID_MACHINE, NOM, CATEGORIE, REFERENCE, DATE_ACHAT, ETAT_ACHAT, LOCALISATION) "
                  "VALUES (?, ?, ?, ?, TO_DATE(?, 'DD/MM/YYYY'), ?, ?)");

    query.addBindValue(idMachine);
    query.addBindValue(nom);
    query.addBindValue(categorie);
    query.addBindValue(reference);
    query.addBindValue(dateAchat);  // Format: DD/MM/YYYY
    query.addBindValue(etat);
    query.addBindValue(localisation);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        qDebug() << "Erreur ajout machine:" << m_lastError;
        return false;
    }
    qDebug() << "✓ Machine ajoutée avec succès (ID:" << idMachine << ")";
    return true;
}

bool Connection::ajouterEmploye(const QString& id, const QString& nom, const QString& prenom, int age,
                                const QString& telephone)
{
    if (!db.isOpen() && !createConnect()) {
        m_lastError = "DB non ouverte";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO employes (id, nom, prenom, age, telephone) VALUES (?, ?, ?, ?, ?)");
    query.addBindValue(id);
    query.addBindValue(nom);
    query.addBindValue(prenom);
    query.addBindValue(age);
    query.addBindValue(telephone);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        qDebug() << "Erreur ajout employe:" << m_lastError;
        return false;
    }
    return true;
}

bool Connection::ajouterIntervention(const QString& date, const QString& machineId, const QString& type,
                                     const QString& technicien, double cout, const QString& statut)
{
    if (!db.isOpen() && !createConnect()) {
        m_lastError = "DB non ouverte";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO interventions (date, machine_id, type, technicien, cout, statut) VALUES (?, ?, ?, ?, ?, ?)");
    query.addBindValue(date);
    query.addBindValue(machineId);
    query.addBindValue(type);
    query.addBindValue(technicien);
    query.addBindValue(cout);
    query.addBindValue(statut);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        qDebug() << "Erreur ajout intervention:" << m_lastError;
        return false;
    }
    return true;
}

bool Connection::getMachines(QList<QVariantMap>& machines)
{
    machines.clear();
    if (!db.isOpen() && !createConnect()) {
        m_lastError = "DB non ouverte";
        return false;
    }

    QSqlQuery query(db);
    // Lire depuis Oracle et formater l'ID en concaténant 'MCH-' + numéro
    QString sql = "SELECT 'MCH-' || LPAD(ID_MACHINE, 3, '0') AS id, NOM AS nom, CATEGORIE AS categorie, "
                  "REFERENCE AS reference, TO_CHAR(DATE_ACHAT, 'DD/MM/YYYY') AS date_achat, "
                  "ETAT_ACHAT AS etat, LOCALISATION AS localisation FROM MACHINES";

    if (!query.exec(sql)) {
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
        m["localisation"] = query.value(6);
        machines.append(m);
    }

    qDebug() << "✓ Machines lues depuis Oracle:" << machines.size();
    return true;
}

QString Connection::lastError() const
{
    return m_lastError;
}

