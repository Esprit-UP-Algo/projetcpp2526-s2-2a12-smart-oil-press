#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe_widget.h"
#include "equipe_widget.h"
#include "widget_client.h"
#include "labo_widget.h"
#include "commande_widget.h"
#include "materiel_widget.h"
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

    // Instantiate all widgets and add to stacked widget
    auto *employe = new EmployeWidget(this);
    auto *equipe = new EquipeWidget(this);
    auto *client = new WidgetClient(this);
    auto *labo = new LaboWidget(this);
    auto *commande = new CommandeWidget(this);
    auto *materiel = new MaterielWidget(this);

    ui->stackedMain->addWidget(employe);     // index 1
    ui->stackedMain->addWidget(equipe);      // index 2
    ui->stackedMain->addWidget(client);      // index 3
    ui->stackedMain->addWidget(labo);        // index 4
    ui->stackedMain->addWidget(commande);    // index 5
    ui->stackedMain->addWidget(materiel);    // index 6

    // Default page: show employe widget on startup
    ui->stackedMain->setCurrentWidget(employe);

    // Disable navigation until login
    ui->btnEmploye->setEnabled(false);
    ui->btnEquipe->setEnabled(false);
    ui->btnClient->setEnabled(false);
    ui->btnLaboratoire->setEnabled(false);
    ui->btnCommande->setEnabled(false);
    ui->btnMachine->setEnabled(false);

    // Navigation: connect all buttons to their respective pages
    connect(ui->btnEmploye, &QPushButton::clicked, [this, employe]() {
        ui->stackedMain->setCurrentWidget(employe);
    });
    connect(ui->btnEquipe, &QPushButton::clicked, [this, equipe]() {
        ui->stackedMain->setCurrentWidget(equipe);
    });
    connect(ui->btnClient, &QPushButton::clicked, [this, client]() {
        ui->stackedMain->setCurrentWidget(client);
    });
    connect(ui->btnLaboratoire, &QPushButton::clicked, [this, labo]() {
        ui->stackedMain->setCurrentWidget(labo);
    });
    connect(ui->btnCommande, &QPushButton::clicked, [this, commande]() {
        ui->stackedMain->setCurrentWidget(commande);
    });
    connect(ui->btnMachine, &QPushButton::clicked, [this, materiel]() {
        ui->stackedMain->setCurrentWidget(materiel);
    });

    connect(ui->btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);

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
