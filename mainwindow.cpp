#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "email_sender.h"
#include "employe.h"
#include <QFile>
#include <QApplication>
#include <QCheckBox>
#include <QMessageBox>
#include <QTabBar>
#include <QFrame>
#include <QDebug>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QDateTime>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPageSize>
#include <QMarginsF>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QVBoxLayout>
#include <QBrush>
#include <QColor>
#include <QPainter>
#include <QStringList>
#include <QRandomGenerator>
#include <QTimer>
#include <QThread>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>

namespace {
bool isNomPrenomValide(const QString &value)
{
    const QString trimmedValue = value.trimmed();
    static const QRegularExpression regexMots("^[A-Za-z\\x{00C0}-\\x{00FF}]+( [A-Za-z\\x{00C0}-\\x{00FF}]+)*$");
    if (!regexMots.match(trimmedValue).hasMatch()) {
        return false;
    }

    const int lettersCount = QString(trimmedValue).remove(' ').size();
    return lettersCount >= 3 && lettersCount <= 20;
}

QString normalizeRole(const QString &role)
{
    return role.trimmed().toLower();
}

QString generateResetCode()
{
    return QString::number(QRandomGenerator::global()->bounded(100000, 1000000));
}

void fillEmployesTable(QTableWidget *table, const QList<EmployeData> &rows)
{
    if (!table) {
        return;
    }

    table->setRowCount(0);
    for (int row = 0; row < rows.size(); ++row) {
        const EmployeData &item = rows.at(row);
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(QString::number(item.idEmploye)));
        table->setItem(row, 1, new QTableWidgetItem(item.nom));
        table->setItem(row, 2, new QTableWidgetItem(item.prenom));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(item.age)));
        table->setItem(row, 4, new QTableWidgetItem(item.poste));
        table->setItem(row, 5, new QTableWidgetItem(QString::number(item.salaire)));
        table->setItem(row, 6, new QTableWidgetItem(QString::number(item.anciennete)));
        table->setItem(row, 7, new QTableWidgetItem(item.disponibilite));
        table->setItem(row, 8, new QTableWidgetItem(QString::number(item.heuresTravail)));
        table->setItem(row, 9, new QTableWidgetItem(QString::number(item.fournisseursTraites)));
        table->setItem(row, 10, new QTableWidgetItem(item.idEquipe));
    }
}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    // === INITIALISATION GENERALE ===
    qDebug() << "[MW] ctor:start";
    ui->setupUi(this);
    qDebug() << "[MW] after setupUi";

    // Load global stylesheet from resources
    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }
    qDebug() << "[MW] after stylesheet";

    auto setEmployeAuthenticated = [this](bool authenticated) {
        if (!ui->tabWidget) {
            return;
        }
        auto setTabVisible = [this](QWidget *tab, bool visible) {
            if (!tab || !ui->tabWidget) {
                return;
            }
            const int idx = ui->tabWidget->indexOf(tab);
            if (idx != -1) {
                ui->tabWidget->setTabVisible(idx, visible);
            }
        };

        if (authenticated) {
            ui->tabWidget->tabBar()->setVisible(true);
            setTabVisible(ui->tabConnexion, false);
            setTabVisible(ui->tabMotPasseOublie, false);
            setTabVisible(ui->tabAjouter, true);
            setTabVisible(ui->tabListe, true);
            setTabVisible(ui->tabSupprimer, true);
            setTabVisible(ui->tabModifier, true);
            setTabVisible(ui->tabStatistiques, true);
            setTabVisible(ui->tabExportPdf, true);

            const int idx = ui->tabWidget->indexOf(ui->tabListe);
            if (idx != -1) {
                ui->tabWidget->setCurrentIndex(idx);
            }

            afficherEmployes();
            refreshStatistiques();
        } else {
            ui->tabWidget->tabBar()->setVisible(false);
            setTabVisible(ui->tabAjouter, false);
            setTabVisible(ui->tabListe, false);
            setTabVisible(ui->tabSupprimer, false);
            setTabVisible(ui->tabModifier, false);
            setTabVisible(ui->tabStatistiques, false);
            setTabVisible(ui->tabExportPdf, false);
            setTabVisible(ui->tabConnexion, true);
            setTabVisible(ui->tabMotPasseOublie, true);

            const int idx = ui->tabWidget->indexOf(ui->tabConnexion);
            if (idx != -1) {
                ui->tabWidget->setCurrentIndex(idx);
            }
        }
    };

    auto setEquipePageFromTab = [this](int index) {
        if (!ui->stackedWidget) {
            return;
        }
        switch (index) {
        case 0: // Ajouter
            ui->stackedWidget->setCurrentWidget(ui->pageadd);
            break;
        case 1: // Gestion
            ui->stackedWidget->setCurrentWidget(ui->page_rech);
            break;
        case 2: // Supprimer
            ui->stackedWidget->setCurrentWidget(ui->pagesupp);
            break;
        case 3: // Modifier
            ui->stackedWidget->setCurrentWidget(ui->pagemodif);
            break;
        case 4: // Statistique
            ui->stackedWidget->setCurrentWidget(ui->page_stat);
            break;
        case 5: // Suggestion
            ui->stackedWidget->setCurrentWidget(ui->sugg);
            break;
        case 6: // Planification
            ui->stackedWidget->setCurrentWidget(ui->page_planification);
            break;
        default:
            break;
        }
    };

    auto setLaboPageFromTab = [this](int index) {
        if (!ui->stackedWidget1) {
            return;
        }
        switch (index) {
        case 0: // Ajouter
            ui->stackedWidget1->setCurrentWidget(ui->pageadd1);
            break;
        case 1: // Liste
            ui->stackedWidget1->setCurrentWidget(ui->page_rech1);
            break;
        case 2: // Supprimer
            ui->stackedWidget1->setCurrentWidget(ui->pagesupp1);
            break;
        case 3: // Modifier
            ui->stackedWidget1->setCurrentWidget(ui->pagemodif1);
            break;
        case 4: // Statistiques
            ui->stackedWidget1->setCurrentWidget(ui->page_stat1);
            break;
        case 5: // Geolocalisation
            ui->stackedWidget1->setCurrentWidget(ui->pageGeo);
            break;
        case 6: // Assistant IA
            ui->stackedWidget1->setCurrentWidget(ui->pageAI);
            break;
        default:
            break;
        }
    };

    auto *nameValidator = new QRegularExpressionValidator(
        QRegularExpression("^[A-Za-z\\x{00C0}-\\x{00FF} ]{0,20}$"), this);
    ui->lineEdit_nom->setValidator(nameValidator);
    ui->lineEdit_prenom->setValidator(nameValidator);
    ui->lineEdit_nom_mod->setValidator(nameValidator);
    ui->lineEdit_prenom_mod->setValidator(nameValidator);
    ui->search_nom->setValidator(nameValidator);
    ui->lineEdit_nom->setMaxLength(20);
    ui->lineEdit_prenom->setMaxLength(20);
    ui->lineEdit_nom_mod->setMaxLength(20);
    ui->lineEdit_prenom_mod->setMaxLength(20);
    ui->search_nom->setMaxLength(20);
    ui->lineEdit_mdp->setMaxLength(255);
    ui->lineEdit_mdp_mod->setMaxLength(255);
    if (ui->line_user_identite_fp) {
        auto *forgotIdentityValidator = new QRegularExpressionValidator(
            QRegularExpression("^[A-Za-z\\x{00C0}-\\x{00FF} ]{0,50}$"), this);
        ui->line_user_identite_fp->setValidator(forgotIdentityValidator);
        ui->line_user_identite_fp->setMaxLength(50);
    }
    if (ui->line_newpass_fp) {
        auto *forgotPasswordValidator = new QRegularExpressionValidator(
            QRegularExpression("^\\S{0,255}$"), this);
        ui->line_newpass_fp->setValidator(forgotPasswordValidator);
        ui->line_newpass_fp->setMaxLength(255);
        ui->line_newpass_fp->setPlaceholderText("Obligatoire - 6 caracteres minimum");
    }
    if (ui->line_confirm_fp) {
        auto *forgotConfirmValidator = new QRegularExpressionValidator(
            QRegularExpression("^\\S{0,255}$"), this);
        ui->line_confirm_fp->setValidator(forgotConfirmValidator);
        ui->line_confirm_fp->setMaxLength(255);
    }
    qDebug() << "[MW] after validators";

    styleSpinboxesAndComboboxes();
    setupCrudConnections();
    qDebug() << "[MW] after setupCrudConnections";

    if (ui->table_employes && ui->table_employes->columnCount() > 11) {
        ui->table_employes->setColumnHidden(11, true);
    }

    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &MainWindow::exporterListeCompletePdf);
    connect(ui->btnExportFicheEmploye, &QPushButton::clicked, this, &MainWindow::exporterFicheEmployePdf);

    auto setupLaboUiData = [this]() {
        ui->tableWidgetLabo->setColumnCount(6);
        ui->tableWidgetLabo->setHorizontalHeaderLabels(
            {"ID Laboratoire", "Nom", "Type d'analyse", "Conformite", "Adresse", "Espace"});
        ui->tableWidgetLabo->setRowCount(5);

        const QList<QStringList> labos = {
            {"LAB001", "Labo Central", "Chimique", "Oui", "12 Rue de Paris", "150 m2"},
            {"LAB002", "Labo Nord", "Bacteriologique", "Oui", "45 Avenue Victor Hugo", "200 m2"},
            {"LAB003", "Labo Sud", "Physique", "Non", "8 Boulevard Gambetta", "120 m2"},
            {"LAB004", "Labo Est", "Biologique", "Oui", "23 Rue Lafayette", "180 m2"},
            {"LAB005", "Labo Ouest", "Chimique", "Non", "56 Rue Nationale", "90 m2"}
        };

        for (int row = 0; row < labos.size(); ++row) {
            for (int col = 0; col < labos[row].size(); ++col) {
                ui->tableWidgetLabo->setItem(row, col, new QTableWidgetItem(labos[row][col]));
            }
        }

        ui->tableWidgetLabo->resizeColumnsToContents();
        ui->tableWidgetLabo->horizontalHeader()->setStretchLastSection(true);
    };

    auto rechercherLaboratoires = [this]() {
        const QString searchText = ui->lineEditRechercheLabo->text();
        for (int row = 0; row < ui->tableWidgetLabo->rowCount(); ++row) {
            bool match = searchText.isEmpty();
            for (int col = 0; col < ui->tableWidgetLabo->columnCount() && !match; ++col) {
                QTableWidgetItem *item = ui->tableWidgetLabo->item(row, col);
                if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                    match = true;
                }
            }
            ui->tableWidgetLabo->setRowHidden(row, !match);
        }
    };

    auto trierLaboratoires = [this]() {
        const QString criteria = ui->comboBoxTriLabo->currentText();
        bool ascending = ui->checkBoxTriLaboCroissant->isChecked();
        if (!ui->checkBoxTriLaboCroissant->isChecked() && !ui->checkBoxTriLaboDecroissant->isChecked()) {
            ascending = true;
        }

        int column = 1;
        if (criteria == "ID") {
            column = 0;
        } else if (criteria == "Type d analyse") {
            column = 2;
        } else if (criteria == "Conformite") {
            column = 3;
        }

        ui->tableWidgetLabo->sortItems(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
    };

    auto exporterListeLaboPdf = [this]() {
        if (ui->tableWidgetLabo->rowCount() == 0) {
            QMessageBox::warning(this, "Export PDF", "Aucune donnee a exporter.");
            return;
        }

        int visibleCount = 0;
        for (int row = 0; row < ui->tableWidgetLabo->rowCount(); ++row) {
            if (!ui->tableWidgetLabo->isRowHidden(row)) {
                ++visibleCount;
            }
        }

        QMessageBox::information(
            this,
            "Export PDF",
            QString("Export de la liste des laboratoires en PDF.\n\n"
                "Total laboratoires: %1\n"
                "Laboratoires affiches: %2")
                .arg(ui->tableWidgetLabo->rowCount())
                .arg(visibleCount));
    };

    auto exporterStatsLaboPdf = [this]() {
        QMessageBox::information(
            this,
            "Export PDF",
            "Fonctionnalite d'export PDF (Statistiques) a implementer");
    };

    auto setupClientUiData = [this]() {
        ui->tableClients->setColumnCount(6);
        ui->tableClients->setHorizontalHeaderLabels(
            {"ID", "Nom", "Type", "Téléphone", "Email", "Statut"});
        ui->tableClients->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tableClients->horizontalHeader()->setStretchLastSection(true);
        ui->tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableClients->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->tableClients->setAlternatingRowColors(true);
        ui->tableClients->setShowGrid(true);
        ui->tableClients->verticalHeader()->setDefaultSectionSize(35);
        ui->tableClients->verticalHeader()->hide();

        const QList<QStringList> clients = {
            {"001", "Mohamed Ali", "Particulier", "98 123 456", "m.ali@email.com", "Actif"},
            {"002", "Fatima Ben Said", "Entreprise", "98 234 567", "f.bensaid@email.com", "Actif"},
            {"003", "Ahmed Jmal", "Particulier", "98 345 678", "a.jmal@email.com", "Inactif"},
            {"004", "Leila Chedly", "Entreprise", "98 456 789", "l.chedly@email.com", "Actif"},
            {"005", "Sami Trabelsi", "Particulier", "98 567 890", "s.trabelsi@email.com", "En attente"}
        };

        ui->tableClients->setRowCount(clients.size());
        for (int i = 0; i < clients.size(); ++i) {
            for (int j = 0; j < clients[i].size(); ++j) {
                ui->tableClients->setItem(i, j, new QTableWidgetItem(clients[i][j]));
            }
        }

        if (ui->cmbType->count() == 0) {
            ui->cmbType->addItems({"Tous", "Particulier", "Entreprise"});
        }
        if (ui->cmbStatut->count() == 0) {
            ui->cmbStatut->addItems({"Tous", "Actif", "Inactif", "En attente"});
        }
        if (ui->cmbAjouterType->count() == 0) {
            ui->cmbAjouterType->addItems({"Particulier", "Entreprise"});
        }
        if (ui->cmbAjouterStatut->count() == 0) {
            ui->cmbAjouterStatut->addItems({"Actif", "Inactif", "En attente"});
        }
        if (ui->cmbModifierType->count() == 0) {
            ui->cmbModifierType->addItems({"Particulier", "Entreprise"});
        }
        if (ui->cmbModifierStatut->count() == 0) {
            ui->cmbModifierStatut->addItems({"Actif", "Inactif", "En attente"});
        }

        ui->txtStatistiques->setHtml(
            "<div style='color:#212121; padding:10px;'>"
            "<h2 style='color:#2E7D32;'>?? Statistiques des Clients</h2>"
            "<p><b>Total Clients:</b> <span style='color:#1976D2;'>5</span></p>"
            "<p><b>Clients Actifs:</b> <span style='color:#388E3C;'>3</span></p>"
            "<p><b>Clients Inactifs:</b> <span style='color:#D32F2F;'>1</span></p>"
            "<p><b>En attente:</b> <span style='color:#F57C00;'>1</span></p>"
            "<hr style='border:1px solid #BDBDBD;'>"
            "<h3 style='color:#2E7D32;'>Par Type</h3>"
            "<p style='color:#424242;'>• Particuliers: 3</p>"
            "<p style='color:#424242;'>• Entreprises: 2</p>"
            "<hr style='border:1px solid #BDBDBD;'>"
            "<h3 style='color:#2E7D32;'>Tendances</h3>"
            "<p style='color:#388E3C;'>?? +20% ce mois</p>"
            "<p style='color:#1976D2;'>?? Chiffre d'affaires: 15,000 DT</p>"
            "</div>"
        );

        ui->txtAlertes->setHtml(
            "<div style='color:#212121; padding:10px;'>"
            "<h2 style='color:#D32F2F;'>?? Alertes et Notifications</h2>"
            "<hr style='border:1px solid #BDBDBD;'>"
            "<h3 style='color:#F57C00;'>?? Expiration de Contrats</h3>"
            "<div style='background-color:#FFF3E0; padding:10px; margin:10px 0; border-left:4px solid #F57C00;'>"
            "<p style='margin:5px 0;'><b>Client:</b> Fatima Ben Said</p>"
            "<p style='margin:5px 0;'><b>Contrat expire le:</b> <span style='color:#E65100;'>15/02/2026 (4 jours)</span></p>"
            "<p style='margin:5px 0;'><b>Type:</b> Contrat annuel - Service maintenance</p>"
            "</div>"
            "<div style='background-color:#FFF3E0; padding:10px; margin:10px 0; border-left:4px solid #F57C00;'>"
            "<p style='margin:5px 0;'><b>Client:</b> Leila Chedly</p>"
            "<p style='margin:5px 0;'><b>Contrat expire le:</b> <span style='color:#E65100;'>20/02/2026 (9 jours)</span></p>"
            "<p style='margin:5px 0;'><b>Type:</b> Contrat de fourniture</p>"
            "</div>"
            "<hr style='border:1px solid #BDBDBD; margin:20px 0;'>"
            "<h3 style='color:#D32F2F;'>?? Délais de Livraison Anormaux</h3>"
            "<div style='background-color:#FFEBEE; padding:10px; margin:10px 0; border-left:4px solid #D32F2F;'>"
            "<p style='margin:5px 0;'><b>Commande:</b> #CMD-2024-156</p>"
            "<p style='margin:5px 0;'><b>Client:</b> Mohamed Ali</p>"
            "<p style='margin:5px 0;'><b>Retard:</b> <span style='color:#C62828; font-weight:bold;'>7 jours</span></p>"
            "</div>"
            "</div>"
        );
    };

    auto clearClientInfo = [this]() {
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
        ui->lblSupprimerNom->setText("Aucun client sélectionné");
        ui->lblSupprimerDetails->setText("-");
    };

    auto updateClientInfo = [this, clearClientInfo]() {
        const int row = ui->tableClients->currentRow();
        if (row < 0 || row >= ui->tableClients->rowCount()) {
            clearClientInfo();
            return;
        }

        const QString nom = ui->tableClients->item(row, 1)->text();
        const QString type = ui->tableClients->item(row, 2)->text();
        const QString tel = ui->tableClients->item(row, 3)->text();
        const QString email = ui->tableClients->item(row, 4)->text();
        const QString statut = ui->tableClients->item(row, 5)->text();

        // Sync Modifier tab fields from selected client
        ui->txtModifierNom->setText(nom);
        ui->cmbModifierType->setCurrentText(type);
        ui->txtModifierTel->setText(tel);
        ui->txtModifierEmail->setText(email);
        ui->cmbModifierStatut->setCurrentText(statut);

        // Sync Supprimer tab info from selected client
        ui->lblSupprimerNom->setText(nom);
        ui->lblSupprimerDetails->setText(
            "Type : " + type + "   |   Statut : " + statut + "   |   Tél : " + tel
        );

        // Infos Client tab (same behavior as old module)
        ui->lblInfoStatut->setText("Statut : " + statut);

        if (statut == "Actif") {
            ui->lblInfoAlertes->setText("Alertes : ? Aucune");
            ui->lblRetardsNombre->setText("Nombre de retards : 2");
            ui->lblRetardsMoyen->setText("Retard moyen : 5 jours");
            ui->lblRetardsTotal->setText("<span style='color: #C97A7A;'>Montant en retard : 0 DT</span>");
        } else if (statut == "En attente") {
            ui->lblInfoAlertes->setText("Alertes : ?? Validation requise");
            ui->lblRetardsNombre->setText("Nombre de retards : 0");
            ui->lblRetardsMoyen->setText("Retard moyen : 0 jours");
            ui->lblRetardsTotal->setText("<span style='color: #6FA66F;'>Montant en retard : 0 DT</span>");
        } else {
            ui->lblInfoAlertes->setText("Alertes : ? Client inactif");
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

        if (type == "Entreprise") {
            ui->lblPrixMoyen->setText("Prix moyen commande : 2,850 DT");
            ui->lblPrixTotal->setText("<span style='color: #6FA66F; font-weight: bold;'>CA total généré : 45,600 DT</span>");
            ui->lblPrixRemise->setText("Remise accordée : 15%");
            ui->lblNombreCommandes->setText("Nombre de commandes : 24");
            ui->lblDerniereCommande->setText("Dernière commande : 10/02/2026");
        } else {
            ui->lblPrixMoyen->setText("Prix moyen commande : 750 DT");
            ui->lblPrixTotal->setText("<span style='color: #6FA66F; font-weight: bold;'>CA total généré : 12,300 DT</span>");
            ui->lblPrixRemise->setText("Remise accordée : 5%");
            ui->lblNombreCommandes->setText("Nombre de commandes : 16");
            ui->lblDerniereCommande->setText("Dernière commande : 05/02/2026");
        }

        ui->lblClientDepuis->setText("Client depuis : 12/03/2023");
    };

    if (ui->tabWidget && ui->tabConnexion) {
        if (ui->tabWidget->tabBar()) {
            ui->tabWidget->tabBar()->setVisible(false);
        }
        const int loginIdx = ui->tabWidget->indexOf(ui->tabConnexion);
        if (loginIdx != -1) {
            ui->tabWidget->setCurrentIndex(loginIdx);
        }
    }
    if (ui->label_login_error) {
        ui->label_login_error->clear();
    }
    if (ui->stackedMain && ui->EmployeWidget) {
        ui->stackedMain->setCurrentWidget(ui->EmployeWidget);
    }
    if (ui->topNavTabs) {
        setEquipePageFromTab(ui->topNavTabs->currentIndex());
    }
    if (ui->topNavTabs1) {
        setLaboPageFromTab(ui->topNavTabs1->currentIndex());
    }
    if (ui->tableWidgetLabo) {
        setupLaboUiData();
    }
    if (ui->tableClients) {
        setupClientUiData();
        if (ui->tableClients->rowCount() > 0) {
            ui->tableClients->selectRow(0);
        }
        updateClientInfo();
    }
    qDebug() << "[MW] after initial ui data setup";

    // Cacher le menu de navigation au demarrage (visible apres connexion)
    if (ui->navFrame) {
        ui->navFrame->setVisible(false);
    }

    // Show all menu buttons (access applied after successful login)
    if (ui->btnEmploye) ui->btnEmploye->setVisible(true);
    if (ui->btnEquipe) ui->btnEquipe->setVisible(true);
    if (ui->btnClient) ui->btnClient->setVisible(true);
    if (ui->btnLaboratoire) ui->btnLaboratoire->setVisible(true);
    if (ui->btnCommande) ui->btnCommande->setVisible(true);
    if (ui->btnMachine) ui->btnMachine->setVisible(true);

    // No module access before authentication
    m_currentRole.clear();
    if (ui->btnEmploye) ui->btnEmploye->setEnabled(false);
    if (ui->btnEquipe) ui->btnEquipe->setEnabled(false);
    if (ui->btnClient) ui->btnClient->setEnabled(false);
    if (ui->btnLaboratoire) ui->btnLaboratoire->setEnabled(false);
    if (ui->btnCommande) ui->btnCommande->setEnabled(false);
    if (ui->btnMachine) ui->btnMachine->setEnabled(false);

    // === SLOTS GENERAUX (navigation, menu, retour) ===
    // Navigation principale entre pages/modules
    connect(ui->btnEmploye, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->EmployeWidget);
    });

    connect(ui->btnEquipe, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->EquipeWidget);
    });

    connect(ui->topNavTabs, &QTabWidget::currentChanged, this, [setEquipePageFromTab](int index) {
        setEquipePageFromTab(index);
    });

    connect(ui->topNavTabs1, &QTabWidget::currentChanged, this, [setLaboPageFromTab](int index) {
        setLaboPageFromTab(index);
    });

    connect(ui->btnCommande, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->CommandeWidget);
    });

    connect(ui->btnLaboratoire, &QPushButton::clicked, this, [this, setLaboPageFromTab]() {
        ui->stackedMain->setCurrentWidget(ui->LaboWidget);
        setLaboPageFromTab(ui->topNavTabs1->currentIndex());
    });

    connect(ui->btnClient, &QPushButton::clicked, this, [this, updateClientInfo]() {
        ui->stackedMain->setCurrentWidget(ui->WidgetClient);
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
        if (ui->tableClients->currentRow() == -1 && ui->tableClients->rowCount() > 0) {
            ui->tableClients->selectRow(0);
        }
        updateClientInfo();
    });

    connect(ui->btnMachine, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->MachineWidget);
    });

    connect(ui->btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);

    connect(ui->btnNavigateForgot, &QPushButton::clicked, this, [this]() {
        if (ui->label_login_error) {
            ui->label_login_error->clear();
        }
        resetForgotFlowState(true);
        const int forgotIdx = ui->tabWidget->indexOf(ui->tabMotPasseOublie);
        if (forgotIdx != -1) {
            ui->tabWidget->setCurrentIndex(forgotIdx);
        }
    });

    connect(ui->btnBackToLogin, &QPushButton::clicked, this, [this]() {
        resetForgotFlowState(true);
        if (ui->label_login_error) {
            ui->label_login_error->clear();
        }
        const int loginIdx = ui->tabWidget->indexOf(ui->tabConnexion);
        if (loginIdx != -1) {
            ui->tabWidget->setCurrentIndex(loginIdx);
        }
    });

    connect(ui->btnContinuer, &QPushButton::clicked, this, [this]() {
        ui->navFrame->setVisible(true);
        QWidget *targetPage = firstAllowedModulePage();
        ui->stackedMain->setCurrentWidget(targetPage ? targetPage : ui->pageAccueil);
    });

    // === MODULE LABO ===
    connect(ui->btnRechercher, &QPushButton::clicked, this, [rechercherLaboratoires]() {
        rechercherLaboratoires();
    });

    connect(ui->lineEditRechercheLabo, &QLineEdit::textChanged, this, [rechercherLaboratoires](const QString &) {
        rechercherLaboratoires();
    });

    connect(ui->btnTrier1, &QPushButton::clicked, this, [trierLaboratoires]() {
        trierLaboratoires();
    });

    connect(ui->comboBoxTriLabo, QOverload<int>::of(&QComboBox::currentIndexChanged), this,
            [trierLaboratoires](int) {
                trierLaboratoires();
            });

    connect(ui->checkBoxTriLaboCroissant, &QCheckBox::toggled, this, [this, trierLaboratoires](bool checked) {
        if (checked && ui->checkBoxTriLaboDecroissant->isChecked()) {
            ui->checkBoxTriLaboDecroissant->setChecked(false);
        }
        trierLaboratoires();
    });

    connect(ui->checkBoxTriLaboDecroissant, &QCheckBox::toggled, this, [this, trierLaboratoires](bool checked) {
        if (checked && ui->checkBoxTriLaboCroissant->isChecked()) {
            ui->checkBoxTriLaboCroissant->setChecked(false);
        }
        trierLaboratoires();
    });

    connect(ui->btnExportPDF, &QPushButton::clicked, this, [exporterListeLaboPdf]() {
        exporterListeLaboPdf();
    });

    connect(ui->btnExportStatsLaboPdf, &QPushButton::clicked, this, [exporterStatsLaboPdf]() {
        exporterStatsLaboPdf();
    });

    connect(ui->tableClients, &QTableWidget::itemSelectionChanged, this, [updateClientInfo]() {
        updateClientInfo();
    });

    connect(ui->tabWidgetClient, &QTabWidget::currentChanged, this, [this, updateClientInfo](int index) {
        QWidget *tab = ui->tabWidgetClient->widget(index);
        if (tab == ui->tabModifier2 || tab == ui->tabSupprimer2 || tab == ui->tabInfosClient) {
            if (ui->tableClients->currentRow() == -1 && ui->tableClients->rowCount() > 0) {
                ui->tableClients->selectRow(0);
            } else {
                updateClientInfo();
            }
        }
    });

    connect(ui->btnAppliquerFiltre, &QPushButton::clicked, this, [this, updateClientInfo]() {
        const QString nomRecherche = ui->txtRechercheNom->text().trimmed().toLower();
        const QString typeFiltre = ui->cmbType->currentText();
        const QString statutFiltre = ui->cmbStatut->currentText();

        int firstVisibleRow = -1;
        for (int i = 0; i < ui->tableClients->rowCount(); ++i) {
            bool visible = true;

            if (!nomRecherche.isEmpty()) {
                const QString nom = ui->tableClients->item(i, 1)->text().toLower();
                if (!nom.contains(nomRecherche)) {
                    visible = false;
                }
            }

            if (typeFiltre != "Tous") {
                const QString type = ui->tableClients->item(i, 2)->text();
                if (type != typeFiltre) {
                    visible = false;
                }
            }

            if (statutFiltre != "Tous") {
                const QString statut = ui->tableClients->item(i, 5)->text();
                if (statut != statutFiltre) {
                    visible = false;
                }
            }

            ui->tableClients->setRowHidden(i, !visible);
            if (visible && firstVisibleRow == -1) {
                firstVisibleRow = i;
            }
        }

        if (firstVisibleRow != -1) {
            ui->tableClients->selectRow(firstVisibleRow);
        } else {
            ui->tableClients->clearSelection();
            updateClientInfo();
        }
    });

    auto clearLoginError = [this]() {
        if (ui->label_login_error) {
            ui->label_login_error->clear();
        }
    };

    connect(ui->line_user_conn, &QLineEdit::textChanged, this, [clearLoginError](const QString &) {
        clearLoginError();
    });

    connect(ui->line_pass_conn, &QLineEdit::textChanged, this, [clearLoginError](const QString &) {
        clearLoginError();
    });

    // === AUTH + MOT DE PASSE OUBLIE ===

    connect(ui->btnValiderIdentite, &QPushButton::clicked, this, &MainWindow::validateForgotIdentity);

    connect(ui->line_user_identite_fp, &QLineEdit::textEdited, this, [this](const QString &) {
        if (m_forgotIdentityValidated) {
            resetForgotFlowState(false);
        }
    });

    connect(ui->line_code_fp, &QLineEdit::textChanged, this, [this](const QString &) {
        updateForgotResetActionState();
    });
    connect(ui->line_newpass_fp, &QLineEdit::textChanged, this, [this](const QString &) {
        updateForgotResetActionState();
    });
    connect(ui->line_confirm_fp, &QLineEdit::textChanged, this, [this](const QString &) {
        updateForgotResetActionState();
    });

    connect(ui->btnEnvoyerCode, &QPushButton::clicked, this, [this]() {
        forgotSendCodeRequested(ui->line_user_email_fp->text());
    });

    connect(ui->btnResetPassword, &QPushButton::clicked, this, [this]() {
        resetPasswordFromForgotFlow();
    });

    // Apres connexion : afficher la page d'accueil
    connect(ui->btnSeConnecter, &QPushButton::clicked, this, [this, setEmployeAuthenticated]() {
        const QString username = ui->line_user_conn->text();
        const QString password = ui->line_pass_conn->text();

        if (username.isEmpty() || password.isEmpty()) {
            if (ui->label_login_error) {
                ui->label_login_error->setText("Username et mot de passe obligatoires.");
            }
            return;
        }

        QString role;
        QString loginError;
        if (!EmployeRepository::authenticateByIdentity(username, password, &role, &loginError)) {
            if (ui->label_login_error) {
                ui->label_login_error->setText(loginError);
            }
            return;
        }

        m_currentRole = role;
        applyAccessByRole(m_currentRole);

        if (ui->label_login_error) {
            ui->label_login_error->clear();
        }
        ui->line_pass_conn->clear();
        setEmployeAuthenticated(true);
        ui->stackedMain->setCurrentWidget(ui->pageAccueil);
    });

    EmployeRepository::clearExpiredResetCodes();
    auto *resetCodeCleanupTimer = new QTimer(this);
    resetCodeCleanupTimer->setInterval(60 * 1000);
    connect(resetCodeCleanupTimer, &QTimer::timeout, this, []() {
        EmployeRepository::clearExpiredResetCodes();
    });
    resetCodeCleanupTimer->start();

    resetForgotFlowState(true);
    qDebug() << "[MW] ctor:end";
}

