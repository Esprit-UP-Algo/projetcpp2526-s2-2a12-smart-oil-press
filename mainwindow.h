#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class EmployeWidget;
class EquipeWidget;
class CommandeWidget;
class LaboWidget;
class WidgetClient;
class MachineWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    EmployeWidget *employeWidget = nullptr;
    EquipeWidget *equipeWidget = nullptr;
    CommandeWidget *commandeWidget = nullptr;
    LaboWidget *laboWidget = nullptr;
    WidgetClient *clientWidget = nullptr;
    MachineWidget *machineWidget = nullptr;
};

#endif // MAINWINDOW_H
