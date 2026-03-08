#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // ── Oracle connection via ODBC ──────────────────────────────────────────
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("fedi");    //  votre username Oracle
    db.setPassword("fedi123");    //  votre mot de passe Oracle

    if (!db.open()) {
        QMessageBox::critical(nullptr, "Erreur de connexion",
            "Impossible de se connecter à Oracle.\n\n"
            "Vérifiez :\n"
            "• Le DSN ODBC 'Source_Projet2A' est configuré\n"
            "• Le nom d'utilisateur et mot de passe Oracle\n"
            "• Oracle est démarré\n\n"
            "Détail : " + db.lastError().text());
        return -1;
    }
    // ───────────────────────────────────────────────────────────────────────

    MainWindow w;
    w.setWindowTitle("Smart Oil Press Management");
    w.resize(1200, 700);
    w.show();

    return a.exec();
}