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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewLab;
    QAction *actionNewControl;
    QAction *actionEditControl;
    QAction *actionExportPDF;
    QAction *actionQuit;
    QAction *actionAIAnalyze;
    QAction *actionAISuggest;
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QFrame *navFrame;
    QVBoxLayout *navLayout;
    QLabel *lblLogo;
    QPushButton *sidebarBtnEmploye;
    QPushButton *sidebarBtnEquipe;
    QPushButton *sidebarBtnClient;
    QPushButton *sidebarBtnLaboratoire;
    QPushButton *sidebarBtnCommande;
    QPushButton *sidebarBtnMachine;
    QSpacerItem *navSpacer;
    QHBoxLayout *contentLayout;
    QVBoxLayout *centerLayout;
    QTabWidget *tabWidget;
    QWidget *tabList;
    QVBoxLayout *tabListLayout;
    QTableWidget *tableLaboratoires;
    QWidget *tabDetails;
    QVBoxLayout *tabDetailsLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *scrollLayout;
    QGroupBox *groupBoxInfo;
    QFormLayout *formLayoutInfo;
    QLabel *lblId;
    QLineEdit *detailId;
    QLabel *lblNom;
    QLineEdit *detailName;
    QLabel *lblAddress;
    QLineEdit *detailAddress;
    QLabel *lblType;
    QComboBox *detailType;
    QLabel *lblConform;
    QComboBox *detailConformite;
    QLabel *lblArea;
    QLineEdit *detailSuperficie;
    QLabel *lblNbMach;
    QLineEdit *detailNbMachines;
    QGroupBox *groupBoxDates;
    QFormLayout *formLayoutDates;
    QLabel *lblLast;
    QDateEdit *detailLastControl;
    QLabel *lblNext;
    QDateEdit *detailNextControl;
    QWidget *tabHistory;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *tabStats;
    QVBoxLayout *tabStatsLayout;
    QGroupBox *groupBoxGlobalStats;
    QGridLayout *gridStats;
    QLabel *lblTotLabText;
    QLabel *lblTotalLabs;
    QLabel *lblConfRateText;
    QLabel *lblConformityRate;
    QLabel *lblNonConfText;
    QLabel *lblNonConform;
    QHBoxLayout *buttonsLayout;
    QPushButton *btnAddControl;
    QPushButton *btnExportControl;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBoxStatsByType;
    QVBoxLayout *typeStatsLayout;
    QTextEdit *textStatsByType;
    QWidget *tabAI;
    QVBoxLayout *tabAILayout;
    QLabel *lblAITitle;
    QTextEdit *textAIChat;
    QHBoxLayout *AIControlLayout;
    QLineEdit *lineEditAIQuestion;
    QPushButton *btnSendQuestion;
    QGroupBox *groupBoxAISuggestions;
    QVBoxLayout *AISuggestionsLayout;
    QTextEdit *textAISuggestions;
    QVBoxLayout *rightLayout;
    QGroupBox *groupBoxSearch;
    QVBoxLayout *searchLayout;
    QLineEdit *lineEditQuickSearch;
    QPushButton *btnRecherche;
    QGroupBox *groupBoxActions;
    QVBoxLayout *actionsLayout;
    QPushButton *btnNewLab;
    QPushButton *btnEditLab;
    QPushButton *btnDeleteLab;
    QPushButton *btnAddControlQuick;
    QGroupBox *groupBoxQuickInfo;
    QGridLayout *gridLayout;
    QLabel *lblQuickConf;
    QLabel *quickConformity;
    QLabel *lblQuickLast;
    QLabel *quickLastControl;
    QLabel *lblQuickNext;
    QLabel *quickNextControl;
    QSpacerItem *rightSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1480, 1109);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow { background-color: #F8EDE3; }"));
        actionNewLab = new QAction(MainWindow);
        actionNewLab->setObjectName("actionNewLab");
        actionNewControl = new QAction(MainWindow);
        actionNewControl->setObjectName("actionNewControl");
        actionEditControl = new QAction(MainWindow);
        actionEditControl->setObjectName("actionEditControl");
        actionExportPDF = new QAction(MainWindow);
        actionExportPDF->setObjectName("actionExportPDF");
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        actionAIAnalyze = new QAction(MainWindow);
        actionAIAnalyze->setObjectName("actionAIAnalyze");
        actionAISuggest = new QAction(MainWindow);
        actionAISuggest->setObjectName("actionAISuggest");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        navFrame = new QFrame(centralwidget);
        navFrame->setObjectName("navFrame");
        navFrame->setFrameShape(QFrame::Shape::StyledPanel);
        navFrame->setStyleSheet(QString::fromUtf8("background-color: #798777;"));
        navLayout = new QVBoxLayout(navFrame);
        navLayout->setSpacing(0);
        navLayout->setObjectName("navLayout");
        navLayout->setContentsMargins(0, 0, 0, 0);
        lblLogo = new QLabel(navFrame);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMinimumSize(QSize(200, 120));
        lblLogo->setMaximumSize(QSize(238, 150));
        lblLogo->setStyleSheet(QString::fromUtf8("background-color: #798777; padding: 20px;"));
        lblLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);
        lblLogo->setScaledContents(true);

        navLayout->addWidget(lblLogo);

        sidebarBtnEmploye = new QPushButton(navFrame);
        sidebarBtnEmploye->setObjectName("sidebarBtnEmploye");
        sidebarBtnEmploye->setMinimumSize(QSize(0, 50));
        sidebarBtnEmploye->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border: none;\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}\n"
