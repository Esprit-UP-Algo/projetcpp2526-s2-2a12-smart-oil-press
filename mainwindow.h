#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    void loadStylesheet();
};

#endif // MAINWINDOW_H
