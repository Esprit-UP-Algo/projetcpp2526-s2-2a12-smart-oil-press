#include "connection.h"
#include <QDebug>

Connection::Connection()
{
}

bool Connection::createConnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    
    // Configuration de la base de données Oracle
    db.setDatabaseName("source_projet2A");
    db.setUserName("hassen");
    db.setPassword("esprit26");
    
    if (db.open()) {
        test = true;
        qDebug() << "Connexion à la base de données Oracle réussie!";
    } else {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
    }
    
    return test;
}
