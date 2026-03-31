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
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QMessageBox>

MachineWidget::MachineWidget(QWidget *parent) : QWidget(parent)
{
    setupUi();
    setupConnections();
}

MachineWidget::~MachineWidget()
{
}

void MachineWidget::setupUi()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setSpacing(20);
    mainLayout->setContentsMargins(20, 20, 20, 20);
    
    // ===== TITRE =====
    QLabel *titleLabel = new QLabel("GESTION DES MACHINES");
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
    
    // ===== FORMULAIRE EN 2 COLONNES =====
    QGridLayout *formLayout = new QGridLayout();
    formLayout->setHorizontalSpacing(30);
    formLayout->setVerticalSpacing(15);
    
    // ID Machine
    formLayout->addWidget(new QLabel("ID Machine *"), 0, 0);
    m_idEdit = new QLineEdit();
    m_idEdit->setPlaceholderText("Ex: MCH-001");
    m_idEdit->setToolTip("Format: MCH-XXX (X = chiffres)");
    formLayout->addWidget(m_idEdit, 0, 1);
    
    // Nom
    formLayout->addWidget(new QLabel("Nom *"), 1, 0);
    m_nomEdit = new QLineEdit();
    m_nomEdit->setPlaceholderText("Nom de la machine");
    formLayout->addWidget(m_nomEdit, 1, 1);
    
    // Catégorie
    formLayout->addWidget(new QLabel("Catégorie *"), 2, 0);
    m_categorieCombo = new QComboBox();
    m_categorieCombo->addItems({"Presse", "Moteur", "Filtre", "Capteur", "Compresseur", "Pompe", "Autre"});
    formLayout->addWidget(m_categorieCombo, 2, 1);
    
    // Référence
    formLayout->addWidget(new QLabel("Référence *"), 3, 0);
    m_referenceEdit = new QLineEdit();
    m_referenceEdit->setPlaceholderText("Réf. constructeur");
    formLayout->addWidget(m_referenceEdit, 3, 1);
    
    // Date d'achat
    formLayout->addWidget(new QLabel("Date d'achat *"), 4, 0);
    m_dateAchatEdit = new QDateEdit();
    m_dateAchatEdit->setDate(QDate::currentDate());
    m_dateAchatEdit->setCalendarPopup(true);
    m_dateAchatEdit->setDisplayFormat("dd/MM/yyyy");
    formLayout->addWidget(m_dateAchatEdit, 4, 1);
    
    // État
    formLayout->addWidget(new QLabel("État *"), 5, 0);
    m_etatCombo = new QComboBox();
    m_etatCombo->addItems({"En service", "En maintenance", "En panne", "Hors service"});
    formLayout->addWidget(m_etatCombo, 5, 1);
    
    // Localisation
    formLayout->addWidget(new QLabel("Localisation"), 6, 0);
    m_localisationEdit = new QLineEdit();
    m_localisationEdit->setPlaceholderText("Atelier, Ligne de production...");
    formLayout->addWidget(m_localisationEdit, 6, 1);
    
    // Note pour les champs obligatoires
    QLabel *requiredNote = new QLabel("* Champs obligatoires");
    requiredNote->setStyleSheet("color: #C97A7A; font-size: 10px;");
    formLayout->addWidget(requiredNote, 7, 0, 1, 2);
    
    scrollLayout->addLayout(formLayout);
    
    // ===== TABLEAU POUR AFFICHER LA LISTE DES MACHINES =====
    QLabel *listTitle = new QLabel("Liste des machines");
    listTitle->setStyleSheet("font-weight: bold; color: #798777; margin-top: 20px;");
    scrollLayout->addWidget(listTitle);
    
    m_tableWidget = new QTableWidget();
    m_tableWidget->setColumnCount(7);
    m_tableWidget->setHorizontalHeaderLabels({"ID", "Nom", "Catégorie", "Référence", "Date d'achat", "État", "Localisation"});
    m_tableWidget->horizontalHeader()->setStretchLastSection(true);
    m_tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    m_tableWidget->setAlternatingRowColors(true);
    scrollLayout->addWidget(m_tableWidget);
    
    scrollLayout->addStretch();
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);
    
    // ===== BOUTONS D'ACTION =====
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->setSpacing(10);
    
    QPushButton *btnAjouter = new QPushButton("Ajouter");
    QPushButton *btnModifier = new QPushButton("Modifier");
    QPushButton *btnSupprimer = new QPushButton("Supprimer");
    QPushButton *btnActualiser = new QPushButton("Actualiser");
    QPushButton *btnVider = new QPushButton("Vider formulaire");
    
    QString buttonStyle = "QPushButton { padding: 10px 15px; border-radius: 5px; font-weight: bold; min-width: 120px; }";
    btnAjouter->setStyleSheet(buttonStyle + "background-color: #6FA66F; color: white;");
    btnModifier->setStyleSheet(buttonStyle + "background-color: #E6C36A; color: black;");
    btnSupprimer->setStyleSheet(buttonStyle + "background-color: #C97A7A; color: white;");
    btnActualiser->setStyleSheet(buttonStyle + "background-color: #A2B29F; color: white;");
    btnVider->setStyleSheet(buttonStyle + "background-color: #798777; color: white;");
    
    buttonLayout->addWidget(btnAjouter);
    buttonLayout->addWidget(btnModifier);
    buttonLayout->addWidget(btnSupprimer);
    buttonLayout->addWidget(btnActualiser);
    buttonLayout->addWidget(btnVider);
    
    mainLayout->addLayout(buttonLayout);
    
    // ===== BOUTON QUITTER =====
    QHBoxLayout *quitLayout = new QHBoxLayout();
    quitLayout->addStretch();
    QPushButton *btnQuitter = new QPushButton("QUITTER");
    btnQuitter->setStyleSheet("QPushButton { background-color: #C97A7A; color: white; padding: 8px 30px; border-radius: 5px; font-weight: bold; }");
    quitLayout->addWidget(btnQuitter);
    quitLayout->addStretch();
    mainLayout->addLayout(quitLayout);
    
    // ===== CONNEXIONS DES BOUTONS =====
    connect(btnAjouter, &QPushButton::clicked, this, &MachineWidget::onAddClicked);
    connect(btnModifier, &QPushButton::clicked, this, &MachineWidget::onUpdateClicked);
    connect(btnSupprimer, &QPushButton::clicked, this, &MachineWidget::onDeleteClicked);
    connect(btnActualiser, &QPushButton::clicked, this, &MachineWidget::historiqueRequested);
    connect(btnVider, &QPushButton::clicked, this, &MachineWidget::clearForm);
    connect(btnQuitter, &QPushButton::clicked, qApp, &QApplication::quit);
}

