#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QApplication>
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
#include <QVariant>
#include <QVBoxLayout>
#include <QPropertyAnimation>
#include <QSequentialAnimationGroup>
#include <QGraphicsOpacityEffect>
#include <QTimer>
#include <QLabel>
#include <QFrame>
#include <QScreen>
#include <QScrollArea>
#include <QInputDialog>  // Ajouté pour l'email

// ── QtCharts ──
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>

// ==============================
// CCOMMANDE IMPLEMENTATION
// ==============================

Ccommande::Ccommande() : m_idCommande(0), m_quantite(0), m_montantTotal(0.0), m_idClient(0) {}

Ccommande::Ccommande(int idCommande, const QString &libelle, const QDate &dateArrivage,
                     const QDate &dateSortie, const QString &etat, int quantite,
                     double montantTotal, int idClient)
    : m_idCommande(idCommande), m_libelle(libelle), m_dateArrivage(dateArrivage),
      m_dateSortie(dateSortie), m_etat(etat), m_quantite(quantite),
      m_montantTotal(montantTotal), m_idClient(idClient) {}

int Ccommande::getIdCommande() const { return m_idCommande; }
QString Ccommande::getLibelle() const { return m_libelle; }
QDate Ccommande::getDateArrivage() const { return m_dateArrivage; }
QDate Ccommande::getDateSortie() const { return m_dateSortie; }
QString Ccommande::getEtat() const { return m_etat; }
int Ccommande::getQuantite() const { return m_quantite; }
double Ccommande::getMontantTotal() const { return m_montantTotal; }
int Ccommande::getIdClient() const { return m_idClient; }

void Ccommande::setIdCommande(int id) { m_idCommande = id; }
void Ccommande::setLibelle(const QString &libelle) { m_libelle = libelle; }
void Ccommande::setDateArrivage(const QDate &date) { m_dateArrivage = date; }
void Ccommande::setDateSortie(const QDate &date) { m_dateSortie = date; }
void Ccommande::setEtat(const QString &etat) { m_etat = etat; }
void Ccommande::setQuantite(int quantite) { m_quantite = quantite; }
void Ccommande::setMontantTotal(double montant) { m_montantTotal = montant; }
void Ccommande::setIdClient(int id) { m_idClient = id; }

