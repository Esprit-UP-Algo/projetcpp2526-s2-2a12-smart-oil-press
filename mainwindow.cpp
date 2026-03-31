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
#include <QDebug>
#include <algorithm>
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
    
    QLabel *titleLabel = new QLabel("AJOUTER UN EMPLOYÉ");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setObjectName("dialogTitle");
    mainLayout->addWidget(titleLabel);
    
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setObjectName("separator");
    mainLayout->addWidget(line);
    
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setSpacing(15);
    
    QGroupBox *infoPersoGroup = new QGroupBox("Informations personnelles");
    infoPersoGroup->setObjectName("infoGroup");
    
    QGridLayout *infoPersoLayout = new QGridLayout(infoPersoGroup);
    infoPersoLayout->setVerticalSpacing(15);
    infoPersoLayout->setHorizontalSpacing(20);
    
    infoPersoLayout->addWidget(new QLabel("ID:"), 0, 0);
    idInput = new QLineEdit();
    idInput->setPlaceholderText("Entrez ID...");
    infoPersoLayout->addWidget(idInput, 0, 1);
    
    infoPersoLayout->addWidget(new QLabel("Nom:"), 1, 0);
    nomInput = new QLineEdit();
    nomInput->setPlaceholderText("Entrez nom...");
    infoPersoLayout->addWidget(nomInput, 1, 1);
    
    infoPersoLayout->addWidget(new QLabel("Prénom:"), 2, 0);
    prenomInput = new QLineEdit();
    prenomInput->setPlaceholderText("Entrez prénom...");
    infoPersoLayout->addWidget(prenomInput, 2, 1);
    
    infoPersoLayout->addWidget(new QLabel("Âge:"), 3, 0);
    ageInput = new QSpinBox();
    ageInput->setRange(18, 99);
    ageInput->setValue(30);
    infoPersoLayout->addWidget(ageInput, 3, 1);
    
    infoPersoLayout->addWidget(new QLabel("Téléphone:"), 4, 0);
    telephoneInput = new QLineEdit();
    telephoneInput->setPlaceholderText("Entrez tel...");
    infoPersoLayout->addWidget(telephoneInput, 4, 1);
    
    scrollLayout->addWidget(infoPersoGroup);
    
    QGroupBox *infoProGroup = new QGroupBox("Informations professionnelles");
    infoProGroup->setObjectName("infoGroup");
    
    QGridLayout *infoProLayout = new QGridLayout(infoProGroup);
    infoProLayout->setVerticalSpacing(15);
    infoProLayout->setHorizontalSpacing(20);
    
    infoProLayout->addWidget(new QLabel("Spécialité:"), 0, 0);
    specialiteCombo = new QComboBox();
    specialiteCombo->addItems({"-- Tous --", "Développeur", "Technicien", "Chef d'équipe", "Responsable", "Autre"});
    infoProLayout->addWidget(specialiteCombo, 0, 1);
    
    infoProLayout->addWidget(new QLabel("Salaire (€):"), 1, 0);
    salaireInput = new QDoubleSpinBox();
    salaireInput->setRange(0, 100000);
    salaireInput->setValue(2500);
    salaireInput->setSingleStep(100);
    infoProLayout->addWidget(salaireInput, 1, 1);
    
    infoProLayout->addWidget(new QLabel("Ancienneté (ans):"), 2, 0);
    ancienneteInput = new QSpinBox();
    ancienneteInput->setRange(0, 50);
    ancienneteInput->setValue(2);
    infoProLayout->addWidget(ancienneteInput, 2, 1);
    
    infoProLayout->addWidget(new QLabel("Disponibilité:"), 3, 0);
    disponibiliteCombo = new QComboBox();
    disponibiliteCombo->addItems({"-- Tous --", "Disponible", "En congé", "En formation", "Indisponible"});
    infoProLayout->addWidget(disponibiliteCombo, 3, 1);
    
    infoProLayout->addWidget(new QLabel("Heures/semaine:"), 4, 0);
    heuresInput = new QSpinBox();
    heuresInput->setRange(0, 168);
    heuresInput->setValue(35);
    infoProLayout->addWidget(heuresInput, 4, 1);
    
    scrollLayout->addWidget(infoProGroup);
    
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
    
    bool connected = Connection::instance()->createConnect();
    if (connected) {
        QMessageBox::information(this, "Connexion réussie", "Connexion à la base de données établie avec succès.");
        QList<QVariantMap> machines;
        if (Connection::instance()->getMachines(machines) && machines.isEmpty()) {
            Connection::instance()->ajouterMachine("MCH-001", "Presse Hydraulique", "Presse", "REF-001", "01/01/2023", "En service", "Atelier A");
            Connection::instance()->ajouterMachine("MCH-002", "Tour CNC", "Moteur", "REF-002", "15/03/2023", "En maintenance", "Atelier B");
            Connection::instance()->ajouterMachine("MCH-003", "Fraiseuse", "Filtre", "REF-003", "20/05/2023", "En service", "Atelier A");
            Connection::instance()->ajouterMachine("MCH-004", "Compresseur", "Capteur", "REF-004", "10/07/2023", "Panne", "Local technique");
            initialiserTableMachines();
            remplirComboboxIds();
        }
    } else {
        QMessageBox::critical(this, "Erreur de connexion", "Impossible de se connecter à la base de données.");
    }
    
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
    
    ui->stackedPages->setCurrentWidget(ui->pageMachine);
    
    initialiserTableMachines();
    initialiserTableHistorique();
    initialiserStatistiques();
    setupConnections();
    ajouterInterventionsDemo();
    mettreAJourStatistiques();
    remplirComboboxIds();
    onTabChanged(ui->tabWidget->currentIndex());
    appliquerStyleCSS();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initialiserTableMachines()
{
    ui->tableEquipments->setColumnCount(7);
    QStringList headers = {"ID Machine", "Nom", "Catégorie", "Référence", "Date Achat", "État", "Localisation"};
    ui->tableEquipments->setHorizontalHeaderLabels(headers);
    ui->tableEquipments->horizontalHeader()->setStretchLastSection(true);
    ui->tableEquipments->setAlternatingRowColors(true);
    ui->tableEquipments->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableEquipments->setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    QList<QVariantMap> machines;
    if (Connection::instance()->getMachines(machines)) {
        ui->tableEquipments->setRowCount(machines.size());
        for (int i = 0; i < machines.size(); ++i) {
            const QVariantMap& machine = machines[i];
            ui->tableEquipments->setItem(i, 0, new QTableWidgetItem(machine["id"].toString()));
            ui->tableEquipments->setItem(i, 1, new QTableWidgetItem(machine["nom"].toString()));
            ui->tableEquipments->setItem(i, 2, new QTableWidgetItem(machine["categorie"].toString()));
            ui->tableEquipments->setItem(i, 3, new QTableWidgetItem(machine["reference"].toString()));
            ui->tableEquipments->setItem(i, 4, new QTableWidgetItem(machine["date_achat"].toString()));
            ui->tableEquipments->setItem(i, 5, new QTableWidgetItem(machine["etat"].toString()));
            ui->tableEquipments->setItem(i, 6, new QTableWidgetItem(machine["localisation"].toString()));
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
}

void MainWindow::setupConnections()
{
    if (ui->btnAddValider) {
        connect(ui->btnAddValider, &QPushButton::clicked, this, &MainWindow::ouvrirAjoutMachine);
    }
    if (ui->btnModifierValider) {
        connect(ui->btnModifierValider, &QPushButton::clicked, this, &MainWindow::validerModificationMachine);
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
    if (ui->btnExportPDF) {
        connect(ui->btnExportPDF, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    if (ui->btnExportPDF_Historique) {
        connect(ui->btnExportPDF_Historique, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    if (ui->btnExportPDF_Stats) {
        connect(ui->btnExportPDF_Stats, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    if (ui->btnApplyFilter) {
        connect(ui->btnApplyFilter, &QPushButton::clicked, this, &MainWindow::appliquerFiltres);
    }
    if (ui->btnScanQR_RightPanel) {
        connect(ui->btnScanQR_RightPanel, &QPushButton::clicked, this, &MainWindow::scannerQR);
    }
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
    
    // Connexion du bouton Ajouter Employé
    if (ui->btnAddEmployee) {
        connect(ui->btnAddEmployee, &QPushButton::clicked, this, &MainWindow::ouvrirAjoutEmploye);
    }
    
    connect(ui->tableEquipments, &QTableWidget::itemSelectionChanged, 
            this, &MainWindow::onTableMachineSelectionChanged);
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::onTabChanged);
}

void MainWindow::onTabChanged(int index)
{
    if (!ui->leftPanel) return;
    bool showLeftPanel = (index == 0);
    ui->leftPanel->setVisible(showLeftPanel);
    qDebug() << "Onglet changé - Panneau gauche visible:" << showLeftPanel;
}

void MainWindow::appliquerFiltres()
{
    QString recherche = ui->lineEditSearch->text().trimmed();
    QString categorie = ui->comboCategory->currentText();
    QString etat = ui->comboState->currentText();
    QString localisation = ui->lineEditLocation->text().trimmed();
    QString triPar = ui->comboSortBy->currentText();
    bool croissant = ui->radioCroissant->isChecked();
    
    QList<QVariantMap> toutesMachines;
    if (!Connection::instance()->getMachines(toutesMachines)) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger les machines");
        return;
    }
    
    QList<QVariantMap> machinesFiltrees;
    for (const QVariantMap& machine : toutesMachines) {
        bool matchRecherche = recherche.isEmpty() ||
            machine["id"].toString().contains(recherche, Qt::CaseInsensitive) ||
            machine["nom"].toString().contains(recherche, Qt::CaseInsensitive) ||
            machine["reference"].toString().contains(recherche, Qt::CaseInsensitive);
        
        bool matchCategorie = (categorie == "Toutes") || 
            (machine["categorie"].toString() == categorie);
        
        bool matchEtat = (etat == "Tous") || 
            (machine["etat"].toString() == etat);
        
        bool matchLocalisation = localisation.isEmpty() ||
            machine["localisation"].toString().contains(localisation, Qt::CaseInsensitive);
        
        if (matchRecherche && matchCategorie && matchEtat && matchLocalisation) {
            machinesFiltrees.append(machine);
        }
    }
    
    if (triPar == "Nom") {
        std::sort(machinesFiltrees.begin(), machinesFiltrees.end(),
            [croissant](const QVariantMap& a, const QVariantMap& b) {
                if (croissant) return a["nom"].toString() < b["nom"].toString();
                else return a["nom"].toString() > b["nom"].toString();
            });
    } else if (triPar == "Date d'achat") {
        std::sort(machinesFiltrees.begin(), machinesFiltrees.end(),
            [croissant](const QVariantMap& a, const QVariantMap& b) {
                QDate dateA = QDate::fromString(a["date_achat"].toString(), "dd/MM/yyyy");
                QDate dateB = QDate::fromString(b["date_achat"].toString(), "dd/MM/yyyy");
                if (croissant) return dateA < dateB;
                else return dateA > dateB;
            });
    } else if (triPar == "État") {
        std::sort(machinesFiltrees.begin(), machinesFiltrees.end(),
            [croissant](const QVariantMap& a, const QVariantMap& b) {
                if (croissant) return a["etat"].toString() < b["etat"].toString();
                else return a["etat"].toString() > b["etat"].toString();
            });
    } else if (triPar == "Catégorie") {
        std::sort(machinesFiltrees.begin(), machinesFiltrees.end(),
            [croissant](const QVariantMap& a, const QVariantMap& b) {
                if (croissant) return a["categorie"].toString() < b["categorie"].toString();
                else return a["categorie"].toString() > b["categorie"].toString();
            });
    } else if (triPar == "Localisation") {
        std::sort(machinesFiltrees.begin(), machinesFiltrees.end(),
            [croissant](const QVariantMap& a, const QVariantMap& b) {
                if (croissant) return a["localisation"].toString() < b["localisation"].toString();
                else return a["localisation"].toString() > b["localisation"].toString();
            });
    }
    
    ui->tableEquipments->setRowCount(machinesFiltrees.size());
    for (int i = 0; i < machinesFiltrees.size(); ++i) {
        const QVariantMap& machine = machinesFiltrees[i];
        ui->tableEquipments->setItem(i, 0, new QTableWidgetItem(machine["id"].toString()));
        ui->tableEquipments->setItem(i, 1, new QTableWidgetItem(machine["nom"].toString()));
        ui->tableEquipments->setItem(i, 2, new QTableWidgetItem(machine["categorie"].toString()));
        ui->tableEquipments->setItem(i, 3, new QTableWidgetItem(machine["reference"].toString()));
        ui->tableEquipments->setItem(i, 4, new QTableWidgetItem(machine["date_achat"].toString()));
        ui->tableEquipments->setItem(i, 5, new QTableWidgetItem(machine["etat"].toString()));
        ui->tableEquipments->setItem(i, 6, new QTableWidgetItem(machine["localisation"].toString()));
    }
    
    QMessageBox::information(this, "Filtres appliqués", 
        QString("%1 machine(s) trouvée(s)").arg(machinesFiltrees.size()));
}

void MainWindow::ajouterMachinesDemo()
{
}

void MainWindow::ajouterInterventionsDemo()
{
    Connection::instance()->ajouterIntervention("15/02/2024", "MCH-001", "Maintenance préventive", "Jean Dupont", 350.00, "Terminé");
    Connection::instance()->ajouterIntervention("10/03/2024", "MCH-002", "Réparation", "Marie Martin", 520.00, "En cours");
    Connection::instance()->ajouterIntervention("05/04/2024", "MCH-004", "Dépannage", "Pierre Durand", 120.00, "Terminé");
    initialiserTableHistorique();
}

void MainWindow::remplirComboboxIds()
{
    if (ui->comboModifierId) {
        ui->comboModifierId->clear();
        for (int i = 0; i < ui->tableEquipments->rowCount(); i++) {
            ui->comboModifierId->addItem(ui->tableEquipments->item(i, 0)->text());
        }
    }
    if (ui->comboSupprimerId) {
        ui->comboSupprimerId->clear();
        for (int i = 0; i < ui->tableEquipments->rowCount(); i++) {
            ui->comboSupprimerId->addItem(ui->tableEquipments->item(i, 0)->text());
        }
    }
    if (ui->comboPanneId) {
        ui->comboPanneId->clear();
        for (int i = 0; i < ui->tableEquipments->rowCount(); i++) {
            ui->comboPanneId->addItem(ui->tableEquipments->item(i, 0)->text());
        }
    }
}

void MainWindow::ouvrirAjoutMachine()
{
    QString id = ui->editAddId ? ui->editAddId->text().trimmed() : QString();
    QString nom = ui->editAddNom ? ui->editAddNom->text().trimmed() : QString();
    QString categorie = ui->comboAddCategorie ? ui->comboAddCategorie->currentText() : QString("Presse");
    QString reference = ui->editAddReference ? ui->editAddReference->text().trimmed() : QString();
    QString dateAchat = ui->dateAddAchat ? ui->dateAddAchat->date().toString("dd/MM/yyyy") : QDate::currentDate().toString("dd/MM/yyyy");
    QString etat = ui->comboAddEtat ? ui->comboAddEtat->currentText() : QString("En service");
    QString localisation = ui->editAddLocalisation ? ui->editAddLocalisation->text().trimmed() : QString();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "Le nom de la machine est obligatoire");
        return;
    }
    if (reference.isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "La référence est obligatoire");
        return;
    }
    
    if (id.isEmpty()) {
        int newNum = ui->tableEquipments->rowCount() + 1;
        id = QString("MCH-%1").arg(newNum, 3, 10, QChar('0'));
    } else {
        // Validation manuelle du format ID sans QRegExp
        if (!id.startsWith("MCH-") || id.length() != 7) {
            QMessageBox::warning(this, "Format ID invalide", "L'ID doit être au format MCH-XXX (ex: MCH-001)");
            return;
        }
        QString numPart = id.mid(4);
        bool ok;
        numPart.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Format ID invalide", "L'ID doit être au format MCH-XXX (ex: MCH-001)");
            return;
        }
    }

    if (Connection::instance()->ajouterMachine(id, nom, categorie, reference, dateAchat, etat, localisation)) {
        QMessageBox::information(this, "Succès", "Machine ajoutée avec succès !");
        initialiserTableMachines();
        remplirComboboxIds();
        mettreAJourStatistiques();
        
        ui->editAddId->clear();
        ui->editAddNom->clear();
        ui->editAddReference->clear();
        ui->editAddLocalisation->clear();
        ui->comboAddCategorie->setCurrentIndex(0);
        ui->comboAddEtat->setCurrentIndex(0);
        ui->dateAddAchat->setDate(QDate::currentDate());
        
        ui->tabWidget->setCurrentWidget(ui->tabList);
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout :\n" + Connection::instance()->lastError());
    }
}

void MainWindow::validerModificationMachine()
{
    QString id = ui->comboModifierId->currentText();
    QString nom = ui->editModifierNom->text();
    QString categorie = ui->comboModifierCategorie->currentText();
    QString reference = ui->editModifierReference->text();
    QString dateAchat = ui->dateModifierAchat->date().toString("dd/MM/yyyy");
    QString etat = ui->comboModifierEtat->currentText();
    QString localisation = ui->editModifierLocalisation->text();
    
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "Le nom de la machine est obligatoire");
        return;
    }
    if (reference.isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "La référence est obligatoire");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation modification", 
        QString("Voulez-vous modifier la machine %1 ?").arg(id),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (Connection::instance()->modifierMachine(id, nom, categorie, reference, dateAchat, etat, localisation)) {
            QMessageBox::information(this, "Succès", "Machine modifiée avec succès !");
            initialiserTableMachines();
            remplirComboboxIds();
            mettreAJourStatistiques();
            ui->tabWidget->setCurrentWidget(ui->tabList);
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la modification :\n" + Connection::instance()->lastError());
        }
    }
}

