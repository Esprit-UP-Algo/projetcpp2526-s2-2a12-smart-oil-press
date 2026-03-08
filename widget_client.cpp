#include "widget_client.h"
#include "ui_widget_client.h"
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
#include <QSqlError>
#include <QRegularExpression>

// ─── Constructor ──────────────────────────────────────────────────────────────
WidgetClient::WidgetClient(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetClient)
{
    ui->setupUi(this);
    setupLogo();
    setupTableClients();
    setupConnections();
    loadSampleData();   // populate combos only
    setupExportTab();
    refreshTableFromDB(); // load real data from Oracle
}

WidgetClient::~WidgetClient() { delete ui; }

// ─── Setup ────────────────────────────────────────────────────────────────────
void WidgetClient::setupLogo()
{
    // Logo is handled by mainwindow.ui (logoLabel) — nothing to do here
}

void WidgetClient::setupTableClients()
{
    ui->tableClients->setColumnCount(6);
    QStringList headers;
    headers << "ID" << "Nom" << "Type" << "Téléphone" << "Email" << "Statut";
    ui->tableClients->setHorizontalHeaderLabels(headers);
    ui->tableClients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableClients->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableClients->setAlternatingRowColors(true);
    ui->tableClients->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableClients->verticalHeader()->hide();
}

void WidgetClient::setupConnections()
{
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

    connect(ui->tabWidget,    &QTabWidget::currentChanged,       this, &WidgetClient::onTabChanged);
    connect(ui->btnAppliquerFiltre, &QPushButton::clicked,       this, &WidgetClient::onAppliquerFiltreClicked);
    connect(ui->tableClients, &QTableWidget::itemSelectionChanged, this, &WidgetClient::onTableClientSelectionChanged);
    // btnNavQuitter is in mainwindow.ui, not widget_client.ui

    connect(ui->btnExportListeClients,&QPushButton::clicked, this, &WidgetClient::onExportListeClientsClicked);
    connect(ui->btnExportStatistiques,&QPushButton::clicked, this, &WidgetClient::onExportStatistiquesClicked);
    connect(ui->btnExportFicheClient, &QPushButton::clicked, this, &WidgetClient::onExportFicheClientClicked);
}

void WidgetClient::loadSampleData()
{
    // ── Combos filtre ──
    ui->cmbType->addItems({"Tous", "beaute", "alimentaire"});
    ui->cmbStatut->addItems({"Tous", "actif", "blackliste"});

    // ── Combos Ajouter ──
    ui->cmbAjouterType->addItems({"beaute", "alimentaire"});
    ui->cmbAjouterStatut->addItems({"actif", "blackliste"});

    // ── Combos Modifier ──
    ui->cmbModifierType->addItems({"beaute", "alimentaire"});
    ui->cmbModifierStatut->addItems({"actif", "blackliste"});
}

void WidgetClient::setupExportTab() {}

// ─── REFRESH FROM DB ──────────────────────────────────────────────────────────
void WidgetClient::refreshTableFromDB()
{
    QSqlQueryModel* model = Ctmp.afficher();
    ui->tableClients->setRowCount(0);

    for (int i = 0; i < model->rowCount(); ++i) {
        int row = ui->tableClients->rowCount();
        ui->tableClients->insertRow(row);
        for (int j = 0; j < 6; ++j) {
            QString val = model->data(model->index(i, j)).toString();
            QTableWidgetItem* item = new QTableWidgetItem(val);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableClients->setItem(row, j, item);
        }
    }
    delete model;
    clearClientInfo();
}

