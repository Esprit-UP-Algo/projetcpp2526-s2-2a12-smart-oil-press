#include "commande_widget.h"
#include "ui_commande_widget.h"
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
#include <QCalendarWidget>

CommandeWidget::CommandeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommandeWidget)
{
    ui->setupUi(this);

    // Créer les actions programmatiquement
    QAction *actionNew = new QAction("&Nouvelle Commande", this);
    actionNew->setObjectName("actionNew");
    actionNew->setShortcut(Qt::CTRL | Qt::Key_N);

    QAction *actionEdit = new QAction("&Modifier", this);
    actionEdit->setObjectName("actionEdit");
    actionEdit->setShortcut(Qt::CTRL | Qt::Key_E);

    QAction *actionDelete = new QAction("&Supprimer", this);
    actionDelete->setObjectName("actionDelete");
    actionDelete->setShortcut(Qt::Key_Delete);

    QAction *actionEnvoyerEmail = new QAction("&Envoyer Email", this);
    actionEnvoyerEmail->setObjectName("actionEnvoyerEmail");
    actionEnvoyerEmail->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_E);

    QAction *actionExportPDF = new QAction("&Exporter PDF", this);
    actionExportPDF->setObjectName("actionExportPDF");
    actionExportPDF->setShortcut(Qt::CTRL | Qt::Key_P);

    QAction *actionRefresh = new QAction("&Actualiser", this);
    actionRefresh->setObjectName("actionRefresh");
    actionRefresh->setShortcut(Qt::Key_F5);

    QAction *actionStatistics = new QAction("📊 Statistiques", this);
    actionStatistics->setObjectName("actionStatistics");
    actionStatistics->setShortcut(Qt::CTRL | Qt::Key_G);

    QAction *actionCalendar = new QAction("📅 Calendrier", this);
    actionCalendar->setObjectName("actionCalendar");
    actionCalendar->setShortcut(Qt::CTRL | Qt::Key_L);

    // Ajouter les actions à la toolbar (Statistiques, Calendrier, Export et Refresh)
    if (ui->toolBar) {
        ui->toolBar->addAction(actionStatistics);
        ui->toolBar->addAction(actionCalendar);
        ui->toolBar->addSeparator();
        ui->toolBar->addAction(actionExportPDF);
        ui->toolBar->addAction(actionRefresh);
    }

    // Stocker les pointeurs comme propriétés pour accès dans setupConnections
    setProperty("actionNew", QVariant::fromValue((QObject*)actionNew));
    setProperty("actionEdit", QVariant::fromValue((QObject*)actionEdit));
    setProperty("actionDelete", QVariant::fromValue((QObject*)actionDelete));
    setProperty("actionEnvoyerEmail", QVariant::fromValue((QObject*)actionEnvoyerEmail));
    setProperty("actionExportPDF", QVariant::fromValue((QObject*)actionExportPDF));
    setProperty("actionRefresh", QVariant::fromValue((QObject*)actionRefresh));
    setProperty("actionStatistics", QVariant::fromValue((QObject*)actionStatistics));
    setProperty("actionCalendar", QVariant::fromValue((QObject*)actionCalendar));

    // Connecter les actions aux slots
    connect(actionNew, &QAction::triggered, this, &CommandeWidget::onActionNew);
    connect(actionEdit, &QAction::triggered, this, &CommandeWidget::onActionEdit);
    connect(actionDelete, &QAction::triggered, this, &CommandeWidget::onActionDelete);
    connect(actionEnvoyerEmail, &QAction::triggered, this, &CommandeWidget::onActionSendEmail);
    connect(actionExportPDF, &QAction::triggered, this, &CommandeWidget::onActionExportPDF);
    connect(actionRefresh, &QAction::triggered, this, &CommandeWidget::onActionRefresh);
    connect(actionStatistics, &QAction::triggered, this, &CommandeWidget::onActionStatistics);
    connect(actionCalendar, &QAction::triggered, this, &CommandeWidget::onActionCalendar);

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
}

CommandeWidget::~CommandeWidget()
{
    delete ui;
}

