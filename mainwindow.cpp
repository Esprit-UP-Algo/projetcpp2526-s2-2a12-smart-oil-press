#include "mainwindow.h"
#include "ui_mainwindow.h"  // This includes the UI from labo.ui
#include <QFile>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load the stylesheet
    QFile styleFile(":/style/styles.qss"); 
    if(styleFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleFile.readAll());
        this->setStyleSheet(styleSheet);
        styleFile.close();
    }

    // Load the logo
    loadLogo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadLogo()
{
    // Load logo from resources
    QPixmap logoPixmap(":/images/logo.png");
    
    if (!logoPixmap.isNull()) {
        // Scale to fit the label
        QPixmap scaledLogo = logoPixmap.scaled(
            ui->lblLogo->size(),
            Qt::KeepAspectRatio,
            Qt::SmoothTransformation
        );
        
        ui->lblLogo->setPixmap(scaledLogo);
        ui->lblLogo->setAlignment(Qt::AlignCenter);
    }
}