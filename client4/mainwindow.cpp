#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QHeaderView>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QTextDocument>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Smart Oil Press Management - Clients");
    setMinimumSize(1200, 700);

    setupUiStyle();
    setupTableClients();
    setupConnections();
    loadSampleData();
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ----------------------------
// Setup Methods
// ----------------------------

void MainWindow::setupUiStyle()
{
    // Style pour les boutons de navigation sélectionnés
    ui->btnClient->setStyleSheet(
        "QPushButton { background:#798777; color:white; font-weight:bold; }"
    );
    
    // S'assurer que le premier onglet est affiché
    ui->tabWidget->setCurrentIndex(0);
    
    // Créer et ajouter le bouton Export PDF dans le coin du TabWidget
    QPushButton *btnExportPDF = new QPushButton("Exporter PDF", this);
    btnExportPDF->setObjectName("btnExporterPDF");
    btnExportPDF->setMinimumSize(120, 28);
    btnExportPDF->setMaximumSize(120, 28);
    btnExportPDF->setStyleSheet(
        "QPushButton { "
        "  background:#A2B29F; "
        "  border-radius:4px; "
        "  padding:4px; "
        "  font-weight:bold; "
        "  color:#2E2E2E; "
        "}"
        "QPushButton:hover { background:#798777; color:white; }"
    );
    ui->tabWidget->setCornerWidget(btnExportPDF, Qt::TopRightCorner);
    
    // Connecter le bouton
    connect(btnExportPDF, &QPushButton::clicked, this, &MainWindow::onExporterPDFClicked);
    
    // Style pour les champs de saisie - fond blanc
    QString inputStyle = 
        "QLineEdit { "
        "  background-color: white; "
        "  border: 1px solid #BDBDBD; "
        "  border-radius: 4px; "
        "  padding: 5px; "
        "  color: #212121; "
        "}"
        "QLineEdit:focus { "
        "  border: 2px solid #66BB6A; "
        "}";
    
    ui->txtRechercheNom->setStyleSheet(inputStyle);
    
    // Style pour les ComboBox - fond blanc
    QString comboStyle = 
        "QComboBox { "
        "  background-color: white; "
        "  border: 1px solid #BDBDBD; "
        "  border-radius: 4px; "
        "  padding: 5px; "
        "  color: #212121; "
        "}"
        "QComboBox:focus { "
        "  border: 2px solid #66BB6A; "
        "}"
        "QComboBox::drop-down { "
        "  border: none; "
        "  width: 20px; "
        "}"
        "QComboBox QAbstractItemView { "
        "  background-color: white; "
        "  selection-background-color: #C8E6C9; "
        "  selection-color: #1B5E20; "
        "}";
    
    ui->cmbType->setStyleSheet(comboStyle);
    ui->cmbStatut->setStyleSheet(comboStyle);
    
    // Style pour la zone de statistiques
    ui->txtStatistiques->setStyleSheet(
        "QTextEdit { "
        "  background-color: white; "
        "  color: #212121; "
        "  border: 1px solid #E0E0E0; "
        "  border-radius: 4px; "
        "  padding: 10px; "
        "}"
    );
}

void MainWindow::setupTableClients()
{
    // Configuration du tableau
    ui->tableClients->setColumnCount(6);
    QStringList headers;
    headers << "ID" << "Nom" << "Type" << "Téléphone" << "Email" << "Statut";
    ui->tableClients->setHorizontalHeaderLabels(headers);
    
    qDebug() << "Table clients setup - Columns:" << ui->tableClients->columnCount();
    
    // Style du header
    ui->tableClients->horizontalHeader()->setStyleSheet(
        "QHeaderView::section { background:#E8F5E9; color:#2E7D32; font-weight:bold; padding:8px; border: 1px solid #A5D6A7; }"
    );
    
    // Style pour les cellules du tableau
    ui->tableClients->setStyleSheet(
        "QTableWidget { "
        "  background-color: white; "
        "  gridline-color: #E0E0E0; "
        "  border: none; "
        "}"
        "QTableWidget::item { "
        "  padding: 8px; "
        "  color: #212121; "
        "  border-bottom: 1px solid #E0E0E0; "
        "}"
        "QTableWidget::item:selected { "
        "  background-color: #C8E6C9; "
        "  color: #1B5E20; "
        "}"
        "QTableWidget::item:alternate { "
        "  background-color: #F9F9F9; "
        "}"
    );
    
    // Ajuster les colonnes
    ui->tableClients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableClients->setAlternatingRowColors(true);
    ui->tableClients->setShowGrid(true);
    ui->tableClients->setVisible(true);
    
    // Ajuster la hauteur des lignes
    ui->tableClients->verticalHeader()->setDefaultSectionSize(35);
    ui->tableClients->verticalHeader()->hide();
}

