#include "connection.h"
#include <QDebug>
#include <QSqlDriver>

Connection::Connection()
{
}

bool Connection::createConnect()
{
    // Vérifier si le driver ODBC est disponible
    if (!QSqlDatabase::isDriverAvailable("QODBC")) {
        qDebug() << "Le driver QODBC n'est pas disponible.";
        return false;
    }

    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("source_projet2A");
    db.setUserName("hassen");
    db.setPassword("esprit26");

    if (db.open()) {
        qDebug() << "Connexion à la base de données Oracle réussie!";
        return true;
    } else {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
        return false;
    }
}