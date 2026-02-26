#ifndef MACHINE_WIDGET_H
#define MACHINE_WIDGET_H

#include <QWidget>

namespace Ui { class MachineWidget; }

class MachineWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MachineWidget(QWidget *parent = nullptr);
    ~MachineWidget();

    void setAuthenticated(bool authenticated);

private:
    Ui::MachineWidget *ui;
};

#endif // MACHINE_WIDGET_H