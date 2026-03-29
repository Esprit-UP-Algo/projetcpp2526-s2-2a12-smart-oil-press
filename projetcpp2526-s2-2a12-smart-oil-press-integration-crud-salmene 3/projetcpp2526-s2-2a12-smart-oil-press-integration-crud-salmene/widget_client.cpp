#include "widget_client.h"
#include "ui_widget_client.h"
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QHeaderView>
#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <QDateTime>
#include <QPageLayout>
#include <QMarginsF>
#include <QDebug>
#include <QPixmap>
#include <QApplication>

WidgetClient::WidgetClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetClient)
{
    ui->setupUi(this);

    setupTableClients();
    setupConnections();
    loadSampleData();
    setupExportTab();
}

WidgetClient::~WidgetClient()
{
    delete ui;
}

// ----------------------------
// Setup Methods
// ----------------------------

void WidgetClient::setupTableClients()
{
    ui->tableClients->setColumnCount(6);
    QStringList headers;
    headers << "ID" << "Nom" << "Type" << "Téléphone" << "Email" << "Statut";
    ui->tableClients->setHorizontalHeaderLabels(headers);
    
    ui->tableClients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableClients->horizontalHeader()->setStretchLastSection(true);
    ui->tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableClients->setAlternatingRowColors(true);
    ui->tableClients->setShowGrid(true);
    ui->tableClients->setVisible(true);
    
    ui->tableClients->verticalHeader()->setDefaultSectionSize(35);
    ui->tableClients->verticalHeader()->hide();
}

void WidgetClient::setupConnections()
{
    // Tab-based CRUD buttons
    connect(ui->btnConfirmerAjouter,  &QPushButton::clicked, this, &WidgetClient::onConfirmerAjouterClicked);
    connect(ui->btnAnnulerAjouter,    &QPushButton::clicked, this, [this]() {
        clearFormAjouter();
        ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    });
    connect(ui->btnConfirmerModifier, &QPushButton::clicked, this, &WidgetClient::onConfirmerModifierClicked);
    connect(ui->btnAnnulerModifier,   &QPushButton::clicked, this, [this]() {
        ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    });
    connect(ui->btnConfirmerSupprimer,&QPushButton::clicked, this, &WidgetClient::onConfirmerSupprimerClicked);
    connect(ui->btnAnnulerSupprimer,  &QPushButton::clicked, this, [this]() {
        ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    });

    // When Modifier tab is opened, pre-fill form from selection
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &WidgetClient::onTabChanged);

    // Filter
    connect(ui->btnAppliquerFiltre, &QPushButton::clicked, this, &WidgetClient::onAppliquerFiltreClicked);

    // Table selection
    connect(ui->tableClients, &QTableWidget::itemSelectionChanged, this, &WidgetClient::onTableClientSelectionChanged);

    // Export PDF tab - 3 buttons
    connect(ui->btnExportListeClients, &QPushButton::clicked, this, &WidgetClient::onExportListeClientsClicked);
    connect(ui->btnExportStatistiques, &QPushButton::clicked, this, &WidgetClient::onExportStatistiquesClicked);
    connect(ui->btnExportFicheClient,  &QPushButton::clicked, this, &WidgetClient::onExportFicheClientClicked);
}

void WidgetClient::loadSampleData()
{
    ui->tableClients->setRowCount(5);
    
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
    
    ui->tableClients->viewport()->update();
    ui->tableClients->show();
    
    ui->cmbType->addItems({"Tous", "Particulier", "Entreprise"});
    ui->cmbStatut->addItems({"Tous", "Actif", "Inactif", "En attente"});

    // Populate Ajouter tab combos
    ui->cmbAjouterType->addItems({"Particulier", "Entreprise"});
    ui->cmbAjouterStatut->addItems({"Actif", "Inactif", "En attente"});

    // Populate Modifier tab combos
    ui->cmbModifierType->addItems({"Particulier", "Entreprise"});
    ui->cmbModifierStatut->addItems({"Actif", "Inactif", "En attente"});
    
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
        "</div>"
        "</div>"
    );
}

