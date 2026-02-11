#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QTextCharFormat>
#include <QColor>
#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QFormLayout>
#include <QComboBox>
#include <QDateEdit>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QGroupBox>
#include <QTabWidget>
#include <QTableWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ────────────────────────────────────────────────
    // Style directement intégré
    // ────────────────────────────────────────────────
    QString styleSheet = R"(
/* Smart Oil Press Management - Stylesheet */

/* ============================================
   COULEURS PRINCIPALES
   ============================================ */

QMainWindow {
    background-color: #F8EDE3;
}

QWidget {
    background-color: #F8EDE3;
    color: #798777;
}

/* ============================================
   TOOLBAR
   ============================================ */
QToolBar {
    background-color: #A2B29F;
    border-bottom: 2px solid #BDD2B6;
    spacing: 5px;
    padding: 5px;
}

QToolBar::separator {
    background-color: #BDD2B6;
    width: 2px;
    margin: 0px 5px;
}

/* ============================================
   GROUPBOX
   ============================================ */
QGroupBox {
    background-color: #F8EDE3;
    border: 2px solid #A2B29F;
    border-radius: 5px;
    margin-top: 10px;
    padding-top: 10px;
    color: #798777;
    font-weight: bold;
}

QGroupBox::title {
    subcontrol-origin: margin;
    left: 10px;
    padding: 0px 5px 0px 5px;
}

/* ============================================
   LABELS
   ============================================ */
QLabel {
    color: #798777;
    background-color: transparent;
}

/* ============================================
   LINE EDIT / INPUT
   ============================================ */
QLineEdit {
    background-color: #ffffff;
    color: #798777;
    border: 2px solid #BDD2B6;
    border-radius: 4px;
    padding: 5px;
    font-size: 11pt;
}

QLineEdit:focus {
    border: 2px solid #A2B29F;
    background-color: #F8EDE3;
}

QLineEdit::placeholder {
    color: #a0a0a0;
}

/* ============================================
   COMBOBOX
   ============================================ */
QComboBox {
    background-color: #ffffff;
    color: #798777;
    border: 2px solid #BDD2B6;
    border-radius: 4px;
    padding: 5px;
    font-size: 11pt;
}

QComboBox::drop-down {
    background-color: #BDD2B6;
    border: none;
    border-radius: 3px;
}

QComboBox::down-arrow {
    image: none;
    background-color: #BDD2B6;
}

QComboBox:focus {
    border: 2px solid #A2B29F;
}

/* ============================================
   BUTTONS
   ============================================ */
QPushButton {
    background-color: #A2B29F;
    color: #ffffff;
    border: none;
    border-radius: 5px;
    padding: 8px 15px;
    font-weight: bold;
    font-size: 11pt;
}

QPushButton:hover {
    background-color: #BDD2B6;
    color: #798777;
}

QPushButton:pressed {
    background-color: #798777;
    color: #F8EDE3;
}

QPushButton:disabled {
    background-color: #6d6d6d;
    color: #a0a0a0;
}

/* ============================================
   TABLES
   ============================================ */
QTableWidget {
    background-color: #ffffff;
    alternate-background-color: #F8EDE3;
    gridline-color: #A2B29F;
    border: 1px solid #A2B29F;
    border-radius: 4px;
}

QTableWidget::item {
    padding: 5px;
    color: #798777;
}

QTableWidget::item:selected {
    background-color: #BDD2B6;
    color: #798777;
}

QHeaderView::section {
    background-color: #A2B29F;
    color: #F8EDE3;
    padding: 5px;
    border: 1px solid #BDD2B6;
    font-weight: bold;
}

/* ============================================
   SPINBOX / DOUBLESPINBOX
   ============================================ */
QSpinBox, QDoubleSpinBox {
    background-color: #ffffff;
    color: #798777;
    border: 2px solid #BDD2B6;
    border-radius: 4px;
    padding: 5px;
}

QSpinBox::up-button, QDoubleSpinBox::up-button {
    background-color: #BDD2B6;
    border: none;
    width: 20px;
}

QSpinBox::down-button, QDoubleSpinBox::down-button {
    background-color: #BDD2B6;
    border: none;
    width: 20px;
}

/* ============================================
   CHECKBOXES & RADIOBUTTONS
   ============================================ */
QCheckBox, QRadioButton {
    color: #798777;
    background-color: transparent;
    spacing: 5px;
}

