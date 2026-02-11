#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QDate>
#include <QTableWidgetItem>
#include <QDoubleSpinBox>
#include <QHeaderView>

// ==================== AjouterMachineDialog ====================
AjouterMachineDialog::AjouterMachineDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void AjouterMachineDialog::setupUI()
{
    setWindowTitle("Ajouter une nouvelle machine");
    setModal(true);
    resize(500, 550); // Réduit car on a supprimé Équipe Responsable
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();
    
    nomInput = new QLineEdit();
    nomInput->setPlaceholderText("Nom de la machine");
    formLayout->addRow("Nom :", nomInput);
    
    referenceInput = new QLineEdit();
    referenceInput->setPlaceholderText("Référence");
    formLayout->addRow("Référence :", referenceInput);
    
    categorieCombo = new QComboBox();
    categorieCombo->addItems({"Presse", "Moteur", "Filtre", "Capteur", "Autre"});
    formLayout->addRow("Catégorie :", categorieCombo);
    
    etatCombo = new QComboBox();
    etatCombo->addItems({"En service", "Panne", "Maintenance", "Hors service"});
    formLayout->addRow("État :", etatCombo);
    
    localisationInput = new QLineEdit();
    localisationInput->setPlaceholderText("Atelier, Ligne...");
    formLayout->addRow("Localisation :", localisationInput);
    
    dateAchat = new QDateEdit();
    dateAchat->setDate(QDate::currentDate());
    dateAchat->setCalendarPopup(true);
    formLayout->addRow("Date d'achat :", dateAchat);
    
    garantieFin = new QDateEdit();
    garantieFin->setDate(QDate::currentDate().addYears(1));
    garantieFin->setCalendarPopup(true);
    formLayout->addRow("Garantie fin :", garantieFin);
    
    descriptionInput = new QTextEdit();
    descriptionInput->setMaximumHeight(100);
    formLayout->addRow("Description :", descriptionInput);
    
    layout->addLayout(formLayout);
    
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    layout->addWidget(buttons);
    setLayout(layout);
}

// ==================== ModifierMachineDialog ====================
ModifierMachineDialog::ModifierMachineDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void ModifierMachineDialog::setupUI()
{
    setWindowTitle("Modifier la machine");
    setModal(true);
    resize(500, 500); // Réduit car on a supprimé Équipe Responsable
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();
    
    idLabel = new QLabel();
    formLayout->addRow("ID Matériel :", idLabel);
    
    nomInput = new QLineEdit();
    formLayout->addRow("Nom :", nomInput);
    
    referenceInput = new QLineEdit();
    formLayout->addRow("Référence :", referenceInput);
    
    categorieCombo = new QComboBox();
    categorieCombo->addItems({"Presse", "Moteur", "Filtre", "Capteur", "Autre"});
    formLayout->addRow("Catégorie :", categorieCombo);
    
    etatCombo = new QComboBox();
    etatCombo->addItems({"En service", "Panne", "Maintenance", "Hors service"});
    formLayout->addRow("État :", etatCombo);
    
    localisationInput = new QLineEdit();
    formLayout->addRow("Localisation :", localisationInput);
    
    dateAchat = new QDateEdit();
    dateAchat->setDate(QDate::currentDate());
    dateAchat->setCalendarPopup(true);
    formLayout->addRow("Date d'achat :", dateAchat);
    
    garantieFin = new QDateEdit();
    garantieFin->setDate(QDate::currentDate().addYears(1));
    garantieFin->setCalendarPopup(true);
    formLayout->addRow("Garantie fin :", garantieFin);
    
    layout->addLayout(formLayout);
    
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    layout->addWidget(buttons);
    setLayout(layout);
}

void ModifierMachineDialog::setMachineData(const QString& id, const QString& nom, const QString& reference,
                                          const QString& categorie, const QString& etat, const QString& localisation)
{
    idLabel->setText(id);
    nomInput->setText(nom);
    referenceInput->setText(reference);
    
    int index = categorieCombo->findText(categorie);
    if (index >= 0) categorieCombo->setCurrentIndex(index);
    
    index = etatCombo->findText(etat);
    if (index >= 0) etatCombo->setCurrentIndex(index);
    
    localisationInput->setText(localisation);
}

// ==================== SupprimerMachineDialog ====================
SupprimerMachineDialog::SupprimerMachineDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void SupprimerMachineDialog::setupUI()
{
    setWindowTitle("Confirmer la suppression");
    setModal(true);
    resize(400, 200);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    messageLabel = new QLabel();
    messageLabel->setWordWrap(true);
    messageLabel->setStyleSheet("font-size: 14px; padding: 20px;");
    layout->addWidget(messageLabel);
    
    QLabel *warning = new QLabel("⚠️ Cette action est irréversible !");
    warning->setStyleSheet("color: red; font-weight: bold;");
    layout->addWidget(warning);
    
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Yes | QDialogButtonBox::No,
        Qt::Horizontal, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    layout->addWidget(buttons);
    setLayout(layout);
}

