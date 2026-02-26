#ifndef MACHINE_WIDGET_H
#define MACHINE_WIDGET_H

#include <QWidget>
#include <QString>

namespace Ui { class MachineWidget; }

class MachineWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MachineWidget(QWidget *parent = nullptr);
    ~MachineWidget();

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

private:
    Ui::MachineWidget *ui;
    void styleSpinboxesAndComboboxes();
};

#endif // MACHINE_WIDGET_H