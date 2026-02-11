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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QAction *actionEnvoyerEmail;
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
    QVBoxLayout *orderLayout;
    QToolBar *toolBar;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *leftLayout;
    QGroupBox *groupBoxSearch;
    QVBoxLayout *vboxLayout4;
    QHBoxLayout *hboxLayout;
    QLabel *labelSearch;
    QLineEdit *lineEditSearch;
    QHBoxLayout *hboxLayout1;
    QLabel *labelFournisseur;
    QComboBox *comboFournisseur;
    QHBoxLayout *hboxLayout2;
    QLabel *labelStatus;
    QComboBox *comboStatus;
    QHBoxLayout *hboxLayout3;
    QLabel *labelDateFrom;
    QDateEdit *dateFrom;
    QHBoxLayout *hboxLayout4;
    QLabel *labelDateTo;
    QDateEdit *dateTo;
    QTableWidget *tableCommandes;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayoutStats;
    QLabel *labelStatTotal;
    QLabel *statTotal;
    QLabel *labelStatEnCours;
    QLabel *statEnCours;
    QLabel *labelStatValidee;
    QLabel *statValidee;
    QLabel *labelStatPrete;
    QLabel *statPrete;
    QLabel *labelStatAnnulee;
    QLabel *statAnnulee;
    QGroupBox *groupBoxStatsByType;
    QVBoxLayout *vboxLayout5;
    QTextEdit *statsTypes;
    QGroupBox *groupBoxStatsDepenses;
    QVBoxLayout *vboxLayout6;
    QTextEdit *statsDepenses;
    QGroupBox *groupBoxCalendrier;
    QVBoxLayout *vboxLayout7;
    QCalendarWidget *calendarCommandes;
    QSpacerItem *verticalSpacer;
    QWidget *rightPanel;
    QVBoxLayout *vboxLayout8;
    QGroupBox *groupBoxActions;
    QVBoxLayout *vboxLayout9;
    QPushButton *btnNewCommande;
    QPushButton *btnEditCommande;
    QPushButton *btnDeleteCommande;
    QPushButton *btnEnvoyerEmail;
    QGroupBox *groupBoxQuickInfo;
    QVBoxLayout *vboxLayout10;
    QLabel *labelEtat;
    QLabel *quickEtat;
    QLabel *labelFournisseur1;
    QLabel *quickFournisseur;
    QLabel *labelDateArrivee;
    QLabel *quickDateArrivee;
    QLabel *labelDateSortie;
    QLabel *quickDateSortie;
    QLabel *labelMontant;
    QLabel *quickMontant;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageMachine;
    QVBoxLayout *machineLayout;
    QLabel *labelPageMachine;
    QPushButton *btnCommandeFromProduit;
    QSpacerItem *verticalSpacerMachine;
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
        actionEnvoyerEmail = new QAction(MainWindow);
        actionEnvoyerEmail->setObjectName("actionEnvoyerEmail");
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
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":gestion_de_commande/assets/oil_press.png")));
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
        orderLayout = new QVBoxLayout(pageOrder);
        orderLayout->setObjectName("orderLayout");
        toolBar = new QToolBar(pageOrder);
        toolBar->setObjectName("toolBar");
        toolBar->setIconSize(QSize(24, 24));

        orderLayout->addWidget(toolBar);

        splitter = new QSplitter(pageOrder);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Orientation::Horizontal);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName("leftPanel");
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(0, 0, 0, 0);
        groupBoxSearch = new QGroupBox(leftPanel);
        groupBoxSearch->setObjectName("groupBoxSearch");
        vboxLayout4 = new QVBoxLayout(groupBoxSearch);
        vboxLayout4->setObjectName("vboxLayout4");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        labelSearch = new QLabel(groupBoxSearch);
        labelSearch->setObjectName("labelSearch");

        hboxLayout->addWidget(labelSearch);

        lineEditSearch = new QLineEdit(groupBoxSearch);
        lineEditSearch->setObjectName("lineEditSearch");

        hboxLayout->addWidget(lineEditSearch);


        vboxLayout4->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        labelFournisseur = new QLabel(groupBoxSearch);
        labelFournisseur->setObjectName("labelFournisseur");

        hboxLayout1->addWidget(labelFournisseur);

        comboFournisseur = new QComboBox(groupBoxSearch);
        comboFournisseur->addItem(QString());
        comboFournisseur->addItem(QString());
        comboFournisseur->addItem(QString());
        comboFournisseur->addItem(QString());
        comboFournisseur->addItem(QString());
        comboFournisseur->addItem(QString());
        comboFournisseur->setObjectName("comboFournisseur");

        hboxLayout1->addWidget(comboFournisseur);


        vboxLayout4->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        labelStatus = new QLabel(groupBoxSearch);
        labelStatus->setObjectName("labelStatus");

        hboxLayout2->addWidget(labelStatus);

        comboStatus = new QComboBox(groupBoxSearch);
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->addItem(QString());
        comboStatus->setObjectName("comboStatus");

        hboxLayout2->addWidget(comboStatus);


        vboxLayout4->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName("hboxLayout3");
        labelDateFrom = new QLabel(groupBoxSearch);
        labelDateFrom->setObjectName("labelDateFrom");

        hboxLayout3->addWidget(labelDateFrom);

        dateFrom = new QDateEdit(groupBoxSearch);
        dateFrom->setObjectName("dateFrom");
        dateFrom->setCalendarPopup(true);

        hboxLayout3->addWidget(dateFrom);


        vboxLayout4->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName("hboxLayout4");
        labelDateTo = new QLabel(groupBoxSearch);
        labelDateTo->setObjectName("labelDateTo");

        hboxLayout4->addWidget(labelDateTo);

        dateTo = new QDateEdit(groupBoxSearch);
        dateTo->setObjectName("dateTo");
        dateTo->setCalendarPopup(true);

        hboxLayout4->addWidget(dateTo);


        vboxLayout4->addLayout(hboxLayout4);


        leftLayout->addWidget(groupBoxSearch);

        tableCommandes = new QTableWidget(leftPanel);
        if (tableCommandes->columnCount() < 7)
            tableCommandes->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableCommandes->setObjectName("tableCommandes");
        tableCommandes->setAlternatingRowColors(true);
        tableCommandes->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableCommandes->setShowGrid(true);
        tableCommandes->horizontalHeader()->setStretchLastSection(true);

        leftLayout->addWidget(tableCommandes);

        groupBoxStats = new QGroupBox(leftPanel);
        groupBoxStats->setObjectName("groupBoxStats");
        gridLayoutStats = new QGridLayout(groupBoxStats);
        gridLayoutStats->setObjectName("gridLayoutStats");
        labelStatTotal = new QLabel(groupBoxStats);
        labelStatTotal->setObjectName("labelStatTotal");

        gridLayoutStats->addWidget(labelStatTotal, 0, 0, 1, 1);

        statTotal = new QLabel(groupBoxStats);
        statTotal->setObjectName("statTotal");

        gridLayoutStats->addWidget(statTotal, 0, 1, 1, 1);

        labelStatEnCours = new QLabel(groupBoxStats);
        labelStatEnCours->setObjectName("labelStatEnCours");

        gridLayoutStats->addWidget(labelStatEnCours, 0, 2, 1, 1);

        statEnCours = new QLabel(groupBoxStats);
        statEnCours->setObjectName("statEnCours");

        gridLayoutStats->addWidget(statEnCours, 0, 3, 1, 1);

        labelStatValidee = new QLabel(groupBoxStats);
        labelStatValidee->setObjectName("labelStatValidee");

        gridLayoutStats->addWidget(labelStatValidee, 1, 0, 1, 1);

        statValidee = new QLabel(groupBoxStats);
        statValidee->setObjectName("statValidee");

        gridLayoutStats->addWidget(statValidee, 1, 1, 1, 1);

        labelStatPrete = new QLabel(groupBoxStats);
        labelStatPrete->setObjectName("labelStatPrete");

        gridLayoutStats->addWidget(labelStatPrete, 1, 2, 1, 1);

        statPrete = new QLabel(groupBoxStats);
        statPrete->setObjectName("statPrete");

        gridLayoutStats->addWidget(statPrete, 1, 3, 1, 1);

        labelStatAnnulee = new QLabel(groupBoxStats);
        labelStatAnnulee->setObjectName("labelStatAnnulee");

        gridLayoutStats->addWidget(labelStatAnnulee, 2, 0, 1, 1);

        statAnnulee = new QLabel(groupBoxStats);
        statAnnulee->setObjectName("statAnnulee");

        gridLayoutStats->addWidget(statAnnulee, 2, 1, 1, 1);


        leftLayout->addWidget(groupBoxStats);

        groupBoxStatsByType = new QGroupBox(leftPanel);
        groupBoxStatsByType->setObjectName("groupBoxStatsByType");
        vboxLayout5 = new QVBoxLayout(groupBoxStatsByType);
        vboxLayout5->setObjectName("vboxLayout5");
        statsTypes = new QTextEdit(groupBoxStatsByType);
        statsTypes->setObjectName("statsTypes");
        statsTypes->setReadOnly(true);

        vboxLayout5->addWidget(statsTypes);


        leftLayout->addWidget(groupBoxStatsByType);

        groupBoxStatsDepenses = new QGroupBox(leftPanel);
        groupBoxStatsDepenses->setObjectName("groupBoxStatsDepenses");
        vboxLayout6 = new QVBoxLayout(groupBoxStatsDepenses);
        vboxLayout6->setObjectName("vboxLayout6");
        statsDepenses = new QTextEdit(groupBoxStatsDepenses);
        statsDepenses->setObjectName("statsDepenses");
        statsDepenses->setReadOnly(true);

        vboxLayout6->addWidget(statsDepenses);


        leftLayout->addWidget(groupBoxStatsDepenses);

        groupBoxCalendrier = new QGroupBox(leftPanel);
        groupBoxCalendrier->setObjectName("groupBoxCalendrier");
        vboxLayout7 = new QVBoxLayout(groupBoxCalendrier);
        vboxLayout7->setObjectName("vboxLayout7");
        calendarCommandes = new QCalendarWidget(groupBoxCalendrier);
        calendarCommandes->setObjectName("calendarCommandes");

        vboxLayout7->addWidget(calendarCommandes);


        leftLayout->addWidget(groupBoxCalendrier);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftLayout->addItem(verticalSpacer);

        splitter->addWidget(leftPanel);
        rightPanel = new QWidget(splitter);
        rightPanel->setObjectName("rightPanel");
        vboxLayout8 = new QVBoxLayout(rightPanel);
        vboxLayout8->setObjectName("vboxLayout8");
        vboxLayout8->setContentsMargins(0, 0, 0, 0);
        groupBoxActions = new QGroupBox(rightPanel);
        groupBoxActions->setObjectName("groupBoxActions");
        vboxLayout9 = new QVBoxLayout(groupBoxActions);
        vboxLayout9->setObjectName("vboxLayout9");
        btnNewCommande = new QPushButton(groupBoxActions);
        btnNewCommande->setObjectName("btnNewCommande");

        vboxLayout9->addWidget(btnNewCommande);

        btnEditCommande = new QPushButton(groupBoxActions);
        btnEditCommande->setObjectName("btnEditCommande");

        vboxLayout9->addWidget(btnEditCommande);

        btnDeleteCommande = new QPushButton(groupBoxActions);
        btnDeleteCommande->setObjectName("btnDeleteCommande");

        vboxLayout9->addWidget(btnDeleteCommande);

        btnEnvoyerEmail = new QPushButton(groupBoxActions);
        btnEnvoyerEmail->setObjectName("btnEnvoyerEmail");

        vboxLayout9->addWidget(btnEnvoyerEmail);


        vboxLayout8->addWidget(groupBoxActions);

        groupBoxQuickInfo = new QGroupBox(rightPanel);
        groupBoxQuickInfo->setObjectName("groupBoxQuickInfo");
        vboxLayout10 = new QVBoxLayout(groupBoxQuickInfo);
        vboxLayout10->setObjectName("vboxLayout10");
        labelEtat = new QLabel(groupBoxQuickInfo);
        labelEtat->setObjectName("labelEtat");

        vboxLayout10->addWidget(labelEtat);

        quickEtat = new QLabel(groupBoxQuickInfo);
        quickEtat->setObjectName("quickEtat");

        vboxLayout10->addWidget(quickEtat);

        labelFournisseur1 = new QLabel(groupBoxQuickInfo);
        labelFournisseur1->setObjectName("labelFournisseur1");

        vboxLayout10->addWidget(labelFournisseur1);

        quickFournisseur = new QLabel(groupBoxQuickInfo);
        quickFournisseur->setObjectName("quickFournisseur");

        vboxLayout10->addWidget(quickFournisseur);

        labelDateArrivee = new QLabel(groupBoxQuickInfo);
        labelDateArrivee->setObjectName("labelDateArrivee");

        vboxLayout10->addWidget(labelDateArrivee);

        quickDateArrivee = new QLabel(groupBoxQuickInfo);
        quickDateArrivee->setObjectName("quickDateArrivee");

        vboxLayout10->addWidget(quickDateArrivee);

        labelDateSortie = new QLabel(groupBoxQuickInfo);
        labelDateSortie->setObjectName("labelDateSortie");

        vboxLayout10->addWidget(labelDateSortie);

        quickDateSortie = new QLabel(groupBoxQuickInfo);
        quickDateSortie->setObjectName("quickDateSortie");

        vboxLayout10->addWidget(quickDateSortie);

        labelMontant = new QLabel(groupBoxQuickInfo);
        labelMontant->setObjectName("labelMontant");

        vboxLayout10->addWidget(labelMontant);

        quickMontant = new QLabel(groupBoxQuickInfo);
        quickMontant->setObjectName("quickMontant");

        vboxLayout10->addWidget(quickMontant);


        vboxLayout8->addWidget(groupBoxQuickInfo);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout8->addItem(verticalSpacer_2);

        splitter->addWidget(rightPanel);

        orderLayout->addWidget(splitter);

        stackedPages->addWidget(pageOrder);
        pageMachine = new QWidget();
        pageMachine->setObjectName("pageMachine");
        machineLayout = new QVBoxLayout(pageMachine);
        machineLayout->setObjectName("machineLayout");
        labelPageMachine = new QLabel(pageMachine);
        labelPageMachine->setObjectName("labelPageMachine");
        labelPageMachine->setAlignment(Qt::AlignCenter);

        machineLayout->addWidget(labelPageMachine);

        btnCommandeFromProduit = new QPushButton(pageMachine);
        btnCommandeFromProduit->setObjectName("btnCommandeFromProduit");

        machineLayout->addWidget(btnCommandeFromProduit);

        verticalSpacerMachine = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        machineLayout->addItem(verticalSpacerMachine);

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
        toolBar->addAction(actionEnvoyerEmail);
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Commandes", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "&Nouvelle Commande", nullptr));
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
        actionEnvoyerEmail->setText(QCoreApplication::translate("MainWindow", "&Envoyer Email", nullptr));
