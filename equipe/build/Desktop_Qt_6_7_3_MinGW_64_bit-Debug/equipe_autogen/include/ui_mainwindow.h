/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QFrame *frame_2;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_11;
    QPushButton *pushButton_10;
    QPushButton *pushButton_9;
    QFrame *frame_3;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Recherche;
    QPushButton *stats;
    QPushButton *planns;
    QStackedWidget *stackedWidget;
    QWidget *page_rech;
    QLineEdit *lineEdit;
    QPushButton *pushButton_19;
    QTableWidget *tableWidget;
    QFrame *frame_4;
    QPushButton *pushButton_20;
    QPushButton *pushButton_21;
    QPushButton *pushButton_22;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_23;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QPushButton *pushButton_14;
    QWidget *page_stat;
    QFrame *frame_5;
    QLabel *label_9;
    QLabel *label_10;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_11;
    QLabel *label_12;
    QListWidget *listWidget_2;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *page_plannification;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_24;
    QListWidget *listWidget;
    QCalendarWidget *calendarWidget;
    QWidget *page_6;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(1280, 720));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 237, 227);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 50, 201, 671));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 177, 158);\n"
"QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding-left: 15px; /* Use padding-left since your text is aligned left */\n"
"    font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    /* One clear color for the text on hover */\n"
"    color: rgb(189, 210, 182); \n"
"    \n"
"    /* A subtle background color so the user knows they are hovering */\n"
"    background-color: rgba(255, 255, 255, 20); \n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 161, 111));
        label->setStyleSheet(QString::fromUtf8("font: 700 14pt \"Segoe UI\";\n"
"color: rgb(248, 237, 227);"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/logo.png")));
        label->setScaledContents(true);
        verticalLayoutWidget = new QWidget(frame);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 170, 171, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setMinimumSize(QSize(50, 50));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    text-align: left;\n"
"    padding-right: 15px;\n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    background-color: rgba(255, 255, 255, 60); /* Increased from 30 to 60 to be more visible */\n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        verticalLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(verticalLayoutWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setMinimumSize(QSize(50, 50));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"   text-align: left;\n"
"    padding-right: 15px;\n"
"    \n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    background-color: rgba(255, 255, 255, 60); /* Increased from 30 to 60 to be more visible */\n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(verticalLayoutWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setMinimumSize(QSize(50, 50));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	text-align: left;\n"
"    padding-right: 15px;\n"
"    \n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    background-color: rgba(255, 255, 255, 60); /* Increased from 30 to 60 to be more visible */\n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(verticalLayoutWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setMinimumSize(QSize(50, 50));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	text-align: left;\n"
"    padding-right: 15px;\n"
"    \n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    background-color: rgba(255, 255, 255, 60); /* Increased from 30 to 60 to be more visible */\n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        verticalLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(verticalLayoutWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setMinimumSize(QSize(50, 50));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	text-align: left;\n"
"    padding-right: 15px;\n"
"    \n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    background-color: rgba(255, 255, 255, 60); /* Increased from 30 to 60 to be more visible */\n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        verticalLayout->addWidget(pushButton_7);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setMinimumSize(QSize(50, 50));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"	text-align: left;\n"
"    padding-right: 15px;\n"
"    \n"
"	font: 700 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    background-color: rgba(255, 255, 255, 60); /* Increased from 30 to 60 to be more visible */\n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        verticalLayout->addWidget(pushButton);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 1281, 31));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 177, 158);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget = new QWidget(frame_2);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 241, 29));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(horizontalLayoutWidget);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    \n"
"	font: 700 6pt \"bold\";\n"
"}\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    \n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        horizontalLayout->addWidget(pushButton_11);

        pushButton_10 = new QPushButton(horizontalLayoutWidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    \n"
"	font: 700 6pt \"bold\";\n"
"}\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    \n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        horizontalLayout->addWidget(pushButton_10);

        pushButton_9 = new QPushButton(horizontalLayoutWidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    \n"
"	font: 700 6pt \"bold\";\n"
"}\n"
"QPushButton:hover {\n"
"    \n"
"	color: rgb(121, 135, 119);\n"
"    \n"
"    border: 1px solid rgba(255, 255, 255, 10); /* Adding a border often forces the OS to let go */\n"
"}"));

        horizontalLayout->addWidget(pushButton_9);

        frame_3 = new QFrame(centralwidget);
        frame_3->setObjectName("frame_3");
        frame_3->setGeometry(QRect(220, 50, 1051, 51));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 177, 158);"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(frame_3);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 1061, 51));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Recherche = new QPushButton(horizontalLayoutWidget_2);
        Recherche->setObjectName("Recherche");
        Recherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"}"));

        horizontalLayout_2->addWidget(Recherche);

        stats = new QPushButton(horizontalLayoutWidget_2);
        stats->setObjectName("stats");
        stats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"}"));

        horizontalLayout_2->addWidget(stats);

        planns = new QPushButton(horizontalLayoutWidget_2);
        planns->setObjectName("planns");
        planns->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"}"));

        horizontalLayout_2->addWidget(planns);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(220, 110, 1071, 591));
        page_rech = new QWidget();
        page_rech->setObjectName("page_rech");
        lineEdit = new QLineEdit(page_rech);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 40, 971, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid rgb(161, 177, 158);\n"