void MainWindow::ouvrirSupprimerMachine()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une machine à supprimer.");
        return;
    }
    
    QString id = ui->tableEquipments->item(selectedRow, 0)->text();
    QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmer la suppression", 
        QString("Êtes-vous sûr de vouloir supprimer la machine '%1' (ID: %2) ?\nCette action est irréversible !")
        .arg(nom).arg(id),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        if (Connection::instance()->supprimerMachine(id)) {
            QMessageBox::information(this, "Succès", "Machine supprimée avec succès !");
            initialiserTableMachines();
            remplirComboboxIds();
            mettreAJourStatistiques();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression :\n" + Connection::instance()->lastError());
        }
    }
}

void MainWindow::ouvrirSignalerPanne()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une machine à signaler.");
        return;
    }
    
    QString id = ui->tableEquipments->item(selectedRow, 0)->text();
    QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
    QString etatActuel = ui->tableEquipments->item(selectedRow, 5)->text();
    
    if (etatActuel == "Panne") {
        QMessageBox::information(this, "Déjà en panne", "Cette machine est déjà signalée en panne.");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", 
        QString("Voulez-vous signaler une panne pour la machine '%1' ?").arg(nom),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        QString categorie = ui->tableEquipments->item(selectedRow, 2)->text();
        QString reference = ui->tableEquipments->item(selectedRow, 3)->text();
        QString dateAchat = ui->tableEquipments->item(selectedRow, 4)->text();
        QString localisation = ui->tableEquipments->item(selectedRow, 6)->text();
        
        if (Connection::instance()->modifierMachine(id, nom, categorie, reference, dateAchat, "Panne", localisation)) {
            QMessageBox::information(this, "Succès", "Panne signalée avec succès !");
            initialiserTableMachines();
            remplirComboboxIds();
            mettreAJourStatistiques();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors du signalement :\n" + Connection::instance()->lastError());
        }
    }
}