void SupprimerMachineDialog::setMachineNom(const QString& nom)
{
    messageLabel->setText(QString("Êtes-vous sûr de vouloir supprimer la machine '%1' ?").arg(nom));
}

// ==================== SignalerPanneDialog ====================
SignalerPanneDialog::SignalerPanneDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void SignalerPanneDialog::setupUI()
{
    setWindowTitle("Signaler une panne");
    setModal(true);
    resize(450, 400);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    
    infoLabel = new QLabel();
    infoLabel->setStyleSheet("font-weight: bold; padding: 10px; background-color: #f0f0f0;");
    layout->addWidget(infoLabel);
    
    QFormLayout *formLayout = new QFormLayout();
    
    typePanne = new QComboBox();
    typePanne->addItems({"Panne mécanique", "Panne électrique", "Panne électronique", 
                         "Panne hydraulique", "Usure", "Autre"});
    formLayout->addRow("Type de panne :", typePanne);
    
    descriptionPanne = new QTextEdit();
    descriptionPanne->setPlaceholderText("Décrivez la panne en détail...");
    descriptionPanne->setMaximumHeight(150);
    formLayout->addRow("Description :", descriptionPanne);
    
    niveauUrgence = new QComboBox();
    niveauUrgence->addItems({"Basse", "Moyenne", "Haute", "Critique"});
    formLayout->addRow("Niveau d'urgence :", niveauUrgence);
    
    technicienInput = new QLineEdit();
    technicienInput->setPlaceholderText("Nom du technicien");
    formLayout->addRow("Technicien :", technicienInput);
    
    layout->addLayout(formLayout);
    
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    layout->addWidget(buttons);
    setLayout(layout);
}

void SignalerPanneDialog::setMachineNom(const QString& nom)
{
    infoLabel->setText(QString("Machine : %1").arg(nom.isEmpty() ? "Non sélectionnée" : nom));
}

// ==================== AjouterInterventionDialog ====================
AjouterInterventionDialog::AjouterInterventionDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void AjouterInterventionDialog::setupUI()
{
    setWindowTitle("Ajouter une intervention");
    setModal(true);
    resize(500, 450);
    
    QVBoxLayout *layout = new QVBoxLayout(this);
    QFormLayout *formLayout = new QFormLayout();
    
    machineLabel = new QLabel();
    formLayout->addRow("Machine :", machineLabel);
    
    dateIntervention = new QDateEdit();
    dateIntervention->setDate(QDate::currentDate());
    dateIntervention->setCalendarPopup(true);
    formLayout->addRow("Date :", dateIntervention);
    
    typeIntervention = new QComboBox();
    typeIntervention->addItems({"Maintenance préventive", "Réparation", "Inspection", "Nettoyage", "Calibration"});
    formLayout->addRow("Type :", typeIntervention);
    
    descriptionIntervention = new QTextEdit();
    descriptionIntervention->setPlaceholderText("Description de l'intervention...");
    descriptionIntervention->setMaximumHeight(100);
    formLayout->addRow("Description :", descriptionIntervention);
    
    technicienIntervention = new QLineEdit();
    technicienIntervention->setPlaceholderText("Nom du technicien");
    formLayout->addRow("Technicien :", technicienIntervention);
    
    coutIntervention = new QDoubleSpinBox();
    coutIntervention->setRange(0, 10000);
    coutIntervention->setSuffix(" €");
    formLayout->addRow("Coût :", coutIntervention);
    
    layout->addLayout(formLayout);
    
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, this);
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    layout->addWidget(buttons);
    setLayout(layout);
}

void AjouterInterventionDialog::setMachineNom(const QString& nom)
{
    machineLabel->setText(nom);
}