// ─── TAB CHANGE ───────────────────────────────────────────────────────────────
void WidgetClient::onTabChanged(int index)
{
    QWidget *tab = ui->tabWidget->widget(index);

    if (tab == ui->tabModifier) {
        int row = ui->tableClients->currentRow();
        if (row == -1) {
            QMessageBox::information(this, "Information",
                "Veuillez d'abord sélectionner un client dans la liste.");
            ui->tabWidget->setCurrentWidget(ui->tabListeClients);
            return;
        }
        ui->txtModifierNom->setText(ui->tableClients->item(row, 1)->text());
        ui->cmbModifierType->setCurrentText(ui->tableClients->item(row, 2)->text());
        ui->txtModifierTel->setText(ui->tableClients->item(row, 3)->text());
        ui->txtModifierEmail->setText(ui->tableClients->item(row, 4)->text());
        ui->cmbModifierStatut->setCurrentText(ui->tableClients->item(row, 5)->text());
    }

    if (tab == ui->tabSupprimer) {
        int row = ui->tableClients->currentRow();
        if (row == -1) {
            QMessageBox::information(this, "Information",
                "Veuillez d'abord sélectionner un client dans la liste.");
            ui->tabWidget->setCurrentWidget(ui->tabListeClients);
            return;
        }
        ui->lblSupprimerNom->setText(ui->tableClients->item(row, 1)->text());
        ui->lblSupprimerDetails->setText(
            "Type : "   + ui->tableClients->item(row, 2)->text() +
            "   |   Statut : " + ui->tableClients->item(row, 5)->text() +
            "   |   Tél : "    + ui->tableClients->item(row, 3)->text()
        );
    }
}

// ─── AJOUTER ──────────────────────────────────────────────────────────────────
void WidgetClient::onConfirmerAjouterClicked()
{
    // ── Contrôle de saisie ──
    QString nom = ui->txtAjouterNom->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champ obligatoire", "Le nom du client est obligatoire.");
        ui->txtAjouterNom->setFocus();
        return;
    }
    if (nom.length() > 50) {
        QMessageBox::warning(this, "Saisie invalide", "Le nom ne peut pas dépasser 50 caractères.");
        return;
    }

    QString tel = ui->txtAjouterTel->text().trimmed();
    if (!tel.isEmpty()) {
        QRegularExpression rePhone("^[0-9 +\\-]{7,20}$");
        if (!rePhone.match(tel).hasMatch()) {
            QMessageBox::warning(this, "Téléphone invalide",
                "Le numéro de téléphone ne doit contenir que des chiffres (7–20 caractères).");
            ui->txtAjouterTel->setFocus();
            return;
        }
    }

    QString email = ui->txtAjouterEmail->text().trimmed();
    if (!email.isEmpty()) {
        QRegularExpression reMail("^[\\w._%+\\-]+@[\\w.\\-]+\\.[a-zA-Z]{2,}$");
        if (!reMail.match(email).hasMatch()) {
            QMessageBox::warning(this, "Email invalide",
                "L'adresse email n'est pas valide (ex: nom@domaine.com).");
            ui->txtAjouterEmail->setFocus();
            return;
        }
    }

    // ── Appel modèle ──
    Client C(0,
             nom,
             ui->cmbAjouterType->currentText(),
             tel,
             email,
             ui->cmbAjouterStatut->currentText());

    if (C.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        clearFormAjouter();
        refreshTableFromDB();
        ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    } else {
        QMessageBox::critical(this, "Erreur base de données",
            "Impossible d'ajouter le client.\nVérifiez la connexion Oracle.");
    }
}

// ─── MODIFIER ─────────────────────────────────────────────────────────────────
void WidgetClient::onConfirmerModifierClicked()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Attention", "Aucun client sélectionné.");
        return;
    }

    // ── Contrôle de saisie ──
    QString nom = ui->txtModifierNom->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Champ obligatoire", "Le nom du client est obligatoire.");
        ui->txtModifierNom->setFocus();
        return;
    }
    if (nom.length() > 50) {
        QMessageBox::warning(this, "Saisie invalide", "Le nom ne peut pas dépasser 50 caractères.");
        return;
    }

    QString tel = ui->txtModifierTel->text().trimmed();
    if (!tel.isEmpty()) {
        QRegularExpression rePhone("^[0-9 +\\-]{7,20}$");
        if (!rePhone.match(tel).hasMatch()) {
            QMessageBox::warning(this, "Téléphone invalide",
                "Le numéro de téléphone doit contenir 7–20 chiffres.");
            ui->txtModifierTel->setFocus();
            return;
        }
    }

    QString email = ui->txtModifierEmail->text().trimmed();
    if (!email.isEmpty()) {
        QRegularExpression reMail("^[\\w._%+\\-]+@[\\w.\\-]+\\.[a-zA-Z]{2,}$");
        if (!reMail.match(email).hasMatch()) {
            QMessageBox::warning(this, "Email invalide",
                "L'adresse email n'est pas valide.");
            ui->txtModifierEmail->setFocus();
            return;
        }
    }

    // ── Appel modèle ──
    int id = ui->tableClients->item(row, 0)->text().toInt();
    Client C(id,
             nom,
             ui->cmbModifierType->currentText(),
             tel,
             email,
             ui->cmbModifierStatut->currentText());

    if (C.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        refreshTableFromDB();
        ui->tabWidget->setCurrentWidget(ui->tabListeClients);
    } else {
        QMessageBox::critical(this, "Erreur base de données",
            "Impossible de modifier le client.\nVérifiez la connexion Oracle.");
    }
}

