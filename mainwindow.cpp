#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QApplication>
#include <QTabBar>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <QDateTime>
#include <QTextDocument>
#include <QPdfWriter>
#include <QPageSize>
#include <QMarginsF>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QVBoxLayout>

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
    static const QRegularExpression regexMots("^[A-Za-zÀ-ÖØ-öø-ÿ]+( [A-Za-zÀ-ÖØ-öø-ÿ]+)*$");
    if (!regexMots.match(trimmedValue).hasMatch()) {
        return false;
    }

    const int lettersCount = QString(trimmedValue).remove(' ').size();
    return lettersCount >= 3 && lettersCount <= 20;
}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Contrôle de saisie: lettres + espace uniquement pour nom/prénom
    auto *nameValidator = new QRegularExpressionValidator(
        QRegularExpression("^[A-Za-zÀ-ÖØ-öø-ÿ ]{0,20}$"),
        this);
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
    
    // Default to Connexion tab on startup
    setAuthenticated(false);

    // Style spinbox and combobox to make arrows visible
    styleSpinboxesAndComboboxes();
    
    // Setup CRUD connections
    setupCrudConnections();

    // Statistiques (Qt Charts)
    setupStatistiquesCharts();
    refreshStatistiques();

    // Export PDF
    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &MainWindow::exporterListeCompletePdf);
    connect(ui->btnExportFicheEmploye, &QPushButton::clicked, this, &MainWindow::exporterFicheEmployePdf);
    // Connexions pour l'authentification et la rÃƒÂ©initialisation de mot de passe (UI-only)
    connect(ui->btnSeConnecter, &QPushButton::clicked, this, [this]() {
        emit loginRequested(ui->line_user_conn->text(), ui->line_pass_conn->text());
    });
    // Navigue vers l'onglet Mot de passe oubliÃƒÂ©
    connect(ui->btnNavigateForgot, &QPushButton::clicked, this, [this]() {
        const int forgotIdx = ui->tabWidget->indexOf(ui->tabMotPasseOublie);
        if (forgotIdx != -1) {
            ui->tabWidget->setCurrentIndex(forgotIdx);
        }
    });
    // Envoyer code pour rÃƒÂ©initialisation
    connect(ui->btnEnvoyerCode, &QPushButton::clicked, this, [this]() {
        emit forgotSendCodeRequested(ui->line_user_email_fp->text());
    });
    // RÃƒÂ©initialiser mot de passe (ÃƒÂ©tape 2)
    connect(ui->btnResetPassword, &QPushButton::clicked, this, [this]() {
        emit resetPasswordRequested(ui->line_code_fp->text(), ui->line_newpass_fp->text());
    });
    // Retour ÃƒÂ  l'onglet Connexion
    connect(ui->btnBackToLogin, &QPushButton::clicked, this, [this]() {
        const int loginIdx = ui->tabWidget->indexOf(ui->tabConnexion);
        if (loginIdx != -1) {
            ui->tabWidget->setCurrentIndex(loginIdx);
        }
    });

    // Load global stylesheet from resources
    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }

    // Only keep the Employe module
    auto *employe = ui->EmployeWidget;
    ui->stackedMain->setCurrentWidget(employe);

    // Hide navigation frame until login
    ui->navFrame->setVisible(false);

    // Show all menu buttons, but keep only Employe enabled
    ui->btnEmploye->setVisible(true);
    ui->btnEquipe->setVisible(true);
    ui->btnClient->setVisible(true);
    ui->btnLaboratoire->setVisible(true);
    ui->btnCommande->setVisible(true);
    ui->btnMachine->setVisible(true);

    ui->btnEmploye->setEnabled(true);
    ui->btnEquipe->setEnabled(false);
    ui->btnClient->setEnabled(false);
    ui->btnLaboratoire->setEnabled(false);
    ui->btnCommande->setEnabled(false);
    ui->btnMachine->setEnabled(false);

    // Menu navigation
    connect(ui->btnEmploye, &QPushButton::clicked, [this, employe]() {
        ui->stackedMain->setCurrentWidget(employe);
    });
    connect(ui->btnQuit, &QPushButton::clicked, qApp, &QApplication::quit);

    // Show menu and authenticate after login button clicked
    connect(this, &MainWindow::loginRequested, this, [this, employe]() {
        setAuthenticated(true);  // Show employee tabs (Liste, Ajouter, etc.)
        ui->navFrame->setVisible(true);
        ui->stackedMain->setCurrentWidget(employe);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::styleSpinboxesAndComboboxes()
{
    // The QSS stylesheet now handles arrow display with SVG images
    // This function is kept for future customizations if needed
}

void MainWindow::setAuthenticated(bool authenticated)
{
    emit authenticatedChanged(authenticated);

    auto setTabVisible = [this](QWidget *tab, bool visible) {
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
        
        // Charger la liste des employÃƒÂ©s aprÃƒÂ¨s connexion
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
}

// ============================================================================
// CRUD Connections Setup
// ============================================================================
void MainWindow::setupCrudConnections()
{
    // Bouton Ajouter
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::ajouterEmploye);
    
    // Bouton Supprimer
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &MainWindow::supprimerEmploye);
    
    // Bouton Modifier
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &MainWindow::modifierEmploye);
    
    // Clic sur une ligne du tableau
    connect(ui->table_employes, &QTableWidget::cellClicked, this, &MainWindow::onTableRowClicked);
    
    // Boutons Recherche/Tri
    connect(ui->btnAppliquerFiltre, &QPushButton::clicked, this, &MainWindow::appliquerFiltreEtTri);
    connect(ui->btnResetFiltre, &QPushButton::clicked, this, &MainWindow::reinitialiserFiltre);
}

