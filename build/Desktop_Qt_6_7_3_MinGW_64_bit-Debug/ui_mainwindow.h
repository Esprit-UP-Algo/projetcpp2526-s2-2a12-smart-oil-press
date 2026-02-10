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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionEdit;
    QAction *actionDelete;
    QAction *actionScan;
    QAction *actionExportPDF;
    QAction *actionRefresh;
    QAction *actionExit;
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
    QToolBar *toolBar;
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
    QLabel *labelResponsibleTeam;
    QComboBox *detailResponsibleTeam;
    QGroupBox *groupBoxFinance;
    QFormLayout *formLayout1;
    QLabel *labelPurchaseDate;
    QDateEdit *detailPurchaseDate;
    QGroupBox *groupBoxTraceability;
    QFormLayout *formLayout2;
    QLabel *labelQRCode;
    QLineEdit *detailQR;
    QLabel *labelBarcode;
    QLineEdit *detailBarCode;
    QPushButton *btnScan;
    QSpacerItem *spacerItem;
    QWidget *tabMaintenance;
    QVBoxLayout *vboxLayout11;
    QGroupBox *groupBoxNextMaint;
    QFormLayout *formLayout3;
    QLabel *labelLastMaint;
    QLineEdit *detailLastMaint;
    QLabel *labelNextMaintDate;
    QDateEdit *detailNextMaint;
    QPushButton *btnScheduleMaint;
    QGroupBox *groupBoxHistoriqueMaint;
    QVBoxLayout *vboxLayout12;
    QTableWidget *tableMaintenance;
    QHBoxLayout *hboxLayout7;
    QPushButton *btnAddMaint;
    QPushButton *btnRemoveMaint;
    QWidget *tabStatistics;
    QVBoxLayout *vboxLayout13;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayout;
    QLabel *labelStatTotal;
    QLabel *statTotal;
    QLabel *labelStatOp;
    QLabel *statOp;
    QLabel *labelStatMaint;
    QLabel *statMaint;
    QLabel *labelStatDef;
    QLabel *statDef;
    QGroupBox *groupBoxStatsByCat;
    QVBoxLayout *vboxLayout14;
    QTextEdit *statsCategories;
    QGroupBox *groupBoxStatsBreakdown;
    QVBoxLayout *vboxLayout15;
    QTextEdit *statsBreakdowns;
    QSpacerItem *spacerItem1;
    QWidget *rightPanel;
    QVBoxLayout *vboxLayout16;
    QGroupBox *groupBoxActions;
    QVBoxLayout *vboxLayout17;
    QPushButton *btnNewEquipment;
    QPushButton *btnEditEquipment;
    QPushButton *btnDeleteEquipment;
    QPushButton *btnReportProblem;
    QGroupBox *groupBoxQuickInfo;
    QVBoxLayout *vboxLayout18;
    QLabel *label;
    QLabel *quickState;
    QLabel *label1;
    QLabel *quickLocation;
    QLabel *label2;
    QLabel *quickNextMaint;
    QLabel *label3;
    QLabel *quickBreakdowns;
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
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName("actionEdit");
        actionDelete = new QAction(MainWindow);
        actionDelete->setObjectName("actionDelete");
        actionScan = new QAction(MainWindow);
        actionScan->setObjectName("actionScan");
        actionExportPDF = new QAction(MainWindow);
        actionExportPDF->setObjectName("actionExportPDF");
        actionRefresh = new QAction(MainWindow);
        actionRefresh->setObjectName("actionRefresh");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
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
        toolBar = new QToolBar(pageMachine);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(24, 24));

        machineLayout->addWidget(toolBar);

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

        vboxLayout8->addWidget(tableEquipments);

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

        labelResponsibleTeam = new QLabel(groupBoxInfo);
        labelResponsibleTeam->setObjectName("labelResponsibleTeam");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelResponsibleTeam);

        detailResponsibleTeam = new QComboBox(groupBoxInfo);
        detailResponsibleTeam->setObjectName("detailResponsibleTeam");

        formLayout->setWidget(7, QFormLayout::FieldRole, detailResponsibleTeam);


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

        labelBarcode = new QLabel(groupBoxTraceability);
        labelBarcode->setObjectName("labelBarcode");

        formLayout2->setWidget(1, QFormLayout::LabelRole, labelBarcode);

        detailBarCode = new QLineEdit(groupBoxTraceability);
        detailBarCode->setObjectName("detailBarCode");
        detailBarCode->setReadOnly(true);

        formLayout2->setWidget(1, QFormLayout::FieldRole, detailBarCode);

        btnScan = new QPushButton(groupBoxTraceability);
        btnScan->setObjectName("btnScan");

        formLayout2->setWidget(2, QFormLayout::SpanningRole, btnScan);


        vboxLayout10->addWidget(groupBoxTraceability);

        spacerItem = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout10->addItem(spacerItem);

        scrollArea->setWidget(scrollAreaWidgetContents);

        vboxLayout9->addWidget(scrollArea);

        tabWidget->addTab(tabDetails, QString());
        tabMaintenance = new QWidget();
        tabMaintenance->setObjectName("tabMaintenance");
        vboxLayout11 = new QVBoxLayout(tabMaintenance);
        vboxLayout11->setObjectName("vboxLayout11");
        groupBoxNextMaint = new QGroupBox(tabMaintenance);
        groupBoxNextMaint->setObjectName("groupBoxNextMaint");
        formLayout3 = new QFormLayout(groupBoxNextMaint);
        formLayout3->setObjectName("formLayout3");
        labelLastMaint = new QLabel(groupBoxNextMaint);
        labelLastMaint->setObjectName("labelLastMaint");

        formLayout3->setWidget(0, QFormLayout::LabelRole, labelLastMaint);

        detailLastMaint = new QLineEdit(groupBoxNextMaint);
        detailLastMaint->setObjectName("detailLastMaint");
        detailLastMaint->setReadOnly(true);

        formLayout3->setWidget(0, QFormLayout::FieldRole, detailLastMaint);

        labelNextMaintDate = new QLabel(groupBoxNextMaint);
        labelNextMaintDate->setObjectName("labelNextMaintDate");

        formLayout3->setWidget(1, QFormLayout::LabelRole, labelNextMaintDate);

        detailNextMaint = new QDateEdit(groupBoxNextMaint);
        detailNextMaint->setObjectName("detailNextMaint");

        formLayout3->setWidget(1, QFormLayout::FieldRole, detailNextMaint);

        btnScheduleMaint = new QPushButton(groupBoxNextMaint);
        btnScheduleMaint->setObjectName("btnScheduleMaint");

        formLayout3->setWidget(2, QFormLayout::SpanningRole, btnScheduleMaint);


        vboxLayout11->addWidget(groupBoxNextMaint);

        groupBoxHistoriqueMaint = new QGroupBox(tabMaintenance);
        groupBoxHistoriqueMaint->setObjectName("groupBoxHistoriqueMaint");
        vboxLayout12 = new QVBoxLayout(groupBoxHistoriqueMaint);
        vboxLayout12->setObjectName("vboxLayout12");
        tableMaintenance = new QTableWidget(groupBoxHistoriqueMaint);
        if (tableMaintenance->columnCount() < 5)
            tableMaintenance->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        tableMaintenance->setObjectName("tableMaintenance");
        tableMaintenance->setColumnCount(5);

        vboxLayout12->addWidget(tableMaintenance);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName("hboxLayout7");
        btnAddMaint = new QPushButton(groupBoxHistoriqueMaint);
        btnAddMaint->setObjectName("btnAddMaint");

        hboxLayout7->addWidget(btnAddMaint);

        btnRemoveMaint = new QPushButton(groupBoxHistoriqueMaint);
        btnRemoveMaint->setObjectName("btnRemoveMaint");

        hboxLayout7->addWidget(btnRemoveMaint);


        vboxLayout12->addLayout(hboxLayout7);


        vboxLayout11->addWidget(groupBoxHistoriqueMaint);

        tabWidget->addTab(tabMaintenance, QString());
        tabStatistics = new QWidget();
        tabStatistics->setObjectName("tabStatistics");
        vboxLayout13 = new QVBoxLayout(tabStatistics);
        vboxLayout13->setObjectName("vboxLayout13");
        groupBoxStats = new QGroupBox(tabStatistics);
        groupBoxStats->setObjectName("groupBoxStats");
        gridLayout = new QGridLayout(groupBoxStats);
        gridLayout->setObjectName("gridLayout");
        labelStatTotal = new QLabel(groupBoxStats);
        labelStatTotal->setObjectName("labelStatTotal");

        gridLayout->addWidget(labelStatTotal, 0, 0, 1, 1);

        statTotal = new QLabel(groupBoxStats);
        statTotal->setObjectName("statTotal");

        gridLayout->addWidget(statTotal, 0, 1, 1, 1);

        labelStatOp = new QLabel(groupBoxStats);
        labelStatOp->setObjectName("labelStatOp");

        gridLayout->addWidget(labelStatOp, 0, 2, 1, 1);

        statOp = new QLabel(groupBoxStats);
        statOp->setObjectName("statOp");

        gridLayout->addWidget(statOp, 0, 3, 1, 1);

        labelStatMaint = new QLabel(groupBoxStats);
        labelStatMaint->setObjectName("labelStatMaint");

        gridLayout->addWidget(labelStatMaint, 1, 0, 1, 1);

        statMaint = new QLabel(groupBoxStats);
        statMaint->setObjectName("statMaint");

        gridLayout->addWidget(statMaint, 1, 1, 1, 1);

        labelStatDef = new QLabel(groupBoxStats);
        labelStatDef->setObjectName("labelStatDef");

        gridLayout->addWidget(labelStatDef, 1, 2, 1, 1);

        statDef = new QLabel(groupBoxStats);
        statDef->setObjectName("statDef");

        gridLayout->addWidget(statDef, 1, 3, 1, 1);


        vboxLayout13->addWidget(groupBoxStats);

        groupBoxStatsByCat = new QGroupBox(tabStatistics);
        groupBoxStatsByCat->setObjectName("groupBoxStatsByCat");
        vboxLayout14 = new QVBoxLayout(groupBoxStatsByCat);
        vboxLayout14->setObjectName("vboxLayout14");
        statsCategories = new QTextEdit(groupBoxStatsByCat);
        statsCategories->setObjectName("statsCategories");
        statsCategories->setReadOnly(true);

        vboxLayout14->addWidget(statsCategories);


        vboxLayout13->addWidget(groupBoxStatsByCat);

        groupBoxStatsBreakdown = new QGroupBox(tabStatistics);
        groupBoxStatsBreakdown->setObjectName("groupBoxStatsBreakdown");
        vboxLayout15 = new QVBoxLayout(groupBoxStatsBreakdown);
        vboxLayout15->setObjectName("vboxLayout15");
        statsBreakdowns = new QTextEdit(groupBoxStatsBreakdown);
        statsBreakdowns->setObjectName("statsBreakdowns");
        statsBreakdowns->setReadOnly(true);

        vboxLayout15->addWidget(statsBreakdowns);


        vboxLayout13->addWidget(groupBoxStatsBreakdown);

        spacerItem1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout13->addItem(spacerItem1);

        tabWidget->addTab(tabStatistics, QString());

        vboxLayout7->addWidget(tabWidget);

        splitter->addWidget(centerPanel);
        rightPanel = new QWidget(splitter);
        rightPanel->setObjectName("rightPanel");
        vboxLayout16 = new QVBoxLayout(rightPanel);
        vboxLayout16->setObjectName("vboxLayout16");
        vboxLayout16->setContentsMargins(0, 0, 0, 0);
        groupBoxActions = new QGroupBox(rightPanel);
        groupBoxActions->setObjectName("groupBoxActions");
        vboxLayout17 = new QVBoxLayout(groupBoxActions);
        vboxLayout17->setObjectName("vboxLayout17");
        btnNewEquipment = new QPushButton(groupBoxActions);
        btnNewEquipment->setObjectName("btnNewEquipment");

        vboxLayout17->addWidget(btnNewEquipment);

        btnEditEquipment = new QPushButton(groupBoxActions);
        btnEditEquipment->setObjectName("btnEditEquipment");

        vboxLayout17->addWidget(btnEditEquipment);

        btnDeleteEquipment = new QPushButton(groupBoxActions);
        btnDeleteEquipment->setObjectName("btnDeleteEquipment");

        vboxLayout17->addWidget(btnDeleteEquipment);

        btnReportProblem = new QPushButton(groupBoxActions);
        btnReportProblem->setObjectName("btnReportProblem");

        vboxLayout17->addWidget(btnReportProblem);


        vboxLayout16->addWidget(groupBoxActions);

        groupBoxQuickInfo = new QGroupBox(rightPanel);
        groupBoxQuickInfo->setObjectName("groupBoxQuickInfo");
        vboxLayout18 = new QVBoxLayout(groupBoxQuickInfo);
        vboxLayout18->setObjectName("vboxLayout18");
        label = new QLabel(groupBoxQuickInfo);
        label->setObjectName("label");

        vboxLayout18->addWidget(label);

        quickState = new QLabel(groupBoxQuickInfo);
        quickState->setObjectName("quickState");

        vboxLayout18->addWidget(quickState);

        label1 = new QLabel(groupBoxQuickInfo);
        label1->setObjectName("label1");

        vboxLayout18->addWidget(label1);

        quickLocation = new QLabel(groupBoxQuickInfo);
        quickLocation->setObjectName("quickLocation");

        vboxLayout18->addWidget(quickLocation);

        label2 = new QLabel(groupBoxQuickInfo);
        label2->setObjectName("label2");

        vboxLayout18->addWidget(label2);

        quickNextMaint = new QLabel(groupBoxQuickInfo);
        quickNextMaint->setObjectName("quickNextMaint");

        vboxLayout18->addWidget(quickNextMaint);

        label3 = new QLabel(groupBoxQuickInfo);
        label3->setObjectName("label3");

        vboxLayout18->addWidget(label3);

        quickBreakdowns = new QLabel(groupBoxQuickInfo);
        quickBreakdowns->setObjectName("quickBreakdowns");

        vboxLayout18->addWidget(quickBreakdowns);


        vboxLayout16->addWidget(groupBoxQuickInfo);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout16->addItem(verticalSpacer_2);

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

        toolBar->addAction(actionNew);
        toolBar->addAction(actionEdit);
        toolBar->addAction(actionDelete);
        toolBar->addSeparator();
        toolBar->addAction(actionScan);
        toolBar->addSeparator();
        toolBar->addAction(actionExportPDF);
        toolBar->addAction(actionRefresh);
        menubar->addAction(menuFichier->menuAction());
        menubar->addAction(menuEdition->menuAction());
        menubar->addAction(menuAffichage->menuAction());
        menuFichier->addAction(actionNew);
        menuFichier->addSeparator();
        menuFichier->addAction(actionExportPDF);
        menuFichier->addSeparator();
        menuFichier->addAction(actionExit);
        menuEdition->addAction(actionEdit);
        menuEdition->addAction(actionDelete);
        menuAffichage->addAction(actionRefresh);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion Machines", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&Nouvelle Machine", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEdit->setText(QCoreApplication::translate("MainWindow", "&Modifier", nullptr));
