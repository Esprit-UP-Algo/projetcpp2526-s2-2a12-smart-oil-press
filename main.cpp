#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QFont font("Segoe UI", 10);
    QApplication::setFont(font);

    MainWindow window;
    window.setWindowTitle("Smart Oil Press Control System");
    window.resize(1280, 720);
    window.show();

    return app.exec();
}
