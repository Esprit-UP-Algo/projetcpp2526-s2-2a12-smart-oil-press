#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QDate>
#include <QTableWidgetItem>
#include <QDoubleSpinBox>
#include <QHeaderView>
#include <QSpinBox>
#include <QScrollArea>
#include <QGroupBox>
#include <QGridLayout>
#include <QMessageBox>
#include "connexion.h"

// ==================== AjouterEmployeDialog ====================
AjouterEmployeDialog::AjouterEmployeDialog(QWidget *parent) : QDialog(parent)
{
    setupUI();
}

void AjouterEmployeDialog::setupUI()
{
    setWindowTitle("Ajouter un employé");
    setModal(true);
    resize(700, 800);
    
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(40, 40, 40, 40);
    
    // Titre
    QLabel *titleLabel = new QLabel("AJOUTER UN EMPLOYÉ");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setObjectName("dialogTitle");
    mainLayout->addWidget(titleLabel);
    
    // Ligne de séparation
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setObjectName("separator");
    mainLayout->addWidget(line);
    
    // Zone de scroll
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setSpacing(15);
    
    // Groupe 1: Informations personnelles
    QGroupBox *infoPersoGroup = new QGroupBox("Informations personnelles");
    infoPersoGroup->setObjectName("infoGroup");
    
    QGridLayout *infoPersoLayout = new QGridLayout(infoPersoGroup);
    infoPersoLayout->setVerticalSpacing(15);
    infoPersoLayout->setHorizontalSpacing(20);
    
    // ID
    infoPersoLayout->addWidget(new QLabel("ID:"), 0, 0);
    idInput = new QLineEdit();
    idInput->setPlaceholderText("Entrez ID...");
    infoPersoLayout->addWidget(idInput, 0, 1);
    
    // Nom
    infoPersoLayout->addWidget(new QLabel("Nom:"), 1, 0);
    nomInput = new QLineEdit();
    nomInput->setPlaceholderText("Entrez nom...");
    infoPersoLayout->addWidget(nomInput, 1, 1);
    
    // Prénom
    infoPersoLayout->addWidget(new QLabel("Prénom:"), 2, 0);
    prenomInput = new QLineEdit();
    prenomInput->setPlaceholderText("Entrez prénom...");
    infoPersoLayout->addWidget(prenomInput, 2, 1);
    
    // Âge
    infoPersoLayout->addWidget(new QLabel("Âge:"), 3, 0);
    ageInput = new QSpinBox();
    ageInput->setRange(18, 99);
    ageInput->setValue(30);
    infoPersoLayout->addWidget(ageInput, 3, 1);
    
    // Téléphone
    infoPersoLayout->addWidget(new QLabel("Téléphone:"), 4, 0);
    telephoneInput = new QLineEdit();
    telephoneInput->setPlaceholderText("Entrez tel...");
    infoPersoLayout->addWidget(telephoneInput, 4, 1);
    
    scrollLayout->addWidget(infoPersoGroup);
    
    // Groupe 2: Informations professionnelles
    QGroupBox *infoProGroup = new QGroupBox("Informations professionnelles");
    infoProGroup->setObjectName("infoGroup");
    
    QGridLayout *infoProLayout = new QGridLayout(infoProGroup);
    infoProLayout->setVerticalSpacing(15);
    infoProLayout->setHorizontalSpacing(20);
    
    // Spécialité
    infoProLayout->addWidget(new QLabel("Spécialité:"), 0, 0);
    specialiteCombo = new QComboBox();
    specialiteCombo->addItems({"-- Tous --", "Développeur", "Technicien", "Chef d'équipe", "Responsable", "Autre"});
    infoProLayout->addWidget(specialiteCombo, 0, 1);
    
    // Salaire
    infoProLayout->addWidget(new QLabel("Salaire (€):"), 1, 0);
    salaireInput = new QDoubleSpinBox();
    salaireInput->setRange(0, 100000);
    salaireInput->setValue(2500);
    salaireInput->setSingleStep(100);
    infoProLayout->addWidget(salaireInput, 1, 1);
    
    // Ancienneté
    infoProLayout->addWidget(new QLabel("Ancienneté (ans):"), 2, 0);
    ancienneteInput = new QSpinBox();
    ancienneteInput->setRange(0, 50);
    ancienneteInput->setValue(2);
    infoProLayout->addWidget(ancienneteInput, 2, 1);
    
    // Disponibilité
    infoProLayout->addWidget(new QLabel("Disponibilité:"), 3, 0);
    disponibiliteCombo = new QComboBox();
    disponibiliteCombo->addItems({"-- Tous --", "Disponible", "En congé", "En formation", "Indisponible"});
    infoProLayout->addWidget(disponibiliteCombo, 3, 1);
    
    // Heures
    infoProLayout->addWidget(new QLabel("Heures/semaine:"), 4, 0);
    heuresInput = new QSpinBox();
    heuresInput->setRange(0, 168);
    heuresInput->setValue(35);
    infoProLayout->addWidget(heuresInput, 4, 1);
    
    scrollLayout->addWidget(infoProGroup);
    
    // Groupe 3: Fournisseurs
    QGroupBox *fournisseursGroup = new QGroupBox("Fournisseurs");
    fournisseursGroup->setObjectName("infoGroup");
    
    QVBoxLayout *fournisseursLayout = new QVBoxLayout(fournisseursGroup);
    fournisseursInput = new QLineEdit();
    fournisseursInput->setPlaceholderText("Fournisseurs associés...");
    fournisseursLayout->addWidget(fournisseursInput);
    
    scrollLayout->addWidget(fournisseursGroup);
    scrollLayout->addStretch();
    
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);
    
    // Boutons
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, this);
    buttons->button(QDialogButtonBox::Ok)->setText("Ajouter");
    buttons->button(QDialogButtonBox::Cancel)->setText("Annuler");
    buttons->button(QDialogButtonBox::Ok)->setObjectName("btnAjouter");
    buttons->button(QDialogButtonBox::Cancel)->setObjectName("btnAnnuler");
    
    connect(buttons, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, this, &QDialog::reject);
    
    mainLayout->addWidget(buttons);
    setLayout(mainLayout);
}

