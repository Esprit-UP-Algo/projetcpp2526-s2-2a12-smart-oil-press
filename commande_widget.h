#ifndef COMMANDE_WIDGET_H
#define COMMANDE_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class CommandeWidget;
}
QT_END_NAMESPACE

class CommandeWidget : public QWidget
{
    Q_OBJECT

public:
    CommandeWidget(QWidget *parent = nullptr);
    ~CommandeWidget();

private slots:
    // CRUD actions for orders
    void onActionNew();
    void onActionEdit();
    void onActionDelete();
    void onActionSendEmail();
    void onActionExportPDF();
    void onActionRefresh();
    void onActionStatistics();
    void onActionCalendar();

    // Quick action buttons
    void onBtnNewCommandeClicked();
    void onBtnEditCommandeClicked();
    void onBtnDeleteCommandeClicked();
    void onBtnEnvoyerEmailClicked();

    // Search and filters
    void onSearchTextChanged(const QString &text);
    void onFilterChanged();

private:
    Ui::CommandeWidget *ui;

    // Helper methods
    void setupConnections();
    void setupTableData();
    void updateQuickInfo();
    void updateStatistics();
    void showCrudDialog(const QString &title);
    void showAdvancedFeatureDialog(const QString &title, const QString &description);
    void applyFilters();
};
#endif // COMMANDE_WIDGET_H
