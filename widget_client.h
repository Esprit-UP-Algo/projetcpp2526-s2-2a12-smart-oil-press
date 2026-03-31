#ifndef WIDGET_CLIENT_H
#define WIDGET_CLIENT_H

#include <QWidget>
#include <QMessageBox>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class WidgetClient;
}
QT_END_NAMESPACE

class WidgetClient : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetClient(QWidget *parent = nullptr);
    ~WidgetClient();

private slots:
    // Tab change
    void onTabChanged(int index);

    // Tab CRUD
    void onConfirmerAjouterClicked();
    void onConfirmerModifierClicked();
    void onConfirmerSupprimerClicked();

    // Filter
    void onAppliquerFiltreClicked();

    // Table selection
    void onTableClientSelectionChanged();

    // Export PDF tab - 3 buttons
    void onExportListeClientsClicked();
    void onExportStatistiquesClicked();
    void onExportFicheClientClicked();
    void onExporterPDFClicked(); // kept for compat

private:
    Ui::WidgetClient *ui;
    Client Ctmp; // ← used to call CRUD methods (Model layer)

    // Setup methods
    void setupConnections();
    void setupTableClients();
    void setupExportTab();

    // Helper methods
    void loadSampleData();
    void updateClientInfo();
    void clearClientInfo();
    void clearFormAjouter();
    void refreshTableFromDB();
};

#endif // WIDGET_CLIENT_H
