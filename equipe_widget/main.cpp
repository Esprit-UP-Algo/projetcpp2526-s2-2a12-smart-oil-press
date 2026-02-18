#include <QApplication>
#include <QFile>
#include "equipe_widget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load stylesheet from resource
    QFile styleFile(":/styles/style.qss");
    if (styleFile.open(QFile::ReadOnly)) {
        QString style = QLatin1String(styleFile.readAll());
        a.setStyleSheet(style);
        styleFile.close();
    }

    MainWindow w;
    w.show();
    return a.exec();
}
