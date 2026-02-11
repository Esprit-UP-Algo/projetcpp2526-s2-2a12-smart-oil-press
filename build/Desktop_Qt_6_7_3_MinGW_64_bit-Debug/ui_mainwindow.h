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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
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
    QAction *actionExportPDF;
    QAction *actionExit;
    QAction *actionRefresh;
    QWidget *centralwidget;
    QHBoxLayout *mainLayout;
    QWidget *sideMenu;
    QVBoxLayout *sideMenuLayout;
    QLabel *labelLogo;
    QPushButton *btnEmployee;
    QPushButton *btnTeam;
    QPushButton *btnClient;
    QPushButton *btnLaboratory;
    QPushButton *btnOrder;
    QPushButton *btnMachine;
    QSpacerItem *verticalSpacer_Menu;
    QStackedWidget *stackedPages;
    QWidget *pageEmployee;
    QVBoxLayout *vboxLayout;
    QLabel *labelPageEmployee;
    QWidget *pageTeam;
    QVBoxLayout *vboxLayout1;
    QLabel *labelPageTeam;
    QWidget *pageClient;
    QVBoxLayout *vboxLayout2;
    QLabel *labelPageClient;
    QWidget *pageLaboratory;
    QVBoxLayout *vboxLayout3;
    QLabel *labelPageLaboratory;
    QWidget *pageOrder;
    QVBoxLayout *vboxLayout4;
    QLabel *labelPageOrder;
    QWidget *pageMachine;
    QVBoxLayout *machineLayout;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *leftLayout;
    QGroupBox *groupBoxSearch;
    QVBoxLayout *vboxLayout5;
    QHBoxLayout *hboxLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QHBoxLayout *hboxLayout1;
    QLabel *labelCategory;
    QComboBox *comboCategory;
    QHBoxLayout *hboxLayout2;
    QLabel *labelState;
    QComboBox *comboState;
    QHBoxLayout *hboxLayout3;
    QLabel *labelLocation;
    QLineEdit *lineEditLocation;
    QHBoxLayout *hboxLayout4;
    QPushButton *btnApplyFilter;
    QPushButton *btnResetFilter;
    QGroupBox *groupBoxSort;
    QVBoxLayout *vboxLayout6;
    QHBoxLayout *hboxLayout5;
    QLabel *labelSortBy;
    QComboBox *comboSortBy;
    QHBoxLayout *hboxLayout6;
    QRadioButton *radioCroissant;
    QRadioButton *radioDecroissant;
    QSpacerItem *verticalSpacer;
    QWidget *centerPanel;
    QVBoxLayout *vboxLayout7;
    QTabWidget *tabWidget;
    QWidget *tabList;
    QVBoxLayout *vboxLayout8;
    QTableWidget *tableEquipments;
    QHBoxLayout *hboxLayout7;
    QPushButton *btnExportPDF;
    QPushButton *btnRefresh;
    QSpacerItem *horizontalSpacer_List;
    QWidget *tabDetails;
    QVBoxLayout *vboxLayout9;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *vboxLayout10;
    QGroupBox *groupBoxInfo;
    QFormLayout *formLayout;
    QLabel *labelID;
    QLineEdit *detailId;
    QLabel *labelName;
    QLineEdit *detailName;
    QLabel *labelReference;
    QLineEdit *detailReference;
    QLabel *labelDetailCategory;
    QComboBox *detailCategory;
    QLabel *labelDetailState;
    QComboBox *detailState;
    QLabel *labelDetailLocation;
    QLineEdit *detailLocation;
    QLabel *labelWarrantyEnd;
    QDateEdit *detailWarrantyEnd;
    QGroupBox *groupBoxFinance;
    QFormLayout *formLayout1;
    QLabel *labelPurchaseDate;
    QDateEdit *detailPurchaseDate;
    QGroupBox *groupBoxTraceability;
    QFormLayout *formLayout2;
    QLabel *labelQRCode;
    QLineEdit *detailQR;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *horizontalSpacer_Left;
    QPushButton *btnAddMachineFromDetails;
    QSpacerItem *horizontalSpacer_Right;
    QWidget *tabHistorique;
    QVBoxLayout *historiqueLayout;
    QWidget *historiqueToolbar;
    QHBoxLayout *hboxLayout9;
    QPushButton *btnAddIntervention;
    QPushButton *btnDeleteIntervention;
    QPushButton *btnViewDetails;
    QSpacerItem *horizontalSpacer_Historique;
    QPushButton *btnExportPDF_Historique;
    QPushButton *btnRefresh_Historique;
    QTableWidget *tableHistorique;
    QHBoxLayout *hboxLayout10;
    QLabel *labelTotalInterventions;
    QLabel *totalInterventionsValue;
    QLabel *labelCoutTotal;
    QLabel *coutTotalValue;
    QSpacerItem *horizontalSpacer_Total;
    QWidget *tabStatistics;
    QVBoxLayout *statisticsLayout;
    QGroupBox *groupBoxStatsCards;
    QHBoxLayout *statsCardsLayout;
    QFrame *cardTotal;
    QVBoxLayout *vboxLayout11;
    QLabel *labelTotalIcon;
    QLabel *labelTotalTitle;
    QLabel *statTotal;
    QFrame *cardOperational;
    QVBoxLayout *vboxLayout12;
    QLabel *labelOpIcon;
    QLabel *labelOpTitle;
    QLabel *statOp;
    QFrame *cardMaintenance;
    QVBoxLayout *vboxLayout13;
    QLabel *labelMaintIcon;
    QLabel *labelMaintTitle;
    QLabel *statMaint;
    QFrame *cardDefective;
    QVBoxLayout *vboxLayout14;
    QLabel *labelDefIcon;
    QLabel *labelDefTitle;
    QLabel *statDef;
    QSplitter *statisticsSplitter;
    QGroupBox *groupBoxCategories;
    QVBoxLayout *vboxLayout15;
    QTextEdit *statsCategories;
    QGroupBox *groupBoxEtats;
    QVBoxLayout *vboxLayout16;
    QTextEdit *statsBreakdowns;
    QGroupBox *groupBoxTrends;
    QVBoxLayout *vboxLayout17;
    QTextEdit *trendChartPlaceholder;
    QGroupBox *groupBoxKPIs;
    QHBoxLayout *kpiLayout;
    QFrame *kpiInterventions;
    QVBoxLayout *vboxLayout18;
    QLabel *labelKpiInterventions;
    QLabel *kpiInterventionsValue;
    QFrame *kpiCoutTotal;
    QVBoxLayout *vboxLayout19;
    QLabel *labelKpiCoutTotal;
    QLabel *kpiCoutTotalValue;
    QFrame *kpiDisponibilite;
    QVBoxLayout *vboxLayout20;
    QLabel *labelKpiDisponibilite;
    QLabel *kpiDisponibiliteValue;
    QFrame *kpiTauxPanne;
    QVBoxLayout *vboxLayout21;
    QLabel *labelKpiTauxPanne;
    QLabel *kpiTauxPanneValue;
    QHBoxLayout *hboxLayout11;
    QPushButton *btnExportPDF_Stats;
    QPushButton *btnRefresh_Stats;
    QSpacerItem *horizontalSpacer_Stats;
    QSpacerItem *verticalSpacerStats;
    QWidget *rightPanel;
    QVBoxLayout *vboxLayout22;
    QGroupBox *groupBoxActions;
    QVBoxLayout *vboxLayout23;
    QPushButton *btnQuickEdit;
    QPushButton *btnQuickDelete;
    QPushButton *btnReportProblem;
    QGroupBox *groupBoxQuickInfo;
    QVBoxLayout *vboxLayout24;
    QLabel *labelEtat;
    QLabel *quickState;
    QLabel *labelLocalisation;
    QLabel *quickLocation;
    QLabel *labelInterventions;
    QLabel *quickBreakdowns;
    QPushButton *btnScanQR_RightPanel;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QMenu *menuFichier;
    QMenu *menuEdition;
    QMenu *menuAffichage;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 900);
        actionExportPDF = new QAction(MainWindow);
        actionExportPDF->setObjectName("actionExportPDF");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName("actionRefresh");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QHBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        sideMenu = new QWidget(centralwidget);
        sideMenu->setObjectName("sideMenu");
        sideMenu->setMinimumWidth(200);
        sideMenu->setMaximumWidth(200);
        sideMenuLayout = new QVBoxLayout(sideMenu);
        sideMenuLayout->setObjectName("sideMenuLayout");
        sideMenuLayout->setContentsMargins(0, 0, 0, 0);
        labelLogo = new QLabel(sideMenu);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setMinimumHeight(120);
        labelLogo->setMaximumHeight(120);
        labelLogo->setAlignment(Qt::AlignCenter);
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/assets/oil_press.png")));
        labelLogo->setScaledContents(true);

        sideMenuLayout->addWidget(labelLogo);

        btnEmployee = new QPushButton(sideMenu);
        btnEmployee->setObjectName("btnEmployee");

        sideMenuLayout->addWidget(btnEmployee);

        btnTeam = new QPushButton(sideMenu);
        btnTeam->setObjectName("btnTeam");

        sideMenuLayout->addWidget(btnTeam);

        btnClient = new QPushButton(sideMenu);
        btnClient->setObjectName("btnClient");

        sideMenuLayout->addWidget(btnClient);

        btnLaboratory = new QPushButton(sideMenu);
        btnLaboratory->setObjectName("btnLaboratory");

        sideMenuLayout->addWidget(btnLaboratory);

        btnOrder = new QPushButton(sideMenu);
        btnOrder->setObjectName("btnOrder");

        sideMenuLayout->addWidget(btnOrder);

        btnMachine = new QPushButton(sideMenu);
        btnMachine->setObjectName("btnMachine");

        sideMenuLayout->addWidget(btnMachine);

        verticalSpacer_Menu = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        sideMenuLayout->addItem(verticalSpacer_Menu);


        mainLayout->addWidget(sideMenu);

        stackedPages = new QStackedWidget(centralwidget);
        stackedPages->setObjectName("stackedPages");
        pageEmployee = new QWidget();
        pageEmployee->setObjectName("pageEmployee");
        vboxLayout = new QVBoxLayout(pageEmployee);
        vboxLayout->setObjectName("vboxLayout");
        labelPageEmployee = new QLabel(pageEmployee);
        labelPageEmployee->setObjectName("labelPageEmployee");
        labelPageEmployee->setAlignment(Qt::AlignCenter);

        vboxLayout->addWidget(labelPageEmployee);

        stackedPages->addWidget(pageEmployee);
        pageTeam = new QWidget();
        pageTeam->setObjectName("pageTeam");
        vboxLayout1 = new QVBoxLayout(pageTeam);
        vboxLayout1->setObjectName("vboxLayout1");
        labelPageTeam = new QLabel(pageTeam);
        labelPageTeam->setObjectName("labelPageTeam");
        labelPageTeam->setAlignment(Qt::AlignCenter);

        vboxLayout1->addWidget(labelPageTeam);

        stackedPages->addWidget(pageTeam);
        pageClient = new QWidget();
        pageClient->setObjectName("pageClient");
        vboxLayout2 = new QVBoxLayout(pageClient);
        vboxLayout2->setObjectName("vboxLayout2");
        labelPageClient = new QLabel(pageClient);
        labelPageClient->setObjectName("labelPageClient");
        labelPageClient->setAlignment(Qt::AlignCenter);

        vboxLayout2->addWidget(labelPageClient);

        stackedPages->addWidget(pageClient);
        pageLaboratory = new QWidget();
        pageLaboratory->setObjectName("pageLaboratory");
        vboxLayout3 = new QVBoxLayout(pageLaboratory);
        vboxLayout3->setObjectName("vboxLayout3");
        labelPageLaboratory = new QLabel(pageLaboratory);
        labelPageLaboratory->setObjectName("labelPageLaboratory");
        labelPageLaboratory->setAlignment(Qt::AlignCenter);

        vboxLayout3->addWidget(labelPageLaboratory);

        stackedPages->addWidget(pageLaboratory);
        pageOrder = new QWidget();
        pageOrder->setObjectName("pageOrder");
        vboxLayout4 = new QVBoxLayout(pageOrder);
        vboxLayout4->setObjectName("vboxLayout4");
        labelPageOrder = new QLabel(pageOrder);
        labelPageOrder->setObjectName("labelPageOrder");
        labelPageOrder->setAlignment(Qt::AlignCenter);

        vboxLayout4->addWidget(labelPageOrder);

        stackedPages->addWidget(pageOrder);
        pageMachine = new QWidget();
        pageMachine->setObjectName("pageMachine");
        machineLayout = new QVBoxLayout(pageMachine);
        machineLayout->setObjectName("machineLayout");
        splitter = new QSplitter(pageMachine);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName("leftPanel");
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(0, 0, 0, 0);
        groupBoxSearch = new QGroupBox(leftPanel);
        groupBoxSearch->setObjectName("groupBoxSearch");
        vboxLayout5 = new QVBoxLayout(groupBoxSearch);
        vboxLayout5->setObjectName("vboxLayout5");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        labelSearch = new QLabel(groupBoxSearch);
        labelSearch->setObjectName("labelSearch");

        hboxLayout->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(groupBoxSearch);
        lineEditSearch->setObjectName("lineEditSearch");

        hboxLayout->addWidget(lineEditSearch);


        vboxLayout5->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        labelCategory = new QLabel(groupBoxSearch);
        labelCategory->setObjectName("labelCategory");

        hboxLayout1->addWidget(labelCategory);

        comboCategory = new QComboBox(groupBoxSearch);
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->setObjectName("comboCategory");

        hboxLayout1->addWidget(comboCategory);


        vboxLayout5->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        labelState = new QLabel(groupBoxSearch);
        labelState->setObjectName("labelState");

        hboxLayout2->addWidget(labelState);

        comboState = new QComboBox(groupBoxSearch);
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->setObjectName("comboState");

        hboxLayout2->addWidget(comboState);


        vboxLayout5->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName("hboxLayout3");
        labelLocation = new QLabel(groupBoxSearch);
        labelLocation->setObjectName("labelLocation");

        hboxLayout3->addWidget(labelLocation);

        lineEditLocation = new QLineEdit(groupBoxSearch);
        lineEditLocation->setObjectName("lineEditLocation");

        hboxLayout3->addWidget(lineEditLocation);


        vboxLayout5->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName("hboxLayout4");
        btnApplyFilter = new QPushButton(groupBoxSearch);
        btnApplyFilter->setObjectName("btnApplyFilter");

        hboxLayout4->addWidget(btnApplyFilter);

        btnResetFilter = new QPushButton(groupBoxSearch);
        btnResetFilter->setObjectName("btnResetFilter");

        hboxLayout4->addWidget(btnResetFilter);


        vboxLayout5->addLayout(hboxLayout4);


        leftLayout->addWidget(groupBoxSearch);

        groupBoxSort = new QGroupBox(leftPanel);
        groupBoxSort->setObjectName("groupBoxSort");
        vboxLayout6 = new QVBoxLayout(groupBoxSort);
        vboxLayout6->setObjectName("vboxLayout6");
        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setObjectName("hboxLayout5");
        labelSortBy = new QLabel(groupBoxSort);
        labelSortBy->setObjectName("labelSortBy");

        hboxLayout5->addWidget(labelSortBy);

        comboSortBy = new QComboBox(groupBoxSort);
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->setObjectName("comboSortBy");

        hboxLayout5->addWidget(comboSortBy);


        vboxLayout6->addLayout(hboxLayout5);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setObjectName("hboxLayout6");
        radioCroissant = new QRadioButton(groupBoxSort);
        radioCroissant->setObjectName("radioCroissant");
        radioCroissant->setChecked(true);

        hboxLayout6->addWidget(radioCroissant);

        radioDecroissant = new QRadioButton(groupBoxSort);
        radioDecroissant->setObjectName("radioDecroissant");

        hboxLayout6->addWidget(radioDecroissant);


        vboxLayout6->addLayout(hboxLayout6);


        leftLayout->addWidget(groupBoxSort);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftLayout->addItem(verticalSpacer);

        splitter->addWidget(leftPanel);
        centerPanel = new QWidget(splitter);
        centerPanel->setObjectName("centerPanel");
        vboxLayout7 = new QVBoxLayout(centerPanel);
        vboxLayout7->setObjectName("vboxLayout7");
        vboxLayout7->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centerPanel);
        tabWidget->setObjectName("tabWidget");
        tabList = new QWidget();
        tabList->setObjectName("tabList");
        vboxLayout8 = new QVBoxLayout(tabList);
        vboxLayout8->setObjectName("vboxLayout8");
        tableEquipments = new QTableWidget(tabList);
        if (tableEquipments->columnCount() < 8)
            tableEquipments->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableEquipments->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableEquipments->setObjectName("tableEquipments");
        tableEquipments->setRowCount(0);
        tableEquipments->setColumnCount(8);
        tableEquipments->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableEquipments->setAlternatingRowColors(true);

        vboxLayout8->addWidget(tableEquipments);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName("hboxLayout7");
        btnExportPDF = new QPushButton(tabList);
        btnExportPDF->setObjectName("btnExportPDF");

        hboxLayout7->addWidget(btnExportPDF);

        btnRefresh = new QPushButton(tabList);
        btnRefresh->setObjectName("btnRefresh");

        hboxLayout7->addWidget(btnRefresh);

        horizontalSpacer_List = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout7->addItem(horizontalSpacer_List);


        vboxLayout8->addLayout(hboxLayout7);

        tabWidget->addTab(tabList, QString());
        tabDetails = new QWidget();
        tabDetails->setObjectName("tabDetails");
        vboxLayout9 = new QVBoxLayout(tabDetails);
        vboxLayout9->setObjectName("vboxLayout9");
        scrollArea = new QScrollArea(tabDetails);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 664, 731));
        vboxLayout10 = new QVBoxLayout(scrollAreaWidgetContents);
        vboxLayout10->setObjectName("vboxLayout10");
        groupBoxInfo = new QGroupBox(scrollAreaWidgetContents);
        groupBoxInfo->setObjectName("groupBoxInfo");
        formLayout = new QFormLayout(groupBoxInfo);
        formLayout->setObjectName("formLayout");
        labelID = new QLabel(groupBoxInfo);
        labelID->setObjectName("labelID");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        detailId = new QLineEdit(groupBoxInfo);
        detailId->setObjectName("detailId");
        detailId->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, detailId);

        labelName = new QLabel(groupBoxInfo);
        labelName->setObjectName("labelName");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelName);

        detailName = new QLineEdit(groupBoxInfo);
        detailName->setObjectName("detailName");

        formLayout->setWidget(1, QFormLayout::FieldRole, detailName);

        labelReference = new QLabel(groupBoxInfo);
        labelReference->setObjectName("labelReference");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelReference);

        detailReference = new QLineEdit(groupBoxInfo);
        detailReference->setObjectName("detailReference");

        formLayout->setWidget(2, QFormLayout::FieldRole, detailReference);

        labelDetailCategory = new QLabel(groupBoxInfo);
        labelDetailCategory->setObjectName("labelDetailCategory");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelDetailCategory);

        detailCategory = new QComboBox(groupBoxInfo);
        detailCategory->setObjectName("detailCategory");

        formLayout->setWidget(3, QFormLayout::FieldRole, detailCategory);

        labelDetailState = new QLabel(groupBoxInfo);
        labelDetailState->setObjectName("labelDetailState");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelDetailState);

        detailState = new QComboBox(groupBoxInfo);
        detailState->setObjectName("detailState");

        formLayout->setWidget(4, QFormLayout::FieldRole, detailState);

        labelDetailLocation = new QLabel(groupBoxInfo);
        labelDetailLocation->setObjectName("labelDetailLocation");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelDetailLocation);

        detailLocation = new QLineEdit(groupBoxInfo);
        detailLocation->setObjectName("detailLocation");

        formLayout->setWidget(5, QFormLayout::FieldRole, detailLocation);

        labelWarrantyEnd = new QLabel(groupBoxInfo);
        labelWarrantyEnd->setObjectName("labelWarrantyEnd");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelWarrantyEnd);

        detailWarrantyEnd = new QDateEdit(groupBoxInfo);
        detailWarrantyEnd->setObjectName("detailWarrantyEnd");

        formLayout->setWidget(6, QFormLayout::FieldRole, detailWarrantyEnd);


        vboxLayout10->addWidget(groupBoxInfo);

        groupBoxFinance = new QGroupBox(scrollAreaWidgetContents);
        groupBoxFinance->setObjectName("groupBoxFinance");
        formLayout1 = new QFormLayout(groupBoxFinance);
        formLayout1->setObjectName("formLayout1");
        labelPurchaseDate = new QLabel(groupBoxFinance);
        labelPurchaseDate->setObjectName("labelPurchaseDate");

        formLayout1->setWidget(0, QFormLayout::LabelRole, labelPurchaseDate);

        detailPurchaseDate = new QDateEdit(groupBoxFinance);
        detailPurchaseDate->setObjectName("detailPurchaseDate");

        formLayout1->setWidget(0, QFormLayout::FieldRole, detailPurchaseDate);


        vboxLayout10->addWidget(groupBoxFinance);

        groupBoxTraceability = new QGroupBox(scrollAreaWidgetContents);
        groupBoxTraceability->setObjectName("groupBoxTraceability");
        formLayout2 = new QFormLayout(groupBoxTraceability);
        formLayout2->setObjectName("formLayout2");
        labelQRCode = new QLabel(groupBoxTraceability);
        labelQRCode->setObjectName("labelQRCode");

        formLayout2->setWidget(0, QFormLayout::LabelRole, labelQRCode);

        detailQR = new QLineEdit(groupBoxTraceability);
        detailQR->setObjectName("detailQR");
        detailQR->setReadOnly(true);

        formLayout2->setWidget(0, QFormLayout::FieldRole, detailQR);


        vboxLayout10->addWidget(groupBoxTraceability);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout10->addItem(spacerItem);

        scrollArea->setWidget(scrollAreaWidgetContents);

        vboxLayout9->addWidget(scrollArea);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setObjectName("hboxLayout8");
        horizontalSpacer_Left = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout8->addItem(horizontalSpacer_Left);

        btnAddMachineFromDetails = new QPushButton(tabDetails);
        btnAddMachineFromDetails->setObjectName("btnAddMachineFromDetails");
        btnAddMachineFromDetails->setMinimumWidth(200);

        hboxLayout8->addWidget(btnAddMachineFromDetails);

        horizontalSpacer_Right = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout8->addItem(horizontalSpacer_Right);


        vboxLayout9->addLayout(hboxLayout8);

        tabWidget->addTab(tabDetails, QString());
        tabHistorique = new QWidget();
        tabHistorique->setObjectName("tabHistorique");
        historiqueLayout = new QVBoxLayout(tabHistorique);
        historiqueLayout->setObjectName("historiqueLayout");
        historiqueToolbar = new QWidget(tabHistorique);
        historiqueToolbar->setObjectName("historiqueToolbar");
        hboxLayout9 = new QHBoxLayout(historiqueToolbar);
        hboxLayout9->setObjectName("hboxLayout9");
        hboxLayout9->setContentsMargins(0, 0, 0, 0);
        btnAddIntervention = new QPushButton(historiqueToolbar);
        btnAddIntervention->setObjectName("btnAddIntervention");

        hboxLayout9->addWidget(btnAddIntervention);

        btnDeleteIntervention = new QPushButton(historiqueToolbar);
        btnDeleteIntervention->setObjectName("btnDeleteIntervention");

        hboxLayout9->addWidget(btnDeleteIntervention);

        btnViewDetails = new QPushButton(historiqueToolbar);
        btnViewDetails->setObjectName("btnViewDetails");

        hboxLayout9->addWidget(btnViewDetails);

        horizontalSpacer_Historique = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout9->addItem(horizontalSpacer_Historique);

        btnExportPDF_Historique = new QPushButton(historiqueToolbar);
        btnExportPDF_Historique->setObjectName("btnExportPDF_Historique");

        hboxLayout9->addWidget(btnExportPDF_Historique);

        btnRefresh_Historique = new QPushButton(historiqueToolbar);
        btnRefresh_Historique->setObjectName("btnRefresh_Historique");

        hboxLayout9->addWidget(btnRefresh_Historique);


        historiqueLayout->addWidget(historiqueToolbar);

        tableHistorique = new QTableWidget(tabHistorique);
        if (tableHistorique->columnCount() < 7)
            tableHistorique->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(6, __qtablewidgetitem14);
        tableHistorique->setObjectName("tableHistorique");
        tableHistorique->setMinimumHeight(300);
        tableHistorique->setColumnCount(7);
        tableHistorique->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableHistorique->setAlternatingRowColors(true);

        historiqueLayout->addWidget(tableHistorique);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setObjectName("hboxLayout10");
        labelTotalInterventions = new QLabel(tabHistorique);
        labelTotalInterventions->setObjectName("labelTotalInterventions");

        hboxLayout10->addWidget(labelTotalInterventions);

        totalInterventionsValue = new QLabel(tabHistorique);
        totalInterventionsValue->setObjectName("totalInterventionsValue");
        QFont font;
        font.setPointSize(14);
        font.setBold(true);
        totalInterventionsValue->setFont(font);

        hboxLayout10->addWidget(totalInterventionsValue);

        labelCoutTotal = new QLabel(tabHistorique);
        labelCoutTotal->setObjectName("labelCoutTotal");

        hboxLayout10->addWidget(labelCoutTotal);

        coutTotalValue = new QLabel(tabHistorique);
        coutTotalValue->setObjectName("coutTotalValue");
        coutTotalValue->setFont(font);

        hboxLayout10->addWidget(coutTotalValue);

        horizontalSpacer_Total = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout10->addItem(horizontalSpacer_Total);


        historiqueLayout->addLayout(hboxLayout10);

        tabWidget->addTab(tabHistorique, QString());
        tabStatistics = new QWidget();
        tabStatistics->setObjectName("tabStatistics");
        statisticsLayout = new QVBoxLayout(tabStatistics);
        statisticsLayout->setObjectName("statisticsLayout");
        groupBoxStatsCards = new QGroupBox(tabStatistics);
        groupBoxStatsCards->setObjectName("groupBoxStatsCards");
        statsCardsLayout = new QHBoxLayout(groupBoxStatsCards);
        statsCardsLayout->setObjectName("statsCardsLayout");
        cardTotal = new QFrame(groupBoxStatsCards);
        cardTotal->setObjectName("cardTotal");
        cardTotal->setMinimumHeight(120);
        vboxLayout11 = new QVBoxLayout(cardTotal);
        vboxLayout11->setObjectName("vboxLayout11");
        labelTotalIcon = new QLabel(cardTotal);
        labelTotalIcon->setObjectName("labelTotalIcon");
        QFont font1;
        font1.setPointSize(24);
        labelTotalIcon->setFont(font1);
        labelTotalIcon->setAlignment(Qt::AlignCenter);

        vboxLayout11->addWidget(labelTotalIcon);

        labelTotalTitle = new QLabel(cardTotal);
        labelTotalTitle->setObjectName("labelTotalTitle");
        labelTotalTitle->setAlignment(Qt::AlignCenter);

        vboxLayout11->addWidget(labelTotalTitle);

        statTotal = new QLabel(cardTotal);
        statTotal->setObjectName("statTotal");
        QFont font2;
        font2.setPointSize(28);
        font2.setBold(true);
        statTotal->setFont(font2);
        statTotal->setAlignment(Qt::AlignCenter);

        vboxLayout11->addWidget(statTotal);


        statsCardsLayout->addWidget(cardTotal);

        cardOperational = new QFrame(groupBoxStatsCards);
        cardOperational->setObjectName("cardOperational");
        cardOperational->setMinimumHeight(120);
        vboxLayout12 = new QVBoxLayout(cardOperational);
        vboxLayout12->setObjectName("vboxLayout12");
        labelOpIcon = new QLabel(cardOperational);
        labelOpIcon->setObjectName("labelOpIcon");
        labelOpIcon->setFont(font1);
        labelOpIcon->setAlignment(Qt::AlignCenter);

        vboxLayout12->addWidget(labelOpIcon);

        labelOpTitle = new QLabel(cardOperational);
        labelOpTitle->setObjectName("labelOpTitle");
        labelOpTitle->setAlignment(Qt::AlignCenter);

        vboxLayout12->addWidget(labelOpTitle);

        statOp = new QLabel(cardOperational);
        statOp->setObjectName("statOp");
        statOp->setFont(font2);
        statOp->setAlignment(Qt::AlignCenter);

        vboxLayout12->addWidget(statOp);


        statsCardsLayout->addWidget(cardOperational);

        cardMaintenance = new QFrame(groupBoxStatsCards);
        cardMaintenance->setObjectName("cardMaintenance");
        cardMaintenance->setMinimumHeight(120);
        vboxLayout13 = new QVBoxLayout(cardMaintenance);
        vboxLayout13->setObjectName("vboxLayout13");
        labelMaintIcon = new QLabel(cardMaintenance);
        labelMaintIcon->setObjectName("labelMaintIcon");
        labelMaintIcon->setFont(font1);
        labelMaintIcon->setAlignment(Qt::AlignCenter);

        vboxLayout13->addWidget(labelMaintIcon);

        labelMaintTitle = new QLabel(cardMaintenance);
        labelMaintTitle->setObjectName("labelMaintTitle");
        labelMaintTitle->setAlignment(Qt::AlignCenter);

        vboxLayout13->addWidget(labelMaintTitle);

        statMaint = new QLabel(cardMaintenance);
        statMaint->setObjectName("statMaint");
        statMaint->setFont(font2);
        statMaint->setAlignment(Qt::AlignCenter);

        vboxLayout13->addWidget(statMaint);


        statsCardsLayout->addWidget(cardMaintenance);

        cardDefective = new QFrame(groupBoxStatsCards);
        cardDefective->setObjectName("cardDefective");
        cardDefective->setMinimumHeight(120);
        vboxLayout14 = new QVBoxLayout(cardDefective);
        vboxLayout14->setObjectName("vboxLayout14");
        labelDefIcon = new QLabel(cardDefective);
        labelDefIcon->setObjectName("labelDefIcon");
        labelDefIcon->setFont(font1);
        labelDefIcon->setAlignment(Qt::AlignCenter);

        vboxLayout14->addWidget(labelDefIcon);

        labelDefTitle = new QLabel(cardDefective);
        labelDefTitle->setObjectName("labelDefTitle");
        labelDefTitle->setAlignment(Qt::AlignCenter);

        vboxLayout14->addWidget(labelDefTitle);

        statDef = new QLabel(cardDefective);
        statDef->setObjectName("statDef");
        statDef->setFont(font2);
        statDef->setAlignment(Qt::AlignCenter);

        vboxLayout14->addWidget(statDef);


        statsCardsLayout->addWidget(cardDefective);


        statisticsLayout->addWidget(groupBoxStatsCards);

        statisticsSplitter = new QSplitter(tabStatistics);
        statisticsSplitter->setObjectName("statisticsSplitter");
        statisticsSplitter->setOrientation(Qt::Horizontal);
        groupBoxCategories = new QGroupBox(statisticsSplitter);
        groupBoxCategories->setObjectName("groupBoxCategories");
        vboxLayout15 = new QVBoxLayout(groupBoxCategories);
        vboxLayout15->setObjectName("vboxLayout15");
        statsCategories = new QTextEdit(groupBoxCategories);
        statsCategories->setObjectName("statsCategories");
        statsCategories->setReadOnly(true);
        statsCategories->setMinimumHeight(200);

        vboxLayout15->addWidget(statsCategories);

        statisticsSplitter->addWidget(groupBoxCategories);
        groupBoxEtats = new QGroupBox(statisticsSplitter);
        groupBoxEtats->setObjectName("groupBoxEtats");
        vboxLayout16 = new QVBoxLayout(groupBoxEtats);
        vboxLayout16->setObjectName("vboxLayout16");
        statsBreakdowns = new QTextEdit(groupBoxEtats);
        statsBreakdowns->setObjectName("statsBreakdowns");
        statsBreakdowns->setReadOnly(true);
        statsBreakdowns->setMinimumHeight(200);

        vboxLayout16->addWidget(statsBreakdowns);

        statisticsSplitter->addWidget(groupBoxEtats);

        statisticsLayout->addWidget(statisticsSplitter);

        groupBoxTrends = new QGroupBox(tabStatistics);
        groupBoxTrends->setObjectName("groupBoxTrends");
        vboxLayout17 = new QVBoxLayout(groupBoxTrends);
        vboxLayout17->setObjectName("vboxLayout17");
        trendChartPlaceholder = new QTextEdit(groupBoxTrends);
        trendChartPlaceholder->setObjectName("trendChartPlaceholder");
        trendChartPlaceholder->setReadOnly(true);
        trendChartPlaceholder->setMinimumHeight(150);

        vboxLayout17->addWidget(trendChartPlaceholder);


        statisticsLayout->addWidget(groupBoxTrends);

        groupBoxKPIs = new QGroupBox(tabStatistics);
        groupBoxKPIs->setObjectName("groupBoxKPIs");
        kpiLayout = new QHBoxLayout(groupBoxKPIs);
        kpiLayout->setObjectName("kpiLayout");
        kpiInterventions = new QFrame(groupBoxKPIs);
        kpiInterventions->setObjectName("kpiInterventions");
        vboxLayout18 = new QVBoxLayout(kpiInterventions);
        vboxLayout18->setObjectName("vboxLayout18");
        labelKpiInterventions = new QLabel(kpiInterventions);
        labelKpiInterventions->setObjectName("labelKpiInterventions");
        labelKpiInterventions->setAlignment(Qt::AlignCenter);

        vboxLayout18->addWidget(labelKpiInterventions);

        kpiInterventionsValue = new QLabel(kpiInterventions);
        kpiInterventionsValue->setObjectName("kpiInterventionsValue");
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        kpiInterventionsValue->setFont(font3);
        kpiInterventionsValue->setAlignment(Qt::AlignCenter);

        vboxLayout18->addWidget(kpiInterventionsValue);


        kpiLayout->addWidget(kpiInterventions);

        kpiCoutTotal = new QFrame(groupBoxKPIs);
        kpiCoutTotal->setObjectName("kpiCoutTotal");
        vboxLayout19 = new QVBoxLayout(kpiCoutTotal);
        vboxLayout19->setObjectName("vboxLayout19");
        labelKpiCoutTotal = new QLabel(kpiCoutTotal);
        labelKpiCoutTotal->setObjectName("labelKpiCoutTotal");
        labelKpiCoutTotal->setAlignment(Qt::AlignCenter);

        vboxLayout19->addWidget(labelKpiCoutTotal);

        kpiCoutTotalValue = new QLabel(kpiCoutTotal);
        kpiCoutTotalValue->setObjectName("kpiCoutTotalValue");
        kpiCoutTotalValue->setFont(font3);
        kpiCoutTotalValue->setAlignment(Qt::AlignCenter);

        vboxLayout19->addWidget(kpiCoutTotalValue);


        kpiLayout->addWidget(kpiCoutTotal);

        kpiDisponibilite = new QFrame(groupBoxKPIs);
        kpiDisponibilite->setObjectName("kpiDisponibilite");
        vboxLayout20 = new QVBoxLayout(kpiDisponibilite);
        vboxLayout20->setObjectName("vboxLayout20");
        labelKpiDisponibilite = new QLabel(kpiDisponibilite);
        labelKpiDisponibilite->setObjectName("labelKpiDisponibilite");
        labelKpiDisponibilite->setAlignment(Qt::AlignCenter);

        vboxLayout20->addWidget(labelKpiDisponibilite);

        kpiDisponibiliteValue = new QLabel(kpiDisponibilite);
        kpiDisponibiliteValue->setObjectName("kpiDisponibiliteValue");
        kpiDisponibiliteValue->setFont(font3);
        kpiDisponibiliteValue->setAlignment(Qt::AlignCenter);

        vboxLayout20->addWidget(kpiDisponibiliteValue);


        kpiLayout->addWidget(kpiDisponibilite);

        kpiTauxPanne = new QFrame(groupBoxKPIs);
        kpiTauxPanne->setObjectName("kpiTauxPanne");
        vboxLayout21 = new QVBoxLayout(kpiTauxPanne);
        vboxLayout21->setObjectName("vboxLayout21");
        labelKpiTauxPanne = new QLabel(kpiTauxPanne);
        labelKpiTauxPanne->setObjectName("labelKpiTauxPanne");
        labelKpiTauxPanne->setAlignment(Qt::AlignCenter);

        vboxLayout21->addWidget(labelKpiTauxPanne);

        kpiTauxPanneValue = new QLabel(kpiTauxPanne);
        kpiTauxPanneValue->setObjectName("kpiTauxPanneValue");
        kpiTauxPanneValue->setFont(font3);
        kpiTauxPanneValue->setAlignment(Qt::AlignCenter);

        vboxLayout21->addWidget(kpiTauxPanneValue);


        kpiLayout->addWidget(kpiTauxPanne);


        statisticsLayout->addWidget(groupBoxKPIs);

        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setObjectName("hboxLayout11");
        btnExportPDF_Stats = new QPushButton(tabStatistics);
        btnExportPDF_Stats->setObjectName("btnExportPDF_Stats");

        hboxLayout11->addWidget(btnExportPDF_Stats);

        btnRefresh_Stats = new QPushButton(tabStatistics);
        btnRefresh_Stats->setObjectName("btnRefresh_Stats");

        hboxLayout11->addWidget(btnRefresh_Stats);

        horizontalSpacer_Stats = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout11->addItem(horizontalSpacer_Stats);


        statisticsLayout->addLayout(hboxLayout11);

        verticalSpacerStats = new QSpacerItem(20, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        statisticsLayout->addItem(verticalSpacerStats);

        tabWidget->addTab(tabStatistics, QString());

        vboxLayout7->addWidget(tabWidget);

        splitter->addWidget(centerPanel);
        rightPanel = new QWidget(splitter);
        rightPanel->setObjectName("rightPanel");
        vboxLayout22 = new QVBoxLayout(rightPanel);
        vboxLayout22->setObjectName("vboxLayout22");
        vboxLayout22->setContentsMargins(0, 0, 0, 0);
        groupBoxActions = new QGroupBox(rightPanel);
        groupBoxActions->setObjectName("groupBoxActions");
        vboxLayout23 = new QVBoxLayout(groupBoxActions);
        vboxLayout23->setObjectName("vboxLayout23");
        btnQuickEdit = new QPushButton(groupBoxActions);
        btnQuickEdit->setObjectName("btnQuickEdit");

        vboxLayout23->addWidget(btnQuickEdit);

        btnQuickDelete = new QPushButton(groupBoxActions);
        btnQuickDelete->setObjectName("btnQuickDelete");

        vboxLayout23->addWidget(btnQuickDelete);

        btnReportProblem = new QPushButton(groupBoxActions);
        btnReportProblem->setObjectName("btnReportProblem");

        vboxLayout23->addWidget(btnReportProblem);


        vboxLayout22->addWidget(groupBoxActions);

        groupBoxQuickInfo = new QGroupBox(rightPanel);
        groupBoxQuickInfo->setObjectName("groupBoxQuickInfo");
        vboxLayout24 = new QVBoxLayout(groupBoxQuickInfo);
        vboxLayout24->setObjectName("vboxLayout24");
        labelEtat = new QLabel(groupBoxQuickInfo);
        labelEtat->setObjectName("labelEtat");

        vboxLayout24->addWidget(labelEtat);

        quickState = new QLabel(groupBoxQuickInfo);
        quickState->setObjectName("quickState");
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        quickState->setFont(font4);

        vboxLayout24->addWidget(quickState);

        labelLocalisation = new QLabel(groupBoxQuickInfo);
        labelLocalisation->setObjectName("labelLocalisation");

        vboxLayout24->addWidget(labelLocalisation);

        quickLocation = new QLabel(groupBoxQuickInfo);
        quickLocation->setObjectName("quickLocation");
        QFont font5;
        font5.setPointSize(12);
        quickLocation->setFont(font5);

        vboxLayout24->addWidget(quickLocation);

        labelInterventions = new QLabel(groupBoxQuickInfo);
        labelInterventions->setObjectName("labelInterventions");

        vboxLayout24->addWidget(labelInterventions);

        quickBreakdowns = new QLabel(groupBoxQuickInfo);
        quickBreakdowns->setObjectName("quickBreakdowns");
        quickBreakdowns->setFont(font4);

        vboxLayout24->addWidget(quickBreakdowns);


        vboxLayout22->addWidget(groupBoxQuickInfo);

        btnScanQR_RightPanel = new QPushButton(rightPanel);
        btnScanQR_RightPanel->setObjectName("btnScanQR_RightPanel");
        btnScanQR_RightPanel->setMinimumHeight(45);

        vboxLayout22->addWidget(btnScanQR_RightPanel);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout22->addItem(verticalSpacer_2);

        splitter->addWidget(rightPanel);

        machineLayout->addWidget(splitter);

        stackedPages->addWidget(pageMachine);

        mainLayout->addWidget(stackedPages);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1400, 26));
        menuFichier = new QMenu(menubar);
        menuFichier->setObjectName("menuFichier");
        menuEdition = new QMenu(menubar);
        menuEdition->setObjectName("menuEdition");
        menuAffichage = new QMenu(menubar);
        menuAffichage->setObjectName("menuAffichage");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuAffichage->menuAction());
        menuFichier->addAction(actionExportPDF);
        menuFichier->addSeparator();
        menuFichier->addAction(actionExit);
        menuAffichage->addAction(actionRefresh);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion Machines", nullptr));
        actionExportPDF->setText(QCoreApplication::translate("MainWindow", "&Exporter PDF", nullptr));