void MainWindow::ouvrirAjouterIntervention()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une machine.");
        return;
    }
    
    QString machineId = ui->tableEquipments->item(selectedRow, 0)->text();
    QString machineNom = ui->tableEquipments->item(selectedRow, 1)->text();
    
    QDialog dialog(this);
    dialog.setWindowTitle("Ajouter une intervention");
    dialog.setModal(true);
    dialog.resize(400, 350);
    
    QVBoxLayout *layout = new QVBoxLayout(&dialog);
    QFormLayout *form = new QFormLayout();
    
    QLabel *machineLabel = new QLabel(machineId + " - " + machineNom);
    machineLabel->setStyleSheet("font-weight: bold; color: #798777;");
    
    QDateEdit *dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("dd/MM/yyyy");
    
    QComboBox *typeCombo = new QComboBox();
    typeCombo->addItems({"Maintenance préventive", "Réparation", "Dépannage", "Inspection", "Mise à jour"});
    
    QLineEdit *technicienEdit = new QLineEdit();
    technicienEdit->setPlaceholderText("Nom du technicien");
    
    QDoubleSpinBox *coutSpin = new QDoubleSpinBox();
    coutSpin->setRange(0, 100000);
    coutSpin->setPrefix("€ ");
    coutSpin->setValue(0);
    
    QComboBox *statutCombo = new QComboBox();
    statutCombo->addItems({"Planifié", "En cours", "Terminé", "Annulé"});
    
    form->addRow("Machine:", machineLabel);
    form->addRow("Date:", dateEdit);
    form->addRow("Type:", typeCombo);
    form->addRow("Technicien:", technicienEdit);
    form->addRow("Coût:", coutSpin);
    form->addRow("Statut:", statutCombo);
    
    QDialogButtonBox *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    buttons->button(QDialogButtonBox::Ok)->setText("Ajouter");
    buttons->button(QDialogButtonBox::Cancel)->setText("Annuler");
    connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);
    
    layout->addLayout(form);
    layout->addWidget(buttons);
    
    if (dialog.exec() == QDialog::Accepted) {
        QString date = dateEdit->date().toString("dd/MM/yyyy");
        QString type = typeCombo->currentText();
        QString technicien = technicienEdit->text();
        double cout = coutSpin->value();
        QString statut = statutCombo->currentText();
        
        if (technicien.isEmpty()) {
            technicien = "Technicien non spécifié";
        }
        
        if (Connection::instance()->ajouterIntervention(date, machineId, type, technicien, cout, statut)) {
            QMessageBox::information(this, "Succès", "Intervention ajoutée avec succès !");
            initialiserTableHistorique();
            mettreAJourStatistiques();
        } else {
            QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout :\n" + Connection::instance()->lastError());
        }
    }
}