// ==================== MainWindow ====================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Établir la connexion à la base de données
    bool connected = Connection::instance()->createConnect();
    if (connected) {
        QMessageBox::information(this, "Connexion réussie", "Connexion à la base de données établie avec succès.");
        // Insérer des machines de démonstration si la base est vide
        QList<QVariantMap> machines;
        if (Connection::instance()->getMachines(machines) && machines.isEmpty()) {
            // Insérer quelques machines de demo
            Connection::instance()->ajouterMachine("MCH-001", "Presse Hydraulique", "Presse", "REF-001", "01/01/2023", "En service", "atelier");
            Connection::instance()->ajouterMachine("MCH-002", "Tour CNC", "Tour", "REF-002", "15/03/2023", "En maintenance", "atelier");
            Connection::instance()->ajouterMachine("MCH-003", "Fraiseuse", "Fraiseuse", "REF-003", "20/05/2023", "En service", "atelier");
            // Recharger la table
            initialiserTableMachines();
            remplirComboboxIds();
        }
    } else {
        QMessageBox::critical(this, "Erreur de connexion", "Impossible de se connecter à la base de données.");
        // Vous pouvez choisir de quitter l'application ou continuer sans DB
        // QApplication::quit();
    }
    
    // Charger et appliquer le stylesheet
    QFile styleFile(":/style/stylesheet.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
        qDebug() << "Style CSS chargé avec succès depuis les ressources";
    } else {
        qDebug() << "Erreur: Impossible de charger le fichier CSS depuis les ressources";
    }
    connect(ui->btnEmployee, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageEmployee);
    });
    
    connect(ui->btnTeam, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageTeam);
    });
    
    connect(ui->btnClient, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageClient);
    });
    
    connect(ui->btnLaboratory, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageLaboratory);
    });
    
    connect(ui->btnOrder, &QPushButton::clicked, this, [this]() {
        ui->stackedPages->setCurrentWidget(ui->pageOrder);
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
    
    // Ajouter les données de démonstration
    // ajouterMachinesDemo(); // Maintenant chargé depuis la DB
    ajouterInterventionsDemo();
    
    // Mettre à jour les statistiques
    mettreAJourStatistiques();
    
    // Remplir les combobox avec les IDs des machines
    remplirComboboxIds();
    
    // Appliquer le style CSS après que tous les widgets soient créés
    appliquerStyleCSS();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialiserTableMachines()
{
    ui->tableEquipments->setColumnCount(7);
    ui->tableEquipments->setRowCount(0);  // Vider le tableau avant de le remplir
    QStringList headers = {"ID Machine", "Nom", "Catégorie", "Référence", "Date Achat", "État", "Localisation"};
    ui->tableEquipments->setHorizontalHeaderLabels(headers);
    ui->tableEquipments->horizontalHeader()->setStretchLastSection(true);
    ui->tableEquipments->setAlternatingRowColors(true);
    ui->tableEquipments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableEquipments->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    // Charger les machines depuis la base de données
    QList<QVariantMap> machines;
    if (Connection::instance()->getMachines(machines)) {
        if (machines.isEmpty()) {
            qDebug() << "Aucune machine trouvée en DB (table vide).";
        }
        for (const QVariantMap& machine : machines) {
            int row = ui->tableEquipments->rowCount();
            ui->tableEquipments->insertRow(row);
            ui->tableEquipments->setItem(row, 0, new QTableWidgetItem(machine["id"].toString()));
            ui->tableEquipments->setItem(row, 1, new QTableWidgetItem(machine["nom"].toString()));
            ui->tableEquipments->setItem(row, 2, new QTableWidgetItem(machine["categorie"].toString()));
            ui->tableEquipments->setItem(row, 3, new QTableWidgetItem(machine["reference"].toString()));
            ui->tableEquipments->setItem(row, 4, new QTableWidgetItem(machine["date_achat"].toString()));
            ui->tableEquipments->setItem(row, 5, new QTableWidgetItem(machine["etat"].toString()));
            ui->tableEquipments->setItem(row, 6, new QTableWidgetItem(machine["localisation"].toString()));
        }
    } else {
        QString err = Connection::instance()->lastError();
        qDebug() << "getMachines a échoué :" << err;
        QMessageBox::warning(this, "Erreur base de données", QString("Impossible de charger les machines : %1").arg(err));
    }
}

void MainWindow::initialiserTableHistorique()
{
    ui->tableHistorique->setColumnCount(6);
    QStringList headers = {"Date", "Machine", "Type d'intervention", "Technicien", "Coût", "Statut"};
    ui->tableHistorique->setHorizontalHeaderLabels(headers);
    ui->tableHistorique->horizontalHeader()->setStretchLastSection(true);
    ui->tableHistorique->setAlternatingRowColors(true);
    ui->tableHistorique->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableHistorique->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void MainWindow::initialiserStatistiques()
{
    // Les statistiques sont déjà définies dans l'UI
}

void MainWindow::setupConnections()
{
    // ===== BOUTONS DES ONGLETS =====
    if (ui->btnAddValider) {
        connect(ui->btnAddValider, &QPushButton::clicked, this, &MainWindow::ouvrirAjoutMachine);
    }
    
    if (ui->btnModifierValider) {
        connect(ui->btnModifierValider, &QPushButton::clicked, this, &MainWindow::ouvrirModifierMachine);
    }
    
    if (ui->btnSupprimerValider) {
        connect(ui->btnSupprimerValider, &QPushButton::clicked, this, &MainWindow::ouvrirSupprimerMachine);
    }
    
    if (ui->btnPanneValider) {
        connect(ui->btnPanneValider, &QPushButton::clicked, this, &MainWindow::ouvrirSignalerPanne);
    }
    
    if (ui->btnAddIntervention) {
        connect(ui->btnAddIntervention, &QPushButton::clicked, this, &MainWindow::ouvrirAjouterIntervention);
    }
    
    // ===== BOUTONS D'EXPORT PDF =====
    if (ui->btnExportPDF) {
        connect(ui->btnExportPDF, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    if (ui->btnExportPDF_Historique) {
        connect(ui->btnExportPDF_Historique, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    if (ui->btnExportPDF_Stats) {
        connect(ui->btnExportPDF_Stats, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    // ===== BOUTON APPLIQUER FILTRES =====
    if (ui->btnApplyFilter) {
        connect(ui->btnApplyFilter, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(this, "Filtres", "Filtres appliqués (simulation)");
        });
    }
    
    // ===== SCANNER QR CODE =====
    if (ui->btnScanQR_RightPanel) {
        connect(ui->btnScanQR_RightPanel, &QPushButton::clicked, this, &MainWindow::scannerQR);
    }
    
    // ===== BOUTONS ANNULER =====
    if (ui->btnAddAnnuler) {
        connect(ui->btnAddAnnuler, &QPushButton::clicked, this, [this]() {
            ui->tabWidget->setCurrentWidget(ui->tabList);
        });
    }
    
    if (ui->btnModifierAnnuler) {
        connect(ui->btnModifierAnnuler, &QPushButton::clicked, this, [this]() {
            ui->tabWidget->setCurrentWidget(ui->tabList);
        });
    }
    
    if (ui->btnSupprimerAnnuler) {
        connect(ui->btnSupprimerAnnuler, &QPushButton::clicked, this, [this]() {
            ui->tabWidget->setCurrentWidget(ui->tabList);
        });
    }
    
    if (ui->btnPanneAnnuler) {
        connect(ui->btnPanneAnnuler, &QPushButton::clicked, this, [this]() {
            ui->tabWidget->setCurrentWidget(ui->tabList);
        });
    }
    
    // ===== ÉVÉNEMENTS =====
    connect(ui->tableEquipments, &QTableWidget::itemSelectionChanged, 
            this, &MainWindow::onTableMachineSelectionChanged);
}

void MainWindow::ajouterMachinesDemo()
{
    ui->tableEquipments->setRowCount(0);
}

void MainWindow::ajouterInterventionsDemo()
{
    ui->tableHistorique->setRowCount(0);
}

void MainWindow::remplirComboboxIds()
{
    // Remplir le comboBox de l'onglet Modifier
    if (ui->comboModifierId) {
        ui->comboModifierId->clear();
        for (int i = 0; i < ui->tableEquipments->rowCount(); i++) {
            ui->comboModifierId->addItem(ui->tableEquipments->item(i, 0)->text());
        }
    }
    
    // Remplir le comboBox de l'onglet Supprimer
    if (ui->comboSupprimerId) {
        ui->comboSupprimerId->clear();
        for (int i = 0; i < ui->tableEquipments->rowCount(); i++) {
            ui->comboSupprimerId->addItem(ui->tableEquipments->item(i, 0)->text());
        }
    }
    
    // Remplir le comboBox de l'onglet Signaler Panne
    if (ui->comboPanneId) {
        ui->comboPanneId->clear();
        for (int i = 0; i < ui->tableEquipments->rowCount(); i++) {
            ui->comboPanneId->addItem(ui->tableEquipments->item(i, 0)->text());
        }
    }
}

// ==================== CRUD MACHINE - VERSION SIMPLIFIÉE AVEC CONFIRMATION ====================

void MainWindow::ouvrirAjoutMachine()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation d'ajout", 
                                 "Voulez-vous ajouter une nouvelle machine ?",
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Lire les champs du formulaire d'ajout
        QString id = ui->editAddId ? ui->editAddId->text().trimmed() : QString();
        QString nom = ui->editAddNom ? ui->editAddNom->text().trimmed() : QString();
        QString categorie = ui->comboAddCategorie ? ui->comboAddCategorie->currentText() : QString("Presse");
        QString reference = ui->editAddReference ? ui->editAddReference->text().trimmed() : QString();
        QString dateAchat = ui->dateAddAchat ? ui->dateAddAchat->date().toString("dd/MM/yyyy") : QDate::currentDate().toString("dd/MM/yyyy");
        QString etat = ui->comboAddEtat ? ui->comboAddEtat->currentText() : QString("En service");
        QString localisation = ui->editAddLocalisation ? ui->editAddLocalisation->text().trimmed() : QString();

        if (id.isEmpty()) {
            int newNum = ui->tableEquipments->rowCount() + 1;
            id = QString("MCH-%1").arg(newNum, 3, 10, QChar('0')); // MCH-001, MCH-002...
        }
        if (nom.isEmpty()) {
            int newNum = ui->tableEquipments->rowCount() + 1;
            nom = "Nouvelle Machine " + QString::number(newNum);
        }
        if (reference.isEmpty()) {
            int newNum = ui->tableEquipments->rowCount() + 1;
            reference = QString("REF-%1").arg(newNum, 3, 10, QChar('0')); // REF-001, REF-002...
        }

        // Ajouter à la base de données d'abord
        if (!Connection::instance()->ajouterMachine(id, nom, categorie, reference, dateAchat, etat, localisation)) {
            QString err = Connection::instance()->lastError();
            QMessageBox::warning(this, "Échec sauvegarde", QString("Impossible d'enregistrer la machine en base de données.\nErreur: %1").arg(err));
            return;
        }

        // Recharger l'interface depuis la base de données pour être sûr que c'est bien persisté.
        initialiserTableMachines();
        remplirComboboxIds();

        QMessageBox::information(this, "Succès", "Machine ajoutée avec succès et rechargée depuis la base !");

        // Mettre à jour les statistiques
        mettreAJourStatistiques();
    }
}

void MainWindow::ouvrirModifierMachine()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une machine dans la liste.");
        return;
    }
    
    QString id = ui->tableEquipments->item(selectedRow, 0)->text();
    QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirmation de modification");
    msgBox.setText("Voulez-vous modifier cette machine ?");
    msgBox.setInformativeText(QString("Machine: %1 (%2)").arg(nom).arg(id));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setIcon(QMessageBox::Question);
    
    if (msgBox.exec() == QMessageBox::Yes) {
        // Simulation de modification (dans une vraie app, vous ouvririez un formulaire)
        QMessageBox::information(this, "Succès", 
            QString("La machine '%1' a été modifiée avec succès !").arg(nom));
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
    
    QString id = ui->tableEquipments->item(selectedRow, 0)->text();
    QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    QMessageBox msgBox;
    msgBox.setWindowTitle("Confirmer la suppression");
    msgBox.setText(QString("Êtes-vous sûr de vouloir supprimer la machine '%1' ?").arg(nom));
    msgBox.setInformativeText("ID: " + id + "\nCette action est irréversible !");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setIcon(QMessageBox::Warning);
    
    if (msgBox.exec() == QMessageBox::Yes) {
        // Supprimer la ligne
        ui->tableEquipments->removeRow(selectedRow);
        
        // Mettre à jour les combobox
        remplirComboboxIds();
        
        QMessageBox::information(this, "Succès", "Machine supprimée avec succès !");
        
        // Mettre à jour les statistiques
        mettreAJourStatistiques();
    }
}

void MainWindow::ouvrirSignalerPanne()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une machine à signaler.");
        return;
    }
    
    QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
    QString etatActuel = ui->tableEquipments->item(selectedRow, 5)->text();
    
    if (etatActuel == "Panne") {
        QMessageBox::information(this, "Déjà en panne", 
                               "Cette machine est déjà signalée en panne.");
        return;
    }
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", 
                                 QString("Voulez-vous signaler une panne pour la machine '%1' ?").arg(nom),
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        ui->tableEquipments->item(selectedRow, 5)->setText("Panne");
        QMessageBox::information(this, "Succès", "Panne signalée avec succès !");
        
        // Mettre à jour les statistiques
        mettreAJourStatistiques();
    }
}

void MainWindow::ouvrirAjouterIntervention()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", 
                           "Veuillez sélectionner une machine.");
        return;
    }
    
    QString machineId = ui->tableEquipments->item(selectedRow, 0)->text();
    QString machineNom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", 
                                 QString("Ajouter une intervention pour '%1' ?").arg(machineNom),
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        // Ajouter une intervention par défaut
        QString date = QDate::currentDate().toString("dd/MM/yyyy");
        QString type = "Maintenance préventive";
        QString technicien = "Technicien";
        double cout = 0.00;
        QString statut = "Planifié";
        
        int row = ui->tableHistorique->rowCount();
        ui->tableHistorique->insertRow(row);
        ui->tableHistorique->setItem(row, 0, new QTableWidgetItem(date));
        ui->tableHistorique->setItem(row, 1, new QTableWidgetItem(machineId));
        ui->tableHistorique->setItem(row, 2, new QTableWidgetItem(type));
        ui->tableHistorique->setItem(row, 3, new QTableWidgetItem(technicien));
        ui->tableHistorique->setItem(row, 4, new QTableWidgetItem(QString::number(cout) + " €"));
        ui->tableHistorique->setItem(row, 5, new QTableWidgetItem(statut));
        
        // Ajouter à la base de données
        if (!Connection::instance()->ajouterIntervention(date, machineId, type, technicien, cout, statut)) {
            QString err = Connection::instance()->lastError();
            QMessageBox::warning(this, "Avertissement",
                                 QString("Intervention ajoutée à l'interface mais pas sauvegardée en base de données.\nError: %1").arg(err));
        } else {
            QMessageBox::information(this, "Succès", "Intervention ajoutée avec succès !");
        }
        
        // Mettre à jour les statistiques
        mettreAJourStatistiques();
    }
}

