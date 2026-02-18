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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Recherche et filtres
    void rechercherLaboratoires();
    void filterLaboratoires();
    void trierLaboratoires();
    
    // Export
    void exporterPDF();           // Pour l'onglet Statistiques
    void exporterListePDF();      // Pour le bouton dans la liste
    
    // Suggestions
    void rechercherSuggestions();

private:
    Ui::MainWindow *ui;
    
    // Fonctions d'initialisation
    void loadStylesheet();
    void loadLogo();
    void setupTabConnections();
    void setupEmptyPages();
    void populateTableWithSampleData();
};

#endif // MAINWINDOW_H