// ----------------------------
// Client Management Slots
// ----------------------------

void WidgetClient::setupExportTab()
{
    // Nothing to pre-populate — buttons trigger directly
}

// Helper: build HTML for full client list PDF
static QString buildListeClientsHTML(QTableWidget *table)
{
    QString html;
    html += "<html><head><style>"
            "body { font-family: Arial, sans-serif; color: #2C2C2C; margin: 20px; }"
            "h1 { color: #3D4F3C; border-bottom: 3px solid #7A9E7E; padding-bottom: 8px; }"
            "table { border-collapse: collapse; width: 100%; margin-top: 10px; }"
            "th { background-color: #7A9E7E; color: white; padding: 10px 8px; text-align: left; }"
            "td { padding: 8px; border-bottom: 1px solid #E8E0D5; }"
            "tr:nth-child(even) { background-color: #F5F0EA; }"
            ".badge-actif { background-color: #6FA66F; color: white; padding: 2px 8px; border-radius: 10px; }"
            ".badge-inactif { background-color: #C97A7A; color: white; padding: 2px 8px; border-radius: 10px; }"
            ".badge-attente { background-color: #E6C36A; color: #3D3D3D; padding: 2px 8px; border-radius: 10px; }"
            ".footer { margin-top: 40px; font-size: 9pt; color: #888; border-top: 1px solid #D5D5D5; padding-top: 8px; }"
            "</style></head><body>";
    html += "<h1>&#128196; Liste Compl&#232;te des Clients &#8212; Smart Oil Press</h1>";
    html += "<p style='color:#888; font-size:9pt;'>G&#233;n&#233;r&#233; le : " +
            QDateTime::currentDateTime().toString("dd/MM/yyyy &#224; HH:mm") + "</p>";
    html += "<table><tr><th>ID</th><th>Nom</th><th>Type</th><th>T&#233;l&#233;phone</th><th>Email</th><th>Statut</th></tr>";
    int count = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->isRowHidden(i)) continue;
        count++;
        QString statut = table->item(i, 5)->text();
        QString badgeClass = (statut == "Actif") ? "badge-actif" :
                             (statut == "Inactif") ? "badge-inactif" : "badge-attente";
        html += "<tr>";
        for (int j = 0; j < 5; ++j)
            html += "<td>" + table->item(i, j)->text() + "</td>";
        html += "<td><span class='" + badgeClass + "'>" + statut + "</span></td></tr>";
    }
    html += "</table>";
    html += "<p style='font-size:9pt; color:#555;'>Total : <b>" + QString::number(count) + "</b> client(s)</p>";
    html += "<div class='footer'>Smart Oil Press &#8212; Rapport confidentiel &#8212; " +
            QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

