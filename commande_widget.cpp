#include "commande_widget.h"
#include "ui_commande_widget.h"
#include "Ccommande.h"
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QPushButton>
#include <QCheckBox>
#include <QDate>
#include <QDateEdit>
#include <QCalendarWidget>
#include <QtCore/QOverload>
#include <QDateTime>
#include <QDebug>
#include <algorithm>
#include <QPrinter>
#include <QTextDocument>
#include <QFileDialog>
#include <QTextTableFormat>
#include <QTextCursor>
#include <QTextBlockFormat>
#include <QTextCharFormat>
#include <QColor>
#include <QBrush>
#include <QDesktopServices>
#include <QUrl>
#include <QUrlQuery>
#include <QClipboard>
#include <QApplication>

CommandeWidget::CommandeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CommandeWidget)
{
    ui->setupUi(this);
    setupConnections();
    loadClients();
    refreshTableCommandes();
    updateStatistics();
    loadPriceByMonth();
    loadMostOrderedProducts();

    ui->dateSearchDebut->setDate(QDate::currentDate().addMonths(-1));
    ui->dateSearchFin->setDate(QDate::currentDate());
    ui->spinAnneeCalendrier->setValue(QDate::currentDate().year());

    applySortingAndDisplay(Ccommande::getAll());
}

CommandeWidget::~CommandeWidget()
{
    delete ui;
}

void CommandeWidget::setupConnections()
{
    connect(ui->btnAjouter, &QPushButton::clicked, this, &CommandeWidget::onAjouterCommande);
    connect(ui->btnResetAjouter, &QPushButton::clicked, this, &CommandeWidget::onResetAjouter);
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &CommandeWidget::onSupprimerCommande);
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &CommandeWidget::onModifierCommande);

    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &CommandeWidget::exportPDF);
    connect(ui->btnExportRapport, &QPushButton::clicked, this, &CommandeWidget::exportPDF);
    connect(ui->btnExportFiche, &QPushButton::clicked, this, &CommandeWidget::exportPDF);

    connect(ui->checkFiltreTous, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreAttente, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreConfirmee, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreExpedie, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);
    connect(ui->checkFiltreLivree, &QCheckBox::toggled, this, &CommandeWidget::refreshTableCommandes);

    connect(ui->btnAppliquerRecherche, &QPushButton::clicked, this, &CommandeWidget::onApplySearch);
    connect(ui->btnReinitialiserRecherche, &QPushButton::clicked, this, &CommandeWidget::onResetSearch);
    connect(ui->comboTriPar, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &CommandeWidget::onApplySorting);

    connect(ui->btnAfficherCalendrier, &QPushButton::clicked, this, &CommandeWidget::onDisplayCalendar);

    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &CommandeWidget::onSendEmailNotification);
    connect(ui->checkEmailAutomatic, &QCheckBox::toggled, this, &CommandeWidget::onEnableEmailNotification);
}

void CommandeWidget::loadClients()
{
    QVector<QPair<int, QString>> clients = Ccommande::getClientList();
    ui->comboClient->clear();
    ui->comboClient->addItem("Sélectionnez un client", 0);
    for (const auto &client : clients) {
        ui->comboClient->addItem(client.second, client.first);
    }
}