void MachineWidget::setupConnections()
{
    connect(m_tableWidget, &QTableWidget::itemClicked, this, [this](QTableWidgetItem *item) {
        if (item) {
            int row = item->row();
            QString id = m_tableWidget->item(row, 0)->text();
            emit machineSelected(id);
        }
    });
}

QString MachineWidget::getId() const { return m_idEdit->text().trimmed(); }
QString MachineWidget::getNom() const { return m_nomEdit->text().trimmed(); }
QString MachineWidget::getCategorie() const { return m_categorieCombo->currentText(); }
QString MachineWidget::getReference() const { return m_referenceEdit->text().trimmed(); }
QString MachineWidget::getDateAchat() const { return m_dateAchatEdit->date().toString("dd/MM/yyyy"); }
QString MachineWidget::getEtat() const { return m_etatCombo->currentText(); }
QString MachineWidget::getLocalisation() const { return m_localisationEdit->text().trimmed(); }

bool MachineWidget::validateForm()
{
    if (getId().isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "L'ID machine est obligatoire");
        m_idEdit->setFocus();
        return false;
    }
    
    // Validation du format ID (MCH-XXX)
    QString id = getId();
    if (!id.startsWith("MCH-") || id.length() != 7) {
        QMessageBox::warning(this, "Format ID invalide", "L'ID doit être au format MCH-XXX (ex: MCH-001)");
        m_idEdit->setFocus();
        return false;
    }
    
    // Vérifier que les 3 derniers caractères sont des chiffres
    QString numPart = id.mid(4);
    bool ok;
    numPart.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Format ID invalide", "L'ID doit être au format MCH-XXX (ex: MCH-001)");
        m_idEdit->setFocus();
        return false;
    }
    
    if (getNom().isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "Le nom de la machine est obligatoire");
        m_nomEdit->setFocus();
        return false;
    }
    
    if (getReference().isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "La référence est obligatoire");
        m_referenceEdit->setFocus();
        return false;
    }
    
    return true;
}

