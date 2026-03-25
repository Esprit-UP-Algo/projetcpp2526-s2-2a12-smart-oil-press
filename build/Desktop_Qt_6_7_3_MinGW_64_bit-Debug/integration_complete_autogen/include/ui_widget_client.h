/********************************************************************************
** Form generated from reading UI file 'widget_client.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_CLIENT_H
#define UI_WIDGET_CLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WidgetClient
{
public:
    QVBoxLayout *rootLayout;
    QVBoxLayout *mainContentLayout;
    QHBoxLayout *contentLayout;
    QGroupBox *grpRechercheFiltre;
    QVBoxLayout *verticalLayout_sidebar;
    QFormLayout *formLayoutTop;
    QLabel *lblNom;
    QLineEdit *txtRechercheNom;
    QSpacerItem *verticalSpacer;
    QGroupBox *grpFiltres;
    QFormLayout *formLayoutBottom;
    QLabel *lblType;
    QComboBox *cmbType;
    QLabel *lblStatut;
    QComboBox *cmbStatut;
    QPushButton *btnAppliquerFiltre;
    QVBoxLayout *centerLayout;
    QTabWidget *tabWidget;
    QWidget *tabAjouter;
    QVBoxLayout *vlAjouter;
    QGroupBox *grpFormAjouter;
    QFormLayout *formAjouter;
    QLabel *label;
    QLineEdit *txtAjouterNom;
    QLabel *label1;
    QComboBox *cmbAjouterType;
    QLabel *label2;
    QLineEdit *txtAjouterTel;
    QLabel *label3;
    QLineEdit *txtAjouterEmail;
    QLabel *label4;
    QComboBox *cmbAjouterStatut;
    QSpacerItem *spacerItem;
    QHBoxLayout *hboxLayout;
    QSpacerItem *spacerItem1;
    QPushButton *btnConfirmerAjouter;
    QPushButton *btnAnnulerAjouter;
    QWidget *tabListeClients;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableClients;
    QWidget *tabSupprimer;
    QVBoxLayout *vlSupprimer;
    QLabel *lblSupprimerInfo;
    QGroupBox *grpClientASupprimer;
    QVBoxLayout *vboxLayout;
    QLabel *lblSupprimerNom;
    QLabel *lblSupprimerDetails;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem3;
    QPushButton *btnConfirmerSupprimer;
    QPushButton *btnAnnulerSupprimer;
    QWidget *tabModifier;
    QVBoxLayout *vlModifier;
    QLabel *lblModifierInfo;
    QGroupBox *grpFormModifier;
    QFormLayout *formModifier;
    QLabel *label5;
    QLineEdit *txtModifierNom;
    QLabel *label6;
    QComboBox *cmbModifierType;
    QLabel *label7;
    QLineEdit *txtModifierTel;
    QLabel *label8;
    QLineEdit *txtModifierEmail;
    QLabel *label9;
    QComboBox *cmbModifierStatut;
    QSpacerItem *spacerItem4;
    QHBoxLayout *hboxLayout2;
    QSpacerItem *spacerItem5;
    QPushButton *btnConfirmerModifier;
    QPushButton *btnAnnulerModifier;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *txtStatistiques;
    QWidget *tabAlertes;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *txtAlertes;
    QWidget *tabInfosClient;
    QVBoxLayout *verticalLayout_infos;
    QGroupBox *grpClientDetails;
    QVBoxLayout *verticalLayout_details;
    QHBoxLayout *horizontalLayout_row1;
    QGroupBox *grpInfoGenerales;
    QVBoxLayout *verticalLayout_general;
    QLabel *lblInfoStatut;
    QLabel *lblInfoAlertes;
    QGroupBox *grpRetards;
    QVBoxLayout *verticalLayout_retards;
    QLabel *lblRetardsNombre;
    QLabel *lblRetardsMoyen;
    QLabel *lblRetardsTotal;
    QHBoxLayout *horizontalLayout_row2;
    QGroupBox *grpRetoursQualite;
    QVBoxLayout *verticalLayout_retours;
    QLabel *lblRetoursNombre;
    QLabel *lblRetoursTaux;
    QLabel *lblRetoursDernier;
    QGroupBox *grpPrix;
    QVBoxLayout *verticalLayout_prix;
    QLabel *lblPrixMoyen;
    QLabel *lblPrixTotal;
    QLabel *lblPrixRemise;
    QGroupBox *grpHistorique;
    QHBoxLayout *horizontalLayout_historique;
    QLabel *lblClientDepuis;
    QLabel *lblNombreCommandes;
    QLabel *lblDerniereCommande;
    QSpacerItem *verticalSpacer_info;
    QWidget *tabExportPDF;
    QVBoxLayout *verticalLayout_export;
    QGroupBox *grpExportOptions;
    QVBoxLayout *vExportOptions;
    QPushButton *btnExportListeClients;
    QPushButton *btnExportStatistiques;
    QPushButton *btnExportFicheClient;
    QGroupBox *grpParamsExport;
    QFormLayout *formParamsExport;
    QLabel *lblIdClient;
    QLineEdit *lineEdit_id_export;
    QGroupBox *grpMessagesExport;
    QVBoxLayout *vMessagesExport;
    QTextEdit *textEdit_export_messages;
    QSpacerItem *verticalSpacer_export;

    void setupUi(QWidget *WidgetClient)
    {
        if (WidgetClient->objectName().isEmpty())
            WidgetClient->setObjectName("WidgetClient");
        WidgetClient->resize(1000, 700);
        rootLayout = new QVBoxLayout(WidgetClient);
        rootLayout->setSpacing(0);
        rootLayout->setObjectName("rootLayout");
        rootLayout->setContentsMargins(0, 0, 0, 0);
        mainContentLayout = new QVBoxLayout();
        mainContentLayout->setObjectName("mainContentLayout");
        mainContentLayout->setContentsMargins(10, 10, 10, 10);
        contentLayout = new QHBoxLayout();
        contentLayout->setObjectName("contentLayout");
        grpRechercheFiltre = new QGroupBox(WidgetClient);
        grpRechercheFiltre->setObjectName("grpRechercheFiltre");
        grpRechercheFiltre->setMinimumWidth(220);
        grpRechercheFiltre->setMaximumWidth(220);
        verticalLayout_sidebar = new QVBoxLayout(grpRechercheFiltre);
        verticalLayout_sidebar->setObjectName("verticalLayout_sidebar");
        formLayoutTop = new QFormLayout();
        formLayoutTop->setObjectName("formLayoutTop");
        lblNom = new QLabel(grpRechercheFiltre);
        lblNom->setObjectName("lblNom");

        formLayoutTop->setWidget(0, QFormLayout::LabelRole, lblNom);

        txtRechercheNom = new QLineEdit(grpRechercheFiltre);
        txtRechercheNom->setObjectName("txtRechercheNom");

        formLayoutTop->setWidget(0, QFormLayout::FieldRole, txtRechercheNom);


        verticalLayout_sidebar->addLayout(formLayoutTop);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_sidebar->addItem(verticalSpacer);

        grpFiltres = new QGroupBox(grpRechercheFiltre);
        grpFiltres->setObjectName("grpFiltres");
        formLayoutBottom = new QFormLayout(grpFiltres);
        formLayoutBottom->setObjectName("formLayoutBottom");
        lblType = new QLabel(grpFiltres);
        lblType->setObjectName("lblType");

        formLayoutBottom->setWidget(0, QFormLayout::LabelRole, lblType);

        cmbType = new QComboBox(grpFiltres);
        cmbType->setObjectName("cmbType");

        formLayoutBottom->setWidget(0, QFormLayout::FieldRole, cmbType);

        lblStatut = new QLabel(grpFiltres);
        lblStatut->setObjectName("lblStatut");

        formLayoutBottom->setWidget(1, QFormLayout::LabelRole, lblStatut);

        cmbStatut = new QComboBox(grpFiltres);
        cmbStatut->setObjectName("cmbStatut");

        formLayoutBottom->setWidget(1, QFormLayout::FieldRole, cmbStatut);

        btnAppliquerFiltre = new QPushButton(grpFiltres);
        btnAppliquerFiltre->setObjectName("btnAppliquerFiltre");

        formLayoutBottom->setWidget(2, QFormLayout::FieldRole, btnAppliquerFiltre);


        verticalLayout_sidebar->addWidget(grpFiltres);


        contentLayout->addWidget(grpRechercheFiltre);

        centerLayout = new QVBoxLayout();
        centerLayout->setObjectName("centerLayout");
        tabWidget = new QTabWidget(WidgetClient);
        tabWidget->setObjectName("tabWidget");
        tabAjouter = new QWidget();
        tabAjouter->setObjectName("tabAjouter");
        vlAjouter = new QVBoxLayout(tabAjouter);
        vlAjouter->setObjectName("vlAjouter");
        vlAjouter->setContentsMargins(20, 20, 20, 20);
        grpFormAjouter = new QGroupBox(tabAjouter);
        grpFormAjouter->setObjectName("grpFormAjouter");
        formAjouter = new QFormLayout(grpFormAjouter);
        formAjouter->setObjectName("formAjouter");
        formAjouter->setHorizontalSpacing(20);
        formAjouter->setVerticalSpacing(14);
        label = new QLabel(grpFormAjouter);
        label->setObjectName("label");

        formAjouter->setWidget(0, QFormLayout::LabelRole, label);

        txtAjouterNom = new QLineEdit(grpFormAjouter);
        txtAjouterNom->setObjectName("txtAjouterNom");

        formAjouter->setWidget(0, QFormLayout::FieldRole, txtAjouterNom);

        label1 = new QLabel(grpFormAjouter);
        label1->setObjectName("label1");

        formAjouter->setWidget(1, QFormLayout::LabelRole, label1);

        cmbAjouterType = new QComboBox(grpFormAjouter);
        cmbAjouterType->setObjectName("cmbAjouterType");

        formAjouter->setWidget(1, QFormLayout::FieldRole, cmbAjouterType);

        label2 = new QLabel(grpFormAjouter);
        label2->setObjectName("label2");

        formAjouter->setWidget(2, QFormLayout::LabelRole, label2);

        txtAjouterTel = new QLineEdit(grpFormAjouter);
        txtAjouterTel->setObjectName("txtAjouterTel");

        formAjouter->setWidget(2, QFormLayout::FieldRole, txtAjouterTel);

        label3 = new QLabel(grpFormAjouter);
        label3->setObjectName("label3");

        formAjouter->setWidget(3, QFormLayout::LabelRole, label3);

        txtAjouterEmail = new QLineEdit(grpFormAjouter);
        txtAjouterEmail->setObjectName("txtAjouterEmail");

        formAjouter->setWidget(3, QFormLayout::FieldRole, txtAjouterEmail);

        label4 = new QLabel(grpFormAjouter);
        label4->setObjectName("label4");

        formAjouter->setWidget(4, QFormLayout::LabelRole, label4);

        cmbAjouterStatut = new QComboBox(grpFormAjouter);
        cmbAjouterStatut->setObjectName("cmbAjouterStatut");

        formAjouter->setWidget(4, QFormLayout::FieldRole, cmbAjouterStatut);


        vlAjouter->addWidget(grpFormAjouter);

        spacerItem = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlAjouter->addItem(spacerItem);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        spacerItem1 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout->addItem(spacerItem1);

        btnConfirmerAjouter = new QPushButton(tabAjouter);
        btnConfirmerAjouter->setObjectName("btnConfirmerAjouter");
        btnConfirmerAjouter->setMinimumHeight(48);
        btnConfirmerAjouter->setMinimumWidth(220);

        hboxLayout->addWidget(btnConfirmerAjouter);

        btnAnnulerAjouter = new QPushButton(tabAjouter);
        btnAnnulerAjouter->setObjectName("btnAnnulerAjouter");
        btnAnnulerAjouter->setMinimumHeight(48);
        btnAnnulerAjouter->setMinimumWidth(160);

        hboxLayout->addWidget(btnAnnulerAjouter);


        vlAjouter->addLayout(hboxLayout);

        tabWidget->addTab(tabAjouter, QString());
        tabListeClients = new QWidget();
        tabListeClients->setObjectName("tabListeClients");
        verticalLayout_3 = new QVBoxLayout(tabListeClients);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tableClients = new QTableWidget(tabListeClients);
        tableClients->setObjectName("tableClients");
        tableClients->setAlternatingRowColors(true);
        tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(tableClients);

        tabWidget->addTab(tabListeClients, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        vlSupprimer = new QVBoxLayout(tabSupprimer);
        vlSupprimer->setObjectName("vlSupprimer");
        vlSupprimer->setContentsMargins(20, 20, 20, 20);
        lblSupprimerInfo = new QLabel(tabSupprimer);
        lblSupprimerInfo->setObjectName("lblSupprimerInfo");
        lblSupprimerInfo->setWordWrap(true);

        vlSupprimer->addWidget(lblSupprimerInfo);

        grpClientASupprimer = new QGroupBox(tabSupprimer);
        grpClientASupprimer->setObjectName("grpClientASupprimer");
        vboxLayout = new QVBoxLayout(grpClientASupprimer);
        vboxLayout->setObjectName("vboxLayout");
        lblSupprimerNom = new QLabel(grpClientASupprimer);
        lblSupprimerNom->setObjectName("lblSupprimerNom");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        lblSupprimerNom->setFont(font);

        vboxLayout->addWidget(lblSupprimerNom);

        lblSupprimerDetails = new QLabel(grpClientASupprimer);
        lblSupprimerDetails->setObjectName("lblSupprimerDetails");

        vboxLayout->addWidget(lblSupprimerDetails);


        vlSupprimer->addWidget(grpClientASupprimer);

        spacerItem2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlSupprimer->addItem(spacerItem2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout1->addItem(spacerItem3);

        btnConfirmerSupprimer = new QPushButton(tabSupprimer);
        btnConfirmerSupprimer->setObjectName("btnConfirmerSupprimer");
        btnConfirmerSupprimer->setMinimumHeight(48);
        btnConfirmerSupprimer->setMinimumWidth(260);

        hboxLayout1->addWidget(btnConfirmerSupprimer);

        btnAnnulerSupprimer = new QPushButton(tabSupprimer);
        btnAnnulerSupprimer->setObjectName("btnAnnulerSupprimer");
        btnAnnulerSupprimer->setMinimumHeight(48);
        btnAnnulerSupprimer->setMinimumWidth(160);

        hboxLayout1->addWidget(btnAnnulerSupprimer);


        vlSupprimer->addLayout(hboxLayout1);

        tabWidget->addTab(tabSupprimer, QString());
        tabModifier = new QWidget();
        tabModifier->setObjectName("tabModifier");
        vlModifier = new QVBoxLayout(tabModifier);
        vlModifier->setObjectName("vlModifier");
        vlModifier->setContentsMargins(20, 20, 20, 20);
        lblModifierInfo = new QLabel(tabModifier);
        lblModifierInfo->setObjectName("lblModifierInfo");

        vlModifier->addWidget(lblModifierInfo);

        grpFormModifier = new QGroupBox(tabModifier);
        grpFormModifier->setObjectName("grpFormModifier");
        formModifier = new QFormLayout(grpFormModifier);
        formModifier->setObjectName("formModifier");
        formModifier->setHorizontalSpacing(20);
        formModifier->setVerticalSpacing(14);
        label5 = new QLabel(grpFormModifier);
        label5->setObjectName("label5");

        formModifier->setWidget(0, QFormLayout::LabelRole, label5);

        txtModifierNom = new QLineEdit(grpFormModifier);
        txtModifierNom->setObjectName("txtModifierNom");

        formModifier->setWidget(0, QFormLayout::FieldRole, txtModifierNom);

        label6 = new QLabel(grpFormModifier);
        label6->setObjectName("label6");

        formModifier->setWidget(1, QFormLayout::LabelRole, label6);

        cmbModifierType = new QComboBox(grpFormModifier);
        cmbModifierType->setObjectName("cmbModifierType");

        formModifier->setWidget(1, QFormLayout::FieldRole, cmbModifierType);

        label7 = new QLabel(grpFormModifier);
        label7->setObjectName("label7");

        formModifier->setWidget(2, QFormLayout::LabelRole, label7);

        txtModifierTel = new QLineEdit(grpFormModifier);
        txtModifierTel->setObjectName("txtModifierTel");

        formModifier->setWidget(2, QFormLayout::FieldRole, txtModifierTel);

        label8 = new QLabel(grpFormModifier);
        label8->setObjectName("label8");

        formModifier->setWidget(3, QFormLayout::LabelRole, label8);

        txtModifierEmail = new QLineEdit(grpFormModifier);
        txtModifierEmail->setObjectName("txtModifierEmail");

        formModifier->setWidget(3, QFormLayout::FieldRole, txtModifierEmail);

        label9 = new QLabel(grpFormModifier);
        label9->setObjectName("label9");

        formModifier->setWidget(4, QFormLayout::LabelRole, label9);

        cmbModifierStatut = new QComboBox(grpFormModifier);
        cmbModifierStatut->setObjectName("cmbModifierStatut");

        formModifier->setWidget(4, QFormLayout::FieldRole, cmbModifierStatut);


        vlModifier->addWidget(grpFormModifier);

        spacerItem4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlModifier->addItem(spacerItem4);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout2->addItem(spacerItem5);

        btnConfirmerModifier = new QPushButton(tabModifier);
        btnConfirmerModifier->setObjectName("btnConfirmerModifier");
        btnConfirmerModifier->setMinimumHeight(48);
        btnConfirmerModifier->setMinimumWidth(260);

        hboxLayout2->addWidget(btnConfirmerModifier);

        btnAnnulerModifier = new QPushButton(tabModifier);
        btnAnnulerModifier->setObjectName("btnAnnulerModifier");
        btnAnnulerModifier->setMinimumHeight(48);
        btnAnnulerModifier->setMinimumWidth(160);

        hboxLayout2->addWidget(btnAnnulerModifier);


        vlModifier->addLayout(hboxLayout2);

        tabWidget->addTab(tabModifier, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_4 = new QVBoxLayout(tabStatistiques);
        verticalLayout_4->setObjectName("verticalLayout_4");
        txtStatistiques = new QTextEdit(tabStatistiques);
        txtStatistiques->setObjectName("txtStatistiques");
        txtStatistiques->setReadOnly(true);

        verticalLayout_4->addWidget(txtStatistiques);

        tabWidget->addTab(tabStatistiques, QString());
        tabAlertes = new QWidget();
        tabAlertes->setObjectName("tabAlertes");
        verticalLayout_7 = new QVBoxLayout(tabAlertes);
        verticalLayout_7->setObjectName("verticalLayout_7");
        txtAlertes = new QTextEdit(tabAlertes);
        txtAlertes->setObjectName("txtAlertes");
        txtAlertes->setReadOnly(true);

        verticalLayout_7->addWidget(txtAlertes);

        tabWidget->addTab(tabAlertes, QString());
        tabInfosClient = new QWidget();
        tabInfosClient->setObjectName("tabInfosClient");
        verticalLayout_infos = new QVBoxLayout(tabInfosClient);
        verticalLayout_infos->setObjectName("verticalLayout_infos");
        grpClientDetails = new QGroupBox(tabInfosClient);
        grpClientDetails->setObjectName("grpClientDetails");
        verticalLayout_details = new QVBoxLayout(grpClientDetails);
        verticalLayout_details->setObjectName("verticalLayout_details");
        horizontalLayout_row1 = new QHBoxLayout();
        horizontalLayout_row1->setObjectName("horizontalLayout_row1");
        grpInfoGenerales = new QGroupBox(grpClientDetails);
        grpInfoGenerales->setObjectName("grpInfoGenerales");
        verticalLayout_general = new QVBoxLayout(grpInfoGenerales);
        verticalLayout_general->setObjectName("verticalLayout_general");
        lblInfoStatut = new QLabel(grpInfoGenerales);
        lblInfoStatut->setObjectName("lblInfoStatut");
        QFont font1;
        font1.setPointSize(11);
        lblInfoStatut->setFont(font1);

        verticalLayout_general->addWidget(lblInfoStatut);

        lblInfoAlertes = new QLabel(grpInfoGenerales);
        lblInfoAlertes->setObjectName("lblInfoAlertes");
        lblInfoAlertes->setFont(font1);

        verticalLayout_general->addWidget(lblInfoAlertes);


        horizontalLayout_row1->addWidget(grpInfoGenerales);

        grpRetards = new QGroupBox(grpClientDetails);
        grpRetards->setObjectName("grpRetards");
        verticalLayout_retards = new QVBoxLayout(grpRetards);
        verticalLayout_retards->setObjectName("verticalLayout_retards");
        lblRetardsNombre = new QLabel(grpRetards);
        lblRetardsNombre->setObjectName("lblRetardsNombre");
        lblRetardsNombre->setFont(font1);

        verticalLayout_retards->addWidget(lblRetardsNombre);

        lblRetardsMoyen = new QLabel(grpRetards);
        lblRetardsMoyen->setObjectName("lblRetardsMoyen");
        lblRetardsMoyen->setFont(font1);

        verticalLayout_retards->addWidget(lblRetardsMoyen);

        lblRetardsTotal = new QLabel(grpRetards);
        lblRetardsTotal->setObjectName("lblRetardsTotal");
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        lblRetardsTotal->setFont(font2);

        verticalLayout_retards->addWidget(lblRetardsTotal);


        horizontalLayout_row1->addWidget(grpRetards);


        verticalLayout_details->addLayout(horizontalLayout_row1);

        horizontalLayout_row2 = new QHBoxLayout();
        horizontalLayout_row2->setObjectName("horizontalLayout_row2");
        grpRetoursQualite = new QGroupBox(grpClientDetails);
        grpRetoursQualite->setObjectName("grpRetoursQualite");
        verticalLayout_retours = new QVBoxLayout(grpRetoursQualite);
        verticalLayout_retours->setObjectName("verticalLayout_retours");
        lblRetoursNombre = new QLabel(grpRetoursQualite);
        lblRetoursNombre->setObjectName("lblRetoursNombre");
        lblRetoursNombre->setFont(font1);

        verticalLayout_retours->addWidget(lblRetoursNombre);

        lblRetoursTaux = new QLabel(grpRetoursQualite);
        lblRetoursTaux->setObjectName("lblRetoursTaux");
        lblRetoursTaux->setFont(font1);

        verticalLayout_retours->addWidget(lblRetoursTaux);

        lblRetoursDernier = new QLabel(grpRetoursQualite);
        lblRetoursDernier->setObjectName("lblRetoursDernier");
        lblRetoursDernier->setFont(font1);

        verticalLayout_retours->addWidget(lblRetoursDernier);


        horizontalLayout_row2->addWidget(grpRetoursQualite);

        grpPrix = new QGroupBox(grpClientDetails);
        grpPrix->setObjectName("grpPrix");
        verticalLayout_prix = new QVBoxLayout(grpPrix);
        verticalLayout_prix->setObjectName("verticalLayout_prix");
        lblPrixMoyen = new QLabel(grpPrix);
        lblPrixMoyen->setObjectName("lblPrixMoyen");
        lblPrixMoyen->setFont(font1);

        verticalLayout_prix->addWidget(lblPrixMoyen);

        lblPrixTotal = new QLabel(grpPrix);
        lblPrixTotal->setObjectName("lblPrixTotal");
        lblPrixTotal->setFont(font2);

        verticalLayout_prix->addWidget(lblPrixTotal);

        lblPrixRemise = new QLabel(grpPrix);
        lblPrixRemise->setObjectName("lblPrixRemise");
        lblPrixRemise->setFont(font1);

        verticalLayout_prix->addWidget(lblPrixRemise);


        horizontalLayout_row2->addWidget(grpPrix);


        verticalLayout_details->addLayout(horizontalLayout_row2);

        grpHistorique = new QGroupBox(grpClientDetails);
        grpHistorique->setObjectName("grpHistorique");
        horizontalLayout_historique = new QHBoxLayout(grpHistorique);
        horizontalLayout_historique->setObjectName("horizontalLayout_historique");
        lblClientDepuis = new QLabel(grpHistorique);
        lblClientDepuis->setObjectName("lblClientDepuis");
        lblClientDepuis->setFont(font1);

        horizontalLayout_historique->addWidget(lblClientDepuis);

        lblNombreCommandes = new QLabel(grpHistorique);
        lblNombreCommandes->setObjectName("lblNombreCommandes");
        lblNombreCommandes->setFont(font1);

        horizontalLayout_historique->addWidget(lblNombreCommandes);

        lblDerniereCommande = new QLabel(grpHistorique);
        lblDerniereCommande->setObjectName("lblDerniereCommande");
        lblDerniereCommande->setFont(font1);

        horizontalLayout_historique->addWidget(lblDerniereCommande);


        verticalLayout_details->addWidget(grpHistorique);

        verticalSpacer_info = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_details->addItem(verticalSpacer_info);


        verticalLayout_infos->addWidget(grpClientDetails);

        tabWidget->addTab(tabInfosClient, QString());
        tabExportPDF = new QWidget();
        tabExportPDF->setObjectName("tabExportPDF");
        verticalLayout_export = new QVBoxLayout(tabExportPDF);
        verticalLayout_export->setSpacing(12);
        verticalLayout_export->setObjectName("verticalLayout_export");
        verticalLayout_export->setContentsMargins(15, 15, 15, 15);
        grpExportOptions = new QGroupBox(tabExportPDF);
        grpExportOptions->setObjectName("grpExportOptions");
        vExportOptions = new QVBoxLayout(grpExportOptions);
        vExportOptions->setSpacing(10);
        vExportOptions->setObjectName("vExportOptions");
        btnExportListeClients = new QPushButton(grpExportOptions);
        btnExportListeClients->setObjectName("btnExportListeClients");
        btnExportListeClients->setMinimumHeight(58);

        vExportOptions->addWidget(btnExportListeClients);

        btnExportStatistiques = new QPushButton(grpExportOptions);
        btnExportStatistiques->setObjectName("btnExportStatistiques");
        btnExportStatistiques->setMinimumHeight(58);

        vExportOptions->addWidget(btnExportStatistiques);

        btnExportFicheClient = new QPushButton(grpExportOptions);
        btnExportFicheClient->setObjectName("btnExportFicheClient");
        btnExportFicheClient->setMinimumHeight(58);

        vExportOptions->addWidget(btnExportFicheClient);


        verticalLayout_export->addWidget(grpExportOptions);

        grpParamsExport = new QGroupBox(tabExportPDF);
        grpParamsExport->setObjectName("grpParamsExport");
        formParamsExport = new QFormLayout(grpParamsExport);
        formParamsExport->setObjectName("formParamsExport");
        lblIdClient = new QLabel(grpParamsExport);
        lblIdClient->setObjectName("lblIdClient");

        formParamsExport->setWidget(0, QFormLayout::LabelRole, lblIdClient);

        lineEdit_id_export = new QLineEdit(grpParamsExport);
        lineEdit_id_export->setObjectName("lineEdit_id_export");

        formParamsExport->setWidget(0, QFormLayout::FieldRole, lineEdit_id_export);


        verticalLayout_export->addWidget(grpParamsExport);

        grpMessagesExport = new QGroupBox(tabExportPDF);
        grpMessagesExport->setObjectName("grpMessagesExport");
        vMessagesExport = new QVBoxLayout(grpMessagesExport);
        vMessagesExport->setObjectName("vMessagesExport");
        textEdit_export_messages = new QTextEdit(grpMessagesExport);
        textEdit_export_messages->setObjectName("textEdit_export_messages");
        textEdit_export_messages->setReadOnly(true);
        textEdit_export_messages->setMinimumHeight(100);

        vMessagesExport->addWidget(textEdit_export_messages);


        verticalLayout_export->addWidget(grpMessagesExport);

        verticalSpacer_export = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_export->addItem(verticalSpacer_export);

        tabWidget->addTab(tabExportPDF, QString());

        centerLayout->addWidget(tabWidget);


        contentLayout->addLayout(centerLayout);


        mainContentLayout->addLayout(contentLayout);


        rootLayout->addLayout(mainContentLayout);


        retranslateUi(WidgetClient);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WidgetClient);
    } // setupUi

    void retranslateUi(QWidget *WidgetClient)
    {
        grpRechercheFiltre->setTitle(QCoreApplication::translate("WidgetClient", "Recherche", nullptr));
        lblNom->setText(QCoreApplication::translate("WidgetClient", "Nom", nullptr));
        grpFiltres->setTitle(QCoreApplication::translate("WidgetClient", "Tri", nullptr));
        lblType->setText(QCoreApplication::translate("WidgetClient", "Type", nullptr));
        lblStatut->setText(QCoreApplication::translate("WidgetClient", "Statut", nullptr));
        btnAppliquerFiltre->setText(QCoreApplication::translate("WidgetClient", "Appliquer", nullptr));
        grpFormAjouter->setTitle(QCoreApplication::translate("WidgetClient", "Nouveau Client", nullptr));
        label->setText(QCoreApplication::translate("WidgetClient", "Nom *", nullptr));
        txtAjouterNom->setPlaceholderText(QCoreApplication::translate("WidgetClient", "Entrez le nom complet", nullptr));
        label1->setText(QCoreApplication::translate("WidgetClient", "Type *", nullptr));
        label2->setText(QCoreApplication::translate("WidgetClient", "T\303\251l\303\251phone", nullptr));
        txtAjouterTel->setPlaceholderText(QCoreApplication::translate("WidgetClient", "Ex: 98 123 456", nullptr));
        label3->setText(QCoreApplication::translate("WidgetClient", "Email", nullptr));
        txtAjouterEmail->setPlaceholderText(QCoreApplication::translate("WidgetClient", "Ex: client@email.com", nullptr));
        label4->setText(QCoreApplication::translate("WidgetClient", "Statut *", nullptr));
        btnConfirmerAjouter->setText(QCoreApplication::translate("WidgetClient", "\342\234\223  Confirmer l'ajout", nullptr));
        btnConfirmerAjouter->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #6FA66F; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #7CB87C; } QPushButton:pressed { background-color: #5D945D; }", nullptr));
        btnAnnulerAjouter->setText(QCoreApplication::translate("WidgetClient", "\342\234\225  Annuler", nullptr));
        btnAnnulerAjouter->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #A0A0A0; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #B8B8B8; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("WidgetClient", "Ajouter un Client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListeClients), QCoreApplication::translate("WidgetClient", "Liste des Clients", nullptr));
        lblSupprimerInfo->setText(QCoreApplication::translate("WidgetClient", "\342\232\240  S\303\251lectionnez un client dans \"Liste des Clients\", puis confirmez la suppression. Cette action est irr\303\251versible.", nullptr));
        lblSupprimerInfo->setStyleSheet(QCoreApplication::translate("WidgetClient", "QLabel { background-color: #FDECEA; color: #C62828; border-radius: 4px; padding: 10px; font-size: 10pt; }", nullptr));
        grpClientASupprimer->setTitle(QCoreApplication::translate("WidgetClient", "Client S\303\251lectionn\303\251", nullptr));
        lblSupprimerNom->setText(QCoreApplication::translate("WidgetClient", "Aucun client s\303\251lectionn\303\251", nullptr));
        lblSupprimerNom->setStyleSheet(QCoreApplication::translate("WidgetClient", "QLabel { color: #3D4F3C; padding: 6px; }", nullptr));
        lblSupprimerDetails->setText(QCoreApplication::translate("WidgetClient", "-", nullptr));
        lblSupprimerDetails->setStyleSheet(QCoreApplication::translate("WidgetClient", "QLabel { color: #666666; padding: 4px; }", nullptr));
        btnConfirmerSupprimer->setText(QCoreApplication::translate("WidgetClient", "\360\237\227\221  Confirmer la suppression", nullptr));
        btnConfirmerSupprimer->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #C97A7A; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #E08989; } QPushButton:pressed { background-color: #B86B6B; }", nullptr));
        btnAnnulerSupprimer->setText(QCoreApplication::translate("WidgetClient", "\342\234\225  Annuler", nullptr));
        btnAnnulerSupprimer->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #A0A0A0; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #B8B8B8; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("WidgetClient", "Supprimer un Client", nullptr));
        lblModifierInfo->setText(QCoreApplication::translate("WidgetClient", "\342\223\230  S\303\251lectionnez un client dans \"Liste des Clients\" puis modifiez ses informations ci-dessous.", nullptr));
        lblModifierInfo->setStyleSheet(QCoreApplication::translate("WidgetClient", "QLabel { background-color: #EAF0EA; color: #3D4F3C; border-radius: 4px; padding: 8px; font-size: 10pt; }", nullptr));
        grpFormModifier->setTitle(QCoreApplication::translate("WidgetClient", "Modifier le Client S\303\251lectionn\303\251", nullptr));
        label5->setText(QCoreApplication::translate("WidgetClient", "Nom *", nullptr));
        txtModifierNom->setPlaceholderText(QCoreApplication::translate("WidgetClient", "Nom du client", nullptr));
        label6->setText(QCoreApplication::translate("WidgetClient", "Type *", nullptr));
        label7->setText(QCoreApplication::translate("WidgetClient", "T\303\251l\303\251phone", nullptr));
        txtModifierTel->setPlaceholderText(QCoreApplication::translate("WidgetClient", "Ex: 98 123 456", nullptr));
        label8->setText(QCoreApplication::translate("WidgetClient", "Email", nullptr));
        txtModifierEmail->setPlaceholderText(QCoreApplication::translate("WidgetClient", "Ex: client@email.com", nullptr));
        label9->setText(QCoreApplication::translate("WidgetClient", "Statut *", nullptr));
        btnConfirmerModifier->setText(QCoreApplication::translate("WidgetClient", "\342\234\223  Confirmer la modification", nullptr));
        btnConfirmerModifier->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #D4A520; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #E6C36A; } QPushButton:pressed { background-color: #B8901A; }", nullptr));
        btnAnnulerModifier->setText(QCoreApplication::translate("WidgetClient", "\342\234\225  Annuler", nullptr));
        btnAnnulerModifier->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #A0A0A0; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #B8B8B8; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("WidgetClient", "Modifier un Client", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("WidgetClient", "Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAlertes), QCoreApplication::translate("WidgetClient", "Alertes", nullptr));
        grpClientDetails->setTitle(QCoreApplication::translate("WidgetClient", "D\303\251tails du Client S\303\251lectionn\303\251", nullptr));
        grpInfoGenerales->setTitle(QCoreApplication::translate("WidgetClient", "Informations G\303\251n\303\251rales", nullptr));
        lblInfoStatut->setText(QCoreApplication::translate("WidgetClient", "Statut : -", nullptr));
        lblInfoAlertes->setText(QCoreApplication::translate("WidgetClient", "Alertes : -", nullptr));
        grpRetards->setTitle(QCoreApplication::translate("WidgetClient", "Retards de Paiement", nullptr));
        lblRetardsNombre->setText(QCoreApplication::translate("WidgetClient", "Nombre de retards : -", nullptr));
        lblRetardsMoyen->setText(QCoreApplication::translate("WidgetClient", "Retard moyen : - jours", nullptr));
        lblRetardsTotal->setText(QCoreApplication::translate("WidgetClient", "Montant en retard : - DT", nullptr));
        grpRetoursQualite->setTitle(QCoreApplication::translate("WidgetClient", "Retours Qualit\303\251", nullptr));
        lblRetoursNombre->setText(QCoreApplication::translate("WidgetClient", "Nombre de retours : -", nullptr));
        lblRetoursTaux->setText(QCoreApplication::translate("WidgetClient", "Taux de retour : - %", nullptr));
        lblRetoursDernier->setText(QCoreApplication::translate("WidgetClient", "Dernier retour : -", nullptr));
        grpPrix->setTitle(QCoreApplication::translate("WidgetClient", "Prix et Facturation", nullptr));
        lblPrixMoyen->setText(QCoreApplication::translate("WidgetClient", "Prix moyen commande : - DT", nullptr));
        lblPrixTotal->setText(QCoreApplication::translate("WidgetClient", "CA total g\303\251n\303\251r\303\251 : - DT", nullptr));
        lblPrixRemise->setText(QCoreApplication::translate("WidgetClient", "Remise accord\303\251e : - %", nullptr));
        grpHistorique->setTitle(QCoreApplication::translate("WidgetClient", "Historique et Statistiques", nullptr));
        lblClientDepuis->setText(QCoreApplication::translate("WidgetClient", "Client depuis : -", nullptr));
        lblNombreCommandes->setText(QCoreApplication::translate("WidgetClient", "Nombre de commandes : -", nullptr));
        lblDerniereCommande->setText(QCoreApplication::translate("WidgetClient", "Derni\303\250re commande : -", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInfosClient), QCoreApplication::translate("WidgetClient", "Infos Client", nullptr));
        grpExportOptions->setTitle(QCoreApplication::translate("WidgetClient", "Options d'export", nullptr));
        btnExportListeClients->setText(QCoreApplication::translate("WidgetClient", "\360\237\223\204  Exporter la liste compl\303\250te des clients (PDF)", nullptr));
        btnExportListeClients->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #7A9E7E; color: #FFFFFF; border: none; border-radius: 5px; font-size: 13pt; font-weight: bold; text-align: center; }\n"
"QPushButton:hover { background-color: #8FB594; }\n"
"QPushButton:pressed { background-color: #6B8C6F; }", nullptr));
        btnExportStatistiques->setText(QCoreApplication::translate("WidgetClient", "\360\237\223\212  Exporter un rapport statistiques clients (PDF)", nullptr));
        btnExportStatistiques->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #7A9E7E; color: #FFFFFF; border: none; border-radius: 5px; font-size: 13pt; font-weight: bold; text-align: center; }\n"
"QPushButton:hover { background-color: #8FB594; }\n"
"QPushButton:pressed { background-color: #6B8C6F; }", nullptr));
        btnExportFicheClient->setText(QCoreApplication::translate("WidgetClient", "\360\237\223\213  Exporter la fiche d'un client par ID (PDF)", nullptr));
        btnExportFicheClient->setStyleSheet(QCoreApplication::translate("WidgetClient", "QPushButton { background-color: #7A9E7E; color: #FFFFFF; border: none; border-radius: 5px; font-size: 13pt; font-weight: bold; text-align: center; }\n"
"QPushButton:hover { background-color: #8FB594; }\n"
"QPushButton:pressed { background-color: #6B8C6F; }", nullptr));
        grpParamsExport->setTitle(QCoreApplication::translate("WidgetClient", "Param\303\250tres d'export", nullptr));
        lblIdClient->setText(QCoreApplication::translate("WidgetClient", "ID Client (pour la fiche)", nullptr));
        grpMessagesExport->setTitle(QCoreApplication::translate("WidgetClient", "Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExportPDF), QCoreApplication::translate("WidgetClient", "Export PDF", nullptr));
        (void)WidgetClient;
    } // retranslateUi

};

namespace Ui {
    class WidgetClient: public Ui_WidgetClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_CLIENT_H
