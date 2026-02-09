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
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
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
    QWidget *contentArea;
    QHBoxLayout *contentLayout;
    QWidget *centerPanel;
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
    QWidget *rightPanel;
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
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuControle;
    QMenu *menuAI;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 900);
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
        navFrame->setMaximumWidth(240);
        navFrame->setMinimumWidth(240);
        navFrame->setFrameShape(QFrame::StyledPanel);
        navLayout = new QVBoxLayout(navFrame);
        navLayout->setSpacing(0);
        navLayout->setObjectName("navLayout");
        navLayout->setContentsMargins(0, 0, 0, 0);
        lblLogo = new QLabel(navFrame);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setAlignment(Qt::AlignCenter);
        lblLogo->setStyleSheet(QString::fromUtf8("font-size: 22pt; color: #FFFFFF; background-color: #798777; padding: 20px 0; font-weight: bold;"));

        navLayout->addWidget(lblLogo);

        sidebarBtnEmploye = new QPushButton(navFrame);
        sidebarBtnEmploye->setObjectName("sidebarBtnEmploye");
        sidebarBtnEmploye->setCheckable(true);
        sidebarBtnEmploye->setStyleSheet(QString::fromUtf8("QPushButton { text-align: left; padding-left: 16px; }"));

        navLayout->addWidget(sidebarBtnEmploye);

        sidebarBtnEquipe = new QPushButton(navFrame);
        sidebarBtnEquipe->setObjectName("sidebarBtnEquipe");
        sidebarBtnEquipe->setCheckable(true);
        sidebarBtnEquipe->setStyleSheet(QString::fromUtf8("QPushButton { text-align: left; padding-left: 16px; }"));

        navLayout->addWidget(sidebarBtnEquipe);

        sidebarBtnClient = new QPushButton(navFrame);
        sidebarBtnClient->setObjectName("sidebarBtnClient");
        sidebarBtnClient->setCheckable(true);
        sidebarBtnClient->setStyleSheet(QString::fromUtf8("QPushButton { text-align: left; padding-left: 16px; }"));

        navLayout->addWidget(sidebarBtnClient);

        sidebarBtnLaboratoire = new QPushButton(navFrame);
        sidebarBtnLaboratoire->setObjectName("sidebarBtnLaboratoire");
        sidebarBtnLaboratoire->setCheckable(true);
        sidebarBtnLaboratoire->setStyleSheet(QString::fromUtf8("QPushButton { text-align: left; padding-left: 16px; }"));

        navLayout->addWidget(sidebarBtnLaboratoire);

        sidebarBtnCommande = new QPushButton(navFrame);
        sidebarBtnCommande->setObjectName("sidebarBtnCommande");
        sidebarBtnCommande->setCheckable(true);
        sidebarBtnCommande->setStyleSheet(QString::fromUtf8("QPushButton { text-align: left; padding-left: 16px; }"));

        navLayout->addWidget(sidebarBtnCommande);

        sidebarBtnMachine = new QPushButton(navFrame);
        sidebarBtnMachine->setObjectName("sidebarBtnMachine");
        sidebarBtnMachine->setCheckable(true);
        sidebarBtnMachine->setStyleSheet(QString::fromUtf8("QPushButton { text-align: left; padding-left: 16px; }"));

        navLayout->addWidget(sidebarBtnMachine);

        navSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        navLayout->addItem(navSpacer);


        mainLayout->addWidget(navFrame);

        contentArea = new QWidget(centralwidget);
        contentArea->setObjectName("contentArea");
        contentLayout = new QHBoxLayout(contentArea);
        contentLayout->setSpacing(8);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(10, 10, 10, 10);
        centerPanel = new QWidget(contentArea);
        centerPanel->setObjectName("centerPanel");
        centerLayout = new QVBoxLayout(centerPanel);
        centerLayout->setSpacing(0);
        centerLayout->setContentsMargins(0, 0, 0, 0);
        centerLayout->setObjectName("centerLayout");
        centerLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centerPanel);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setDocumentMode(false);
        tabList = new QWidget();
        tabList->setObjectName("tabList");
        tabListLayout = new QVBoxLayout(tabList);
        tabListLayout->setSpacing(0);
        tabListLayout->setContentsMargins(0, 0, 0, 0);
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
        tableLaboratoires->setRowCount(0);
        tableLaboratoires->setColumnCount(7);
        tableLaboratoires->setAlternatingRowColors(true);
        tableLaboratoires->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableLaboratoires->setSelectionMode(QAbstractItemView::SingleSelection);
        tableLaboratoires->setShowGrid(true);
        tableLaboratoires->setGridStyle(Qt::SolidLine);
        tableLaboratoires->setSortingEnabled(true);
        tableLaboratoires->setWordWrap(false);
        tableLaboratoires->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        tableLaboratoires->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

        tabListLayout->addWidget(tableLaboratoires);

        tabWidget->addTab(tabList, QString());
        tabDetails = new QWidget();
        tabDetails->setObjectName("tabDetails");
        tabDetailsLayout = new QVBoxLayout(tabDetails);
        tabDetailsLayout->setSpacing(8);
        tabDetailsLayout->setObjectName("tabDetailsLayout");
        scrollArea = new QScrollArea(tabDetails);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollLayout = new QVBoxLayout(scrollAreaWidgetContents);
        scrollLayout->setSpacing(12);
        scrollLayout->setObjectName("scrollLayout");
        groupBoxInfo = new QGroupBox(scrollAreaWidgetContents);
        groupBoxInfo->setObjectName("groupBoxInfo");
        formLayoutInfo = new QFormLayout(groupBoxInfo);
        formLayoutInfo->setSpacing(6);
        formLayoutInfo->setObjectName("formLayoutInfo");
        formLayoutInfo->setVerticalSpacing(8);
        lblId = new QLabel(groupBoxInfo);
        lblId->setObjectName("lblId");

        formLayoutInfo->setWidget(0, QFormLayout::LabelRole, lblId);

        detailId = new QLineEdit(groupBoxInfo);
        detailId->setObjectName("detailId");
        detailId->setReadOnly(true);

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

        formLayoutInfo->setWidget(3, QFormLayout::FieldRole, detailType);

        lblConform = new QLabel(groupBoxInfo);
        lblConform->setObjectName("lblConform");

        formLayoutInfo->setWidget(4, QFormLayout::LabelRole, lblConform);

        detailConformite = new QComboBox(groupBoxInfo);
        detailConformite->setObjectName("detailConformite");

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
        formLayoutDates = new QFormLayout(groupBoxDates);
        formLayoutDates->setSpacing(6);
        formLayoutDates->setObjectName("formLayoutDates");
        formLayoutDates->setVerticalSpacing(8);
        lblLast = new QLabel(groupBoxDates);
        lblLast->setObjectName("lblLast");

        formLayoutDates->setWidget(0, QFormLayout::LabelRole, lblLast);

        detailLastControl = new QDateEdit(groupBoxDates);
        detailLastControl->setObjectName("detailLastControl");

        formLayoutDates->setWidget(0, QFormLayout::FieldRole, detailLastControl);

        lblNext = new QLabel(groupBoxDates);
        lblNext->setObjectName("lblNext");

        formLayoutDates->setWidget(1, QFormLayout::LabelRole, lblNext);

        detailNextControl = new QDateEdit(groupBoxDates);
        detailNextControl->setObjectName("detailNextControl");

        formLayoutDates->setWidget(1, QFormLayout::FieldRole, detailNextControl);


        scrollLayout->addWidget(groupBoxDates);

        scrollArea->setWidget(scrollAreaWidgetContents);

        tabDetailsLayout->addWidget(scrollArea);

        tabWidget->addTab(tabDetails, QString());
        tabHistory = new QWidget();
        tabHistory->setObjectName("tabHistory");
        verticalLayout = new QVBoxLayout(tabHistory);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(tabHistory);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tabWidget->addTab(tabHistory, QString());
        tabStats = new QWidget();
        tabStats->setObjectName("tabStats");
        tabStatsLayout = new QVBoxLayout(tabStats);
        tabStatsLayout->setSpacing(12);
        tabStatsLayout->setObjectName("tabStatsLayout");
        groupBoxGlobalStats = new QGroupBox(tabStats);
        groupBoxGlobalStats->setObjectName("groupBoxGlobalStats");
        gridStats = new QGridLayout(groupBoxGlobalStats);
        gridStats->setSpacing(8);
        gridStats->setObjectName("gridStats");
        gridStats->setVerticalSpacing(8);
        lblTotLabText = new QLabel(groupBoxGlobalStats);
        lblTotLabText->setObjectName("lblTotLabText");

        gridStats->addWidget(lblTotLabText, 0, 0, 1, 1);

        lblTotalLabs = new QLabel(groupBoxGlobalStats);
        lblTotalLabs->setObjectName("lblTotalLabs");

        gridStats->addWidget(lblTotalLabs, 0, 1, 1, 1);

        lblConfRateText = new QLabel(groupBoxGlobalStats);
        lblConfRateText->setObjectName("lblConfRateText");

        gridStats->addWidget(lblConfRateText, 1, 0, 1, 1);

        lblConformityRate = new QLabel(groupBoxGlobalStats);
        lblConformityRate->setObjectName("lblConformityRate");

        gridStats->addWidget(lblConformityRate, 1, 1, 1, 1);

        lblNonConfText = new QLabel(groupBoxGlobalStats);
        lblNonConfText->setObjectName("lblNonConfText");

        gridStats->addWidget(lblNonConfText, 2, 0, 1, 1);

        lblNonConform = new QLabel(groupBoxGlobalStats);
        lblNonConform->setObjectName("lblNonConform");

        gridStats->addWidget(lblNonConform, 2, 1, 1, 1);


        tabStatsLayout->addWidget(groupBoxGlobalStats);

        buttonsLayout = new QHBoxLayout();
        buttonsLayout->setSpacing(8);
        buttonsLayout->setObjectName("buttonsLayout");
        btnAddControl = new QPushButton(tabStats);
        btnAddControl->setObjectName("btnAddControl");

        buttonsLayout->addWidget(btnAddControl);

        btnExportControl = new QPushButton(tabStats);
        btnExportControl->setObjectName("btnExportControl");

        buttonsLayout->addWidget(btnExportControl);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        buttonsLayout->addItem(horizontalSpacer);


        tabStatsLayout->addLayout(buttonsLayout);

        groupBoxStatsByType = new QGroupBox(tabStats);
        groupBoxStatsByType->setObjectName("groupBoxStatsByType");
        typeStatsLayout = new QVBoxLayout(groupBoxStatsByType);
        typeStatsLayout->setSpacing(8);
        typeStatsLayout->setObjectName("typeStatsLayout");
        textStatsByType = new QTextEdit(groupBoxStatsByType);
        textStatsByType->setObjectName("textStatsByType");
        textStatsByType->setReadOnly(true);

        typeStatsLayout->addWidget(textStatsByType);


        tabStatsLayout->addWidget(groupBoxStatsByType);

        tabWidget->addTab(tabStats, QString());
        tabAI = new QWidget();
        tabAI->setObjectName("tabAI");
        tabAILayout = new QVBoxLayout(tabAI);
        tabAILayout->setSpacing(0);
        tabAILayout->setContentsMargins(0, 0, 0, 0);
        tabAILayout->setObjectName("tabAILayout");
        lblAITitle = new QLabel(tabAI);
        lblAITitle->setObjectName("lblAITitle");
        lblAITitle->setAlignment(Qt::AlignCenter);
        lblAITitle->setStyleSheet(QString::fromUtf8("padding: 15px; background-color: #798777; color: white;"));

        tabAILayout->addWidget(lblAITitle);

        textAIChat = new QTextEdit(tabAI);
        textAIChat->setObjectName("textAIChat");
        textAIChat->setReadOnly(true);

        tabAILayout->addWidget(textAIChat);

        AIControlLayout = new QHBoxLayout();
        AIControlLayout->setSpacing(8);
        AIControlLayout->setObjectName("AIControlLayout");
        lineEditAIQuestion = new QLineEdit(tabAI);
        lineEditAIQuestion->setObjectName("lineEditAIQuestion");

        AIControlLayout->addWidget(lineEditAIQuestion);

        btnSendQuestion = new QPushButton(tabAI);
        btnSendQuestion->setObjectName("btnSendQuestion");

        AIControlLayout->addWidget(btnSendQuestion);


        tabAILayout->addLayout(AIControlLayout);

        groupBoxAISuggestions = new QGroupBox(tabAI);
        groupBoxAISuggestions->setObjectName("groupBoxAISuggestions");
        AISuggestionsLayout = new QVBoxLayout(groupBoxAISuggestions);
        AISuggestionsLayout->setSpacing(8);
        AISuggestionsLayout->setObjectName("AISuggestionsLayout");
        textAISuggestions = new QTextEdit(groupBoxAISuggestions);
        textAISuggestions->setObjectName("textAISuggestions");
        textAISuggestions->setReadOnly(true);

        AISuggestionsLayout->addWidget(textAISuggestions);


        tabAILayout->addWidget(groupBoxAISuggestions);

        tabWidget->addTab(tabAI, QString());

        centerLayout->addWidget(tabWidget);


        contentLayout->addWidget(centerPanel);

        rightPanel = new QWidget(contentArea);
        rightPanel->setObjectName("rightPanel");
        rightPanel->setMaximumWidth(340);
        rightLayout = new QVBoxLayout(rightPanel);
        rightLayout->setSpacing(12);
        rightLayout->setObjectName("rightLayout");
        rightLayout->setContentsMargins(0, 0, 0, 0);
        groupBoxSearch = new QGroupBox(rightPanel);
        groupBoxSearch->setObjectName("groupBoxSearch");
        searchLayout = new QVBoxLayout(groupBoxSearch);
        searchLayout->setSpacing(8);
        searchLayout->setObjectName("searchLayout");
        lineEditQuickSearch = new QLineEdit(groupBoxSearch);
        lineEditQuickSearch->setObjectName("lineEditQuickSearch");
        lineEditQuickSearch->setClearButtonEnabled(true);

        searchLayout->addWidget(lineEditQuickSearch);

        btnRecherche = new QPushButton(groupBoxSearch);
        btnRecherche->setObjectName("btnRecherche");
        btnRecherche->setMinimumWidth(120);

        searchLayout->addWidget(btnRecherche);


        rightLayout->addWidget(groupBoxSearch);

        groupBoxActions = new QGroupBox(rightPanel);
        groupBoxActions->setObjectName("groupBoxActions");
        actionsLayout = new QVBoxLayout(groupBoxActions);
        actionsLayout->setSpacing(8);
        actionsLayout->setObjectName("actionsLayout");
        btnNewLab = new QPushButton(groupBoxActions);
        btnNewLab->setObjectName("btnNewLab");

        actionsLayout->addWidget(btnNewLab);

        btnEditLab = new QPushButton(groupBoxActions);
        btnEditLab->setObjectName("btnEditLab");

        actionsLayout->addWidget(btnEditLab);

        btnDeleteLab = new QPushButton(groupBoxActions);
        btnDeleteLab->setObjectName("btnDeleteLab");

        actionsLayout->addWidget(btnDeleteLab);

        btnAddControlQuick = new QPushButton(groupBoxActions);
        btnAddControlQuick->setObjectName("btnAddControlQuick");

        actionsLayout->addWidget(btnAddControlQuick);


        rightLayout->addWidget(groupBoxActions);

        groupBoxQuickInfo = new QGroupBox(rightPanel);
        groupBoxQuickInfo->setObjectName("groupBoxQuickInfo");
        gridLayout = new QGridLayout(groupBoxQuickInfo);
        gridLayout->setSpacing(6);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setVerticalSpacing(8);
        lblQuickConf = new QLabel(groupBoxQuickInfo);
        lblQuickConf->setObjectName("lblQuickConf");

        gridLayout->addWidget(lblQuickConf, 0, 0, 1, 1);

        quickConformity = new QLabel(groupBoxQuickInfo);
        quickConformity->setObjectName("quickConformity");

        gridLayout->addWidget(quickConformity, 0, 1, 1, 1);

        lblQuickLast = new QLabel(groupBoxQuickInfo);
        lblQuickLast->setObjectName("lblQuickLast");

        gridLayout->addWidget(lblQuickLast, 1, 0, 1, 1);

        quickLastControl = new QLabel(groupBoxQuickInfo);
        quickLastControl->setObjectName("quickLastControl");

        gridLayout->addWidget(quickLastControl, 1, 1, 1, 1);

        lblQuickNext = new QLabel(groupBoxQuickInfo);
        lblQuickNext->setObjectName("lblQuickNext");

        gridLayout->addWidget(lblQuickNext, 2, 0, 1, 1);

        quickNextControl = new QLabel(groupBoxQuickInfo);
        quickNextControl->setObjectName("quickNextControl");

        gridLayout->addWidget(quickNextControl, 2, 1, 1, 1);


        rightLayout->addWidget(groupBoxQuickInfo);

        rightSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightLayout->addItem(rightSpacer);


        contentLayout->addWidget(rightPanel);


        mainLayout->addWidget(contentArea);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 22));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuControle = new QMenu(menubar);
        menuControle->setObjectName("menuControle");
        menuAI = new QMenu(menubar);
        menuAI->setObjectName("menuAI");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuControle->menuAction());
        menubar->addAction(menuAI->menuAction());
        menuFichier->addAction(actionNewLab);
        menuFichier->addAction(actionExportPDF);
        menuFichier->addSeparator();
        menuFichier->addAction(actionQuit);
        menuControle->addAction(actionNewControl);
        menuControle->addAction(actionEditControl);
        menuAI->addAction(actionAIAnalyze);
        menuAI->addAction(actionAISuggest);

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
        lblLogo->setText(QCoreApplication::translate("MainWindow", "<b>LABO CTRL</b>", nullptr));
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
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "review(5)", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableLaboratoires->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "espace (m\302\262)", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableLaboratoires->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "espace-reste(m\302\262)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabList), QCoreApplication::translate("MainWindow", "Liste des Laboratoires", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "Informations du Laboratoire", nullptr));
        lblId->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        lblNom->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        lblAddress->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        lblType->setText(QCoreApplication::translate("MainWindow", "Type :", nullptr));
        lblConform->setText(QCoreApplication::translate("MainWindow", "review(5):", nullptr));
        lblArea->setText(QCoreApplication::translate("MainWindow", "espace(m\302\262) :", nullptr));
        lblNbMach->setText(QCoreApplication::translate("MainWindow", "reste(m\302\262):", nullptr));
        groupBoxDates->setTitle(QCoreApplication::translate("MainWindow", "Dates", nullptr));
        lblLast->setText(QCoreApplication::translate("MainWindow", "Dernier contr\303\264le :", nullptr));
        lblNext->setText(QCoreApplication::translate("MainWindow", "Prochain contr\303\264le :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QCoreApplication::translate("MainWindow", "D\303\251tails du Laboratoire", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<center><h3>Fonctionnalit\303\251 en d\303\251veloppement</h3><br>Cette section affichera la g\303\251olocalisation des laboratoires sur une carte interactive.</center>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistory), QCoreApplication::translate("MainWindow", "Geolocalisation", nullptr));
        groupBoxGlobalStats->setTitle(QCoreApplication::translate("MainWindow", "Vue d'ensemble", nullptr));
        lblTotLabText->setText(QCoreApplication::translate("MainWindow", "Total laboratoires :", nullptr));
        lblTotalLabs->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblConfRateText->setText(QCoreApplication::translate("MainWindow", "Taux de conformit\303\251 :", nullptr));
        lblConformityRate->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        lblNonConfText->setText(QCoreApplication::translate("MainWindow", "Non conformes :", nullptr));
        lblNonConform->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnAddControl->setText(QCoreApplication::translate("MainWindow", "+ Nouveau contr\303\264le", nullptr));
        btnExportControl->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        groupBoxStatsByType->setTitle(QCoreApplication::translate("MainWindow", "R\303\251partition par type", nullptr));
        textStatsByType->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Biologie: 25% (5 labos)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Chimie: 40% (8 labos)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:9pt;\">Microbiologie: 20% (4 labos)</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; "
                        "text-indent:0px;\"><span style=\" font-size:9pt;\">Pathologie: 15% (3 labos)</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStats), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        lblAITitle->setText(QCoreApplication::translate("MainWindow", "<h2>\360\237\244\226 Assistant IA - Suggestions Labo</h2>", nullptr));
        textAIChat->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:10pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" color:#6FA66F; font-weight:600;\">Assistant IA:</span> Bonjour! Je suis votre assistant IA pour les laboratoires. Je peux analyser vos donn\303\251es et sugg\303\251rer des am\303\251liorations ou r\303\251novations.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">S\303\251lectionnez un laboratoire dans la liste pour obtenir des suggestions personnalis\303\251es.</p>\n"
"</body></html>", nullptr));
        lineEditAIQuestion->setPlaceholderText(QCoreApplication::translate("MainWindow", "Posez une question sur les am\303\251liorations...", nullptr));
        btnSendQuestion->setText(QCoreApplication::translate("MainWindow", "Envoyer", nullptr));
        groupBoxAISuggestions->setTitle(QCoreApplication::translate("MainWindow", "Suggestions bas\303\251es sur les donn\303\251es", nullptr));
        textAISuggestions->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#798777;\">Analyses disponibles:</span></p>\n"