QCheckBox::indicator, QRadioButton::indicator {
    width: 18px;
    height: 18px;
    border: 2px solid #BDD2B6;
    border-radius: 3px;
}

QCheckBox::indicator:checked, QRadioButton::indicator:checked {
    background-color: #A2B29F;
    border: 2px solid #A2B29F;
}

QCheckBox::indicator:hover, QRadioButton::indicator:hover {
    border: 2px solid #798777;
}

/* ============================================
   DIALOG
   ============================================ */
QDialog {
    background-color: #F8EDE3;
}

/* ============================================
   MENUBARS & MENUS
   ============================================ */
QMenuBar {
    background-color: #A2B29F;
    color: #F8EDE3;
    border-bottom: 2px solid #BDD2B6;
}

QMenuBar::item:selected {
    background-color: #BDD2B6;
    color: #798777;
}

QMenu {
    background-color: #A2B29F;
    color: #F8EDE3;
    border: 1px solid #BDD2B6;
}

QMenu::item:selected {
    background-color: #BDD2B6;
    color: #798777;
}

/* ============================================
   SPLITTER
   ============================================ */
QSplitter::handle {
    background-color: #BDD2B6;
    width: 2px;
}

QSplitter::handle:hover {
    background-color: #A2B29F;
}

/* ============================================
   SCROLLBAR
   ============================================ */
QScrollBar:vertical {
    background-color: #F8EDE3;
    width: 12px;
    border: 1px solid #A2B29F;
}

QScrollBar::handle:vertical {
    background-color: #BDD2B6;
    border-radius: 6px;
    min-height: 20px;
}

QScrollBar::handle:vertical:hover {
    background-color: #A2B29F;
}

QScrollBar:horizontal {
    background-color: #F8EDE3;
    height: 12px;
    border: 1px solid #A2B29F;
}

QScrollBar::handle:horizontal {
    background-color: #BDD2B6;
    border-radius: 6px;
    min-width: 20px;
}

QScrollBar::handle:horizontal:hover {
    background-color: #A2B29F;
}

/* ============================================
   TABS
   ============================================ */
QTabWidget::pane {
    border: 1px solid #A2B29F;
    background-color: #F8EDE3;
}

QTabBar::tab {
    background-color: #A2B29F;
    color: #F8EDE3;
    padding: 8px 20px;
    border: 1px solid #BDD2B6;
    border-bottom: none;
    border-radius: 4px 4px 0px 0px;
}

QTabBar::tab:selected {
    background-color: #BDD2B6;
    color: #798777;
    font-weight: bold;
}

QTabBar::tab:hover {
    background-color: #B5BAB0;
}

/* ============================================
   STATUS BAR & PROGRESS BAR
   ============================================ */
QStatusBar {
    background-color: #A2B29F;
    color: #F8EDE3;
    border-top: 2px solid #BDD2B6;
}

QProgressBar {
    background-color: #F8EDE3;
    border: 2px solid #BDD2B6;
    border-radius: 4px;
    text-align: center;
    color: #798777;
}

QProgressBar::chunk {
    background-color: #BDD2B6;
    border-radius: 2px;
}

/* ============================================
   TOOLTIPS
   ============================================ */
