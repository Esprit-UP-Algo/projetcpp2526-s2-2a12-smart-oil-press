// Refactored to a widget-only module for the Equipe feature
#ifndef EQUIPE_WIDGET_H
#define EQUIPE_WIDGET_H

#include <QWidget>
#include <QVector>
#include <QDate>
#include <QString>
#include "team_repository.h"

QT_BEGIN_NAMESPACE
namespace Ui { class EquipeWidget; }
QT_END_NAMESPACE

class EquipeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EquipeWidget(QWidget *parent = nullptr);
    ~EquipeWidget();

private slots:
    void on_topNavTabs_currentChanged(int index);
    void on_btnAddTeamSave_clicked(); // Enregistrer (Add)
    void on_btnDeleteTeam_clicked(); // Supprimer (Delete)
    void on_btnUpdateTeam_clicked(); // Modifier (Modify)
    void on_btnRechercher_clicked(); // Search by category
    void on_btnTrier_clicked();
    void on_checkSortAscending_toggled(bool checked);
    void on_checkSortDescending_toggled(bool checked);
    void on_pushButton_validateTeam_clicked(); // Validate team ID in Planification
    void on_pushButton_addTask_clicked();      // Open add task popup
    void on_pushButton_deleteTask_clicked();   // Delete selected planned task
    void on_btnRunSuggestionSearch_clicked();           // Suggestion search
    void on_pushButton_exportGlobalStatsPdf_clicked(); // Export global stats sections to PDF
    void on_pushButton_exportTeamDetailsPdf_clicked(); // Export selected team details section to PDF
    void on_calendarWidget_clicked(const QDate &date); // Show scheduled tasks for selected day

    void refreshTable();

private:
    void completeTaskSlot(const QString &slotCode);
    void completeTaskSlotForTeam(int teamId, const QString &slotCode);
    void deleteTaskSlotForTeam(int teamId, const QString &slotCode);
    void showTasksForDate(const QDate &date);
    void updateOverallTeamsStats();
    void updateTeamDetailsSection();
    void updateTopPerformersAndAlerts();
    int findTeamIndexById(int id) const;
    bool parseTeamId(const QString &idText, int &idOut,
                     const QString &emptyMessage = "Veuillez saisir un ID.");
    void clearAddInputs();
    void clearModifyInputs();

    Ui::EquipeWidget *ui;
    QVector<Team> teams;          // Local cache
    int selectedTeamIdForPlanning; // Currently selected team ID for Planification
    bool selectedTeamIsActiveForPlanning; // Active/inactive state of selected planning team
};

#endif // EQUIPE_WIDGET_H