// ============================================================================
// CREATE - Ajouter un employÃƒÂ©
// ============================================================================
void MainWindow::ajouterEmploye()
{
    if (!validateAjouterForm()) {
        return;
    }
    
    QSqlQuery query;
    QString idEquipe = ui->lineEdit_id_equipe->text().trimmed();
    
    // VÃƒÂ©rifier si l'ÃƒÂ©quipe existe (si spÃƒÂ©cifiÃƒÂ©e)
    if (!idEquipe.isEmpty()) {
        QSqlQuery checkEquipe;
        checkEquipe.prepare("SELECT ID_EQUIPE FROM EQUIPE WHERE ID_EQUIPE = :id");
        checkEquipe.bindValue(":id", idEquipe.toInt());
        if (!checkEquipe.exec() || !checkEquipe.next()) {
            QMessageBox::warning(this, "Validation", 
                "L'équipe avec l'ID " + idEquipe + " n'existe pas.\n"
                "Laissez le champ vide ou entrez un ID d'équipe valide.");
            return;
        }
    }
    
    if (idEquipe.isEmpty()) {
        // Sans ID_EQUIPE (sera NULL) - ID_EMPLOYE auto-incrÃƒÂ©mentÃƒÂ©
        query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES) "
                      "VALUES (:nom, :prenom, :age, :poste, :salaire, :anciennete, :disp, :heures, :fourn)");
    } else {
        // Avec ID_EQUIPE - ID_EMPLOYE auto-incrÃƒÂ©mentÃƒÂ©
        query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE) "
                      "VALUES (:nom, :prenom, :age, :poste, :salaire, :anciennete, :disp, :heures, :fourn, :id_equipe)");
        query.bindValue(":id_equipe", idEquipe.toInt());
    }
    
    query.bindValue(":nom", ui->lineEdit_nom->text().trimmed());
    query.bindValue(":prenom", ui->lineEdit_prenom->text().trimmed());
    query.bindValue(":age", ui->spinBox_age->value());
    query.bindValue(":poste", ui->combo_spec->currentText());
    query.bindValue(":salaire", ui->doubleSpin_salaire->value());
    query.bindValue(":anciennete", ui->spin_anciennete->value());
    query.bindValue(":disp", ui->combo_disp->currentText());
    query.bindValue(":heures", ui->spin_heures->value());
    query.bindValue(":fourn", ui->spin_fourn->value());
    
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès!");
        clearAjouterForm();
        afficherEmployes();
        refreshStatistiques();
        emit addRequested(); // Signal pour notifier
    } else {
        QMessageBox::critical(this, "Erreur", 
            "Erreur lors de l'ajout:\n" + query.lastError().text());
    }
}

