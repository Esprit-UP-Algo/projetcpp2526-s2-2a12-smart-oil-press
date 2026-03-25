#ifndef COMMANDE_WIDGET_H
#define COMMANDE_WIDGET_H

#include <QWidget>
#include <QDate>

namespace Ui { class CommandeWidget; }

class CommandeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommandeWidget(QWidget *parent = nullptr);
    ~CommandeWidget();

private:
    Ui::CommandeWidget *ui;

    void setupConnections();

    // CRUD
    void onAjouterCommande();
    void onSupprimerCommande();
    void onModifierCommande();

    // Search/Filter
    void onSearchByDate();
    void onSearchByFournisseur();
    void onApplySearch();
    void onResetSearch();
    void refreshTableCommandes();

    // Sort
    void onApplySorting();

    // Statistics
    void updateStatistics();
    void loadPriceByMonth();
    void loadMostOrderedProducts();

    // Calendar
    void onDisplayCalendar();
    void refreshCalendarAlerts();

    // Email & Export
    void onSendEmailNotification();
    void exportPDF();
    void onEnableEmailNotification(bool enabled);

    // Utilities
    void showMessage(const QString &title, const QString &message);
};

#endif // COMMANDE_WIDGET_H
