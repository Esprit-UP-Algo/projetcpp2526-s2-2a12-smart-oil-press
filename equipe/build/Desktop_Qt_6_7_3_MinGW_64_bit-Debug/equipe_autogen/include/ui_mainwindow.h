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
    QPushButton *sugg_2;
    QPushButton *plan;
    QStackedWidget *stackedWidget;
    QWidget *page_rech;
    QLineEdit *lineEdit;
    QPushButton *pushButton_19;
    QTableWidget *tableWidget;
    QFrame *frame_4;
    QPushButton *supprimer;
    QPushButton *pushButton_21;
    QPushButton *ajout;
    QLabel *label_6;
    QLabel *label_7;
    QPushButton *pushButton_23;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QPushButton *pushButton_14;
    QWidget *pagesupp;
    QFrame *frame_9;
    QPushButton *Retour_3;
    QPushButton *pushButton_30;
    QLabel *label_41;
    QLabel *label_42;
    QLineEdit *lineEdit_9;
    QWidget *pageadd;
    QFrame *frame_7;
    QPushButton *Retour;
    QPushButton *pushButton_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QComboBox *comboBox_7;
    QComboBox *comboBox_8;
    QWidget *pagemodif;
    QFrame *frame_8;
    QPushButton *Retour_2;
    QPushButton *pushButton_34;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit_8;
    QComboBox *comboBox_9;
    QComboBox *comboBox_10;
    QLabel *label_39;
    QComboBox *comboBox_11;
    QLabel *label_40;
    QComboBox *comboBox_12;
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
    QLabel *label_26;
    QComboBox *comboBox_6;
    QLabel *label_27;
    QPushButton *pushButton_25;
    QWidget *sugg;
    QFrame *frame_6;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *pushButton_29;
    QCheckBox *checkBox_5;
    QLabel *label_18;
    QComboBox *comboBox_3;
    QLabel *label_19;
    QLineEdit *lineEdit_3;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QLabel *label_24;
    QListWidget *listWidget_3;
    QFrame *line_3;
    QLabel *label_25;
    QComboBox *comboBox_5;
    QWidget *page_plannification;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_24;
    QListWidget *listWidget;
    QCalendarWidget *calendarWidget;
    QWidget *overpage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1541, 868);
        MainWindow->setMinimumSize(QSize(1280, 720));
        MainWindow->setMaximumSize(QSize(16777215, 16777215));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(248, 237, 227);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 50, 201, 781));
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
        frame_2->setGeometry(QRect(0, 0, 1611, 31));
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
        frame_3->setGeometry(QRect(220, 50, 1271, 51));
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgb(161, 177, 158);"));
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayoutWidget_2 = new QWidget(frame_3);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(10, 0, 1221, 51));
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

        sugg_2 = new QPushButton(horizontalLayoutWidget_2);
        sugg_2->setObjectName("sugg_2");
        sugg_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"}"));

        horizontalLayout_2->addWidget(sugg_2);

        plan = new QPushButton(horizontalLayoutWidget_2);
        plan->setObjectName("plan");
        plan->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    color: rgb(248, 237, 227);\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    font: bold 12pt \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: rgba(255, 255, 255, 30);\n"
