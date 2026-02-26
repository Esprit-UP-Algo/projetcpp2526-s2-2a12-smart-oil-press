#include "machine_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QDateEdit>
#include <QPushButton>
#include <QScrollArea>
#include <QFrame>
#include <QApplication>
#include <QDate>

MachineWidget::MachineWidget(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    
    // ===== TITRE "MACHINE" =====
    QLabel *titleLabel = new QLabel("MACHINE");
    titleLabel->setStyleSheet("font-size: 28px; font-weight: bold; color: #798777; margin: 10px;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);
    
    // ===== LIGNE DE SÉPARATION =====
    QFrame *line = new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setStyleSheet("background-color: #BDD2B6; max-height: 2px;");
    mainLayout->addWidget(line);
    
    // ===== ZONE DE SCROLL =====
    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setFrameShape(QFrame::NoFrame);
    
    QWidget *scrollContent = new QWidget();
    QVBoxLayout *scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setSpacing(15);
    
    // ===== GRILLE PRINCIPALE (2 COLONNES) =====
    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setHorizontalSpacing(30);
    gridLayout->setVerticalSpacing(15);
    
    // ===== COLONNE GAUCHE =====
    gridLayout->addWidget(new QLabel("ID Machine"), 0, 0);
    QLineEdit *idEdit = new QLineEdit();
    idEdit->setPlaceholderText("ID");
    gridLayout->addWidget(idEdit, 0, 1);
    
    gridLayout->addWidget(new QLabel("Nom"), 1, 0);
    QLineEdit *nomEdit = new QLineEdit();
    nomEdit->setPlaceholderText("Nom");
    gridLayout->addWidget(nomEdit, 1, 1);
    
    gridLayout->addWidget(new QLabel("Modèle"), 2, 0);
    QLineEdit *modeleEdit = new QLineEdit();
    modeleEdit->setPlaceholderText("Modèle");
    gridLayout->addWidget(modeleEdit, 2, 1);
    
    gridLayout->addWidget(new QLabel("Marque"), 3, 0);
    QLineEdit *marqueEdit = new QLineEdit();
    marqueEdit->setPlaceholderText("Marque");
    gridLayout->addWidget(marqueEdit, 3, 1);
    
    gridLayout->addWidget(new QLabel("Type"), 4, 0);
    QComboBox *typeCombo = new QComboBox();
    typeCombo->addItems({"Presse", "Moteur", "Filtre", "Capteur", "Autre"});
    gridLayout->addWidget(typeCombo, 4, 1);
    
    gridLayout->addWidget(new QLabel("Localisation"), 5, 0);
    QLineEdit *localisationEdit = new QLineEdit();
    localisationEdit->setPlaceholderText("Atelier, Ligne...");
    gridLayout->addWidget(localisationEdit, 5, 1);
    
    gridLayout->addWidget(new QLabel("Date installation"), 6, 0);
    QDateEdit *dateInstallEdit = new QDateEdit();
    dateInstallEdit->setDate(QDate::currentDate());
    dateInstallEdit->setCalendarPopup(true);
    gridLayout->addWidget(dateInstallEdit, 6, 1);
    
    // ===== COLONNE DROITE =====
    QLabel *etatTitle = new QLabel("ÉTAT");
    etatTitle->setStyleSheet("font-weight: bold; color: #798777;");
    gridLayout->addWidget(etatTitle, 0, 2);
    
    gridLayout->setColumnMinimumWidth(2, 150);
    
    gridLayout->addWidget(new QLabel("État"), 1, 2);
    QComboBox *etatCombo = new QComboBox();
    etatCombo->addItems({"En service", "En maintenance", "En panne", "Hors service"});
    gridLayout->addWidget(etatCombo, 1, 3);
    
    gridLayout->addWidget(new QLabel("Dernière maintenance"), 2, 2);
    QDateEdit *derniereMaintEdit = new QDateEdit();
    derniereMaintEdit->setDate(QDate::currentDate().addMonths(-3));
    derniereMaintEdit->setCalendarPopup(true);
    gridLayout->addWidget(derniereMaintEdit, 2, 3);
    
    gridLayout->addWidget(new QLabel("Prochaine maintenance"), 3, 2);
    QDateEdit *prochaineMaintEdit = new QDateEdit();
    prochaineMaintEdit->setDate(QDate::currentDate().addMonths(3));
    prochaineMaintEdit->setCalendarPopup(true);
    gridLayout->addWidget(prochaineMaintEdit, 3, 3);
    
    QLabel *maintenanceTitle = new QLabel("MAINTENANCE");
    maintenanceTitle->setStyleSheet("font-weight: bold; color: #798777;");
    gridLayout->addWidget(maintenanceTitle, 4, 2);
    
    gridLayout->addWidget(new QLabel("Fréquence (jours)"), 5, 2);
    QSpinBox *frequenceSpin = new QSpinBox();
    frequenceSpin->setRange(0, 365);
    frequenceSpin->setValue(90);
    gridLayout->addWidget(frequenceSpin, 5, 3);
    
    QLabel *panneTitle = new QLabel("PANNE");
    panneTitle->setStyleSheet("font-weight: bold; color: #798777;");
    gridLayout->addWidget(panneTitle, 6, 2);
    
    gridLayout->addWidget(new QLabel("Nombre de pannes"), 7, 2);
    QSpinBox *nbPannesSpin = new QSpinBox();
    nbPannesSpin->setRange(0, 100);
    nbPannesSpin->setValue(0);
    gridLayout->addWidget(nbPannesSpin, 7, 3);
    
    gridLayout->addWidget(new QLabel("Temps d'arrêt (h)"), 8, 2);
    QDoubleSpinBox *tempsArretSpin = new QDoubleSpinBox();
    tempsArretSpin->setRange(0, 1000);
    tempsArretSpin->setValue(0);
    gridLayout->addWidget(tempsArretSpin, 8, 3);
    
    scrollLayout->addLayout(gridLayout);
    scrollLayout->addStretch();
    
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);
    
    // ===== BOUTONS DU BAS =====
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);
    
    QPushButton *btnAjouter = new QPushButton("Ajouter une machine");
    QPushButton *btnListe = new QPushButton("Liste des machines");
    QPushButton *btnSupprimer = new QPushButton("Supprimer une machine");
    QPushButton *btnModifier = new QPushButton("Modifier une machine");
    QPushButton *btnMaintenance = new QPushButton("Maintenance");
    QPushButton *btnExport = new QPushButton("Export PDF");
    
    QString buttonStyle = "QPushButton { padding: 10px 15px; border-radius: 5px; font-weight: bold; min-width: 120px; }";
    btnAjouter->setStyleSheet(buttonStyle + "background-color: #6FA66F; color: white;");
    btnListe->setStyleSheet(buttonStyle + "background-color: #A2B29F; color: white;");
    btnSupprimer->setStyleSheet(buttonStyle + "background-color: #C97A7A; color: white;");
    btnModifier->setStyleSheet(buttonStyle + "background-color: #E6C36A; color: black;");
    btnMaintenance->setStyleSheet(buttonStyle + "background-color: #7DA3A1; color: white;");
    btnExport->setStyleSheet(buttonStyle + "background-color: #798777; color: white;");
    
    buttonLayout->addWidget(btnAjouter);
    buttonLayout->addWidget(btnListe);
    buttonLayout->addWidget(btnSupprimer);
    buttonLayout->addWidget(btnModifier);
    buttonLayout->addWidget(btnMaintenance);
    buttonLayout->addWidget(btnExport);
    
    mainLayout->addLayout(buttonLayout);
    
    // ===== BOUTON QUITTER =====
    QHBoxLayout *quitLayout = new QHBoxLayout();
    quitLayout->addStretch();
    QPushButton *btnQuitter = new QPushButton("QUITTER");
    btnQuitter->setStyleSheet("QPushButton { background-color: #C97A7A; color: white; padding: 8px 30px; border-radius: 5px; font-weight: bold; }");
    quitLayout->addWidget(btnQuitter);
    quitLayout->addStretch();
    mainLayout->addLayout(quitLayout);
    
    // ===== CONNEXIONS DES SIGNAUX =====
    connect(btnAjouter, &QPushButton::clicked, this, &MachineWidget::addRequested);
    connect(btnListe, &QPushButton::clicked, this, &MachineWidget::historiqueRequested);
    connect(btnSupprimer, &QPushButton::clicked, this, &MachineWidget::deleteRequested);
    connect(btnModifier, &QPushButton::clicked, this, &MachineWidget::updateRequested);
    connect(btnMaintenance, &QPushButton::clicked, this, &MachineWidget::maintenanceRequested);
    connect(btnExport, &QPushButton::clicked, this, &MachineWidget::exportListeRequested);
    connect(btnQuitter, &QPushButton::clicked, qApp, &QApplication::quit);
}

MachineWidget::~MachineWidget()
{
}

void MachineWidget::styleSpinboxesAndComboboxes()
{
    // Géré par le QSS
}

void MachineWidget::setAuthenticated(bool authenticated)
{
    Q_UNUSED(authenticated);
}