"<ul style=\"margin-top: 0px; margin-bottom: 0px; margin-left: 0px; margin-right: 0px; -qt-list-indent: 1;\">\n"
"<li style=\" margin-top:6px; margin-bottom:6px;\">Analyse des taux de conformit\303\251</li>\n"
"<li style=\" margin-top:6px; margin-bottom:6px;\">Suggestions d'am\303\251lioration d'espace</li>\n"
"<li style=\" margin-top:6px; margin-bottom:6px;\">Recommandations de r\303\251novation</li>\n"
"<li style=\" margin-top:6px; margin-bottom:6px;\">Optimisation des ressourc"
                        "es</li>\n"
"<li style=\" margin-top:6px; margin-bottom:6px;\">Pr\303\251visions de maintenance</li>\n"
"</ul>\n"
"</body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAI), QCoreApplication::translate("MainWindow", "Assistant IA", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "Recherche Rapide", nullptr));
        lineEditQuickSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher un laboratoire...", nullptr));
        btnRecherche->setText(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        btnNewLab->setText(QCoreApplication::translate("MainWindow", "Nouveau Laboratoire", nullptr));
        btnEditLab->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnDeleteLab->setText(QCoreApplication::translate("MainWindow", "Supprimer / Archiver", nullptr));
        btnAddControlQuick->setText(QCoreApplication::translate("MainWindow", "Nouveau contr\303\264le", nullptr));
        groupBoxQuickInfo->setTitle(QCoreApplication::translate("MainWindow", "Informations rapides", nullptr));
        lblQuickConf->setText(QCoreApplication::translate("MainWindow", "Conformit\303\251 :", nullptr));
        quickConformity->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lblQuickLast->setText(QCoreApplication::translate("MainWindow", "Dernier contr\303\264le :", nullptr));
        quickLastControl->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lblQuickNext->setText(QCoreApplication::translate("MainWindow", "Prochain contr\303\264le :", nullptr));
        quickNextControl->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "&Fichier", nullptr));
        menuControle->setTitle(QCoreApplication::translate("MainWindow", "&Contr\303\264le", nullptr));
        menuAI->setTitle(QCoreApplication::translate("MainWindow", "&IA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