"}"));

        horizontalLayout_2->addWidget(plan);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(220, 110, 1381, 731));
        page_rech = new QWidget();
        page_rech->setObjectName("page_rech");
        lineEdit = new QLineEdit(page_rech);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 40, 1171, 31));
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
        tableWidget->setGeometry(QRect(290, 90, 911, 641));
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
        frame_4->setGeometry(QRect(0, 90, 271, 641));
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
        supprimer = new QPushButton(frame_4);
        supprimer->setObjectName("supprimer");
        supprimer->setGeometry(QRect(0, 580, 271, 41));
        pushButton_21 = new QPushButton(frame_4);
        pushButton_21->setObjectName("pushButton_21");
        pushButton_21->setGeometry(QRect(0, 530, 271, 41));
        ajout = new QPushButton(frame_4);
        ajout->setObjectName("ajout");
        ajout->setGeometry(QRect(0, 470, 271, 41));
        label_6 = new QLabel(frame_4);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 400, 271, 51));
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
        pushButton_14->setGeometry(QRect(1190, 40, 71, 31));
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
        pagesupp = new QWidget();
        pagesupp->setObjectName("pagesupp");
        frame_9 = new QFrame(pagesupp);
        frame_9->setObjectName("frame_9");
        frame_9->setGeometry(QRect(190, 140, 691, 431));
        frame_9->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        Retour_3 = new QPushButton(frame_9);
        Retour_3->setObjectName("Retour_3");
        Retour_3->setGeometry(QRect(10, 360, 311, 41));
        pushButton_30 = new QPushButton(frame_9);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setGeometry(QRect(360, 360, 311, 41));
        label_41 = new QLabel(frame_9);
        label_41->setObjectName("label_41");
        label_41->setGeometry(QRect(210, 10, 331, 51));
        label_41->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_42 = new QLabel(frame_9);
        label_42->setObjectName("label_42");
        label_42->setGeometry(QRect(30, 140, 61, 41));
        label_42->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        lineEdit_9 = new QLineEdit(frame_9);
        lineEdit_9->setObjectName("lineEdit_9");
        lineEdit_9->setGeometry(QRect(100, 140, 584, 41));
        lineEdit_9->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        stackedWidget->addWidget(pagesupp);
        pageadd = new QWidget();
        pageadd->setObjectName("pageadd");
        frame_7 = new QFrame(pageadd);
        frame_7->setObjectName("frame_7");
        frame_7->setGeometry(QRect(290, 40, 691, 431));
        frame_7->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        Retour = new QPushButton(frame_7);
        Retour->setObjectName("Retour");
        Retour->setGeometry(QRect(10, 360, 311, 41));
        pushButton_28 = new QPushButton(frame_7);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setGeometry(QRect(360, 360, 311, 41));
        label_29 = new QLabel(frame_7);
        label_29->setObjectName("label_29");
        label_29->setGeometry(QRect(210, 10, 301, 51));
        label_29->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_30 = new QLabel(frame_7);
        label_30->setObjectName("label_30");
        label_30->setGeometry(QRect(10, 90, 91, 41));
        label_30->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_31 = new QLabel(frame_7);
        label_31->setObjectName("label_31");
        label_31->setGeometry(QRect(10, 150, 91, 41));
        label_31->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_32 = new QLabel(frame_7);
        label_32->setObjectName("label_32");
        label_32->setGeometry(QRect(10, 210, 171, 41));
        label_32->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_33 = new QLabel(frame_7);
        label_33->setObjectName("label_33");
        label_33->setGeometry(QRect(10, 270, 301, 41));
        label_33->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        lineEdit_5 = new QLineEdit(frame_7);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(100, 90, 584, 41));
        lineEdit_5->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_6 = new QLineEdit(frame_7);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(100, 150, 584, 41));
        lineEdit_6->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        comboBox_7 = new QComboBox(frame_7);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");
        comboBox_7->setGeometry(QRect(190, 210, 321, 44));
        comboBox_7->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        comboBox_8 = new QComboBox(frame_7);
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->addItem(QString());
        comboBox_8->setObjectName("comboBox_8");
        comboBox_8->setGeometry(QRect(320, 270, 321, 44));
        comboBox_8->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        stackedWidget->addWidget(pageadd);
        pagemodif = new QWidget();
        pagemodif->setObjectName("pagemodif");
        frame_8 = new QFrame(pagemodif);
        frame_8->setObjectName("frame_8");
        frame_8->setGeometry(QRect(330, 40, 691, 541));
        frame_8->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        Retour_2 = new QPushButton(frame_8);
        Retour_2->setObjectName("Retour_2");
        Retour_2->setGeometry(QRect(10, 480, 311, 41));
        pushButton_34 = new QPushButton(frame_8);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setGeometry(QRect(360, 480, 311, 41));
        label_34 = new QLabel(frame_8);
        label_34->setObjectName("label_34");
        label_34->setGeometry(QRect(210, 10, 301, 51));
        label_34->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_35 = new QLabel(frame_8);
        label_35->setObjectName("label_35");
        label_35->setGeometry(QRect(10, 90, 91, 41));
        label_35->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_36 = new QLabel(frame_8);
        label_36->setObjectName("label_36");
        label_36->setGeometry(QRect(10, 150, 91, 41));
        label_36->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_37 = new QLabel(frame_8);
        label_37->setObjectName("label_37");
        label_37->setGeometry(QRect(10, 210, 171, 41));
        label_37->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_38 = new QLabel(frame_8);
        label_38->setObjectName("label_38");
        label_38->setGeometry(QRect(10, 290, 301, 41));
        label_38->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        lineEdit_7 = new QLineEdit(frame_8);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(100, 90, 584, 41));
        lineEdit_7->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEdit_8 = new QLineEdit(frame_8);
        lineEdit_8->setObjectName("lineEdit_8");
        lineEdit_8->setGeometry(QRect(100, 150, 584, 41));
        lineEdit_8->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        comboBox_9 = new QComboBox(frame_8);
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->setObjectName("comboBox_9");
        comboBox_9->setGeometry(QRect(190, 210, 321, 44));
        comboBox_9->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        comboBox_10 = new QComboBox(frame_8);
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->addItem(QString());
        comboBox_10->setObjectName("comboBox_10");
        comboBox_10->setGeometry(QRect(320, 290, 321, 44));
        comboBox_10->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        label_39 = new QLabel(frame_8);
        label_39->setObjectName("label_39");
        label_39->setGeometry(QRect(10, 350, 71, 41));
        label_39->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        comboBox_11 = new QComboBox(frame_8);
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName("comboBox_11");
        comboBox_11->setGeometry(QRect(90, 350, 321, 44));
        comboBox_11->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        label_40 = new QLabel(frame_8);
        label_40->setObjectName("label_40");
        label_40->setGeometry(QRect(10, 420, 71, 41));
        label_40->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        comboBox_12 = new QComboBox(frame_8);
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->addItem(QString());
        comboBox_12->setObjectName("comboBox_12");
        comboBox_12->setGeometry(QRect(90, 410, 321, 44));
        comboBox_12->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        stackedWidget->addWidget(pagemodif);
        page_stat = new QWidget();
        page_stat->setObjectName("page_stat");
        frame_5 = new QFrame(page_stat);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(10, 30, 1251, 641));
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
        label_9->setGeometry(QRect(790, 310, 271, 51));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_10 = new QLabel(frame_5);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(190, 0, 271, 51));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        line = new QFrame(frame_5);
        line->setObjectName("line");
        line->setGeometry(QRect(0, 290, 1251, 20));
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        line_2 = new QFrame(frame_5);
        line_2->setObjectName("line_2");
        line_2->setGeometry(QRect(610, 0, 16, 641));
        line_2->setFrameShape(QFrame::Shape::VLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);
        label_11 = new QLabel(frame_5);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(760, 0, 291, 51));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_12 = new QLabel(frame_5);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(180, 310, 271, 51));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        listWidget_2 = new QListWidget(frame_5);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(670, 80, 491, 201));
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
        plainTextEdit->setGeometry(QRect(670, 460, 471, 171));
        plainTextEdit->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #A1B19E; /* Votre vert signature */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    color: #333333;\n"