MainWindow::~MainWindow()
{
    delete ui;
}

// === SLOTS GENERAUX (navigation, menu, retour) ===
void MainWindow::applyAccessByRole(const QString &role)
{
    const QString normalized = normalizeRole(role);

    const bool canEmploye = (normalized == "admin");
    const bool canEquipe = (normalized == "admin");
    const bool canClient = (normalized == "admin" || normalized == "manager");
    const bool canLabo = (normalized == "admin" || normalized == "magasinier");
    const bool canCommande = (normalized == "admin" || normalized == "manager" || normalized == "magasinier");
    const bool canMachine = (normalized == "admin" || normalized == "technicien");

    ui->btnEmploye->setEnabled(canEmploye);
    ui->btnEquipe->setEnabled(canEquipe);
    ui->btnClient->setEnabled(canClient);
    ui->btnLaboratoire->setEnabled(canLabo);
    ui->btnCommande->setEnabled(canCommande);
    ui->btnMachine->setEnabled(canMachine);
}

QWidget *MainWindow::firstAllowedModulePage() const
{
    const QString normalized = normalizeRole(m_currentRole);

    if (normalized == "admin") {
        return ui->EmployeWidget;
    }
    if (normalized == "manager") {
        return ui->WidgetClient;
    }
    if (normalized == "technicien") {
        return ui->MachineWidget;
    }
    if (normalized == "magasinier") {
        return ui->LaboWidget;
    }
    return ui->pageAccueil;
}

