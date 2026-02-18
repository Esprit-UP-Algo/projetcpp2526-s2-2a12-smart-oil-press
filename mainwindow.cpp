#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    // Charge le stylesheet
    loadStylesheet();
    
    // Charge le logo
    loadLogo();
    
    // Connecte les onglets aux pages correspondantes
    setupTabConnections();
    
    // Configure les pages vides pour géolocalisation et IA
    setupEmptyPages();
    
    // Remplit la table avec des données exemple
    populateTableWithSampleData();
    
    // Affiche la page par défaut (liste des laboratoires)
    ui->stackedWidget->setCurrentWidget(ui->page_rech);
    
    qDebug() << "Application démarrée - Navigation entre onglets activée";
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ==================== STYLESHEET ====================
void MainWindow::loadStylesheet()
{
    QStringList paths = {
        ":/style/styles.qss",
        "style/styles.qss",
        "styles.qss"
    };
    
    for (const QString& path : paths) {
        QFile styleFile(path);
        if (styleFile.open(QFile::ReadOnly)) {
            QString styleSheet = QLatin1String(styleFile.readAll());
            this->setStyleSheet(styleSheet);
            styleFile.close();
            qDebug() << "✅ Stylesheet chargé depuis:" << path;
            qDebug() << "   Taille:" << styleSheet.length() << "caractères";
            return;
        } else {
            qDebug() << "❌ Échec de chargement depuis:" << path;
        }
    }
    
    qDebug() << "⚠️  Stylesheet non trouvé!";
}

// ==================== LOGO ====================
void MainWindow::loadLogo()
{
    if (!ui->logoLabel) return;
    
    QPixmap logoPixmap(":/images/logo.png");
    if (!logoPixmap.isNull()) {
        QPixmap scaledLogo = logoPixmap.scaled(
            ui->logoLabel->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        );
        ui->logoLabel->setPixmap(scaledLogo);
        ui->logoLabel->setAlignment(Qt::AlignCenter);
        qDebug() << "✅ Logo chargé";
    } else {
        qDebug() << "❌ Logo non trouvé";
    }
}

// ==================== DONNÉES EXEMPLE ====================
void MainWindow::populateTableWithSampleData()
{
    if (!ui->tableWidget) return;
    
    // Configure les en-têtes
    QStringList headers;
    headers << "ID Laboratoire" << "Nom" << "Type d'analyse" << "Conformité" << "Adresse" << "Espace";
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    
    // Ajoute des données exemple
    ui->tableWidget->setRowCount(5);
    
    QStringList ids = {"LAB001", "LAB002", "LAB003", "LAB004", "LAB005"};
    QStringList noms = {"Labo Central", "Labo Nord", "Labo Sud", "Labo Est", "Labo Ouest"};
    QStringList types = {"Chimique", "Bactériologique", "Physique", "Biologique", "Chimique"};
    QStringList conformites = {"Oui", "Oui", "Non", "Oui", "Non"};
    QStringList adresses = {"12 Rue de Paris", "45 Avenue Victor Hugo", "8 Boulevard Gambetta", 
                           "23 Rue Lafayette", "56 Rue Nationale"};
    QStringList espaces = {"150 m²", "200 m²", "120 m²", "180 m²", "90 m²"};
    
    for (int row = 0; row < 5; ++row) {
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(ids[row]));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(noms[row]));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(types[row]));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(conformites[row]));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(adresses[row]));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(espaces[row]));
    }
    
    // Ajuste les colonnes
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    
    qDebug() << "✅ Table remplie avec" << ui->tableWidget->rowCount() << "lignes";
}

// ==================== PAGES VIDES ====================
void MainWindow::setupEmptyPages()
{
    if (ui->tabGeolocalisation) {
        ui->tabGeolocalisation->setStyleSheet("background-color: #F8EDE3;");
    }
    
    if (ui->tabAIBot) {
        ui->tabAIBot->setStyleSheet("background-color: #F8EDE3;");
    }
}

