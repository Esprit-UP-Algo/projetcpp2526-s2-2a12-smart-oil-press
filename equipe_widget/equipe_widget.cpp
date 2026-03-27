#include "equipe_widget.h"
#include "ui_equipe_widget.h"
#include "team_repository.h"

#include <QAbstractItemView>
#include <QDateEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QPdfWriter>
#include <QPageLayout>
#include <QPageSize>
#include <QTextDocument>
#include <QUrl>
#include <QBuffer>
#include <QDateTime>
#include <QStandardPaths>
#include <QDir>
#include <QApplication>
#include <QSignalBlocker>
#include <QHeaderView>
#include <QLayout>
#include <QPainter>
#include <QTextEdit>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QDebug>
#include <QMap>
#include <QHash>
#include <QStringList>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <algorithm>
#include <cmath>
namespace {
struct PlannedTaskSlot {
    QString code;
    QString description;
    QString startDate;
    QString endDate;
};

struct PlanningRateData {
    QVector<PlannedTaskSlot> taskSlots;
    int successCount;
    int lossCount;
    QString computedRate;
};

QString buildTableHtml(const QTableWidget *table, const QString &title)
{
    QString html;
    html += QString("<h3>%1</h3>").arg(title.toHtmlEscaped());
    html += "<table style='width:100%; border-collapse:collapse; font-size:11pt;'>";
    html += "<thead><tr>";

    for (int c = 0; c < table->columnCount(); ++c) {
        const QTableWidgetItem *headerItem = table->horizontalHeaderItem(c);
        const QString headerText = headerItem ? headerItem->text() : QString("Colonne %1").arg(c + 1);
        html += QString("<th style='border:1px solid #444; padding:6px; text-align:left; background:#f0f0f0;'>%1</th>")
            .arg(headerText.toHtmlEscaped());
    }
    html += "</tr></thead><tbody>";

    for (int r = 0; r < table->rowCount(); ++r) {
        html += "<tr>";
        for (int c = 0; c < table->columnCount(); ++c) {
            const QTableWidgetItem *item = table->item(r, c);
            const QString value = item ? item->text() : QString();
            html += QString("<td style='border:1px solid #777; padding:6px;'>%1</td>")
                .arg(value.toHtmlEscaped());
        }
        html += "</tr>";
    }

    if (table->rowCount() == 0) {
        html += QString("<tr><td colspan='%1' style='border:1px solid #777; padding:6px; color:#666;'>Aucune donnée</td></tr>")
            .arg(table->columnCount());
    }

    html += "</tbody></table>";
    return html;
}

PlanningRateData makeDefaultPlanningRateData()
{
    PlanningRateData data;
    data.successCount = 0;
    data.lossCount = 0;
    data.computedRate = "0";
    data.taskSlots = {
        {"T1", "EMPTY", "NULL", "NULL"},
        {"T2", "EMPTY", "NULL", "NULL"},
        {"T3", "EMPTY", "NULL", "NULL"}
    };
    return data;
}

PlanningRateData parsePlanningRateData(const QString &rateRaw)
{
    PlanningRateData data = makeDefaultPlanningRateData();
    const QString normalized = rateRaw.trimmed();
    if (normalized.isEmpty()) {
        return data;
    }

    const QStringList level1 = normalized.split("||");
    const QString tasksPart = level1.value(0);
    const QString statsPart = level1.size() > 1 ? level1.at(1) : QString();

    const QStringList taskSlots = tasksPart.split(';', Qt::KeepEmptyParts);
    for (int i = 0; i < 3; ++i) {
        if (i >= taskSlots.size()) {
            continue;
        }

        const QString slotRaw = taskSlots.at(i).trimmed();
        if (slotRaw.isEmpty()) {
            continue;
        }

        const QStringList details = slotRaw.split(',', Qt::KeepEmptyParts);
        if (details.size() >= 4) {
            data.taskSlots[i].code = details.at(0).trimmed().isEmpty() ? QString("T%1").arg(i + 1) : details.at(0).trimmed();
            data.taskSlots[i].description = details.at(1).trimmed().isEmpty() ? "EMPTY" : details.at(1).trimmed();
            data.taskSlots[i].startDate = details.at(2).trimmed().isEmpty() ? "NULL" : details.at(2).trimmed();
            data.taskSlots[i].endDate = details.at(3).trimmed().isEmpty() ? "NULL" : details.at(3).trimmed();
        }
    }

    const QStringList counters = statsPart.split('|', Qt::SkipEmptyParts);
    for (const QString &counter : counters) {
        const QString token = counter.trimmed();
        if (token.startsWith("S:")) {
            data.successCount = token.mid(2).toInt();
        } else if (token.startsWith("L:")) {
            data.lossCount = token.mid(2).toInt();
        } else if (token.startsWith("R:")) {
            const QString r = token.mid(2).trimmed();
            data.computedRate = r.isEmpty() ? "0" : r;
        }
    }

    return data;
}

QString serializePlanningRateData(const PlanningRateData &data)
{
    QStringList tasks;
    for (int i = 0; i < 3; ++i) {
        PlannedTaskSlot slot = (i < data.taskSlots.size())
            ? data.taskSlots.at(i)
            : PlannedTaskSlot{QString("T%1").arg(i + 1), "EMPTY", "NULL", "NULL"};

        if (slot.code.trimmed().isEmpty()) {
            slot.code = QString("T%1").arg(i + 1);
        }
        if (slot.description.trimmed().isEmpty()) {
            slot.description = "EMPTY";
        }
        if (slot.startDate.trimmed().isEmpty()) {
            slot.startDate = "NULL";
        }
        if (slot.endDate.trimmed().isEmpty()) {
            slot.endDate = "NULL";
        }

        tasks.append(QString("%1,%2,%3,%4")
            .arg(slot.code, slot.description, slot.startDate, slot.endDate));
    }

    return QString("%1||S:%2|L:%3|R:%4")
        .arg(tasks.join(';'))
        .arg(data.successCount)
        .arg(data.lossCount)
        .arg(data.computedRate);
}

bool isEmptyTaskSlot(const PlannedTaskSlot &slot)
{
    return slot.description.trimmed().compare("EMPTY", Qt::CaseInsensitive) == 0;
}

void clearTaskSlot(PlannedTaskSlot &slot, int index)
{
    slot.code = QString("T%1").arg(index + 1);
    slot.description = "EMPTY";
    slot.startDate = "NULL";
    slot.endDate = "NULL";
}

QDate parseIsoDate(const QString &isoDate)
{
    return QDate::fromString(isoDate.trimmed(), "yyyy-MM-dd");
}

QString calculateRate(int successCount, int lossCount)
{
    if (successCount == 0 && lossCount == 0) {
        return "0";
    }
    const double total = static_cast<double>(successCount + lossCount);
    const double rate = (static_cast<double>(successCount) / total) * 10.0;
    return QString::number(rate, 'f', 2);
}

QString extractRateValue(const QString &rateString)
{
    const QStringList parts = rateString.split("||");
    if (parts.size() < 2) {
        return "0";
    }
    const QString statsPart = parts.at(1);
    const QStringList tokens = statsPart.split('|', Qt::SkipEmptyParts);
    for (const QString &token : tokens) {
        if (token.startsWith("R:")) {
            return token.mid(2).trimmed();
        }
    }
    return "0";
}

bool applyOverdueFailures(PlanningRateData &planning, const QDate &today)
{
    bool changed = false;
    for (int i = 0; i < planning.taskSlots.size(); ++i) {
        PlannedTaskSlot &slot = planning.taskSlots[i];
        if (isEmptyTaskSlot(slot)) {
            continue;
        }

        const QDate deadline = parseIsoDate(slot.endDate);
        if (deadline.isValid() && today > deadline) {
            clearTaskSlot(slot, i);
            planning.lossCount += 1;
            changed = true;
        }
    }
    if (changed) {
        planning.computedRate = calculateRate(planning.successCount, planning.lossCount);
    }
    return changed;
}

QString toDbStatus(const QString &uiStatus)
{
    const QString s = uiStatus.trimmed().toLower();
    if (s == "disponible" || s == "active") {
        return "active";
    }
    if (s == "n'est pas disponible" || s == "inactive") {
        return "inactive";
    }
    return s;
}

QString toDbSpecialty(const QString &uiSpecialty)
{
    const QString s = uiSpecialty.trimmed().toLower();
    if (s == "maintenance") {
        return "maintenance";
    }
    if (s == "production") {
        return "production";
    }
    if (s == "back-office" || s == "backoffice") {
        return "backoffice";
    }
    if (s == "mécanique" || s == "mecanique") {
        return "mecanique";
    }
    return s;
}

bool isTeamActive(const QString &statusRaw)
{
    const QString status = statusRaw.trimmed().toLower();
    return status == "active" || status == "disponible";
}

int countOngoingTasks(const PlanningRateData &planning)
{
    int count = 0;
    for (const PlannedTaskSlot &slot : planning.taskSlots) {
        if (!isEmptyTaskSlot(slot)) {
            ++count;
        }
    }
    return count;
}

double availabilityScore(bool active, int ongoingTasks)
{
    if (!active) {
        return 0.0;
    }
    if (ongoingTasks <= 1) {
        return 10.0;
    }
    if (ongoingTasks == 2) {
        return 6.0;
    }
    return 2.0;
}

double reliabilityScore(int failures)
{
    if (failures <= 0) {
        return 10.0;
    }
    if (failures == 1) {
        return 7.0;
    }
    if (failures == 2) {
        return 4.0;
    }
    return 1.0;
}

QString downgradeClass(const QString &classification)
{
    if (classification == "Recommandé") {
        return "Acceptable";
    }
    if (classification == "Acceptable") {
        return "Risque élevé";
    }
    return "Risque élevé";
}

QString scoreClass(double score)
{
    if (score >= 7.5) {
        return "Recommandé";
    }
    if (score >= 5.5) {
        return "Acceptable";
    }
    return "Risque élevé";
}

}

