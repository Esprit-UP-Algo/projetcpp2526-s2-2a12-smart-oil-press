#ifndef EQUIPE_WIDGET_H
#define EQUIPE_WIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class EquipeWidget; }
QT_END_NAMESPACE

class EquipeWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit EquipeWidget(QWidget *parent = nullptr);
    ~EquipeWidget();

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
    Ui::EquipeWidget *ui;
};
#endif // EQUIPE_WIDGET_H
