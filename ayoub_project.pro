QT = core gui sql widgets
QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = ayoub_project
TEMPLATE = app

# Force SQL module
QMAKE_CXXFLAGS += -IC:/Qt/6.7.3/mingw_64/include/QtSql
QMAKE_LFLAGS += -LC:/Qt/6.7.3/mingw_64/lib -lQt6Sql
LIBS += C:/Qt/6.7.3/mingw_64/lib/libQt6Sql.a

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    connection.cpp

HEADERS += \
    mainwindow.h \
    connection.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    resources.qrc