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
#include <QtWidgets/QCheckBox>
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
#include <QtWidgets/QPushButton>
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
    QLabel *labelNom;
    QLineEdit *lineNom;
    QLabel *labelPrenom;
    QLineEdit *linePrenom;
    QLabel *labelEmail;
    QLineEdit *lineEmail;
    QLabel *labelPoste;
    QComboBox *comboPoste;
    QLabel *labelSalaire;
    QDoubleSpinBox *spinSalaire;
    QLabel *labelDateEmbauche;
    QLineEdit *lineDateEmbauche;
    QHBoxLayout *hButtonsAjouter;
    QSpacerItem *horizontalSpacer_ajouter;
    QPushButton *btnAjouter;
    QPushButton *btnResetAjouter;
    QWidget *tabListe;
    QHBoxLayout *hLayout_liste;
    QFrame *sidebarListe;
    QVBoxLayout *vLayoutSidebar;
    QLabel *labelFiltres;
    QCheckBox *checkFiltreTous;
    QCheckBox *checkFiltreActifs;
    QCheckBox *checkFiltreInactifs;
    QSpacerItem *verticalSpacer_sidebar;
    QFrame *mainListe;
    QVBoxLayout *vLayoutMain;
    QTableWidget *tableEmployes;
    QWidget *tabSupprimer;
    QVBoxLayout *vertical_supprimer;
    QFormLayout *formSuppr;
    QLabel *labelIdSuppr;
    QLineEdit *lineIdSuppr;
    QPushButton *btnSupprimerConfirm;
    QWidget *tabModifier;
    QVBoxLayout *vertical_modifier;
    QFormLayout *formModifier;
    QLabel *labelIdMod;
    QLineEdit *lineIdMod;
    QGroupBox *groupBox_prefill;
    QGridLayout *gridPrefill;
    QLabel *labelSalaireModif;
    QDoubleSpinBox *spinSalaireModif;
    QLabel *labelPosteModif;
    QComboBox *comboPosteModif;
    QPushButton *btnModifierConfirm;
    QWidget *tabRechercheTri;
    QVBoxLayout *vertical_recherche_tri_emp;
    QGroupBox *groupRechercheEmp;
    QGridLayout *gridRechercheEmp;
    QLabel *labelSearchNom;
    QLineEdit *lineSearchNom;
    QLabel *labelSearchIdBadge;
    QLineEdit *lineSearchIdBadge;
    QLabel *labelSearchSalaire;
    QDoubleSpinBox *doubleSearchSalaireMin;
    QLabel *labelSearchSalaireEt;
    QDoubleSpinBox *doubleSearchSalaireMax;
    QLabel *labelSearchAnciennete;
    QSpinBox *spinSearchAnciennete;
    QGroupBox *groupTriEmp;
    QGridLayout *gridTriEmp;
    QLabel *labelTriParEmp;
    QComboBox *comboTriParEmp;
    QSpacerItem *horizontalSpacer_tri_emp;
    QHBoxLayout *hLayoutSearchButtonsEmp;
    QSpacerItem *horizontalSpacer_search_emp;
    QPushButton *btnAppliquerRechercheEmp;
    QPushButton *btnReinitialiserRechercheEmp;
    QTableWidget *tableResultatsRechercheEmp;
    QWidget *tabStatistiques;
    QVBoxLayout *vertical_statistiques;
    QGroupBox *groupEffectifs;
    QGridLayout *gridStatEffectifs;
    QLabel *labelTotalEmp;
    QLineEdit *lineTotalEmp;
    QLabel *labelActifs;
    QLineEdit *lineActifs;
    QGroupBox *groupFinances;
    QGridLayout *gridStatFinances;
    QLabel *labelMasseSalariale;
    QLineEdit *lineMasseSalariale;
    QLabel *labelSalaireMoyen;
    QLineEdit *lineSalaireMoyen;
    QGroupBox *groupPerformance;
    QGridLayout *gridStatPerformance;
    QLabel *labelMoyennePerf;
    QLineEdit *lineMoyennePerf;
    QSpacerItem *verticalSpacer_stats;
    QWidget *tabStatistiquesAvancees;
    QVBoxLayout *vertical_statistiques_avancees;
    QGroupBox *groupSalairesVsMissions;
    QVBoxLayout *vLayoutSalairesVsMissions;
    QTableWidget *tableSalairesVsMissions;
    QGroupBox *groupDépensesEmployes;
    QVBoxLayout *vLayoutDépensesEmployes;
    QHBoxLayout *hLayoutDépensesControls;
    QLabel *labelMoisDépenses;
    QComboBox *comboMoisDépenses;
    QSpacerItem *horizontalSpacer_depenses;
    QTableWidget *tableDépensesEmployes;
    QGroupBox *groupIndiceRendement;
    QVBoxLayout *vLayoutIndiceRendement;
    QHBoxLayout *hLayoutIndiceControls;
    QLabel *labelMoisIndice;
    QComboBox *comboMoisIndice;
    QSpinBox *spinAnneeIndice;
    QSpacerItem *horizontalSpacer_indice;
    QTableWidget *tableIndiceRendement;
    QSpacerItem *verticalSpacer_adv_stats;
    QWidget *tabAuthentication;
    QVBoxLayout *vertical_authentication;
    QGroupBox *groupPasswordReset;
    QGridLayout *gridPasswordReset;
    QLabel *labelEmailReset;
    QLineEdit *lineEmailReset;
    QLabel *labelSecurityQuestion;
    QComboBox *comboSecurityQuestion;
    QLabel *labelSecurityAnswer;
    QLineEdit *lineSecurityAnswer;
    QLabel *labelNewPassword;
    QLineEdit *lineNewPassword;
    QLabel *labelConfirmPassword;
    QLineEdit *lineConfirmPassword;
    QHBoxLayout *hLayoutPasswordButtons;
    QSpacerItem *horizontalSpacer_password;
    QPushButton *btnResetPassword;
    QGroupBox *groupContractGeneration;
    QGridLayout *gridContractGeneration;
    QLabel *labelIdEmployeContract;
    QLineEdit *lineIdEmployeContract;
    QLabel *labelContractType;
    QComboBox *comboContractType;
    QLabel *labelDateDebut;
    QDateEdit *dateContractStart;
    QLabel *labelDureeContrat;
    QSpinBox *spinContractDuration;
    QLabel *labelSalaireContrat;
    QDoubleSpinBox *spinSalaryContract;
    QLabel *labelAccessLevel;
    QComboBox *comboAccessLevel;
    QHBoxLayout *hLayoutContractButtons;
    QSpacerItem *horizontalSpacer_contract;
    QPushButton *btnGenerateContractAI;
    QPushButton *btnExportContract;
    QTextEdit *textContractPreview;
    QSpacerItem *verticalSpacer_authentication;
    QWidget *tabExportPdf;
    QVBoxLayout *vertical_export_pdf;
    QGroupBox *groupExportOptions;
    QVBoxLayout *vLayoutExportOptions;
    QCheckBox *checkExportTous;
    QCheckBox *checkExportFiltre;
    QGroupBox *groupIdExport;
    QHBoxLayout *hLayoutIdExport;
    QPushButton *btnExportListeComplete;
    QPushButton *btnExportRapportRH;
    QPushButton *btnExportFicheEmploye;
    QGroupBox *groupMessagesExport;
    QVBoxLayout *vLayoutMessagesExport;
    QLineEdit *lineExportMessages;
    QSpacerItem *verticalSpacer_export;

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
        labelNom = new QLabel(tabAjouter);
        labelNom->setObjectName("labelNom");

        grid_ajouter->addWidget(labelNom, 0, 0, 1, 1);

        lineNom = new QLineEdit(tabAjouter);
        lineNom->setObjectName("lineNom");

        grid_ajouter->addWidget(lineNom, 0, 1, 1, 1);

        labelPrenom = new QLabel(tabAjouter);
        labelPrenom->setObjectName("labelPrenom");

        grid_ajouter->addWidget(labelPrenom, 1, 0, 1, 1);

        linePrenom = new QLineEdit(tabAjouter);
        linePrenom->setObjectName("linePrenom");

        grid_ajouter->addWidget(linePrenom, 1, 1, 1, 1);

        labelEmail = new QLabel(tabAjouter);
        labelEmail->setObjectName("labelEmail");

        grid_ajouter->addWidget(labelEmail, 2, 0, 1, 1);

        lineEmail = new QLineEdit(tabAjouter);
        lineEmail->setObjectName("lineEmail");

        grid_ajouter->addWidget(lineEmail, 2, 1, 1, 1);

        labelPoste = new QLabel(tabAjouter);
        labelPoste->setObjectName("labelPoste");

        grid_ajouter->addWidget(labelPoste, 3, 0, 1, 1);

        comboPoste = new QComboBox(tabAjouter);
        comboPoste->setObjectName("comboPoste");

        grid_ajouter->addWidget(comboPoste, 3, 1, 1, 1);

        labelSalaire = new QLabel(tabAjouter);
        labelSalaire->setObjectName("labelSalaire");

        grid_ajouter->addWidget(labelSalaire, 4, 0, 1, 1);

        spinSalaire = new QDoubleSpinBox(tabAjouter);
        spinSalaire->setObjectName("spinSalaire");

        grid_ajouter->addWidget(spinSalaire, 4, 1, 1, 1);

        labelDateEmbauche = new QLabel(tabAjouter);
        labelDateEmbauche->setObjectName("labelDateEmbauche");

        grid_ajouter->addWidget(labelDateEmbauche, 5, 0, 1, 1);

        lineDateEmbauche = new QLineEdit(tabAjouter);
        lineDateEmbauche->setObjectName("lineDateEmbauche");

        grid_ajouter->addWidget(lineDateEmbauche, 5, 1, 1, 1);


        verticalLayout_ajouter->addLayout(grid_ajouter);

        hButtonsAjouter = new QHBoxLayout();
        hButtonsAjouter->setObjectName("hButtonsAjouter");
        horizontalSpacer_ajouter = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hButtonsAjouter->addItem(horizontalSpacer_ajouter);

        btnAjouter = new QPushButton(tabAjouter);
        btnAjouter->setObjectName("btnAjouter");

        hButtonsAjouter->addWidget(btnAjouter);

        btnResetAjouter = new QPushButton(tabAjouter);
        btnResetAjouter->setObjectName("btnResetAjouter");

        hButtonsAjouter->addWidget(btnResetAjouter);


        verticalLayout_ajouter->addLayout(hButtonsAjouter);

        tabWidget->addTab(tabAjouter, QString());
        tabListe = new QWidget();
        tabListe->setObjectName("tabListe");
        hLayout_liste = new QHBoxLayout(tabListe);
        hLayout_liste->setObjectName("hLayout_liste");
        sidebarListe = new QFrame(tabListe);
        sidebarListe->setObjectName("sidebarListe");
        sidebarListe->setMinimumWidth(150);
        vLayoutSidebar = new QVBoxLayout(sidebarListe);
        vLayoutSidebar->setObjectName("vLayoutSidebar");
        labelFiltres = new QLabel(sidebarListe);
        labelFiltres->setObjectName("labelFiltres");

        vLayoutSidebar->addWidget(labelFiltres);

        checkFiltreTous = new QCheckBox(sidebarListe);
        checkFiltreTous->setObjectName("checkFiltreTous");
        checkFiltreTous->setChecked(true);

        vLayoutSidebar->addWidget(checkFiltreTous);

        checkFiltreActifs = new QCheckBox(sidebarListe);
        checkFiltreActifs->setObjectName("checkFiltreActifs");

        vLayoutSidebar->addWidget(checkFiltreActifs);

        checkFiltreInactifs = new QCheckBox(sidebarListe);
        checkFiltreInactifs->setObjectName("checkFiltreInactifs");

        vLayoutSidebar->addWidget(checkFiltreInactifs);

        verticalSpacer_sidebar = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayoutSidebar->addItem(verticalSpacer_sidebar);


        hLayout_liste->addWidget(sidebarListe);

        mainListe = new QFrame(tabListe);
        mainListe->setObjectName("mainListe");
        vLayoutMain = new QVBoxLayout(mainListe);
        vLayoutMain->setObjectName("vLayoutMain");
        tableEmployes = new QTableWidget(mainListe);
        if (tableEmployes->columnCount() < 6)
            tableEmployes->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableEmployes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableEmployes->setObjectName("tableEmployes");
        tableEmployes->setAlternatingRowColors(true);

        vLayoutMain->addWidget(tableEmployes);


        hLayout_liste->addWidget(mainListe);

        tabWidget->addTab(tabListe, QString());
        tabSupprimer = new QWidget();
        tabSupprimer->setObjectName("tabSupprimer");
        vertical_supprimer = new QVBoxLayout(tabSupprimer);
        vertical_supprimer->setObjectName("vertical_supprimer");
        formSuppr = new QFormLayout();
        formSuppr->setObjectName("formSuppr");
        labelIdSuppr = new QLabel(tabSupprimer);
        labelIdSuppr->setObjectName("labelIdSuppr");

        formSuppr->setWidget(0, QFormLayout::LabelRole, labelIdSuppr);

        lineIdSuppr = new QLineEdit(tabSupprimer);
        lineIdSuppr->setObjectName("lineIdSuppr");

        formSuppr->setWidget(0, QFormLayout::FieldRole, lineIdSuppr);


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
        labelIdMod = new QLabel(tabModifier);
        labelIdMod->setObjectName("labelIdMod");

        formModifier->setWidget(0, QFormLayout::LabelRole, labelIdMod);

        lineIdMod = new QLineEdit(tabModifier);
        lineIdMod->setObjectName("lineIdMod");

        formModifier->setWidget(0, QFormLayout::FieldRole, lineIdMod);


        vertical_modifier->addLayout(formModifier);

        groupBox_prefill = new QGroupBox(tabModifier);
        groupBox_prefill->setObjectName("groupBox_prefill");
        gridPrefill = new QGridLayout(groupBox_prefill);
        gridPrefill->setObjectName("gridPrefill");
        labelSalaireModif = new QLabel(groupBox_prefill);
        labelSalaireModif->setObjectName("labelSalaireModif");

        gridPrefill->addWidget(labelSalaireModif, 0, 0, 1, 1);

        spinSalaireModif = new QDoubleSpinBox(groupBox_prefill);
        spinSalaireModif->setObjectName("spinSalaireModif");

        gridPrefill->addWidget(spinSalaireModif, 0, 1, 1, 1);

        labelPosteModif = new QLabel(groupBox_prefill);
        labelPosteModif->setObjectName("labelPosteModif");

        gridPrefill->addWidget(labelPosteModif, 1, 0, 1, 1);

        comboPosteModif = new QComboBox(groupBox_prefill);
        comboPosteModif->setObjectName("comboPosteModif");

        gridPrefill->addWidget(comboPosteModif, 1, 1, 1, 1);


        vertical_modifier->addWidget(groupBox_prefill);

        btnModifierConfirm = new QPushButton(tabModifier);
        btnModifierConfirm->setObjectName("btnModifierConfirm");

        vertical_modifier->addWidget(btnModifierConfirm);

        tabWidget->addTab(tabModifier, QString());
        tabRechercheTri = new QWidget();
        tabRechercheTri->setObjectName("tabRechercheTri");
        vertical_recherche_tri_emp = new QVBoxLayout(tabRechercheTri);
        vertical_recherche_tri_emp->setObjectName("vertical_recherche_tri_emp");
        groupRechercheEmp = new QGroupBox(tabRechercheTri);
        groupRechercheEmp->setObjectName("groupRechercheEmp");
        gridRechercheEmp = new QGridLayout(groupRechercheEmp);
        gridRechercheEmp->setObjectName("gridRechercheEmp");
        labelSearchNom = new QLabel(groupRechercheEmp);
        labelSearchNom->setObjectName("labelSearchNom");

        gridRechercheEmp->addWidget(labelSearchNom, 0, 0, 1, 1);

        lineSearchNom = new QLineEdit(groupRechercheEmp);
        lineSearchNom->setObjectName("lineSearchNom");

        gridRechercheEmp->addWidget(lineSearchNom, 0, 1, 1, 3);

        labelSearchIdBadge = new QLabel(groupRechercheEmp);
        labelSearchIdBadge->setObjectName("labelSearchIdBadge");

        gridRechercheEmp->addWidget(labelSearchIdBadge, 1, 0, 1, 1);

        lineSearchIdBadge = new QLineEdit(groupRechercheEmp);
        lineSearchIdBadge->setObjectName("lineSearchIdBadge");

        gridRechercheEmp->addWidget(lineSearchIdBadge, 1, 1, 1, 3);

        labelSearchSalaire = new QLabel(groupRechercheEmp);
        labelSearchSalaire->setObjectName("labelSearchSalaire");

        gridRechercheEmp->addWidget(labelSearchSalaire, 2, 0, 1, 1);

        doubleSearchSalaireMin = new QDoubleSpinBox(groupRechercheEmp);
        doubleSearchSalaireMin->setObjectName("doubleSearchSalaireMin");

        gridRechercheEmp->addWidget(doubleSearchSalaireMin, 2, 1, 1, 1);

        labelSearchSalaireEt = new QLabel(groupRechercheEmp);
        labelSearchSalaireEt->setObjectName("labelSearchSalaireEt");

        gridRechercheEmp->addWidget(labelSearchSalaireEt, 2, 2, 1, 1);

        doubleSearchSalaireMax = new QDoubleSpinBox(groupRechercheEmp);
        doubleSearchSalaireMax->setObjectName("doubleSearchSalaireMax");

        gridRechercheEmp->addWidget(doubleSearchSalaireMax, 2, 3, 1, 1);

        labelSearchAnciennete = new QLabel(groupRechercheEmp);
        labelSearchAnciennete->setObjectName("labelSearchAnciennete");

        gridRechercheEmp->addWidget(labelSearchAnciennete, 3, 0, 1, 1);

        spinSearchAnciennete = new QSpinBox(groupRechercheEmp);
        spinSearchAnciennete->setObjectName("spinSearchAnciennete");
        spinSearchAnciennete->setMinimum(0);
        spinSearchAnciennete->setMaximum(50);

        gridRechercheEmp->addWidget(spinSearchAnciennete, 3, 1, 1, 3);


        vertical_recherche_tri_emp->addWidget(groupRechercheEmp);

        groupTriEmp = new QGroupBox(tabRechercheTri);
        groupTriEmp->setObjectName("groupTriEmp");
        gridTriEmp = new QGridLayout(groupTriEmp);
        gridTriEmp->setObjectName("gridTriEmp");
        labelTriParEmp = new QLabel(groupTriEmp);
        labelTriParEmp->setObjectName("labelTriParEmp");

        gridTriEmp->addWidget(labelTriParEmp, 0, 0, 1, 1);

        comboTriParEmp = new QComboBox(groupTriEmp);
        comboTriParEmp->addItem(QString());
        comboTriParEmp->addItem(QString());
        comboTriParEmp->addItem(QString());
        comboTriParEmp->addItem(QString());
        comboTriParEmp->addItem(QString());
        comboTriParEmp->addItem(QString());
        comboTriParEmp->addItem(QString());
        comboTriParEmp->setObjectName("comboTriParEmp");

        gridTriEmp->addWidget(comboTriParEmp, 0, 1, 1, 1);

        horizontalSpacer_tri_emp = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridTriEmp->addItem(horizontalSpacer_tri_emp, 0, 2, 1, 1);


        vertical_recherche_tri_emp->addWidget(groupTriEmp);

        hLayoutSearchButtonsEmp = new QHBoxLayout();
        hLayoutSearchButtonsEmp->setObjectName("hLayoutSearchButtonsEmp");
        horizontalSpacer_search_emp = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutSearchButtonsEmp->addItem(horizontalSpacer_search_emp);

        btnAppliquerRechercheEmp = new QPushButton(tabRechercheTri);
        btnAppliquerRechercheEmp->setObjectName("btnAppliquerRechercheEmp");

        hLayoutSearchButtonsEmp->addWidget(btnAppliquerRechercheEmp);

        btnReinitialiserRechercheEmp = new QPushButton(tabRechercheTri);
        btnReinitialiserRechercheEmp->setObjectName("btnReinitialiserRechercheEmp");

        hLayoutSearchButtonsEmp->addWidget(btnReinitialiserRechercheEmp);


        vertical_recherche_tri_emp->addLayout(hLayoutSearchButtonsEmp);

        tableResultatsRechercheEmp = new QTableWidget(tabRechercheTri);
        if (tableResultatsRechercheEmp->columnCount() < 6)
            tableResultatsRechercheEmp->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableResultatsRechercheEmp->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableResultatsRechercheEmp->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableResultatsRechercheEmp->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableResultatsRechercheEmp->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableResultatsRechercheEmp->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableResultatsRechercheEmp->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        tableResultatsRechercheEmp->setObjectName("tableResultatsRechercheEmp");
        tableResultatsRechercheEmp->setAlternatingRowColors(true);

        vertical_recherche_tri_emp->addWidget(tableResultatsRechercheEmp);

        tabWidget->addTab(tabRechercheTri, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        vertical_statistiques = new QVBoxLayout(tabStatistiques);
        vertical_statistiques->setObjectName("vertical_statistiques");
        groupEffectifs = new QGroupBox(tabStatistiques);
        groupEffectifs->setObjectName("groupEffectifs");
        gridStatEffectifs = new QGridLayout(groupEffectifs);
        gridStatEffectifs->setObjectName("gridStatEffectifs");
        labelTotalEmp = new QLabel(groupEffectifs);
        labelTotalEmp->setObjectName("labelTotalEmp");

        gridStatEffectifs->addWidget(labelTotalEmp, 0, 0, 1, 1);

        lineTotalEmp = new QLineEdit(groupEffectifs);
        lineTotalEmp->setObjectName("lineTotalEmp");
        lineTotalEmp->setReadOnly(true);

        gridStatEffectifs->addWidget(lineTotalEmp, 0, 1, 1, 1);

        labelActifs = new QLabel(groupEffectifs);
        labelActifs->setObjectName("labelActifs");

        gridStatEffectifs->addWidget(labelActifs, 1, 0, 1, 1);

        lineActifs = new QLineEdit(groupEffectifs);
        lineActifs->setObjectName("lineActifs");
        lineActifs->setReadOnly(true);

        gridStatEffectifs->addWidget(lineActifs, 1, 1, 1, 1);


        vertical_statistiques->addWidget(groupEffectifs);

        groupFinances = new QGroupBox(tabStatistiques);
        groupFinances->setObjectName("groupFinances");
        gridStatFinances = new QGridLayout(groupFinances);
        gridStatFinances->setObjectName("gridStatFinances");
        labelMasseSalariale = new QLabel(groupFinances);
        labelMasseSalariale->setObjectName("labelMasseSalariale");

        gridStatFinances->addWidget(labelMasseSalariale, 0, 0, 1, 1);

        lineMasseSalariale = new QLineEdit(groupFinances);
        lineMasseSalariale->setObjectName("lineMasseSalariale");
        lineMasseSalariale->setReadOnly(true);

        gridStatFinances->addWidget(lineMasseSalariale, 0, 1, 1, 1);

        labelSalaireMoyen = new QLabel(groupFinances);
        labelSalaireMoyen->setObjectName("labelSalaireMoyen");

        gridStatFinances->addWidget(labelSalaireMoyen, 1, 0, 1, 1);

        lineSalaireMoyen = new QLineEdit(groupFinances);
        lineSalaireMoyen->setObjectName("lineSalaireMoyen");
        lineSalaireMoyen->setReadOnly(true);

        gridStatFinances->addWidget(lineSalaireMoyen, 1, 1, 1, 1);


        vertical_statistiques->addWidget(groupFinances);

        groupPerformance = new QGroupBox(tabStatistiques);
        groupPerformance->setObjectName("groupPerformance");
        gridStatPerformance = new QGridLayout(groupPerformance);
        gridStatPerformance->setObjectName("gridStatPerformance");
        labelMoyennePerf = new QLabel(groupPerformance);
        labelMoyennePerf->setObjectName("labelMoyennePerf");

        gridStatPerformance->addWidget(labelMoyennePerf, 0, 0, 1, 1);

        lineMoyennePerf = new QLineEdit(groupPerformance);
        lineMoyennePerf->setObjectName("lineMoyennePerf");
        lineMoyennePerf->setReadOnly(true);

        gridStatPerformance->addWidget(lineMoyennePerf, 0, 1, 1, 1);


        vertical_statistiques->addWidget(groupPerformance);

        verticalSpacer_stats = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_statistiques->addItem(verticalSpacer_stats);

        tabWidget->addTab(tabStatistiques, QString());
        tabStatistiquesAvancees = new QWidget();
        tabStatistiquesAvancees->setObjectName("tabStatistiquesAvancees");
        vertical_statistiques_avancees = new QVBoxLayout(tabStatistiquesAvancees);
        vertical_statistiques_avancees->setObjectName("vertical_statistiques_avancees");
        groupSalairesVsMissions = new QGroupBox(tabStatistiquesAvancees);
        groupSalairesVsMissions->setObjectName("groupSalairesVsMissions");
        vLayoutSalairesVsMissions = new QVBoxLayout(groupSalairesVsMissions);
        vLayoutSalairesVsMissions->setObjectName("vLayoutSalairesVsMissions");
        tableSalairesVsMissions = new QTableWidget(groupSalairesVsMissions);
        if (tableSalairesVsMissions->columnCount() < 5)
            tableSalairesVsMissions->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableSalairesVsMissions->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableSalairesVsMissions->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableSalairesVsMissions->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableSalairesVsMissions->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableSalairesVsMissions->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        tableSalairesVsMissions->setObjectName("tableSalairesVsMissions");
        tableSalairesVsMissions->setAlternatingRowColors(true);

        vLayoutSalairesVsMissions->addWidget(tableSalairesVsMissions);


        vertical_statistiques_avancees->addWidget(groupSalairesVsMissions);

        groupDépensesEmployes = new QGroupBox(tabStatistiquesAvancees);
        groupDépensesEmployes->setObjectName("groupD\303\251pensesEmployes");
        vLayoutDépensesEmployes = new QVBoxLayout(groupDépensesEmployes);
        vLayoutDépensesEmployes->setObjectName("vLayoutD\303\251pensesEmployes");
        hLayoutDépensesControls = new QHBoxLayout();
        hLayoutDépensesControls->setObjectName("hLayoutD\303\251pensesControls");
        labelMoisDépenses = new QLabel(groupDépensesEmployes);
        labelMoisDépenses->setObjectName("labelMoisD\303\251penses");

        hLayoutDépensesControls->addWidget(labelMoisDépenses);

        comboMoisDépenses = new QComboBox(groupDépensesEmployes);
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->addItem(QString());
        comboMoisDépenses->setObjectName("comboMoisD\303\251penses");

        hLayoutDépensesControls->addWidget(comboMoisDépenses);

        horizontalSpacer_depenses = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutDépensesControls->addItem(horizontalSpacer_depenses);


        vLayoutDépensesEmployes->addLayout(hLayoutDépensesControls);

        tableDépensesEmployes = new QTableWidget(groupDépensesEmployes);
        if (tableDépensesEmployes->columnCount() < 5)
            tableDépensesEmployes->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableDépensesEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableDépensesEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableDépensesEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableDépensesEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableDépensesEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem21);
        tableDépensesEmployes->setObjectName("tableD\303\251pensesEmployes");
        tableDépensesEmployes->setAlternatingRowColors(true);

        vLayoutDépensesEmployes->addWidget(tableDépensesEmployes);


        vertical_statistiques_avancees->addWidget(groupDépensesEmployes);

        groupIndiceRendement = new QGroupBox(tabStatistiquesAvancees);
        groupIndiceRendement->setObjectName("groupIndiceRendement");
        vLayoutIndiceRendement = new QVBoxLayout(groupIndiceRendement);
        vLayoutIndiceRendement->setObjectName("vLayoutIndiceRendement");
        hLayoutIndiceControls = new QHBoxLayout();
        hLayoutIndiceControls->setObjectName("hLayoutIndiceControls");
        labelMoisIndice = new QLabel(groupIndiceRendement);
        labelMoisIndice->setObjectName("labelMoisIndice");

        hLayoutIndiceControls->addWidget(labelMoisIndice);

        comboMoisIndice = new QComboBox(groupIndiceRendement);
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->addItem(QString());
        comboMoisIndice->setObjectName("comboMoisIndice");

        hLayoutIndiceControls->addWidget(comboMoisIndice);

        spinAnneeIndice = new QSpinBox(groupIndiceRendement);
        spinAnneeIndice->setObjectName("spinAnneeIndice");
        spinAnneeIndice->setMinimum(2020);
        spinAnneeIndice->setMaximum(2030);
        spinAnneeIndice->setValue(2026);

        hLayoutIndiceControls->addWidget(spinAnneeIndice);

        horizontalSpacer_indice = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutIndiceControls->addItem(horizontalSpacer_indice);


        vLayoutIndiceRendement->addLayout(hLayoutIndiceControls);

        tableIndiceRendement = new QTableWidget(groupIndiceRendement);
        if (tableIndiceRendement->columnCount() < 4)
            tableIndiceRendement->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableIndiceRendement->setHorizontalHeaderItem(0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableIndiceRendement->setHorizontalHeaderItem(1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableIndiceRendement->setHorizontalHeaderItem(2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableIndiceRendement->setHorizontalHeaderItem(3, __qtablewidgetitem25);
        tableIndiceRendement->setObjectName("tableIndiceRendement");
        tableIndiceRendement->setAlternatingRowColors(true);

        vLayoutIndiceRendement->addWidget(tableIndiceRendement);


        vertical_statistiques_avancees->addWidget(groupIndiceRendement);

        verticalSpacer_adv_stats = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_statistiques_avancees->addItem(verticalSpacer_adv_stats);

        tabWidget->addTab(tabStatistiquesAvancees, QString());
        tabAuthentication = new QWidget();
        tabAuthentication->setObjectName("tabAuthentication");
        vertical_authentication = new QVBoxLayout(tabAuthentication);
        vertical_authentication->setObjectName("vertical_authentication");
        groupPasswordReset = new QGroupBox(tabAuthentication);
        groupPasswordReset->setObjectName("groupPasswordReset");
        gridPasswordReset = new QGridLayout(groupPasswordReset);
        gridPasswordReset->setObjectName("gridPasswordReset");
        labelEmailReset = new QLabel(groupPasswordReset);
        labelEmailReset->setObjectName("labelEmailReset");

        gridPasswordReset->addWidget(labelEmailReset, 0, 0, 1, 1);

        lineEmailReset = new QLineEdit(groupPasswordReset);
        lineEmailReset->setObjectName("lineEmailReset");

        gridPasswordReset->addWidget(lineEmailReset, 0, 1, 1, 2);

        labelSecurityQuestion = new QLabel(groupPasswordReset);
        labelSecurityQuestion->setObjectName("labelSecurityQuestion");

        gridPasswordReset->addWidget(labelSecurityQuestion, 1, 0, 1, 1);

        comboSecurityQuestion = new QComboBox(groupPasswordReset);
        comboSecurityQuestion->addItem(QString());
        comboSecurityQuestion->addItem(QString());
        comboSecurityQuestion->addItem(QString());
        comboSecurityQuestion->addItem(QString());
        comboSecurityQuestion->setObjectName("comboSecurityQuestion");

        gridPasswordReset->addWidget(comboSecurityQuestion, 1, 1, 1, 2);

        labelSecurityAnswer = new QLabel(groupPasswordReset);
        labelSecurityAnswer->setObjectName("labelSecurityAnswer");

        gridPasswordReset->addWidget(labelSecurityAnswer, 2, 0, 1, 1);

        lineSecurityAnswer = new QLineEdit(groupPasswordReset);
        lineSecurityAnswer->setObjectName("lineSecurityAnswer");

        gridPasswordReset->addWidget(lineSecurityAnswer, 2, 1, 1, 2);

        labelNewPassword = new QLabel(groupPasswordReset);
        labelNewPassword->setObjectName("labelNewPassword");

        gridPasswordReset->addWidget(labelNewPassword, 3, 0, 1, 1);

        lineNewPassword = new QLineEdit(groupPasswordReset);
        lineNewPassword->setObjectName("lineNewPassword");
        lineNewPassword->setEchoMode(QLineEdit::Password);

        gridPasswordReset->addWidget(lineNewPassword, 3, 1, 1, 2);

        labelConfirmPassword = new QLabel(groupPasswordReset);
        labelConfirmPassword->setObjectName("labelConfirmPassword");

        gridPasswordReset->addWidget(labelConfirmPassword, 4, 0, 1, 1);

        lineConfirmPassword = new QLineEdit(groupPasswordReset);
        lineConfirmPassword->setObjectName("lineConfirmPassword");
        lineConfirmPassword->setEchoMode(QLineEdit::Password);

        gridPasswordReset->addWidget(lineConfirmPassword, 4, 1, 1, 2);


        vertical_authentication->addWidget(groupPasswordReset);

        hLayoutPasswordButtons = new QHBoxLayout();
        hLayoutPasswordButtons->setObjectName("hLayoutPasswordButtons");
        horizontalSpacer_password = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutPasswordButtons->addItem(horizontalSpacer_password);

        btnResetPassword = new QPushButton(tabAuthentication);
        btnResetPassword->setObjectName("btnResetPassword");

        hLayoutPasswordButtons->addWidget(btnResetPassword);


        vertical_authentication->addLayout(hLayoutPasswordButtons);

        groupContractGeneration = new QGroupBox(tabAuthentication);
        groupContractGeneration->setObjectName("groupContractGeneration");
        gridContractGeneration = new QGridLayout(groupContractGeneration);
        gridContractGeneration->setObjectName("gridContractGeneration");
        labelIdEmployeContract = new QLabel(groupContractGeneration);
        labelIdEmployeContract->setObjectName("labelIdEmployeContract");

        gridContractGeneration->addWidget(labelIdEmployeContract, 0, 0, 1, 1);

        lineIdEmployeContract = new QLineEdit(groupContractGeneration);
        lineIdEmployeContract->setObjectName("lineIdEmployeContract");

        gridContractGeneration->addWidget(lineIdEmployeContract, 0, 1, 1, 1);

        labelContractType = new QLabel(groupContractGeneration);
        labelContractType->setObjectName("labelContractType");

        gridContractGeneration->addWidget(labelContractType, 1, 0, 1, 1);

        comboContractType = new QComboBox(groupContractGeneration);
        comboContractType->addItem(QString());
        comboContractType->addItem(QString());
        comboContractType->addItem(QString());
        comboContractType->addItem(QString());
        comboContractType->setObjectName("comboContractType");

        gridContractGeneration->addWidget(comboContractType, 1, 1, 1, 1);

        labelDateDebut = new QLabel(groupContractGeneration);
        labelDateDebut->setObjectName("labelDateDebut");

        gridContractGeneration->addWidget(labelDateDebut, 2, 0, 1, 1);

        dateContractStart = new QDateEdit(groupContractGeneration);
        dateContractStart->setObjectName("dateContractStart");
        dateContractStart->setCalendarPopup(true);

        gridContractGeneration->addWidget(dateContractStart, 2, 1, 1, 1);

        labelDureeContrat = new QLabel(groupContractGeneration);
        labelDureeContrat->setObjectName("labelDureeContrat");

        gridContractGeneration->addWidget(labelDureeContrat, 3, 0, 1, 1);

        spinContractDuration = new QSpinBox(groupContractGeneration);
        spinContractDuration->setObjectName("spinContractDuration");
        spinContractDuration->setMinimum(0);
        spinContractDuration->setMaximum(36);

        gridContractGeneration->addWidget(spinContractDuration, 3, 1, 1, 1);

        labelSalaireContrat = new QLabel(groupContractGeneration);
        labelSalaireContrat->setObjectName("labelSalaireContrat");

        gridContractGeneration->addWidget(labelSalaireContrat, 4, 0, 1, 1);

        spinSalaryContract = new QDoubleSpinBox(groupContractGeneration);
        spinSalaryContract->setObjectName("spinSalaryContract");
        spinSalaryContract->setMinimum(0);
        spinSalaryContract->setMaximum(999999);

        gridContractGeneration->addWidget(spinSalaryContract, 4, 1, 1, 1);

        labelAccessLevel = new QLabel(groupContractGeneration);
        labelAccessLevel->setObjectName("labelAccessLevel");

        gridContractGeneration->addWidget(labelAccessLevel, 5, 0, 1, 1);

        comboAccessLevel = new QComboBox(groupContractGeneration);
        comboAccessLevel->addItem(QString());
        comboAccessLevel->addItem(QString());
        comboAccessLevel->addItem(QString());
        comboAccessLevel->addItem(QString());
        comboAccessLevel->setObjectName("comboAccessLevel");

        gridContractGeneration->addWidget(comboAccessLevel, 5, 1, 1, 1);


        vertical_authentication->addWidget(groupContractGeneration);

        hLayoutContractButtons = new QHBoxLayout();
        hLayoutContractButtons->setObjectName("hLayoutContractButtons");
        horizontalSpacer_contract = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutContractButtons->addItem(horizontalSpacer_contract);

        btnGenerateContractAI = new QPushButton(tabAuthentication);
        btnGenerateContractAI->setObjectName("btnGenerateContractAI");

        hLayoutContractButtons->addWidget(btnGenerateContractAI);

        btnExportContract = new QPushButton(tabAuthentication);
        btnExportContract->setObjectName("btnExportContract");

        hLayoutContractButtons->addWidget(btnExportContract);


        vertical_authentication->addLayout(hLayoutContractButtons);

        textContractPreview = new QTextEdit(tabAuthentication);
        textContractPreview->setObjectName("textContractPreview");
        textContractPreview->setReadOnly(true);

        vertical_authentication->addWidget(textContractPreview);

        verticalSpacer_authentication = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_authentication->addItem(verticalSpacer_authentication);

        tabWidget->addTab(tabAuthentication, QString());
        tabExportPdf = new QWidget();
        tabExportPdf->setObjectName("tabExportPdf");
        vertical_export_pdf = new QVBoxLayout(tabExportPdf);
        vertical_export_pdf->setObjectName("vertical_export_pdf");
        groupExportOptions = new QGroupBox(tabExportPdf);
        groupExportOptions->setObjectName("groupExportOptions");
        vLayoutExportOptions = new QVBoxLayout(groupExportOptions);
        vLayoutExportOptions->setObjectName("vLayoutExportOptions");
        checkExportTous = new QCheckBox(groupExportOptions);
        checkExportTous->setObjectName("checkExportTous");
        checkExportTous->setChecked(true);

        vLayoutExportOptions->addWidget(checkExportTous);

        checkExportFiltre = new QCheckBox(groupExportOptions);
        checkExportFiltre->setObjectName("checkExportFiltre");

        vLayoutExportOptions->addWidget(checkExportFiltre);


        vertical_export_pdf->addWidget(groupExportOptions);

        groupIdExport = new QGroupBox(tabExportPdf);
        groupIdExport->setObjectName("groupIdExport");
        hLayoutIdExport = new QHBoxLayout(groupIdExport);
        hLayoutIdExport->setObjectName("hLayoutIdExport");
        btnExportListeComplete = new QPushButton(groupIdExport);
        btnExportListeComplete->setObjectName("btnExportListeComplete");

        hLayoutIdExport->addWidget(btnExportListeComplete);

        btnExportRapportRH = new QPushButton(groupIdExport);
        btnExportRapportRH->setObjectName("btnExportRapportRH");

        hLayoutIdExport->addWidget(btnExportRapportRH);

        btnExportFicheEmploye = new QPushButton(groupIdExport);
        btnExportFicheEmploye->setObjectName("btnExportFicheEmploye");

        hLayoutIdExport->addWidget(btnExportFicheEmploye);


        vertical_export_pdf->addWidget(groupIdExport);

        groupMessagesExport = new QGroupBox(tabExportPdf);
        groupMessagesExport->setObjectName("groupMessagesExport");
        vLayoutMessagesExport = new QVBoxLayout(groupMessagesExport);
        vLayoutMessagesExport->setObjectName("vLayoutMessagesExport");
        lineExportMessages = new QLineEdit(groupMessagesExport);
        lineExportMessages->setObjectName("lineExportMessages");
        lineExportMessages->setReadOnly(true);

        vLayoutMessagesExport->addWidget(lineExportMessages);


        vertical_export_pdf->addWidget(groupMessagesExport);

        verticalSpacer_export = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_export_pdf->addItem(verticalSpacer_export);

        tabWidget->addTab(tabExportPdf, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(EmployeWidget);

        QMetaObject::connectSlotsByName(EmployeWidget);
    } // setupUi

    void retranslateUi(QWidget *EmployeWidget)
    {
        labelNom->setText(QCoreApplication::translate("EmployeWidget", "Nom :", nullptr));
        labelPrenom->setText(QCoreApplication::translate("EmployeWidget", "Pr\303\251nom :", nullptr));
        labelEmail->setText(QCoreApplication::translate("EmployeWidget", "Email :", nullptr));
        labelPoste->setText(QCoreApplication::translate("EmployeWidget", "Poste :", nullptr));
        labelSalaire->setText(QCoreApplication::translate("EmployeWidget", "Salaire :", nullptr));
        labelDateEmbauche->setText(QCoreApplication::translate("EmployeWidget", "Date d'embauche :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("EmployeWidget", "Ajouter", nullptr));
        btnResetAjouter->setText(QCoreApplication::translate("EmployeWidget", "R\303\251initialiser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("EmployeWidget", "Ajouter un employ\303\251", nullptr));
        labelFiltres->setText(QCoreApplication::translate("EmployeWidget", "Filtres :", nullptr));
        labelFiltres->setStyleSheet(QCoreApplication::translate("EmployeWidget", "font-weight: bold;", nullptr));
        checkFiltreTous->setText(QCoreApplication::translate("EmployeWidget", "Tous", nullptr));
        checkFiltreActifs->setText(QCoreApplication::translate("EmployeWidget", "Actifs", nullptr));
        checkFiltreInactifs->setText(QCoreApplication::translate("EmployeWidget", "Inactifs", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("EmployeWidget", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("EmployeWidget", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("EmployeWidget", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableEmployes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("EmployeWidget", "Date d'embauche", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("EmployeWidget", "Liste des employ\303\251s", nullptr));
        labelIdSuppr->setText(QCoreApplication::translate("EmployeWidget", "ID Employ\303\251 :", nullptr));
        btnSupprimerConfirm->setText(QCoreApplication::translate("EmployeWidget", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("EmployeWidget", "Supprimer un employ\303\251", nullptr));
        labelIdMod->setText(QCoreApplication::translate("EmployeWidget", "ID Employ\303\251 :", nullptr));
        groupBox_prefill->setTitle(QCoreApplication::translate("EmployeWidget", "Modifier les donn\303\251es", nullptr));
        labelSalaireModif->setText(QCoreApplication::translate("EmployeWidget", "Nouveau salaire :", nullptr));
        labelPosteModif->setText(QCoreApplication::translate("EmployeWidget", "Nouveau poste :", nullptr));
        btnModifierConfirm->setText(QCoreApplication::translate("EmployeWidget", "Mettre \303\240 jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("EmployeWidget", "Modifier un employ\303\251", nullptr));
        groupRechercheEmp->setTitle(QCoreApplication::translate("EmployeWidget", "Recherche", nullptr));
        labelSearchNom->setText(QCoreApplication::translate("EmployeWidget", "Rechercher par nom :", nullptr));
        lineSearchNom->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez le nom", nullptr));
        labelSearchIdBadge->setText(QCoreApplication::translate("EmployeWidget", "Rechercher par ID Badge :", nullptr));
        lineSearchIdBadge->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez l'ID Badge", nullptr));
        labelSearchSalaire->setText(QCoreApplication::translate("EmployeWidget", "Rechercher par salaire (entre) :", nullptr));
        labelSearchSalaireEt->setText(QCoreApplication::translate("EmployeWidget", "\303\240", nullptr));
        labelSearchAnciennete->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251 (ann\303\251es) :", nullptr));
        groupTriEmp->setTitle(QCoreApplication::translate("EmployeWidget", "Tri", nullptr));
        labelTriParEmp->setText(QCoreApplication::translate("EmployeWidget", "Trier par :", nullptr));
        comboTriParEmp->setItemText(0, QCoreApplication::translate("EmployeWidget", "Nom (A-Z)", nullptr));
        comboTriParEmp->setItemText(1, QCoreApplication::translate("EmployeWidget", "Nom (Z-A)", nullptr));
        comboTriParEmp->setItemText(2, QCoreApplication::translate("EmployeWidget", "Salaire (Croissant)", nullptr));
        comboTriParEmp->setItemText(3, QCoreApplication::translate("EmployeWidget", "Salaire (D\303\251croissant)", nullptr));
        comboTriParEmp->setItemText(4, QCoreApplication::translate("EmployeWidget", "Anciennet\303\251 (R\303\251cent)", nullptr));
        comboTriParEmp->setItemText(5, QCoreApplication::translate("EmployeWidget", "Anciennet\303\251 (Ancien)", nullptr));
        comboTriParEmp->setItemText(6, QCoreApplication::translate("EmployeWidget", "ID Badge", nullptr));

        btnAppliquerRechercheEmp->setText(QCoreApplication::translate("EmployeWidget", "Appliquer", nullptr));
        btnReinitialiserRechercheEmp->setText(QCoreApplication::translate("EmployeWidget", "R\303\251initialiser", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableResultatsRechercheEmp->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("EmployeWidget", "ID Badge", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableResultatsRechercheEmp->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("EmployeWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableResultatsRechercheEmp->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("EmployeWidget", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableResultatsRechercheEmp->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("EmployeWidget", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableResultatsRechercheEmp->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableResultatsRechercheEmp->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("EmployeWidget", "Anciennet\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRechercheTri), QCoreApplication::translate("EmployeWidget", "Recherche & Tri", nullptr));
        groupEffectifs->setTitle(QCoreApplication::translate("EmployeWidget", "Effectifs", nullptr));
        labelTotalEmp->setText(QCoreApplication::translate("EmployeWidget", "Total :", nullptr));
        labelActifs->setText(QCoreApplication::translate("EmployeWidget", "Actifs :", nullptr));
        groupFinances->setTitle(QCoreApplication::translate("EmployeWidget", "Finances", nullptr));
        labelMasseSalariale->setText(QCoreApplication::translate("EmployeWidget", "Masse salariale :", nullptr));
        labelSalaireMoyen->setText(QCoreApplication::translate("EmployeWidget", "Salaire moyen :", nullptr));
        groupPerformance->setTitle(QCoreApplication::translate("EmployeWidget", "Performance", nullptr));
        labelMoyennePerf->setText(QCoreApplication::translate("EmployeWidget", "Note moyenne :", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("EmployeWidget", "Statistiques", nullptr));
        groupSalairesVsMissions->setTitle(QCoreApplication::translate("EmployeWidget", "Salaires vs Missions R\303\251alis\303\251es", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableSalairesVsMissions->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("EmployeWidget", "Employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableSalairesVsMissions->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("EmployeWidget", "Salaire Mensuel", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableSalairesVsMissions->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("EmployeWidget", "Missions R\303\251alis\303\251es", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableSalairesVsMissions->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("EmployeWidget", "Revenue G\303\251n\303\251r\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableSalairesVsMissions->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("EmployeWidget", "Ratio", nullptr));
        groupDépensesEmployes->setTitle(QCoreApplication::translate("EmployeWidget", "D\303\251penses des Employ\303\251s", nullptr));
        labelMoisDépenses->setText(QCoreApplication::translate("EmployeWidget", "Mois :", nullptr));
        comboMoisDépenses->setItemText(0, QCoreApplication::translate("EmployeWidget", "Janvier", nullptr));
        comboMoisDépenses->setItemText(1, QCoreApplication::translate("EmployeWidget", "F\303\251vrier", nullptr));
        comboMoisDépenses->setItemText(2, QCoreApplication::translate("EmployeWidget", "Mars", nullptr));
        comboMoisDépenses->setItemText(3, QCoreApplication::translate("EmployeWidget", "Avril", nullptr));
        comboMoisDépenses->setItemText(4, QCoreApplication::translate("EmployeWidget", "Mai", nullptr));
        comboMoisDépenses->setItemText(5, QCoreApplication::translate("EmployeWidget", "Juin", nullptr));
        comboMoisDépenses->setItemText(6, QCoreApplication::translate("EmployeWidget", "Juillet", nullptr));
        comboMoisDépenses->setItemText(7, QCoreApplication::translate("EmployeWidget", "Ao\303\273t", nullptr));
        comboMoisDépenses->setItemText(8, QCoreApplication::translate("EmployeWidget", "Septembre", nullptr));
        comboMoisDépenses->setItemText(9, QCoreApplication::translate("EmployeWidget", "Octobre", nullptr));
        comboMoisDépenses->setItemText(10, QCoreApplication::translate("EmployeWidget", "Novembre", nullptr));
        comboMoisDépenses->setItemText(11, QCoreApplication::translate("EmployeWidget", "D\303\251cembre", nullptr));

        QTableWidgetItem *___qtablewidgetitem17 = tableDépensesEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("EmployeWidget", "Employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableDépensesEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("EmployeWidget", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableDépensesEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251 (%)", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableDépensesEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("EmployeWidget", "Nombre Absences", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableDépensesEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("EmployeWidget", "Total D\303\251pense", nullptr));
        groupIndiceRendement->setTitle(QCoreApplication::translate("EmployeWidget", "Indice de Rendement (par mois)", nullptr));
        labelMoisIndice->setText(QCoreApplication::translate("EmployeWidget", "Mois :", nullptr));
        comboMoisIndice->setItemText(0, QCoreApplication::translate("EmployeWidget", "Janvier", nullptr));
        comboMoisIndice->setItemText(1, QCoreApplication::translate("EmployeWidget", "F\303\251vrier", nullptr));
        comboMoisIndice->setItemText(2, QCoreApplication::translate("EmployeWidget", "Mars", nullptr));
        comboMoisIndice->setItemText(3, QCoreApplication::translate("EmployeWidget", "Avril", nullptr));
        comboMoisIndice->setItemText(4, QCoreApplication::translate("EmployeWidget", "Mai", nullptr));
        comboMoisIndice->setItemText(5, QCoreApplication::translate("EmployeWidget", "Juin", nullptr));
        comboMoisIndice->setItemText(6, QCoreApplication::translate("EmployeWidget", "Juillet", nullptr));
        comboMoisIndice->setItemText(7, QCoreApplication::translate("EmployeWidget", "Ao\303\273t", nullptr));
        comboMoisIndice->setItemText(8, QCoreApplication::translate("EmployeWidget", "Septembre", nullptr));
        comboMoisIndice->setItemText(9, QCoreApplication::translate("EmployeWidget", "Octobre", nullptr));
        comboMoisIndice->setItemText(10, QCoreApplication::translate("EmployeWidget", "Novembre", nullptr));
        comboMoisIndice->setItemText(11, QCoreApplication::translate("EmployeWidget", "D\303\251cembre", nullptr));

        QTableWidgetItem *___qtablewidgetitem22 = tableIndiceRendement->horizontalHeaderItem(0);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("EmployeWidget", "Employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableIndiceRendement->horizontalHeaderItem(1);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("EmployeWidget", "Rendement Score", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableIndiceRendement->horizontalHeaderItem(2);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("EmployeWidget", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableIndiceRendement->horizontalHeaderItem(3);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("EmployeWidget", "Gain/Perte", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiquesAvancees), QCoreApplication::translate("EmployeWidget", "Statistiques Avanc\303\251es", nullptr));
        groupPasswordReset->setTitle(QCoreApplication::translate("EmployeWidget", "R\303\251cup\303\251ration de Mot de Passe", nullptr));
        labelEmailReset->setText(QCoreApplication::translate("EmployeWidget", "Email de l'employ\303\251 :", nullptr));
        lineEmailReset->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "exemple@example.com", nullptr));
        labelSecurityQuestion->setText(QCoreApplication::translate("EmployeWidget", "Question de s\303\251curit\303\251 :", nullptr));
        comboSecurityQuestion->setItemText(0, QCoreApplication::translate("EmployeWidget", "Quel est le nom de votre animal de compagnie?", nullptr));
        comboSecurityQuestion->setItemText(1, QCoreApplication::translate("EmployeWidget", "Quelle est votre ville natale?", nullptr));
        comboSecurityQuestion->setItemText(2, QCoreApplication::translate("EmployeWidget", "Quel est le nom de votre meilleur ami d'enfance?", nullptr));
        comboSecurityQuestion->setItemText(3, QCoreApplication::translate("EmployeWidget", "Quel est votre film pr\303\251f\303\251r\303\251?", nullptr));

        labelSecurityAnswer->setText(QCoreApplication::translate("EmployeWidget", "R\303\251ponse :", nullptr));
        lineSecurityAnswer->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Votre r\303\251ponse", nullptr));
        labelNewPassword->setText(QCoreApplication::translate("EmployeWidget", "Nouveau mot de passe :", nullptr));
        lineNewPassword->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Nouveau mot de passe", nullptr));
        labelConfirmPassword->setText(QCoreApplication::translate("EmployeWidget", "Confirmer mot de passe :", nullptr));
        lineConfirmPassword->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Confirmer", nullptr));
        btnResetPassword->setText(QCoreApplication::translate("EmployeWidget", "R\303\251initialiser le mot de passe", nullptr));
        groupContractGeneration->setTitle(QCoreApplication::translate("EmployeWidget", "G\303\251n\303\251ration de Contrat de Travail (avec IA)", nullptr));
        labelIdEmployeContract->setText(QCoreApplication::translate("EmployeWidget", "ID Employ\303\251 :", nullptr));
        lineIdEmployeContract->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez l'ID", nullptr));
        labelContractType->setText(QCoreApplication::translate("EmployeWidget", "Type de contrat :", nullptr));
        comboContractType->setItemText(0, QCoreApplication::translate("EmployeWidget", "CDI (Contrat \303\240 Dur\303\251e Ind\303\251termin\303\251e)", nullptr));
        comboContractType->setItemText(1, QCoreApplication::translate("EmployeWidget", "CDD (Contrat \303\240 Dur\303\251e D\303\251termin\303\251e)", nullptr));
        comboContractType->setItemText(2, QCoreApplication::translate("EmployeWidget", "Stage", nullptr));
        comboContractType->setItemText(3, QCoreApplication::translate("EmployeWidget", "Alternance", nullptr));

        labelDateDebut->setText(QCoreApplication::translate("EmployeWidget", "Date de d\303\251but :", nullptr));
        labelDureeContrat->setText(QCoreApplication::translate("EmployeWidget", "Dur\303\251e (mois) - Si CDD :", nullptr));
        labelSalaireContrat->setText(QCoreApplication::translate("EmployeWidget", "Salaire propos\303\251 :", nullptr));
        labelAccessLevel->setText(QCoreApplication::translate("EmployeWidget", "Niveau d'acc\303\250s :", nullptr));
        comboAccessLevel->setItemText(0, QCoreApplication::translate("EmployeWidget", "Utilisateur Standard", nullptr));
        comboAccessLevel->setItemText(1, QCoreApplication::translate("EmployeWidget", "Manager", nullptr));
        comboAccessLevel->setItemText(2, QCoreApplication::translate("EmployeWidget", "Administrateur RH", nullptr));
        comboAccessLevel->setItemText(3, QCoreApplication::translate("EmployeWidget", "Directeur", nullptr));

        btnGenerateContractAI->setText(QCoreApplication::translate("EmployeWidget", "G\303\251n\303\251rer avec IA", nullptr));
        btnExportContract->setText(QCoreApplication::translate("EmployeWidget", "Exporter le contrat", nullptr));
        textContractPreview->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Aper\303\247u du contrat g\303\251n\303\251r\303\251...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAuthentication), QCoreApplication::translate("EmployeWidget", "Authentification & Contrats", nullptr));
        groupExportOptions->setTitle(QCoreApplication::translate("EmployeWidget", "Options d'export", nullptr));
        checkExportTous->setText(QCoreApplication::translate("EmployeWidget", "Exporter tous", nullptr));
        checkExportFiltre->setText(QCoreApplication::translate("EmployeWidget", "Exporter filtr\303\251s", nullptr));
        groupIdExport->setTitle(QCoreApplication::translate("EmployeWidget", "Param\303\250tres d'export", nullptr));
        btnExportListeComplete->setText(QCoreApplication::translate("EmployeWidget", "Liste compl\303\250te", nullptr));
        btnExportRapportRH->setText(QCoreApplication::translate("EmployeWidget", "Rapport RH", nullptr));
        btnExportFicheEmploye->setText(QCoreApplication::translate("EmployeWidget", "Fiche employ\303\251", nullptr));
        groupMessagesExport->setTitle(QCoreApplication::translate("EmployeWidget", "Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExportPdf), QCoreApplication::translate("EmployeWidget", "Export PDF", nullptr));
        (void)EmployeWidget;
    } // retranslateUi

};

namespace Ui {
    class EmployeWidget: public Ui_EmployeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYE_WIDGET_H
