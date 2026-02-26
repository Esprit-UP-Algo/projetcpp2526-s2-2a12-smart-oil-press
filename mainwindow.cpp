#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe_widget.h"
#include "equipe_widget.h"
#include "commande_widget.h"
#include "labo_widget.h"
#include "widget_client.h"
#include "machine_widget.h"
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

    // Create and add Employe module
    employeWidget = new EmployeWidget(this);
    ui->stackedMain->addWidget(employeWidget);
    ui->stackedMain->setCurrentWidget(employeWidget);

    // Create and add Equipe module
    equipeWidget = new EquipeWidget(this);
    ui->stackedMain->addWidget(equipeWidget);

    // Create and add Commande module
    commandeWidget = new CommandeWidget(this);
    ui->stackedMain->addWidget(commandeWidget);

    // Create and add Labo module
    laboWidget = new LaboWidget(this);
    ui->stackedMain->addWidget(laboWidget);

    // Create and add Client module
    clientWidget = new WidgetClient(this);
    ui->stackedMain->addWidget(clientWidget);

    // Create and add Machine module
    machineWidget = new MachineWidget(this);
    ui->stackedMain->addWidget(machineWidget);

    // Cacher le menu de navigation au démarrage (visible après connexion)
    ui->navFrame->setVisible(false);

    // Show all menu buttons
    ui->btnEmploye->setVisible(true);
    ui->btnEquipe->setVisible(true);
    ui->btnClient->setVisible(true);
    ui->btnLaboratoire->setVisible(true);
    ui->btnCommande->setVisible(true);
    ui->btnMachine->setVisible(true);

    // Enable Employe, Equipe, Commande, Laboratoire and Client, disable others for now
    ui->btnEmploye->setEnabled(true);
    ui->btnEquipe->setEnabled(true);
    ui->btnClient->setEnabled(true);
    ui->btnLaboratoire->setEnabled(true);
    ui->btnCommande->setEnabled(true);
    ui->btnMachine->setEnabled(true);

    // Menu navigation - Employe
    connect(ui->btnEmploye, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(employeWidget);
    });

    // Menu navigation - Equipe
    connect(ui->btnEquipe, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(equipeWidget);
    });

    // Menu navigation - Commande
    connect(ui->btnCommande, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(commandeWidget);
    });

    // Menu navigation - Laboratoire
    connect(ui->btnLaboratoire, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(laboWidget);
    });

    // Menu navigation - Client
    connect(ui->btnClient, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(clientWidget);
    });

    // Menu navigation - Machine
    connect(ui->btnMachine, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(machineWidget);
    });

    connect(ui->btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);

    // Après connexion : afficher la page d'accueil
    connect(employeWidget, &EmployeWidget::loginRequested, this, [this]() {
        employeWidget->setAuthenticated(true);  // Préparer les onglets employé
        ui->stackedMain->setCurrentWidget(ui->pageAccueil);  // Afficher la page d'accueil
    });

    // Bouton Continuer : afficher le menu et commencer la navigation
    connect(ui->btnContinuer, &QPushButton::clicked, this, [this]() {
        ui->navFrame->setVisible(true);         // Afficher le menu de navigation
        ui->stackedMain->setCurrentWidget(employeWidget);  // Aller au module Employé
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