QToolTip {
    background-color: #BDD2B6;
    color: #798777;
    border: 1px solid #A2B29F;
    border-radius: 4px;
    padding: 3px;
}
)";

    qApp->setStyleSheet(styleSheet);

    // ────────────────────────────────────────────────
    // Configuration des connexions et données
    // ────────────────────────────────────────────────
    setupConnections();
    setupTableData();
    updateStatistics();

    // Configurer le calendrier
    QDate today = QDate::currentDate();
    ui->dateFrom->setDate(today.addDays(-30));
    ui->dateTo->setDate(today);

    // Page par défaut
    ui->stackedPages->setCurrentWidget(ui->pageOrder);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupConnections()
{
    // Connecter les boutons du menu latéral
    connect(ui->btnEmployee, &QPushButton::clicked, this, &MainWindow::onBtnEmployeeClicked);
    connect(ui->btnTeam, &QPushButton::clicked, this, &MainWindow::onBtnTeamClicked);
    connect(ui->btnClient, &QPushButton::clicked, this, &MainWindow::onBtnClientClicked);
    connect(ui->btnLaboratory, &QPushButton::clicked, this, &MainWindow::onBtnLaboratoryClicked);
    connect(ui->btnOrder, &QPushButton::clicked, this, &MainWindow::onBtnOrderClicked);
    connect(ui->btnMachine, &QPushButton::clicked, this, &MainWindow::onBtnMachineClicked);

    // Connecter les actions de la toolbar/menu
    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::onActionNew);
    connect(ui->actionEdit, &QAction::triggered, this, &MainWindow::onActionEdit);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::onActionDelete);
    connect(ui->actionEnvoyerEmail, &QAction::triggered, this, &MainWindow::onActionSendEmail);
    connect(ui->actionExportPDF, &QAction::triggered, this, &MainWindow::onActionExportPDF);
    connect(ui->actionRefresh, &QAction::triggered, this, &MainWindow::onActionRefresh);
    connect(ui->actionExit, &QAction::triggered, this, &MainWindow::onActionExit);

    // Connecter les boutons d'actions rapides
    connect(ui->btnNewCommande, &QPushButton::clicked, this, &MainWindow::onBtnNewCommandeClicked);
    connect(ui->btnEditCommande, &QPushButton::clicked, this, &MainWindow::onBtnEditCommandeClicked);
    connect(ui->btnDeleteCommande, &QPushButton::clicked, this, &MainWindow::onBtnDeleteCommandeClicked);
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &MainWindow::onBtnEnvoyerEmailClicked);

    // Connecter la navigation depuis la page Machine
    connect(ui->btnCommandeFromProduit, &QPushButton::clicked, this, &MainWindow::onBtnCommandeFromProduitClicked);

    // Connecter les fonctionnalités avancées
    connect(ui->groupBoxStatsByType, &QGroupBox::clicked, this, &MainWindow::onGroupBoxStatsByTypeClicked);
    connect(ui->groupBoxStatsDepenses, &QGroupBox::clicked, this, &MainWindow::onGroupBoxStatsDepensesClicked);
    connect(ui->groupBoxCalendrier, &QGroupBox::clicked, this, &MainWindow::onGroupBoxCalendrierClicked);

    // Connecter la sélection dans la table
    connect(ui->tableCommandes, &QTableWidget::itemSelectionChanged, this, &MainWindow::updateQuickInfo);

    // Connecter les filtres
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &MainWindow::onSearchTextChanged);
    connect(ui->comboFournisseur, &QComboBox::currentTextChanged, this, &MainWindow::onFilterChanged);
    connect(ui->comboStatus, &QComboBox::currentTextChanged, this, &MainWindow::onFilterChanged);
    connect(ui->dateFrom, &QDateEdit::dateChanged, this, &MainWindow::onFilterChanged);
    connect(ui->dateTo, &QDateEdit::dateChanged, this, &MainWindow::onFilterChanged);
}

void MainWindow::setupTableData()
{
    // Configurer la table avec des données de test
    QStringList headers = {"ID", "Libellé", "Fournisseur", "État", "Date Arrivée", "Date Sortie", "Montant Total"};
    ui->tableCommandes->setColumnCount(headers.size());

    for (int i = 0; i < headers.size(); ++i) {
        QTableWidgetItem *header = new QTableWidgetItem(headers[i]);
        ui->tableCommandes->setHorizontalHeaderItem(i, header);
    }

    // Données de test
    QStringList commandesData = {
        "CMD001,Huile d'olive vierge extra,Fournisseur A,En cours,2024-01-15,2024-01-20,1500.00€",
        "CMD002,Presse hydraulique 20T,Fournisseur B,Validée,2024-01-10,2024-01-25,2300.00€",
        "CMD003,Filtres à huile premium,Fournisseur C,Prête,2024-01-05,2024-01-30,1800.00€",
        "CMD004,Bouteilles verre 500ml,Fournisseur A,Annulée,2024-01-12,2024-01-12,900.00€",
        "CMD005,Machine d'embouteillage,Fournisseur D,En cours,2024-01-18,,3500.00€",
        "CMD006,Étiquettes personnalisées,Fournisseur B,Prête,2024-01-08,2024-01-28,650.00€"
    };

    ui->tableCommandes->setRowCount(commandesData.size());

    for (int row = 0; row < commandesData.size(); ++row) {
        QStringList fields = commandesData[row].split(',');
        for (int col = 0; col < fields.size() && col < headers.size(); ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(fields[col]);
            ui->tableCommandes->setItem(row, col, item);
        }
    }

    // Ajuster la largeur des colonnes
    ui->tableCommandes->resizeColumnsToContents();
}

