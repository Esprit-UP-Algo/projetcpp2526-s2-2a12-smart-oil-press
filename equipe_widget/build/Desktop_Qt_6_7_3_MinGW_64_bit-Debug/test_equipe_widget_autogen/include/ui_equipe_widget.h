/********************************************************************************
** Form generated from reading UI file 'equipe_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EQUIPE_WIDGET_H
#define UI_EQUIPE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainContainerLayout;
    QFrame *topBar;
    QHBoxLayout *mainLayout;
    QFrame *navFrame;
    QVBoxLayout *navLayout;
    QLabel *logoLabel;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_5;
    QPushButton *pushButton_7;
    QPushButton *pushButton;
    QSpacerItem *navSpacer;
    QPushButton *quitButton;
    QFrame *contentFrame;
    QVBoxLayout *contentLayout;
    QTabWidget *topNavTabs;
    QWidget *tabAjouter;
    QWidget *tabGestion;
    QWidget *tabSupprimer;
    QWidget *tabModifier;
    QWidget *tabStatistique;
    QWidget *tabSuggestion;
    QWidget *tabPlanification;
    QStackedWidget *stackedWidget;
    QWidget *page_rech;
    QVBoxLayout *rechLayout;
    QHBoxLayout *rechTopLayout;
    QLineEdit *lineEdit;
    QPushButton *btnFiltre;
    QSpacerItem *searchSpacer;
    QPushButton *btnRechercher;
    QHBoxLayout *rechMainLayout;
    QFrame *frame_4;
    QVBoxLayout *frame4Layout;
    QLabel *label_7;
    QPushButton *btnTrier;
    QComboBox *comboBox_2;
    QHBoxLayout *sortOptionsLayout;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QSpacerItem *frame4Spacer;
    QTableWidget *tableWidget;
    QWidget *page_stat;
    QVBoxLayout *statLayout;
    QLabel *statTitle;
    QHBoxLayout *statsContentLayout;
    QGroupBox *performanceGroup;
    QVBoxLayout *vboxLayout;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *vitesseGroup;
    QVBoxLayout *vboxLayout1;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *statsSecondRowLayout;
    QGroupBox *objectifsGroup;
    QVBoxLayout *vboxLayout2;
    QListWidget *listWidget_2;
    QGroupBox *evalGroup;
    QVBoxLayout *vboxLayout3;
    QPlainTextEdit *plainTextEdit_3;
    QHBoxLayout *exportLayout;
    QSpacerItem *exportSpacer;
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
    QWidget *page_planification;
    QVBoxLayout *planLayout;
    QHBoxLayout *planSearchLayout;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_24;
    QHBoxLayout *planContentLayout;
    QCalendarWidget *calendarWidget;
    QFrame *taskFrame;
    QVBoxLayout *taskLayout;
    QLabel *taskLabel;
    QListWidget *listWidget;
    QWidget *pageadd;
    QVBoxLayout *addLayout;
    QLabel *addTitle;
    QFrame *addFormFrame;
    QFormLayout *addFormLayout;
    QLabel *label_30;
    QLineEdit *lineEdit_5;
    QLabel *label_31;
    QLineEdit *lineEdit_6;
    QLabel *label_32;
    QComboBox *comboBox_7;
    QLabel *label_33;
    QComboBox *comboBox_8;
    QSpacerItem *addSpacer;
    QHBoxLayout *addActionLayout;
    QSpacerItem *addActionSpacer;
    QPushButton *pushButton_28;
    QWidget *pagemodif;
    QVBoxLayout *modifLayout;
    QLabel *modifTitle;
    QFrame *modifFormFrame;
    QFormLayout *modifFormLayout;
    QLabel *label_35;
    QLineEdit *lineEdit_7;
    QLabel *label_36;
    QLineEdit *lineEdit_8;
    QLabel *label_37;
    QComboBox *comboBox_9;
    QLabel *label_38;
    QComboBox *comboBox_10;
    QLabel *label_39;
    QComboBox *comboBox_11;
    QLabel *label_40;
    QComboBox *comboBox_12;
    QSpacerItem *modifSpacer;
    QHBoxLayout *modifActionLayout;
    QSpacerItem *modifActionSpacer;
    QPushButton *pushButton_34;
    QWidget *pagesupp;
    QVBoxLayout *suppLayout;
    QLabel *suppTitle;
    QFrame *suppFormFrame;
    QVBoxLayout *suppFormLayout;
    QLabel *suppWarning;
    QHBoxLayout *suppIdLayout;
    QLabel *label_42;
    QLineEdit *lineEdit_9;
    QSpacerItem *suppSpacer;
    QHBoxLayout *suppActionLayout;
    QSpacerItem *suppActionSpacer;
    QPushButton *pushButton_30;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1600, 900);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainContainerLayout = new QVBoxLayout(centralwidget);
        mainContainerLayout->setSpacing(12);
        mainContainerLayout->setObjectName("mainContainerLayout");
        mainContainerLayout->setContentsMargins(0, 0, 0, 0);
        topBar = new QFrame(centralwidget);
        topBar->setObjectName("topBar");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topBar->sizePolicy().hasHeightForWidth());
        topBar->setSizePolicy(sizePolicy);
        topBar->setMinimumSize(QSize(0, 30));
        topBar->setMaximumSize(QSize(16777215, 30));

        mainContainerLayout->addWidget(topBar);

        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(12);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(10, 10, 10, 10);
        navFrame = new QFrame(centralwidget);
        navFrame->setObjectName("navFrame");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(navFrame->sizePolicy().hasHeightForWidth());
        navFrame->setSizePolicy(sizePolicy1);
        navFrame->setMinimumSize(QSize(220, 0));
        navFrame->setMaximumSize(QSize(220, 16777215));
        navLayout = new QVBoxLayout(navFrame);
        navLayout->setSpacing(12);
        navLayout->setObjectName("navLayout");
        navLayout->setAlignment(Qt::AlignTop);
        navLayout->setContentsMargins(0, 15, 0, 15);
        logoLabel = new QLabel(navFrame);
        logoLabel->setObjectName("logoLabel");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(logoLabel->sizePolicy().hasHeightForWidth());
        logoLabel->setSizePolicy(sizePolicy2);
        logoLabel->setMinimumSize(QSize(0, 80));
        logoLabel->setMaximumSize(QSize(160, 80));
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logoLabel->setScaledContents(true);
        logoLabel->setAlignment(Qt::AlignCenter);
        logoLabel->setAlignment(Qt::AlignCenter);

        navLayout->addWidget(logoLabel, 0, Qt::AlignHCenter);

        pushButton_3 = new QPushButton(navFrame);
        pushButton_3->setObjectName("pushButton_3");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy3);
        pushButton_3->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(navFrame);
        pushButton_4->setObjectName("pushButton_4");
        sizePolicy3.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy3);
        pushButton_4->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(pushButton_4);

        pushButton_6 = new QPushButton(navFrame);
        pushButton_6->setObjectName("pushButton_6");
        sizePolicy3.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy3);
        pushButton_6->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(pushButton_6);

        pushButton_5 = new QPushButton(navFrame);
        pushButton_5->setObjectName("pushButton_5");
        sizePolicy3.setHeightForWidth(pushButton_5->sizePolicy().hasHeightForWidth());
        pushButton_5->setSizePolicy(sizePolicy3);
        pushButton_5->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(pushButton_5);

        pushButton_7 = new QPushButton(navFrame);
        pushButton_7->setObjectName("pushButton_7");
        sizePolicy3.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy3);
        pushButton_7->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(pushButton_7);

        pushButton = new QPushButton(navFrame);
        pushButton->setObjectName("pushButton");
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(pushButton);

        navSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        navLayout->addItem(navSpacer);

        quitButton = new QPushButton(navFrame);
        quitButton->setObjectName("quitButton");
        sizePolicy3.setHeightForWidth(quitButton->sizePolicy().hasHeightForWidth());
        quitButton->setSizePolicy(sizePolicy3);
        quitButton->setMinimumSize(QSize(0, 40));

        navLayout->addWidget(quitButton);


        mainLayout->addWidget(navFrame);

        contentFrame = new QFrame(centralwidget);
        contentFrame->setObjectName("contentFrame");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(1);
        sizePolicy4.setHeightForWidth(contentFrame->sizePolicy().hasHeightForWidth());
        contentFrame->setSizePolicy(sizePolicy4);
        contentLayout = new QVBoxLayout(contentFrame);
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        topNavTabs = new QTabWidget(contentFrame);
        topNavTabs->setObjectName("topNavTabs");
        sizePolicy3.setHeightForWidth(topNavTabs->sizePolicy().hasHeightForWidth());
        topNavTabs->setSizePolicy(sizePolicy3);
        topNavTabs->setMinimumSize(QSize(0, 50));
        topNavTabs->setMaximumSize(QSize(16777215, 50));
        tabAjouter = new QWidget();
        tabAjouter->setObjectName("tabAjouter");
        topNavTabs->addTab(tabAjouter, QString());
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        topNavTabs->addTab(tabGestion, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        topNavTabs->addTab(tabSupprimer, QString());
        tabModifier = new QWidget();
        tabModifier->setObjectName("tabModifier");
        topNavTabs->addTab(tabModifier, QString());
        tabStatistique = new QWidget();
        tabStatistique->setObjectName("tabStatistique");
        topNavTabs->addTab(tabStatistique, QString());
        tabSuggestion = new QWidget();
        tabSuggestion->setObjectName("tabSuggestion");
        topNavTabs->addTab(tabSuggestion, QString());
        tabPlanification = new QWidget();
        tabPlanification->setObjectName("tabPlanification");
        topNavTabs->addTab(tabPlanification, QString());

        contentLayout->addWidget(topNavTabs);

        stackedWidget = new QStackedWidget(contentFrame);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy5.setHorizontalStretch(1);
        sizePolicy5.setVerticalStretch(1);
        sizePolicy5.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy5);
        page_rech = new QWidget();
        page_rech->setObjectName("page_rech");
        rechLayout = new QVBoxLayout(page_rech);
        rechLayout->setSpacing(8);
        rechLayout->setObjectName("rechLayout");
        rechLayout->setContentsMargins(10, 10, 20, 10);
        rechTopLayout = new QHBoxLayout();
        rechTopLayout->setSpacing(8);
        rechTopLayout->setObjectName("rechTopLayout");
        lineEdit = new QLineEdit(page_rech);
        lineEdit->setObjectName("lineEdit");

        rechTopLayout->addWidget(lineEdit);

        btnFiltre = new QPushButton(page_rech);
        btnFiltre->setObjectName("btnFiltre");
        btnFiltre->setMaximumWidth(100);

        rechTopLayout->addWidget(btnFiltre);

        searchSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        rechTopLayout->addItem(searchSpacer);

        btnRechercher = new QPushButton(page_rech);
        btnRechercher->setObjectName("btnRechercher");
        btnRechercher->setMaximumWidth(120);

        rechTopLayout->addWidget(btnRechercher);


        rechLayout->addLayout(rechTopLayout);

        rechMainLayout = new QHBoxLayout();
        rechMainLayout->setSpacing(8);
        rechMainLayout->setObjectName("rechMainLayout");
        frame_4 = new QFrame(page_rech);
        frame_4->setObjectName("frame_4");
        frame4Layout = new QVBoxLayout(frame_4);
        frame4Layout->setSpacing(12);
        frame4Layout->setObjectName("frame4Layout");
        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");

        frame4Layout->addWidget(label_7);

        btnTrier = new QPushButton(frame_4);
        btnTrier->setObjectName("btnTrier");

        frame4Layout->addWidget(btnTrier);

        comboBox_2 = new QComboBox(frame_4);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        frame4Layout->addWidget(comboBox_2);

        sortOptionsLayout = new QHBoxLayout();
        sortOptionsLayout->setObjectName("sortOptionsLayout");
        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName("checkBox_3");

        sortOptionsLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(frame_4);
        checkBox_4->setObjectName("checkBox_4");

        sortOptionsLayout->addWidget(checkBox_4);


        frame4Layout->addLayout(sortOptionsLayout);

        frame4Spacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        frame4Layout->addItem(frame4Spacer);


        rechMainLayout->addWidget(frame_4);

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
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setMinimumSize(QSize(400, 200));
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        rechMainLayout->addWidget(tableWidget);


        rechLayout->addLayout(rechMainLayout);

        stackedWidget->addWidget(page_rech);
        page_stat = new QWidget();
        page_stat->setObjectName("page_stat");
        statLayout = new QVBoxLayout(page_stat);
        statLayout->setObjectName("statLayout");
        statTitle = new QLabel(page_stat);
        statTitle->setObjectName("statTitle");

        statLayout->addWidget(statTitle);

        statsContentLayout = new QHBoxLayout();
        statsContentLayout->setObjectName("statsContentLayout");
        performanceGroup = new QGroupBox(page_stat);
        performanceGroup->setObjectName("performanceGroup");
        vboxLayout = new QVBoxLayout(performanceGroup);
        vboxLayout->setObjectName("vboxLayout");
        plainTextEdit = new QPlainTextEdit(performanceGroup);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setReadOnly(true);

        vboxLayout->addWidget(plainTextEdit);


        statsContentLayout->addWidget(performanceGroup);

        vitesseGroup = new QGroupBox(page_stat);
        vitesseGroup->setObjectName("vitesseGroup");
        vboxLayout1 = new QVBoxLayout(vitesseGroup);
        vboxLayout1->setObjectName("vboxLayout1");
        plainTextEdit_2 = new QPlainTextEdit(vitesseGroup);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setReadOnly(true);

        vboxLayout1->addWidget(plainTextEdit_2);


        statsContentLayout->addWidget(vitesseGroup);


        statLayout->addLayout(statsContentLayout);

        statsSecondRowLayout = new QHBoxLayout();
        statsSecondRowLayout->setObjectName("statsSecondRowLayout");
        objectifsGroup = new QGroupBox(page_stat);
        objectifsGroup->setObjectName("objectifsGroup");
        vboxLayout2 = new QVBoxLayout(objectifsGroup);
        vboxLayout2->setObjectName("vboxLayout2");
        listWidget_2 = new QListWidget(objectifsGroup);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName("listWidget_2");

        vboxLayout2->addWidget(listWidget_2);


        statsSecondRowLayout->addWidget(objectifsGroup);

        evalGroup = new QGroupBox(page_stat);
        evalGroup->setObjectName("evalGroup");
        vboxLayout3 = new QVBoxLayout(evalGroup);
        vboxLayout3->setObjectName("vboxLayout3");
        plainTextEdit_3 = new QPlainTextEdit(evalGroup);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setReadOnly(true);

        vboxLayout3->addWidget(plainTextEdit_3);


        statsSecondRowLayout->addWidget(evalGroup);


        statLayout->addLayout(statsSecondRowLayout);

        exportLayout = new QHBoxLayout();
        exportLayout->setObjectName("exportLayout");
        exportSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        exportLayout->addItem(exportSpacer);

        pushButton_25 = new QPushButton(page_stat);
        pushButton_25->setObjectName("pushButton_25");
        pushButton_25->setMaximumWidth(150);

        exportLayout->addWidget(pushButton_25);


        statLayout->addLayout(exportLayout);

        stackedWidget->addWidget(page_stat);
        sugg = new QWidget();
        sugg->setObjectName("sugg");
        frame_6 = new QFrame(sugg);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 10, 1271, 711));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 260, 81, 51));
        label_17 = new QLabel(frame_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(530, 0, 331, 51));
        pushButton_29 = new QPushButton(frame_6);
        pushButton_29->setObjectName("pushButton_29");
        pushButton_29->setGeometry(QRect(50, 580, 441, 41));
        checkBox_5 = new QCheckBox(frame_6);
        checkBox_5->setObjectName("checkBox_5");
        checkBox_5->setGeometry(QRect(20, 460, 221, 51));
        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 100, 141, 41));
        comboBox_3 = new QComboBox(frame_6);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName("comboBox_3");
        comboBox_3->setGeometry(QRect(145, 100, 321, 44));
        label_19 = new QLabel(frame_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 160, 571, 41));
        lineEdit_3 = new QLineEdit(frame_6);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(10, 220, 584, 31));
        checkBox_7 = new QCheckBox(frame_6);
        checkBox_7->setObjectName("checkBox_7");
        checkBox_7->setGeometry(QRect(20, 330, 101, 51));
        checkBox_8 = new QCheckBox(frame_6);
        checkBox_8->setObjectName("checkBox_8");
        checkBox_8->setGeometry(QRect(140, 330, 121, 51));
        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 380, 231, 51));
        listWidget_3 = new QListWidget(frame_6);
        new QListWidgetItem(listWidget_3);
        listWidget_3->setObjectName("listWidget_3");
        listWidget_3->setGeometry(QRect(730, 100, 531, 601));
        line_3 = new QFrame(frame_6);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(680, 50, 16, 661));
        line_3->setFrameShape(QFrame::Shape::VLine);
        line_3->setFrameShadow(QFrame::Shadow::Sunken);
        label_25 = new QLabel(frame_6);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(920, 50, 121, 41));
        comboBox_5 = new QComboBox(frame_6);
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->addItem(QString());
        comboBox_5->setObjectName("comboBox_5");
        comboBox_5->setGeometry(QRect(145, 380, 321, 44));
        stackedWidget->addWidget(sugg);
        page_planification = new QWidget();
        page_planification->setObjectName("page_planification");
        planLayout = new QVBoxLayout(page_planification);
        planLayout->setSpacing(8);
        planLayout->setObjectName("planLayout");
        planSearchLayout = new QHBoxLayout();
        planSearchLayout->setSpacing(4);
        planSearchLayout->setObjectName("planSearchLayout");
        lineEdit_2 = new QLineEdit(page_planification);
        lineEdit_2->setObjectName("lineEdit_2");

        planSearchLayout->addWidget(lineEdit_2);

        pushButton_24 = new QPushButton(page_planification);
        pushButton_24->setObjectName("pushButton_24");
        pushButton_24->setMinimumSize(QSize(120, 0));
        pushButton_24->setMaximumSize(QSize(150, 16777215));

        planSearchLayout->addWidget(pushButton_24);


        planLayout->addLayout(planSearchLayout);

        planContentLayout = new QHBoxLayout();
        planContentLayout->setSpacing(8);
        planContentLayout->setObjectName("planContentLayout");
        calendarWidget = new QCalendarWidget(page_planification);
        calendarWidget->setObjectName("calendarWidget");
        sizePolicy5.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy5);
        calendarWidget->setMinimumSize(QSize(400, 400));

        planContentLayout->addWidget(calendarWidget);

        taskFrame = new QFrame(page_planification);
        taskFrame->setObjectName("taskFrame");
        sizePolicy5.setHeightForWidth(taskFrame->sizePolicy().hasHeightForWidth());
        taskFrame->setSizePolicy(sizePolicy5);
        taskFrame->setMinimumSize(QSize(300, 400));
        taskLayout = new QVBoxLayout(taskFrame);
        taskLayout->setSpacing(4);
        taskLayout->setObjectName("taskLayout");
        taskLabel = new QLabel(taskFrame);
        taskLabel->setObjectName("taskLabel");

        taskLayout->addWidget(taskLabel);

        listWidget = new QListWidget(taskFrame);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        sizePolicy4.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy4);

        taskLayout->addWidget(listWidget);


        planContentLayout->addWidget(taskFrame);


        planLayout->addLayout(planContentLayout);

        stackedWidget->addWidget(page_planification);
        pageadd = new QWidget();
        pageadd->setObjectName("pageadd");
        addLayout = new QVBoxLayout(pageadd);
        addLayout->setObjectName("addLayout");
        addTitle = new QLabel(pageadd);
        addTitle->setObjectName("addTitle");

        addLayout->addWidget(addTitle);

        addFormFrame = new QFrame(pageadd);
        addFormFrame->setObjectName("addFormFrame");
        addFormLayout = new QFormLayout(addFormFrame);
        addFormLayout->setObjectName("addFormLayout");
        label_30 = new QLabel(addFormFrame);
        label_30->setObjectName("label_30");

        addFormLayout->setWidget(0, QFormLayout::LabelRole, label_30);

        lineEdit_5 = new QLineEdit(addFormFrame);
        lineEdit_5->setObjectName("lineEdit_5");

        addFormLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_5);

        label_31 = new QLabel(addFormFrame);
        label_31->setObjectName("label_31");

        addFormLayout->setWidget(1, QFormLayout::LabelRole, label_31);

        lineEdit_6 = new QLineEdit(addFormFrame);
        lineEdit_6->setObjectName("lineEdit_6");

        addFormLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_6);

        label_32 = new QLabel(addFormFrame);
        label_32->setObjectName("label_32");

        addFormLayout->setWidget(2, QFormLayout::LabelRole, label_32);

        comboBox_7 = new QComboBox(addFormFrame);
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->addItem(QString());
        comboBox_7->setObjectName("comboBox_7");

        addFormLayout->setWidget(2, QFormLayout::FieldRole, comboBox_7);

        label_33 = new QLabel(addFormFrame);
        label_33->setObjectName("label_33");

        addFormLayout->setWidget(3, QFormLayout::LabelRole, label_33);

        comboBox_8 = new QComboBox(addFormFrame);
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

        addFormLayout->setWidget(3, QFormLayout::FieldRole, comboBox_8);


        addLayout->addWidget(addFormFrame);

        addSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        addLayout->addItem(addSpacer);

        addActionLayout = new QHBoxLayout();
        addActionLayout->setObjectName("addActionLayout");
        addActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        addActionLayout->addItem(addActionSpacer);

        pushButton_28 = new QPushButton(pageadd);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setMinimumWidth(200);

        addActionLayout->addWidget(pushButton_28);


        addLayout->addLayout(addActionLayout);

        stackedWidget->addWidget(pageadd);
        pagemodif = new QWidget();
        pagemodif->setObjectName("pagemodif");
        modifLayout = new QVBoxLayout(pagemodif);
        modifLayout->setObjectName("modifLayout");
        modifTitle = new QLabel(pagemodif);
        modifTitle->setObjectName("modifTitle");

        modifLayout->addWidget(modifTitle);

        modifFormFrame = new QFrame(pagemodif);
        modifFormFrame->setObjectName("modifFormFrame");
        modifFormLayout = new QFormLayout(modifFormFrame);
        modifFormLayout->setObjectName("modifFormLayout");
        label_35 = new QLabel(modifFormFrame);
        label_35->setObjectName("label_35");

        modifFormLayout->setWidget(0, QFormLayout::LabelRole, label_35);

        lineEdit_7 = new QLineEdit(modifFormFrame);
        lineEdit_7->setObjectName("lineEdit_7");

        modifFormLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_7);

        label_36 = new QLabel(modifFormFrame);
        label_36->setObjectName("label_36");

        modifFormLayout->setWidget(1, QFormLayout::LabelRole, label_36);

        lineEdit_8 = new QLineEdit(modifFormFrame);
        lineEdit_8->setObjectName("lineEdit_8");

        modifFormLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_8);

        label_37 = new QLabel(modifFormFrame);
        label_37->setObjectName("label_37");

        modifFormLayout->setWidget(2, QFormLayout::LabelRole, label_37);

        comboBox_9 = new QComboBox(modifFormFrame);
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->addItem(QString());
        comboBox_9->setObjectName("comboBox_9");

        modifFormLayout->setWidget(2, QFormLayout::FieldRole, comboBox_9);

        label_38 = new QLabel(modifFormFrame);
        label_38->setObjectName("label_38");

        modifFormLayout->setWidget(3, QFormLayout::LabelRole, label_38);

        comboBox_10 = new QComboBox(modifFormFrame);
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

        modifFormLayout->setWidget(3, QFormLayout::FieldRole, comboBox_10);

        label_39 = new QLabel(modifFormFrame);
        label_39->setObjectName("label_39");

        modifFormLayout->setWidget(4, QFormLayout::LabelRole, label_39);

        comboBox_11 = new QComboBox(modifFormFrame);
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->addItem(QString());
        comboBox_11->setObjectName("comboBox_11");

        modifFormLayout->setWidget(4, QFormLayout::FieldRole, comboBox_11);

        label_40 = new QLabel(modifFormFrame);
        label_40->setObjectName("label_40");

        modifFormLayout->setWidget(5, QFormLayout::LabelRole, label_40);

        comboBox_12 = new QComboBox(modifFormFrame);
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

        modifFormLayout->setWidget(5, QFormLayout::FieldRole, comboBox_12);


        modifLayout->addWidget(modifFormFrame);

        modifSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        modifLayout->addItem(modifSpacer);

        modifActionLayout = new QHBoxLayout();
        modifActionLayout->setObjectName("modifActionLayout");
        modifActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        modifActionLayout->addItem(modifActionSpacer);

        pushButton_34 = new QPushButton(pagemodif);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setMinimumWidth(200);

        modifActionLayout->addWidget(pushButton_34);


        modifLayout->addLayout(modifActionLayout);

        stackedWidget->addWidget(pagemodif);
        pagesupp = new QWidget();
        pagesupp->setObjectName("pagesupp");
        suppLayout = new QVBoxLayout(pagesupp);
        suppLayout->setObjectName("suppLayout");
        suppTitle = new QLabel(pagesupp);
        suppTitle->setObjectName("suppTitle");

        suppLayout->addWidget(suppTitle);

        suppFormFrame = new QFrame(pagesupp);
        suppFormFrame->setObjectName("suppFormFrame");
        suppFormLayout = new QVBoxLayout(suppFormFrame);
        suppFormLayout->setObjectName("suppFormLayout");
        suppWarning = new QLabel(suppFormFrame);
        suppWarning->setObjectName("suppWarning");

        suppFormLayout->addWidget(suppWarning);

        suppIdLayout = new QHBoxLayout();
        suppIdLayout->setObjectName("suppIdLayout");
        label_42 = new QLabel(suppFormFrame);
        label_42->setObjectName("label_42");

        suppIdLayout->addWidget(label_42);

        lineEdit_9 = new QLineEdit(suppFormFrame);
        lineEdit_9->setObjectName("lineEdit_9");

        suppIdLayout->addWidget(lineEdit_9);


        suppFormLayout->addLayout(suppIdLayout);

        suppSpacer = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        suppFormLayout->addItem(suppSpacer);

        suppActionLayout = new QHBoxLayout();
        suppActionLayout->setObjectName("suppActionLayout");
        suppActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        suppActionLayout->addItem(suppActionSpacer);

        pushButton_30 = new QPushButton(suppFormFrame);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setMinimumWidth(200);

        suppActionLayout->addWidget(pushButton_30);


        suppFormLayout->addLayout(suppActionLayout);


        suppLayout->addWidget(suppFormFrame);

        stackedWidget->addWidget(pagesupp);

        contentLayout->addWidget(stackedWidget);


        mainLayout->addWidget(contentFrame);


        mainContainerLayout->addLayout(mainLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        topNavTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        topBar->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame#topBar {\n"
"    background-color: #798777;\n"
"    border: none;\n"
"}", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "   EMPLOY\303\211", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "   EQUIPE", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "   CLIENT", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "   LABORATOIRE", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "   COMMANDE", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "   MACHINE", nullptr));
        quitButton->setText(QCoreApplication::translate("MainWindow", "   QUITTER", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabAjouter), QCoreApplication::translate("MainWindow", "Ajouter une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabGestion), QCoreApplication::translate("MainWindow", "Liste des \303\251quipes", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSupprimer), QCoreApplication::translate("MainWindow", "Supprimer une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabModifier), QCoreApplication::translate("MainWindow", "Modifier une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabStatistique), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSuggestion), QCoreApplication::translate("MainWindow", "Suggestion", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabPlanification), QCoreApplication::translate("MainWindow", "Planification", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "recherche des equipes par ID, NOM, sp\303\251cialit\303\251 ...", nullptr));
        btnFiltre->setText(QCoreApplication::translate("MainWindow", "filtre", nullptr));
        btnRechercher->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "   Tri des \303\251quipes", nullptr));
        btnTrier->setText(QCoreApplication::translate("MainWindow", "trier par", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Nom chef", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Specialit\303\251", nullptr));

        checkBox_3->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        checkBox_4->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
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
        statTitle->setText(QCoreApplication::translate("MainWindow", "Statistiques et Performance", nullptr));
        performanceGroup->setTitle(QCoreApplication::translate("MainWindow", "Performance", nullptr));
        vitesseGroup->setTitle(QCoreApplication::translate("MainWindow", "Vitesse de Traitement", nullptr));
        objectifsGroup->setTitle(QCoreApplication::translate("MainWindow", "R\303\251ussites & Objectifs", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Missions r\303\251ussies", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        evalGroup->setTitle(QCoreApplication::translate("MainWindow", "Notes & \303\211valuations", nullptr));
        pushButton_25->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "cas:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Meilleures Recommandations", nullptr));
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
        lineEdit_3->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer le nombre ici", nullptr));
        checkBox_7->setText(QCoreApplication::translate("MainWindow", "urgent", nullptr));
        checkBox_8->setText(QCoreApplication::translate("MainWindow", "\303\251tat normal", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "difficult\303\251 du cas :", nullptr));

        const bool __sortingEnabled1 = listWidget_3->isSortingEnabled();
        listWidget_3->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_3->item(0);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Recommandations affich\303\251es ici", nullptr));
        listWidget_3->setSortingEnabled(__sortingEnabled1);

        label_25->setText(QCoreApplication::translate("MainWindow", "Resultat", nullptr));
        comboBox_5->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la difficult\303\251 ici ", nullptr));
        comboBox_5->setItemText(1, QCoreApplication::translate("MainWindow", "facile", nullptr));
        comboBox_5->setItemText(2, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBox_5->setItemText(3, QCoreApplication::translate("MainWindow", "Difficile", nullptr));

        lineEdit_2->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher des \303\251quipes par ID, NOM, CHEF, \303\211TAT...", nullptr));
        pushButton_24->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        taskLabel->setText(QCoreApplication::translate("MainWindow", "Liste des T\303\242ches", nullptr));

        const bool __sortingEnabled2 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(0);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "T\303\242ches planifi\303\251es affich\303\251es ici", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled2);

        addTitle->setText(QCoreApplication::translate("MainWindow", "Ajouter une \303\211quipe", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        lineEdit_5->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom de l'\303\251quipe", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Chef:", nullptr));
        lineEdit_6->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez le nom du chef", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251:", nullptr));
        comboBox_7->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner la sp\303\251cialit\303\251", nullptr));
        comboBox_7->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboBox_7->setItemText(2, QCoreApplication::translate("MainWindow", "Production", nullptr));
        comboBox_7->setItemText(3, QCoreApplication::translate("MainWindow", "Back-office", nullptr));
        comboBox_7->setItemText(4, QCoreApplication::translate("MainWindow", "M\303\251canique", nullptr));

        label_33->setText(QCoreApplication::translate("MainWindow", "Nombre de membres:", nullptr));
        comboBox_8->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner le nombre", nullptr));
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

        pushButton_28->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        modifTitle->setText(QCoreApplication::translate("MainWindow", "Modifier une \303\211quipe", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nouveau nom", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Chef:", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez le nouveau chef", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251:", nullptr));
        comboBox_9->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner la sp\303\251cialit\303\251", nullptr));
        comboBox_9->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboBox_9->setItemText(2, QCoreApplication::translate("MainWindow", "Production", nullptr));
        comboBox_9->setItemText(3, QCoreApplication::translate("MainWindow", "Back-office", nullptr));
        comboBox_9->setItemText(4, QCoreApplication::translate("MainWindow", "M\303\251canique", nullptr));

        label_38->setText(QCoreApplication::translate("MainWindow", "Nombre de membres:", nullptr));
        comboBox_10->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner le nombre", nullptr));
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

        label_39->setText(QCoreApplication::translate("MainWindow", "\303\211tat:", nullptr));
        comboBox_11->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner l'\303\251tat", nullptr));
        comboBox_11->setItemText(1, QCoreApplication::translate("MainWindow", "Disponible", nullptr));
        comboBox_11->setItemText(2, QCoreApplication::translate("MainWindow", "Non disponible", nullptr));

        label_40->setText(QCoreApplication::translate("MainWindow", "Note:", nullptr));
        comboBox_12->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner une note (1-10)", nullptr));
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

        pushButton_34->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        suppTitle->setText(QCoreApplication::translate("MainWindow", "Supprimer une \303\211quipe", nullptr));
        suppWarning->setText(QCoreApplication::translate("MainWindow", "Attention: Cette action est irr\303\251versible", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez l'ID de l'\303\251quipe \303\240 supprimer", nullptr));
        pushButton_30->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        (void)MainWindow;
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPE_WIDGET_H