bool Ccommande::ajouter(const Ccommande &cmd)
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM COMMENDE WHERE ID_COMMANDE = :id");
    checkQuery.bindValue(":id", cmd.getIdCommande());
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Erreur vérification ID:" << checkQuery.lastError().text();
        return false;
    }

    bool exists = (checkQuery.value(0).toInt() > 0);
    QSqlQuery query;

    if (exists) {
        query.prepare("UPDATE COMMENDE SET "
                      "LIBELLE = :libelle, "
                      "DATE_ARRIVAGE = TO_DATE(:dateArr, 'YYYY-MM-DD'), "
                      "DATE_SORTIE = TO_DATE(:dateSort, 'YYYY-MM-DD'), "
                      "ETAT = :etat, "
                      "QUANTITE = :qte, "
                      "MONTANT_TOTAL = :montant, "
                      "ID_CLIENT = :idClient "
                      "WHERE ID_COMMANDE = :id");
    } else {
        query.prepare("INSERT INTO COMMENDE "
                      "(ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, QUANTITE, MONTANT_TOTAL, ID_CLIENT) "
                      "VALUES (:id, :libelle, TO_DATE(:dateArr,'YYYY-MM-DD'), TO_DATE(:dateSort,'YYYY-MM-DD'), :etat, :qte, :montant, :idClient)");
    }

    query.bindValue(":id",       cmd.getIdCommande());
    query.bindValue(":libelle",  cmd.getLibelle());
    query.bindValue(":dateArr",  cmd.getDateArrivage().toString("yyyy-MM-dd"));
    query.bindValue(":dateSort", cmd.getDateSortie().toString("yyyy-MM-dd"));
    query.bindValue(":etat",     cmd.getEtat());
    query.bindValue(":qte",      cmd.getQuantite());
    query.bindValue(":montant",  cmd.getMontantTotal());
    query.bindValue(":idClient", cmd.getIdClient());

    if (!query.exec()) {
        qDebug() << "Erreur ajouter/modifier commande:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Ccommande::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM COMMENDE WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur suppression commande:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Ccommande::modifier(int id, const Ccommande &newCmd)
{
    QSqlQuery query;
    query.prepare("UPDATE COMMENDE SET "
                  "LIBELLE = :libelle, "
                  "DATE_ARRIVAGE = TO_DATE(:dateArr, 'YYYY-MM-DD'), "
                  "DATE_SORTIE = TO_DATE(:dateSort, 'YYYY-MM-DD'), "
                  "ETAT = :etat, "
                  "QUANTITE = :qte, "
                  "MONTANT_TOTAL = :montant, "
                  "ID_CLIENT = :idClient "
                  "WHERE ID_COMMANDE = :id");

    query.bindValue(":libelle",  newCmd.getLibelle());
    query.bindValue(":dateArr",  newCmd.getDateArrivage().toString("yyyy-MM-dd"));
    query.bindValue(":dateSort", newCmd.getDateSortie().toString("yyyy-MM-dd"));
    query.bindValue(":etat",     newCmd.getEtat());
    query.bindValue(":qte",      newCmd.getQuantite());
    query.bindValue(":montant",  newCmd.getMontantTotal());
    query.bindValue(":idClient", newCmd.getIdClient());
    query.bindValue(":id",       id);

    if (!query.exec()) {
        qDebug() << "Erreur modification commande:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Ccommande::clientExists(int idClient)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM CLIENT WHERE ID_CLIENT = :id");
    q.bindValue(":id", idClient);
    if (q.exec() && q.next()) {
        return q.value(0).toInt() > 0;
    }
    return false;
}

QVector<QPair<int,QString>> Ccommande::getClientList()
{
    QVector<QPair<int,QString>> clients;
    QSqlQuery q("SELECT ID_CLIENT, NOM_CLIENT FROM CLIENT ORDER BY NOM_CLIENT");
    while (q.next()) {
        clients.append(qMakePair(q.value(0).toInt(), q.value(1).toString()));
    }
    return clients;
}

QVector<int> Ccommande::getClientIds()
{
    QVector<int> ids;
    QSqlQuery q("SELECT ID_CLIENT FROM CLIENT ORDER BY ID_CLIENT");
    while (q.next()) {
        ids.append(q.value(0).toInt());
    }
    return ids;
}

Ccommande Ccommande::getById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                  "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM COMMENDE WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return Ccommande(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        );
    }
    return Ccommande();
}

