#ifndef WIDGET_CLIENT_H
#define WIDGET_CLIENT_H

#include <QWidget>
#include <QMessageBox>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetClient; }
QT_END_NAMESPACE

class WidgetClient : public QWidget
{
    Q_OBJECT

public:
    explicit WidgetClient(QWidget *parent = nullptr);
    ~WidgetClient();

private slots:
    void onTabChanged(int index);

    void onConfirmerAjouterClicked();
    void onConfirmerModifierClicked();
    void onConfirmerSupprimerClicked();

    void onAppliquerFiltreClicked();
    void onTableClientSelectionChanged();
    void onNavQuitterClicked();      // called from mainwindow btnQuit signal

    void onExportListeClientsClicked();
    void onExportStatistiquesClicked();
    void onExportFicheClientClicked();
    void onExporterPDFClicked();

private:
    Ui::WidgetClient *ui;
    Client Ctmp;

    void setupConnections();
    void setupTableClients();
    void setupLogo();          // no-op: logo is in mainwindow.ui
    void setupExportTab();

    void loadSampleData();
    void refreshTableFromDB();
    void updateClientInfo();
    void clearClientInfo();
    void clearFormAjouter();
};

#endif // WIDGET_CLIENT_H