// ==================== CRUD EMPLOYÉ ====================

void MainWindow::ouvrirAjoutEmploye()
{
    AjouterEmployeDialog dialog(this);
    
    if (dialog.exec() == QDialog::Accepted) {
        QString id = dialog.getIdInput()->text();
        QString nom = dialog.getNomInput()->text();
        QString prenom = dialog.getPrenomInput()->text();
        int age = dialog.getAgeInput()->value();
        QString telephone = dialog.getTelephoneInput()->text();
        
        // Ajouter à la base de données
        if (!Connection::instance()->ajouterEmploye(id, nom, prenom, age, telephone)) {
            QString err = Connection::instance()->lastError();
            QMessageBox::warning(this, "Avertissement",
                                 QString("Employé ajouté à l'interface mais pas sauvegardé en base de données.\nError: %1").arg(err));
        } else {
            QMessageBox::information(this, "Succès", 
                QString("Employé ajouté avec succès !\n\n"
                       "ID: %1\n"
                       "Nom: %2 %3\n"
                       "Âge: %4\n"
                       "Téléphone: %5")
                .arg(id).arg(prenom).arg(nom).arg(age).arg(telephone));
        }
    }
}

// ==================== ACTIONS HISTORIQUE ====================

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
                                 "Voulez-vous vraiment supprimer cette intervention ?",
                                 QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        ui->tableHistorique->removeRow(selectedRow);
        QMessageBox::information(this, "Succès", "Intervention supprimée !");
        mettreAJourStatistiques();
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
        "Technicien: %4\n"
        "Coût: %5\n"
        "Statut: %6"
    ).arg(ui->tableHistorique->item(selectedRow, 0)->text())
     .arg(ui->tableHistorique->item(selectedRow, 1)->text())
     .arg(ui->tableHistorique->item(selectedRow, 2)->text())
     .arg(ui->tableHistorique->item(selectedRow, 3)->text())
     .arg(ui->tableHistorique->item(selectedRow, 4)->text())
     .arg(ui->tableHistorique->item(selectedRow, 5)->text());
    
    QMessageBox::information(this, "Détails de l'intervention", details);
}

