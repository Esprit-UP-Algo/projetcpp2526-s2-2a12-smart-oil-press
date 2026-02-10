#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_centralwidget_customContextMenuRequested(const QPoint &pos)
{

}


void MainWindow::on_stats_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_Recherche_clicked()
{
   ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_planns_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

