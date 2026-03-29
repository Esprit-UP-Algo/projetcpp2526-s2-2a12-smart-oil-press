/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QSpacerItem *verticalSpacer_Employee;
    QWidget *pageTeam;
    QVBoxLayout *vboxLayout1;
    QLabel *labelPageTeam;
    QSpacerItem *verticalSpacer_Team;
    QWidget *pageClient;
    QVBoxLayout *vboxLayout2;
    QLabel *labelPageClient;
    QSpacerItem *verticalSpacer_Client;
    QWidget *pageLaboratory;
    QVBoxLayout *vboxLayout3;
    QLabel *labelPageLaboratory;
    QSpacerItem *verticalSpacer_Laboratory;
    QWidget *pageOrder;
    QVBoxLayout *vboxLayout4;
    QLabel *labelPageOrder;
    QSpacerItem *verticalSpacer_Order;
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
    QGroupBox *groupBoxSort;
    QVBoxLayout *vboxLayout6;
    QHBoxLayout *hboxLayout5;
    QLabel *labelSortBy;
    QComboBox *comboSortBy;
    QHBoxLayout *hboxLayout6;
    QRadioButton *radioCroissant;
    QRadioButton *radioDecroissant;
    QPushButton *btnScanQR_RightPanel;
    QSpacerItem *verticalSpacer;
    QWidget *centerPanel;
    QVBoxLayout *vboxLayout7;
    QTabWidget *tabWidget;
    QWidget *tabList;
    QVBoxLayout *vboxLayout8;
    QTableWidget *tableEquipments;
    QHBoxLayout *hboxLayout7;
    QPushButton *btnExportPDF;
    QSpacerItem *horizontalSpacer_List;
    QWidget *tabAddMachine;
    QVBoxLayout *vboxLayout9;
    QLabel *labelAdd;
    QFrame *frameAdd;
    QFormLayout *formLayoutAdd;
    QLabel *labelAddId;
    QLineEdit *editAddId;
    QLabel *labelAddNom;
    QLineEdit *editAddNom;
    QLabel *labelAddCategorie;
    QComboBox *comboAddCategorie;
    QLabel *labelAddReference;
    QLineEdit *editAddReference;
    QLabel *labelAddDate;
    QDateEdit *dateAddAchat;
    QLabel *labelAddEtat;
    QComboBox *comboAddEtat;
    QLabel *labelAddLocalisation;
    QLineEdit *editAddLocalisation;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *horizontalSpacer_AddLeft;
    QPushButton *btnAddValider;
    QPushButton *btnAddAnnuler;
    QSpacerItem *horizontalSpacer_AddRight;
    QSpacerItem *verticalSpacer_Add;
    QWidget *tabModifier;
    QVBoxLayout *vboxLayout10;
    QLabel *labelModifier;
    QFrame *frameModifier;
    QFormLayout *formLayoutModifier;
    QLabel *labelModifierId;
    QComboBox *comboModifierId;
    QLabel *labelModifierNom;
    QLineEdit *editModifierNom;
    QLabel *labelModifierCategorie;
    QComboBox *comboModifierCategorie;
    QLabel *labelModifierReference;
    QLineEdit *editModifierReference;
    QLabel *labelModifierDate;
    QDateEdit *dateModifierAchat;
    QLabel *labelModifierEtat;
    QComboBox *comboModifierEtat;
    QLabel *labelModifierLocalisation;
    QLineEdit *editModifierLocalisation;
    QHBoxLayout *hboxLayout9;
    QSpacerItem *horizontalSpacer_ModifierLeft;
    QPushButton *btnModifierValider;
    QPushButton *btnModifierAnnuler;
    QSpacerItem *horizontalSpacer_ModifierRight;
    QSpacerItem *verticalSpacer_Modifier;
    QWidget *tabSupprimer;
    QVBoxLayout *vboxLayout11;
    QLabel *labelSupprimer;
    QFrame *frameSupprimer;
    QFormLayout *formLayoutSupprimer;
    QLabel *labelSupprimerId;
    QComboBox *comboSupprimerId;
    QHBoxLayout *hboxLayout10;
    QSpacerItem *horizontalSpacer_SupprimerLeft;
    QPushButton *btnSupprimerValider;
    QPushButton *btnSupprimerAnnuler;
    QSpacerItem *horizontalSpacer_SupprimerRight;
    QSpacerItem *verticalSpacer_Supprimer;
    QWidget *tabPanne;
    QVBoxLayout *vboxLayout12;
    QLabel *labelPanne;
    QFrame *framePanne;
    QFormLayout *formLayoutPanne;
    QLabel *labelPanneId;
    QComboBox *comboPanneId;
    QLabel *labelPanneType;
    QComboBox *comboPanneType;
    QLabel *labelPanneDescription;
    QTextEdit *textPanneDescription;
    QLabel *labelPanneUrgence;
    QComboBox *comboPanneUrgence;
    QHBoxLayout *hboxLayout11;
    QSpacerItem *horizontalSpacer_PanneLeft;
    QPushButton *btnPanneValider;
    QPushButton *btnPanneAnnuler;
    QSpacerItem *horizontalSpacer_PanneRight;
    QSpacerItem *verticalSpacer_Panne;
    QWidget *tabHistorique;
    QVBoxLayout *historiqueLayout;
    QTableWidget *tableHistorique;
    QHBoxLayout *hboxLayout12;
    QPushButton *btnAddIntervention;
    QPushButton *btnExportPDF_Historique;
    QSpacerItem *horizontalSpacer_Historique;
    QWidget *tabStatistics;
    QVBoxLayout *statisticsLayout;
    QGroupBox *groupBoxStatsCards;
    QHBoxLayout *statsCardsLayout;
    QFrame *cardTotal;
    QVBoxLayout *vboxLayout13;
    QLabel *labelTotalIcon;
    QLabel *labelTotalTitle;
    QLabel *statTotal;
    QFrame *cardOperational;
    QVBoxLayout *vboxLayout14;
    QLabel *labelOpIcon;
    QLabel *labelOpTitle;
    QLabel *statOp;
    QFrame *cardMaintenance;
    QVBoxLayout *vboxLayout15;
    QLabel *labelMaintIcon;
    QLabel *labelMaintTitle;
    QLabel *statMaint;
    QFrame *cardDefective;
    QVBoxLayout *vboxLayout16;
    QLabel *labelDefIcon;
    QLabel *labelDefTitle;
    QLabel *statDef;
    QSplitter *statisticsSplitter;
    QGroupBox *groupBoxCategories;
    QVBoxLayout *vboxLayout17;
    QTextEdit *statsCategories;
    QGroupBox *groupBoxEtats;
    QVBoxLayout *vboxLayout18;
    QTextEdit *statsBreakdowns;
    QGroupBox *groupBoxKPIs;
    QHBoxLayout *hboxLayout13;
    QFrame *kpiInterventions;
    QVBoxLayout *vboxLayout19;
    QLabel *labelKpiInterventions;
    QLabel *kpiInterventionsValue;
    QFrame *kpiCoutTotal;
    QVBoxLayout *vboxLayout20;
    QLabel *labelKpiCoutTotal;
    QLabel *kpiCoutTotalValue;
    QHBoxLayout *hboxLayout14;
    QPushButton *btnExportPDF_Stats;
    QSpacerItem *horizontalSpacer_Stats;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1600, 1000);
        actionExportPDF = new QAction(MainWindow);
        actionExportPDF->setObjectName("actionExportPDF");
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
        sideMenuLayout->setSpacing(0);
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

        verticalSpacer_Employee = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout->addItem(verticalSpacer_Employee);

        stackedPages->addWidget(pageEmployee);
        pageTeam = new QWidget();
        pageTeam->setObjectName("pageTeam");
        vboxLayout1 = new QVBoxLayout(pageTeam);
        vboxLayout1->setObjectName("vboxLayout1");
        labelPageTeam = new QLabel(pageTeam);
        labelPageTeam->setObjectName("labelPageTeam");
        labelPageTeam->setAlignment(Qt::AlignCenter);

        vboxLayout1->addWidget(labelPageTeam);

        verticalSpacer_Team = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout1->addItem(verticalSpacer_Team);

        stackedPages->addWidget(pageTeam);
        pageClient = new QWidget();
        pageClient->setObjectName("pageClient");
        vboxLayout2 = new QVBoxLayout(pageClient);
        vboxLayout2->setObjectName("vboxLayout2");
        labelPageClient = new QLabel(pageClient);
        labelPageClient->setObjectName("labelPageClient");
        labelPageClient->setAlignment(Qt::AlignCenter);

        vboxLayout2->addWidget(labelPageClient);

        verticalSpacer_Client = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout2->addItem(verticalSpacer_Client);

        stackedPages->addWidget(pageClient);
        pageLaboratory = new QWidget();
        pageLaboratory->setObjectName("pageLaboratory");
        vboxLayout3 = new QVBoxLayout(pageLaboratory);
        vboxLayout3->setObjectName("vboxLayout3");
        labelPageLaboratory = new QLabel(pageLaboratory);
        labelPageLaboratory->setObjectName("labelPageLaboratory");
        labelPageLaboratory->setAlignment(Qt::AlignCenter);

        vboxLayout3->addWidget(labelPageLaboratory);

        verticalSpacer_Laboratory = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout3->addItem(verticalSpacer_Laboratory);

        stackedPages->addWidget(pageLaboratory);
        pageOrder = new QWidget();
        pageOrder->setObjectName("pageOrder");
        vboxLayout4 = new QVBoxLayout(pageOrder);
        vboxLayout4->setObjectName("vboxLayout4");
        labelPageOrder = new QLabel(pageOrder);
        labelPageOrder->setObjectName("labelPageOrder");
        labelPageOrder->setAlignment(Qt::AlignCenter);

        vboxLayout4->addWidget(labelPageOrder);

        verticalSpacer_Order = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout4->addItem(verticalSpacer_Order);

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
        btnApplyFilter->setMinimumHeight(35);

        hboxLayout4->addWidget(btnApplyFilter);


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

        btnScanQR_RightPanel = new QPushButton(leftPanel);
        btnScanQR_RightPanel->setObjectName("btnScanQR_RightPanel");
        btnScanQR_RightPanel->setMinimumHeight(45);
        btnScanQR_RightPanel->setMinimumWidth(180);

        leftLayout->addWidget(btnScanQR_RightPanel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftLayout->addItem(verticalSpacer);

        splitter->addWidget(leftPanel);
        centerPanel = new QWidget(splitter);
        centerPanel->setObjectName("centerPanel");
        vboxLayout7 = new QVBoxLayout(centerPanel);
        vboxLayout7->setObjectName("vboxLayout7");
        vboxLayout7->setContentsMargins(10, 10, 10, 10);
        tabWidget = new QTabWidget(centerPanel);
        tabWidget->setObjectName("tabWidget");
        tabList = new QWidget();
        tabList->setObjectName("tabList");
        vboxLayout8 = new QVBoxLayout(tabList);
        vboxLayout8->setObjectName("vboxLayout8");
        tableEquipments = new QTableWidget(tabList);
        if (tableEquipments->columnCount() < 6)
            tableEquipments->setColumnCount(6);
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
        tableEquipments->setObjectName("tableEquipments");
        tableEquipments->setRowCount(0);
        tableEquipments->setColumnCount(6);
        tableEquipments->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableEquipments->setAlternatingRowColors(true);

        vboxLayout8->addWidget(tableEquipments);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName("hboxLayout7");
        btnExportPDF = new QPushButton(tabList);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setMinimumHeight(35);

        hboxLayout7->addWidget(btnExportPDF);

        horizontalSpacer_List = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout7->addItem(horizontalSpacer_List);


        vboxLayout8->addLayout(hboxLayout7);

        tabWidget->addTab(tabList, QString());
        tabAddMachine = new QWidget();
        tabAddMachine->setObjectName("tabAddMachine");
        vboxLayout9 = new QVBoxLayout(tabAddMachine);
        vboxLayout9->setObjectName("vboxLayout9");
        labelAdd = new QLabel(tabAddMachine);
        labelAdd->setObjectName("labelAdd");
        labelAdd->setAlignment(Qt::AlignCenter);

        vboxLayout9->addWidget(labelAdd);

        frameAdd = new QFrame(tabAddMachine);
        frameAdd->setObjectName("frameAdd");
        frameAdd->setFrameShape(QFrame::StyledPanel);
        frameAdd->setFrameShadow(QFrame::Raised);
        formLayoutAdd = new QFormLayout(frameAdd);
        formLayoutAdd->setObjectName("formLayoutAdd");
        labelAddId = new QLabel(frameAdd);
        labelAddId->setObjectName("labelAddId");

        formLayoutAdd->setWidget(0, QFormLayout::LabelRole, labelAddId);

        editAddId = new QLineEdit(frameAdd);
        editAddId->setObjectName("editAddId");

        formLayoutAdd->setWidget(0, QFormLayout::FieldRole, editAddId);

        labelAddNom = new QLabel(frameAdd);
        labelAddNom->setObjectName("labelAddNom");

        formLayoutAdd->setWidget(1, QFormLayout::LabelRole, labelAddNom);

        editAddNom = new QLineEdit(frameAdd);
        editAddNom->setObjectName("editAddNom");

        formLayoutAdd->setWidget(1, QFormLayout::FieldRole, editAddNom);

        labelAddCategorie = new QLabel(frameAdd);
        labelAddCategorie->setObjectName("labelAddCategorie");

        formLayoutAdd->setWidget(2, QFormLayout::LabelRole, labelAddCategorie);

        comboAddCategorie = new QComboBox(frameAdd);
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->setObjectName("comboAddCategorie");

        formLayoutAdd->setWidget(2, QFormLayout::FieldRole, comboAddCategorie);

        labelAddReference = new QLabel(frameAdd);
        labelAddReference->setObjectName("labelAddReference");

        formLayoutAdd->setWidget(3, QFormLayout::LabelRole, labelAddReference);

        editAddReference = new QLineEdit(frameAdd);
        editAddReference->setObjectName("editAddReference");

        formLayoutAdd->setWidget(3, QFormLayout::FieldRole, editAddReference);

        labelAddDate = new QLabel(frameAdd);
        labelAddDate->setObjectName("labelAddDate");

        formLayoutAdd->setWidget(4, QFormLayout::LabelRole, labelAddDate);

        dateAddAchat = new QDateEdit(frameAdd);
        dateAddAchat->setObjectName("dateAddAchat");
        dateAddAchat->setCalendarPopup(true);
        dateAddAchat->setDate(QDate(2024, 1, 1));

        formLayoutAdd->setWidget(4, QFormLayout::FieldRole, dateAddAchat);

        labelAddEtat = new QLabel(frameAdd);
        labelAddEtat->setObjectName("labelAddEtat");

        formLayoutAdd->setWidget(5, QFormLayout::LabelRole, labelAddEtat);

        comboAddEtat = new QComboBox(frameAdd);
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->setObjectName("comboAddEtat");

        formLayoutAdd->setWidget(5, QFormLayout::FieldRole, comboAddEtat);

        labelAddLocalisation = new QLabel(frameAdd);
        labelAddLocalisation->setObjectName("labelAddLocalisation");

        formLayoutAdd->setWidget(6, QFormLayout::LabelRole, labelAddLocalisation);

        editAddLocalisation = new QLineEdit(frameAdd);
        editAddLocalisation->setObjectName("editAddLocalisation");

        formLayoutAdd->setWidget(6, QFormLayout::FieldRole, editAddLocalisation);


        vboxLayout9->addWidget(frameAdd);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setObjectName("hboxLayout8");
        horizontalSpacer_AddLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout8->addItem(horizontalSpacer_AddLeft);

        btnAddValider = new QPushButton(tabAddMachine);
        btnAddValider->setObjectName("btnAddValider");
        btnAddValider->setMinimumHeight(40);

        hboxLayout8->addWidget(btnAddValider);

        btnAddAnnuler = new QPushButton(tabAddMachine);
        btnAddAnnuler->setObjectName("btnAddAnnuler");
        btnAddAnnuler->setMinimumHeight(40);

        hboxLayout8->addWidget(btnAddAnnuler);

        horizontalSpacer_AddRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout8->addItem(horizontalSpacer_AddRight);


        vboxLayout9->addLayout(hboxLayout8);

        verticalSpacer_Add = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout9->addItem(verticalSpacer_Add);

        tabWidget->addTab(tabAddMachine, QString());
        tabModifier = new QWidget();
        tabModifier->setObjectName("tabModifier");
        vboxLayout10 = new QVBoxLayout(tabModifier);
        vboxLayout10->setObjectName("vboxLayout10");
        labelModifier = new QLabel(tabModifier);
        labelModifier->setObjectName("labelModifier");
        labelModifier->setAlignment(Qt::AlignCenter);
        labelModifier->setWordWrap(true);

        vboxLayout10->addWidget(labelModifier);

        frameModifier = new QFrame(tabModifier);
        frameModifier->setObjectName("frameModifier");
        frameModifier->setFrameShape(QFrame::StyledPanel);
        frameModifier->setFrameShadow(QFrame::Raised);
        formLayoutModifier = new QFormLayout(frameModifier);
        formLayoutModifier->setObjectName("formLayoutModifier");
        labelModifierId = new QLabel(frameModifier);
        labelModifierId->setObjectName("labelModifierId");

        formLayoutModifier->setWidget(0, QFormLayout::LabelRole, labelModifierId);

        comboModifierId = new QComboBox(frameModifier);
        comboModifierId->setObjectName("comboModifierId");
        comboModifierId->setEditable(true);

        formLayoutModifier->setWidget(0, QFormLayout::FieldRole, comboModifierId);

        labelModifierNom = new QLabel(frameModifier);
        labelModifierNom->setObjectName("labelModifierNom");

        formLayoutModifier->setWidget(1, QFormLayout::LabelRole, labelModifierNom);

        editModifierNom = new QLineEdit(frameModifier);
        editModifierNom->setObjectName("editModifierNom");

        formLayoutModifier->setWidget(1, QFormLayout::FieldRole, editModifierNom);

        labelModifierCategorie = new QLabel(frameModifier);
        labelModifierCategorie->setObjectName("labelModifierCategorie");

        formLayoutModifier->setWidget(2, QFormLayout::LabelRole, labelModifierCategorie);

        comboModifierCategorie = new QComboBox(frameModifier);
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->setObjectName("comboModifierCategorie");

        formLayoutModifier->setWidget(2, QFormLayout::FieldRole, comboModifierCategorie);

        labelModifierReference = new QLabel(frameModifier);
        labelModifierReference->setObjectName("labelModifierReference");

        formLayoutModifier->setWidget(3, QFormLayout::LabelRole, labelModifierReference);

        editModifierReference = new QLineEdit(frameModifier);
        editModifierReference->setObjectName("editModifierReference");

        formLayoutModifier->setWidget(3, QFormLayout::FieldRole, editModifierReference);

        labelModifierDate = new QLabel(frameModifier);
        labelModifierDate->setObjectName("labelModifierDate");

        formLayoutModifier->setWidget(4, QFormLayout::LabelRole, labelModifierDate);

        dateModifierAchat = new QDateEdit(frameModifier);
        dateModifierAchat->setObjectName("dateModifierAchat");
        dateModifierAchat->setCalendarPopup(true);

        formLayoutModifier->setWidget(4, QFormLayout::FieldRole, dateModifierAchat);

        labelModifierEtat = new QLabel(frameModifier);
        labelModifierEtat->setObjectName("labelModifierEtat");

        formLayoutModifier->setWidget(5, QFormLayout::LabelRole, labelModifierEtat);

        comboModifierEtat = new QComboBox(frameModifier);
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->setObjectName("comboModifierEtat");

        formLayoutModifier->setWidget(5, QFormLayout::FieldRole, comboModifierEtat);

        labelModifierLocalisation = new QLabel(frameModifier);
        labelModifierLocalisation->setObjectName("labelModifierLocalisation");

        formLayoutModifier->setWidget(6, QFormLayout::LabelRole, labelModifierLocalisation);

        editModifierLocalisation = new QLineEdit(frameModifier);
        editModifierLocalisation->setObjectName("editModifierLocalisation");

        formLayoutModifier->setWidget(6, QFormLayout::FieldRole, editModifierLocalisation);


        vboxLayout10->addWidget(frameModifier);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setObjectName("hboxLayout9");
        horizontalSpacer_ModifierLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout9->addItem(horizontalSpacer_ModifierLeft);

        btnModifierValider = new QPushButton(tabModifier);
        btnModifierValider->setObjectName("btnModifierValider");
        btnModifierValider->setMinimumHeight(40);

        hboxLayout9->addWidget(btnModifierValider);

        btnModifierAnnuler = new QPushButton(tabModifier);
        btnModifierAnnuler->setObjectName("btnModifierAnnuler");
        btnModifierAnnuler->setMinimumHeight(40);

        hboxLayout9->addWidget(btnModifierAnnuler);

        horizontalSpacer_ModifierRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout9->addItem(horizontalSpacer_ModifierRight);


        vboxLayout10->addLayout(hboxLayout9);

        verticalSpacer_Modifier = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout10->addItem(verticalSpacer_Modifier);

        tabWidget->addTab(tabModifier, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        vboxLayout11 = new QVBoxLayout(tabSupprimer);
        vboxLayout11->setObjectName("vboxLayout11");
        labelSupprimer = new QLabel(tabSupprimer);
        labelSupprimer->setObjectName("labelSupprimer");
        labelSupprimer->setAlignment(Qt::AlignCenter);
        labelSupprimer->setWordWrap(true);

        vboxLayout11->addWidget(labelSupprimer);

        frameSupprimer = new QFrame(tabSupprimer);
        frameSupprimer->setObjectName("frameSupprimer");
        frameSupprimer->setFrameShape(QFrame::StyledPanel);
        frameSupprimer->setFrameShadow(QFrame::Raised);
        formLayoutSupprimer = new QFormLayout(frameSupprimer);
        formLayoutSupprimer->setObjectName("formLayoutSupprimer");
        labelSupprimerId = new QLabel(frameSupprimer);
        labelSupprimerId->setObjectName("labelSupprimerId");

        formLayoutSupprimer->setWidget(0, QFormLayout::LabelRole, labelSupprimerId);

        comboSupprimerId = new QComboBox(frameSupprimer);
        comboSupprimerId->setObjectName("comboSupprimerId");
        comboSupprimerId->setEditable(true);

        formLayoutSupprimer->setWidget(0, QFormLayout::FieldRole, comboSupprimerId);


        vboxLayout11->addWidget(frameSupprimer);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setObjectName("hboxLayout10");
        horizontalSpacer_SupprimerLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout10->addItem(horizontalSpacer_SupprimerLeft);

        btnSupprimerValider = new QPushButton(tabSupprimer);
        btnSupprimerValider->setObjectName("btnSupprimerValider");
        btnSupprimerValider->setMinimumHeight(40);

        hboxLayout10->addWidget(btnSupprimerValider);

        btnSupprimerAnnuler = new QPushButton(tabSupprimer);
        btnSupprimerAnnuler->setObjectName("btnSupprimerAnnuler");
        btnSupprimerAnnuler->setMinimumHeight(40);

        hboxLayout10->addWidget(btnSupprimerAnnuler);

        horizontalSpacer_SupprimerRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout10->addItem(horizontalSpacer_SupprimerRight);


        vboxLayout11->addLayout(hboxLayout10);

        verticalSpacer_Supprimer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout11->addItem(verticalSpacer_Supprimer);

        tabWidget->addTab(tabSupprimer, QString());
        tabPanne = new QWidget();
        tabPanne->setObjectName("tabPanne");
        vboxLayout12 = new QVBoxLayout(tabPanne);
        vboxLayout12->setObjectName("vboxLayout12");
        labelPanne = new QLabel(tabPanne);
        labelPanne->setObjectName("labelPanne");
        labelPanne->setAlignment(Qt::AlignCenter);
        labelPanne->setWordWrap(true);

        vboxLayout12->addWidget(labelPanne);

        framePanne = new QFrame(tabPanne);
        framePanne->setObjectName("framePanne");
        framePanne->setFrameShape(QFrame::StyledPanel);
        framePanne->setFrameShadow(QFrame::Raised);
        formLayoutPanne = new QFormLayout(framePanne);
        formLayoutPanne->setObjectName("formLayoutPanne");
        labelPanneId = new QLabel(framePanne);
        labelPanneId->setObjectName("labelPanneId");

        formLayoutPanne->setWidget(0, QFormLayout::LabelRole, labelPanneId);

        comboPanneId = new QComboBox(framePanne);
        comboPanneId->setObjectName("comboPanneId");
        comboPanneId->setEditable(true);

        formLayoutPanne->setWidget(0, QFormLayout::FieldRole, comboPanneId);

        labelPanneType = new QLabel(framePanne);
        labelPanneType->setObjectName("labelPanneType");

        formLayoutPanne->setWidget(1, QFormLayout::LabelRole, labelPanneType);

        comboPanneType = new QComboBox(framePanne);
        comboPanneType->addItem(QString());
        comboPanneType->addItem(QString());
        comboPanneType->addItem(QString());
        comboPanneType->addItem(QString());
        comboPanneType->addItem(QString());
        comboPanneType->addItem(QString());
        comboPanneType->setObjectName("comboPanneType");

        formLayoutPanne->setWidget(1, QFormLayout::FieldRole, comboPanneType);

        labelPanneDescription = new QLabel(framePanne);
        labelPanneDescription->setObjectName("labelPanneDescription");

        formLayoutPanne->setWidget(2, QFormLayout::LabelRole, labelPanneDescription);

        textPanneDescription = new QTextEdit(framePanne);
        textPanneDescription->setObjectName("textPanneDescription");
        textPanneDescription->setMaximumHeight(100);

        formLayoutPanne->setWidget(2, QFormLayout::FieldRole, textPanneDescription);

        labelPanneUrgence = new QLabel(framePanne);
        labelPanneUrgence->setObjectName("labelPanneUrgence");

        formLayoutPanne->setWidget(3, QFormLayout::LabelRole, labelPanneUrgence);

        comboPanneUrgence = new QComboBox(framePanne);
        comboPanneUrgence->addItem(QString());
        comboPanneUrgence->addItem(QString());
        comboPanneUrgence->addItem(QString());
        comboPanneUrgence->addItem(QString());
        comboPanneUrgence->setObjectName("comboPanneUrgence");

        formLayoutPanne->setWidget(3, QFormLayout::FieldRole, comboPanneUrgence);


        vboxLayout12->addWidget(framePanne);

        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setObjectName("hboxLayout11");
        horizontalSpacer_PanneLeft = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout11->addItem(horizontalSpacer_PanneLeft);

        btnPanneValider = new QPushButton(tabPanne);
        btnPanneValider->setObjectName("btnPanneValider");
        btnPanneValider->setMinimumHeight(40);

        hboxLayout11->addWidget(btnPanneValider);

        btnPanneAnnuler = new QPushButton(tabPanne);
        btnPanneAnnuler->setObjectName("btnPanneAnnuler");
        btnPanneAnnuler->setMinimumHeight(40);

        hboxLayout11->addWidget(btnPanneAnnuler);

        horizontalSpacer_PanneRight = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout11->addItem(horizontalSpacer_PanneRight);


        vboxLayout12->addLayout(hboxLayout11);

        verticalSpacer_Panne = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout12->addItem(verticalSpacer_Panne);

        tabWidget->addTab(tabPanne, QString());
        tabHistorique = new QWidget();
        tabHistorique->setObjectName("tabHistorique");
        historiqueLayout = new QVBoxLayout(tabHistorique);
        historiqueLayout->setObjectName("historiqueLayout");
        tableHistorique = new QTableWidget(tabHistorique);
        if (tableHistorique->columnCount() < 6)
            tableHistorique->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        if (tableHistorique->rowCount() < 3)
            tableHistorique->setRowCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableHistorique->setVerticalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableHistorique->setVerticalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableHistorique->setVerticalHeaderItem(2, __qtablewidgetitem14);
        tableHistorique->setObjectName("tableHistorique");
        tableHistorique->setRowCount(3);
        tableHistorique->setColumnCount(6);
        tableHistorique->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableHistorique->setAlternatingRowColors(true);

        historiqueLayout->addWidget(tableHistorique);

        hboxLayout12 = new QHBoxLayout();
        hboxLayout12->setObjectName("hboxLayout12");
        btnAddIntervention = new QPushButton(tabHistorique);
        btnAddIntervention->setObjectName("btnAddIntervention");
        btnAddIntervention->setMinimumHeight(35);

        hboxLayout12->addWidget(btnAddIntervention);

        btnExportPDF_Historique = new QPushButton(tabHistorique);
        btnExportPDF_Historique->setObjectName("btnExportPDF_Historique");
        btnExportPDF_Historique->setMinimumHeight(35);

        hboxLayout12->addWidget(btnExportPDF_Historique);

        horizontalSpacer_Historique = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout12->addItem(horizontalSpacer_Historique);


        historiqueLayout->addLayout(hboxLayout12);

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
        vboxLayout13 = new QVBoxLayout(cardTotal);
        vboxLayout13->setObjectName("vboxLayout13");
        labelTotalIcon = new QLabel(cardTotal);
        labelTotalIcon->setObjectName("labelTotalIcon");
        QFont font;
        font.setPointSize(24);
        labelTotalIcon->setFont(font);
        labelTotalIcon->setAlignment(Qt::AlignCenter);

        vboxLayout13->addWidget(labelTotalIcon);

        labelTotalTitle = new QLabel(cardTotal);
        labelTotalTitle->setObjectName("labelTotalTitle");
        labelTotalTitle->setAlignment(Qt::AlignCenter);

        vboxLayout13->addWidget(labelTotalTitle);

        statTotal = new QLabel(cardTotal);
        statTotal->setObjectName("statTotal");
        QFont font1;
        font1.setPointSize(28);
        font1.setBold(true);
        statTotal->setFont(font1);
        statTotal->setAlignment(Qt::AlignCenter);

        vboxLayout13->addWidget(statTotal);


        statsCardsLayout->addWidget(cardTotal);

        cardOperational = new QFrame(groupBoxStatsCards);
        cardOperational->setObjectName("cardOperational");
        cardOperational->setMinimumHeight(120);
        vboxLayout14 = new QVBoxLayout(cardOperational);
        vboxLayout14->setObjectName("vboxLayout14");
        labelOpIcon = new QLabel(cardOperational);
        labelOpIcon->setObjectName("labelOpIcon");
        labelOpIcon->setFont(font);
        labelOpIcon->setAlignment(Qt::AlignCenter);

        vboxLayout14->addWidget(labelOpIcon);

        labelOpTitle = new QLabel(cardOperational);
        labelOpTitle->setObjectName("labelOpTitle");
        labelOpTitle->setAlignment(Qt::AlignCenter);

        vboxLayout14->addWidget(labelOpTitle);

        statOp = new QLabel(cardOperational);
        statOp->setObjectName("statOp");
        statOp->setFont(font1);
        statOp->setAlignment(Qt::AlignCenter);

        vboxLayout14->addWidget(statOp);


        statsCardsLayout->addWidget(cardOperational);

        cardMaintenance = new QFrame(groupBoxStatsCards);
        cardMaintenance->setObjectName("cardMaintenance");
        cardMaintenance->setMinimumHeight(120);
        vboxLayout15 = new QVBoxLayout(cardMaintenance);
        vboxLayout15->setObjectName("vboxLayout15");
        labelMaintIcon = new QLabel(cardMaintenance);
        labelMaintIcon->setObjectName("labelMaintIcon");
        labelMaintIcon->setFont(font);
        labelMaintIcon->setAlignment(Qt::AlignCenter);

        vboxLayout15->addWidget(labelMaintIcon);

        labelMaintTitle = new QLabel(cardMaintenance);
        labelMaintTitle->setObjectName("labelMaintTitle");
        labelMaintTitle->setAlignment(Qt::AlignCenter);

        vboxLayout15->addWidget(labelMaintTitle);

        statMaint = new QLabel(cardMaintenance);
        statMaint->setObjectName("statMaint");
        statMaint->setFont(font1);
        statMaint->setAlignment(Qt::AlignCenter);

        vboxLayout15->addWidget(statMaint);


        statsCardsLayout->addWidget(cardMaintenance);

        cardDefective = new QFrame(groupBoxStatsCards);
        cardDefective->setObjectName("cardDefective");
        cardDefective->setMinimumHeight(120);
        vboxLayout16 = new QVBoxLayout(cardDefective);
        vboxLayout16->setObjectName("vboxLayout16");
        labelDefIcon = new QLabel(cardDefective);
        labelDefIcon->setObjectName("labelDefIcon");
        labelDefIcon->setFont(font);
        labelDefIcon->setAlignment(Qt::AlignCenter);

        vboxLayout16->addWidget(labelDefIcon);

        labelDefTitle = new QLabel(cardDefective);
        labelDefTitle->setObjectName("labelDefTitle");
        labelDefTitle->setAlignment(Qt::AlignCenter);

        vboxLayout16->addWidget(labelDefTitle);

        statDef = new QLabel(cardDefective);
        statDef->setObjectName("statDef");
        statDef->setFont(font1);
        statDef->setAlignment(Qt::AlignCenter);

        vboxLayout16->addWidget(statDef);


        statsCardsLayout->addWidget(cardDefective);


        statisticsLayout->addWidget(groupBoxStatsCards);

        statisticsSplitter = new QSplitter(tabStatistics);
        statisticsSplitter->setObjectName("statisticsSplitter");
        statisticsSplitter->setOrientation(Qt::Horizontal);
        groupBoxCategories = new QGroupBox(statisticsSplitter);
        groupBoxCategories->setObjectName("groupBoxCategories");
        vboxLayout17 = new QVBoxLayout(groupBoxCategories);
        vboxLayout17->setObjectName("vboxLayout17");
        statsCategories = new QTextEdit(groupBoxCategories);
        statsCategories->setObjectName("statsCategories");
        statsCategories->setReadOnly(true);

        vboxLayout17->addWidget(statsCategories);

        statisticsSplitter->addWidget(groupBoxCategories);
        groupBoxEtats = new QGroupBox(statisticsSplitter);
        groupBoxEtats->setObjectName("groupBoxEtats");
        vboxLayout18 = new QVBoxLayout(groupBoxEtats);
        vboxLayout18->setObjectName("vboxLayout18");
        statsBreakdowns = new QTextEdit(groupBoxEtats);
        statsBreakdowns->setObjectName("statsBreakdowns");
        statsBreakdowns->setReadOnly(true);

        vboxLayout18->addWidget(statsBreakdowns);

        statisticsSplitter->addWidget(groupBoxEtats);

        statisticsLayout->addWidget(statisticsSplitter);

        groupBoxKPIs = new QGroupBox(tabStatistics);
        groupBoxKPIs->setObjectName("groupBoxKPIs");
        hboxLayout13 = new QHBoxLayout(groupBoxKPIs);
        hboxLayout13->setObjectName("hboxLayout13");
        kpiInterventions = new QFrame(groupBoxKPIs);
        kpiInterventions->setObjectName("kpiInterventions");
        vboxLayout19 = new QVBoxLayout(kpiInterventions);
        vboxLayout19->setObjectName("vboxLayout19");
        labelKpiInterventions = new QLabel(kpiInterventions);
        labelKpiInterventions->setObjectName("labelKpiInterventions");
        labelKpiInterventions->setAlignment(Qt::AlignCenter);

        vboxLayout19->addWidget(labelKpiInterventions);

        kpiInterventionsValue = new QLabel(kpiInterventions);
        kpiInterventionsValue->setObjectName("kpiInterventionsValue");
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        kpiInterventionsValue->setFont(font2);
        kpiInterventionsValue->setAlignment(Qt::AlignCenter);

        vboxLayout19->addWidget(kpiInterventionsValue);


        hboxLayout13->addWidget(kpiInterventions);

        kpiCoutTotal = new QFrame(groupBoxKPIs);
        kpiCoutTotal->setObjectName("kpiCoutTotal");
        vboxLayout20 = new QVBoxLayout(kpiCoutTotal);
        vboxLayout20->setObjectName("vboxLayout20");
        labelKpiCoutTotal = new QLabel(kpiCoutTotal);
        labelKpiCoutTotal->setObjectName("labelKpiCoutTotal");
        labelKpiCoutTotal->setAlignment(Qt::AlignCenter);

        vboxLayout20->addWidget(labelKpiCoutTotal);

        kpiCoutTotalValue = new QLabel(kpiCoutTotal);
        kpiCoutTotalValue->setObjectName("kpiCoutTotalValue");
        kpiCoutTotalValue->setFont(font2);
        kpiCoutTotalValue->setAlignment(Qt::AlignCenter);

        vboxLayout20->addWidget(kpiCoutTotalValue);


        hboxLayout13->addWidget(kpiCoutTotal);


        statisticsLayout->addWidget(groupBoxKPIs);

        hboxLayout14 = new QHBoxLayout();
        hboxLayout14->setObjectName("hboxLayout14");
        btnExportPDF_Stats = new QPushButton(tabStatistics);
        btnExportPDF_Stats->setObjectName("btnExportPDF_Stats");
        btnExportPDF_Stats->setMinimumHeight(35);

        hboxLayout14->addWidget(btnExportPDF_Stats);

        horizontalSpacer_Stats = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout14->addItem(horizontalSpacer_Stats);


        statisticsLayout->addLayout(hboxLayout14);

        tabWidget->addTab(tabStatistics, QString());

        vboxLayout7->addWidget(tabWidget);

        splitter->addWidget(centerPanel);

        machineLayout->addWidget(splitter);

        stackedPages->addWidget(pageMachine);

        mainLayout->addWidget(stackedPages);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

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
        labelLogo->setText(QString());
        btnEmployee->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        btnTeam->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnLaboratory->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnOrder->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        labelPageEmployee->setText(QCoreApplication::translate("MainWindow", "Gestion des Employ\303\251s", nullptr));
        labelPageEmployee->setObjectName(QCoreApplication::translate("MainWindow", "pageTitle", nullptr));
        labelPageTeam->setText(QCoreApplication::translate("MainWindow", "Gestion des \303\211quipes", nullptr));
        labelPageTeam->setObjectName(QCoreApplication::translate("MainWindow", "pageTitle", nullptr));
        labelPageClient->setText(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        labelPageClient->setObjectName(QCoreApplication::translate("MainWindow", "pageTitle", nullptr));
        labelPageLaboratory->setText(QCoreApplication::translate("MainWindow", "Gestion du Laboratoire", nullptr));
        labelPageLaboratory->setObjectName(QCoreApplication::translate("MainWindow", "pageTitle", nullptr));
        labelPageOrder->setText(QCoreApplication::translate("MainWindow", "Gestion des Commandes", nullptr));
        labelPageOrder->setObjectName(QCoreApplication::translate("MainWindow", "pageTitle", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\215 Recherche et Filtres", nullptr));
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
        btnApplyFilter->setText(QCoreApplication::translate("MainWindow", "\342\234\205 Appliquer", nullptr));
        groupBoxSort->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 Tri", nullptr));
        labelSortBy->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboSortBy->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboSortBy->setItemText(1, QCoreApplication::translate("MainWindow", "Date d'achat", nullptr));
        comboSortBy->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        comboSortBy->setItemText(3, QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        comboSortBy->setItemText(4, QCoreApplication::translate("MainWindow", "Localisation", nullptr));

        radioCroissant->setText(QCoreApplication::translate("MainWindow", "\342\254\206\357\270\217 Croissant", nullptr));
        radioDecroissant->setText(QCoreApplication::translate("MainWindow", "\342\254\207\357\270\217 D\303\251croissant", nullptr));
        btnScanQR_RightPanel->setText(QCoreApplication::translate("MainWindow", "\360\237\223\267 Scanner QR Code", nullptr));
        btnScanQR_RightPanel->setObjectName(QCoreApplication::translate("MainWindow", "btnScanQR", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEquipments->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID MACHINE", nullptr));
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
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabList), QCoreApplication::translate("MainWindow", " Liste des Machines", nullptr));
        labelAdd->setText(QCoreApplication::translate("MainWindow", "<h2>Ajouter une nouvelle machine</h2>", nullptr));
        labelAddId->setText(QCoreApplication::translate("MainWindow", "ID Machine :", nullptr));
        editAddId->setPlaceholderText(QCoreApplication::translate("MainWindow", "MCH-XXX", nullptr));
        labelAddNom->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        editAddNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom de la machine", nullptr));
        labelAddCategorie->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        comboAddCategorie->setItemText(0, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboAddCategorie->setItemText(1, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboAddCategorie->setItemText(2, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboAddCategorie->setItemText(3, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboAddCategorie->setItemText(4, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        labelAddReference->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence :", nullptr));
        editAddReference->setPlaceholderText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        labelAddDate->setText(QCoreApplication::translate("MainWindow", "Date d'achat :", nullptr));
        labelAddEtat->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        comboAddEtat->setItemText(0, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboAddEtat->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboAddEtat->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboAddEtat->setItemText(3, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        labelAddLocalisation->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        editAddLocalisation->setPlaceholderText(QCoreApplication::translate("MainWindow", "Atelier, Ligne...", nullptr));
        btnAddValider->setText(QCoreApplication::translate("MainWindow", "\342\234\205 Ajouter", nullptr));
        btnAddValider->setObjectName(QCoreApplication::translate("MainWindow", "btnAjouter", nullptr));
        btnAddAnnuler->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler", nullptr));
        btnAddAnnuler->setObjectName(QCoreApplication::translate("MainWindow", "btnAnnuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAddMachine), QCoreApplication::translate("MainWindow", " Ajouter Machine", nullptr));
        labelModifier->setText(QCoreApplication::translate("MainWindow", "<h2>Modifier une machine</h2><p>S\303\251lectionnez une machine dans la liste pour la modifier.</p>", nullptr));
        labelModifierId->setText(QCoreApplication::translate("MainWindow", "ID Machine :", nullptr));
        labelModifierNom->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        labelModifierCategorie->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        comboModifierCategorie->setItemText(0, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboModifierCategorie->setItemText(1, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboModifierCategorie->setItemText(2, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboModifierCategorie->setItemText(3, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboModifierCategorie->setItemText(4, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        labelModifierReference->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence :", nullptr));
        labelModifierDate->setText(QCoreApplication::translate("MainWindow", "Date d'achat :", nullptr));
        labelModifierEtat->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        comboModifierEtat->setItemText(0, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboModifierEtat->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboModifierEtat->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboModifierEtat->setItemText(3, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        labelModifierLocalisation->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        btnModifierValider->setText(QCoreApplication::translate("MainWindow", "\342\234\205 Valider la modification", nullptr));
        btnModifierValider->setObjectName(QCoreApplication::translate("MainWindow", "btnValider", nullptr));
        btnModifierAnnuler->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler", nullptr));
        btnModifierAnnuler->setObjectName(QCoreApplication::translate("MainWindow", "btnAnnuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("MainWindow", " Modifier Machine", nullptr));
        labelSupprimer->setText(QCoreApplication::translate("MainWindow", "<h2>Supprimer une machine</h2><p>S\303\251lectionnez une machine \303\240 supprimer.</p>", nullptr));
        labelSupprimerId->setText(QCoreApplication::translate("MainWindow", "ID Machine :", nullptr));
        btnSupprimerValider->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Confirmer la suppression", nullptr));
        btnSupprimerValider->setObjectName(QCoreApplication::translate("MainWindow", "btnSupprimer", nullptr));
        btnSupprimerAnnuler->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler", nullptr));
        btnSupprimerAnnuler->setObjectName(QCoreApplication::translate("MainWindow", "btnAnnuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("MainWindow", " Supprimer Machine", nullptr));
        labelPanne->setText(QCoreApplication::translate("MainWindow", "<h2>Signaler une panne</h2><p>S\303\251lectionnez la machine en panne et d\303\251crivez le probl\303\250me.</p>", nullptr));
        labelPanneId->setText(QCoreApplication::translate("MainWindow", "ID Machine :", nullptr));
        labelPanneType->setText(QCoreApplication::translate("MainWindow", "Type de panne :", nullptr));
        comboPanneType->setItemText(0, QCoreApplication::translate("MainWindow", "Panne m\303\251canique", nullptr));
        comboPanneType->setItemText(1, QCoreApplication::translate("MainWindow", "Panne \303\251lectrique", nullptr));
        comboPanneType->setItemText(2, QCoreApplication::translate("MainWindow", "Panne \303\251lectronique", nullptr));
        comboPanneType->setItemText(3, QCoreApplication::translate("MainWindow", "Panne hydraulique", nullptr));
        comboPanneType->setItemText(4, QCoreApplication::translate("MainWindow", "Usure", nullptr));
        comboPanneType->setItemText(5, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        labelPanneDescription->setText(QCoreApplication::translate("MainWindow", "Description :", nullptr));
        labelPanneUrgence->setText(QCoreApplication::translate("MainWindow", "Niveau d'urgence :", nullptr));
        comboPanneUrgence->setItemText(0, QCoreApplication::translate("MainWindow", "Basse", nullptr));
        comboPanneUrgence->setItemText(1, QCoreApplication::translate("MainWindow", "Moyenne", nullptr));
        comboPanneUrgence->setItemText(2, QCoreApplication::translate("MainWindow", "Haute", nullptr));
        comboPanneUrgence->setItemText(3, QCoreApplication::translate("MainWindow", "Critique", nullptr));

        btnPanneValider->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Signaler la panne", nullptr));
        btnPanneValider->setObjectName(QCoreApplication::translate("MainWindow", "btnSignaler", nullptr));
        btnPanneAnnuler->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler", nullptr));
        btnPanneAnnuler->setObjectName(QCoreApplication::translate("MainWindow", "btnAnnuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPanne), QCoreApplication::translate("MainWindow", "Signaler Panne", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableHistorique->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableHistorique->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableHistorique->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Type d'intervention", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableHistorique->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableHistorique->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Co\303\273t", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableHistorique->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableHistorique->verticalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Termin\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableHistorique->verticalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "En cours", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableHistorique->verticalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Termin\303\251", nullptr));
        btnAddIntervention->setText(QCoreApplication::translate("MainWindow", "Ajouter intervention", nullptr));
        btnAddIntervention->setObjectName(QCoreApplication::translate("MainWindow", "btnAjouter", nullptr));
        btnExportPDF_Historique->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btnExportPDF_Historique->setObjectName(QCoreApplication::translate("MainWindow", "btnExportPDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistorique), QCoreApplication::translate("MainWindow", " Historique des Interventions", nullptr));
        groupBoxStatsCards->setTitle(QCoreApplication::translate("MainWindow", "\360\237\216\257 Tableau de Bord", nullptr));
        labelTotalIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\226\245\357\270\217", nullptr));
        labelTotalTitle->setText(QCoreApplication::translate("MainWindow", "Total Machines", nullptr));
        labelTotalTitle->setObjectName(QCoreApplication::translate("MainWindow", "cardTitle", nullptr));
        statTotal->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        statTotal->setObjectName(QCoreApplication::translate("MainWindow", "statValue", nullptr));
        labelOpIcon->setText(QCoreApplication::translate("MainWindow", "\342\234\205", nullptr));
        labelOpTitle->setText(QCoreApplication::translate("MainWindow", "Op\303\251rationnels", nullptr));
        labelOpTitle->setObjectName(QCoreApplication::translate("MainWindow", "cardTitle", nullptr));
        statOp->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        statOp->setObjectName(QCoreApplication::translate("MainWindow", "statValue", nullptr));
        labelMaintIcon->setText(QCoreApplication::translate("MainWindow", "\360\237\224\247", nullptr));
        labelMaintTitle->setText(QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        labelMaintTitle->setObjectName(QCoreApplication::translate("MainWindow", "cardTitle", nullptr));
        statMaint->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        statMaint->setObjectName(QCoreApplication::translate("MainWindow", "statValue", nullptr));
        labelDefIcon->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217", nullptr));
        labelDefTitle->setText(QCoreApplication::translate("MainWindow", "En panne", nullptr));
        labelDefTitle->setObjectName(QCoreApplication::translate("MainWindow", "cardTitle", nullptr));
        statDef->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        statDef->setObjectName(QCoreApplication::translate("MainWindow", "statValue", nullptr));
        groupBoxCategories->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 R\303\251partition par Cat\303\251gorie", nullptr));
        statsCategories->setHtml(QCoreApplication::translate("MainWindow", "<div style='text-align: center; padding: 15px;'>\n"
"                        <h3>R\303\251partition par Cat\303\251gorie</h3>\n"
"                        <table style='width: 100%;'>\n"
"                         <tr><td>Presse</td><td>1</td></tr>\n"
"                         <tr><td>Moteur</td><td>1</td></tr>\n"
"                         <tr><td>Filtre</td><td>1</td></tr>\n"
"                         <tr><td>Capteur</td><td>1</td></tr>\n"
"                        </table>\n"
"                       </div>", nullptr));
        groupBoxEtats->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\247 \303\211tat des Machines", nullptr));
        statsBreakdowns->setHtml(QCoreApplication::translate("MainWindow", "<div style='text-align: center; padding: 15px;'>\n"
"                        <h3>\303\211tat des Machines</h3>\n"
"                        <table style='width: 100%;'>\n"
"                         <tr><td>En service</td><td>2</td></tr>\n"
"                         <tr><td>Maintenance</td><td>1</td></tr>\n"
"                         <tr><td>Panne</td><td>1</td></tr>\n"
"                        </table>\n"
"                       </div>", nullptr));
        groupBoxKPIs->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\210 Indicateurs", nullptr));
        labelKpiInterventions->setText(QCoreApplication::translate("MainWindow", "Interventions", nullptr));
        kpiInterventionsValue->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        labelKpiCoutTotal->setText(QCoreApplication::translate("MainWindow", "Co\303\273t total", nullptr));
        kpiCoutTotalValue->setText(QCoreApplication::translate("MainWindow", "990.00 \342\202\254", nullptr));
        btnExportPDF_Stats->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btnExportPDF_Stats->setObjectName(QCoreApplication::translate("MainWindow", "btnExportPDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistics), QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques", nullptr));
        statusbar->setObjectName(QCoreApplication::translate("MainWindow", "statusBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