"QPushButton:checked {\n"
"    background-color: #5A6A56;\n"
"    border-left: 4px solid #FFFFFF;\n"
"}"));
        sidebarBtnEmploye->setCheckable(true);

        navLayout->addWidget(sidebarBtnEmploye);

        sidebarBtnEquipe = new QPushButton(navFrame);
        sidebarBtnEquipe->setObjectName("sidebarBtnEquipe");
        sidebarBtnEquipe->setMinimumSize(QSize(0, 50));
        sidebarBtnEquipe->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border: none;\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}\n"
"QPushButton:checked {\n"
"    background-color: #5A6A56;\n"
"    border-left: 4px solid #FFFFFF;\n"
"}"));
        sidebarBtnEquipe->setCheckable(true);

        navLayout->addWidget(sidebarBtnEquipe);

        sidebarBtnClient = new QPushButton(navFrame);
        sidebarBtnClient->setObjectName("sidebarBtnClient");
        sidebarBtnClient->setMinimumSize(QSize(0, 50));
        sidebarBtnClient->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border: none;\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}\n"
"QPushButton:checked {\n"
"    background-color: #5A6A56;\n"
"    border-left: 4px solid #FFFFFF;\n"
"}"));
        sidebarBtnClient->setCheckable(true);

        navLayout->addWidget(sidebarBtnClient);

        sidebarBtnLaboratoire = new QPushButton(navFrame);
        sidebarBtnLaboratoire->setObjectName("sidebarBtnLaboratoire");
        sidebarBtnLaboratoire->setMinimumSize(QSize(0, 50));
        sidebarBtnLaboratoire->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border: none;\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}\n"
"QPushButton:checked {\n"
"    background-color: #5A6A56;\n"
"    border-left: 4px solid #FFFFFF;\n"
"}"));
        sidebarBtnLaboratoire->setCheckable(true);

        navLayout->addWidget(sidebarBtnLaboratoire);

        sidebarBtnCommande = new QPushButton(navFrame);
        sidebarBtnCommande->setObjectName("sidebarBtnCommande");
        sidebarBtnCommande->setMinimumSize(QSize(0, 50));
        sidebarBtnCommande->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border: none;\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}\n"
"QPushButton:checked {\n"
"    background-color: #5A6A56;\n"
"    border-left: 4px solid #FFFFFF;\n"
"}"));
        sidebarBtnCommande->setCheckable(true);

        navLayout->addWidget(sidebarBtnCommande);

        sidebarBtnMachine = new QPushButton(navFrame);
        sidebarBtnMachine->setObjectName("sidebarBtnMachine");
        sidebarBtnMachine->setMinimumSize(QSize(0, 50));
        sidebarBtnMachine->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"    border: none;\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}\n"
"QPushButton:checked {\n"
"    background-color: #5A6A56;\n"
"    border-left: 4px solid #FFFFFF;\n"
"}"));
        sidebarBtnMachine->setCheckable(true);

        navLayout->addWidget(sidebarBtnMachine);

        navSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        navLayout->addItem(navSpacer);


        mainLayout->addWidget(navFrame);

        contentLayout = new QHBoxLayout();
        contentLayout->setSpacing(20);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(30, 20, 20, 20);
        centerLayout = new QVBoxLayout();
        centerLayout->setSpacing(0);
        centerLayout->setObjectName("centerLayout");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #D1C7B7;\n"