bool MainWindow::validateAjouterForm()
{
    const QString nom = ui->lineEdit_nom->text().trimmed();
    const QString prenom = ui->lineEdit_prenom->text().trimmed();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire.");
        return false;
    }
    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le prénom est obligatoire.");
        return false;
    }

    if (!isNomPrenomValide(nom)) {
        QMessageBox::warning(this, "Validation",
                             "Le nom doit contenir uniquement des lettres et espaces (3 à 20 lettres).");
        return false;
    }

    if (!isNomPrenomValide(prenom)) {
        QMessageBox::warning(this, "Validation",
                             "Le prénom doit contenir uniquement des lettres et espaces (3 à 20 lettres).");
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
}

// ============================================================================
// READ - Afficher la liste des employÃƒÂ©s
// ============================================================================
void MainWindow::afficherEmployes()
{
    ui->table_employes->setRowCount(0);
    
    QSqlQuery query;
    if (!query.exec("SELECT ID_EMPLOYE, NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE FROM EMPLOYE ORDER BY ID_EMPLOYE")) {
        qDebug() << "Erreur SQL SELECT:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement de la liste:\n" + query.lastError().text());
        return;
    }
    
    int row = 0;
    while (query.next()) {
        ui->table_employes->insertRow(row);
        ui->table_employes->setItem(row, 0, new QTableWidgetItem(query.value("ID_EMPLOYE").toString()));
        ui->table_employes->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->table_employes->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
        ui->table_employes->setItem(row, 3, new QTableWidgetItem(query.value("AGE").toString()));
        ui->table_employes->setItem(row, 4, new QTableWidgetItem(query.value("POSTE").toString()));
        ui->table_employes->setItem(row, 5, new QTableWidgetItem(query.value("SALAIRE").toString()));
        ui->table_employes->setItem(row, 6, new QTableWidgetItem(query.value("ANCIENNETE").toString()));
        ui->table_employes->setItem(row, 7, new QTableWidgetItem(query.value("DISPONIBILITE").toString()));
        ui->table_employes->setItem(row, 8, new QTableWidgetItem(query.value("HEURES_TRAVAIL").toString()));
        ui->table_employes->setItem(row, 9, new QTableWidgetItem(query.value("FOURNISSEURS_TRAITES").toString()));
        ui->table_employes->setItem(row, 10, new QTableWidgetItem(query.value("ID_EQUIPE").toString()));
        row++;
    }
    
    qDebug() << "Nombre d'employés chargés:" << row;
}

// ============================================================================
// UPDATE - Modifier un employÃƒÂ©
// ============================================================================
void MainWindow::chargerEmployePourModification()
{
    QString id = ui->lineEdit_id_mod->text().trimmed();
    
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez entrer l'ID de l'employé à modifier.");
        return;
    }
    
    QSqlQuery query;
    query.prepare("SELECT * FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);
    
    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", 
            "Erreur lors du chargement:\n" + query.lastError().text());
        return;
    }
    
    if (query.next()) {
        ui->lineEdit_nom_mod->setText(query.value("NOM").toString());
        ui->lineEdit_prenom_mod->setText(query.value("PRENOM").toString());
        ui->spinBox_age_mod->setValue(query.value("AGE").toInt());
        ui->combo_spec_mod->setCurrentText(query.value("POSTE").toString());
        ui->doubleSpin_salaire_mod->setValue(query.value("SALAIRE").toDouble());
        ui->spin_anciennete_mod->setValue(query.value("ANCIENNETE").toInt());
        ui->combo_disp_mod->setCurrentText(query.value("DISPONIBILITE").toString());
        ui->spin_heures_mod->setValue(query.value("HEURES_TRAVAIL").toInt());
        ui->spin_fourn_mod->setValue(query.value("FOURNISSEURS_TRAITES").toInt());
        ui->lineEdit_id_equipe_mod->setText(query.value("ID_EQUIPE").toString());
    } else {
        QMessageBox::warning(this, "Non trouvé", "Aucun employé trouvé avec cet ID.");
    }
}