// Helper: build HTML for statistics PDF
static QString buildStatistiquesHTML(QTableWidget *table)
{
    int actif = 0, inactif = 0, attente = 0, particulier = 0, entreprise = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->isRowHidden(i)) continue;
        QString s = table->item(i, 5)->text();
        QString t = table->item(i, 2)->text();
        if (s == "Actif") actif++;
        else if (s == "Inactif") inactif++;
        else attente++;
        if (t == "Particulier") particulier++;
        else entreprise++;
    }
    int total = actif + inactif + attente;

    QString html;
    html += "<html><head><style>"
            "body { font-family: Arial, sans-serif; color: #2C2C2C; margin: 20px; }"
            "h1 { color: #3D4F3C; border-bottom: 3px solid #7A9E7E; padding-bottom: 8px; }"
            "h2 { color: #5A7259; margin-top: 24px; }"
            "table { border-collapse: collapse; width: 60%; margin-top: 10px; }"
            "th { background-color: #7A9E7E; color: white; padding: 10px; text-align: left; }"
            "td { padding: 10px; border-bottom: 1px solid #E8E0D5; }"
            "tr:nth-child(even) { background-color: #F5F0EA; }"
            ".green { color: #6FA66F; font-weight: bold; }"
            ".red { color: #C97A7A; font-weight: bold; }"
            ".yellow { color: #D4A020; font-weight: bold; }"
            ".footer { margin-top: 40px; font-size: 9pt; color: #888; border-top: 1px solid #D5D5D5; padding-top: 8px; }"
            "</style></head><body>";
    html += "<h1>&#128202; Rapport Statistiques Clients &#8212; Smart Oil Press</h1>";
    html += "<p style='color:#888; font-size:9pt;'>G&#233;n&#233;r&#233; le : " +
            QDateTime::currentDateTime().toString("dd/MM/yyyy &#224; HH:mm") + "</p>";
    html += "<h2>Vue d'ensemble</h2>";
    html += "<table><tr><th>Indicateur</th><th>Valeur</th></tr>";
    html += "<tr><td>Total Clients</td><td><b>" + QString::number(total) + "</b></td></tr>";
    html += "<tr><td>Clients Actifs</td><td class='green'>" + QString::number(actif) + "</td></tr>";
    html += "<tr><td>Clients Inactifs</td><td class='red'>" + QString::number(inactif) + "</td></tr>";
    html += "<tr><td>En attente</td><td class='yellow'>" + QString::number(attente) + "</td></tr>";
    html += "</table>";
    html += "<h2>R&#233;partition par type</h2>";
    html += "<table><tr><th>Type</th><th>Nombre</th><th>Pourcentage</th></tr>";
    int pctP = total > 0 ? (particulier * 100 / total) : 0;
    int pctE = total > 0 ? (entreprise * 100 / total) : 0;
    html += "<tr><td>Particuliers</td><td>" + QString::number(particulier) + "</td><td>" + QString::number(pctP) + "%</td></tr>";
    html += "<tr><td>Entreprises</td><td>" + QString::number(entreprise) + "</td><td>" + QString::number(pctE) + "%</td></tr>";
    html += "</table>";
    html += "<div class='footer'>Smart Oil Press &#8212; Rapport confidentiel &#8212; " +
            QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

