#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindow window;
    window.showMaximized();   // واجهة كبيرة كيما الصورة
    // window.show();         // تنجم تستعملها إذا تحب

    return app.exec();
}