void MainWindow::modifierEmploye()
{
    if (!validateModifierForm()) {
        return;
    }
    
    QSqlQuery query;
    QString idEquipeMod = ui->lineEdit_id_equipe_mod->text().trimmed();
    
    // VÃƒÂ©rifier si l'ÃƒÂ©quipe existe (si spÃƒÂ©cifiÃƒÂ©e)
    if (!idEquipeMod.isEmpty()) {
        QSqlQuery checkEquipe;
        checkEquipe.prepare("SELECT ID_EQUIPE FROM EQUIPE WHERE ID_EQUIPE = :id");
        checkEquipe.bindValue(":id", idEquipeMod.toInt());
        if (!checkEquipe.exec() || !checkEquipe.next()) {
            QMessageBox::warning(this, "Validation", 
                "L'équipe avec l'ID " + idEquipeMod + " n'existe pas.\n"
                "Laissez le champ vide ou entrez un ID d'équipe valide.");
            return;
        }
    }
    
    if (idEquipeMod.isEmpty()) {
        query.prepare("UPDATE EMPLOYE SET NOM = :nom, PRENOM = :prenom, AGE = :age, POSTE = :poste, "
                      "SALAIRE = :salaire, ANCIENNETE = :anciennete, DISPONIBILITE = :disp, "
                      "HEURES_TRAVAIL = :heures, FOURNISSEURS_TRAITES = :fourn, ID_EQUIPE = NULL "
                      "WHERE ID_EMPLOYE = :id");
    } else {
        query.prepare("UPDATE EMPLOYE SET NOM = :nom, PRENOM = :prenom, AGE = :age, POSTE = :poste, "
                      "SALAIRE = :salaire, ANCIENNETE = :anciennete, DISPONIBILITE = :disp, "
                      "HEURES_TRAVAIL = :heures, FOURNISSEURS_TRAITES = :fourn, ID_EQUIPE = :id_equipe "
                      "WHERE ID_EMPLOYE = :id");
        query.bindValue(":id_equipe", idEquipeMod.toInt());
    }
    
    query.bindValue(":id", ui->lineEdit_id_mod->text().trimmed().toInt());
    query.bindValue(":nom", ui->lineEdit_nom_mod->text().trimmed());
    query.bindValue(":prenom", ui->lineEdit_prenom_mod->text().trimmed());
    query.bindValue(":age", ui->spinBox_age_mod->value());
    query.bindValue(":poste", ui->combo_spec_mod->currentText());
    query.bindValue(":salaire", ui->doubleSpin_salaire_mod->value());
    query.bindValue(":anciennete", ui->spin_anciennete_mod->value());
    query.bindValue(":disp", ui->combo_disp_mod->currentText());
    query.bindValue(":heures", ui->spin_heures_mod->value());
    query.bindValue(":fourn", ui->spin_fourn_mod->value());
    
    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "Succès", "Employé modifié avec succès!");
            clearModifierForm();
            afficherEmployes();
            refreshStatistiques();
            emit updateRequested(); // Signal pour notifier
        } else {
            QMessageBox::warning(this, "Attention", "Aucun employé trouvé avec cet ID.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", 
            "Erreur lors de la modification:\n" + query.lastError().text());
    }
}

