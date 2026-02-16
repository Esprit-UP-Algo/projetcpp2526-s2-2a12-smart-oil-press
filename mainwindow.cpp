#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Charger le stylesheet
    loadStylesheet();

    // Configuration initiale
    ui->stackedMain->setCurrentWidget(ui->pageCommandes);
    ui->statusbar->showMessage("Prêt");

    // Connecter les boutons de navigation
    setupNavigation();

    // Connecter les fonctionnalités
    setupConnections();

    // Ajouter des données d'exemple dans le tableau
    ui->tableWidget_commandes->setRowCount(4);

    QStringList etats = {"En cours", "Validée", "Prête", "Annulée"};

    for (int i = 0; i < 4; i++) {
        ui->tableWidget_commandes->setItem(i, 0, new QTableWidgetItem(QString("CMD00%1").arg(i+1)));
        ui->tableWidget_commandes->setItem(i, 1, new QTableWidgetItem(QString("Commande test %1").arg(i+1)));
        ui->tableWidget_commandes->setItem(i, 2, new QTableWidgetItem(QString("Fournisseur %1").arg(char('A' + i))));
        ui->tableWidget_commandes->setItem(i, 3, new QTableWidgetItem(QString("01/0%1/2026").arg(i+2)));
        ui->tableWidget_commandes->setItem(i, 4, new QTableWidgetItem(QString("15/0%1/2026").arg(i+2)));
        ui->tableWidget_commandes->setItem(i, 5, new QTableWidgetItem(etats[i % 4]));
        ui->tableWidget_commandes->setItem(i, 6, new QTableWidgetItem(QString::number((i+1) * 10)));
        ui->tableWidget_commandes->setItem(i, 7, new QTableWidgetItem(QString("€ %1.00").arg((i+1) * 1250)));
    }

    ui->tableWidget_commandes->horizontalHeader()->setStretchLastSection(true);

    // Données d'exemple pour les tableaux de statistiques
    ui->tableWidget_depenses->setRowCount(3);
    ui->tableWidget_depenses->setItem(0, 0, new QTableWidgetItem("Janvier 2026"));
    ui->tableWidget_depenses->setItem(0, 1, new QTableWidgetItem("€ 12500.00"));
    ui->tableWidget_depenses->setItem(1, 0, new QTableWidgetItem("Février 2026"));
    ui->tableWidget_depenses->setItem(1, 1, new QTableWidgetItem("€ 15800.00"));
    ui->tableWidget_depenses->setItem(2, 0, new QTableWidgetItem("Mars 2026"));
    ui->tableWidget_depenses->setItem(2, 1, new QTableWidgetItem("€ 14200.00"));

    ui->tableWidget_top->setRowCount(3);
    ui->tableWidget_top->setItem(0, 0, new QTableWidgetItem("Huile d'olive"));
    ui->tableWidget_top->setItem(0, 1, new QTableWidgetItem("150"));
    ui->tableWidget_top->setItem(1, 0, new QTableWidgetItem("Huile de tournesol"));
    ui->tableWidget_top->setItem(1, 1, new QTableWidgetItem("120"));
    ui->tableWidget_top->setItem(2, 0, new QTableWidgetItem("Huile de colza"));
    ui->tableWidget_top->setItem(2, 1, new QTableWidgetItem("85"));

    // Données d'exemple pour la liste du calendrier
    ui->listWidget_commandes->addItem("CMD001 - Fournisseur A (En cours) - Prête le 20/02");
    ui->listWidget_commandes->addItem("CMD002 - Fournisseur B (Prête) - Prête aujourd'hui");
    ui->listWidget_commandes->addItem("CMD003 - Fournisseur C (Validée) - Prête le 25/02");

    // Valeurs par défaut pour la date du calendrier
    QDate today = QDate::currentDate();
    ui->calendarWidget->setSelectedDate(today);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadStylesheet()
{
    QString styleSheet = R"(
/* ============================================================================
   Smart Oil Press - QSS Stylesheet
   ============================================================================
   Palette:
   - Primary: #F8EDE3 (Beige clair)
   - Sections: #BDD2B6 (Vert pâle)
   - Interactive: #A2B29F (Vert moyen)
   - Sidebar: #798777 (Vert foncé)
   - Success: #6FA66F
   - Warning: #E6C36A
   - Error: #C97A7A
   - Info: #7DA3A1
   ============================================================================ */

/* ============================================================================
   GENERAL - QWidget
   ============================================================================ */
QWidget {
    background-color: #F8EDE3;
    color: #2C2C2C;
}

QMainWindow {
    background-color: #F8EDE3;
}

/* ============================================================================
   SIDEBAR / NAVIGATION
   ============================================================================ */
QFrame#navFrame {
    background-color: #798777;
    border: 1px solid #6B7B6B;
}

