#include "mainwindow.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QGroupBox>
#include <QLineEdit>
#include <QComboBox>

// ───────────────────────────────────────────────
// Sidebar
// ───────────────────────────────────────────────

Sidebar::Sidebar(QWidget *parent) : QWidget(parent)
{
    setFixedWidth(220);
    setStyleSheet("background-color: #2a2a40; border-right: 1px solid #3a3a55;");

    auto *lay = new QVBoxLayout(this);
    lay->setContentsMargins(10, 20, 10, 10);
    lay->setSpacing(12);
    lay->setAlignment(Qt::AlignTop);

    auto *logo = new QLabel("OIL PRESS", this);
    logo->setStyleSheet("color: #ffd700; font-size: 22px; font-weight: bold;");
    logo->setAlignment(Qt::AlignCenter);
    lay->addWidget(logo);

    QString btnStyle =
        "QPushButton {background:transparent; color:#c0c0ff; text-align:left; "
        "padding:12px 8px; border-radius:6px; font-size:15px;}"
        "QPushButton:hover {background:#3a3a55;}";

    QStringList items = {"Dashboard", "Produits", "Production", "Maintenance", "Paramètres"};

    for (const QString &text : items) {
        auto *btn = new QPushButton("  " + text, this);
        btn->setStyleSheet(btnStyle);
        btn->setFlat(true);
        lay->addWidget(btn);
    }

    lay->addStretch();
}

// ───────────────────────────────────────────────
// Produits
// ───────────────────────────────────────────────

ProductsPage::ProductsPage(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #242436;");
    setupUI();
}

