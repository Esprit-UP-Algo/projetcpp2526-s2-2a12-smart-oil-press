#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QFrame>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCommande_clicked();
    void on_btnEquipe_clicked();
    void on_btnClient_clicked();
    void on_btnLaboratoire_clicked();
    void on_btnFournisseur_clicked();
    void on_btnMachine_clicked();

    // Slots pour les fonctionnalités
    void on_btnAjouter_clicked();
    void on_btnSupprimer_clicked();
    void on_btnModifier_clicked();
    void on_btnCharger_clicked();
    void on_btnExportListe_clicked();
    void on_btnExportRapport_clicked();
    void on_btnExportFiche_clicked();
    void on_btnEnvoyerEmail_clicked();

    // Slots pour le tri
    void on_radioButton_dateArrivage_toggled(bool checked);
    void on_radioButton_montant_toggled(bool checked);
    void on_radioButton_quantite_toggled(bool checked);
    void on_radioButton_dateSortie_toggled(bool checked);
    void on_radioButton_croissant_toggled(bool checked);
    void on_radioButton_decroissant_toggled(bool checked);

private:
    Ui::MainWindow *ui;
    void setupNavigation();
    void setupConnections();
    void loadStylesheet();
    void trierTableau();
};

#endif // MAINWINDOW_H
