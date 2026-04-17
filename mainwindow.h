#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QDate>
#include <QMap>
#include <QPair>
#include <QVector>
#include <QColor>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QCompleter>
#include "equipe.h"
#include "labo.h"
#include "commande.h"
#include "client.h"
#include "tunisia_map_widget.h"

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
    void setupLaboCharts();
    void refreshLaboStatistiques();
    void refreshEmployeEquipeCombo();
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
    

    // === MODULE EQUIPE ===
    void setupEquipeConnections();
    void refreshEquipeTable();
    void updateEquipeOverallStats();
    void updateEquipeDetailsStats();
    void updateEquipeTopPerformers();
    void clearEquipeAddInputs();
    void clearEquipeModifyInputs();
    bool parseEquipeId(const QString &idText, int &idOut, const QString &emptyMessage = "Veuillez saisir un ID.");
    int findEquipeIndexById(int idEquipe) const;
    void ajouterEquipe();
    void modifierEquipe();
    void supprimerEquipe();
    void rechercherEquipe();
    void trierEquipe();
    void onEquipeTriCroissantToggled(bool checked);
    void onEquipeTriDecroissantToggled(bool checked);

    // === MODULE CLIENT ===
    void setupClientConnections();
    void setupTableClients();
    void setupClientStatistiquesCharts();
    void setupClientHistoriqueWidget();
    void loadClientData();
    void refreshTableFromDB();
    void refreshClientStatistiques();
    void refreshClientAlertes();
    void updateClientInfo();
    void updateClientHistorique(int idClient, const ClientInfosDetail &infos,
                                const QString &nom, const QString &type,
                                const QString &statut);
    void clearClientInfo();
    void clearFormAjouter();
    void onTabClientChanged(int index);
    void onConfirmerAjouterClicked();
    void onConfirmerModifierClicked();
    void onConfirmerSupprimerClicked();
    void onAppliquerFiltreClicked();
    void onTableClientSelectionChanged();
    void onExportListeClientsClicked();
    void onExportStatistiquesClicked();
    void onExportFicheClientClicked();
    Client m_clientTmp;

    // Chart views -- module CLIENT
    QChartView *m_clientChartStatut     = nullptr;
    QChartView *m_clientChartType       = nullptr;
    QChartView *m_clientChartCA         = nullptr;
    QChartView *m_clientChartHistorique = nullptr;

    // === MODULE LABO ===
    // Declarations reservees au module Laboratoire.
    void setupLaboConnections();
    void ajouterLabo();
    void afficherLabos();
    void supprimerLabo();
    void modifierLabo();
    void chargerLaboPourModification();
    void exporterFicheLaboPdf();

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
    QVector<Ccommande> sortCommands(const QVector<Ccommande> &list, int sortIndex);
    void applySortingAndDisplay(const QVector<Ccommande> &source);

    // Methodes pour l'export PDF
    QString buildHtmlListeComplete(const QVector<Ccommande> &orders);
    QString buildHtmlRapport(const QVector<Ccommande> &orders);
    QString buildHtmlFicheCommande(const Ccommande &cmd);

    // Methodes pour le calendrier
    void updateCalendarColors(int month, int year);
    QColor getColorForEtat(const QString &etat) const;
    int getPriorityForEtat(const QString &etat) const;

    // === MODULE MACHINE ===
    void setupMachineConnections();
    void afficherMachines();
    void applyMachineFiltersAndSorting();
    void updateMachineToolControlsVisibility();
    void ajouterMachine();
    void modifierMachine();
    void supprimerMachine();
    void chargerMachinePourModification();
    void onMachineSelectionChanged();
    void onSignalPanneMachine();
    void exportMachineListePdf();
    void exportMachineStatsPdf();
    void refreshMachineStats();
    void refreshMachineHistory();
    void setupMachineCharts();
    void clearMachineAddForm();
    void clearMachineModifierForm();
    void clearMachineSuppressionForm();
    void scanMachineQRCode();
    // Declarations reservees au module Machine.

    // === MODULE CHATBOT ===
    void setupChatbotConnections();
    void sendChatMessage();
    void importChatConversation();
    void exportChatConversation();
    void updateChatDisplay();
    QString generateAIResponse(const QString &userMessage);
    void askAI(const QString &userMessage, const QString &providerOverride = QString());
    void onAIReplyFinished(QNetworkReply *reply);
    QString detectAIProviderFromMessage(const QString &message) const;
    QString getAIProvider() const;
    QString getAPIKey(const QString &provider = QString()) const;

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

    // === ETAT MODULE LABO ===
    QChartView *laboStatsTopChartView = nullptr;
    QChartView *laboStatsLeftChartView = nullptr;
    QChartView *laboStatsRightChartView = nullptr;
    QCompleter *m_laboAddressCompleter = nullptr;
    QCompleter *m_laboAddressCompleterModif = nullptr;
    TunisiaMapWidget *m_tunisiaMapWidget = nullptr;

    // === ETAT MODULE MACHINE ===
    QChartView *machineStatsTopChartView = nullptr;
    QChartView *machineStatsLeftChartView = nullptr;
    QChartView *machineStatsRightChartView = nullptr;

    // === ETAT MODULE EQUIPE ===
    QList<EquipeData> m_equipes;

    // === ETAT MODULE COMMANDE ===
    QVector<Ccommande> m_lastSearchResults;
    bool m_searchActive = false;
    QVector<Ccommande> m_currentDisplayedOrders;

    // Pointeurs vers les QChartView du module commande
    QChartView *m_chartViewMontant = nullptr;
    QChartView *m_chartViewNbCmds = nullptr;
    QChartView *m_chartViewEtat = nullptr;
    QChartView *m_chartViewProduits = nullptr;

    // === ETAT MODULE CHATBOT ===
    QStringList m_chatMessages;

    // Gestionnaire reseau pour les emails
    QNetworkAccessManager *m_networkManager = nullptr;
};

#endif // MAINWINDOW_H
