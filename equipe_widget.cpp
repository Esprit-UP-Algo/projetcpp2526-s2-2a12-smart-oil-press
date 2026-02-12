#include "equipe_widget.h"
#include "ui_equipe_widget.h"
#include <QFile>
#include <QApplication>

EquipeWidget::EquipeWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::EquipeWidget)
{
    ui->setupUi(this);

    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }

    // Safety check: Start the app on the first page (usually index 0)
    if(ui->stackedWidget->count() > 0) {
        ui->stackedWidget->setCurrentIndex(0);
    }
}

EquipeWidget::~EquipeWidget()
{
    delete ui;
}

// All previous button functions (stats, Recherche, sugg_2, etc.) have been removed.
// You can now re-add them one by one using "Go to slot..." in the Designer.

void EquipeWidget::on_Recherche_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rech);
}



void EquipeWidget::on_stats_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_stat);
}


void EquipeWidget::on_sugg_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->sugg);
}


void EquipeWidget::on_plan_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_plannification);
}


void EquipeWidget::on_ajout_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pageadd);
}


void EquipeWidget::on_Retour_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rech);
}


void EquipeWidget::on_Retour_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rech);
}


void EquipeWidget::on_pushButton_21_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagemodif);
}


void EquipeWidget::on_supprimer_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pagesupp);
}


void EquipeWidget::on_Retour_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->page_rech);

}

