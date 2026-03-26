#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "labo.h"

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
    // Declarations reservees au module Laboratoire.
    void ajouterLabo();
    void afficherLabos();
    void supprimerLabo();
    void modifierLabo();
    void chargerLaboPourModification();

    // === MODULE COMMANDE ===
    // Declarations reservees au module Commande.

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
};

#endif // MAINWINDOW_H