EquipeWidget::EquipeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EquipeWidget)
{
    ui->setupUi(this);
    
    if (!initializeTeamRepositoryConnection()) {
        QMessageBox::critical(this, "Database Error",
                              "Failed to connect to database.\n" + teamRepoLastError());
    }
    
    // Ensure stacked page matches the currently selected top tab
    if (ui->stackedWidget->count() > 0) {
        on_topNavTabs_currentChanged(ui->topNavTabs->currentIndex());
    }

    // initialize table
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setHorizontalHeaderLabels({"ID", "Nom", "Spécialité", "Membres", "État", "Rate"});

    // Make table read-only (editing done through form)
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Default sort order
    ui->checkSortAscending->setChecked(true);

    // Configure planning table that replaces the old task list.
    ui->planningTableWidget->setColumnCount(4);
    ui->planningTableWidget->setHorizontalHeaderLabels({"Tâche", "Assignée à", "Début", "Deadline"});
    ui->planningTableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->planningTableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->planningTableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->planningTableWidget->verticalHeader()->setVisible(false);
    ui->planningTableWidget->horizontalHeader()->setStretchLastSection(false);
    ui->planningTableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->planningTableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->planningTableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->planningTableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Interactive);
    ui->planningTableWidget->setColumnWidth(3, 95);

    ui->specialtyStatsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->specialtyStatsTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->specialtyStatsTable->verticalHeader()->setVisible(false);
    ui->specialtyStatsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->performanceRankingTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->performanceRankingTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->performanceRankingTable->verticalHeader()->setVisible(false);
    ui->performanceRankingTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->suggestionResultsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->suggestionResultsTable->setSelectionMode(QAbstractItemView::NoSelection);
    ui->suggestionResultsTable->verticalHeader()->setVisible(false);
    ui->suggestionResultsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->suggestionResultsTable->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->suggestionResultsTable->horizontalHeader()->setSectionResizeMode(9, QHeaderView::Stretch);
        connect(ui->pushButton_validateTeamDetails, &QPushButton::clicked,
            this, &EquipeWidget::updateTeamDetailsSection);
        connect(ui->lineEdit_teamDetailsId, &QLineEdit::returnPressed,
            this, &EquipeWidget::updateTeamDetailsSection);
    
    // Load teams from database
    refreshTable();
    
    // Initialize selected team ID for planning
    selectedTeamIdForPlanning = -1;
    selectedTeamIsActiveForPlanning = false;
    showTasksForDate(ui->calendarWidget->selectedDate());
}

EquipeWidget::~EquipeWidget()
{
    closeTeamRepositoryConnection();
    delete ui;
}


void EquipeWidget::on_btnAddTeamSave_clicked()
{
    const QString name = ui->inputAddTeamName->text().trimmed();
    const QString specialty = ui->comboAddTeamSpecialty->currentText();
    const QString membersText = ui->comboAddTeamMembers->currentText();
    const QString statusText = ui->comboBox_add_etat->currentText();

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Le nom de l'équipe est requis.");
        return;
    }

    if (specialty.startsWith("Sélectionner")) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner une spécialité.");
        return;
    }

    if (membersText.startsWith("Sélectionner")) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner le nombre de membres.");
        return;
    }

    if (statusText.startsWith("Sélectionner")) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner l'état.");
        return;
    }

    if (teamNameExists(name)) {
        QMessageBox::warning(this, "Validation", "Ce nom d'équipe existe déjà. Veuillez choisir un autre nom.");
        return;
    }

    if (!teamRepoLastError().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Impossible de vérifier l'unicité du nom:\n" + teamRepoLastError());
        return;
    }

    // Create team object using setter methods
    Team team;
    team.setName(name);
    team.setSpecialty(toDbSpecialty(specialty));
    team.setMembers(membersText.toInt());
    team.setStatus(toDbStatus(statusText));
    team.setRate("");
    
    // Generate ID (you may want to use auto-increment in Oracle instead)
    int maxId = 0;
    for (const Team &t : teams) {
        if (t.getId() > maxId) maxId = t.getId();
    }
    team.setId(maxId + 1);

    // Insert into database
    if (insertTeamRecord(team)) {
        QMessageBox::information(this, "Succès", "Équipe enregistrée avec succès!");
        refreshTable();
        clearAddInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'insertion:\n" + teamRepoLastError());
    }
}


void EquipeWidget::on_btnDeleteTeam_clicked()
{
    // Keep local cache synchronized before searching by ID.
    refreshTable();

    int id = -1;
    if (!parseTeamId(ui->inputDeleteTeamId->text().trimmed(), id)) {
        return;
    }

    const int index = findTeamIndexById(id);
    if (index == -1) {
        QMessageBox::information(this, "Supprimer", "Aucune équipe trouvée avec cet ID.");
        return;
    }

    // Confirm deletion
    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", 
        "Êtes-vous sûr de vouloir supprimer cette équipe?");
    
    if (reply != QMessageBox::Yes) {
        return;
    }

    // Delete from database
    if (deleteTeamRecord(id)) {
        QMessageBox::information(this, "Succès", "Équipe supprimée avec succès!");
        refreshTable();
        ui->inputDeleteTeamId->clear();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression:\n" + teamRepoLastError());
    }
}