// ==================== MainWindow ====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Charger et appliquer le stylesheet
    QFile styleFile(":/stylesheet.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }
    
    // Connecter les boutons du menu
    connect(ui->btnEmployee, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageEmployee);
        QMessageBox::information(this, "Page Employé", "Page Employé (maquette)");
    });
    
    connect(ui->btnTeam, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageTeam);
        QMessageBox::information(this, "Page Équipe", "Page Équipe (maquette)");
    });
    
    connect(ui->btnClient, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageClient);
        QMessageBox::information(this, "Page Client", "Page Client (maquette)");
    });
    
    connect(ui->btnLaboratory, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageLaboratory);
        QMessageBox::information(this, "Page Laboratoire", "Page Laboratoire (maquette)");
    });
    
    connect(ui->btnOrder, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageOrder);
        QMessageBox::information(this, "Page Commande", "Page Commande (maquette)");
    });
    
    connect(ui->btnMachine, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageMachine);
    });
    
    // Page Machine par défaut
    ui->stackedPages->setCurrentWidget(ui->pageMachine);
    
    // Initialiser les tableaux
    initialiserTableMachines();
    initialiserTableHistorique();
    
    // Initialiser les statistiques
    initialiserStatistiques();
    
    // Configurer les connexions
    setupConnections();
    
    // Ajouter les données de démonstration STATIQUES
    ajouterMachinesDemo();
    ajouterInterventionsDemo();
    
    // Mettre à jour les statistiques avec les données démo
    mettreAJourStatistiques();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialiserTableMachines()
{
    ui->tableEquipments->setColumnCount(8);
    QStringList headers = {"ID Matériel", "Nom", "Catégorie", "Référence", 
                          "Date Achat", "État", "Localisation", "Garantie Fin"};
    ui->tableEquipments->setHorizontalHeaderLabels(headers);
    ui->tableEquipments->horizontalHeader()->setStretchLastSection(true);
    ui->tableEquipments->setAlternatingRowColors(true);
    ui->tableEquipments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableEquipments->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::initialiserTableHistorique()
{
    ui->tableHistorique->setColumnCount(7);
    QStringList headers = {"Date", "Machine", "Type", "Description", "Technicien", "Coût", "Statut"};
    ui->tableHistorique->setHorizontalHeaderLabels(headers);
    ui->tableHistorique->horizontalHeader()->setStretchLastSection(true);
    ui->tableHistorique->setAlternatingRowColors(true);
    ui->tableHistorique->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableHistorique->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::initialiserStatistiques()
{
    // Styles des cartes
    QString cardStyle = "QFrame { background-color: #F8EDE3; border-radius: 10px; border: 1px solid #BDD2B6; padding: 10px; }";
    
    if (ui->cardTotal) ui->cardTotal->setStyleSheet(cardStyle);
    if (ui->cardOperational) ui->cardOperational->setStyleSheet(cardStyle);
    if (ui->cardMaintenance) ui->cardMaintenance->setStyleSheet(cardStyle);
    if (ui->cardDefective) ui->cardDefective->setStyleSheet(cardStyle);
    
    // Styles des KPI
    QString kpiStyle = "QFrame { background-color: #F8EDE3; border-radius: 8px; border: 1px solid #BDD2B6; padding: 15px; }";
    if (ui->kpiInterventions) ui->kpiInterventions->setStyleSheet(kpiStyle);
    if (ui->kpiCoutTotal) ui->kpiCoutTotal->setStyleSheet(kpiStyle);
    if (ui->kpiDisponibilite) ui->kpiDisponibilite->setStyleSheet(kpiStyle);
    if (ui->kpiTauxPanne) ui->kpiTauxPanne->setStyleSheet(kpiStyle);
}

void MainWindow::setupConnections()
{
    // ===== CRUD MACHINE =====
    // Connexion depuis l'onglet Détails
    if (ui->btnAddMachineFromDetails) {
        connect(ui->btnAddMachineFromDetails, &QPushButton::clicked, 
                this, &MainWindow::ouvrirAjoutMachineDepuisDetails);
    }
    
    // Actions rapides (panneau droit)
    if (ui->btnQuickEdit) {
        connect(ui->btnQuickEdit, &QPushButton::clicked, this, &MainWindow::ouvrirModifierMachine);
    }
    
    if (ui->btnQuickDelete) {
        connect(ui->btnQuickDelete, &QPushButton::clicked, this, &MainWindow::ouvrirSupprimerMachine);
    }
    
    if (ui->btnReportProblem) {
        connect(ui->btnReportProblem, &QPushButton::clicked, this, &MainWindow::ouvrirSignalerPanne);
    }
    
    // ===== SCANNER QR CODE =====
    // Uniquement dans le panneau droit
    if (ui->btnScanQR_RightPanel) {
        connect(ui->btnScanQR_RightPanel, &QPushButton::clicked, this, &MainWindow::scannerQR);
    }
    
    // ===== ACTIONS HISTORIQUE =====
    if (ui->btnAddIntervention) {
        connect(ui->btnAddIntervention, &QPushButton::clicked, this, &MainWindow::ouvrirAjouterIntervention);
    }
    
    if (ui->btnDeleteIntervention) {
        connect(ui->btnDeleteIntervention, &QPushButton::clicked, this, &MainWindow::ouvrirSupprimerIntervention);
    }
    
    if (ui->btnViewDetails) {
        connect(ui->btnViewDetails, &QPushButton::clicked, this, &MainWindow::ouvrirVoirDetailsIntervention);
    }
    
    // ===== EXPORT PDF ET ACTUALISER =====
    if (ui->btnExportPDF) {
        connect(ui->btnExportPDF, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    if (ui->btnRefresh) {
        connect(ui->btnRefresh, &QPushButton::clicked, this, &MainWindow::actualiser);
    }
    
    if (ui->btnExportPDF_Historique) {
        connect(ui->btnExportPDF_Historique, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    if (ui->btnRefresh_Historique) {
        connect(ui->btnRefresh_Historique, &QPushButton::clicked, this, &MainWindow::actualiser);
    }
    
    if (ui->btnExportPDF_Stats) {
        connect(ui->btnExportPDF_Stats, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    if (ui->btnRefresh_Stats) {
        connect(ui->btnRefresh_Stats, &QPushButton::clicked, this, &MainWindow::actualiser);
    }
    
    // ===== ÉVÉNEMENTS =====
    connect(ui->tableEquipments, &QTableWidget::itemSelectionChanged, 
            this, &MainWindow::onTableMachineSelectionChanged);
    
    connect(ui->tableHistorique, &QTableWidget::itemSelectionChanged, 
            this, &MainWindow::onTableHistoriqueSelectionChanged);
}

void MainWindow::ajouterMachinesDemo()
{
    // Données de démonstration STATIQUES (toujours les mêmes)
    ui->tableEquipments->setRowCount(0);
    
    int row = ui->tableEquipments->rowCount();
    ui->tableEquipments->insertRow(row);
    ui->tableEquipments->setItem(row, 0, new QTableWidgetItem("MCH-001"));
    ui->tableEquipments->setItem(row, 1, new QTableWidgetItem("Presse Hydraulique P20"));
    ui->tableEquipments->setItem(row, 2, new QTableWidgetItem("Presse"));
    ui->tableEquipments->setItem(row, 3, new QTableWidgetItem("PH-2023-001"));
    ui->tableEquipments->setItem(row, 4, new QTableWidgetItem("15/01/2023"));
    ui->tableEquipments->setItem(row, 5, new QTableWidgetItem("En service"));
    ui->tableEquipments->setItem(row, 6, new QTableWidgetItem("Atelier A"));
    ui->tableEquipments->setItem(row, 7, new QTableWidgetItem("15/01/2025"));
    
    row = ui->tableEquipments->rowCount();
    ui->tableEquipments->insertRow(row);
    ui->tableEquipments->setItem(row, 0, new QTableWidgetItem("MCH-002"));
    ui->tableEquipments->setItem(row, 1, new QTableWidgetItem("Moteur Électrique 5kW"));
    ui->tableEquipments->setItem(row, 2, new QTableWidgetItem("Moteur"));
    ui->tableEquipments->setItem(row, 3, new QTableWidgetItem("ME-2023-045"));
    ui->tableEquipments->setItem(row, 4, new QTableWidgetItem("20/03/2023"));
    ui->tableEquipments->setItem(row, 5, new QTableWidgetItem("Maintenance"));
    ui->tableEquipments->setItem(row, 6, new QTableWidgetItem("Ligne 2"));
    ui->tableEquipments->setItem(row, 7, new QTableWidgetItem("20/03/2026"));
    
    row = ui->tableEquipments->rowCount();
    ui->tableEquipments->insertRow(row);
    ui->tableEquipments->setItem(row, 0, new QTableWidgetItem("MCH-003"));
    ui->tableEquipments->setItem(row, 1, new QTableWidgetItem("Filtre à huile F200"));
    ui->tableEquipments->setItem(row, 2, new QTableWidgetItem("Filtre"));
    ui->tableEquipments->setItem(row, 3, new QTableWidgetItem("FH-2024-012"));
    ui->tableEquipments->setItem(row, 4, new QTableWidgetItem("10/01/2024"));
    ui->tableEquipments->setItem(row, 5, new QTableWidgetItem("En service"));
    ui->tableEquipments->setItem(row, 6, new QTableWidgetItem("Atelier B"));
    ui->tableEquipments->setItem(row, 7, new QTableWidgetItem("10/01/2027"));
    
    row = ui->tableEquipments->rowCount();
    ui->tableEquipments->insertRow(row);
    ui->tableEquipments->setItem(row, 0, new QTableWidgetItem("MCH-004"));
    ui->tableEquipments->setItem(row, 1, new QTableWidgetItem("Capteur de pression PX100"));
    ui->tableEquipments->setItem(row, 2, new QTableWidgetItem("Capteur"));
    ui->tableEquipments->setItem(row, 3, new QTableWidgetItem("CP-2024-078"));
    ui->tableEquipments->setItem(row, 4, new QTableWidgetItem("05/02/2024"));
    ui->tableEquipments->setItem(row, 5, new QTableWidgetItem("Panne"));
    ui->tableEquipments->setItem(row, 6, new QTableWidgetItem("Ligne 1"));
    ui->tableEquipments->setItem(row, 7, new QTableWidgetItem("05/02/2026"));
}

void MainWindow::ajouterInterventionsDemo()
{
    // Données de démonstration STATIQUES pour l'historique
    ui->tableHistorique->setRowCount(0);
    
    int row = ui->tableHistorique->rowCount();
    ui->tableHistorique->insertRow(row);
    ui->tableHistorique->setItem(row, 0, new QTableWidgetItem("15/02/2024"));
    ui->tableHistorique->setItem(row, 1, new QTableWidgetItem("MCH-001 - Presse Hydraulique"));
    ui->tableHistorique->setItem(row, 2, new QTableWidgetItem("Maintenance préventive"));
    ui->tableHistorique->setItem(row, 3, new QTableWidgetItem("Vérification générale et lubrification"));
    ui->tableHistorique->setItem(row, 4, new QTableWidgetItem("Jean Dupont"));
    ui->tableHistorique->setItem(row, 5, new QTableWidgetItem("350.00 €"));
    ui->tableHistorique->setItem(row, 6, new QTableWidgetItem("Terminé"));
    
    row = ui->tableHistorique->rowCount();
    ui->tableHistorique->insertRow(row);
    ui->tableHistorique->setItem(row, 0, new QTableWidgetItem("10/03/2024"));
    ui->tableHistorique->setItem(row, 1, new QTableWidgetItem("MCH-002 - Moteur Électrique"));
    ui->tableHistorique->setItem(row, 2, new QTableWidgetItem("Réparation"));
    ui->tableHistorique->setItem(row, 3, new QTableWidgetItem("Remplacement roulement"));
    ui->tableHistorique->setItem(row, 4, new QTableWidgetItem("Marie Martin"));
    ui->tableHistorique->setItem(row, 5, new QTableWidgetItem("520.00 €"));
    ui->tableHistorique->setItem(row, 6, new QTableWidgetItem("En cours"));
    
    row = ui->tableHistorique->rowCount();
    ui->tableHistorique->insertRow(row);
    ui->tableHistorique->setItem(row, 0, new QTableWidgetItem("05/04/2024"));
    ui->tableHistorique->setItem(row, 1, new QTableWidgetItem("MCH-004 - Capteur pression"));
    ui->tableHistorique->setItem(row, 2, new QTableWidgetItem("Dépannage"));
    ui->tableHistorique->setItem(row, 3, new QTableWidgetItem("Réinitialisation et calibration"));
    ui->tableHistorique->setItem(row, 4, new QTableWidgetItem("Pierre Durand"));
    ui->tableHistorique->setItem(row, 5, new QTableWidgetItem("120.00 €"));
    ui->tableHistorique->setItem(row, 6, new QTableWidgetItem("Terminé"));
}

// ==================== CRUD MACHINE - SIMULATION ====================

void MainWindow::ouvrirAjoutMachine()
{
    AjouterMachineDialog dialog(this);
    
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Simulation", 
            "Fonctionnalité d'ajout de machine (simulation)\n\n"
            "Mode maquette - Les données ne sont pas sauvegardées.");
    }
}

void MainWindow::ouvrirAjoutMachineDepuisDetails()
{
    QMessageBox::information(this, "Simulation", 
        "Ajout de machine depuis l'onglet Détails (simulation)\n\n"
        "Mode maquette - Les données ne sont pas sauvegardées.");
    
    ouvrirAjoutMachine();
}

void MainWindow::ouvrirModifierMachine()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une machine à modifier.");
        return;
    }
    
    QString id = ui->tableEquipments->item(selectedRow, 0)->text();
    QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
    QString categorie = ui->tableEquipments->item(selectedRow, 2)->text();
    QString reference = ui->tableEquipments->item(selectedRow, 3)->text();
    QString etat = ui->tableEquipments->item(selectedRow, 5)->text();
    QString localisation = ui->tableEquipments->item(selectedRow, 6)->text();
    
    ModifierMachineDialog dialog(this);
    dialog.setMachineData(id, nom, reference, categorie, etat, localisation);
    
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Simulation", 
            "Fonctionnalité de modification (simulation)\n\n"
            "Mode maquette - Les modifications ne sont pas sauvegardées.");
    }
}

void MainWindow::ouvrirSupprimerMachine()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une machine à supprimer.");
        return;
    }
    
    QString machineNom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    SupprimerMachineDialog dialog(this);
    dialog.setMachineNom(machineNom);
    
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Simulation", 
            "Fonctionnalité de suppression (simulation)\n\n"
            "Mode maquette - La machine n'est pas réellement supprimée.");
    }
}