QVector<Ccommande> Ccommande::getAll()
{
    QVector<Ccommande> list;
    QSqlQuery query("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                    "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM COMMENDE ORDER BY ID_COMMANDE");
    while (query.next()) {
        list.append(Ccommande(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        ));
    }
    return list;
}

QVector<Ccommande> Ccommande::rechercher(const QDate &debut, const QDate &fin,
                                         const QString &etat, int idClient,
                                         const QString &nomClient, const QString &fournisseur)
{
    QVector<Ccommande> results;
    QString sql = "SELECT c.ID_COMMANDE, c.LIBELLE, c.DATE_ARRIVAGE, c.DATE_SORTIE, "
                  "c.ETAT, c.QUANTITE, c.MONTANT_TOTAL, c.ID_CLIENT "
                  "FROM COMMENDE c";

    if (!nomClient.isEmpty()) {
        sql += " JOIN CLIENT cl ON c.ID_CLIENT = cl.ID_CLIENT";
    }

    sql += " WHERE 1=1";

    if (debut.isValid())  sql += " AND c.DATE_ARRIVAGE >= TO_DATE(:debut, 'YYYY-MM-DD')";
    if (fin.isValid())    sql += " AND c.DATE_ARRIVAGE <= TO_DATE(:fin, 'YYYY-MM-DD')";
    if (!etat.isEmpty())  sql += " AND c.ETAT = :etat";
    if (idClient > 0)     sql += " AND c.ID_CLIENT = :idClient";
    if (!nomClient.isEmpty()) sql += " AND cl.NOM_CLIENT LIKE :nomClient";
    if (!fournisseur.isEmpty()) sql += " AND c.LIBELLE LIKE :fournisseur";

    QSqlQuery query;
    query.prepare(sql);

    if (debut.isValid())  query.bindValue(":debut",    debut.toString("yyyy-MM-dd"));
    if (fin.isValid())    query.bindValue(":fin",      fin.toString("yyyy-MM-dd"));
    if (!etat.isEmpty())  query.bindValue(":etat",     etat);
    if (idClient > 0)     query.bindValue(":idClient", idClient);
    if (!nomClient.isEmpty()) query.bindValue(":nomClient", "%" + nomClient + "%");
    if (!fournisseur.isEmpty()) query.bindValue(":fournisseur", "%" + fournisseur + "%");

    if (query.exec()) {
        while (query.next()) {
            results.append(Ccommande(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toDate(),
                query.value(3).toDate(),
                query.value(4).toString(),
                query.value(5).toInt(),
                query.value(6).toDouble(),
                query.value(7).toInt()
            ));
        }
    } else {
        qDebug() << "Erreur recherche avancée:" << query.lastError().text();
    }
    return results;
}

int Ccommande::getTotalCommandes()
{
    QSqlQuery query("SELECT COUNT(*) FROM COMMENDE");
    if (query.next()) return query.value(0).toInt();
    return 0;
}

double Ccommande::getMontantTotalGlobal()
{
    QSqlQuery query("SELECT SUM(MONTANT_TOTAL) FROM COMMENDE");
    if (query.next()) return query.value(0).toDouble();
    return 0.0;
}

double Ccommande::getMoyenneMontant()
{
    QSqlQuery query("SELECT AVG(MONTANT_TOTAL) FROM COMMENDE");
    if (query.next()) return query.value(0).toDouble();
    return 0.0;
}

QMap<QString, double> Ccommande::getMontantParMois()
{
    QMap<QString, double> moisMap;
    QSqlQuery query("SELECT TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') AS MOIS, SUM(MONTANT_TOTAL) "
                    "FROM COMMENDE GROUP BY TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') ORDER BY MOIS");
    while (query.next()) {
        moisMap.insert(query.value(0).toString(), query.value(1).toDouble());
    }
    return moisMap;
}

QMap<QString, int> Ccommande::getNbCommandesParMois()
{
    QMap<QString, int> moisMap;
    QSqlQuery query("SELECT TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') AS MOIS, COUNT(*) "
                    "FROM COMMENDE GROUP BY TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') ORDER BY MOIS");
    while (query.next()) {
        moisMap.insert(query.value(0).toString(), query.value(1).toInt());
    }
    return moisMap;
}

QVector<QPair<QString, int>> Ccommande::getProduitsPlusCommandes(int limit)
{
    QVector<QPair<QString, int>> produits;
    QSqlQuery query;
    query.prepare("SELECT LIBELLE, SUM(QUANTITE) AS QTE_TOTALE FROM COMMENDE "
                  "GROUP BY LIBELLE ORDER BY QTE_TOTALE DESC");
    if (!query.exec()) {
        qDebug() << "Erreur produits plus commandés:" << query.lastError().text();
        return produits;
    }
    int count = 0;
    while (query.next() && count < limit) {
        produits.append(qMakePair(query.value(0).toString(), query.value(1).toInt()));
        ++count;
    }
    return produits;
}

QVector<QPair<QString, double>> Ccommande::getProduitsPlusRentables(int limit)
{
    QVector<QPair<QString, double>> produits;
    QSqlQuery query;
    query.prepare("SELECT LIBELLE, SUM(MONTANT_TOTAL) AS MONTANT_TOTAL FROM COMMENDE "
                  "GROUP BY LIBELLE ORDER BY MONTANT_TOTAL DESC");
    if (!query.exec()) {
        qDebug() << "Erreur produits plus rentables:" << query.lastError().text();
        return produits;
    }
    int count = 0;
    while (query.next() && count < limit) {
        produits.append(qMakePair(query.value(0).toString(), query.value(1).toDouble()));
        ++count;
    }
    return produits;
}

QMap<QString, int> Ccommande::getNbCommandesParEtat()
{
    QMap<QString, int> result;
    QSqlQuery query("SELECT ETAT, COUNT(*) FROM COMMENDE GROUP BY ETAT");
    while (query.next()) {
        result.insert(query.value(0).toString(), query.value(1).toInt());
    }
    return result;
}

// ==============================
// MAINWINDOW IMPLEMENTATION
// ==============================

static const QColor CLR_GREEN_DARK  ("#798777");
static const QColor CLR_GREEN_MED   ("#A2B29F");
static const QColor CLR_GREEN_LIGHT ("#BDD2B6");
static const QColor CLR_BEIGE       ("#F8EDE3");
static const QColor CLR_ORANGE      ("#E8A87C");
static const QColor CLR_YELLOW      ("#D4A843");
static const QColor CLR_GREY        ("#AAAAAA");
static const QColor CLR_RED         ("#C0392B");

static QColor colorForEtat(const QString &etat)
{
    QString e = etat.toLower();
    if (e == "en cours") return CLR_ORANGE;
    if (e == "validee")  return CLR_GREEN_MED;
    if (e == "prete")    return CLR_YELLOW;
    if (e == "annulee")  return CLR_GREY;
    return CLR_BEIGE;
}

static QChartView* makeAnimatedChartView(QChart *chart, const QString &title)
{
    chart->setTitle(title);
    chart->setTheme(QChart::ChartThemeLight);
    chart->setBackgroundBrush(QBrush(CLR_BEIGE));
    chart->setDropShadowEnabled(true);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setAnimationDuration(900);
    chart->setAnimationEasingCurve(QEasingCurve::OutCubic);

    QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(10);
    chart->setTitleFont(titleFont);
    chart->setTitleBrush(QBrush(CLR_GREEN_DARK));

    QChartView *view = new QChartView(chart);
    view->setRenderHint(QPainter::Antialiasing);
    view->setMinimumHeight(300);
    return view;
}

static void insertChartIntoFrame(QFrame *frame, QChartView *&storedView, QChartView *newView)
{
    if (storedView) {
        delete storedView;
        storedView = nullptr;
    }

    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(frame->layout());
    if (!layout) {
        layout = new QVBoxLayout(frame);
        layout->setContentsMargins(4, 4, 4, 4);
        frame->setLayout(layout);
    }
    layout->addWidget(newView);
    storedView = newView;

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(newView);
    newView->setGraphicsEffect(effect);
    QPropertyAnimation *anim = new QPropertyAnimation(effect, "opacity", newView);
    anim->setDuration(700);
    anim->setStartValue(0.0);
    anim->setEndValue(1.0);
    anim->setEasingCurve(QEasingCurve::InOutQuad);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1100, 720);
    QScreen *screen = QApplication::primaryScreen();
    if (screen) {
        QRect geo = screen->availableGeometry();
        move((geo.width() - width()) / 2, (geo.height() - height()) / 2);
    }

    loadStylesheet();
    setupConnections();
    loadClients();
    refreshTableCommandes();
    updateStatistics();
    refreshAllCharts();

    ui->dateSearchDebut->setDate(QDate::currentDate().addMonths(-1));
    ui->dateSearchFin->setDate(QDate::currentDate());
    ui->spinAnneeCalendrier->setValue(QDate::currentDate().year());

    applySortingAndDisplay(Ccommande::getAll());

    // Initialisation du gestionnaire réseau
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &MainWindow::onBrevoReplyFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadStylesheet()
{
    QFile styleFile(":/stylesheet.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }
}

void MainWindow::on_btnCommande_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageCommandes);
}