void MainWindow::ouvrirAjoutEmploye()
{
    AjouterEmployeDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString id = dialog.getIdInput()->text();
        QString nom = dialog.getNomInput()->text();
        QString prenom = dialog.getPrenomInput()->text();
        int age = dialog.getAgeInput()->value();
        QString telephone = dialog.getTelephoneInput()->text();
        
        if (!Connection::instance()->ajouterEmploye(id, nom, prenom, age, telephone)) {
            QString err = Connection::instance()->lastError();
            QMessageBox::warning(this, "Avertissement", QString("Erreur lors de l'ajout de l'employé :\n%1").arg(err));
        } else {
            QMessageBox::information(this, "Succès", 
                QString("Employé ajouté avec succès !\n\nID: %1\nNom: %2 %3\nÂge: %4\nTéléphone: %5")
                .arg(id).arg(prenom).arg(nom).arg(age).arg(telephone));
        }
    }
}

void MainWindow::scannerQR()
{
    QMessageBox::information(this, "Scanner QR Code", 
        "📷 Fonctionnalité de scan QR code\n\nPointez la caméra vers le QR code de la machine.\n\n(Mode démonstration - Simulation de scan)");
}

void MainWindow::exporterPDF()
{
    QMessageBox::information(this, "Exporter PDF", 
        "📄 Fonctionnalité d'export PDF\n\nLe rapport sera généré au format PDF.\n\n(Mode démonstration - Simulation d'export)");
}