void MainWindow::ouvrirSignalerPanne()
{
    int selectedRow = ui->tableEquipments->currentRow();
    QString machineNom;
    
    if (selectedRow >= 0) {
        machineNom = ui->tableEquipments->item(selectedRow, 1)->text();
    }
    
    SignalerPanneDialog dialog(this);
    dialog.setMachineNom(machineNom);
    
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Simulation", 
            "Panne signalée (simulation)\n\n"
            "Mode maquette - Aucune intervention n'est ajoutée à l'historique.");
    }
}

// ==================== ACTIONS HISTORIQUE - SIMULATION ====================

void MainWindow::ouvrirAjouterIntervention()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une machine pour ajouter une intervention.");
        return;
    }
    
    QString machineNom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    AjouterInterventionDialog dialog(this);
    dialog.setMachineNom(machineNom);
    
    if (dialog.exec() == QDialog::Accepted) {
        QMessageBox::information(this, "Simulation", 
            "Intervention ajoutée (simulation)\n\n"
            "Mode maquette - L'historique n'est pas modifié.");
    }
}

void MainWindow::ouvrirSupprimerIntervention()
{
    int selectedRow = ui->tableHistorique->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une intervention à supprimer.");
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmer", 
                                 "Voulez-vous vraiment supprimer cette intervention ?\n\n"
                                 "(Simulation - aucune suppression réelle)",
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QMessageBox::information(this, "Simulation", 
            "Intervention supprimée (simulation)");
    }
}