// === AUTH + MOT DE PASSE OUBLIE ===
void MainWindow::setForgotIdentityValidated(bool validated)
{
    m_forgotIdentityValidated = validated;

    ui->line_user_email_fp->setReadOnly(!validated);
    ui->line_user_email_fp->setEnabled(validated && !m_resetEmailSendingInProgress);
    ui->btnEnvoyerCode->setEnabled(validated && !m_resetEmailSendingInProgress);
    ui->line_code_fp->setEnabled(validated && !m_resetEmailSendingInProgress);
    ui->line_newpass_fp->setEnabled(validated && !m_resetEmailSendingInProgress);
    ui->line_confirm_fp->setEnabled(validated && !m_resetEmailSendingInProgress);
    ui->btnValiderIdentite->setEnabled(!m_resetEmailSendingInProgress);
    ui->line_user_identite_fp->setEnabled(!m_resetEmailSendingInProgress);
    updateForgotResetActionState();
}

void MainWindow::updateForgotResetActionState()
{
    const QString code = ui->line_code_fp->text().trimmed();
    const QString newPassword = ui->line_newpass_fp->text().trimmed();
    const QString confirmPassword = ui->line_confirm_fp->text().trimmed();

    const bool canReset = m_forgotIdentityValidated
                          && !m_resetEmailSendingInProgress
                          && !code.isEmpty()
                          && newPassword.size() >= 6
                          && !confirmPassword.isEmpty()
                          && (newPassword == confirmPassword);

    ui->btnResetPassword->setEnabled(canReset);
}