void CommandeWidget::onAjouterCommande()
{
    int id = ui->lineNumCommande->text().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Le numéro de commande doit être non nul !");
        return;
    }

    int idClient = ui->comboClient->currentData().toInt();
    if (idClient == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un client valide !");
        return;
    }

    if (!Ccommande::clientExists(idClient)) {
        QMessageBox::critical(this, "Client invalide",
                              QString("L'ID client %1 n'existe pas dans la table CLIENT.").arg(idClient));
        loadClients();
        return;
    }

    QString libelle = ui->comboLibelle->currentText();
    int quantite = ui->spinQuantite->value();
    double prixUnitaire = ui->spinPrix->value();
    double montantTotal = prixUnitaire * quantite;

    QString etat = ui->comboStatut->currentText().trimmed();
    qDebug() << "Valeur du combo statut (ajout):" << etat;
    QStringList etatsValides = {"en cours", "validee", "prete", "annulee"};
    if (!etatsValides.contains(etat)) {
        QMessageBox::warning(this, "Erreur", "Statut invalide.");
        return;
    }

    QDate dateArrivage = QDate::fromString(ui->lineDate->text(), "dd/MM/yyyy");
    if (!dateArrivage.isValid()) {
        dateArrivage = QDate::currentDate();
        ui->lineDate->setText(dateArrivage.toString("dd/MM/yyyy"));
    }
    QDate dateSortie = dateArrivage;

    Ccommande cmd(id, libelle, dateArrivage, dateSortie, etat, quantite, montantTotal, idClient);

    if (Ccommande::ajouter(cmd)) {
        QMessageBox::information(this, "Succès", "Commande sauvegardée !");
        refreshTableCommandes();
        updateStatistics();
        loadPriceByMonth();
        loadMostOrderedProducts();
        onResetAjouter();
        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur BD",
                              "Échec de l'ajout. Consultez la console pour le détail.");
    }
}
void CommandeWidget::onResetAjouter()
{
    ui->lineNumCommande->clear();
    ui->comboClient->setCurrentIndex(0);
    ui->comboLibelle->setCurrentIndex(0);
    ui->spinQuantite->setValue(0);
    ui->spinPrix->setValue(0.0);
    ui->comboStatut->setCurrentIndex(0);
    ui->lineDate->setText(QDate::currentDate().toString("dd/MM/yyyy"));
}