void MainWindow::ouvrirVoirDetailsIntervention()
{
    int selectedRow = ui->tableHistorique->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une intervention à consulter.");
        return;
    }
    
    QString details = QString(
        "=== DÉTAILS DE L'INTERVENTION ===\n\n"
        "Date: %1\n"
        "Machine: %2\n"
        "Type: %3\n"
        "Description: %4\n"
        "Technicien: %5\n"
        "Coût: %6\n"
        "Statut: %7\n"
    ).arg(ui->tableHistorique->item(selectedRow, 0)->text())
     .arg(ui->tableHistorique->item(selectedRow, 1)->text())
     .arg(ui->tableHistorique->item(selectedRow, 2)->text())
     .arg(ui->tableHistorique->item(selectedRow, 3)->text())
     .arg(ui->tableHistorique->item(selectedRow, 4)->text())
     .arg(ui->tableHistorique->item(selectedRow, 5)->text())
     .arg(ui->tableHistorique->item(selectedRow, 6)->text());
    
    QMessageBox::information(this, "Détails de l'intervention", details);
}

// ==================== AUTRES ACTIONS - SIMULATION ====================

void MainWindow::scannerQR()
{
    QMessageBox::information(this, "Simulation", 
        "Fonctionnalité de scan QR code (simulation)\n\n"
        "Mode maquette - Cette fonctionnalité n'est pas implémentée.");
}

