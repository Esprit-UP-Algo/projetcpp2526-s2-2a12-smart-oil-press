#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "machine.h"
#include "email_sender.h"
#include "equipe.h"
#include "employe.h"
#include <QFile>
#include <QApplication>
#include <QCheckBox>
#include <QMessageBox>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
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
#include <QDir>
#include <QPrinter>
#include <QNetworkRequest>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>
#include <QEasingCurve>
#include <QMap>

#include <algorithm>
#include <cmath>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QSplineSeries>

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

QString formatLaboId(int id)
{
    return QString("lab%1").arg(id, 2, 10, QChar('0'));
}

int parseLaboId(const QString &text)
{
    QString normalized = text.trimmed().toLower();
    if (normalized.startsWith("lab")) {
        bool ok;
        int value = normalized.mid(3).toInt(&ok);
        if (ok) {
            return value;
        }
    }
    bool ok;
    return text.toInt(&ok) ? text.toInt() : -1;
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

// Couleurs pour les commandes
const QColor CLR_GREEN_DARK  ("#798777");
const QColor CLR_GREEN_MED   ("#A2B29F");
const QColor CLR_GREEN_LIGHT ("#BDD2B6");
const QColor CLR_BEIGE       ("#F8EDE3");
const QColor CLR_ORANGE      ("#E8A87C");
const QColor CLR_YELLOW      ("#D4A843");
const QColor CLR_GREY        ("#AAAAAA");

static QString normalizeEtatValue(QString etat)
{
    etat = etat.trimmed().toLower();
    etat.replace(QChar(0x00E9), "e"); // é
    etat.replace(QChar(0x00E8), "e"); // è
    etat.replace(QChar(0x00EA), "e"); // ê
    etat.replace(QChar(0x00EB), "e"); // ë
    etat.replace(QChar(0x00E0), "a"); // à
    etat.replace(QChar(0x00E2), "a"); // â
    etat.replace(QChar(0x00F9), "u"); // ù
    etat.replace(QChar(0x00FB), "u"); // û
    etat.replace(QChar(0xFFFD), "e"); // replacement char
    etat.replace(QString::fromLatin1("\xEF\xBF\xBD"), "e"); // "ï¿½" style mojibake

    if (etat.contains("cours")) return "en cours";
    if (etat.contains("valid")) return "validee";
    if (etat.contains("pret"))  return "prete";
    if (etat.contains("annul")) return "annulee";
    return etat.simplified();
}

static bool isEtatAllowed(const QString &etat)
{
    const QString e = normalizeEtatValue(etat);
    return e == "en cours" || e == "validee" || e == "prete" || e == "annulee";
}

static QString toDbEtatValue(const QString &etat)
{
    const QString e = normalizeEtatValue(etat);
    if (e == "en cours") return "en cours";
    if (e == "validee")  return "validee";
    if (e == "prete")    return "prete";
    if (e == "annulee")  return "annulee";
    return etat.trimmed();
}

static QString displayEtatLabel(const QString &etat)
{
    const QString e = normalizeEtatValue(etat);
    if (e == "en cours") return "en cours";
    if (e == "validee")  return "validee";
    if (e == "prete")    return "prete";
    if (e == "annulee")  return "annulee";
    return etat.trimmed();
}

static QColor colorForEtat(const QString &etat)
{
    const QString e = normalizeEtatValue(etat);
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
        QString style = QString::fromUtf8(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }
    qDebug() << "[MW] after stylesheet";

    // Initialisation du gestionnaire reseau pour les emails
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &MainWindow::onBrevoReplyFinished);

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
            refreshLaboStats();
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
    setupEquipeConnections();
    qDebug() << "[MW] after setupCrudConnections";

    if (ui->table_employes && ui->table_employes->columnCount() > 11) {
        ui->table_employes->setColumnHidden(11, true);
    }

    connect(ui->btnExportListeComplete, &QPushButton::clicked, this, &MainWindow::exporterListeCompletePdf);
    connect(ui->btnExportFicheEmploye, &QPushButton::clicked, this, &MainWindow::exporterFicheEmployePdf);

    auto setupLaboUiData = [this]() {
        ui->tableWidgetLabo->setColumnCount(8);
        ui->tableWidgetLabo->setHorizontalHeaderLabels(
            {"ID_LABO", "NOM_LABO", "RESULTATS", "CONFORMITE", "ADRESSE", "ESPACE_LABO", "ESPACE_RESTE", "REVIEW"});

        // Display the data from database
        afficherLabos();
    };

    auto rechercherLaboratoires = [this]() {
        const QString searchText = ui->lineEditRechercheLabo->text();
        for (int row = 0; row < ui->tableWidgetLabo->rowCount(); ++row) {
            bool match = searchText.isEmpty();
            // Only search in ID (column 0) and Adresse (column 4) columns
            if (!match) {
                QTableWidgetItem *idItem = ui->tableWidgetLabo->item(row, 0);
                if (idItem && idItem->text().contains(searchText, Qt::CaseInsensitive)) {
                    match = true;
                }
            }
            if (!match) {
                QTableWidgetItem *adresseItem = ui->tableWidgetLabo->item(row, 4);
                if (adresseItem && adresseItem->text().contains(searchText, Qt::CaseInsensitive)) {
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

        int column;
        if (criteria == "Espace Labo") {
            column = 5;
        } else {
            // Default to ID.
            column = 0;
        }

        ui->tableWidgetLabo->sortItems(column, ascending ? Qt::AscendingOrder : Qt::DescendingOrder);
    };

    auto exporterListeLaboPdf = [this]() {
        if (ui->tableWidgetLabo->rowCount() == 0) {
            QMessageBox::warning(this, "Export PDF", "Aucune donnee a exporter.");
            return;
        }

        const QString defaultName = QString("liste_laboratoires_%1.pdf")
                                        .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
        const QString filePath = QFileDialog::getSaveFileName(
            this,
            "Exporter la liste des laboratoires en PDF",
            defaultName,
            "PDF Files (*.pdf)");

        if (filePath.isEmpty()) {
            return;
        }

        int totalRows = ui->tableWidgetLabo->rowCount();
        int totalCols = ui->tableWidgetLabo->columnCount();

        QString html;
        html += "<h2>Liste des laboratoires</h2>";
        html += "<p>Genere le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
        html += "<table border='1' cellspacing='0' cellpadding='4'>";

        // Header row
        html += "<tr>";
        for (int col = 0; col < totalCols; ++col) {
            QString header = ui->tableWidgetLabo->horizontalHeaderItem(col)
                ? ui->tableWidgetLabo->horizontalHeaderItem(col)->text() : QString("Col%1").arg(col + 1);
            html += "<th>" + header.toHtmlEscaped() + "</th>";
        }
        html += "</tr>";

        // Data rows
        for (int row = 0; row < totalRows; ++row) {
            html += "<tr>";
            for (int col = 0; col < totalCols; ++col) {
                QTableWidgetItem *item = ui->tableWidgetLabo->item(row, col);
                QString value = item ? item->text() : "";
                html += "<td>" + value.toHtmlEscaped() + "</td>";
            }
            html += "</tr>";
        }

        html += "</table>";

        QTextDocument document;
        document.setHtml(html);

        QPdfWriter writer(filePath);
        writer.setPageSize(QPageSize(QPageSize::A4));
        writer.setPageMargins(QMarginsF(12, 12, 12, 12));
        document.print(&writer);

        // Effacer les messages de bas après export
        if (ui->textEdit_export_messages1) ui->textEdit_export_messages1->clear();
        if (ui->textEdit_export_messages_labo) ui->textEdit_export_messages_labo->clear();

        QMessageBox::information(this, "Export PDF", "Export complet du tableau effectue avec succes :\n" + filePath);
    };

    auto exporterStatsLaboPdf = [this]() {
        exportLaboStatsPdf();
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
        refreshEquipeTable();
    }
    if (ui->topNavTabs1) {
        setLaboPageFromTab(ui->topNavTabs1->currentIndex());
    }
    if (ui->tableWidgetLabo) {
        setupLaboUiData();
    }
    setupMachineConnections();
    afficherMachines();
    refreshMachineStats();
    refreshLaboStats();
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

    connect(ui->topNavTabs, &QTabWidget::currentChanged, this, [this, setEquipePageFromTab](int index) {
        setEquipePageFromTab(index);
        if (index == 1 || index == 4) {
            refreshEquipeTable();
        }
    });

    connect(ui->topNavTabs1, &QTabWidget::currentChanged, this, [setLaboPageFromTab](int index) {
        setLaboPageFromTab(index);
    });

    connect(ui->btnCommande, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->CommandeWidget);
        loadClients();
        refreshTableCommandes();
        updateStatistics();
        refreshAllCharts();
        ui->dateSearchDebut->setDate(QDate::currentDate().addMonths(-1));
        ui->dateSearchFin->setDate(QDate::currentDate());
        ui->spinAnneeCalendrier->setValue(QDate::currentDate().year());
        applySortingAndDisplay(Ccommande::getAll());
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
    // Ensure tri selection only includes ID and Espace Labo
    ui->comboBoxTriLabo->clear();
    ui->comboBoxTriLabo->addItem("ID");
    ui->comboBoxTriLabo->addItem("Espace Labo");

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

    // === MODULE COMMANDE - Connexions ===
    setupCommandeConnections();
    loadClients();

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

    // Labo connections
    connect(ui->btnAjouterLabo, &QPushButton::clicked, this, &MainWindow::ajouterLabo);
    connect(ui->btnSupprimerLabo, &QPushButton::clicked, this, &MainWindow::supprimerLabo);
    connect(ui->btnModifierLabo, &QPushButton::clicked, this, &MainWindow::modifierLabo);
    connect(ui->lineEdit_modif_id1, &QLineEdit::editingFinished, this, &MainWindow::chargerLaboPourModification);
    connect(ui->btnExportFicheLabo, &QPushButton::clicked, this, &MainWindow::exporterFicheLaboPdf);
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

void MainWindow::exporterFicheLaboPdf()
{
    const QString id = ui->lineEdit_id_export_labo->text().trimmed();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Export PDF", "Veuillez saisir un ID laboratoire.");
        return;
    }

    int idLabo = parseLaboId(id);
    if (idLabo <= 0) {
        QMessageBox::warning(this, "Export PDF", "ID laboratoire invalide.");
        return;
    }

    LaboData labo;
    QString dbError;
    if (!LaboRepository::getLaboById(idLabo, &labo, &dbError)) {
        QMessageBox::warning(this, "Export PDF", dbError);
        return;
    }

    const QString defaultName = QString("fiche_labo_%1_%2.pdf")
                                    .arg(id)
                                    .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
    const QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter la fiche laboratoire en PDF",
        defaultName,
        "PDF Files (*.pdf)");

    if (filePath.isEmpty()) {
        return;
    }

    QString html;
    html += "<h2>Fiche Laboratoire</h2>";
    html += "<p>Genere le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<table border='1' cellspacing='0' cellpadding='6'>";
    html += "<tr><td><b>ID</b></td><td>" + formatLaboId(labo.idLabo) + "</td></tr>";
    html += "<tr><td><b>Nom</b></td><td>" + labo.nomLabo.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Resultats</b></td><td>" + labo.resultats.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Conformite</b></td><td>" + labo.conformite.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Adresse</b></td><td>" + labo.adresse.toHtmlEscaped() + "</td></tr>";
    html += "<tr><td><b>Espace Labo</b></td><td>" + QString::number(labo.espaceLabo).toHtmlEscaped() + " m²</td></tr>";
    html += "<tr><td><b>Espace Restant</b></td><td>" + QString::number(labo.espaceReste).toHtmlEscaped() + " m²</td></tr>";
    html += "<tr><td><b>Review</b></td><td>" + QString::number(labo.review).toHtmlEscaped() + "/10</td></tr>";
    html += "</table>";

    const QString message = ui->textEdit_export_messages_labo->toPlainText().trimmed();
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

    QMessageBox::information(this, "Export PDF", "Fiche laboratoire exportee avec succes :\n" + filePath);
}

void MainWindow::refreshLaboStats()
{
    LaboStatsSummary summary;
    QString error;
    if (!LaboRepository::getStatsSummary(&summary, &error)) {
        qDebug() << "Erreur stats labo :" << error;
    }

    QList<LaboData> labos;
    if (!LaboRepository::listLabos(&labos, &error)) {
        qDebug() << "Erreur liste labos pour stats :" << error;
    }

    int total = summary.totalLabos;
    int conformes = summary.totalConformes;
    double taux = total > 0 ? (conformes * 100.0 / total) : 0.0;

    if (ui->label_total_labos) {
        ui->label_total_labos->setText(QString("Total laboratoires : %1").arg(total));
    }
    if (ui->label_conformes_labos) {
        ui->label_conformes_labos->setText(QString("Conformes : %1").arg(conformes));
    }
    if (ui->label_taux_conformite) {
        ui->label_taux_conformite->setText(QString("Taux conformité : %1 %").arg(QString::number(taux, 'f', 2)));
    }

    if (ui->plainTextEdit1) {
        QString text = QString("Total laboratoires : %1\nConformes : %2\nNon conformes : %3\nTaux de conformité : %4 %")
                .arg(total)
                .arg(conformes)
                .arg(total - conformes)
                .arg(QString::number(taux, 'f', 2));
        ui->plainTextEdit1->setPlainText(text);
    }

    if (ui->plainTextEdit_21) {
        double averageReview = 0.0;
        int count = 0;
        for (const LaboData &labo : labos) {
            if (labo.review >= 0) {
                averageReview += labo.review;
                count++;
            }
        }
        if (count > 0) averageReview /= count;

        QString text = QString("Nombre de laboratoires chargés : %1\n" 
                              "Review moyenne : %2/10\n" 
                              "Analyse moyenne par labo : %3")
                .arg(labos.count())
                .arg(count > 0 ? QString::number(averageReview, 'f', 2) : QString("0.00"))
                .arg("N/A");
        ui->plainTextEdit_21->setPlainText(text);
    }
}

void MainWindow::exportLaboStatsPdf()
{
    const QString defaultName = QString("stats_labos_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
    const QString filePath = QFileDialog::getSaveFileName(this, "Exporter statistiques laboratoires en PDF", defaultName, "PDF Files (*.pdf)");
    if (filePath.isEmpty()) return;

    QString html;
    html += "<h2>Statistiques des laboratoires</h2>";
    html += "<p>Genere le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<pre>" + (ui->plainTextEdit1 ? ui->plainTextEdit1->toPlainText() : QString()) + "</pre>";
    html += "<pre>" + (ui->plainTextEdit_21 ? ui->plainTextEdit_21->toPlainText() : QString()) + "</pre>";

    QTextDocument document;
    document.setHtml(html);

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));
    document.print(&writer);

    QMessageBox::information(this, "Export PDF", "Statistiques laboratoires exportees avec succes :\n" + filePath);
}

void MainWindow::refreshMachineStats()
{
    MachineStatsSummary stats;
    QString error;
    if (!MachineWidget::getStatsSummary(&stats, &error)) {
        qDebug() << "Erreur stats machine :" << error;
    }

    if (ui->lblStatsTotalMachines) ui->lblStatsTotalMachines->setText(QString::number(stats.totalMachines));
    if (ui->lblStatsEnService) ui->lblStatsEnService->setText(QString::number(stats.enService));
    if (ui->lblStatsEnPanne) ui->lblStatsEnPanne->setText(QString::number(stats.enPanne));
    if (ui->lblStatsMaintenance) ui->lblStatsMaintenance->setText(QString::number(stats.maintenance));

    if (ui->txtStatistiques_mach) {
        QString txt;
        txt += QString("Total machines : %1\n").arg(stats.totalMachines);
        txt += QString("En service : %1\n").arg(stats.enService);
        txt += QString("En panne : %1\n").arg(stats.enPanne);
        txt += QString("Maintenance : %1\n").arg(stats.maintenance);
        txt += QString("Hors service : %1\n").arg(stats.horsService);
        txt += QString("En stock : %1\n").arg(stats.enStock);
        txt += QString("En attente : %1\n").arg(stats.enAttente);

        QList<MachineData> machines;
        if (MachineWidget::listMachines(&machines, &error)) {
            QMap<QString,int> categories;
            for (const MachineData &m : machines) {
                categories[m.categorie.toLower()] += 1;
            }
            txt += "\nRépartition par catégorie :\n";
            for (auto it = categories.constBegin(); it != categories.constEnd(); ++it) {
                txt += QString("%1 : %2\n").arg(it.key(), QString::number(it.value()));
            }
        }

        ui->txtStatistiques_mach->setPlainText(txt);
    }
}

void MainWindow::exportMachineStatsPdf()
{
    const QString defaultName = QString("stats_machines_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss"));
    const QString filePath = QFileDialog::getSaveFileName(this, "Exporter statistiques machines en PDF", defaultName, "PDF Files (*.pdf)");
    if (filePath.isEmpty()) return;

    QString html;
    html += "<h2>Statistiques des machines</h2>";
    html += "<p>Genere le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy hh:mm") + "</p>";
    html += "<pre>" + (ui->txtStatistiques_mach ? ui->txtStatistiques_mach->toPlainText() : QString()) + "</pre>";

    QTextDocument document;
    document.setHtml(html);

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));
    document.print(&writer);

    QMessageBox::information(this, "Export PDF", "Statistiques machines exportees avec succes :\n" + filePath);
}

