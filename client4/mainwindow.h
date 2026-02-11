#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

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

private slots:
    // Navigation buttons
    void onEmployeClicked();
    void onEquipeClicked();
    void onClientClicked();
    void onLaboratoireClicked();
    void onCommandeClicked();
    void onMachineClicked();

    // Client management buttons
    void onExporterPDFClicked();
    
    // Quick action buttons
    void onActionAjouterClicked();
    void onActionModifierClicked();
    void onActionSupprrimerClicked();
    
    // Filter
    void onAppliquerFiltreClicked();
    
    // Table selection
    void onTableClientSelectionChanged();

private:
    Ui::MainWindow *ui;

    // Setup methods
    void setupUiStyle();
    void setupConnections();
    void setupTableClients();
    
    // Helper methods
    void loadSampleData();
    void updateClientInfo();
    void clearClientInfo();
    void showClientDialog(bool isEdit = false);
};

#endif // MAINWINDOW_H
