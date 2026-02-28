#ifndef COMMANDE_WIDGET_H
#define COMMANDE_WIDGET_H

#include <QWidget>
#include <QDate>
#include <QVector>
#include "Ccommande.h"

namespace Ui { class CommandeWidget; }

class CommandeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommandeWidget(QWidget *parent = nullptr);
    ~CommandeWidget();

private slots:
    // CRUD
    void onAjouterCommande();
    void onSupprimerCommande();
    void onModifierCommande();

    // Search/Filter
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

    // Reset form
    void onResetAjouter();

private:
    Ui::CommandeWidget *ui;

    // Membres pour la recherche et le tri
    QVector<Ccommande> m_lastSearchResults;
    bool m_searchActive = false;

    // Membres pour l'export (commandes actuellement affichées)
    QVector<Ccommande> m_currentDisplayedOrders;

    // Méthodes privées
    void setupConnections();
    void loadClients();
    void showMessage(const QString &title, const QString &message);

    // Tri et affichage
    QVector<Ccommande> sortCommands(const QVector<Ccommande>& list, int sortIndex);
    void applySortingAndDisplay(const QVector<Ccommande>& source);

    // Construction HTML pour les PDF
    QString buildHtmlListeComplete(const QVector<Ccommande>& orders);
    QString buildHtmlRapport(const QVector<Ccommande>& orders);
    QString buildHtmlFicheCommande(const Ccommande& cmd);

    // Calendrier avancé
    void updateCalendarColors(int month, int year);
    QColor getColorForEtat(const QString &etat) const;
    int getPriorityForEtat(const QString &etat) const;
   
};

#endif // COMMANDE_WIDGET_H