// === MODULE EQUIPE ===
void MainWindow::setupEquipeConnections()
{
    if (!ui->tableWidgetEquipe) {
        return;
    }

    ui->tableWidgetEquipe->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetEquipe->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidgetEquipe->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableWidgetEquipe->verticalHeader()->setVisible(false);
    ui->tableWidgetEquipe->setColumnCount(6);
    ui->tableWidgetEquipe->setHorizontalHeaderLabels(
        {"ID Équipe", "Nom", "Spécialité", "Membres", "État", "Rate"});
    ui->tableWidgetEquipe->horizontalHeader()->setStretchLastSection(true);

    if (ui->specialtyStatsTable) {
        ui->specialtyStatsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->specialtyStatsTable->setSelectionMode(QAbstractItemView::NoSelection);
        ui->specialtyStatsTable->verticalHeader()->setVisible(false);
        ui->specialtyStatsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    if (ui->performanceRankingTable) {
        ui->performanceRankingTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->performanceRankingTable->setSelectionMode(QAbstractItemView::NoSelection);
        ui->performanceRankingTable->verticalHeader()->setVisible(false);
        ui->performanceRankingTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    }

    auto *nameValidator = new QRegularExpressionValidator(
        QRegularExpression("^[A-Za-z\\x{00C0}-\\x{00FF}][A-Za-z\\x{00C0}-\\x{00FF} ]{1,49}$"), this);
    ui->lineEditNomEquipeAjout->setValidator(nameValidator);
    ui->lineEditNomEquipeModif->setValidator(nameValidator);
    ui->lineEditNomEquipeAjout->setMaxLength(50);
    ui->lineEditNomEquipeModif->setMaxLength(50);

    auto configurePromptItem = [](QComboBox *combo) {
        if (!combo || combo->count() == 0) {
            return;
        }

        const QString prompt = combo->itemText(0).trimmed();
        combo->removeItem(0);
        combo->setCurrentIndex(-1);
        combo->setPlaceholderText(prompt);
    };

    configurePromptItem(ui->comboBoxSpecialiteEquipeAjout);
    configurePromptItem(ui->comboBoxNbMembresEquipeAjout);
    configurePromptItem(ui->comboBox_add_etat);
    configurePromptItem(ui->comboBoxSpecialiteEquipeModif);
    configurePromptItem(ui->comboBoxNbMembresEquipeModif);
    configurePromptItem(ui->comboBox_mod_etat);

    if (ui->checkBoxTriEquipeCroissant && ui->checkBoxTriEquipeDecroissant) {
        ui->checkBoxTriEquipeCroissant->setChecked(true);
    }

    connect(ui->btnAjouterEquipe, &QPushButton::clicked, this, &MainWindow::ajouterEquipe);
    connect(ui->btnModifierEquipe, &QPushButton::clicked, this, &MainWindow::modifierEquipe);
    connect(ui->btnSupprimerEquipe, &QPushButton::clicked, this, &MainWindow::supprimerEquipe);
    connect(ui->btnRechercherEquipe, &QPushButton::clicked, this, &MainWindow::rechercherEquipe);
    connect(ui->btnTrier, &QPushButton::clicked, this, &MainWindow::trierEquipe);

    connect(ui->checkBoxTriEquipeCroissant, &QCheckBox::toggled,
            this, &MainWindow::onEquipeTriCroissantToggled);
    connect(ui->checkBoxTriEquipeDecroissant, &QCheckBox::toggled,
            this, &MainWindow::onEquipeTriDecroissantToggled);

    connect(ui->pushButton_validateTeamDetails, &QPushButton::clicked,
            this, &MainWindow::updateEquipeDetailsStats);
    connect(ui->lineEdit_teamDetailsId, &QLineEdit::returnPressed,
            this, &MainWindow::updateEquipeDetailsStats);
}

void MainWindow::refreshEquipeTable()
{
    QList<EquipeData> rows;
    QString errorMessage;
    if (!EquipeRepository::listerEquipes(&rows, &errorMessage)) {
        QMessageBox::warning(this, "Equipe", "Impossible de charger la liste des equipes:\n" + errorMessage);
        return;
    }

    m_equipes = rows;
    ui->tableWidgetEquipe->setRowCount(0);

    for (int row = 0; row < m_equipes.size(); ++row) {
        const EquipeData &equipe = m_equipes.at(row);
        EquipeRateData rateData;
        QString serviceError;
        if (!EquipeRepository::extraireRateData(equipe.rate, &rateData, &serviceError)) {
            QMessageBox::warning(this, "Equipe", serviceError);
            return;
        }

        ui->tableWidgetEquipe->insertRow(row);
        ui->tableWidgetEquipe->setItem(row, 0, new QTableWidgetItem(QString::number(equipe.idEquipe)));
        ui->tableWidgetEquipe->setItem(row, 1, new QTableWidgetItem(equipe.nomEquipe));
        ui->tableWidgetEquipe->setItem(row, 2, new QTableWidgetItem(equipe.specialite));
        ui->tableWidgetEquipe->setItem(row, 3, new QTableWidgetItem(QString::number(equipe.nbreMembres)));
        ui->tableWidgetEquipe->setItem(row, 4, new QTableWidgetItem(equipe.etat));
        ui->tableWidgetEquipe->setItem(row, 5, new QTableWidgetItem(QString::number(rateData.rateValue, 'f', 2)));
    }

    updateEquipeOverallStats();
    updateEquipeDetailsStats();
}

void MainWindow::updateEquipeOverallStats()
{
    QList<EquipeSpecialiteStatData> specialtyRows;
    QMap<QString, int> specialtyCounts;
    QString serviceError;
    if (!EquipeRepository::calculerStatsSpecialites(m_equipes, &specialtyRows, &specialtyCounts, &serviceError)) {
        QMessageBox::warning(this, "Equipe", serviceError);
        return;
    }

    if (ui->label_totalTeams) {
        ui->label_totalTeams->setText(QString("Total equipes: %1").arg(m_equipes.size()));
    }

    if (ui->label_specialtyCount) {
        ui->label_specialtyCount->setText(
            QString("Specialites representees: %1").arg(specialtyCounts.size()));
    }

    if (ui->overallSpecialtyChartHost) {
        auto *hostLayout = qobject_cast<QVBoxLayout *>(ui->overallSpecialtyChartHost->layout());
        if (!hostLayout) {
            hostLayout = new QVBoxLayout(ui->overallSpecialtyChartHost);
            hostLayout->setContentsMargins(0, 0, 0, 0);
        }

        while (QLayoutItem *item = hostLayout->takeAt(0)) {
            if (item->widget()) {
                item->widget()->deleteLater();
            }
            delete item;
        }

        auto *series = new QPieSeries();
        const int totalTeams = m_equipes.size();
        for (auto it = specialtyCounts.cbegin(); it != specialtyCounts.cend(); ++it) {
            QString specialtyLabel = it.key();
            if (!specialtyLabel.isEmpty()) {
                specialtyLabel[0] = specialtyLabel.at(0).toUpper();
            }
            const int count = it.value();
            const double pct = totalTeams > 0
                                   ? (static_cast<double>(count) / static_cast<double>(totalTeams)) * 100.0
                                   : 0.0;
            QPieSlice *slice = series->append(
                QString("%1 - %2%").arg(specialtyLabel).arg(pct, 0, 'f', 1),
                count);
            slice->setLabelVisible(true);
        }

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTitle(totalTeams > 0
                            ? "Pourcentage des equipes par specialite"
                            : "Aucune equipe disponible");

        auto *chartView = new QChartView(chart, ui->overallSpecialtyChartHost);
        chartView->setRenderHint(QPainter::Antialiasing);
        hostLayout->addWidget(chartView);
    }

    if (ui->specialtyStatsTable) {
        ui->specialtyStatsTable->setRowCount(0);

        int row = 0;
        for (const EquipeSpecialiteStatData &statRow : specialtyRows) {
            QString specialtyLabel = statRow.specialite;
            if (!specialtyLabel.isEmpty()) {
                specialtyLabel[0] = specialtyLabel.at(0).toUpper();
            }

            ui->specialtyStatsTable->insertRow(row);
            ui->specialtyStatsTable->setItem(row, 0, new QTableWidgetItem(specialtyLabel));
            ui->specialtyStatsTable->setItem(
                row, 1, new QTableWidgetItem(QString::number(static_cast<int>(std::round(statRow.membersAverage)))));
            ui->specialtyStatsTable->setItem(row, 2, new QTableWidgetItem(QString::number(statRow.rateAverage, 'f', 2)));
            ui->specialtyStatsTable->setItem(row, 3, new QTableWidgetItem(
                                                   QString("%1/%2").arg(statRow.activeCount).arg(statRow.teamCount)));
            ui->specialtyStatsTable->setItem(row, 4, new QTableWidgetItem(
                                                   QString::number(statRow.activeGlobalPercent, 'f', 1) + "%"));
            ++row;
        }
    }

    updateEquipeTopPerformers();
}

void MainWindow::updateEquipeTopPerformers()
{
    if (!ui->performanceRankingTable) {
        return;
    }

    QList<EquipePerformanceStatData> rankingRows;
    QString serviceError;
    if (!EquipeRepository::calculerClassement(m_equipes, &rankingRows, &serviceError)) {
        QMessageBox::warning(this, "Equipe", serviceError);
        return;
    }

    ui->performanceRankingTable->setRowCount(0);
    if (rankingRows.isEmpty()) {
        return;
    }

    int row = 0;
    for (const EquipePerformanceStatData &item : rankingRows) {
        ui->performanceRankingTable->insertRow(row);
        ui->performanceRankingTable->setItem(row, 0, new QTableWidgetItem(item.categorie));
        ui->performanceRankingTable->setItem(row, 1, new QTableWidgetItem(QString::number(item.idEquipe)));
        ui->performanceRankingTable->setItem(row, 2, new QTableWidgetItem(item.nomEquipe));
        ui->performanceRankingTable->setItem(row, 3, new QTableWidgetItem(QString::number(item.rate, 'f', 2)));
        ++row;
    }
}

void MainWindow::updateEquipeDetailsStats()
{
    if (!ui->lineEdit_teamDetailsId) {
        return;
    }

    const QString idText = ui->lineEdit_teamDetailsId->text().trimmed();
    if (idText.isEmpty()) {
        ui->selectedTeamDetailsLabel->setText("Equipe selectionnee: Aucune");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
        return;
    }

    bool ok = false;
    const int idEquipe = idText.toInt(&ok);
    if (!ok) {
        ui->selectedTeamDetailsLabel->setText("Equipe selectionnee: ID invalide");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
        return;
    }

    const int index = findEquipeIndexById(idEquipe);
    if (index < 0) {
        ui->selectedTeamDetailsLabel->setText("Equipe selectionnee: Introuvable");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
        return;
    }

    const EquipeData &team = m_equipes.at(index);
    EquipeDetailsStatData details;
    QString serviceError;
    if (!EquipeRepository::calculerDetails(team, &details, &serviceError)) {
        QMessageBox::warning(this, "Equipe", serviceError);
        return;
    }

    ui->selectedTeamDetailsLabel->setText(
        QString("Equipe selectionnee: %1, ID: %2").arg(team.nomEquipe).arg(team.idEquipe));
    ui->completedTasksValueLabel->setText(QString::number(details.successCount));
    ui->failedTasksValueLabel->setText(QString::number(details.failureCount));
    ui->teamRateValueLabel->setText(QString::number(details.rateValue, 'f', 2));
    ui->teamFeedbackLabel->setText("Feedback: " + details.feedback);
}

void MainWindow::clearEquipeAddInputs()
{
    ui->lineEditNomEquipeAjout->clear();
    ui->comboBoxSpecialiteEquipeAjout->setCurrentIndex(-1);
    ui->comboBoxNbMembresEquipeAjout->setCurrentIndex(-1);
    ui->comboBox_add_etat->setCurrentIndex(-1);
}

void MainWindow::clearEquipeModifyInputs()
{
    ui->lineEdit_modif_id->clear();
    ui->lineEditNomEquipeModif->clear();
    ui->comboBoxSpecialiteEquipeModif->setCurrentIndex(-1);
    ui->comboBoxNbMembresEquipeModif->setCurrentIndex(-1);
    ui->comboBox_mod_etat->setCurrentIndex(-1);
}

bool MainWindow::parseEquipeId(const QString &idText, int &idOut, const QString &emptyMessage)
{
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Validation", emptyMessage);
        return false;
    }

    bool ok = false;
    idOut = idText.toInt(&ok);
    if (!ok || idOut <= 0) {
        QMessageBox::warning(this, "Validation", "L'ID doit etre un nombre positif.");
        return false;
    }
    return true;
}