void EquipeWidget::on_btnUpdateTeam_clicked()
{
    // Keep local cache synchronized before searching by ID.
    refreshTable();

    int id = -1;
    if (!parseTeamId(ui->lineEdit_mod_id->text().trimmed(), id,
                     "Veuillez saisir l'ID de l'équipe à modifier.")) {
        return;
    }

    const int index = findTeamIndexById(id);
    if (index == -1) {
        QMessageBox::information(this, "Modifier", "Aucune équipe trouvée avec cet ID.");
        return;
    }

    Team &team = teams[index];
    const QString newName = ui->inputUpdateTeamName->text().trimmed();
    const QString newSpecialty = ui->comboUpdateTeamSpecialty->currentText();
    const QString newMembersText = ui->comboUpdateTeamMembers->currentText();
    const QString newEtat = ui->comboBox_mod_etat->currentText();

    if (!newName.isEmpty() && teamNameExists(newName, id)) {
        QMessageBox::warning(this, "Validation", "Ce nom d'équipe est déjà utilisé par une autre équipe.");
        return;
    }

    if (!newName.isEmpty() && !teamRepoLastError().isEmpty()) {
        QMessageBox::critical(this, "Erreur", "Impossible de vérifier l'unicité du nom:\n" + teamRepoLastError());
        return;
    }

    // Update only if new values are provided using setters
    if (!newName.isEmpty()) team.setName(newName);
    if (!newSpecialty.startsWith("Sélectionner")) team.setSpecialty(toDbSpecialty(newSpecialty));
    if (newMembersText != "Sélectionner le nombre") team.setMembers(newMembersText.toInt());
    if (!newEtat.startsWith("Sélectionner")) team.setStatus(toDbStatus(newEtat));

    // Update in database
    if (updateTeamRecord(team)) {
        QMessageBox::information(this, "Succès", "Équipe modifiée avec succès!");
        refreshTable();
        clearModifyInputs();
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la modification:\n" + teamRepoLastError());
    }
}


void EquipeWidget::refreshTable() {
    // Load teams from database
    teams = getAllTeamsRecord();

    if (!teamRepoLastError().isEmpty()) {
        QMessageBox::warning(this, "Erreur base de donnees",
                             "Impossible de charger la liste des equipes:\n" + teamRepoLastError());
    }
    
    // Clear table
    ui->tableWidget->setRowCount(0);
    
    // Set uniform row height
    const int uniformRowHeight = 28;
    
    // Populate table using getters
    for (int row = 0; row < teams.size(); ++row) {
        const Team &team = teams[row];
        
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setRowHeight(row, uniformRowHeight);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(team.getId())));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(team.getName()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(team.getSpecialty()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(team.getMembers())));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(team.getStatus()));
        ui->tableWidget->setItem(row, 5, new QTableWidgetItem(extractRateValue(team.getRate())));
    }

    updateOverallTeamsStats();

    if (ui->lineEdit_teamDetailsId->text().trimmed().isEmpty()) {
        ui->selectedTeamDetailsLabel->setText("Équipe sélectionnée: Aucune");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
    }
    
}

void EquipeWidget::updateTeamDetailsSection()
{
    const QString idText = ui->lineEdit_teamDetailsId->text().trimmed();
    if (idText.isEmpty()) {
        ui->selectedTeamDetailsLabel->setText("Équipe sélectionnée: Aucune");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
        return;
    }

    bool ok = false;
    const int selectedId = idText.toInt(&ok);
    if (!ok) {
        ui->selectedTeamDetailsLabel->setText("Équipe sélectionnée: ID invalide");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
        return;
    }

    const int index = findTeamIndexById(selectedId);
    if (index < 0) {
        ui->selectedTeamDetailsLabel->setText("Équipe sélectionnée: Introuvable");
        ui->completedTasksValueLabel->setText("0");
        ui->failedTasksValueLabel->setText("0");
        ui->teamRateValueLabel->setText("0.00");
        ui->teamFeedbackLabel->setText("Feedback: -");
        return;
    }

    const Team &team = teams[index];
    const PlanningRateData planning = parsePlanningRateData(team.getRate());
    const double rate = extractRateValue(team.getRate()).toDouble();

    ui->selectedTeamDetailsLabel->setText(
        QString("Équipe sélectionnée: %1, ID: %2").arg(team.getName()).arg(team.getId()));
    ui->completedTasksValueLabel->setText(QString::number(planning.successCount));
    ui->failedTasksValueLabel->setText(QString::number(planning.lossCount));
    ui->teamRateValueLabel->setText(QString::number(rate, 'f', 2));

    QString feedback;
    if (rate < 2.5) {
        feedback = "Les résultats manquent de précision pour le moment. L'équipe a besoin de plus de rigueur et de méthodes pour atteindre nos standards de qualité";
    } else if (rate < 6.0) {
        feedback = "L'équipe remplit les objectifs de base, mais il y a encore une marge de progression pour atteindre un niveau de qualité supérieur.";
    } else if (rate <= 8.0) {
        feedback = "Les résultats sont très satisfaisants et réguliers. L'équipe gagne en maturité, même si elle a encore besoin d'une validation finale sur les points les plus complexes.";
    } else {
        feedback = "L'équipe fait preuve d'une maîtrise totale du projet. Ils sont autonomes et anticipent parfaitement les besoins techniques";
    }

    ui->teamFeedbackLabel->setText("Feedback: " + feedback);
}

void EquipeWidget::updateOverallTeamsStats()
{
    ui->label_totalTeams->setText(QString("Total équipes: %1").arg(teams.size()));

    struct SpecialtyAggregate {
        int teamCount = 0;
        int membersSum = 0;
        double rateSum = 0.0;
        int activeCount = 0;
    };

    QMap<QString, int> specialtyCounts;
    QMap<QString, SpecialtyAggregate> specialtyAgg;
    for (const Team &team : teams) {
        QString specialty = team.getSpecialty().trimmed().toLower();
        if (specialty.isEmpty()) {
            specialty = "non définie";
        }
        specialtyCounts[specialty] += 1;

        SpecialtyAggregate &agg = specialtyAgg[specialty];
        agg.teamCount += 1;
        agg.membersSum += team.getMembers();
        agg.rateSum += extractRateValue(team.getRate()).toDouble();

        const QString status = team.getStatus().trimmed().toLower();
        if (status == "active" || status == "disponible") {
            agg.activeCount += 1;
        }
    }

    ui->label_specialtyCount->setText(
        QString("Spécialités représentées: %1").arg(specialtyCounts.size()));

    auto *hostLayout = qobject_cast<QVBoxLayout*>(ui->overallSpecialtyChartHost->layout());
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
    const int totalTeams = teams.size();
    for (auto it = specialtyCounts.cbegin(); it != specialtyCounts.cend(); ++it) {
        QString specialtyLabel = it.key();
        const int count = it.value();
        if (!specialtyLabel.isEmpty()) {
            specialtyLabel[0] = specialtyLabel.at(0).toUpper();
        }
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
        ? "Pourcentage des équipes par spécialité"
        : "Aucune équipe disponible");

    auto *chartView = new QChartView(chart, ui->overallSpecialtyChartHost);
    chartView->setRenderHint(QPainter::Antialiasing);
    hostLayout->addWidget(chartView);

    ui->specialtyStatsTable->setRowCount(0);
    int row = 0;
    for (auto it = specialtyAgg.cbegin(); it != specialtyAgg.cend(); ++it) {
        QString specialtyLabel = it.key();
        if (!specialtyLabel.isEmpty()) {
            specialtyLabel[0] = specialtyLabel.at(0).toUpper();
        }

        const SpecialtyAggregate &agg = it.value();
        const double avgMembers = agg.teamCount > 0
            ? static_cast<double>(agg.membersSum) / static_cast<double>(agg.teamCount)
            : 0.0;
        const double avgRate = agg.teamCount > 0
            ? agg.rateSum / static_cast<double>(agg.teamCount)
            : 0.0;
        const double activeGlobalPct = totalTeams > 0
            ? (static_cast<double>(agg.activeCount) / static_cast<double>(totalTeams)) * 100.0
            : 0.0;

        ui->specialtyStatsTable->insertRow(row);
        ui->specialtyStatsTable->setItem(row, 0, new QTableWidgetItem(specialtyLabel));
        ui->specialtyStatsTable->setItem(row, 1, new QTableWidgetItem(QString::number(static_cast<int>(std::round(avgMembers)))));
        ui->specialtyStatsTable->setItem(row, 2, new QTableWidgetItem(QString::number(avgRate, 'f', 2)));
        ui->specialtyStatsTable->setItem(row, 3, new QTableWidgetItem(
            QString("%1/%2").arg(agg.activeCount).arg(agg.teamCount)));
        ui->specialtyStatsTable->setItem(row, 4, new QTableWidgetItem(
            QString::number(activeGlobalPct, 'f', 1) + "%"));
        ++row;
    }

    updateTopPerformersAndAlerts();
}

