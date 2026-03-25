#include "connection.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection::Connection() {}

bool Connection::createconnect()
{
    // Try ODBC connection first
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    
    // Using connection string directly instead of DSN
    QString connectionString = "Driver={Microsoft Access Driver (*.mdb, *.accdb)};DBQ=source_Projet2A;";
    db.setDatabaseName(connectionString);
    db.setUserName("SMARTOIL");
    db.setPassword("1234");

    if (db.open()) {
        qDebug() << "Database connected successfully!";
        m_lastError = "Connection successful";
        createLaboTable(); // Create table if it doesn't exist
        return true;
    } else {
        m_lastError = db.lastError().text();
        qDebug() << "ODBC Connection Error:" << m_lastError;
        
        // Fallback to SQLite for testing
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("test_database.db");
        
        if (db.open()) {
            qDebug() << "Fallback: SQLite database connected!";
            m_lastError = "Using SQLite fallback database";
            createLaboTable(); // Create table if it doesn't exist
            return true;
        } else {
            m_lastError = db.lastError().text();
            return false;
        }
    }
}

void Connection::createLaboTable()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "Cannot create table: database not connected";
        return;
    }
    
    QSqlQuery query(db);
    
    // Check if table exists
    QStringList tables = db.tables();
    if (tables.contains("LABORATOIRE", Qt::CaseInsensitive)) {
        qDebug() << "✅ LABORATOIRE table already exists";
        return;
    }
    
    qDebug() << "Creating LABORATOIRE table...";
    
    // Create LABORATOIRE table with complete schema
    QString createTableSQL = "CREATE TABLE LABORATOIRE ("
                            "id_labo INTEGER PRIMARY KEY,"
                            "nom_labo VARCHAR(100),"
                            "resultats VARCHAR(200),"
                            "conformite VARCHAR(50),"
                            "observations VARCHAR(200),"
                            "adresse VARCHAR(200),"
                            "espace_labo DECIMAL(10,2),"
                            "espace_reste DECIMAL(10,2),"
                            "review VARCHAR(200)"
                            ")";
    
    if (!query.exec(createTableSQL)) {
        qDebug() << "❌ Failed to create LABORATOIRE table:" << query.lastError().text();
        m_lastError = query.lastError().text();
    } else {
        qDebug() << "✅ LABORATOIRE table created successfully";
    }
}

QString Connection::getLastError() const
{
    return m_lastError;
}

// CRUD Operations
bool Connection::addLabo(const LaboData& labo)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        m_lastError = "Database is not connected";
        qDebug() << "ERROR: Database not open!";
        return false;
    }
    
    qDebug() << "Attempting to add laboratoire with name:" << labo.nom_labo;
    
    QSqlQuery query(db);
    
    // Escape apostrophes in string fields
    auto escapeString = [](const QString& str) {
        QString escaped = str;
        escaped.replace("'", "''");
        return escaped;
    };
    
    QString escapedNom = escapeString(labo.nom_labo);
    QString escapedResultats = escapeString(labo.resultats);
    QString escapedConformite = escapeString(labo.conformite);
    QString escapedObservations = escapeString(labo.observations);
    QString escapedAdresse = escapeString(labo.adresse);
    QString escapedReview = escapeString(labo.review);
    
    QString queryStr = QString("INSERT INTO LABORATOIRE (nom_labo, resultats, conformite, observations, adresse, espace_labo, espace_reste, review) "
                            "VALUES ('%1', '%2', '%3', '%4', '%5', %6, %7, '%8')")
                        .arg(escapedNom, escapedResultats, escapedConformite, escapedObservations, escapedAdresse)
                        .arg(labo.espace_labo).arg(labo.espace_reste).arg(escapedReview);
    
    qDebug() << "Query:" << queryStr;
    
    if (!query.exec(queryStr)) {
        m_lastError = query.lastError().text();
        qDebug() << "❌ Add error:" << m_lastError;
        qDebug() << "Driver error:" << query.lastError().driverText();
        qDebug() << "Database error:" << db.lastError().text();
        return false;
    }
    
    qDebug() << "✅ Laboratoire added successfully!";
    qDebug() << "Inserted ID:" << query.lastInsertId().toString();
    return true;
}