/* ============================================================================
   BUTTONS - GENERAL
   ============================================================================ */
QPushButton {
    background-color: #A2B29F;
    color: #FFFFFF;
    border: 1px solid #798777;
    border-radius: 4px;
    padding: 8px 16px;
    font-weight: bold;
    font-size: 11pt;
    min-height: 36px;
    outline: none;
}

QPushButton:hover {
    background-color: #BDD2B6;
    border: 1px solid #A2B29F;
}

QPushButton:pressed {
    background-color: #9FA59C;
    border: 1px solid #798777;
}

QPushButton:disabled {
    background-color: #D3D3D3;
    color: #808080;
    border: 1px solid #BEBEBE;
}

/* ============================================================================
   BUTTONS - SIDEBAR
   ============================================================================ */
QFrame#navFrame QPushButton {
    background-color: #798777;
    color: #FFFFFF;
    border: none;
    border-radius: 0px;
    padding: 12px 16px;
    font-size: 10pt;
    font-weight: bold;
    min-height: 48px;
    text-align: left;
    margin: 2px 0px;
}

QFrame#navFrame QPushButton:hover {
    background-color: #A2B29F;
    border-left: 4px solid #BDD2B6;
    padding-left: 12px;
}

QFrame#navFrame QPushButton:pressed {
    background-color: #BDD2B6;
    color: #798777;
    border-left: 4px solid #798777;
    padding-left: 12px;
}

/* ============================================================================
   BUTTONS - COLORED (Success, Error, Warning)
   ============================================================================ */
QPushButton#btnAjouter,
QPushButton#btnExportListe,
QPushButton#btnExportRapport,
QPushButton#btnExportFiche,
QPushButton#btnEnvoyerEmail {
    background-color: #6FA66F;
    border: 1px solid #5D945D;
}

QPushButton#btnAjouter:hover,
QPushButton#btnExportListe:hover,
QPushButton#btnExportRapport:hover,
QPushButton#btnExportFiche:hover,
QPushButton#btnEnvoyerEmail:hover {
    background-color: #7CB87C;
    border: 1px solid #6FA66F;
}

QPushButton#btnSupprimer,
QPushButton#btnReset {
    background-color: #C97A7A;
    border: 1px solid #B86B6B;
}

QPushButton#btnSupprimer:hover,
QPushButton#btnReset:hover {
    background-color: #E08989;
    border: 1px solid #C97A7A;
}

QPushButton#btnModifier,
QPushButton#btnCharger {
    background-color: #E6C36A;
    border: 1px solid #D9B55F;
}

QPushButton#btnModifier:hover,
QPushButton#btnCharger:hover {
    background-color: #F0D188;
    border: 1px solid #E6C36A;
}

/* ============================================================================
   FORMS - INPUT FIELDS
   ============================================================================ */
QLineEdit {
    background-color: #FFFFFF;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    border-radius: 4px;
    padding: 8px;
    font-size: 10pt;
    selection-background-color: #BDD2B6;
}

QLineEdit:focus {
    border: 2px solid #A2B29F;
    background-color: #FFFEF9;
}

QPlainTextEdit,
QTextEdit {
    background-color: #FFFFFF;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    border-radius: 4px;
    padding: 8px;
    font-size: 10pt;
    selection-background-color: #BDD2B6;
}

QPlainTextEdit:focus,
QTextEdit:focus {
    border: 2px solid #A2B29F;
    background-color: #FFFEF9;
}

/* ============================================================================
   FORMS - COMBOBOX
   ============================================================================ */
QComboBox {
    background-color: #FFFFFF;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    border-radius: 4px;
    padding: 6px 8px;
    padding-right: 4px;
    font-size: 10pt;
    min-height: 32px;
    min-width: 100px;
}

QComboBox:focus {
    border: 2px solid #A2B29F;
}