void CommandeWidget::onSupprimerCommande()
{
    QString idStr = ui->lineIdSuppr->text();
    if (idStr.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }
    int id = idStr.toInt();
    if (Ccommande::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Commande supprimée !");
        ui->lineIdSuppr->clear();
        refreshTableCommandes();
        updateStatistics();
        loadPriceByMonth();
        loadMostOrderedProducts();
        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void CommandeWidget::onModifierCommande()
{
    int id = ui->lineIdMod->text().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide !");
        return;
    }

    Ccommande oldCmd = Ccommande::getById(id);
    if (oldCmd.getIdCommande() == 0) {
        QMessageBox::warning(this, "Erreur", "Commande introuvable.");
        return;
    }

    int nouvelleQuantite = ui->spinQuantiteModif->value();
    if (nouvelleQuantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être supérieure à 0.");
        return;
    }

    QString nouvelEtat = ui->comboStatutModif->currentText().trimmed();
    qDebug() << "Valeur du combo statut (modification):" << nouvelEtat;
    QStringList etatsValides = {"en cours", "validee", "prete", "annulee"};
    if (!etatsValides.contains(nouvelEtat)) {
        QMessageBox::warning(this, "Erreur", "L'état sélectionné n'est pas valide.");
        return;
    }

    Ccommande newCmd = oldCmd;
    newCmd.setEtat(nouvelEtat);
    newCmd.setQuantite(nouvelleQuantite);

    if (Ccommande::modifier(id, newCmd)) {
        QMessageBox::information(this, "Succès", "Commande modifiée !");
        refreshTableCommandes();
        updateStatistics();
        loadPriceByMonth();
        loadMostOrderedProducts();
        ui->lineIdMod->clear();
        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec modification.");
    }
}

// ==============================
// RECHERCHE ET TRI
// ==============================

void CommandeWidget::onApplySearch()
{
    QDate debut = ui->dateSearchDebut->date();
    QDate fin = ui->dateSearchFin->date();

    QString texteClient = ui->lineSearchClient->text();
    int idClient = texteClient.toInt();
    QString nomClient = (idClient == 0) ? texteClient : QString();
    QString etat = "";


    m_searchActive = true;

    applySortingAndDisplay(m_lastSearchResults);

    QMessageBox::information(this, "Recherche",
                             QString("%1 résultat(s) trouvé(s).").arg(m_lastSearchResults.size()));
}

void CommandeWidget::onResetSearch()
{
    ui->dateSearchDebut->setDate(QDate::currentDate().addMonths(-1));
    ui->dateSearchFin->setDate(QDate::currentDate());

    ui->lineSearchClient->clear();

    m_searchActive = false;
    m_lastSearchResults.clear();

    applySortingAndDisplay(Ccommande::getAll());
}

void CommandeWidget::onApplySorting()
{
    if (m_searchActive) {
        applySortingAndDisplay(m_lastSearchResults);
    } else {
        applySortingAndDisplay(Ccommande::getAll());
    }
}

QVector<Ccommande> CommandeWidget::sortCommands(const QVector<Ccommande>& list, int sortIndex)
{
    QVector<Ccommande> sorted = list;
    switch (sortIndex) {
    case 0:
        std::sort(sorted.begin(), sorted.end(),
                  [](const Ccommande &a, const Ccommande &b) { return a.getMontantTotal() < b.getMontantTotal(); });
        break;
    case 1:
        std::sort(sorted.begin(), sorted.end(),
                  [](const Ccommande &a, const Ccommande &b) { return a.getMontantTotal() > b.getMontantTotal(); });
        break;
    case 2:
        std::sort(sorted.begin(), sorted.end(),
                  [](const Ccommande &a, const Ccommande &b) { return a.getDateArrivage() > b.getDateArrivage(); });
        break;
    case 3:
        std::sort(sorted.begin(), sorted.end(),
                  [](const Ccommande &a, const Ccommande &b) { return a.getDateArrivage() < b.getDateArrivage(); });
        break;
    case 4:
        std::sort(sorted.begin(), sorted.end(),
                  [](const Ccommande &a, const Ccommande &b) { return a.getEtat() < b.getEtat(); });
        break;
    case 5:
        std::sort(sorted.begin(), sorted.end(),
                  [](const Ccommande &a, const Ccommande &b) { return a.getIdClient() < b.getIdClient(); });
        break;
    default:
        break;
    }
    return sorted;
}

void CommandeWidget::applySortingAndDisplay(const QVector<Ccommande>& source)
{
    int sortIndex = ui->comboTriPar->currentIndex();
    QVector<Ccommande> sorted = sortCommands(source, sortIndex);

    ui->tableResultatsRecherche->setRowCount(sorted.size());

    for (int i = 0; i < sorted.size(); ++i) {
        const Ccommande &cmd = sorted[i];
        ui->tableResultatsRecherche->setItem(i, 0, new QTableWidgetItem(QString::number(cmd.getIdCommande())));
        ui->tableResultatsRecherche->setItem(i, 1, new QTableWidgetItem(QString::number(cmd.getIdClient())));
        ui->tableResultatsRecherche->setItem(i, 2, new QTableWidgetItem(cmd.getLibelle()));
        ui->tableResultatsRecherche->setItem(i, 3, new QTableWidgetItem(QString::number(cmd.getMontantTotal(), 'f', 2)));
        ui->tableResultatsRecherche->setItem(i, 4, new QTableWidgetItem(cmd.getDateArrivage().toString("dd/MM/yyyy")));
        ui->tableResultatsRecherche->setItem(i, 5, new QTableWidgetItem(cmd.getEtat()));
    }
}

// ==============================
// AUTRES FONCTIONS
// ==============================

void CommandeWidget::refreshTableCommandes()
{
    QVector<Ccommande> allList = Ccommande::getAll();

    bool filtreTous      = ui->checkFiltreTous->isChecked();
    bool filtreEnCours   = ui->checkFiltreAttente->isChecked();
    bool filtreValide    = ui->checkFiltreConfirmee->isChecked();
    bool filtrePrete     = ui->checkFiltreExpedie->isChecked();
    bool filtreLivree    = ui->checkFiltreLivree->isChecked();

    QVector<Ccommande> list;
    for (const Ccommande &cmd : allList) {
        if (filtreTous) {
            list.append(cmd);
        } else {
            const QString &e = cmd.getEtat();
            if ((filtreEnCours && e == "en cours") ||
                (filtreValide  && e == "validee")  ||
                (filtrePrete   && e == "prete")    ||
                (filtreLivree  && e == "livrée")) {
                list.append(cmd);
            }
        }
    }

    m_currentDisplayedOrders = list;
    ui->tableCommandes->setRowCount(list.size());

    for (int i = 0; i < list.size(); ++i) {
        const Ccommande &cmd = list[i];
        ui->tableCommandes->setItem(i, 0, new QTableWidgetItem(QString::number(cmd.getIdCommande())));
        ui->tableCommandes->setItem(i, 1, new QTableWidgetItem(QString::number(cmd.getIdClient())));
        ui->tableCommandes->setItem(i, 2, new QTableWidgetItem(cmd.getLibelle()));
        ui->tableCommandes->setItem(i, 3, new QTableWidgetItem(QString::number(cmd.getQuantite())));
        ui->tableCommandes->setItem(i, 4, new QTableWidgetItem(cmd.getEtat()));
        ui->tableCommandes->setItem(i, 5, new QTableWidgetItem(cmd.getDateArrivage().toString("dd/MM/yyyy")));
    }
}

void CommandeWidget::updateStatistics()
{
    ui->lineTotalCmd->setText(QString::number(Ccommande::getTotalCommandes()));
    ui->lineRevenuTotal->setText(QString::number(Ccommande::getMontantTotalGlobal(), 'f', 2));
    ui->lineMoyenneCmd->setText(QString::number(Ccommande::getMoyenneMontant(), 'f', 2));

    int enAttente = 0;
    for (const Ccommande &cmd : Ccommande::getAll()) {
        if (cmd.getEtat() == "en cours") enAttente++;
    }
    ui->lineEnAttenteCmd->setText(QString::number(enAttente));
}

void CommandeWidget::loadPriceByMonth()
{
    QMap<QString, double> montantParMois = Ccommande::getMontantParMois();
    QMap<QString, int> nbParMois = Ccommande::getNbCommandesParMois();

    ui->tablePrixParMois->setRowCount(montantParMois.size());

    int row = 0;
    for (auto it = montantParMois.begin(); it != montantParMois.end(); ++it) {
        QString mois = it.key();
        ui->tablePrixParMois->setItem(row, 0, new QTableWidgetItem(mois));
        ui->tablePrixParMois->setItem(row, 1, new QTableWidgetItem(QString::number(it.value(), 'f', 2)));
        ui->tablePrixParMois->setItem(row, 2, new QTableWidgetItem(QString::number(nbParMois.value(mois, 0))));
        ++row;
    }
}

void CommandeWidget::loadMostOrderedProducts()
{
    auto produitsQte = Ccommande::getProduitsPlusCommandes();
    auto produitsMontant = Ccommande::getProduitsPlusRentables();

    int maxSize = qMax(produitsQte.size(), produitsMontant.size());
    ui->tableProduitsMostCommandes->setRowCount(maxSize);

    for (int i = 0; i < maxSize; ++i) {
        if (i < produitsQte.size()) {
            ui->tableProduitsMostCommandes->setItem(i, 0, new QTableWidgetItem(produitsQte[i].first));
            ui->tableProduitsMostCommandes->setItem(i, 1, new QTableWidgetItem(QString::number(produitsQte[i].second)));
        } else {
            ui->tableProduitsMostCommandes->setItem(i, 0, new QTableWidgetItem(""));
            ui->tableProduitsMostCommandes->setItem(i, 1, new QTableWidgetItem(""));
        }

        if (i < produitsMontant.size()) {
            ui->tableProduitsMostCommandes->setItem(i, 3, new QTableWidgetItem(QString::number(produitsMontant[i].second, 'f', 2)));
        } else {
            ui->tableProduitsMostCommandes->setItem(i, 3, new QTableWidgetItem(""));
        }

        ui->tableProduitsMostCommandes->setItem(i, 2, new QTableWidgetItem("..."));
    }
}

void CommandeWidget::onDisplayCalendar()
{
    int month = ui->comboMoisCalendrier->currentIndex() + 1;
    int year = ui->spinAnneeCalendrier->value();
    QDate firstDay(year, month, 1);
    ui->calendarCommandes->setSelectedDate(firstDay);
    refreshCalendarAlerts();
    updateCalendarColors(month, year);
}

void CommandeWidget::refreshCalendarAlerts()
{
    ui->listAlertes->clear();

    int month = ui->comboMoisCalendrier->currentIndex() + 1;
    int year = ui->spinAnneeCalendrier->value();
    QDate debut(year, month, 1);
    QDate fin = debut.addMonths(1).addDays(-1);

    auto commandes = Ccommande::rechercher(debut, fin, "", 0);
    for (const Ccommande &cmd : commandes) {
        QString couleur;
        QString etat = cmd.getEtat().toLower();
        if (etat.contains("en cours")) couleur = "🔴";
        else if (etat.contains("validée") || etat.contains("validee")) couleur = "🟠";
        else if (etat.contains("prete") || etat.contains("prete")) couleur = "🟡";
        else if (etat.contains("annulée") || etat.contains("annulee")) couleur = "⚪";
        else couleur = "⚪";

        ui->listAlertes->addItem(QString("%1 Commande #%2 - %3 (%4)")
                                     .arg(couleur)
                                     .arg(cmd.getIdCommande())
                                     .arg(cmd.getLibelle())
                                     .arg(cmd.getDateArrivage().toString("dd/MM")));
    }
    updateCalendarColors(month, year);
}

void CommandeWidget::onSendEmailNotification()
{
    QString numCommande = ui->lineNumCommandeEmail->text().trimmed();
    QString email = ui->lineEmailDestinataire->text().trimmed();
    QString message = ui->textMessageEmail->toPlainText().trimmed();

    if (numCommande.isEmpty() || email.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
        return;
    }

    int id = numCommande.toInt();
    Ccommande cmd = Ccommande::getById(id);
    if (cmd.getIdCommande() == 0) {
        QMessageBox::warning(this, "Erreur", "Commande introuvable.");
        return;
    }

    QString subject = QString("Notification commande n°%1").arg(numCommande);
    QString body = QString("Bonjour,\n\nDétails de la commande n°%1 :\n").arg(numCommande);
    body += QString("Client : %1\n").arg(cmd.getIdClient());
    body += QString("Produit : %1\n").arg(cmd.getLibelle());
    body += QString("Quantité : %1\n").arg(cmd.getQuantite());
    body += QString("Montant : %1 €\n").arg(cmd.getMontantTotal());
    body += QString("Statut : %1\n").arg(cmd.getEtat());
    body += QString("Date : %1\n").arg(cmd.getDateArrivage().toString("dd/MM/yyyy"));
    body += QString("\nMessage : %1\n").arg(message);
    body += "\nCordialement,\nL'équipe Smart Oil Press";

    // Encoder les paramètres pour URL
    QString encodedSubject = QString::fromUtf8(QUrl::toPercentEncoding(subject));
    QString encodedBody = QString::fromUtf8(QUrl::toPercentEncoding(body));
    QString encodedEmail = QString::fromUtf8(QUrl::toPercentEncoding(email));

    // Demander à l'utilisateur quel service il utilise
    QMessageBox msgBox;
    msgBox.setWindowTitle("Choix du service mail");
    msgBox.setText("Quel service de messagerie utilisez-vous ?");
    
    QPushButton *btnGmail = msgBox.addButton("Gmail", QMessageBox::ActionRole);
    QPushButton *btnOutlook = msgBox.addButton("Outlook.com", QMessageBox::ActionRole);
    QPushButton *btnYahoo = msgBox.addButton("Yahoo Mail", QMessageBox::ActionRole);
    QPushButton *btnAutre = msgBox.addButton("Autre (lien copié)", QMessageBox::ActionRole);
    
    msgBox.exec();

    QUrl url;
    if (msgBox.clickedButton() == btnGmail) {
        // Gmail compose URL
        url = QUrl(QString("https://mail.google.com/mail/?view=cm&fs=1&to=%1&su=%2&body=%3")
                   .arg(email).arg(encodedSubject).arg(encodedBody));
    }
    else if (msgBox.clickedButton() == btnOutlook) {
        // Outlook.com compose URL
        url = QUrl(QString("https://outlook.live.com/mail/0/deeplink/compose?to=%1&subject=%2&body=%3")
                   .arg(email).arg(encodedSubject).arg(encodedBody));
    }
    else if (msgBox.clickedButton() == btnYahoo) {
        // Yahoo Mail compose URL
        url = QUrl(QString("https://compose.mail.yahoo.com/?to=%1&subject=%2&body=%3")
                   .arg(email).arg(encodedSubject).arg(encodedBody));
    }
    else {
        // Fallback : lien mailto copié
        QUrl mailto;
        mailto.setScheme("mailto");
        mailto.setPath(email);
        QUrlQuery query;
        query.addQueryItem("subject", subject);
        query.addQueryItem("body", body);
        mailto.setQuery(query);
        
        QString mailtoString = mailto.toString();
        QClipboard *clipboard = QApplication::clipboard();
        clipboard->setText(mailtoString);
        
        QMessageBox::information(this, "Lien copié", 
            "Le lien mailto a été copié dans le presse-papiers.\n"
            "Collez-le dans la barre d'adresse de votre navigateur.");
            
        // Ajout dans l'historique et sortie
        int rowCount = ui->tableHistoriqueEmails->rowCount();
        ui->tableHistoriqueEmails->insertRow(rowCount);
        ui->tableHistoriqueEmails->setItem(rowCount, 0, new QTableWidgetItem(numCommande));
        ui->tableHistoriqueEmails->setItem(rowCount, 1, new QTableWidgetItem(email));
        ui->tableHistoriqueEmails->setItem(rowCount, 2, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm")));
        ui->tableHistoriqueEmails->setItem(rowCount, 3, new QTableWidgetItem("Lien copié"));
        
        ui->lineNumCommandeEmail->clear();
        ui->lineEmailDestinataire->clear();
        ui->textMessageEmail->clear();
        return;
    }

    // Ouvrir l'URL dans le navigateur par défaut
    QDesktopServices::openUrl(url);

    // Ajout dans l'historique
    int rowCount = ui->tableHistoriqueEmails->rowCount();
    ui->tableHistoriqueEmails->insertRow(rowCount);
    ui->tableHistoriqueEmails->setItem(rowCount, 0, new QTableWidgetItem(numCommande));
    ui->tableHistoriqueEmails->setItem(rowCount, 1, new QTableWidgetItem(email));
    ui->tableHistoriqueEmails->setItem(rowCount, 2, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm")));
    ui->tableHistoriqueEmails->setItem(rowCount, 3, new QTableWidgetItem("Préparé"));

    ui->lineNumCommandeEmail->clear();
    ui->lineEmailDestinataire->clear();
    ui->textMessageEmail->clear();
}void CommandeWidget::onEnableEmailNotification(bool enabled)
{
    if (enabled) {
        QMessageBox::information(this, "Notifications", "Notifications automatiques activées!");
    } else {
        QMessageBox::information(this, "Notifications", "Notifications automatiques désactivées!");
    }
}
void CommandeWidget::exportPDF()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    QString buttonText = button->text();
    bool exportAll = ui->checkExportTous->isChecked();
    bool exportFiltered = ui->checkExportFiltre->isChecked();

    QVector<Ccommande> ordersToExport;
    if (exportAll) {
        ordersToExport = Ccommande::getAll();
    } else if (exportFiltered) {
        ordersToExport = m_currentDisplayedOrders;
    } else {
        ordersToExport = Ccommande::getAll();
    }

    QString html;
    if (buttonText == "Liste complète") {
        html = buildHtmlListeComplete(ordersToExport);
    } else if (buttonText == "Rapport") {
        html = buildHtmlRapport(ordersToExport);
    } else if (buttonText == "Fiche commande") {
        int currentRow = ui->tableCommandes->currentRow();
        if (currentRow < 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une commande dans la liste.");
            return;
        }
        int id = ui->tableCommandes->item(currentRow, 0)->text().toInt();
        Ccommande cmd = Ccommande::getById(id);
        if (cmd.getIdCommande() == 0) {
            QMessageBox::warning(this, "Erreur", "Commande introuvable.");
            return;
        }
        html = buildHtmlFicheCommande(cmd);
    } else {
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QDir::homePath(), "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;
    if (!fileName.endsWith(".pdf", Qt::CaseInsensitive)) fileName += ".pdf";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    if (buttonText == "Fiche commande") {
        printer.setPageOrientation(QPageLayout::Portrait);
    } else {
        printer.setPageOrientation(QPageLayout::Landscape);
    }

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::Point).size());
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "PDF généré avec succès : " + fileName);
}

