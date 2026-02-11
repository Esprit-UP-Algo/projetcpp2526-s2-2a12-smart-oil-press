#include "employe_widget.h"
#include "ui_employe_widget.h"

EmployeWidget::EmployeWidget(QWidget *parent) : QWidget(parent), ui(new Ui::EmployeWidget)
{
    ui->setupUi(this);
    
    // Default to Connexion tab on startup
    setAuthenticated(false);

    // Style spinbox and combobox to make arrows visible
    styleSpinboxesAndComboboxes();
    
    // UI-only: connect internal buttons to signals (no business logic)
    connect(ui->btnAjouter, &QPushButton::clicked, this, &EmployeWidget::addRequested);
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &EmployeWidget::deleteRequested);
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &EmployeWidget::updateRequested);
    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &EmployeWidget::exportListeRequested);
    connect(ui->btnExportRapportRH, &QPushButton::clicked, this, &EmployeWidget::exportRapportRHRequested);
    connect(ui->btnExportFicheEmploye, &QPushButton::clicked, this, &EmployeWidget::exportFicheRequested);
    // Connexions pour l'authentification et la réinitialisation de mot de passe (UI-only)
    connect(ui->btnSeConnecter, &QPushButton::clicked, this, [this]() {
        emit loginRequested(ui->line_user_conn->text(), ui->line_pass_conn->text());
    });
    // Navigue vers l'onglet Mot de passe oublié
    connect(ui->btnNavigateForgot, &QPushButton::clicked, this, [this]() {
        int idx = ui->tabWidget->indexOf(ui->tabMotPasseOublie);
        if (idx != -1) {
            ui->tabWidget->setCurrentIndex(idx);
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
        int idx = ui->tabWidget->indexOf(ui->tabConnexion);
        if (idx != -1) {
            ui->tabWidget->setCurrentIndex(idx);
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
    } else {
        setTabVisible(ui->tabAjouter, false);
        setTabVisible(ui->tabListe, false);
        setTabVisible(ui->tabSupprimer, false);
        setTabVisible(ui->tabModifier, false);
        setTabVisible(ui->tabStatistiques, false);
        setTabVisible(ui->tabExportPdf, false);
        setTabVisible(ui->tabConnexion, true);
        // Keep hidden from tab bar but allow navigation via button
        setTabVisible(ui->tabMotPasseOublie, false);

        const int idx = ui->tabWidget->indexOf(ui->tabConnexion);
        if (idx != -1) {
            ui->tabWidget->setCurrentIndex(idx);
        }
    }
}