void EquipeWidget::updateTopPerformersAndAlerts()
{
    struct TeamScore {
        Team team;
        double rate = 0.0;
        int failed = 0;
    };

    QVector<TeamScore> scores;
    scores.reserve(teams.size());
    for (const Team &team : teams) {
        TeamScore score;
        score.team = team;
        score.rate = extractRateValue(team.getRate()).toDouble();
        score.failed = parsePlanningRateData(team.getRate()).lossCount;
        scores.append(score);
    }

    ui->performanceRankingTable->setRowCount(0);
    if (scores.isEmpty()) {
        return;
    }

    QVector<TeamScore> byBest = scores;
    std::sort(byBest.begin(), byBest.end(), [](const TeamScore &a, const TeamScore &b) {
        if (a.rate == b.rate) {
            return a.team.getId() < b.team.getId();
        }
        return a.rate > b.rate;
    });

    const int topCount = std::min(3, static_cast<int>(byBest.size()));
    int row = 0;
    for (int i = 0; i < topCount; ++i) {
        ui->performanceRankingTable->insertRow(row);
        ui->performanceRankingTable->setItem(row, 0, new QTableWidgetItem(QString("Top %1").arg(i + 1)));
        ui->performanceRankingTable->setItem(row, 1, new QTableWidgetItem(QString::number(byBest[i].team.getId())));
        ui->performanceRankingTable->setItem(row, 2, new QTableWidgetItem(byBest[i].team.getName()));
        ui->performanceRankingTable->setItem(row, 3, new QTableWidgetItem(QString::number(byBest[i].rate, 'f', 2)));
        ++row;
    }

    QVector<TeamScore> byWorst = scores;
    std::sort(byWorst.begin(), byWorst.end(), [](const TeamScore &a, const TeamScore &b) {
        if (a.rate == b.rate) {
            return a.team.getId() < b.team.getId();
        }
        return a.rate < b.rate;
    });

    const int bottomCount = std::min(3, static_cast<int>(byWorst.size()));
    for (int i = 0; i < bottomCount; ++i) {
        ui->performanceRankingTable->insertRow(row);
        ui->performanceRankingTable->setItem(row, 0, new QTableWidgetItem(QString("Bottom %1").arg(i + 1)));
        ui->performanceRankingTable->setItem(row, 1, new QTableWidgetItem(QString::number(byWorst[i].team.getId())));
        ui->performanceRankingTable->setItem(row, 2, new QTableWidgetItem(byWorst[i].team.getName()));
        ui->performanceRankingTable->setItem(row, 3, new QTableWidgetItem(QString::number(byWorst[i].rate, 'f', 2)));
        ++row;
    }

}


int EquipeWidget::findTeamIndexById(int id) const {
    for (int i = 0; i < teams.size(); ++i) {
        if (teams[i].getId() == id) {
            return i;
        }
    }
    return -1;
}


bool EquipeWidget::parseTeamId(const QString &idText, int &idOut,
                                const QString &emptyMessage) {
    if (idText.isEmpty()) {
        QMessageBox::warning(this, "Validation", emptyMessage);
        return false;
    }
    
    bool ok;
    idOut = idText.toInt(&ok);
    if (!ok) {
        QMessageBox::warning(this, "Validation", "L'ID doit être un nombre valide.");
        return false;
    }
    
    return true;
}


void EquipeWidget::clearAddInputs() {
    ui->inputAddTeamName->clear();  // name
    ui->comboAddTeamSpecialty->setCurrentIndex(0);  // specialty
    ui->comboAddTeamMembers->setCurrentIndex(0);  // members
    ui->comboBox_add_etat->setCurrentIndex(0);  // status
}


void EquipeWidget::clearModifyInputs() {
    ui->lineEdit_mod_id->clear();  // id
    ui->inputUpdateTeamName->clear();       // name
    ui->comboUpdateTeamSpecialty->setCurrentIndex(0);   // specialty
    ui->comboUpdateTeamMembers->setCurrentIndex(0);  // members
    ui->comboBox_mod_etat->setCurrentIndex(0);  // status
}


void EquipeWidget::on_topNavTabs_currentChanged(int index) {
    if (ui->stackedWidget) {
        // Tab order differs from stacked page order in the .ui file.
        int pageIndex = index;
        switch (index) {
        case 2: // "Supprimer une équipe" tab
            pageIndex = 3; // pagesupp
            break;
        case 3: // "Modifier une équipe" tab
            pageIndex = 2; // pagemodif
            break;
        default:
            break;
        }

        ui->stackedWidget->setCurrentIndex(pageIndex);

        // Refresh displayed data when opening the list tab.
        if (index == 1) {
            refreshTable();
        }
    }
}


void EquipeWidget::on_btnRechercher_clicked() {
    // Get search text and selected category
    const QString searchText = ui->lineEdit->text().trimmed();
    const QString selectedCategory = ui->comboBoxFilter->currentText();
    
    // If search text is empty, refresh the full table
    if (searchText.isEmpty()) {
        refreshTable();
        return;
    }
    
    // Clear the table
    ui->tableWidget->setRowCount(0);
    
    // Set uniform row height
    const int uniformRowHeight = 28;
    
    // Search and filter teams based on selected category
    int rowCount = 0;
    for (const Team &team : teams) {
        bool matches = false;
        
        if (selectedCategory == "ID") {
            // Search by ID
            matches = QString::number(team.getId()).contains(searchText, Qt::CaseInsensitive);
        }
        else if (selectedCategory == "Nom") {
            // Search by Name
            matches = team.getName().contains(searchText, Qt::CaseInsensitive);
        }
        else if (selectedCategory == "Spécialité") {
            // Search by Specialty
            matches = team.getSpecialty().contains(searchText, Qt::CaseInsensitive);
        }
        else if (selectedCategory == "Membres") {
            // Search by Members count
            matches = QString::number(team.getMembers()).contains(searchText, Qt::CaseInsensitive);
        }
        else if (selectedCategory == "État") {
            // Search by Status
            matches = team.getStatus().contains(searchText, Qt::CaseInsensitive);
        }
        
        // If the search matches, add the row to the table
        if (matches) {
            ui->tableWidget->insertRow(rowCount);
            ui->tableWidget->setRowHeight(rowCount, uniformRowHeight);
            ui->tableWidget->setItem(rowCount, 0, new QTableWidgetItem(QString::number(team.getId())));
            ui->tableWidget->setItem(rowCount, 1, new QTableWidgetItem(team.getName()));
            ui->tableWidget->setItem(rowCount, 2, new QTableWidgetItem(team.getSpecialty()));
            ui->tableWidget->setItem(rowCount, 3, new QTableWidgetItem(QString::number(team.getMembers())));
            ui->tableWidget->setItem(rowCount, 4, new QTableWidgetItem(team.getStatus()));
            ui->tableWidget->setItem(rowCount, 5, new QTableWidgetItem(extractRateValue(team.getRate())));
            rowCount++;
        }
    }
    
    // Show a message if no results found
    if (rowCount == 0) {
        QMessageBox::information(this, "Recherche", 
            QString("Aucune équipe trouvée pour '%1' dans la catégorie '%2'.")
            .arg(searchText, selectedCategory));
    }
}