#if QT_CONFIG(shortcut)
        actionEdit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionDelete->setText(QCoreApplication::translate("MainWindow", "&Supprimer", nullptr));
#if QT_CONFIG(shortcut)
        actionDelete->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionScan->setText(QCoreApplication::translate("MainWindow", "&Scanner QR", nullptr));
#if QT_CONFIG(shortcut)
        actionScan->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExportPDF->setText(QCoreApplication::translate("MainWindow", "&Exporter PDF", nullptr));
#if QT_CONFIG(shortcut)
        actionExportPDF->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+P", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRefresh->setText(QCoreApplication::translate("MainWindow", "&Actualiser", nullptr));
#if QT_CONFIG(shortcut)
        actionRefresh->setShortcut(QCoreApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "&Quitter", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        sideMenu->setStyleSheet(QCoreApplication::translate("MainWindow", "background-color: #A2B29F;", nullptr));
        labelLogo->setText(QString());
        labelLogo->setStyleSheet(QCoreApplication::translate("MainWindow", "padding: 10px 10px;", nullptr));
        btnEmployee->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        btnEmployee->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        btnTeam->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnTeam->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnClient->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #A2B29F; }", nullptr));
        btnLaboratory->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnLaboratory->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        btnOrder->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnOrder->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        btnMachine->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #A2B29F; }", nullptr));
        labelPageEmployee->setText(QCoreApplication::translate("MainWindow", "Page Employ\303\251", nullptr));
        labelPageTeam->setText(QCoreApplication::translate("MainWindow", "Page \303\211quipe", nullptr));
        labelPageClient->setText(QCoreApplication::translate("MainWindow", "Page Client", nullptr));
        labelPageLaboratory->setText(QCoreApplication::translate("MainWindow", "Page Laboratoire", nullptr));
        labelPageOrder->setText(QCoreApplication::translate("MainWindow", "Page Commande", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "Recherche et Filtres", nullptr));
        labelSearch->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom, r\303\251f\303\251rence\342\200\246", nullptr));
        labelCategory->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        comboCategory->setItemText(0, QCoreApplication::translate("MainWindow", "Toutes", nullptr));
        comboCategory->setItemText(1, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboCategory->setItemText(2, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboCategory->setItemText(3, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboCategory->setItemText(4, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboCategory->setItemText(5, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        labelState->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        comboState->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        comboState->setItemText(1, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboState->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboState->setItemText(3, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboState->setItemText(4, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        labelLocation->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        lineEditLocation->setPlaceholderText(QCoreApplication::translate("MainWindow", "Atelier, Ligne 1\342\200\246", nullptr));
        btnApplyFilter->setText(QCoreApplication::translate("MainWindow", "Appliquer", nullptr));
        btnResetFilter->setText(QCoreApplication::translate("MainWindow", "R\303\251initialiser", nullptr));
        groupBoxSort->setTitle(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        labelSortBy->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboSortBy->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboSortBy->setItemText(1, QCoreApplication::translate("MainWindow", "Date d'achat", nullptr));
        comboSortBy->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        comboSortBy->setItemText(3, QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        comboSortBy->setItemText(4, QCoreApplication::translate("MainWindow", "Localisation", nullptr));

        radioCroissant->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        radioDecroissant->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
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
        tabWidget->setTabText(tabWidget->indexOf(tabList), QCoreApplication::translate("MainWindow", "Liste des Machines", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "Informations G\303\251n\303\251rales", nullptr));
        labelID->setText(QCoreApplication::translate("MainWindow", "ID :", nullptr));
        labelName->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        labelReference->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence :", nullptr));
        labelDetailCategory->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        labelDetailState->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        labelDetailLocation->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        labelWarrantyEnd->setText(QCoreApplication::translate("MainWindow", "Garantie Fin :", nullptr));
        labelResponsibleTeam->setText(QCoreApplication::translate("MainWindow", "\303\211quipe Responsable :", nullptr));
        groupBoxFinance->setTitle(QCoreApplication::translate("MainWindow", "Date d'Achat", nullptr));
        labelPurchaseDate->setText(QCoreApplication::translate("MainWindow", "Date d'Achat :", nullptr));
        groupBoxTraceability->setTitle(QCoreApplication::translate("MainWindow", "Tra\303\247abilit\303\251", nullptr));
        labelQRCode->setText(QCoreApplication::translate("MainWindow", "Code QR :", nullptr));
        labelBarcode->setText(QCoreApplication::translate("MainWindow", "Code-barres :", nullptr));
        btnScan->setText(QCoreApplication::translate("MainWindow", "Scanner QR / Code-barres", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabDetails), QCoreApplication::translate("MainWindow", "D\303\251tails Machine", nullptr));
        groupBoxNextMaint->setTitle(QCoreApplication::translate("MainWindow", "Prochaine Maintenance", nullptr));
        labelLastMaint->setText(QCoreApplication::translate("MainWindow", "Derni\303\250re :", nullptr));
        labelNextMaintDate->setText(QCoreApplication::translate("MainWindow", "Prochaine :", nullptr));
        btnScheduleMaint->setText(QCoreApplication::translate("MainWindow", "Planifier Maintenance", nullptr));
        groupBoxHistoriqueMaint->setTitle(QCoreApplication::translate("MainWindow", "Historique des Interventions", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableMaintenance->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableMaintenance->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableMaintenance->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableMaintenance->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableMaintenance->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Co\303\273t", nullptr));
        btnAddMaint->setText(QCoreApplication::translate("MainWindow", "Ajouter Intervention", nullptr));
        btnRemoveMaint->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMaintenance), QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques Globales", nullptr));
        labelStatTotal->setText(QCoreApplication::translate("MainWindow", "Total :", nullptr));
        statTotal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatOp->setText(QCoreApplication::translate("MainWindow", "Op\303\251rationnels :", nullptr));
        statOp->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatMaint->setText(QCoreApplication::translate("MainWindow", "En Maintenance :", nullptr));
        statMaint->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatDef->setText(QCoreApplication::translate("MainWindow", "D\303\251fectueux :", nullptr));
        statDef->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBoxStatsByCat->setTitle(QCoreApplication::translate("MainWindow", "\303\211quipements par Cat\303\251gorie", nullptr));
        groupBoxStatsBreakdown->setTitle(QCoreApplication::translate("MainWindow", "Pannes par Cat\303\251gorie", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistics), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "Actions Rapides", nullptr));
        btnNewEquipment->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter", nullptr));
        btnEditEquipment->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnDeleteEquipment->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Supprimer", nullptr));
        btnReportProblem->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Signaler Panne", nullptr));
        groupBoxQuickInfo->setTitle(QCoreApplication::translate("MainWindow", "Infos Rapides", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        quickState->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        quickLocation->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "Prochaine Maint :", nullptr));
        quickNextMaint->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Pannes :", nullptr));
        quickBreakdowns->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        menuFichier->setTitle(QCoreApplication::translate("MainWindow", "&Fichier", nullptr));
        menuEdition->setTitle(QCoreApplication::translate("MainWindow", "&\303\211dition", nullptr));
        menuAffichage->setTitle(QCoreApplication::translate("MainWindow", "&Affichage", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