bool Connection::updateLabo(const LaboData& labo)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        m_lastError = "Database is not connected";
        return false;
    }
    
    QSqlQuery query(db);
    
    // Escape apostrophes in string fields
    auto escapeString = [](const QString& str) {
        QString escaped = str;
        escaped.replace("'", "''");
        return escaped;
    };
    
    QString escapedNom = escapeString(labo.nom_labo);
    QString escapedResultats = escapeString(labo.resultats);
    QString escapedConformite = escapeString(labo.conformite);
    QString escapedObservations = escapeString(labo.observations);
    QString escapedAdresse = escapeString(labo.adresse);
    QString escapedReview = escapeString(labo.review);
    
    QString queryStr = QString("UPDATE LABORATOIRE SET nom_labo = '%1', resultats = '%2', conformite = '%3', "
                            "observations = '%4', adresse = '%5', espace_labo = %6, espace_reste = %7, review = '%8' "
                            "WHERE id_labo = %9")
                        .arg(escapedNom, escapedResultats, escapedConformite, escapedObservations, escapedAdresse)
                        .arg(labo.espace_labo).arg(labo.espace_reste).arg(escapedReview).arg(labo.id_labo);
    
    qDebug() << "Query:" << queryStr;
    
    if (!query.exec(queryStr)) {
        m_lastError = query.lastError().text();
        qDebug() << "❌ Update error:" << m_lastError;
        return false;
    }
    qDebug() << "✅ Laboratoire updated successfully!";
    return true;
}

bool Connection::deleteLabo(int id)
{
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        m_lastError = "Database is not connected";
        return false;
    }
    
    QSqlQuery query(db);
    
    QString queryStr = QString("DELETE FROM LABORATOIRE WHERE id_labo = %1").arg(id);
    
    qDebug() << "Query:" << queryStr;
    
    if (!query.exec(queryStr)) {
        m_lastError = query.lastError().text();
        qDebug() << "❌ Delete error:" << m_lastError;
        return false;
    }
    qDebug() << "✅ Laboratoire deleted successfully!";
    return true;
}

QList<LaboData> Connection::getAllLabos()
{
    QList<LaboData> labos;
    QSqlDatabase db = QSqlDatabase::database();
    
    if (!db.isOpen()) {
        m_lastError = "Database is not connected";
        return labos;
    }
    
    QSqlQuery query(db);
    if (!query.exec("SELECT id_labo, nom_labo, resultats, conformite, observations, adresse, espace_labo, espace_reste, review FROM LABORATOIRE")) {
        m_lastError = query.lastError().text();
        qDebug() << "Query error:" << m_lastError;
        return labos;
    }
    
    while (query.next()) {
        LaboData labo;
        labo.id_labo = query.value("id_labo").toInt();
        labo.nom_labo = query.value("nom_labo").toString();
        labo.resultats = query.value("resultats").toString();
        labo.conformite = query.value("conformite").toString();
        labo.observations = query.value("observations").toString();
        labo.adresse = query.value("adresse").toString();
        labo.espace_labo = query.value("espace_labo").toDouble();
        labo.espace_reste = query.value("espace_reste").toDouble();
        labo.review = query.value("review").toString();
        labos.append(labo);
    }
    
    return labos;
}

LaboData Connection::getLaboById(int id)
{
    LaboData labo;
    QSqlDatabase db = QSqlDatabase::database();
    
    if (!db.isOpen()) {
        m_lastError = "Database is not connected";
        return labo;
    }
    
    QSqlQuery query(db);
    
    QString queryStr = QString("SELECT id_labo, nom_labo, resultats, conformite, observations, adresse, espace_labo, espace_reste, review FROM LABORATOIRE WHERE id_labo = %1").arg(id);
    
    if (!query.exec(queryStr) || !query.next()) {
        m_lastError = query.lastError().text();
        return labo;
    }
    
    labo.id_labo = query.value("id_labo").toInt();
    labo.nom_labo = query.value("nom_labo").toString();
    labo.resultats = query.value("resultats").toString();
    labo.conformite = query.value("conformite").toString();
    labo.observations = query.value("observations").toString();
    labo.adresse = query.value("adresse").toString();
    labo.espace_labo = query.value("espace_labo").toDouble();
    labo.espace_reste = query.value("espace_reste").toDouble();
    labo.review = query.value("review").toString();
    
    return labo;
}