void MainWindow::onTableMachineSelectionChanged()
{
    int selectedRow = ui->tableEquipments->currentRow();
    if (selectedRow >= 0) {
        QString id = ui->tableEquipments->item(selectedRow, 0)->text();
        QString nom = ui->tableEquipments->item(selectedRow, 1)->text();
        QString categorie = ui->tableEquipments->item(selectedRow, 2)->text();
        QString reference = ui->tableEquipments->item(selectedRow, 3)->text();
        QString dateAchat = ui->tableEquipments->item(selectedRow, 4)->text();
        QString etat = ui->tableEquipments->item(selectedRow, 5)->text();
        QString localisation = ui->tableEquipments->item(selectedRow, 6)->text();
        
        if (ui->comboModifierId) {
            int index = ui->comboModifierId->findText(id);
            if (index >= 0) ui->comboModifierId->setCurrentIndex(index);
        }
        if (ui->editModifierNom) ui->editModifierNom->setText(nom);
        if (ui->comboModifierCategorie) {
            int index = ui->comboModifierCategorie->findText(categorie);
            if (index >= 0) ui->comboModifierCategorie->setCurrentIndex(index);
        }
        if (ui->editModifierReference) ui->editModifierReference->setText(reference);
        if (ui->dateModifierAchat) {
            QDate date = QDate::fromString(dateAchat, "dd/MM/yyyy");
            ui->dateModifierAchat->setDate(date);
        }
        if (ui->comboModifierEtat) {
            int index = ui->comboModifierEtat->findText(etat);
            if (index >= 0) ui->comboModifierEtat->setCurrentIndex(index);
        }
        if (ui->editModifierLocalisation) ui->editModifierLocalisation->setText(localisation);
        
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
}

void MainWindow::mettreAJourStatistiques()
{
    int total = ui->tableEquipments->rowCount();
    int enService = 0, enMaintenance = 0, enPanne = 0, horsService = 0;
    
    for (int i = 0; i < total; i++) {
        QString etat = ui->tableEquipments->item(i, 5)->text();
        if (etat == "En service") enService++;
        else if (etat == "Maintenance" || etat == "En maintenance") enMaintenance++;
        else if (etat == "Panne") enPanne++;
        else if (etat == "Hors service") horsService++;
    }
    
    if (ui->statTotal) ui->statTotal->setText(QString::number(total));
    if (ui->statOp) ui->statOp->setText(QString::number(enService));
    if (ui->statMaint) ui->statMaint->setText(QString::number(enMaintenance));
    if (ui->statDef) ui->statDef->setText(QString::number(enPanne + horsService));
}

void MainWindow::ouvrirSupprimerIntervention()
{
    int selectedRow = ui->tableHistorique->currentRow();
    if (selectedRow < 0) {
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une intervention à supprimer.");
        return;
    }
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmer", "Voulez-vous vraiment supprimer cette intervention ?", QMessageBox::Yes | QMessageBox::No);
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
        QMessageBox::warning(this, "Aucune sélection", "Veuillez sélectionner une intervention à consulter.");
        return;
    }
    QString details = QString("=== DÉTAILS DE L'INTERVENTION ===\n\nDate: %1\nMachine: %2\nType: %3\nTechnicien: %4\nCoût: %5\nStatut: %6")
        .arg(ui->tableHistorique->item(selectedRow, 0)->text())
        .arg(ui->tableHistorique->item(selectedRow, 1)->text())
        .arg(ui->tableHistorique->item(selectedRow, 2)->text())
        .arg(ui->tableHistorique->item(selectedRow, 3)->text())
        .arg(ui->tableHistorique->item(selectedRow, 4)->text())
        .arg(ui->tableHistorique->item(selectedRow, 5)->text());
    QMessageBox::information(this, "Détails de l'intervention", details);
}

void MainWindow::appliquerStyleCSS()
{
    qDebug() << "Style CSS appliqué";
}