#if QT_CONFIG(shortcut)
        actionExportPDF->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "&Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "&Actualiser", nullptr));
#if QT_CONFIG(shortcut)
        actionRefresh->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        sideMenu->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #A2B29F;", nullptr));
        labelLogo->setText(QString());
        labelLogo->setStyleSheet(QCoreApplication::translate("MainWindow", "padding: 10px 10px;", nullptr));
        btnEmployee->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        btnEmployee->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        btnTeam->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnTeam->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnClient->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnLaboratory->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnLaboratory->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        btnOrder->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnOrder->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        btnMachine->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        labelPageEmployee->setText(QCoreApplication::translate("MainWindow", "Page Employ\303\251", nullptr));
        labelPageEmployee->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #798777; font-weight: bold;", nullptr));
        labelPageTeam->setText(QCoreApplication::translate("MainWindow", "Page \303\211quipe", nullptr));
        labelPageTeam->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #798777; font-weight: bold;", nullptr));
        labelPageClient->setText(QCoreApplication::translate("MainWindow", "Page Client", nullptr));
        labelPageClient->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #798777; font-weight: bold;", nullptr));
        labelPageLaboratory->setText(QCoreApplication::translate("MainWindow", "Page Laboratoire", nullptr));
        labelPageLaboratory->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #798777; font-weight: bold;", nullptr));
        labelPageOrder->setText(QCoreApplication::translate("MainWindow", "Page Commande", nullptr));
        labelPageOrder->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 24px; color: #798777; font-weight: bold;", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\215 Recherche et Filtres", nullptr));
        groupBoxSearch->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        labelSearch->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        labelSearch->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom, r\303\251f\303\251rence\342\200\246", nullptr));
        lineEditSearch->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelCategory->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        labelCategory->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        comboCategory->setItemText(0, QCoreApplication::translate("MainWindow", "Toutes", nullptr));
        comboCategory->setItemText(1, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboCategory->setItemText(2, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboCategory->setItemText(3, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboCategory->setItemText(4, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboCategory->setItemText(5, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        comboCategory->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelState->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        labelState->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        comboState->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        comboState->setItemText(1, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboState->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboState->setItemText(3, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboState->setItemText(4, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        comboState->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelLocation->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        labelLocation->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        lineEditLocation->setPlaceholderText(QCoreApplication::translate("MainWindow", "Atelier, Ligne 1\342\200\246", nullptr));
        lineEditLocation->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        btnApplyFilter->setText(QCoreApplication::translate("MainWindow", "\342\234\205 Appliquer", nullptr));
        btnApplyFilter->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border-radius: 5px; padding: 8px; font-weight: bold; } QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        btnResetFilter->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 R\303\251initialiser", nullptr));
        btnResetFilter->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border-radius: 5px; padding: 8px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        groupBoxSort->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 Tri", nullptr));
        groupBoxSort->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        labelSortBy->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        labelSortBy->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        comboSortBy->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboSortBy->setItemText(1, QCoreApplication::translate("MainWindow", "Date d'achat", nullptr));
        comboSortBy->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        comboSortBy->setItemText(3, QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        comboSortBy->setItemText(4, QCoreApplication::translate("MainWindow", "Localisation", nullptr));

        comboSortBy->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        radioCroissant->setText(QCoreApplication::translate("MainWindow", "\342\254\206\357\270\217 Croissant", nullptr));
        radioCroissant->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        radioDecroissant->setText(QCoreApplication::translate("MainWindow", "\342\254\207\357\270\217 D\303\251croissant", nullptr));
        radioDecroissant->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        tabWidget->setStyleSheet(QCoreApplication::translate("MainWindow", "QTabWidget::pane { border: 1px solid #BDD2B6; border-radius: 5px; padding: 10px; background: white; }\n"
"QTabBar::tab { background: #F8EDE3; color: #798777; padding: 10px 20px; margin-right: 2px; border-top-left-radius: 5px; border-top-right-radius: 5px; }\n"
"QTabBar::tab:selected { background: #A2B29F; color: #F8EDE3; }\n"
"QTabBar::tab:hover:!selected { background: #BDD2B6; color: #798777; }", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEquipments->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID Mat\303\251riel", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEquipments->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEquipments->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEquipments->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEquipments->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Date Achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEquipments->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableEquipments->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableEquipments->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Garantie Fin", nullptr));
        tableEquipments->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget::item { padding: 5px; }\n"
"QHeaderView::section { background-color: #A2B29F; color: #F8EDE3; font-weight: bold; padding: 8px; border: none; }", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btnExportPDF->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #798777; color: #F8EDE3; border-radius: 5px; padding: 8px 15px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnRefresh->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 Actualiser", nullptr));
        btnRefresh->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border-radius: 5px; padding: 8px 15px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabList), QCoreApplication::translate("MainWindow", "\360\237\224\247 Liste des Machines", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "Informations G\303\251n\303\251rales", nullptr));
        groupBoxInfo->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        labelID->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        labelID->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailId->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; background: #F8EDE3; }", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        labelName->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailName->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelReference->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence :", nullptr));
        labelReference->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailReference->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelDetailCategory->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        labelDetailCategory->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailCategory->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelDetailState->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        labelDetailState->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailState->setStyleSheet(QCoreApplication::translate("MainWindow", "QComboBox { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelDetailLocation->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        labelDetailLocation->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailLocation->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        labelWarrantyEnd->setText(QCoreApplication::translate("MainWindow", "Garantie Fin :", nullptr));
        labelWarrantyEnd->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailWarrantyEnd->setStyleSheet(QCoreApplication::translate("MainWindow", "QDateEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        groupBoxFinance->setTitle(QCoreApplication::translate("MainWindow", "Date d'Achat", nullptr));
        groupBoxFinance->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        labelPurchaseDate->setText(QCoreApplication::translate("MainWindow", "Date d'Achat :", nullptr));
        labelPurchaseDate->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailPurchaseDate->setStyleSheet(QCoreApplication::translate("MainWindow", "QDateEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; }", nullptr));
        groupBoxTraceability->setTitle(QCoreApplication::translate("MainWindow", "Tra\303\247abilit\303\251", nullptr));
        groupBoxTraceability->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        labelQRCode->setText(QCoreApplication::translate("MainWindow", "Code QR :", nullptr));
        labelQRCode->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        detailQR->setStyleSheet(QCoreApplication::translate("MainWindow", "QLineEdit { border: 2px solid #BDD2B6; border-radius: 5px; padding: 5px; background: #F8EDE3; }", nullptr));
        btnAddMachineFromDetails->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter une machine", nullptr));
        btnAddMachineFromDetails->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { \n"
"                       background-color: #A2B29F; \n"
"                       color: #F8EDE3; \n"
"                       border-radius: 5px; \n"
"                       padding: 12px 25px; \n"
"                       font-weight: bold; \n"
"                       font-size: 14px;\n"
"                     } \n"
"                     QPushButton:hover { \n"
"                       background-color: #BDD2B6; \n"
"                       color: #798777; \n"
"                     }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QCoreApplication::translate("MainWindow", "\342\204\271\357\270\217 D\303\251tails Machine", nullptr));
        btnAddIntervention->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter", nullptr));
        btnAddIntervention->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { padding: 8px 15px; background-color: #A2B29F; color: #F8EDE3; border-radius: 5px; font-weight: bold; }\n"
"QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        btnDeleteIntervention->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Supprimer", nullptr));
        btnDeleteIntervention->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { padding: 8px 15px; background-color: #798777; color: #F8EDE3; border-radius: 5px; font-weight: bold; }\n"
"QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnViewDetails->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Voir d\303\251tails", nullptr));
        btnViewDetails->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { padding: 8px 15px; background-color: #BDD2B6; color: #798777; border-radius: 5px; font-weight: bold; }\n"
"QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnExportPDF_Historique->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btnExportPDF_Historique->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #798777; color: #F8EDE3; border-radius: 5px; padding: 8px 15px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnRefresh_Historique->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 Actualiser", nullptr));
        btnRefresh_Historique->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border-radius: 5px; padding: 8px 15px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableHistorique->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableHistorique->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableHistorique->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableHistorique->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableHistorique->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableHistorique->horizontalHeaderItem(5);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Co\303\273t", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableHistorique->horizontalHeaderItem(6);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        tableHistorique->setStyleSheet(QCoreApplication::translate("MainWindow", "QTableWidget::item { padding: 5px; }\n"
"QHeaderView::section { background-color: #A2B29F; color: #F8EDE3; font-weight: bold; padding: 8px; border: none; }", nullptr));
        labelTotalInterventions->setText(QCoreApplication::translate("MainWindow", "Total:", nullptr));
        labelTotalInterventions->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 14px; color: #798777;", nullptr));
        totalInterventionsValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        totalInterventionsValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        labelCoutTotal->setText(QCoreApplication::translate("MainWindow", "Co\303\273t total:", nullptr));
        labelCoutTotal->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold; font-size: 14px; margin-left: 20px; color: #798777;", nullptr));
        coutTotalValue->setText(QCoreApplication::translate("MainWindow", "0.00 \342\202\254", nullptr));
        coutTotalValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistorique), QCoreApplication::translate("MainWindow", "\360\237\223\213 Historique des Interventions", nullptr));
        groupBoxStatsCards->setTitle(QCoreApplication::translate("MainWindow", "\360\237\216\257 Tableau de Bord", nullptr));
        groupBoxStatsCards->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        cardTotal->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 10px; border: 1px solid #BDD2B6; padding: 10px; }", nullptr));
        labelTotalIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\226\245\357\270\217", nullptr));
        labelTotalTitle->setText(QCoreApplication::translate("MainWindow", "Total Machines", nullptr));
        labelTotalTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        statTotal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        statTotal->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        cardOperational->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 10px; border: 1px solid #BDD2B6; padding: 10px; }", nullptr));
        labelOpIcon->setText(QCoreApplication::translate("MainWindow", "\342\234\205", nullptr));
        labelOpTitle->setText(QCoreApplication::translate("MainWindow", "Op\303\251rationnels", nullptr));
        labelOpTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        statOp->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        statOp->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        cardMaintenance->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 10px; border: 1px solid #BDD2B6; padding: 10px; }", nullptr));
        labelMaintIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\224\247", nullptr));
        labelMaintTitle->setText(QCoreApplication::translate("MainWindow", "En Maintenance", nullptr));
        labelMaintTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        statMaint->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        statMaint->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        cardDefective->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 10px; border: 1px solid #BDD2B6; padding: 10px; }", nullptr));
        labelDefIcon->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217", nullptr));
        labelDefTitle->setText(QCoreApplication::translate("MainWindow", "D\303\251fectueux", nullptr));
        labelDefTitle->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        statDef->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        statDef->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        groupBoxCategories->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 R\303\251partition par Cat\303\251gorie", nullptr));
        groupBoxCategories->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        statsCategories->setStyleSheet(QCoreApplication::translate("MainWindow", "QTextEdit { border: 1px solid #BDD2B6; border-radius: 5px; background: #F8EDE3; }", nullptr));
        groupBoxEtats->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\247 \303\211tat des Machines", nullptr));
        groupBoxEtats->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        statsBreakdowns->setStyleSheet(QCoreApplication::translate("MainWindow", "QTextEdit { border: 1px solid #BDD2B6; border-radius: 5px; background: #F8EDE3; }", nullptr));
        groupBoxTrends->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\210 Tendance des Interventions", nullptr));
        groupBoxTrends->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        trendChartPlaceholder->setStyleSheet(QCoreApplication::translate("MainWindow", "QTextEdit { border: 1px solid #BDD2B6; border-radius: 5px; background: #F8EDE3; }", nullptr));
        groupBoxKPIs->setTitle(QCoreApplication::translate("MainWindow", "\360\237\216\257 Indicateurs de Performance", nullptr));
        groupBoxKPIs->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        kpiInterventions->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 8px; border: 1px solid #BDD2B6; padding: 15px; }", nullptr));
        labelKpiInterventions->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 Interventions", nullptr));
        labelKpiInterventions->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        kpiInterventionsValue->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        kpiInterventionsValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        kpiCoutTotal->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 8px; border: 1px solid #BDD2B6; padding: 15px; }", nullptr));
        labelKpiCoutTotal->setText(QCoreApplication::translate("MainWindow", "\360\237\222\260 Co\303\273t total", nullptr));
        labelKpiCoutTotal->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        kpiCoutTotalValue->setText(QCoreApplication::translate("MainWindow", "0.00 \342\202\254", nullptr));
        kpiCoutTotalValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        kpiDisponibilite->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 8px; border: 1px solid #BDD2B6; padding: 15px; }", nullptr));
        labelKpiDisponibilite->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Disponibilit\303\251", nullptr));
        labelKpiDisponibilite->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        kpiDisponibiliteValue->setText(QCoreApplication::translate("MainWindow", "98.5%", nullptr));
        kpiDisponibiliteValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        kpiTauxPanne->setStyleSheet(QCoreApplication::translate("MainWindow", "QFrame { background-color: #F8EDE3; border-radius: 8px; border: 1px solid #BDD2B6; padding: 15px; }", nullptr));
        labelKpiTauxPanne->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Taux de panne", nullptr));
        labelKpiTauxPanne->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; font-weight: bold;", nullptr));
        kpiTauxPanneValue->setText(QCoreApplication::translate("MainWindow", "3.2%", nullptr));
        kpiTauxPanneValue->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        btnExportPDF_Stats->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btnExportPDF_Stats->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #798777; color: #F8EDE3; border-radius: 5px; padding: 8px 15px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnRefresh_Stats->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 Actualiser", nullptr));
        btnRefresh_Stats->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border-radius: 5px; padding: 8px 15px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistics), QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques & Analyses", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "\342\232\241 Actions Rapides", nullptr));
        groupBoxActions->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        btnQuickEdit->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnQuickEdit->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border-radius: 5px; padding: 10px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnQuickDelete->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Supprimer", nullptr));
        btnQuickDelete->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #798777; color: #F8EDE3; border-radius: 5px; padding: 10px; font-weight: bold; } QPushButton:hover { background-color: #A2B29F; color: #F8EDE3; }", nullptr));
        btnReportProblem->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Signaler Panne", nullptr));
        btnReportProblem->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border-radius: 5px; padding: 10px; font-weight: bold; } QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        groupBoxQuickInfo->setTitle(QCoreApplication::translate("MainWindow", "\342\204\271\357\270\217 Infos Rapides", nullptr));
        groupBoxQuickInfo->setStyleSheet(QCoreApplication::translate("MainWindow", "QGroupBox { font-weight: bold; color: #798777; }", nullptr));
        labelEtat->setText(QCoreApplication::translate("MainWindow", "\360\237\223\214 \303\211tat :", nullptr));
        labelEtat->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        quickState->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        quickState->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        labelLocalisation->setText(QCoreApplication::translate("MainWindow", "\360\237\223\215 Localisation :", nullptr));
        labelLocalisation->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        quickLocation->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        quickLocation->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        labelInterventions->setText(QCoreApplication::translate("MainWindow", "\360\237\233\240\357\270\217 Interventions :", nullptr));
        labelInterventions->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        quickBreakdowns->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        quickBreakdowns->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #A2B29F;", nullptr));
        btnScanQR_RightPanel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\267 Scanner QR Code", nullptr));
        btnScanQR_RightPanel->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border-radius: 5px; padding: 12px; font-weight: bold; font-size: 14px; margin-top: 10px; } \n"
"QPushButton:hover { background-color: #BDD2B6; color: #798777; }", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "&Fichier", nullptr));
        menuEdition->setTitle(QCoreApplication::translate("MainWindow", "&\303\211dition", nullptr));
        menuAffichage->setTitle(QCoreApplication::translate("MainWindow", "&Affichage", nullptr));
        statusbar->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777; background: #F8EDE3;", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