QComboBox::drop-down {
    border: 0px;
    border-left: 1px solid #D5D5D5;
    width: 32px;
    height: 28px;
    background-color: #A2B29F;
    margin-right: 2px;
}

QComboBox QAbstractItemView {
    background-color: #FFFFFF;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    selection-background-color: #BDD2B6;
    padding: 4px;
}

/* ============================================================================
   FORMS - SPINBOX / DOUBLESPINBOX / DATEEDIT
   ============================================================================ */
QSpinBox,
QDoubleSpinBox,
QDateEdit {
    background-color: #FFFFFF;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    border-radius: 4px;
    padding-left: 8px;
    padding-right: 4px;
    padding-top: 6px;
    padding-bottom: 6px;
    font-size: 10pt;
    min-height: 32px;
    min-width: 100px;
}

QSpinBox:focus,
QDoubleSpinBox:focus,
QDateEdit:focus {
    border: 2px solid #A2B29F;
}

QSpinBox::up-button,
QDoubleSpinBox::up-button,
QDateEdit::up-button,
QSpinBox::down-button,
QDoubleSpinBox::down-button,
QDateEdit::down-button {
    background-color: #BDD2B6;
    border: 1px solid #A2B29F;
    border-radius: 2px;
    width: 32px;
    height: 14px;
    padding: 0px;
    margin: 1px;
}

QSpinBox::up-button:hover,
QDoubleSpinBox::up-button:hover,
QDateEdit::up-button:hover,
QSpinBox::down-button:hover,
QDoubleSpinBox::down-button:hover,
QDateEdit::down-button:hover {
    background-color: #A2B29F;
}

/* ============================================================================
   LABELS
   ============================================================================ */
QLabel {
    color: #2C2C2C;
    font-size: 10pt;
    background-color: transparent;
}

QLabel#label {
    font-weight: bold;
    font-size: 12pt;
    color: #798777;
}

/* ============================================================================
   TABLES
   ============================================================================ */
QTableWidget {
    background-color: #FFFFFF;
    alternate-background-color: #F5F0EA;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    border-radius: 4px;
    gridline-color: #E8E0D5;
    font-size: 9pt;
}

QTableWidget::item {
    padding: 6px;
}

QTableWidget::item:selected {
    background-color: #BDD2B6;
    color: #2C2C2C;
}

QHeaderView::section {
    background-color: #A2B29F;
    color: #FFFFFF;
    padding: 8px;
    border: none;
    border-right: 1px solid #798777;
    font-weight: bold;
    font-size: 9pt;
    text-align: center;
}

QHeaderView::section:hover {
    background-color: #9FA59C;
}

/* ============================================================================
   GROUPBOX
   ============================================================================ */
QGroupBox {
    color: #798777;
    background-color: #FFFFFF;
    border: 1px solid #D5D5D5;
    border-radius: 6px;
    margin-top: 12px;
    padding-top: 12px;
    padding-left: 8px;
    padding-right: 8px;
    padding-bottom: 8px;
    font-weight: bold;
    font-size: 10pt;
}

QGroupBox::title {
    subcontrol-origin: margin;
    subcontrol-position: top left;
    margin-left: 10px;
    padding: 0px 4px 0px 4px;
    color: #798777;
}

/* Minimize sidebar groupboxes */
QFrame#sidebarListe QGroupBox {
    margin-top: 4px;
    padding-top: 6px;
    padding-left: 4px;
    padding-right: 4px;
    padding-bottom: 4px;
    font-size: 9pt;
}

QFrame#sidebarListe QGroupBox::title {
    margin-left: 4px;
    padding: 0px 2px 0px 2px;
    font-size: 8.5pt;
}

QFrame#sidebarListe QLabel {
    font-size: 8pt;
    margin: 2px 0px 0px 0px;
    padding: 2px 0px;
}

QFrame#sidebarListe QLineEdit {
    padding: 2px 4px;
    font-size: 8pt;
    height: 20px;
}

QFrame#sidebarListe QComboBox {
    padding: 2px 4px;
    font-size: 8pt;
    height: 20px;
}

QFrame#sidebarListe QRadioButton {
    font-size: 8pt;
    spacing: 2px;
    margin: 2px 0px;
    padding: 0px 2px;
}

/* ============================================================================
   TABS
   ============================================================================ */
QTabWidget::pane {
    border: 1px solid #D5D5D5;
    background-color: #FFFFFF;
    border-radius: 4px;
}