void MainWindow::resetForgotFlowState(bool clearIdentityInput)
{
    if (clearIdentityInput) {
        ui->line_user_identite_fp->clear();
    }
    ui->line_user_email_fp->clear();
    ui->line_code_fp->clear();
    ui->line_newpass_fp->clear();
    ui->line_confirm_fp->clear();

    m_resetEmail.clear();
    m_resetIdentity.clear();
    m_resetEmployeeId.clear();
    setForgotIdentityValidated(false);
}

void MainWindow::validateForgotIdentity()
{
    const QString identity = ui->line_user_identite_fp->text().simplified();

    QString resolvedEmployeeId;
    QString errorMessage;
    if (!EmployeRepository::resolveEmployeIdByIdentity(identity, &resolvedEmployeeId, &errorMessage)) {
        resetForgotFlowState(false);
        QMessageBox::warning(this, "Mot de passe oublie", errorMessage);
        return;
    }

    m_resetIdentity = identity;
    m_resetEmployeeId = resolvedEmployeeId;
    m_resetEmail.clear();
    ui->line_user_email_fp->clear();
    setForgotIdentityValidated(true);

    QMessageBox::information(
        this,
        "Mot de passe oublie",
        QString("Utilisateur identifie: %1\nSaisissez maintenant l'email de reception du code.")
            .arg(identity));
}

