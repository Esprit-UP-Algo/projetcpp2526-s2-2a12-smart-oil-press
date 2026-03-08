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
    QHBoxLayout *horizontalLayoutMain;
    QFrame *navFrame;
    QVBoxLayout *navLayout;
    QLabel *logoLabel;
    QPushButton *btnEmploye;
    QPushButton *btnEquipe;
    QPushButton *btnClient;
    QPushButton *btnLaboratoire;
    QPushButton *btnCommande;
    QPushButton *btnMachine;
    QPushButton *btnQuit;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedMain;
    QWidget *pagePlaceholder;
    QVBoxLayout *verticalLayout_placeholder;
    QLabel *welcomeLabel;
    QWidget *pageAccueil;
    QVBoxLayout *accueilLayout;
    QSpacerItem *accueilTopSpacer;
    QLabel *accueilTitre;
    QLabel *accueilMessage;
    QHBoxLayout *accueilBtnLayout;
    QSpacerItem *accueilBtnLeftSpacer;
    QPushButton *btnContinuer;
    QSpacerItem *accueilBtnRightSpacer;
    QSpacerItem *accueilBottomSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 800);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutMain = new QHBoxLayout(centralwidget);
        horizontalLayoutMain->setObjectName("horizontalLayoutMain");
        navFrame = new QFrame(centralwidget);
        navFrame->setObjectName("navFrame");
        navFrame->setMinimumWidth(200);
        navLayout = new QVBoxLayout(navFrame);
        navLayout->setObjectName("navLayout");
        logoLabel = new QLabel(navFrame);
        logoLabel->setObjectName("logoLabel");
        logoLabel->setAlignment(Qt::AlignCenter);
        logoLabel->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logoLabel->setScaledContents(true);
        logoLabel->setMaximumHeight(100);

        navLayout->addWidget(logoLabel);

        btnEmploye = new QPushButton(navFrame);
        btnEmploye->setObjectName("btnEmploye");

        navLayout->addWidget(btnEmploye);

        btnEquipe = new QPushButton(navFrame);
        btnEquipe->setObjectName("btnEquipe");

        navLayout->addWidget(btnEquipe);

        btnClient = new QPushButton(navFrame);
        btnClient->setObjectName("btnClient");

        navLayout->addWidget(btnClient);

        btnLaboratoire = new QPushButton(navFrame);
        btnLaboratoire->setObjectName("btnLaboratoire");

        navLayout->addWidget(btnLaboratoire);

        btnCommande = new QPushButton(navFrame);
        btnCommande->setObjectName("btnCommande");

        navLayout->addWidget(btnCommande);

        btnMachine = new QPushButton(navFrame);
        btnMachine->setObjectName("btnMachine");

        navLayout->addWidget(btnMachine);

        btnQuit = new QPushButton(navFrame);
        btnQuit->setObjectName("btnQuit");

        navLayout->addWidget(btnQuit);

        verticalSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        navLayout->addItem(verticalSpacer);


        horizontalLayoutMain->addWidget(navFrame);

        stackedMain = new QStackedWidget(centralwidget);
        stackedMain->setObjectName("stackedMain");
        pagePlaceholder = new QWidget();
        pagePlaceholder->setObjectName("pagePlaceholder");
        verticalLayout_placeholder = new QVBoxLayout(pagePlaceholder);
        verticalLayout_placeholder->setObjectName("verticalLayout_placeholder");
        welcomeLabel = new QLabel(pagePlaceholder);
        welcomeLabel->setObjectName("welcomeLabel");
        welcomeLabel->setAlignment(Qt::AlignCenter);

        verticalLayout_placeholder->addWidget(welcomeLabel);

        stackedMain->addWidget(pagePlaceholder);
        pageAccueil = new QWidget();
        pageAccueil->setObjectName("pageAccueil");
        accueilLayout = new QVBoxLayout(pageAccueil);
        accueilLayout->setObjectName("accueilLayout");
        accueilLayout->setContentsMargins(60, -1, 60, -1);
        accueilTopSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        accueilLayout->addItem(accueilTopSpacer);

        accueilTitre = new QLabel(pageAccueil);
        accueilTitre->setObjectName("accueilTitre");
        accueilTitre->setAlignment(Qt::AlignCenter);

        accueilLayout->addWidget(accueilTitre);

        accueilMessage = new QLabel(pageAccueil);
        accueilMessage->setObjectName("accueilMessage");
        accueilMessage->setAlignment(Qt::AlignCenter);
        accueilMessage->setWordWrap(true);

        accueilLayout->addWidget(accueilMessage);

        accueilBtnLayout = new QHBoxLayout();
        accueilBtnLayout->setObjectName("accueilBtnLayout");
        accueilBtnLeftSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        accueilBtnLayout->addItem(accueilBtnLeftSpacer);

        btnContinuer = new QPushButton(pageAccueil);
        btnContinuer->setObjectName("btnContinuer");
        btnContinuer->setMinimumSize(QSize(200, 50));

        accueilBtnLayout->addWidget(btnContinuer);

        accueilBtnRightSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        accueilBtnLayout->addItem(accueilBtnRightSpacer);


        accueilLayout->addLayout(accueilBtnLayout);

        accueilBottomSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        accueilLayout->addItem(accueilBottomSpacer);

        stackedMain->addWidget(pageAccueil);

        horizontalLayoutMain->addWidget(stackedMain);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Oil Press Management", nullptr));
        btnEmploye->setText(QCoreApplication::translate("MainWindow", "EMPLOY\303\211", nullptr));
        btnEquipe->setText(QCoreApplication::translate("MainWindow", "\303\211QUIPE", nullptr));
        btnClient->setText(QCoreApplication::translate("MainWindow", "CLIENT", nullptr));
        btnLaboratoire->setText(QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        btnCommande->setText(QCoreApplication::translate("MainWindow", "COMMANDE", nullptr));
        btnMachine->setText(QCoreApplication::translate("MainWindow", "MACHINE", nullptr));
        btnQuit->setText(QCoreApplication::translate("MainWindow", "QUITTER", nullptr));
        welcomeLabel->setText(QCoreApplication::translate("MainWindow", "Bienvenue dans l'application de gestion", nullptr));
        accueilTitre->setText(QCoreApplication::translate("MainWindow", "\360\237\214\277 Bienvenue sur Smart Oil Management", nullptr));
        accueilTitre->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 28px; font-weight: bold; color: #2E7D32; margin-bottom: 20px;", nullptr));
        accueilMessage->setText(QCoreApplication::translate("MainWindow", "Votre solution compl\303\250te pour la gestion intelligente de votre huilerie.\n"
"\n"
"G\303\251rez efficacement vos employ\303\251s, \303\251quipes, commandes, laboratoires et machines\n"
"depuis une interface moderne et intuitive.\n"
"\n"
"Optimisez votre production, suivez vos analyses qualit\303\251 et prenez des d\303\251cisions\n"
"\303\251clair\303\251es gr\303\242ce \303\240 nos outils de statistiques et de g\303\251olocalisation.", nullptr));
        accueilMessage->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; color: #555; line-height: 1.6; margin: 30px 0;", nullptr));
        btnContinuer->setText(QCoreApplication::translate("MainWindow", "Commencer \342\206\222", nullptr));
        btnContinuer->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #2E7D32; color: white; font-size: 18px; font-weight: bold; border-radius: 8px; } QPushButton:hover { background-color: #1B5E20; }", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