// ==================== CONNEXIONS DES ONGLETS ====================
void MainWindow::setupTabConnections()
{
    // Connexion du changement d'onglet
    connect(ui->topNavTabs, &QTabWidget::currentChanged, this, [this](int index) {
        QString tabText = ui->topNavTabs->tabText(index);
        qDebug() << "Onglet sélectionné:" << tabText << "Index:" << index;
        
        // Cacher toutes les pages
        if (ui->page_rech) ui->page_rech->hide();
        if (ui->pageadd) ui->pageadd->hide();
        if (ui->pagesupp) ui->pagesupp->hide();
        if (ui->pagemodif) ui->pagemodif->hide();
        if (ui->page_stat) ui->page_stat->hide();
        if (ui->tabGeolocalisation) ui->tabGeolocalisation->hide();
        if (ui->tabAIBot) ui->tabAIBot->hide();
        
        // Afficher la page correspondante
        if (tabText.contains("Ajouter")) {
            ui->stackedWidget->setCurrentWidget(ui->pageadd);
            ui->pageadd->show();
            qDebug() << "→ Page: Ajouter";
        }
        else if (tabText.contains("Liste")) {
            ui->stackedWidget->setCurrentWidget(ui->page_rech);
            ui->page_rech->show();
            qDebug() << "→ Page: Liste";
        }
        else if (tabText.contains("Supprimer")) {
            ui->stackedWidget->setCurrentWidget(ui->pagesupp);
            ui->pagesupp->show();
            qDebug() << "→ Page: Supprimer";
        }
        else if (tabText.contains("Modifier")) {
            ui->stackedWidget->setCurrentWidget(ui->pagemodif);
            ui->pagemodif->show();
            qDebug() << "→ Page: Modifier";
        }
        else if (tabText.contains("Statistiques")) {
            ui->stackedWidget->setCurrentWidget(ui->page_stat);
            ui->page_stat->show();
            qDebug() << "→ Page: Statistiques";
        }
        else if (tabText.contains("Geolocalisation")) {
            ui->stackedWidget->setCurrentWidget(ui->tabGeolocalisation);
            ui->tabGeolocalisation->show();
            qDebug() << "→ Page: Géolocalisation";
        }
        else if (tabText.contains("Assistant IA")) {
            ui->stackedWidget->setCurrentWidget(ui->tabAIBot);
            ui->tabAIBot->show();
            qDebug() << "→ Page: Assistant IA";
        }
    });
    
    // === BOUTONS SIDEBAR ===
    if (ui->pushButton_3) {
        connect(ui->pushButton_3, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(this, "Information", "Page EMPLOYE - sera implémentée prochainement");
        });
    }
    
    if (ui->pushButton_4) {
        connect(ui->pushButton_4, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(this, "Information", "Page EQUIPE - sera implémentée prochainement");
        });
    }
    
    if (ui->pushButton_6) {
        connect(ui->pushButton_6, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(this, "Information", "Page CLIENT - sera implémentée prochainement");
        });
    }
    
    if (ui->pushButton_5) {
        connect(ui->pushButton_5, &QPushButton::clicked, this, [this]() {
            ui->topNavTabs->setCurrentWidget(ui->tabGestion);
        });
    }
    
    if (ui->pushButton_7) {
        connect(ui->pushButton_7, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(this, "Information", "Page COMMANDE - sera implémentée prochainement");
        });
    }
    
    if (ui->pushButton) {
        connect(ui->pushButton, &QPushButton::clicked, this, [this]() {
            QMessageBox::information(this, "Information", "Page MACHINE - sera implémentée prochainement");
        });
    }
    
    if (ui->quitButton) {
        connect(ui->quitButton, &QPushButton::clicked, this, &MainWindow::close);
    }
    
    // === BOUTONS DE RECHERCHE ET FILTRES ===
    if (ui->btnRechercher) {
        connect(ui->btnRechercher, &QPushButton::clicked, this, &MainWindow::rechercherLaboratoires);
    }
    
    if (ui->btnFiltre) {
        connect(ui->btnFiltre, &QPushButton::clicked, this, &MainWindow::filterLaboratoires);
    }
    
    if (ui->btnTrier) {
        connect(ui->btnTrier, &QPushButton::clicked, this, &MainWindow::trierLaboratoires);
    }
    
    if (ui->pushButton_25) {
        connect(ui->pushButton_25, &QPushButton::clicked, this, &MainWindow::exporterPDF);
    }
    
    if (ui->pushButton_29) {
        connect(ui->pushButton_29, &QPushButton::clicked, this, &MainWindow::rechercherSuggestions);
    }
    
    // === NOUVEAU BOUTON EXPORT PDF DANS LA LISTE ===
    if (ui->btnExportPDF) {
        connect(ui->btnExportPDF, &QPushButton::clicked, this, &MainWindow::exporterListePDF);
        qDebug() << "✅ Bouton Export PDF connecté";
    } else {
        qDebug() << "⚠️ Bouton Export PDF non trouvé dans l'UI";
    }
    
    // === RECHERCHE EN TEMPS RÉEL ===
    if (ui->lineEdit) {
        connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::rechercherLaboratoires);
    }
    
    // === OPTIONS DE TRI ===
    if (ui->comboBox_2) {
        connect(ui->comboBox_2, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &MainWindow::trierLaboratoires);
    }
    
    if (ui->checkBox_3) {
        connect(ui->checkBox_3, &QCheckBox::toggled, this, &MainWindow::trierLaboratoires);
    }
    
    if (ui->checkBox_4) {
        connect(ui->checkBox_4, &QCheckBox::toggled, this, &MainWindow::trierLaboratoires);
    }
    
    qDebug() << "✅ Toutes les connexions établies";
}