// ─── SUPPRIMER ────────────────────────────────────────────────────────────────
void WidgetClient::onConfirmerSupprimerClicked()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) {
        QMessageBox::warning(this, "Attention", "Aucun client sélectionné.");
        return;
    }

    QString nom = ui->tableClients->item(row, 1)->text();
    int     id  = ui->tableClients->item(row, 0)->text().toInt();

    auto reply = QMessageBox::question(this, "Confirmation",
        "Êtes-vous sûr de vouloir supprimer le client\n\"" + nom + "\" ?\n"
        "Cette action est irréversible.",
        QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (Ctmp.supprimer(id)) {
            QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
            refreshTableFromDB();
            ui->lblSupprimerNom->setText("Aucun client sélectionné");
            ui->lblSupprimerDetails->setText("-");
            ui->tabWidget->setCurrentWidget(ui->tabListeClients);
        } else {
            QMessageBox::critical(this, "Erreur base de données",
                "Impossible de supprimer le client.\n"
                "Il est peut-être référencé par des commandes existantes.");
        }
    }
}

// ─── FILTRE ───────────────────────────────────────────────────────────────────
void WidgetClient::onAppliquerFiltreClicked()
{
    QString nom    = ui->txtRechercheNom->text().trimmed();
    QString type   = ui->cmbType->currentText();
    QString statut = ui->cmbStatut->currentText();

    // Use the rechercher() method from the Model (SQL query, not loop)
    QSqlQueryModel* model = Ctmp.rechercher(nom, type, statut);
    ui->tableClients->setRowCount(0);

    for (int i = 0; i < model->rowCount(); ++i) {
        int row = ui->tableClients->rowCount();
        ui->tableClients->insertRow(row);
        for (int j = 0; j < 6; ++j) {
            QString val = model->data(model->index(i, j)).toString();
            QTableWidgetItem* item = new QTableWidgetItem(val);
            item->setFlags(item->flags() & ~Qt::ItemIsEditable);
            ui->tableClients->setItem(row, j, item);
        }
    }
    delete model;
}

// ─── SELECTION TABLE ──────────────────────────────────────────────────────────
void WidgetClient::onTableClientSelectionChanged()
{
    if (ui->tableClients->currentRow() != -1)
        updateClientInfo();
    else
        clearClientInfo();
}

// ─── QUITTER ──────────────────────────────────────────────────────────────────
void WidgetClient::onNavQuitterClicked()
{
    QApplication::quit();
}

// ─── HELPERS ──────────────────────────────────────────────────────────────────
void WidgetClient::clearFormAjouter()
{
    ui->txtAjouterNom->clear();
    ui->txtAjouterTel->clear();
    ui->txtAjouterEmail->clear();
    ui->cmbAjouterType->setCurrentIndex(0);
    ui->cmbAjouterStatut->setCurrentIndex(0);
}

void WidgetClient::updateClientInfo()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) return;

    QString statut = ui->tableClients->item(row, 5)->text();
    QString type   = ui->tableClients->item(row, 2)->text();

    ui->lblInfoStatut->setText("Statut : " + statut);
    ui->lblInfoAlertes->setText(statut == "actif" ? "Alertes : ✅ Aucune" : "Alertes : ⚠️ Client blacklisté");

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