void ProductsPage::setupUI()
{
    auto *mainLay = new QVBoxLayout(this);
    mainLay->setContentsMargins(25, 20, 25, 25);
    mainLay->setSpacing(20);

    auto *title = new QLabel("Gestion des Produits / Inventaire");
    title->setStyleSheet("font-size:22px; font-weight:bold; color:white;");
    mainLay->addWidget(title);

    auto *actions = new QHBoxLayout();
    actions->setSpacing(12);

    auto *btnAdd    = new QPushButton("Ajouter Produit");
    auto *btnEdit   = new QPushButton("Modifier");
    auto *btnDelete = new QPushButton("Supprimer");

    btnAdd->setStyleSheet("background:#28a745; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");
    btnEdit->setStyleSheet("background:#007bff; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");
    btnDelete->setStyleSheet("background:#dc3545; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");

    actions->addWidget(btnAdd);
    actions->addWidget(btnEdit);
    actions->addWidget(btnDelete);
    actions->addStretch();
    mainLay->addLayout(actions);

    auto *btnToCmd = new QPushButton("→ Gérer les Commandes");
    btnToCmd->setStyleSheet("background:#17a2b8; color:white; font-size:17px; font-weight:bold; padding:14px; border-radius:8px;");
    btnToCmd->setMinimumHeight(55);

    connect(btnToCmd, &QPushButton::clicked, this, [this]() {
        emit goToOrders();
    });

    mainLay->addWidget(btnToCmd);

    // Recherche (ton code original)
    auto *searchGroup = new QGroupBox("Recherche");
    searchGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; border: 1px solid #444; }");
    auto *searchLay = new QVBoxLayout(searchGroup);

    auto *row1 = new QHBoxLayout();
    row1->addWidget(new QLabel("Produits par type/stock :"));
    auto *edit1 = new QLineEdit();
    auto *btn1 = new QPushButton("Rechercher");
    btn1->setStyleSheet("background:#007bff; color:white;");
    row1->addWidget(edit1);
    row1->addWidget(btn1);
    searchLay->addLayout(row1);

    auto *row2 = new QHBoxLayout();
    row2->addWidget(new QLabel("Commandes par date/statut/fournisseur :"));
    auto *edit2 = new QLineEdit();
    auto *btn2 = new QPushButton("Rechercher");
    btn2->setStyleSheet("background:#007bff; color:white;");
    row2->addWidget(edit2);
    row2->addWidget(btn2);
    searchLay->addLayout(row2);

    mainLay->addWidget(searchGroup);

    // Tri (ton code original)
    auto *sortGroup = new QGroupBox("Tri");
    sortGroup->setStyleSheet("QGroupBox { color: white; font-weight: bold; border: 1px solid #444; }");
    auto *sortLay = new QVBoxLayout(sortGroup);

    auto *srow1 = new QHBoxLayout();
    srow1->addWidget(new QLabel("Produits :"));
    auto *cprod = new QComboBox();
    cprod->addItems({"Prix croissant", "Prix décroissant", "Stock croissant", "Stock décroissant"});
    auto *bsprod = new QPushButton("Trier");
    bsprod->setStyleSheet("background:#17a2b8; color:white;");
    srow1->addWidget(cprod);
    srow1->addWidget(bsprod);
    sortLay->addLayout(srow1);

    auto *srow2 = new QHBoxLayout();
    srow2->addWidget(new QLabel("Commandes :"));
    auto *ccmd = new QComboBox();
    ccmd->addItems({"Montant croissant", "Montant décroissant", "Date récente", "Date ancienne"});
    auto *bscmd = new QPushButton("Trier");
    bscmd->setStyleSheet("background:#17a2b8; color:white;");
    srow2->addWidget(ccmd);
    srow2->addWidget(bscmd);
    sortLay->addLayout(srow2);

    mainLay->addWidget(sortGroup);

    auto *table = new QTableWidget(0, 8);
    table->setHorizontalHeaderLabels({"ID", "Libellé", "Type", "Prix unit.", "Stock actuel", "Seuil alerte", "État", "Fournisseur"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setStyleSheet("background:#343a50; color:white;");
    table->setAlternatingRowColors(true);
    mainLay->addWidget(table, 1);
}

// ───────────────────────────────────────────────
// Commandes
// ───────────────────────────────────────────────

OrdersPage::OrdersPage(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color: #242436;");
    setupUI();
}

void OrdersPage::setupUI()
{
    auto *mainLay = new QVBoxLayout(this);
    mainLay->setContentsMargins(25, 20, 25, 25);
    mainLay->setSpacing(20);

    auto *header = new QHBoxLayout();
    auto *title = new QLabel("Gestion des Commandes");
    title->setStyleSheet("font-size:22px; font-weight:bold; color:white;");
    header->addWidget(title, 1);

    auto *btnRetour = new QPushButton("← Retour aux Produits");
    btnRetour->setStyleSheet("background:#6c757d; color:white; font-size:15px; font-weight:bold; padding:10px 20px; border-radius:8px;");
    btnRetour->setMinimumWidth(220);

    connect(btnRetour, &QPushButton::clicked, this, [this]() {
        emit goBackToProducts();
    });

    header->addWidget(btnRetour, 0, Qt::AlignRight);
    mainLay->addLayout(header);

    auto *actions = new QHBoxLayout();
    actions->setSpacing(12);

    auto *btnAdd    = new QPushButton("Ajouter Commande");
    auto *btnEdit   = new QPushButton("Modifier");
    auto *btnDelete = new QPushButton("Supprimer");
    auto *btnShow   = new QPushButton("Afficher");

    btnAdd->setStyleSheet("background:#28a745; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");
    btnEdit->setStyleSheet("background:#007bff; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");
    btnDelete->setStyleSheet("background:#dc3545; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");
    btnShow->setStyleSheet("background:#17a2b8; color:white; padding:10px 18px; border-radius:6px; font-weight:bold;");

    actions->addWidget(btnAdd);
    actions->addWidget(btnEdit);
    actions->addWidget(btnDelete);
    actions->addWidget(btnShow);
    actions->addStretch();
    mainLay->addLayout(actions);

    // Statistiques, Export, Workflow, Prévision, tableau (ton code original)
    auto *stats = new QGroupBox("Statistiques");
    stats->setStyleSheet("QGroupBox { color: white; font-weight: bold; border: 1px solid #444; }");
    auto *slay = new QVBoxLayout(stats);
    slay->addWidget(new QPushButton("Dépenses par mois"));
    slay->addWidget(new QPushButton("Top produits commandés"));
    slay->addWidget(new QPushButton("Ruptures de stock"));
    mainLay->addWidget(stats);

    auto *exp = new QGroupBox("Export PDF");
    exp->setStyleSheet("QGroupBox { color: white; font-weight: bold; border: 1px solid #444; }");
    auto *explay = new QVBoxLayout(exp);
    explay->addWidget(new QPushButton("Bon de commande"));
    explay->addWidget(new QPushButton("Facture"));
    explay->addWidget(new QPushButton("Catalogue produits"));
    mainLay->addWidget(exp);

    auto *wf = new QGroupBox("Workflow d’approbation");
    wf->setStyleSheet("QGroupBox { color: white; font-weight: bold; border: 1px solid #444; }");
    auto *wflay = new QVBoxLayout(wf);
    wflay->addWidget(new QPushButton("Valider commande (manager)"));
    wflay->addWidget(new QPushButton("Signature numérique / Trace"));
    mainLay->addWidget(wf);

    auto *prev = new QGroupBox("Prévision & réapprovisionnement");
    prev->setStyleSheet("QGroupBox { color: white; font-weight: bold; border: 1px solid #444; }");
    auto *play = new QVBoxLayout(prev);
    play->addWidget(new QPushButton("Proposition de commande auto (seuil + historique)"));
    mainLay->addWidget(prev);

    auto *table = new QTableWidget(0, 6);
    table->setHorizontalHeaderLabels({"ID", "Date", "Statut", "Montant total", "Fournisseur", "Créé par"});
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setStyleSheet("background:#343a50; color:white;");
    table->setAlternatingRowColors(true);
    mainLay->addWidget(table, 1);
}

// ───────────────────────────────────────────────
// MainWindow
// ───────────────────────────────────────────────

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setStyleSheet("background-color: #1e1e2f; color: #e0e0ff;");
    setupInterface();
    createConnections();
}

MainWindow::~MainWindow() = default;

void MainWindow::setupInterface()
{
    auto *central = new QWidget(this);
    setCentralWidget(central);

    auto *mainLayout = new QHBoxLayout(central);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSpacing(0);

    m_sidebar = new Sidebar(this);
    mainLayout->addWidget(m_sidebar);

    m_stackedWidget = new QStackedWidget(this);
    mainLayout->addWidget(m_stackedWidget, 1);

    m_productsPage = new ProductsPage(this);
    m_ordersPage = new OrdersPage(this);

    m_stackedWidget->addWidget(m_productsPage);
    m_stackedWidget->addWidget(m_ordersPage);

    m_stackedWidget->setCurrentIndex(0);
}

void MainWindow::createConnections()
{
    connect(m_productsPage, &ProductsPage::goToOrders,
            m_stackedWidget, [this]() {
                m_stackedWidget->setCurrentWidget(m_ordersPage);
            });

    connect(m_ordersPage, &OrdersPage::goBackToProducts,
            m_stackedWidget, [this]() {
                m_stackedWidget->setCurrentWidget(m_productsPage);
            });
}