void EquipeWidget::on_btnTrier_clicked()
{
    const QString selectedCategory = ui->comboSortField->currentText();
    const bool ascending = ui->checkSortAscending->isChecked() || !ui->checkSortDescending->isChecked();

    int column = 1; // Nom by default
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
    rows.reserve(ui->tableWidget->rowCount());

    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        TableRow tableRow;
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem *item = ui->tableWidget->item(row, col);
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

    const int uniformRowHeight = 28;
    ui->tableWidget->setRowCount(0);
    for (int row = 0; row < rows.size(); ++row) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setRowHeight(row, uniformRowHeight);
        for (int col = 0; col < rows[row].values.size(); ++col) {
            ui->tableWidget->setItem(row, col, new QTableWidgetItem(rows[row].values[col]));
        }
    }
}


void EquipeWidget::on_checkSortAscending_toggled(bool checked)
{
    if (checked) {
        ui->checkSortDescending->setChecked(false);
    } else if (!ui->checkSortDescending->isChecked()) {
        ui->checkSortAscending->setChecked(true);
    }
}


void EquipeWidget::on_checkSortDescending_toggled(bool checked)
{
    if (checked) {
        ui->checkSortAscending->setChecked(false);
    } else if (!ui->checkSortAscending->isChecked()) {
        ui->checkSortDescending->setChecked(true);
    }
}

void EquipeWidget::on_pushButton_validateTeam_clicked()
{
    refreshTable();
    const QString teamIdText = ui->lineEdit_teamId->text().trimmed();
    
    if (teamIdText.isEmpty()) {
        ui->label_teamStatus->clear();
        ui->label_teamStatus->setStyleSheet("color: gray; font-style: italic;");
        selectedTeamIdForPlanning = -1;
        selectedTeamIsActiveForPlanning = false;
        showTasksForDate(ui->calendarWidget->selectedDate());
        return;
    }
    
    bool ok = false;
    int teamId = teamIdText.toInt(&ok);
    
    if (!ok || teamId <= 0) {
        ui->label_teamStatus->setText("ID invalide. Veuillez entrer un nombre positif.");
        ui->label_teamStatus->setStyleSheet("color: red;");
        selectedTeamIdForPlanning = -1;
        selectedTeamIsActiveForPlanning = false;
        showTasksForDate(ui->calendarWidget->selectedDate());
        return;
    }
    
    // Search for team in the list
    int teamIndex = findTeamIndexById(teamId);
    
    if (teamIndex >= 0 && teamIndex < teams.size()) {
        selectedTeamIdForPlanning = teamId;
        Team team = teams[teamIndex];
        PlanningRateData planning = parsePlanningRateData(team.getRate());

        if (applyOverdueFailures(planning, QDate::currentDate())) {
            team.setRate(serializePlanningRateData(planning));
            if (!updateTeamRecord(team)) {
                QMessageBox::critical(this, "Erreur",
                                      "Impossible de mettre à jour les tâches expirées:\n" + teamRepoLastError());
                return;
            }
            refreshTable();
            teamIndex = findTeamIndexById(teamId);
            if (teamIndex < 0 || teamIndex >= teams.size()) {
                ui->label_teamStatus->setText("Équipe non trouvée. Vérifier le ID du l équipe");
                ui->label_teamStatus->setStyleSheet("color: red;");
                selectedTeamIdForPlanning = -1;
                selectedTeamIsActiveForPlanning = false;
                showTasksForDate(ui->calendarWidget->selectedDate());
                return;
            }
            team = teams[teamIndex];
            planning = parsePlanningRateData(team.getRate());
        }

        const QString teamName = team.getName();
        const QString teamStatus = team.getStatus().trimmed().toLower();
        selectedTeamIsActiveForPlanning =
            (teamStatus == "active" || teamStatus == "disponible");

        if (selectedTeamIsActiveForPlanning) {
            ui->label_teamStatus->setText("Équipe sélectionnée: " + teamName);
            ui->label_teamStatus->setStyleSheet("color: green; font-weight: bold;");
        } else {
            ui->label_teamStatus->setText(
                QString("Équipe %1: désolé, cette équipe est inactive pour le moment.")
                    .arg(teamName));
            ui->label_teamStatus->setStyleSheet("color: #b00020; font-weight: bold;");
        }
        showTasksForDate(ui->calendarWidget->selectedDate());
    } else {
        ui->label_teamStatus->setText("Équipe non trouvée. Vérifier le ID du l équipe");
        ui->label_teamStatus->setStyleSheet("color: red;");
        selectedTeamIdForPlanning = -1;
        selectedTeamIsActiveForPlanning = false;
        showTasksForDate(ui->calendarWidget->selectedDate());
    }
}

void EquipeWidget::on_calendarWidget_clicked(const QDate &date)
{
    selectedTeamIdForPlanning = -1;
    selectedTeamIsActiveForPlanning = false;
    ui->label_teamStatus->clear();
    ui->label_teamStatus->setStyleSheet("color: gray; font-style: italic;");
    showTasksForDate(date);
}

