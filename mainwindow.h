#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// ==================== Dialogue Ajouter Employé (gardé car utilisé) ====================
class AjouterEmployeDialog : public QDialog
{
    Q_OBJECT
public:
    explicit AjouterEmployeDialog(QWidget *parent = nullptr);
    
    QLineEdit* getIdInput() const { return idInput; }
    QLineEdit* getNomInput() const { return nomInput; }
    QLineEdit* getPrenomInput() const { return prenomInput; }
    QSpinBox* getAgeInput() const { return ageInput; }
    QLineEdit* getTelephoneInput() const { return telephoneInput; }
    QComboBox* getSpecialiteCombo() const { return specialiteCombo; }
    QDoubleSpinBox* getSalaireInput() const { return salaireInput; }
    QSpinBox* getAncienneteInput() const { return ancienneteInput; }
    QComboBox* getDisponibiliteCombo() const { return disponibiliteCombo; }
    QSpinBox* getHeuresInput() const { return heuresInput; }
    QLineEdit* getFournisseursInput() const { return fournisseursInput; }

private:
    void setupUI();
    
    QLineEdit *idInput;
    QLineEdit *nomInput;
    QLineEdit *prenomInput;
    QSpinBox *ageInput;
    QLineEdit *telephoneInput;
    QComboBox *specialiteCombo;
    QDoubleSpinBox *salaireInput;
    QSpinBox *ancienneteInput;
    QComboBox *disponibiliteCombo;
    QSpinBox *heuresInput;
    QLineEdit *fournisseursInput;
};

// ==================== Classe Principale MainWindow ====================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // CRUD Machine - Version simplifiée avec boîtes de confirmation
    void ouvrirAjoutMachine();
    void ouvrirModifierMachine();
    void ouvrirSupprimerMachine();
    void ouvrirSignalerPanne();
    void ouvrirAjouterIntervention();
    
    // CRUD Employé
    void ouvrirAjoutEmploye();
    
    // Actions Historique (gardées pour compatibilité)
    void ouvrirSupprimerIntervention();
    void ouvrirVoirDetailsIntervention();
    
    // Autres actions
    void scannerQR();
    void exporterPDF();
    
    // Événements
    void onTableMachineSelectionChanged();
    void onTableHistoriqueSelectionChanged();

private:
    Ui::MainWindow *ui;
    
    void initialiserTableMachines();
    void initialiserTableHistorique();
    void initialiserStatistiques();
    void setupConnections();
    void ajouterMachinesDemo();
    void ajouterInterventionsDemo();
    void remplirComboboxIds();
    
    void mettreAJourStatistiques();
    
    // Application du style CSS
    void appliquerStyleCSS();
};

#endif // MAINWINDOW_H