int MainWindow::findEquipeIndexById(int idEquipe) const
{
    for (int i = 0; i < m_equipes.size(); ++i) {
        if (m_equipes.at(i).idEquipe == idEquipe) {
            return i;
        }
    }
    return -1;
}

void MainWindow::ajouterEquipe()
{
    const QString nom = ui->lineEditNomEquipeAjout->text().trimmed();
    const QString specialiteUi = ui->comboBoxSpecialiteEquipeAjout->currentText().trimmed();
    const QString membresUi = ui->comboBoxNbMembresEquipeAjout->currentText().trimmed();
    const QString etatUi = ui->comboBox_add_etat->currentText().trimmed();

    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom de l'equipe est requis.");
        return;
    }

    if (ui->comboBoxSpecialiteEquipeAjout->currentIndex() < 0) {
        QMessageBox::warning(this, "Validation", "Veuillez selectionner une specialite.");
        return;
    }

    if (ui->comboBoxNbMembresEquipeAjout->currentIndex() < 0) {
        QMessageBox::warning(this, "Validation", "Veuillez selectionner le nombre de membres.");
        return;
    }

    if (ui->comboBox_add_etat->currentIndex() < 0) {
        QMessageBox::warning(this, "Validation", "Veuillez selectionner l'etat.");
        return;
    }

    QString dbError;
    EquipeData data;
    if (!EquipeRepository::prochainIdEquipe(&data.idEquipe, &dbError)) {
        QMessageBox::critical(this, "Erreur", "Impossible de calculer le prochain ID:\n" + dbError);
        return;
    }

    data.nomEquipe = nom;

    if (!EquipeRepository::normaliserSpecialite(specialiteUi, &data.specialite, &dbError)) {
        QMessageBox::warning(this, "Validation", dbError);
        return;
    }

    bool ok = false;
    data.nbreMembres = membresUi.toInt(&ok);
    if (!ok || data.nbreMembres <= 0) {
        QMessageBox::warning(this, "Validation", "Nombre de membres invalide.");
        return;
    }

    if (!EquipeRepository::normaliserEtat(etatUi, &data.etat, &dbError)) {
        QMessageBox::warning(this, "Validation", dbError);
        return;
    }

    data.rate = "0";

    if (!EquipeRepository::ajouterEquipe(data, &dbError)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout:\n" + dbError);
        return;
    }

    QMessageBox::information(this, "Succes", "Equipe ajoutee avec succes.");
    refreshEquipeTable();
    clearEquipeAddInputs();
}

