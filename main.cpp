#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>

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
    
    QMessageBox::information(nullptr, 
        QObject::tr("Connexion réussie"),
        QObject::tr("Connexion à la base de données établie avec succès!"),
        QMessageBox::Ok);

    MainWindow w;
    w.show();

    return a.exec();
}