#if QT_CONFIG(shortcut)
        actionEnvoyerEmail->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+M", nullptr));
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
        btnClient->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        btnLaboratory->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnLaboratory->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        btnOrder->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnOrder->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #BDD2B6; color: #798777; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #A2B29F; }", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        btnMachine->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A2B29F; color: #F8EDE3; border: none; padding: 15px; font-weight: bold; text-align: left; }\n"
"QPushButton:hover { background-color: #BDD2B6; }", nullptr));
        labelPageEmployee->setText(QCoreApplication::translate("MainWindow", "Page Employ\303\251", nullptr));
        labelPageTeam->setText(QCoreApplication::translate("MainWindow", "Page \303\211quipe", nullptr));
        labelPageClient->setText(QCoreApplication::translate("MainWindow", "Page Client", nullptr));
        labelPageLaboratory->setText(QCoreApplication::translate("MainWindow", "Page Laboratoire", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "Recherche et Filtres", nullptr));
        labelSearch->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID, libell\303\251, fournisseur\342\200\246", nullptr));
        labelFournisseur->setText(QCoreApplication::translate("MainWindow", "Fournisseur :", nullptr));
        comboFournisseur->setItemText(0, QCoreApplication::translate("MainWindow", "Toutes", nullptr));
        comboFournisseur->setItemText(1, QCoreApplication::translate("MainWindow", "Fournisseur A", nullptr));
        comboFournisseur->setItemText(2, QCoreApplication::translate("MainWindow", "Fournisseur B", nullptr));
        comboFournisseur->setItemText(3, QCoreApplication::translate("MainWindow", "Fournisseur C", nullptr));
        comboFournisseur->setItemText(4, QCoreApplication::translate("MainWindow", "Fournisseur D", nullptr));
        comboFournisseur->setItemText(5, QCoreApplication::translate("MainWindow", "Autres", nullptr));

        labelStatus->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        comboStatus->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        comboStatus->setItemText(1, QCoreApplication::translate("MainWindow", "En cours", nullptr));
        comboStatus->setItemText(2, QCoreApplication::translate("MainWindow", "Valid\303\251e", nullptr));
        comboStatus->setItemText(3, QCoreApplication::translate("MainWindow", "Pr\303\252te", nullptr));
        comboStatus->setItemText(4, QCoreApplication::translate("MainWindow", "Annul\303\251e", nullptr));

        labelDateFrom->setText(QCoreApplication::translate("MainWindow", "Date depuis :", nullptr));
        labelDateTo->setText(QCoreApplication::translate("MainWindow", "Jusqu'\303\240 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableCommandes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableCommandes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Libell\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableCommandes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableCommandes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableCommandes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Date Arriv\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableCommandes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Date Sortie", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableCommandes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Montant Total", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        labelStatTotal->setText(QCoreApplication::translate("MainWindow", "Total Commandes :", nullptr));
        statTotal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatEnCours->setText(QCoreApplication::translate("MainWindow", "En cours :", nullptr));
        statEnCours->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatValidee->setText(QCoreApplication::translate("MainWindow", "Valid\303\251es :", nullptr));
        statValidee->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatPrete->setText(QCoreApplication::translate("MainWindow", "Pr\303\252tes :", nullptr));
        statPrete->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        labelStatAnnulee->setText(QCoreApplication::translate("MainWindow", "Annul\303\251es :", nullptr));
        statAnnulee->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBoxStatsByType->setTitle(QCoreApplication::translate("MainWindow", "Produits par Type/Stock", nullptr));
        groupBoxStatsDepenses->setTitle(QCoreApplication::translate("MainWindow", "D\303\251penses par Mois / Ruptures", nullptr));
        groupBoxCalendrier->setTitle(QCoreApplication::translate("MainWindow", "Calendrier des Commandes", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "Actions Rapides", nullptr));
        btnNewCommande->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Cr\303\251er", nullptr));
        btnEditCommande->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnDeleteCommande->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Annuler / Supprimer", nullptr));
        btnEnvoyerEmail->setText(QCoreApplication::translate("MainWindow", "\360\237\223\247 Envoyer Email", nullptr));
        groupBoxQuickInfo->setTitle(QCoreApplication::translate("MainWindow", "Infos Rapides", nullptr));
        labelEtat->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        quickEtat->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelFournisseur1->setText(QCoreApplication::translate("MainWindow", "Fournisseur :", nullptr));
        quickFournisseur->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelDateArrivee->setText(QCoreApplication::translate("MainWindow", "Date Arriv\303\251e :", nullptr));
        quickDateArrivee->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelDateSortie->setText(QCoreApplication::translate("MainWindow", "Date Sortie :", nullptr));
        quickDateSortie->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelMontant->setText(QCoreApplication::translate("MainWindow", "Montant Total :", nullptr));
        quickMontant->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        labelPageMachine->setText(QCoreApplication::translate("MainWindow", "Page Machine (Produit)", nullptr));
        btnCommandeFromProduit->setText(QCoreApplication::translate("MainWindow", "Commande", nullptr));
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