// Helper: build HTML for single client fiche
static QString buildFicheClientHTML(QTableWidget *table, const QString &clientId)
{
    QString html;
    html += "<html><head><style>"
            "body { font-family: Arial, sans-serif; color: #2C2C2C; margin: 20px; }"
            "h1 { color: #3D4F3C; border-bottom: 3px solid #7A9E7E; padding-bottom: 8px; }"
            "table { border-collapse: collapse; width: 80%; margin-top: 10px; }"
            "th { background-color: #7A9E7E; color: white; padding: 10px; text-align: left; width: 40%; }"
            "td { padding: 10px; border-bottom: 1px solid #E8E0D5; }"
            ".badge-actif { background-color: #6FA66F; color: white; padding: 3px 12px; border-radius: 10px; }"
            ".badge-inactif { background-color: #C97A7A; color: white; padding: 3px 12px; border-radius: 10px; }"
            ".badge-attente { background-color: #E6C36A; color: #3D3D3D; padding: 3px 12px; border-radius: 10px; }"
            ".footer { margin-top: 40px; font-size: 9pt; color: #888; border-top: 1px solid #D5D5D5; padding-top: 8px; }"
            "</style></head><body>";

    // Find client by ID
    int foundRow = -1;
    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->item(i, 0) && table->item(i, 0)->text() == clientId) {
            foundRow = i;
            break;
        }
    }

    if (foundRow == -1) {
        html += "<h1>Fiche Client &#8212; Smart Oil Press</h1>";
        html += "<p style='color:#C97A7A; font-weight:bold;'>&#10060; Aucun client trouv&#233; avec l'ID : " + clientId + "</p>";
    } else {
        QString nom    = table->item(foundRow, 1)->text();
        QString type   = table->item(foundRow, 2)->text();
        QString tel    = table->item(foundRow, 3)->text();
        QString email  = table->item(foundRow, 4)->text();
        QString statut = table->item(foundRow, 5)->text();
        QString badgeClass = (statut == "Actif") ? "badge-actif" :
                             (statut == "Inactif") ? "badge-inactif" : "badge-attente";

        html += "<h1>&#128203; Fiche Client &#8212; " + nom + "</h1>";
        html += "<p style='color:#888; font-size:9pt;'>G&#233;n&#233;r&#233; le : " +
                QDateTime::currentDateTime().toString("dd/MM/yyyy &#224; HH:mm") + "</p>";
        html += "<table>";
        html += "<tr><th>ID</th><td>" + clientId + "</td></tr>";
        html += "<tr><th>Nom</th><td><b>" + nom + "</b></td></tr>";
        html += "<tr><th>Type</th><td>" + type + "</td></tr>";
        html += "<tr><th>T&#233;l&#233;phone</th><td>" + tel + "</td></tr>";
        html += "<tr><th>Email</th><td>" + email + "</td></tr>";
        html += "<tr><th>Statut</th><td><span class='" + badgeClass + "'>" + statut + "</span></td></tr>";
        html += "</table>";
    }
    html += "<div class='footer'>Smart Oil Press &#8212; Rapport confidentiel &#8212; " +
            QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static void savePDF(QWidget *parent, const QString &html, const QString &defaultName, QTextEdit *msgBox)
{
    QString fileName = QFileDialog::getSaveFileName(
        parent, "Enregistrer le PDF", defaultName, "PDF Files (*.pdf)"
    );
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    doc.setHtml(html);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15, 15, 15, 15), QPageLayout::Millimeter);
    doc.print(&printer);

    if (msgBox)
        msgBox->append("&#10003; PDF export&#233; avec succ&#232;s : " + fileName);

    QMessageBox::information(parent, "Succ&#232;s", "PDF export&#233; avec succ&#232;s !\n" + fileName);
}

void WidgetClient::onExportListeClientsClicked()
{
    savePDF(this, buildListeClientsHTML(ui->tableClients),
            "liste_clients.pdf", ui->textEdit_export_messages);
}

void WidgetClient::onExportStatistiquesClicked()
{
    savePDF(this, buildStatistiquesHTML(ui->tableClients),
            "statistiques_clients.pdf", ui->textEdit_export_messages);
}

void WidgetClient::onExportFicheClientClicked()
{
    QString id = ui->lineEdit_id_export->text().trimmed();
    if (id.isEmpty()) {
        ui->textEdit_export_messages->append("&#9888; Veuillez saisir un ID client pour la fiche.");
        QMessageBox::warning(this, "ID manquant", "Veuillez saisir un ID client dans le champ 'Param&#232;tres d'export'.");
        return;
    }
    savePDF(this, buildFicheClientHTML(ui->tableClients, id),
            "fiche_client_" + id + ".pdf", ui->textEdit_export_messages);
}

void WidgetClient::onExporterPDFClicked() { onExportListeClientsClicked(); }

// ----------------------------
// Tab Change Handler
// ----------------------------