// ==================== FONCTIONS DE RECHERCHE ====================
void MainWindow::rechercherLaboratoires()
{
    if (!ui->lineEdit || !ui->tableWidget) return;
    
    QString searchText = ui->lineEdit->text();
    qDebug() << "Recherche:" << searchText;
    
    int visibleCount = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        bool match = searchText.isEmpty();
        for (int col = 0; col < ui->tableWidget->columnCount() && !match; ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item && item->text().contains(searchText, Qt::CaseInsensitive)) {
                match = true;
            }
        }
        ui->tableWidget->setRowHidden(row, !match);
        if (match) visibleCount++;
    }
    
    qDebug() << "→ Résultats:" << visibleCount << "laboratoires trouvés";
}

void MainWindow::filterLaboratoires()
{
    QMessageBox::information(this, "Filtre", 
        "Fonctionnalité de filtre à implémenter");
}

void MainWindow::trierLaboratoires()
{
    if (!ui->comboBox_2 || !ui->tableWidget) return;
    
    QString criteria = ui->comboBox_2->currentText();
    bool ascending = ui->checkBox_3 ? ui->checkBox_3->isChecked() : true;
    
    qDebug() << "Tri par:" << criteria << (ascending ? "Croissant" : "Décroissant");
    
    int column = 1; // Nom par défaut
    if (criteria == "ID") column = 0;
    else if (criteria == "Type d analyse") column = 2;
    else if (criteria == "Conformite") column = 3;
    
    ui->tableWidget->sortItems(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
}

// ==================== FONCTIONS D'EXPORT ====================
void MainWindow::exporterPDF()
{
    QMessageBox::information(this, "Export PDF", 
        "Fonctionnalité d'export PDF (Statistiques) à implémenter");
}

void MainWindow::exporterListePDF()
{
    qDebug() << "Export de la liste des laboratoires en PDF";
    
    if (!ui->tableWidget || ui->tableWidget->rowCount() == 0) {
        QMessageBox::warning(this, "Export PDF", 
            "Aucune donnée à exporter dans la liste des laboratoires.");
        return;
    }
    
    // Compter les lignes visibles
    int visibleCount = 0;
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        if (!ui->tableWidget->isRowHidden(row)) {
            visibleCount++;
        }
    }
    
    QMessageBox::information(this, "Export PDF", 
        QString("Export de la liste des laboratoires en PDF.\n\n"
                "📊 Statistiques:\n"
                "• Total laboratoires: %1\n"
                "• Laboratoires affichés: %2\n\n"
                "Fonctionnalité à implémenter - "
                "Créera un PDF avec la liste complète.")
        .arg(ui->tableWidget->rowCount())
        .arg(visibleCount));
}

// ==================== FONCTIONS DE SUGGESTIONS ====================
void MainWindow::rechercherSuggestions()
{
    if (!ui->listWidget_3) return;
    
    qDebug() << "Recherche de suggestions";
    
    ui->listWidget_3->clear();
    ui->listWidget_3->addItem("🔬 Recommandations disponibles:");
    ui->listWidget_3->addItem("");
    ui->listWidget_3->addItem("• Mise à niveau des équipements");
    ui->listWidget_3->addItem("• Optimisation de l'espace");
    ui->listWidget_3->addItem("• Formation du personnel");
    ui->listWidget_3->addItem("• Audit qualité");
    
    qDebug() << "→ Suggestions affichées";
}