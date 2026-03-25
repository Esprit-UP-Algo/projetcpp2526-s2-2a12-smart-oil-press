/********************************************************************************
** Form generated from reading UI file 'labo_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABO_WIDGET_H
#define UI_LABO_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LaboWidget
{
public:
    QVBoxLayout *mainLayout;
    QTabWidget *topNavTabs;
    QWidget *tabAjouter;
    QWidget *tabGestion;
    QWidget *tabSupprimer;
    QWidget *tabModifier;
    QWidget *tabStatistique;
    QWidget *tabGeolocalisation;
    QWidget *tabAIBot;
    QStackedWidget *stackedWidget;
    QWidget *pageadd;
    QVBoxLayout *addLayout;
    QLabel *addTitle;
    QFrame *addFormFrame;
    QFormLayout *addFormLayout;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLabel *label_type;
    QComboBox *comboBox_type;
    QLabel *label_conformite;
    QComboBox *comboBox_conformite;
    QLabel *label_adresse;
    QLineEdit *lineEdit_adresse;
    QLabel *label_espace;
    QSpinBox *spinBox_espace;
    QSpacerItem *addSpacer;
    QHBoxLayout *addActionLayout;
    QSpacerItem *addActionSpacer;
    QPushButton *pushButton_28;
    QWidget *page_rech;
    QVBoxLayout *rechLayout;
    QHBoxLayout *rechTopLayout;
    QLineEdit *lineEdit;
    QPushButton *btnRechercher;
    QHBoxLayout *rechMainLayout;
    QFrame *frame_4;
    QVBoxLayout *frame4Layout;
    QLabel *label_7;
    QPushButton *btnTrier;
    QComboBox *comboBox_2;
    QHBoxLayout *sortOptionsLayout;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QFrame *line_export;
    QLabel *label_export;
    QPushButton *btnExportPDF;
    QSpacerItem *frame4Spacer;
    QTableWidget *tableWidget;
    QWidget *pagesupp;
    QVBoxLayout *suppLayout;
    QLabel *suppTitle;
    QFrame *suppFormFrame;
    QVBoxLayout *suppFormLayout;
    QLabel *suppWarning;
    QHBoxLayout *suppIdLayout;
    QLabel *label_42;
    QLineEdit *lineEdit_9;
    QSpacerItem *suppSpacer;
    QHBoxLayout *suppActionLayout;
    QSpacerItem *suppActionSpacer;
    QPushButton *pushButton_30;
    QWidget *pagemodif;
    QVBoxLayout *modifLayout;
    QLabel *modifTitle;
    QFrame *modifFormFrame;
    QFormLayout *modifFormLayout;
    QLabel *label_modif_id;
    QLineEdit *lineEdit_modif_id;
    QLabel *label_35;
    QLineEdit *lineEdit_7;
    QLabel *label_36;
    QComboBox *comboBox_modif_type;
    QLabel *label_37;
    QComboBox *comboBox_modif_conf;
    QLabel *label_38;
    QLineEdit *lineEdit_8;
    QSpacerItem *modifSpacer;
    QHBoxLayout *modifActionLayout;
    QSpacerItem *modifActionSpacer;
    QPushButton *pushButton_34;
    QWidget *page_stat;
    QVBoxLayout *statLayout;
    QLabel *statTitle;
    QHBoxLayout *statsContentLayout;
    QGroupBox *performanceGroup;
    QVBoxLayout *vboxLayout;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *vitesseGroup;
    QVBoxLayout *vboxLayout1;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *exportLayout;
    QSpacerItem *exportSpacer;
    QPushButton *pushButton_25;
    QWidget *pageGeo;
    QVBoxLayout *geoLayout;
    QLabel *geoPlaceholder;
    QWidget *pageAI;
    QVBoxLayout *aiLayout;
    QLabel *aiPlaceholder;

    void setupUi(QWidget *LaboWidget)
    {
        if (LaboWidget->objectName().isEmpty())
            LaboWidget->setObjectName("LaboWidget");
        LaboWidget->resize(900, 700);
        mainLayout = new QVBoxLayout(LaboWidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        topNavTabs = new QTabWidget(LaboWidget);
        topNavTabs->setObjectName("topNavTabs");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(topNavTabs->sizePolicy().hasHeightForWidth());
        topNavTabs->setSizePolicy(sizePolicy);
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
        tabGeolocalisation = new QWidget();
        tabGeolocalisation->setObjectName("tabGeolocalisation");
        topNavTabs->addTab(tabGeolocalisation, QString());
        tabAIBot = new QWidget();
        tabAIBot->setObjectName("tabAIBot");
        topNavTabs->addTab(tabAIBot, QString());

        mainLayout->addWidget(topNavTabs);

        stackedWidget = new QStackedWidget(LaboWidget);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
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
        label_id = new QLabel(addFormFrame);
        label_id->setObjectName("label_id");

        addFormLayout->setWidget(0, QFormLayout::LabelRole, label_id);

        lineEdit_id = new QLineEdit(addFormFrame);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setReadOnly(true);

        addFormLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_id);

        label_nom = new QLabel(addFormFrame);
        label_nom->setObjectName("label_nom");

        addFormLayout->setWidget(1, QFormLayout::LabelRole, label_nom);

        lineEdit_nom = new QLineEdit(addFormFrame);
        lineEdit_nom->setObjectName("lineEdit_nom");

        addFormLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_nom);

        label_type = new QLabel(addFormFrame);
        label_type->setObjectName("label_type");

        addFormLayout->setWidget(2, QFormLayout::LabelRole, label_type);

        comboBox_type = new QComboBox(addFormFrame);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");

        addFormLayout->setWidget(2, QFormLayout::FieldRole, comboBox_type);

        label_conformite = new QLabel(addFormFrame);
        label_conformite->setObjectName("label_conformite");

        addFormLayout->setWidget(3, QFormLayout::LabelRole, label_conformite);

        comboBox_conformite = new QComboBox(addFormFrame);
        comboBox_conformite->addItem(QString());
        comboBox_conformite->addItem(QString());
        comboBox_conformite->setObjectName("comboBox_conformite");

        addFormLayout->setWidget(3, QFormLayout::FieldRole, comboBox_conformite);

        label_adresse = new QLabel(addFormFrame);
        label_adresse->setObjectName("label_adresse");

        addFormLayout->setWidget(4, QFormLayout::LabelRole, label_adresse);

        lineEdit_adresse = new QLineEdit(addFormFrame);
        lineEdit_adresse->setObjectName("lineEdit_adresse");

        addFormLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_adresse);

        label_espace = new QLabel(addFormFrame);
        label_espace->setObjectName("label_espace");

        addFormLayout->setWidget(5, QFormLayout::LabelRole, label_espace);

        spinBox_espace = new QSpinBox(addFormFrame);
        spinBox_espace->setObjectName("spinBox_espace");
        spinBox_espace->setMaximum(10000);

        addFormLayout->setWidget(5, QFormLayout::FieldRole, spinBox_espace);


        addLayout->addWidget(addFormFrame);

        addSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        addLayout->addItem(addSpacer);

        addActionLayout = new QHBoxLayout();
        addActionLayout->setObjectName("addActionLayout");
        addActionSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        addActionLayout->addItem(addActionSpacer);

        pushButton_28 = new QPushButton(pageadd);
        pushButton_28->setObjectName("pushButton_28");
        pushButton_28->setMinimumWidth(200);

        addActionLayout->addWidget(pushButton_28);


        addLayout->addLayout(addActionLayout);

        stackedWidget->addWidget(pageadd);
        page_rech = new QWidget();
        page_rech->setObjectName("page_rech");
        rechLayout = new QVBoxLayout(page_rech);
        rechLayout->setSpacing(8);
        rechLayout->setObjectName("rechLayout");
        rechLayout->setContentsMargins(10, 10, 10, 10);
        rechTopLayout = new QHBoxLayout();
        rechTopLayout->setObjectName("rechTopLayout");
        lineEdit = new QLineEdit(page_rech);
        lineEdit->setObjectName("lineEdit");

        rechTopLayout->addWidget(lineEdit);

        btnRechercher = new QPushButton(page_rech);
        btnRechercher->setObjectName("btnRechercher");

        rechTopLayout->addWidget(btnRechercher);


        rechLayout->addLayout(rechTopLayout);

        rechMainLayout = new QHBoxLayout();
        rechMainLayout->setObjectName("rechMainLayout");
        frame_4 = new QFrame(page_rech);
        frame_4->setObjectName("frame_4");
        frame_4->setMinimumSize(QSize(220, 0));
        frame_4->setMaximumSize(QSize(220, 16777215));
        frame4Layout = new QVBoxLayout(frame_4);
        frame4Layout->setObjectName("frame4Layout");
        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");

        frame4Layout->addWidget(label_7);

        btnTrier = new QPushButton(frame_4);
        btnTrier->setObjectName("btnTrier");

        frame4Layout->addWidget(btnTrier);

        comboBox_2 = new QComboBox(frame_4);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName("comboBox_2");

        frame4Layout->addWidget(comboBox_2);

        sortOptionsLayout = new QHBoxLayout();
        sortOptionsLayout->setObjectName("sortOptionsLayout");
        checkBox_3 = new QCheckBox(frame_4);
        checkBox_3->setObjectName("checkBox_3");

        sortOptionsLayout->addWidget(checkBox_3);

        checkBox_4 = new QCheckBox(frame_4);
        checkBox_4->setObjectName("checkBox_4");

        sortOptionsLayout->addWidget(checkBox_4);


        frame4Layout->addLayout(sortOptionsLayout);

        line_export = new QFrame(frame_4);
        line_export->setObjectName("line_export");
        line_export->setFrameShape(QFrame::Shape::HLine);
        line_export->setFrameShadow(QFrame::Shadow::Sunken);

        frame4Layout->addWidget(line_export);

        label_export = new QLabel(frame_4);
        label_export->setObjectName("label_export");

        frame4Layout->addWidget(label_export);

        btnExportPDF = new QPushButton(frame_4);
        btnExportPDF->setObjectName("btnExportPDF");

        frame4Layout->addWidget(btnExportPDF);

        frame4Spacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        frame4Layout->addItem(frame4Spacer);


        rechMainLayout->addWidget(frame_4);

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
        sizePolicy1.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy1);
        tableWidget->horizontalHeader()->setStretchLastSection(true);

        rechMainLayout->addWidget(tableWidget);


        rechLayout->addLayout(rechMainLayout);

        stackedWidget->addWidget(page_rech);
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
        label_42 = new QLabel(suppFormFrame);
        label_42->setObjectName("label_42");

        suppIdLayout->addWidget(label_42);

        lineEdit_9 = new QLineEdit(suppFormFrame);
        lineEdit_9->setObjectName("lineEdit_9");

        suppIdLayout->addWidget(lineEdit_9);


        suppFormLayout->addLayout(suppIdLayout);

        suppSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        suppFormLayout->addItem(suppSpacer);

        suppActionLayout = new QHBoxLayout();
        suppActionLayout->setObjectName("suppActionLayout");
        suppActionSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        suppActionLayout->addItem(suppActionSpacer);

        pushButton_30 = new QPushButton(suppFormFrame);
        pushButton_30->setObjectName("pushButton_30");
        pushButton_30->setMinimumWidth(200);

        suppActionLayout->addWidget(pushButton_30);


        suppFormLayout->addLayout(suppActionLayout);


        suppLayout->addWidget(suppFormFrame);

        stackedWidget->addWidget(pagesupp);
        pagemodif = new QWidget();
        pagemodif->setObjectName("pagemodif");
        modifLayout = new QVBoxLayout(pagemodif);
        modifLayout->setObjectName("modifLayout");
        modifTitle = new QLabel(pagemodif);
        modifTitle->setObjectName("modifTitle");

        modifLayout->addWidget(modifTitle);

        modifFormFrame = new QFrame(pagemodif);
        modifFormFrame->setObjectName("modifFormFrame");
        modifFormLayout = new QFormLayout(modifFormFrame);
        modifFormLayout->setObjectName("modifFormLayout");
        label_modif_id = new QLabel(modifFormFrame);
        label_modif_id->setObjectName("label_modif_id");

        modifFormLayout->setWidget(0, QFormLayout::LabelRole, label_modif_id);

        lineEdit_modif_id = new QLineEdit(modifFormFrame);
        lineEdit_modif_id->setObjectName("lineEdit_modif_id");

        modifFormLayout->setWidget(0, QFormLayout::FieldRole, lineEdit_modif_id);

        label_35 = new QLabel(modifFormFrame);
        label_35->setObjectName("label_35");

        modifFormLayout->setWidget(1, QFormLayout::LabelRole, label_35);

        lineEdit_7 = new QLineEdit(modifFormFrame);
        lineEdit_7->setObjectName("lineEdit_7");

        modifFormLayout->setWidget(1, QFormLayout::FieldRole, lineEdit_7);

        label_36 = new QLabel(modifFormFrame);
        label_36->setObjectName("label_36");

        modifFormLayout->setWidget(2, QFormLayout::LabelRole, label_36);

        comboBox_modif_type = new QComboBox(modifFormFrame);
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->setObjectName("comboBox_modif_type");

        modifFormLayout->setWidget(2, QFormLayout::FieldRole, comboBox_modif_type);

        label_37 = new QLabel(modifFormFrame);
        label_37->setObjectName("label_37");

        modifFormLayout->setWidget(3, QFormLayout::LabelRole, label_37);

        comboBox_modif_conf = new QComboBox(modifFormFrame);
        comboBox_modif_conf->addItem(QString());
        comboBox_modif_conf->addItem(QString());
        comboBox_modif_conf->setObjectName("comboBox_modif_conf");

        modifFormLayout->setWidget(3, QFormLayout::FieldRole, comboBox_modif_conf);

        label_38 = new QLabel(modifFormFrame);
        label_38->setObjectName("label_38");

        modifFormLayout->setWidget(4, QFormLayout::LabelRole, label_38);

        lineEdit_8 = new QLineEdit(modifFormFrame);
        lineEdit_8->setObjectName("lineEdit_8");

        modifFormLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_8);


        modifLayout->addWidget(modifFormFrame);

        modifSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        modifLayout->addItem(modifSpacer);

        modifActionLayout = new QHBoxLayout();
        modifActionLayout->setObjectName("modifActionLayout");
        modifActionSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        modifActionLayout->addItem(modifActionSpacer);

        pushButton_34 = new QPushButton(pagemodif);
        pushButton_34->setObjectName("pushButton_34");
        pushButton_34->setMinimumWidth(200);

        modifActionLayout->addWidget(pushButton_34);


        modifLayout->addLayout(modifActionLayout);

        stackedWidget->addWidget(pagemodif);
        page_stat = new QWidget();
        page_stat->setObjectName("page_stat");
        statLayout = new QVBoxLayout(page_stat);
        statLayout->setObjectName("statLayout");
        statTitle = new QLabel(page_stat);
        statTitle->setObjectName("statTitle");

        statLayout->addWidget(statTitle);

        statsContentLayout = new QHBoxLayout();
        statsContentLayout->setObjectName("statsContentLayout");
        performanceGroup = new QGroupBox(page_stat);
        performanceGroup->setObjectName("performanceGroup");
        vboxLayout = new QVBoxLayout(performanceGroup);
        vboxLayout->setObjectName("vboxLayout");
        plainTextEdit = new QPlainTextEdit(performanceGroup);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setReadOnly(true);

        vboxLayout->addWidget(plainTextEdit);


        statsContentLayout->addWidget(performanceGroup);

        vitesseGroup = new QGroupBox(page_stat);
        vitesseGroup->setObjectName("vitesseGroup");
        vboxLayout1 = new QVBoxLayout(vitesseGroup);
        vboxLayout1->setObjectName("vboxLayout1");
        plainTextEdit_2 = new QPlainTextEdit(vitesseGroup);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setReadOnly(true);

        vboxLayout1->addWidget(plainTextEdit_2);


        statsContentLayout->addWidget(vitesseGroup);


        statLayout->addLayout(statsContentLayout);

        exportLayout = new QHBoxLayout();
        exportLayout->setObjectName("exportLayout");
        exportSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        exportLayout->addItem(exportSpacer);

        pushButton_25 = new QPushButton(page_stat);
        pushButton_25->setObjectName("pushButton_25");

        exportLayout->addWidget(pushButton_25);


        statLayout->addLayout(exportLayout);

        stackedWidget->addWidget(page_stat);
        pageGeo = new QWidget();
        pageGeo->setObjectName("pageGeo");
        geoLayout = new QVBoxLayout(pageGeo);
        geoLayout->setObjectName("geoLayout");
        geoPlaceholder = new QLabel(pageGeo);
        geoPlaceholder->setObjectName("geoPlaceholder");
        geoPlaceholder->setAlignment(Qt::AlignCenter);

        geoLayout->addWidget(geoPlaceholder);

        stackedWidget->addWidget(pageGeo);
        pageAI = new QWidget();
        pageAI->setObjectName("pageAI");
        aiLayout = new QVBoxLayout(pageAI);
        aiLayout->setObjectName("aiLayout");
        aiPlaceholder = new QLabel(pageAI);
        aiPlaceholder->setObjectName("aiPlaceholder");
        aiPlaceholder->setAlignment(Qt::AlignCenter);

        aiLayout->addWidget(aiPlaceholder);

        stackedWidget->addWidget(pageAI);

        mainLayout->addWidget(stackedWidget);


        retranslateUi(LaboWidget);

        topNavTabs->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(LaboWidget);
    } // setupUi

    void retranslateUi(QWidget *LaboWidget)
    {
        topNavTabs->setTabText(topNavTabs->indexOf(tabAjouter), QCoreApplication::translate("LaboWidget", "Ajouter un laboratoire", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabGestion), QCoreApplication::translate("LaboWidget", "Liste des laboratoires", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSupprimer), QCoreApplication::translate("LaboWidget", "Supprimer", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabModifier), QCoreApplication::translate("LaboWidget", "Modifier", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabStatistique), QCoreApplication::translate("LaboWidget", "Statistiques", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabGeolocalisation), QCoreApplication::translate("LaboWidget", "G\303\251olocalisation", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabAIBot), QCoreApplication::translate("LaboWidget", "Assistant IA", nullptr));
        addTitle->setText(QCoreApplication::translate("LaboWidget", "Ajouter un Laboratoire", nullptr));
        label_id->setText(QCoreApplication::translate("LaboWidget", "ID:", nullptr));
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("LaboWidget", "ID g\303\251n\303\251r\303\251 automatiquement", nullptr));
        label_nom->setText(QCoreApplication::translate("LaboWidget", "Nom:", nullptr));
        lineEdit_nom->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Nom du laboratoire", nullptr));
        label_type->setText(QCoreApplication::translate("LaboWidget", "Type d'analyse:", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("LaboWidget", "S\303\251lectionner le type", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("LaboWidget", "Chimique", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("LaboWidget", "Bact\303\251riologique", nullptr));
        comboBox_type->setItemText(3, QCoreApplication::translate("LaboWidget", "Physique", nullptr));
        comboBox_type->setItemText(4, QCoreApplication::translate("LaboWidget", "Biologique", nullptr));

        label_conformite->setText(QCoreApplication::translate("LaboWidget", "Conformit\303\251:", nullptr));
        comboBox_conformite->setItemText(0, QCoreApplication::translate("LaboWidget", "Oui", nullptr));
        comboBox_conformite->setItemText(1, QCoreApplication::translate("LaboWidget", "Non", nullptr));

        label_adresse->setText(QCoreApplication::translate("LaboWidget", "Adresse:", nullptr));
        lineEdit_adresse->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Adresse du laboratoire", nullptr));
        label_espace->setText(QCoreApplication::translate("LaboWidget", "Espace (m\302\262):", nullptr));
        pushButton_28->setText(QCoreApplication::translate("LaboWidget", "Enregistrer", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Rechercher par ID, Nom, Adresse, Type d'analyse...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("LaboWidget", "Rechercher", nullptr));
        label_7->setText(QCoreApplication::translate("LaboWidget", "Tri des laboratoires", nullptr));
        btnTrier->setText(QCoreApplication::translate("LaboWidget", "Trier par", nullptr));
        comboBox_2->setItemText(0, QCoreApplication::translate("LaboWidget", "Nom", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("LaboWidget", "Type d analyse", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("LaboWidget", "ID", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("LaboWidget", "Conformite", nullptr));

        checkBox_3->setText(QCoreApplication::translate("LaboWidget", "Croissant", nullptr));
        checkBox_4->setText(QCoreApplication::translate("LaboWidget", "D\303\251croissant", nullptr));
        label_export->setText(QCoreApplication::translate("LaboWidget", "Export", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("LaboWidget", "Exporter PDF", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("LaboWidget", "ID Laboratoire", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("LaboWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("LaboWidget", "Type d'analyse", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("LaboWidget", "Conformit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("LaboWidget", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("LaboWidget", "Espace", nullptr));
        suppTitle->setText(QCoreApplication::translate("LaboWidget", "Supprimer un Laboratoire", nullptr));
        suppWarning->setText(QCoreApplication::translate("LaboWidget", "Attention: Cette action est irr\303\251versible", nullptr));
        label_42->setText(QCoreApplication::translate("LaboWidget", "ID:", nullptr));
        lineEdit_9->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Saisissez l'ID du laboratoire \303\240 supprimer", nullptr));
        pushButton_30->setText(QCoreApplication::translate("LaboWidget", "Supprimer", nullptr));
        modifTitle->setText(QCoreApplication::translate("LaboWidget", "Modifier un Laboratoire", nullptr));
        label_modif_id->setText(QCoreApplication::translate("LaboWidget", "ID:", nullptr));
        lineEdit_modif_id->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Saisissez l'ID du laboratoire", nullptr));
        label_35->setText(QCoreApplication::translate("LaboWidget", "Nom:", nullptr));
        lineEdit_7->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Nouveau nom", nullptr));
        label_36->setText(QCoreApplication::translate("LaboWidget", "Type d'analyse:", nullptr));
        comboBox_modif_type->setItemText(0, QCoreApplication::translate("LaboWidget", "Chimique", nullptr));
        comboBox_modif_type->setItemText(1, QCoreApplication::translate("LaboWidget", "Bact\303\251riologique", nullptr));
        comboBox_modif_type->setItemText(2, QCoreApplication::translate("LaboWidget", "Physique", nullptr));
        comboBox_modif_type->setItemText(3, QCoreApplication::translate("LaboWidget", "Biologique", nullptr));

        label_37->setText(QCoreApplication::translate("LaboWidget", "Conformit\303\251:", nullptr));
        comboBox_modif_conf->setItemText(0, QCoreApplication::translate("LaboWidget", "Oui", nullptr));
        comboBox_modif_conf->setItemText(1, QCoreApplication::translate("LaboWidget", "Non", nullptr));

        label_38->setText(QCoreApplication::translate("LaboWidget", "Adresse:", nullptr));
        lineEdit_8->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Nouvelle adresse", nullptr));
        pushButton_34->setText(QCoreApplication::translate("LaboWidget", "Modifier", nullptr));
        statTitle->setText(QCoreApplication::translate("LaboWidget", "Statistiques et Performance des laboratoires", nullptr));
        performanceGroup->setTitle(QCoreApplication::translate("LaboWidget", "Taux de conformit\303\251", nullptr));
        plainTextEdit->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Statistiques de conformit\303\251 des analyses...", nullptr));
        vitesseGroup->setTitle(QCoreApplication::translate("LaboWidget", "Analyses mensuelles", nullptr));
        plainTextEdit_2->setPlaceholderText(QCoreApplication::translate("LaboWidget", "Nombre d'analyses par mois...", nullptr));
        pushButton_25->setText(QCoreApplication::translate("LaboWidget", "Exporter PDF", nullptr));
        geoPlaceholder->setText(QCoreApplication::translate("LaboWidget", "Page de g\303\251olocalisation des laboratoires", nullptr));
        aiPlaceholder->setText(QCoreApplication::translate("LaboWidget", "Assistant IA - Chatbot intelligent", nullptr));
        (void)LaboWidget;
    } // retranslateUi

};

namespace Ui {
    class LaboWidget: public Ui_LaboWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABO_WIDGET_H