"    border-radius: 15px;\n"
"    color: black; /* This is the text you type */\n"
"    padding: 5px 15px;\n"
"    font: 700 10pt \"Segoe UI\";\n"
"    min-width: 550px; /* Essential to show your long placeholder text */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid black;\n"
"}\n"
"\n"
"/* This styles the 'recherche des equipes...' text before you type */\n"
"QLineEdit::placeholder {\n"
"    color: #666666; /* Dark grey placeholder */\n"
"    font-style: italic;\n"
"    font-weight: 400;\n"
"}"));
        pushButton_19 = new QPushButton(page_rech);
        pushButton_19->setObjectName("pushButton_19");
        pushButton_19->setGeometry(QRect(10, 0, 71, 31));
        pushButton_19->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A1B19E; /* Your green */\n"
"    color: white;\n"
"    border-radius: 10px;      /* This rounds the corners */\n"
"    padding: 5px 15px;        /* Adds space inside so text doesn't touch the edge */\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8E9E8B; /* Darkens when you hover over it */\n"
"}"));
        tableWidget = new QTableWidget(page_rech);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QFont font;
        font.setBold(true);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(280, 90, 771, 501));
        tableWidget->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: white;\n"
"    color: black;\n"
"    gridline-color: #A1B19E;\n"
"    border: 2px solid #A1B19E;\n"
"    font: 10pt \"Segoe UI\";\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #A1B19E;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"    padding: 5px;\n"
"    border: 1px solid white;\n"
"}\n"
"/* Styling the Vertical Scroll Bar */\n"
"QScrollBar:vertical {\n"
"    border: none;\n"
"    background: #F8F4F0; /* Light cream background */\n"
"    width: 14px;         /* Make it wide enough to grab easily */\n"
"    margin: 0px 0px 0px 0px;\n"
"}\n"
"\n"
"/* The actual draggable handle */\n"
"QScrollBar::handle:vertical {\n"
"    background: #A1B19E; /* Your signature green */\n"
"    min-height: 30px;\n"
"    border-radius: 7px;\n"
"    margin: 2px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:hover {\n"
"    background: #8E9E8B; /* Darker green when hovering */\n"
"}\n"
"\n"
"/* Hide the arrows at the top and bottom for a modern look */\n"
"QScrollBar::"
                        "add-line:vertical, QScrollBar::sub-line:vertical {\n"
"    height: 0px;\n"
"}"));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);
        frame_4 = new QFrame(page_rech);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 90, 271, 481));
        frame_4->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     /* Very light cream to contrast the table */\n"
"	background-color: rgb(248, 237, 227);\n"
"    border: 2px solid #A1B19E;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"/* Style for all buttons inside this frame */\n"
"QPushButton {\n"
"    background-color: #A1B19E;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\";\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8E9E8B; /* Darker green on hover */\n"
"}\n"
"\n"
"QPushButton#btnDelete {\n"
"    background-color: #c97d7d; /* Soft red for delete to warn the user */\n"
"}"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_20 = new QPushButton(frame_4);
        pushButton_20->setObjectName("pushButton_20");
        pushButton_20->setGeometry(QRect(0, 440, 271, 41));
        pushButton_21 = new QPushButton(frame_4);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(0, 390, 271, 41));
        pushButton_22 = new QPushButton(frame_4);
        pushButton_22->setObjectName("pushButton_22");
        pushButton_22->setGeometry(QRect(0, 340, 271, 41));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 280, 271, 51));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 0, 271, 51));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        pushButton_23 = new QPushButton(frame_4);
        pushButton_23->setObjectName("pushButton_23");
        pushButton_23->setGeometry(QRect(10, 80, 111, 41));
        pushButton_23->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A1B19E; /* Your green */\n"