void MainWindow::on_btnEquipe_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageEquipe);
}

void MainWindow::on_btnClient_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageClient);
}

void MainWindow::on_btnLaboratoire_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageLaboratoire);
}

void MainWindow::on_btnFournisseur_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageFournisseur);
}

void MainWindow::on_btnMachine_clicked()
{
    ui->stackedMain->setCurrentWidget(ui->pageMachine);
}

void MainWindow::setupConnections()
{
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::onAjouterCommande);
    connect(ui->btnResetAjouter, &QPushButton::clicked, this, &MainWindow::onResetAjouter);
    connect(ui->btnSupprimerConfirm, &QPushButton::clicked, this, &MainWindow::onSupprimerCommande);
    connect(ui->btnModifierConfirm, &QPushButton::clicked, this, &MainWindow::onModifierCommande);

    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &MainWindow::exportPDF);
    connect(ui->btnExportRapport, &QPushButton::clicked, this, &MainWindow::exportPDF);
    connect(ui->btnExportFiche, &QPushButton::clicked, this, &MainWindow::exportPDF);

    connect(ui->checkFiltreTous, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreAttente, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreConfirmee, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreExpedie, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreLivree, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);

    connect(ui->btnAppliquerRecherche, &QPushButton::clicked, this, &MainWindow::onApplySearch);
    connect(ui->btnReinitialiserRecherche, &QPushButton::clicked, this, &MainWindow::onResetSearch);
    connect(ui->comboTriPar, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onApplySorting);

    connect(ui->btnAfficherCalendrier, &QPushButton::clicked, this, &MainWindow::onDisplayCalendar);
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &MainWindow::onSendEmailNotification);
    connect(ui->checkEmailAutomatic, &QCheckBox::toggled, this, &MainWindow::onEnableEmailNotification);
}

