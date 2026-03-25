#ifndef LABO_WIDGET_H
#define LABO_WIDGET_H

#include <QWidget>

namespace Ui { class LaboWidget; }

class LaboWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LaboWidget(QWidget *parent = nullptr);
    ~LaboWidget();

private slots:
    void on_topNavTabs_currentChanged(int index);
    void rechercherLaboratoires();
    void filterLaboratoires();
    void trierLaboratoires();
    void exporterPDF();
    void exporterListePDF();

private:
    Ui::LaboWidget *ui;
    void setupConnections();
    void populateTableWithSampleData();
};

#endif // LABO_WIDGET_H
