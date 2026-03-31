#include "mainwindow.h"
#include "connection.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Connexion à la base de données
    Connection connexion;
    bool isConnected = connexion.createConnect();

    if (!isConnected) {
        QMessageBox::critical(nullptr,
            QObject::tr("Erreur de connexion"),
            QObject::tr("Impossible de se connecter à la base de données 'source_projet2A'.\n"
                        "Vérifiez vos identifiants et la disponibilité du serveur."),
            QMessageBox::Ok);
        return 1;
    }

    qDebug() << "Creating MainWindow...";
    MainWindow w;
    qDebug() << "MainWindow created.";
    w.show();
    qDebug() << "MainWindow shown.";
    return a.exec();
}