void MainWindow::loadClients()
{
    QVector<QPair<int, QString>> clients = Ccommande::getClientList();
    ui->comboClient->clear();
    ui->comboClient->addItem("Sélectionnez un client", 0);
    for (const auto &client : clients) {
        ui->comboClient->addItem(client.second, client.first);
    }
}

void MainWindow::onAjouterCommande()
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

    if (quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantité doit être supérieure à zéro !");
        return;
    }
    if (prixUnitaire <= 0.0) {
        QMessageBox::warning(this, "Erreur", "Le prix unitaire doit être supérieur à zéro !");
        return;
    }

    double montantTotal = prixUnitaire * quantite;

    QString etat = ui->comboStatut->currentText().trimmed();
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
        refreshAllCharts();
        onResetAjouter();

        // Envoi automatique si activé
        if (ui->checkEmailAutomatic->isChecked()) {
            QString clientEmail = ui->lineEmail->text().trimmed();  // Email saisi dans le formulaire
            if (!clientEmail.isEmpty()) {
                QString subject = QString("Confirmation de commande n°%1").arg(cmd.getIdCommande());
                QString html = buildHtmlFicheCommande(cmd);
                sendEmailViaBrevo(clientEmail, subject, html);
            } else {
                qDebug() << "Aucun email renseigné pour le client" << cmd.getIdClient();
            }
        }

        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur BD", "Échec de l'ajout. Consultez la console pour le détail.");
    }
}

void MainWindow::onResetAjouter()
{
    ui->lineNumCommande->clear();
    ui->comboClient->setCurrentIndex(0);
    ui->comboLibelle->setCurrentIndex(0);
    ui->spinQuantite->setValue(0);
    ui->spinPrix->setValue(0.0);
    ui->comboStatut->setCurrentIndex(0);
    ui->lineDate->setText(QDate::currentDate().toString("dd/MM/yyyy"));
    ui->lineEmail->clear();  // Efface l'email
}

void MainWindow::onSupprimerCommande()
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
        refreshAllCharts();
        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression.");
    }
}

void MainWindow::onModifierCommande()
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
        refreshAllCharts();
        ui->lineIdMod->clear();

        // Envoi automatique si activé
        if (ui->checkEmailAutomatic->isChecked()) {
            QString clientEmail = ui->lineEmailModif->text().trimmed();  // Email saisi dans le formulaire
            if (!clientEmail.isEmpty()) {
                QString subject = QString("Modification commande n°%1").arg(newCmd.getIdCommande());
                QString html = buildHtmlFicheCommande(newCmd);
                sendEmailViaBrevo(clientEmail, subject, html);
            }
        }

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

void MainWindow::onApplySearch()
{
    QDate debut = ui->dateSearchDebut->date();
    QDate fin = ui->dateSearchFin->date();

    QString texteClient = ui->lineSearchClient->text().trimmed();
    int idClient = texteClient.toInt();
    QString nomClient = (idClient == 0) ? texteClient : QString();
    QString etat = ""; // pas utilisé

    m_lastSearchResults = Ccommande::rechercher(debut, fin, etat, idClient, nomClient);
    m_searchActive = true;

    applySortingAndDisplay(m_lastSearchResults);

    QMessageBox::information(this, "Recherche",
                             QString("%1 résultat(s) trouvé(s).").arg(m_lastSearchResults.size()));
}