void MainWindow::forgotSendCodeRequested(const QString &email)
{
    if (m_resetEmailSendingInProgress) {
        QMessageBox::information(this, "Mot de passe oublie", "Envoi en cours, veuillez patienter.");
        return;
    }

    if (!m_forgotIdentityValidated) {
        QMessageBox::warning(
            this,
            "Mot de passe oublie",
            "Veuillez d'abord valider votre identifiant (Nom Prenom).");
        return;
    }

    if (m_resetEmployeeId.trimmed().isEmpty()) {
        QMessageBox::warning(this, "Mot de passe oublie", "Identifiant utilisateur invalide.");
        return;
    }

    const QString targetEmail = email.trimmed();
    if (targetEmail.isEmpty()) {
        QMessageBox::warning(this, "Mot de passe oublie", "Veuillez saisir votre email.");
        return;
    }

    EmployeRepository::clearExpiredResetCodes();

    const QString code = generateResetCode();
    m_resetEmail = targetEmail;
    ui->line_user_email_fp->setText(targetEmail);
    const QString employeeId = m_resetEmployeeId.trimmed();
    m_resetEmailSendingInProgress = true;
    setForgotIdentityValidated(m_forgotIdentityValidated);

    auto *smtpThread = new QThread();
    auto *sender = new EmailSender();
    sender->moveToThread(smtpThread);

    connect(smtpThread, &QThread::started, sender, [sender, targetEmail, code]() {
        sender->sendResetCode(targetEmail, code);
    });
    connect(sender, &EmailSender::emailSent, smtpThread, &QThread::quit, Qt::QueuedConnection);

    connect(sender, &EmailSender::emailSent, this, [this, smtpThread, employeeId, code](bool success, const QString &msg) {
        if (success) {
            QString dbError;
            if (!EmployeRepository::storeResetCode(employeeId, code, &dbError)) {
                QMessageBox::warning(
                    this,
                    "Mot de passe oublie",
                    "Email envoye, mais enregistrement du code impossible: " + dbError);
            } else {
                QMessageBox::information(this, "Mot de passe oublie", msg + "\nLe code expire dans 3 minutes.");
            }
        } else {
            EmployeRepository::clearResetCode(employeeId);
            QMessageBox::warning(this, "Mot de passe oublie", msg);
        }
        m_resetEmailSendingInProgress = false;
        setForgotIdentityValidated(m_forgotIdentityValidated);
    });

    connect(smtpThread, &QThread::finished, sender, &QObject::deleteLater);
    connect(smtpThread, &QThread::finished, smtpThread, &QObject::deleteLater);

    smtpThread->start();
}

void MainWindow::resetPasswordFromForgotFlow()
{
    if (!m_forgotIdentityValidated) {
        QMessageBox::warning(
            this,
            "Reinitialisation",
            "Veuillez d'abord valider votre identifiant (Nom Prenom).");
        return;
    }

    const QString employeeId = m_resetEmployeeId.trimmed();
    const QString code = ui->line_code_fp->text().trimmed();
    const QString newPassword = ui->line_newpass_fp->text().trimmed();
    const QString confirmPassword = ui->line_confirm_fp->text().trimmed();

    if (employeeId.isEmpty()) {
        QMessageBox::warning(this, "Reinitialisation", "Identifiant utilisateur invalide.");
        return;
    }

    if (code.isEmpty()) {
        QMessageBox::warning(this, "Reinitialisation", "Le code de verification est obligatoire.");
        return;
    }
    if (newPassword.isEmpty()) {
        QMessageBox::warning(this, "Reinitialisation", "Le nouveau mot de passe est obligatoire.");
        return;
    }
    if (newPassword.size() < 6) {
        QMessageBox::warning(this, "Reinitialisation", "Le mot de passe doit contenir au moins 6 caracteres.");
        return;
    }
    if (confirmPassword.isEmpty()) {
        QMessageBox::warning(this, "Reinitialisation", "La confirmation du mot de passe est obligatoire.");
        return;
    }
    if (newPassword != confirmPassword) {
        QMessageBox::warning(this, "Reinitialisation", "La confirmation du mot de passe ne correspond pas.");
        return;
    }

    EmployeRepository::clearExpiredResetCodes();
    QString dbError;
    if (!EmployeRepository::resetPasswordWithCode(
            employeeId,
            code,
            EmployeRepository::hashPassword(newPassword),
            &dbError)) {
        QMessageBox::warning(this, "Reinitialisation", dbError);
        return;
    }
    ui->line_pass_conn->clear();
    resetForgotFlowState(true);

    QMessageBox::information(this, "Reinitialisation", "Mot de passe reinitialise avec succes.");

    const int loginIdx = ui->tabWidget->indexOf(ui->tabConnexion);
    if (loginIdx != -1) {
        ui->tabWidget->setCurrentIndex(loginIdx);
    }
}

// === MODULE EMPLOYE ===
void MainWindow::styleSpinboxesAndComboboxes()
{
}