"    color: white;\n"
"    border-radius: 10px;      /* This rounds the corners */\n"
"    padding: 5px 15px;        /* Adds space inside so text doesn't touch the edge */\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8E9E8B; /* Darkens when you hover over it */\n"
"}"));
        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName("checkBox_3");
        checkBox_3->setGeometry(QRect(20, 210, 111, 51));
        checkBox_3->setStyleSheet(QString::fromUtf8("/* The text next to the checkbox */\n"
"QCheckBox {\n"
"    color: black;\n"
"    font: 10pt \"Segoe UI\";\n"
"    spacing: 8px; /* Space between the box and the text */\n"
"}\n"
"\n"
"/* The actual square box */\n"
"QCheckBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 2px solid #A1B19E; /* Your green */\n"
"    border-radius: 4px;        /* Soft edges */\n"
"    background-color: white;\n"
"}\n"
"\n"
"/* When the user hovers over the box */\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #8E9E8B; /* Darker green */\n"
"    background-color: #F4F7F3;\n"
"}\n"
"\n"
"/* Style for the 'Checked' state */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #A1B19E; /* Fill with green when checked */\n"
"    border: 2px solid #A1B19E;\n"
"    /* This creates a simple white 'L' shape as a checkmark */\n"
"    image: url(check_mark.png); /* If you have an icon, or use the styling below */\n"
"}\n"
"\n"
"/* If you don't have an icon file, you can use a background color \n"
""
                        "   or a different border style to show it is selected */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #A1B19E;\n"
"    image: none; \n"
"}"));
        checkBox_4 = new QCheckBox(frame_4);
        checkBox_4->setObjectName("checkBox_4");
        checkBox_4->setGeometry(QRect(140, 210, 121, 51));
        checkBox_4->setStyleSheet(QString::fromUtf8("/* The text next to the checkbox */\n"
"QCheckBox {\n"
"    color: black;\n"
"    font: 10pt \"Segoe UI\";\n"
"    spacing: 8px; /* Space between the box and the text */\n"
"}\n"
"\n"
"/* The actual square box */\n"
"QCheckBox::indicator {\n"
"    width: 18px;\n"
"    height: 18px;\n"
"    border: 2px solid #A1B19E; /* Your green */\n"
"    border-radius: 4px;        /* Soft edges */\n"
"    background-color: white;\n"
"}\n"
"\n"
"/* When the user hovers over the box */\n"
"QCheckBox::indicator:hover {\n"
"    border: 2px solid #8E9E8B; /* Darker green */\n"
"    background-color: #F4F7F3;\n"
"}\n"
"\n"
"/* Style for the 'Checked' state */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #A1B19E; /* Fill with green when checked */\n"
"    border: 2px solid #A1B19E;\n"
"    /* This creates a simple white 'L' shape as a checkmark */\n"
"    image: url(check_mark.png); /* If you have an icon, or use the styling below */\n"
"}\n"
"\n"
"/* If you don't have an icon file, you can use a background color \n"
""
                        "   or a different border style to show it is selected */\n"
"QCheckBox::indicator:checked {\n"
"    background-color: #A1B19E;\n"
"    image: none; \n"
"}"));
        label_8 = new QLabel(frame_4);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 170, 91, 41));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        comboBox_2 = new QComboBox(frame_4);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(130, 80, 111, 44));
        comboBox_2->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
"QComboBox {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #A1B19E;\n"
"    border-radius: 10px;\n"
"    padding: 5px 10px;\n"
"    color: #000000;\n"
"    font: 10pt \"Segoe UI\";\n"
"    min-height: 30px;\n"
"}\n"
"\n"
"/* Style for the little arrow area on the right */\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 30px;\n"
"    border-left: 1px solid #A1B19E;\n"
"    border-top-right-radius: 10px;\n"
"    border-bottom-right-radius: 10px;\n"
"    background-color: #f9f9f9;\n"
"}\n"
"\n"
"/* The actual arrow icon */\n"
"QComboBox::down-arrow {\n"
"    image: none;\n"
"    border-left: 5px solid transparent;\n"
"    border-right: 5px solid transparent;\n"
"    border-top: 7px solid #A1B19E; /* Green downward triangle */\n"
"}\n"
"\n"
"/* Styling the popup list that appears */\n"
"QComboBox QAbstractItemView {\n"
"    border: 2px solid #A1B19E;\n"
"    background-color: #ffffff;\n"
"    "
                        "selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        pushButton_14 = new QPushButton(page_rech);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(980, 40, 71, 31));
        pushButton_14->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A1B19E; /* Your green */\n"
