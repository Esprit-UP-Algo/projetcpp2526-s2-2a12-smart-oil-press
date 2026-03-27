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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EquipeWidget
{
public:
    QStatusBar *statusbar;
    QVBoxLayout *mainContainerLayout;
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
    QWidget *pageadd;
    QVBoxLayout *addLayout;
    QLabel *addTitle;
    QFrame *addFormFrame;
    QFormLayout *addFormLayout;
    QLabel *labelAddTeamName;
    QLineEdit *inputAddTeamName;
    QLabel *labelAddTeamSpecialty;
    QComboBox *comboAddTeamSpecialty;
    QLabel *labelAddTeamMembers;
    QComboBox *comboAddTeamMembers;
    QLabel *label_add_etat;
    QComboBox *comboBox_add_etat;
    QSpacerItem *addSpacer;
    QHBoxLayout *addActionLayout;
    QSpacerItem *addActionSpacer;
    QPushButton *btnAddTeamSave;
    QWidget *page_rech;
    QVBoxLayout *rechLayout;
    QHBoxLayout *rechTopLayout;
    QLineEdit *lineEdit;
    QComboBox *comboBoxFilter;
    QSpacerItem *searchSpacer;
    QPushButton *btnRechercher;
    QHBoxLayout *rechMainLayout;
    QFrame *sortPanelFrame;
    QVBoxLayout *frame4Layout;
    QLabel *labelSortTeams;
    QPushButton *btnTrier;
    QComboBox *comboSortField;
    QHBoxLayout *sortOptionsLayout;
    QCheckBox *checkSortAscending;
    QCheckBox *checkSortDescending;
    QSpacerItem *frame4Spacer;
    QTableWidget *tableWidget;
    QWidget *pagemodif;
    QVBoxLayout *modifLayout;
    QLabel *modifTitle;
    QHBoxLayout *modifIdLayout;
    QLabel *label_mod_id;
    QLineEdit *lineEdit_mod_id;
    QFrame *modifFormFrame;
    QFormLayout *modifFormLayout;
    QLabel *labelUpdateTeamName;
    QLineEdit *inputUpdateTeamName;
    QLabel *labelUpdateTeamSpecialty;
    QComboBox *comboUpdateTeamSpecialty;
    QLabel *labelUpdateTeamMembers;
    QComboBox *comboUpdateTeamMembers;
    QLabel *label_etat;
    QComboBox *comboBox_mod_etat;
    QSpacerItem *modifSpacer;
    QHBoxLayout *modifActionLayout;
    QSpacerItem *modifActionSpacer;
    QPushButton *btnUpdateTeam;
    QWidget *pagesupp;
    QVBoxLayout *suppLayout;
    QLabel *suppTitle;
    QFrame *suppFormFrame;
    QVBoxLayout *suppFormLayout;
    QLabel *suppWarning;
    QHBoxLayout *suppIdLayout;
    QLabel *labelDeleteTeamId;
    QLineEdit *inputDeleteTeamId;
    QSpacerItem *suppSpacer;
    QHBoxLayout *suppActionLayout;
    QSpacerItem *suppActionSpacer;
    QPushButton *btnDeleteTeam;
    QWidget *page_stat;
    QVBoxLayout *statLayout;
    QScrollArea *statsScrollArea;
    QWidget *statsScrollContent;
    QVBoxLayout *statsScrollContentLayout;
    QLabel *statTitle;
    QHBoxLayout *statsExportButtonsLayout;
    QPushButton *pushButton_exportGlobalStatsPdf;
    QPushButton *pushButton_exportTeamDetailsPdf;
    QSpacerItem *statsExportSpacer;
    QGroupBox *overallTeamsStatsGroup;
    QVBoxLayout *overallTeamsStatsLayout;
    QHBoxLayout *overallStatsHeaderLayout;
    QLabel *label_totalTeams;
    QLabel *label_specialtyCount;
    QSpacerItem *overallHeaderSpacer;
    QWidget *overallSpecialtyChartHost;
    QLabel *label_overallStatsHint;
    QGroupBox *specialtyDetailsGroup;
    QVBoxLayout *specialtyDetailsLayout;
    QTableWidget *specialtyStatsTable;
    QLabel *specialtyDetailsHintLabel;
    QGroupBox *section1Group;
    QVBoxLayout *section1Layout;
    QHBoxLayout *teamDetailsSelectorLayout;
    QLabel *label_selectTeamDetails;
    QLineEdit *lineEdit_teamDetailsId;
    QPushButton *pushButton_validateTeamDetails;
    QSpacerItem *teamDetailsSelectorSpacer;
    QLabel *selectedTeamDetailsLabel;
    QFormLayout *teamDetailsMetricsLayout;
    QLabel *label_completedTasks;
    QLabel *completedTasksValueLabel;
    QLabel *label_failedTasks;
    QLabel *failedTasksValueLabel;
    QLabel *label_teamRate;
    QLabel *teamRateValueLabel;
    QLabel *teamFeedbackLabel;
    QGroupBox *section2Group;
    QVBoxLayout *section2Layout;
    QTableWidget *performanceRankingTable;
    QWidget *sugg;
    QVBoxLayout *suggestionLayout;
    QScrollArea *suggestionScrollArea;
    QWidget *suggestionScrollContent;
    QVBoxLayout *suggestionScrollContentLayout;
    QGroupBox *suggestionQuestionsGroup;
    QVBoxLayout *suggestionQuestionsLayout;
    QFormLayout *suggestionFormLayout;
    QLabel *labelSuggestionSpecialty;
    QComboBox *comboSuggestionSpecialty;
    QLabel *labelSuggestionMinMembers;
    QLineEdit *inputSuggestionMinMembers;
    QLabel *labelSuggestionCase;
    QHBoxLayout *casesLayout;
    QCheckBox *checkSuggestionUrgent;
    QCheckBox *checkSuggestionNormalState;
    QSpacerItem *casesSpacer;
    QLabel *labelSuggestionDifficulty;
    QComboBox *comboSuggestionDifficulty;
    QCheckBox *checkSuggestionRequiresAvailability;
    QHBoxLayout *suggestionActionLayout;
    QSpacerItem *suggestionActionSpacer;
    QPushButton *btnRunSuggestionSearch;
    QGroupBox *suggestionResultsGroup;
    QVBoxLayout *suggestionResultsLayout;
    QLabel *labelSuggestionBestRecommendations;
    QTableWidget *suggestionResultsTable;
    QWidget *page_planification;
    QVBoxLayout *planLayout;
    QHBoxLayout *teamSelectionLayout;
    QLabel *label_teamSelection;
    QLineEdit *lineEdit_teamId;
    QPushButton *pushButton_validateTeam;
    QSpacerItem *horizontalSpacer_teamSelection;
    QLabel *label_teamStatus;
    QHBoxLayout *planContentLayout;
    QFrame *taskFrame;
    QVBoxLayout *taskLayout;
    QLabel *taskLabel;
    QTableWidget *planningTableWidget;
    QHBoxLayout *taskButtonsLayout;
    QPushButton *pushButton_addTask;
    QPushButton *pushButton_deleteTask;
    QLabel *taskInstructionLabel;
    QVBoxLayout *calendarSectionLayout;
    QCalendarWidget *calendarWidget;
    QLabel *calendarInstructionLabel;

    void setupUi(QWidget *EquipeWidget)
    {
        if (EquipeWidget->objectName().isEmpty())
            EquipeWidget->setObjectName("EquipeWidget");
        EquipeWidget->resize(800, 600);
        statusbar = new QStatusBar(EquipeWidget);
        statusbar->setObjectName("statusbar");
        mainContainerLayout = new QVBoxLayout(EquipeWidget);
        mainContainerLayout->setSpacing(0);
        mainContainerLayout->setObjectName("mainContainerLayout");
        mainContainerLayout->setContentsMargins(0, 0, 0, 0);
        contentFrame = new QFrame(EquipeWidget);
        contentFrame->setObjectName("contentFrame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(contentFrame->sizePolicy().hasHeightForWidth());
        contentFrame->setSizePolicy(sizePolicy);
        contentLayout = new QVBoxLayout(contentFrame);
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        topNavTabs = new QTabWidget(contentFrame);
        topNavTabs->setObjectName("topNavTabs");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topNavTabs->sizePolicy().hasHeightForWidth());
        topNavTabs->setSizePolicy(sizePolicy1);
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
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
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
        labelAddTeamName = new QLabel(addFormFrame);
        labelAddTeamName->setObjectName("labelAddTeamName");

        addFormLayout->setWidget(0, QFormLayout::LabelRole, labelAddTeamName);

        inputAddTeamName = new QLineEdit(addFormFrame);
        inputAddTeamName->setObjectName("inputAddTeamName");

        addFormLayout->setWidget(0, QFormLayout::FieldRole, inputAddTeamName);

        labelAddTeamSpecialty = new QLabel(addFormFrame);
        labelAddTeamSpecialty->setObjectName("labelAddTeamSpecialty");

        addFormLayout->setWidget(1, QFormLayout::LabelRole, labelAddTeamSpecialty);

        comboAddTeamSpecialty = new QComboBox(addFormFrame);
        comboAddTeamSpecialty->addItem(QString());
        comboAddTeamSpecialty->addItem(QString());
        comboAddTeamSpecialty->addItem(QString());
        comboAddTeamSpecialty->addItem(QString());
        comboAddTeamSpecialty->addItem(QString());
        comboAddTeamSpecialty->setObjectName("comboAddTeamSpecialty");

        addFormLayout->setWidget(1, QFormLayout::FieldRole, comboAddTeamSpecialty);

        labelAddTeamMembers = new QLabel(addFormFrame);
        labelAddTeamMembers->setObjectName("labelAddTeamMembers");

        addFormLayout->setWidget(2, QFormLayout::LabelRole, labelAddTeamMembers);

        comboAddTeamMembers = new QComboBox(addFormFrame);
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->addItem(QString());
        comboAddTeamMembers->setObjectName("comboAddTeamMembers");

        addFormLayout->setWidget(2, QFormLayout::FieldRole, comboAddTeamMembers);

        label_add_etat = new QLabel(addFormFrame);
        label_add_etat->setObjectName("label_add_etat");

        addFormLayout->setWidget(3, QFormLayout::LabelRole, label_add_etat);

        comboBox_add_etat = new QComboBox(addFormFrame);
        comboBox_add_etat->addItem(QString());
        comboBox_add_etat->addItem(QString());
        comboBox_add_etat->addItem(QString());
        comboBox_add_etat->setObjectName("comboBox_add_etat");

        addFormLayout->setWidget(3, QFormLayout::FieldRole, comboBox_add_etat);


        addLayout->addWidget(addFormFrame);

        addSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        addLayout->addItem(addSpacer);

        addActionLayout = new QHBoxLayout();
        addActionLayout->setObjectName("addActionLayout");
        addActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        addActionLayout->addItem(addActionSpacer);

        btnAddTeamSave = new QPushButton(pageadd);
        btnAddTeamSave->setObjectName("btnAddTeamSave");
        btnAddTeamSave->setMinimumWidth(200);

        addActionLayout->addWidget(btnAddTeamSave);


        addLayout->addLayout(addActionLayout);

        stackedWidget->addWidget(pageadd);
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

        comboBoxFilter = new QComboBox(page_rech);
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->addItem(QString());
        comboBoxFilter->setObjectName("comboBoxFilter");
        comboBoxFilter->setMaximumWidth(150);

        rechTopLayout->addWidget(comboBoxFilter);

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
        sortPanelFrame = new QFrame(page_rech);
        sortPanelFrame->setObjectName("sortPanelFrame");
        frame4Layout = new QVBoxLayout(sortPanelFrame);
        frame4Layout->setSpacing(12);
        frame4Layout->setObjectName("frame4Layout");
        labelSortTeams = new QLabel(sortPanelFrame);
        labelSortTeams->setObjectName("labelSortTeams");

        frame4Layout->addWidget(labelSortTeams);

        btnTrier = new QPushButton(sortPanelFrame);
        btnTrier->setObjectName("btnTrier");

        frame4Layout->addWidget(btnTrier);

        comboSortField = new QComboBox(sortPanelFrame);
        comboSortField->addItem(QString());
        comboSortField->addItem(QString());
        comboSortField->addItem(QString());
        comboSortField->addItem(QString());
        comboSortField->addItem(QString());
        comboSortField->addItem(QString());
        comboSortField->setObjectName("comboSortField");

        frame4Layout->addWidget(comboSortField);

        sortOptionsLayout = new QHBoxLayout();
        sortOptionsLayout->setObjectName("sortOptionsLayout");
        checkSortAscending = new QCheckBox(sortPanelFrame);
        checkSortAscending->setObjectName("checkSortAscending");

        sortOptionsLayout->addWidget(checkSortAscending);

        checkSortDescending = new QCheckBox(sortPanelFrame);
        checkSortDescending->setObjectName("checkSortDescending");

        sortOptionsLayout->addWidget(checkSortDescending);


        frame4Layout->addLayout(sortOptionsLayout);

        frame4Spacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        frame4Layout->addItem(frame4Spacer);


        rechMainLayout->addWidget(sortPanelFrame);

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
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);
        tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidget->setAutoScroll(false);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        rechMainLayout->addWidget(tableWidget);


        rechLayout->addLayout(rechMainLayout);

        stackedWidget->addWidget(page_rech);
        pagemodif = new QWidget();
        pagemodif->setObjectName("pagemodif");
        modifLayout = new QVBoxLayout(pagemodif);
        modifLayout->setObjectName("modifLayout");
        modifTitle = new QLabel(pagemodif);
        modifTitle->setObjectName("modifTitle");

        modifLayout->addWidget(modifTitle);

        modifIdLayout = new QHBoxLayout();
        modifIdLayout->setObjectName("modifIdLayout");
        label_mod_id = new QLabel(pagemodif);
        label_mod_id->setObjectName("label_mod_id");

        modifIdLayout->addWidget(label_mod_id);

        lineEdit_mod_id = new QLineEdit(pagemodif);
        lineEdit_mod_id->setObjectName("lineEdit_mod_id");
        lineEdit_mod_id->setMaximumWidth(240);

        modifIdLayout->addWidget(lineEdit_mod_id);


        modifLayout->addLayout(modifIdLayout);

        modifFormFrame = new QFrame(pagemodif);
        modifFormFrame->setObjectName("modifFormFrame");
        modifFormLayout = new QFormLayout(modifFormFrame);
        modifFormLayout->setObjectName("modifFormLayout");
        labelUpdateTeamName = new QLabel(modifFormFrame);
        labelUpdateTeamName->setObjectName("labelUpdateTeamName");

        modifFormLayout->setWidget(0, QFormLayout::LabelRole, labelUpdateTeamName);

        inputUpdateTeamName = new QLineEdit(modifFormFrame);
        inputUpdateTeamName->setObjectName("inputUpdateTeamName");

        modifFormLayout->setWidget(0, QFormLayout::FieldRole, inputUpdateTeamName);

        labelUpdateTeamSpecialty = new QLabel(modifFormFrame);
        labelUpdateTeamSpecialty->setObjectName("labelUpdateTeamSpecialty");

        modifFormLayout->setWidget(1, QFormLayout::LabelRole, labelUpdateTeamSpecialty);

        comboUpdateTeamSpecialty = new QComboBox(modifFormFrame);
        comboUpdateTeamSpecialty->addItem(QString());
        comboUpdateTeamSpecialty->addItem(QString());
        comboUpdateTeamSpecialty->addItem(QString());
        comboUpdateTeamSpecialty->addItem(QString());
        comboUpdateTeamSpecialty->addItem(QString());
        comboUpdateTeamSpecialty->setObjectName("comboUpdateTeamSpecialty");

        modifFormLayout->setWidget(1, QFormLayout::FieldRole, comboUpdateTeamSpecialty);

        labelUpdateTeamMembers = new QLabel(modifFormFrame);
        labelUpdateTeamMembers->setObjectName("labelUpdateTeamMembers");

        modifFormLayout->setWidget(2, QFormLayout::LabelRole, labelUpdateTeamMembers);

        comboUpdateTeamMembers = new QComboBox(modifFormFrame);
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->addItem(QString());
        comboUpdateTeamMembers->setObjectName("comboUpdateTeamMembers");

        modifFormLayout->setWidget(2, QFormLayout::FieldRole, comboUpdateTeamMembers);

        label_etat = new QLabel(modifFormFrame);
        label_etat->setObjectName("label_etat");

        modifFormLayout->setWidget(4, QFormLayout::LabelRole, label_etat);

        comboBox_mod_etat = new QComboBox(modifFormFrame);
        comboBox_mod_etat->addItem(QString());
        comboBox_mod_etat->addItem(QString());
        comboBox_mod_etat->addItem(QString());
        comboBox_mod_etat->setObjectName("comboBox_mod_etat");

        modifFormLayout->setWidget(4, QFormLayout::FieldRole, comboBox_mod_etat);


        modifLayout->addWidget(modifFormFrame);

        modifSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        modifLayout->addItem(modifSpacer);

        modifActionLayout = new QHBoxLayout();
        modifActionLayout->setObjectName("modifActionLayout");
        modifActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        modifActionLayout->addItem(modifActionSpacer);

        btnUpdateTeam = new QPushButton(pagemodif);
        btnUpdateTeam->setObjectName("btnUpdateTeam");
        btnUpdateTeam->setMinimumWidth(200);

        modifActionLayout->addWidget(btnUpdateTeam);


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
        labelDeleteTeamId = new QLabel(suppFormFrame);
        labelDeleteTeamId->setObjectName("labelDeleteTeamId");

        suppIdLayout->addWidget(labelDeleteTeamId);

        inputDeleteTeamId = new QLineEdit(suppFormFrame);
        inputDeleteTeamId->setObjectName("inputDeleteTeamId");

        suppIdLayout->addWidget(inputDeleteTeamId);


        suppFormLayout->addLayout(suppIdLayout);

        suppSpacer = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        suppFormLayout->addItem(suppSpacer);

        suppActionLayout = new QHBoxLayout();
        suppActionLayout->setObjectName("suppActionLayout");
        suppActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        suppActionLayout->addItem(suppActionSpacer);

        btnDeleteTeam = new QPushButton(suppFormFrame);
        btnDeleteTeam->setObjectName("btnDeleteTeam");
        btnDeleteTeam->setMinimumWidth(200);

        suppActionLayout->addWidget(btnDeleteTeam);


        suppFormLayout->addLayout(suppActionLayout);


        suppLayout->addWidget(suppFormFrame);

        stackedWidget->addWidget(pagesupp);
        page_stat = new QWidget();
        page_stat->setObjectName("page_stat");
        statLayout = new QVBoxLayout(page_stat);
        statLayout->setObjectName("statLayout");
        statsScrollArea = new QScrollArea(page_stat);
        statsScrollArea->setObjectName("statsScrollArea");
        statsScrollArea->setWidgetResizable(true);
        statsScrollContent = new QWidget();
        statsScrollContent->setObjectName("statsScrollContent");
        statsScrollContentLayout = new QVBoxLayout(statsScrollContent);
        statsScrollContentLayout->setObjectName("statsScrollContentLayout");
        statTitle = new QLabel(statsScrollContent);
        statTitle->setObjectName("statTitle");

        statsScrollContentLayout->addWidget(statTitle);

        statsExportButtonsLayout = new QHBoxLayout();
        statsExportButtonsLayout->setObjectName("statsExportButtonsLayout");
        pushButton_exportGlobalStatsPdf = new QPushButton(statsScrollContent);
        pushButton_exportGlobalStatsPdf->setObjectName("pushButton_exportGlobalStatsPdf");
        pushButton_exportGlobalStatsPdf->setMinimumSize(QSize(220, 36));

        statsExportButtonsLayout->addWidget(pushButton_exportGlobalStatsPdf);

        pushButton_exportTeamDetailsPdf = new QPushButton(statsScrollContent);
        pushButton_exportTeamDetailsPdf->setObjectName("pushButton_exportTeamDetailsPdf");
        pushButton_exportTeamDetailsPdf->setMinimumSize(QSize(220, 36));

        statsExportButtonsLayout->addWidget(pushButton_exportTeamDetailsPdf);

        statsExportSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        statsExportButtonsLayout->addItem(statsExportSpacer);


        statsScrollContentLayout->addLayout(statsExportButtonsLayout);

        overallTeamsStatsGroup = new QGroupBox(statsScrollContent);
        overallTeamsStatsGroup->setObjectName("overallTeamsStatsGroup");
        overallTeamsStatsLayout = new QVBoxLayout(overallTeamsStatsGroup);
        overallTeamsStatsLayout->setObjectName("overallTeamsStatsLayout");
        overallStatsHeaderLayout = new QHBoxLayout();
        overallStatsHeaderLayout->setObjectName("overallStatsHeaderLayout");
        label_totalTeams = new QLabel(overallTeamsStatsGroup);
        label_totalTeams->setObjectName("label_totalTeams");

        overallStatsHeaderLayout->addWidget(label_totalTeams);

        label_specialtyCount = new QLabel(overallTeamsStatsGroup);
        label_specialtyCount->setObjectName("label_specialtyCount");

        overallStatsHeaderLayout->addWidget(label_specialtyCount);

        overallHeaderSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        overallStatsHeaderLayout->addItem(overallHeaderSpacer);


        overallTeamsStatsLayout->addLayout(overallStatsHeaderLayout);

        overallSpecialtyChartHost = new QWidget(overallTeamsStatsGroup);
        overallSpecialtyChartHost->setObjectName("overallSpecialtyChartHost");
        overallSpecialtyChartHost->setMinimumSize(QSize(0, 420));

        overallTeamsStatsLayout->addWidget(overallSpecialtyChartHost);

        label_overallStatsHint = new QLabel(overallTeamsStatsGroup);
        label_overallStatsHint->setObjectName("label_overallStatsHint");

        overallTeamsStatsLayout->addWidget(label_overallStatsHint);


        statsScrollContentLayout->addWidget(overallTeamsStatsGroup);

        specialtyDetailsGroup = new QGroupBox(statsScrollContent);
        specialtyDetailsGroup->setObjectName("specialtyDetailsGroup");
        specialtyDetailsLayout = new QVBoxLayout(specialtyDetailsGroup);
        specialtyDetailsLayout->setObjectName("specialtyDetailsLayout");
        specialtyStatsTable = new QTableWidget(specialtyDetailsGroup);
        if (specialtyStatsTable->columnCount() < 5)
            specialtyStatsTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        specialtyStatsTable->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        specialtyStatsTable->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        specialtyStatsTable->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        specialtyStatsTable->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        specialtyStatsTable->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        specialtyStatsTable->setObjectName("specialtyStatsTable");
        specialtyStatsTable->setColumnCount(5);
        specialtyStatsTable->setRowCount(0);

        specialtyDetailsLayout->addWidget(specialtyStatsTable);

        specialtyDetailsHintLabel = new QLabel(specialtyDetailsGroup);
        specialtyDetailsHintLabel->setObjectName("specialtyDetailsHintLabel");

        specialtyDetailsLayout->addWidget(specialtyDetailsHintLabel);


        statsScrollContentLayout->addWidget(specialtyDetailsGroup);

        section1Group = new QGroupBox(statsScrollContent);
        section1Group->setObjectName("section1Group");
        section1Layout = new QVBoxLayout(section1Group);
        section1Layout->setObjectName("section1Layout");
        teamDetailsSelectorLayout = new QHBoxLayout();
        teamDetailsSelectorLayout->setObjectName("teamDetailsSelectorLayout");
        label_selectTeamDetails = new QLabel(section1Group);
        label_selectTeamDetails->setObjectName("label_selectTeamDetails");

        teamDetailsSelectorLayout->addWidget(label_selectTeamDetails);

        lineEdit_teamDetailsId = new QLineEdit(section1Group);
        lineEdit_teamDetailsId->setObjectName("lineEdit_teamDetailsId");
        lineEdit_teamDetailsId->setMaximumSize(QSize(180, 16777215));

        teamDetailsSelectorLayout->addWidget(lineEdit_teamDetailsId);

        pushButton_validateTeamDetails = new QPushButton(section1Group);
        pushButton_validateTeamDetails->setObjectName("pushButton_validateTeamDetails");

        teamDetailsSelectorLayout->addWidget(pushButton_validateTeamDetails);

        teamDetailsSelectorSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        teamDetailsSelectorLayout->addItem(teamDetailsSelectorSpacer);


        section1Layout->addLayout(teamDetailsSelectorLayout);

        selectedTeamDetailsLabel = new QLabel(section1Group);
        selectedTeamDetailsLabel->setObjectName("selectedTeamDetailsLabel");

        section1Layout->addWidget(selectedTeamDetailsLabel);

        teamDetailsMetricsLayout = new QFormLayout();
        teamDetailsMetricsLayout->setObjectName("teamDetailsMetricsLayout");
        label_completedTasks = new QLabel(section1Group);
        label_completedTasks->setObjectName("label_completedTasks");

        teamDetailsMetricsLayout->setWidget(0, QFormLayout::LabelRole, label_completedTasks);

        completedTasksValueLabel = new QLabel(section1Group);
        completedTasksValueLabel->setObjectName("completedTasksValueLabel");

        teamDetailsMetricsLayout->setWidget(0, QFormLayout::FieldRole, completedTasksValueLabel);

        label_failedTasks = new QLabel(section1Group);
        label_failedTasks->setObjectName("label_failedTasks");

        teamDetailsMetricsLayout->setWidget(1, QFormLayout::LabelRole, label_failedTasks);

        failedTasksValueLabel = new QLabel(section1Group);
        failedTasksValueLabel->setObjectName("failedTasksValueLabel");

        teamDetailsMetricsLayout->setWidget(1, QFormLayout::FieldRole, failedTasksValueLabel);

        label_teamRate = new QLabel(section1Group);
        label_teamRate->setObjectName("label_teamRate");

        teamDetailsMetricsLayout->setWidget(2, QFormLayout::LabelRole, label_teamRate);

        teamRateValueLabel = new QLabel(section1Group);
        teamRateValueLabel->setObjectName("teamRateValueLabel");

        teamDetailsMetricsLayout->setWidget(2, QFormLayout::FieldRole, teamRateValueLabel);


        section1Layout->addLayout(teamDetailsMetricsLayout);

        teamFeedbackLabel = new QLabel(section1Group);
        teamFeedbackLabel->setObjectName("teamFeedbackLabel");
        teamFeedbackLabel->setWordWrap(true);

        section1Layout->addWidget(teamFeedbackLabel);


        statsScrollContentLayout->addWidget(section1Group);

        section2Group = new QGroupBox(statsScrollContent);
        section2Group->setObjectName("section2Group");
        section2Layout = new QVBoxLayout(section2Group);
        section2Layout->setObjectName("section2Layout");
        performanceRankingTable = new QTableWidget(section2Group);
        if (performanceRankingTable->columnCount() < 4)
            performanceRankingTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        performanceRankingTable->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        performanceRankingTable->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        performanceRankingTable->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        performanceRankingTable->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        performanceRankingTable->setObjectName("performanceRankingTable");
        performanceRankingTable->setColumnCount(4);
        performanceRankingTable->setRowCount(0);

        section2Layout->addWidget(performanceRankingTable);


        statsScrollContentLayout->addWidget(section2Group);

        statsScrollArea->setWidget(statsScrollContent);

        statLayout->addWidget(statsScrollArea);

        stackedWidget->addWidget(page_stat);
        sugg = new QWidget();
        sugg->setObjectName("sugg");
        suggestionLayout = new QVBoxLayout(sugg);
        suggestionLayout->setObjectName("suggestionLayout");
        suggestionScrollArea = new QScrollArea(sugg);
        suggestionScrollArea->setObjectName("suggestionScrollArea");
        suggestionScrollArea->setWidgetResizable(true);
        suggestionScrollContent = new QWidget();
        suggestionScrollContent->setObjectName("suggestionScrollContent");
        suggestionScrollContentLayout = new QVBoxLayout(suggestionScrollContent);
        suggestionScrollContentLayout->setObjectName("suggestionScrollContentLayout");
        suggestionQuestionsGroup = new QGroupBox(suggestionScrollContent);
        suggestionQuestionsGroup->setObjectName("suggestionQuestionsGroup");
        suggestionQuestionsLayout = new QVBoxLayout(suggestionQuestionsGroup);
        suggestionQuestionsLayout->setObjectName("suggestionQuestionsLayout");
        suggestionFormLayout = new QFormLayout();
        suggestionFormLayout->setObjectName("suggestionFormLayout");
        labelSuggestionSpecialty = new QLabel(suggestionQuestionsGroup);
        labelSuggestionSpecialty->setObjectName("labelSuggestionSpecialty");

        suggestionFormLayout->setWidget(0, QFormLayout::LabelRole, labelSuggestionSpecialty);

        comboSuggestionSpecialty = new QComboBox(suggestionQuestionsGroup);
        comboSuggestionSpecialty->addItem(QString());
        comboSuggestionSpecialty->addItem(QString());
        comboSuggestionSpecialty->addItem(QString());
        comboSuggestionSpecialty->addItem(QString());
        comboSuggestionSpecialty->addItem(QString());
        comboSuggestionSpecialty->addItem(QString());
        comboSuggestionSpecialty->setObjectName("comboSuggestionSpecialty");

        suggestionFormLayout->setWidget(0, QFormLayout::FieldRole, comboSuggestionSpecialty);

        labelSuggestionMinMembers = new QLabel(suggestionQuestionsGroup);
        labelSuggestionMinMembers->setObjectName("labelSuggestionMinMembers");

        suggestionFormLayout->setWidget(1, QFormLayout::LabelRole, labelSuggestionMinMembers);

        inputSuggestionMinMembers = new QLineEdit(suggestionQuestionsGroup);
        inputSuggestionMinMembers->setObjectName("inputSuggestionMinMembers");

        suggestionFormLayout->setWidget(1, QFormLayout::FieldRole, inputSuggestionMinMembers);

        labelSuggestionCase = new QLabel(suggestionQuestionsGroup);
        labelSuggestionCase->setObjectName("labelSuggestionCase");

        suggestionFormLayout->setWidget(2, QFormLayout::LabelRole, labelSuggestionCase);

        casesLayout = new QHBoxLayout();
        casesLayout->setObjectName("casesLayout");
        checkSuggestionUrgent = new QCheckBox(suggestionQuestionsGroup);
        checkSuggestionUrgent->setObjectName("checkSuggestionUrgent");

        casesLayout->addWidget(checkSuggestionUrgent);

        checkSuggestionNormalState = new QCheckBox(suggestionQuestionsGroup);
        checkSuggestionNormalState->setObjectName("checkSuggestionNormalState");

        casesLayout->addWidget(checkSuggestionNormalState);

        casesSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        casesLayout->addItem(casesSpacer);


        suggestionFormLayout->setLayout(2, QFormLayout::FieldRole, casesLayout);

        labelSuggestionDifficulty = new QLabel(suggestionQuestionsGroup);
        labelSuggestionDifficulty->setObjectName("labelSuggestionDifficulty");

        suggestionFormLayout->setWidget(3, QFormLayout::LabelRole, labelSuggestionDifficulty);

        comboSuggestionDifficulty = new QComboBox(suggestionQuestionsGroup);
        comboSuggestionDifficulty->addItem(QString());
        comboSuggestionDifficulty->addItem(QString());
        comboSuggestionDifficulty->addItem(QString());
        comboSuggestionDifficulty->addItem(QString());
        comboSuggestionDifficulty->setObjectName("comboSuggestionDifficulty");

        suggestionFormLayout->setWidget(3, QFormLayout::FieldRole, comboSuggestionDifficulty);


        suggestionQuestionsLayout->addLayout(suggestionFormLayout);

        checkSuggestionRequiresAvailability = new QCheckBox(suggestionQuestionsGroup);
        checkSuggestionRequiresAvailability->setObjectName("checkSuggestionRequiresAvailability");

        suggestionQuestionsLayout->addWidget(checkSuggestionRequiresAvailability);

        suggestionActionLayout = new QHBoxLayout();
        suggestionActionLayout->setObjectName("suggestionActionLayout");
        suggestionActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        suggestionActionLayout->addItem(suggestionActionSpacer);

        btnRunSuggestionSearch = new QPushButton(suggestionQuestionsGroup);
        btnRunSuggestionSearch->setObjectName("btnRunSuggestionSearch");
        btnRunSuggestionSearch->setMinimumSize(QSize(220, 40));

        suggestionActionLayout->addWidget(btnRunSuggestionSearch);


        suggestionQuestionsLayout->addLayout(suggestionActionLayout);


        suggestionScrollContentLayout->addWidget(suggestionQuestionsGroup);

        suggestionResultsGroup = new QGroupBox(suggestionScrollContent);
        suggestionResultsGroup->setObjectName("suggestionResultsGroup");
        suggestionResultsLayout = new QVBoxLayout(suggestionResultsGroup);
        suggestionResultsLayout->setObjectName("suggestionResultsLayout");
        labelSuggestionBestRecommendations = new QLabel(suggestionResultsGroup);
        labelSuggestionBestRecommendations->setObjectName("labelSuggestionBestRecommendations");

        suggestionResultsLayout->addWidget(labelSuggestionBestRecommendations);

        suggestionResultsTable = new QTableWidget(suggestionResultsGroup);
        if (suggestionResultsTable->columnCount() < 10)
            suggestionResultsTable->setColumnCount(10);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(5, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(6, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(7, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(8, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        suggestionResultsTable->setHorizontalHeaderItem(9, __qtablewidgetitem24);
        suggestionResultsTable->setObjectName("suggestionResultsTable");
        suggestionResultsTable->setColumnCount(10);
        suggestionResultsTable->setRowCount(0);

        suggestionResultsLayout->addWidget(suggestionResultsTable);


        suggestionScrollContentLayout->addWidget(suggestionResultsGroup);

        suggestionScrollArea->setWidget(suggestionScrollContent);

        suggestionLayout->addWidget(suggestionScrollArea);

        stackedWidget->addWidget(sugg);
        page_planification = new QWidget();
        page_planification->setObjectName("page_planification");
        planLayout = new QVBoxLayout(page_planification);
        planLayout->setSpacing(8);
        planLayout->setObjectName("planLayout");
        teamSelectionLayout = new QHBoxLayout();
        teamSelectionLayout->setSpacing(8);
        teamSelectionLayout->setObjectName("teamSelectionLayout");
        label_teamSelection = new QLabel(page_planification);
        label_teamSelection->setObjectName("label_teamSelection");

        teamSelectionLayout->addWidget(label_teamSelection);

        lineEdit_teamId = new QLineEdit(page_planification);
        lineEdit_teamId->setObjectName("lineEdit_teamId");
        lineEdit_teamId->setMinimumWidth(220);

        teamSelectionLayout->addWidget(lineEdit_teamId);

        pushButton_validateTeam = new QPushButton(page_planification);
        pushButton_validateTeam->setObjectName("pushButton_validateTeam");
        pushButton_validateTeam->setMinimumSize(QSize(100, 0));
        pushButton_validateTeam->setMaximumSize(QSize(100, 16777215));

        teamSelectionLayout->addWidget(pushButton_validateTeam);

        horizontalSpacer_teamSelection = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        teamSelectionLayout->addItem(horizontalSpacer_teamSelection);


        planLayout->addLayout(teamSelectionLayout);

        label_teamStatus = new QLabel(page_planification);
        label_teamStatus->setObjectName("label_teamStatus");

        planLayout->addWidget(label_teamStatus);

        planContentLayout = new QHBoxLayout();
        planContentLayout->setSpacing(8);
        planContentLayout->setObjectName("planContentLayout");
        taskFrame = new QFrame(page_planification);
        taskFrame->setObjectName("taskFrame");
        sizePolicy2.setHeightForWidth(taskFrame->sizePolicy().hasHeightForWidth());
        taskFrame->setSizePolicy(sizePolicy2);
        taskFrame->setMinimumSize(QSize(300, 400));
        taskLayout = new QVBoxLayout(taskFrame);
        taskLayout->setSpacing(4);
        taskLayout->setObjectName("taskLayout");
        taskLabel = new QLabel(taskFrame);
        taskLabel->setObjectName("taskLabel");

        taskLayout->addWidget(taskLabel);

        planningTableWidget = new QTableWidget(taskFrame);
        if (planningTableWidget->columnCount() < 4)
            planningTableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        planningTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        planningTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        planningTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        planningTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem28);
        planningTableWidget->setObjectName("planningTableWidget");
        sizePolicy.setHeightForWidth(planningTableWidget->sizePolicy().hasHeightForWidth());
        planningTableWidget->setSizePolicy(sizePolicy);
        planningTableWidget->setColumnCount(4);
        planningTableWidget->setRowCount(0);

        taskLayout->addWidget(planningTableWidget);

        taskButtonsLayout = new QHBoxLayout();
        taskButtonsLayout->setSpacing(8);
        taskButtonsLayout->setObjectName("taskButtonsLayout");
        pushButton_addTask = new QPushButton(taskFrame);
        pushButton_addTask->setObjectName("pushButton_addTask");
        pushButton_addTask->setMinimumSize(QSize(0, 35));

        taskButtonsLayout->addWidget(pushButton_addTask);

        pushButton_deleteTask = new QPushButton(taskFrame);
        pushButton_deleteTask->setObjectName("pushButton_deleteTask");
        pushButton_deleteTask->setMinimumSize(QSize(0, 35));

        taskButtonsLayout->addWidget(pushButton_deleteTask);


        taskLayout->addLayout(taskButtonsLayout);

        taskInstructionLabel = new QLabel(taskFrame);
        taskInstructionLabel->setObjectName("taskInstructionLabel");
        taskInstructionLabel->setWordWrap(true);
        taskInstructionLabel->setAlignment(Qt::AlignTop);

        taskLayout->addWidget(taskInstructionLabel);


        planContentLayout->addWidget(taskFrame);

        calendarSectionLayout = new QVBoxLayout();
        calendarSectionLayout->setObjectName("calendarSectionLayout");
        calendarWidget = new QCalendarWidget(page_planification);
        calendarWidget->setObjectName("calendarWidget");
        sizePolicy2.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy2);
        calendarWidget->setMinimumSize(QSize(350, 400));

        calendarSectionLayout->addWidget(calendarWidget);

        calendarInstructionLabel = new QLabel(page_planification);
        calendarInstructionLabel->setObjectName("calendarInstructionLabel");
        calendarInstructionLabel->setWordWrap(true);
        calendarInstructionLabel->setAlignment(Qt::AlignTop);

        calendarSectionLayout->addWidget(calendarInstructionLabel);


        planContentLayout->addLayout(calendarSectionLayout);


        planLayout->addLayout(planContentLayout);

        stackedWidget->addWidget(page_planification);

        contentLayout->addWidget(stackedWidget);


        mainContainerLayout->addWidget(contentFrame);


        retranslateUi(EquipeWidget);

        topNavTabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EquipeWidget);
    } // setupUi

    void retranslateUi(QWidget *EquipeWidget)
    {
        topNavTabs->setTabText(topNavTabs->indexOf(tabAjouter), QCoreApplication::translate("EquipeWidget", "Ajouter une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabGestion), QCoreApplication::translate("EquipeWidget", "Liste des \303\251quipes", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSupprimer), QCoreApplication::translate("EquipeWidget", "Supprimer une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabModifier), QCoreApplication::translate("EquipeWidget", "Modifier une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabStatistique), QCoreApplication::translate("EquipeWidget", "Statistique", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSuggestion), QCoreApplication::translate("EquipeWidget", "Suggestion", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabPlanification), QCoreApplication::translate("EquipeWidget", "Planification", nullptr));
        addTitle->setText(QCoreApplication::translate("EquipeWidget", "Ajouter une \303\211quipe", nullptr));
        labelAddTeamName->setText(QCoreApplication::translate("EquipeWidget", "Nom:", nullptr));
        inputAddTeamName->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "Entrez le nom de l'\303\251quipe", nullptr));
        labelAddTeamSpecialty->setText(QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251:", nullptr));
        comboAddTeamSpecialty->setItemText(0, QCoreApplication::translate("EquipeWidget", "S\303\251lectionner la sp\303\251cialit\303\251", nullptr));
        comboAddTeamSpecialty->setItemText(1, QCoreApplication::translate("EquipeWidget", "Maintenance", nullptr));
        comboAddTeamSpecialty->setItemText(2, QCoreApplication::translate("EquipeWidget", "Production", nullptr));
        comboAddTeamSpecialty->setItemText(3, QCoreApplication::translate("EquipeWidget", "Back-office", nullptr));
        comboAddTeamSpecialty->setItemText(4, QCoreApplication::translate("EquipeWidget", "M\303\251canique", nullptr));

        labelAddTeamMembers->setText(QCoreApplication::translate("EquipeWidget", "Nombre de membres:", nullptr));
        comboAddTeamMembers->setItemText(0, QCoreApplication::translate("EquipeWidget", "S\303\251lectionner le nombre", nullptr));
        comboAddTeamMembers->setItemText(1, QCoreApplication::translate("EquipeWidget", "1", nullptr));
        comboAddTeamMembers->setItemText(2, QCoreApplication::translate("EquipeWidget", "2", nullptr));
        comboAddTeamMembers->setItemText(3, QCoreApplication::translate("EquipeWidget", "3", nullptr));
        comboAddTeamMembers->setItemText(4, QCoreApplication::translate("EquipeWidget", "4", nullptr));
        comboAddTeamMembers->setItemText(5, QCoreApplication::translate("EquipeWidget", "5", nullptr));
        comboAddTeamMembers->setItemText(6, QCoreApplication::translate("EquipeWidget", "6", nullptr));
        comboAddTeamMembers->setItemText(7, QCoreApplication::translate("EquipeWidget", "7", nullptr));
        comboAddTeamMembers->setItemText(8, QCoreApplication::translate("EquipeWidget", "8", nullptr));
        comboAddTeamMembers->setItemText(9, QCoreApplication::translate("EquipeWidget", "9", nullptr));
        comboAddTeamMembers->setItemText(10, QCoreApplication::translate("EquipeWidget", "10", nullptr));

        label_add_etat->setText(QCoreApplication::translate("EquipeWidget", "\303\211tat:", nullptr));
        comboBox_add_etat->setItemText(0, QCoreApplication::translate("EquipeWidget", "S\303\251lectionner l'\303\251tat", nullptr));
        comboBox_add_etat->setItemText(1, QCoreApplication::translate("EquipeWidget", "active", nullptr));
        comboBox_add_etat->setItemText(2, QCoreApplication::translate("EquipeWidget", "inactive", nullptr));

        btnAddTeamSave->setText(QCoreApplication::translate("EquipeWidget", "Enregistrer", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "recherche des equipes par ID, NOM, sp\303\251cialit\303\251 ...", nullptr));
        comboBoxFilter->setItemText(0, QCoreApplication::translate("EquipeWidget", "ID", nullptr));
        comboBoxFilter->setItemText(1, QCoreApplication::translate("EquipeWidget", "Nom", nullptr));
        comboBoxFilter->setItemText(2, QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251", nullptr));
        comboBoxFilter->setItemText(3, QCoreApplication::translate("EquipeWidget", "Membres", nullptr));
        comboBoxFilter->setItemText(4, QCoreApplication::translate("EquipeWidget", "\303\211tat", nullptr));

        btnRechercher->setText(QCoreApplication::translate("EquipeWidget", "search", nullptr));
        labelSortTeams->setText(QCoreApplication::translate("EquipeWidget", "Tri des \303\251quipes", nullptr));
        btnTrier->setText(QCoreApplication::translate("EquipeWidget", "trier par", nullptr));
        comboSortField->setItemText(0, QCoreApplication::translate("EquipeWidget", "ID", nullptr));
        comboSortField->setItemText(1, QCoreApplication::translate("EquipeWidget", "Nom", nullptr));
        comboSortField->setItemText(2, QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251", nullptr));
        comboSortField->setItemText(3, QCoreApplication::translate("EquipeWidget", "Membres", nullptr));
        comboSortField->setItemText(4, QCoreApplication::translate("EquipeWidget", "\303\211tat", nullptr));
        comboSortField->setItemText(5, QCoreApplication::translate("EquipeWidget", "Rate", nullptr));

        checkSortAscending->setText(QCoreApplication::translate("EquipeWidget", "Croissant", nullptr));
        checkSortDescending->setText(QCoreApplication::translate("EquipeWidget", "D\303\251croissant", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EquipeWidget", "ID \303\211quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EquipeWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EquipeWidget", "Membres", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EquipeWidget", "Chef ", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("EquipeWidget", "\303\251tat d' \303\251quipe", nullptr));
        modifTitle->setText(QCoreApplication::translate("EquipeWidget", "Modifier une \303\211quipe", nullptr));
        label_mod_id->setText(QCoreApplication::translate("EquipeWidget", "ID:", nullptr));
        lineEdit_mod_id->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "Entrez l'ID de l'\303\251quipe \303\240 modifier", nullptr));
        labelUpdateTeamName->setText(QCoreApplication::translate("EquipeWidget", "Nom:", nullptr));
        inputUpdateTeamName->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "Entrez le nouveau nom", nullptr));
        labelUpdateTeamSpecialty->setText(QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251:", nullptr));
        comboUpdateTeamSpecialty->setItemText(0, QCoreApplication::translate("EquipeWidget", "S\303\251lectionner la sp\303\251cialit\303\251", nullptr));
        comboUpdateTeamSpecialty->setItemText(1, QCoreApplication::translate("EquipeWidget", "Maintenance", nullptr));
        comboUpdateTeamSpecialty->setItemText(2, QCoreApplication::translate("EquipeWidget", "Production", nullptr));
        comboUpdateTeamSpecialty->setItemText(3, QCoreApplication::translate("EquipeWidget", "Back-office", nullptr));
        comboUpdateTeamSpecialty->setItemText(4, QCoreApplication::translate("EquipeWidget", "M\303\251canique", nullptr));

        labelUpdateTeamMembers->setText(QCoreApplication::translate("EquipeWidget", "Nombre de membres:", nullptr));
        comboUpdateTeamMembers->setItemText(0, QCoreApplication::translate("EquipeWidget", "S\303\251lectionner le nombre", nullptr));
        comboUpdateTeamMembers->setItemText(1, QCoreApplication::translate("EquipeWidget", "1", nullptr));
        comboUpdateTeamMembers->setItemText(2, QCoreApplication::translate("EquipeWidget", "2", nullptr));
        comboUpdateTeamMembers->setItemText(3, QCoreApplication::translate("EquipeWidget", "3", nullptr));
        comboUpdateTeamMembers->setItemText(4, QCoreApplication::translate("EquipeWidget", "4", nullptr));
        comboUpdateTeamMembers->setItemText(5, QCoreApplication::translate("EquipeWidget", "5", nullptr));
        comboUpdateTeamMembers->setItemText(6, QCoreApplication::translate("EquipeWidget", "6", nullptr));
        comboUpdateTeamMembers->setItemText(7, QCoreApplication::translate("EquipeWidget", "7", nullptr));
        comboUpdateTeamMembers->setItemText(8, QCoreApplication::translate("EquipeWidget", "8", nullptr));
        comboUpdateTeamMembers->setItemText(9, QCoreApplication::translate("EquipeWidget", "9", nullptr));
        comboUpdateTeamMembers->setItemText(10, QCoreApplication::translate("EquipeWidget", "10", nullptr));

        label_etat->setText(QCoreApplication::translate("EquipeWidget", "\303\211tat:", nullptr));
        comboBox_mod_etat->setItemText(0, QCoreApplication::translate("EquipeWidget", "S\303\251lectionner l'\303\251tat", nullptr));
        comboBox_mod_etat->setItemText(1, QCoreApplication::translate("EquipeWidget", "active", nullptr));
        comboBox_mod_etat->setItemText(2, QCoreApplication::translate("EquipeWidget", "inactive", nullptr));

        btnUpdateTeam->setText(QCoreApplication::translate("EquipeWidget", "Modifier", nullptr));
        suppTitle->setText(QCoreApplication::translate("EquipeWidget", "Supprimer une \303\211quipe", nullptr));
        suppWarning->setText(QCoreApplication::translate("EquipeWidget", "Attention: Cette action est irr\303\251versible", nullptr));
        labelDeleteTeamId->setText(QCoreApplication::translate("EquipeWidget", "ID:", nullptr));
        inputDeleteTeamId->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "Saisissez l'ID de l'\303\251quipe \303\240 supprimer", nullptr));
        btnDeleteTeam->setText(QCoreApplication::translate("EquipeWidget", "Supprimer", nullptr));
        statTitle->setText(QCoreApplication::translate("EquipeWidget", "Statistiques des \303\251quipes", nullptr));
        pushButton_exportGlobalStatsPdf->setText(QCoreApplication::translate("EquipeWidget", "Exporter PDF global (Sections 1/3/4)", nullptr));
        pushButton_exportTeamDetailsPdf->setText(QCoreApplication::translate("EquipeWidget", "Exporter PDF \303\251quipe (Section 3)", nullptr));
        overallTeamsStatsGroup->setTitle(QCoreApplication::translate("EquipeWidget", "Statistiques globales des \303\251quipes", nullptr));
        label_totalTeams->setText(QCoreApplication::translate("EquipeWidget", "Total \303\251quipes: 0", nullptr));
        label_specialtyCount->setText(QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251s repr\303\251sent\303\251es: 0", nullptr));
        label_overallStatsHint->setText(QCoreApplication::translate("EquipeWidget", "R\303\251partition (%) des \303\251quipes par sp\303\251cialit\303\251.", nullptr));
        label_overallStatsHint->setStyleSheet(QCoreApplication::translate("EquipeWidget", "color: gray; font-style: italic;", nullptr));
        specialtyDetailsGroup->setTitle(QCoreApplication::translate("EquipeWidget", "D\303\251tails par sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = specialtyStatsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("EquipeWidget", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = specialtyStatsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("EquipeWidget", "Moyenne membres", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = specialtyStatsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("EquipeWidget", "Moyenne rate (/10)", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = specialtyStatsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("EquipeWidget", "\303\211quipes actives", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = specialtyStatsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("EquipeWidget", "Actives / total global", nullptr));
        specialtyDetailsHintLabel->setText(QCoreApplication::translate("EquipeWidget", "Statistiques globales calcul\303\251es par sp\303\251cialit\303\251.", nullptr));
        specialtyDetailsHintLabel->setStyleSheet(QCoreApplication::translate("EquipeWidget", "color: gray; font-style: italic;", nullptr));
        section1Group->setTitle(QCoreApplication::translate("EquipeWidget", "D\303\251tails de chaque \303\251quipe", nullptr));
        label_selectTeamDetails->setText(QCoreApplication::translate("EquipeWidget", "S\303\251lectionner \303\251quipe par ID:", nullptr));
        lineEdit_teamDetailsId->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "Entrez l'ID de l'\303\251quipe", nullptr));
        pushButton_validateTeamDetails->setText(QCoreApplication::translate("EquipeWidget", "Valider", nullptr));
        selectedTeamDetailsLabel->setText(QCoreApplication::translate("EquipeWidget", "\303\211quipe s\303\251lectionn\303\251e: Aucune", nullptr));
        selectedTeamDetailsLabel->setStyleSheet(QCoreApplication::translate("EquipeWidget", "font-weight: 600;", nullptr));
        label_completedTasks->setText(QCoreApplication::translate("EquipeWidget", "Nombre de t\303\242ches compl\303\251t\303\251es:", nullptr));
        completedTasksValueLabel->setText(QCoreApplication::translate("EquipeWidget", "0", nullptr));
        label_failedTasks->setText(QCoreApplication::translate("EquipeWidget", "Nombre de t\303\242ches \303\251chou\303\251es:", nullptr));
        failedTasksValueLabel->setText(QCoreApplication::translate("EquipeWidget", "0", nullptr));
        label_teamRate->setText(QCoreApplication::translate("EquipeWidget", "Rate sur 10:", nullptr));
        teamRateValueLabel->setText(QCoreApplication::translate("EquipeWidget", "0.00", nullptr));
        teamFeedbackLabel->setText(QCoreApplication::translate("EquipeWidget", "Feedback: -", nullptr));
        section2Group->setTitle(QCoreApplication::translate("EquipeWidget", "Top performers", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = performanceRankingTable->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("EquipeWidget", "Cat\303\251gorie", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = performanceRankingTable->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("EquipeWidget", "ID \303\251quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = performanceRankingTable->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("EquipeWidget", "\303\211quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = performanceRankingTable->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("EquipeWidget", "Rate /10", nullptr));
        suggestionQuestionsGroup->setTitle(QCoreApplication::translate("EquipeWidget", "Questions de suggestion", nullptr));
        labelSuggestionSpecialty->setText(QCoreApplication::translate("EquipeWidget", "sp\303\251cialit\303\251:", nullptr));
        comboSuggestionSpecialty->setItemText(0, QCoreApplication::translate("EquipeWidget", "selectionner la specialit\303\251 demand\303\251", nullptr));
        comboSuggestionSpecialty->setItemText(1, QCoreApplication::translate("EquipeWidget", "maintenace", nullptr));
        comboSuggestionSpecialty->setItemText(2, QCoreApplication::translate("EquipeWidget", "production", nullptr));
        comboSuggestionSpecialty->setItemText(3, QCoreApplication::translate("EquipeWidget", "backoffice", nullptr));
        comboSuggestionSpecialty->setItemText(4, QCoreApplication::translate("EquipeWidget", "m\303\251canique", nullptr));
        comboSuggestionSpecialty->setItemText(5, QString());

        labelSuggestionMinMembers->setText(QCoreApplication::translate("EquipeWidget", "nombre minimum des individu de l'\303\251quipe :", nullptr));
        inputSuggestionMinMembers->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "Entrer le nombre ici", nullptr));
        labelSuggestionCase->setText(QCoreApplication::translate("EquipeWidget", "cas:", nullptr));
        checkSuggestionUrgent->setText(QCoreApplication::translate("EquipeWidget", "urgent", nullptr));
        checkSuggestionNormalState->setText(QCoreApplication::translate("EquipeWidget", "\303\251tat normal", nullptr));
        labelSuggestionDifficulty->setText(QCoreApplication::translate("EquipeWidget", "difficult\303\251 du cas :", nullptr));
        comboSuggestionDifficulty->setItemText(0, QCoreApplication::translate("EquipeWidget", "selectionner la difficult\303\251 ici ", nullptr));
        comboSuggestionDifficulty->setItemText(1, QCoreApplication::translate("EquipeWidget", "facile", nullptr));
        comboSuggestionDifficulty->setItemText(2, QCoreApplication::translate("EquipeWidget", "Normal", nullptr));
        comboSuggestionDifficulty->setItemText(3, QCoreApplication::translate("EquipeWidget", "Difficile", nullptr));

        checkSuggestionRequiresAvailability->setText(QCoreApplication::translate("EquipeWidget", "n\303\251cessite la diponibilit\303\251", nullptr));
        btnRunSuggestionSearch->setText(QCoreApplication::translate("EquipeWidget", "RECHERCHER", nullptr));
        suggestionResultsGroup->setTitle(QCoreApplication::translate("EquipeWidget", "R\303\251sultat", nullptr));
        labelSuggestionBestRecommendations->setText(QCoreApplication::translate("EquipeWidget", "Meilleures Recommandations", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = suggestionResultsTable->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("EquipeWidget", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = suggestionResultsTable->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("EquipeWidget", "Classe", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = suggestionResultsTable->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("EquipeWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = suggestionResultsTable->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("EquipeWidget", "\303\211quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = suggestionResultsTable->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("EquipeWidget", "Score /10", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = suggestionResultsTable->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("EquipeWidget", "Rate", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = suggestionResultsTable->horizontalHeaderItem(6);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("EquipeWidget", "Disponibilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = suggestionResultsTable->horizontalHeaderItem(7);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("EquipeWidget", "Fiabilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = suggestionResultsTable->horizontalHeaderItem(8);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("EquipeWidget", "Charge", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = suggestionResultsTable->horizontalHeaderItem(9);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("EquipeWidget", "Raisons", nullptr));
        label_teamSelection->setText(QCoreApplication::translate("EquipeWidget", "Choisir une \303\251quipe pour consulter / planifier:", nullptr));
        label_teamSelection->setStyleSheet(QCoreApplication::translate("EquipeWidget", "font-weight: bold;", nullptr));
        lineEdit_teamId->setPlaceholderText(QCoreApplication::translate("EquipeWidget", "entrer ici l ID du l \303\251quipe", nullptr));
        pushButton_validateTeam->setText(QCoreApplication::translate("EquipeWidget", "entrer", nullptr));
        label_teamStatus->setText(QString());
        label_teamStatus->setStyleSheet(QCoreApplication::translate("EquipeWidget", "color: gray; font-style: italic;", nullptr));
        taskLabel->setText(QCoreApplication::translate("EquipeWidget", "Liste des T\303\242ches", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = planningTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("EquipeWidget", "T\303\242che", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = planningTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("EquipeWidget", "Assign\303\251e \303\240", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = planningTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("EquipeWidget", "D\303\251but", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = planningTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("EquipeWidget", "Deadline", nullptr));
        pushButton_addTask->setText(QCoreApplication::translate("EquipeWidget", "Ajouter une tache", nullptr));
        pushButton_deleteTask->setText(QCoreApplication::translate("EquipeWidget", "Supprimer tache", nullptr));
        taskInstructionLabel->setText(QCoreApplication::translate("EquipeWidget", "<html><head/><body><p><span style=\" font-size:11px; color:#808080; font-style:italic;\">\342\200\242 Utilisez le bouton \"Ajouter une t\303\242che\" pour ajouter une nouvelle t\303\242che pour une \303\251quipe sp\303\251cifique s\303\251lectionn\303\251e par ID</span></p><p><span style=\" font-size:11px; color:#808080; font-style:italic;\">\342\200\242 Maximum 3 t\303\242ches en cours par \303\251quipe</span></p><p><span style=\" font-size:11px; color:#808080; font-style:italic;\">\342\200\242 Cochez la case devant la t\303\242che pour marquer celle-ci comme compl\303\250te</span></p><p><span style=\" font-size:11px; color:#808080; font-style:italic;\">\342\200\242 S\303\251lectionnez une ligne puis cliquez sur \"Supprimer t\303\242che\" (ne compte ni comme succ\303\250s ni comme \303\251chec)</span></p></body></html>", nullptr));
        calendarInstructionLabel->setText(QCoreApplication::translate("EquipeWidget", "S\303\251lectionnez un jour dans le calendrier pour consulter la liste des t\303\242ches en cours pour le jour choisi.", nullptr));
        calendarInstructionLabel->setStyleSheet(QCoreApplication::translate("EquipeWidget", "color: gray; font-size: 11px; font-style: italic;", nullptr));
        (void)EquipeWidget;
    } // retranslateUi

};

namespace Ui {
    class EquipeWidget: public Ui_EquipeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EQUIPE_WIDGET_H
