#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe_widget.h"
#include <QFile>
#include <QApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load global stylesheet from resources
    QFile styleFile(":/styles/styles.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        qApp->setStyleSheet(style);
        styleFile.close();
    }

    // Instantiate employe widget and add to stacked widget
    auto *employe = new EmployeWidget(this);
    ui->stackedMain->addWidget(employe);

    // Simple UI navigation: show employe page when button clicked
    connect(ui->btnEmploye, &QPushButton::clicked, [this, employe]() {
        ui->stackedMain->setCurrentWidget(employe);
    });

    // Other navigation buttons left unimplemented (UI only)
}

MainWindow::~MainWindow()
{
    delete ui;
}