void MainWindow::setupConnections()
{
    // Navigation buttons
    connect(ui->btnEmploye, &QPushButton::clicked, this, &MainWindow::onEmployeClicked);
    connect(ui->btnEquipe, &QPushButton::clicked, this, &MainWindow::onEquipeClicked);
    connect(ui->btnClient, &QPushButton::clicked, this, &MainWindow::onClientClicked);
    connect(ui->btnLaboratoire, &QPushButton::clicked, this, &MainWindow::onLaboratoireClicked);
    connect(ui->btnCommande, &QPushButton::clicked, this, &MainWindow::onCommandeClicked);
    connect(ui->btnMachine, &QPushButton::clicked, this, &MainWindow::onMachineClicked);
    
    // Quick actions
    connect(ui->btnActionAjouter, &QPushButton::clicked, this, &MainWindow::onActionAjouterClicked);
    connect(ui->btnActionModifier, &QPushButton::clicked, this, &MainWindow::onActionModifierClicked);
    connect(ui->btnActionSupprimer, &QPushButton::clicked, this, &MainWindow::onActionSupprrimerClicked);
    
    // Filter
    connect(ui->btnAppliquerFiltre, &QPushButton::clicked, this, &MainWindow::onAppliquerFiltreClicked);
    
    // Table selection
    connect(ui->tableClients, &QTableWidget::itemSelectionChanged, this, &MainWindow::onTableClientSelectionChanged);
}