"    background-color: white;\n"
"    border-radius: 4px;\n"
"}\n"
"QTabBar::tab {\n"
"    background-color: #F8EDE3;\n"
"    padding: 10px 20px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 4px;\n"
"    border-top-right-radius: 4px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background-color: white;\n"
"    border-bottom: 2px solid #798777;\n"
"}"));
        tabList = new QWidget();
        tabList->setObjectName("tabList");
        tabListLayout = new QVBoxLayout(tabList);
        tabListLayout->setSpacing(0);
        tabListLayout->setObjectName("tabListLayout");
        tableLaboratoires = new QTableWidget(tabList);
        if (tableLaboratoires->columnCount() < 7)
            tableLaboratoires->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableLaboratoires->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableLaboratoires->setObjectName("tableLaboratoires");
        tableLaboratoires->setMinimumSize(QSize(900, 600));
        tableLaboratoires->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: white;\n"
"    alternate-background-color: #F9F9F9;\n"
"    gridline-color: #E0E0E0;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"}"));
        tableLaboratoires->setAlternatingRowColors(true);
        tableLaboratoires->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableLaboratoires->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableLaboratoires->setShowGrid(true);
        tableLaboratoires->setGridStyle(Qt::PenStyle::SolidLine);
        tableLaboratoires->setSortingEnabled(true);
        tableLaboratoires->setRowCount(0);
        tableLaboratoires->setColumnCount(7);

        tabListLayout->addWidget(tableLaboratoires);

        tabWidget->addTab(tabList, QString());
        tabDetails = new QWidget();
        tabDetails->setObjectName("tabDetails");
        tabDetailsLayout = new QVBoxLayout(tabDetails);
        tabDetailsLayout->setSpacing(10);
        tabDetailsLayout->setObjectName("tabDetailsLayout");
        scrollArea = new QScrollArea(tabDetails);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setStyleSheet(QString::fromUtf8("QScrollArea {\n"
"    border: none;\n"
"    background-color: transparent;\n"
"}"));
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 946, 980));
        scrollLayout = new QVBoxLayout(scrollAreaWidgetContents);
        scrollLayout->setSpacing(15);
        scrollLayout->setObjectName("scrollLayout");
        groupBoxInfo = new QGroupBox(scrollAreaWidgetContents);
        groupBoxInfo->setObjectName("groupBoxInfo");
        groupBoxInfo->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        formLayoutInfo = new QFormLayout(groupBoxInfo);
        formLayoutInfo->setObjectName("formLayoutInfo");
        formLayoutInfo->setHorizontalSpacing(15);
        formLayoutInfo->setVerticalSpacing(10);
        lblId = new QLabel(groupBoxInfo);
        lblId->setObjectName("lblId");

        formLayoutInfo->setWidget(0, QFormLayout::LabelRole, lblId);

        detailId = new QLineEdit(groupBoxInfo);
        detailId->setObjectName("detailId");
        detailId->setReadOnly(true);
        detailId->setStyleSheet(QString::fromUtf8("background-color: #F5F5F5;"));

        formLayoutInfo->setWidget(0, QFormLayout::FieldRole, detailId);

        lblNom = new QLabel(groupBoxInfo);
        lblNom->setObjectName("lblNom");

        formLayoutInfo->setWidget(1, QFormLayout::LabelRole, lblNom);

        detailName = new QLineEdit(groupBoxInfo);
        detailName->setObjectName("detailName");

        formLayoutInfo->setWidget(1, QFormLayout::FieldRole, detailName);

        lblAddress = new QLabel(groupBoxInfo);
        lblAddress->setObjectName("lblAddress");

        formLayoutInfo->setWidget(2, QFormLayout::LabelRole, lblAddress);

        detailAddress = new QLineEdit(groupBoxInfo);
        detailAddress->setObjectName("detailAddress");

        formLayoutInfo->setWidget(2, QFormLayout::FieldRole, detailAddress);

        lblType = new QLabel(groupBoxInfo);
        lblType->setObjectName("lblType");

        formLayoutInfo->setWidget(3, QFormLayout::LabelRole, lblType);

        detailType = new QComboBox(groupBoxInfo);
        detailType->setObjectName("detailType");
        detailType->setStyleSheet(QString::fromUtf8("padding: 5px;"));

        formLayoutInfo->setWidget(3, QFormLayout::FieldRole, detailType);

        lblConform = new QLabel(groupBoxInfo);
        lblConform->setObjectName("lblConform");

        formLayoutInfo->setWidget(4, QFormLayout::LabelRole, lblConform);

        detailConformite = new QComboBox(groupBoxInfo);
        detailConformite->setObjectName("detailConformite");
        detailConformite->setStyleSheet(QString::fromUtf8("padding: 5px;"));

        formLayoutInfo->setWidget(4, QFormLayout::FieldRole, detailConformite);

        lblArea = new QLabel(groupBoxInfo);
        lblArea->setObjectName("lblArea");

        formLayoutInfo->setWidget(5, QFormLayout::LabelRole, lblArea);

        detailSuperficie = new QLineEdit(groupBoxInfo);
        detailSuperficie->setObjectName("detailSuperficie");

        formLayoutInfo->setWidget(5, QFormLayout::FieldRole, detailSuperficie);

        lblNbMach = new QLabel(groupBoxInfo);
        lblNbMach->setObjectName("lblNbMach");

        formLayoutInfo->setWidget(6, QFormLayout::LabelRole, lblNbMach);

        detailNbMachines = new QLineEdit(groupBoxInfo);
        detailNbMachines->setObjectName("detailNbMachines");

        formLayoutInfo->setWidget(6, QFormLayout::FieldRole, detailNbMachines);


        scrollLayout->addWidget(groupBoxInfo);

        groupBoxDates = new QGroupBox(scrollAreaWidgetContents);
        groupBoxDates->setObjectName("groupBoxDates");
        groupBoxDates->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        formLayoutDates = new QFormLayout(groupBoxDates);
        formLayoutDates->setObjectName("formLayoutDates");
        formLayoutDates->setHorizontalSpacing(15);
        formLayoutDates->setVerticalSpacing(10);
        lblLast = new QLabel(groupBoxDates);
        lblLast->setObjectName("lblLast");

        formLayoutDates->setWidget(0, QFormLayout::LabelRole, lblLast);

        detailLastControl = new QDateEdit(groupBoxDates);
        detailLastControl->setObjectName("detailLastControl");
        detailLastControl->setCalendarPopup(true);

        formLayoutDates->setWidget(0, QFormLayout::FieldRole, detailLastControl);

        lblNext = new QLabel(groupBoxDates);
        lblNext->setObjectName("lblNext");

        formLayoutDates->setWidget(1, QFormLayout::LabelRole, lblNext);

        detailNextControl = new QDateEdit(groupBoxDates);
        detailNextControl->setObjectName("detailNextControl");
        detailNextControl->setCalendarPopup(true);

        formLayoutDates->setWidget(1, QFormLayout::FieldRole, detailNextControl);


        scrollLayout->addWidget(groupBoxDates);

        scrollArea->setWidget(scrollAreaWidgetContents);

        tabDetailsLayout->addWidget(scrollArea);

        tabWidget->addTab(tabDetails, QString());
        tabHistory = new QWidget();
        tabHistory->setObjectName("tabHistory");
        verticalLayout = new QVBoxLayout(tabHistory);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(tabHistory);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font-size: 14px; color: #666666; padding: 50px;"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        tabWidget->addTab(tabHistory, QString());
        tabStats = new QWidget();
        tabStats->setObjectName("tabStats");
        tabStatsLayout = new QVBoxLayout(tabStats);
        tabStatsLayout->setSpacing(15);
        tabStatsLayout->setObjectName("tabStatsLayout");
        groupBoxGlobalStats = new QGroupBox(tabStats);
        groupBoxGlobalStats->setObjectName("groupBoxGlobalStats");
        groupBoxGlobalStats->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        gridStats = new QGridLayout(groupBoxGlobalStats);
        gridStats->setSpacing(10);
        gridStats->setObjectName("gridStats");
        lblTotLabText = new QLabel(groupBoxGlobalStats);
        lblTotLabText->setObjectName("lblTotLabText");

        gridStats->addWidget(lblTotLabText, 0, 0, 1, 1);

        lblTotalLabs = new QLabel(groupBoxGlobalStats);
        lblTotalLabs->setObjectName("lblTotalLabs");
        lblTotalLabs->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #798777;"));

        gridStats->addWidget(lblTotalLabs, 0, 1, 1, 1);

        lblConfRateText = new QLabel(groupBoxGlobalStats);
        lblConfRateText->setObjectName("lblConfRateText");

        gridStats->addWidget(lblConfRateText, 1, 0, 1, 1);

        lblConformityRate = new QLabel(groupBoxGlobalStats);
        lblConformityRate->setObjectName("lblConformityRate");
        lblConformityRate->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #4CAF50;"));

        gridStats->addWidget(lblConformityRate, 1, 1, 1, 1);

        lblNonConfText = new QLabel(groupBoxGlobalStats);
        lblNonConfText->setObjectName("lblNonConfText");

        gridStats->addWidget(lblNonConfText, 2, 0, 1, 1);

        lblNonConform = new QLabel(groupBoxGlobalStats);
        lblNonConform->setObjectName("lblNonConform");
        lblNonConform->setStyleSheet(QString::fromUtf8("font-size: 18px; font-weight: bold; color: #F44336;"));

        gridStats->addWidget(lblNonConform, 2, 1, 1, 1);


        tabStatsLayout->addWidget(groupBoxGlobalStats);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(10);
        buttonsLayout->setObjectName("buttonsLayout");
        btnAddControl = new QPushButton(tabStats);
        btnAddControl->setObjectName("btnAddControl");
        btnAddControl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}"));

        buttonsLayout->addWidget(btnAddControl);

        btnExportControl = new QPushButton(tabStats);
        btnExportControl->setObjectName("btnExportControl");
        btnExportControl->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5D737E;\n"
