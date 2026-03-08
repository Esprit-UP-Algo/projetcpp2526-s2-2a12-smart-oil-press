#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "widget_client.h"
#include <QFile>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(QLatin1String(styleFile.readAll()));
        styleFile.close();
    }

    clientWidget = new WidgetClient(this);
    ui->stackedMain->addWidget(clientWidget);

    // Show menu immediately
    ui->navFrame->setVisible(true);
    ui->stackedMain->setCurrentWidget(ui->pageAccueil);

    // Other buttons visible but disabled
    ui->btnEmploye->setEnabled(false);
    ui->btnEquipe->setEnabled(false);
    ui->btnLaboratoire->setEnabled(false);
    ui->btnCommande->setEnabled(false);
    ui->btnMachine->setEnabled(false);


    connect(ui->btnClient, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(clientWidget);
    });

    connect(ui->btnContinuer, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(clientWidget);
    });

    connect(ui->btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);
}

MainWindow::~MainWindow()
{
    delete ui;
}