void MainWindow::modifierEquipe()
{
    refreshEquipeTable();

    int idEquipe = 0;
    if (!parseEquipeId(ui->lineEdit_modif_id->text().trimmed(), idEquipe,
                       "Veuillez saisir l'ID de l'equipe a modifier.")) {
        return;
    }

    const int index = findEquipeIndexById(idEquipe);
    if (index < 0) {
        QMessageBox::information(this, "Modifier", "Aucune equipe trouvee avec cet ID.");
        return;
    }

    EquipeData updated = m_equipes.at(index);

    const QString newNom = ui->lineEditNomEquipeModif->text().trimmed();
    const QString newSpecialite = ui->comboBoxSpecialiteEquipeModif->currentText().trimmed();
    const QString newMembres = ui->comboBoxNbMembresEquipeModif->currentText().trimmed();
    const QString newEtat = ui->comboBox_mod_etat->currentText().trimmed();

    QString dbError;
    if (!newNom.isEmpty()) {
        updated.nomEquipe = newNom;
    }

    if (ui->comboBoxSpecialiteEquipeModif->currentIndex() >= 0) {
        if (!EquipeRepository::normaliserSpecialite(newSpecialite, &updated.specialite, &dbError)) {
            QMessageBox::warning(this, "Validation", dbError);
            return;
        }
    }

    if (ui->comboBoxNbMembresEquipeModif->currentIndex() >= 0) {
        bool ok = false;
        updated.nbreMembres = newMembres.toInt(&ok);
        if (!ok || updated.nbreMembres <= 0) {
            QMessageBox::warning(this, "Validation", "Nombre de membres invalide.");
            return;
        }
    }

    if (ui->comboBox_mod_etat->currentIndex() >= 0) {
        if (!EquipeRepository::normaliserEtat(newEtat, &updated.etat, &dbError)) {
            QMessageBox::warning(this, "Validation", dbError);
            return;
        }
    }

    int rowsAffected = 0;
    if (!EquipeRepository::modifierEquipe(updated, &rowsAffected, &dbError)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification:\n" + dbError);
        return;
    }

    if (rowsAffected <= 0) {
        QMessageBox::warning(this, "Erreur", "Aucune equipe modifiee.");
        return;
    }

    QMessageBox::information(this, "Succes", "Equipe modifiee avec succes.");
    refreshEquipeTable();
    clearEquipeModifyInputs();
}

void MainWindow::supprimerEquipe()
{
    refreshEquipeTable();

    int idEquipe = 0;
    if (!parseEquipeId(ui->lineEditIdEquipeSuppression->text().trimmed(), idEquipe,
                       "Veuillez saisir l'ID de l'equipe a supprimer.")) {
        return;
    }

    if (findEquipeIndexById(idEquipe) < 0) {
        QMessageBox::information(this, "Supprimer", "Aucune equipe trouvee avec cet ID.");
        return;
    }

    const QMessageBox::StandardButton reply = QMessageBox::question(
        this,
        "Confirmation",
        "Etes-vous sur de vouloir supprimer cette equipe ?",
        QMessageBox::Yes | QMessageBox::No);

    if (reply != QMessageBox::Yes) {
        return;
    }

    int rowsAffected = 0;
    QString dbError;
    if (!EquipeRepository::supprimerEquipe(idEquipe, &rowsAffected, &dbError)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression:\n" + dbError);
        return;
    }

    if (rowsAffected <= 0) {
        QMessageBox::warning(this, "Erreur", "Aucune equipe supprimee.");
        return;
    }

    QMessageBox::information(this, "Succes", "Equipe supprimee avec succes.");
    ui->lineEditIdEquipeSuppression->clear();
    refreshEquipeTable();
}

void MainWindow::rechercherEquipe()
{
    refreshEquipeTable();

    const QString searchText = ui->lineEditRechercheEquipe->text().trimmed();
    const QString category = ui->comboBoxFilter->currentText();

    if (searchText.isEmpty()) {
        return;
    }

    ui->tableWidgetEquipe->setRowCount(0);
    int row = 0;

    for (const EquipeData &team : m_equipes) {
        bool matches = false;
        if (category == "ID") {
            matches = QString::number(team.idEquipe).contains(searchText, Qt::CaseInsensitive);
        } else if (category == "Nom") {
            matches = team.nomEquipe.contains(searchText, Qt::CaseInsensitive);
        } else if (category == "Spécialité") {
            matches = team.specialite.contains(searchText, Qt::CaseInsensitive);
        } else if (category == "Membres") {
            matches = QString::number(team.nbreMembres).contains(searchText, Qt::CaseInsensitive);
        } else if (category == "État") {
            matches = team.etat.contains(searchText, Qt::CaseInsensitive);
        }

        if (!matches) {
            continue;
        }

        EquipeRateData rateData;
        QString serviceError;
        if (!EquipeRepository::extraireRateData(team.rate, &rateData, &serviceError)) {
            QMessageBox::warning(this, "Equipe", serviceError);
            return;
        }
        ui->tableWidgetEquipe->insertRow(row);
        ui->tableWidgetEquipe->setItem(row, 0, new QTableWidgetItem(QString::number(team.idEquipe)));
        ui->tableWidgetEquipe->setItem(row, 1, new QTableWidgetItem(team.nomEquipe));
        ui->tableWidgetEquipe->setItem(row, 2, new QTableWidgetItem(team.specialite));
        ui->tableWidgetEquipe->setItem(row, 3, new QTableWidgetItem(QString::number(team.nbreMembres)));
        ui->tableWidgetEquipe->setItem(row, 4, new QTableWidgetItem(team.etat));
        ui->tableWidgetEquipe->setItem(row, 5, new QTableWidgetItem(QString::number(rateData.rateValue, 'f', 2)));
        ++row;
    }
}

void MainWindow::trierEquipe()
{
    const QString selectedCategory = ui->comboBoxTriEquipe->currentText();
    const bool ascending = ui->checkBoxTriEquipeCroissant->isChecked() || !ui->checkBoxTriEquipeDecroissant->isChecked();

    int column = 1;
    bool numericSort = false;

    if (selectedCategory == "ID") {
        column = 0;
        numericSort = true;
    } else if (selectedCategory == "Nom") {
        column = 1;
    } else if (selectedCategory == "Spécialité" || selectedCategory == "Specialité") {
        column = 2;
    } else if (selectedCategory == "Membres") {
        column = 3;
        numericSort = true;
    } else if (selectedCategory == "État" || selectedCategory == "Etat") {
        column = 4;
    } else if (selectedCategory == "Rate") {
        column = 5;
        numericSort = true;
    }

    struct TableRow {
        QStringList values;
    };

    QVector<TableRow> rows;
    rows.reserve(ui->tableWidgetEquipe->rowCount());

    for (int row = 0; row < ui->tableWidgetEquipe->rowCount(); ++row) {
        TableRow tableRow;
        for (int col = 0; col < ui->tableWidgetEquipe->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidgetEquipe->item(row, col);
            tableRow.values.append(item ? item->text() : QString());
        }
        rows.append(tableRow);
    }

    std::sort(rows.begin(), rows.end(), [column, numericSort, ascending](const TableRow &a, const TableRow &b) {
        if (numericSort) {
            bool okA = false;
            bool okB = false;
            const double valueA = a.values[column].toDouble(&okA);
            const double valueB = b.values[column].toDouble(&okB);
            if (okA && okB) {
                return ascending ? (valueA < valueB) : (valueA > valueB);
            }
        }

        const int cmp = QString::localeAwareCompare(a.values[column], b.values[column]);
        return ascending ? (cmp < 0) : (cmp > 0);
    });

    ui->tableWidgetEquipe->setRowCount(0);
    for (int row = 0; row < rows.size(); ++row) {
        ui->tableWidgetEquipe->insertRow(row);
        for (int col = 0; col < rows[row].values.size(); ++col) {
            ui->tableWidgetEquipe->setItem(row, col, new QTableWidgetItem(rows[row].values[col]));
        }
    }
}

void MainWindow::onEquipeTriCroissantToggled(bool checked)
{
    if (checked) {
        ui->checkBoxTriEquipeDecroissant->setChecked(false);
    } else if (!ui->checkBoxTriEquipeDecroissant->isChecked()) {
        ui->checkBoxTriEquipeCroissant->setChecked(true);
    }
}

void MainWindow::onEquipeTriDecroissantToggled(bool checked)
{
    if (checked) {
        ui->checkBoxTriEquipeCroissant->setChecked(false);
    } else if (!ui->checkBoxTriEquipeCroissant->isChecked()) {
        ui->checkBoxTriEquipeDecroissant->setChecked(true);
    }
}

// === MODULE CLIENT ===
// Zone reservee aux methodes du module Client.

// === MODULE LABO ===
// Zone reservee aux methodes du module Laboratoire.