void CommandeWidget::setupConnections()
{
    // Les actions ont déjà été connectées dans le constructeur
    
    // Connecter les boutons d'actions rapides
    connect(ui->btnNewCommande, &QPushButton::clicked, this, &CommandeWidget::onBtnNewCommandeClicked);
    connect(ui->btnEditCommande, &QPushButton::clicked, this, &CommandeWidget::onBtnEditCommandeClicked);
    connect(ui->btnDeleteCommande, &QPushButton::clicked, this, &CommandeWidget::onBtnDeleteCommandeClicked);
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &CommandeWidget::onBtnEnvoyerEmailClicked);

    // Connecter les fonctionnalités avancées
    // (Les groupBox de statistiques ont été supprimés - affichés maintenant dans la fenêtre Statistiques)

    // Connecter la sélection dans la table
    connect(ui->tableCommandes, &QTableWidget::itemSelectionChanged, this, &CommandeWidget::updateQuickInfo);

    // Connecter les filtres
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &CommandeWidget::onSearchTextChanged);
    connect(ui->comboFournisseur, &QComboBox::currentTextChanged, this, &CommandeWidget::onFilterChanged);
    connect(ui->comboStatus, &QComboBox::currentTextChanged, this, &CommandeWidget::onFilterChanged);
    connect(ui->dateFrom, &QDateEdit::dateChanged, this, &CommandeWidget::onFilterChanged);
    connect(ui->dateTo, &QDateEdit::dateChanged, this, &CommandeWidget::onFilterChanged);
}

void CommandeWidget::setupTableData()
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

// ==================== CRUD ACTIONS ====================

void CommandeWidget::onActionNew()
{
    showCrudDialog("Nouvelle Commande");
}

void CommandeWidget::onActionEdit()
{
    if (ui->tableCommandes->currentRow() >= 0) {
        showCrudDialog("Modifier Commande");
    } else {
        QMessageBox::warning(this, "Aucune sélection",
                             "Veuillez sélectionner une commande à modifier.");
    }
}

void CommandeWidget::onActionDelete()
{
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
}

void CommandeWidget::onActionSendEmail()
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

void CommandeWidget::onActionExportPDF()
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

void CommandeWidget::onActionRefresh()
{
    // Simulation de chargement de données
    setupTableData();
    updateStatistics();
}

void CommandeWidget::onActionStatistics()
{
    // Créer une fenêtre de dialogue pour afficher les statistiques
    QDialog *statsDialog = new QDialog(this);
    statsDialog->setWindowTitle("Statistiques");
    statsDialog->setMinimumSize(700, 600);

    QVBoxLayout *mainLayout = new QVBoxLayout(statsDialog);

    // Label titre
    QLabel *titleLabel = new QLabel("📊 Statistiques des Commandes", statsDialog);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(14);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    mainLayout->addWidget(titleLabel);

    // GroupBox 0: Statistiques Générales (depuis la première page)
    QGroupBox *groupBoxStats = new QGroupBox("Statistiques Générales", statsDialog);
    QGridLayout *gridLayoutStats = new QGridLayout(groupBoxStats);
    
    // Calculer les statistiques
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
    
    // Total Commandes
    QLabel *labelStatTotal = new QLabel("Total Commandes :", statsDialog);
    QLabel *statTotal = new QLabel(QString::number(total), statsDialog);
    gridLayoutStats->addWidget(labelStatTotal, 0, 0);
    gridLayoutStats->addWidget(statTotal, 0, 1);
    
    // En cours
    QLabel *labelStatEnCours = new QLabel("En cours :", statsDialog);
    QLabel *statEnCours = new QLabel(QString::number(enCours), statsDialog);
    gridLayoutStats->addWidget(labelStatEnCours, 0, 2);
    gridLayoutStats->addWidget(statEnCours, 0, 3);
    
    // Validées
    QLabel *labelStatValidee = new QLabel("Validées :", statsDialog);
    QLabel *statValidee = new QLabel(QString::number(validee), statsDialog);
    gridLayoutStats->addWidget(labelStatValidee, 1, 0);
    gridLayoutStats->addWidget(statValidee, 1, 1);
    
    // Prêtes
    QLabel *labelStatPrete = new QLabel("Prêtes :", statsDialog);
    QLabel *statPrete = new QLabel(QString::number(prete), statsDialog);
    gridLayoutStats->addWidget(labelStatPrete, 1, 2);
    gridLayoutStats->addWidget(statPrete, 1, 3);
    
    // Annulées
    QLabel *labelStatAnnulee = new QLabel("Annulées :", statsDialog);
    QLabel *statAnnulee = new QLabel(QString::number(annulee), statsDialog);
    gridLayoutStats->addWidget(labelStatAnnulee, 2, 0);
    gridLayoutStats->addWidget(statAnnulee, 2, 1);
    
    mainLayout->addWidget(groupBoxStats);

    // GroupBox 1: Produits par Type/Stock
    QGroupBox *groupBoxStatsByType = new QGroupBox("Produits par Type/Stock", statsDialog);
    QVBoxLayout *statsTypesLayout = new QVBoxLayout(groupBoxStatsByType);
    QTextEdit *statsTypesEdit = new QTextEdit(statsDialog);
    statsTypesEdit->setReadOnly(true);
    
    QString statsTypesText = "=== ANALYSE PAR TYPE DE PRODUIT ===\n\n"
                             "• Huiles: 45 unités (Stock: Normal)\n"
                             "• Machines: 12 unités (Stock: Bas)\n"
                             "• Emballages: 120 unités (Stock: Élevé)\n"
                             "• Pièces détachées: 67 unités (Stock: Normal)\n\n"
                             "=== ALERTES STOCK ===\n"
                             "⚠ 2 produits en niveau critique\n"
                             "⚠ 5 produits à réapprovisionner";
    statsTypesEdit->setPlainText(statsTypesText);
    statsTypesLayout->addWidget(statsTypesEdit);
    mainLayout->addWidget(groupBoxStatsByType);

    // GroupBox 2: Dépenses par Mois / Ruptures
    QGroupBox *groupBoxStatsDepenses = new QGroupBox("Dépenses par Mois / Ruptures", statsDialog);
    QVBoxLayout *statsDepensesLayout = new QVBoxLayout(groupBoxStatsDepenses);
    QTextEdit *statsDepensesEdit = new QTextEdit(statsDialog);
    statsDepensesEdit->setReadOnly(true);
    
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
    statsDepensesEdit->setPlainText(statsDepensesText);
    statsDepensesLayout->addWidget(statsDepensesEdit);
    mainLayout->addWidget(groupBoxStatsDepenses);

    // Bouton Fermer
    QPushButton *closeBtn = new QPushButton("Fermer", statsDialog);
    connect(closeBtn, &QPushButton::clicked, statsDialog, &QDialog::accept);
    mainLayout->addWidget(closeBtn);

    statsDialog->exec();
    delete statsDialog;
}

