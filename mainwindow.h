#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>

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
    void setAuthenticated(bool authenticated);

signals:
    void addRequested();
    void deleteRequested();
    void updateRequested();
    void exportListeRequested();
    void exportRapportRHRequested();
    void exportFicheRequested();
    // Authentication / password reset signals (UI-only)
    void loginRequested(const QString &username, const QString &password);
    void forgotSendCodeRequested(const QString &userOrEmail);
    void resetPasswordRequested(const QString &code, const QString &newPassword);
    void backToLoginRequested();
    void authenticatedChanged(bool authenticated);

private slots:
    // CRUD Operations
    void ajouterEmploye();
    void afficherEmployes();
    void supprimerEmploye();
    void modifierEmploye();
    void chargerEmployePourModification();
    void onTableRowClicked(int row, int column);
    
    // Recherche et Tri
    void appliquerFiltreEtTri();
    void reinitialiserFiltre();

    // Export PDF
    void exporterListeCompletePdf();
    void exporterFicheEmployePdf();

private:
    Ui::MainWindow *ui;
    QChartView *statsTopChartView = nullptr;
    QChartView *statsLeftChartView = nullptr;
    QChartView *statsRightChartView = nullptr;

    void styleSpinboxesAndComboboxes();
    void setupCrudConnections();
    void setupStatistiquesCharts();
    void refreshStatistiques();
    void clearAjouterForm();
    void clearModifierForm();
    bool validateAjouterForm();
    bool validateModifierForm();
};

#endif // MAINWINDOW_H
