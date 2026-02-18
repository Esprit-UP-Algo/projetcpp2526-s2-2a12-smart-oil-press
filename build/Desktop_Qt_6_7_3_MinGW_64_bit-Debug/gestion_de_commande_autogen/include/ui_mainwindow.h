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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
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
    QPushButton *btnEmploye;
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
    QVBoxLayout *verticalLayout_commandes;
    QLabel *label_commandes_placeholder;
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

        btnEmploye = new QPushButton(navFrame);
        btnEmploye->setObjectName("btnEmploye");

        navLayout->addWidget(btnEmploye);

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
        verticalLayout_commandes = new QVBoxLayout(pageCommandes);
        verticalLayout_commandes->setObjectName("verticalLayout_commandes");
        label_commandes_placeholder = new QLabel(pageCommandes);
        label_commandes_placeholder->setObjectName("label_commandes_placeholder");
        label_commandes_placeholder->setAlignment(Qt::AlignCenter);

        verticalLayout_commandes->addWidget(label_commandes_placeholder);

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

        stackedMain->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Oil Press - Gestion des Commandes", nullptr));
        logoLabel->setText(QCoreApplication::translate("MainWindow", "SMART OIL", nullptr));
        btnEmploye->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        btnCommande->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnEquipe->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnLaboratoire->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnFournisseur->setText(QCoreApplication::translate("MainWindow", "FOURNISSEUR", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Bienvenue dans Smart Oil Press", nullptr));
        label_commandes_placeholder->setText(QCoreApplication::translate("MainWindow", "Gestion des Commandes", nullptr));
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