void MainWindow::ajouterLabo()
{
    // Validate form
    QString nomLabo = ui->lineEdit_nom1->text().trimmed();
    if (nomLabo.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom du laboratoire est obligatoire.");
        return;
    }

    QString resultats = ui->lineEdit_resultats->text().trimmed();
    if (resultats.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Les résultats sont obligatoires.");
        return;
    }

    QString adresse = ui->lineEdit_adresse->text().trimmed();
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, "Validation", "L'adresse est obligatoire.");
        return;
    }

    // Create data and normalize conformite to satisfy DB constraint
    QString conformite = ui->comboBox_conformite->currentText().trimmed().toLower();
    if (conformite != "oui" && conformite != "non") {
        QMessageBox::warning(this, "Validation", "La conformité doit être 'oui' ou 'non'.");
        return;
    }

    int espaceLabo = ui->spinBox_espace_labo->value();
    int espaceReste = ui->spinBox_espace_reste->value();
    if (espaceLabo <= espaceReste) {
        QMessageBox::warning(this, "Validation", "L'espace labo doit être supérieur à l'espace restant.");
        return;
    }

    bool okReview;
    int review = ui->lineEdit_review->text().trimmed().toInt(&okReview);
    if (!okReview || review < 0 || review > 10) {
        QMessageBox::warning(this, "Validation", "La note REVIEW doit être un entier entre 0 et 10.");
        return;
    }

    LaboData data;
    data.nomLabo = nomLabo;
    data.resultats = resultats;
    data.conformite = conformite;
    data.adresse = adresse;
    data.espaceLabo = espaceLabo;
    data.espaceReste = espaceReste;
    data.review = review;

    // Add to repository
    QString errorMessage;
    if (LaboRepository::addLabo(data, &errorMessage)) {
        QMessageBox::information(this, "Succès", "Laboratoire ajouté avec succès.");
        // Clear form
        ui->lineEdit_nom1->clear();
        ui->lineEdit_resultats->clear();
        ui->lineEdit_adresse->clear();
        ui->spinBox_espace_labo->setValue(0);
        ui->spinBox_espace_reste->setValue(0);
        ui->lineEdit_review->clear();
        ui->comboBox_conformite->setCurrentIndex(0);
        ui->lineEdit_id1->clear();
        // Refresh display
        afficherLabos();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout:\n" + errorMessage);
    }
}

void MainWindow::afficherLabos()
{
    QList<LaboData> labos;
    QString errorMessage;
    if (!LaboRepository::listLabos(&labos, &errorMessage)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement des laboratoires:\n" + errorMessage);
        return;
    }

    ui->tableWidgetLabo->setRowCount(labos.size());
    for (int row = 0; row < labos.size(); ++row) {
        const LaboData &labo = labos[row];

        auto *idItem = new QTableWidgetItem(formatLaboId(labo.idLabo));
        idItem->setData(Qt::UserRole, labo.idLabo);
        idItem->setData(Qt::EditRole, labo.idLabo);
        ui->tableWidgetLabo->setItem(row, 0, idItem);

        ui->tableWidgetLabo->setItem(row, 1, new QTableWidgetItem(labo.nomLabo));
        ui->tableWidgetLabo->setItem(row, 2, new QTableWidgetItem(labo.resultats));
        ui->tableWidgetLabo->setItem(row, 3, new QTableWidgetItem(labo.conformite));
        ui->tableWidgetLabo->setItem(row, 4, new QTableWidgetItem(labo.adresse));

        auto *espaceLaboItem = new QTableWidgetItem(QString::number(labo.espaceLabo) + " m²");
        espaceLaboItem->setData(Qt::UserRole, labo.espaceLabo);
        espaceLaboItem->setData(Qt::EditRole, labo.espaceLabo);
        ui->tableWidgetLabo->setItem(row, 5, espaceLaboItem);

        auto *espaceResteItem = new QTableWidgetItem(QString::number(labo.espaceReste) + " m²");
        espaceResteItem->setData(Qt::UserRole, labo.espaceReste);
        espaceResteItem->setData(Qt::EditRole, labo.espaceReste);
        ui->tableWidgetLabo->setItem(row, 6, espaceResteItem);

        auto *reviewItem = new QTableWidgetItem(QString::number(labo.review) + "/10");
        reviewItem->setData(Qt::UserRole, labo.review);
        reviewItem->setData(Qt::EditRole, labo.review);
        ui->tableWidgetLabo->setItem(row, 7, reviewItem);
    }
    ui->tableWidgetLabo->resizeColumnsToContents();
    ui->tableWidgetLabo->horizontalHeader()->setStretchLastSection(true);
}

void MainWindow::supprimerLabo()
{
    QString idLaboStr = ui->lineEditIdLaboSuppression->text().trimmed();
    if (idLaboStr.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir l'ID du laboratoire à supprimer.");
        return;
    }

    int idLabo = parseLaboId(idLaboStr);
    if (idLabo <= 0) {
        QMessageBox::warning(this, "Validation", "ID du laboratoire invalide.");
        return;
    }

    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation",
        QString("Êtes-vous sûr de vouloir supprimer le laboratoire %1 ?").arg(idLabo),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply != QMessageBox::Yes) {
        return;
    }

    int rowsAffected = 0;
    QString errorMessage;
    if (LaboRepository::deleteLabo(idLabo, &rowsAffected, &errorMessage)) {
        if (rowsAffected > 0) {
            QMessageBox::information(this, "Succès", "Laboratoire supprimé avec succès.");
            ui->lineEditIdLaboSuppression->clear();
            afficherLabos();
        } else {
            QMessageBox::warning(this, "Erreur", "Laboratoire non trouvé.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression:\n" + errorMessage);
    }
}