void MainWindow::onResetSearch()
{
    ui->dateSearchDebut->setDate(QDate::currentDate().addMonths(-1));
    ui->dateSearchFin->setDate(QDate::currentDate());
    ui->lineSearchClient->clear();

    m_searchActive = false;
    m_lastSearchResults.clear();

    applySortingAndDisplay(Ccommande::getAll());
}

void MainWindow::onApplySorting()
{
    if (m_searchActive) {
        applySortingAndDisplay(m_lastSearchResults);
    } else {
        applySortingAndDisplay(Ccommande::getAll());
    }
}

QVector<Ccommande> MainWindow::sortCommands(const QVector<Ccommande>& list, int sortIndex)
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

void MainWindow::applySortingAndDisplay(const QVector<Ccommande>& source)
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

void MainWindow::refreshTableCommandes()
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

void MainWindow::updateStatistics()
{
    // Fonction vidée car les LineEdit ont été supprimés de l'UI.
}

// ==============================
// GRAPHIQUES
// ==============================

void MainWindow::buildChartMontantParMois()
{
    QMap<QString, double> data = Ccommande::getMontantParMois();

    QBarSet *set = new QBarSet("Montant (€)");
    set->setColor(CLR_GREEN_DARK);
    set->setBorderColor(CLR_GREEN_DARK.darker(130));
    set->setLabelColor(CLR_GREEN_DARK);

    QStringList categories;
    for (auto it = data.begin(); it != data.end(); ++it) {
        *set << it.value();
        categories << it.key();
    }

    QLinearGradient barGrad(QPointF(0, 0), QPointF(0, 1));
    barGrad.setColorAt(0.0, CLR_GREEN_MED.lighter(115));
    barGrad.setColorAt(1.0, CLR_GREEN_DARK);
    barGrad.setCoordinateMode(QGradient::ObjectBoundingMode);
    set->setBrush(QBrush(barGrad));

    QBarSeries *series = new QBarSeries();
    series->append(set);
    series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    QChart *chart = new QChart();
    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsAngle(-40);
    QFont axFont;
    axFont.setPointSize(8);
    axisX->setLabelsFont(axFont);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Montant (€)");
    axisY->setLabelFormat("%.0f");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *view = makeAnimatedChartView(chart, "💰 Montant total des commandes par mois");
    insertChartIntoFrame(ui->frameChartMontant, m_chartViewMontant, view);
}

void MainWindow::buildChartNbCommandesParMois()
{
    QMap<QString, int> data = Ccommande::getNbCommandesParMois();

    QSplineSeries *series = new QSplineSeries();
    series->setName("Nb commandes");
    QPen pen(CLR_GREEN_DARK);
    pen.setWidth(3);
    series->setPen(pen);
    series->setPointsVisible(true);

    QStringList categories;
    int x = 0;
    for (auto it = data.begin(); it != data.end(); ++it, ++x) {
        series->append(x, it.value());
        categories << it.key();
    }

    QSplineSeries *lower = new QSplineSeries();
    for (int i = 0; i < x; i++) lower->append(i, 0);

    QAreaSeries *area = new QAreaSeries(series, lower);
    QLinearGradient areaGrad(QPointF(0, 0), QPointF(0, 1));
    areaGrad.setColorAt(0.0, QColor(CLR_GREEN_LIGHT).darker(110));
    areaGrad.setColorAt(1.0, QColor(CLR_GREEN_LIGHT.red(),
                                    CLR_GREEN_LIGHT.green(),
                                    CLR_GREEN_LIGHT.blue(), 30));
    areaGrad.setCoordinateMode(QGradient::ObjectBoundingMode);
    area->setBrush(QBrush(areaGrad));
    area->setPen(Qt::NoPen);
    area->setName("Évolution");

    QChart *chart = new QChart();
    chart->addSeries(area);
    chart->addSeries(series);

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    axisX->setLabelsAngle(-40);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    area->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setTitleText("Nombre de commandes");
    axisY->setLabelFormat("%d");
    axisY->setTickType(QValueAxis::TicksDynamic);
    axisY->setTickInterval(1);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    area->attachAxis(axisY);

    QChartView *view = makeAnimatedChartView(chart, "📈 Évolution du nombre de commandes par mois");
    insertChartIntoFrame(ui->frameChartNbCmds, m_chartViewNbCmds, view);
}

