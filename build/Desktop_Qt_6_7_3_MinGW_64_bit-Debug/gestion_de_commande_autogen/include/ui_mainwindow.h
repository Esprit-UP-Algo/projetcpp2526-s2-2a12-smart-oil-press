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
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *navFrame;
    QVBoxLayout *navLayout;
    QLabel *logoLabel;
    QPushButton *btnCommande;
    QPushButton *btnEquipe;
    QPushButton *btnClient;
    QPushButton *btnLaboratoire;
    QPushButton *btnFournisseur;
    QPushButton *btnMachine;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedMain;
    QWidget *pageAccueil;
    QVBoxLayout *verticalLayout_2;
    QLabel *welcomeLabel;
    QWidget *pageCommandes;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tabAjouter;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_id;
    QLabel *label_3;
    QLineEdit *lineEdit_libelle;
    QLabel *label_4;
    QComboBox *combo_fournisseur;
    QLabel *label_5;
    QDateEdit *dateEdit_arrivage;
    QLabel *label_6;
    QDateEdit *dateEdit_sortie;
    QLabel *label_7;
    QComboBox *combo_etat;
    QLabel *label_8;
    QSpinBox *spinBox_quantite;
    QLabel *label_9;
    QDoubleSpinBox *doubleSpinBox_montant;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnAjouter;
    QWidget *tabListe;
    QHBoxLayout *horizontalLayout_3;
    QFrame *sidebarListe;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_recherche;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_10;
    QLineEdit *search_id;
    QLabel *label_11;
    QLineEdit *search_fournisseur;
    QLabel *label_12;
    QComboBox *search_etat;
    QLabel *label_13;
    QDateEdit *search_date_debut;
    QLabel *label_14;
    QDateEdit *search_date_fin;
    QGroupBox *groupBox_tri;
    QVBoxLayout *verticalLayout_6;
    QRadioButton *radioButton_dateArrivage;
    QRadioButton *radioButton_montant;
    QRadioButton *radioButton_quantite;
    QRadioButton *radioButton_dateSortie;
    QGroupBox *groupBox_ordre;
    QVBoxLayout *verticalLayout_7;
    QRadioButton *radioButton_croissant;
    QRadioButton *radioButton_decroissant;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableWidget_commandes;
    QWidget *tabSupprimer;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout;
    QLabel *label_15;
    QLineEdit *lineEdit_id_supprimer;
    QPushButton *btnSupprimer;
    QSpacerItem *verticalSpacer_3;
    QWidget *tabModifier;
    QVBoxLayout *verticalLayout_9;
    QFormLayout *formLayout_2;
    QLabel *label_16;
    QLineEdit *lineEdit_id_modifier;
    QPushButton *btnCharger;
    QGroupBox *groupBox_modifier;
    QGridLayout *gridLayout_2;
    QLabel *label_17;
    QLineEdit *lineEdit_libelle_mod;
    QLabel *label_18;
    QComboBox *combo_fournisseur_mod;
    QLabel *label_19;
    QDateEdit *dateEdit_arrivage_mod;
    QLabel *label_20;
    QDateEdit *dateEdit_sortie_mod;
    QLabel *label_21;
    QComboBox *combo_etat_mod;
    QLabel *label_22;
    QSpinBox *spinBox_quantite_mod;
    QLabel *label_23;
    QDoubleSpinBox *doubleSpinBox_montant_mod;
    QPushButton *btnModifier;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_depenses;
    QVBoxLayout *verticalLayout_11;
    QTableWidget *tableWidget_depenses;
    QGroupBox *groupBox_top;
    QVBoxLayout *verticalLayout_12;
    QTableWidget *tableWidget_top;
    QWidget *tabCalendrier;
    QVBoxLayout *verticalLayout_13;
    QCalendarWidget *calendarWidget;
    QGroupBox *groupBox_commandes_jour;
    QVBoxLayout *verticalLayout_14;
    QListWidget *listWidget_commandes;
    QWidget *tabExport;
    QVBoxLayout *verticalLayout_15;
    QPushButton *btnExportListe;
    QPushButton *btnExportRapport;
    QPushButton *btnExportFiche;
    QFormLayout *formLayout_3;
    QLabel *label_24;
    QLineEdit *lineEdit_id_export;
    QGroupBox *groupBox_email;
    QFormLayout *formLayout_4;
    QLabel *label_25;
    QLineEdit *lineEdit_email_client;
    QLabel *label_26;
    QLineEdit *lineEdit_id_email;
    QPushButton *btnEnvoyerEmail;
    QTextEdit *textEdit_messages;
    QSpacerItem *verticalSpacer_4;
    QWidget *pageEquipe;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_equipe;
    QWidget *pageClient;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_client;
    QWidget *pageLaboratoire;
    QVBoxLayout *verticalLayout_18;
    QLabel *label_labo;
    QWidget *pageFournisseur;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_fournisseur;
    QWidget *pageMachine;
    QVBoxLayout *verticalLayout_20;
    QLabel *label_machine;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        navFrame = new QFrame(centralwidget);
        navFrame->setObjectName("navFrame");
        navFrame->setMinimumWidth(200);
        navFrame->setMaximumWidth(250);
        navLayout = new QVBoxLayout(navFrame);
        navLayout->setObjectName("navLayout");
        logoLabel = new QLabel(navFrame);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignCenter);

        navLayout->addWidget(logoLabel);

        btnCommande = new QPushButton(navFrame);
        btnCommande->setObjectName("btnCommande");

        navLayout->addWidget(btnCommande);

        btnEquipe = new QPushButton(navFrame);
        btnEquipe->setObjectName("btnEquipe");

        navLayout->addWidget(btnEquipe);

        btnClient = new QPushButton(navFrame);
        btnClient->setObjectName("btnClient");

        navLayout->addWidget(btnClient);

        btnLaboratoire = new QPushButton(navFrame);
        btnLaboratoire->setObjectName("btnLaboratoire");

        navLayout->addWidget(btnLaboratoire);

        btnFournisseur = new QPushButton(navFrame);
        btnFournisseur->setObjectName("btnFournisseur");

        navLayout->addWidget(btnFournisseur);

        btnMachine = new QPushButton(navFrame);
        btnMachine->setObjectName("btnMachine");

        navLayout->addWidget(btnMachine);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        navLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(navFrame);

        stackedMain = new QStackedWidget(centralwidget);
        stackedMain->setObjectName("stackedMain");
        pageAccueil = new QWidget();
        pageAccueil->setObjectName("pageAccueil");
        verticalLayout_2 = new QVBoxLayout(pageAccueil);
        verticalLayout_2->setObjectName("verticalLayout_2");
        welcomeLabel = new QLabel(pageAccueil);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(welcomeLabel);

        stackedMain->addWidget(pageAccueil);
        pageCommandes = new QWidget();
        pageCommandes->setObjectName("pageCommandes");
        verticalLayout = new QVBoxLayout(pageCommandes);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(pageCommandes);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(pageCommandes);
        tabWidget->setObjectName("tabWidget");
        tabAjouter = new QWidget();
        tabAjouter->setObjectName("tabAjouter");
        verticalLayout_3 = new QVBoxLayout(tabAjouter);
        verticalLayout_3->setObjectName("verticalLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        label_2 = new QLabel(tabAjouter);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_id = new QLineEdit(tabAjouter);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setReadOnly(true);

        gridLayout->addWidget(lineEdit_id, 0, 1, 1, 1);

        label_3 = new QLabel(tabAjouter);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_libelle = new QLineEdit(tabAjouter);
        lineEdit_libelle->setObjectName("lineEdit_libelle");

        gridLayout->addWidget(lineEdit_libelle, 1, 1, 1, 1);

        label_4 = new QLabel(tabAjouter);
        label_4->setObjectName("label_4");

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        combo_fournisseur = new QComboBox(tabAjouter);
        combo_fournisseur->addItem(QString());
        combo_fournisseur->addItem(QString());
        combo_fournisseur->addItem(QString());
        combo_fournisseur->setObjectName("combo_fournisseur");

        gridLayout->addWidget(combo_fournisseur, 2, 1, 1, 1);

        label_5 = new QLabel(tabAjouter);
        label_5->setObjectName("label_5");

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        dateEdit_arrivage = new QDateEdit(tabAjouter);
        dateEdit_arrivage->setObjectName("dateEdit_arrivage");
        dateEdit_arrivage->setCalendarPopup(true);
        dateEdit_arrivage->setDate(QDate(2026, 2, 16));

        gridLayout->addWidget(dateEdit_arrivage, 3, 1, 1, 1);

        label_6 = new QLabel(tabAjouter);
        label_6->setObjectName("label_6");

        gridLayout->addWidget(label_6, 4, 0, 1, 1);

        dateEdit_sortie = new QDateEdit(tabAjouter);
        dateEdit_sortie->setObjectName("dateEdit_sortie");
        dateEdit_sortie->setCalendarPopup(true);
        dateEdit_sortie->setDate(QDate(2026, 3, 16));

        gridLayout->addWidget(dateEdit_sortie, 4, 1, 1, 1);

        label_7 = new QLabel(tabAjouter);
        label_7->setObjectName("label_7");

        gridLayout->addWidget(label_7, 5, 0, 1, 1);

        combo_etat = new QComboBox(tabAjouter);
        combo_etat->addItem(QString());
        combo_etat->addItem(QString());
        combo_etat->addItem(QString());
        combo_etat->addItem(QString());
        combo_etat->setObjectName("combo_etat");

        gridLayout->addWidget(combo_etat, 5, 1, 1, 1);

        label_8 = new QLabel(tabAjouter);
        label_8->setObjectName("label_8");

        gridLayout->addWidget(label_8, 6, 0, 1, 1);

        spinBox_quantite = new QSpinBox(tabAjouter);
        spinBox_quantite->setObjectName("spinBox_quantite");
        spinBox_quantite->setMinimum(1);
        spinBox_quantite->setMaximum(10000);

        gridLayout->addWidget(spinBox_quantite, 6, 1, 1, 1);

        label_9 = new QLabel(tabAjouter);
        label_9->setObjectName("label_9");

        gridLayout->addWidget(label_9, 7, 0, 1, 1);

        doubleSpinBox_montant = new QDoubleSpinBox(tabAjouter);
        doubleSpinBox_montant->setObjectName("doubleSpinBox_montant");
        doubleSpinBox_montant->setDecimals(2);
        doubleSpinBox_montant->setMaximum(0);

        gridLayout->addWidget(doubleSpinBox_montant, 7, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnAjouter = new QPushButton(tabAjouter);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout_2->addWidget(btnAjouter);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tabWidget->addTab(tabAjouter, QString());
        tabListe = new QWidget();
        tabListe->setObjectName("tabListe");
        horizontalLayout_3 = new QHBoxLayout(tabListe);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        sidebarListe = new QFrame(tabListe);
        sidebarListe->setObjectName("sidebarListe");
        sidebarListe->setMinimumSize(QSize(180, 0));
        sidebarListe->setMaximumSize(QSize(200, 16777215));
        verticalLayout_5 = new QVBoxLayout(sidebarListe);
        verticalLayout_5->setObjectName("verticalLayout_5");
        groupBox_recherche = new QGroupBox(sidebarListe);
        groupBox_recherche->setObjectName("groupBox_recherche");
        verticalLayout_4 = new QVBoxLayout(groupBox_recherche);
        verticalLayout_4->setObjectName("verticalLayout_4");
        label_10 = new QLabel(groupBox_recherche);
        label_10->setObjectName("label_10");

        verticalLayout_4->addWidget(label_10);

        search_id = new QLineEdit(groupBox_recherche);
        search_id->setObjectName("search_id");

        verticalLayout_4->addWidget(search_id);

        label_11 = new QLabel(groupBox_recherche);
        label_11->setObjectName("label_11");

        verticalLayout_4->addWidget(label_11);

        search_fournisseur = new QLineEdit(groupBox_recherche);
        search_fournisseur->setObjectName("search_fournisseur");

        verticalLayout_4->addWidget(search_fournisseur);

        label_12 = new QLabel(groupBox_recherche);
        label_12->setObjectName("label_12");

        verticalLayout_4->addWidget(label_12);

        search_etat = new QComboBox(groupBox_recherche);
        search_etat->addItem(QString());
        search_etat->addItem(QString());
        search_etat->addItem(QString());
        search_etat->addItem(QString());
        search_etat->addItem(QString());
        search_etat->setObjectName("search_etat");

        verticalLayout_4->addWidget(search_etat);

        label_13 = new QLabel(groupBox_recherche);
        label_13->setObjectName("label_13");

        verticalLayout_4->addWidget(label_13);

        search_date_debut = new QDateEdit(groupBox_recherche);
        search_date_debut->setObjectName("search_date_debut");
        search_date_debut->setCalendarPopup(true);

        verticalLayout_4->addWidget(search_date_debut);

        label_14 = new QLabel(groupBox_recherche);
        label_14->setObjectName("label_14");

        verticalLayout_4->addWidget(label_14);

        search_date_fin = new QDateEdit(groupBox_recherche);
        search_date_fin->setObjectName("search_date_fin");
        search_date_fin->setCalendarPopup(true);

        verticalLayout_4->addWidget(search_date_fin);


        verticalLayout_5->addWidget(groupBox_recherche);

        groupBox_tri = new QGroupBox(sidebarListe);
        groupBox_tri->setObjectName("groupBox_tri");
        verticalLayout_6 = new QVBoxLayout(groupBox_tri);
        verticalLayout_6->setObjectName("verticalLayout_6");
        radioButton_dateArrivage = new QRadioButton(groupBox_tri);
        radioButton_dateArrivage->setObjectName("radioButton_dateArrivage");
        radioButton_dateArrivage->setChecked(true);

        verticalLayout_6->addWidget(radioButton_dateArrivage);

        radioButton_montant = new QRadioButton(groupBox_tri);
        radioButton_montant->setObjectName("radioButton_montant");

        verticalLayout_6->addWidget(radioButton_montant);

        radioButton_quantite = new QRadioButton(groupBox_tri);
        radioButton_quantite->setObjectName("radioButton_quantite");

        verticalLayout_6->addWidget(radioButton_quantite);

        radioButton_dateSortie = new QRadioButton(groupBox_tri);
        radioButton_dateSortie->setObjectName("radioButton_dateSortie");

        verticalLayout_6->addWidget(radioButton_dateSortie);


        verticalLayout_5->addWidget(groupBox_tri);

        groupBox_ordre = new QGroupBox(sidebarListe);
        groupBox_ordre->setObjectName("groupBox_ordre");
        verticalLayout_7 = new QVBoxLayout(groupBox_ordre);
        verticalLayout_7->setObjectName("verticalLayout_7");
        radioButton_croissant = new QRadioButton(groupBox_ordre);
        radioButton_croissant->setObjectName("radioButton_croissant");
        radioButton_croissant->setChecked(true);

        verticalLayout_7->addWidget(radioButton_croissant);

        radioButton_decroissant = new QRadioButton(groupBox_ordre);
        radioButton_decroissant->setObjectName("radioButton_decroissant");

        verticalLayout_7->addWidget(radioButton_decroissant);


        verticalLayout_5->addWidget(groupBox_ordre);

        verticalSpacer_2 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(sidebarListe);

        tableWidget_commandes = new QTableWidget(tabListe);
        if (tableWidget_commandes->columnCount() < 8)
            tableWidget_commandes->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_commandes->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableWidget_commandes->setObjectName("tableWidget_commandes");
        tableWidget_commandes->setColumnCount(8);

        horizontalLayout_3->addWidget(tableWidget_commandes);

        tabWidget->addTab(tabListe, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        verticalLayout_8 = new QVBoxLayout(tabSupprimer);
        verticalLayout_8->setObjectName("verticalLayout_8");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_15 = new QLabel(tabSupprimer);
        label_15->setObjectName("label_15");

        formLayout->setWidget(0, QFormLayout::LabelRole, label_15);

        lineEdit_id_supprimer = new QLineEdit(tabSupprimer);
        lineEdit_id_supprimer->setObjectName("lineEdit_id_supprimer");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id_supprimer);


        verticalLayout_8->addLayout(formLayout);

        btnSupprimer = new QPushButton(tabSupprimer);
        btnSupprimer->setObjectName("btnSupprimer");

        verticalLayout_8->addWidget(btnSupprimer);

        verticalSpacer_3 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_3);

        tabWidget->addTab(tabSupprimer, QString());
        tabModifier = new QWidget();
        tabModifier->setObjectName("tabModifier");
        verticalLayout_9 = new QVBoxLayout(tabModifier);
        verticalLayout_9->setObjectName("verticalLayout_9");
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName("formLayout_2");
        label_16 = new QLabel(tabModifier);
        label_16->setObjectName("label_16");

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_16);

        lineEdit_id_modifier = new QLineEdit(tabModifier);
        lineEdit_id_modifier->setObjectName("lineEdit_id_modifier");

        formLayout_2->setWidget(0, QFormLayout::FieldRole, lineEdit_id_modifier);

        btnCharger = new QPushButton(tabModifier);
        btnCharger->setObjectName("btnCharger");

        formLayout_2->setWidget(1, QFormLayout::FieldRole, btnCharger);


        verticalLayout_9->addLayout(formLayout_2);

        groupBox_modifier = new QGroupBox(tabModifier);
        groupBox_modifier->setObjectName("groupBox_modifier");
        gridLayout_2 = new QGridLayout(groupBox_modifier);
        gridLayout_2->setObjectName("gridLayout_2");
        label_17 = new QLabel(groupBox_modifier);
        label_17->setObjectName("label_17");

        gridLayout_2->addWidget(label_17, 0, 0, 1, 1);

        lineEdit_libelle_mod = new QLineEdit(groupBox_modifier);
        lineEdit_libelle_mod->setObjectName("lineEdit_libelle_mod");

        gridLayout_2->addWidget(lineEdit_libelle_mod, 0, 1, 1, 1);

        label_18 = new QLabel(groupBox_modifier);
        label_18->setObjectName("label_18");

        gridLayout_2->addWidget(label_18, 1, 0, 1, 1);

        combo_fournisseur_mod = new QComboBox(groupBox_modifier);
        combo_fournisseur_mod->addItem(QString());
        combo_fournisseur_mod->addItem(QString());
        combo_fournisseur_mod->addItem(QString());
        combo_fournisseur_mod->setObjectName("combo_fournisseur_mod");

        gridLayout_2->addWidget(combo_fournisseur_mod, 1, 1, 1, 1);

        label_19 = new QLabel(groupBox_modifier);
        label_19->setObjectName("label_19");

        gridLayout_2->addWidget(label_19, 2, 0, 1, 1);

        dateEdit_arrivage_mod = new QDateEdit(groupBox_modifier);
        dateEdit_arrivage_mod->setObjectName("dateEdit_arrivage_mod");
        dateEdit_arrivage_mod->setCalendarPopup(true);

        gridLayout_2->addWidget(dateEdit_arrivage_mod, 2, 1, 1, 1);

        label_20 = new QLabel(groupBox_modifier);
        label_20->setObjectName("label_20");

        gridLayout_2->addWidget(label_20, 3, 0, 1, 1);

        dateEdit_sortie_mod = new QDateEdit(groupBox_modifier);
        dateEdit_sortie_mod->setObjectName("dateEdit_sortie_mod");
        dateEdit_sortie_mod->setCalendarPopup(true);

        gridLayout_2->addWidget(dateEdit_sortie_mod, 3, 1, 1, 1);

        label_21 = new QLabel(groupBox_modifier);
        label_21->setObjectName("label_21");

        gridLayout_2->addWidget(label_21, 4, 0, 1, 1);

        combo_etat_mod = new QComboBox(groupBox_modifier);
        combo_etat_mod->addItem(QString());
        combo_etat_mod->addItem(QString());
        combo_etat_mod->addItem(QString());
        combo_etat_mod->addItem(QString());
        combo_etat_mod->setObjectName("combo_etat_mod");

        gridLayout_2->addWidget(combo_etat_mod, 4, 1, 1, 1);

        label_22 = new QLabel(groupBox_modifier);
        label_22->setObjectName("label_22");

        gridLayout_2->addWidget(label_22, 5, 0, 1, 1);

        spinBox_quantite_mod = new QSpinBox(groupBox_modifier);
        spinBox_quantite_mod->setObjectName("spinBox_quantite_mod");
        spinBox_quantite_mod->setMinimum(1);
        spinBox_quantite_mod->setMaximum(10000);

        gridLayout_2->addWidget(spinBox_quantite_mod, 5, 1, 1, 1);

        label_23 = new QLabel(groupBox_modifier);
        label_23->setObjectName("label_23");

        gridLayout_2->addWidget(label_23, 6, 0, 1, 1);

        doubleSpinBox_montant_mod = new QDoubleSpinBox(groupBox_modifier);
        doubleSpinBox_montant_mod->setObjectName("doubleSpinBox_montant_mod");

        gridLayout_2->addWidget(doubleSpinBox_montant_mod, 6, 1, 1, 1);


        verticalLayout_9->addWidget(groupBox_modifier);

        btnModifier = new QPushButton(tabModifier);
        btnModifier->setObjectName("btnModifier");

        verticalLayout_9->addWidget(btnModifier);

        tabWidget->addTab(tabModifier, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_10 = new QVBoxLayout(tabStatistiques);
        verticalLayout_10->setObjectName("verticalLayout_10");
        groupBox_depenses = new QGroupBox(tabStatistiques);
        groupBox_depenses->setObjectName("groupBox_depenses");
        verticalLayout_11 = new QVBoxLayout(groupBox_depenses);
        verticalLayout_11->setObjectName("verticalLayout_11");
        tableWidget_depenses = new QTableWidget(groupBox_depenses);
        if (tableWidget_depenses->columnCount() < 2)
            tableWidget_depenses->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_depenses->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_depenses->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        tableWidget_depenses->setObjectName("tableWidget_depenses");
        tableWidget_depenses->setColumnCount(2);

        verticalLayout_11->addWidget(tableWidget_depenses);


        verticalLayout_10->addWidget(groupBox_depenses);

        groupBox_top = new QGroupBox(tabStatistiques);
        groupBox_top->setObjectName("groupBox_top");
        verticalLayout_12 = new QVBoxLayout(groupBox_top);
        verticalLayout_12->setObjectName("verticalLayout_12");
        tableWidget_top = new QTableWidget(groupBox_top);
        if (tableWidget_top->columnCount() < 2)
            tableWidget_top->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_top->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        tableWidget_top->setObjectName("tableWidget_top");
        tableWidget_top->setColumnCount(2);

        verticalLayout_12->addWidget(tableWidget_top);


        verticalLayout_10->addWidget(groupBox_top);

        tabWidget->addTab(tabStatistiques, QString());
        tabCalendrier = new QWidget();
        tabCalendrier->setObjectName("tabCalendrier");
        verticalLayout_13 = new QVBoxLayout(tabCalendrier);
        verticalLayout_13->setObjectName("verticalLayout_13");
        calendarWidget = new QCalendarWidget(tabCalendrier);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGridVisible(true);

        verticalLayout_13->addWidget(calendarWidget);

        groupBox_commandes_jour = new QGroupBox(tabCalendrier);
        groupBox_commandes_jour->setObjectName("groupBox_commandes_jour");
        verticalLayout_14 = new QVBoxLayout(groupBox_commandes_jour);
        verticalLayout_14->setObjectName("verticalLayout_14");
        listWidget_commandes = new QListWidget(groupBox_commandes_jour);
        listWidget_commandes->setObjectName("listWidget_commandes");

        verticalLayout_14->addWidget(listWidget_commandes);


        verticalLayout_13->addWidget(groupBox_commandes_jour);

        tabWidget->addTab(tabCalendrier, QString());
        tabExport = new QWidget();
        tabExport->setObjectName("tabExport");
        verticalLayout_15 = new QVBoxLayout(tabExport);
        verticalLayout_15->setObjectName("verticalLayout_15");
        btnExportListe = new QPushButton(tabExport);
        btnExportListe->setObjectName("btnExportListe");

        verticalLayout_15->addWidget(btnExportListe);

        btnExportRapport = new QPushButton(tabExport);
        btnExportRapport->setObjectName("btnExportRapport");

        verticalLayout_15->addWidget(btnExportRapport);

        btnExportFiche = new QPushButton(tabExport);
        btnExportFiche->setObjectName("btnExportFiche");

        verticalLayout_15->addWidget(btnExportFiche);

        formLayout_3 = new QFormLayout();
        formLayout_3->setObjectName("formLayout_3");
        label_24 = new QLabel(tabExport);
        label_24->setObjectName("label_24");

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_24);

        lineEdit_id_export = new QLineEdit(tabExport);
        lineEdit_id_export->setObjectName("lineEdit_id_export");

        formLayout_3->setWidget(0, QFormLayout::FieldRole, lineEdit_id_export);


        verticalLayout_15->addLayout(formLayout_3);

        groupBox_email = new QGroupBox(tabExport);
        groupBox_email->setObjectName("groupBox_email");
        formLayout_4 = new QFormLayout(groupBox_email);
        formLayout_4->setObjectName("formLayout_4");
        label_25 = new QLabel(groupBox_email);
        label_25->setObjectName("label_25");

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_25);

        lineEdit_email_client = new QLineEdit(groupBox_email);
        lineEdit_email_client->setObjectName("lineEdit_email_client");

        formLayout_4->setWidget(0, QFormLayout::FieldRole, lineEdit_email_client);

        label_26 = new QLabel(groupBox_email);
        label_26->setObjectName("label_26");

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_26);

        lineEdit_id_email = new QLineEdit(groupBox_email);
        lineEdit_id_email->setObjectName("lineEdit_id_email");

        formLayout_4->setWidget(1, QFormLayout::FieldRole, lineEdit_id_email);

        btnEnvoyerEmail = new QPushButton(groupBox_email);
        btnEnvoyerEmail->setObjectName("btnEnvoyerEmail");

        formLayout_4->setWidget(2, QFormLayout::SpanningRole, btnEnvoyerEmail);


        verticalLayout_15->addWidget(groupBox_email);

        textEdit_messages = new QTextEdit(tabExport);
        textEdit_messages->setObjectName("textEdit_messages");
        textEdit_messages->setMaximumHeight(100);

        verticalLayout_15->addWidget(textEdit_messages);

        verticalSpacer_4 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_4);

        tabWidget->addTab(tabExport, QString());

        verticalLayout->addWidget(tabWidget);

        stackedMain->addWidget(pageCommandes);
        pageEquipe = new QWidget();
        pageEquipe->setObjectName("pageEquipe");
        verticalLayout_16 = new QVBoxLayout(pageEquipe);
        verticalLayout_16->setObjectName("verticalLayout_16");
        label_equipe = new QLabel(pageEquipe);
        label_equipe->setObjectName("label_equipe");
        label_equipe->setAlignment(Qt::AlignCenter);

        verticalLayout_16->addWidget(label_equipe);

        stackedMain->addWidget(pageEquipe);
        pageClient = new QWidget();
        pageClient->setObjectName("pageClient");
        verticalLayout_17 = new QVBoxLayout(pageClient);
        verticalLayout_17->setObjectName("verticalLayout_17");
        label_client = new QLabel(pageClient);
        label_client->setObjectName("label_client");
        label_client->setAlignment(Qt::AlignCenter);

        verticalLayout_17->addWidget(label_client);

        stackedMain->addWidget(pageClient);
        pageLaboratoire = new QWidget();
        pageLaboratoire->setObjectName("pageLaboratoire");
        verticalLayout_18 = new QVBoxLayout(pageLaboratoire);
        verticalLayout_18->setObjectName("verticalLayout_18");
        label_labo = new QLabel(pageLaboratoire);
        label_labo->setObjectName("label_labo");
        label_labo->setAlignment(Qt::AlignCenter);

        verticalLayout_18->addWidget(label_labo);

        stackedMain->addWidget(pageLaboratoire);
        pageFournisseur = new QWidget();
        pageFournisseur->setObjectName("pageFournisseur");
        verticalLayout_19 = new QVBoxLayout(pageFournisseur);
        verticalLayout_19->setObjectName("verticalLayout_19");
        label_fournisseur = new QLabel(pageFournisseur);
        label_fournisseur->setObjectName("label_fournisseur");
        label_fournisseur->setAlignment(Qt::AlignCenter);

        verticalLayout_19->addWidget(label_fournisseur);

        stackedMain->addWidget(pageFournisseur);
        pageMachine = new QWidget();
        pageMachine->setObjectName("pageMachine");
        verticalLayout_20 = new QVBoxLayout(pageMachine);
        verticalLayout_20->setObjectName("verticalLayout_20");
        label_machine = new QLabel(pageMachine);
        label_machine->setObjectName("label_machine");
        label_machine->setAlignment(Qt::AlignCenter);

        verticalLayout_20->addWidget(label_machine);

        stackedMain->addWidget(pageMachine);

        horizontalLayout->addWidget(stackedMain);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedMain->setCurrentIndex(1);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Oil Press - Gestion des Commandes", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "SMART OIL", nullptr));
        btnCommande->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnEquipe->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnLaboratoire->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnFournisseur->setText(QCoreApplication::translate("MainWindow", "FOURNISSEUR", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Bienvenue dans Smart Oil Press", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "GESTION DES COMMANDES", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "ID Commande:", nullptr));
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "G\303\251n\303\251r\303\251 automatiquement", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Libell\303\251:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Fournisseur:", nullptr));
        combo_fournisseur->setItemText(0, QCoreApplication::translate("MainWindow", "Fournisseur A", nullptr));
        combo_fournisseur->setItemText(1, QCoreApplication::translate("MainWindow", "Fournisseur B", nullptr));
        combo_fournisseur->setItemText(2, QCoreApplication::translate("MainWindow", "Fournisseur C", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "Date arrivage:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Date sortie:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\303\211tat:", nullptr));
        combo_etat->setItemText(0, QCoreApplication::translate("MainWindow", "En cours", nullptr));
        combo_etat->setItemText(1, QCoreApplication::translate("MainWindow", "Valid\303\251e", nullptr));
        combo_etat->setItemText(2, QCoreApplication::translate("MainWindow", "Pr\303\252te", nullptr));
        combo_etat->setItemText(3, QCoreApplication::translate("MainWindow", "Annul\303\251e", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "Montant (\342\202\254):", nullptr));
        doubleSpinBox_montant->setPrefix(QCoreApplication::translate("MainWindow", "\342\202\254 ", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter la commande", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        groupBox_recherche->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Fournisseur:", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\303\211tat:", nullptr));
        search_etat->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        search_etat->setItemText(1, QCoreApplication::translate("MainWindow", "En cours", nullptr));
        search_etat->setItemText(2, QCoreApplication::translate("MainWindow", "Valid\303\251e", nullptr));
        search_etat->setItemText(3, QCoreApplication::translate("MainWindow", "Pr\303\252te", nullptr));
        search_etat->setItemText(4, QCoreApplication::translate("MainWindow", "Annul\303\251e", nullptr));

        label_13->setText(QCoreApplication::translate("MainWindow", "Date d\303\251but:", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Date fin:", nullptr));
        groupBox_tri->setTitle(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        radioButton_dateArrivage->setText(QCoreApplication::translate("MainWindow", "Date arrivage", nullptr));
        radioButton_montant->setText(QCoreApplication::translate("MainWindow", "Montant", nullptr));
        radioButton_quantite->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        radioButton_dateSortie->setText(QCoreApplication::translate("MainWindow", "Date sortie", nullptr));
        groupBox_ordre->setTitle(QCoreApplication::translate("MainWindow", "Ordre", nullptr));
        radioButton_croissant->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        radioButton_decroissant->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_commandes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_commandes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Libell\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_commandes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_commandes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Date arrivage", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_commandes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Date sortie", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_commandes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_commandes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_commandes->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Montant (\342\202\254)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("MainWindow", "Liste", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "ID Commande:", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "ID Commande:", nullptr));
        btnCharger->setText(QCoreApplication::translate("MainWindow", "Charger", nullptr));
        groupBox_modifier->setTitle(QCoreApplication::translate("MainWindow", "Donn\303\251es \303\240 modifier", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Libell\303\251:", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "Fournisseur:", nullptr));
        combo_fournisseur_mod->setItemText(0, QCoreApplication::translate("MainWindow", "Fournisseur A", nullptr));
        combo_fournisseur_mod->setItemText(1, QCoreApplication::translate("MainWindow", "Fournisseur B", nullptr));
        combo_fournisseur_mod->setItemText(2, QCoreApplication::translate("MainWindow", "Fournisseur C", nullptr));

        label_19->setText(QCoreApplication::translate("MainWindow", "Date arrivage:", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "Date sortie:", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\303\211tat:", nullptr));
        combo_etat_mod->setItemText(0, QCoreApplication::translate("MainWindow", "En cours", nullptr));
        combo_etat_mod->setItemText(1, QCoreApplication::translate("MainWindow", "Valid\303\251e", nullptr));
        combo_etat_mod->setItemText(2, QCoreApplication::translate("MainWindow", "Pr\303\252te", nullptr));
        combo_etat_mod->setItemText(3, QCoreApplication::translate("MainWindow", "Annul\303\251e", nullptr));

        label_22->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251:", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "Montant:", nullptr));
        doubleSpinBox_montant_mod->setPrefix(QCoreApplication::translate("MainWindow", "\342\202\254 ", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Mettre \303\240 jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        groupBox_depenses->setTitle(QCoreApplication::translate("MainWindow", "D\303\251penses mensuelles", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_depenses->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Mois", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_depenses->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Montant (\342\202\254)", nullptr));
        groupBox_top->setTitle(QCoreApplication::translate("MainWindow", "Top produits command\303\251s", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_top->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Produit", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_top->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        groupBox_commandes_jour->setTitle(QCoreApplication::translate("MainWindow", "Commandes du jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCalendrier), QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
        btnExportListe->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter la liste compl\303\250te (PDF)", nullptr));
        btnExportRapport->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Exporter le rapport statistiques (PDF)", nullptr));
        btnExportFiche->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 Exporter la fiche commande (PDF)", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "ID Commande:", nullptr));
        groupBox_email->setTitle(QCoreApplication::translate("MainWindow", "Envoi par email", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "Email client:", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "ID Commande pr\303\252te:", nullptr));
        btnEnvoyerEmail->setText(QCoreApplication::translate("MainWindow", "\360\237\223\247 Envoyer email de notification", nullptr));
        textEdit_messages->setPlaceholderText(QCoreApplication::translate("MainWindow", "Messages d'export et notifications...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExport), QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        label_equipe->setText(QCoreApplication::translate("MainWindow", "Gestion des \303\211quipes", nullptr));
        label_client->setText(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label_labo->setText(QCoreApplication::translate("MainWindow", "Gestion du Laboratoire", nullptr));
        label_fournisseur->setText(QCoreApplication::translate("MainWindow", "Gestion des Fournisseurs", nullptr));
        label_machine->setText(QCoreApplication::translate("MainWindow", "Gestion des Machines", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
