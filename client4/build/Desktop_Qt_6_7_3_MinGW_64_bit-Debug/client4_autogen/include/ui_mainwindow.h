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
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QFrame *sidebarFrame;
    QVBoxLayout *verticalLayout;
    QLabel *lblLogo;
    QPushButton *btnEmploye;
    QPushButton *btnEquipe;
    QPushButton *btnClient;
    QPushButton *btnLaboratoire;
    QPushButton *btnCommande;
    QPushButton *btnMachine;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *mainContentLayout;
    QHBoxLayout *contentLayout;
    QGroupBox *grpRechercheFiltre;
    QFormLayout *formLayout;
    QLabel *lblNom;
    QLineEdit *txtRechercheNom;
    QLabel *lblType;
    QComboBox *cmbType;
    QLabel *lblStatut;
    QComboBox *cmbStatut;
    QPushButton *btnAppliquerFiltre;
    QTabWidget *tabWidget;
    QWidget *tabListeClients;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableClients;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *txtStatistiques;
    QWidget *tabAlertes;
    QVBoxLayout *verticalLayout_7;
    QTextEdit *txtAlertes;
    QVBoxLayout *rightPanelLayout;
    QGroupBox *grpActionsRapides;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnActionAjouter;
    QPushButton *btnActionModifier;
    QPushButton *btnActionSupprimer;
    QGroupBox *grpInfosClient;
    QVBoxLayout *verticalLayout_6;
    QLabel *lblInfoStatut;
    QLabel *lblInfoScore;
    QLabel *lblInfoAlertes;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1400, 800);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow { background:#F8EDE3; }\n"
"    QPushButton {\n"
"      background:#A2B29F;\n"
"      border-radius:6px;\n"
"      padding:6px;\n"
"      font-weight:bold;\n"
"      color:#2E2E2E;\n"
"    }\n"
"    QPushButton:hover { background:#798777; color:white; }\n"
"    QGroupBox {\n"
"      background:#BDD2B6;\n"
"      border-radius:8px;\n"
"      margin-top:8px;\n"
"    }\n"
"    QGroupBox::title {\n"
"      subcontrol-origin: margin;\n"
"      left:10px;\n"
"      padding:0 5px;\n"
"      font-weight:bold;\n"
"    }\n"
"    QTabBar::tab {\n"
"      background:#C8E6C9;\n"
"      padding:8px;\n"
"      border-top-left-radius:6px;\n"
"      border-top-right-radius:6px;\n"
"      color:#2E2E2E;\n"
"    }\n"
"    QTabBar::tab:selected {\n"
"      background:#A5D6A7;\n"
"      color:#1B5E20;\n"
"      font-weight:bold;\n"
"    }\n"
"    QTabWidget::pane {\n"
"      background:white;\n"
"      border: 1px solid #A5D6A7;\n"
"      border-radius:4px;\n"
"    }\n"
"    QTableWidget {\n"
"      background"
                        "-color:white;\n"
"      border: 1px solid #E0E0E0;\n"
"      gridline-color:#E0E0E0;\n"
"    }\n"
"    QTextEdit {\n"
"      background-color:white;\n"
"      border: 1px solid #E0E0E0;\n"
"      border-radius:4px;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName("horizontalLayout");
        sidebarFrame = new QFrame(centralwidget);
        sidebarFrame->setObjectName("sidebarFrame");
        sidebarFrame->setMaximumWidth(200);
        sidebarFrame->setStyleSheet(QString::fromUtf8("background:#A2B29F;"));
        verticalLayout = new QVBoxLayout(sidebarFrame);
        verticalLayout->setObjectName("verticalLayout");
        lblLogo = new QLabel(sidebarFrame);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setPixmap(QPixmap(QString::fromUtf8(":/logo_oil_press.png")));
        lblLogo->setScaledContents(true);
        lblLogo->setAlignment(Qt::AlignCenter);
        lblLogo->setMinimumSize(QSize(150, 150));
        lblLogo->setMaximumSize(QSize(180, 180));

        verticalLayout->addWidget(lblLogo);

        btnEmploye = new QPushButton(sidebarFrame);
        btnEmploye->setObjectName("btnEmploye");

        verticalLayout->addWidget(btnEmploye);

        btnEquipe = new QPushButton(sidebarFrame);
        btnEquipe->setObjectName("btnEquipe");

        verticalLayout->addWidget(btnEquipe);

        btnClient = new QPushButton(sidebarFrame);
        btnClient->setObjectName("btnClient");

        verticalLayout->addWidget(btnClient);

        btnLaboratoire = new QPushButton(sidebarFrame);
        btnLaboratoire->setObjectName("btnLaboratoire");

        verticalLayout->addWidget(btnLaboratoire);

        btnCommande = new QPushButton(sidebarFrame);
        btnCommande->setObjectName("btnCommande");

        verticalLayout->addWidget(btnCommande);

        btnMachine = new QPushButton(sidebarFrame);
        btnMachine->setObjectName("btnMachine");

        verticalLayout->addWidget(btnMachine);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addWidget(sidebarFrame);

        mainContentLayout = new QVBoxLayout();
        mainContentLayout->setObjectName("mainContentLayout");
        contentLayout = new QHBoxLayout();
        contentLayout->setObjectName("contentLayout");
        grpRechercheFiltre = new QGroupBox(centralwidget);
        grpRechercheFiltre->setObjectName("grpRechercheFiltre");
        grpRechercheFiltre->setMaximumWidth(250);
        formLayout = new QFormLayout(grpRechercheFiltre);
        formLayout->setObjectName("formLayout");
        lblNom = new QLabel(grpRechercheFiltre);
        lblNom->setObjectName("lblNom");

        formLayout->setWidget(0, QFormLayout::LabelRole, lblNom);

        txtRechercheNom = new QLineEdit(grpRechercheFiltre);
        txtRechercheNom->setObjectName("txtRechercheNom");

        formLayout->setWidget(0, QFormLayout::FieldRole, txtRechercheNom);

        lblType = new QLabel(grpRechercheFiltre);
        lblType->setObjectName("lblType");

        formLayout->setWidget(1, QFormLayout::LabelRole, lblType);

        cmbType = new QComboBox(grpRechercheFiltre);
        cmbType->setObjectName("cmbType");

        formLayout->setWidget(1, QFormLayout::FieldRole, cmbType);

        lblStatut = new QLabel(grpRechercheFiltre);
        lblStatut->setObjectName("lblStatut");

        formLayout->setWidget(2, QFormLayout::LabelRole, lblStatut);

        cmbStatut = new QComboBox(grpRechercheFiltre);
        cmbStatut->setObjectName("cmbStatut");

        formLayout->setWidget(2, QFormLayout::FieldRole, cmbStatut);

        btnAppliquerFiltre = new QPushButton(grpRechercheFiltre);
        btnAppliquerFiltre->setObjectName("btnAppliquerFiltre");

        formLayout->setWidget(3, QFormLayout::FieldRole, btnAppliquerFiltre);


        contentLayout->addWidget(grpRechercheFiltre);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { background: white; border: 1px solid #A5D6A7; }"));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setUsesScrollButtons(true);
        tabListeClients = new QWidget();
        tabListeClients->setObjectName("tabListeClients");
        verticalLayout_3 = new QVBoxLayout(tabListeClients);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        tableClients = new QTableWidget(tabListeClients);
        tableClients->setObjectName("tableClients");
        tableClients->setAlternatingRowColors(true);
        tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableClients->setStyleSheet(QString::fromUtf8("QTableWidget { background-color: white; }"));

        verticalLayout_3->addWidget(tableClients);

        tabWidget->addTab(tabListeClients, QString());
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

        contentLayout->addWidget(tabWidget);

        rightPanelLayout = new QVBoxLayout();
        rightPanelLayout->setObjectName("rightPanelLayout");
        grpActionsRapides = new QGroupBox(centralwidget);
        grpActionsRapides->setObjectName("grpActionsRapides");
        grpActionsRapides->setMaximumWidth(180);
        verticalLayout_5 = new QVBoxLayout(grpActionsRapides);
        verticalLayout_5->setObjectName("verticalLayout_5");
        btnActionAjouter = new QPushButton(grpActionsRapides);
        btnActionAjouter->setObjectName("btnActionAjouter");

        verticalLayout_5->addWidget(btnActionAjouter);

        btnActionModifier = new QPushButton(grpActionsRapides);
        btnActionModifier->setObjectName("btnActionModifier");

        verticalLayout_5->addWidget(btnActionModifier);

        btnActionSupprimer = new QPushButton(grpActionsRapides);
        btnActionSupprimer->setObjectName("btnActionSupprimer");

        verticalLayout_5->addWidget(btnActionSupprimer);


        rightPanelLayout->addWidget(grpActionsRapides);

        grpInfosClient = new QGroupBox(centralwidget);
        grpInfosClient->setObjectName("grpInfosClient");
        grpInfosClient->setMaximumWidth(180);
        verticalLayout_6 = new QVBoxLayout(grpInfosClient);
        verticalLayout_6->setObjectName("verticalLayout_6");
        lblInfoStatut = new QLabel(grpInfosClient);
        lblInfoStatut->setObjectName("lblInfoStatut");

        verticalLayout_6->addWidget(lblInfoStatut);

        lblInfoScore = new QLabel(grpInfosClient);
        lblInfoScore->setObjectName("lblInfoScore");

        verticalLayout_6->addWidget(lblInfoScore);

        lblInfoAlertes = new QLabel(grpInfosClient);
        lblInfoAlertes->setObjectName("lblInfoAlertes");

        verticalLayout_6->addWidget(lblInfoAlertes);


        rightPanelLayout->addWidget(grpInfosClient);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        rightPanelLayout->addItem(verticalSpacer_2);


        contentLayout->addLayout(rightPanelLayout);


        mainContentLayout->addLayout(contentLayout);


        horizontalLayout->addLayout(mainContentLayout);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Oil Press Management - Clients", nullptr));
        lblLogo->setText(QString());
        btnEmploye->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        btnEquipe->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnLaboratoire->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnCommande->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        grpRechercheFiltre->setTitle(QCoreApplication::translate("MainWindow", "Recherche et Filtres", nullptr));
        lblNom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        lblType->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        lblStatut->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        btnAppliquerFiltre->setText(QCoreApplication::translate("MainWindow", "Appliquer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListeClients), QCoreApplication::translate("MainWindow", "Liste des Clients", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAlertes), QCoreApplication::translate("MainWindow", "Alertes", nullptr));
        grpActionsRapides->setTitle(QCoreApplication::translate("MainWindow", "Actions Rapides", nullptr));
        btnActionAjouter->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter", nullptr));
        btnActionModifier->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnActionSupprimer->setText(QCoreApplication::translate("MainWindow", "\342\235\214 Supprimer", nullptr));
        grpInfosClient->setTitle(QCoreApplication::translate("MainWindow", "Infos Client", nullptr));
        lblInfoStatut->setText(QCoreApplication::translate("MainWindow", "Statut : -", nullptr));
        lblInfoScore->setText(QCoreApplication::translate("MainWindow", "Score : -", nullptr));
        lblInfoAlertes->setText(QCoreApplication::translate("MainWindow", "Alertes : -", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