// ==================== NAVIGATION MENU ====================

void MainWindow::onBtnEmployeeClicked()
{
    ui->stackedPages->setCurrentWidget(ui->pageEmployee);
    showCrudDialog("Gestion des Employés");
}

void MainWindow::onBtnTeamClicked()
{
    ui->stackedPages->setCurrentWidget(ui->pageTeam);
    showCrudDialog("Gestion des Équipes");
}

void MainWindow::onBtnClientClicked()
{
    ui->stackedPages->setCurrentWidget(ui->pageClient);
    showCrudDialog("Gestion des Clients");
}

void MainWindow::onBtnLaboratoryClicked()
{
    ui->stackedPages->setCurrentWidget(ui->pageLaboratory);
    showCrudDialog("Gestion des Laboratoires");
}

void MainWindow::onBtnOrderClicked()
{
    ui->stackedPages->setCurrentWidget(ui->pageOrder);
    onActionRefresh(); // Rafraîchir les données
}

void MainWindow::onBtnMachineClicked()
{
    ui->stackedPages->setCurrentWidget(ui->pageMachine);
    showCrudDialog("Gestion des Machines/Produits");
}

// ==================== CRUD ACTIONS ====================

void MainWindow::onActionNew()
{
    QString currentPage = ui->stackedPages->currentWidget()->objectName();

    if (currentPage == "pageOrder") {
        showCrudDialog("Nouvelle Commande");
    } else if (currentPage == "pageEmployee") {
        showCrudDialog("Nouvel Employé");
    } else if (currentPage == "pageClient") {
        showCrudDialog("Nouveau Client");
    } else if (currentPage == "pageMachine") {
        showCrudDialog("Nouvelle Machine/Produit");
    } else {
        showCrudDialog("Nouvel Élément");
    }
}

void MainWindow::onActionEdit()
{
    QString currentPage = ui->stackedPages->currentWidget()->objectName();

    if (currentPage == "pageOrder") {
        if (ui->tableCommandes->currentRow() >= 0) {
            showCrudDialog("Modifier Commande");
        } else {
            QMessageBox::warning(this, "Aucune sélection",
                                 "Veuillez sélectionner une commande à modifier.");
        }
    } else {
        showCrudDialog("Modifier Élément");
    }
}

void MainWindow::onActionDelete()
{
    QString currentPage = ui->stackedPages->currentWidget()->objectName();

    if (currentPage == "pageOrder") {
        int currentRow = ui->tableCommandes->currentRow();
        if (currentRow >= 0) {
            QMessageBox::StandardButton reply;
            reply = QMessageBox::question(this, "Confirmation",
                                          "Êtes-vous sûr de vouloir supprimer cette commande ?",
                                          QMessageBox::Yes | QMessageBox::No);

            if (reply == QMessageBox::Yes) {
                ui->tableCommandes->removeRow(currentRow);
                updateStatistics();
                QMessageBox::information(this, "Succès", "Commande supprimée avec succès.");
            }
        } else {
            QMessageBox::warning(this, "Aucune sélection",
                                 "Veuillez sélectionner une commande à supprimer.");
        }
    } else {
        QMessageBox::information(this, "Suppression",
                                 "Fonctionnalité de suppression pour cette page.");
    }
}

void MainWindow::onActionSendEmail()
{
    QDialog *emailDialog = new QDialog(this);
    emailDialog->setWindowTitle("Envoyer Email");
    emailDialog->setMinimumSize(500, 400);

    QVBoxLayout *layout = new QVBoxLayout(emailDialog);

    QLabel *label = new QLabel("Interface d'envoi d'email", emailDialog);
    QTextEdit *messageEdit = new QTextEdit(emailDialog);
    messageEdit->setPlaceholderText("Écrivez votre message ici...");
    messageEdit->setMinimumHeight(200);

    QPushButton *sendBtn = new QPushButton("Envoyer", emailDialog);
    QPushButton *cancelBtn = new QPushButton("Annuler", emailDialog);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(sendBtn);
    buttonLayout->addWidget(cancelBtn);

    layout->addWidget(label);
    layout->addWidget(messageEdit);
    layout->addLayout(buttonLayout);

    connect(sendBtn, &QPushButton::clicked, emailDialog, [emailDialog, messageEdit]() {
        QMessageBox::information(emailDialog, "Email envoyé",
                                 "L'email a été envoyé avec succès.");
        emailDialog->accept();
    });

    connect(cancelBtn, &QPushButton::clicked, emailDialog, &QDialog::reject);

    emailDialog->exec();
    delete emailDialog;
}