void CommandeWidget::showMessage(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}

QString CommandeWidget::buildHtmlListeComplete(const QVector<Ccommande>& orders)
{
    QString html = "<html><head><style>"
                   "body { font-family: Arial, sans-serif; }"
                   "h1 { text-align: center; }"
                   "table { border-collapse: collapse; width: 100%; }"
                   "th, td { border: 1px solid black; padding: 5px; text-align: left; }"
                   "th { background-color: #f2f2f2; }"
                   "</style></head><body>";
    html += "<h1>Liste complète des commandes</h1>";
    html += "<table>";
    html += "<tr><th>ID</th><th>Client</th><th>Libellé</th><th>Quantité</th><th>Montant</th><th>Statut</th><th>Date arrivage</th></tr>";

    for (const Ccommande& cmd : orders) {
        html += "<tr>";
        html += "<td>" + QString::number(cmd.getIdCommande()) + "</td>";
        html += "<td>" + QString::number(cmd.getIdClient()) + "</td>";
        html += "<td>" + cmd.getLibelle() + "</td>";
        html += "<td>" + QString::number(cmd.getQuantite()) + "</td>";
        html += "<td>" + QString::number(cmd.getMontantTotal(), 'f', 2) + "</td>";
        html += "<td>" + cmd.getEtat() + "</td>";
        html += "<td>" + cmd.getDateArrivage().toString("dd/MM/yyyy") + "</td>";
        html += "</tr>";
    }
    html += "</table></body></html>";
    return html;
}

