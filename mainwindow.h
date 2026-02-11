#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Navigation menu
    void onBtnEmployeeClicked();
    void onBtnTeamClicked();
    void onBtnClientClicked();
    void onBtnLaboratoryClicked();
    void onBtnOrderClicked();
    void onBtnMachineClicked();

    // CRUD actions for orders
    void onActionNew();
    void onActionEdit();
    void onActionDelete();
    void onActionSendEmail();
    void onActionExportPDF();
    void onActionRefresh();
    void onActionExit();

    // Quick action buttons
    void onBtnNewCommandeClicked();
    void onBtnEditCommandeClicked();
    void onBtnDeleteCommandeClicked();
    void onBtnEnvoyerEmailClicked();

    // Navigation from machine to order
    void onBtnCommandeFromProduitClicked();

    // Advanced features
    void onGroupBoxStatsByTypeClicked();
    void onGroupBoxStatsDepensesClicked();
    void onGroupBoxCalendrierClicked();

    // Search and filters
    void onSearchTextChanged(const QString &text);
    void onFilterChanged();

private:
    Ui::MainWindow *ui;

    // Helper methods
    void setupConnections();
    void setupTableData();
    void updateQuickInfo();
    void updateStatistics();
    void showCrudDialog(const QString &title);
    void showAdvancedFeatureDialog(const QString &title, const QString &description);
    void applyFilters();
};
#endif // MAINWINDOW_H
