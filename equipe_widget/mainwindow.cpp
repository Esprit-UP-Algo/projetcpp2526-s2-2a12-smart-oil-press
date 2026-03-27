
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipe_widget.h"
#include <QApplication>
#include <QFile>
#include <QLayout>
#include <QPushButton>
#include <QSizePolicy>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile styleFile(":/styles/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        qApp->setStyleSheet(QLatin1String(styleFile.readAll()));
    }

    if (ui->navFrame) {
        ui->navFrame->setMinimumWidth(200);
        ui->navFrame->setMaximumWidth(200);
        ui->navFrame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        if (ui->navFrame->layout()) {
            ui->navFrame->layout()->setContentsMargins(8, 8, 8, 8);
            ui->navFrame->layout()->setSpacing(8);
        }
    }

    const auto navButtons = {ui->btnEmploye, ui->btnEquipe, ui->btnClient,
                             ui->btnLaboratoire, ui->btnCommande, ui->btnMachine};
    for (QPushButton *btn : navButtons) {
        if (btn) {
            btn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            btn->setMinimumHeight(45);
            btn->setMinimumWidth(0);
        }
    }

    if (ui->stackedMain) {
        ui->stackedMain->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    if (ui->horizontalLayoutMain) {
        ui->horizontalLayoutMain->setStretch(0, 0);
        ui->horizontalLayoutMain->setStretch(1, 1);
        ui->horizontalLayoutMain->setContentsMargins(12, 12, 12, 12);
        ui->horizontalLayoutMain->setSpacing(12);
    }

    if (ui->centralwidget && ui->centralwidget->layout()) {
        ui->centralwidget->layout()->setContentsMargins(12, 12, 12, 12);
    }

    equipeWidget = new EquipeWidget(this);
    if (ui->stackedMain && equipeWidget) {
        ui->stackedMain->addWidget(equipeWidget);
        ui->stackedMain->setContentsMargins(0, 0, 0, 0);
        ui->stackedMain->setCurrentWidget(equipeWidget);
        equipeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        equipeWidget->setContentsMargins(0, 0, 0, 0);
    }

    if (ui->btnEquipe) {
        connect(ui->btnEquipe, &QPushButton::clicked, this, [this]() {
            if (ui->stackedMain && equipeWidget) {
                ui->stackedMain->setCurrentWidget(equipeWidget);
            }
        });
    }

    for (QPushButton *btn : {ui->btnEmploye, ui->btnClient, ui->btnLaboratoire, ui->btnCommande, ui->btnMachine}) {
        if (btn) {
            btn->setEnabled(false);
        }
    }

    if (ui->navFrame) {
        ui->navFrame->setVisible(true);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
}
