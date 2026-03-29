#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QDate>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "labo.h"
#include "commande_widget.h"


class QChartView;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    // === SLOTS GENERAUX (navigation, menu, retour) ===
    void applyAccessByRole(const QString &role);
    QWidget *firstAllowedModulePage() const;

    // === AUTH + MOT DE PASSE OUBLIE ===
    void validateForgotIdentity();
    void forgotSendCodeRequested(const QString &email);
    void setForgotIdentityValidated(bool validated);
    void updateForgotResetActionState();
    void resetForgotFlowState(bool clearIdentityInput = true);
    void resetPasswordFromForgotFlow();

    // === MODULE EMPLOYE ===
    void styleSpinboxesAndComboboxes();
    void setupCrudConnections();
    void setupStatistiquesCharts();
    void refreshStatistiques();
    void clearAjouterForm();
    void clearModifierForm();
    bool validateAjouterForm();
    bool validateModifierForm();
    void ajouterEmploye();
    void afficherEmployes();
    void supprimerEmploye();
    void modifierEmploye();
    void chargerEmployePourModification();
    void onTableRowClicked(int row, int column);
    void appliquerFiltreEtTri();
    void reinitialiserFiltre();
    void exporterListeCompletePdf();
    void exporterFicheEmployePdf();
    void exporterFicheLaboPdf();

    // === MODULE EQUIPE ===
    // Declarations reservees au module Equipe.

    // === MODULE CLIENT ===
    // Declarations reservees au module Client.

    // === MODULE LABO ===
    void ajouterLabo();
    void afficherLabos();
    void supprimerLabo();
    void modifierLabo();
    void chargerLaboPourModification();

    // === MODULE COMMANDE ===
    void setupCommandeConnections();
    void loadClients();
    void onAjouterCommande();
    void onResetAjouter();
    void onSupprimerCommande();
    void onModifierCommande();
    void onApplySearch();
    void onResetSearch();
    void onApplySorting();
    void refreshTableCommandes();
    void updateStatistics();
    void refreshAllCharts();
    void onDisplayCalendar();
    void refreshCalendarAlerts();
    void onSendEmailNotification();
    void onEnableEmailNotification(bool enabled);
    void exportPDF();
    void sendEmailViaBrevo(const QString &to, const QString &subject, const QString &htmlBody);
    void onBrevoReplyFinished(QNetworkReply *reply);
    

    // Methodes pour les graphiques
    void buildChartMontantParMois();
    void buildChartNbCommandesParMois();
    void buildChartRepartitionEtat();
    void buildChartTop10Produits();

    // Methodes pour le tri et l'affichage
    QVector<Ccommande> sortCommands(const QVector<Ccommande>& list, int sortIndex);
    void applySortingAndDisplay(const QVector<Ccommande>& source);

    // Methodes pour l'export PDF
    QString buildHtmlListeComplete(const QVector<Ccommande>& orders);
    QString buildHtmlRapport(const QVector<Ccommande>& orders);
    QString buildHtmlFicheCommande(const Ccommande& cmd);

    // Methodes pour le calendrier
    void updateCalendarColors(int month, int year);
    QColor getColorForEtat(const QString &etat) const;
    int getPriorityForEtat(const QString &etat) const;

    // === MODULE MACHINE ===
    // Declarations reservees au module Machine.

    Ui::MainWindow *ui;

    // === ETAT GLOBAL ===
    QString m_currentRole;

    // === ETAT AUTH + MOT DE PASSE OUBLIE ===
    QString m_resetEmail;
    QString m_resetIdentity;
    QString m_resetEmployeeId;
    bool m_forgotIdentityValidated = false;
    bool m_resetEmailSendingInProgress = false;

    // === ETAT MODULE EMPLOYE ===
    QChartView *statsTopChartView = nullptr;
    QChartView *statsLeftChartView = nullptr;
    QChartView *statsRightChartView = nullptr;

    // === ETAT MODULE COMMANDE ===
    QVector<Ccommande> m_lastSearchResults;
    bool m_searchActive = false;
    QVector<Ccommande> m_currentDisplayedOrders;

    // Pointeurs vers les QChartView du module commande
    QChartView *m_chartViewMontant = nullptr;
    QChartView *m_chartViewNbCmds = nullptr;
    QChartView *m_chartViewEtat = nullptr;
    QChartView *m_chartViewProduits = nullptr;

    // Gestionnaire réseau pour les emails
    QNetworkAccessManager *m_networkManager = nullptr;
};

#endif // MAINWINDOW_H
