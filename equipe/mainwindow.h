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
    // Section vide pour supprimer les erreurs "undefined reference"
    // Tu rajouteras tes boutons un par un plus tard.

    void on_Recherche_clicked();

    void on_stats_clicked();

    void on_sugg_2_clicked();

    void on_plan_clicked();

    void on_ajout_clicked();



    void on_Retour_clicked();

    void on_Retour_2_clicked();

    void on_pushButton_21_clicked();

    void on_supprimer_clicked();

    void on_Retour_3_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