void EquipeWidget::showTasksForDate(const QDate &date)
{
    if (!date.isValid()) {
        ui->taskLabel->setText("Liste des tâches");
        ui->planningTableWidget->setRowCount(0);
        return;
    }

    refreshTable();
    ui->planningTableWidget->setRowCount(0);

    const QString formattedDate = date.toString("yyyy-MM-dd");
    const QString displayDate = date.toString("dd/MM/yy");

    QVector<Team> teamsToDisplay;
    QString selectedTeamName;
    if (selectedTeamIdForPlanning > 0) {
        const int selectedIndex = findTeamIndexById(selectedTeamIdForPlanning);
        if (selectedIndex >= 0 && selectedIndex < teams.size()) {
            teamsToDisplay.append(teams[selectedIndex]);
            selectedTeamName = teams[selectedIndex].getName();
        }
    }
    if (teamsToDisplay.isEmpty()) {
        teamsToDisplay = teams;
    }

    if (!selectedTeamName.isEmpty()) {
        ui->taskLabel->setText(QString("Liste des tâches de l'équipe %1").arg(selectedTeamName));
    } else {
        ui->taskLabel->setText(QString("Liste de toutes les tâches pour le jour %1").arg(displayDate));
    }

    for (const Team &team : teamsToDisplay) {
        const PlanningRateData planning = parsePlanningRateData(team.getRate());
        for (const PlannedTaskSlot &slot : planning.taskSlots) {
            if (isEmptyTaskSlot(slot)) {
                continue;
            }

            const QDate startDate = parseIsoDate(slot.startDate);
            const QDate endDate = parseIsoDate(slot.endDate);
            if (!startDate.isValid() || !endDate.isValid()) {
                continue;
            }

            if (date >= startDate && date <= endDate) {
                const int row = ui->planningTableWidget->rowCount();
                ui->planningTableWidget->insertRow(row);

                auto *taskItem = new QTableWidgetItem();
                taskItem->setSizeHint(QSize(taskItem->sizeHint().width(), 28));
                taskItem->setData(Qt::UserRole, slot.code);
                taskItem->setData(Qt::UserRole + 1, team.getId());
                ui->planningTableWidget->setItem(row, 0, taskItem);

                auto *taskCell = new QWidget(ui->planningTableWidget);
                auto *taskLayout = new QHBoxLayout(taskCell);
                taskLayout->setContentsMargins(4, 2, 4, 2);
                taskLayout->setSpacing(6);

                auto *checkbox = new QCheckBox(taskCell);
                auto *taskLabel = new QLabel(slot.description, taskCell);
                taskLabel->setWordWrap(true);

                taskLayout->addWidget(checkbox);
                taskLayout->addWidget(taskLabel, 1);

                const QString slotCode = slot.code;
                const int teamId = team.getId();
                QObject::connect(checkbox, &QCheckBox::toggled, this,
                                 [this, slotCode, teamId](bool checked) {
                    if (!checked) {
                        return;
                    }
                    completeTaskSlotForTeam(teamId, slotCode);
                });

                ui->planningTableWidget->setCellWidget(row, 0, taskCell);
                ui->planningTableWidget->setItem(row, 1, new QTableWidgetItem(team.getName()));
                ui->planningTableWidget->setItem(row, 2, new QTableWidgetItem(slot.startDate));
                ui->planningTableWidget->setItem(row, 3, new QTableWidgetItem(slot.endDate));
            }
        }
    }

    if (ui->planningTableWidget->rowCount() == 0) {
        ui->planningTableWidget->insertRow(0);
        ui->planningTableWidget->setItem(0, 0, new QTableWidgetItem(QString("Aucune tâche planifiée pour le %1").arg(formattedDate)));
        ui->planningTableWidget->setItem(0, 1, new QTableWidgetItem("-"));
        ui->planningTableWidget->setItem(0, 2, new QTableWidgetItem("-"));
        ui->planningTableWidget->setItem(0, 3, new QTableWidgetItem("-"));
    }
}

void EquipeWidget::on_pushButton_deleteTask_clicked()
{
    if (selectedTeamIdForPlanning <= 0) {
        QMessageBox::warning(this, "Validation", "Veuillez choisir une équipe avant de supprimer une tâche.");
        return;
    }

    const int row = ui->planningTableWidget->currentRow();
    if (row < 0) {
        QMessageBox::information(this, "Suppression", "Veuillez sélectionner une tâche à supprimer.");
        return;
    }

    QTableWidgetItem *taskItem = ui->planningTableWidget->item(row, 0);
    if (!taskItem) {
        QMessageBox::information(this, "Suppression", "Veuillez sélectionner une tâche valide.");
        return;
    }

    const QString slotCode = taskItem->data(Qt::UserRole).toString();
    const int teamIdFromRow = taskItem->data(Qt::UserRole + 1).toInt();

    if (slotCode.isEmpty() || teamIdFromRow <= 0) {
        QMessageBox::information(this, "Suppression", "Aucune tâche supprimable dans la ligne sélectionnée.");
        return;
    }

    if (teamIdFromRow != selectedTeamIdForPlanning) {
        QMessageBox::warning(this, "Suppression",
                             "La tâche sélectionnée ne correspond pas à l'équipe active.");
        return;
    }

    deleteTaskSlotForTeam(teamIdFromRow, slotCode);
}

void EquipeWidget::on_pushButton_addTask_clicked()
{
    if (selectedTeamIdForPlanning <= 0) {
        ui->label_teamStatus->setText("Veuillez choisir une équipe avant d'ajouter une tâche.");
        ui->label_teamStatus->setStyleSheet("color: red;");
        return;
    }

    if (!selectedTeamIsActiveForPlanning) {
        ui->label_teamStatus->setText(
            "Désolé, cette équipe est inactive pour le moment. Ajout de tâche impossible.");
        ui->label_teamStatus->setStyleSheet("color: #b00020; font-weight: bold;");
        return;
    }

    QDialog dialog(this);
    dialog.setWindowTitle("Ajout d une tache");
    dialog.setModal(true);
    dialog.setMinimumWidth(420);

    auto *layout = new QVBoxLayout(&dialog);
    auto *title = new QLabel("Ajout d une tache", &dialog);
    title->setStyleSheet("font-weight: bold; font-size: 14px;");
    layout->addWidget(title);

    auto *formLayout = new QFormLayout();

    auto *startDateEdit = new QDateEdit(QDate::currentDate(), &dialog);
    startDateEdit->setCalendarPopup(true);
    startDateEdit->setDisplayFormat("dd/MM/yyyy");
    formLayout->addRow("Date de début:", startDateEdit);

    auto *deadlineEdit = new QDateEdit(QDate::currentDate().addDays(7), &dialog);
    deadlineEdit->setCalendarPopup(true);
    deadlineEdit->setDisplayFormat("dd/MM/yyyy");
    formLayout->addRow("Date limite:", deadlineEdit);

    auto *descriptionEdit = new QTextEdit(&dialog);
    descriptionEdit->setPlaceholderText("Description de la tache...");
    descriptionEdit->setMinimumHeight(100);
    formLayout->addRow("Description:", descriptionEdit);

    layout->addLayout(formLayout);

    auto *buttons = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel, &dialog);
    buttons->button(QDialogButtonBox::Ok)->setText("Confirmer");
    buttons->button(QDialogButtonBox::Cancel)->setText("Annuler");
    layout->addWidget(buttons);

    QObject::connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    if (dialog.exec() != QDialog::Accepted) {
        return;
    }

    const QString description = descriptionEdit->toPlainText().trimmed();
    const QDate startDate = startDateEdit->date();
    const QDate deadline = deadlineEdit->date();

    if (description.isEmpty()) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir une description de tâche.");
        return;
    }

    if (description.contains(',') || description.contains(';') || description.contains('|')) {
        QMessageBox::warning(this, "Validation",
                             "La description ne doit pas contenir les caractères: , ; |");
        return;
    }

    if (startDate > deadline) {
        QMessageBox::warning(this, "Validation", "La date de début doit être avant la date limite.");
        return;
    }

    int teamIndex = findTeamIndexById(selectedTeamIdForPlanning);
    if (teamIndex < 0 || teamIndex >= teams.size()) {
        refreshTable();
        teamIndex = findTeamIndexById(selectedTeamIdForPlanning);
    }

    if (teamIndex < 0 || teamIndex >= teams.size()) {
        QMessageBox::warning(this, "Erreur", "Impossible de trouver l'équipe sélectionnée.");
        return;
    }

    Team team = teams[teamIndex];
    PlanningRateData planning = parsePlanningRateData(team.getRate());

    int emptySlotIndex = -1;
    for (int i = 0; i < planning.taskSlots.size(); ++i) {
        if (isEmptyTaskSlot(planning.taskSlots[i])) {
            emptySlotIndex = i;
            break;
        }
    }

    if (emptySlotIndex == -1) {
        QMessageBox::information(this, "Limite atteinte",
                                 "Vous avez atteint le maximum de tâches en cours pour cette équipe.");
        return;
    }

    planning.taskSlots[emptySlotIndex].code = QString("T%1").arg(emptySlotIndex + 1);
    planning.taskSlots[emptySlotIndex].description = description;
    planning.taskSlots[emptySlotIndex].startDate = startDate.toString("yyyy-MM-dd");
    planning.taskSlots[emptySlotIndex].endDate = deadline.toString("yyyy-MM-dd");

    team.setRate(serializePlanningRateData(planning));

    if (!updateTeamRecord(team)) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible d'enregistrer la tâche:\n" + teamRepoLastError());
        return;
    }

    refreshTable();
    on_pushButton_validateTeam_clicked();
}

