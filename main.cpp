#include "mainwindow.h"
#include "connection.h"

#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Test database connection
    Connection conn;
    if (conn.createconnect()) {
        QMessageBox::information(nullptr, "✓ Connection Successful", 
            "Successfully connected to Oracle database!\n\n"
            "Database: source_Projet2A\n"
            "Status: Connected");
    } else {
        QMessageBox::critical(nullptr, "✗ Connection Failed", 
            "Failed to connect to the database!\n\n"
            "Error Details:\n" + conn.getLastError());
    }
    
    MainWindow w;
    w.show();
    return a.exec();
}