void MainWindow::loadSampleData()
{
    // Données d'exemple
    ui->tableClients->setRowCount(5);
    
    qDebug() << "Loading sample data - Table rows:" << ui->tableClients->rowCount();
    qDebug() << "Table columns:" << ui->tableClients->columnCount();
    
    QStringList clients[5] = {
        {"001", "Mohamed Ali", "Particulier", "98 123 456", "m.ali@email.com", "Actif"},
        {"002", "Fatima Ben Said", "Entreprise", "98 234 567", "f.bensaid@email.com", "Actif"},
        {"003", "Ahmed Jmal", "Particulier", "98 345 678", "a.jmal@email.com", "Inactif"},
        {"004", "Leila Chedly", "Entreprise", "98 456 789", "l.chedly@email.com", "Actif"},
        {"005", "Sami Trabelsi", "Particulier", "98 567 890", "s.trabelsi@email.com", "En attente"}
    };
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 6; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(clients[i][j]);
            ui->tableClients->setItem(i, j, item);
        }
    }
    
    qDebug() << "Sample data loaded successfully";
    
    // Forcer la mise à jour de l'affichage
    ui->tableClients->viewport()->update();
    ui->tableClients->show();
    
    // Remplir les combos de filtres
    ui->cmbType->addItems({"Tous", "Particulier", "Entreprise"});
    ui->cmbStatut->addItems({"Tous", "Actif", "Inactif", "En attente"});
    
    // Statistiques d'exemple
    ui->txtStatistiques->setHtml(
        "<div style='color: #212121; padding: 10px;'>"
        "<h2 style='color: #2E7D32;'>📊 Statistiques des Clients</h2>"
        "<p><b>Total Clients:</b> <span style='color: #1976D2;'>5</span></p>"
        "<p><b>Clients Actifs:</b> <span style='color: #388E3C;'>3</span></p>"
        "<p><b>Clients Inactifs:</b> <span style='color: #D32F2F;'>1</span></p>"
        "<p><b>En attente:</b> <span style='color: #F57C00;'>1</span></p>"
        "<hr style='border: 1px solid #BDBDBD;'>"
        "<h3 style='color: #2E7D32;'>Par Type</h3>"
        "<p style='color: #424242;'>• Particuliers: 3</p>"
        "<p style='color: #424242;'>• Entreprises: 2</p>"
        "<hr style='border: 1px solid #BDBDBD;'>"
        "<h3 style='color: #2E7D32;'>Tendances</h3>"
        "<p style='color: #388E3C;'>📈 +20% ce mois</p>"
        "<p style='color: #1976D2;'>💰 Chiffre d'affaires: 15,000 DT</p>"
        "</div>"
    );
    
    // Alertes d'exemple
    ui->txtAlertes->setStyleSheet(
        "QTextEdit { "
        "  background-color: white; "
        "  color: #212121; "
        "  border: 1px solid #E0E0E0; "
        "  border-radius: 4px; "
        "  padding: 10px; "
        "}"
    );
    
    ui->txtAlertes->setHtml(
        "<div style='color: #212121; padding: 10px;'>"
        "<h2 style='color: #D32F2F;'>⚠️ Alertes et Notifications</h2>"
        "<hr style='border: 1px solid #BDBDBD;'>"
        
        "<h3 style='color: #F57C00;'>📅 Expiration de Contrats</h3>"
        "<div style='background-color: #FFF3E0; padding: 10px; margin: 10px 0; border-left: 4px solid #F57C00;'>"
        "<p style='margin: 5px 0;'><b>Client:</b> Fatima Ben Said</p>"
        "<p style='margin: 5px 0;'><b>Contrat expire le:</b> <span style='color: #E65100;'>15/02/2026 (4 jours)</span></p>"
        "<p style='margin: 5px 0;'><b>Type:</b> Contrat annuel - Service maintenance</p>"
        "</div>"
        
        "<div style='background-color: #FFF3E0; padding: 10px; margin: 10px 0; border-left: 4px solid #F57C00;'>"
        "<p style='margin: 5px 0;'><b>Client:</b> Leila Chedly</p>"
        "<p style='margin: 5px 0;'><b>Contrat expire le:</b> <span style='color: #E65100;'>20/02/2026 (9 jours)</span></p>"
        "<p style='margin: 5px 0;'><b>Type:</b> Contrat de fourniture</p>"
        "</div>"
        
        "<hr style='border: 1px solid #BDBDBD; margin: 20px 0;'>"
        
        "<h3 style='color: #D32F2F;'>🚚 Délais de Livraison Anormaux</h3>"
        "<div style='background-color: #FFEBEE; padding: 10px; margin: 10px 0; border-left: 4px solid #D32F2F;'>"
        "<p style='margin: 5px 0;'><b>Commande:</b> #CMD-2024-156</p>"
        "<p style='margin: 5px 0;'><b>Client:</b> Mohamed Ali</p>"
        "<p style='margin: 5px 0;'><b>Retard:</b> <span style='color: #C62828; font-weight: bold;'>7 jours</span></p>"
        "<p style='margin: 5px 0;'><b>Date prévue:</b> 04/02/2026</p>"
        "<p style='margin: 5px 0;'><b>Statut:</b> En transit - Problème logistique</p>"
        "</div>"
        
        "<div style='background-color: #FFEBEE; padding: 10px; margin: 10px 0; border-left: 4px solid #D32F2F;'>"
        "<p style='margin: 5px 0;'><b>Commande:</b> #CMD-2024-189</p>"
        "<p style='margin: 5px 0;'><b>Client:</b> Sami Trabelsi</p>"
        "<p style='margin: 5px 0;'><b>Retard:</b> <span style='color: #C62828; font-weight: bold;'>3 jours</span></p>"
        "<p style='margin: 5px 0;'><b>Date prévue:</b> 08/02/2026</p>"
        "<p style='margin: 5px 0;'><b>Statut:</b> En préparation - Retard fournisseur</p>"
        "</div>"
        
        "<hr style='border: 1px solid #BDBDBD; margin: 20px 0;'>"
        
        "<div style='background-color: #E3F2FD; padding: 15px; border-radius: 5px; margin-top: 20px;'>"
        "<h4 style='color: #1976D2; margin-top: 0;'>📊 Résumé des Alertes</h4>"
        "<p style='margin: 5px 0;'>• Contrats expirant bientôt: <b style='color: #F57C00;'>2</b></p>"
        "<p style='margin: 5px 0;'>• Livraisons en retard: <b style='color: #D32F2F;'>2</b></p>"
        "<p style='margin: 5px 0;'>• Clients nécessitant attention: <b style='color: #F57C00;'>4</b></p>"
        "</div>"
        "</div>"
    );
}

// ----------------------------
// Navigation Slots
// ----------------------------