bool MainWindow::validateModifierForm()
{
    const QString nom = ui->lineEdit_nom_mod->text().trimmed();
    const QString prenom = ui->lineEdit_prenom_mod->text().trimmed();

    if (ui->lineEdit_id_mod->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "L'ID est obligatoire.");
        return false;
    }
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire.");
        return false;
    }
    if (prenom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le prénom est obligatoire.");
        return false;
    }

    if (!isNomPrenomValide(nom)) {
        QMessageBox::warning(this, "Validation",
                             "Le nom doit contenir uniquement des lettres et espaces (3 à 20 lettres).");
        return false;
    }

    if (!isNomPrenomValide(prenom)) {
        QMessageBox::warning(this, "Validation",
                             "Le prénom doit contenir uniquement des lettres et espaces (3 à 20 lettres).");
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
}

// ============================================================================
// DELETE - Supprimer un employÃƒÂ©
// ============================================================================
void MainWindow::supprimerEmploye()
{
    QString id = ui->lineEdit_id_suppr->text().trimmed();
    
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez entrer l'ID de l'employé à supprimer.");
        return;
    }
    
    // Confirmation
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation",
        "Êtes-vous sûr de vouloir supprimer l'employé avec l'ID: " + id + " ?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply != QMessageBox::Yes) {
        return;
    }
    
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id.toInt());
    
    if (query.exec()) {
        if (query.numRowsAffected() > 0) {
            QMessageBox::information(this, "Succès", "Employé supprimé avec succès!");
            ui->lineEdit_id_suppr->clear();
            afficherEmployes();
            refreshStatistiques();
            emit deleteRequested(); // Signal pour notifier
        } else {
            QMessageBox::warning(this, "Attention", "Aucun employé trouvé avec cet ID.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", 
            "Erreur lors de la suppression:\n" + query.lastError().text());
    }
}

// ============================================================================
// Helpers
// ============================================================================
void MainWindow::onTableRowClicked(int row, int column)
{
    Q_UNUSED(column);
    
    // RÃƒÂ©cupÃƒÂ©rer toutes les donnÃƒÂ©es de la ligne cliquÃƒÂ©e
    QTableWidgetItem *idItem = ui->table_employes->item(row, 0);
    if (!idItem) return;
    
    QString id = idItem->text();
    
    // Remplir le champ ID pour Supprimer
    ui->lineEdit_id_suppr->setText(id);
    
    // Remplir tous les champs pour Modifier
    ui->lineEdit_id_mod->setText(id);
    
    // Charger directement depuis la ligne du tableau
    if (ui->table_employes->item(row, 1)) 
        ui->lineEdit_nom_mod->setText(ui->table_employes->item(row, 1)->text());
    if (ui->table_employes->item(row, 2)) 
        ui->lineEdit_prenom_mod->setText(ui->table_employes->item(row, 2)->text());
    if (ui->table_employes->item(row, 3)) 
        ui->spinBox_age_mod->setValue(ui->table_employes->item(row, 3)->text().toInt());
    if (ui->table_employes->item(row, 4)) 
        ui->combo_spec_mod->setCurrentText(ui->table_employes->item(row, 4)->text());
    if (ui->table_employes->item(row, 5)) 
        ui->doubleSpin_salaire_mod->setValue(ui->table_employes->item(row, 5)->text().toDouble());
    if (ui->table_employes->item(row, 6)) 
        ui->spin_anciennete_mod->setValue(ui->table_employes->item(row, 6)->text().toInt());
    if (ui->table_employes->item(row, 7)) 
        ui->combo_disp_mod->setCurrentText(ui->table_employes->item(row, 7)->text());
    if (ui->table_employes->item(row, 8)) 
        ui->spin_heures_mod->setValue(ui->table_employes->item(row, 8)->text().toInt());
    if (ui->table_employes->item(row, 9)) 
        ui->spin_fourn_mod->setValue(ui->table_employes->item(row, 9)->text().toInt());
    if (ui->table_employes->item(row, 10)) 
        ui->lineEdit_id_equipe_mod->setText(ui->table_employes->item(row, 10)->text());
}