void MainWindow::buildChartRepartitionEtat()
{
    QMap<QString, int> data = Ccommande::getNbCommandesParEtat();

    QPieSeries *series = new QPieSeries();
    series->setHoleSize(0.40);
    series->setPieSize(0.85);

    int total = 0;
    for (auto it = data.begin(); it != data.end(); ++it) total += it.value();

    for (auto it = data.begin(); it != data.end(); ++it) {
        QPieSlice *slice = series->append(it.key(), it.value());
        slice->setColor(colorForEtat(it.key()));
        slice->setBorderColor(QColor("#ffffff"));
        slice->setBorderWidth(2);

        double pct = total > 0 ? (it.value() * 100.0 / total) : 0;
        slice->setLabel(QString("%1\n%2 (%3%)")
                            .arg(it.key())
                            .arg(it.value())
                            .arg(QString::number(pct, 'f', 1)));
        slice->setLabelVisible(true);
        slice->setLabelArmLengthFactor(0.15);
    }

    if (!series->slices().isEmpty()) {
        QPieSlice *biggest = nullptr;
        for (QPieSlice *sl : series->slices()) {
            if (!biggest || sl->value() > biggest->value()) biggest = sl;
        }
        if (biggest) {
            biggest->setExploded(true);
            biggest->setExplodeDistanceFactor(0.07);
        }
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->setAlignment(Qt::AlignRight);

    QChartView *view = makeAnimatedChartView(chart, "🥧 Répartition des commandes par statut");
    insertChartIntoFrame(ui->frameChartEtat, m_chartViewEtat, view);
}

void MainWindow::buildChartTop10Produits()
{
    auto produitsQte = Ccommande::getProduitsPlusCommandes(10);

    QBarSet *setQte = new QBarSet("Quantité commandée");
    QLinearGradient barGrad(QPointF(0, 0), QPointF(1, 0));
    barGrad.setColorAt(0.0, CLR_GREEN_LIGHT);
    barGrad.setColorAt(1.0, CLR_GREEN_DARK);
    barGrad.setCoordinateMode(QGradient::ObjectBoundingMode);
    setQte->setBrush(QBrush(barGrad));
    setQte->setBorderColor(CLR_GREEN_DARK.darker(120));
    setQte->setLabelColor(CLR_GREEN_DARK);

    QStringList prodNames;
    for (const auto &p : produitsQte) {
        *setQte << p.second;
        QString name = p.first;
        if (name.length() > 20) name = name.left(18) + "…";
        prodNames << name;
    }

    QHorizontalBarSeries *series = new QHorizontalBarSeries();
    series->append(setQte);
    series->setLabelsVisible(true);
    series->setLabelsPosition(QAbstractBarSeries::LabelsOutsideEnd);

    QChart *chart = new QChart();
    chart->addSeries(series);

    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append(prodNames);
    QFont axFont;
    axFont.setPointSize(8);
    axisY->setLabelsFont(axFont);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QValueAxis *axisX = new QValueAxis();
    axisX->setTitleText("Quantité totale");
    axisX->setLabelFormat("%d");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QChartView *view = makeAnimatedChartView(chart, "🏆 Top 10 produits les plus commandés");
    view->setMinimumHeight(340);
    insertChartIntoFrame(ui->frameChartProduits, m_chartViewProduits, view);
}

void MainWindow::refreshAllCharts()
{
    buildChartMontantParMois();

    QTimer::singleShot(150, this, [this]() {
        buildChartNbCommandesParMois();
    });

    QTimer::singleShot(300, this, [this]() {
        buildChartRepartitionEtat();
    });

    QTimer::singleShot(450, this, [this]() {
        buildChartTop10Produits();
    });
}

void MainWindow::onDisplayCalendar()
{
    int month = ui->comboMoisCalendrier->currentIndex() + 1;
    int year = ui->spinAnneeCalendrier->value();
    QDate firstDay(year, month, 1);
    ui->calendarCommandes->setSelectedDate(firstDay);
    refreshCalendarAlerts();
    updateCalendarColors(month, year);
}

void MainWindow::refreshCalendarAlerts()
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

// NOUVEAU : Envoi d'email via Brevo
void MainWindow::sendEmailViaBrevo(const QString &to, const QString &subject, const QString &htmlBody)
{
    // Clé API (à sécuriser)
    const QString apiKey = "xkeysib-MASKED-PENTEST-AUTHORIZED";
    // Expéditeur (doit être validé dans Brevo)
    const QString senderEmail = "karouihassen927@gmail.com";
    const QString senderName = "Smart Oil Press";

    QJsonObject json;
    QJsonObject senderObj;
    senderObj["name"] = senderName;
    senderObj["email"] = senderEmail;
    json["sender"] = senderObj;

    QJsonArray toArray;
    QJsonObject toObj;
    toObj["email"] = to;
    toArray.append(toObj);
    json["to"] = toArray;

    json["subject"] = subject;
    json["htmlContent"] = htmlBody;

    QJsonDocument doc(json);
    QByteArray data = doc.toJson();

    QNetworkRequest request(QUrl("https://api.brevo.com/v3/smtp/email"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("api-key", apiKey.toUtf8());

    m_networkManager->post(request, data);
}

void MainWindow::onBrevoReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Email envoyé avec succès via Brevo";
        // Optionnel : afficher un message de succès
        // QMessageBox::information(this, "Succès", "L'email a été envoyé.");
    } else {
        qDebug() << "Erreur d'envoi Brevo:" << reply->errorString();
        qDebug() << "Réponse:" << reply->readAll();
        QMessageBox::warning(this, "Erreur d'envoi",
                             "Échec de l'envoi de l'email : " + reply->errorString());
    }
    reply->deleteLater();
}

// Envoi manuel (utilise également Brevo)
void MainWindow::onSendEmailNotification()
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
    QString html = buildHtmlFicheCommande(cmd);
    html += "<p><b>Message :</b><br/>" + message.toHtmlEscaped() + "</p>";

    sendEmailViaBrevo(email, subject, html);

    // Ajouter à l'historique
    int rowCount = ui->tableHistoriqueEmails->rowCount();
    ui->tableHistoriqueEmails->insertRow(rowCount);
    ui->tableHistoriqueEmails->setItem(rowCount, 0, new QTableWidgetItem(numCommande));
    ui->tableHistoriqueEmails->setItem(rowCount, 1, new QTableWidgetItem(email));
    ui->tableHistoriqueEmails->setItem(rowCount, 2, new QTableWidgetItem(QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm")));
    ui->tableHistoriqueEmails->setItem(rowCount, 3, new QTableWidgetItem("Envoyé via Brevo"));

    ui->lineNumCommandeEmail->clear();
    ui->lineEmailDestinataire->clear();
    ui->textMessageEmail->clear();
}

void MainWindow::onEnableEmailNotification(bool enabled)
{
    if (enabled) {
        QMessageBox::information(this, "Notifications", "Notifications automatiques activées!");
    } else {
        QMessageBox::information(this, "Notifications", "Notifications automatiques désactivées!");
    }
}

void MainWindow::exportPDF()
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

void MainWindow::showMessage(const QString &title, const QString &message)
{
    QMessageBox::information(this, title, message);
}

QString MainWindow::buildHtmlListeComplete(const QVector<Ccommande>& orders)
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

QString MainWindow::buildHtmlRapport(const QVector<Ccommande>& orders)
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

QString MainWindow::buildHtmlFicheCommande(const Ccommande& cmd)
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

void MainWindow::updateCalendarColors(int month, int year)
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

QColor MainWindow::getColorForEtat(const QString &etat) const
{
    QString e = etat.toLower();
    if (e == "en cours") return QColor(255, 99, 71);
    if (e == "validee")  return QColor(255, 165, 0);
    if (e == "prete")    return QColor(255, 255, 0);
    if (e == "annulee")  return QColor(211, 211, 211);
    return QColor(255, 255, 255);
}

int MainWindow::getPriorityForEtat(const QString &etat) const
{
    QString e = etat.toLower();
    if (e == "en cours") return 4;
    if (e == "validee")  return 3;
    if (e == "prete")    return 2;
    if (e == "annulee")  return 1;
    return 0;
}