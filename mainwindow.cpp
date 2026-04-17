#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "machine.h"
#include "email_sender.h"
#include "equipe.h"
#include "employe.h"
#include "client.h"
#include "tunisian_regions.h"
#include "tunisia_map_widget.h"
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
#include <QSqlQuery>
#include <QSqlError>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QTextStream>
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
#include <QCompleter>
#include <QStringListModel>
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
int parseMachineId(const QString &text)
{
    QString cleaned = text.trimmed();
    cleaned.remove(QRegularExpression("[^0-9]"));
    return cleaned.toInt();
}

QString getEtatDisplayText(const QString &etat)
{
    QString e = etat.trimmed().toLower();
    if (e == "en service") return "En service";
    if (e == "maintenance") return "Maintenance";
    if (e == "panne") return "Panne";
    if (e == "hors service") return "Hors service";
    if (e == "en stock") return "En stock";
    if (e == "en attente") return "En attente";
    return etat;
}

QColor getEtatColor(const QString &etat)
{
    QString e = etat.trimmed().toLower();
    if (e == "en service") return QColor(76, 175, 80);     // Green
    if (e == "maintenance") return QColor(255, 152, 0);    // Orange
    if (e == "panne") return QColor(244, 67, 54);          // Red
    if (e == "hors service") return QColor(158, 158, 158); // Gray
    if (e == "en stock") return QColor(33, 150, 243);      // Blue
    if (e == "en attente") return QColor(255, 193, 7);     // Amber
    return QColor(0, 0, 0);
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

    // Initialisation du gestionnaire reseau pour les emails et IA
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &MainWindow::onBrevoReplyFinished);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &MainWindow::onAIReplyFinished);

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
            refreshLaboStatistiques();
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
    setupLaboConnections();
    setupLaboCharts();
    setupEquipeConnections();
    setupClientConnections();
    setupChatbotConnections();
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
        QMessageBox::information(
            this,
            "Export PDF",
            "Fonctionnalite d'export PDF (Statistiques) a implementer");
    };

    auto setupClientUiData = [this]() {
        setupTableClients();
        loadClientData();
    };

    // CLIENT info helpers are now proper methods — see // === MODULE CLIENT ===

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
    if (ui->tableClients) {
        setupClientUiData();
        if (ui->tableClients->rowCount() > 0) {
            ui->tableClients->selectRow(0);
        }
        this->updateClientInfo();
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

    connect(ui->btnClient, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->WidgetClient);
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
        if (ui->tableClients->currentRow() == -1 && ui->tableClients->rowCount() > 0) {
            ui->tableClients->selectRow(0);
        }
        this->updateClientInfo();
    });

    connect(ui->btnMachine, &QPushButton::clicked, this, [this]() {
        ui->stackedMain->setCurrentWidget(ui->MachineWidget);
        afficherMachines();
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

    // CLIENT connections are handled in setupClientConnections()

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
    
    // Setup machine connections
    setupMachineConnections();
    
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
    refreshEmployeEquipeCombo();
}

void MainWindow::refreshEmployeEquipeCombo()
{
    if (!ui->lineEdit_id_equipe) {
        return;
    }

    const QVariant previousId = ui->lineEdit_id_equipe->currentData();
    ui->lineEdit_id_equipe->blockSignals(true);
    ui->lineEdit_id_equipe->clear();
    ui->lineEdit_id_equipe->addItem("Aucune equipe", QVariant());

    QList<EquipeData> equipes;
    QString dbError;
    if (!EquipeRepository::listerEquipes(&equipes, &dbError)) {
        qDebug() << "[Employe] Impossible de charger la liste des equipes pour l'ajout:" << dbError;
        ui->lineEdit_id_equipe->setCurrentIndex(0);
        ui->lineEdit_id_equipe->blockSignals(false);
        return;
    }

    for (const EquipeData &equipe : equipes) {
        const QString etat = equipe.etat.trimmed().toLower();
        if (etat == "active" || etat == "disponible") {
            ui->lineEdit_id_equipe->addItem(
                QString("%1 - %2").arg(equipe.idEquipe).arg(equipe.nomEquipe),
                equipe.idEquipe);
        }
    }

    const int previousIndex = ui->lineEdit_id_equipe->findData(previousId);
    ui->lineEdit_id_equipe->setCurrentIndex(previousIndex >= 0 ? previousIndex : 0);
    ui->lineEdit_id_equipe->blockSignals(false);
}

void MainWindow::setupLaboConnections()
{
    connect(ui->btnAjouterLabo, &QPushButton::clicked, this, &MainWindow::ajouterLabo);
    connect(ui->btnSupprimerLabo, &QPushButton::clicked, this, &MainWindow::supprimerLabo);
    connect(ui->btnModifierLabo, &QPushButton::clicked, this, &MainWindow::modifierLabo);
    connect(ui->lineEdit_modif_id1, &QLineEdit::editingFinished, this, &MainWindow::chargerLaboPourModification);
    connect(ui->btnExportFicheLabo, &QPushButton::clicked, this, &MainWindow::exporterFicheLaboPdf);
    
    // Setup autocomplete for address fields with Tunisian regions
    QStringList regions = TunisianRegions::getAllRegions();
    
    // Completer for "Ajouter" (add) address field
    QStringListModel *model1 = new QStringListModel(regions, this);
    m_laboAddressCompleter = new QCompleter(model1, this);
    m_laboAddressCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    m_laboAddressCompleter->setCompletionMode(QCompleter::PopupCompletion);
    m_laboAddressCompleter->setMaxVisibleItems(10);
    ui->lineEdit_adresse->setCompleter(m_laboAddressCompleter);
    
    // Completer for "Modifier" (modify) address field
    QStringListModel *model2 = new QStringListModel(regions, this);
    m_laboAddressCompleterModif = new QCompleter(model2, this);
    m_laboAddressCompleterModif->setCaseSensitivity(Qt::CaseInsensitive);
    m_laboAddressCompleterModif->setCompletionMode(QCompleter::PopupCompletion);
    m_laboAddressCompleterModif->setMaxVisibleItems(10);
    ui->lineEditAdresseLaboModif->setCompleter(m_laboAddressCompleterModif);
    
    // Setup Tunisia Map Widget for geography section - simplified approach
    if (!m_tunisiaMapWidget) {
        try {
            m_tunisiaMapWidget = new TunisiaMapWidget(this);
            m_tunisiaMapWidget->setStyleSheet("background-color: #f5f5f5;");
            
            // Try to load map image from correct paths
            bool imageLoaded = false;
            
            // Try absolute path first (most reliable)
            QString appPath = QApplication::applicationDirPath();
            QString mapImagePath = appPath + "/images/tunisia_map.png";
            qDebug() << "Trying to load from:" << mapImagePath;
            
            if (m_tunisiaMapWidget->loadMapImage(mapImagePath)) {
                imageLoaded = true;
                qDebug() << "Successfully loaded map from:" << mapImagePath;
            } else {
                // Try relative path
                mapImagePath = "images/tunisia_map.png";
                qDebug() << "Trying relative path:" << mapImagePath;
                if (m_tunisiaMapWidget->loadMapImage(mapImagePath)) {
                    imageLoaded = true;
                    qDebug() << "Successfully loaded map from relative path";
                } else {
                    // Try resource path
                    if (m_tunisiaMapWidget->loadMapImage(":/images/tunisia_map.png")) {
                        imageLoaded = true;
                        qDebug() << "Successfully loaded map from resources";
                    }
                }
            }
            
            if (!imageLoaded) {
                qWarning() << "Failed to load map image from any path";
                qWarning() << "Application directory:" << appPath;
            }
            
            m_tunisiaMapWidget->drawTunisiaMap();
            
            // Find the geography page layout and add the map directly
            QWidget *geoPlaceholder = findChild<QWidget *>("geoPlaceholder");
            if (geoPlaceholder && geoPlaceholder->parentWidget()) {
                QWidget *geoPage = geoPlaceholder->parentWidget();
                QLayout *pageLayout = geoPage->layout();
                
                if (pageLayout) {
                    // Clear the layout and add the map
                    QLayoutItem *item;
                    while ((item = pageLayout->takeAt(0)) != nullptr) {
                        if (item->widget()) {
                            item->widget()->hide();
                        }
                        delete item;
                    }
                    pageLayout->addWidget(m_tunisiaMapWidget);
                }
            }
            
            // Connect governorate click signal if needed
            connect(m_tunisiaMapWidget, &TunisiaMapWidget::governorateClicked, 
                    [this](const QString &govName) {
                qDebug() << "Selected governorate: " << govName;
            });
        } catch (const std::exception &e) {
            qWarning() << "Error setting up Tunisia map:" << e.what();
        } catch (...) {
            qWarning() << "Unknown error setting up Tunisia map";
        }
    }
}

void MainWindow::setupLaboCharts()
{
    // Hide the plain text edits
    if (ui->plainTextEdit1) ui->plainTextEdit1->hide();
    if (ui->plainTextEdit_21) ui->plainTextEdit_21->hide();

    // Create frames for charts if they don't exist
    if (!laboStatsTopChartView) {
        QFrame *frame = new QFrame(ui->performanceGroup1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setLayout(new QVBoxLayout());
        frame->layout()->setContentsMargins(4, 4, 4, 4);
        laboStatsTopChartView = new QChartView(frame);
        laboStatsTopChartView->setRenderHint(QPainter::Antialiasing);
        frame->layout()->addWidget(laboStatsTopChartView);
        ui->performanceGroup1->layout()->addWidget(frame);
    }

    if (!laboStatsLeftChartView) {
        QFrame *frame = new QFrame(ui->vitesseGroup1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setLayout(new QVBoxLayout());
        frame->layout()->setContentsMargins(4, 4, 4, 4);
        laboStatsLeftChartView = new QChartView(frame);
        laboStatsLeftChartView->setRenderHint(QPainter::Antialiasing);
        frame->layout()->addWidget(laboStatsLeftChartView);
        ui->vitesseGroup1->layout()->addWidget(frame);
    }

    // For the third chart, we might need to add another group box or modify the layout
    // For now, let's add it to the main layout
    if (!laboStatsRightChartView) {
        QFrame *frame = new QFrame(ui->page_stat1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setLayout(new QVBoxLayout());
        frame->layout()->setContentsMargins(4, 4, 4, 4);
        laboStatsRightChartView = new QChartView(frame);
        laboStatsRightChartView->setRenderHint(QPainter::Antialiasing);
        frame->layout()->addWidget(laboStatsRightChartView);
        ui->statLayout1->addWidget(frame);
    }
}

void MainWindow::refreshLaboStatistiques()
{
    if (!laboStatsTopChartView || !laboStatsLeftChartView || !laboStatsRightChartView) {
        setupLaboCharts();
    }
    if (!laboStatsTopChartView || !laboStatsLeftChartView || !laboStatsRightChartView) {
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

    // Chart 1: Space Usage Percentage
    {
        QList<LaboSpaceUsage> spaceStats;
        QString error;
        if (!LaboRepository::getSpaceUsageStats(&spaceStats, &error)) {
            qDebug() << "Erreur stats espace labo:" << error;
        }

        QStringList categories;
        auto *setSpaceUsed = new QBarSet("Pourcentage d'espace utilisé (%)");
        for (const LaboSpaceUsage &stat : spaceStats) {
            categories << stat.nomLabo;
            *setSpaceUsed << stat.percentageUsed;
        }

        auto *series = new QBarSeries();
        series->append(setSpaceUsed);
        setSpaceUsed->setColor(greenPrimary);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Utilisation de l'espace par laboratoire");
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
        axisY->setRange(0, 100);
        axisY->setLabelFormat("%.1f%%");
        axisY->setLabelsColor(textColor);
        axisY->setGridLineColor(gridColor);
        axisY->setLinePenColor(gridColor);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(laboStatsTopChartView, chart);
    }

    // Chart 2: Conformité Distribution
    {
        QList<LaboConformiteCount> conformiteStats;
        QString error;
        if (!LaboRepository::getConformiteStats(&conformiteStats, &error)) {
            qDebug() << "Erreur stats conformité labo:" << error;
        }

        auto *series = new QPieSeries();
        for (const LaboConformiteCount &stat : conformiteStats) {
            series->append(stat.conformite, stat.count);
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
        chart->setTitle("Répartition de la conformité");
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(laboStatsLeftChartView, chart);
    }

    // Chart 3: Review Statistics
    {
        LaboReviewStats reviewStats;
        QString error;
        if (!LaboRepository::getReviewStats(&reviewStats, &error)) {
            qDebug() << "Erreur stats review labo:" << error;
        }

        // Create a simple bar chart for average review
        QStringList categories = {"Note moyenne"};
        auto *setReview = new QBarSet("Note moyenne (/10)");
        *setReview << reviewStats.averageReview;

        auto *series = new QBarSeries();
        series->append(setReview);
        setReview->setColor(greenSecondary);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(QString("Évaluation des laboratoires (Total: %1)").arg(reviewStats.totalReviews));
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
        axisY->setRange(0, 10);
        axisY->setLabelFormat("%.1f");
        axisY->setLabelsColor(textColor);
        axisY->setGridLineColor(gridColor);
        axisY->setLinePenColor(gridColor);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(laboStatsRightChartView, chart);
    }
}

void MainWindow::ajouterEmploye()
{
    if (!validateAjouterForm()) {
        return;
    }

    const QVariant idEquipeData = ui->lineEdit_id_equipe->currentData();
    const bool hasEquipe = idEquipeData.isValid() && !idEquipeData.toString().trimmed().isEmpty();
    int idEquipeInt = 0;

    if (hasEquipe) {
        bool ok = false;
        idEquipeInt = idEquipeData.toInt(&ok);
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
    refreshEmployeEquipeCombo();
    ui->lineEdit_id_equipe->setCurrentIndex(0);
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

    refreshEmployeEquipeCombo();

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

void MainWindow::setupClientConnections()
{
    connect(ui->btnConfirmerAjouter,   &QPushButton::clicked, this, &MainWindow::onConfirmerAjouterClicked);
    connect(ui->btnConfirmerModifier,  &QPushButton::clicked, this, &MainWindow::onConfirmerModifierClicked);
    connect(ui->btnConfirmerSupprimer, &QPushButton::clicked, this, &MainWindow::onConfirmerSupprimerClicked);

    connect(ui->btnAnnulerAjouter, &QPushButton::clicked, this, [this]() {
        clearFormAjouter();
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
    });
    connect(ui->btnAnnulerModifier, &QPushButton::clicked, this, [this]() {
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
    });
    connect(ui->btnAnnulerSupprimer, &QPushButton::clicked, this, [this]() {
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
    });

    connect(ui->tabWidgetClient, &QTabWidget::currentChanged, this, &MainWindow::onTabClientChanged);
    connect(ui->tableClients, &QTableWidget::itemSelectionChanged,
            this, &MainWindow::onTableClientSelectionChanged);
    connect(ui->btnAppliquerFiltre, &QPushButton::clicked, this, &MainWindow::onAppliquerFiltreClicked);
    connect(ui->btnExportListeClients, &QPushButton::clicked, this, &MainWindow::onExportListeClientsClicked);
    connect(ui->btnExportStatistiques, &QPushButton::clicked, this, &MainWindow::onExportStatistiquesClicked);
    connect(ui->btnExportFicheClient,  &QPushButton::clicked, this, &MainWindow::onExportFicheClientClicked);
}

void MainWindow::setupTableClients()
{
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
}

// ---------------------------------------------------------------------------
// Setup Qt Chart views for Statistics tab — called once (idempotent).
// ---------------------------------------------------------------------------
void MainWindow::setupClientStatistiquesCharts()
{
    if (m_clientChartStatut && m_clientChartType && m_clientChartCA) return;

    QWidget *statsTab = ui->tabStatistiques1;
    if (!statsTab) return;

    ui->txtStatistiques->hide();

    QVBoxLayout *mainLayout = qobject_cast<QVBoxLayout *>(statsTab->layout());
    if (!mainLayout) {
        mainLayout = new QVBoxLayout(statsTab);
        mainLayout->setContentsMargins(8, 8, 8, 8);
        mainLayout->setSpacing(8);
    }

    // Summary labels row
    QHBoxLayout *summaryRow = new QHBoxLayout();
    summaryRow->setSpacing(12);
    auto makeSummaryLabel = [&](const QString &objName) -> QLabel * {
        QLabel *lbl = new QLabel(statsTab);
        lbl->setObjectName(objName);
        lbl->setAlignment(Qt::AlignCenter);
        lbl->setStyleSheet(
            "QLabel { background-color:#2E4A2E; color:#C8E6C9; border-radius:6px;"
            "padding:6px 10px; font-size:10pt; font-weight:bold; }");
        lbl->setMinimumHeight(38);
        summaryRow->addWidget(lbl);
        return lbl;
    };
    makeSummaryLabel("lblClientTotal");
    makeSummaryLabel("lblClientActifs");
    makeSummaryLabel("lblClientCA");
    mainLayout->addLayout(summaryRow);

    // Chart frames row
    QHBoxLayout *chartsRow = new QHBoxLayout();
    chartsRow->setSpacing(8);
    auto makeChartFrame = [&](QChartView *&chartViewPtr) {
        QFrame *frame = new QFrame(statsTab);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setStyleSheet("QFrame { background-color:#1E2521; border-radius:6px; }");
        QVBoxLayout *fl = new QVBoxLayout(frame);
        fl->setContentsMargins(4, 4, 4, 4);
        chartViewPtr = new QChartView(frame);
        chartViewPtr->setRenderHint(QPainter::Antialiasing);
        chartViewPtr->setBackgroundBrush(QBrush(QColor("#1E2521")));
        fl->addWidget(chartViewPtr);
        chartsRow->addWidget(frame);
    };
    makeChartFrame(m_clientChartStatut);
    makeChartFrame(m_clientChartType);
    makeChartFrame(m_clientChartCA);
    mainLayout->addLayout(chartsRow);
}

void MainWindow::loadClientData()
{
    setupClientStatistiquesCharts();
    refreshTableFromDB();

    if (ui->cmbType->count() == 0)
        ui->cmbType->addItems({"Tous", "Particulier", "Entreprise"});
    if (ui->cmbStatut->count() == 0)
        ui->cmbStatut->addItems({"Tous", "Actif", "Inactif"});
    if (ui->cmbAjouterType->count() == 0)
        ui->cmbAjouterType->addItems({"Particulier", "Entreprise"});
    if (ui->cmbAjouterStatut->count() == 0)
        ui->cmbAjouterStatut->addItems({"Actif", "Inactif"});
    if (ui->cmbModifierType->count() == 0)
        ui->cmbModifierType->addItems({"Particulier", "Entreprise"});
    if (ui->cmbModifierStatut->count() == 0)
        ui->cmbModifierStatut->addItems({"Actif", "Inactif"});

    refreshClientStatistiques();
    refreshClientAlertes();
}

void MainWindow::refreshTableFromDB()
{
    auto normalizeClientToken = [](QString value) {
        value = value.trimmed().toLower();
        value.replace(QChar(0x00E9), "e");
        value.replace(QChar(0x00E8), "e");
        value.replace(QChar(0x00EA), "e");
        value.replace(QChar(0x00EB), "e");
        value.replace(QChar(0x00E0), "a");
        value.replace(QChar(0x00E2), "a");
        value.replace(QChar(0xFFFD), "e");
        value.remove(' '); value.remove('-'); value.remove('_');
        return value;
    };
    auto displayClientType = [&](const QString &dbType) {
        const QString token = normalizeClientToken(dbType);
        if (token.contains("alimentaire") || token.contains("entreprise")) return QString("Entreprise");
        if (token.contains("beaut")       || token.contains("particulier")) return QString("Particulier");
        return dbType;
    };
    auto displayClientStatut = [&](const QString &dbStatut) {
        const QString token = normalizeClientToken(dbStatut);
        if (token.contains("blacklist") || token.contains("inactif")) return QString("Inactif");
        if (token.contains("actif"))                                   return QString("Actif");
        return dbStatut;
    };

    QSqlQueryModel *model = m_clientTmp.afficher();
    ui->tableClients->setRowCount(0);
    for (int i = 0; i < model->rowCount(); ++i) {
        int row = ui->tableClients->rowCount();
        ui->tableClients->insertRow(row);
        ui->tableClients->setItem(row, 0, new QTableWidgetItem(model->data(model->index(i, 0)).toString()));
        ui->tableClients->setItem(row, 1, new QTableWidgetItem(model->data(model->index(i, 1)).toString()));
        ui->tableClients->setItem(row, 2, new QTableWidgetItem(displayClientType(model->data(model->index(i, 5)).toString())));
        ui->tableClients->setItem(row, 3, new QTableWidgetItem(model->data(model->index(i, 2)).toString()));
        ui->tableClients->setItem(row, 4, new QTableWidgetItem(model->data(model->index(i, 3)).toString()));
        ui->tableClients->setItem(row, 5, new QTableWidgetItem(displayClientStatut(model->data(model->index(i, 6)).toString())));
    }
    delete model;
}

void MainWindow::refreshClientStatistiques()
{
    ClientStatsSummary stats;
    QString erreur;
    if (!Client::getStatsSummary(&stats, &erreur))
        qDebug() << "[CLIENT] refreshClientStatistiques error:" << erreur;

    const int    pctActif = stats.total > 0 ? (stats.actifs       * 100 / stats.total) : 0;
    const int    pctPart  = stats.total > 0 ? (stats.particuliers  * 100 / stats.total) : 0;
    const int    pctEntr  = stats.total > 0 ? (stats.entreprises   * 100 / stats.total) : 0;
    const double moyCmd   = stats.nbCommandes > 0 ? (stats.caTotal / stats.nbCommandes) : 0.0;

    if (QLabel *l = ui->tabStatistiques1->findChild<QLabel*>("lblClientTotal"))
        l->setText(QString("Total Clients : %1").arg(stats.total));
    if (QLabel *l = ui->tabStatistiques1->findChild<QLabel*>("lblClientActifs"))
        l->setText(QString("Actifs : %1  (%2%)").arg(stats.actifs).arg(pctActif));
    if (QLabel *l = ui->tabStatistiques1->findChild<QLabel*>("lblClientCA"))
        l->setText(QString("CA Total : %1 DT").arg(stats.caTotal, 0, 'f', 0));

    const QColor bgColor("#1E2521"), plotBg("#151A18"), textColor("#E8F0E8"), gridColor("#3A4941");
    const QColor green1("#67D98A"), green2("#4FBF78"), green3("#9EE6B0");
    const QColor orange1("#E6C36A"), red1("#C97A7A"), blue1("#7DA3A1");

    auto applyDark = [&](QChart *c) {
        c->setBackgroundBrush(QBrush(bgColor));
        c->setPlotAreaBackgroundVisible(true);
        c->setPlotAreaBackgroundBrush(QBrush(plotBg));
        c->setTitleBrush(QBrush(textColor));
        if (c->legend()) c->legend()->setLabelColor(textColor);
    };
    auto replaceChart = [](QChartView *v, QChart *c) {
        if (!v) { delete c; return; }
        QChart *old = v->chart(); v->setChart(c); if (old) delete old;
    };

    // Chart 1: Pie - statut
    if (m_clientChartStatut) {
        auto *s = new QPieSeries();
        s->append(QString("Actifs (%1)").arg(stats.actifs),    stats.actifs    > 0 ? stats.actifs    : 0.001);
        s->append(QString("Inactifs (%1)").arg(stats.inactifs),stats.inactifs  > 0 ? stats.inactifs  : 0.001);
        const QList<QColor> cols = {green1, red1};
        const auto sl = s->slices();
        for (int i = 0; i < sl.size(); ++i) { sl.at(i)->setBrush(cols.at(i % cols.size())); sl.at(i)->setLabelVisible(true); sl.at(i)->setLabelColor(textColor); }
        if (!sl.isEmpty()) { QPieSlice *lg = sl.first(); for (auto *x : sl) if (x->value() > lg->value()) lg = x; lg->setExploded(true); lg->setExplodeDistanceFactor(0.08); }
        auto *c = new QChart(); c->addSeries(s); c->setTitle("Répartition par statut");
        c->setAnimationOptions(QChart::SeriesAnimations); applyDark(c);
        c->legend()->setVisible(true); c->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(m_clientChartStatut, c);
    }

    // Chart 2: Pie - type
    if (m_clientChartType) {
        auto *s = new QPieSeries();
        s->append(QString("Particuliers (%1 — %2%)").arg(stats.particuliers).arg(pctPart), stats.particuliers > 0 ? stats.particuliers : 0.001);
        s->append(QString("Entreprises (%1 — %2%)").arg(stats.entreprises).arg(pctEntr),   stats.entreprises  > 0 ? stats.entreprises  : 0.001);
        const QList<QColor> cols = {green2, blue1};
        const auto sl = s->slices();
        for (int i = 0; i < sl.size(); ++i) { sl.at(i)->setBrush(cols.at(i % cols.size())); sl.at(i)->setLabelVisible(true); sl.at(i)->setLabelColor(textColor); }
        auto *c = new QChart(); c->addSeries(s); c->setTitle("Répartition par type");
        c->setAnimationOptions(QChart::SeriesAnimations); applyDark(c);
        c->legend()->setVisible(true); c->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(m_clientChartType, c);
    }

    // Chart 3: Bar - activité commandes
    if (m_clientChartCA) {
        auto *set = new QBarSet("Valeur"); set->setColor(green3);
        *set << stats.caTotal << moyCmd << (double)stats.nbCommandes;
        auto *s = new QBarSeries(); s->append(set);
        auto *c = new QChart(); c->addSeries(s); c->setTitle("Activité commandes");
        c->setAnimationOptions(QChart::SeriesAnimations); applyDark(c);
        auto *axX = new QBarCategoryAxis(); axX->append({"CA Total (DT)", "Moy./Commande (DT)", "Nb Commandes"});
        axX->setLabelsColor(textColor); axX->setGridLineColor(gridColor); axX->setLinePenColor(gridColor);
        c->addAxis(axX, Qt::AlignBottom); s->attachAxis(axX);
        auto *axY = new QValueAxis(); axY->setLabelFormat("%.0f");
        axY->setLabelsColor(textColor); axY->setGridLineColor(gridColor); axY->setLinePenColor(gridColor);
        c->addAxis(axY, Qt::AlignLeft); s->attachAxis(axY);
        c->legend()->setVisible(true); c->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(m_clientChartCA, c);
    }
}

void MainWindow::refreshClientAlertes()
{
    QList<ClientAlerteInfo> alertes;
    QString erreur;
    Client::getAlertes(&alertes, &erreur);

    for (int i = 0; i < ui->tabWidgetClient->count(); ++i) {
        if (ui->tabWidgetClient->widget(i) == ui->tabAlertes) {
            ui->tabWidgetClient->setTabText(i, alertes.isEmpty() ? "Alertes"
                                            : QString("Alertes (%1)").arg(alertes.size()));
            break;
        }
    }

    QString html;
    html += "<div style='color:#212121; padding:10px;'>";
    html += "<h2 style='color:#D32F2F;'>&#9888;&#65039; Alertes et Notifications</h2>";
    html += "<p style='color:#888; font-size:9pt;'>Mise &agrave; jour : "
            + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</p>";
    html += "<hr style='border:1px solid #BDBDBD;'>";

    if (alertes.isEmpty()) {
        html += "<div style='background-color:#E8F5E9; padding:15px; margin:10px 0; border-left:4px solid #388E3C; border-radius:4px;'>";
        html += "<p style='margin:0; color:#2E7D32; font-weight:bold; font-size:11pt;'>&#10003; Aucune alerte &mdash; toutes les commandes sont livr&eacute;es.</p></div>";
    } else {
        const int nbHaute = (int)std::count_if(alertes.begin(), alertes.end(),
                            [](const ClientAlerteInfo &a){ return a.nbRetards >= 2; });
        html += "<div style='background-color:#FFF8E1; padding:10px; margin:8px 0; border-left:4px solid #FBC02D; border-radius:4px;'>";
        html += "<p style='margin:0; font-size:10pt; color:#5D4037;'><b>" + QString::number(alertes.size())
                + "</b> client(s) avec commandes non livr&eacute;es";
        if (nbHaute > 0) html += " &mdash; <span style='color:#C62828; font-weight:bold;'>"
                                  + QString::number(nbHaute) + " priorit&eacute; haute</span>";
        html += ".</p></div>";

        for (const ClientAlerteInfo &a : alertes) {
            const bool haute  = (a.nbRetards >= 2);
            const QString bg  = haute ? "#FFEBEE" : "#FFF3E0";
            const QString brd = haute ? "#D32F2F" : "#F57C00";
            const QString tc  = haute ? "#C62828"  : "#E65100";
            const QString ico = haute ? "&#128308;" : "&#128992;";
            html += "<div style='background-color:" + bg + "; padding:12px; margin:8px 0; border-left:5px solid " + brd + "; border-radius:4px;'>";
            html += "<p style='margin:3px 0; font-size:10pt;'>" + ico + " <b>Client #"
                    + QString::number(a.idClient) + " &mdash; " + a.nomClient + "</b></p>";
            html += "<p style='margin:3px 0; color:" + tc + "; font-weight:bold;'>Commandes en attente : "
                    + QString::number(a.nbRetards) + "</p>";
            if (haute) html += "<p style='margin:3px 0; color:#C62828; font-size:9pt;'>&#9888; Priorit&eacute; &eacute;lev&eacute;e</p>";
            html += "</div>";
        }
    }
    html += "<hr style='border:1px solid #BDBDBD; margin:20px 0;'>";
    html += "<p style='color:#888; font-size:8pt;'>Donn&eacute;es r&eacute;elles extraites de la base &mdash; "
            + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</p></div>";
    ui->txtAlertes->setHtml(html);
}

void MainWindow::onTabClientChanged(int index)
{
    QWidget *tab = ui->tabWidgetClient->widget(index);

    if (tab == ui->tabStatistiques1) {
        setupClientStatistiquesCharts();
        refreshClientStatistiques();
        return;
    }
    if (tab == ui->tabAlertes) {
        refreshClientAlertes();
        return;
    }
    if (tab == ui->tabModifier2) {
        int row = ui->tableClients->currentRow();
        if (row != -1) {
            ui->txtModifierNom->setText(ui->tableClients->item(row, 1)->text());
            ui->cmbModifierType->setCurrentText(ui->tableClients->item(row, 2)->text());
            ui->txtModifierTel->setText(ui->tableClients->item(row, 3)->text());
            ui->txtModifierEmail->setText(ui->tableClients->item(row, 4)->text());
            ui->cmbModifierStatut->setCurrentText(ui->tableClients->item(row, 5)->text());
        } else {
            QMessageBox::information(this, "Information", "Veuillez d'abord sélectionner un client dans la liste.");
            ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
        }
    }
    if (tab == ui->tabSupprimer2) {
        int row = ui->tableClients->currentRow();
        if (row != -1) {
            ui->lblSupprimerNom->setText(ui->tableClients->item(row, 1)->text());
            ui->lblSupprimerDetails->setText("Type : " + ui->tableClients->item(row, 2)->text()
                + "   |   Statut : " + ui->tableClients->item(row, 5)->text()
                + "   |   Tél : " + ui->tableClients->item(row, 3)->text());
        } else {
            QMessageBox::information(this, "Information", "Veuillez d'abord sélectionner un client dans la liste.");
            ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
        }
    }
    if (tab == ui->tabInfosClient || tab == ui->tabModifier2 || tab == ui->tabSupprimer2) {
        if (ui->tableClients->currentRow() == -1 && ui->tableClients->rowCount() > 0)
            ui->tableClients->selectRow(0);
        updateClientInfo();
    }
}

void MainWindow::onConfirmerAjouterClicked()
{
    const QString nom    = ui->txtAjouterNom->text().trimmed();
    const QString tel    = ui->txtAjouterTel->text().trimmed();
    const QString email  = ui->txtAjouterEmail->text().trimmed();
    const QString type   = ui->cmbAjouterType->currentText();
    const QString statut = ui->cmbAjouterStatut->currentText();

    QString erreur;
    if (!Client::valider(nom, tel, email, &erreur)) {
        QMessageBox::warning(this, "Saisie invalide", erreur); return;
    }
    Client c(0, nom, type, tel, email, statut);
    QString dbErreur;
    if (c.ajouter(&dbErreur)) {
        refreshTableFromDB();
        refreshClientStatistiques();
        refreshClientAlertes();
        QMessageBox::information(this, "Succès", "Client ajouté avec succès !");
        clearFormAjouter();
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'ajout.\n\n" + dbErreur);
    }
}

void MainWindow::onConfirmerModifierClicked()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) { QMessageBox::warning(this, "Attention", "Aucun client sélectionné."); return; }

    const QString nom    = ui->txtModifierNom->text().trimmed();
    const QString tel    = ui->txtModifierTel->text().trimmed();
    const QString email  = ui->txtModifierEmail->text().trimmed();
    const QString type   = ui->cmbModifierType->currentText();
    const QString statut = ui->cmbModifierStatut->currentText();
    const int id         = ui->tableClients->item(row, 0)->text().toInt();

    QString erreur;
    if (!Client::valider(nom, tel, email, &erreur)) {
        QMessageBox::warning(this, "Saisie invalide", erreur); return;
    }
    Client c(id, nom, type, tel, email, statut);
    QString dbErreur;
    if (c.modifier(&dbErreur)) {
        refreshTableFromDB();
        refreshClientStatistiques();
        refreshClientAlertes();
        QMessageBox::information(this, "Succès", "Client modifié avec succès !");
        ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
        updateClientInfo();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la modification.\n\n" + dbErreur);
    }
}

void MainWindow::onConfirmerSupprimerClicked()
{
    int row = ui->tableClients->currentRow();
    if (row == -1) { QMessageBox::warning(this, "Attention", "Aucun client sélectionné."); return; }

    const QString nom = ui->tableClients->item(row, 1)->text();
    int id = ui->tableClients->item(row, 0)->text().toInt();

    auto reply = QMessageBox::question(this, "Confirmation",
        "Êtes-vous sûr de vouloir supprimer \"" + nom + "\" ?\nCette action est irréversible.",
        QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        if (m_clientTmp.supprimer(id)) {
            refreshTableFromDB();
            clearClientInfo();
            ui->lblSupprimerNom->setText("Aucun client sélectionné");
            ui->lblSupprimerDetails->setText("-");
            QMessageBox::information(this, "Succès", "Client supprimé avec succès !");
            ui->tabWidgetClient->setCurrentWidget(ui->tabListeClients);
        } else {
            QMessageBox::critical(this, "Erreur", "Échec de la suppression dans la base de données.");
        }
    }
}

void MainWindow::onAppliquerFiltreClicked()
{
    const QString nomR  = ui->txtRechercheNom->text().trimmed().toLower();
    const QString typeF = ui->cmbType->currentText();
    const QString statF = ui->cmbStatut->currentText();

    int firstVisible = -1;
    for (int i = 0; i < ui->tableClients->rowCount(); ++i) {
        bool vis = true;
        if (!nomR.isEmpty()  && !ui->tableClients->item(i,1)->text().toLower().contains(nomR)) vis = false;
        if (typeF != "Tous"  &&  ui->tableClients->item(i,2)->text() != typeF) vis = false;
        if (statF != "Tous"  &&  ui->tableClients->item(i,5)->text() != statF) vis = false;
        ui->tableClients->setRowHidden(i, !vis);
        if (vis && firstVisible == -1) firstVisible = i;
    }
    if (firstVisible != -1) ui->tableClients->selectRow(firstVisible);
    else { ui->tableClients->clearSelection(); clearClientInfo(); }
}

void MainWindow::onTableClientSelectionChanged()
{
    if (ui->tableClients->currentRow() != -1) updateClientInfo();
    else clearClientInfo();
}

void MainWindow::setupClientHistoriqueWidget()
{
    if (m_clientChartHistorique) return;

    QGroupBox *grp = ui->grpHistorique;
    if (!grp) return;

    // Force enough height for KPI cards + chart
    grp->setMinimumHeight(300);
    grp->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    if (ui->lblClientDepuis)     ui->lblClientDepuis->hide();
    if (ui->lblNombreCommandes)  ui->lblNombreCommandes->hide();
    if (ui->lblDerniereCommande) ui->lblDerniereCommande->hide();

    // Remove old horizontal layout cleanly
    QLayout *oldLayout = grp->layout();
    if (oldLayout) {
        QLayoutItem *child;
        while ((child = oldLayout->takeAt(0)) != nullptr) {
            if (child->widget()) child->widget()->hide();
            delete child;
        }
        delete oldLayout;
    }

    QVBoxLayout *vbox = new QVBoxLayout(grp);
    vbox->setContentsMargins(10, 20, 10, 8);
    vbox->setSpacing(6);

    // ---- KPI cards row ----
    QHBoxLayout *kpiRow = new QHBoxLayout();
    kpiRow->setSpacing(6);
    auto makeKpi = [&](const QString &objName, const QString &icon) -> QLabel * {
        QLabel *card = new QLabel(grp);
        card->setObjectName(objName);
        card->setTextFormat(Qt::RichText);
        card->setAlignment(Qt::AlignCenter);
        card->setText(icon + "<br><b>-</b>");
        card->setMinimumHeight(55);
        card->setMinimumWidth(85);
        card->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        card->setStyleSheet(
            "QLabel { background-color:#2E4A2E; color:#C8E6C9; border-radius:8px;"
            " padding:4px 6px; font-size:9pt; }");
        kpiRow->addWidget(card);
        return card;
    };
    makeKpi("kpiNbCmd",    "&#128196;");
    makeKpi("kpiCA",       "&#128176;");
    makeKpi("kpiMoyCmd",   "&#128083;");
    makeKpi("kpiTauxAnn",  "&#10060;");
    makeKpi("kpiDerniere", "&#128337;");
    makeKpi("kpiStatut",   "&#9679;");
    vbox->addLayout(kpiRow);

    // ---- Chart frame ----
    QFrame *chartFrame = new QFrame(grp);
    chartFrame->setObjectName("frameHistoChart");
    chartFrame->setMinimumHeight(200);
    chartFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    chartFrame->setStyleSheet("QFrame { background-color:#1E2521; border-radius:6px; }");
    QVBoxLayout *fl = new QVBoxLayout(chartFrame);
    fl->setContentsMargins(4, 4, 4, 4);

    m_clientChartHistorique = new QChartView(chartFrame);
    m_clientChartHistorique->setRenderHint(QPainter::Antialiasing);
    m_clientChartHistorique->setBackgroundBrush(QBrush(QColor("#1E2521")));
    m_clientChartHistorique->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    fl->addWidget(m_clientChartHistorique);

    vbox->addWidget(chartFrame, 1);  // stretch=1 → chart grows to fill available space
}

void MainWindow::updateClientInfo()
{
    const int row = ui->tableClients->currentRow();
    if (row < 0 || row >= ui->tableClients->rowCount()) { clearClientInfo(); return; }

    const int     idClient = ui->tableClients->item(row, 0)->text().toInt();
    const QString nom      = ui->tableClients->item(row, 1)->text();
    const QString type     = ui->tableClients->item(row, 2)->text();
    const QString tel      = ui->tableClients->item(row, 3)->text();
    const QString email    = ui->tableClients->item(row, 4)->text();
    const QString statut   = ui->tableClients->item(row, 5)->text();

    ui->txtModifierNom->setText(nom);
    ui->cmbModifierType->setCurrentText(type);
    ui->txtModifierTel->setText(tel);
    ui->txtModifierEmail->setText(email);
    ui->cmbModifierStatut->setCurrentText(statut);
    ui->lblSupprimerNom->setText(nom);
    ui->lblSupprimerDetails->setText("Type : " + type + "   |   Statut : " + statut + "   |   Tél : " + tel);
    ui->lblInfoStatut->setTextFormat(Qt::RichText);
    ui->lblInfoAlertes->setTextFormat(Qt::RichText);
    ui->lblInfoStatut->setText("Statut : " + statut);

    if (statut == "Actif")
        ui->lblInfoAlertes->setText("Alertes : <span style='color:#6FA66F;'>&#10003; Client actif</span>");
    else
        ui->lblInfoAlertes->setText("Alertes : <span style='color:#C97A7A;'>&#10060; Client inactif</span>");

    ClientInfosDetail infos;
    QString erreur;
    if (!Client::getClientInfos(idClient, &infos, &erreur))
        qDebug() << "[CLIENT] updateClientInfo error:" << erreur;

    ui->lblRetardsNombre->setText("Commandes en attente : " + QString::number(infos.nbRetards));
    ui->lblRetardsMoyen->setText("Commandes annulées : " + QString::number(infos.nbAnnulees));
    ui->lblRetardsTotal->setText(
        infos.nbRetards == 0
        ? "<span style='color:#6FA66F;'>Montant total : " + QString::number(infos.montantTotal,'f',0) + " DT</span>"
        : "<span style='color:#C97A7A; font-weight:bold;'>Montant total : " + QString::number(infos.montantTotal,'f',0) + " DT</span>");

    if (infos.nbCommandes > 0) {
        double tauxAnn = (double)infos.nbAnnulees * 100.0 / infos.nbCommandes;
        QString couleur = (tauxAnn < 10.0) ? "#6FA66F" : "#C97A7A";
        ui->lblRetoursNombre->setText("Commandes annulées : " + QString::number(infos.nbAnnulees));
        ui->lblRetoursTaux->setText("Taux d'annulation : <span style='color:" + couleur + ";'>" + QString::number(tauxAnn,'f',1) + "%</span>");
        ui->lblRetoursDernier->setText("Dernière commande : " + infos.derniereCommande);
    } else {
        ui->lblRetoursNombre->setText("Commandes annulées : 0");
        ui->lblRetoursTaux->setText("Taux d'annulation : <span style='color:#6FA66F;'>0%</span>");
        ui->lblRetoursDernier->setText("Dernière commande : Aucune");
    }

    ui->lblNombreCommandes->setText("Nombre de commandes : " + QString::number(infos.nbCommandes));
    ui->lblDerniereCommande->setText("Dernière commande : " + infos.derniereCommande);
    ui->lblPrixMoyen->setText("Montant moyen : " + QString::number(infos.montantMoyen,'f',0) + " DT");
    ui->lblPrixTotal->setText("<span style='color:#6FA66F; font-weight:bold;'>CA total : " + QString::number(infos.montantTotal,'f',0) + " DT</span>");
    ui->lblPrixRemise->setText(type == "Entreprise" ? "Remise accordée : 15%" : "Remise accordée : 5%");
    ui->lblClientDepuis->setText("ID Client : " + QString::number(idClient));

    setupClientHistoriqueWidget();
    updateClientHistorique(idClient, infos, nom, type, statut);
}

void MainWindow::updateClientHistorique(int idClient, const ClientInfosDetail &infos,
                                         const QString &nom, const QString &type,
                                         const QString &statut)
{
    QGroupBox *grp = ui->grpHistorique;
    if (!grp || !m_clientChartHistorique) return;

    double tauxAnn = infos.nbCommandes > 0 ? ((double)infos.nbAnnulees * 100.0 / infos.nbCommandes) : 0.0;
    QString couleurTaux   = (tauxAnn < 10.0) ? "#6FA66F" : "#C97A7A";
    QString couleurStatut = (statut == "Actif") ? "#6FA66F" : "#C97A7A";
    QString iconStatut    = (statut == "Actif") ? "&#9679; Actif" : "&#9679; Inactif";
    QString remise        = (type == "Entreprise") ? "15%" : "5%";

    auto setKpi = [&](const QString &objName, const QString &icon, const QString &value, const QString &color = "#C8E6C9") {
        QLabel *lbl = grp->findChild<QLabel*>(objName);
        if (lbl) lbl->setText(icon + "<br><span style='color:" + color + "; font-size:11pt; font-weight:bold;'>" + value + "</span>");
    };
    setKpi("kpiNbCmd",    "&#128196; Commandes",  QString::number(infos.nbCommandes));
    setKpi("kpiCA",       "&#128176; CA Total",   QString::number(infos.montantTotal,'f',0) + " DT", "#9EE6B0");
    setKpi("kpiMoyCmd",   "&#128083; Moy./cmd",   QString::number(infos.montantMoyen,'f',0) + " DT");
    setKpi("kpiTauxAnn",  "&#10060; Annulations", QString::number(tauxAnn,'f',1) + "%", couleurTaux);
    setKpi("kpiDerniere", "&#128337; Derni&egrave;re cmd", infos.derniereCommande.isEmpty() ? "Aucune" : infos.derniereCommande);
    setKpi("kpiStatut",   "&#9679; Statut",        iconStatut + " | Remise : " + remise, couleurStatut);

    QList<ClientCommandeInfo> commandes;
    QString erreur;
    Client::getCommandesDuClient(idClient, &commandes, &erreur);

    const QColor bgColor("#1E2521"), plotBg("#151A18"), textColor("#E8F0E8"), gridColor("#3A4941");
    const QColor greenBar("#67D98A"), redBar("#C97A7A");

    QStringList labels;
    auto *setMontants = new QBarSet("Montant (DT)"); setMontants->setColor(greenBar);
    auto *setAnn      = new QBarSet("Annulée");      setAnn->setColor(redBar);

    int start = qMax(0, commandes.size() - 8);
    for (int i = start; i < commandes.size(); ++i) {
        const ClientCommandeInfo &c = commandes.at(i);
        labels << "#" + QString::number(c.idCommande);
        bool ann = c.etat.toUpper().contains("ANNUL");
        *setMontants << (ann ? 0.0 : c.montant);
        *setAnn      << (ann ? c.montant : 0.0);
    }
    if (commandes.isEmpty()) { labels << "Aucune commande"; *setMontants << 0.0; *setAnn << 0.0; }

    auto *series = new QBarSeries(); series->append(setMontants); series->append(setAnn);
    auto *chart  = new QChart();
    chart->addSeries(series);
    chart->setTitle("Montants par commande — " + nom);
    chart->setAnimationOptions(QChart::SeriesAnimations);
    chart->setBackgroundBrush(QBrush(bgColor));
    chart->setPlotAreaBackgroundVisible(true);
    chart->setPlotAreaBackgroundBrush(QBrush(plotBg));
    chart->setTitleBrush(QBrush(textColor));
    if (chart->legend()) { chart->legend()->setLabelColor(textColor); chart->legend()->setAlignment(Qt::AlignBottom); }

    auto *axX = new QBarCategoryAxis(); axX->append(labels);
    axX->setLabelsColor(textColor); axX->setGridLineColor(gridColor); axX->setLinePenColor(gridColor);
    chart->addAxis(axX, Qt::AlignBottom); series->attachAxis(axX);
    auto *axY = new QValueAxis(); axY->setLabelFormat("%.0f");
    axY->setLabelsColor(textColor); axY->setGridLineColor(gridColor); axY->setLinePenColor(gridColor);
    chart->addAxis(axY, Qt::AlignLeft); series->attachAxis(axY);

    QChart *old = m_clientChartHistorique->chart();
    m_clientChartHistorique->setChart(chart);
    if (old) delete old;
}

void MainWindow::clearClientInfo()
{
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

    if (ui->grpHistorique) {
        const QStringList kpis  = {"kpiNbCmd","kpiCA","kpiMoyCmd","kpiTauxAnn","kpiDerniere","kpiStatut"};
        const QStringList icons = {"&#128196;","&#128176;","&#128083;","&#10060;","&#128337;","&#9679;"};
        for (int i = 0; i < kpis.size(); ++i) {
            QLabel *lbl = ui->grpHistorique->findChild<QLabel*>(kpis.at(i));
            if (lbl) lbl->setText(icons.at(i) + "<br><b>-</b>");
        }
    }
    if (m_clientChartHistorique) {
        auto *empty = new QChart();
        empty->setTitle("Aucun client sélectionné");
        empty->setBackgroundBrush(QBrush(QColor("#1E2521")));
        empty->setTitleBrush(QBrush(QColor("#E8F0E8")));
        QChart *old = m_clientChartHistorique->chart();
        m_clientChartHistorique->setChart(empty);
        if (old) delete old;
    }
}

void MainWindow::clearFormAjouter()
{
    ui->txtAjouterNom->clear();
    ui->txtAjouterTel->clear();
    ui->txtAjouterEmail->clear();
    ui->cmbAjouterType->setCurrentIndex(0);
    ui->cmbAjouterStatut->setCurrentIndex(0);
}

// --- PDF helpers (static, local to this module) ---

static QString buildListeClientsHTML(QTableWidget *table)
{
    QString html;
    html += "<html><head><style>"
            "body{font-family:Arial,sans-serif;color:#2C2C2C;margin:20px;}"
            "h1{color:#3D4F3C;border-bottom:3px solid #7A9E7E;padding-bottom:8px;}"
            "table{border-collapse:collapse;width:100%;margin-top:10px;}"
            "th{background-color:#7A9E7E;color:white;padding:10px 8px;text-align:left;}"
            "td{padding:8px;border-bottom:1px solid #E8E0D5;}"
            "tr:nth-child(even){background-color:#F5F0EA;}"
            ".footer{margin-top:40px;font-size:9pt;color:#888;border-top:1px solid #D5D5D5;padding-top:8px;}"
            "</style></head><body>";
    html += "<h1>&#128196; Liste Compl&#232;te des Clients &#8212; Smart Oil Press</h1>";
    html += "<p style='color:#888;font-size:9pt;'>G&#233;n&#233;r&#233; le : " +
            QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</p>";
    html += "<table><tr><th>ID</th><th>Nom</th><th>Type</th><th>T&#233;l&#233;phone</th><th>Email</th><th>Statut</th></tr>";
    int count = 0;
    for (int i = 0; i < table->rowCount(); ++i) {
        if (table->isRowHidden(i)) continue;
        ++count;
        html += "<tr>";
        for (int j = 0; j < 6; ++j)
            html += "<td>" + (table->item(i,j) ? table->item(i,j)->text() : "") + "</td>";
        html += "</tr>";
    }
    html += "</table><p style='font-size:9pt;color:#555;'>Total : <b>" + QString::number(count) + "</b> client(s)</p>";
    html += "<div class='footer'>Smart Oil Press &#8212; " + QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static QString buildStatistiquesHTML(QTableWidget *table)
{
    int actif=0,inactif=0,particulier=0,entreprise=0;
    for (int i=0;i<table->rowCount();++i) {
        if (table->isRowHidden(i)) continue;
        QString s = table->item(i,5) ? table->item(i,5)->text() : "";
        QString t = table->item(i,2) ? table->item(i,2)->text() : "";
        if (s=="Actif") actif++; else inactif++;
        if (t=="Particulier") particulier++; else entreprise++;
    }
    int total=actif+inactif;
    int pctP=total>0?(particulier*100/total):0, pctE=total>0?(entreprise*100/total):0;
    QString html;
    html += "<html><head><style>body{font-family:Arial,sans-serif;color:#2C2C2C;margin:20px;}"
            "h1{color:#3D4F3C;border-bottom:3px solid #7A9E7E;padding-bottom:8px;}h2{color:#5A7259;margin-top:24px;}"
            "table{border-collapse:collapse;width:65%;margin-top:10px;}"
            "th{background-color:#7A9E7E;color:white;padding:10px;text-align:left;}"
            "td{padding:10px;border-bottom:1px solid #E8E0D5;}tr:nth-child(even){background-color:#F5F0EA;}"
            ".footer{margin-top:40px;font-size:9pt;color:#888;border-top:1px solid #D5D5D5;padding-top:8px;}"
            "</style></head><body>";
    html += "<h1>&#128202; Rapport Statistiques Clients &#8212; Smart Oil Press</h1>";
    html += "<p style='color:#888;font-size:9pt;'>G&#233;n&#233;r&#233; le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</p>";
    html += "<h2>Vue d'ensemble</h2><table><tr><th>Indicateur</th><th>Valeur</th></tr>"
            "<tr><td>Total</td><td><b>" + QString::number(total) + "</b></td></tr>"
            "<tr><td>Actifs</td><td>" + QString::number(actif) + "</td></tr>"
            "<tr><td>Inactifs</td><td>" + QString::number(inactif) + "</td></tr></table>";
    html += "<h2>R&#233;partition par type</h2><table><tr><th>Type</th><th>Nombre</th><th>%</th></tr>"
            "<tr><td>Particuliers</td><td>" + QString::number(particulier) + "</td><td>" + QString::number(pctP) + "%</td></tr>"
            "<tr><td>Entreprises</td><td>"  + QString::number(entreprise)  + "</td><td>" + QString::number(pctE) + "%</td></tr></table>";
    html += "<div class='footer'>Smart Oil Press &#8212; " + QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static QString buildFicheClientHTML(QTableWidget *table, const QString &clientId)
{
    QString html;
    html += "<html><head><style>body{font-family:Arial,sans-serif;color:#2C2C2C;margin:20px;}"
            "h1{color:#3D4F3C;border-bottom:3px solid #7A9E7E;padding-bottom:8px;}"
            "table{border-collapse:collapse;width:80%;margin-top:10px;}"
            "th{background-color:#7A9E7E;color:white;padding:10px;text-align:left;width:40%;}"
            "td{padding:10px;border-bottom:1px solid #E8E0D5;}"
            ".footer{margin-top:40px;font-size:9pt;color:#888;border-top:1px solid #D5D5D5;padding-top:8px;}"
            "</style></head><body>";
    int foundRow=-1;
    for (int i=0;i<table->rowCount();++i) {
        if (table->item(i,0) && table->item(i,0)->text()==clientId) { foundRow=i; break; }
    }
    if (foundRow==-1) {
        html += "<h1>Fiche Client</h1><p style='color:#C97A7A;'>&#10060; Client non trouv&#233; : " + clientId + "</p>";
    } else {
        QString nom=table->item(foundRow,1)->text(), type=table->item(foundRow,2)->text();
        QString tel=table->item(foundRow,3)->text(), email=table->item(foundRow,4)->text();
        QString statut=table->item(foundRow,5)->text();
        html += "<h1>&#128203; Fiche Client &#8212; " + nom + "</h1>";
        html += "<p style='color:#888;font-size:9pt;'>G&#233;n&#233;r&#233; le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm") + "</p>";
        html += "<table><tr><th>ID</th><td>" + clientId + "</td></tr>"
                "<tr><th>Nom</th><td><b>" + nom + "</b></td></tr>"
                "<tr><th>Type</th><td>" + type + "</td></tr>"
                "<tr><th>T&#233;l&#233;phone</th><td>" + tel + "</td></tr>"
                "<tr><th>Email</th><td>" + email + "</td></tr>"
                "<tr><th>Statut</th><td>" + statut + "</td></tr>"
                "<tr><th>Remise</th><td>" + (type=="Entreprise" ? "15%" : "5%") + "</td></tr></table>";
    }
    html += "<div class='footer'>Smart Oil Press &#8212; " + QDateTime::currentDateTime().toString("yyyy") + "</div></body></html>";
    return html;
}

static void saveClientPDF(QWidget *parent, const QString &html, const QString &defaultName, QTextEdit *msgBox)
{
    QString fileName = QFileDialog::getSaveFileName(parent, "Enregistrer le PDF", defaultName, "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;
    QTextDocument doc; doc.setHtml(html);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageMargins(QMarginsF(15,15,15,15), QPageLayout::Millimeter);
    doc.print(&printer);
    if (msgBox) msgBox->append("&#10003; PDF export&#233; : " + fileName);
    QMessageBox::information(parent, "Succès", "PDF exporté avec succès !\n" + fileName);
}

void MainWindow::onExportListeClientsClicked()
{
    saveClientPDF(this, buildListeClientsHTML(ui->tableClients),
                  "liste_clients.pdf", ui->textEdit_export_messages1);
}

void MainWindow::onExportStatistiquesClicked()
{
    saveClientPDF(this, buildStatistiquesHTML(ui->tableClients),
                  "statistiques_clients.pdf", ui->textEdit_export_messages1);
}

void MainWindow::onExportFicheClientClicked()
{
    const QString id = ui->lineEdit_id_export1->text().trimmed();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "ID manquant", "Veuillez saisir un ID client.");
        return;
    }
    saveClientPDF(this, buildFicheClientHTML(ui->tableClients, id),
                  "fiche_client_" + id + ".pdf", ui->textEdit_export_messages1);
}

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
    const QString apiKey = "";
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
    if (reply->request().url().host().contains("brevo.com")) {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "Email envoyé avec succès via Brevo";
        } else {
            qDebug() << "Erreur d'envoi Brevo:" << reply->errorString();
            qDebug() << "Réponse:" << reply->readAll();
            QMessageBox::warning(this, "Erreur d'envoi",
                                 "Échec de l'envoi de l'email : " + reply->errorString());
        }
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

// === MODULE MACHINE ===

void MainWindow::setupMachineConnections()
{
    if (!ui->tableMachines) {
        qDebug() << "[Machine] tableMachines not found!";
        return;
    }

    // Configure table
    ui->tableMachines->setColumnCount(8);
    ui->tableMachines->setHorizontalHeaderLabels({
        "ID", "Nom", "Catégorie", "Référence", 
        "Date Achat", "État", "Localisation", "Fin Garantie"
    });
    ui->tableMachines->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableMachines->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableMachines->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tableMachines->setAlternatingRowColors(true);
    
    // CRUD buttons
    if (ui->btnConfirmerAjouter_mach) {
        connect(ui->btnConfirmerAjouter_mach, &QPushButton::clicked, 
                this, &MainWindow::ajouterMachine);
    }
    if (ui->btnAnnulerAjouter_mach) {
        connect(ui->btnAnnulerAjouter_mach, &QPushButton::clicked, 
                this, &MainWindow::clearMachineAddForm);
    }
    if (ui->btnConfirmerModifier_mach) {
        connect(ui->btnConfirmerModifier_mach, &QPushButton::clicked, 
                this, &MainWindow::modifierMachine);
    }
    if (ui->btnAnnulerModifier_mach) {
        connect(ui->btnAnnulerModifier_mach, &QPushButton::clicked, 
                this, &MainWindow::clearMachineModifierForm);
    }
    if (ui->btnConfirmerSupprimer_mach) {
        connect(ui->btnConfirmerSupprimer_mach, &QPushButton::clicked, 
                this, &MainWindow::supprimerMachine);
    }
    if (ui->btnAnnulerSupprimer_mach) {
        connect(ui->btnAnnulerSupprimer_mach, &QPushButton::clicked, 
                this, &MainWindow::clearMachineSuppressionForm);
    }
    
    // Refresh and export buttons
    if (ui->btnRefresh) {
        connect(ui->btnRefresh, &QPushButton::clicked, 
                this, &MainWindow::afficherMachines);
    }
    if (ui->btnExportPDF_mach) {
        connect(ui->btnExportPDF_mach, &QPushButton::clicked, 
                this, &MainWindow::exportMachineListePdf);
    }
    if (ui->btnExportStats) {
        connect(ui->btnExportStats, &QPushButton::clicked, 
                this, &MainWindow::exportMachineStatsPdf);
    }
    if (ui->btnRefreshHistorique) {
        connect(ui->btnRefreshHistorique, &QPushButton::clicked, 
                this, &MainWindow::refreshMachineHistory);
    }
    
    // Panne button
    if (ui->btnSignalerPanne) {
        connect(ui->btnSignalerPanne, &QPushButton::clicked, 
                this, &MainWindow::onSignalPanneMachine);
    }
    
    // Table selection
    if (ui->tableMachines) {
        connect(ui->tableMachines, &QTableWidget::itemSelectionChanged, 
                this, &MainWindow::onMachineSelectionChanged);
    }
    
    // Tab change
    if (ui->tabWidget_mach) {
        connect(ui->tabWidget_mach, &QTabWidget::currentChanged, 
                this, [this](int index) {
            updateMachineToolControlsVisibility();
            if (ui->tabWidget_mach->currentWidget() == ui->tabStatistiques_mach) {
                if (!machineStatsTopChartView) {
                    setupMachineCharts();
                }
                refreshMachineStats();
            } else if (ui->tabWidget_mach->currentWidget() == ui->tabHistorique_mach) {
                refreshMachineHistory();
            }
        });
    }
    
    // Filter and sort controls
    if (ui->btnApplyFilter) {
        connect(ui->btnApplyFilter, &QPushButton::clicked, 
                this, &MainWindow::applyMachineFiltersAndSorting);
    }
    if (ui->lineEditSearch) {
        connect(ui->lineEditSearch, &QLineEdit::textChanged, 
                this, &MainWindow::applyMachineFiltersAndSorting);
    }
    if (ui->comboCategory) {
        connect(ui->comboCategory, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &MainWindow::applyMachineFiltersAndSorting);
    }
    if (ui->comboState) {
        connect(ui->comboState, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &MainWindow::applyMachineFiltersAndSorting);
    }
    if (ui->lineEditLocation) {
        connect(ui->lineEditLocation, &QLineEdit::textChanged, 
                this, &MainWindow::applyMachineFiltersAndSorting);
    }
    if (ui->comboSortBy) {
        connect(ui->comboSortBy, QOverload<int>::of(&QComboBox::currentIndexChanged), 
                this, &MainWindow::applyMachineFiltersAndSorting);
    }
    if (ui->radioCroissant) {
        connect(ui->radioCroissant, &QRadioButton::toggled, 
                this, [this](bool) { applyMachineFiltersAndSorting(); });
    }
    if (ui->radioDecroissant) {
        connect(ui->radioDecroissant, &QRadioButton::toggled, 
                this, [this](bool) { applyMachineFiltersAndSorting(); });
    }
    if (ui->btnScanQR) {
        connect(ui->btnScanQR, &QPushButton::clicked, 
                this, &MainWindow::scanMachineQRCode);
    }

    updateMachineToolControlsVisibility();
    qDebug() << "[Machine] Connections setup complete";
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
    
    // Load all machines from database
    if (!MachineWidget::listMachines(&machines, &error)) {
        qDebug() << "[Machine] Error loading machines:" << error;
        QMessageBox::critical(this, "Erreur Machine", 
            "Impossible de charger les machines:\n" + error);
        return;
    }

    // Apply filters
    const QString searchText = ui->lineEditSearch ? 
        ui->lineEditSearch->text().trimmed().toLower() : QString();
    const QString selectedCategory = ui->comboCategory ? 
        ui->comboCategory->currentText().toLower() : QString();
    const QString selectedState = ui->comboState ? 
        ui->comboState->currentText().toLower() : QString();
    const QString locationFilter = ui->lineEditLocation ? 
        ui->lineEditLocation->text().trimmed().toLower() : QString();

    QList<MachineData> filtered;
    for (const MachineData &mach : machines) {
        QString name = mach.nom.trimmed().toLower();
        QString reference = mach.reference.trimmed().toLower();
        QString category = mach.categorie.trimmed().toLower();
        QString etat = mach.etatAchat.trimmed().toLower();
        QString location = mach.localisation.trimmed().toLower();

        // Search filter
        if (!searchText.isEmpty()) {
            if (!name.contains(searchText) && !reference.contains(searchText) && 
                !location.contains(searchText)) {
                continue;
            }
        }

        // Category filter
        if (!selectedCategory.isEmpty() && selectedCategory != "toutes" && 
            selectedCategory != "autre") {
            if (selectedCategory != category) {
                continue;
            }
        }

        // "Autre" category filter
        if (!selectedCategory.isEmpty() && selectedCategory == "autre") {
            if (category == "presse" || category == "moteur" || 
                category == "filtre" || category == "capteur") {
                continue;
            }
        }

        // State filter
        if (!selectedState.isEmpty() && selectedState != "tous") {
            if (etat != selectedState.toLower()) {
                continue;
            }
        }

        // Location filter
        if (!locationFilter.isEmpty() && !location.contains(locationFilter)) {
            continue;
        }

        filtered.append(mach);
    }

    // Apply sorting
    const QString sortBy = ui->comboSortBy ? 
        ui->comboSortBy->currentText().toLower() : QString();
    const bool ascending = ui->radioCroissant ? ui->radioCroissant->isChecked() : true;

    std::sort(filtered.begin(), filtered.end(), 
        [sortBy, ascending](const MachineData &a, const MachineData &b) {
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
            cmp = a.dateFinGarantie < b.dateFinGarantie ? -1 : 
                  (a.dateFinGarantie > b.dateFinGarantie ? 1 : 0);
        }
        return ascending ? (cmp < 0) : (cmp > 0);
    });

    // Fill table
    ui->tableMachines->setRowCount(filtered.size());
    for (int i = 0; i < filtered.size(); ++i) {
        const MachineData &m = filtered.at(i);
        ui->tableMachines->setItem(i, 0, new QTableWidgetItem(QString::number(m.idMachine)));
        ui->tableMachines->setItem(i, 1, new QTableWidgetItem(m.nom));
        ui->tableMachines->setItem(i, 2, new QTableWidgetItem(m.categorie));
        ui->tableMachines->setItem(i, 3, new QTableWidgetItem(m.reference));
        ui->tableMachines->setItem(i, 4, new QTableWidgetItem(
            m.dateAchat.isValid() ? m.dateAchat.toString("dd/MM/yyyy") : ""));
        ui->tableMachines->setItem(i, 5, new QTableWidgetItem(getEtatDisplayText(m.etatAchat)));
        ui->tableMachines->setItem(i, 6, new QTableWidgetItem(m.localisation));
        ui->tableMachines->setItem(i, 7, new QTableWidgetItem(
            m.dateFinGarantie.isValid() ? m.dateFinGarantie.toString("dd/MM/yyyy") : ""));
        
        // Color code the state
        QTableWidgetItem *stateItem = ui->tableMachines->item(i, 5);
        if (stateItem) {
            stateItem->setForeground(QBrush(getEtatColor(m.etatAchat)));
        }
    }
    ui->tableMachines->resizeColumnsToContents();
    
    // Update stats display
    if (ui->tabWidget_mach && ui->tabWidget_mach->currentWidget() == ui->tabStatistiques_mach) {
        refreshMachineStats();
    }
}

void MainWindow::clearMachineAddForm()
{
    if (!ui->editAddId) return;
    ui->editAddId->clear();
    if (ui->editAddNom) ui->editAddNom->clear();
    if (ui->comboAddCategorie) ui->comboAddCategorie->setCurrentIndex(0);
    if (ui->editAddReference) ui->editAddReference->clear();
    if (ui->dateAddAchat) ui->dateAddAchat->setDate(QDate::currentDate());
    if (ui->comboAddEtat) ui->comboAddEtat->setCurrentIndex(0);
    if (ui->editAddLocalisation) ui->editAddLocalisation->clear();
}

void MainWindow::clearMachineModifierForm()
{
    if (!ui->editModifierId) return;
    ui->editModifierId->clear();
    if (ui->editModifierNom) ui->editModifierNom->clear();
    if (ui->comboModifierCategorie) ui->comboModifierCategorie->setCurrentIndex(0);
    if (ui->editModifierReference) ui->editModifierReference->clear();
    if (ui->dateModifierAchat) ui->dateModifierAchat->setDate(QDate::currentDate());
    if (ui->comboModifierEtat) ui->comboModifierEtat->setCurrentIndex(0);
    if (ui->editModifierLocalisation) ui->editModifierLocalisation->clear();
}

void MainWindow::clearMachineSuppressionForm()
{
    if (ui->lblSupprimerNom_mach) 
        ui->lblSupprimerNom_mach->setText("Aucune machine sélectionnée");
    if (ui->lblSupprimerDetails_mach) 
        ui->lblSupprimerDetails_mach->setText("-");
}

void MainWindow::ajouterMachine()
{
    // Validate ID
    const int idMachine = parseMachineId(ui->editAddId ? ui->editAddId->text() : QString());
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide (doit être un nombre positif).");
        return;
    }

    // Validate Nom
    const QString nom = ui->editAddNom ? ui->editAddNom->text().trimmed() : QString();
    if (nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom de la machine est obligatoire.");
        return;
    }

    // Build machine data
    MachineData data;
    data.idMachine = idMachine;
    data.nom = nom;
    data.categorie = ui->comboAddCategorie ? ui->comboAddCategorie->currentText() : "";
    data.reference = ui->editAddReference ? ui->editAddReference->text().trimmed() : "";
    data.dateAchat = ui->dateAddAchat ? ui->dateAddAchat->date() : QDate::currentDate();
    data.etatAchat = ui->comboAddEtat ? ui->comboAddEtat->currentText() : "";
    data.localisation = ui->editAddLocalisation ? ui->editAddLocalisation->text().trimmed() : "";
    
    if (!data.dateAchat.isValid()) data.dateAchat = QDate::currentDate();
    data.dateFinGarantie = data.dateAchat.addYears(1);
    data.idLabo = 1; // Default labo ID

    // Validate and add
    QString error;
    if (!MachineWidget::addMachine(data, &error)) {
        QMessageBox::critical(this, "Erreur Machine", 
            "Impossible d'ajouter la machine:\n" + error);
        return;
    }

    QMessageBox::information(this, "Succès", "Machine ajoutée avec succès.");
    clearMachineAddForm();
    afficherMachines();
    refreshMachineHistory();
}

void MainWindow::modifierMachine()
{
    // Validate ID
    const int idMachine = parseMachineId(ui->editModifierId ? ui->editModifierId->text() : QString());
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide pour modification.");
        return;
    }

    // Get existing machine to verify it exists
    MachineData existingMachine;
    QString error;
    if (!MachineWidget::getMachineById(idMachine, &existingMachine, &error)) {
        QMessageBox::warning(this, "Erreur", "Machine non trouvée:\n" + error);
        return;
    }

    // Build updated data
    MachineData data;
    data.idMachine = idMachine;
    data.nom = ui->editModifierNom ? ui->editModifierNom->text().trimmed() : "";
    data.categorie = ui->comboModifierCategorie ? ui->comboModifierCategorie->currentText() : "";
    data.reference = ui->editModifierReference ? ui->editModifierReference->text().trimmed() : "";
    data.dateAchat = ui->dateModifierAchat ? ui->dateModifierAchat->date() : QDate::currentDate();
    data.etatAchat = ui->comboModifierEtat ? ui->comboModifierEtat->currentText() : "";
    data.localisation = ui->editModifierLocalisation ? ui->editModifierLocalisation->text().trimmed() : "";
    
    if (!data.dateAchat.isValid()) data.dateAchat = QDate::currentDate();
    data.dateFinGarantie = data.dateAchat.addYears(1);
    data.idLabo = 1;

    // Validate
    if (data.nom.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom de la machine est obligatoire.");
        return;
    }

    // Update
    int rowsAffected = 0;
    if (!MachineWidget::updateMachine(idMachine, data, &rowsAffected, &error)) {
        QMessageBox::critical(this, "Erreur Machine", 
            "Impossible de modifier la machine:\n" + error);
        return;
    }

    if (rowsAffected <= 0) {
        QMessageBox::warning(this, "Erreur", "Aucune machine modifiée (ID peut-être invalide).");
        return;
    }

    QMessageBox::information(this, "Succès", "Machine modifiée avec succès.");
    clearMachineModifierForm();
    afficherMachines();
    refreshMachineHistory();
}

void MainWindow::supprimerMachine()
{
    const int row = ui->tableMachines ? ui->tableMachines->currentRow() : -1;
    if (row < 0) {
        QMessageBox::warning(this, "Validation", 
            "Veuillez sélectionner une machine à supprimer dans la liste.");
        return;
    }

    QTableWidgetItem *idItem = ui->tableMachines->item(row, 0);
    if (!idItem) return;
    
    const int idMachine = idItem->text().toInt();
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide.");
        return;
    }

    QString machineName = ui->tableMachines->item(row, 1) ? 
        ui->tableMachines->item(row, 1)->text() : QString::number(idMachine);

    auto reply = QMessageBox::question(this, "Confirmation", 
        QString("Voulez-vous vraiment supprimer la machine \"%1\" (ID: %2) ?\n"
                "Cette action est irréversible.").arg(machineName).arg(idMachine),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply != QMessageBox::Yes) return;

    int rowsAffected = 0;
    QString error;
    if (!MachineWidget::deleteMachine(idMachine, &rowsAffected, &error)) {
        QMessageBox::critical(this, "Erreur Machine", 
            "Impossible de supprimer la machine:\n" + error);
        return;
    }

    if (rowsAffected <= 0) {
        QMessageBox::warning(this, "Erreur", "Aucune machine supprimée (ID peut-être invalide).");
        return;
    }

    QMessageBox::information(this, "Succès", "Machine supprimée avec succès.");
    clearMachineSuppressionForm();
    afficherMachines();
    refreshMachineHistory();
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
        qDebug() << "[Machine] Error loading machine for selection:" << error;
        return;
    }

    // Update suppression tab
    if (ui->lblSupprimerNom_mach) {
        ui->lblSupprimerNom_mach->setText(machine.nom.isEmpty() ? 
            "(nom indisponible)" : machine.nom);
    }
    if (ui->lblSupprimerDetails_mach) {
        ui->lblSupprimerDetails_mach->setText(
            QString("ID: %1 | Catégorie: %2 | État: %3 | Localisation: %4")
            .arg(machine.idMachine)
            .arg(machine.categorie)
            .arg(getEtatDisplayText(machine.etatAchat))
            .arg(machine.localisation));
    }

    // Update modification tab
    if (ui->editModifierId) ui->editModifierId->setText(QString::number(machine.idMachine));
    if (ui->editModifierNom) ui->editModifierNom->setText(machine.nom);
    if (ui->comboModifierCategorie) ui->comboModifierCategorie->setCurrentText(machine.categorie);
    if (ui->editModifierReference) ui->editModifierReference->setText(machine.reference);
    if (ui->dateModifierAchat && machine.dateAchat.isValid()) {
        ui->dateModifierAchat->setDate(machine.dateAchat);
    }
    if (ui->comboModifierEtat) ui->comboModifierEtat->setCurrentText(machine.etatAchat);
    if (ui->editModifierLocalisation) ui->editModifierLocalisation->setText(machine.localisation);
}

void MainWindow::onSignalPanneMachine()
{
    const int row = ui->tableMachines ? ui->tableMachines->currentRow() : -1;
    if (row < 0) {
        QMessageBox::warning(this, "Validation", 
            "Veuillez sélectionner une machine pour signaler une panne.");
        return;
    }

    QTableWidgetItem *idItem = ui->tableMachines->item(row, 0);
    if (!idItem) return;
    
    const int idMachine = idItem->text().toInt();
    if (idMachine <= 0) {
        QMessageBox::warning(this, "Validation", "ID Machine invalide.");
        return;
    }

    QString machineName = ui->tableMachines->item(row, 1) ? 
        ui->tableMachines->item(row, 1)->text() : QString::number(idMachine);

    auto reply = QMessageBox::question(this, "Signaler une panne", 
        QString("Voulez-vous signaler une panne pour la machine \"%1\" (ID: %2) ?")
        .arg(machineName).arg(idMachine),
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply != QMessageBox::Yes) return;

    MachineData machine;
    QString error;
    if (!MachineWidget::getMachineById(idMachine, &machine, &error)) {
        QMessageBox::critical(this, "Erreur Machine", 
            "Machine non trouvée:\n" + error);
        return;
    }

    machine.etatAchat = "Panne";
    int rowsAffected = 0;
    
    if (!MachineWidget::updateMachine(idMachine, machine, &rowsAffected, &error)) {
        QMessageBox::critical(this, "Erreur Machine", 
            "Impossible de signaler la panne:\n" + error);
        return;
    }

    afficherMachines();
    QMessageBox::information(this, "Succès", 
        QString("Panne signalée pour la machine \"%1\".").arg(machineName));
}

void MainWindow::exportMachineListePdf()
{
    if (!ui->tableMachines || ui->tableMachines->rowCount() == 0) {
        QMessageBox::warning(this, "Export PDF", "Aucune machine à exporter.");
        return;
    }

    const QString fileName = QFileDialog::getSaveFileName(this, 
        "Enregistrer le PDF", 
        QString("liste_machines_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")), 
        "Fichiers PDF (*.pdf)");
    
    if (fileName.isEmpty()) return;

    // Build HTML for PDF
    QString html = "<html><head><style>"
                   "body { font-family: Arial, sans-serif; margin: 20px; }"
                   "h1 { color: #2E7D32; text-align: center; }"
                   "table { border-collapse: collapse; width: 100%; margin-top: 20px; }"
                   "th { background-color: #7A9E7E; color: white; padding: 10px; text-align: left; }"
                   "td { border: 1px solid #ddd; padding: 8px; }"
                   "tr:nth-child(even) { background-color: #f2f2f2; }"
                   ".footer { margin-top: 30px; text-align: center; font-size: 10px; color: gray; }"
                   "</style></head><body>";
    
    html += "<h1>📋 Liste des Machines - Smart Oil Press</h1>";
    html += "<p>Généré le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss") + "</p>";
    html += "<table>";
    html += "<tr><th>ID</th><th>Nom</th><th>Catégorie</th><th>Référence</th>"
            "<th>Date Achat</th><th>État</th><th>Localisation</th><th>Fin Garantie</th></tr>";
    
    for (int r = 0; r < ui->tableMachines->rowCount(); ++r) {
        html += "<tr>";
        for (int c = 0; c < ui->tableMachines->columnCount(); ++c) {
            QTableWidgetItem *item = ui->tableMachines->item(r, c);
            html += "<td>" + (item ? item->text().toHtmlEscaped() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";
    html += "<div class='footer'>Smart Oil Press Management System</div>";
    html += "</body></html>";
    
    QTextDocument doc;
    doc.setHtml(html);
    
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageOrientation(QPageLayout::Landscape);
    doc.print(&printer);
    
    QMessageBox::information(this, "Export PDF", 
        "Export PDF de la liste des machines terminé avec succès.\n" + fileName);
}

void MainWindow::setupMachineCharts()
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

    ensureChartHost(ui->frameMachineStatsTopChart, machineStatsTopChartView);
    ensureChartHost(ui->frameMachineStatsLeftChart, machineStatsLeftChartView);
    ensureChartHost(ui->frameMachineStatsRightChart, machineStatsRightChartView);
}

void MainWindow::refreshMachineStats()
{
    if (!machineStatsTopChartView || !machineStatsLeftChartView || !machineStatsRightChartView) {
        setupMachineCharts();
    }
    if (!machineStatsTopChartView || !machineStatsLeftChartView || !machineStatsRightChartView) {
        return;
    }
    
    MachineStatsSummary stats;
    QString error;
    
    if (!MachineWidget::getStatsSummary(&stats, &error)) {
        qDebug() << "[Machine] Error loading stats:" << error;
        ui->txtStatistiques_mach->setPlainText("Erreur lors du chargement des statistiques:\n" + error);
        return;
    }
    
    // Update summary labels
    if (ui->lblStatsTotalMachines) 
        ui->lblStatsTotalMachines->setText(QString::number(stats.totalMachines));
    if (ui->lblStatsEnService) 
        ui->lblStatsEnService->setText(QString::number(stats.enService));
    if (ui->lblStatsEnPanne) 
        ui->lblStatsEnPanne->setText(QString::number(stats.enPanne));
    if (ui->lblStatsMaintenance) 
        ui->lblStatsMaintenance->setText(QString::number(stats.maintenance));
    
    const QColor chartBgColor("#1E2521");
    const QColor plotBgColor("#151A18");
    const QColor textColor("#E8F0E8");
    const QColor gridColor("#3A4941");
    const QColor primaryColor("#67D98A");
    const QColor secondaryColor("#4FBF78");
    const QColor accentColor("#9EE6B0");
    const QColor tertiaryColor("#7ACFAC");

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

    {
        auto *series = new QPieSeries();
        series->append("En service", stats.enService);
        series->append("En panne", stats.enPanne);
        series->append("Maintenance", stats.maintenance);
        series->append("Hors service", stats.horsService);
        series->append("En stock", stats.enStock);
        series->append("En attente", stats.enAttente);

        const QList<QColor> sliceColors = {primaryColor, secondaryColor, accentColor, tertiaryColor, QColor("#51A7A3"), QColor("#C7E4C4")};
        const auto slices = series->slices();
        for (int i = 0; i < slices.size(); ++i) {
            QPieSlice *slice = slices.at(i);
            slice->setBrush(sliceColors.at(i % sliceColors.size()));
            slice->setLabelVisible(true);
            slice->setLabelColor(textColor);
            slice->setPen(QPen(QBrush(plotBgColor), 1));
        }

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTitle("Répartition des états des machines");
        applyDarkTheme(chart);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignBottom);
        replaceChart(machineStatsTopChartView, chart);
    }

    {
        QList<MachineCategoryStats> categoryStats;
        if (!MachineWidget::getMachinesByCategory(&categoryStats, &error)) {
            qDebug() << "[Machine] Error loading category stats:" << error;
        }

        auto *setCategory = new QBarSet("Machines");
        QStringList categories;
        for (const MachineCategoryStats &row : categoryStats) {
            categories << row.category;
            *setCategory << row.count;
        }

        auto *series = new QBarSeries();
        series->append(setCategory);
        setCategory->setColor(primaryColor);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);
        chart->setTitle("Machines par catégorie");

        auto *axisX = new QBarCategoryAxis();
        axisX->append(categories);
        axisX->setLabelsColor(textColor);
        axisX->setGridLineColor(gridColor);
        axisX->setLinePenColor(gridColor);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        auto *axisY = new QValueAxis();
        axisY->setLabelFormat("%d");
        axisY->setLabelsColor(textColor);
        axisY->setGridLineColor(gridColor);
        axisY->setLinePenColor(gridColor);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(false);
        replaceChart(machineStatsLeftChartView, chart);
    }

    {
        QList<MachineLabStats> labStats;
        if (!MachineWidget::getMachinesByLab(&labStats, &error)) {
            qDebug() << "[Machine] Error loading lab stats:" << error;
        }

        auto *setLab = new QBarSet("Machines");
        QStringList labNames;
        for (const MachineLabStats &row : labStats) {
            labNames << row.labName;
            *setLab << row.machineCount;
        }

        auto *series = new QBarSeries();
        series->append(setLab);
        setLab->setColor(secondaryColor);

        auto *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        applyDarkTheme(chart);
        chart->setTitle("Machines par laboratoire");

        auto *axisX = new QBarCategoryAxis();
        axisX->append(labNames);
        axisX->setLabelsColor(textColor);
        axisX->setGridLineColor(gridColor);
        axisX->setLinePenColor(gridColor);
        chart->addAxis(axisX, Qt::AlignBottom);
        series->attachAxis(axisX);

        auto *axisY = new QValueAxis();
        axisY->setLabelFormat("%d");
        axisY->setLabelsColor(textColor);
        axisY->setGridLineColor(gridColor);
        axisY->setLinePenColor(gridColor);
        chart->addAxis(axisY, Qt::AlignLeft);
        series->attachAxis(axisY);

        chart->legend()->setVisible(false);
        replaceChart(machineStatsRightChartView, chart);
    }

    // Build detailed statistics text
    QString statsText;
    statsText += "=== STATISTIQUES DES MACHINES ===\n\n";
    statsText += "📊 RÉSUMÉ GÉNÉRAL:\n";
    statsText += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    statsText += QString("• Total des machines : %1\n").arg(stats.totalMachines);
    statsText += QString("• Machines en service : %1 (%2%)\n")
        .arg(stats.enService)
        .arg(stats.totalMachines > 0 ? (stats.enService * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
    statsText += QString("• Machines en panne : %1 (%2%)\n")
        .arg(stats.enPanne)
        .arg(stats.totalMachines > 0 ? (stats.enPanne * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
    statsText += QString("• Machines en maintenance : %1 (%2%)\n")
        .arg(stats.maintenance)
        .arg(stats.totalMachines > 0 ? (stats.maintenance * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
    statsText += QString("• Machines hors service : %1 (%2%)\n")
        .arg(stats.horsService)
        .arg(stats.totalMachines > 0 ? (stats.horsService * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
    statsText += QString("• Machines en stock : %1\n").arg(stats.enStock);
    statsText += QString("• Machines en attente : %1\n").arg(stats.enAttente);
    
    statsText += "\n📈 TAUX DE DISPONIBILITÉ:\n";
    statsText += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    double disponibilite = stats.totalMachines > 0 ? 
        (stats.enService * 100.0 / stats.totalMachines) : 0;
    statsText += QString("• Disponibilité : %1%\n").arg(disponibilite, 0, 'f', 1);
    
    statsText += "\n⚠️ MACHINES NÉCESSITANT UNE ATTENTION:\n";
    statsText += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
    int machinesProbleme = stats.enPanne + stats.maintenance + stats.horsService;
    statsText += QString("• Nombre de machines avec problème : %1\n").arg(machinesProbleme);
    
    if (machinesProbleme > 0) {
        statsText += "\n📋 RECOMMANDATIONS:\n";
        statsText += "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n";
        if (stats.enPanne > 0) {
            statsText += "• " + QString::number(stats.enPanne) + " machine(s) en panne - Intervention technique requise\n";
        }
        if (stats.maintenance > 0) {
            statsText += "• " + QString::number(stats.maintenance) + " machine(s) en maintenance - Suivre l'avancement\n";
        }
        if (stats.horsService > 0) {
            statsText += "• " + QString::number(stats.horsService) + " machine(s) hors service - Évaluer remplacement\n";
        }
    }
    
    ui->txtStatistiques_mach->setPlainText(statsText);
}

void MainWindow::exportMachineStatsPdf()
{
    if (!ui->txtStatistiques_mach) return;
    
    const QString fileName = QFileDialog::getSaveFileName(this, 
        "Enregistrer les statistiques en PDF", 
        QString("statistiques_machines_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")), 
        "Fichiers PDF (*.pdf)");
    
    if (fileName.isEmpty()) return;
    
    // Build HTML for PDF
    QString html = "<html><head><style>"
                   "body { font-family: Arial, sans-serif; margin: 20px; }"
                   "h1 { color: #2E7D32; text-align: center; }"
                   "h2 { color: #7A9E7E; margin-top: 20px; }"
                   "table { border-collapse: collapse; width: 100%; margin-top: 10px; }"
                   "th { background-color: #7A9E7E; color: white; padding: 8px; text-align: left; }"
                   "td { border: 1px solid #ddd; padding: 8px; }"
                   ".stat-box { background-color: #f5f5f5; padding: 15px; margin: 10px 0; border-radius: 5px; }"
                   ".footer { margin-top: 30px; text-align: center; font-size: 10px; color: gray; }"
                   "</style></head><body>";
    
    html += "<h1>📊 Rapport Statistiques des Machines</h1>";
    html += "<p>Généré le : " + QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm:ss") + "</p>";
    
    // Get stats data
    MachineStatsSummary stats;
    QString error;
    if (MachineWidget::getStatsSummary(&stats, &error)) {
        html += "<div class='stat-box'>";
        html += "<h2>Résumé Général</h2>";
        html += "<table>";
        html += "<tr><th>Indicateur</th><th>Valeur</th><th>Pourcentage</th></tr>";
        html += QString("<tr><td>Total des machines</td><td>%1</td><td>100%</td></tr>").arg(stats.totalMachines);
        html += QString("<tr><td>En service</td><td>%1</td><td>%2%</td></tr>")
            .arg(stats.enService)
            .arg(stats.totalMachines > 0 ? (stats.enService * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
        html += QString("<tr><td>En panne</td><td>%1</td><td>%2%</td></tr>")
            .arg(stats.enPanne)
            .arg(stats.totalMachines > 0 ? (stats.enPanne * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
        html += QString("<tr><td>En maintenance</td><td>%1</td><td>%2%</td></tr>")
            .arg(stats.maintenance)
            .arg(stats.totalMachines > 0 ? (stats.maintenance * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
        html += QString("<tr><td>Hors service</td><td>%1</td><td>%2%</td></tr>")
            .arg(stats.horsService)
            .arg(stats.totalMachines > 0 ? (stats.horsService * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
        html += QString("<tr><td>En stock</td><td>%1</td><td>%2%</td></tr>")
            .arg(stats.enStock)
            .arg(stats.totalMachines > 0 ? (stats.enStock * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
        html += QString("<tr><td>En attente</td><td>%1</td><td>%2%</td></tr>")
            .arg(stats.enAttente)
            .arg(stats.totalMachines > 0 ? (stats.enAttente * 100.0 / stats.totalMachines) : 0, 0, 'f', 1);
        html += "\\table";
        html += "</div>";
        
        html += "<div class='stat-box'>";
        html += "<h2>Taux de Disponibilité</h2>";
        double disponibilite = stats.totalMachines > 0 ? 
            (stats.enService * 100.0 / stats.totalMachines) : 0;
        html += QString("<p><strong>Disponibilité globale : %1%</strong></p>").arg(disponibilite, 0, 'f', 1);
        html += "</div>";
    } else {
        html += "<p style='color:red;'>Erreur lors du chargement des statistiques: " + error.toHtmlEscaped() + "</p>";
    }
    
    html += "<div class='footer'>Smart Oil Press Management System - Rapport généré automatiquement</div>";
    html += "</body></html>";
    
    QTextDocument doc;
    doc.setHtml(html);
    
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    printer.setPageOrientation(QPageLayout::Portrait);
    doc.print(&printer);
    
    QMessageBox::information(this, "Export PDF", 
        "Export PDF des statistiques terminé avec succès.\n" + fileName);
}

void MainWindow::refreshMachineHistory()
{
    if (!ui->tableHistoriqueMachines) return;

    QList<MachineHistoryData> history;
    QString error;
    if (!MachineWidget::listMachineHistory(&history, &error)) {
        QMessageBox::warning(this, "Erreur", "Erreur lors du chargement de l'historique:\n" + error);
        return;
    }

    ui->tableHistoriqueMachines->setRowCount(0);
    ui->tableHistoriqueMachines->setRowCount(history.size());

    for (int i = 0; i < history.size(); ++i) {
        const MachineHistoryData &row = history[i];

        // ID Machine
        QTableWidgetItem *idItem = new QTableWidgetItem(QString::number(row.idMachine));
        idItem->setData(Qt::UserRole, row.id);
        ui->tableHistoriqueMachines->setItem(i, 0, idItem);

        // Type Intervention
        ui->tableHistoriqueMachines->setItem(i, 1, new QTableWidgetItem(row.typeIntervention));

        // Description
        ui->tableHistoriqueMachines->setItem(i, 2, new QTableWidgetItem(row.description));

        // Responsable
        ui->tableHistoriqueMachines->setItem(i, 3, new QTableWidgetItem(row.responsable));

        // Resultat
        ui->tableHistoriqueMachines->setItem(i, 4, new QTableWidgetItem(row.resultat));

        // Niveau Urgence
        ui->tableHistoriqueMachines->setItem(i, 5, new QTableWidgetItem(row.niveauUrgence));

        // Cout Intervention
        ui->tableHistoriqueMachines->setItem(i, 6, new QTableWidgetItem(row.coutIntervention == 0.0 ? QString() : QString::number(row.coutIntervention)));

        // Duree Intervention
        ui->tableHistoriqueMachines->setItem(i, 7, new QTableWidgetItem(row.dureeIntervention == 0 ? QString() : QString::number(row.dureeIntervention)));

        // Piece Remplacee
        ui->tableHistoriqueMachines->setItem(i, 8, new QTableWidgetItem(row.pieceRemplacee));

        // Date Intervention
        ui->tableHistoriqueMachines->setItem(i, 9, new QTableWidgetItem(row.dateIntervention.toString("dd/MM/yyyy HH:mm:ss")));
    }

    ui->tableHistoriqueMachines->resizeColumnsToContents();
}

void MainWindow::scanMachineQRCode()
{
    QMessageBox::information(this, "Scanner QR Code",
        "Fonctionnalité de scan QR Code en développement.\n"
        "Cette fonctionnalité permettra de scanner le QR code d'une machine\n"
        "pour accéder rapidement à ses informations.");
}

// ---------------------------------------------------------------------------
// MODULE CHATBOT - Assistant IA
// ---------------------------------------------------------------------------

void MainWindow::setupChatbotConnections()
{
    connect(ui->btnSendMessage, &QPushButton::clicked, this, &MainWindow::sendChatMessage);
    connect(ui->chatInput, &QLineEdit::returnPressed, this, &MainWindow::sendChatMessage);
    connect(ui->btnImportChat, &QPushButton::clicked, this, &MainWindow::importChatConversation);
    connect(ui->btnExportChat, &QPushButton::clicked, this, &MainWindow::exportChatConversation);

    // Initialize chat display
    updateChatDisplay();
}

void MainWindow::sendChatMessage()
{
    QString message = ui->chatInput->text().trimmed();
    if (message.isEmpty()) {
        return;
    }

    // Add user message
    QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString userMessage = QString("[%1] Vous: %2").arg(timestamp, message);
    m_chatMessages.append(userMessage);

    // Clear input
    ui->chatInput->clear();

    // Check if user wants to force external AI usage
    QString lowerMessage = message.toLower();
    bool forceExternalAI = lowerMessage.contains("geminai") || lowerMessage.contains("gemini") ||
                          lowerMessage.contains("ai") || lowerMessage.contains("ia") ||
                          lowerMessage.contains("chatgpt") || lowerMessage.contains("claude") ||
                          lowerMessage.contains("grok") || lowerMessage.contains("openai");

    QString requestedProvider;
    if (forceExternalAI) {
        requestedProvider = detectAIProviderFromMessage(lowerMessage);
    }

    // Generate local AI response and decide whether to use external AI
    QString aiResponse = forceExternalAI ? QString() : generateAIResponse(message);
    bool useExternalAI = (aiResponse.isEmpty() && !getAPIKey(requestedProvider).isEmpty()) || forceExternalAI;
    QString aiTimestamp = QDateTime::currentDateTime().toString("hh:mm:ss");

    if (useExternalAI) {
        QString provider = !requestedProvider.isEmpty() ? requestedProvider : getAIProvider();
        QString aiName = provider;
        if (aiName == "google" || aiName == "gemini") aiName = "Gemini";
        else if (aiName == "openai") aiName = "ChatGPT";
        else if (aiName == "anthropic" || aiName == "claude") aiName = "Claude";
        else if (aiName == "xai" || aiName == "grok") aiName = "Grok";
        else if (aiName.isEmpty()) aiName = "IA";
        else aiName = aiName.toUpper();

        QString placeholder = QString("[%1] Assistant IA: %2").arg(aiTimestamp, QString("Je consulte %1 pour votre demande...").arg(aiName));
        m_chatMessages.append(placeholder);
        updateChatDisplay();
        askAI(message, provider);
    } else {
        if (aiResponse.isEmpty()) {
            aiResponse = "Je n'ai pas pu comprendre votre demande ou aucune IA n'est configurée. Essayez 'aide' ou configurez une API_KEY.";
        }
        QString aiMessage = QString("[%1] Assistant IA: %2").arg(aiTimestamp, aiResponse);
        m_chatMessages.append(aiMessage);
        updateChatDisplay();
    }
}

void MainWindow::importChatConversation()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        "Importer une conversation",
        "",
        "Fichiers texte (*.txt);;Tous les fichiers (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur",
            "Impossible d'ouvrir le fichier: " + file.errorString());
        return;
    }

    QTextStream in(&file);
    m_chatMessages.clear();

    while (!in.atEnd()) {
        QString line = in.readLine();
        if (!line.trimmed().isEmpty()) {
            m_chatMessages.append(line);
        }
    }

    file.close();
    updateChatDisplay();

    QMessageBox::information(this, "Import réussi",
        "La conversation a été importée avec succès.");
}

void MainWindow::exportChatConversation()
{
    if (m_chatMessages.isEmpty()) {
        QMessageBox::information(this, "Aucune conversation",
            "Il n'y a aucune conversation à exporter.");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this,
        "Exporter la conversation",
        QString("conversation_%1.txt").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss")),
        "Fichiers texte (*.txt);;Tous les fichiers (*)");

    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Erreur",
            "Impossible de créer le fichier: " + file.errorString());
        return;
    }

    QTextStream out(&file);
    out << "Conversation Chatbot - " << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "\n";
    out << QString("-").repeated(50) << "\n\n";

    for (const QString &message : m_chatMessages) {
        out << message << "\n";
    }

    file.close();

    QMessageBox::information(this, "Export réussi",
        QString("La conversation a été exportée vers:\n%1").arg(fileName));
}

void MainWindow::updateChatDisplay()
{
    QString htmlContent = "<style>"
        "body { background-color: #F8F9F8; color: #2E3D2E; font-family: Arial, sans-serif; }"
        ".user { color: #7A9E7E; font-weight: bold; }"
        ".ai { color: #6FA66F; font-weight: bold; }"
        ".timestamp { color: #8FB594; font-size: 10px; }"
        "</style>";

    for (const QString &message : m_chatMessages) {
        if (message.contains("Vous:")) {
            htmlContent += QString("<div class='user'>%1</div>").arg(message.toHtmlEscaped());
        } else if (message.contains("Assistant IA:")) {
            htmlContent += QString("<div class='ai'>%1</div>").arg(message.toHtmlEscaped());
        } else {
            htmlContent += QString("<div>%1</div>").arg(message.toHtmlEscaped());
        }
    }

    ui->chatDisplay->setHtml(htmlContent);

    // Auto scroll to bottom
    QTextCursor cursor = ui->chatDisplay->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->chatDisplay->setTextCursor(cursor);
}

QString MainWindow::getAIProvider() const
{
    QString provider = QString::fromUtf8(qgetenv("AI_PROVIDER")).trimmed().toLower();
    return provider;
}

QString MainWindow::detectAIProviderFromMessage(const QString &message) const
{
    if (message.contains("geminai") || message.contains("gemini")) {
        return "google";
    }
    if (message.contains("chatgpt") || message.contains("openai")) {
        return "openai";
    }
    if (message.contains("claude") || message.contains("anthropic")) {
        return "anthropic";
    }
    if (message.contains("grok") || message.contains("xai")) {
        return "xai";
    }
    return QString();
}

QString MainWindow::getAPIKey(const QString &provider) const
{
    QString effectiveProvider = provider.trimmed().toLower();
    if (effectiveProvider.isEmpty()) {
        effectiveProvider = getAIProvider();
    }

    QString envVar;
    if (effectiveProvider == "openai") {
        envVar = "OPENAI_API_KEY";
    } else if (effectiveProvider == "anthropic" || effectiveProvider == "claude") {
        envVar = "ANTHROPIC_API_KEY";
    } else if (effectiveProvider == "google" || effectiveProvider == "gemini") {
        envVar = "GOOGLE_API_KEY";
    } else if (effectiveProvider == "xai" || effectiveProvider == "grok") {
        envVar = "XAI_API_KEY";
    } else if (!effectiveProvider.isEmpty()) {
        envVar = "AI_API_KEY";
    }

    if (envVar.isEmpty()) {
        return QString();
    }

    QString apiKey = QString::fromUtf8(qgetenv(envVar.toUtf8())).trimmed();
    qDebug() << "[DEBUG] Provider:" << effectiveProvider << "| EnvVar:" << envVar << "| ApiKey found:" << !apiKey.isEmpty();

    // Temporary fallback for testing Gemini API
    if (apiKey.isEmpty() && (effectiveProvider == "google" || effectiveProvider == "gemini")) {
        apiKey = "";
        qDebug() << "[DEBUG] Using temporary fallback Gemini API key for testing";
    }

    return apiKey;
}

void MainWindow::askAI(const QString &userMessage, const QString &providerOverride)
{
    const QString provider = providerOverride.trimmed().toLower().isEmpty()
        ? getAIProvider()
        : providerOverride.trimmed().toLower();
    const QString apiKey = getAPIKey(provider);

    if (apiKey.isEmpty()) {
        QString timestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
        QString displayName = provider;
        if (displayName == "google" || displayName == "gemini") displayName = "Gemini";
        else if (displayName == "openai") displayName = "ChatGPT";
        else if (displayName == "anthropic" || displayName == "claude") displayName = "Claude";
        else if (displayName == "xai" || displayName == "grok") displayName = "Grok";
        else displayName = displayName.isEmpty() ? "l'IA" : displayName.toUpper();

        QString errorMessage = QString("[%1] Assistant IA: %2").arg(timestamp,
            QString("Erreur : %1 n'est pas configurée. Veuillez définir la clé API appropriée.").arg(displayName));
        m_chatMessages.append(errorMessage);
        updateChatDisplay();
        return;
    }

    QJsonObject payload;
    QNetworkRequest request;
    QString url;

    if (provider == "openai" || provider.isEmpty()) {
        if (provider.isEmpty()) {
            url = "https://api.openai.com/v1/chat/completions";
        } else {
            url = "https://api.openai.com/v1/chat/completions";
        }
        payload["model"] = "gpt-3.5-turbo";
        QJsonArray messages;
        QJsonObject systemMessage;
        systemMessage["role"] = "system";
        systemMessage["content"] = "Tu es un assistant pour une application de gestion industrielle. Réponds en français et utilise les données de la base quand c'est possible.";
        messages.append(systemMessage);

        QJsonObject userMessageObject;
        userMessageObject["role"] = "user";
        userMessageObject["content"] = userMessage;
        messages.append(userMessageObject);

        payload["messages"] = messages;
        payload["temperature"] = 0.7;
        payload["max_tokens"] = 800;

        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    } else if (provider == "anthropic" || provider == "claude") {
        url = "https://api.anthropic.com/v1/messages";
        payload["model"] = "claude-3-sonnet-20240229";
        payload["max_tokens"] = 800;
        payload["temperature"] = 0.7;
        payload["system"] = "Tu es un assistant pour une application de gestion industrielle. Réponds en français et utilise les données de la base quand c'est possible.";

        QJsonArray messages;
        QJsonObject userMessageObject;
        userMessageObject["role"] = "user";
        userMessageObject["content"] = userMessage;
        messages.append(userMessageObject);
        payload["messages"] = messages;

        request.setRawHeader("x-api-key", apiKey.toUtf8());
        request.setRawHeader("anthropic-version", "2023-06-01");

    } else if (provider == "google" || provider == "gemini") {
        url = QString("https://generativelanguage.googleapis.com/v1beta/models/gemini-2.5-flash:generateContent?key=%1").arg(apiKey);
        QJsonArray contents;
        QJsonObject content;
        content["role"] = "user";
        QJsonArray parts;
        QJsonObject part;
        part["text"] = QString("Tu es un assistant pour une application de gestion industrielle. Réponds en français et utilise les données de la base quand c'est possible.\n\nQuestion: %1").arg(userMessage);
        parts.append(part);
        content["parts"] = parts;
        contents.append(content);
        payload["contents"] = contents;

    } else if (provider == "xai" || provider == "grok") {
        url = "https://api.x.ai/v1/chat/completions";
        payload["model"] = "grok-beta";
        QJsonArray messages;
        QJsonObject systemMessage;
        systemMessage["role"] = "system";
        systemMessage["content"] = "Tu es un assistant pour une application de gestion industrielle. Réponds en français et utilise les données de la base quand c'est possible.";
        messages.append(systemMessage);

        QJsonObject userMessageObject;
        userMessageObject["role"] = "user";
        userMessageObject["content"] = userMessage;
        messages.append(userMessageObject);

        payload["messages"] = messages;
        payload["temperature"] = 0.7;
        payload["max_tokens"] = 800;

        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());

    } else {
        // Custom provider - assume OpenAI-compatible API
        QString customUrl = QString::fromUtf8(qgetenv("AI_API_URL")).trimmed();
        if (customUrl.isEmpty()) {
            customUrl = "https://api.openai.com/v1/chat/completions";
        }
        url = customUrl;

        payload["model"] = QString::fromUtf8(qgetenv("AI_MODEL")).trimmed();
        if (payload["model"].toString().isEmpty()) {
            payload["model"] = "gpt-3.5-turbo";
        }

        QJsonArray messages;
        QJsonObject systemMessage;
        systemMessage["role"] = "system";
        systemMessage["content"] = "Tu es un assistant pour une application de gestion industrielle. Réponds en français et utilise les données de la base quand c'est possible.";
        messages.append(systemMessage);

        QJsonObject userMessageObject;
        userMessageObject["role"] = "user";
        userMessageObject["content"] = userMessage;
        messages.append(userMessageObject);

        payload["messages"] = messages;
        payload["temperature"] = 0.7;
        payload["max_tokens"] = 800;

        request.setRawHeader("Authorization", QString("Bearer %1").arg(apiKey).toUtf8());
    }

    request.setUrl(QUrl(url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QJsonDocument doc(payload);
    m_networkManager->post(request, doc.toJson());
}

void MainWindow::onAIReplyFinished(QNetworkReply *reply)
{
    QUrl requestUrl = reply->request().url();
    QString host = requestUrl.host().toLower();
    bool isAIRequest = host.contains("openai.com") || host.contains("anthropic.com") ||
                       host.contains("googleapis.com") || host.contains("x.ai") ||
                       host.contains("api.x.ai") || host.contains("api.anthropic.com") ||
                       host.contains("api.openai.com") || host.contains("api.googleapis.com");
    if (!isAIRequest && host.contains("brevo.com")) {
        reply->deleteLater();
        return;
    }
    if (!isAIRequest) {
        // Unknown non-AI request; ignore here
        return;
    }

    QString provider;
    if (host.contains("openai.com") || host.contains("api.openai.com")) {
        provider = "openai";
    } else if (host.contains("anthropic.com") || host.contains("api.anthropic.com")) {
        provider = "anthropic";
    } else if (host.contains("googleapis.com")) {
        provider = "google";
    } else if (host.contains("x.ai") || host.contains("api.x.ai")) {
        provider = "xai";
    }

    QString aiResponse;
    if (reply->error() == QNetworkReply::NoError) {
        const QByteArray responseBytes = reply->readAll();
        const QJsonDocument jsonResponse = QJsonDocument::fromJson(responseBytes);

        if (provider == "openai" || provider == "xai" || provider == "grok") {
            if (jsonResponse.isObject()) {
                QJsonObject responseObject = jsonResponse.object();
                QJsonArray choices = responseObject.value("choices").toArray();
                if (!choices.isEmpty()) {
                    QJsonObject firstChoice = choices.first().toObject();
                    QJsonObject messageObject = firstChoice.value("message").toObject();
                    aiResponse = messageObject.value("content").toString().trimmed();
                }
            }
        } else if (provider == "anthropic" || provider == "claude") {
            if (jsonResponse.isObject()) {
                QJsonObject responseObject = jsonResponse.object();
                QJsonArray content = responseObject.value("content").toArray();
                if (!content.isEmpty()) {
                    QJsonObject firstContent = content.first().toObject();
                    aiResponse = firstContent.value("text").toString().trimmed();
                }
            }
        } else if (provider == "google" || provider == "gemini") {
            if (jsonResponse.isObject()) {
                QJsonObject responseObject = jsonResponse.object();
                QJsonArray candidates = responseObject.value("candidates").toArray();
                if (!candidates.isEmpty()) {
                    QJsonObject firstCandidate = candidates.first().toObject();
                    QJsonObject content = firstCandidate.value("content").toObject();
                    QJsonArray parts = content.value("parts").toArray();
                    if (!parts.isEmpty()) {
                        QJsonObject firstPart = parts.first().toObject();
                        aiResponse = firstPart.value("text").toString().trimmed();
                    }
                }
            }
        }
    } else {
        QByteArray errorResponse = reply->readAll();
        int statusCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug() << "[ERROR] HTTP Status:" << statusCode << "| Error:" << reply->errorString() << "| Response:" << QString::fromUtf8(errorResponse);
        aiResponse = QString("Erreur %1 (HTTP %2) : %3").arg(provider.toUpper()).arg(statusCode).arg(reply->errorString());
    }

    if (aiResponse.isEmpty()) {
        aiResponse = "Désolé, l'IA n'a pas renvoyé de réponse valide.";
    }

    QString aiTimestamp = QDateTime::currentDateTime().toString("hh:mm:ss");
    QString aiMessage = QString("[%1] Assistant IA: %2").arg(aiTimestamp, aiResponse);
    m_chatMessages.append(aiMessage);
    updateChatDisplay();
    reply->deleteLater();
}

QString MainWindow::generateAIResponse(const QString &userMessage)
{
    QString message = userMessage.toLower().trimmed();

    auto containsAny = [&](const QStringList &keywords) {
        for (const QString &keyword : keywords) {
            if (message.contains(keyword)) {
                return true;
            }
        }
        return false;
    };

    const bool askedHelp = containsAny({"aide", "help", "?"});
    const bool askedDatabase = containsAny({"bdd", "bd", "base de données", "base de donnee", "database", "intégrer", "integrer", "connect"});
    const bool askedLab = containsAny({"labo", "laboratoire", "lab"});
    const bool askedMachine = containsAny({"machine", "machines"});
    const bool askedEmployee = containsAny({"employ", "employé", "employe", "personnel"});
    const bool askedStats = containsAny({"statistique", "statistiques", "stats", "stat"});
    const bool askedList = containsAny({"liste", "list", "tous", "toutes", "affiche", "montrer", "donne", "show"});
    const bool askedBest = containsAny({"efficace", "meilleur", "top", "best"});
    const bool askedOnlyThis = containsAny({"seulement ça", "seulement ca", "juste ça", "juste ca", "faire seulement", "faire juste"});
    const bool askedChatGPT = containsAny({"chatgpt", "gpt", "openai", "geminai", "gemini", "ai", "ia", "claude", "anthropic", "grok", "xai"});

    if (askedHelp) {
        return "🤖 ASSISTANT IA - AIDE 🤖\n\n"
               "Je peux vous aider avec :\n\n"
               "🏢 LABORATOIRES :\n"
               "• 'liste labo' - Voir tous les laboratoires\n"
               "• 'labo le plus efficace' - Meilleur laboratoire\n"
               "• 'stats labo' - Statistiques des laboratoires\n\n"
               "👥 EMPLOYÉS :\n"
               "• 'liste employés' - Voir tous les employés\n"
               "• 'stats employé' - Statistiques des employés\n\n"
               "🔧 MACHINES :\n"
               "• 'liste machine' - Voir toutes les machines\n"
               "• 'stats machine' - Statistiques des machines\n\n"
               "🤖 INTELLIGENCE ARTIFICIELLE :\n"
               "• 'geminai [question]' - Utiliser Google Gemini\n"
               "• 'ai [question]' - Utiliser l'IA configurée\n"
               "• 'chatgpt [question]' - Utiliser ChatGPT\n\n"
               "💾 BASE DE DONNÉES :\n"
               "• Je peux interroger la base en temps réel pour répondre à vos questions\n"
               "• Posez simplement des commandes en français";
    }

    if (askedOnlyThis) {
        return "Je peux faire bien plus que ça. Par exemple, demandez :\n"
               "• 'liste labo'\n"
               "• 'stats labo'\n"
               "• 'labo le plus efficace'\n"
               "• 'liste machine'\n"
               "• 'stats employé'";
    }

    if (askedChatGPT) {
        if (!getAPIKey().isEmpty()) {
            return QString(); // Request will be routed to configured AI
        }
        return QString("Aucune API IA n'est configurée. Veuillez définir une clé API (OPENAI_API_KEY, ANTHROPIC_API_KEY, GOOGLE_API_KEY, XAI_API_KEY, ou AI_API_KEY).");
    }

    if (askedDatabase && !askedStats && !askedList && !askedLab && !askedMachine && !askedEmployee) {
        return "Oui, je suis connecté à la base de données du système. Je peux répondre à des demandes comme 'liste labo', 'stats labo', 'liste machine', 'stats machine', 'liste employés' et 'stats employé'.";
    }

    if (askedLab) {
        if (askedList) {
            QList<LaboData> labs;
            QString error;
            if (LaboRepository::listLabos(&labs, &error)) {
                if (labs.isEmpty()) {
                    return "Aucun laboratoire n'est enregistré dans le système.";
                }
                QString response = QString("Voici la liste des %1 laboratoires enregistrés :\n\n").arg(labs.size());
                for (const LaboData &lab : labs) {
                    response += QString("• ID %1: %2 (%3)\n").arg(lab.idLabo).arg(lab.nomLabo).arg(lab.adresse);
                    response += QString("  Espace: %1m², Restant: %2m², Conformité: %3, Note: %4/10\n\n")
                                .arg(lab.espaceLabo).arg(lab.espaceReste).arg(lab.conformite).arg(lab.review);
                }
                return response;
            }
            return "Erreur lors de la récupération de la liste des laboratoires: " + error;
        }

        if (askedStats) {
            LaboStatsSummary summary;
            QString error;
            if (LaboRepository::getStatsSummary(&summary, &error)) {
                QList<LaboSpaceUsage> spaceStats;
                QList<LaboConformiteCount> conformiteStats;
                LaboReviewStats reviewStats;

                LaboRepository::getSpaceUsageStats(&spaceStats, &error);
                LaboRepository::getConformiteStats(&conformiteStats, &error);
                LaboRepository::getReviewStats(&reviewStats, &error);

                QString response = "📊 STATISTIQUES DES LABORATOIRES 📊\n\n";
                response += QString("🏢 Nombre total de laboratoires: %1\n").arg(summary.totalLabos);
                response += QString("✅ Laboratoires conformes: %1\n").arg(summary.totalConformes);
                response += QString("❌ Laboratoires non conformes: %1\n").arg(summary.totalLabos - summary.totalConformes);
                response += QString("📈 Taux de conformité: %.1f%%\n\n").arg(summary.totalLabos > 0 ? (double)summary.totalConformes / summary.totalLabos * 100.0 : 0.0);

                if (!spaceStats.isEmpty()) {
                    response += "🏗️ UTILISATION DE L'ESPACE :\n";
                    for (const LaboSpaceUsage &stat : spaceStats) {
                        response += QString("• %1: %.1f%% utilisé\n").arg(stat.nomLabo).arg(stat.percentageUsed);
                    }
                    response += "\n";
                }
                if (!conformiteStats.isEmpty()) {
                    response += "📋 RÉPARTITION PAR CONFORMITÉ :\n";
                    for (const LaboConformiteCount &stat : conformiteStats) {
                        response += QString("• %1: %2 laboratoires\n").arg(stat.conformite).arg(stat.count);
                    }
                    response += "\n";
                }
                response += QString("⭐ Note moyenne: %.1f/10 (%2 évaluations)").arg(reviewStats.averageReview).arg(reviewStats.totalReviews);
                return response;
            }
            return "Erreur lors de la récupération des statistiques: " + error;
        }

        if (askedBest) {
            QList<LaboData> labs;
            QString error;
            if (LaboRepository::listLabos(&labs, &error)) {
                if (labs.isEmpty()) {
                    return "Aucun laboratoire n'est enregistré dans le système.";
                }
                LaboData bestLab;
                double bestScore = -1;
                for (const LaboData &lab : labs) {
                    double utilization = lab.espaceLabo > 0 ? ((double)(lab.espaceLabo - lab.espaceReste) / lab.espaceLabo) * 100.0 : 0.0;
                    double score = (lab.review * 0.6) + (utilization * 0.4);
                    if (score > bestScore) {
                        bestScore = score;
                        bestLab = lab;
                    }
                }
                double utilization = bestLab.espaceLabo > 0 ? ((double)(bestLab.espaceLabo - bestLab.espaceReste) / bestLab.espaceLabo) * 100.0 : 0.0;
                return QString("Le laboratoire le plus efficace est :\n\n"
                               "🏆 %1 (ID: %2)\n"
                               "📍 Adresse: %3\n"
                               "📊 Note: %4/10\n"
                               "🏢 Utilisation espace: %.1f%%\n"
                               "✅ Conformité: %5\n"
                               "📈 Score d'efficacité: %.1f/100")
                               .arg(bestLab.nomLabo).arg(bestLab.idLabo).arg(bestLab.adresse)
                               .arg(bestLab.review).arg(utilization).arg(bestLab.conformite).arg(bestScore);
            }
            return "Erreur lors de l'analyse des laboratoires: " + error;
        }

        return "Je peux vous aider avec les laboratoires :\n"
               "• 'liste labo'\n"
               "• 'stats labo'\n"
               "• 'labo le plus efficace'\n"
               "• 'ajouter labo'";
    }

    if (askedMachine) {
        if (askedList) {
            QList<MachineData> machines;
            QString error;
            if (MachineWidget::listMachines(&machines, &error)) {
                if (machines.isEmpty()) {
                    return "Aucune machine n'est enregistrée dans le système.";
                }
                QString response = QString("Voici la liste des %1 machines :\n\n").arg(machines.size());
                for (const MachineData &mach : machines) {
                    response += QString("• ID %1: %2 (%3) - %4\n").arg(mach.idMachine).arg(mach.nom).arg(mach.categorie).arg(mach.etatAchat);
                }
                return response;
            }
            return "Erreur lors de la récupération de la liste des machines: " + error;
        }

        if (askedStats) {
            MachineStatsSummary summary;
            QString error;
            if (MachineWidget::getStatsSummary(&summary, &error)) {
                return QString("📊 STATISTIQUES MACHINES 📊\n\n"
                               "• Total machines : %1\n"
                               "• En service : %2\n"
                               "• En panne : %3\n"
                               "• Maintenance : %4\n"
                               "• Hors service : %5\n"
                               "• En stock : %6\n"
                               "• En attente : %7\n")
                               .arg(summary.totalMachines)
                               .arg(summary.enService)
                               .arg(summary.enPanne)
                               .arg(summary.maintenance)
                               .arg(summary.horsService)
                               .arg(summary.enStock)
                               .arg(summary.enAttente);
            }
            return "Erreur lors de la récupération des statistiques des machines: " + error;
        }

        return "Je peux vous aider avec les machines :\n"
               "• 'liste machine'\n"
               "• 'stats machine'\n"
               "• 'machine en panne' (sous forme de filtre depuis le module)";
    }

    if (askedEmployee) {
        if (askedList) {
            QList<EmployeData> employees;
            QString error;
            if (EmployeRepository::listEmployes(&employees, &error)) {
                if (employees.isEmpty()) {
                    return "Aucun employé n'est enregistré dans le système.";
                }
                QString response = QString("Voici la liste des %1 employés :\n\n").arg(employees.size());
                for (const EmployeData &emp : employees) {
                    response += QString("• ID %1: %2 %3 - %4\n").arg(emp.idEmploye).arg(emp.prenom).arg(emp.nom).arg(emp.poste);
                }
                return response;
            }
            return "Erreur lors de la récupération de la liste des employés: " + error;
        }

        if (askedStats) {
            EmployeStatsSummary summary;
            QString error;
            if (EmployeRepository::getStatsSummary(&summary, &error)) {
                return QString("📊 STATISTIQUES EMPLOYÉS 📊\n\n"
                               "• Total employés : %1\n"
                               "• Masse salariale : %2\n"
                               "• Salaire moyen : %3\n")
                               .arg(summary.totalEmployes)
                               .arg(summary.masseSalariale, 0, 'f', 2)
                               .arg(summary.totalEmployes > 0 ? (summary.masseSalariale / summary.totalEmployes) : 0.0, 0, 'f', 2);
            }
            return "Erreur lors de la récupération des statistiques des employés: " + error;
        }

        return "Je peux vous aider avec les employés :\n"
               "• 'liste employés'\n"
               "• 'stats employé'\n"
               "• 'meilleur employé' (à ajouter si nécessaire)";
    }

    if (askedStats) {
        return "Quelles statistiques souhaitez-vous consulter ?\n"
               "• 'stats labo'\n"
               "• 'stats employé'\n"
               "• 'stats machine'";
    }

    if (askedDatabase) {
        return "Oui, je suis connecté à la base de données du système. Posez-moi une question comme 'liste labo' ou 'stats machine' et je vous répondrai avec les données existantes.";
    }

    if (!getAPIKey().isEmpty()) {
        return QString();
    }

    return "Je n'ai pas bien compris votre demande. Essayez :\n"
           "• 'liste labo' pour voir les laboratoires\n"
           "• 'stats labo' pour les statistiques\n"
           "• 'labo le plus efficace' pour le meilleur labo\n"
           "• 'liste machine' pour les machines\n"
           "• 'stats employé' pour les employés\n"
           "• 'geminai [question]' pour utiliser Google Gemini\n"
           "• 'ai [question]' pour utiliser l'IA configurée\n"
           "• 'aide' pour plus d'informations\n\n"
           "Je peux aussi utiliser la base de données pour répondre en temps réel et une IA externe si configurée (OpenAI, Anthropic, Google, xAI).";
}