QTabBar::tab {
    background-color: #D5D5D5;
    color: #2C2C2C;
    padding: 8px 20px;
    border: 1px solid #D5D5D5;
    border-bottom: none;
    border-top-left-radius: 4px;
    border-top-right-radius: 4px;
    min-width: 100px;
    font-size: 10pt;
    font-weight: bold;
}

QTabBar::tab:hover {
    background-color: #BDD2B6;
    color: #2C2C2C;
}

QTabBar::tab:selected {
    background-color: #FFFFFF;
    color: #798777;
    border-bottom: 2px solid #A2B29F;
}

/* ============================================================================
   SCROLLBAR
   ============================================================================ */
QScrollBar:vertical {
    background-color: #F8EDE3;
    width: 14px;
    border: 0px;
    border-radius: 7px;
}

QScrollBar::handle:vertical {
    background-color: #A2B29F;
    border-radius: 7px;
    min-height: 20px;
}

QScrollBar::handle:vertical:hover {
    background-color: #BDD2B6;
}

QScrollBar:horizontal {
    background-color: #F8EDE3;
    height: 14px;
    border: 0px;
    border-radius: 7px;
}

QScrollBar::handle:horizontal {
    background-color: #A2B29F;
    border-radius: 7px;
    min-width: 20px;
}

QScrollBar::handle:horizontal:hover {
    background-color: #BDD2B6;
}

/* ============================================================================
   MENUBAR
   ============================================================================ */
QMenuBar {
    background-color: #798777;
    color: #FFFFFF;
    border-bottom: 1px solid #5F7B5F;
    spacing: 8px;
    padding: 4px;
}

QMenuBar::item:selected {
    background-color: #A2B29F;
    border-radius: 4px;
}

/* ============================================================================
   MENU
   ============================================================================ */
QMenu {
    background-color: #FFFFFF;
    color: #2C2C2C;
    border: 1px solid #D5D5D5;
    padding: 4px 0px;
    border-radius: 4px;
}

QMenu::item:selected {
    background-color: #BDD2B6;
    padding: 4px 16px;
}

/* ============================================================================
   STATUSBAR
   ============================================================================ */
QStatusBar {
    background-color: #798777;
    color: #FFFFFF;
    border-top: 1px solid #6B7B6B;
    padding: 4px;
    font-size: 9pt;
}

/* ============================================================================
   CHECKBOXES & RADIOBUTTONS
   ============================================================================ */
QCheckBox,
QRadioButton {
    color: #2C2C2C;
    spacing: 6px;
    font-size: 10pt;
    background-color: transparent;
}

QCheckBox::indicator,
QRadioButton::indicator {
    width: 18px;
    height: 18px;
    border-radius: 3px;
    border: 2px solid #A2B29F;
    background-color: #FFFFFF;
}

QCheckBox::indicator:hover,
QRadioButton::indicator:hover {
    border: 2px solid #BDD2B6;
    background-color: #FFFEF9;
}

QCheckBox::indicator:checked,
QRadioButton::indicator:checked {
    background-color: #A2B29F;
    border: 2px solid #798777;
}

QCheckBox::indicator:checked:hover,
QRadioButton::indicator:checked:hover {
    background-color: #BDD2B6;
}

QRadioButton::indicator {
    border-radius: 9px;
    width: 18px;
    height: 18px;
}

/* ============================================================================
   TOOLTIPS
   ============================================================================ */
QToolTip {
    background-color: #798777;
    color: #FFFFFF;
    border: 1px solid #A2B29F;
    border-radius: 4px;
    padding: 4px 8px;
    font-size: 9pt;
}

/* ============================================================================
   CALENDAR WIDGET
   ============================================================================ */
QCalendarWidget QWidget {
    background-color: #FFFFFF;
    color: #2C2C2C;
}

QCalendarWidget QToolButton {
    background-color: #A2B29F;
    color: #FFFFFF;
    border: none;
    border-radius: 4px;
    padding: 6px;
    font-weight: bold;
}

QCalendarWidget QToolButton:hover {
    background-color: #BDD2B6;
}

QCalendarWidget QMenu {
    background-color: #FFFFFF;
    border: 1px solid #D5D5D5;
}

QCalendarWidget QSpinBox {
    background-color: #FFFFFF;
    border: 1px solid #D5D5D5;
    border-radius: 4px;
    padding: 4px;
}

