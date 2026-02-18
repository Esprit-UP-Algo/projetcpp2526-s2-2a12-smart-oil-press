
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipe_widget.h"
#include <QFile>
#include <QApplication>
#include <QSizePolicy>
#include <QLayout>
#include <QResizeEvent>
#include <QWidget>
#include <QFormLayout>
#include <QDebug>
#include <stdexcept>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load global stylesheet from resources
    QFile styleFile(":/styles/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }

    // Ensure sidebar stays at intended width and its layout is normalized
    if (ui->navFrame) {
        // Keep the sidebar at 200px and give its internal layout a small padding
        ui->navFrame->setMinimumWidth(200);
        ui->navFrame->setMaximumWidth(200);
        ui->navFrame->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        if (ui->navFrame->layout()) {
            // small padding inside the sidebar so the logo and buttons don't stick to edges
            ui->navFrame->layout()->setContentsMargins(8, 8, 8, 8);
            ui->navFrame->layout()->setSpacing(8);
        }
    }

    // Set navigation buttons to fill available space with fixed height
    for (auto btn : {ui->btnEmploye, ui->btnEquipe, ui->btnClient, 
                     ui->btnLaboratoire, ui->btnCommande, ui->btnMachine}) {
        if (btn) {
            // Use Preferred policy so they size to the layout, not expand beyond it
            btn->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
            btn->setMinimumHeight(45);
            btn->setMinimumWidth(0);  // Don't force width, let layout handle it
        }
    }

    // Ensure main stacked area expands to fill the remaining space
    if (ui->stackedMain) {
        ui->stackedMain->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    }

    // Make sure the horizontal layout gives most space to the stacked area
    if (ui->horizontalLayoutMain) {
        // index 0 = navFrame (fixed 200px), index 1 = stackedMain (takes remaining space)
        ui->horizontalLayoutMain->setStretch(0, 0);
        ui->horizontalLayoutMain->setStretch(1, 1);
        // leave a modest outer margin so the sidebar doesn't touch the window edges
        ui->horizontalLayoutMain->setContentsMargins(12, 12, 12, 12);
        ui->horizontalLayoutMain->setSpacing(12);
    }

    // Give the central area a matching outer margin so content sits nicely inside the window
    if (ui->centralwidget && ui->centralwidget->layout()) {
        ui->centralwidget->layout()->setContentsMargins(12, 12, 12, 12);
    }

    // Instantiate EquipeWidget (module) and add to main stacked widget
    equipeWidget = new EquipeWidget(this);
    if (ui->stackedMain && equipeWidget) {
        ui->stackedMain->addWidget(equipeWidget);
        // Zero all margins and padding on stacked area
        ui->stackedMain->setContentsMargins(0, 0, 0, 0);
        ui->stackedMain->setCurrentWidget(equipeWidget);
        equipeWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        equipeWidget->setContentsMargins(0, 0, 0, 0);
    }

    // Connect sidebar button to show the equipe module
    if (ui->btnEquipe) {
        connect(ui->btnEquipe, &QPushButton::clicked, this, [this]() {
            if (ui->stackedMain && equipeWidget) ui->stackedMain->setCurrentWidget(equipeWidget);
        });
    }

    // Disable navigation until login (UI-only)
    if (ui->btnEmploye) ui->btnEmploye->setEnabled(false);
    if (ui->btnClient) ui->btnClient->setEnabled(false);
    if (ui->btnLaboratoire) ui->btnLaboratoire->setEnabled(false);
    if (ui->btnCommande) ui->btnCommande->setEnabled(false);
    if (ui->btnMachine) ui->btnMachine->setEnabled(false);

    // Show sidebar at startup. If you want to hide it until login, set false.
    if (ui->navFrame) ui->navFrame->setVisible(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    // Layout is now handled purely by stretch factors and sizePolicy;
    // no artificial constraints needed.
    // Debug: print sizes to diagnose sidebar/central sizing
    if (ui) {
        int navW = ui->navFrame ? ui->navFrame->width() : -1;
        int centralW = ui->centralwidget ? ui->centralwidget->width() : -1;
        int stackedW = ui->stackedMain ? ui->stackedMain->width() : -1;
        qDebug() << "resizeEvent: navFrame.width=" << navW
                 << " central.width=" << centralW
                 << " stacked.width=" << stackedW;
    }
}