void WidgetClient::onTabChanged(int index)
{
    QWidget *tab = ui->tabWidget->widget(index);

    // When switching to Modifier tab, pre-fill from selected row
    if (tab == ui->tabModifier) {
        int row = ui->tableClients->currentRow();
        if (row != -1) {
            ui->txtModifierNom->setText(ui->tableClients->item(row, 1)->text());
            ui->cmbModifierType->setCurrentText(ui->tableClients->item(row, 2)->text());
            ui->txtModifierTel->setText(ui->tableClients->item(row, 3)->text());
            ui->txtModifierEmail->setText(ui->tableClients->item(row, 4)->text());
            ui->cmbModifierStatut->setCurrentText(ui->tableClients->item(row, 5)->text());
        } else {
            QMessageBox::information(this, "Information",
                "Veuillez d'abord sélectionner un client dans la liste.");
            ui->tabWidget->setCurrentWidget(ui->tabListeClients);
        }
    }

    // When switching to Supprimer tab, update displayed client
    if (tab == ui->tabSupprimer) {
        int row = ui->tableClients->currentRow();
        if (row != -1) {
            ui->lblSupprimerNom->setText(ui->tableClients->item(row, 1)->text());
            ui->lblSupprimerDetails->setText(
                "Type : " + ui->tableClients->item(row, 2)->text() +
                "   |   Statut : " + ui->tableClients->item(row, 5)->text() +
                "   |   Tél : " + ui->tableClients->item(row, 3)->text()
            );
        } else {
            QMessageBox::information(this, "Information",
                "Veuillez d'abord sélectionner un client dans la liste.");
            ui->tabWidget->setCurrentWidget(ui->tabListeClients);
        }
    }
}

// ----------------------------
// Tab CRUD Slots
// ----------------------------

void WidgetClient::onConfirmerAjouterClicked()
{
    if (ui->txtAjouterNom->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Champ obligatoire", "Le nom du client est obligatoire.");
        return;
    }

    int newId = ui->tableClients->rowCount() + 1;

    // --- Model layer: save to DB ---
    Client C(newId,
             ui->txtAjouterNom->text().trimmed(),
             ui->cmbAjouterType->currentText(),
             ui->txtAjouterTel->text().trimmed(),
             ui->txtAjouterEmail->text().trimmed(),
             ui->cmbAjouterStatut->currentText());
    C.ajouter(); // DB insert (errors handled silently for demo)

    // --- View layer: add row to table ---
    int newRow = ui->tableClients->rowCount();
    ui->tableClients->insertRow(newRow);
    QString newIdStr = QString::number(newId).rightJustified(3, '0');
    ui->tableClients->setItem(newRow, 0, new QTableWidgetItem(newIdStr));
    ui->tableClients->setItem(newRow, 1, new QTableWidgetItem(ui->txtAjouterNom->text().trimmed()));
    ui->tableClients->setItem(newRow, 2, new QTableWidgetItem(ui->cmbAjouterType->currentText()));
    ui->tableClients->setItem(newRow, 3, new QTableWidgetItem(ui->txtAjouterTel->text().trimmed()));
    ui->tableClients->setItem(newRow, 4, new QTableWidgetItem(ui->txtAjouterEmail->text().trimmed()));
    ui->tableClients->setItem(newRow, 5, new QTableWidgetItem(ui->cmbAjouterStatut->currentText()));

    QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
    clearFormAjouter();
    ui->tabWidget->setCurrentWidget(ui->tabListeClients);
}

void WidgetClient::onConfirmerModifierClicked()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Attention", "Aucun client sélectionné.");
        return;
    }
    if (ui->txtModifierNom->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Champ obligatoire", "Le nom du client est obligatoire.");
        return;
    }

    int id = ui->tableClients->item(row, 0)->text().toInt();

    // --- Model layer: save to DB ---
    Client C(id,
             ui->txtModifierNom->text().trimmed(),
             ui->cmbModifierType->currentText(),
             ui->txtModifierTel->text().trimmed(),
             ui->txtModifierEmail->text().trimmed(),
             ui->cmbModifierStatut->currentText());
    C.modifier();

    // --- View layer: update table row ---
    ui->tableClients->item(row, 1)->setText(ui->txtModifierNom->text().trimmed());
    ui->tableClients->item(row, 2)->setText(ui->cmbModifierType->currentText());
    ui->tableClients->item(row, 3)->setText(ui->txtModifierTel->text().trimmed());
    ui->tableClients->item(row, 4)->setText(ui->txtModifierEmail->text().trimmed());
    ui->tableClients->item(row, 5)->setText(ui->cmbModifierStatut->currentText());

    QMessageBox::information(this, "Succès", "Client modifié avec succès !");
    ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    updateClientInfo();
}

