#ifndef EQUIPE_WIDGET_H
#define EQUIPE_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QTabWidget;
class QStackedWidget;
QT_END_NAMESPACE

class EquipeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EquipeWidget(QWidget *parent = nullptr);
    ~EquipeWidget();

private slots:
    void on_topNavTabs_currentChanged(int index);

private:
    // Supprimez Ui::EquipeWidget *ui;
    
    // Remplacez par des pointeurs directs si nécessaire
    QTabWidget *m_topNavTabs;
    QStackedWidget *m_stackedWidget;
};

#endif // EQUIPE_WIDGET_H
