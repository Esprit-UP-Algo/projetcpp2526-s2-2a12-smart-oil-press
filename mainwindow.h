#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTextEdit>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDoubleSpinBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

// ==================== Dialogue Ajouter Machine ====================
class AjouterMachineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterMachineDialog(QWidget *parent = nullptr);
    
    QLineEdit* getNomInput() const { return nomInput; }
    QLineEdit* getReferenceInput() const { return referenceInput; }
    QComboBox* getCategorieCombo() const { return categorieCombo; }
    QComboBox* getEtatCombo() const { return etatCombo; }
    QLineEdit* getLocalisationInput() const { return localisationInput; }
    QDateEdit* getDateAchat() const { return dateAchat; }
    QDateEdit* getGarantieFin() const { return garantieFin; }
    QTextEdit* getDescriptionInput() const { return descriptionInput; }

private:
    void setupUI();
    
    QLineEdit *nomInput;
    QLineEdit *referenceInput;
    QComboBox *categorieCombo;
    QComboBox *etatCombo;
    QLineEdit *localisationInput;
    QDateEdit *dateAchat;
    QDateEdit *garantieFin;
    QTextEdit *descriptionInput;
};

// ==================== Dialogue Modifier Machine ====================
class ModifierMachineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ModifierMachineDialog(QWidget *parent = nullptr);
    
    void setMachineData(const QString& id, const QString& nom, const QString& reference,
                       const QString& categorie, const QString& etat, const QString& localisation);
    
    QLineEdit* getNomInput() const { return nomInput; }
    QLineEdit* getReferenceInput() const { return referenceInput; }
    QComboBox* getCategorieCombo() const { return categorieCombo; }
    QComboBox* getEtatCombo() const { return etatCombo; }
    QLineEdit* getLocalisationInput() const { return localisationInput; }

private:
    void setupUI();
    
    QLabel *idLabel;
    QLineEdit *nomInput;
    QLineEdit *referenceInput;
    QComboBox *categorieCombo;
    QComboBox *etatCombo;
    QLineEdit *localisationInput;
    QDateEdit *dateAchat;
    QDateEdit *garantieFin;
};

// ==================== Dialogue Supprimer Machine ====================
class SupprimerMachineDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SupprimerMachineDialog(QWidget *parent = nullptr);
    
    void setMachineNom(const QString& nom);

private:
    void setupUI();
    
    QLabel *messageLabel;
};

// ==================== Dialogue Signaler Panne ====================
class SignalerPanneDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SignalerPanneDialog(QWidget *parent = nullptr);
    
    void setMachineNom(const QString& nom);
    
    QComboBox* getTypePanne() const { return typePanne; }
    QTextEdit* getDescriptionPanne() const { return descriptionPanne; }
    QComboBox* getNiveauUrgence() const { return niveauUrgence; }
    QLineEdit* getTechnicienInput() const { return technicienInput; }

private:
    void setupUI();
    
    QLabel *infoLabel;
    QComboBox *typePanne;
    QTextEdit *descriptionPanne;
    QComboBox *niveauUrgence;
    QLineEdit *technicienInput;
};

// ==================== Dialogue Ajouter Intervention ====================
class AjouterInterventionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterInterventionDialog(QWidget *parent = nullptr);
    
    void setMachineNom(const QString& nom);
    
    QDateEdit* getDateIntervention() const { return dateIntervention; }
    QComboBox* getTypeIntervention() const { return typeIntervention; }
    QTextEdit* getDescriptionIntervention() const { return descriptionIntervention; }
    QLineEdit* getTechnicienIntervention() const { return technicienIntervention; }
    QDoubleSpinBox* getCoutIntervention() const { return coutIntervention; }

private:
    void setupUI();
    
    QLabel *machineLabel;
    QDateEdit *dateIntervention;
    QComboBox *typeIntervention;
    QTextEdit *descriptionIntervention;
    QLineEdit *technicienIntervention;
    QDoubleSpinBox *coutIntervention;
};

// ==================== Fenêtre Principale ====================
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // CRUD Machine - SIMULATION
    void ouvrirAjoutMachine();
    void ouvrirAjoutMachineDepuisDetails();
    void ouvrirModifierMachine();
    void ouvrirSupprimerMachine();
    void ouvrirSignalerPanne();
    
    // Actions Historique - SIMULATION
    void ouvrirAjouterIntervention();
    void ouvrirSupprimerIntervention();
    void ouvrirVoirDetailsIntervention();
    
    // Autres actions - SIMULATION
    void scannerQR();
    void exporterPDF();
    void actualiser();
    
    // Événements - STATIQUES
    void onTableMachineSelectionChanged();
    void onTableHistoriqueSelectionChanged();
    
    // Statistiques - STATIQUES
    void mettreAJourStatistiques();
    void mettreAJourGraphiqueCategories();
    void mettreAJourGraphiqueEtats();
    void mettreAJourTendanceInterventions();

private:
    void setupConnections();
    void ajouterMachinesDemo();
    void ajouterInterventionsDemo();
    void initialiserTableMachines();
    void initialiserTableHistorique();
    void initialiserStatistiques();
    
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H