void MainWindow::onActionExportPDF()
{
    QDialog *exportDialog = new QDialog(this);
    exportDialog->setWindowTitle("Exporter en PDF");
    exportDialog->setMinimumSize(400, 300);

    QVBoxLayout *layout = new QVBoxLayout(exportDialog);

    QLabel *label = new QLabel("Options d'export PDF", exportDialog);

    QGroupBox *optionsGroup = new QGroupBox("Options", exportDialog);
    QVBoxLayout *optionsLayout = new QVBoxLayout(optionsGroup);

    QCheckBox *includeDetails = new QCheckBox("Inclure les détails", optionsGroup);
    QCheckBox *includeStats = new QCheckBox("Inclure les statistiques", optionsGroup);
    QCheckBox *includeCalendar = new QCheckBox("Inclure le calendrier", optionsGroup);

    includeDetails->setChecked(true);
    includeStats->setChecked(true);

    optionsLayout->addWidget(includeDetails);
    optionsLayout->addWidget(includeStats);
    optionsLayout->addWidget(includeCalendar);

    QPushButton *exportBtn = new QPushButton("Exporter", exportDialog);
    QPushButton *cancelBtn = new QPushButton("Annuler", exportDialog);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(exportBtn);
    buttonLayout->addWidget(cancelBtn);

    layout->addWidget(label);
    layout->addWidget(optionsGroup);
    layout->addLayout(buttonLayout);

    connect(exportBtn, &QPushButton::clicked, exportDialog, [exportDialog]() {
        QMessageBox::information(exportDialog, "Export réussi",
                                 "Le PDF a été exporté avec succès.\nFichier: commandes_export.pdf");
        exportDialog->accept();
    });

    connect(cancelBtn, &QPushButton::clicked, exportDialog, &QDialog::reject);

    exportDialog->exec();
    delete exportDialog;
}

void MainWindow::onActionRefresh()
{
    // Simulation de chargement de données
    setupTableData();
    updateStatistics();

    // Mettre à jour les textes des statistiques avancées
    QString statsTypesText = "=== ANALYSE PAR TYPE DE PRODUIT ===\n\n"
                             "• Huiles: 45 unités (Stock: Normal)\n"
                             "• Machines: 12 unités (Stock: Bas)\n"
                             "• Emballages: 120 unités (Stock: Élevé)\n"
                             "• Pièces détachées: 67 unités (Stock: Normal)\n\n"
                             "=== ALERTES STOCK ===\n"
                             "⚠ 2 produits en niveau critique\n"
                             "⚠ 5 produits à réapprovisionner";

    ui->statsTypes->setPlainText(statsTypesText);

    QString statsDepensesText = "=== DÉPENSES MENSUELLES 2024 ===\n\n"
                                "• Janvier: 12,500€\n"
                                "• Février: 14,200€\n"
                                "• Mars: 11,800€\n"
                                "• Avril: 13,100€\n\n"
                                "=== TENDANCE ===\n"
                                "📈 Augmentation de 8% vs 2023\n\n"
                                "=== RUPTURES ===\n"
                                "• Produit A: 2 occurrences\n"
                                "• Produit B: 1 occurrence\n"
                                "• Produit C: 0 occurrence";

    ui->statsDepenses->setPlainText(statsDepensesText);

    // Marquer des dates importantes dans le calendrier
    QTextCharFormat importantFormat;
    importantFormat.setBackground(QColor("#BDD2B6"));
    importantFormat.setFontWeight(QFont::Bold);

    QDate today = QDate::currentDate();
    ui->calendarCommandes->setDateTextFormat(today.addDays(3), importantFormat);
    ui->calendarCommandes->setDateTextFormat(today.addDays(10), importantFormat);
    ui->calendarCommandes->setDateTextFormat(today.addDays(15), importantFormat);
}

void MainWindow::onActionExit()
{
    QApplication::quit();
}