void MainWindow::modifierLabo()
{
    QString idLaboStr = ui->lineEdit_modif_id1->text().trimmed();
    if (idLaboStr.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir l'ID du laboratoire à modifier.");
        return;
    }

    int idLabo = parseLaboId(idLaboStr);
    if (idLabo <= 0) {
        QMessageBox::warning(this, "Validation", "ID du laboratoire invalide.");
        return;
    }

    // Validate form
    QString nomLabo = ui->lineEditNomLaboModif->text().trimmed();
    if (nomLabo.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom du laboratoire est obligatoire.");
        return;
    }

    QString resultats = ui->lineEditResultatsLaboModif->text().trimmed();
    if (resultats.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Les résultats sont obligatoires.");
        return;
    }

    QString adresse = ui->lineEditAdresseLaboModif->text().trimmed();
    if (adresse.isEmpty()) {
        QMessageBox::warning(this, "Validation", "L'adresse est obligatoire.");
        return;
    }

    // Create updated data and normalize conformite to satisfy DB constraint
    QString conformite = ui->comboBox_modif_conf->currentText().trimmed().toLower();
    if (conformite != "oui" && conformite != "non") {
        QMessageBox::warning(this, "Validation", "La conformité doit être 'oui' ou 'non'.");
        return;
    }

    int espaceLabo = ui->spinBox_espace_labo_modif->value();
    int espaceReste = ui->spinBox_espace_reste_modif->value();
    if (espaceLabo <= espaceReste) {
        QMessageBox::warning(this, "Validation", "L'espace labo doit être supérieur à l'espace restant.");
        return;
    }

    bool okReview;
    int review = ui->lineEditReviewLaboModif->text().trimmed().toInt(&okReview);
    if (!okReview || review < 0 || review > 10) {
        QMessageBox::warning(this, "Validation", "La note REVIEW doit être un entier entre 0 et 10.");
        return;
    }

    LaboData data;
    data.idLabo = idLabo;
    data.nomLabo = nomLabo;
    data.resultats = resultats;
    data.conformite = conformite;
    data.adresse = adresse;
    data.espaceLabo = espaceLabo;
    data.espaceReste = espaceReste;
    data.review = review;

    // Update in repository
    int rowsAffected = 0;
    QString errorMessage;
    if (LaboRepository::updateLabo(idLabo, data, &rowsAffected, &errorMessage)) {
        if (rowsAffected > 0) {
            QMessageBox::information(this, "Succès", "Laboratoire modifié avec succès.");
            // Clear form
            ui->lineEdit_modif_id1->clear();
            ui->lineEditNomLaboModif->clear();
            ui->lineEditResultatsLaboModif->clear();
            ui->lineEditAdresseLaboModif->clear();
            ui->spinBox_espace_labo_modif->setValue(0);
            ui->spinBox_espace_reste_modif->setValue(0);
            ui->lineEditReviewLaboModif->clear();
            ui->comboBox_modif_conf->setCurrentIndex(0);
            // Refresh display
            afficherLabos();
        } else {
            QMessageBox::warning(this, "Erreur", "Laboratoire non trouvé.");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification:\n" + errorMessage);
    }
}

void MainWindow::chargerLaboPourModification()
{
    QString idLaboStr = ui->lineEdit_modif_id1->text().trimmed();
    if (idLaboStr.isEmpty()) {
        return;
    }

    int idLabo = parseLaboId(idLaboStr);
    if (idLabo <= 0) {
        QMessageBox::warning(this, "Erreur", "ID du laboratoire invalide.");
        return;
    }
    ui->lineEdit_modif_id1->setText(formatLaboId(idLabo));

    LaboData data;
    QString errorMessage;
    if (LaboRepository::getLaboById(idLabo, &data, &errorMessage)) {
        ui->lineEditNomLaboModif->setText(data.nomLabo);
        ui->lineEditResultatsLaboModif->setText(data.resultats);
        ui->comboBox_modif_conf->setCurrentText(data.conformite);
        ui->lineEditAdresseLaboModif->setText(data.adresse);
        ui->spinBox_espace_labo_modif->setValue(data.espaceLabo);
        ui->spinBox_espace_reste_modif->setValue(data.espaceReste);
        ui->lineEditReviewLaboModif->setText(QString::number(data.review));
    } else {
        QMessageBox::warning(this, "Erreur", "Laboratoire non trouvé:\n" + errorMessage);
        // Clear form
        ui->lineEditNomLaboModif->clear();
        ui->lineEditResultatsLaboModif->clear();
        ui->lineEditAdresseLaboModif->clear();
        ui->spinBox_espace_labo_modif->setValue(0);
        ui->spinBox_espace_reste_modif->setValue(0);
        ui->lineEditReviewLaboModif->clear();
    }
}

// === MODULE COMMANDE ===
void MainWindow::setupCommandeConnections()
{
    // Aligner les libelles avec la contrainte Oracle COMMENDE_CHK2
    ui->comboLibelle->clear();
    ui->comboLibelle->addItem("Achat");
    ui->comboLibelle->addItem("Service");
    ui->comboLibelle->addItem("Maintenance");
    ui->comboLibelle->addItem("Urgente");
    ui->comboLibelle->addItem("Autre");

    // Aligner les statuts avec COMMENDE_CHK1
    ui->comboStatut->clear();
    ui->comboStatut->addItem("en cours");
    ui->comboStatut->addItem("validee");
    ui->comboStatut->addItem("prete");
    ui->comboStatut->addItem("annulee");

    ui->comboStatutModif->clear();
    ui->comboStatutModif->addItem("en cours");
    ui->comboStatutModif->addItem("validee");
    ui->comboStatutModif->addItem("prete");
    ui->comboStatutModif->addItem("annulee");

    // CRUD Commandes
    connect(ui->btnAjouter_cmd, &QPushButton::clicked, this, &MainWindow::onAjouterCommande);
    connect(ui->btnResetAjouter, &QPushButton::clicked, this, &MainWindow::onResetAjouter);
    connect(ui->btnSupprimerConfirm_cmd, &QPushButton::clicked, this, &MainWindow::onSupprimerCommande);
    connect(ui->btnModifierConfirm_cmd, &QPushButton::clicked, this, &MainWindow::onModifierCommande);

    // Export PDF
    connect(ui->btnExportListeComplete_cmd, &QPushButton::clicked, this, &MainWindow::exportPDF);
    connect(ui->btnExportRapport, &QPushButton::clicked, this, &MainWindow::exportPDF);
    connect(ui->btnExportFiche, &QPushButton::clicked, this, &MainWindow::exportPDF);

    // Filtres
    connect(ui->checkFiltreTous, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreAttente, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreConfirmee, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreExpedie, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);
    connect(ui->checkFiltreLivree, &QCheckBox::toggled, this, &MainWindow::refreshTableCommandes);

    // Recherche et tri
    connect(ui->btnAppliquerRecherche, &QPushButton::clicked, this, &MainWindow::onApplySearch);
    connect(ui->btnReinitialiserRecherche, &QPushButton::clicked, this, &MainWindow::onResetSearch);
    connect(ui->comboTriPar, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onApplySorting);

    // Calendrier
    connect(ui->btnAfficherCalendrier, &QPushButton::clicked, this, &MainWindow::onDisplayCalendar);

    // Notifications email
    connect(ui->btnEnvoyerEmail, &QPushButton::clicked, this, &MainWindow::onSendEmailNotification);
    connect(ui->checkEmailAutomatic, &QCheckBox::toggled, this, &MainWindow::onEnableEmailNotification);
}



    


void MainWindow::onAjouterCommande()
{
    int id = ui->lineNumCommande->text().toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Le numero de commande doit etre non nul.");
        return;
    }

    int idClient = ui->comboClient->currentData().toInt();
    if (idClient == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez selectionner un client valide.");
        return;
    }

    if (!Ccommande::clientExists(idClient)) {
        QMessageBox::critical(this, "Client invalide",
                              QString("L'ID client %1 n'existe pas dans la table CLIENT.").arg(idClient));
        loadClients();
        return;
    }

    QString libelle = ui->comboLibelle->currentText().trimmed();
    const QStringList libellesValides = {"Achat", "Service", "Maintenance", "Urgente", "Autre"};
    if (!libellesValides.contains(libelle)) {
        QMessageBox::warning(this, "Erreur", "Libelle invalide pour la base de donnees.");
        return;
    }

    int quantite = ui->spinQuantite->value();
    double prixUnitaire = ui->spinPrix->value();

    if (quantite <= 0) {
        QMessageBox::warning(this, "Erreur", "La quantite doit etre superieure a zero.");
        return;
    }
    if (prixUnitaire <= 0.0) {
        QMessageBox::warning(this, "Erreur", "Le prix unitaire doit etre superieur a zero.");
        return;
    }

    double montantTotal = prixUnitaire * quantite;

    const QString etatUi = ui->comboStatut->currentText().trimmed();
    if (!isEtatAllowed(etatUi)) {
        QMessageBox::warning(this, "Erreur", "Statut invalide.");
        return;
    }
    const QString etat = toDbEtatValue(etatUi);

    QDate dateArrivage = QDate::fromString(ui->lineDate->text(), "dd/MM/yyyy");
    if (!dateArrivage.isValid()) {
        dateArrivage = QDate::currentDate();
        ui->lineDate->setText(dateArrivage.toString("dd/MM/yyyy"));
    }
    QDate dateSortie = dateArrivage;

    Ccommande cmd(id, libelle, dateArrivage, dateSortie, etat, quantite, montantTotal, idClient);

    if (Ccommande::ajouter(cmd)) {
        QMessageBox::information(this, "Succes", "Commande sauvegardee.");
        refreshTableCommandes();
        updateStatistics();
        refreshAllCharts();
        onResetAjouter();

        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur BD", "Echec de l'ajout. Consultez la console pour le detail.");
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
        QMessageBox::information(this, "Succes", "Commande supprimee.");
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
        QMessageBox::critical(this, "Erreur", "Echec de la suppression.");
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
        QMessageBox::warning(this, "Erreur", "La quantite doit etre superieure a 0.");
        return;
    }

    const QString nouvelEtatUi = ui->comboStatutModif->currentText().trimmed();
    if (!isEtatAllowed(nouvelEtatUi)) {
        QMessageBox::warning(this, "Erreur", "L'etat selectionne n'est pas valide.");
        return;
    }
    const QString nouvelEtat = toDbEtatValue(nouvelEtatUi);

    Ccommande newCmd = oldCmd;
    newCmd.setEtat(nouvelEtat);
    newCmd.setQuantite(nouvelleQuantite);

    if (Ccommande::modifier(id, newCmd)) {
        QMessageBox::information(this, "Succes", "Commande modifiee.");
        refreshTableCommandes();
        updateStatistics();
        refreshAllCharts();
        ui->lineIdMod->clear();

        if (m_searchActive) {
            onApplySearch();
        } else {
            applySortingAndDisplay(Ccommande::getAll());
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Echec modification.");
    }
}
void MainWindow::onApplySearch()
{
    QDate debut = ui->dateSearchDebut->date();
    QDate fin = ui->dateSearchFin->date();

    QString texteClient = ui->lineSearchClient->text().trimmed();
    int idClient = texteClient.toInt();
    QString nomClient = (idClient == 0) ? texteClient : QString();
    QString etat = "";

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
        ui->tableResultatsRecherche->setItem(i, 5, new QTableWidgetItem(displayEtatLabel(cmd.getEtat())));
    }
}

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
            const QString e = normalizeEtatValue(cmd.getEtat());
            if ((filtreEnCours && e == "en cours") ||
                (filtreValide  && e == "validee")  ||
                (filtrePrete   && e == "prete")    ||
                (filtreLivree  && e == "annulee")) {
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
        ui->tableCommandes->setItem(i, 4, new QTableWidgetItem(displayEtatLabel(cmd.getEtat())));
        ui->tableCommandes->setItem(i, 5, new QTableWidgetItem(cmd.getDateArrivage().toString("dd/MM/yyyy")));
    }
}

void MainWindow::updateStatistics()
{
    int total = Ccommande::getTotalCommandes();
    double montantTotal = Ccommande::getMontantTotalGlobal();
    double moyenne = Ccommande::getMoyenneMontant();

    QMap<QString, int> etats = Ccommande::getNbCommandesParEtat();
    int enAttente = 0;
    for (auto it = etats.begin(); it != etats.end(); ++it) {
        if (normalizeEtatValue(it.key()) == "en cours") {
            enAttente += it.value();
        }
    }


    ui->lineRevenuTotal->setText(QString::number(montantTotal, 'f', 2) + " EUR");
    ui->lineMoyenneCmd->setText(QString::number(moyenne, 'f', 2) + " EUR");

    QMap<QString, double> moisMontant = Ccommande::getMontantParMois();
    QMap<QString, int> moisNb = Ccommande::getNbCommandesParMois();


    int row = 0;
    for (auto it = moisMontant.begin(); it != moisMontant.end(); ++it, ++row) {

    }

    auto produits = Ccommande::getProduitsPlusCommandes(10);

    for (int i = 0; i < produits.size(); ++i) {

    }
}

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
        const QString etat = normalizeEtatValue(cmd.getEtat());
        if (etat == "en cours") couleur = "[Rouge]";
        else if (etat == "validee") couleur = "[Orange]";
        else if (etat == "prete") couleur = "[Jaune]";
        else if (etat == "annulee") couleur = "[Blanc]";
        else couleur = "[N/A]";

        ui->listAlertes->addItem(QString("%1 Commande #%2 - %3 (%4)")
                                     .arg(couleur)
                                     .arg(cmd.getIdCommande())
                                     .arg(cmd.getLibelle())
                                     .arg(cmd.getDateArrivage().toString("dd/MM")));
    }
    updateCalendarColors(month, year);
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
    const QString e = normalizeEtatValue(etat);
    if (e == "en cours") return QColor(255, 99, 71);
    if (e == "validee")  return QColor(255, 165, 0);
    if (e == "prete")    return QColor(255, 255, 0);
    if (e == "annulee")  return QColor(211, 211, 211);
    return QColor(255, 255, 255);
}

int MainWindow::getPriorityForEtat(const QString &etat) const
{
    const QString e = normalizeEtatValue(etat);
    if (e == "en cours") return 4;
    if (e == "validee")  return 3;
    if (e == "prete")    return 2;
    if (e == "annulee")  return 1;
    return 0;
}