"}"));
        plainTextEdit_2 = new QPlainTextEdit(frame_5);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(70, 80, 481, 201));
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("QPlainTextEdit {\n"
"    background-color: #ffffff;\n"
"    border: 1px solid #A1B19E; /* Votre vert signature */\n"
"    border-radius: 8px;\n"
"    padding: 10px;\n"
"    color: #333333;\n"
"}"));
        label_13 = new QLabel(frame_5);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(20, 530, 231, 31));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_14 = new QLabel(frame_5);
        label_14->setObjectName("label_14");
        label_14->setGeometry(QRect(20, 480, 231, 31));
        label_14->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_15 = new QLabel(frame_5);
        label_15->setObjectName("label_15");
        label_15->setGeometry(QRect(20, 430, 231, 31));
        label_15->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_26 = new QLabel(frame_5);
        label_26->setObjectName("label_26");
        label_26->setGeometry(QRect(670, 380, 201, 41));
        label_26->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        comboBox_6 = new QComboBox(frame_5);
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->addItem(QString());
        comboBox_6->setObjectName("comboBox_6");
        comboBox_6->setGeometry(QRect(880, 380, 171, 44));
        comboBox_6->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        label_27 = new QLabel(frame_5);
        label_27->setObjectName("label_27");
        label_27->setGeometry(QRect(670, 420, 161, 41));
        label_27->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        pushButton_25 = new QPushButton(page_stat);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setGeometry(QRect(560, 680, 131, 41));
        pushButton_25->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        stackedWidget->addWidget(page_stat);
        sugg = new QWidget();
        sugg->setObjectName("sugg");
        frame_6 = new QFrame(sugg);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 10, 1271, 711));
        frame_6->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 260, 81, 51));
        label_16->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        label_17 = new QLabel(frame_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(530, 0, 331, 51));
        label_17->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        pushButton_29 = new QPushButton(frame_6);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(50, 580, 441, 41));
        pushButton_29->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        checkBox_5 = new QCheckBox(frame_6);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(20, 460, 221, 51));
        checkBox_5->setStyleSheet(QString::fromUtf8("/* The text next to the checkbox */\n"
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
        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 100, 141, 41));
        label_18->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        comboBox_3 = new QComboBox(frame_6);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(160, 100, 321, 44));
        comboBox_3->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        label_19 = new QLabel(frame_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 160, 571, 41));
        label_19->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        lineEdit_3 = new QLineEdit(frame_6);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 220, 584, 31));
        lineEdit_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        checkBox_7 = new QCheckBox(frame_6);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(20, 330, 101, 51));
        checkBox_7->setStyleSheet(QString::fromUtf8("/* The text next to the checkbox */\n"
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
        checkBox_8 = new QCheckBox(frame_6);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setGeometry(QRect(160, 330, 121, 51));
        checkBox_8->setStyleSheet(QString::fromUtf8("/* The text next to the checkbox */\n"
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
        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 380, 231, 51));
        label_24->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        listWidget_3 = new QListWidget(frame_6);
        new QListWidgetItem(listWidget_3);
        listWidget_3->setObjectName("listWidget_3");
        listWidget_3->setGeometry(QRect(730, 100, 531, 601));
        listWidget_3->setStyleSheet(QString::fromUtf8("/* Ensure the list container itself is visible */\n"
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
        line_3 = new QFrame(frame_6);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(680, 50, 16, 661));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        label_25 = new QLabel(frame_6);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(920, 50, 121, 41));
        label_25->setStyleSheet(QString::fromUtf8("color: rgb(121, 135, 119);\n"
"font: 700 italic 16pt \"Segoe UI\";"));
        comboBox_5 = new QComboBox(frame_6);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(250, 380, 321, 44));
        comboBox_5->setStyleSheet(QString::fromUtf8("/* The main box before clicking */\n"
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
"    \n"
"	\n"
"	color: rgb(2, 2, 2);\n"
"    border: 2px solid #A1B19E;\n"
""
                        "    background-color: #ffffff;\n"
"    selection-background-color: #A1B19E; /* Green highlight when hovering */\n"
"    selection-color: #ffffff;\n"
"    outline: none;\n"
"}"));
        stackedWidget->addWidget(sugg);
        page_plannification = new QWidget();
        page_plannification->setObjectName("page_plannification");
        lineEdit_2 = new QLineEdit(page_plannification);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(0, 20, 1141, 31));
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
        pushButton_24->setGeometry(QRect(1150, 20, 71, 31));
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
        listWidget->setGeometry(QRect(650, 60, 571, 641));
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
        calendarWidget->setGeometry(QRect(30, 60, 611, 641));
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
        overpage = new QWidget();
        overpage->setObjectName("overpage");
        stackedWidget->addWidget(overpage);
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
        sugg_2->setText(QCoreApplication::translate("MainWindow", "suggestion", nullptr));
        plan->setText(QCoreApplication::translate("MainWindow", "plannification", nullptr));
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "recherche des equipes par ID, NOM, sp\303\251cialit\303\251 ...", nullptr));
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
        supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        pushButton_21->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        ajout->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
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
        Retour_3->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        label_41->setText(QCoreApplication::translate("MainWindow", "   Supprimer une  \303\251quipe", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEdit_9->setText(QString());
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", " sasir l ID de l'\303\251quipe a supprim\303\251", nullptr));
        Retour->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        pushButton_28->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "   Ajouter une  \303\251quipe", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "nom:", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "chef:", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Specialit\303\251:", nullptr));
        label_33->setText(QCoreApplication::translate("MainWindow", "nombre des membres:", nullptr));
        lineEdit_5->setText(QString());
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", " sasir le nom", nullptr));
        lineEdit_6->setText(QString());
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisir le Nom du chef ", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la specialit\303\251 ICI", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "maintenace", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "production", nullptr));
        comboBox_7->setItemText(3, QCoreApplication::translate("MainWindow", "backoffice", nullptr));
        comboBox_7->setItemText(4, QCoreApplication::translate("MainWindow", "m\303\251canique", nullptr));
        comboBox_7->setItemText(5, QString());

        comboBox_8->setItemText(0, QCoreApplication::translate("MainWindow", "Selectionner le nombre ICI", nullptr));
        comboBox_8->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_8->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_8->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_8->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_8->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_8->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_8->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_8->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_8->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_8->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

        Retour_2->setText(QCoreApplication::translate("MainWindow", "retour", nullptr));
        pushButton_34->setText(QCoreApplication::translate("MainWindow", "modifier", nullptr));
        label_34->setText(QCoreApplication::translate("MainWindow", "   Modifier une  \303\251quipe", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "nom:", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "chef:", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Specialit\303\251:", nullptr));
        label_38->setText(QCoreApplication::translate("MainWindow", "nombre des membres:", nullptr));
        lineEdit_7->setText(QString());
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", " sasir le  nouveau nom", nullptr));
        lineEdit_8->setText(QString());
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisir le nouveau chef ", nullptr));
        comboBox_9->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la specialit\303\251 ICI", nullptr));
        comboBox_9->setItemText(1, QCoreApplication::translate("MainWindow", "maintenace", nullptr));
        comboBox_9->setItemText(2, QCoreApplication::translate("MainWindow", "production", nullptr));
        comboBox_9->setItemText(3, QCoreApplication::translate("MainWindow", "backoffice", nullptr));
        comboBox_9->setItemText(4, QCoreApplication::translate("MainWindow", "m\303\251canique", nullptr));
        comboBox_9->setItemText(5, QString());

        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "Selectionner le nombre ICI", nullptr));
        comboBox_10->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_10->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_10->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_10->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_10->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_10->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_10->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_10->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_10->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_10->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

        label_39->setText(QCoreApplication::translate("MainWindow", "etat", nullptr));
        comboBox_11->setItemText(0, QCoreApplication::translate("MainWindow", "selectionne  l etat", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("MainWindow", "dispo", nullptr));
        comboBox_11->setItemText(2, QCoreApplication::translate("MainWindow", "non dispo", nullptr));

        label_40->setText(QCoreApplication::translate("MainWindow", "rate", nullptr));
        comboBox_12->setItemText(0, QCoreApplication::translate("MainWindow", "1-10", nullptr));
        comboBox_12->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_12->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_12->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_12->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_12->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_12->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_12->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_12->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_12->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_12->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

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
        label_15->setText(QCoreApplication::translate("MainWindow", "dur\303\251e:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "note generale :", nullptr));
        comboBox_6->setItemText(0, QCoreApplication::translate("MainWindow", "De 1 a 10", nullptr));
        comboBox_6->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBox_6->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBox_6->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBox_6->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBox_6->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBox_6->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBox_6->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBox_6->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBox_6->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBox_6->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

        label_27->setText(QCoreApplication::translate("MainWindow", "description : ", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "cas:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Meilleur Recomondation", nullptr));
        pushButton_29->setText(QCoreApplication::translate("MainWindow", "RECHERCHER", nullptr));
        checkBox_5->setText(QCoreApplication::translate("MainWindow", "n\303\251cessite la diponibilit\303\251", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "sp\303\251cialit\303\251:", nullptr));
        comboBox_3->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la specialit\303\251 demand\303\251", nullptr));
        comboBox_3->setItemText(1, QCoreApplication::translate("MainWindow", "maintenace", nullptr));
        comboBox_3->setItemText(2, QCoreApplication::translate("MainWindow", "production", nullptr));
        comboBox_3->setItemText(3, QCoreApplication::translate("MainWindow", "backoffice", nullptr));
        comboBox_3->setItemText(4, QCoreApplication::translate("MainWindow", "m\303\251canique", nullptr));
        comboBox_3->setItemText(5, QString());

        label_19->setText(QCoreApplication::translate("MainWindow", "nombre minimum des individu de l'\303\251quipe :", nullptr));
        lineEdit_3->setText(QString());
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer le nombre ici", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "urgent", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "\303\251tat normal", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "difficult\303\251 du cas :", nullptr));

        const bool __sortingEnabled1 = listWidget_3->isSortingEnabled();
        listWidget_3->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_3->item(0);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "liste des mission r\303\251ussite", nullptr));
        listWidget_3->setSortingEnabled(__sortingEnabled1);

        label_25->setText(QCoreApplication::translate("MainWindow", "Resultat", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la difficult\303\251 ici ", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "facile", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("MainWindow", "Difficile", nullptr));

        lineEdit_2->setText(QString());
        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "recherche des equipes par ID, NOM, CHEF, ETAT ...pour inspecter son emploi", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "search", nullptr));

        const bool __sortingEnabled2 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(0);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "task list", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled2);

    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