QString CommandeWidget::buildHtmlRapport(const QVector<Ccommande>& orders)
{
    int totalCommandes = orders.size();
    double montantTotal = 0;
    for (const Ccommande& cmd : orders) montantTotal += cmd.getMontantTotal();
    double moyenne = totalCommandes ? montantTotal / totalCommandes : 0;

    int enCours = 0, validee = 0, prete = 0, livree = 0, annulee = 0;
    for (const Ccommande& cmd : orders) {
        if (cmd.getEtat() == "en cours") enCours++;
        else if (cmd.getEtat() == "validee") validee++;
        else if (cmd.getEtat() == "prete") prete++;
        else if (cmd.getEtat() == "livree") livree++;
        else if (cmd.getEtat() == "annulee") annulee++;
    }

    QString html = "<html><head><style>"
                   "body { font-family: Arial, sans-serif; }"
                   "h1 { text-align: center; }"
                   ".stat { font-weight: bold; }"
                   "table { border-collapse: collapse; width: 100%; margin-top:20px; }"
                   "th, td { border: 1px solid black; padding: 5px; text-align: left; }"
                   "th { background-color: #f2f2f2; }"
                   "</style></head><body>";
    html += "<h1>Rapport des commandes</h1>";
    html += "<p><span class='stat'>Total commandes :</span> " + QString::number(totalCommandes) + "</p>";
    html += "<p><span class='stat'>Montant total :</span> " + QString::number(montantTotal, 'f', 2) + " €</p>";
    html += "<p><span class='stat'>Moyenne par commande :</span> " + QString::number(moyenne, 'f', 2) + " €</p>";
    html += "<h2>Répartition par statut</h2>";
    html += "<table>";
    html += "<tr><th>Statut</th><th>Nombre</th></tr>";
    html += "<tr><td>En cours</td><td>" + QString::number(enCours) + "</td></tr>";
    html += "<tr><td>Validée</td><td>" + QString::number(validee) + "</td></tr>";
    html += "<tr><td>Prête</td><td>" + QString::number(prete) + "</td></tr>";
    html += "<tr><td>Livrée</td><td>" + QString::number(livree) + "</td></tr>";
    html += "<tr><td>Annulée</td><td>" + QString::number(annulee) + "</td></tr>";
    html += "</table>";

    html += "<h2>Dernières commandes</h2>";
    html += "<table><tr><th>ID</th><th>Client</th><th>Libellé</th><th>Montant</th><th>Statut</th><th>Date</th></tr>";
    int count = 0;
    for (int i = orders.size() - 1; i >= 0 && count < 10; --i, ++count) {
        const Ccommande& cmd = orders[i];
        html += "<tr>";
        html += "<td>" + QString::number(cmd.getIdCommande()) + "</td>";
        html += "<td>" + QString::number(cmd.getIdClient()) + "</td>";
        html += "<td>" + cmd.getLibelle() + "</td>";
        html += "<td>" + QString::number(cmd.getMontantTotal(), 'f', 2) + "</td>";
        html += "<td>" + cmd.getEtat() + "</td>";
        html += "<td>" + cmd.getDateArrivage().toString("dd/MM/yyyy") + "</td>";
        html += "</tr>";
    }
    html += "</table></body></html>";
    return html;
}

