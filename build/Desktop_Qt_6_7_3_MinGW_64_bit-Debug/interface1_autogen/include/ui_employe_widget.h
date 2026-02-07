/********************************************************************************
** Form generated from reading UI file 'employe_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYE_WIDGET_H
#define UI_EMPLOYE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAjouter;
    QVBoxLayout *verticalLayout_ajouter;
    QGridLayout *grid_ajouter;
    QLabel *label_id;
    QLineEdit *lineEdit_id;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_age;
    QSpinBox *spinBox_age;
    QLabel *label_tel;
    QLineEdit *lineEdit_tel;
    QLabel *label_spec;
    QComboBox *combo_spec;
    QLabel *label_salaire;
    QDoubleSpinBox *doubleSpin_salaire;
    QLabel *label_anciennete;
    QSpinBox *spin_anciennete;
    QLabel *label_disp;
    QComboBox *combo_disp;
    QLabel *label_heures;
    QSpinBox *spin_heures;
    QLabel *label_fourn;
    QSpinBox *spin_fourn;
    QHBoxLayout *hButtonsAjouter;
    QSpacerItem *spacerH;
    QPushButton *btnAjouter;
    QWidget *tabListe;
    QHBoxLayout *hLayout_liste;
    QFrame *sidebarListe;
    QVBoxLayout *vLayout_sidebar;
    QGroupBox *groupSearch;
    QVBoxLayout *vSearch;
    QLabel *label_search_id;
    QLineEdit *search_id;
    QLabel *label_search_nom;
    QLineEdit *search_nom;
    QLabel *label_search_tel;
    QLineEdit *search_tel;
    QLabel *label_search_spec;
    QComboBox *search_spec;
    QLabel *label_search_disp;
    QComboBox *search_disp;
    QGroupBox *groupSort;
    QVBoxLayout *vSort;
    QRadioButton *sort_nom;
    QRadioButton *sort_salaire;
    QRadioButton *sort_anciennete;
    QRadioButton *sort_age;
    QRadioButton *sort_heures;
    QRadioButton *sort_fournisseurs;
    QGroupBox *groupOrder;
    QVBoxLayout *vOrder;
    QRadioButton *order_asc;
    QRadioButton *order_desc;
    QSpacerItem *verticalSpacer_liste;
    QFrame *mainListe;
    QVBoxLayout *vLayout_tableArea;
    QTableWidget *table_employes;
    QWidget *tabSupprimer;
    QVBoxLayout *vertical_supprimer;
    QFormLayout *formSuppr;
    QLabel *label_id_suppr;
    QLineEdit *lineEdit_id_suppr;
    QPushButton *btnSupprimerConfirm;
    QWidget *tabModifier;
    QVBoxLayout *vertical_modifier;
    QFormLayout *formModifier;
    QLabel *label_id_mod;
    QLineEdit *lineEdit_id_mod;
    QGroupBox *groupBox_prefill;
    QGridLayout *grid_prefill;
    QLabel *label_nom_mod;
    QLineEdit *lineEdit_nom_mod;
    QLabel *label_prenom_mod;
    QLineEdit *lineEdit_prenom_mod;
    QLabel *label_age_mod;
    QSpinBox *spinBox_age_mod;
    QLabel *label_tel_mod;
    QLineEdit *lineEdit_tel_mod;
    QLabel *label_spec_mod;
    QComboBox *combo_spec_mod;
    QLabel *label_salaire_mod;
    QDoubleSpinBox *doubleSpin_salaire_mod;
    QLabel *label_anciennete_mod;
    QSpinBox *spin_anciennete_mod;
    QLabel *label_disp_mod;
    QComboBox *combo_disp_mod;
    QLabel *label_heures_mod;
    QSpinBox *spin_heures_mod;
    QLabel *label_fourn_mod;
    QSpinBox *spin_fourn_mod;
    QPushButton *btnModifierConfirm;
    QWidget *tabStatistiques;
    QVBoxLayout *vertical_statistiques;
    QGroupBox *groupEffectifs;
    QVBoxLayout *vEffectifs;
    QLabel *label_total_employes;
    QLabel *label_par_specialite;
    QTableWidget *table_effectifs_spec;
    QLabel *label_par_disponibilite;
    QTableWidget *table_effectifs_disp;
    QGroupBox *groupFinances;
    QVBoxLayout *vFinances;
    QLabel *label_masse_salariale;
    QLabel *label_salaire_moyen;
    QLabel *label_par_specialite_sal;
    QTableWidget *table_finances_spec;
    QGroupBox *groupPerformance;
    QVBoxLayout *vPerformance;
    QLabel *label_anciennete_moyenne;
    QLabel *label_heures_moyennes;
    QLabel *label_fournisseurs_moyen;
    QSpacerItem *spacerPerf;
    QSpacerItem *verticalSpacer_stats;
    QWidget *tabExportPdf;
    QVBoxLayout *vertical_export_pdf;
    QGroupBox *groupExportOptions;
    QVBoxLayout *vExportOptions;
    QPushButton *btnExportListeComplete;
    QPushButton *btnExportRapportRH;
    QPushButton *btnExportFicheEmploye;
    QGroupBox *groupIdExport;
    QFormLayout *formIdExport;
    QLabel *label_id_export;
    QLineEdit *lineEdit_id_export;
    QGroupBox *groupMessagesExport;
    QVBoxLayout *vMessagesExport;
    QTextEdit *textEdit_export_messages;
    QSpacerItem *verticalSpacer_export;
    QWidget *tabConnexion;
    QVBoxLayout *vertical_connexion;
    QGroupBox *groupConnexion;
    QFormLayout *formConnexion;
    QLabel *label_user_conn;
    QLineEdit *line_user_conn;
    QLabel *label_pass_conn;
    QLineEdit *line_pass_conn;
    QHBoxLayout *hButtonsConn;
    QPushButton *btnSeConnecter;
    QSpacerItem *spacerConnH;
    QPushButton *btnNavigateForgot;
    QWidget *tabMotPasseOublie;
    QVBoxLayout *vertical_mdp_oublie;
    QGroupBox *groupFPStep1;
    QFormLayout *formFP1;
    QLabel *label_user_email_fp;
    QLineEdit *line_user_email_fp;
    QPushButton *btnEnvoyerCode;
    QGroupBox *groupFPStep2;
    QFormLayout *formFP2;
    QLabel *label_code_fp;
    QLineEdit *line_code_fp;
    QLabel *label_newpass_fp;
    QLineEdit *line_newpass_fp;
    QLabel *label_confirm_fp;
    QLineEdit *line_confirm_fp;
    QHBoxLayout *hButtons_mdp;
    QPushButton *btnResetPassword;
    QPushButton *btnBackToLogin;
    QGroupBox *groupFPMessages;
    QVBoxLayout *vFPMessages;
    QTextEdit *textEdit_fp_messages;

    void setupUi(QWidget *EmployeWidget)
    {
        if (EmployeWidget->objectName().isEmpty())
            EmployeWidget->setObjectName("EmployeWidget");
        EmployeWidget->setMinimumSize(QSize(600, 400));
        verticalLayout = new QVBoxLayout(EmployeWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(EmployeWidget);
        tabWidget->setObjectName("tabWidget");
        tabAjouter = new QWidget();
        tabAjouter->setObjectName("tabAjouter");
        verticalLayout_ajouter = new QVBoxLayout(tabAjouter);
        verticalLayout_ajouter->setObjectName("verticalLayout_ajouter");
        grid_ajouter = new QGridLayout();
        grid_ajouter->setObjectName("grid_ajouter");
        label_id = new QLabel(tabAjouter);
        label_id->setObjectName("label_id");

        grid_ajouter->addWidget(label_id, 0, 0, 1, 1);

        lineEdit_id = new QLineEdit(tabAjouter);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setReadOnly(true);

        grid_ajouter->addWidget(lineEdit_id, 0, 1, 1, 1);

        label_nom = new QLabel(tabAjouter);
        label_nom->setObjectName("label_nom");

        grid_ajouter->addWidget(label_nom, 1, 0, 1, 1);

        lineEdit_nom = new QLineEdit(tabAjouter);
        lineEdit_nom->setObjectName("lineEdit_nom");

        grid_ajouter->addWidget(lineEdit_nom, 1, 1, 1, 1);

        label_prenom = new QLabel(tabAjouter);
        label_prenom->setObjectName("label_prenom");

        grid_ajouter->addWidget(label_prenom, 2, 0, 1, 1);

        lineEdit_prenom = new QLineEdit(tabAjouter);
        lineEdit_prenom->setObjectName("lineEdit_prenom");

        grid_ajouter->addWidget(lineEdit_prenom, 2, 1, 1, 1);

        label_age = new QLabel(tabAjouter);
        label_age->setObjectName("label_age");

        grid_ajouter->addWidget(label_age, 3, 0, 1, 1);

        spinBox_age = new QSpinBox(tabAjouter);
        spinBox_age->setObjectName("spinBox_age");
        spinBox_age->setMinimum(16);
        spinBox_age->setMaximum(120);

        grid_ajouter->addWidget(spinBox_age, 3, 1, 1, 1);

        label_tel = new QLabel(tabAjouter);
        label_tel->setObjectName("label_tel");

        grid_ajouter->addWidget(label_tel, 4, 0, 1, 1);

        lineEdit_tel = new QLineEdit(tabAjouter);
        lineEdit_tel->setObjectName("lineEdit_tel");

        grid_ajouter->addWidget(lineEdit_tel, 4, 1, 1, 1);

        label_spec = new QLabel(tabAjouter);
        label_spec->setObjectName("label_spec");

        grid_ajouter->addWidget(label_spec, 5, 0, 1, 1);

        combo_spec = new QComboBox(tabAjouter);
        combo_spec->addItem(QString());
        combo_spec->addItem(QString());
        combo_spec->addItem(QString());
        combo_spec->addItem(QString());
        combo_spec->setObjectName("combo_spec");

        grid_ajouter->addWidget(combo_spec, 5, 1, 1, 1);

        label_salaire = new QLabel(tabAjouter);
        label_salaire->setObjectName("label_salaire");

        grid_ajouter->addWidget(label_salaire, 6, 0, 1, 1);

        doubleSpin_salaire = new QDoubleSpinBox(tabAjouter);
        doubleSpin_salaire->setObjectName("doubleSpin_salaire");
        doubleSpin_salaire->setDecimals(2);

        grid_ajouter->addWidget(doubleSpin_salaire, 6, 1, 1, 1);

        label_anciennete = new QLabel(tabAjouter);
        label_anciennete->setObjectName("label_anciennete");

        grid_ajouter->addWidget(label_anciennete, 7, 0, 1, 1);

        spin_anciennete = new QSpinBox(tabAjouter);
        spin_anciennete->setObjectName("spin_anciennete");

        grid_ajouter->addWidget(spin_anciennete, 7, 1, 1, 1);

        label_disp = new QLabel(tabAjouter);
        label_disp->setObjectName("label_disp");

        grid_ajouter->addWidget(label_disp, 8, 0, 1, 1);

        combo_disp = new QComboBox(tabAjouter);
        combo_disp->addItem(QString());
        combo_disp->addItem(QString());
        combo_disp->setObjectName("combo_disp");

        grid_ajouter->addWidget(combo_disp, 8, 1, 1, 1);

        label_heures = new QLabel(tabAjouter);
        label_heures->setObjectName("label_heures");

        grid_ajouter->addWidget(label_heures, 9, 0, 1, 1);

        spin_heures = new QSpinBox(tabAjouter);
        spin_heures->setObjectName("spin_heures");
        spin_heures->setMaximum(168);

        grid_ajouter->addWidget(spin_heures, 9, 1, 1, 1);

        label_fourn = new QLabel(tabAjouter);
        label_fourn->setObjectName("label_fourn");

        grid_ajouter->addWidget(label_fourn, 10, 0, 1, 1);

        spin_fourn = new QSpinBox(tabAjouter);
        spin_fourn->setObjectName("spin_fourn");

        grid_ajouter->addWidget(spin_fourn, 10, 1, 1, 1);


        verticalLayout_ajouter->addLayout(grid_ajouter);

        hButtonsAjouter = new QHBoxLayout();
        hButtonsAjouter->setObjectName("hButtonsAjouter");
        spacerH = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hButtonsAjouter->addItem(spacerH);

        btnAjouter = new QPushButton(tabAjouter);
        btnAjouter->setObjectName("btnAjouter");

        hButtonsAjouter->addWidget(btnAjouter);


        verticalLayout_ajouter->addLayout(hButtonsAjouter);

        tabWidget->addTab(tabAjouter, QString());
        tabListe = new QWidget();
        tabListe->setObjectName("tabListe");
        hLayout_liste = new QHBoxLayout(tabListe);
        hLayout_liste->setObjectName("hLayout_liste");
        sidebarListe = new QFrame(tabListe);
        sidebarListe->setObjectName("sidebarListe");
        sidebarListe->setMinimumWidth(150);
        sidebarListe->setMaximumWidth(180);
        vLayout_sidebar = new QVBoxLayout(sidebarListe);
        vLayout_sidebar->setSpacing(4);
        vLayout_sidebar->setContentsMargins(4, 4, 4, 4);
        vLayout_sidebar->setObjectName("vLayout_sidebar");
        groupSearch = new QGroupBox(sidebarListe);
        groupSearch->setObjectName("groupSearch");
        vSearch = new QVBoxLayout(groupSearch);
        vSearch->setObjectName("vSearch");
        label_search_id = new QLabel(groupSearch);
        label_search_id->setObjectName("label_search_id");

        vSearch->addWidget(label_search_id);

        search_id = new QLineEdit(groupSearch);
        search_id->setObjectName("search_id");

        vSearch->addWidget(search_id);

        label_search_nom = new QLabel(groupSearch);
        label_search_nom->setObjectName("label_search_nom");

        vSearch->addWidget(label_search_nom);

        search_nom = new QLineEdit(groupSearch);
        search_nom->setObjectName("search_nom");

        vSearch->addWidget(search_nom);

        label_search_tel = new QLabel(groupSearch);
        label_search_tel->setObjectName("label_search_tel");

        vSearch->addWidget(label_search_tel);

        search_tel = new QLineEdit(groupSearch);
        search_tel->setObjectName("search_tel");

        vSearch->addWidget(search_tel);

        label_search_spec = new QLabel(groupSearch);
        label_search_spec->setObjectName("label_search_spec");

        vSearch->addWidget(label_search_spec);

        search_spec = new QComboBox(groupSearch);
        search_spec->addItem(QString());
        search_spec->addItem(QString());
        search_spec->addItem(QString());
        search_spec->addItem(QString());
        search_spec->addItem(QString());
        search_spec->setObjectName("search_spec");

        vSearch->addWidget(search_spec);

        label_search_disp = new QLabel(groupSearch);
        label_search_disp->setObjectName("label_search_disp");

        vSearch->addWidget(label_search_disp);

        search_disp = new QComboBox(groupSearch);
        search_disp->addItem(QString());
        search_disp->addItem(QString());
        search_disp->addItem(QString());
        search_disp->setObjectName("search_disp");

        vSearch->addWidget(search_disp);


        vLayout_sidebar->addWidget(groupSearch);

        groupSort = new QGroupBox(sidebarListe);
        groupSort->setObjectName("groupSort");
        vSort = new QVBoxLayout(groupSort);
        vSort->setObjectName("vSort");
        sort_nom = new QRadioButton(groupSort);
        sort_nom->setObjectName("sort_nom");

        vSort->addWidget(sort_nom);

        sort_salaire = new QRadioButton(groupSort);
        sort_salaire->setObjectName("sort_salaire");

        vSort->addWidget(sort_salaire);

        sort_anciennete = new QRadioButton(groupSort);
        sort_anciennete->setObjectName("sort_anciennete");

        vSort->addWidget(sort_anciennete);

        sort_age = new QRadioButton(groupSort);
        sort_age->setObjectName("sort_age");

        vSort->addWidget(sort_age);

        sort_heures = new QRadioButton(groupSort);
        sort_heures->setObjectName("sort_heures");

        vSort->addWidget(sort_heures);

        sort_fournisseurs = new QRadioButton(groupSort);
        sort_fournisseurs->setObjectName("sort_fournisseurs");

        vSort->addWidget(sort_fournisseurs);


        vLayout_sidebar->addWidget(groupSort);

        groupOrder = new QGroupBox(sidebarListe);
        groupOrder->setObjectName("groupOrder");
        vOrder = new QVBoxLayout(groupOrder);
        vOrder->setObjectName("vOrder");
        order_asc = new QRadioButton(groupOrder);
        order_asc->setObjectName("order_asc");
        order_asc->setChecked(true);

        vOrder->addWidget(order_asc);

        order_desc = new QRadioButton(groupOrder);
        order_desc->setObjectName("order_desc");

        vOrder->addWidget(order_desc);


        vLayout_sidebar->addWidget(groupOrder);

        verticalSpacer_liste = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayout_sidebar->addItem(verticalSpacer_liste);


        hLayout_liste->addWidget(sidebarListe);

        mainListe = new QFrame(tabListe);
        mainListe->setObjectName("mainListe");
        vLayout_tableArea = new QVBoxLayout(mainListe);
        vLayout_tableArea->setObjectName("vLayout_tableArea");
        table_employes = new QTableWidget(mainListe);
        if (table_employes->columnCount() < 11)
            table_employes->setColumnCount(11);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        table_employes->setObjectName("table_employes");
        table_employes->setColumnCount(11);

        vLayout_tableArea->addWidget(table_employes);


        hLayout_liste->addWidget(mainListe);

        tabWidget->addTab(tabListe, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        vertical_supprimer = new QVBoxLayout(tabSupprimer);
        vertical_supprimer->setObjectName("vertical_supprimer");
        formSuppr = new QFormLayout();
        formSuppr->setObjectName("formSuppr");
        label_id_suppr = new QLabel(tabSupprimer);
        label_id_suppr->setObjectName("label_id_suppr");

        formSuppr->setWidget(0, QFormLayout::LabelRole, label_id_suppr);

        lineEdit_id_suppr = new QLineEdit(tabSupprimer);
        lineEdit_id_suppr->setObjectName("lineEdit_id_suppr");

        formSuppr->setWidget(0, QFormLayout::FieldRole, lineEdit_id_suppr);


        vertical_supprimer->addLayout(formSuppr);

        btnSupprimerConfirm = new QPushButton(tabSupprimer);
        btnSupprimerConfirm->setObjectName("btnSupprimerConfirm");

        vertical_supprimer->addWidget(btnSupprimerConfirm);

        tabWidget->addTab(tabSupprimer, QString());
        tabModifier = new QWidget();
        tabModifier->setObjectName("tabModifier");
        vertical_modifier = new QVBoxLayout(tabModifier);
        vertical_modifier->setObjectName("vertical_modifier");
        formModifier = new QFormLayout();
        formModifier->setObjectName("formModifier");
        label_id_mod = new QLabel(tabModifier);
        label_id_mod->setObjectName("label_id_mod");

        formModifier->setWidget(0, QFormLayout::LabelRole, label_id_mod);

        lineEdit_id_mod = new QLineEdit(tabModifier);
        lineEdit_id_mod->setObjectName("lineEdit_id_mod");
        lineEdit_id_mod->setReadOnly(true);

        formModifier->setWidget(0, QFormLayout::FieldRole, lineEdit_id_mod);


        vertical_modifier->addLayout(formModifier);

        groupBox_prefill = new QGroupBox(tabModifier);
        groupBox_prefill->setObjectName("groupBox_prefill");
        grid_prefill = new QGridLayout(groupBox_prefill);
        grid_prefill->setObjectName("grid_prefill");
        label_nom_mod = new QLabel(groupBox_prefill);
        label_nom_mod->setObjectName("label_nom_mod");

        grid_prefill->addWidget(label_nom_mod, 0, 0, 1, 1);

        lineEdit_nom_mod = new QLineEdit(groupBox_prefill);
        lineEdit_nom_mod->setObjectName("lineEdit_nom_mod");

        grid_prefill->addWidget(lineEdit_nom_mod, 0, 1, 1, 1);

        label_prenom_mod = new QLabel(groupBox_prefill);
        label_prenom_mod->setObjectName("label_prenom_mod");

        grid_prefill->addWidget(label_prenom_mod, 1, 0, 1, 1);

        lineEdit_prenom_mod = new QLineEdit(groupBox_prefill);
        lineEdit_prenom_mod->setObjectName("lineEdit_prenom_mod");

        grid_prefill->addWidget(lineEdit_prenom_mod, 1, 1, 1, 1);

        label_age_mod = new QLabel(groupBox_prefill);
        label_age_mod->setObjectName("label_age_mod");

        grid_prefill->addWidget(label_age_mod, 2, 0, 1, 1);

        spinBox_age_mod = new QSpinBox(groupBox_prefill);
        spinBox_age_mod->setObjectName("spinBox_age_mod");
        spinBox_age_mod->setMinimum(16);
        spinBox_age_mod->setMaximum(120);

        grid_prefill->addWidget(spinBox_age_mod, 2, 1, 1, 1);

        label_tel_mod = new QLabel(groupBox_prefill);
        label_tel_mod->setObjectName("label_tel_mod");

        grid_prefill->addWidget(label_tel_mod, 3, 0, 1, 1);

        lineEdit_tel_mod = new QLineEdit(groupBox_prefill);
        lineEdit_tel_mod->setObjectName("lineEdit_tel_mod");

        grid_prefill->addWidget(lineEdit_tel_mod, 3, 1, 1, 1);

        label_spec_mod = new QLabel(groupBox_prefill);
        label_spec_mod->setObjectName("label_spec_mod");

        grid_prefill->addWidget(label_spec_mod, 4, 0, 1, 1);

        combo_spec_mod = new QComboBox(groupBox_prefill);
        combo_spec_mod->addItem(QString());
        combo_spec_mod->addItem(QString());
        combo_spec_mod->addItem(QString());
        combo_spec_mod->addItem(QString());
        combo_spec_mod->setObjectName("combo_spec_mod");

        grid_prefill->addWidget(combo_spec_mod, 4, 1, 1, 1);

        label_salaire_mod = new QLabel(groupBox_prefill);
        label_salaire_mod->setObjectName("label_salaire_mod");

        grid_prefill->addWidget(label_salaire_mod, 5, 0, 1, 1);

        doubleSpin_salaire_mod = new QDoubleSpinBox(groupBox_prefill);
        doubleSpin_salaire_mod->setObjectName("doubleSpin_salaire_mod");
        doubleSpin_salaire_mod->setDecimals(2);

        grid_prefill->addWidget(doubleSpin_salaire_mod, 5, 1, 1, 1);

        label_anciennete_mod = new QLabel(groupBox_prefill);
        label_anciennete_mod->setObjectName("label_anciennete_mod");

        grid_prefill->addWidget(label_anciennete_mod, 6, 0, 1, 1);

        spin_anciennete_mod = new QSpinBox(groupBox_prefill);
        spin_anciennete_mod->setObjectName("spin_anciennete_mod");

        grid_prefill->addWidget(spin_anciennete_mod, 6, 1, 1, 1);

        label_disp_mod = new QLabel(groupBox_prefill);
        label_disp_mod->setObjectName("label_disp_mod");

        grid_prefill->addWidget(label_disp_mod, 7, 0, 1, 1);

        combo_disp_mod = new QComboBox(groupBox_prefill);
        combo_disp_mod->addItem(QString());
        combo_disp_mod->addItem(QString());
        combo_disp_mod->setObjectName("combo_disp_mod");

        grid_prefill->addWidget(combo_disp_mod, 7, 1, 1, 1);

        label_heures_mod = new QLabel(groupBox_prefill);
        label_heures_mod->setObjectName("label_heures_mod");

        grid_prefill->addWidget(label_heures_mod, 8, 0, 1, 1);

        spin_heures_mod = new QSpinBox(groupBox_prefill);
        spin_heures_mod->setObjectName("spin_heures_mod");
        spin_heures_mod->setMaximum(168);

        grid_prefill->addWidget(spin_heures_mod, 8, 1, 1, 1);

        label_fourn_mod = new QLabel(groupBox_prefill);
        label_fourn_mod->setObjectName("label_fourn_mod");

        grid_prefill->addWidget(label_fourn_mod, 9, 0, 1, 1);

        spin_fourn_mod = new QSpinBox(groupBox_prefill);
        spin_fourn_mod->setObjectName("spin_fourn_mod");

        grid_prefill->addWidget(spin_fourn_mod, 9, 1, 1, 1);


        vertical_modifier->addWidget(groupBox_prefill);

        btnModifierConfirm = new QPushButton(tabModifier);
        btnModifierConfirm->setObjectName("btnModifierConfirm");

        vertical_modifier->addWidget(btnModifierConfirm);

        tabWidget->addTab(tabModifier, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        vertical_statistiques = new QVBoxLayout(tabStatistiques);
        vertical_statistiques->setObjectName("vertical_statistiques");
        groupEffectifs = new QGroupBox(tabStatistiques);
        groupEffectifs->setObjectName("groupEffectifs");
        vEffectifs = new QVBoxLayout(groupEffectifs);
        vEffectifs->setObjectName("vEffectifs");
        label_total_employes = new QLabel(groupEffectifs);
        label_total_employes->setObjectName("label_total_employes");

        vEffectifs->addWidget(label_total_employes);

        label_par_specialite = new QLabel(groupEffectifs);
        label_par_specialite->setObjectName("label_par_specialite");

        vEffectifs->addWidget(label_par_specialite);

        table_effectifs_spec = new QTableWidget(groupEffectifs);
        if (table_effectifs_spec->columnCount() < 2)
            table_effectifs_spec->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_effectifs_spec->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        table_effectifs_spec->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        table_effectifs_spec->setObjectName("table_effectifs_spec");
        table_effectifs_spec->setMaximumHeight(150);
        table_effectifs_spec->setColumnCount(2);

        vEffectifs->addWidget(table_effectifs_spec);

        label_par_disponibilite = new QLabel(groupEffectifs);
        label_par_disponibilite->setObjectName("label_par_disponibilite");

        vEffectifs->addWidget(label_par_disponibilite);

        table_effectifs_disp = new QTableWidget(groupEffectifs);
        if (table_effectifs_disp->columnCount() < 2)
            table_effectifs_disp->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        table_effectifs_disp->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        table_effectifs_disp->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        table_effectifs_disp->setObjectName("table_effectifs_disp");
        table_effectifs_disp->setMaximumHeight(120);
        table_effectifs_disp->setColumnCount(2);

        vEffectifs->addWidget(table_effectifs_disp);


        vertical_statistiques->addWidget(groupEffectifs);

        groupFinances = new QGroupBox(tabStatistiques);
        groupFinances->setObjectName("groupFinances");
        vFinances = new QVBoxLayout(groupFinances);
        vFinances->setObjectName("vFinances");
        label_masse_salariale = new QLabel(groupFinances);
        label_masse_salariale->setObjectName("label_masse_salariale");

        vFinances->addWidget(label_masse_salariale);

        label_salaire_moyen = new QLabel(groupFinances);
        label_salaire_moyen->setObjectName("label_salaire_moyen");

        vFinances->addWidget(label_salaire_moyen);

        label_par_specialite_sal = new QLabel(groupFinances);
        label_par_specialite_sal->setObjectName("label_par_specialite_sal");

        vFinances->addWidget(label_par_specialite_sal);

        table_finances_spec = new QTableWidget(groupFinances);
        if (table_finances_spec->columnCount() < 2)
            table_finances_spec->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        table_finances_spec->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        table_finances_spec->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        table_finances_spec->setObjectName("table_finances_spec");
        table_finances_spec->setMaximumHeight(150);
        table_finances_spec->setColumnCount(2);

        vFinances->addWidget(table_finances_spec);


        vertical_statistiques->addWidget(groupFinances);

        groupPerformance = new QGroupBox(tabStatistiques);
        groupPerformance->setObjectName("groupPerformance");
        vPerformance = new QVBoxLayout(groupPerformance);
        vPerformance->setObjectName("vPerformance");
        label_anciennete_moyenne = new QLabel(groupPerformance);
        label_anciennete_moyenne->setObjectName("label_anciennete_moyenne");

        vPerformance->addWidget(label_anciennete_moyenne);

        label_heures_moyennes = new QLabel(groupPerformance);
        label_heures_moyennes->setObjectName("label_heures_moyennes");

        vPerformance->addWidget(label_heures_moyennes);

        label_fournisseurs_moyen = new QLabel(groupPerformance);
        label_fournisseurs_moyen->setObjectName("label_fournisseurs_moyen");

        vPerformance->addWidget(label_fournisseurs_moyen);

        spacerPerf = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vPerformance->addItem(spacerPerf);


        vertical_statistiques->addWidget(groupPerformance);

        verticalSpacer_stats = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_statistiques->addItem(verticalSpacer_stats);

        tabWidget->addTab(tabStatistiques, QString());
        tabExportPdf = new QWidget();
        tabExportPdf->setObjectName("tabExportPdf");
        vertical_export_pdf = new QVBoxLayout(tabExportPdf);
        vertical_export_pdf->setObjectName("vertical_export_pdf");
        groupExportOptions = new QGroupBox(tabExportPdf);
        groupExportOptions->setObjectName("groupExportOptions");
        vExportOptions = new QVBoxLayout(groupExportOptions);
        vExportOptions->setObjectName("vExportOptions");
        btnExportListeComplete = new QPushButton(groupExportOptions);
        btnExportListeComplete->setObjectName("btnExportListeComplete");
        btnExportListeComplete->setMinimumHeight(50);

        vExportOptions->addWidget(btnExportListeComplete);

        btnExportRapportRH = new QPushButton(groupExportOptions);
        btnExportRapportRH->setObjectName("btnExportRapportRH");
        btnExportRapportRH->setMinimumHeight(50);

        vExportOptions->addWidget(btnExportRapportRH);

        btnExportFicheEmploye = new QPushButton(groupExportOptions);
        btnExportFicheEmploye->setObjectName("btnExportFicheEmploye");
        btnExportFicheEmploye->setMinimumHeight(50);

        vExportOptions->addWidget(btnExportFicheEmploye);


        vertical_export_pdf->addWidget(groupExportOptions);

        groupIdExport = new QGroupBox(tabExportPdf);
        groupIdExport->setObjectName("groupIdExport");
        formIdExport = new QFormLayout(groupIdExport);
        formIdExport->setObjectName("formIdExport");
        label_id_export = new QLabel(groupIdExport);
        label_id_export->setObjectName("label_id_export");

        formIdExport->setWidget(0, QFormLayout::LabelRole, label_id_export);

        lineEdit_id_export = new QLineEdit(groupIdExport);
        lineEdit_id_export->setObjectName("lineEdit_id_export");

        formIdExport->setWidget(0, QFormLayout::FieldRole, lineEdit_id_export);


        vertical_export_pdf->addWidget(groupIdExport);

        groupMessagesExport = new QGroupBox(tabExportPdf);
        groupMessagesExport->setObjectName("groupMessagesExport");
        vMessagesExport = new QVBoxLayout(groupMessagesExport);
        vMessagesExport->setObjectName("vMessagesExport");
        textEdit_export_messages = new QTextEdit(groupMessagesExport);
        textEdit_export_messages->setObjectName("textEdit_export_messages");
        textEdit_export_messages->setReadOnly(true);
        textEdit_export_messages->setMaximumHeight(100);

        vMessagesExport->addWidget(textEdit_export_messages);


        vertical_export_pdf->addWidget(groupMessagesExport);

        verticalSpacer_export = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_export_pdf->addItem(verticalSpacer_export);

        tabWidget->addTab(tabExportPdf, QString());
        tabConnexion = new QWidget();
        tabConnexion->setObjectName("tabConnexion");
        vertical_connexion = new QVBoxLayout(tabConnexion);
        vertical_connexion->setObjectName("vertical_connexion");
        groupConnexion = new QGroupBox(tabConnexion);
        groupConnexion->setObjectName("groupConnexion");
        formConnexion = new QFormLayout(groupConnexion);
        formConnexion->setObjectName("formConnexion");
        label_user_conn = new QLabel(groupConnexion);
        label_user_conn->setObjectName("label_user_conn");

        formConnexion->setWidget(0, QFormLayout::LabelRole, label_user_conn);

        line_user_conn = new QLineEdit(groupConnexion);
        line_user_conn->setObjectName("line_user_conn");

        formConnexion->setWidget(0, QFormLayout::FieldRole, line_user_conn);

        label_pass_conn = new QLabel(groupConnexion);
        label_pass_conn->setObjectName("label_pass_conn");

        formConnexion->setWidget(1, QFormLayout::LabelRole, label_pass_conn);

        line_pass_conn = new QLineEdit(groupConnexion);
        line_pass_conn->setObjectName("line_pass_conn");
        line_pass_conn->setEchoMode(QLineEdit::Password);

        formConnexion->setWidget(1, QFormLayout::FieldRole, line_pass_conn);


        vertical_connexion->addWidget(groupConnexion);

        hButtonsConn = new QHBoxLayout();
        hButtonsConn->setObjectName("hButtonsConn");
        btnSeConnecter = new QPushButton(tabConnexion);
        btnSeConnecter->setObjectName("btnSeConnecter");

        hButtonsConn->addWidget(btnSeConnecter);

        spacerConnH = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hButtonsConn->addItem(spacerConnH);

        btnNavigateForgot = new QPushButton(tabConnexion);
        btnNavigateForgot->setObjectName("btnNavigateForgot");

        hButtonsConn->addWidget(btnNavigateForgot);


        vertical_connexion->addLayout(hButtonsConn);

        tabWidget->addTab(tabConnexion, QString());
        tabMotPasseOublie = new QWidget();
        tabMotPasseOublie->setObjectName("tabMotPasseOublie");
        vertical_mdp_oublie = new QVBoxLayout(tabMotPasseOublie);
        vertical_mdp_oublie->setObjectName("vertical_mdp_oublie");
        groupFPStep1 = new QGroupBox(tabMotPasseOublie);
        groupFPStep1->setObjectName("groupFPStep1");
        formFP1 = new QFormLayout(groupFPStep1);
        formFP1->setObjectName("formFP1");
        label_user_email_fp = new QLabel(groupFPStep1);
        label_user_email_fp->setObjectName("label_user_email_fp");

        formFP1->setWidget(0, QFormLayout::LabelRole, label_user_email_fp);

        line_user_email_fp = new QLineEdit(groupFPStep1);
        line_user_email_fp->setObjectName("line_user_email_fp");

        formFP1->setWidget(0, QFormLayout::FieldRole, line_user_email_fp);

        btnEnvoyerCode = new QPushButton(groupFPStep1);
        btnEnvoyerCode->setObjectName("btnEnvoyerCode");

        formFP1->setWidget(1, QFormLayout::SpanningRole, btnEnvoyerCode);


        vertical_mdp_oublie->addWidget(groupFPStep1);

        groupFPStep2 = new QGroupBox(tabMotPasseOublie);
        groupFPStep2->setObjectName("groupFPStep2");
        formFP2 = new QFormLayout(groupFPStep2);
        formFP2->setObjectName("formFP2");
        label_code_fp = new QLabel(groupFPStep2);
        label_code_fp->setObjectName("label_code_fp");

        formFP2->setWidget(0, QFormLayout::LabelRole, label_code_fp);

        line_code_fp = new QLineEdit(groupFPStep2);
        line_code_fp->setObjectName("line_code_fp");

        formFP2->setWidget(0, QFormLayout::FieldRole, line_code_fp);

        label_newpass_fp = new QLabel(groupFPStep2);
        label_newpass_fp->setObjectName("label_newpass_fp");

        formFP2->setWidget(1, QFormLayout::LabelRole, label_newpass_fp);

        line_newpass_fp = new QLineEdit(groupFPStep2);
        line_newpass_fp->setObjectName("line_newpass_fp");
        line_newpass_fp->setEchoMode(QLineEdit::Password);

        formFP2->setWidget(1, QFormLayout::FieldRole, line_newpass_fp);

        label_confirm_fp = new QLabel(groupFPStep2);
        label_confirm_fp->setObjectName("label_confirm_fp");

        formFP2->setWidget(2, QFormLayout::LabelRole, label_confirm_fp);

        line_confirm_fp = new QLineEdit(groupFPStep2);
        line_confirm_fp->setObjectName("line_confirm_fp");
        line_confirm_fp->setEchoMode(QLineEdit::Password);

        formFP2->setWidget(2, QFormLayout::FieldRole, line_confirm_fp);

        hButtons_mdp = new QHBoxLayout();
        hButtons_mdp->setObjectName("hButtons_mdp");
        btnResetPassword = new QPushButton(groupFPStep2);
        btnResetPassword->setObjectName("btnResetPassword");

        hButtons_mdp->addWidget(btnResetPassword);

        btnBackToLogin = new QPushButton(groupFPStep2);
        btnBackToLogin->setObjectName("btnBackToLogin");

        hButtons_mdp->addWidget(btnBackToLogin);


        formFP2->setLayout(3, QFormLayout::SpanningRole, hButtons_mdp);


        vertical_mdp_oublie->addWidget(groupFPStep2);

        groupFPMessages = new QGroupBox(tabMotPasseOublie);
        groupFPMessages->setObjectName("groupFPMessages");
        vFPMessages = new QVBoxLayout(groupFPMessages);
        vFPMessages->setObjectName("vFPMessages");
        textEdit_fp_messages = new QTextEdit(groupFPMessages);
        textEdit_fp_messages->setObjectName("textEdit_fp_messages");
        textEdit_fp_messages->setReadOnly(true);
        textEdit_fp_messages->setMaximumHeight(100);

        vFPMessages->addWidget(textEdit_fp_messages);


        vertical_mdp_oublie->addWidget(groupFPMessages);

        tabWidget->addTab(tabMotPasseOublie, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(EmployeWidget);

        QMetaObject::connectSlotsByName(EmployeWidget);
    } // setupUi

    void retranslateUi(QWidget *EmployeWidget)
    {
        label_id->setText(QCoreApplication::translate("EmployeWidget", "ID", nullptr));
        label_nom->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        label_prenom->setText(QCoreApplication::translate("EmployeWidget", "Pr\303\251nom", nullptr));
        label_age->setText(QCoreApplication::translate("EmployeWidget", "\303\202ge", nullptr));
        label_tel->setText(QCoreApplication::translate("EmployeWidget", "T\303\251l\303\251phone", nullptr));
        label_spec->setText(QCoreApplication::translate("EmployeWidget", "Sp\303\251cialit\303\251", nullptr));
        combo_spec->setItemText(0, QCoreApplication::translate("EmployeWidget", "Admin", nullptr));
        combo_spec->setItemText(1, QCoreApplication::translate("EmployeWidget", "Manager", nullptr));
        combo_spec->setItemText(2, QCoreApplication::translate("EmployeWidget", "Technicien", nullptr));
        combo_spec->setItemText(3, QCoreApplication::translate("EmployeWidget", "Magasinier", nullptr));

        label_salaire->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        doubleSpin_salaire->setPrefix(QCoreApplication::translate("EmployeWidget", "\342\202\254 ", nullptr));
        label_anciennete->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251", nullptr));
        label_disp->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251", nullptr));
        combo_disp->setItemText(0, QCoreApplication::translate("EmployeWidget", "Actif", nullptr));
        combo_disp->setItemText(1, QCoreApplication::translate("EmployeWidget", "Suspendu", nullptr));

        label_heures->setText(QCoreApplication::translate("EmployeWidget", "Heures / semaine", nullptr));
        label_fourn->setText(QCoreApplication::translate("EmployeWidget", "Fournisseurs trait\303\251s", nullptr));
        btnAjouter->setText(QCoreApplication::translate("EmployeWidget", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("EmployeWidget", "Ajouter un employ\303\251", nullptr));
        groupSearch->setTitle(QCoreApplication::translate("EmployeWidget", "Recherche", nullptr));
        label_search_id->setText(QCoreApplication::translate("EmployeWidget", "ID", nullptr));
        search_id->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez ID...", nullptr));
        label_search_nom->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        search_nom->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez nom...", nullptr));
        label_search_tel->setText(QCoreApplication::translate("EmployeWidget", "T\303\251l\303\251phone", nullptr));
        search_tel->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez tel...", nullptr));
        label_search_spec->setText(QCoreApplication::translate("EmployeWidget", "Sp\303\251cialit\303\251", nullptr));
        search_spec->setItemText(0, QCoreApplication::translate("EmployeWidget", "-- Tous --", nullptr));
        search_spec->setItemText(1, QCoreApplication::translate("EmployeWidget", "Admin", nullptr));
        search_spec->setItemText(2, QCoreApplication::translate("EmployeWidget", "Manager", nullptr));
        search_spec->setItemText(3, QCoreApplication::translate("EmployeWidget", "Technicien", nullptr));
        search_spec->setItemText(4, QCoreApplication::translate("EmployeWidget", "Magasinier", nullptr));

        label_search_disp->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251", nullptr));
        search_disp->setItemText(0, QCoreApplication::translate("EmployeWidget", "-- Tous --", nullptr));
        search_disp->setItemText(1, QCoreApplication::translate("EmployeWidget", "Actif", nullptr));
        search_disp->setItemText(2, QCoreApplication::translate("EmployeWidget", "Suspendu", nullptr));

        groupSort->setTitle(QCoreApplication::translate("EmployeWidget", "Tri", nullptr));
        sort_nom->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        sort_salaire->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        sort_anciennete->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251", nullptr));
        sort_age->setText(QCoreApplication::translate("EmployeWidget", "\303\202ge", nullptr));
        sort_heures->setText(QCoreApplication::translate("EmployeWidget", "Heures", nullptr));
        sort_fournisseurs->setText(QCoreApplication::translate("EmployeWidget", "Fournisseurs", nullptr));
        groupOrder->setTitle(QCoreApplication::translate("EmployeWidget", "Ordre", nullptr));
        order_asc->setText(QCoreApplication::translate("EmployeWidget", "Croissant", nullptr));
        order_desc->setText(QCoreApplication::translate("EmployeWidget", "D\303\251croissant", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_employes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EmployeWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_employes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_employes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EmployeWidget", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_employes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EmployeWidget", "\303\202ge", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_employes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EmployeWidget", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_employes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("EmployeWidget", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_employes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_employes->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_employes->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_employes->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("EmployeWidget", "Heures", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table_employes->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("EmployeWidget", "Fournisseurs", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("EmployeWidget", "Liste des employ\303\251s", nullptr));
        label_id_suppr->setText(QCoreApplication::translate("EmployeWidget", "ID Employ\303\251", nullptr));
        btnSupprimerConfirm->setText(QCoreApplication::translate("EmployeWidget", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("EmployeWidget", "Supprimer un employ\303\251", nullptr));
        label_id_mod->setText(QCoreApplication::translate("EmployeWidget", "ID Employ\303\251", nullptr));
        groupBox_prefill->setTitle(QCoreApplication::translate("EmployeWidget", "Modifier les donn\303\251es", nullptr));
        label_nom_mod->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        label_prenom_mod->setText(QCoreApplication::translate("EmployeWidget", "Pr\303\251nom", nullptr));
        label_age_mod->setText(QCoreApplication::translate("EmployeWidget", "\303\202ge", nullptr));
        label_tel_mod->setText(QCoreApplication::translate("EmployeWidget", "T\303\251l\303\251phone", nullptr));
        label_spec_mod->setText(QCoreApplication::translate("EmployeWidget", "Sp\303\251cialit\303\251", nullptr));
        combo_spec_mod->setItemText(0, QCoreApplication::translate("EmployeWidget", "Admin", nullptr));
        combo_spec_mod->setItemText(1, QCoreApplication::translate("EmployeWidget", "Manager", nullptr));
        combo_spec_mod->setItemText(2, QCoreApplication::translate("EmployeWidget", "Technicien", nullptr));
        combo_spec_mod->setItemText(3, QCoreApplication::translate("EmployeWidget", "Magasinier", nullptr));

        label_salaire_mod->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        doubleSpin_salaire_mod->setPrefix(QCoreApplication::translate("EmployeWidget", "\342\202\254 ", nullptr));
        label_anciennete_mod->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251", nullptr));
        label_disp_mod->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251", nullptr));
        combo_disp_mod->setItemText(0, QCoreApplication::translate("EmployeWidget", "Actif", nullptr));
        combo_disp_mod->setItemText(1, QCoreApplication::translate("EmployeWidget", "Suspendu", nullptr));

        label_heures_mod->setText(QCoreApplication::translate("EmployeWidget", "Heures / semaine", nullptr));
        label_fourn_mod->setText(QCoreApplication::translate("EmployeWidget", "Fournisseurs trait\303\251s", nullptr));
        btnModifierConfirm->setText(QCoreApplication::translate("EmployeWidget", "Mettre \303\240 jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("EmployeWidget", "Modifier un employ\303\251", nullptr));
        groupEffectifs->setTitle(QCoreApplication::translate("EmployeWidget", "Effectifs", nullptr));
        label_total_employes->setText(QCoreApplication::translate("EmployeWidget", "Nombre total d'employ\303\251s : 0", nullptr));
        label_par_specialite->setText(QCoreApplication::translate("EmployeWidget", "Nombre par sp\303\251cialit\303\251 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table_effectifs_spec->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("EmployeWidget", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = table_effectifs_spec->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("EmployeWidget", "Nombre", nullptr));
        label_par_disponibilite->setText(QCoreApplication::translate("EmployeWidget", "Nombre par disponibilit\303\251 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = table_effectifs_disp->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = table_effectifs_disp->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("EmployeWidget", "Nombre", nullptr));
        groupFinances->setTitle(QCoreApplication::translate("EmployeWidget", "Finances", nullptr));
        label_masse_salariale->setText(QCoreApplication::translate("EmployeWidget", "Masse salariale totale : 0.00 \342\202\254", nullptr));
        label_salaire_moyen->setText(QCoreApplication::translate("EmployeWidget", "Salaire moyen : 0.00 \342\202\254", nullptr));
        label_par_specialite_sal->setText(QCoreApplication::translate("EmployeWidget", "Masse salariale par sp\303\251cialit\303\251 :", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = table_finances_spec->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("EmployeWidget", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = table_finances_spec->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("EmployeWidget", "Masse salariale (\342\202\254)", nullptr));
        groupPerformance->setTitle(QCoreApplication::translate("EmployeWidget", "Performance", nullptr));
        label_anciennete_moyenne->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251 moyenne : 0 ans", nullptr));
        label_heures_moyennes->setText(QCoreApplication::translate("EmployeWidget", "Heures de travail moyennes : 0 h/semaine", nullptr));
        label_fournisseurs_moyen->setText(QCoreApplication::translate("EmployeWidget", "Nombre moyen de fournisseurs : 0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("EmployeWidget", "Statistiques", nullptr));
        groupExportOptions->setTitle(QCoreApplication::translate("EmployeWidget", "Options d'export", nullptr));
        btnExportListeComplete->setText(QCoreApplication::translate("EmployeWidget", "\360\237\223\204 Exporter la liste compl\303\250te des employ\303\251s (PDF)", nullptr));
        btnExportRapportRH->setText(QCoreApplication::translate("EmployeWidget", "\360\237\223\212 Exporter un rapport statistiques RH (PDF)", nullptr));
        btnExportFicheEmploye->setText(QCoreApplication::translate("EmployeWidget", "\360\237\223\213 Exporter la fiche d'un employ\303\251 par ID (PDF)", nullptr));
        groupIdExport->setTitle(QCoreApplication::translate("EmployeWidget", "Param\303\250tres d'export", nullptr));
        label_id_export->setText(QCoreApplication::translate("EmployeWidget", "ID Employ\303\251 (pour la fiche)", nullptr));
        groupMessagesExport->setTitle(QCoreApplication::translate("EmployeWidget", "Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExportPdf), QCoreApplication::translate("EmployeWidget", "Export PDF", nullptr));
        groupConnexion->setTitle(QCoreApplication::translate("EmployeWidget", "Connexion administrateur", nullptr));
        label_user_conn->setText(QCoreApplication::translate("EmployeWidget", "Identifiant", nullptr));
        label_pass_conn->setText(QCoreApplication::translate("EmployeWidget", "Mot de passe", nullptr));
        btnSeConnecter->setText(QCoreApplication::translate("EmployeWidget", "Se connecter", nullptr));
        btnNavigateForgot->setText(QCoreApplication::translate("EmployeWidget", "Mot de passe oubli\303\251 ?", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConnexion), QCoreApplication::translate("EmployeWidget", "Connexion", nullptr));
        groupFPStep1->setTitle(QCoreApplication::translate("EmployeWidget", "\303\211tape 1 \342\200\224 Demander code", nullptr));
        label_user_email_fp->setText(QCoreApplication::translate("EmployeWidget", "Identifiant / Email", nullptr));
        btnEnvoyerCode->setText(QCoreApplication::translate("EmployeWidget", "Envoyer code", nullptr));
        groupFPStep2->setTitle(QCoreApplication::translate("EmployeWidget", "\303\211tape 2 \342\200\224 R\303\251initialiser", nullptr));
        label_code_fp->setText(QCoreApplication::translate("EmployeWidget", "Code", nullptr));
        label_newpass_fp->setText(QCoreApplication::translate("EmployeWidget", "Nouveau mot de passe", nullptr));
        label_confirm_fp->setText(QCoreApplication::translate("EmployeWidget", "Confirmation", nullptr));
        btnResetPassword->setText(QCoreApplication::translate("EmployeWidget", "R\303\251initialiser", nullptr));
        btnBackToLogin->setText(QCoreApplication::translate("EmployeWidget", "Retour \303\240 Connexion", nullptr));
        groupFPMessages->setTitle(QCoreApplication::translate("EmployeWidget", "Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMotPasseOublie), QCoreApplication::translate("EmployeWidget", "Mot de passe oubli\303\251", nullptr));
        (void)EmployeWidget;
    } // retranslateUi

};

namespace Ui {
    class EmployeWidget: public Ui_EmployeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_WIDGET_H