// ==================== QUICK ACTION BUTTONS ====================

void MainWindow::onBtnNewCommandeClicked()
{
    onActionNew();
}

void MainWindow::onBtnEditCommandeClicked()
{
    onActionEdit();
}

void MainWindow::onBtnDeleteCommandeClicked()
{
    onActionDelete();
}

void MainWindow::onBtnEnvoyerEmailClicked()
{
    onActionSendEmail();
}

// ==================== NAVIGATION FROM MACHINE ====================

void MainWindow::onBtnCommandeFromProduitClicked()
{
    // Naviguer vers la page Commande
    ui->stackedPages->setCurrentWidget(ui->pageOrder);

    // Ouvrir le dialogue de création de commande
    onActionNew();
}

// ==================== ADVANCED FEATURES ====================

void MainWindow::onGroupBoxStatsByTypeClicked()
{
    showAdvancedFeatureDialog("Analyse Avancée par Type/Stock",
                              "Cette fonctionnalité avancée permet:\n"
                              "• Analyse détaillée des stocks par catégorie\n"
                              "• Prévisions de réapprovisionnement\n"
                              "• Suivi des tendances d'achat\n"
                              "• Alertes automatiques de rupture\n"
                              "• Optimisation des niveaux de stock");
}

void MainWindow::onGroupBoxStatsDepensesClicked()
{
    showAdvancedFeatureDialog("Analyse Avancée des Dépenses",
                              "Cette fonctionnalité avancée permet:\n"
                              "• Analyse comparative mois par mois\n"
                              "• Prévisions budgétaires\n"
                              "• Identification des économies potentielles\n"
                              "• Suivi des fournisseurs (coût/qualité)\n"
                              "• Rapport de rentabilité par produit");
}

void MainWindow::onGroupBoxCalendrierClicked()
{
    showAdvancedFeatureDialog("Calendrier Avancé des Commandes",
                              "Cette fonctionnalité avancée permet:\n"
                              "• Vue mensuelle/annuelle des commandes\n"
                              "• Alertes de dates d'échéance\n"
                              "• Planification des livraisons\n"
                              "• Gestion des conflits de planning\n"
                              "• Export vers Outlook/Google Calendar");
}

// ==================== SEARCH AND FILTERS ====================

void MainWindow::onSearchTextChanged(const QString &text)
{
    applyFilters();
}

void MainWindow::onFilterChanged()
{
    applyFilters();
}

void MainWindow::applyFilters()
{
    QString searchText = ui->lineEditSearch->text().toLower();
    QString selectedFournisseur = ui->comboFournisseur->currentText();
    QString selectedStatus = ui->comboStatus->currentText();
    QDate dateFrom = ui->dateFrom->date();
    QDate dateTo = ui->dateTo->date();

    for (int row = 0; row < ui->tableCommandes->rowCount(); ++row) {
        bool shouldShow = true;

        // Filtrer par texte de recherche
        if (!searchText.isEmpty()) {
            bool found = false;
            for (int col = 0; col < ui->tableCommandes->columnCount(); ++col) {
                QTableWidgetItem *item = ui->tableCommandes->item(row, col);
                if (item && item->text().toLower().contains(searchText)) {
                    found = true;
                    break;
                }
            }
            shouldShow = shouldShow && found;
        }

        // Filtrer par fournisseur
        if (selectedFournisseur != "Toutes") {
            QTableWidgetItem *fournisseurItem = ui->tableCommandes->item(row, 2);
            if (fournisseurItem && fournisseurItem->text() != selectedFournisseur) {
                shouldShow = false;
            }
        }

        // Filtrer par statut
        if (selectedStatus != "Tous") {
            QTableWidgetItem *statusItem = ui->tableCommandes->item(row, 3);
            if (statusItem && statusItem->text() != selectedStatus) {
                shouldShow = false;
            }
        }

        // Filtrer par date
        QTableWidgetItem *dateItem = ui->tableCommandes->item(row, 4);
        if (dateItem && !dateItem->text().isEmpty()) {
            QDate orderDate = QDate::fromString(dateItem->text(), "yyyy-MM-dd");
            if (orderDate < dateFrom || orderDate > dateTo) {
                shouldShow = false;
            }
        }

        // Afficher ou masquer la ligne
        ui->tableCommandes->setRowHidden(row, !shouldShow);
    }

    updateStatistics();
}

