#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe_widget.h"
#include <QFile>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load global stylesheet from resources
    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }

    // Only keep the Employe module
    auto *employe = new EmployeWidget(this);
    ui->stackedMain->addWidget(employe);
    ui->stackedMain->setCurrentWidget(employe);

    // Hide navigation frame until login
    ui->navFrame->setVisible(false);

    // Show all menu buttons, but keep only Employe enabled
    ui->btnEmploye->setVisible(true);
    ui->btnEquipe->setVisible(true);
    ui->btnClient->setVisible(true);
    ui->btnLaboratoire->setVisible(true);
    ui->btnCommande->setVisible(true);
    ui->btnMachine->setVisible(true);

    ui->btnEmploye->setEnabled(true);
    ui->btnEquipe->setEnabled(false);
    ui->btnClient->setEnabled(false);
    ui->btnLaboratoire->setEnabled(false);
    ui->btnCommande->setEnabled(false);
    ui->btnMachine->setEnabled(false);

    // Menu navigation
    connect(ui->btnEmploye, &QPushButton::clicked, [this, employe]() {
        ui->stackedMain->setCurrentWidget(employe);
    });
    connect(ui->btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);

    // Show menu and authenticate after login button clicked
    connect(employe, &EmployeWidget::loginRequested, this, [this, employe]() {
        employe->setAuthenticated(true);  // Show employee tabs (Liste, Ajouter, etc.)
        ui->navFrame->setVisible(true);
        ui->stackedMain->setCurrentWidget(employe);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