void MainWindow::onEmployeClicked()
{
    QMessageBox::information(this, "Navigation", 
        "Module EMPLOYÉ sera disponible prochainement");
}

void MainWindow::onEquipeClicked()
{
    QMessageBox::information(this, "Navigation", 
        "Module ÉQUIPE sera disponible prochainement");
}

void MainWindow::onClientClicked()
{
    // Déjà sur cette page
    QMessageBox::information(this, "Navigation", "Vous êtes déjà sur la page Clients");
}

void MainWindow::onLaboratoireClicked()
{
    QMessageBox::information(this, "Navigation", 
        "Module LABORATOIRE sera disponible prochainement");
}

void MainWindow::onCommandeClicked()
{
    QMessageBox::information(this, "Navigation", 
        "Module COMMANDE sera disponible prochainement");
}

void MainWindow::onMachineClicked()
{
    QMessageBox::information(this, "Navigation", 
        "Module MACHINE sera disponible prochainement");
}

// ----------------------------
// Client Management Slots
// ----------------------------

void MainWindow::onExporterPDFClicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this, "Exporter en PDF", "", "PDF Files (*.pdf)"
    );
    
    if (fileName.isEmpty())
        return;
    
    // Créer le document HTML
    QString html = "<h1>Liste des Clients</h1><table border='1' cellspacing='0' cellpadding='5'>";
    html += "<tr><th>ID</th><th>Nom</th><th>Type</th><th>Téléphone</th><th>Email</th><th>Statut</th></tr>";
    
    for (int i = 0; i < ui->tableClients->rowCount(); ++i) {
        html += "<tr>";
        for (int j = 0; j < ui->tableClients->columnCount(); ++j) {
            html += "<td>" + ui->tableClients->item(i, j)->text() + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";
    
    QTextDocument document;
    document.setHtml(html);
    
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    document.print(&printer);
    
    QMessageBox::information(this, "Succès", 
        "Liste exportée en PDF avec succès!");
}

// ----------------------------
// Quick Actions Slots
// ----------------------------

void MainWindow::onActionAjouterClicked()
{
    showClientDialog(false);
}

void MainWindow::onActionModifierClicked()
{
    if (ui->tableClients->currentRow() == -1) {
        QMessageBox::warning(this, "Attention", 
            "Veuillez sélectionner un client à modifier");
        return;
    }
    showClientDialog(true);
}

void MainWindow::onActionSupprrimerClicked()
{
    if (ui->tableClients->currentRow() == -1) {
        QMessageBox::warning(this, "Attention", 
            "Veuillez sélectionner un client à supprimer");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation", 
        "Voulez-vous vraiment supprimer ce client ?",
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply == QMessageBox::Yes) {
        ui->tableClients->removeRow(ui->tableClients->currentRow());
        clearClientInfo();
        QMessageBox::information(this, "Succès", "Client supprimé avec succès");
    }
}

// ----------------------------
// Filter Slot
// ----------------------------

void MainWindow::onAppliquerFiltreClicked()
{
    QString nomRecherche = ui->txtRechercheNom->text().toLower();
    QString typeFiltre = ui->cmbType->currentText();
    QString statutFiltre = ui->cmbStatut->currentText();
    
    for (int i = 0; i < ui->tableClients->rowCount(); ++i) {
        bool visible = true;
        
        // Filtre par nom
        if (!nomRecherche.isEmpty()) {
            QString nom = ui->tableClients->item(i, 1)->text().toLower();
            if (!nom.contains(nomRecherche)) {
                visible = false;
            }
        }
        
        // Filtre par type
        if (typeFiltre != "Tous") {
            QString type = ui->tableClients->item(i, 2)->text();
            if (type != typeFiltre) {
                visible = false;
            }
        }
        
        // Filtre par statut
        if (statutFiltre != "Tous") {
            QString statut = ui->tableClients->item(i, 5)->text();
            if (statut != statutFiltre) {
                visible = false;
            }
        }
        
        ui->tableClients->setRowHidden(i, !visible);
    }
}

// ----------------------------
// Table Selection Slot
// ----------------------------

void MainWindow::onTableClientSelectionChanged()
{
    if (ui->tableClients->currentRow() != -1) {
        updateClientInfo();
    } else {
        clearClientInfo();
    }
}

// ----------------------------
// Helper Methods
// ----------------------------

void MainWindow::updateClientInfo()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) return;
    
    QString statut = ui->tableClients->item(row, 5)->text();
    ui->lblInfoStatut->setText("Statut : " + statut);
    ui->lblInfoScore->setText("Score : ⭐⭐⭐⭐");
    
    if (statut == "Actif") {
        ui->lblInfoAlertes->setText("Alertes : ✅ Aucune");
    } else if (statut == "En attente") {
        ui->lblInfoAlertes->setText("Alertes : ⚠️ Validation requise");
    } else {
        ui->lblInfoAlertes->setText("Alertes : ❌ Client inactif");
    }
}