void MainWindow::setupCrudConnections()
{
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::ajouterEmploye);
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &MainWindow::supprimerEmploye);
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &MainWindow::modifierEmploye);
    connect(ui->table_employes, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);
    connect(ui->btnAppliquerFiltreEmploye, &QPushButton::clicked, this, &MainWindow::appliquerFiltreEtTri);
    connect(ui->btnResetFiltre, &QPushButton::clicked, this, &MainWindow::reinitialiserFiltre);
    connect(ui->lineEdit_id_mod, &QLineEdit::editingFinished, this, &MainWindow::chargerEmployePourModification);
}

void MainWindow::ajouterEmploye()
{
    if (!validateAjouterForm()) {
        return;
    }

    const QString idEquipe = ui->lineEdit_id_equipe->text().trimmed();
    const bool hasEquipe = !idEquipe.isEmpty();
    int idEquipeInt = 0;

    if (hasEquipe) {
        bool ok = false;
        idEquipeInt = idEquipe.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Validation", "ID Equipe invalide.");
            return;
        }

        QString equipeError;
        if (!EmployeRepository::equipeExists(idEquipeInt, &equipeError)) {
            QMessageBox::warning(this, "Validation", equipeError);
            return;
        }
    }

    EmployeData data;
    data.nom = ui->lineEdit_nom->text().trimmed();
    data.prenom = ui->lineEdit_prenom->text().trimmed();
    data.age = ui->spinBox_age->value();
    data.poste = ui->combo_spec->currentText();
    data.salaire = ui->doubleSpin_salaire->value();
    data.anciennete = ui->spin_anciennete->value();
    data.disponibilite = ui->combo_disp->currentText();
    data.heuresTravail = ui->spin_heures->value();
    data.fournisseursTraites = ui->spin_fourn->value();
    data.mdp = EmployeRepository::hashPassword(ui->lineEdit_mdp->text().trimmed());

    QString duplicateError;
    if (!EmployeRepository::isNomPrenomDisponible(data.nom, data.prenom, -1, &duplicateError)) {
        QMessageBox::warning(this, "Validation", duplicateError);
        return;
    }

    QString dbError;
    if (EmployeRepository::addEmploye(data, hasEquipe, idEquipeInt, &dbError)) {
        QMessageBox::information(this, "Succes", "Employe ajoute avec succes.");
        clearAjouterForm();
        afficherEmployes();
        refreshStatistiques();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout:\n" + dbError);
    }
}

bool MainWindow::validateAjouterForm()
{
    const QString nom = ui->lineEdit_nom->text().trimmed();
    const QString prenom = ui->lineEdit_prenom->text().trimmed();
    const QString mdp = ui->lineEdit_mdp->text().trimmed();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire.");
        return false;
    }
    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le prenom est obligatoire.");
        return false;
    }
    if (mdp.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le mot de passe est obligatoire.");
        return false;
    }
    if (mdp.size() < 6) {
        QMessageBox::warning(this, "Validation", "Le mot de passe doit contenir au moins 6 caracteres.");
        return false;
    }

    if (!isNomPrenomValide(nom)) {
        QMessageBox::warning(this, "Validation",
                             "Le nom doit contenir uniquement des lettres et espaces (3 a 20 lettres).");
        return false;
    }

    if (!isNomPrenomValide(prenom)) {
        QMessageBox::warning(this, "Validation",
                             "Le prenom doit contenir uniquement des lettres et espaces (3 a 20 lettres).");
        return false;
    }

    return true;
}

void MainWindow::clearAjouterForm()
{
    ui->lineEdit_nom->clear();
    ui->lineEdit_prenom->clear();
    ui->spinBox_age->setValue(16);
    ui->combo_spec->setCurrentIndex(0);
    ui->doubleSpin_salaire->setValue(0);
    ui->spin_anciennete->setValue(0);
    ui->combo_disp->setCurrentIndex(0);
    ui->spin_heures->setValue(0);
    ui->spin_fourn->setValue(0);
    ui->lineEdit_id_equipe->clear();
    ui->lineEdit_mdp->clear();
}

void MainWindow::afficherEmployes()
{
    QList<EmployeData> rows;
    QString dbError;
    if (!EmployeRepository::listEmployes(&rows, &dbError)) {
        qDebug() << "Erreur SQL SELECT:" << dbError;
        return;
    }
    fillEmployesTable(ui->table_employes, rows);
}

void MainWindow::chargerEmployePourModification()
{
    const QString id = ui->lineEdit_id_mod->text().trimmed();
    if (id.isEmpty()) {
        return;
    }

    bool ok = false;
    const int idEmploye = id.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Validation", "ID employe invalide.");
        return;
    }

    EmployeData data;
    QString dbError;
    if (!EmployeRepository::getEmployeById(idEmploye, &data, &dbError)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement:\n" + dbError);
        return;
    }

    ui->lineEdit_mdp_mod->clear();
    ui->lineEdit_nom_mod->setText(data.nom);
    ui->lineEdit_prenom_mod->setText(data.prenom);
    ui->spinBox_age_mod->setValue(data.age);
    ui->combo_spec_mod->setCurrentText(data.poste);
    ui->doubleSpin_salaire_mod->setValue(data.salaire);
    ui->spin_anciennete_mod->setValue(data.anciennete);
    ui->combo_disp_mod->setCurrentText(data.disponibilite);
    ui->spin_heures_mod->setValue(data.heuresTravail);
    ui->spin_fourn_mod->setValue(data.fournisseursTraites);
    ui->lineEdit_id_equipe_mod->setText(data.idEquipe);
}

void MainWindow::modifierEmploye()
{
    if (!validateModifierForm()) {
        return;
    }

    const QString idEquipeMod = ui->lineEdit_id_equipe_mod->text().trimmed();
    const bool hasEquipe = !idEquipeMod.isEmpty();
    int idEquipeInt = 0;

    if (hasEquipe) {
        bool ok = false;
        idEquipeInt = idEquipeMod.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Validation", "ID Equipe invalide.");
            return;
        }

        QString equipeError;
        if (!EmployeRepository::equipeExists(idEquipeInt, &equipeError)) {
            QMessageBox::warning(this, "Validation", equipeError);
            return;
        }
    }

    const QString mdpMod = ui->lineEdit_mdp_mod->text().trimmed();
    const bool updatePassword = !mdpMod.isEmpty();
    bool ok = false;
    const int idEmploye = ui->lineEdit_id_mod->text().trimmed().toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Validation", "ID employe invalide.");
        return;
    }

    EmployeData data;
    data.nom = ui->lineEdit_nom_mod->text().trimmed();
    data.prenom = ui->lineEdit_prenom_mod->text().trimmed();
    data.age = ui->spinBox_age_mod->value();
    data.poste = ui->combo_spec_mod->currentText();
    data.salaire = ui->doubleSpin_salaire_mod->value();
    data.anciennete = ui->spin_anciennete_mod->value();
    data.disponibilite = ui->combo_disp_mod->currentText();
    data.heuresTravail = ui->spin_heures_mod->value();
    data.fournisseursTraites = ui->spin_fourn_mod->value();

    QString duplicateError;
    if (!EmployeRepository::isNomPrenomDisponible(data.nom, data.prenom, idEmploye, &duplicateError)) {
        QMessageBox::warning(this, "Validation", duplicateError);
        return;
    }

    int rowsAffected = 0;
    QString dbError;
    if (EmployeRepository::updateEmploye(
            idEmploye,
            data,
            hasEquipe,
            idEquipeInt,
            updatePassword,
            EmployeRepository::hashPassword(mdpMod),
            &rowsAffected,
            &dbError)) {
        if (rowsAffected > 0) {
            QMessageBox::information(this, "Succes", "Employe modifie avec succes.");
            clearModifierForm();
            afficherEmployes();
            refreshStatistiques();
        } else {
            QMessageBox::warning(this, "Attention", "Aucun employe trouve avec cet ID.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification:\n" + dbError);
    }
}

