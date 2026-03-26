#include "commande_widget.h"
#include "ui_commande_widget.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPushButton>
#include <QCheckBox>
#include <QDate>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QtCore/QOverload>

CommandeWidget::CommandeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CommandeWidget)
{
    ui->setupUi(this);
    setupConnections();
    updateStatistics();
    loadPriceByMonth();
    loadMostOrderedProducts();
}

CommandeWidget::~CommandeWidget()
{
    delete ui;
}

void CommandeWidget::setupConnections()
{
    // CRUD Buttons
    connect(ui->btnAjouter, &QPushButton::clicked, this, &CommandeWidget::onAjouterCommande);
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &CommandeWidget::onSupprimerCommande);
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &CommandeWidget::onModifierCommande);

    // Export buttons
    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &CommandeWidget::exportPDF);
    connect(ui->btnExportRapport, &QPushButton::clicked, this, &CommandeWidget::exportPDF);
    connect(ui->btnExportFiche, &QPushButton::clicked, this, &CommandeWidget::exportPDF);

    // Filter checkboxes
    connect(ui->checkFiltreTous, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreAttente, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreConfirmee, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreExpedie, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreLivree, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);

    // Search & Sort buttons
    connect(ui->btnAppliquerRecherche, &QPushButton::clicked, this, &CommandeWidget::onApplySearch);
    connect(ui->btnReinitialiserRecherche, &QPushButton::clicked, this, &CommandeWidget::onResetSearch);
    connect(ui->comboTriPar, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CommandeWidget::onApplySorting);

    // Calendar buttons
    connect(ui->btnAfficherCalendrier, &QPushButton::clicked, this, &CommandeWidget::onDisplayCalendar);

    // Email notifications
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &CommandeWidget::onSendEmailNotification);
    connect(ui->checkEmailAutomatic, &QCheckBox::toggled, this, &CommandeWidget::onEnableEmailNotification);
}

void CommandeWidget::onAjouterCommande()
{
    QString num = ui->lineNumCommande->text();
    QString client = ui->lineClient->text();

    if (!num.isEmpty() && !client.isEmpty()) {
        QMessageBox::information(this, "Succès", "Commande ajoutée!");
        updateStatistics();
        loadPriceByMonth();
        loadMostOrderedProducts();
    } else {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs!");
    }
}

void CommandeWidget::onSupprimerCommande()
{
    QString id = ui->lineIdSuppr->text();

    if (!id.isEmpty()) {
        QMessageBox::information(this, "Succès", "Commande supprimée!");
        ui->lineIdSuppr->clear();
        refreshTableCommandes();
        updateStatistics();
    } else {
        QMessageBox::warning(this, "Erreur", "ID invalide!");
    }
}

void CommandeWidget::onModifierCommande()
{
    QString id = ui->lineIdMod->text();

    if (!id.isEmpty()) {
        QMessageBox::information(this, "Succès", "Commande modifiée!");
        ui->lineIdMod->clear();
        refreshTableCommandes();
        updateStatistics();
    } else {
        QMessageBox::warning(this, "Erreur", "ID invalide!");
    }
}

void CommandeWidget::onSearchByDate()
{
    QDate dateDebut = ui->dateSearchDebut->date();
    QDate dateFin = ui->dateSearchFin->date();

    // Placeholder for date search implementation
}

void CommandeWidget::onSearchByFournisseur()
{
    QString fournisseur = ui->lineSearchFournisseur->text();

    // Placeholder for supplier search implementation
}

void CommandeWidget::onApplySearch()
{
    QDate dateDebut = ui->dateSearchDebut->date();
    QDate dateFin = ui->dateSearchFin->date();
    QString fournisseur = ui->lineSearchFournisseur->text();
    QString client = ui->lineSearchClient->text();

    // Clear the table
    ui->tableResultatsRecherche->setRowCount(0);

    // Placeholder: Load search results
    // In a real implementation, this would query the database with the given criteria
    QMessageBox::information(this, "Recherche", "Recherche appliquée!\nDate: " + dateDebut.toString() + " au " + dateFin.toString() + 
                                              "\nFournisseur: " + (fournisseur.isEmpty() ? "Toutes" : fournisseur) + 
                                              "\nClient: " + (client.isEmpty() ? "Tous" : client));
}

