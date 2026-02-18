// Refactored to a widget-only module for the Equipe feature
#ifndef EQUIPE_WIDGET_H
#define EQUIPE_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class EquipeWidget; }
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
    Ui::EquipeWidget *ui;
};

#endif // EQUIPE_WIDGET_H