"    color: white;\n"
"    padding: 10px 20px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4C626E;\n"
"}"));

        buttonsLayout->addWidget(btnExportControl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonsLayout->addItem(horizontalSpacer);


        tabStatsLayout->addLayout(buttonsLayout);

        groupBoxStatsByType = new QGroupBox(tabStats);
        groupBoxStatsByType->setObjectName("groupBoxStatsByType");
        groupBoxStatsByType->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        typeStatsLayout = new QVBoxLayout(groupBoxStatsByType);
        typeStatsLayout->setSpacing(8);
        typeStatsLayout->setObjectName("typeStatsLayout");
        textStatsByType = new QTextEdit(groupBoxStatsByType);
        textStatsByType->setObjectName("textStatsByType");
        textStatsByType->setReadOnly(true);
        textStatsByType->setStyleSheet(QString::fromUtf8("background-color: #F9F9F9; padding: 10px; border-radius: 4px;"));

        typeStatsLayout->addWidget(textStatsByType);


        tabStatsLayout->addWidget(groupBoxStatsByType);

        tabWidget->addTab(tabStats, QString());
        tabAI = new QWidget();
        tabAI->setObjectName("tabAI");
        tabAILayout = new QVBoxLayout(tabAI);
        tabAILayout->setSpacing(0);
        tabAILayout->setObjectName("tabAILayout");
        lblAITitle = new QLabel(tabAI);
        lblAITitle->setObjectName("lblAITitle");
        lblAITitle->setMinimumSize(QSize(0, 60));
        lblAITitle->setStyleSheet(QString::fromUtf8("background-color: #798777; color: white; padding: 15px; font-size: 16px;"));
        lblAITitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        tabAILayout->addWidget(lblAITitle);

        textAIChat = new QTextEdit(tabAI);
        textAIChat->setObjectName("textAIChat");
        textAIChat->setMinimumSize(QSize(0, 150));
        textAIChat->setReadOnly(true);
        textAIChat->setStyleSheet(QString::fromUtf8("background-color: #F9F9F9; padding: 15px; border: none;"));

        tabAILayout->addWidget(textAIChat);

        AIControlLayout = new QHBoxLayout();
        AIControlLayout->setSpacing(10);
        AIControlLayout->setObjectName("AIControlLayout");
        AIControlLayout->setContentsMargins(15, 10, 15, 10);
        lineEditAIQuestion = new QLineEdit(tabAI);
        lineEditAIQuestion->setObjectName("lineEditAIQuestion");
        lineEditAIQuestion->setStyleSheet(QString::fromUtf8("padding: 10px; border: 1px solid #D1C7B7; border-radius: 4px;"));

        AIControlLayout->addWidget(lineEditAIQuestion);

        btnSendQuestion = new QPushButton(tabAI);
        btnSendQuestion->setObjectName("btnSendQuestion");
        btnSendQuestion->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    padding: 10px 25px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}"));

        AIControlLayout->addWidget(btnSendQuestion);


        tabAILayout->addLayout(AIControlLayout);

        groupBoxAISuggestions = new QGroupBox(tabAI);
        groupBoxAISuggestions->setObjectName("groupBoxAISuggestions");
        groupBoxAISuggestions->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        AISuggestionsLayout = new QVBoxLayout(groupBoxAISuggestions);
        AISuggestionsLayout->setSpacing(8);
        AISuggestionsLayout->setObjectName("AISuggestionsLayout");
        textAISuggestions = new QTextEdit(groupBoxAISuggestions);
        textAISuggestions->setObjectName("textAISuggestions");
        textAISuggestions->setReadOnly(true);
        textAISuggestions->setStyleSheet(QString::fromUtf8("background-color: #F9F9F9; padding: 10px; border-radius: 4px;"));

        AISuggestionsLayout->addWidget(textAISuggestions);


        tabAILayout->addWidget(groupBoxAISuggestions);

        tabWidget->addTab(tabAI, QString());

        centerLayout->addWidget(tabWidget);


        contentLayout->addLayout(centerLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setSpacing(20);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, -1, -1);
        groupBoxSearch = new QGroupBox(centralwidget);
        groupBoxSearch->setObjectName("groupBoxSearch");
        groupBoxSearch->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        searchLayout = new QVBoxLayout(groupBoxSearch);
        searchLayout->setSpacing(10);
        searchLayout->setObjectName("searchLayout");
        lineEditQuickSearch = new QLineEdit(groupBoxSearch);
        lineEditQuickSearch->setObjectName("lineEditQuickSearch");
        lineEditQuickSearch->setClearButtonEnabled(true);
        lineEditQuickSearch->setStyleSheet(QString::fromUtf8("padding: 10px; border: 1px solid #D1C7B7; border-radius: 4px;"));

        searchLayout->addWidget(lineEditQuickSearch);

        btnRecherche = new QPushButton(groupBoxSearch);
        btnRecherche->setObjectName("btnRecherche");
        btnRecherche->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    padding: 10px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}"));

        searchLayout->addWidget(btnRecherche);


        rightLayout->addWidget(groupBoxSearch);

        groupBoxActions = new QGroupBox(centralwidget);
        groupBoxActions->setObjectName("groupBoxActions");
        groupBoxActions->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        actionsLayout = new QVBoxLayout(groupBoxActions);
        actionsLayout->setSpacing(8);
        actionsLayout->setObjectName("actionsLayout");
        btnNewLab = new QPushButton(groupBoxActions);
        btnNewLab->setObjectName("btnNewLab");
        btnNewLab->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}"));

        actionsLayout->addWidget(btnNewLab);

        btnEditLab = new QPushButton(groupBoxActions);
        btnEditLab->setObjectName("btnEditLab");
        btnEditLab->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #5D737E;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #4C626E;\n"