QString CommandeWidget::buildHtmlFicheCommande(const Ccommande& cmd)
{
    QString html = "<html><head><style>"
                   "body { font-family: Arial, sans-serif; }"
                   "h1 { text-align: center; }"
                   ".field { font-weight: bold; }"
                   "table { border-collapse: collapse; width: 50%; margin: auto; }"
                   "td { border: 1px solid #ddd; padding: 8px; }"
                   ".label { background-color: #f2f2f2; }"
                   "</style></head><body>";
    html += "<h1>Fiche commande n° " + QString::number(cmd.getIdCommande()) + "</h1>";
    html += "<table>";
    html += "<tr><td class='label'>ID Commande</td><td>" + QString::number(cmd.getIdCommande()) + "</td></tr>";
    html += "<tr><td class='label'>Client</td><td>" + QString::number(cmd.getIdClient()) + "</td></tr>";
    html += "<tr><td class='label'>Libellé</td><td>" + cmd.getLibelle() + "</td></tr>";
    html += "<tr><td class='label'>Quantité</td><td>" + QString::number(cmd.getQuantite()) + "</td></tr>";
    html += "<tr><td class='label'>Montant total</td><td>" + QString::number(cmd.getMontantTotal(), 'f', 2) + " €</td></tr>";
    html += "<tr><td class='label'>Statut</td><td>" + cmd.getEtat() + "</td></tr>";
    html += "<tr><td class='label'>Date arrivage</td><td>" + cmd.getDateArrivage().toString("dd/MM/yyyy") + "</td></tr>";
    html += "<tr><td class='label'>Date sortie</td><td>" + cmd.getDateSortie().toString("dd/MM/yyyy") + "</td></tr>";
    html += "</table></body></html>";
    return html;
}

