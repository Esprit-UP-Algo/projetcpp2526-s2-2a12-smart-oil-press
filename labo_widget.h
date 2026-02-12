#ifndef LABO_WIDGET_H
#define LABO_WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class LaboWidget;
}
QT_END_NAMESPACE

class LaboWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LaboWidget(QWidget *parent = nullptr);
    ~LaboWidget();

private slots:
    void onDeleteLabClicked();
    void onEditLabClicked();

private:
    Ui::LaboWidget *ui;
};

#endif // LABO_WIDGET_H