void MainWindow::exporterPDF()
{
    QMessageBox::information(this, "Simulation", 
        "Fonctionnalité d'export PDF (simulation)\n\n"
        "Mode maquette - Cette fonctionnalité n'est pas implémentée.");
}

void MainWindow::actualiser()
{
    ui->statusbar->showMessage("Données actualisées (simulation)", 3000);
    
    // Réinitialiser les données démo (comme si on rechargeait)
    ajouterMachinesDemo();
    ajouterInterventionsDemo();
    mettreAJourStatistiques();
    
    QMessageBox::information(this, "Simulation", 
        "Actualisation des données (simulation)\n\n"
        "Les données de démonstration sont réaffichées.");
}

// ==================== ÉVÉNEMENTS ====================

void MainWindow::onTableMachineSelectionChanged()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow >= 0) {
        QString etat = ui->tableEquipments->item(selectedRow, 5)->text();
        QString localisation = ui->tableEquipments->item(selectedRow, 6)->text();
        
        ui->quickState->setText(etat);
        ui->quickLocation->setText(localisation);
        
        // Compter les interventions pour cette machine (statique)
        QString machineId = ui->tableEquipments->item(selectedRow, 0)->text();
        int count = 0;
        for (int i = 0; i < ui->tableHistorique->rowCount(); i++) {
            if (ui->tableHistorique->item(i, 1)->text().startsWith(machineId)) {
                count++;
            }
        }
        ui->quickBreakdowns->setText(QString::number(count));
    }
}

void MainWindow::onTableHistoriqueSelectionChanged()
{
    bool hasSelection = ui->tableHistorique->currentRow() >= 0;
    if (ui->btnDeleteIntervention) ui->btnDeleteIntervention->setEnabled(hasSelection);
    if (ui->btnViewDetails) ui->btnViewDetails->setEnabled(hasSelection);
}

// ==================== STATISTIQUES ====================

void MainWindow::mettreAJourStatistiques()
{
    int total = ui->tableEquipments->rowCount();
    int enService = 0, enMaintenance = 0, enPanne = 0, horsService = 0;
    
    for (int i = 0; i < total; i++) {
        QString etat = ui->tableEquipments->item(i, 5)->text();
        if (etat == "En service") enService++;
        else if (etat == "Maintenance") enMaintenance++;
        else if (etat == "Panne") enPanne++;
        else if (etat == "Hors service") horsService++;
    }
    
    // Mettre à jour les cartes
    if (ui->statTotal) ui->statTotal->setText(QString::number(total));
    if (ui->statOp) ui->statOp->setText(QString::number(enService));
    if (ui->statMaint) ui->statMaint->setText(QString::number(enMaintenance));
    if (ui->statDef) ui->statDef->setText(QString::number(enPanne + horsService));
    
    // Statistiques interventions
    int totalInterventions = ui->tableHistorique->rowCount();
    double coutTotal = 0.0;
    for (int i = 0; i < totalInterventions; i++) {
        QString coutStr = ui->tableHistorique->item(i, 5)->text();
        coutStr = coutStr.replace(" €", "").replace(",", ".");
        bool ok;
        double cout = coutStr.toDouble(&ok);
        if (ok) coutTotal += cout;
    }
    
    // Mettre à jour les KPI
    if (ui->kpiInterventionsValue) {
        ui->kpiInterventionsValue->setText(QString::number(totalInterventions));
    }
    if (ui->kpiCoutTotalValue) {
        ui->kpiCoutTotalValue->setText(QString("%1 €").arg(coutTotal, 0, 'f', 2));
    }
    
    double disponibilite = total > 0 ? (double(enService) / total) * 100 : 0;
    if (ui->kpiDisponibiliteValue) {
        ui->kpiDisponibiliteValue->setText(QString("%1%").arg(disponibilite, 0, 'f', 1));
    }
    
    double tauxPanne = total > 0 ? (double(enPanne + horsService) / total) * 100 : 0;
    if (ui->kpiTauxPanneValue) {
        ui->kpiTauxPanneValue->setText(QString("%1%").arg(tauxPanne, 0, 'f', 1));
    }
    
    // Mettre à jour les graphiques
    mettreAJourGraphiqueCategories();
    mettreAJourGraphiqueEtats();
    mettreAJourTendanceInterventions();
}

