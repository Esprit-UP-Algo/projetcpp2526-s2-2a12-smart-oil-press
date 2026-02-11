#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Safety check: Start the app on the first page (usually index 0)
    if(ui->stackedWidget->count() > 0) {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// All previous button functions (stats, Recherche, sugg_2, etc.) have been removed.
// You can now re-add them one by one using "Go to slot..." in the Designer.

void MainWindow::on_Recherche_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rech);
}



void MainWindow::on_stats_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_stat);
}


void MainWindow::on_sugg_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sugg);
}


void MainWindow::on_plan_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_plannification);
}


void MainWindow::on_ajout_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pageadd);
}


void MainWindow::on_Retour_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->page_rech);
}


void MainWindow::on_Retour_2_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->page_rech);
}


void MainWindow::on_pushButton_21_clicked()
{
  ui->stackedWidget->setCurrentWidget(ui->pagemodif);
}


void MainWindow::on_supprimer_clicked()
{
   ui->stackedWidget->setCurrentWidget(ui->pagesupp);
}


void MainWindow::on_Retour_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rech);

}