void WidgetClient::onConfirmerSupprimerClicked()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Attention", "Aucun client sélectionné.");
        return;
    }

    QString nom = ui->tableClients->item(row, 1)->text();
    int id = ui->tableClients->item(row, 0)->text().toInt();

    auto reply = QMessageBox::question(this, "Confirmation",
        "Êtes-vous sûr de vouloir supprimer le client \"" + nom + "\" ?\nCette action est irréversible.",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // --- Model layer: delete from DB ---
        Ctmp.supprimer(id);

        // --- View layer: remove from table ---
        ui->tableClients->removeRow(row);
        clearClientInfo();
        ui->lblSupprimerNom->setText("Aucun client sélectionné");
        ui->lblSupprimerDetails->setText("-");
        QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
        ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    }
}

void WidgetClient::clearFormAjouter()
{
    ui->txtAjouterNom->clear();
    ui->txtAjouterTel->clear();
    ui->txtAjouterEmail->clear();
    ui->cmbAjouterType->setCurrentIndex(0);
    ui->cmbAjouterStatut->setCurrentIndex(0);
}

// ----------------------------
// Filter Slot
// ----------------------------

void WidgetClient::onAppliquerFiltreClicked()
{
    QString nomRecherche = ui->txtRechercheNom->text().toLower();
    QString typeFiltre = ui->cmbType->currentText();
    QString statutFiltre = ui->cmbStatut->currentText();
    
    for (int i = 0; i < ui->tableClients->rowCount(); ++i) {
        bool visible = true;
        
        if (!nomRecherche.isEmpty()) {
            QString nom = ui->tableClients->item(i, 1)->text().toLower();
            if (!nom.contains(nomRecherche)) visible = false;
        }
        
        if (typeFiltre != "Tous") {
            QString type = ui->tableClients->item(i, 2)->text();
            if (type != typeFiltre) visible = false;
        }
        
        if (statutFiltre != "Tous") {
            QString statut = ui->tableClients->item(i, 5)->text();
            if (statut != statutFiltre) visible = false;
        }
        
        ui->tableClients->setRowHidden(i, !visible);
    }
}

// ----------------------------
// Table Selection Slot
// ----------------------------

void WidgetClient::onTableClientSelectionChanged()
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

