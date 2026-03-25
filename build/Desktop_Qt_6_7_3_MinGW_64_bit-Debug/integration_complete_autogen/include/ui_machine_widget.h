/********************************************************************************
** Form generated from reading UI file 'machine_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MACHINE_WIDGET_H
#define UI_MACHINE_WIDGET_H

#include <QtCore/QVariant>
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MachineWidget
{
public:
    QVBoxLayout *machineLayout;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *leftLayout;
    QGroupBox *groupBoxSearch;
    QVBoxLayout *vboxLayout;
    QHBoxLayout *hboxLayout;
    QLabel *label;
    QLineEdit *lineEditSearch;
    QHBoxLayout *hboxLayout1;
    QLabel *label1;
    QComboBox *comboCategory;
    QHBoxLayout *hboxLayout2;
    QLabel *label2;
    QComboBox *comboState;
    QHBoxLayout *hboxLayout3;
    QLabel *label3;
    QLineEdit *lineEditLocation;
    QPushButton *btnApplyFilter;
    QGroupBox *groupBoxSort;
    QVBoxLayout *vboxLayout1;
    QHBoxLayout *hboxLayout4;
    QLabel *label4;
    QComboBox *comboSortBy;
    QHBoxLayout *hboxLayout5;
    QRadioButton *radioCroissant;
    QRadioButton *radioDecroissant;
    QPushButton *btnScanQR;
    QSpacerItem *verticalSpacerLeft;
    QWidget *centerPanel;
    QVBoxLayout *centerLayout;
    QTabWidget *tabWidget;
    QWidget *tabAjouter;
    QVBoxLayout *vboxLayout2;
    QLabel *labelAdd;
    QFrame *frameAdd;
    QFormLayout *formLayoutAdd;
    QLabel *label5;
    QLineEdit *editAddId;
    QLabel *label6;
    QLineEdit *editAddNom;
    QLabel *label7;
    QComboBox *comboAddCategorie;
    QLabel *label8;
    QLineEdit *editAddReference;
    QLabel *label9;
    QDateEdit *dateAddAchat;
    QLabel *label10;
    QComboBox *comboAddEtat;
    QLabel *label11;
    QLineEdit *editAddLocalisation;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout6;
    QSpacerItem *spacerItem1;
    QPushButton *btnConfirmerAjouter;
    QPushButton *btnAnnulerAjouter;
    QWidget *tabListe;
    QVBoxLayout *vboxLayout3;
    QTableWidget *tableMachines;
    QHBoxLayout *hboxLayout7;
    QPushButton *btnExportPDF;
    QPushButton *btnRefresh;
    QSpacerItem *spacerItem2;
    QWidget *tabSupprimer;
    QVBoxLayout *vboxLayout4;
    QLabel *label12;
    QGroupBox *grpMachineASupprimer;
    QVBoxLayout *vboxLayout5;
    QLabel *lblSupprimerNom;
    QLabel *lblSupprimerDetails;
    QSpacerItem *spacerItem3;
    QHBoxLayout *hboxLayout8;
    QSpacerItem *spacerItem4;
    QPushButton *btnConfirmerSupprimer;
    QPushButton *btnAnnulerSupprimer;
    QWidget *tabModifier;
    QVBoxLayout *vboxLayout6;
    QLabel *label13;
    QGroupBox *grpFormModifier;
    QFormLayout *formLayout;
    QLabel *label14;
    QLineEdit *editModifierId;
    QLabel *label15;
    QLineEdit *editModifierNom;
    QLabel *label16;
    QComboBox *comboModifierCategorie;
    QLabel *label17;
    QLineEdit *editModifierReference;
    QLabel *label18;
    QDateEdit *dateModifierAchat;
    QLabel *label19;
    QComboBox *comboModifierEtat;
    QLabel *label20;
    QLineEdit *editModifierLocalisation;
    QSpacerItem *spacerItem5;
    QHBoxLayout *hboxLayout9;
    QSpacerItem *spacerItem6;
    QPushButton *btnConfirmerModifier;
    QPushButton *btnAnnulerModifier;
    QWidget *tabPanne;
    QVBoxLayout *vboxLayout7;
    QLabel *label21;
    QGroupBox *grpPanne;
    QFormLayout *formLayout1;
    QLabel *label22;
    QComboBox *comboPanneMachine;
    QLabel *label23;
    QDateEdit *datePanne;
    QLabel *label24;
    QComboBox *comboTypePanne;
    QLabel *label25;
    QComboBox *comboGravite;
    QLabel *label26;
    QTextEdit *txtDescriptionPanne;
    QSpacerItem *spacerItem7;
    QHBoxLayout *hboxLayout10;
    QSpacerItem *spacerItem8;
    QPushButton *btnSignalerPanne;
    QPushButton *btnAnnulerPanne;
    QWidget *tabHistorique;
    QVBoxLayout *vboxLayout8;
    QTableWidget *tableHistorique;
    QHBoxLayout *hboxLayout11;
    QPushButton *btnExportHistorique;
    QSpacerItem *spacerItem9;
    QWidget *tabStatistiques;
    QVBoxLayout *vboxLayout9;
    QGroupBox *grpStatsResume;
    QHBoxLayout *hboxLayout12;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout10;
    QLabel *lblStatsTotalMachines;
    QGroupBox *groupBox1;
    QVBoxLayout *vboxLayout11;
    QLabel *lblStatsEnService;
    QGroupBox *groupBox2;
    QVBoxLayout *vboxLayout12;
    QLabel *lblStatsEnPanne;
    QGroupBox *groupBox3;
    QVBoxLayout *vboxLayout13;
    QLabel *lblStatsMaintenance;
    QTextEdit *txtStatistiques;
    QHBoxLayout *hboxLayout13;
    QPushButton *btnExportStats;
    QSpacerItem *spacerItem10;

    void setupUi(QWidget *MachineWidget)
    {
        if (MachineWidget->objectName().isEmpty())
            MachineWidget->setObjectName("MachineWidget");
        MachineWidget->resize(1200, 800);
        machineLayout = new QVBoxLayout(MachineWidget);
        machineLayout->setObjectName("machineLayout");
        splitter = new QSplitter(MachineWidget);
        splitter->setObjectName("splitter");
        splitter->setOrientation(Qt::Horizontal);
        leftPanel = new QWidget(splitter);
        leftPanel->setObjectName("leftPanel");
        leftPanel->setMinimumSize(QSize(220, 0));
        leftPanel->setMaximumSize(QSize(280, 16777215));
        leftLayout = new QVBoxLayout(leftPanel);
        leftLayout->setObjectName("leftLayout");
        leftLayout->setContentsMargins(5, 5, 5, 5);
        groupBoxSearch = new QGroupBox(leftPanel);
        groupBoxSearch->setObjectName("groupBoxSearch");
        vboxLayout = new QVBoxLayout(groupBoxSearch);
        vboxLayout->setObjectName("vboxLayout");
        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        label = new QLabel(groupBoxSearch);
        label->setObjectName("label");

        hboxLayout->addWidget(label);

        lineEditSearch = new QLineEdit(groupBoxSearch);
        lineEditSearch->setObjectName("lineEditSearch");

        hboxLayout->addWidget(lineEditSearch);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        label1 = new QLabel(groupBoxSearch);
        label1->setObjectName("label1");

        hboxLayout1->addWidget(label1);

        comboCategory = new QComboBox(groupBoxSearch);
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->setObjectName("comboCategory");

        hboxLayout1->addWidget(comboCategory);


        vboxLayout->addLayout(hboxLayout1);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        label2 = new QLabel(groupBoxSearch);
        label2->setObjectName("label2");

        hboxLayout2->addWidget(label2);

        comboState = new QComboBox(groupBoxSearch);
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->setObjectName("comboState");

        hboxLayout2->addWidget(comboState);


        vboxLayout->addLayout(hboxLayout2);

        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName("hboxLayout3");
        label3 = new QLabel(groupBoxSearch);
        label3->setObjectName("label3");

        hboxLayout3->addWidget(label3);

        lineEditLocation = new QLineEdit(groupBoxSearch);
        lineEditLocation->setObjectName("lineEditLocation");

        hboxLayout3->addWidget(lineEditLocation);


        vboxLayout->addLayout(hboxLayout3);

        btnApplyFilter = new QPushButton(groupBoxSearch);
        btnApplyFilter->setObjectName("btnApplyFilter");
        btnApplyFilter->setMinimumHeight(35);

        vboxLayout->addWidget(btnApplyFilter);


        leftLayout->addWidget(groupBoxSearch);

        groupBoxSort = new QGroupBox(leftPanel);
        groupBoxSort->setObjectName("groupBoxSort");
        vboxLayout1 = new QVBoxLayout(groupBoxSort);
        vboxLayout1->setObjectName("vboxLayout1");
        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName("hboxLayout4");
        label4 = new QLabel(groupBoxSort);
        label4->setObjectName("label4");

        hboxLayout4->addWidget(label4);

        comboSortBy = new QComboBox(groupBoxSort);
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->setObjectName("comboSortBy");

        hboxLayout4->addWidget(comboSortBy);


        vboxLayout1->addLayout(hboxLayout4);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setObjectName("hboxLayout5");
        radioCroissant = new QRadioButton(groupBoxSort);
        radioCroissant->setObjectName("radioCroissant");
        radioCroissant->setChecked(true);

        hboxLayout5->addWidget(radioCroissant);

        radioDecroissant = new QRadioButton(groupBoxSort);
        radioDecroissant->setObjectName("radioDecroissant");

        hboxLayout5->addWidget(radioDecroissant);


        vboxLayout1->addLayout(hboxLayout5);


        leftLayout->addWidget(groupBoxSort);

        btnScanQR = new QPushButton(leftPanel);
        btnScanQR->setObjectName("btnScanQR");
        btnScanQR->setMinimumHeight(45);

        leftLayout->addWidget(btnScanQR);

        verticalSpacerLeft = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        leftLayout->addItem(verticalSpacerLeft);

        splitter->addWidget(leftPanel);
        centerPanel = new QWidget(splitter);
        centerPanel->setObjectName("centerPanel");
        centerLayout = new QVBoxLayout(centerPanel);
        centerLayout->setObjectName("centerLayout");
        centerLayout->setContentsMargins(10, 10, 10, 10);
        tabWidget = new QTabWidget(centerPanel);
        tabWidget->setObjectName("tabWidget");
        tabAjouter = new QWidget();
        tabAjouter->setObjectName("tabAjouter");
        vboxLayout2 = new QVBoxLayout(tabAjouter);
        vboxLayout2->setObjectName("vboxLayout2");
        labelAdd = new QLabel(tabAjouter);
        labelAdd->setObjectName("labelAdd");
        labelAdd->setAlignment(Qt::AlignCenter);

        vboxLayout2->addWidget(labelAdd);

        frameAdd = new QFrame(tabAjouter);
        frameAdd->setObjectName("frameAdd");
        frameAdd->setFrameShape(QFrame::StyledPanel);
        frameAdd->setFrameShadow(QFrame::Raised);
        formLayoutAdd = new QFormLayout(frameAdd);
        formLayoutAdd->setObjectName("formLayoutAdd");
        formLayoutAdd->setHorizontalSpacing(20);
        formLayoutAdd->setVerticalSpacing(12);
        label5 = new QLabel(frameAdd);
        label5->setObjectName("label5");

        formLayoutAdd->setWidget(0, QFormLayout::LabelRole, label5);

        editAddId = new QLineEdit(frameAdd);
        editAddId->setObjectName("editAddId");

        formLayoutAdd->setWidget(0, QFormLayout::FieldRole, editAddId);

        label6 = new QLabel(frameAdd);
        label6->setObjectName("label6");

        formLayoutAdd->setWidget(1, QFormLayout::LabelRole, label6);

        editAddNom = new QLineEdit(frameAdd);
        editAddNom->setObjectName("editAddNom");

        formLayoutAdd->setWidget(1, QFormLayout::FieldRole, editAddNom);

        label7 = new QLabel(frameAdd);
        label7->setObjectName("label7");

        formLayoutAdd->setWidget(2, QFormLayout::LabelRole, label7);

        comboAddCategorie = new QComboBox(frameAdd);
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->setObjectName("comboAddCategorie");

        formLayoutAdd->setWidget(2, QFormLayout::FieldRole, comboAddCategorie);

        label8 = new QLabel(frameAdd);
        label8->setObjectName("label8");

        formLayoutAdd->setWidget(3, QFormLayout::LabelRole, label8);

        editAddReference = new QLineEdit(frameAdd);
        editAddReference->setObjectName("editAddReference");

        formLayoutAdd->setWidget(3, QFormLayout::FieldRole, editAddReference);

        label9 = new QLabel(frameAdd);
        label9->setObjectName("label9");

        formLayoutAdd->setWidget(4, QFormLayout::LabelRole, label9);

        dateAddAchat = new QDateEdit(frameAdd);
        dateAddAchat->setObjectName("dateAddAchat");
        dateAddAchat->setCalendarPopup(true);

        formLayoutAdd->setWidget(4, QFormLayout::FieldRole, dateAddAchat);

        label10 = new QLabel(frameAdd);
        label10->setObjectName("label10");

        formLayoutAdd->setWidget(5, QFormLayout::LabelRole, label10);

        comboAddEtat = new QComboBox(frameAdd);
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->setObjectName("comboAddEtat");

        formLayoutAdd->setWidget(5, QFormLayout::FieldRole, comboAddEtat);

        label11 = new QLabel(frameAdd);
        label11->setObjectName("label11");

        formLayoutAdd->setWidget(6, QFormLayout::LabelRole, label11);

        editAddLocalisation = new QLineEdit(frameAdd);
        editAddLocalisation->setObjectName("editAddLocalisation");

        formLayoutAdd->setWidget(6, QFormLayout::FieldRole, editAddLocalisation);


        vboxLayout2->addWidget(frameAdd);

        spacerItem = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout2->addItem(spacerItem);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setObjectName("hboxLayout6");
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout6->addItem(spacerItem1);

        btnConfirmerAjouter = new QPushButton(tabAjouter);
        btnConfirmerAjouter->setObjectName("btnConfirmerAjouter");
        btnConfirmerAjouter->setMinimumHeight(45);
        btnConfirmerAjouter->setMinimumWidth(200);

        hboxLayout6->addWidget(btnConfirmerAjouter);

        btnAnnulerAjouter = new QPushButton(tabAjouter);
        btnAnnulerAjouter->setObjectName("btnAnnulerAjouter");
        btnAnnulerAjouter->setMinimumHeight(45);
        btnAnnulerAjouter->setMinimumWidth(150);

        hboxLayout6->addWidget(btnAnnulerAjouter);


        vboxLayout2->addLayout(hboxLayout6);

        tabWidget->addTab(tabAjouter, QString());
        tabListe = new QWidget();
        tabListe->setObjectName("tabListe");
        vboxLayout3 = new QVBoxLayout(tabListe);
        vboxLayout3->setObjectName("vboxLayout3");
        tableMachines = new QTableWidget(tabListe);
        if (tableMachines->columnCount() < 7)
            tableMachines->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableMachines->setObjectName("tableMachines");
        tableMachines->setAlternatingRowColors(true);
        tableMachines->setSelectionBehavior(QAbstractItemView::SelectRows);

        vboxLayout3->addWidget(tableMachines);

        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName("hboxLayout7");
        btnExportPDF = new QPushButton(tabListe);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setMinimumHeight(35);

        hboxLayout7->addWidget(btnExportPDF);

        btnRefresh = new QPushButton(tabListe);
        btnRefresh->setObjectName("btnRefresh");
        btnRefresh->setMinimumHeight(35);

        hboxLayout7->addWidget(btnRefresh);

        spacerItem2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout7->addItem(spacerItem2);


        vboxLayout3->addLayout(hboxLayout7);

        tabWidget->addTab(tabListe, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        vboxLayout4 = new QVBoxLayout(tabSupprimer);
        vboxLayout4->setObjectName("vboxLayout4");
        vboxLayout4->setContentsMargins(20, 20, 20, 20);
        label12 = new QLabel(tabSupprimer);
        label12->setObjectName("label12");
        label12->setWordWrap(true);

        vboxLayout4->addWidget(label12);

        grpMachineASupprimer = new QGroupBox(tabSupprimer);
        grpMachineASupprimer->setObjectName("grpMachineASupprimer");
        vboxLayout5 = new QVBoxLayout(grpMachineASupprimer);
        vboxLayout5->setObjectName("vboxLayout5");
        lblSupprimerNom = new QLabel(grpMachineASupprimer);
        lblSupprimerNom->setObjectName("lblSupprimerNom");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        lblSupprimerNom->setFont(font);

        vboxLayout5->addWidget(lblSupprimerNom);

        lblSupprimerDetails = new QLabel(grpMachineASupprimer);
        lblSupprimerDetails->setObjectName("lblSupprimerDetails");

        vboxLayout5->addWidget(lblSupprimerDetails);


        vboxLayout4->addWidget(grpMachineASupprimer);

        spacerItem3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout4->addItem(spacerItem3);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setObjectName("hboxLayout8");
        spacerItem4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout8->addItem(spacerItem4);

        btnConfirmerSupprimer = new QPushButton(tabSupprimer);
        btnConfirmerSupprimer->setObjectName("btnConfirmerSupprimer");
        btnConfirmerSupprimer->setMinimumHeight(45);
        btnConfirmerSupprimer->setMinimumWidth(250);

        hboxLayout8->addWidget(btnConfirmerSupprimer);

        btnAnnulerSupprimer = new QPushButton(tabSupprimer);
        btnAnnulerSupprimer->setObjectName("btnAnnulerSupprimer");
        btnAnnulerSupprimer->setMinimumHeight(45);
        btnAnnulerSupprimer->setMinimumWidth(150);

        hboxLayout8->addWidget(btnAnnulerSupprimer);


        vboxLayout4->addLayout(hboxLayout8);

        tabWidget->addTab(tabSupprimer, QString());
        tabModifier = new QWidget();
        tabModifier->setObjectName("tabModifier");
        vboxLayout6 = new QVBoxLayout(tabModifier);
        vboxLayout6->setObjectName("vboxLayout6");
        vboxLayout6->setContentsMargins(20, 20, 20, 20);
        label13 = new QLabel(tabModifier);
        label13->setObjectName("label13");

        vboxLayout6->addWidget(label13);

        grpFormModifier = new QGroupBox(tabModifier);
        grpFormModifier->setObjectName("grpFormModifier");
        formLayout = new QFormLayout(grpFormModifier);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(12);
        label14 = new QLabel(grpFormModifier);
        label14->setObjectName("label14");

        formLayout->setWidget(0, QFormLayout::LabelRole, label14);

        editModifierId = new QLineEdit(grpFormModifier);
        editModifierId->setObjectName("editModifierId");
        editModifierId->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, editModifierId);

        label15 = new QLabel(grpFormModifier);
        label15->setObjectName("label15");

        formLayout->setWidget(1, QFormLayout::LabelRole, label15);

        editModifierNom = new QLineEdit(grpFormModifier);
        editModifierNom->setObjectName("editModifierNom");

        formLayout->setWidget(1, QFormLayout::FieldRole, editModifierNom);

        label16 = new QLabel(grpFormModifier);
        label16->setObjectName("label16");

        formLayout->setWidget(2, QFormLayout::LabelRole, label16);

        comboModifierCategorie = new QComboBox(grpFormModifier);
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->setObjectName("comboModifierCategorie");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboModifierCategorie);

        label17 = new QLabel(grpFormModifier);
        label17->setObjectName("label17");

        formLayout->setWidget(3, QFormLayout::LabelRole, label17);

        editModifierReference = new QLineEdit(grpFormModifier);
        editModifierReference->setObjectName("editModifierReference");

        formLayout->setWidget(3, QFormLayout::FieldRole, editModifierReference);

        label18 = new QLabel(grpFormModifier);
        label18->setObjectName("label18");

        formLayout->setWidget(4, QFormLayout::LabelRole, label18);

        dateModifierAchat = new QDateEdit(grpFormModifier);
        dateModifierAchat->setObjectName("dateModifierAchat");
        dateModifierAchat->setCalendarPopup(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, dateModifierAchat);

        label19 = new QLabel(grpFormModifier);
        label19->setObjectName("label19");

        formLayout->setWidget(5, QFormLayout::LabelRole, label19);

        comboModifierEtat = new QComboBox(grpFormModifier);
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->setObjectName("comboModifierEtat");

        formLayout->setWidget(5, QFormLayout::FieldRole, comboModifierEtat);

        label20 = new QLabel(grpFormModifier);
        label20->setObjectName("label20");

        formLayout->setWidget(6, QFormLayout::LabelRole, label20);

        editModifierLocalisation = new QLineEdit(grpFormModifier);
        editModifierLocalisation->setObjectName("editModifierLocalisation");

        formLayout->setWidget(6, QFormLayout::FieldRole, editModifierLocalisation);


        vboxLayout6->addWidget(grpFormModifier);

        spacerItem5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout6->addItem(spacerItem5);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setObjectName("hboxLayout9");
        spacerItem6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout9->addItem(spacerItem6);

        btnConfirmerModifier = new QPushButton(tabModifier);
        btnConfirmerModifier->setObjectName("btnConfirmerModifier");
        btnConfirmerModifier->setMinimumHeight(45);
        btnConfirmerModifier->setMinimumWidth(250);

        hboxLayout9->addWidget(btnConfirmerModifier);

        btnAnnulerModifier = new QPushButton(tabModifier);
        btnAnnulerModifier->setObjectName("btnAnnulerModifier");
        btnAnnulerModifier->setMinimumHeight(45);
        btnAnnulerModifier->setMinimumWidth(150);

        hboxLayout9->addWidget(btnAnnulerModifier);


        vboxLayout6->addLayout(hboxLayout9);

        tabWidget->addTab(tabModifier, QString());
        tabPanne = new QWidget();
        tabPanne->setObjectName("tabPanne");
        vboxLayout7 = new QVBoxLayout(tabPanne);
        vboxLayout7->setObjectName("vboxLayout7");
        vboxLayout7->setContentsMargins(20, 20, 20, 20);
        label21 = new QLabel(tabPanne);
        label21->setObjectName("label21");

        vboxLayout7->addWidget(label21);

        grpPanne = new QGroupBox(tabPanne);
        grpPanne->setObjectName("grpPanne");
        formLayout1 = new QFormLayout(grpPanne);
        formLayout1->setObjectName("formLayout1");
        formLayout1->setHorizontalSpacing(20);
        formLayout1->setVerticalSpacing(12);
        label22 = new QLabel(grpPanne);
        label22->setObjectName("label22");

        formLayout1->setWidget(0, QFormLayout::LabelRole, label22);

        comboPanneMachine = new QComboBox(grpPanne);
        comboPanneMachine->setObjectName("comboPanneMachine");

        formLayout1->setWidget(0, QFormLayout::FieldRole, comboPanneMachine);

        label23 = new QLabel(grpPanne);
        label23->setObjectName("label23");

        formLayout1->setWidget(1, QFormLayout::LabelRole, label23);

        datePanne = new QDateEdit(grpPanne);
        datePanne->setObjectName("datePanne");
        datePanne->setCalendarPopup(true);

        formLayout1->setWidget(1, QFormLayout::FieldRole, datePanne);

        label24 = new QLabel(grpPanne);
        label24->setObjectName("label24");

        formLayout1->setWidget(2, QFormLayout::LabelRole, label24);

        comboTypePanne = new QComboBox(grpPanne);
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->setObjectName("comboTypePanne");

        formLayout1->setWidget(2, QFormLayout::FieldRole, comboTypePanne);

        label25 = new QLabel(grpPanne);
        label25->setObjectName("label25");

        formLayout1->setWidget(3, QFormLayout::LabelRole, label25);

        comboGravite = new QComboBox(grpPanne);
        comboGravite->addItem(QString());
        comboGravite->addItem(QString());
        comboGravite->addItem(QString());
        comboGravite->addItem(QString());
        comboGravite->setObjectName("comboGravite");

        formLayout1->setWidget(3, QFormLayout::FieldRole, comboGravite);

        label26 = new QLabel(grpPanne);
        label26->setObjectName("label26");

        formLayout1->setWidget(4, QFormLayout::LabelRole, label26);

        txtDescriptionPanne = new QTextEdit(grpPanne);
        txtDescriptionPanne->setObjectName("txtDescriptionPanne");
        txtDescriptionPanne->setMaximumHeight(100);

        formLayout1->setWidget(4, QFormLayout::FieldRole, txtDescriptionPanne);


        vboxLayout7->addWidget(grpPanne);

        spacerItem7 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout7->addItem(spacerItem7);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setObjectName("hboxLayout10");
        spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout10->addItem(spacerItem8);

        btnSignalerPanne = new QPushButton(tabPanne);
        btnSignalerPanne->setObjectName("btnSignalerPanne");
        btnSignalerPanne->setMinimumHeight(45);
        btnSignalerPanne->setMinimumWidth(220);

        hboxLayout10->addWidget(btnSignalerPanne);

        btnAnnulerPanne = new QPushButton(tabPanne);
        btnAnnulerPanne->setObjectName("btnAnnulerPanne");
        btnAnnulerPanne->setMinimumHeight(45);
        btnAnnulerPanne->setMinimumWidth(150);

        hboxLayout10->addWidget(btnAnnulerPanne);


        vboxLayout7->addLayout(hboxLayout10);

        tabWidget->addTab(tabPanne, QString());
        tabHistorique = new QWidget();
        tabHistorique->setObjectName("tabHistorique");
        vboxLayout8 = new QVBoxLayout(tabHistorique);
        vboxLayout8->setObjectName("vboxLayout8");
        tableHistorique = new QTableWidget(tabHistorique);
        if (tableHistorique->columnCount() < 6)
            tableHistorique->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(5, __qtablewidgetitem12);
        tableHistorique->setObjectName("tableHistorique");
        tableHistorique->setAlternatingRowColors(true);
        tableHistorique->setSelectionBehavior(QAbstractItemView::SelectRows);

        vboxLayout8->addWidget(tableHistorique);

        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setObjectName("hboxLayout11");
        btnExportHistorique = new QPushButton(tabHistorique);
        btnExportHistorique->setObjectName("btnExportHistorique");
        btnExportHistorique->setMinimumHeight(35);

        hboxLayout11->addWidget(btnExportHistorique);

        spacerItem9 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout11->addItem(spacerItem9);


        vboxLayout8->addLayout(hboxLayout11);

        tabWidget->addTab(tabHistorique, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        vboxLayout9 = new QVBoxLayout(tabStatistiques);
        vboxLayout9->setObjectName("vboxLayout9");
        grpStatsResume = new QGroupBox(tabStatistiques);
        grpStatsResume->setObjectName("grpStatsResume");
        hboxLayout12 = new QHBoxLayout(grpStatsResume);
        hboxLayout12->setObjectName("hboxLayout12");
        groupBox = new QGroupBox(grpStatsResume);
        groupBox->setObjectName("groupBox");
        vboxLayout10 = new QVBoxLayout(groupBox);
        vboxLayout10->setObjectName("vboxLayout10");
        lblStatsTotalMachines = new QLabel(groupBox);
        lblStatsTotalMachines->setObjectName("lblStatsTotalMachines");
        lblStatsTotalMachines->setAlignment(Qt::AlignCenter);
        QFont font1;
        font1.setPointSize(24);
        font1.setBold(true);
        lblStatsTotalMachines->setFont(font1);

        vboxLayout10->addWidget(lblStatsTotalMachines);


        hboxLayout12->addWidget(groupBox);

        groupBox1 = new QGroupBox(grpStatsResume);
        groupBox1->setObjectName("groupBox1");
        vboxLayout11 = new QVBoxLayout(groupBox1);
        vboxLayout11->setObjectName("vboxLayout11");
        lblStatsEnService = new QLabel(groupBox1);
        lblStatsEnService->setObjectName("lblStatsEnService");
        lblStatsEnService->setAlignment(Qt::AlignCenter);
        lblStatsEnService->setFont(font1);

        vboxLayout11->addWidget(lblStatsEnService);


        hboxLayout12->addWidget(groupBox1);

        groupBox2 = new QGroupBox(grpStatsResume);
        groupBox2->setObjectName("groupBox2");
        vboxLayout12 = new QVBoxLayout(groupBox2);
        vboxLayout12->setObjectName("vboxLayout12");
        lblStatsEnPanne = new QLabel(groupBox2);
        lblStatsEnPanne->setObjectName("lblStatsEnPanne");
        lblStatsEnPanne->setAlignment(Qt::AlignCenter);
        lblStatsEnPanne->setFont(font1);

        vboxLayout12->addWidget(lblStatsEnPanne);


        hboxLayout12->addWidget(groupBox2);

        groupBox3 = new QGroupBox(grpStatsResume);
        groupBox3->setObjectName("groupBox3");
        vboxLayout13 = new QVBoxLayout(groupBox3);
        vboxLayout13->setObjectName("vboxLayout13");
        lblStatsMaintenance = new QLabel(groupBox3);
        lblStatsMaintenance->setObjectName("lblStatsMaintenance");
        lblStatsMaintenance->setAlignment(Qt::AlignCenter);
        lblStatsMaintenance->setFont(font1);

        vboxLayout13->addWidget(lblStatsMaintenance);


        hboxLayout12->addWidget(groupBox3);


        vboxLayout9->addWidget(grpStatsResume);

        txtStatistiques = new QTextEdit(tabStatistiques);
        txtStatistiques->setObjectName("txtStatistiques");
        txtStatistiques->setReadOnly(true);

        vboxLayout9->addWidget(txtStatistiques);

        hboxLayout13 = new QHBoxLayout();
        hboxLayout13->setObjectName("hboxLayout13");
        btnExportStats = new QPushButton(tabStatistiques);
        btnExportStats->setObjectName("btnExportStats");
        btnExportStats->setMinimumHeight(35);

        hboxLayout13->addWidget(btnExportStats);

        spacerItem10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout13->addItem(spacerItem10);


        vboxLayout9->addLayout(hboxLayout13);

        tabWidget->addTab(tabStatistiques, QString());

        centerLayout->addWidget(tabWidget);

        splitter->addWidget(centerPanel);

        machineLayout->addWidget(splitter);


        retranslateUi(MachineWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MachineWidget);
    } // setupUi

    void retranslateUi(QWidget *MachineWidget)
    {
        MachineWidget->setWindowTitle(QCoreApplication::translate("MachineWidget", "Gestion Machines", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MachineWidget", "\360\237\224\215 Recherche et Filtres", nullptr));
        label->setText(QCoreApplication::translate("MachineWidget", "Rechercher :", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("MachineWidget", "Nom, r\303\251f\303\251rence\342\200\246", nullptr));
        label1->setText(QCoreApplication::translate("MachineWidget", "Cat\303\251gorie :", nullptr));
        comboCategory->setItemText(0, QCoreApplication::translate("MachineWidget", "Toutes", nullptr));
        comboCategory->setItemText(1, QCoreApplication::translate("MachineWidget", "Presse", nullptr));
        comboCategory->setItemText(2, QCoreApplication::translate("MachineWidget", "Moteur", nullptr));
        comboCategory->setItemText(3, QCoreApplication::translate("MachineWidget", "Filtre", nullptr));
        comboCategory->setItemText(4, QCoreApplication::translate("MachineWidget", "Capteur", nullptr));
        comboCategory->setItemText(5, QCoreApplication::translate("MachineWidget", "Autre", nullptr));

        label2->setText(QCoreApplication::translate("MachineWidget", "\303\211tat :", nullptr));
        comboState->setItemText(0, QCoreApplication::translate("MachineWidget", "Tous", nullptr));
        comboState->setItemText(1, QCoreApplication::translate("MachineWidget", "En service", nullptr));
        comboState->setItemText(2, QCoreApplication::translate("MachineWidget", "Panne", nullptr));
        comboState->setItemText(3, QCoreApplication::translate("MachineWidget", "Maintenance", nullptr));
        comboState->setItemText(4, QCoreApplication::translate("MachineWidget", "Hors service", nullptr));

        label3->setText(QCoreApplication::translate("MachineWidget", "Localisation :", nullptr));
        lineEditLocation->setPlaceholderText(QCoreApplication::translate("MachineWidget", "Atelier, Ligne\342\200\246", nullptr));
        btnApplyFilter->setText(QCoreApplication::translate("MachineWidget", "\342\234\205 Appliquer", nullptr));
        groupBoxSort->setTitle(QCoreApplication::translate("MachineWidget", "\360\237\223\212 Tri", nullptr));
        label4->setText(QCoreApplication::translate("MachineWidget", "Trier par :", nullptr));
        comboSortBy->setItemText(0, QCoreApplication::translate("MachineWidget", "Nom", nullptr));
        comboSortBy->setItemText(1, QCoreApplication::translate("MachineWidget", "Date d'achat", nullptr));
        comboSortBy->setItemText(2, QCoreApplication::translate("MachineWidget", "\303\211tat", nullptr));
        comboSortBy->setItemText(3, QCoreApplication::translate("MachineWidget", "Cat\303\251gorie", nullptr));
        comboSortBy->setItemText(4, QCoreApplication::translate("MachineWidget", "Localisation", nullptr));

        radioCroissant->setText(QCoreApplication::translate("MachineWidget", "\342\254\206\357\270\217 Croissant", nullptr));
        radioDecroissant->setText(QCoreApplication::translate("MachineWidget", "\342\254\207\357\270\217 D\303\251croissant", nullptr));
        btnScanQR->setText(QCoreApplication::translate("MachineWidget", "\360\237\223\267 Scanner QR Code", nullptr));
        labelAdd->setText(QCoreApplication::translate("MachineWidget", "<h2>Ajouter une nouvelle machine</h2>", nullptr));
        label5->setText(QCoreApplication::translate("MachineWidget", "ID Machine *", nullptr));
        editAddId->setPlaceholderText(QCoreApplication::translate("MachineWidget", "MCH-XXX", nullptr));
        label6->setText(QCoreApplication::translate("MachineWidget", "Nom *", nullptr));
        editAddNom->setPlaceholderText(QCoreApplication::translate("MachineWidget", "Nom de la machine", nullptr));
        label7->setText(QCoreApplication::translate("MachineWidget", "Cat\303\251gorie *", nullptr));
        comboAddCategorie->setItemText(0, QCoreApplication::translate("MachineWidget", "Presse", nullptr));
        comboAddCategorie->setItemText(1, QCoreApplication::translate("MachineWidget", "Moteur", nullptr));
        comboAddCategorie->setItemText(2, QCoreApplication::translate("MachineWidget", "Filtre", nullptr));
        comboAddCategorie->setItemText(3, QCoreApplication::translate("MachineWidget", "Capteur", nullptr));
        comboAddCategorie->setItemText(4, QCoreApplication::translate("MachineWidget", "Autre", nullptr));

        label8->setText(QCoreApplication::translate("MachineWidget", "R\303\251f\303\251rence", nullptr));
        editAddReference->setPlaceholderText(QCoreApplication::translate("MachineWidget", "R\303\251f\303\251rence", nullptr));
        label9->setText(QCoreApplication::translate("MachineWidget", "Date d'achat", nullptr));
        label10->setText(QCoreApplication::translate("MachineWidget", "\303\211tat *", nullptr));
        comboAddEtat->setItemText(0, QCoreApplication::translate("MachineWidget", "En service", nullptr));
        comboAddEtat->setItemText(1, QCoreApplication::translate("MachineWidget", "Maintenance", nullptr));
        comboAddEtat->setItemText(2, QCoreApplication::translate("MachineWidget", "Panne", nullptr));
        comboAddEtat->setItemText(3, QCoreApplication::translate("MachineWidget", "Hors service", nullptr));

        label11->setText(QCoreApplication::translate("MachineWidget", "Localisation", nullptr));
        editAddLocalisation->setPlaceholderText(QCoreApplication::translate("MachineWidget", "Atelier, Ligne...", nullptr));
        btnConfirmerAjouter->setText(QCoreApplication::translate("MachineWidget", "\342\234\223 Confirmer l'ajout", nullptr));
        btnConfirmerAjouter->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #6FA66F; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerAjouter->setText(QCoreApplication::translate("MachineWidget", "\342\234\227 Annuler", nullptr));
        btnAnnulerAjouter->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("MachineWidget", "Ajouter Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableMachines->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MachineWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableMachines->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MachineWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableMachines->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MachineWidget", "Cat\303\251gorie", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableMachines->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MachineWidget", "R\303\251f\303\251rence", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableMachines->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MachineWidget", "Date Achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableMachines->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MachineWidget", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableMachines->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MachineWidget", "Localisation", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MachineWidget", "\360\237\223\204 Exporter PDF", nullptr));
        btnRefresh->setText(QCoreApplication::translate("MachineWidget", "\360\237\224\204 Actualiser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("MachineWidget", "Liste des Machines", nullptr));
        label12->setText(QCoreApplication::translate("MachineWidget", "\342\232\240\357\270\217 S\303\251lectionnez une machine dans \"Liste des Machines\", puis confirmez la suppression. Cette action est irr\303\251versible.", nullptr));
        label12->setStyleSheet(QCoreApplication::translate("MachineWidget", "QLabel { background-color: #FDECEA; color: #C62828; border-radius: 4px; padding: 10px; }", nullptr));
        grpMachineASupprimer->setTitle(QCoreApplication::translate("MachineWidget", "Machine S\303\251lectionn\303\251e", nullptr));
        lblSupprimerNom->setText(QCoreApplication::translate("MachineWidget", "Aucune machine s\303\251lectionn\303\251e", nullptr));
        lblSupprimerDetails->setText(QCoreApplication::translate("MachineWidget", "-", nullptr));
        btnConfirmerSupprimer->setText(QCoreApplication::translate("MachineWidget", "\360\237\227\221 Confirmer la suppression", nullptr));
        btnConfirmerSupprimer->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #C97A7A; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerSupprimer->setText(QCoreApplication::translate("MachineWidget", "\342\234\227 Annuler", nullptr));
        btnAnnulerSupprimer->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("MachineWidget", "Supprimer Machine", nullptr));
        label13->setText(QCoreApplication::translate("MachineWidget", "\342\204\271\357\270\217 S\303\251lectionnez une machine dans \"Liste des Machines\" puis modifiez ses informations ci-dessous.", nullptr));
        label13->setStyleSheet(QCoreApplication::translate("MachineWidget", "QLabel { background-color: #EAF0EA; color: #3D4F3C; border-radius: 4px; padding: 8px; }", nullptr));
        grpFormModifier->setTitle(QCoreApplication::translate("MachineWidget", "Modifier la Machine S\303\251lectionn\303\251e", nullptr));
        label14->setText(QCoreApplication::translate("MachineWidget", "ID Machine", nullptr));
        label15->setText(QCoreApplication::translate("MachineWidget", "Nom *", nullptr));
        label16->setText(QCoreApplication::translate("MachineWidget", "Cat\303\251gorie *", nullptr));
        comboModifierCategorie->setItemText(0, QCoreApplication::translate("MachineWidget", "Presse", nullptr));
        comboModifierCategorie->setItemText(1, QCoreApplication::translate("MachineWidget", "Moteur", nullptr));
        comboModifierCategorie->setItemText(2, QCoreApplication::translate("MachineWidget", "Filtre", nullptr));
        comboModifierCategorie->setItemText(3, QCoreApplication::translate("MachineWidget", "Capteur", nullptr));
        comboModifierCategorie->setItemText(4, QCoreApplication::translate("MachineWidget", "Autre", nullptr));

        label17->setText(QCoreApplication::translate("MachineWidget", "R\303\251f\303\251rence", nullptr));
        label18->setText(QCoreApplication::translate("MachineWidget", "Date d'achat", nullptr));
        label19->setText(QCoreApplication::translate("MachineWidget", "\303\211tat *", nullptr));
        comboModifierEtat->setItemText(0, QCoreApplication::translate("MachineWidget", "En service", nullptr));
        comboModifierEtat->setItemText(1, QCoreApplication::translate("MachineWidget", "Maintenance", nullptr));
        comboModifierEtat->setItemText(2, QCoreApplication::translate("MachineWidget", "Panne", nullptr));
        comboModifierEtat->setItemText(3, QCoreApplication::translate("MachineWidget", "Hors service", nullptr));

        label20->setText(QCoreApplication::translate("MachineWidget", "Localisation", nullptr));
        btnConfirmerModifier->setText(QCoreApplication::translate("MachineWidget", "\342\234\223 Confirmer la modification", nullptr));
        btnConfirmerModifier->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #D4A520; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerModifier->setText(QCoreApplication::translate("MachineWidget", "\342\234\227 Annuler", nullptr));
        btnAnnulerModifier->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("MachineWidget", "Modifier Machine", nullptr));
        label21->setText(QCoreApplication::translate("MachineWidget", "\360\237\224\247 S\303\251lectionnez une machine et d\303\251crivez la panne constat\303\251e.", nullptr));
        label21->setStyleSheet(QCoreApplication::translate("MachineWidget", "QLabel { background-color: #FFF3E0; color: #E65100; border-radius: 4px; padding: 8px; }", nullptr));
        grpPanne->setTitle(QCoreApplication::translate("MachineWidget", "D\303\251tails de la Panne", nullptr));
        label22->setText(QCoreApplication::translate("MachineWidget", "Machine *", nullptr));
        label23->setText(QCoreApplication::translate("MachineWidget", "Date de panne", nullptr));
        label24->setText(QCoreApplication::translate("MachineWidget", "Type de panne *", nullptr));
        comboTypePanne->setItemText(0, QCoreApplication::translate("MachineWidget", "M\303\251canique", nullptr));
        comboTypePanne->setItemText(1, QCoreApplication::translate("MachineWidget", "\303\211lectrique", nullptr));
        comboTypePanne->setItemText(2, QCoreApplication::translate("MachineWidget", "Hydraulique", nullptr));
        comboTypePanne->setItemText(3, QCoreApplication::translate("MachineWidget", "Logicielle", nullptr));
        comboTypePanne->setItemText(4, QCoreApplication::translate("MachineWidget", "Autre", nullptr));

        label25->setText(QCoreApplication::translate("MachineWidget", "Gravit\303\251 *", nullptr));
        comboGravite->setItemText(0, QCoreApplication::translate("MachineWidget", "Mineure", nullptr));
        comboGravite->setItemText(1, QCoreApplication::translate("MachineWidget", "Moyenne", nullptr));
        comboGravite->setItemText(2, QCoreApplication::translate("MachineWidget", "Majeure", nullptr));
        comboGravite->setItemText(3, QCoreApplication::translate("MachineWidget", "Critique", nullptr));

        label26->setText(QCoreApplication::translate("MachineWidget", "Description", nullptr));
        txtDescriptionPanne->setPlaceholderText(QCoreApplication::translate("MachineWidget", "D\303\251crivez la panne...", nullptr));
        btnSignalerPanne->setText(QCoreApplication::translate("MachineWidget", "\342\232\240\357\270\217 Signaler la panne", nullptr));
        btnSignalerPanne->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #FF8F00; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerPanne->setText(QCoreApplication::translate("MachineWidget", "\342\234\227 Annuler", nullptr));
        btnAnnulerPanne->setStyleSheet(QCoreApplication::translate("MachineWidget", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabPanne), QCoreApplication::translate("MachineWidget", "Signaler Panne", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableHistorique->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MachineWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableHistorique->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MachineWidget", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableHistorique->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MachineWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableHistorique->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MachineWidget", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableHistorique->horizontalHeaderItem(4);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MachineWidget", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableHistorique->horizontalHeaderItem(5);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MachineWidget", "Technicien", nullptr));
        btnExportHistorique->setText(QCoreApplication::translate("MachineWidget", "\360\237\223\204 Exporter Historique", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabHistorique), QCoreApplication::translate("MachineWidget", "Historique Interventions", nullptr));
        grpStatsResume->setTitle(QCoreApplication::translate("MachineWidget", "R\303\251sum\303\251", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MachineWidget", "Total Machines", nullptr));
        lblStatsTotalMachines->setText(QCoreApplication::translate("MachineWidget", "0", nullptr));
        groupBox1->setTitle(QCoreApplication::translate("MachineWidget", "En Service", nullptr));
        lblStatsEnService->setText(QCoreApplication::translate("MachineWidget", "0", nullptr));
        lblStatsEnService->setStyleSheet(QCoreApplication::translate("MachineWidget", "color: #4CAF50;", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("MachineWidget", "En Panne", nullptr));
        lblStatsEnPanne->setText(QCoreApplication::translate("MachineWidget", "0", nullptr));
        lblStatsEnPanne->setStyleSheet(QCoreApplication::translate("MachineWidget", "color: #F44336;", nullptr));
        groupBox3->setTitle(QCoreApplication::translate("MachineWidget", "En Maintenance", nullptr));
        lblStatsMaintenance->setText(QCoreApplication::translate("MachineWidget", "0", nullptr));
        lblStatsMaintenance->setStyleSheet(QCoreApplication::translate("MachineWidget", "color: #FF9800;", nullptr));
        btnExportStats->setText(QCoreApplication::translate("MachineWidget", "\360\237\223\212 Exporter Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("MachineWidget", "\360\237\223\212 Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MachineWidget: public Ui_MachineWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MACHINE_WIDGET_H
