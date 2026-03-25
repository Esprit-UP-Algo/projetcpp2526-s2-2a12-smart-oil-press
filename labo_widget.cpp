#include "labo_widget.h"
#include "ui_labo_widget.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QDebug>

LaboWidget::LaboWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LaboWidget)
{
    ui->setupUi(this);
    setupConnections();
    populateTableWithSampleData();
    
    // Affiche la page par défaut (liste des laboratoires)
    if (ui->stackedWidget->count() > 0) {
        on_topNavTabs_currentChanged(ui->topNavTabs->currentIndex());
    }
}

LaboWidget::~LaboWidget()
{
    delete ui;
}

void LaboWidget::setupConnections()
{
    // Boutons de recherche et filtres
    if (ui->btnRechercher) {
        connect(ui->btnRechercher, &QPushButton::clicked, this, &LaboWidget::rechercherLaboratoires);
    }
    
    if (ui->btnTrier) {
        connect(ui->btnTrier, &QPushButton::clicked, this, &LaboWidget::trierLaboratoires);
    }
    
    // Export PDF
    if (ui->pushButton_25) {
        connect(ui->pushButton_25, &QPushButton::clicked, this, &LaboWidget::exporterPDF);
    }
    
    if (ui->btnExportPDF) {
        connect(ui->btnExportPDF, &QPushButton::clicked, this, &LaboWidget::exporterListePDF);
    }
    
    // Recherche en temps réel
    if (ui->lineEdit) {
        connect(ui->lineEdit, &QLineEdit::textChanged, this, &LaboWidget::rechercherLaboratoires);
    }
    
    // Options de tri
    if (ui->comboBox_2) {
        connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &LaboWidget::trierLaboratoires);
    }
    
    if (ui->checkBox_3) {
        connect(ui->checkBox_3, &QCheckBox::toggled, this, &LaboWidget::trierLaboratoires);
    }
    
    if (ui->checkBox_4) {
        connect(ui->checkBox_4, &QCheckBox::toggled, this, &LaboWidget::trierLaboratoires);
    }
}

void LaboWidget::populateTableWithSampleData()
{
    if (!ui->tableWidget) return;
    
    // Configure les en-têtes
    QStringList headers;
    headers << "ID Laboratoire" << "Nom" << "Type d'analyse" << "Conformité" << "Adresse" << "Espace";
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    
    // Ajoute des données exemple
    ui->tableWidget->setRowCount(5);
    
    QStringList ids = {"LAB001", "LAB002", "LAB003", "LAB004", "LAB005"};
    QStringList noms = {"Labo Central", "Labo Nord", "Labo Sud", "Labo Est", "Labo Ouest"};
    QStringList types = {"Chimique", "Bactériologique", "Physique", "Biologique", "Chimique"};
    QStringList conformites = {"Oui", "Oui", "Non", "Oui", "Non"};
    QStringList adresses = {"12 Rue de Paris", "45 Avenue Victor Hugo", "8 Boulevard Gambetta", 
                           "23 Rue Lafayette", "56 Rue Nationale"};
    QStringList espaces = {"150 m²", "200 m²", "120 m²", "180 m²", "90 m²"};
    
    for (int row = 0; row < 5; ++row) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ids[row]));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(noms[row]));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(types[row]));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(conformites[row]));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(adresses[row]));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(espaces[row]));
    }
    
    // Ajuste les colonnes
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
}

void LaboWidget::on_topNavTabs_currentChanged(int index)
{
    switch (index) {
    case 0: // Ajouter
        ui->stackedWidget->setCurrentWidget(ui->pageadd);
        break;
    case 1: // Liste
        ui->stackedWidget->setCurrentWidget(ui->page_rech);
        break;
    case 2: // Supprimer
        ui->stackedWidget->setCurrentWidget(ui->pagesupp);
        break;
    case 3: // Modifier
        ui->stackedWidget->setCurrentWidget(ui->pagemodif);
        break;
    case 4: // Statistiques
        ui->stackedWidget->setCurrentWidget(ui->page_stat);
        break;
    case 5: // Géolocalisation
        ui->stackedWidget->setCurrentWidget(ui->pageGeo);
        break;
    case 6: // Assistant IA
        ui->stackedWidget->setCurrentWidget(ui->pageAI);
        break;
    default:
        break;
    }
}

void LaboWidget::rechercherLaboratoires()
{
    if (!ui->lineEdit || !ui->tableWidget) return;
    
    QString searchText = ui->lineEdit->text();
    
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool match = searchText.isEmpty();
        for (int col = 0; col < ui->tableWidget->columnCount() && !match; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                match = true;
            }
        }
        ui->tableWidget->setRowHidden(row, !match);
    }
}

void LaboWidget::filterLaboratoires()
{
    QMessageBox::information(this, "Filtre", 
        "Fonctionnalité de filtre à implémenter");
}

void LaboWidget::trierLaboratoires()
{
    if (!ui->comboBox_2 || !ui->tableWidget) return;
    
    QString criteria = ui->comboBox_2->currentText();
    bool ascending = ui->checkBox_3 ? ui->checkBox_3->isChecked() : true;
    
    int column = 1; // Nom par défaut
    if (criteria == "ID") column = 0;
    else if (criteria == "Type d analyse") column = 2;
    else if (criteria == "Conformite") column = 3;
    
    ui->tableWidget->sortItems(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
}

void LaboWidget::exporterPDF()
{
    QMessageBox::information(this, "Export PDF", 
        "Fonctionnalité d'export PDF (Statistiques) à implémenter");
}

void LaboWidget::exporterListePDF()
{
    if (!ui->tableWidget || ui->tableWidget->rowCount() == 0) {
        QMessageBox::warning(this, "Export PDF", 
            "Aucune donnée à exporter dans la liste des laboratoires.");
        return;
    }
    
    int visibleCount = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (!ui->tableWidget->isRowHidden(row)) {
            visibleCount++;
        }
    }
    
    QMessageBox::information(this, "Export PDF", 
        QString("Export de la liste des laboratoires en PDF.\n\n"
                "Total laboratoires: %1\n"
                "Laboratoires affichés: %2")
        .arg(ui->tableWidget->rowCount())
        .arg(visibleCount));
}