void MainWindow::mettreAJourGraphiqueCategories()
{
    if (!ui->statsCategories) return;
    
    QMap<QString, int> categories;
    int total = ui->tableEquipments->rowCount();
    
    for (int i = 0; i < total; i++) {
        QString categorie = ui->tableEquipments->item(i, 2)->text();
        categories[categorie]++;
    }
    
    QString html = "<div style='text-align: center; padding: 15px; font-family: Arial;'>";
    html += "<h3 style='color: #798777; margin-bottom: 25px; border-bottom: 2px solid #A2B29F; padding-bottom: 10px;'>";
    html += "📊 RÉPARTITION PAR CATÉGORIE</h3>";
    html += "<table style='width: 100%; border-collapse: collapse;'>";
    
    QStringList couleurs = {"#A2B29F", "#BDD2B6", "#798777", "#A2B29F", "#BDD2B6"};
    int index = 0;
    
    for (auto it = categories.begin(); it != categories.end(); ++it) {
        int pourcentage = total > 0 ? (it.value() * 100) / total : 0;
        QString couleur = couleurs[index % couleurs.size()];
        
        html += "<tr style='border-bottom: 1px solid #F8EDE3;'>";
        html += QString("<td style='padding: 12px; text-align: left;'><b style='color: #798777;'>%1</b></td>").arg(it.key());
        html += QString("<td style='padding: 12px; width: 60px; text-align: center;'><b style='color: #A2B29F;'>%1%</b></td>").arg(pourcentage);
        html += QString("<td style='padding: 12px;'><div style='height: 25px; width: %1px; background: %2; "
                       "border-radius: 12px; box-shadow: 0 2px 4px rgba(0,0,0,0.1);'></div></td>")
                       .arg(pourcentage * 3).arg(couleur);
        html += QString("<td style='padding: 12px; color: %1; text-align: right;'><b>%2</b></td>")
                       .arg(couleur).arg(it.value());
        html += "</tr>";
        
        index++;
    }
    
    html += "</table></div>";
    ui->statsCategories->setHtml(html);
}

void MainWindow::mettreAJourGraphiqueEtats()
{
    if (!ui->statsBreakdowns) return;
    
    int total = ui->tableEquipments->rowCount();
    int enService = 0, enMaintenance = 0, enPanne = 0, horsService = 0;
    
    for (int i = 0; i < total; i++) {
        QString etat = ui->tableEquipments->item(i, 5)->text();
        if (etat == "En service") enService++;
        else if (etat == "Maintenance") enMaintenance++;
        else if (etat == "Panne") enPanne++;
        else if (etat == "Hors service") horsService++;
    }
    
    QString html = "<div style='text-align: center; padding: 15px; font-family: Arial;'>";
    html += "<h3 style='color: #798777; margin-bottom: 25px; border-bottom: 2px solid #BDD2B6; padding-bottom: 10px;'>";
    html += "🔧 ÉTAT DES MACHINES</h3>";
    html += "<table style='width: 100%; border-collapse: collapse;'>";
    
    // En service
    int pourcentage1 = total > 0 ? (enService * 100) / total : 0;
    html += "<tr style='border-bottom: 1px solid #F8EDE3;'>";
    html += "<td style='padding: 12px;'><span style='display: inline-block; width: 12px; height: 12px; background: #A2B29F; border-radius: 3px;'></span> <b style='color: #798777;'>En service</b></td>";
    html += QString("<td style='padding: 12px; width: 60px; text-align: center;'><b style='color: #A2B29F;'>%1%</b></td>").arg(pourcentage1);
    html += QString("<td style='padding: 12px;'><div style='height: 25px; width: %1px; background: #A2B29F; "
                   "border-radius: 12px; box-shadow: 0 2px 4px rgba(0,0,0,0.1);'></div></td>").arg(pourcentage1 * 3);
    html += QString("<td style='padding: 12px; color: #A2B29F; text-align: right;'><b>%1</b></td>").arg(enService);
    html += "</tr>";
    
    // En maintenance
    int pourcentage2 = total > 0 ? (enMaintenance * 100) / total : 0;
    html += "<tr style='border-bottom: 1px solid #F8EDE3;'>";
    html += "<td style='padding: 12px;'><span style='display: inline-block; width: 12px; height: 12px; background: #BDD2B6; border-radius: 3px;'></span> <b style='color: #798777;'>Maintenance</b></td>";
    html += QString("<td style='padding: 12px; width: 60px; text-align: center;'><b style='color: #A2B29F;'>%1%</b></td>").arg(pourcentage2);
    html += QString("<td style='padding: 12px;'><div style='height: 25px; width: %1px; background: #BDD2B6; "
                   "border-radius: 12px; box-shadow: 0 2px 4px rgba(0,0,0,0.1);'></div></td>").arg(pourcentage2 * 3);
    html += QString("<td style='padding: 12px; color: #BDD2B6; text-align: right;'><b>%1</b></td>").arg(enMaintenance);
    html += "</tr>";
    
    // En panne
    int pourcentage3 = total > 0 ? (enPanne * 100) / total : 0;
    html += "<tr style='border-bottom: 1px solid #F8EDE3;'>";
    html += "<td style='padding: 12px;'><span style='display: inline-block; width: 12px; height: 12px; background: #798777; border-radius: 3px;'></span> <b style='color: #798777;'>En panne</b></td>";
    html += QString("<td style='padding: 12px; width: 60px; text-align: center;'><b style='color: #A2B29F;'>%1%</b></td>").arg(pourcentage3);
    html += QString("<td style='padding: 12px;'><div style='height: 25px; width: %1px; background: #798777; "
                   "border-radius: 12px; box-shadow: 0 2px 4px rgba(0,0,0,0.1);'></div></td>").arg(pourcentage3 * 3);
    html += QString("<td style='padding: 12px; color: #798777; text-align: right;'><b>%1</b></td>").arg(enPanne);
    html += "</tr>";
    
    // Hors service
    int pourcentage4 = total > 0 ? (horsService * 100) / total : 0;
    html += "<tr style='border-bottom: 1px solid #F8EDE3;'>";
    html += "<td style='padding: 12px;'><span style='display: inline-block; width: 12px; height: 12px; background: #BDD2B6; border-radius: 3px;'></span> <b style='color: #798777;'>Hors service</b></td>";
    html += QString("<td style='padding: 12px; width: 60px; text-align: center;'><b style='color: #A2B29F;'>%1%</b></td>").arg(pourcentage4);
    html += QString("<td style='padding: 12px;'><div style='height: 25px; width: %1px; background: #BDD2B6; "
                   "border-radius: 12px; box-shadow: 0 2px 4px rgba(0,0,0,0.1);'></div></td>").arg(pourcentage4 * 3);
    html += QString("<td style='padding: 12px; color: #BDD2B6; text-align: right;'><b>%1</b></td>").arg(horsService);
    html += "</tr>";
    
    html += "</table></div>";
    ui->statsBreakdowns->setHtml(html);
}