"    color: white;\n"
"    border-radius: 10px;      /* This rounds the corners */\n"
"    padding: 5px 15px;        /* Adds space inside so text doesn't touch the edge */\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8E9E8B; /* Darkens when you hover over it */\n"
"}"));
        stackedWidget->addWidget(page_rech);
        page_stat = new QWidget();
        page_stat->setObjectName("page_stat");
        frame_5 = new QFrame(page_stat);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(10, 30, 1011, 481));
        frame_5->setStyleSheet(QString::fromUtf8("QFrame {\n"
"     /* Very light cream to contrast the table */\n"
"	background-color: rgb(248, 237, 227);\n"
"    border: 2px solid #A1B19E;\n"
"    border-radius: 15px;\n"
"}\n"
"\n"
"/* Style for all buttons inside this frame */\n"
"QPushButton {\n"
"    background-color: #A1B19E;\n"
"    color: white;\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    font-weight: bold;\n"
"    font-family: \"Segoe UI\";\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8E9E8B; /* Darker green on hover */\n"
"}\n"
"\n"
"QPushButton#btnDelete {\n"
"    background-color: #c97d7d; /* Soft red for delete to warn the user */\n"
"}"));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        label_9 = new QLabel(frame_5);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(530, 250, 271, 51));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_10 = new QLabel(frame_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(0, 0, 271, 51));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        line = new QFrame(frame_5);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 230, 1011, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(frame_5);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(510, 0, 16, 481));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label_11 = new QLabel(frame_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(530, 0, 291, 51));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(0, 250, 271, 51));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        listWidget_2 = new QListWidget(frame_5);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(540, 60, 441, 151));
        listWidget_2->setStyleSheet(QString::fromUtf8("/* Ensure the list container itself is visible */\n"
"QListWidget {\n"
"    background-color: #fcfaf8; /* Very light cream to match your app background */\n"
"    border: 1px solid #A1B19E;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Create the \"Card\" look for each task */\n"
"QListWidget::item {\n"
"    background-color: #ffffff; \n"
"    color: #333333;\n"
"    border: 1px solid #A1B19E;\n"
"    border-radius: 5px;\n"
"    margin: 4px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #f0f2ef;\n"
"}"));
        plainTextEdit = new QPlainTextEdit(frame_5);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(530, 310, 471, 161));
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #A1B19E; /* Votre vert signature */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    color: #333333;\n"
"}"));
        plainTextEdit_2 = new QPlainTextEdit(frame_5);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(20, 60, 471, 161));
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #A1B19E; /* Votre vert signature */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    color: #333333;\n"
"}"));
        label_13 = new QLabel(frame_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(30, 440, 231, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_14 = new QLabel(frame_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(30, 400, 231, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_15 = new QLabel(frame_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(30, 360, 231, 31));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        stackedWidget->addWidget(page_stat);
        page_plannification = new QWidget();
        page_plannification->setObjectName("page_plannification");
        lineEdit_2 = new QLineEdit(page_plannification);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(0, 20, 971, 31));
        lineEdit_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: white;\n"
"    border: 2px solid rgb(161, 177, 158);\n"
"    border-radius: 15px;\n"
"    color: black; /* This is the text you type */\n"
"    padding: 5px 15px;\n"
"    font: 700 10pt \"Segoe UI\";\n"
"    min-width: 550px; /* Essential to show your long placeholder text */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid black;\n"
"}\n"
"\n"
"/* This styles the 'recherche des equipes...' text before you type */\n"
"QLineEdit::placeholder {\n"
"    color: #666666; /* Dark grey placeholder */\n"
"    font-style: italic;\n"
"    font-weight: 400;\n"
"}"));
        pushButton_24 = new QPushButton(page_plannification);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setGeometry(QRect(970, 20, 71, 31));
        pushButton_24->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #A1B19E; /* Your green */\n"
"    color: white;\n"
"    border-radius: 10px;      /* This rounds the corners */\n"
"    padding: 5px 15px;        /* Adds space inside so text doesn't touch the edge */\n"
"    border: none;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8E9E8B; /* Darkens when you hover over it */\n"
"}"));
        listWidget = new QListWidget(page_plannification);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(650, 60, 311, 481));
        listWidget->setStyleSheet(QString::fromUtf8("/* Ensure the list container itself is visible */\n"
"QListWidget {\n"
"    background-color: #fcfaf8; /* Very light cream to match your app background */\n"
"    border: 1px solid #A1B19E;\n"
"    border-radius: 10px;\n"
"    padding: 5px;\n"
"}\n"
"\n"
"/* Create the \"Card\" look for each task */\n"
"QListWidget::item {\n"
"    background-color: #ffffff; \n"
"    color: #333333;\n"
"    border: 1px solid #A1B19E;\n"
"    border-radius: 5px;\n"
"    margin: 4px;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QListWidget::item:hover {\n"
"    background-color: #f0f2ef;\n"
"}"));
        calendarWidget = new QCalendarWidget(page_plannification);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setEnabled(false);
        calendarWidget->setGeometry(QRect(30, 60, 611, 481));
        calendarWidget->setAutoFillBackground(false);
        calendarWidget->setStyleSheet(QString::fromUtf8("/* --- 1. THE MAIN BACKGROUND --- */\n"
"QCalendarWidget QWidget {\n"
"    background-color: #ffffff; /* Change this to change the overall background color */\n"
"}\n"
"\n"
"/* --- 2. THE TOP BAR (Month and Year Selector) --- */\n"
"QCalendarWidget #qt_calendar_navigationbar {\n"
"    background-color: #A1B19E; /* Change this for the top header background */\n"
"    border-bottom: 1px solid #8E9E8B;\n"
"}\n"
"\n"
"/* --- 3. THE BUTTONS AT THE TOP (Arrows and Month/Year text) --- */\n"
"QCalendarWidget QToolButton {\n"
"    color: #ffffff;             /* Change this for the text color of month/year */\n"
"    background-color: transparent; \n"
"    font-weight: bold;\n"
"    border: none;\n"
"}\n"
"\n"
"/* --- 4. THE FIX FOR THE BLACK BARS (First Line and First Column) --- */\n"
"/* This targets the \"Header\" sections which are usually black by default */\n"
"QCalendarWidget QHeaderView::section {\n"
"    background-color: #f9f9f9; /* Change this to fix the black background of the headers */\n"
"    color: #A1"
                        "B19E;           /* Change this for the color of \"lun, mar...\" and week numbers */\n"
"    padding: 3px;\n"
"    border: none;\n"
"}\n"
"\n"
"/* --- 5. THE CALENDAR GRID (The Day Numbers) --- */\n"
"QCalendarWidget QAbstractItemView {\n"
"    background-color: #ffffff; /* Change this for the background of the date grid */\n"
"    color: #333333;           /* Change this for the color of the numbers */\n"
"    selection-background-color: #A1B19E; /* Color when you click a date */\n"
"    selection-color: #ffffff;           /* Text color of the selected date */\n"
"    outline: none;\n"
"}\n"
"\n"
"/* --- 6. WEEKEND COLORING (Optional) --- */\n"
"/* This targets specific colors for Saturday and Sunday if you want them different */\n"
"QCalendarWidget QAbstractItemView:disabled { \n"
"    color: #dcdcdc; /* Color for days outside the current month */\n"
"}"));
        calendarWidget->setGridVisible(false);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(false);
        stackedWidget->addWidget(page_plannification);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget->addWidget(page_6);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "gestion des \303\251quipes", nullptr));
        label->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "   EMPLOY\303\211", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "   EQUIPE", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "   CLIENT", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "   LABORATOIRE", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "   COMMANDE", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "   MACHINE", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "fichier", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "\303\251dition", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "affichage", nullptr));
        Recherche->setText(QCoreApplication::translate("MainWindow", "Gestion", nullptr));
        stats->setText(QCoreApplication::translate("MainWindow", "Statistique ", nullptr));
        planns->setText(QCoreApplication::translate("MainWindow", "plannification", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "recherche des equipes par ID, NOM, CHEF, ETAT ...", nullptr));
        pushButton_19->setText(QCoreApplication::translate("MainWindow", "filtre", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID \303\211quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Membres", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Chef ", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\303\251tat d' \303\251quipe", nullptr));
        pushButton_20->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "modifi\303\251", nullptr));
        pushButton_22->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Gestion des \303\251quipe", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "   Tri des \303\251quipes", nullptr));
        pushButton_23->setText(QCoreApplication::translate("MainWindow", "trier par", nullptr));
        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "ordre", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Nom chef", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Specialit\303\251", nullptr));

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Notes & \303\211valuations", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "performance", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "R\303\251ussites  & Objectifs", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Vitesse de Broyage", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "liste des mission r\303\251ussite", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        label_13->setText(QCoreApplication::translate("MainWindow", "effectif:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "rendement:", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "effectif:", nullptr));
        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "recherche des equipes par ID, NOM, CHEF, ETAT ...pour inspecter son emploi", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "search", nullptr));

        const bool __sortingEnabled1 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(0);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "task list", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled1);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