QCalendarWidget QTableView {
    border: 1px solid #D5D5D5;
    background-color: #FFFFFF;
    selection-background-color: #BDD2B6;
}

/* ============================================================================
   FIN - End of Stylesheet
   ============================================================================ */
)";

    qApp->setStyleSheet(styleSheet);
}

void MainWindow::setupNavigation()
{
    // Connecter les signaux des boutons aux slots
    connect(ui->btnCommande, &QPushButton::clicked, this, &MainWindow::on_btnCommande_clicked);
    connect(ui->btnEquipe, &QPushButton::clicked, this, &MainWindow::on_btnEquipe_clicked);
    connect(ui->btnClient, &QPushButton::clicked, this, &MainWindow::on_btnClient_clicked);
    connect(ui->btnLaboratoire, &QPushButton::clicked, this, &MainWindow::on_btnLaboratoire_clicked);
    connect(ui->btnFournisseur, &QPushButton::clicked, this, &MainWindow::on_btnFournisseur_clicked);
    connect(ui->btnMachine, &QPushButton::clicked, this, &MainWindow::on_btnMachine_clicked);
}

void MainWindow::setupConnections()
{
    // Boutons d'action
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::on_btnAjouter_clicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::on_btnSupprimer_clicked);
    connect(ui->btnCharger, &QPushButton::clicked, this, &MainWindow::on_btnCharger_clicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::on_btnModifier_clicked);
    connect(ui->btnExportListe, &QPushButton::clicked, this, &MainWindow::on_btnExportListe_clicked);
    connect(ui->btnExportRapport, &QPushButton::clicked, this, &MainWindow::on_btnExportRapport_clicked);
    connect(ui->btnExportFiche, &QPushButton::clicked, this, &MainWindow::on_btnExportFiche_clicked);
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &MainWindow::on_btnEnvoyerEmail_clicked);

    // Radio buttons pour le tri
    connect(ui->radioButton_dateArrivage, &QRadioButton::toggled, this, &MainWindow::on_radioButton_dateArrivage_toggled);
    connect(ui->radioButton_montant, &QRadioButton::toggled, this, &MainWindow::on_radioButton_montant_toggled);
    connect(ui->radioButton_quantite, &QRadioButton::toggled, this, &MainWindow::on_radioButton_quantite_toggled);
    connect(ui->radioButton_dateSortie, &QRadioButton::toggled, this, &MainWindow::on_radioButton_dateSortie_toggled);
    connect(ui->radioButton_croissant, &QRadioButton::toggled, this, &MainWindow::on_radioButton_croissant_toggled);
    connect(ui->radioButton_decroissant, &QRadioButton::toggled, this, &MainWindow::on_radioButton_decroissant_toggled);
}

void MainWindow::on_btnCommande_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageCommandes);
    ui->statusbar->showMessage("Page: Gestion des commandes");
}

void MainWindow::on_btnEquipe_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageEquipe);
    ui->statusbar->showMessage("Page: Gestion des équipes");
}

void MainWindow::on_btnClient_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageClient);
    ui->statusbar->showMessage("Page: Gestion des clients");
}

void MainWindow::on_btnLaboratoire_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageLaboratoire);
    ui->statusbar->showMessage("Page: Gestion du laboratoire");
}

void MainWindow::on_btnFournisseur_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageFournisseur);
    ui->statusbar->showMessage("Page: Gestion des fournisseurs");
}

void MainWindow::on_btnMachine_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageMachine);
    ui->statusbar->showMessage("Page: Gestion des machines");
}

void MainWindow::on_btnAjouter_clicked()
{
    QString libelle = ui->lineEdit_libelle->text();
    if (libelle.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un libellé");
        return;
    }

    QMessageBox::information(this, "Succès", "Commande ajoutée avec succès !");
    ui->statusbar->showMessage("Commande ajoutée");
}

void MainWindow::on_btnSupprimer_clicked()
{
    QString id = ui->lineEdit_id_supprimer->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID");
        return;
    }

    int reponse = QMessageBox::question(this, "Confirmation",
                                        "Voulez-vous vraiment supprimer la commande " + id + " ?");
    if (reponse == QMessageBox::Yes) {
        QMessageBox::information(this, "Succès", "Commande supprimée !");
        ui->statusbar->showMessage("Commande supprimée");
        ui->lineEdit_id_supprimer->clear();
    }
}