void EquipeWidget::on_btnRunSuggestionSearch_clicked()
{
    refreshTable();
    ui->suggestionResultsTable->setRowCount(0);

    const QString requestedSpecialtyRaw = ui->comboSuggestionSpecialty->currentText().trimmed();
    const QString requestedSpecialty = toDbSpecialty(requestedSpecialtyRaw);
    if (requestedSpecialtyRaw.isEmpty() || requestedSpecialtyRaw.toLower().startsWith("selectionner")) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner une spécialité demandée.");
        return;
    }

    bool membersOk = false;
    const int minMembers = ui->inputSuggestionMinMembers->text().trimmed().toInt(&membersOk);
    if (!membersOk || minMembers < 0) {
        QMessageBox::warning(this, "Validation", "Veuillez saisir un nombre minimum valide.");
        return;
    }

    const QString difficultyRaw = ui->comboSuggestionDifficulty->currentText().trimmed().toLower();
    if (difficultyRaw.isEmpty() || difficultyRaw.startsWith("selectionner")) {
        QMessageBox::warning(this, "Validation", "Veuillez sélectionner la difficulté du cas.");
        return;
    }

    const bool urgentCase = ui->checkSuggestionUrgent->isChecked();
    const bool requiresAvailability = ui->checkSuggestionRequiresAvailability->isChecked();

    struct SuggestionResult {
        int teamId = 0;
        QString teamName;
        QString classification;
        double score = 0.0;
        double rate = 0.0;
        double availability = 0.0;
        double reliability = 0.0;
        int ongoingTasks = 0;
        int maxTasks = 3;
        QStringList reasons;
        bool eligible = false;
    };

    QVector<SuggestionResult> eligibleResults;
    QVector<SuggestionResult> nonEligibleResults;

    for (const Team &team : teams) {
        SuggestionResult result;
        result.teamId = team.getId();
        result.teamName = team.getName();

        const QString teamSpecialty = team.getSpecialty().trimmed().toLower();
        const bool active = isTeamActive(team.getStatus());

        const PlanningRateData planning = parsePlanningRateData(team.getRate());
        result.ongoingTasks = countOngoingTasks(planning);
        result.maxTasks = planning.taskSlots.isEmpty() ? 3 : static_cast<int>(planning.taskSlots.size());
        if (result.maxTasks <= 0) {
            result.maxTasks = 3;
        }

        if (teamSpecialty != requestedSpecialty) {
            result.reasons.append("spécialité non correspondante");
        }
        if (team.getMembers() < minMembers) {
            result.reasons.append("membres insuffisants");
        }
        if (requiresAvailability) {
            if (!active) {
                result.reasons.append("équipe inactive");
            } else if (result.ongoingTasks >= result.maxTasks) {
                result.reasons.append("aucune capacité disponible");
            }
        }

        if (!result.reasons.isEmpty()) {
            result.classification = "Non éligible";
            nonEligibleResults.append(result);
            continue;
        }

        result.rate = extractRateValue(team.getRate()).toDouble();
        result.availability = availabilityScore(active, result.ongoingTasks);
        result.reliability = reliabilityScore(planning.lossCount);

        result.score = (0.5 * result.rate) + (0.3 * result.availability) + (0.2 * result.reliability);
        result.classification = scoreClass(result.score);

        if (difficultyRaw == "normal" && result.rate < 5.0) {
            result.classification = downgradeClass(result.classification);
        } else if (difficultyRaw == "difficile" && result.rate < 7.0) {
            result.classification = downgradeClass(result.classification);
        }

        if (urgentCase && result.ongoingTasks >= 2) {
            result.classification = downgradeClass(result.classification);
        }

        result.eligible = true;
        eligibleResults.append(result);
    }

    std::sort(eligibleResults.begin(), eligibleResults.end(), [](const SuggestionResult &a, const SuggestionResult &b) {
        if (a.score == b.score) {
            return a.rate > b.rate;
        }
        return a.score > b.score;
    });

    std::sort(nonEligibleResults.begin(), nonEligibleResults.end(), [](const SuggestionResult &a, const SuggestionResult &b) {
        return a.teamId < b.teamId;
    });

    auto addResultRow = [this](const QString &statusLabel, const SuggestionResult &r) {
        const int row = ui->suggestionResultsTable->rowCount();
        ui->suggestionResultsTable->insertRow(row);

        ui->suggestionResultsTable->setItem(row, 0, new QTableWidgetItem(statusLabel));
        ui->suggestionResultsTable->setItem(row, 1, new QTableWidgetItem(r.classification));
        ui->suggestionResultsTable->setItem(row, 2, new QTableWidgetItem(QString::number(r.teamId)));
        ui->suggestionResultsTable->setItem(row, 3, new QTableWidgetItem(r.teamName));
        ui->suggestionResultsTable->setItem(row, 4, new QTableWidgetItem(QString::number(r.score, 'f', 1)));
        ui->suggestionResultsTable->setItem(row, 5, new QTableWidgetItem(QString::number(r.rate, 'f', 1)));
        ui->suggestionResultsTable->setItem(row, 6, new QTableWidgetItem(QString::number(r.availability, 'f', 0)));
        ui->suggestionResultsTable->setItem(row, 7, new QTableWidgetItem(QString::number(r.reliability, 'f', 0)));
        ui->suggestionResultsTable->setItem(row, 8, new QTableWidgetItem(QString("%1/%2").arg(r.ongoingTasks).arg(r.maxTasks)));
        ui->suggestionResultsTable->setItem(row, 9, new QTableWidgetItem(r.reasons.isEmpty() ? "-" : r.reasons.join("; ")));
    };

    if (eligibleResults.isEmpty() && nonEligibleResults.isEmpty()) {
        SuggestionResult emptyResult;
        emptyResult.classification = "-";
        emptyResult.teamName = "Aucune équipe disponible";
        addResultRow("Info", emptyResult);
        return;
    }

    for (const SuggestionResult &r : eligibleResults) {
        addResultRow("Éligible", r);
    }

    for (const SuggestionResult &r : nonEligibleResults) {
        addResultRow("Non éligible", r);
    }
}

void EquipeWidget::completeTaskSlot(const QString &slotCode)
{
    completeTaskSlotForTeam(selectedTeamIdForPlanning, slotCode);
}

void EquipeWidget::completeTaskSlotForTeam(int teamId, const QString &slotCode)
{
    if (slotCode.trimmed().isEmpty()) {
        return;
    }

    if (teamId <= 0) {
        return;
    }

    int teamIndex = findTeamIndexById(teamId);
    if (teamIndex < 0 || teamIndex >= teams.size()) {
        refreshTable();
        teamIndex = findTeamIndexById(teamId);
    }

    if (teamIndex < 0 || teamIndex >= teams.size()) {
        QMessageBox::warning(this, "Erreur", "Impossible de trouver l'équipe sélectionnée.");
        return;
    }

    Team team = teams[teamIndex];
    PlanningRateData planning = parsePlanningRateData(team.getRate());

    bool found = false;
    for (int i = 0; i < planning.taskSlots.size(); ++i) {
        PlannedTaskSlot &slot = planning.taskSlots[i];
        if (slot.code == slotCode && !isEmptyTaskSlot(slot)) {
            clearTaskSlot(slot, i);
            planning.successCount += 1;
            planning.computedRate = calculateRate(planning.successCount, planning.lossCount);
            found = true;
            break;
        }
    }

    if (!found) {
        return;
    }

    team.setRate(serializePlanningRateData(planning));
    if (!updateTeamRecord(team)) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de valider la tâche:\n" + teamRepoLastError());
        return;
    }

    refreshTable();
    showTasksForDate(ui->calendarWidget->selectedDate());

    if (selectedTeamIdForPlanning == teamId) {
        ui->label_teamStatus->setText("Équipe sélectionnée: " + team.getName());
        ui->label_teamStatus->setStyleSheet("color: green; font-weight: bold;");
    }
}