void MainWindow::sendEmailViaBrevo(const QString &to, const QString &subject, const QString &htmlBody)
{
    const QString apiKey = "git";
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
void MainWindow::loadClients()
{
    QVector<QPair<int, QString>> clients = Ccommande::getClientList();
    ui->comboClient->clear();
    ui->comboClient->addItem("Selectionnez un client", 0);
    for (const auto &client : clients) {
        const QString nom = client.second.trimmed();
        const QString label = nom.isEmpty()
                                  ? QString("Client #%1").arg(client.first)
                                  : QString("%1 - %2").arg(client.first).arg(nom);
        ui->comboClient->addItem(label, client.first);
    }
    qDebug() << "Clients charges dans comboClient:" << clients.size();
}
void MainWindow::onBrevoReplyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        qDebug() << "Email envoyé avec succès via Brevo";
    } else {
        qDebug() << "Erreur d'envoi Brevo:" << reply->errorString();
        qDebug() << "Réponse:" << reply->readAll();
        QMessageBox::warning(this, "Erreur d'envoi",
                             "Échec de l'envoi de l'email : " + reply->errorString());
    }
    reply->deleteLater();
}

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
        QMessageBox::information(this, "Notifications", "Notifications automatiques activees!");
    } else {
        QMessageBox::information(this, "Notifications", "Notifications automatiques desactivees!");
    }
}
void MainWindow::exportPDF()
{
    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    const QString buttonName = button->objectName();
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
    if (buttonName == "btnExportListeComplete_cmd") {
        html = buildHtmlListeComplete(ordersToExport);
    } else if (buttonName == "btnExportRapport") {
        html = buildHtmlRapport(ordersToExport);
    } else if (buttonName == "btnExportFiche") {
        int currentRow = ui->tableCommandes->currentRow();
        if (currentRow < 0) {
            QMessageBox::warning(this, "Erreur", "Veuillez selectionner une commande dans la liste.");
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
    if (buttonName == "btnExportFiche") {
        printer.setPageOrientation(QPageLayout::Portrait);
    } else {
        printer.setPageOrientation(QPageLayout::Landscape);
    }

    QTextDocument doc;
    doc.setHtml(html);
    doc.setPageSize(printer.pageRect(QPrinter::Point).size());
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "PDF genere avec succes : " + fileName);
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
    html += "<h1>Liste complete des commandes</h1>";
    html += "<table>";
    html += "<tr><th>ID</th><th>Client</th><th>Libelle</th><th>Quantite</th><th>Montant</th><th>Statut</th><th>Date arrivage</th></tr>";

    for (const Ccommande& cmd : orders) {
        html += "<tr>";
        html += "<td>" + QString::number(cmd.getIdCommande()) + "</td>";
        html += "<td>" + QString::number(cmd.getIdClient()) + "</td>";
        html += "<td>" + cmd.getLibelle().toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(cmd.getQuantite()) + "</td>";
        html += "<td>" + QString::number(cmd.getMontantTotal(), 'f', 2) + "</td>";
        html += "<td>" + cmd.getEtat().toHtmlEscaped() + "</td>";
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

    int enCours = 0, validee = 0, prete = 0, annulee = 0;
    for (const Ccommande& cmd : orders) {
        const QString e = normalizeEtatValue(cmd.getEtat());
        if (e == "en cours") enCours++;
        else if (e == "validee") validee++;
        else if (e == "prete") prete++;
        else if (e == "annulee") annulee++;
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
    html += "<p><span class='stat'>Montant total :</span> " + QString::number(montantTotal, 'f', 2) + " EUR</p>";
    html += "<p><span class='stat'>Moyenne par commande :</span> " + QString::number(moyenne, 'f', 2) + " EUR</p>";

    html += "<h2>Repartition par statut</h2>";
    html += "<table>";
    html += "<tr><th>Statut</th><th>Nombre</th></tr>";
    html += "<tr><td>En cours</td><td>" + QString::number(enCours) + "</td></tr>";
    html += "<tr><td>Validee</td><td>" + QString::number(validee) + "</td></tr>";
    html += "<tr><td>Prete</td><td>" + QString::number(prete) + "</td></tr>";
    html += "<tr><td>Annulee</td><td>" + QString::number(annulee) + "</td></tr>";
    html += "</table>";

    html += "<h2>Dernieres commandes</h2>";
    html += "<table>";
    html += "<tr><th>ID</th><th>Client</th><th>Libelle</th><th>Montant</th><th>Statut</th><th>Date</th></tr>";
    int count = 0;
    for (int i = orders.size() - 1; i >= 0 && count < 10; --i, ++count) {
        const Ccommande& cmd = orders[i];
        html += "<tr>";
        html += "<td>" + QString::number(cmd.getIdCommande()) + "</td>";
        html += "<td>" + QString::number(cmd.getIdClient()) + "</td>";
        html += "<td>" + cmd.getLibelle().toHtmlEscaped() + "</td>";
        html += "<td>" + QString::number(cmd.getMontantTotal(), 'f', 2) + "</td>";
        html += "<td>" + cmd.getEtat().toHtmlEscaped() + "</td>";
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
                   "table { border-collapse: collapse; width: 50%; margin: auto; }"
                   "td { border: 1px solid #ddd; padding: 8px; }"
                   ".label { background-color: #f2f2f2; }"
                   "</style></head><body>";

    html += "<h1>Fiche commande #" + QString::number(cmd.getIdCommande()) + "</h1>";
    html += "<table>";
    html += "<tr><td class='label'>ID Commande</td><td>" + QString::number(cmd.getIdCommande()) + "</td></tr>";
    html += "<tr><td class='label'>Client</td><td>" + QString::number(cmd.getIdClient()) + "</td></tr>";
    html += "<tr><td class='label'>Libelle</td><td>" + cmd.getLibelle().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td class='label'>Quantite</td><td>" + QString::number(cmd.getQuantite()) + "</td></tr>";
    html += "<tr><td class='label'>Montant total</td><td>" + QString::number(cmd.getMontantTotal(), 'f', 2) + " EUR</td></tr>";
    html += "<tr><td class='label'>Statut</td><td>" + cmd.getEtat().toHtmlEscaped() + "</td></tr>";
    html += "<tr><td class='label'>Date arrivage</td><td>" + cmd.getDateArrivage().toString("dd/MM/yyyy") + "</td></tr>";
    html += "<tr><td class='label'>Date sortie</td><td>" + cmd.getDateSortie().toString("dd/MM/yyyy") + "</td></tr>";
    html += "</table></body></html>";
    return html;
}
// === MODULE MACHINE ===
// Zone reservee aux methodes du module Machine.

static int parseMachineId(const QString &text)
{
    QString cleaned = text.trimmed();
    cleaned.remove(QRegularExpression("[^0-9]"));
    return cleaned.toInt();
}

void MainWindow::clearMachineAddForm()
{
    if (!ui->editAddId) return;
    ui->editAddId->clear();
    ui->editAddNom->clear();
    ui->comboAddCategorie->setCurrentIndex(0);
    ui->editAddReference->clear();
    ui->dateAddAchat->setDate(QDate::currentDate());
    ui->comboAddEtat->setCurrentIndex(0);
    ui->editAddLocalisation->clear();
}

void MainWindow::clearMachineModifierForm()
{
    if (!ui->editModifierId) return;
    ui->editModifierId->clear();
    ui->editModifierNom->clear();
    ui->comboModifierCategorie->setCurrentIndex(0);
    ui->editModifierReference->clear();
    ui->dateModifierAchat->setDate(QDate::currentDate());
    ui->comboModifierEtat->setCurrentIndex(0);
    ui->editModifierLocalisation->clear();
}

void MainWindow::clearMachineSuppressionForm()
{
    if (ui->lblSupprimerNom_mach) ui->lblSupprimerNom_mach->setText("Aucune machine sélectionnée");
    if (ui->lblSupprimerDetails_mach) ui->lblSupprimerDetails_mach->setText("-");
}

void MainWindow::setupMachineConnections()
{
    if (!ui->tableMachines) return;

    ui->tableMachines->setColumnCount(8);
    ui->tableMachines->setHorizontalHeaderLabels({"ID", "Nom", "Catégorie", "Référence", "Date Achat", "État", "Localisation", "Date Fin Garantie"});
    ui->tableMachines->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableMachines->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableMachines->setSelectionMode(QAbstractItemView::SingleSelection);

    connect(ui->btnConfirmerAjouter_mach, &QPushButton::clicked, this, &MainWindow::ajouterMachine);
    connect(ui->btnAnnulerAjouter_mach, &QPushButton::clicked, this, &MainWindow::clearMachineAddForm);
    connect(ui->btnConfirmerModifier_mach, &QPushButton::clicked, this, &MainWindow::modifierMachine);
    connect(ui->btnAnnulerModifier_mach, &QPushButton::clicked, this, &MainWindow::clearMachineModifierForm);

    connect(ui->btnConfirmerSupprimer_mach, &QPushButton::clicked, this, &MainWindow::supprimerMachine);
    connect(ui->btnAnnulerSupprimer_mach, &QPushButton::clicked, this, &MainWindow::clearMachineSuppressionForm);

    connect(ui->btnRefresh, &QPushButton::clicked, this, &MainWindow::afficherMachines);
    connect(ui->btnExportPDF_mach, &QPushButton::clicked, this, &MainWindow::exportMachineListePdf);
    connect(ui->btnExportStats, &QPushButton::clicked, this, &MainWindow::exportMachineStatsPdf);
    connect(ui->btnSignalerPanne, &QPushButton::clicked, this, &MainWindow::onSignalPanneMachine);

    connect(ui->tableMachines, &QTableWidget::itemSelectionChanged, this, &MainWindow::onMachineSelectionChanged);

    connect(ui->tabWidget_mach, &QTabWidget::currentChanged, this, [this](int index) {
        updateMachineToolControlsVisibility();
        applyMachineFiltersAndSorting();
        if (ui->tabWidget_mach && ui->tabStatistiques_mach && ui->tabWidget_mach->currentWidget() == ui->tabStatistiques_mach) {
            refreshMachineStats();
        }
    });

    connect(ui->btnApplyFilter, &QPushButton::clicked, this, &MainWindow::applyMachineFiltersAndSorting);
    connect(ui->lineEditSearch, &QLineEdit::textChanged, this, &MainWindow::applyMachineFiltersAndSorting);
    connect(ui->comboCategory, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::applyMachineFiltersAndSorting);
    connect(ui->comboState, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::applyMachineFiltersAndSorting);
    connect(ui->lineEditLocation, &QLineEdit::textChanged, this, &MainWindow::applyMachineFiltersAndSorting);
    connect(ui->comboSortBy, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::applyMachineFiltersAndSorting);
    connect(ui->radioCroissant, &QRadioButton::toggled, this, [this](bool) { applyMachineFiltersAndSorting(); });
    connect(ui->radioDecroissant, &QRadioButton::toggled, this, [this](bool) { applyMachineFiltersAndSorting(); });
    connect(ui->btnScanQR, &QPushButton::clicked, this, &MainWindow::scanMachineQRCode);

    updateMachineToolControlsVisibility();
}

void MainWindow::afficherMachines()
{
    applyMachineFiltersAndSorting();
}

void MainWindow::updateMachineToolControlsVisibility()
{
    if (!ui->tabWidget_mach) return;

    bool showTools = ui->tabWidget_mach->currentWidget() == ui->tabListe_mach;
    if (ui->groupBoxSearch) ui->groupBoxSearch->setVisible(showTools);
    if (ui->groupBoxSort) ui->groupBoxSort->setVisible(showTools);
    if (ui->btnScanQR) ui->btnScanQR->setVisible(showTools);
}

void MainWindow::applyMachineFiltersAndSorting()
{
    QList<MachineData> machines;
    QString error;
    if (!MachineWidget::listMachines(&machines, &error)) {
        QMessageBox::critical(this, "Erreur Machine", "Impossible de charger les machines:\n" + error);
        return;
    }

    const QString searchText = ui->lineEditSearch ? ui->lineEditSearch->text().trimmed().toLower() : QString();
    const QString selectedCategory = ui->comboCategory ? ui->comboCategory->currentText().toLower() : QString();
    const QString selectedState = ui->comboState ? ui->comboState->currentText().toLower() : QString();
    const QString locationFilter = ui->lineEditLocation ? ui->lineEditLocation->text().trimmed().toLower() : QString();

    QList<MachineData> filtered;
    for (const MachineData &mach : machines) {
        QString name = mach.nom.trimmed().toLower();
        QString reference = mach.reference.trimmed().toLower();
        QString category = mach.categorie.trimmed().toLower();
        QString etat = mach.etatAchat.trimmed().toLower();
        QString location = mach.localisation.trimmed().toLower();

        if (!searchText.isEmpty()) {
            if (!name.contains(searchText) && !reference.contains(searchText) && !location.contains(searchText)) {
                continue;
            }
        }

        if (!selectedCategory.isEmpty() && selectedCategory != "toutes" && selectedCategory != "autre") {
            if (selectedCategory != category) {
                continue;
            }
        }

        if (!selectedCategory.isEmpty() && selectedCategory == "autre") {
            if (category == "presse" || category == "moteur" || category == "filtre" || category == "capteur") {
                continue;
            }
        }

        if (!selectedState.isEmpty() && selectedState != "tous") {
            if (etat != selectedState.toLower()) {
                continue;
            }
        }

        if (!locationFilter.isEmpty() && !location.contains(locationFilter)) {
            continue;
        }

        filtered.append(mach);
    }

    const QString sortBy = ui->comboSortBy ? ui->comboSortBy->currentText().toLower() : QString();
    const bool ascending = ui->radioCroissant ? ui->radioCroissant->isChecked() : true;

    std::sort(filtered.begin(), filtered.end(), [sortBy, ascending](const MachineData &a, const MachineData &b) {
        int cmp = 0;
        if (sortBy == "nom") {
            cmp = QString::compare(a.nom, b.nom, Qt::CaseInsensitive);
        } else if (sortBy == "date d'achat") {
            cmp = a.dateAchat < b.dateAchat ? -1 : (a.dateAchat > b.dateAchat ? 1 : 0);
        } else if (sortBy == "état") {
            cmp = QString::compare(a.etatAchat, b.etatAchat, Qt::CaseInsensitive);
        } else if (sortBy == "catégorie") {
            cmp = QString::compare(a.categorie, b.categorie, Qt::CaseInsensitive);
        } else if (sortBy == "date de fin de garantie") {
            cmp = a.dateFinGarantie < b.dateFinGarantie ? -1 : (a.dateFinGarantie > b.dateFinGarantie ? 1 : 0);
        }
        return ascending ? (cmp < 0) : (cmp > 0);
    });

    ui->tableMachines->setRowCount(0);
    for (int i = 0; i < filtered.size(); ++i) {
        const MachineData &m = filtered.at(i);
        ui->tableMachines->insertRow(i);
        ui->tableMachines->setItem(i, 0, new QTableWidgetItem(QString::number(m.idMachine)));
        ui->tableMachines->setItem(i, 1, new QTableWidgetItem(m.nom));
        ui->tableMachines->setItem(i, 2, new QTableWidgetItem(m.categorie));
        ui->tableMachines->setItem(i, 3, new QTableWidgetItem(m.reference));
        ui->tableMachines->setItem(i, 4, new QTableWidgetItem(m.dateAchat.isValid() ? m.dateAchat.toString("dd/MM/yyyy") : QString()));
        ui->tableMachines->setItem(i, 5, new QTableWidgetItem(m.etatAchat));
        ui->tableMachines->setItem(i, 6, new QTableWidgetItem(m.localisation));
        ui->tableMachines->setItem(i, 7, new QTableWidgetItem(m.dateFinGarantie.isValid() ? m.dateFinGarantie.toString("dd/MM/yyyy") : QString()));
    }
    ui->tableMachines->resizeColumnsToContents();
}

void MainWindow::scanMachineQRCode()
{
    QMessageBox::information(this, "Scanner QR Code", "Scanner QR Code n'est disponible que dans la liste des machines.");
}

void MainWindow::onMachineSelectionChanged()
{
    if (!ui->tableMachines) return;
    const int row = ui->tableMachines->currentRow();
    if (row < 0) {
        clearMachineSuppressionForm();
        clearMachineModifierForm();
        return;
    }

    QTableWidgetItem *idItem = ui->tableMachines->item(row, 0);
    if (!idItem) return;

    int idMachine = idItem->text().toInt();
    MachineData machine;
    QString error;
    if (!MachineWidget::getMachineById(idMachine, &machine, &error)) {
        QMessageBox::warning(this, "Machine", "Impossible de lire la machine sélectionnée:\n" + error);
        return;
    }

    ui->lblSupprimerNom_mach->setText(machine.nom.isEmpty() ? "(nom indisponible)" : machine.nom);
    ui->lblSupprimerDetails_mach->setText(QString("ID %1 - Catégorie: %2 - État: %3").arg(machine.idMachine).arg(machine.categorie).arg(machine.etatAchat));

    ui->editModifierId->setText(QString::number(machine.idMachine));
    ui->editModifierNom->setText(machine.nom);
    ui->comboModifierCategorie->setCurrentText(machine.categorie);
    ui->editModifierReference->setText(machine.reference);
    if (machine.dateAchat.isValid()) ui->dateModifierAchat->setDate(machine.dateAchat);
    ui->comboModifierEtat->setCurrentText(machine.etatAchat);
    ui->editModifierLocalisation->setText(machine.localisation);
}

void MainWindow::ajouterMachine()
{
    const int idMachine = parseMachineId(ui->editAddId->text());
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide.");
        return;
    }

    const QString nom = ui->editAddNom->text().trimmed();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Nom obligatoire.");
        return;
    }

    MachineData data;
    data.idMachine = idMachine;
    data.nom = nom;
    data.categorie = ui->comboAddCategorie->currentText();
    data.reference = ui->editAddReference->text().trimmed();
    data.dateAchat = ui->dateAddAchat->date();
    data.etatAchat = ui->comboAddEtat->currentText();
    data.localisation = ui->editAddLocalisation->text().trimmed();
    if (!data.dateAchat.isValid()) data.dateAchat = QDate::currentDate();
    data.dateFinGarantie = data.dateAchat.addYears(1);
    data.idLabo = 1;

    QString error;
    if (!MachineWidget::addMachine(data, &error)) {
        QMessageBox::critical(this, "Erreur Machine", "Ajout impossible:\n" + error);
        return;
    }

    QMessageBox::information(this, "Succès", "Machine ajoutée avec succès.");
    clearMachineAddForm();
    afficherMachines();
}

void MainWindow::modifierMachine()
{
    const int idMachine = parseMachineId(ui->editModifierId->text());
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide pour modification.");
        return;
    }

    MachineData data;
    data.idMachine = idMachine;
    data.nom = ui->editModifierNom->text().trimmed();
    data.categorie = ui->comboModifierCategorie->currentText();
    data.reference = ui->editModifierReference->text().trimmed();
    data.dateAchat = ui->dateModifierAchat->date();
    data.etatAchat = ui->comboModifierEtat->currentText();
    data.localisation = ui->editModifierLocalisation->text().trimmed();
    if (!data.dateAchat.isValid()) data.dateAchat = QDate::currentDate();
    data.dateFinGarantie = data.dateAchat.addYears(1);
    data.idLabo = 1;

    int rowsAffected = 0;
    QString error;
    if (!MachineWidget::updateMachine(idMachine, data, &rowsAffected, &error)) {
        QMessageBox::critical(this, "Erreur Machine", "Modification impossible:\n" + error);
        return;
    }

    if (rowsAffected <= 0) {
        QMessageBox::warning(this, "Erreur", "Aucune machine modifiée.");
        return;
    }

    QMessageBox::information(this, "Succès", "Machine modifiée avec succès.");
    clearMachineModifierForm();
    afficherMachines();
}

void MainWindow::supprimerMachine()
{
    const int row = ui->tableMachines->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Validation", "Sélectionnez une machine à supprimer.");
        return;
    }

    const int idMachine = ui->tableMachines->item(row, 0)->text().toInt();
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide.");
        return;
    }

    auto reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette machine ?", QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;

    int rowsAffected = 0;
    QString error;
    if (!MachineWidget::deleteMachine(idMachine, &rowsAffected, &error)) {
        QMessageBox::critical(this, "Erreur Machine", "Suppression impossible:\n" + error);
        return;
    }

    if (rowsAffected <= 0) {
        QMessageBox::warning(this, "Erreur", "Aucune machine supprimée.");
        return;
    }

    QMessageBox::information(this, "Succès", "Machine supprimée avec succès.");
    clearMachineSuppressionForm();
    afficherMachines();
}