// ============================================================================
// RECHERCHE ET TRI
// ============================================================================
void MainWindow::appliquerFiltreEtTri()
{
    ui->table_employes->setRowCount(0);
    
    // Construction de la requête SQL avec filtres
    QString sql = "SELECT ID_EMPLOYE, NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, "
                  "DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE FROM EMPLOYE";
    QStringList whereConditions;
    
    // Filtres de recherche
    QString searchId = ui->search_id->text().trimmed();
    QString searchNom = ui->search_nom->text().trimmed();
    QString searchIdEquipe = ui->search_id_equipe->text().trimmed();
    QString searchSpec = ui->search_spec->currentText();
    
    if (!searchId.isEmpty()) {
        whereConditions << "TO_CHAR(ID_EMPLOYE) LIKE :search_id";
    }
    if (!searchNom.isEmpty()) {
        whereConditions << "UPPER(NOM) LIKE UPPER(:search_nom)";
    }
    if (!searchIdEquipe.isEmpty()) {
        whereConditions << "TO_CHAR(ID_EQUIPE) LIKE :search_id_equipe";
    }
    if (searchSpec != "-- Tous --") {
        whereConditions << "POSTE = :search_spec";
    }

    if (!whereConditions.isEmpty()) {
        sql += " WHERE " + whereConditions.join(" AND ");
    }
    
    // Tri
    QString orderColumn;
    if (ui->sort_salaire->isChecked()) {
        orderColumn = "SALAIRE";
    } else if (ui->sort_anciennete->isChecked()) {
        orderColumn = "ANCIENNETE";
    } else if (ui->sort_heures->isChecked()) {
        orderColumn = "HEURES_TRAVAIL";
    } else if (ui->sort_fournisseurs->isChecked()) {
        orderColumn = "FOURNISSEURS_TRAITES";
    }
    
    if (!orderColumn.isEmpty()) {
        sql += " ORDER BY " + orderColumn;
        if (ui->order_desc->isChecked()) {
            sql += " DESC";
        } else {
            sql += " ASC";
        }
    } else {
        sql += " ORDER BY ID_EMPLOYE";
    }
    
    QSqlQuery query;
    query.prepare(sql);

    if (!searchId.isEmpty()) {
        query.bindValue(":search_id", "%" + searchId + "%");
    }
    if (!searchNom.isEmpty()) {
        query.bindValue(":search_nom", "%" + searchNom + "%");
    }
    if (!searchIdEquipe.isEmpty()) {
        query.bindValue(":search_id_equipe", "%" + searchIdEquipe + "%");
    }
    if (searchSpec != "-- Tous --") {
        query.bindValue(":search_spec", searchSpec);
    }

    if (!query.exec()) {
        qDebug() << "Erreur SQL Filtre:" << query.lastError().text();
        QMessageBox::critical(this, "Erreur", "Erreur lors de la recherche:\n" + query.lastError().text());
        return;
    }
    
    int row = 0;
    while (query.next()) {
        ui->table_employes->insertRow(row);
        ui->table_employes->setItem(row, 0, new QTableWidgetItem(query.value("ID_EMPLOYE").toString()));
        ui->table_employes->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->table_employes->setItem(row, 2, new QTableWidgetItem(query.value("PRENOM").toString()));
        ui->table_employes->setItem(row, 3, new QTableWidgetItem(query.value("AGE").toString()));
        ui->table_employes->setItem(row, 4, new QTableWidgetItem(query.value("POSTE").toString()));
        ui->table_employes->setItem(row, 5, new QTableWidgetItem(query.value("SALAIRE").toString()));
        ui->table_employes->setItem(row, 6, new QTableWidgetItem(query.value("ANCIENNETE").toString()));
        ui->table_employes->setItem(row, 7, new QTableWidgetItem(query.value("DISPONIBILITE").toString()));
        ui->table_employes->setItem(row, 8, new QTableWidgetItem(query.value("HEURES_TRAVAIL").toString()));
        ui->table_employes->setItem(row, 9, new QTableWidgetItem(query.value("FOURNISSEURS_TRAITES").toString()));
        ui->table_employes->setItem(row, 10, new QTableWidgetItem(query.value("ID_EQUIPE").toString()));
        row++;
    }
    
    qDebug() << "Résultats filtrés:" << row << "employés";
}

