#ifndef MACHINE_WIDGET_H
#define MACHINE_WIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QVariantMap>
#include <QList>

class MachineWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MachineWidget(QWidget *parent = nullptr);
    ~MachineWidget();

    // Getters pour récupérer les valeurs saisies
    QString getId() const;
    QString getNom() const;
    QString getCategorie() const;
    QString getReference() const;
    QString getDateAchat() const;
    QString getEtat() const;
    QString getLocalisation() const;
    
    // Setter pour remplir le formulaire (modification)
    void setMachineData(const QString& id, const QString& nom, const QString& categorie,
                        const QString& reference, const QString& dateAchat, 
                        const QString& etat, const QString& localisation);
    
    // Pour afficher la liste des machines
    void setMachinesList(const QList<QVariantMap>& machines);
    
    // Réinitialiser le formulaire
    void clearForm();
    
    void setAuthenticated(bool authenticated);

signals:
    void addRequested();
    void deleteRequested();
    void updateRequested();
    void exportListeRequested();
    void exportRapportMachineRequested();
    void exportFicheRequested();
    void maintenanceRequested();
    void panneRequested();
    void historiqueRequested();
    void machineSelected(const QString& id);

private slots:
    void onAddClicked();
    void onDeleteClicked();
    void onUpdateClicked();
    void onHistoriqueClicked();

private:
    // Widgets principaux
    QLineEdit *m_idEdit;
    QLineEdit *m_nomEdit;
    QComboBox *m_categorieCombo;
    QLineEdit *m_referenceEdit;
    QDateEdit *m_dateAchatEdit;
    QComboBox *m_etatCombo;
    QLineEdit *m_localisationEdit;
    QTableWidget *m_tableWidget;
    
    void setupUi();
    void setupConnections();
    bool validateForm();
    void styleSpinboxesAndComboboxes();
};

#endif // MACHINE_WIDGET_H