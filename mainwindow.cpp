#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande_widget.h"
#include <QFile>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadStylesheet();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadStylesheet()
{
    QFile styleFile(":/stylesheet.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }
}

void MainWindow::on_btnCommande_clicked()
{
    CommandeWidget *commandeWidget = new CommandeWidget(this);
    ui->stackedMain->addWidget(commandeWidget);
    ui->stackedMain->setCurrentWidget(commandeWidget);
}

void MainWindow::on_btnEquipe_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageEquipe);
}

void MainWindow::on_btnClient_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageClient);
}

void MainWindow::on_btnLaboratoire_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageLaboratoire);
}

void MainWindow::on_btnFournisseur_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageFournisseur);
}

void MainWindow::on_btnMachine_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageMachine);
}