void MainWindow::reinitialiserFiltre()
{
    // Réinitialiser les champs de recherche
    ui->search_id->clear();
    ui->search_nom->clear();
    ui->search_id_equipe->clear();
    ui->search_spec->setCurrentIndex(0);
    
    // Réinitialiser les options de tri
    ui->sort_salaire->setChecked(false);
    ui->sort_anciennete->setChecked(false);
    ui->sort_heures->setChecked(false);
    ui->sort_fournisseurs->setChecked(false);
    ui->order_asc->setChecked(true);
    
    // Recharger la liste complète
    afficherEmployes();
}

void MainWindow::setupStatistiquesCharts()
{
    auto *topLayout = new QVBoxLayout(ui->frameStatsTopChart);
    topLayout->setContentsMargins(4, 4, 4, 4);
    statsTopChartView = new QChartView(ui->frameStatsTopChart);
    statsTopChartView->setRenderHint(QPainter::Antialiasing);
    topLayout->addWidget(statsTopChartView);

    auto *leftLayout = new QVBoxLayout(ui->frameStatsLeftChart);
    leftLayout->setContentsMargins(4, 4, 4, 4);
    statsLeftChartView = new QChartView(ui->frameStatsLeftChart);
    statsLeftChartView->setRenderHint(QPainter::Antialiasing);
    leftLayout->addWidget(statsLeftChartView);

    auto *rightLayout = new QVBoxLayout(ui->frameStatsRightChart);
    rightLayout->setContentsMargins(4, 4, 4, 4);
    statsRightChartView = new QChartView(ui->frameStatsRightChart);
    statsRightChartView->setRenderHint(QPainter::Antialiasing);
    rightLayout->addWidget(statsRightChartView);
}

void MainWindow::refreshStatistiques()
{
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

    // KPI principaux
    int totalEmployes = 0;
    double masseSalariale = 0.0;

    {
        QSqlQuery q;
        if (q.exec("SELECT COUNT(*), NVL(SUM(SALAIRE), 0) FROM EMPLOYE") && q.next()) {
            totalEmployes = q.value(0).toInt();
            masseSalariale = q.value(1).toDouble();
        }
    }

    const double salaireMoyen = totalEmployes > 0 ? (masseSalariale / totalEmployes) : 0.0;
    ui->label_total_employes->setText(QString("Nombre total d'employés : %1").arg(totalEmployes));
    ui->label_masse_salariale->setText(QString("Masse salariale totale : %1 €").arg(masseSalariale, 0, 'f', 2));
    ui->label_salaire_moyen->setText(QString("Salaire moyen : %1 €").arg(salaireMoyen, 0, 'f', 2));

    // Graphe haut: masse salariale par spécialité
    {
        QStringList categories;
        auto *setMasse = new QBarSet("Masse salariale");

        QSqlQuery q;
        q.exec("SELECT POSTE, NVL(SUM(SALAIRE),0) AS MASSE FROM EMPLOYE GROUP BY POSTE ORDER BY POSTE");
        while (q.next()) {
            categories << q.value("POSTE").toString();
            *setMasse << q.value("MASSE").toDouble();
        }

        auto *series = new QBarSeries();
        series->append(setMasse);
        setMasse->setColor(greenPrimary);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Masse salariale par spécialité");
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

    // Graphe bas gauche: répartition des employés par spécialité
    {
        auto *series = new QPieSeries();
        QSqlQuery q;
        q.exec("SELECT POSTE, COUNT(*) AS TOTAL FROM EMPLOYE GROUP BY POSTE ORDER BY POSTE");
        while (q.next()) {
            series->append(q.value("POSTE").toString(), q.value("TOTAL").toDouble());
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
        chart->setTitle("Répartition des employés par spécialité");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(statsLeftChartView, chart);
    }

    // Graphe bas droite: top employés par fournisseurs traités
    {
        QStringList categories;
        auto *setTop = new QBarSet("Fournisseurs traités");

        QSqlQuery q;
         q.exec("SELECT NVL(NOM,'') || ' ' || NVL(PRENOM,'') AS LIBELLE, NVL(FOURNISSEURS_TRAITES,0) AS FOURNISSEURS_TRAITES FROM ("
             "SELECT NOM, PRENOM, FOURNISSEURS_TRAITES FROM EMPLOYE ORDER BY FOURNISSEURS_TRAITES DESC"
               ") WHERE ROWNUM <= 5");
        while (q.next()) {
            categories << q.value("LIBELLE").toString();
            *setTop << q.value("FOURNISSEURS_TRAITES").toDouble();
        }

        auto *series = new QBarSeries();
        series->append(setTop);
        setTop->setColor(greenSecondary);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Top employés par fournisseurs traités");
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
        "Exporter la liste complète en PDF",
        defaultName,
        "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }

    QSqlQuery query;
    if (!query.exec("SELECT ID_EMPLOYE, NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE FROM EMPLOYE ORDER BY ID_EMPLOYE")) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les employés pour export :\n" + query.lastError().text());
        return;
    }

    QString html;
    html += "<h2>Liste complète des employés</h2>";
    html += "<p>Généré le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>ID</th><th>Nom</th><th>Prénom</th><th>Âge</th><th>Poste</th><th>Salaire</th><th>Ancienneté</th><th>Disponibilité</th><th>Heures</th><th>Fournisseurs</th><th>ID Equipe</th></tr>";

    int count = 0;
    while (query.next()) {
        html += "<tr>";
        html += "<td>" + query.value("ID_EMPLOYE").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("NOM").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("PRENOM").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("AGE").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("POSTE").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("SALAIRE").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("ANCIENNETE").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("DISPONIBILITE").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("HEURES_TRAVAIL").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("FOURNISSEURS_TRAITES").toString().toHtmlEscaped() + "</td>";
        html += "<td>" + query.value("ID_EQUIPE").toString().toHtmlEscaped() + "</td>";
        html += "</tr>";
        ++count;
    }
    html += "</table>";

    if (count == 0) {
        QMessageBox::warning(this, "Export PDF", "Aucun employé à exporter.");
        return;
    }

    QTextDocument document;
    document.setHtml(html);

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));
    document.print(&writer);

    emit exportListeRequested();
    QMessageBox::information(this, "Export PDF", "Liste exportée avec succès :\n" + filePath);
}

