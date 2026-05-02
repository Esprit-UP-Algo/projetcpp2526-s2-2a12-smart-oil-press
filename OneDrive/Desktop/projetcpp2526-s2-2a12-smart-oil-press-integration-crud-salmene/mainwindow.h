#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QByteArray>
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
#include "Arduino.h"
#include "arduino_environment.h"
#include "tunisia_map_widget.h"

class QChartView;
class QDialog;
class QLabel;
class QLineEdit;
class QPushButton;
class QSerialPort;
class QWidget;
class QTimer;

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

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void update_label();

    // === SLOTS GENERAUX (navigation, menu, retour) ===
    void applyAccessByRole(const QString &role);
    QWidget *firstAllowedModulePage() const;
    void setEmployeAuthenticated(bool authenticated);
    void completeEmployeAuthentication(const QString &identity, const QString &role);

    // === AUTH + MOT DE PASSE OUBLIE ===
    void validateForgotIdentity();
    void forgotSendCodeRequested(const QString &email);
    void setForgotIdentityValidated(bool validated);
    void updateForgotResetActionState();
    void resetForgotFlowState(bool clearIdentityInput = true);
    void resetPasswordFromForgotFlow();
    void openFingerprintAuthDialog();
    void setupFingerprintEnrollTab();
    bool ensureFingerprintSerialConnected(QString *errorMessage = nullptr);
    bool sendFingerprintCommand(const QString &command, QString *errorMessage = nullptr);
    void handleFingerprintSerialReadyRead();
    void failFingerprintOperation(const QString &message);
    QString buildArduinoDisplayMessage(const QString &prefix, const QString &identity) const;
    void sendArduinoDisplayCommand(const QString &commandPrefix, const QString &message);
    void finishFingerprintAuthentication(int fingerprintId);
    void finishFingerprintEnrollment(int fingerprintId);
    void clearFingerprintOperationState();
    void updateFingerprintEnrollIdentity();
    void startFingerprintEnrollment();

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
    void completeTaskSlotForTeam(int teamId, const QString &slotCode);
    void deleteTaskSlotForTeam(int teamId, const QString &slotCode);
    void showTasksForDate(const QDate &date);
    void on_btnRunSuggestionSearch_clicked();
    void on_pushButton_exportGlobalStatsPdf_clicked();
    void on_pushButton_exportTeamDetailsPdf_clicked();
    void on_pushButton_validateTeam_clicked();
    void on_pushButton_addTask_clicked();
    void on_pushButton_deleteTask_clicked();
    void on_calendarWidget_clicked(const QDate &date);
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

    // === MODULE LABO ===
    void setupLaboConnections();
    void ajouterLabo();
    void afficherLabos();
    void supprimerLabo();
    void modifierLabo();
    void chargerLaboPourModification();
    void exporterFicheLaboPdf();
    void onGovernorateClicked(const QString &governorate);

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

    // === MODULE ARDUINO ENVIRONNEMENT (DHT11 + FAN) ===
    void setupEnvironmentArduino();
    void startEnvironmentMonitoring();
    void stopEnvironmentMonitoring();
    void readEnvironmentSensor();
    void onEnvSensorDataReceived(const EnvSensorData &data);
    void updateCommandesWithEnvironmentData();
    void updateLabosWithEnvironmentData();
    void onEnvArduinoCommandSent(bool success, const QString &message);
    
    // Recherche et enregistrement Arduino
    void onSearchArduinoCommande();        // Search commande by ID
    void onRecordArduinoData();            // Record sensor data
    void onClearArduinoHistory();
    void onConnectEnvArduinoClicked();
    void onDisconnectEnvArduinoClicked();
    void updateEnvArduinoStatus();
    void addArduinoHistoryRow(const EnvSensorData &data, const QString &fanEvent, const QString &alert);
    void saveArduinoReadingToDB(const EnvSensorData &data, const QString &alert);
    void applyFanAlertStyle(const QString &alert);

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

private:
    Ui::MainWindow *ui;

    Client m_clientTmp;

    // Chart views -- module CLIENT
    QChartView *m_clientChartStatut     = nullptr;
    QChartView *m_clientChartType       = nullptr;
    QChartView *m_clientChartCA         = nullptr;
    QChartView *m_clientChartHistorique = nullptr;

    // === ETAT GLOBAL ===
    QString m_currentRole;

    // === ETAT AUTH + MOT DE PASSE OUBLIE ===
    QString m_resetEmail;
    QString m_resetIdentity;
    QString m_resetEmployeeId;
    bool m_forgotIdentityValidated = false;
    bool m_resetEmailSendingInProgress = false;
    QByteArray data;
    
    // Arduino pour empreinte digitale
    Arduino A;
    QSerialPort *m_fingerprintSerial = nullptr;
    QByteArray m_fingerprintBuffer;
    QString m_fingerprintOperation;
    int m_pendingFingerprintEmployeId = -1;
    int m_pendingFingerprintId = -1;
    QDialog *m_fingerprintAuthDialog = nullptr;
    QLabel *m_fingerprintAuthStatusLabel = nullptr;
    QWidget *m_fingerprintEnrollTab = nullptr;
    QLineEdit *m_fingerprintEnrollEmployeIdEdit = nullptr;
    QLineEdit *m_fingerprintEnrollIdentityEdit = nullptr;
    QLabel *m_fingerprintEnrollStatusLabel = nullptr;
    QPushButton *m_fingerprintEnrollStartButton = nullptr;
    QTimer *m_fingerprintTimeoutTimer = nullptr;

    // === NOUVEAU: Arduino pour environnement (DHT11 + Ventilateur) ===
    ArduinoEnvironment m_envArduino;
    QTimer *m_envSensorTimer = nullptr;
    bool m_envMonitorActive = false;
    EnvSensorData m_lastEnvData;
    int m_currentArduinoCommandeId = -1;  // ID de la commande actuellement monitoée via Arduino

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
    int m_selectedTeamIdForPlanning = -1;
    bool m_selectedTeamIsActiveForPlanning = false;

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

    // Gestionnaire reseau pour les emails et IA
    QNetworkAccessManager *m_networkManager = nullptr;
};

#endif // MAINWINDOW_H