"}"));

        actionsLayout->addWidget(btnEditLab);

        btnDeleteLab = new QPushButton(groupBoxActions);
        btnDeleteLab->setObjectName("btnDeleteLab");
        btnDeleteLab->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #B05454;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #9E4444;\n"
"}"));

        actionsLayout->addWidget(btnDeleteLab);

        btnAddControlQuick = new QPushButton(groupBoxActions);
        btnAddControlQuick->setObjectName("btnAddControlQuick");
        btnAddControlQuick->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #798777;\n"
"    color: white;\n"
"    padding: 12px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"    text-align: left;\n"
"    padding-left: 20px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #6A7A66;\n"
"}"));

        actionsLayout->addWidget(btnAddControlQuick);


        rightLayout->addWidget(groupBoxActions);

        groupBoxQuickInfo = new QGroupBox(centralwidget);
        groupBoxQuickInfo->setObjectName("groupBoxQuickInfo");
        groupBoxQuickInfo->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #798777;\n"
"    border-radius: 8px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"}\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 10px 0 10px;\n"
"}"));
        gridLayout = new QGridLayout(groupBoxQuickInfo);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(12);
        lblQuickConf = new QLabel(groupBoxQuickInfo);
        lblQuickConf->setObjectName("lblQuickConf");

        gridLayout->addWidget(lblQuickConf, 0, 0, 1, 1);

        quickConformity = new QLabel(groupBoxQuickInfo);
        quickConformity->setObjectName("quickConformity");
        quickConformity->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #798777;"));

        gridLayout->addWidget(quickConformity, 0, 1, 1, 1);

        lblQuickLast = new QLabel(groupBoxQuickInfo);
        lblQuickLast->setObjectName("lblQuickLast");

        gridLayout->addWidget(lblQuickLast, 1, 0, 1, 1);

        quickLastControl = new QLabel(groupBoxQuickInfo);
        quickLastControl->setObjectName("quickLastControl");
        quickLastControl->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #5D737E;"));

        gridLayout->addWidget(quickLastControl, 1, 1, 1, 1);

        lblQuickNext = new QLabel(groupBoxQuickInfo);
        lblQuickNext->setObjectName("lblQuickNext");

        gridLayout->addWidget(lblQuickNext, 2, 0, 1, 1);

        quickNextControl = new QLabel(groupBoxQuickInfo);
        quickNextControl->setObjectName("quickNextControl");
        quickNextControl->setStyleSheet(QString::fromUtf8("font-weight: bold; color: #4CAF50;"));

        gridLayout->addWidget(quickNextControl, 2, 1, 1, 1);


        rightLayout->addWidget(groupBoxQuickInfo);

        rightSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightLayout->addItem(rightSpacer);


        contentLayout->addLayout(rightLayout);


        mainLayout->addLayout(contentLayout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        statusbar->setStyleSheet(QString::fromUtf8("background-color: #798777; color: white;"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion de Laboratoire - Contr\303\264les Qualit\303\251", nullptr));
        actionNewLab->setText(QCoreApplication::translate("MainWindow", "&Nouveau Laboratoire", nullptr));
#if QT_CONFIG(shortcut)
        actionNewLab->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNewControl->setText(QCoreApplication::translate("MainWindow", "&Nouveau Contr\303\264le Qualit\303\251", nullptr));
#if QT_CONFIG(shortcut)
        actionNewControl->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEditControl->setText(QCoreApplication::translate("MainWindow", "&Modifier Contr\303\264le", nullptr));
#if QT_CONFIG(shortcut)
        actionEditControl->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportPDF->setText(QCoreApplication::translate("MainWindow", "&Exporter Rapport PDF", nullptr));
#if QT_CONFIG(shortcut)
        actionExportPDF->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionQuit->setText(QCoreApplication::translate("MainWindow", "&Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionQuit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAIAnalyze->setText(QCoreApplication::translate("MainWindow", "&Analyser avec IA", nullptr));
#if QT_CONFIG(shortcut)
        actionAIAnalyze->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+I", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAISuggest->setText(QCoreApplication::translate("MainWindow", "&Demander suggestions", nullptr));
#if QT_CONFIG(shortcut)
        actionAISuggest->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+I", nullptr));
#endif // QT_CONFIG(shortcut)
        lblLogo->setText(QString());
        sidebarBtnEmploye->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        sidebarBtnEquipe->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        sidebarBtnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        sidebarBtnLaboratoire->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        sidebarBtnCommande->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        sidebarBtnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableLaboratoires->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableLaboratoires->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom Laboratoire", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableLaboratoires->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableLaboratoires->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Adresse / Site", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableLaboratoires->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Review (5)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableLaboratoires->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Espace (m\302\262)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableLaboratoires->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Espace Reste(m\302\262)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabList), QCoreApplication::translate("MainWindow", "\360\237\223\213 Liste des Laboratoires", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\213 Informations du Laboratoire", nullptr));
        lblId->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        lblNom->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        lblAddress->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        lblType->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        lblConform->setText(QCoreApplication::translate("MainWindow", "Review (5) :", nullptr));
        lblArea->setText(QCoreApplication::translate("MainWindow", "Espace (m\302\262) :", nullptr));
        lblNbMach->setText(QCoreApplication::translate("MainWindow", "Espace Reste (m\302\262) :", nullptr));
        groupBoxDates->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\205 Dates", nullptr));
        lblLast->setText(QCoreApplication::translate("MainWindow", "Dernier contr\303\264le :", nullptr));
        lblNext->setText(QCoreApplication::translate("MainWindow", "Prochain contr\303\264le :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QCoreApplication::translate("MainWindow", "\360\237\224\215 D\303\251tails du Laboratoire", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<center><h2 style='color:#798777;'>\360\237\223\215 G\303\251olocalisation</h2>\n"
"<br>\n"
"<p>Cette section affichera la g\303\251olocalisation des laboratoires sur une carte interactive.</p>\n"
"<br>\n"
"<div style='font-size: 16px; color: #555;'>\360\237\232\247 Fonctionnalit\303\251 en d\303\251veloppement \360\237\232\247</div></center>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistory), QCoreApplication::translate("MainWindow", "\360\237\223\215 G\303\251olocalisation", nullptr));
        groupBoxGlobalStats->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\210 Vue d'ensemble", nullptr));
        lblTotLabText->setText(QCoreApplication::translate("MainWindow", "Total laboratoires :", nullptr));
        lblTotalLabs->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblConfRateText->setText(QCoreApplication::translate("MainWindow", "Taux de conformit\303\251 :", nullptr));
        lblConformityRate->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        lblNonConfText->setText(QCoreApplication::translate("MainWindow", "Non conformes :", nullptr));
        lblNonConform->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnAddControl->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Nouveau contr\303\264le", nullptr));
        btnExportControl->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        groupBoxStatsByType->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 R\303\251partition par type", nullptr));
        textStatsByType->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#798777;\">Biologie:</span> 25% (5 labos)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#798777;\">Chimie:</span> 40% (8 labos)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#798777;\">Microbiologie:</span> 20% (4 labos)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-l"
                        "eft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#798777;\">Pathologie:</span> 15% (3 labos)</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStats), QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques", nullptr));
        lblAITitle->setText(QCoreApplication::translate("MainWindow", "<h2 style='margin: 0;'>\360\237\244\226 Assistant IA - Suggestions Labo</h2>", nullptr));
        textAIChat->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600; color:#798777;\">Assistant IA:</span><span style=\" font-size:11pt;\"> Bonjour! Je suis votre assistant IA pour les laboratoires. Je peux analyser vos donn\303\251es et sugg\303\251rer des am\303\251liorations ou r\303\251novations.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">S\303\251lectionnez un laboratoire dans la liste pour obtenir des suggestions personnalis\303\251es.</span></p></body"
                        "></html>", nullptr));
        lineEditAIQuestion->setPlaceholderText(QCoreApplication::translate("MainWindow", "Posez une question sur les am\303\251liorations...", nullptr));
        btnSendQuestion->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        groupBoxAISuggestions->setTitle(QCoreApplication::translate("MainWindow", "\360\237\222\241 Suggestions bas\303\251es sur les donn\303\251es", nullptr));
        textAISuggestions->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#798777;\">Analyses disponibles:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 20px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" margin-top:8px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Analyse des taux de conformit\303\251</li>\n"
"<li style=\" margin-top:8px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Suggestions d'am\303\251lioration d'espace</li>\n"
"<li style=\" margin-top:"
                        "8px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Recommandations de r\303\251novation</li>\n"
"<li style=\" margin-top:8px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Optimisation des ressources</li>\n"
"<li style=\" margin-top:8px; margin-bottom:8px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Pr\303\251visions de maintenance</li></ul></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAI), QCoreApplication::translate("MainWindow", "\360\237\244\226 Assistant IA", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\215 Recherche Rapide", nullptr));
        lineEditQuickSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un laboratoire...", nullptr));
        btnRecherche->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "\342\232\241 Actions", nullptr));
        btnNewLab->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Nouveau Laboratoire", nullptr));
        btnEditLab->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnDeleteLab->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Supprimer / Archiver", nullptr));
        btnAddControlQuick->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 Nouveau contr\303\264le", nullptr));
        groupBoxQuickInfo->setTitle(QCoreApplication::translate("MainWindow", "\342\204\271\357\270\217 Informations rapides", nullptr));
        lblQuickConf->setText(QCoreApplication::translate("MainWindow", "Conformit\303\251 :", nullptr));
        quickConformity->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lblQuickLast->setText(QCoreApplication::translate("MainWindow", "Dernier contr\303\264le :", nullptr));
        quickLastControl->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lblQuickNext->setText(QCoreApplication::translate("MainWindow", "Prochain contr\303\264le :", nullptr));
        quickNextControl->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
