#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Test de connexion SQLite
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbPath = QDir::currentPath() + "/test.db";
    db.setDatabaseName(dbPath);

    qDebug() << "Tentative de connexion à:" << dbPath;

    if (db.open()) {
        qDebug() << "Connexion SQLite réussie!";

        // Créer une table de test
        QSqlQuery query(db);
        if (query.exec("CREATE TABLE IF NOT EXISTS test (id INTEGER PRIMARY KEY, name TEXT)")) {
            qDebug() << "Table créée avec succès";

            // Insérer des données de test
            query.prepare("INSERT INTO test (name) VALUES (?)");
            query.addBindValue("Test Machine");
            if (query.exec()) {
                qDebug() << "Données insérées avec succès";
            } else {
                qDebug() << "Erreur insertion:" << query.lastError().text();
            }
        } else {
            qDebug() << "Erreur création table:" << query.lastError().text();
        }

        db.close();
    } else {
        qDebug() << "Erreur de connexion SQLite:" << db.lastError().text();
    }

    return 0;
}