void CommandeWidget::updateCalendarColors(int month, int year)
{
    ui->calendarCommandes->setDateTextFormat(QDate(), QTextCharFormat());

    QDate firstDay(year, month, 1);
    QDate lastDay = firstDay.addMonths(1).addDays(-1);

    auto commandes = Ccommande::rechercher(firstDay, lastDay, "", 0, QString(), QString());

    QMap<QDate, QString> bestEtat;
    QMap<QDate, int> bestPriority;

    for (const Ccommande &cmd : commandes) {
        QDate date = cmd.getDateArrivage();
        QString etat = cmd.getEtat();
        int priority = getPriorityForEtat(etat);

        if (!bestPriority.contains(date) || priority > bestPriority[date]) {
            bestPriority[date] = priority;
            bestEtat[date] = etat;
        }
    }

    for (auto it = bestEtat.begin(); it != bestEtat.end(); ++it) {
        QTextCharFormat format;
        format.setBackground(QBrush(getColorForEtat(it.value())));
        ui->calendarCommandes->setDateTextFormat(it.key(), format);
    }
}

QColor CommandeWidget::getColorForEtat(const QString &etat) const
{
    QString e = etat.toLower();


    if (e == "en cours") return QColor(255, 99, 71);
    if (e == "validee")  return QColor(255, 165, 0);
    if (e == "prete")    return QColor(255, 255, 0);
    if (e == "annulee")  return QColor(211, 211, 211);
    return QColor(255, 255, 255);
}

int CommandeWidget::getPriorityForEtat(const QString &etat) const
{
    QString e = etat.toLower();


    if (e == "en cours") return 4;
    if (e == "validee")  return 3;
    if (e == "prete")    return 2;
    if (e == "annulee")  return 1;
    return 0;
}