void EquipeWidget::deleteTaskSlotForTeam(int teamId, const QString &slotCode)
{
    if (slotCode.trimmed().isEmpty()) {
        return;
    }

    if (teamId <= 0) {
        return;
    }

    int teamIndex = findTeamIndexById(teamId);
    if (teamIndex < 0 || teamIndex >= teams.size()) {
        refreshTable();
        teamIndex = findTeamIndexById(teamId);
    }

    if (teamIndex < 0 || teamIndex >= teams.size()) {
        QMessageBox::warning(this, "Erreur", "Impossible de trouver l'équipe sélectionnée.");
        return;
    }

    Team team = teams[teamIndex];
    PlanningRateData planning = parsePlanningRateData(team.getRate());

    bool found = false;
    for (int i = 0; i < planning.taskSlots.size(); ++i) {
        PlannedTaskSlot &slot = planning.taskSlots[i];
        if (slot.code == slotCode && !isEmptyTaskSlot(slot)) {
            clearTaskSlot(slot, i);
            found = true;
            break;
        }
    }

    if (!found) {
        return;
    }

    team.setRate(serializePlanningRateData(planning));
    if (!updateTeamRecord(team)) {
        QMessageBox::critical(this, "Erreur",
                              "Impossible de supprimer la tâche:\n" + teamRepoLastError());
        return;
    }

    refreshTable();
    showTasksForDate(ui->calendarWidget->selectedDate());
}

void EquipeWidget::on_pushButton_exportGlobalStatsPdf_clicked()
{
    refreshTable();
    updateOverallTeamsStats();

    const QString defaultDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    const QString defaultFile = QDir(defaultDir).filePath(
        QString("stats_globales_equipes_%1.pdf").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")));

    const QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter statistiques globales",
        defaultFile,
        "PDF Files (*.pdf)");

    if (filePath.trimmed().isEmpty()) {
        return;
    }

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Portrait);
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));

    QTextDocument document;
    document.setDocumentMargin(20.0);

    // Use a document image resource instead of base64 HTML image for better Qt PDF compatibility.
    QChartView *chartView = ui->overallSpecialtyChartHost->findChild<QChartView*>();
    QPixmap chartPixmap;
    if (chartView) {
        chartView->repaint();
        QApplication::processEvents();
        chartPixmap = chartView->grab();
    } else {
        ui->overallSpecialtyChartHost->repaint();
        QApplication::processEvents();
        chartPixmap = ui->overallSpecialtyChartHost->grab();
    }

    const QUrl chartResourceUrl("chart://overall_specialty");
    if (!chartPixmap.isNull()) {
        document.addResource(QTextDocument::ImageResource, chartResourceUrl, chartPixmap.toImage());
    }

    QString html;
    html += "<h1>Statistiques globales des équipes</h1>";
    html += QString("<p><b>Date d'export:</b> %1</p>")
        .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm"));
    html += "<hr/>";
    html += "<h2>Section 1 - Vue globale</h2>";
    html += QString("<p>%1<br/>%2</p>")
        .arg(ui->label_totalTeams->text().toHtmlEscaped(), ui->label_specialtyCount->text().toHtmlEscaped());

    html += "<h2>Section 3 - Détails par spécialité</h2>";
    if (!chartPixmap.isNull()) {
        html += QString(
            "<div style='margin:8px 0 12px 0;'>"
            "<img src='%1' width='680' style='border:1px solid #ddd; padding:4px;'/>"
            "</div>")
            .arg(chartResourceUrl.toString());
    } else {
        html += "<p style='color:#777; font-style:italic;'>Graphique indisponible.</p>";
    }
    html += buildTableHtml(ui->specialtyStatsTable, "Tableau des spécialités");

    html += "<h2>Section 4 - Top performers</h2>";
    html += buildTableHtml(ui->performanceRankingTable, "Classement performances");

    document.setHtml(html);
    document.print(&writer);

    QMessageBox::information(this, "Export PDF", "Le PDF des statistiques globales a été généré avec succès.");
}

void EquipeWidget::on_pushButton_exportTeamDetailsPdf_clicked()
{
    refreshTable();
    updateTeamDetailsSection();

    bool ok = false;
    const int teamId = ui->lineEdit_teamDetailsId->text().trimmed().toInt(&ok);
    if (!ok || teamId <= 0) {
        QMessageBox::warning(this, "Export PDF", "Veuillez saisir un ID équipe valide pour exporter les détails.");
        return;
    }

    const int index = findTeamIndexById(teamId);
    if (index < 0) {
        QMessageBox::warning(this, "Export PDF", "Aucune équipe trouvée avec cet ID.");
        return;
    }

    const Team &team = teams[index];

    const QString defaultDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    const QString defaultFile = QDir(defaultDir).filePath(
        QString("details_equipe_%1_%2.pdf")
            .arg(teamId)
            .arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")));

    const QString filePath = QFileDialog::getSaveFileName(
        this,
        "Exporter détails équipe",
        defaultFile,
        "PDF Files (*.pdf)");

    if (filePath.trimmed().isEmpty()) {
        return;
    }

    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize(QPageSize::A4));
    writer.setPageOrientation(QPageLayout::Portrait);
    writer.setPageMargins(QMarginsF(12, 12, 12, 12));

    QTextDocument document;
    document.setDocumentMargin(20.0);

    QString html;
    html += "<h1>Détails équipe - Section 3</h1>";
    html += QString("<p><b>Date d'export:</b> %1</p>")
        .arg(QDateTime::currentDateTime().toString("dd/MM/yyyy HH:mm"));
    html += "<hr/>";
    html += QString("<p><b>Nom:</b> %1<br/><b>ID:</b> %2</p>")
        .arg(team.getName().toHtmlEscaped())
        .arg(team.getId());

    html += "<table style='width:100%; border-collapse:collapse; font-size:11pt;'>";
    html += "<tr><th style='border:1px solid #444; padding:6px; text-align:left; background:#f0f0f0;'>Indicateur</th>"
            "<th style='border:1px solid #444; padding:6px; text-align:left; background:#f0f0f0;'>Valeur</th></tr>";
    html += QString("<tr><td style='border:1px solid #777; padding:6px;'>Tâches complétées</td><td style='border:1px solid #777; padding:6px;'>%1</td></tr>")
        .arg(ui->completedTasksValueLabel->text().toHtmlEscaped());
    html += QString("<tr><td style='border:1px solid #777; padding:6px;'>Tâches échouées</td><td style='border:1px solid #777; padding:6px;'>%1</td></tr>")
        .arg(ui->failedTasksValueLabel->text().toHtmlEscaped());
    html += QString("<tr><td style='border:1px solid #777; padding:6px;'>Rate (/10)</td><td style='border:1px solid #777; padding:6px;'>%1</td></tr>")
        .arg(ui->teamRateValueLabel->text().toHtmlEscaped());
    html += "</table>";

    html += QString("<h3>Feedback</h3><p>%1</p>")
        .arg(ui->teamFeedbackLabel->text().toHtmlEscaped());

    document.setHtml(html);
    document.print(&writer);

    QMessageBox::information(this, "Export PDF", "Le PDF des détails d'équipe a été généré avec succès.");
}