// ─── PDF EXPORT HELPERS ───────────────────────────────────────────────────────
static QString buildListeClientsHTML(QTableWidget *table)
{
    QString html;
    html += "<html><head><style>"
            "body{font-family:Arial,sans-serif;color:#2C2C2C;margin:20px}"
            "h1{color:#3D4F3C;border-bottom:3px solid #7A9E7E;padding-bottom:8px}"
            "table{border-collapse:collapse;width:100%;margin-top:10px}"
            "th{background-color:#7A9E7E;color:white;padding:10px 8px;text-align:left}"
            "td{padding:8px;border-bottom:1px solid #E8E0D5}"
            "tr:nth-child(even){background-color:#F5F0EA}"
            ".actif{background:#6FA66F;color:white;padding:2px 8px;border-radius:10px}"
            ".blackliste{background:#C97A7A;color:white;padding:2px 8px;border-radius:10px}"
            ".footer{margin-top:40px;font-size:9pt;color:#888;border-top:1px solid #D5D5D5;padding-top:8px}"
            "</style></head><body>";
    html += "<h1>Liste des Clients &mdash; Smart Oil Press</h1>";
    html += "<p style='color:#888;font-size:9pt;'>G&eacute;n&eacute;r&eacute; le : "
            + QDateTime::currentDateTime().toString("dd/MM/yyyy &agrave; HH:mm") + "</p>";
    html += "<table><tr><th>ID</th><th>Nom</th><th>Type</th><th>T&eacute;l&eacute;phone</th><th>Email</th><th>Statut</th></tr>";
    int count = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->isRowHidden(i)) continue;
        count++;
        QString statut = table->item(i,5)->text();
        QString cls = (statut == "actif") ? "actif" : "blackliste";
        html += "<tr>";
        for (int j = 0; j < 5; ++j)
            html += "<td>" + table->item(i,j)->text() + "</td>";
        html += "<td><span class='" + cls + "'>" + statut + "</span></td></tr>";
    }
    html += "</table><p style='font-size:9pt;color:#555;'>Total : <b>"
            + QString::number(count) + "</b> client(s)</p>";
    html += "<div class='footer'>Smart Oil Press &mdash; Rapport confidentiel &mdash; "
            + QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static QString buildStatistiquesHTML(QTableWidget *table)
{
    int actif=0, blackliste=0, beaute=0, alimentaire=0;
    for (int i=0; i<table->rowCount(); ++i) {
        if (table->isRowHidden(i)) continue;
        QString s = table->item(i,5)->text();
        QString t = table->item(i,2)->text();
        if (s=="actif") actif++; else blackliste++;
        if (t=="beaute") beaute++; else alimentaire++;
    }
    int total = actif + blackliste;
    QString html;
    html += "<html><head><style>"
            "body{font-family:Arial,sans-serif;color:#2C2C2C;margin:20px}"
            "h1{color:#3D4F3C;border-bottom:3px solid #7A9E7E;padding-bottom:8px}"
            "h2{color:#5A7259;margin-top:24px}"
            "table{border-collapse:collapse;width:60%;margin-top:10px}"
            "th{background-color:#7A9E7E;color:white;padding:10px;text-align:left}"
            "td{padding:10px;border-bottom:1px solid #E8E0D5}"
            "tr:nth-child(even){background-color:#F5F0EA}"
            ".g{color:#6FA66F;font-weight:bold}.r{color:#C97A7A;font-weight:bold}"
            ".footer{margin-top:40px;font-size:9pt;color:#888;border-top:1px solid #D5D5D5;padding-top:8px}"
            "</style></head><body>";
    html += "<h1>Statistiques Clients &mdash; Smart Oil Press</h1>";
    html += "<p style='color:#888;font-size:9pt;'>G&eacute;n&eacute;r&eacute; le : "
            + QDateTime::currentDateTime().toString("dd/MM/yyyy &agrave; HH:mm") + "</p>";
    html += "<h2>Vue d'ensemble</h2><table>"
            "<tr><th>Indicateur</th><th>Valeur</th></tr>"
            "<tr><td>Total</td><td><b>" + QString::number(total) + "</b></td></tr>"
            "<tr><td>Actifs</td><td class='g'>" + QString::number(actif) + "</td></tr>"
            "<tr><td>Blacklist&eacute;s</td><td class='r'>" + QString::number(blackliste) + "</td></tr>"
            "</table>";
    html += "<h2>Par type</h2><table>"
            "<tr><th>Type</th><th>Nombre</th><th>%</th></tr>"
            "<tr><td>Beaut&eacute;</td><td>" + QString::number(beaute) + "</td><td>"
            + (total>0 ? QString::number(beaute*100/total) : "0") + "%</td></tr>"
            "<tr><td>Alimentaire</td><td>" + QString::number(alimentaire) + "</td><td>"
            + (total>0 ? QString::number(alimentaire*100/total) : "0") + "%</td></tr>"
            "</table>";
    html += "<div class='footer'>Smart Oil Press &mdash; "
            + QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static QString buildFicheClientHTML(QTableWidget *table, const QString &clientId)
{
    QString html;
    html += "<html><head><style>"
            "body{font-family:Arial,sans-serif;color:#2C2C2C;margin:20px}"
            "h1{color:#3D4F3C;border-bottom:3px solid #7A9E7E;padding-bottom:8px}"
            "table{border-collapse:collapse;width:80%;margin-top:10px}"
            "th{background-color:#7A9E7E;color:white;padding:10px;text-align:left;width:40%}"
            "td{padding:10px;border-bottom:1px solid #E8E0D5}"
            ".actif{background:#6FA66F;color:white;padding:3px 12px;border-radius:10px}"
            ".blackliste{background:#C97A7A;color:white;padding:3px 12px;border-radius:10px}"
            ".footer{margin-top:40px;font-size:9pt;color:#888;border-top:1px solid #D5D5D5;padding-top:8px}"
            "</style></head><body>";
    int foundRow = -1;
    for (int i=0; i<table->rowCount(); ++i)
        if (table->item(i,0) && table->item(i,0)->text() == clientId) { foundRow=i; break; }

    if (foundRow == -1) {
        html += "<h1>Fiche Client</h1><p style='color:#C97A7A;font-weight:bold;'>Client introuvable : " + clientId + "</p>";
    } else {
        QString nom    = table->item(foundRow,1)->text();
        QString type   = table->item(foundRow,2)->text();
        QString tel    = table->item(foundRow,3)->text();
        QString email  = table->item(foundRow,4)->text();
        QString statut = table->item(foundRow,5)->text();
        QString cls    = (statut=="actif") ? "actif" : "blackliste";
        html += "<h1>Fiche Client &mdash; " + nom + "</h1>"
                "<p style='color:#888;font-size:9pt;'>G&eacute;n&eacute;r&eacute; le : "
                + QDateTime::currentDateTime().toString("dd/MM/yyyy &agrave; HH:mm") + "</p>"
                "<table>"
                "<tr><th>ID</th><td>" + clientId + "</td></tr>"
                "<tr><th>Nom</th><td><b>" + nom + "</b></td></tr>"
                "<tr><th>Type</th><td>" + type + "</td></tr>"
                "<tr><th>T&eacute;l&eacute;phone</th><td>" + tel + "</td></tr>"
                "<tr><th>Email</th><td>" + email + "</td></tr>"
                "<tr><th>Statut</th><td><span class='" + cls + "'>" + statut + "</span></td></tr>"
                "</table>";
    }
    html += "<div class='footer'>Smart Oil Press &mdash; "
            + QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static void savePDF(QWidget *parent, const QString &html, const QString &defaultName, QTextEdit *msgBox)
{
    QString fileName = QFileDialog::getSaveFileName(
        parent, "Enregistrer le PDF", defaultName, "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;
    QTextDocument doc;
    doc.setHtml(html);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15,15,15,15), QPageLayout::Millimeter);
    doc.print(&printer);
    if (msgBox) msgBox->append("&#10003; PDF exporté : " + fileName);
    QMessageBox::information(parent, "Succès", "PDF exporté avec succès !\n" + fileName);
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
        QMessageBox::warning(this, "ID manquant", "Saisissez un ID client.");
        return;
    }
    savePDF(this, buildFicheClientHTML(ui->tableClients, id),
            "fiche_client_" + id + ".pdf", ui->textEdit_export_messages);
}
void WidgetClient::onExporterPDFClicked() { onExportListeClientsClicked(); }