// ==================== AUTRES ACTIONS ====================

void MainWindow::scannerQR()
{
    QMessageBox::information(this, "Scanner QR", 
        "Fonctionnalité de scan QR code\n\nMode démonstration - Simulation de scan.");
}

void MainWindow::exporterPDF()
{
    QMessageBox::information(this, "Exporter PDF", 
        "Fonctionnalité d'export PDF\n\nMode démonstration - Simulation d'export.");
}

// ==================== ÉVÉNEMENTS ====================

void MainWindow::onTableMachineSelectionChanged()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow >= 0) {
        QString id = ui->tableEquipments->item(selectedRow, 0)->text();
        
        // Mettre à jour les comboBox dans les autres onglets
        if (ui->comboModifierId) {
            int index = ui->comboModifierId->findText(id);
            if (index >= 0) ui->comboModifierId->setCurrentIndex(index);
        }
        
        if (ui->comboSupprimerId) {
            int index = ui->comboSupprimerId->findText(id);
            if (index >= 0) ui->comboSupprimerId->setCurrentIndex(index);
        }
        
        if (ui->comboPanneId) {
            int index = ui->comboPanneId->findText(id);
            if (index >= 0) ui->comboPanneId->setCurrentIndex(index);
        }
    }
}

void MainWindow::onTableHistoriqueSelectionChanged()
{
    // Gardé pour compatibilité
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
    
    if (ui->statTotal) ui->statTotal->setText(QString::number(total));
    if (ui->statOp) ui->statOp->setText(QString::number(enService));
    if (ui->statMaint) ui->statMaint->setText(QString::number(enMaintenance));
    if (ui->statDef) ui->statDef->setText(QString::number(enPanne + horsService));
    
    int totalInterventions = ui->tableHistorique->rowCount();
    double coutTotal = 0.0;
    for (int i = 0; i < totalInterventions; i++) {
        QString coutStr = ui->tableHistorique->item(i, 4)->text();
        coutStr = coutStr.replace(" €", "").replace(",", ".");
        bool ok;
        double cout = coutStr.toDouble(&ok);
        if (ok) coutTotal += cout;
    }
    
    if (ui->kpiInterventionsValue) {
        ui->kpiInterventionsValue->setText(QString::number(totalInterventions));
    }
    if (ui->kpiCoutTotalValue) {
        ui->kpiCoutTotalValue->setText(QString("%1 €").arg(coutTotal, 0, 'f', 2));
    }
}

// ==================== APPLICATION DU STYLE CSS ====================

void MainWindow::appliquerStyleCSS()
{
    // Charger et appliquer le stylesheet
    QFile styleFile(":/style/stylesheet.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
        qDebug() << "Style CSS appliqué avec succès après l'initialisation complète";
    } else {
        qDebug() << "Erreur: Impossible de charger le fichier CSS depuis les ressources";
    }
}