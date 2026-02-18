#include "equipe_widget.h"
#include "ui_equipe_widget.h"

EquipeWidget::EquipeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EquipeWidget)
{
    ui->setupUi(this);
    // Ensure stacked page matches the currently selected top tab
    if (ui->stackedWidget->count() > 0) {
        on_topNavTabs_currentChanged(ui->topNavTabs->currentIndex());
    }
}

EquipeWidget::~EquipeWidget()
{
    delete ui;
}


void EquipeWidget::on_topNavTabs_currentChanged(int index)
{
    switch (index) {
    case 0: // Ajouter
        ui->stackedWidget->setCurrentWidget(ui->pageadd);
        break;
    case 1: // Gestion
        ui->stackedWidget->setCurrentWidget(ui->page_rech);
        break;
    case 2: // Supprimer
        ui->stackedWidget->setCurrentWidget(ui->pagesupp);
        break;
    case 3: // Modifier
        ui->stackedWidget->setCurrentWidget(ui->pagemodif);
        break;
    case 4: // Statistique
        ui->stackedWidget->setCurrentWidget(ui->page_stat);
        break;
    case 5: // Suggestion
        ui->stackedWidget->setCurrentWidget(ui->sugg);
        break;
    case 6: // Planification
        ui->stackedWidget->setCurrentWidget(ui->page_planification);
        break;
    default:
        break;
    }
}