// ==================== QUICK ACTION BUTTONS ====================

void CommandeWidget::onBtnNewCommandeClicked()
{
    onActionNew();
}

void CommandeWidget::onBtnEditCommandeClicked()
{
    onActionEdit();
}

void CommandeWidget::onActionCalendar()
{
    // Créer une fenêtre de dialogue pour afficher le calendrier
    QDialog *calendarDialog = new QDialog(this);
    calendarDialog->setWindowTitle("Calendrier des Commandes");
    calendarDialog->setMinimumSize(500, 500);

    QVBoxLayout *mainLayout = new QVBoxLayout(calendarDialog);

    // Label titre
    QLabel *titleLabel = new QLabel("📅 Calendrier des Commandes", calendarDialog);
    titleLabel->setAlignment(Qt::AlignCenter);
    QFont titleFont = titleLabel->font();
    titleFont.setPointSize(14);
    titleFont.setBold(true);
    titleLabel->setFont(titleFont);
    mainLayout->addWidget(titleLabel);

    // Calendrier
    QCalendarWidget *calendar = new QCalendarWidget(calendarDialog);
    
    // Marquer des dates importantes
    QTextCharFormat importantFormat;
    importantFormat.setBackground(QColor("#BDD2B6"));
    importantFormat.setFontWeight(QFont::Bold);
    
    QDate today = QDate::currentDate();
    calendar->setDateTextFormat(today.addDays(3), importantFormat);
    calendar->setDateTextFormat(today.addDays(10), importantFormat);
    calendar->setDateTextFormat(today.addDays(15), importantFormat);
    
    mainLayout->addWidget(calendar);

    // Bouton Fermer
    QPushButton *closeBtn = new QPushButton("Fermer", calendarDialog);
    connect(closeBtn, &QPushButton::clicked, calendarDialog, &QDialog::accept);
    mainLayout->addWidget(closeBtn);

    calendarDialog->exec();
    delete calendarDialog;
}

void CommandeWidget::onBtnDeleteCommandeClicked()
{
    onActionDelete();
}

void CommandeWidget::onBtnEnvoyerEmailClicked()
{
    onActionSendEmail();
}

// ==================== SEARCH AND FILTERS ====================

void CommandeWidget::onSearchTextChanged(const QString &text)
{
    applyFilters();
}

void CommandeWidget::onFilterChanged()
{
    applyFilters();
}

void CommandeWidget::applyFilters()
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

void CommandeWidget::updateQuickInfo()
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

void CommandeWidget::updateStatistics()
{
    // Les statistiques sont maintenant affichées dans la fenêtre "Statistiques" au lieu de la première page
    // Cette fonction reste ici pour les futurs traitements si nécessaire
}

void CommandeWidget::showCrudDialog(const QString &title)
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

void CommandeWidget::showAdvancedFeatureDialog(const QString &title, const QString &description)
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