void MainWindow::onSignalPanneMachine()
{
    const int row = ui->tableMachines->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Validation", "Sélectionnez une machine pour signaler une panne.");
        return;
    }

    const int idMachine = ui->tableMachines->item(row, 0)->text().toInt();
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide.");
        return;
    }

    MachineData machine;
    QString err;
    if (!MachineWidget::getMachineById(idMachine, &machine, &err)) {
        QMessageBox::critical(this, "Erreur Machine", "Machine non trouvée:\n" + err);
        return;
    }

    machine.etatAchat = "Panne";

    int rowAffected = 0;
    if (!MachineWidget::updateMachine(idMachine, machine, &rowAffected, &err)) {
        QMessageBox::critical(this, "Erreur Machine", "Impossible de signaler la panne:\n" + err);
        return;
    }

    afficherMachines();
    QMessageBox::information(this, "Succès", "Panne signalée pour la machine.");
}

void MainWindow::exportMachineListePdf()
{
    if (ui->tableMachines->rowCount() == 0) {
        QMessageBox::warning(this, "Export PDF", "Aucune machine à exporter.");
        return;
    }

    const QString fileName = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", QDir::homePath(), "Fichiers PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName.endsWith(".pdf", Qt::CaseInsensitive) ? fileName : fileName + ".pdf");

    QString html = "<h1>Liste des machines</h1><table border=1 cellpadding=4 cellspacing=0><tr><th>ID</th><th>Nom</th><th>Catégorie</th><th>Référence</th><th>Date Achat</th><th>État</th><th>Localisation</th></tr>";

    for (int r = 0; r < ui->tableMachines->rowCount(); ++r) {
        html += "<tr>";
        for (int c = 0; c < ui->tableMachines->columnCount(); ++c) {
            html += "<td>" + ui->tableMachines->item(r, c)->text().toHtmlEscaped() + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "Export PDF de la liste des machines terminé.");
}