void MainWindow::clearClientInfo()
{
    ui->lblInfoStatut->setText("Statut : -");
    ui->lblInfoScore->setText("Score : -");
    ui->lblInfoAlertes->setText("Alertes : -");
}

void MainWindow::showClientDialog(bool isEdit)
{
    QDialog dialog(this);
    dialog.setWindowTitle(isEdit ? "Modifier Client" : "Nouveau Client");
    dialog.setMinimumWidth(400);
    
    QVBoxLayout *mainLayout = new QVBoxLayout(&dialog);
    QFormLayout *formLayout = new QFormLayout();
    
    // Champs du formulaire
    QLineEdit *txtNom = new QLineEdit(&dialog);
    QComboBox *cmbType = new QComboBox(&dialog);
    cmbType->addItems({"Particulier", "Entreprise"});
    QLineEdit *txtTel = new QLineEdit(&dialog);
    QLineEdit *txtEmail = new QLineEdit(&dialog);
    QComboBox *cmbStatut = new QComboBox(&dialog);
    cmbStatut->addItems({"Actif", "Inactif", "En attente"});
    
    // Si modification, remplir avec les données existantes
    if (isEdit && ui->tableClients->currentRow() != -1) {
        int row = ui->tableClients->currentRow();
        txtNom->setText(ui->tableClients->item(row, 1)->text());
        cmbType->setCurrentText(ui->tableClients->item(row, 2)->text());
        txtTel->setText(ui->tableClients->item(row, 3)->text());
        txtEmail->setText(ui->tableClients->item(row, 4)->text());
        cmbStatut->setCurrentText(ui->tableClients->item(row, 5)->text());
    }
    
    formLayout->addRow("Nom:", txtNom);
    formLayout->addRow("Type:", cmbType);
    formLayout->addRow("Téléphone:", txtTel);
    formLayout->addRow("Email:", txtEmail);
    formLayout->addRow("Statut:", cmbStatut);
    
    mainLayout->addLayout(formLayout);
    
    // Boutons
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog
    );
    mainLayout->addWidget(buttonBox);
    
    connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    
    if (dialog.exec() == QDialog::Accepted) {
        if (txtNom->text().isEmpty()) {
            QMessageBox::warning(this, "Attention", "Le nom est obligatoire");
            return;
        }
        
        if (isEdit && ui->tableClients->currentRow() != -1) {
            // Modification
            int row = ui->tableClients->currentRow();
            ui->tableClients->item(row, 1)->setText(txtNom->text());
            ui->tableClients->item(row, 2)->setText(cmbType->currentText());
            ui->tableClients->item(row, 3)->setText(txtTel->text());
            ui->tableClients->item(row, 4)->setText(txtEmail->text());
            ui->tableClients->item(row, 5)->setText(cmbStatut->currentText());
            QMessageBox::information(this, "Succès", "Client modifié avec succès");
        } else {
            // Nouveau client
            int newRow = ui->tableClients->rowCount();
            ui->tableClients->insertRow(newRow);
            
            QString newId = QString::number(newRow + 1).rightJustified(3, '0');
            ui->tableClients->setItem(newRow, 0, new QTableWidgetItem(newId));
            ui->tableClients->setItem(newRow, 1, new QTableWidgetItem(txtNom->text()));
            ui->tableClients->setItem(newRow, 2, new QTableWidgetItem(cmbType->currentText()));
            ui->tableClients->setItem(newRow, 3, new QTableWidgetItem(txtTel->text()));
            ui->tableClients->setItem(newRow, 4, new QTableWidgetItem(txtEmail->text()));
            ui->tableClients->setItem(newRow, 5, new QTableWidgetItem(cmbStatut->currentText()));
            
            QMessageBox::information(this, "Succès", "Client ajouté avec succès");
        }
        
        updateClientInfo();
    }
}