void MachineWidget::clearForm()
{
    m_idEdit->clear();
    m_nomEdit->clear();
    m_categorieCombo->setCurrentIndex(0);
    m_referenceEdit->clear();
    m_dateAchatEdit->setDate(QDate::currentDate());
    m_etatCombo->setCurrentIndex(0);
    m_localisationEdit->clear();
    m_idEdit->setFocus();
}

void MachineWidget::setMachineData(const QString& id, const QString& nom, const QString& categorie,
                                    const QString& reference, const QString& dateAchat,
                                    const QString& etat, const QString& localisation)
{
    m_idEdit->setText(id);
    m_nomEdit->setText(nom);
    
    int catIndex = m_categorieCombo->findText(categorie);
    if (catIndex >= 0) m_categorieCombo->setCurrentIndex(catIndex);
    
    m_referenceEdit->setText(reference);
    m_dateAchatEdit->setDate(QDate::fromString(dateAchat, "dd/MM/yyyy"));
    
    int etatIndex = m_etatCombo->findText(etat);
    if (etatIndex >= 0) m_etatCombo->setCurrentIndex(etatIndex);
    
    m_localisationEdit->setText(localisation);
}

void MachineWidget::setMachinesList(const QList<QVariantMap>& machines)
{
    m_tableWidget->setRowCount(machines.size());
    
    for (int i = 0; i < machines.size(); ++i) {
        const QVariantMap& m = machines[i];
        m_tableWidget->setItem(i, 0, new QTableWidgetItem(m["id"].toString()));
        m_tableWidget->setItem(i, 1, new QTableWidgetItem(m["nom"].toString()));
        m_tableWidget->setItem(i, 2, new QTableWidgetItem(m["categorie"].toString()));
        m_tableWidget->setItem(i, 3, new QTableWidgetItem(m["reference"].toString()));
        m_tableWidget->setItem(i, 4, new QTableWidgetItem(m["date_achat"].toString()));
        m_tableWidget->setItem(i, 5, new QTableWidgetItem(m["etat"].toString()));
        m_tableWidget->setItem(i, 6, new QTableWidgetItem(m["localisation"].toString()));
    }
    
    m_tableWidget->resizeColumnsToContents();
}

void MachineWidget::onAddClicked()
{
    if (validateForm()) {
        emit addRequested();
    }
}

void MachineWidget::onUpdateClicked()
{
    if (validateForm()) {
        emit updateRequested();
    }
}

void MachineWidget::onDeleteClicked()
{
    if (getId().isEmpty()) {
        QMessageBox::warning(this, "Sélection requise", "Veuillez sélectionner une machine à supprimer ou saisir son ID");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation suppression",
        QString("Voulez-vous vraiment supprimer la machine %1 ?").arg(getId()),
        QMessageBox::Yes | QMessageBox::No);
        
    if (reply == QMessageBox::Yes) {
        emit deleteRequested();
    }
}

void MachineWidget::onHistoriqueClicked()
{
    emit historiqueRequested();
}

void MachineWidget::setAuthenticated(bool authenticated)
{
    Q_UNUSED(authenticated);
}

void MachineWidget::styleSpinboxesAndComboboxes()
{
    // Géré par le QSS
}