void MainWindow::mettreAJourTendanceInterventions()
{
    if (!ui->trendChartPlaceholder) return;
    
    QString html = "<div style='text-align: center; padding: 15px; font-family: Arial;'>";
    html += "<h3 style='color: #798777; margin-bottom: 25px; border-bottom: 2px solid #A2B29F; padding-bottom: 10px;'>";
    html += "📈 TENDANCE DES INTERVENTIONS</h3>";
    
    html += "<table style='width: 100%; border-collapse: collapse;'>";
    html += "<tr style='background-color: #F8EDE3;'>";
    html += "<th style='padding: 12px; color: #798777;'>Jan</th>";
    html += "<th style='padding: 12px; color: #798777;'>Fév</th>";
    html += "<th style='padding: 12px; color: #798777;'>Mar</th>";
    html += "<th style='padding: 12px; color: #798777;'>Avr</th>";
    html += "<th style='padding: 12px; color: #798777;'>Mai</th>";
    html += "<th style='padding: 12px; color: #798777;'>Juin</th>";
    html += "</tr><tr style='height: 80px;'>";
    
    QList<int> valeurs = {3, 2, 4, 5, 3, 2};
    for (int val : valeurs) {
        int hauteur = val * 12;
        html += QString("<td style='vertical-align: bottom; text-align: center;'>"
                       "<div style='display: inline-block; width: 40px; height: %1px; "
                       "background: linear-gradient(to top, #A2B29F, #BDD2B6); "
                       "border-radius: 6px 6px 0 0; box-shadow: 0 -2px 5px rgba(0,0,0,0.1); "
                       "margin-bottom: 5px;'></div><br>"
                       "<span style='font-weight: bold; font-size: 16px; color: #798777;'>%2</span>"
                       "</td>").arg(hauteur).arg(val);
    }
    
    html += "</tr></table>";
    
    int total = ui->tableHistorique->rowCount();
    double coutTotal = 0.0;
    for (int i = 0; i < total; i++) {
        QString coutStr = ui->tableHistorique->item(i, 5)->text();
        coutStr = coutStr.replace(" €", "").replace(",", ".");
        bool ok;
        double cout = coutStr.toDouble(&ok);
        if (ok) coutTotal += cout;
    }
    
    html += QString("<p style='margin-top: 25px; padding: 15px; background: #F8EDE3; "
                   "border-radius: 10px; color: #798777; font-weight: bold; border: 1px solid #BDD2B6;'>"
                   "📊 Total des interventions: <span style='color: #A2B29F; font-size: 20px;'>%1</span> | "
                   "Coût total: <span style='color: #A2B29F; font-size: 20px;'>%2 €</span></p>")
                   .arg(total).arg(coutTotal, 0, 'f', 2);
    
    html += "</div>";
    ui->trendChartPlaceholder->setHtml(html);
}