void MainWindow::exporterFicheEmployePdf()
{
    const QString id = ui->lineEdit_id_export->text().trimmed();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Export PDF", "Veuillez saisir un ID employé.");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT ID_EMPLOYE, NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES, ID_EQUIPE FROM EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id.toInt());

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Erreur SQL pendant l'export :\n" + query.lastError().text());
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "Export PDF", "Aucun employé trouvé avec cet ID.");
        return;
    }

    const QString defaultName = QString("fiche_employe_%1_%2.pdf")
                                    .arg(id)
                                    .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
    const QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter la fiche employé en PDF",
        defaultName,
        "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }

    QString html;
    html += "<h2>Fiche Employé</h2>";
    html += "<p>Généré le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='6'>";
    html += "<tr><td><b>ID</b></td><td>" + query.value("ID_EMPLOYE").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Nom</b></td><td>" + query.value("NOM").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Prénom</b></td><td>" + query.value("PRENOM").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Âge</b></td><td>" + query.value("AGE").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Poste</b></td><td>" + query.value("POSTE").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Salaire</b></td><td>" + query.value("SALAIRE").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Ancienneté</b></td><td>" + query.value("ANCIENNETE").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Disponibilité</b></td><td>" + query.value("DISPONIBILITE").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Heures</b></td><td>" + query.value("HEURES_TRAVAIL").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Fournisseurs</b></td><td>" + query.value("FOURNISSEURS_TRAITES").toString().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>ID Equipe</b></td><td>" + query.value("ID_EQUIPE").toString().toHtmlEscaped() + "</td></tr>";
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

    emit exportFicheRequested();
    QMessageBox::information(this, "Export PDF", "Fiche employé exportée avec succès :\n" + filePath);
}