void MainWindow::on_btnCharger_clicked()
{
    QString id = ui->lineEdit_id_modifier->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID");
        return;
    }

    // Simulation de chargement
    ui->lineEdit_libelle_mod->setText("Commande chargée");
    ui->combo_fournisseur_mod->setCurrentIndex(1);
    ui->lineEdit_id_modifier->setReadOnly(true);

    QMessageBox::information(this, "Succès", "Données chargées pour la commande " + id);
}

void MainWindow::on_btnModifier_clicked()
{
    QString id = ui->lineEdit_id_modifier->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez charger une commande d'abord");
        return;
    }

    QMessageBox::information(this, "Succès", "Commande modifiée avec succès !");
    ui->statusbar->showMessage("Commande modifiée");
}

void MainWindow::on_btnExportListe_clicked()
{
    ui->textEdit_messages->append("📄 Export de la liste complète des commandes en PDF...");
    ui->textEdit_messages->append("✅ Export terminé avec succès !");
    ui->statusbar->showMessage("Export PDF: Liste complète");
}

void MainWindow::on_btnExportRapport_clicked()
{
    ui->textEdit_messages->append("📊 Export du rapport statistiques en PDF...");
    ui->textEdit_messages->append("✅ Rapport exporté avec succès !");
    ui->statusbar->showMessage("Export PDF: Rapport statistiques");
}

void MainWindow::on_btnExportFiche_clicked()
{
    QString id = ui->lineEdit_id_export->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir un ID de commande");
        return;
    }

    ui->textEdit_messages->append("📋 Export de la fiche commande " + id + " en PDF...");
    ui->textEdit_messages->append("✅ Fiche exportée avec succès !");
    ui->statusbar->showMessage("Export PDF: Fiche commande " + id);
}

void MainWindow::on_btnEnvoyerEmail_clicked()
{
    QString email = ui->lineEdit_email_client->text();
    QString id = ui->lineEdit_id_email->text();

    if (email.isEmpty() || id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez saisir l'email et l'ID de la commande");
        return;
    }

    if (!email.contains("@")) {
        QMessageBox::warning(this, "Erreur", "Email invalide");
        return;
    }

    ui->textEdit_messages->append("📧 Envoi d'email à " + email + " pour la commande " + id + "...");
    ui->textEdit_messages->append("✅ Email envoyé avec succès ! La commande " + id + " est prête.");
    ui->statusbar->showMessage("Email envoyé à " + email);

    QMessageBox::information(this, "Succès", "Email de notification envoyé au client !");
}

// Fonctions de tri
void MainWindow::trierTableau()
{
    int colonne = 0;
    Qt::SortOrder ordre = Qt::AscendingOrder;

    // Déterminer la colonne de tri
    if (ui->radioButton_dateArrivage->isChecked())
        colonne = 3; // Colonne date arrivage
    else if (ui->radioButton_montant->isChecked())
        colonne = 7; // Colonne montant
    else if (ui->radioButton_quantite->isChecked())
        colonne = 6; // Colonne quantité
    else if (ui->radioButton_dateSortie->isChecked())
        colonne = 4; // Colonne date sortie

    // Déterminer l'ordre
    if (ui->radioButton_decroissant->isChecked())
        ordre = Qt::DescendingOrder;

    ui->tableWidget_commandes->sortByColumn(colonne, ordre);

    QString message = "Table trié par " + ui->radioButton_dateArrivage->text() +
                      " (" + (ordre == Qt::AscendingOrder ? "Croissant" : "Décroissant") + ")";
    ui->statusbar->showMessage(message);
}

void MainWindow::on_radioButton_dateArrivage_toggled(bool checked)
{
    if (checked) trierTableau();
}

void MainWindow::on_radioButton_montant_toggled(bool checked)
{
    if (checked) trierTableau();
}

void MainWindow::on_radioButton_quantite_toggled(bool checked)
{
    if (checked) trierTableau();
}

void MainWindow::on_radioButton_dateSortie_toggled(bool checked)
{
    if (checked) trierTableau();
}

void MainWindow::on_radioButton_croissant_toggled(bool checked)
{
    if (checked) trierTableau();
}

void MainWindow::on_radioButton_decroissant_toggled(bool checked)
{
    if (checked) trierTableau();
}