bool MainWindow::validateModifierForm()
{
    const QString nom = ui->lineEdit_nom_mod->text().trimmed();
    const QString prenom = ui->lineEdit_prenom_mod->text().trimmed();
    const QString mdp = ui->lineEdit_mdp_mod->text().trimmed();

    if (ui->lineEdit_id_mod->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "L'ID est obligatoire.");
        return false;
    }
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire.");
        return false;
    }
    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le prenom est obligatoire.");
        return false;
    }

    if (!isNomPrenomValide(nom)) {
        QMessageBox::warning(this, "Validation",
                             "Le nom doit contenir uniquement des lettres et espaces (3 a 20 lettres).");
        return false;
    }

    if (!isNomPrenomValide(prenom)) {
        QMessageBox::warning(this, "Validation",
                             "Le prenom doit contenir uniquement des lettres et espaces (3 a 20 lettres).");
        return false;
    }
    if (!mdp.isEmpty() && mdp.size() < 6) {
        QMessageBox::warning(this, "Validation",
                             "Le nouveau mot de passe doit contenir au moins 6 caracteres.");
        return false;
    }

    return true;
}

void MainWindow::clearModifierForm()
{
    ui->lineEdit_id_mod->clear();
    ui->lineEdit_nom_mod->clear();
    ui->lineEdit_prenom_mod->clear();
    ui->spinBox_age_mod->setValue(16);
    ui->combo_spec_mod->setCurrentIndex(0);
    ui->doubleSpin_salaire_mod->setValue(0);
    ui->spin_anciennete_mod->setValue(0);
    ui->combo_disp_mod->setCurrentIndex(0);
    ui->spin_heures_mod->setValue(0);
    ui->spin_fourn_mod->setValue(0);
    ui->lineEdit_id_equipe_mod->clear();
    ui->lineEdit_mdp_mod->clear();
}

void MainWindow::supprimerEmploye()
{
    const QString id = ui->lineEdit_id_suppr->text().trimmed();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez entrer l'ID de l'employe a supprimer.");
        return;
    }

    const QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Confirmation",
        "Etes-vous sur de vouloir supprimer l'employe avec cet ID ?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) {
        return;
    }

    bool ok = false;
    const int idEmploye = id.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Validation", "ID employe invalide.");
        return;
    }

    int rowsAffected = 0;
    QString dbError;
    if (EmployeRepository::deleteEmploye(idEmploye, &rowsAffected, &dbError)) {
        if (rowsAffected > 0) {
            QMessageBox::information(this, "Succes", "Employe supprime avec succes.");
            ui->lineEdit_id_suppr->clear();
            afficherEmployes();
            refreshStatistiques();
        } else {
            QMessageBox::warning(this, "Attention", "Aucun employe trouve avec cet ID.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression:\n" + dbError);
    }
}

void MainWindow::onTableRowClicked(int row, int column)
{
    Q_UNUSED(column);
    ui->lineEdit_mdp_mod->clear();

    QTableWidgetItem *idItem = ui->table_employes->item(row, 0);
    if (!idItem) {
        return;
    }

    const QString id = idItem->text();
    ui->lineEdit_id_suppr->setText(id);
    ui->lineEdit_id_mod->setText(id);

    if (ui->table_employes->item(row, 1)) {
        ui->lineEdit_nom_mod->setText(ui->table_employes->item(row, 1)->text());
    }
    if (ui->table_employes->item(row, 2)) {
        ui->lineEdit_prenom_mod->setText(ui->table_employes->item(row, 2)->text());
    }
    if (ui->table_employes->item(row, 3)) {
        ui->spinBox_age_mod->setValue(ui->table_employes->item(row, 3)->text().toInt());
    }
    if (ui->table_employes->item(row, 4)) {
        ui->combo_spec_mod->setCurrentText(ui->table_employes->item(row, 4)->text());
    }
    if (ui->table_employes->item(row, 5)) {
        ui->doubleSpin_salaire_mod->setValue(ui->table_employes->item(row, 5)->text().toDouble());
    }
    if (ui->table_employes->item(row, 6)) {
        ui->spin_anciennete_mod->setValue(ui->table_employes->item(row, 6)->text().toInt());
    }
    if (ui->table_employes->item(row, 7)) {
        ui->combo_disp_mod->setCurrentText(ui->table_employes->item(row, 7)->text());
    }
    if (ui->table_employes->item(row, 8)) {
        ui->spin_heures_mod->setValue(ui->table_employes->item(row, 8)->text().toInt());
    }
    if (ui->table_employes->item(row, 9)) {
        ui->spin_fourn_mod->setValue(ui->table_employes->item(row, 9)->text().toInt());
    }
    if (ui->table_employes->item(row, 10)) {
        ui->lineEdit_id_equipe_mod->setText(ui->table_employes->item(row, 10)->text());
    }
}

void MainWindow::appliquerFiltreEtTri()
{
    const QString searchId = ui->search_id->text().trimmed();
    const QString searchNom = ui->search_nom->text().trimmed();
    const QString searchIdEquipe = ui->search_id_equipe->text().trimmed();
    const QString searchSpec = ui->search_spec->currentText();

    EmployeFilter filter;
    filter.searchNom = searchNom;
    filter.searchSpec = searchSpec;

    if (!searchId.isEmpty()) {
        bool ok = false;
        filter.searchId = searchId.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Validation", "Le filtre ID doit etre numerique.");
            return;
        }
        filter.hasSearchId = true;
    }

    if (!searchIdEquipe.isEmpty()) {
        bool ok = false;
        filter.searchIdEquipe = searchIdEquipe.toInt(&ok);
        if (!ok) {
            QMessageBox::warning(this, "Validation", "Le filtre ID Equipe doit etre numerique.");
            return;
        }
        filter.hasSearchIdEquipe = true;
    }

    if (ui->sort_salaire->isChecked()) {
        filter.orderColumn = "SALAIRE";
    } else if (ui->sort_anciennete->isChecked()) {
        filter.orderColumn = "ANCIENNETE";
    } else if (ui->sort_heures->isChecked()) {
        filter.orderColumn = "HEURES_TRAVAIL";
    } else if (ui->sort_fournisseurs->isChecked()) {
        filter.orderColumn = "FOURNISSEURS_TRAITES";
    }
    filter.descending = ui->order_desc->isChecked();

    QList<EmployeData> rows;
    QString dbError;
    if (!EmployeRepository::filterEmployes(filter, &rows, &dbError)) {
        qDebug() << "Erreur SQL Filtre:" << dbError;
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche:\n" + dbError);
        return;
    }

    fillEmployesTable(ui->table_employes, rows);
}

void MainWindow::reinitialiserFiltre()
{
    ui->search_id->clear();
    ui->search_nom->clear();
    ui->search_id_equipe->clear();
    ui->search_spec->setCurrentIndex(0);

    ui->sort_salaire->setChecked(false);
    ui->sort_anciennete->setChecked(false);
    ui->sort_heures->setChecked(false);
    ui->sort_fournisseurs->setChecked(false);
    ui->order_asc->setChecked(true);

    afficherEmployes();
}

void MainWindow::setupStatistiquesCharts()
{
    auto ensureChartHost = [](QFrame *frame, QChartView *&chartView) {
        QVBoxLayout *layout = qobject_cast<QVBoxLayout *>(frame->layout());
        if (!layout) {
            layout = new QVBoxLayout(frame);
            layout->setContentsMargins(4, 4, 4, 4);
        }
        if (!chartView) {
            chartView = new QChartView(frame);
            chartView->setRenderHint(QPainter::Antialiasing);
            layout->addWidget(chartView);
        }
    };

    ensureChartHost(ui->frameStatsTopChart, statsTopChartView);
    ensureChartHost(ui->frameStatsLeftChart, statsLeftChartView);
    ensureChartHost(ui->frameStatsRightChart, statsRightChartView);
}

