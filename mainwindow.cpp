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

    // Instantiate employe widget and add to stacked widget
    auto *employe = new EmployeWidget(this);
    ui->stackedMain->addWidget(employe);

    // Default page: show employe widget on startup
    ui->stackedMain->setCurrentWidget(employe);

    // Disable navigation until login
    ui->btnEmploye->setEnabled(false);
    ui->btnEquipe->setEnabled(false);
    ui->btnClient->setEnabled(false);
    ui->btnLaboratoire->setEnabled(false);
    ui->btnCommande->setEnabled(false);
    ui->btnMachine->setEnabled(false);

    // Simple UI navigation: show employe page when button clicked
    connect(ui->btnEmploye, &QPushButton::clicked, [this, employe]() {
        ui->stackedMain->setCurrentWidget(employe);
    });

    // UI-only login flow: unlock navigation and show welcome page
    connect(employe, &EmployeWidget::loginRequested, this, [this, employe]() {
        employe->setAuthenticated(true);
        ui->btnEmploye->setEnabled(true);
        ui->btnEquipe->setEnabled(true);
        ui->btnClient->setEnabled(true);
        ui->btnLaboratoire->setEnabled(true);
        ui->btnCommande->setEnabled(true);
        ui->btnMachine->setEnabled(true);
        ui->stackedMain->setCurrentWidget(ui->pagePlaceholder);
    });

    // Hide/show sidebar based on authentication
    connect(employe, &EmployeWidget::authenticatedChanged, this, [this](bool authenticated) {
        ui->navFrame->setVisible(authenticated);
    });

    // Hide sidebar at startup (before login)
    ui->navFrame->setVisible(false);

    // Other navigation buttons left unimplemented (UI only)
}

MainWindow::~MainWindow()
{
    delete ui;
}