void CommandeWidget::onResetSearch()
{
    ui->dateSearchDebut->setDate(QDate::currentDate().addMonths(-1));
    ui->dateSearchFin->setDate(QDate::currentDate());
    ui->lineSearchFournisseur->clear();
    ui->lineSearchClient->clear();
    ui->tableResultatsRecherche->setRowCount(0);
}

void CommandeWidget::onApplySorting()
{
    int sortIndex = ui->comboTriPar->currentIndex();
    QString sortType;

    switch(sortIndex) {
        case 0: sortType = "Montant croissant"; break;
        case 1: sortType = "Montant décroissant"; break;
        case 2: sortType = "Date récente"; break;
        case 3: sortType = "Date ancien"; break;
        case 4: sortType = "Statut"; break;
        case 5: sortType = "Client"; break;
        default: sortType = "Inconnu";
    }

    // Placeholder: Apply sorting
}

void CommandeWidget::refreshTableCommandes()
{
    ui->tableCommandes->setRowCount(0);
}

void CommandeWidget::updateStatistics()
{
    ui->lineTotalCmd->setText("0");
    ui->lineEnAttenteCmd->setText("0");
    ui->lineRevenuTotal->setText("0.00 €");
    ui->lineMoyenneCmd->setText("0.00 €");
}

void CommandeWidget::loadPriceByMonth()
{
    ui->tablePrixParMois->setRowCount(0);
    
    // Placeholder: Load data from database
    // Structure: Mois | Montant Total | Nombre de commandes
}

void CommandeWidget::loadMostOrderedProducts()
{
    ui->tableProduitsMostCommandes->setRowCount(0);
    
    // Placeholder: Load data from database
    // Structure: Produit | Quantité Totale | Nombre de commandes | Revenue
}

void CommandeWidget::onDisplayCalendar()
{
    int month = ui->comboMoisCalendrier->currentIndex() + 1;
    int year = ui->spinAnneeCalendrier->value();
    
    QDate firstDay(year, month, 1);
    ui->calendarCommandes->setSelectedDate(firstDay);
    
    refreshCalendarAlerts();
}

void CommandeWidget::refreshCalendarAlerts()
{
    ui->listAlertes->clear();
    
    // Placeholder: Load alerts from database
    // Display orders with visual alerts based on status
    ui->listAlertes->addItem("Exemple: Commande #001 - En attente (🔴)");
    ui->listAlertes->addItem("Exemple: Commande #002 - Confirmée (🟠)");
    ui->listAlertes->addItem("Exemple: Commande #003 - Expédiée (🟡)");
}

void CommandeWidget::onSendEmailNotification()
{
    QString numCommande = ui->lineNumCommandeEmail->text();
    QString email = ui->lineEmailDestinataire->text();
    QString message = ui->textMessageEmail->toPlainText();

    if (numCommande.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs!");
        return;
    }

    // Placeholder: Send email notification
    QMessageBox::information(this, "Email", "Email envoyé à " + email + " pour la commande " + numCommande);

    // Add to history
    int rowCount = ui->tableHistoriqueEmails->rowCount();
    ui->tableHistoriqueEmails->insertRow(rowCount);
    
    ui->tableHistoriqueEmails->setItem(rowCount, 0, new QTableWidgetItem(numCommande));
    ui->tableHistoriqueEmails->setItem(rowCount, 1, new QTableWidgetItem(email));
    ui->tableHistoriqueEmails->setItem(rowCount, 2, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm")));
    ui->tableHistoriqueEmails->setItem(rowCount, 3, new QTableWidgetItem("Envoyé"));
}

void CommandeWidget::onEnableEmailNotification(bool enabled)
{
    if (enabled) {
        QMessageBox::information(this, "Notifications", "Notifications automatiques activées!");
    } else {
        QMessageBox::information(this, "Notifications", "Notifications automatiques désactivées!");
    }
}

void CommandeWidget::exportPDF()
{
    QMessageBox::information(this, "Export", "Export PDF - À implémenter");
}

void CommandeWidget::showMessage(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}
