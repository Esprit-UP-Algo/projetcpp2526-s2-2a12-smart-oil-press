#include "equipe_widget.h"
#include "ui_equipe_widget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Safety: set the stacked page to match the currently selected top tab
    if(ui->stackedWidget->count() > 0) {
        on_topNavTabs_currentChanged(ui->topNavTabs->currentIndex());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_topNavTabs_currentChanged(int index)
{
    switch(index) {
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