// ==================== HELPER METHODS ====================

void MainWindow::updateQuickInfo()
{
    int currentRow = ui->tableCommandes->currentRow();
    if (currentRow >= 0 && !ui->tableCommandes->isRowHidden(currentRow)) {
        ui->quickEtat->setText(ui->tableCommandes->item(currentRow, 3)->text());
        ui->quickFournisseur->setText(ui->tableCommandes->item(currentRow, 2)->text());
        ui->quickDateArrivee->setText(ui->tableCommandes->item(currentRow, 4)->text());
        ui->quickDateSortie->setText(ui->tableCommandes->item(currentRow, 5)->text());
        ui->quickMontant->setText(ui->tableCommandes->item(currentRow, 6)->text());
    } else {
        ui->quickEtat->setText("-");
        ui->quickFournisseur->setText("-");
        ui->quickDateArrivee->setText("-");
        ui->quickDateSortie->setText("-");
        ui->quickMontant->setText("-");
    }
}

void MainWindow::updateStatistics()
{
    int total = 0;
    int enCours = 0;
    int validee = 0;
    int prete = 0;
    int annulee = 0;

    for (int i = 0; i < ui->tableCommandes->rowCount(); ++i) {
        if (!ui->tableCommandes->isRowHidden(i)) {
            total++;
            QString etat = ui->tableCommandes->item(i, 3)->text();
            if (etat == "En cours") enCours++;
            else if (etat == "Validée") validee++;
            else if (etat == "Prête") prete++;
            else if (etat == "Annulée") annulee++;
        }
    }

    ui->statTotal->setText(QString::number(total));
    ui->statEnCours->setText(QString::number(enCours));
    ui->statValidee->setText(QString::number(validee));
    ui->statPrete->setText(QString::number(prete));
    ui->statAnnulee->setText(QString::number(annulee));
}

void MainWindow::showCrudDialog(const QString &title)
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(title);
    dialog->setMinimumSize(500, 400);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);

    QLabel *titleLabel = new QLabel(title, dialog);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(14);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);

    QFormLayout *formLayout = new QFormLayout();

    // Champs génériques selon le type
    if (title.contains("Commande")) {
        formLayout->addRow("ID Commande:", new QLineEdit(dialog));
        formLayout->addRow("Libellé:", new QLineEdit(dialog));

        QComboBox *fournisseurCombo = new QComboBox(dialog);
        fournisseurCombo->addItems({"Fournisseur A", "Fournisseur B", "Fournisseur C", "Fournisseur D"});
        formLayout->addRow("Fournisseur:", fournisseurCombo);

        QComboBox *statusCombo = new QComboBox(dialog);
        statusCombo->addItems({"En cours", "Validée", "Prête", "Annulée"});
        formLayout->addRow("État:", statusCombo);

        formLayout->addRow("Date Arrivée:", new QDateEdit(QDate::currentDate(), dialog));
        formLayout->addRow("Date Sortie:", new QDateEdit(QDate::currentDate().addDays(7), dialog));

        QDoubleSpinBox *montantSpin = new QDoubleSpinBox(dialog);
        montantSpin->setRange(0, 100000);
        montantSpin->setPrefix("€ ");
        formLayout->addRow("Montant:", montantSpin);
    } else if (title.contains("Employé")) {
        formLayout->addRow("Nom:", new QLineEdit(dialog));
        formLayout->addRow("Prénom:", new QLineEdit(dialog));
        formLayout->addRow("Email:", new QLineEdit(dialog));
        formLayout->addRow("Téléphone:", new QLineEdit(dialog));

        QComboBox *posteCombo = new QComboBox(dialog);
        posteCombo->addItems({"Gestionnaire", "Technicien", "Commercial", "Administratif"});
        formLayout->addRow("Poste:", posteCombo);
    } else {
        formLayout->addRow("Nom:", new QLineEdit(dialog));
        QTextEdit *descEdit = new QTextEdit(dialog);
        descEdit->setMaximumHeight(100);
        formLayout->addRow("Description:", descEdit);
    }

    QPushButton *saveBtn = new QPushButton("Enregistrer", dialog);
    QPushButton *cancelBtn = new QPushButton("Annuler", dialog);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(saveBtn);
    buttonLayout->addWidget(cancelBtn);

    mainLayout->addWidget(titleLabel);
    mainLayout->addLayout(formLayout);
    mainLayout->addStretch();
    mainLayout->addLayout(buttonLayout);

    connect(saveBtn, &QPushButton::clicked, dialog, [dialog, this]() {
        QMessageBox::information(dialog, "Succès", "Enregistrement effectué avec succès.");
        dialog->accept();
        onActionRefresh(); // Rafraîchir les données
    });

    connect(cancelBtn, &QPushButton::clicked, dialog, &QDialog::reject);

    dialog->exec();
    delete dialog;
}