void MainWindow::refreshStatistiques()
{
    if (!statsTopChartView || !statsLeftChartView || !statsRightChartView) {
        setupStatistiquesCharts();
    }
    if (!statsTopChartView || !statsLeftChartView || !statsRightChartView) {
        return;
    }

    const QColor chartBgColor("#1E2521");
    const QColor plotBgColor("#151A18");
    const QColor textColor("#E8F0E8");
    const QColor gridColor("#3A4941");
    const QColor greenPrimary("#67D98A");
    const QColor greenSecondary("#4FBF78");
    const QColor greenAccent("#9EE6B0");

    auto applyDarkTheme = [&](QChart *chart) {
        chart->setBackgroundVisible(true);
        chart->setBackgroundBrush(QBrush(chartBgColor));
        chart->setPlotAreaBackgroundVisible(true);
        chart->setPlotAreaBackgroundBrush(QBrush(plotBgColor));
        chart->setTitleBrush(QBrush(textColor));
        if (chart->legend()) {
            chart->legend()->setLabelColor(textColor);
        }
    };

    auto replaceChart = [](QChartView *view, QChart *chart) {
        if (!view) {
            delete chart;
            return;
        }
        QChart *oldChart = view->chart();
        view->setChart(chart);
        if (oldChart) {
            delete oldChart;
        }
    };

    EmployeStatsSummary summary;
    QString statsError;
    if (!EmployeRepository::getStatsSummary(&summary, &statsError)) {
        qDebug() << "Erreur stats resume employe:" << statsError;
    }

    const int totalEmployes = summary.totalEmployes;
    const double masseSalariale = summary.masseSalariale;

    const double salaireMoyen = totalEmployes > 0 ? (masseSalariale / totalEmployes) : 0.0;
    ui->label_total_employes->setText(QString("Nombre total d'employes : %1").arg(totalEmployes));
    ui->label_masse_salariale->setText(QString("Masse salariale totale : %1").arg(masseSalariale, 0, 'f', 2));
    ui->label_salaire_moyen->setText(QString("Salaire moyen : %1").arg(salaireMoyen, 0, 'f', 2));

    {
        QList<EmployeMasseByPoste> rows;
        if (!EmployeRepository::getMasseByPoste(&rows, &statsError)) {
            qDebug() << "Erreur stats masse par poste:" << statsError;
        }

        QStringList categories;
        auto *setMasse = new QBarSet("Masse salariale");
        for (const EmployeMasseByPoste &row : rows) {
            categories << row.poste;
            *setMasse << row.masse;
        }

        auto *series = new QBarSeries();
        series->append(setMasse);
        setMasse->setColor(greenPrimary);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);

        auto *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setLabelsColor(textColor);
        axisX->setGridLineColor(gridColor);
        axisX->setLinePenColor(gridColor);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        auto *axisY = new QValueAxis();
        axisY->setLabelFormat("%.0f");
        axisY->setLabelsColor(textColor);
        axisY->setGridLineColor(gridColor);
        axisY->setLinePenColor(gridColor);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(statsTopChartView, chart);
    }

    {
        QList<EmployeCountByPoste> rows;
        if (!EmployeRepository::getCountByPoste(&rows, &statsError)) {
            qDebug() << "Erreur stats effectif par poste:" << statsError;
        }

        auto *series = new QPieSeries();
        for (const EmployeCountByPoste &row : rows) {
            series->append(row.poste, row.total);
        }

        const QList<QColor> pieColors = {greenPrimary, greenSecondary, greenAccent, QColor("#3EAE67"), QColor("#B6F0C4")};
        const auto pieSlices = series->slices();
        for (int i = 0; i < pieSlices.size(); ++i) {
            auto *slice = pieSlices.at(i);
            slice->setBrush(pieColors.at(i % pieColors.size()));
            slice->setLabelVisible(true);
            slice->setLabelColor(textColor);
        }

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(statsLeftChartView, chart);
    }

    {
        QList<EmployeTopFournisseurs> rows;
        if (!EmployeRepository::getTopFournisseurs(5, &rows, &statsError)) {
            qDebug() << "Erreur stats top fournisseurs:" << statsError;
        }

        QStringList categories;
        auto *setTop = new QBarSet("Fournisseurs traites");
        for (const EmployeTopFournisseurs &row : rows) {
            categories << (row.nom.trimmed() + " " + row.prenom.trimmed()).trimmed();
            *setTop << row.fournisseursTraites;
        }

        auto *series = new QBarSeries();
        series->append(setTop);
        setTop->setColor(greenSecondary);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);

        auto *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setLabelsColor(textColor);
        axisX->setGridLineColor(gridColor);
        axisX->setLinePenColor(gridColor);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        auto *axisY = new QValueAxis();
        axisY->setLabelFormat("%.0f");
        axisY->setLabelsColor(textColor);
        axisY->setGridLineColor(gridColor);
        axisY->setLinePenColor(gridColor);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(statsRightChartView, chart);
    }
}

void MainWindow::exporterListeCompletePdf()
{
    const QString defaultName = QString("liste_employes_%1.pdf")
                                    .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
    const QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter la liste complete en PDF",
        defaultName,
        "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }

    QList<EmployeData> rows;
    QString dbError;
    if (!EmployeRepository::listEmployes(&rows, &dbError)) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les employes pour export :\n" + dbError);
        return;
    }

    QString html;
    html += "<h2>Liste complete des employes</h2>";
    html += "<p>Genere le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>ID</th><th>Nom</th><th>Prenom</th><th>Age</th><th>Poste</th><th>Salaire</th><th>Anciennete</th><th>Disponibilite</th><th>Heures</th><th>Fournisseurs</th><th>ID Equipe</th></tr>";

    int count = 0;
    for (const EmployeData &row : rows) {
        html += "<tr>";
        html += "<td>" + QString::number(row.idEmploye).toHtmlEscaped() + "</td>";
        html += "<td>" + row.nom.toHtmlEscaped() + "</td>";
        html += "<td>" + row.prenom.toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(row.age).toHtmlEscaped() + "</td>";
        html += "<td>" + row.poste.toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(row.salaire, 'f', 2).toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(row.anciennete).toHtmlEscaped() + "</td>";
        html += "<td>" + row.disponibilite.toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(row.heuresTravail).toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(row.fournisseursTraites).toHtmlEscaped() + "</td>";
        html += "<td>" + row.idEquipe.toHtmlEscaped() + "</td>";
        html += "</tr>";
        ++count;
    }
    html += "</table>";

    if (count == 0) {
        QMessageBox::warning(this, "Export PDF", "Aucun employe a exporter.");
        return;
    }

    QTextDocument document;
    document.setHtml(html);

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));
    document.print(&writer);

    QMessageBox::information(this, "Export PDF", "Liste exportee avec succes :\n" + filePath);
}

void MainWindow::exporterFicheEmployePdf()
{
    const QString id = ui->lineEdit_id_export->text().trimmed();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Export PDF", "Veuillez saisir un ID employe.");
        return;
    }

    bool ok = false;
    const int idEmploye = id.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Export PDF", "ID employe invalide.");
        return;
    }

    EmployeData employe;
    QString dbError;
    if (!EmployeRepository::getEmployeById(idEmploye, &employe, &dbError)) {
        QMessageBox::warning(this, "Export PDF", dbError);
        return;
    }

    const QString defaultName = QString("fiche_employe_%1_%2.pdf")
                                    .arg(id)
                                    .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
    const QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter la fiche employe en PDF",
        defaultName,
        "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }

    QString html;
    html += "<h2>Fiche Employe</h2>";
    html += "<p>Genere le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='6'>";
    html += "<tr><td><b>ID</b></td><td>" + QString::number(employe.idEmploye).toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Nom</b></td><td>" + employe.nom.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Prenom</b></td><td>" + employe.prenom.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Age</b></td><td>" + QString::number(employe.age).toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Poste</b></td><td>" + employe.poste.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Salaire</b></td><td>" + QString::number(employe.salaire, 'f', 2).toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Anciennete</b></td><td>" + QString::number(employe.anciennete).toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Disponibilite</b></td><td>" + employe.disponibilite.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Heures</b></td><td>" + QString::number(employe.heuresTravail).toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Fournisseurs</b></td><td>" + QString::number(employe.fournisseursTraites).toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>ID Equipe</b></td><td>" + employe.idEquipe.toHtmlEscaped() + "</td></tr>";
    html += "</table>";

    const QString message = ui->textEdit_export_messages->toPlainText().trimmed();
    if (!message.isEmpty()) {
        html += "<h3>Message</h3>";
        html += "<p>" + message.toHtmlEscaped().replace("\n", "<br/>") + "</p>";
    }

    QTextDocument document;
    document.setHtml(html);

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));
    document.print(&writer);

    QMessageBox::information(this, "Export PDF", "Fiche employe exportee avec succes :\n" + filePath);
}

// === MODULE EQUIPE ===
// Zone reservee aux methodes du module Equipe.

// === MODULE CLIENT ===
// Zone reservee aux methodes du module Client.

// === MODULE LABO ===
// Zone reservee aux methodes du module Laboratoire.

// === MODULE COMMANDE ===
// Zone reservee aux methodes du module Commande.

// === MODULE MACHINE ===
// Zone reservee aux methodes du module Machine.
