#include "machine_widget.h"
#include "ui_machine_widget.h"
#include <QDate>

MachineWidget::MachineWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MachineWidget)
{
    ui->setupUi(this);

    // Initialiser les dates
    ui->dateAddAchat->setDate(QDate::currentDate());
    ui->dateModifierAchat->setDate(QDate::currentDate());
    ui->datePanne->setDate(QDate::currentDate());

    // Connexions pour Ajouter
    connect(ui->btnConfirmerAjouter, &QPushButton::clicked, this, [this]() {
        // TODO: Implémenter l'ajout
    });
    connect(ui->btnAnnulerAjouter, &QPushButton::clicked, this, [this]() {
        ui->editAddId->clear();
        ui->editAddNom->clear();
        ui->editAddReference->clear();
        ui->editAddLocalisation->clear();
        ui->comboAddCategorie->setCurrentIndex(0);
        ui->comboAddEtat->setCurrentIndex(0);
    });

    // Connexions pour Modifier
    connect(ui->btnConfirmerModifier, &QPushButton::clicked, this, [this]() {
        // TODO: Implémenter la modification
    });
    connect(ui->btnAnnulerModifier, &QPushButton::clicked, this, [this]() {
        ui->editModifierId->clear();
        ui->editModifierNom->clear();
        ui->editModifierReference->clear();
        ui->editModifierLocalisation->clear();
    });

    // Connexions pour Supprimer
    connect(ui->btnConfirmerSupprimer, &QPushButton::clicked, this, [this]() {
        // TODO: Implémenter la suppression
    });
    connect(ui->btnAnnulerSupprimer, &QPushButton::clicked, this, [this]() {
        ui->lblSupprimerNom->setText("Aucune machine sélectionnée");
        ui->lblSupprimerDetails->setText("-");
    });

    // Connexions pour Signaler Panne
    connect(ui->btnSignalerPanne, &QPushButton::clicked, this, [this]() {
        // TODO: Implémenter le signalement de panne
    });
    connect(ui->btnAnnulerPanne, &QPushButton::clicked, this, [this]() {
        ui->txtDescriptionPanne->clear();
        ui->comboPanneMachine->setCurrentIndex(0);
        ui->comboTypePanne->setCurrentIndex(0);
        ui->comboGravite->setCurrentIndex(0);
    });

    // Connexions pour actions diverses
    connect(ui->btnApplyFilter, &QPushButton::clicked, this, [this]() {
        // TODO: Appliquer les filtres
    });

    connect(ui->btnExportPDF, &QPushButton::clicked, this, [this]() {
        // TODO: Export PDF liste
    });

    connect(ui->btnRefresh, &QPushButton::clicked, this, [this]() {
        // TODO: Actualiser la liste
    });

    connect(ui->btnScanQR, &QPushButton::clicked, this, [this]() {
        // TODO: Scanner QR code
    });
}

MachineWidget::~MachineWidget()
{
    delete ui;
}

void MachineWidget::setAuthenticated(bool authenticated)
{
    Q_UNUSED(authenticated);
}