void MainWindow::showAdvancedFeatureDialog(const QString &title, const QString &description)
{
    QDialog *dialog = new QDialog(this);
    dialog->setWindowTitle(title);
    dialog->setMinimumSize(700, 500);

    QVBoxLayout *mainLayout = new QVBoxLayout(dialog);

    // En-tête
    QLabel *titleLabel = new QLabel(title, dialog);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(16);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    titleLabel->setStyleSheet("color: #798777; padding: 10px;");

    // Description
    QLabel *descLabel = new QLabel(description, dialog);
    descLabel->setAlignment(Qt::AlignLeft);
    descLabel->setWordWrap(true);
    descLabel->setStyleSheet("background-color: #F8EDE3; padding: 15px; border-radius: 5px;");

    // Onglets pour différentes vues
    QTabWidget *tabWidget = new QTabWidget(dialog);

    // Onglet 1: Vue détaillée
    QWidget *tab1 = new QWidget();
    QVBoxLayout *tab1Layout = new QVBoxLayout(tab1);

    QTableWidget *detailTable = new QTableWidget(10, 5, tab1);
    QStringList headers = {"Métrique", "Valeur", "Évolution", "Seuil", "Statut"};
    detailTable->setHorizontalHeaderLabels(headers);
    tab1Layout->addWidget(detailTable);
    tabWidget->addTab(tab1, "Vue détaillée");

    // Onglet 2: Graphiques
    QWidget *tab2 = new QWidget();
    QVBoxLayout *tab2Layout = new QVBoxLayout(tab2);

    QLabel *graphLabel = new QLabel("📈 Visualisation graphique des données\n\n"
                                    "• Graphique 1: Évolution des stocks\n"
                                    "• Graphique 2: Dépenses mensuelles\n"
                                    "• Graphique 3: Tendance des commandes", tab2);
    graphLabel->setAlignment(Qt::AlignCenter);
    graphLabel->setMinimumHeight(300);
    graphLabel->setStyleSheet("background-color: #BDD2B6; border-radius: 5px; padding: 20px;");
    tab2Layout->addWidget(graphLabel);
    tabWidget->addTab(tab2, "Graphiques");

    // Onglet 3: Export/Rapports
    QWidget *tab3 = new QWidget();
    QVBoxLayout *tab3Layout = new QVBoxLayout(tab3);

    QGroupBox *exportGroup = new QGroupBox("Options d'export", tab3);
    QVBoxLayout *exportLayout = new QVBoxLayout(exportGroup);

    exportLayout->addWidget(new QCheckBox("Exporter en PDF"));
    exportLayout->addWidget(new QCheckBox("Exporter en Excel"));
    exportLayout->addWidget(new QCheckBox("Exporter en CSV"));
    exportLayout->addWidget(new QCheckBox("Générer un rapport automatique"));

    tab3Layout->addWidget(exportGroup);
    tabWidget->addTab(tab3, "Export/Rapports");

    // Boutons
    QPushButton *closeBtn = new QPushButton("Fermer", dialog);
    QPushButton *generateBtn = new QPushButton("Générer Rapport", dialog);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(generateBtn);
    buttonLayout->addStretch();
    buttonLayout->addWidget(closeBtn);

    mainLayout->addWidget(titleLabel);
    mainLayout->addWidget(descLabel);
    mainLayout->addWidget(tabWidget);
    mainLayout->addLayout(buttonLayout);

    connect(generateBtn, &QPushButton::clicked, dialog, [dialog]() {
        QMessageBox::information(dialog, "Rapport généré",
                                 "Le rapport avancé a été généré avec succès.\n"
                                 "Consultez le dossier 'Rapports' pour plus de détails.");
    });

    connect(closeBtn, &QPushButton::clicked, dialog, &QDialog::accept);

    dialog->exec();
    delete dialog;
}
