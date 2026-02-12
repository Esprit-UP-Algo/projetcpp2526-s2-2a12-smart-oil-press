#ifndef WIDGET_CLIENT_H
#define WIDGET_CLIENT_H

#include <QWidget>
#include <QMessageBox>

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
    Ui::WidgetClient *ui;

    // Setup methods
    void setupConnections();
    void setupTableClients();
    
    // Helper methods
    void loadSampleData();
    void updateClientInfo();
    void clearClientInfo();
    void showClientDialog(bool isEdit = false);
};

#endif // WIDGET_CLIENT_H
