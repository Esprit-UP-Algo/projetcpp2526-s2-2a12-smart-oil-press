#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Charger et appliquer le stylesheet depuis les ressources
    QFile styleFile(":/stylesheet.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }
    
    // Connecter les boutons du menu aux pages
    connect(ui->btnEmployee, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageEmployee);
    });
    
    connect(ui->btnTeam, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageTeam);
    });
    
    connect(ui->btnClient, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageClient);
    });
    
    connect(ui->btnLaboratory, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageLaboratory);
    });
    
    connect(ui->btnOrder, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageOrder);
    });
    
    connect(ui->btnMachine, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageMachine);
    });
    
    // Afficher la page Machine par défaut
    ui->stackedPages->setCurrentWidget(ui->pageMachine);
}

MainWindow::~MainWindow()
{
    delete ui;
}