void WidgetClient::updateClientInfo()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) return;
    
    QString statut = ui->tableClients->item(row, 5)->text();
    QString nom = ui->tableClients->item(row, 1)->text();
    
    ui->lblInfoStatut->setText("Statut : " + statut);
    
    if (statut == "Actif") {
        ui->lblInfoAlertes->setText("Alertes : ✅ Aucune");
    } else if (statut == "En attente") {
        ui->lblInfoAlertes->setText("Alertes : ⚠️ Validation requise");
    } else {
        ui->lblInfoAlertes->setText("Alertes : ❌ Client inactif");
    }
    
    if (statut == "Actif") {
        ui->lblRetardsNombre->setText("Nombre de retards : 2");
        ui->lblRetardsMoyen->setText("Retard moyen : 5 jours");
        ui->lblRetardsTotal->setText("<span style='color: #C97A7A;'>Montant en retard : 0 DT</span>");
    } else if (statut == "En attente") {
        ui->lblRetardsNombre->setText("Nombre de retards : 0");
        ui->lblRetardsMoyen->setText("Retard moyen : 0 jours");
        ui->lblRetardsTotal->setText("<span style='color: #6FA66F;'>Montant en retard : 0 DT</span>");
    } else {
        ui->lblRetardsNombre->setText("Nombre de retards : 5");
        ui->lblRetardsMoyen->setText("Retard moyen : 15 jours");
        ui->lblRetardsTotal->setText("<span style='color: #C97A7A; font-weight: bold;'>Montant en retard : 2,500 DT</span>");
    }
    
    if (nom.contains("Mohamed")) {
        ui->lblRetoursNombre->setText("Nombre de retours : 1");
        ui->lblRetoursTaux->setText("Taux de retour : <span style='color: #6FA66F;'>2.5%</span>");
        ui->lblRetoursDernier->setText("Dernier retour : 15/12/2025");
    } else if (nom.contains("Fatima")) {
        ui->lblRetoursNombre->setText("Nombre de retours : 0");
        ui->lblRetoursTaux->setText("Taux de retour : <span style='color: #6FA66F; font-weight: bold;'>0%</span>");
        ui->lblRetoursDernier->setText("Dernier retour : Aucun");
    } else {
        ui->lblRetoursNombre->setText("Nombre de retours : 3");
        ui->lblRetoursTaux->setText("Taux de retour : <span style='color: #E6C36A;'>8.5%</span>");
        ui->lblRetoursDernier->setText("Dernier retour : 02/02/2026");
    }
    
    if (ui->tableClients->item(row, 2)->text() == "Entreprise") {
        ui->lblPrixMoyen->setText("Prix moyen commande : 2,850 DT");
        ui->lblPrixTotal->setText("<span style='color: #6FA66F; font-weight: bold;'>CA total généré : 45,600 DT</span>");
        ui->lblPrixRemise->setText("Remise accordée : 15%");
    } else {
        ui->lblPrixMoyen->setText("Prix moyen commande : 750 DT");
        ui->lblPrixTotal->setText("<span style='color: #6FA66F; font-weight: bold;'>CA total généré : 12,300 DT</span>");
        ui->lblPrixRemise->setText("Remise accordée : 5%");
    }
    
    ui->lblClientDepuis->setText("Client depuis : 12/03/2023");
    
    if (ui->tableClients->item(row, 2)->text() == "Entreprise") {
        ui->lblNombreCommandes->setText("Nombre de commandes : 24");
        ui->lblDerniereCommande->setText("Dernière commande : 10/02/2026");
    } else {
        ui->lblNombreCommandes->setText("Nombre de commandes : 16");
        ui->lblDerniereCommande->setText("Dernière commande : 05/02/2026");
    }
}

void WidgetClient::clearClientInfo()
{
    ui->lblInfoStatut->setText("Statut : -");
    ui->lblInfoAlertes->setText("Alertes : -");
    ui->lblRetardsNombre->setText("Nombre de retards : -");
    ui->lblRetardsMoyen->setText("Retard moyen : - jours");
    ui->lblRetardsTotal->setText("Montant en retard : - DT");
    ui->lblRetoursNombre->setText("Nombre de retours : -");
    ui->lblRetoursTaux->setText("Taux de retour : - %");
    ui->lblRetoursDernier->setText("Dernier retour : -");
    ui->lblPrixMoyen->setText("Prix moyen commande : - DT");
    ui->lblPrixTotal->setText("CA total généré : - DT");
    ui->lblPrixRemise->setText("Remise accordée : - %");
    ui->lblClientDepuis->setText("Client depuis : -");
    ui->lblNombreCommandes->setText("Nombre de commandes : -");
    ui->lblDerniereCommande->setText("Dernière commande : -");
}

// ----------------------------
// DB Refresh Helper
// ----------------------------

void WidgetClient::refreshTableFromDB()
{
    QSqlQueryModel* model = Ctmp.afficher();
    ui->tableClients->setRowCount(0);
    for (int i = 0; i < model->rowCount(); ++i) {
        int row = ui->tableClients->rowCount();
        ui->tableClients->insertRow(row);
        for (int j = 0; j < model->columnCount() && j < 6; ++j) {
            ui->tableClients->setItem(row, j,
                new QTableWidgetItem(model->data(model->index(i, j)).toString()));
        }
    }
    delete model;
}
