#include "employe_widget.h"
#include "ui_employe_widget.h"
#include <QTabBar>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <QMessageBox>
#include <QDebug>

EmployeWidget::EmployeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::EmployeWidget)
{
    ui->setupUi(this);
    
    // Default to Connexion tab on startup
    setAuthenticated(false);

    // Style spinbox and combobox to make arrows visible
    styleSpinboxesAndComboboxes();
    
    // Setup CRUD connections
    setupCrudConnections();

    // UI-only: connect internal buttons to signals (no business logic)
    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &EmployeWidget::exportListeRequested);
    connect(ui->btnExportRapportRH, &QPushButton::clicked, this, &EmployeWidget::exportRapportRHRequested);
    connect(ui->btnExportFicheEmploye, &QPushButton::clicked, this, &EmployeWidget::exportFicheRequested);
    // Connexions pour l'authentification et la réinitialisation de mot de passe (UI-only)
    connect(ui->btnSeConnecter, &QPushButton::clicked, this, [this]() {
        emit loginRequested(ui->line_user_conn->text(), ui->line_pass_conn->text());
    });
    // Navigue vers l'onglet Mot de passe oublié
    connect(ui->btnNavigateForgot, &QPushButton::clicked, this, [this]() {
        const int forgotIdx = ui->tabWidget->indexOf(ui->tabMotPasseOublie);
        if (forgotIdx != -1) {
            ui->tabWidget->setCurrentIndex(forgotIdx);
        }
    });
    // Envoyer code pour réinitialisation
    connect(ui->btnEnvoyerCode, &QPushButton::clicked, this, [this]() {
        emit forgotSendCodeRequested(ui->line_user_email_fp->text());
    });
    // Réinitialiser mot de passe (étape 2)
    connect(ui->btnResetPassword, &QPushButton::clicked, this, [this]() {
        emit resetPasswordRequested(ui->line_code_fp->text(), ui->line_newpass_fp->text());
    });
    // Retour à l'onglet Connexion
    connect(ui->btnBackToLogin, &QPushButton::clicked, this, [this]() {
        const int loginIdx = ui->tabWidget->indexOf(ui->tabConnexion);
        if (loginIdx != -1) {
            ui->tabWidget->setCurrentIndex(loginIdx);
        }
    });
}

EmployeWidget::~EmployeWidget()
{
    delete ui;
}
void EmployeWidget::styleSpinboxesAndComboboxes()
{
    // The QSS stylesheet now handles arrow display with SVG images
    // This function is kept for future customizations if needed
}

void EmployeWidget::setAuthenticated(bool authenticated)
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
        
        // Charger la liste des employés après connexion
        afficherEmployes();
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
void EmployeWidget::setupCrudConnections()
{
    // Bouton Ajouter
    connect(ui->btnAjouter, &QPushButton::clicked, this, &EmployeWidget::ajouterEmploye);
    
    // Bouton Supprimer
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &EmployeWidget::supprimerEmploye);
    
    // Bouton Modifier
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &EmployeWidget::modifierEmploye);
    
    // Clic sur une ligne du tableau
    connect(ui->table_employes, &QTableWidget::cellClicked, this, &EmployeWidget::onTableRowClicked);
}

// ============================================================================
// CREATE - Ajouter un employé
// ============================================================================
void EmployeWidget::ajouterEmploye()
{
    if (!validateAjouterForm()) {
        return;
    }
    
    QSqlQuery query;
    QString idEquipe = ui->lineEdit_id_equipe->text().trimmed();
    
    // Vérifier si l'équipe existe (si spécifiée)
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
        // Sans ID_EQUIPE (sera NULL) - ID_EMPLOYE auto-incrémenté
        query.prepare("INSERT INTO EMPLOYE (NOM, PRENOM, AGE, POSTE, SALAIRE, ANCIENNETE, DISPONIBILITE, HEURES_TRAVAIL, FOURNISSEURS_TRAITES) "
                      "VALUES (:nom, :prenom, :age, :poste, :salaire, :anciennete, :disp, :heures, :fourn)");
    } else {
        // Avec ID_EQUIPE - ID_EMPLOYE auto-incrémenté
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
        emit addRequested(); // Signal pour notifier
    } else {
        QMessageBox::critical(this, "Erreur", 
            "Erreur lors de l'ajout:\n" + query.lastError().text());
    }
}

bool EmployeWidget::validateAjouterForm()
{
    if (ui->lineEdit_nom->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire.");
        return false;
    }
    if (ui->lineEdit_prenom->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le prénom est obligatoire.");
        return false;
    }
    return true;
}

void EmployeWidget::clearAjouterForm()
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
// READ - Afficher la liste des employés
// ============================================================================
void EmployeWidget::afficherEmployes()
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
// UPDATE - Modifier un employé
// ============================================================================
void EmployeWidget::chargerEmployePourModification()
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

void EmployeWidget::modifierEmploye()
{
    if (!validateModifierForm()) {
        return;
    }
    
    QSqlQuery query;
    QString idEquipeMod = ui->lineEdit_id_equipe_mod->text().trimmed();
    
    // Vérifier si l'équipe existe (si spécifiée)
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
            emit updateRequested(); // Signal pour notifier
        } else {
            QMessageBox::warning(this, "Attention", "Aucun employé trouvé avec cet ID.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", 
            "Erreur lors de la modification:\n" + query.lastError().text());
    }
}

bool EmployeWidget::validateModifierForm()
{
    if (ui->lineEdit_id_mod->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "L'ID est obligatoire.");
        return false;
    }
    if (ui->lineEdit_nom_mod->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom est obligatoire.");
        return false;
    }
    if (ui->lineEdit_prenom_mod->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le prénom est obligatoire.");
        return false;
    }
    return true;
}

void EmployeWidget::clearModifierForm()
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
// DELETE - Supprimer un employé
// ============================================================================
void EmployeWidget::supprimerEmploye()
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
void EmployeWidget::onTableRowClicked(int row, int column)
{
    Q_UNUSED(column);
    
    // Récupérer toutes les données de la ligne cliquée
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