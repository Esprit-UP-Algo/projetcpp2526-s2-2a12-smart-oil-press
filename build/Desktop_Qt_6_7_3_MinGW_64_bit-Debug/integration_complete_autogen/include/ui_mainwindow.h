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
#include <QtWidgets/QCalendarWidget>
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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QSplitter>
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
    QWidget *EmployeWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabAjouter;
    QVBoxLayout *verticalLayout_ajouter;
    QGridLayout *grid_ajouter;
    QLabel *label_nom;
    QLineEdit *lineEdit_nom;
    QLabel *label_prenom;
    QLineEdit *lineEdit_prenom;
    QLabel *label_age;
    QSpinBox *spinBox_age;
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
    QLabel *label_id_equipe;
    QLineEdit *lineEdit_id_equipe;
    QLabel *label_mdp;
    QLineEdit *lineEdit_mdp;
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
    QLabel *label_search_id_equipe;
    QLineEdit *search_id_equipe;
    QLabel *label_search_spec;
    QComboBox *search_spec;
    QGroupBox *groupSort;
    QVBoxLayout *vSort;
    QRadioButton *sort_salaire;
    QRadioButton *sort_anciennete;
    QRadioButton *sort_heures;
    QRadioButton *sort_fournisseurs;
    QGroupBox *groupOrder;
    QVBoxLayout *vOrder;
    QRadioButton *order_asc;
    QRadioButton *order_desc;
    QPushButton *btnAppliquerFiltreEmploye;
    QPushButton *btnResetFiltre;
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
    QLabel *label_id_equipe_mod;
    QLineEdit *lineEdit_id_equipe_mod;
    QLabel *label_mdp_mod;
    QLineEdit *lineEdit_mdp_mod;
    QPushButton *btnModifierConfirm;
    QWidget *tabStatistiques;
    QVBoxLayout *vertical_statistiques;
    QHBoxLayout *hStatsSummary;
    QLabel *label_total_employes;
    QLabel *label_masse_salariale;
    QLabel *label_salaire_moyen;
    QGroupBox *groupTopChart;
    QVBoxLayout *vTopChart;
    QFrame *frameStatsTopChart;
    QHBoxLayout *hBottomCharts;
    QGroupBox *groupLeftChart;
    QVBoxLayout *vLeftChart;
    QFrame *frameStatsLeftChart;
    QGroupBox *groupRightChart;
    QVBoxLayout *vRightChart;
    QFrame *frameStatsRightChart;
    QWidget *tabExportPdf;
    QVBoxLayout *vertical_export_pdf;
    QGroupBox *groupExportOptions;
    QVBoxLayout *vExportOptions;
    QPushButton *btnExportListeComplete;
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
    QHBoxLayout *hLogoConn;
    QLabel *logoLabelConn;
    QLabel *label_app_title;
    QSpacerItem *spacerLogoH;
    QSpacerItem *spacerTop;
    QHBoxLayout *hCenterConn;
    QSpacerItem *spacerLeftConn;
    QWidget *loginFormContainer;
    QVBoxLayout *vLoginForm;
    QLabel *label_login_title;
    QFormLayout *formConnexion;
    QLabel *label_user_conn;
    QLineEdit *line_user_conn;
    QLabel *label_pass_conn;
    QLineEdit *line_pass_conn;
    QPushButton *btnSeConnecter;
    QLabel *label_login_error;
    QPushButton *btnNavigateForgot;
    QSpacerItem *spacerRightConn;
    QSpacerItem *spacerBottom;
    QWidget *tabMotPasseOublie;
    QVBoxLayout *vertical_mdp_oublie;
    QGroupBox *groupFPStep1;
    QFormLayout *formFP1;
    QLabel *label_user_identite_fp;
    QLineEdit *line_user_identite_fp;
    QPushButton *btnValiderIdentite;
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
    QWidget *EquipeWidget;
    QStatusBar *statusbar;
    QVBoxLayout *mainContainerLayout;
    QFrame *contentFrame;
    QVBoxLayout *contentLayout;
    QTabWidget *topNavTabs;
    QWidget *tabAjouter1;
    QWidget *tabGestion;
    QWidget *tabSupprimer1;
    QWidget *tabModifier1;
    QWidget *tabStatistique;
    QWidget *tabSuggestion;
    QWidget *tabPlanification;
    QStackedWidget *stackedWidget;
    QWidget *pageadd;
    QVBoxLayout *addLayout;
    QLabel *addTitle;
    QFrame *addFormFrame;
    QFormLayout *addFormLayout;
    QLabel *label_30;
    QLineEdit *lineEditNomEquipeAjout;
    QLabel *label_31;
    QLineEdit *lineEditChefEquipeAjout;
    QLabel *label_32;
    QComboBox *comboBoxSpecialiteEquipeAjout;
    QLabel *label_33;
    QComboBox *comboBoxNbMembresEquipeAjout;
    QSpacerItem *addSpacer;
    QHBoxLayout *addActionLayout;
    QSpacerItem *addActionSpacer;
    QPushButton *btnAjouterEquipe;
    QWidget *page_rech;
    QVBoxLayout *rechLayout;
    QHBoxLayout *rechTopLayout;
    QLineEdit *lineEditRechercheEquipe;
    QPushButton *btnFiltre;
    QSpacerItem *searchSpacer;
    QHBoxLayout *rechMainLayout;
    QFrame *frame_4;
    QVBoxLayout *frame4Layout;
    QLabel *label_7;
    QPushButton *btnTrier;
    QComboBox *comboBoxTriEquipe;
    QHBoxLayout *sortOptionsLayout;
    QCheckBox *checkBoxTriEquipeCroissant;
    QCheckBox *checkBoxTriEquipeDecroissant;
    QSpacerItem *frame4Spacer;
    QTableWidget *tableWidgetEquipe;
    QWidget *pagemodif;
    QVBoxLayout *modifLayout;
    QLabel *modifTitle;
    QFrame *modifFormFrame;
    QFormLayout *modifFormLayout;
    QLabel *label_modif_id;
    QLineEdit *lineEdit_modif_id;
    QLabel *label_35;
    QLineEdit *lineEditNomEquipeModif;
    QLabel *label_36;
    QLineEdit *lineEditChefEquipeModif;
    QLabel *label_37;
    QComboBox *comboBoxSpecialiteEquipeModif;
    QLabel *label_38;
    QComboBox *comboBoxNbMembresEquipeModif;
    QSpacerItem *modifSpacer;
    QHBoxLayout *modifActionLayout;
    QSpacerItem *modifActionSpacer;
    QPushButton *btnModifierEquipe;
    QWidget *pagesupp;
    QVBoxLayout *suppLayout;
    QLabel *suppTitle;
    QFrame *suppFormFrame;
    QVBoxLayout *suppFormLayout;
    QLabel *suppWarning;
    QHBoxLayout *suppIdLayout;
    QLabel *label_42;
    QLineEdit *lineEditIdEquipeSuppression;
    QSpacerItem *suppSpacer;
    QHBoxLayout *suppActionLayout;
    QSpacerItem *suppActionSpacer;
    QPushButton *btnSupprimerEquipe;
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
    QHBoxLayout *statsSecondRowLayout;
    QGroupBox *objectifsGroup;
    QVBoxLayout *vboxLayout2;
    QListWidget *listWidget_2;
    QGroupBox *evalGroup;
    QVBoxLayout *vboxLayout3;
    QPlainTextEdit *plainTextEdit_3;
    QHBoxLayout *exportLayout;
    QSpacerItem *exportSpacer;
    QPushButton *btnExportEquipePdf;
    QWidget *sugg;
    QFrame *frame_6;
    QLabel *label_16;
    QLabel *label_17;
    QPushButton *btnRechercherRecommandationEquipe;
    QCheckBox *checkBoxRequiertDisponibilite;
    QLabel *label_18;
    QComboBox *comboBoxSpecialiteRecommandation;
    QLabel *label_19;
    QLineEdit *lineEditNbMembresMinRecommandation;
    QCheckBox *checkBoxUrgentRecommandation;
    QCheckBox *checkBoxEtatNormalRecommandation;
    QLabel *label_24;
    QListWidget *listWidget_3;
    QFrame *line_3;
    QLabel *label_25;
    QComboBox *comboBoxDifficulteRecommandation;
    QWidget *page_planification;
    QVBoxLayout *planLayout;
    QHBoxLayout *planSearchLayout;
    QLineEdit *lineEditRecherchePlanificationEquipe;
    QPushButton *btnRechercherPlanificationEquipe;
    QHBoxLayout *planContentLayout;
    QCalendarWidget *calendarWidget;
    QFrame *taskFrame;
    QVBoxLayout *taskLayout;
    QLabel *taskLabel;
    QListWidget *listWidget;
    QWidget *WidgetClient;
    QVBoxLayout *rootLayout;
    QVBoxLayout *mainContentLayout;
    QHBoxLayout *contentLayout1;
    QGroupBox *grpRechercheFiltre;
    QVBoxLayout *verticalLayout_sidebar;
    QFormLayout *formLayoutTop;
    QLabel *lblNom;
    QLineEdit *txtRechercheNom;
    QSpacerItem *verticalSpacer1;
    QGroupBox *grpFiltres;
    QFormLayout *formLayoutBottom;
    QLabel *lblType;
    QComboBox *cmbType;
    QLabel *lblStatut;
    QComboBox *cmbStatut;
    QPushButton *btnAppliquerFiltre;
    QVBoxLayout *centerLayout;
    QTabWidget *tabWidgetClient;
    QWidget *tabAjouter2;
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
    QWidget *tabSupprimer2;
    QVBoxLayout *vlSupprimer;
    QLabel *lblSupprimerInfo;
    QGroupBox *grpClientASupprimer;
    QVBoxLayout *vboxLayout4;
    QLabel *lblSupprimerNom;
    QLabel *lblSupprimerDetails;
    QSpacerItem *spacerItem2;
    QHBoxLayout *hboxLayout1;
    QSpacerItem *spacerItem3;
    QPushButton *btnConfirmerSupprimer;
    QPushButton *btnAnnulerSupprimer;
    QWidget *tabModifier2;
    QVBoxLayout *vlModifier;
    QLabel *lblModifierInfo;
    QGroupBox *grpFormModifier;
    QFormLayout *formModifier1;
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
    QWidget *tabStatistiques1;
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
    QVBoxLayout *vExportOptions1;
    QPushButton *btnExportListeClients;
    QPushButton *btnExportStatistiques;
    QPushButton *btnExportFicheClient;
    QGroupBox *grpParamsExport;
    QFormLayout *formParamsExport;
    QLabel *lblIdClient;
    QLineEdit *lineEdit_id_export1;
    QGroupBox *grpMessagesExport;
    QVBoxLayout *vMessagesExport1;
    QTextEdit *textEdit_export_messages1;
    QSpacerItem *verticalSpacer_export1;
    QWidget *LaboWidget;
    QVBoxLayout *mainLayout;
    QTabWidget *topNavTabs1;
    QWidget *tabAjouter3;
    QWidget *tabGestion1;
    QWidget *tabSupprimer3;
    QWidget *tabModifier3;
    QWidget *tabStatistique1;
    QWidget *tabGeolocalisation;
    QWidget *tabAIBot;
    QStackedWidget *stackedWidget1;
    QWidget *pageadd1;
    QVBoxLayout *addLayout1;
    QLabel *addTitle1;
    QFrame *addFormFrame1;
    QFormLayout *addFormLayout1;
    QLabel *label_id1;
    QLineEdit *lineEdit_id1;
    QLabel *label_nom1;
    QLineEdit *lineEdit_nom1;
    QLabel *label_type;
    QComboBox *comboBox_type;
    QLabel *label_conformite;
    QComboBox *comboBox_conformite;
    QLabel *label_adresse;
    QLineEdit *lineEdit_adresse;
    QLabel *label_espace;
    QSpinBox *spinBox_espace;
    QSpacerItem *addSpacer1;
    QHBoxLayout *addActionLayout1;
    QSpacerItem *addActionSpacer1;
    QPushButton *btnAjouterLabo;
    QWidget *page_rech1;
    QVBoxLayout *rechLayout1;
    QHBoxLayout *rechTopLayout1;
    QLineEdit *lineEditRechercheLabo;
    QPushButton *btnRechercher;
    QHBoxLayout *rechMainLayout1;
    QFrame *frame_41;
    QVBoxLayout *frame4Layout1;
    QLabel *label_71;
    QPushButton *btnTrier1;
    QComboBox *comboBoxTriLabo;
    QHBoxLayout *sortOptionsLayout1;
    QCheckBox *checkBoxTriLaboCroissant;
    QCheckBox *checkBoxTriLaboDecroissant;
    QFrame *line_export;
    QLabel *label_export;
    QPushButton *btnExportPDF;
    QSpacerItem *frame4Spacer1;
    QTableWidget *tableWidgetLabo;
    QWidget *pagesupp1;
    QVBoxLayout *suppLayout1;
    QLabel *suppTitle1;
    QFrame *suppFormFrame1;
    QVBoxLayout *suppFormLayout1;
    QLabel *suppWarning1;
    QHBoxLayout *suppIdLayout1;
    QLabel *label_421;
    QLineEdit *lineEditIdLaboSuppression;
    QSpacerItem *suppSpacer1;
    QHBoxLayout *suppActionLayout1;
    QSpacerItem *suppActionSpacer1;
    QPushButton *btnSupprimerLabo;
    QWidget *pagemodif1;
    QVBoxLayout *modifLayout1;
    QLabel *modifTitle1;
    QFrame *modifFormFrame1;
    QFormLayout *modifFormLayout1;
    QLabel *label_modif_id1;
    QLineEdit *lineEdit_modif_id1;
    QLabel *label_351;
    QLineEdit *lineEditNomLaboModif;
    QLabel *label_361;
    QComboBox *comboBox_modif_type;
    QLabel *label_371;
    QComboBox *comboBox_modif_conf;
    QLabel *label_381;
    QLineEdit *lineEditAdresseLaboModif;
    QSpacerItem *modifSpacer1;
    QHBoxLayout *modifActionLayout1;
    QSpacerItem *modifActionSpacer1;
    QPushButton *btnModifierLabo;
    QWidget *page_stat1;
    QVBoxLayout *statLayout1;
    QLabel *statTitle1;
    QHBoxLayout *statsContentLayout1;
    QGroupBox *performanceGroup1;
    QVBoxLayout *vboxLayout5;
    QPlainTextEdit *plainTextEdit1;
    QGroupBox *vitesseGroup1;
    QVBoxLayout *vboxLayout6;
    QPlainTextEdit *plainTextEdit_21;
    QHBoxLayout *exportLayout1;
    QSpacerItem *exportSpacer1;
    QPushButton *btnExportStatsLaboPdf;
    QWidget *pageGeo;
    QVBoxLayout *geoLayout;
    QLabel *geoPlaceholder;
    QWidget *pageAI;
    QVBoxLayout *aiLayout;
    QLabel *aiPlaceholder;
    QWidget *CommandeWidget;
    QVBoxLayout *verticalLayout_cmd;
    QLabel *label_cmd;
    QTabWidget *tabWidget_cmd;
    QWidget *tabAjouter_cmd;
    QVBoxLayout *verticalLayout_ajouter_cmd;
    QGridLayout *grid_ajouter_cmd;
    QLabel *labelNumCommande;
    QLineEdit *lineNumCommande;
    QLabel *labelClient;
    QLineEdit *lineClient;
    QLabel *labelProduit;
    QComboBox *comboProduit;
    QLabel *labelQuantite;
    QSpinBox *spinQuantite;
    QLabel *labelPrix;
    QDoubleSpinBox *spinPrix;
    QLabel *labelStatut;
    QComboBox *comboStatut;
    QLabel *labelDate;
    QLineEdit *lineDate;
    QHBoxLayout *hButtonsAjouter_cmd;
    QSpacerItem *horizontalSpacer_ajouter;
    QPushButton *btnAjouter_cmd;
    QPushButton *btnResetAjouter;
    QWidget *tabListe_cmd;
    QHBoxLayout *hLayout_liste_cmd;
    QFrame *sidebarListe_cmd;
    QVBoxLayout *vLayoutSidebar;
    QLabel *labelFiltres;
    QCheckBox *checkFiltreTous;
    QCheckBox *checkFiltreAttente;
    QCheckBox *checkFiltreConfirmee;
    QCheckBox *checkFiltreExpedie;
    QCheckBox *checkFiltreLivree;
    QSpacerItem *verticalSpacer_sidebar;
    QFrame *mainListe_cmd;
    QVBoxLayout *vLayoutMain;
    QTableWidget *tableCommandes;
    QWidget *tabSupprimer_cmd;
    QVBoxLayout *vertical_supprimer_cmd;
    QFormLayout *formSuppr_cmd;
    QLabel *labelIdSuppr;
    QLineEdit *lineIdSuppr;
    QPushButton *btnSupprimerConfirm_cmd;
    QWidget *tabModifier_cmd;
    QVBoxLayout *vertical_modifier_cmd;
    QFormLayout *formModifier_cmd;
    QLabel *labelIdMod;
    QLineEdit *lineIdMod;
    QGroupBox *groupBox_prefill_cmd;
    QGridLayout *gridPrefill;
    QLabel *labelStatutModif;
    QComboBox *comboStatutModif;
    QLabel *labelQuantiteModif;
    QSpinBox *spinQuantiteModif;
    QPushButton *btnModifierConfirm_cmd;
    QWidget *tabRechercheTri;
    QVBoxLayout *vertical_recherche_tri;
    QGroupBox *groupRecherche;
    QGridLayout *gridRecherche;
    QLabel *labelSearchDate;
    QDateEdit *dateSearchDebut;
    QLabel *labelSearchDateTo;
    QDateEdit *dateSearchFin;
    QLabel *labelSearchFournisseur;
    QLineEdit *lineSearchFournisseur;
    QLabel *labelSearchClient;
    QLineEdit *lineSearchClient;
    QGroupBox *groupTri;
    QGridLayout *gridTri;
    QLabel *labelTriPar;
    QComboBox *comboTriPar;
    QSpacerItem *horizontalSpacer_tri;
    QHBoxLayout *hLayoutSearchButtons;
    QSpacerItem *horizontalSpacer_search;
    QPushButton *btnAppliquerRecherche;
    QPushButton *btnReinitialiserRecherche;
    QTableWidget *tableResultatsRecherche;
    QWidget *tabStatistiques_cmd;
    QVBoxLayout *vertical_statistiques_cmd;
    QGroupBox *groupCommandes;
    QGridLayout *gridStatCommandes;
    QLabel *labelTotalCmd;
    QLineEdit *lineTotalCmd;
    QLabel *labelEnAttenteCmd;
    QLineEdit *lineEnAttenteCmd;
    QGroupBox *groupRevenue;
    QGridLayout *gridStatRevenue;
    QLabel *labelRevenuTotal;
    QLineEdit *lineRevenuTotal;
    QLabel *labelMoyenneCmd;
    QLineEdit *lineMoyenneCmd;
    QGroupBox *groupPrixParMois;
    QVBoxLayout *vLayoutPrixMois;
    QTableWidget *tablePrixParMois;
    QGroupBox *groupProduitsMostCommandes;
    QVBoxLayout *vLayoutProduitsMost;
    QTableWidget *tableProduitsMostCommandes;
    QSpacerItem *verticalSpacer_stats_cmd;
    QWidget *tabCalendrier;
    QVBoxLayout *vertical_calendrier;
    QGroupBox *groupCalendrier;
    QVBoxLayout *vLayoutCalendrier;
    QHBoxLayout *hLayoutCalendrierControls;
    QLabel *labelMoisAnnee;
    QComboBox *comboMoisCalendrier;
    QSpinBox *spinAnneeCalendrier;
    QSpacerItem *horizontalSpacer_calendrier;
    QPushButton *btnAfficherCalendrier;
    QCalendarWidget *calendarCommandes;
    QGroupBox *groupAlertes;
    QVBoxLayout *vLayoutAlertes;
    QLabel *labelAlertesLegend;
    QListWidget *listAlertes;
    QSpacerItem *verticalSpacer_calendrier;
    QWidget *tabNotifications;
    QVBoxLayout *vertical_notifications;
    QGroupBox *groupEmailConfig;
    QGridLayout *gridEmailConfig;
    QLabel *labelEmailDestinataire;
    QLineEdit *lineEmailDestinataire;
    QLabel *labelEmailCommande;
    QComboBox *comboEmailNotification;
    QCheckBox *checkEmailAutomatic;
    QGroupBox *groupEmailManuel;
    QGridLayout *gridEmailManuel;
    QLabel *labelNumCommandeEmail;
    QLineEdit *lineNumCommandeEmail;
    QLabel *labelMessageEmail;
    QTextEdit *textMessageEmail;
    QHBoxLayout *hLayoutEmailButtons;
    QSpacerItem *horizontalSpacer_email;
    QPushButton *btnEnvoyerEmail;
    QGroupBox *groupHistoriqueEmails;
    QVBoxLayout *vLayoutHistoriqueEmails;
    QTableWidget *tableHistoriqueEmails;
    QSpacerItem *verticalSpacer_notifications;
    QWidget *tabExportPdf_cmd;
    QVBoxLayout *vertical_export_pdf_cmd;
    QGroupBox *groupExportOptions_cmd;
    QVBoxLayout *vLayoutExportOptions;
    QCheckBox *checkExportTous;
    QCheckBox *checkExportFiltre;
    QGroupBox *groupIdExport_cmd;
    QHBoxLayout *hLayoutIdExport;
    QPushButton *btnExportListeComplete_cmd;
    QPushButton *btnExportRapport;
    QPushButton *btnExportFiche;
    QGroupBox *groupMessagesExport_cmd;
    QVBoxLayout *vLayoutMessagesExport;
    QLineEdit *lineExportMessages;
    QSpacerItem *verticalSpacer_export_cmd;
    QWidget *MachineWidget;
    QVBoxLayout *machineLayout;
    QSplitter *splitter;
    QWidget *leftPanel;
    QVBoxLayout *leftLayout;
    QGroupBox *groupBoxSearch;
    QVBoxLayout *vboxLayout7;
    QHBoxLayout *hboxLayout3;
    QLabel *label10;
    QLineEdit *lineEditSearch;
    QHBoxLayout *hboxLayout4;
    QLabel *label11;
    QComboBox *comboCategory;
    QHBoxLayout *hboxLayout5;
    QLabel *label12;
    QComboBox *comboState;
    QHBoxLayout *hboxLayout6;
    QLabel *label13;
    QLineEdit *lineEditLocation;
    QPushButton *btnApplyFilter;
    QGroupBox *groupBoxSort;
    QVBoxLayout *vboxLayout8;
    QHBoxLayout *hboxLayout7;
    QLabel *label14;
    QComboBox *comboSortBy;
    QHBoxLayout *hboxLayout8;
    QRadioButton *radioCroissant;
    QRadioButton *radioDecroissant;
    QPushButton *btnScanQR;
    QSpacerItem *verticalSpacerLeft;
    QWidget *centerPanel;
    QVBoxLayout *centerLayout_mach;
    QTabWidget *tabWidget_mach;
    QWidget *tabAjouter_mach;
    QVBoxLayout *vboxLayout9;
    QLabel *labelAdd;
    QFrame *frameAdd;
    QFormLayout *formLayoutAdd;
    QLabel *label15;
    QLineEdit *editAddId;
    QLabel *label16;
    QLineEdit *editAddNom;
    QLabel *label17;
    QComboBox *comboAddCategorie;
    QLabel *label18;
    QLineEdit *editAddReference;
    QLabel *label19;
    QDateEdit *dateAddAchat;
    QLabel *label20;
    QComboBox *comboAddEtat;
    QLabel *label21;
    QLineEdit *editAddLocalisation;
    QSpacerItem *spacerItem6;
    QHBoxLayout *hboxLayout9;
    QSpacerItem *spacerItem7;
    QPushButton *btnConfirmerAjouter_mach;
    QPushButton *btnAnnulerAjouter_mach;
    QWidget *tabListe_mach;
    QVBoxLayout *vboxLayout10;
    QTableWidget *tableMachines;
    QHBoxLayout *hboxLayout10;
    QPushButton *btnExportPDF_mach;
    QPushButton *btnRefresh;
    QSpacerItem *spacerItem8;
    QWidget *tabSupprimer_mach;
    QVBoxLayout *vboxLayout11;
    QLabel *label22;
    QGroupBox *grpMachineASupprimer;
    QVBoxLayout *vboxLayout12;
    QLabel *lblSupprimerNom_mach;
    QLabel *lblSupprimerDetails_mach;
    QSpacerItem *spacerItem9;
    QHBoxLayout *hboxLayout11;
    QSpacerItem *spacerItem10;
    QPushButton *btnConfirmerSupprimer_mach;
    QPushButton *btnAnnulerSupprimer_mach;
    QWidget *tabModifier_mach;
    QVBoxLayout *vboxLayout13;
    QLabel *label23;
    QGroupBox *grpFormModifier_mach;
    QFormLayout *formLayout;
    QLabel *label24;
    QLineEdit *editModifierId;
    QLabel *label25;
    QLineEdit *editModifierNom;
    QLabel *label26;
    QComboBox *comboModifierCategorie;
    QLabel *label27;
    QLineEdit *editModifierReference;
    QLabel *label28;
    QDateEdit *dateModifierAchat;
    QLabel *label29;
    QComboBox *comboModifierEtat;
    QLabel *label30;
    QLineEdit *editModifierLocalisation;
    QSpacerItem *spacerItem11;
    QHBoxLayout *hboxLayout12;
    QSpacerItem *spacerItem12;
    QPushButton *btnConfirmerModifier_mach;
    QPushButton *btnAnnulerModifier_mach;
    QWidget *tabPanne;
    QVBoxLayout *vboxLayout14;
    QLabel *label31;
    QGroupBox *grpPanne;
    QFormLayout *formLayout1;
    QLabel *label32;
    QComboBox *comboPanneMachine;
    QLabel *label33;
    QDateEdit *datePanne;
    QLabel *label34;
    QComboBox *comboTypePanne;
    QLabel *label35;
    QComboBox *comboGravite;
    QLabel *label36;
    QTextEdit *txtDescriptionPanne;
    QSpacerItem *spacerItem13;
    QHBoxLayout *hboxLayout13;
    QSpacerItem *spacerItem14;
    QPushButton *btnSignalerPanne;
    QPushButton *btnAnnulerPanne;
    QWidget *tabHistorique;
    QVBoxLayout *vboxLayout15;
    QTableWidget *tableHistorique;
    QHBoxLayout *hboxLayout14;
    QPushButton *btnExportHistorique;
    QSpacerItem *spacerItem15;
    QWidget *tabStatistiques_mach;
    QVBoxLayout *vboxLayout16;
    QGroupBox *grpStatsResume;
    QHBoxLayout *hboxLayout15;
    QGroupBox *groupBox;
    QVBoxLayout *vboxLayout17;
    QLabel *lblStatsTotalMachines;
    QGroupBox *groupBox1;
    QVBoxLayout *vboxLayout18;
    QLabel *lblStatsEnService;
    QGroupBox *groupBox2;
    QVBoxLayout *vboxLayout19;
    QLabel *lblStatsEnPanne;
    QGroupBox *groupBox3;
    QVBoxLayout *vboxLayout20;
    QLabel *lblStatsMaintenance;
    QTextEdit *txtStatistiques_mach;
    QHBoxLayout *hboxLayout16;
    QPushButton *btnExportStats;
    QSpacerItem *spacerItem16;
    QMenuBar *menubar;
    QStatusBar *statusbar1;

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
        EmployeWidget = new QWidget();
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
        label_nom = new QLabel(tabAjouter);
        label_nom->setObjectName("label_nom");

        grid_ajouter->addWidget(label_nom, 0, 0, 1, 1);

        lineEdit_nom = new QLineEdit(tabAjouter);
        lineEdit_nom->setObjectName("lineEdit_nom");

        grid_ajouter->addWidget(lineEdit_nom, 0, 1, 1, 1);

        label_prenom = new QLabel(tabAjouter);
        label_prenom->setObjectName("label_prenom");

        grid_ajouter->addWidget(label_prenom, 1, 0, 1, 1);

        lineEdit_prenom = new QLineEdit(tabAjouter);
        lineEdit_prenom->setObjectName("lineEdit_prenom");

        grid_ajouter->addWidget(lineEdit_prenom, 1, 1, 1, 1);

        label_age = new QLabel(tabAjouter);
        label_age->setObjectName("label_age");

        grid_ajouter->addWidget(label_age, 2, 0, 1, 1);

        spinBox_age = new QSpinBox(tabAjouter);
        spinBox_age->setObjectName("spinBox_age");
        spinBox_age->setMinimum(18);
        spinBox_age->setMaximum(120);

        grid_ajouter->addWidget(spinBox_age, 2, 1, 1, 1);

        label_spec = new QLabel(tabAjouter);
        label_spec->setObjectName("label_spec");

        grid_ajouter->addWidget(label_spec, 3, 0, 1, 1);

        combo_spec = new QComboBox(tabAjouter);
        combo_spec->addItem(QString());
        combo_spec->addItem(QString());
        combo_spec->addItem(QString());
        combo_spec->addItem(QString());
        combo_spec->setObjectName("combo_spec");

        grid_ajouter->addWidget(combo_spec, 3, 1, 1, 1);

        label_salaire = new QLabel(tabAjouter);
        label_salaire->setObjectName("label_salaire");

        grid_ajouter->addWidget(label_salaire, 6, 0, 1, 1);

        doubleSpin_salaire = new QDoubleSpinBox(tabAjouter);
        doubleSpin_salaire->setObjectName("doubleSpin_salaire");
        doubleSpin_salaire->setDecimals(2);
        doubleSpin_salaire->setMaximum(1000000.000000000000000);

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
        spin_fourn->setMaximum(1000000);

        grid_ajouter->addWidget(spin_fourn, 10, 1, 1, 1);

        label_id_equipe = new QLabel(tabAjouter);
        label_id_equipe->setObjectName("label_id_equipe");

        grid_ajouter->addWidget(label_id_equipe, 11, 0, 1, 1);

        lineEdit_id_equipe = new QLineEdit(tabAjouter);
        lineEdit_id_equipe->setObjectName("lineEdit_id_equipe");

        grid_ajouter->addWidget(lineEdit_id_equipe, 11, 1, 1, 1);

        label_mdp = new QLabel(tabAjouter);
        label_mdp->setObjectName("label_mdp");

        grid_ajouter->addWidget(label_mdp, 12, 0, 1, 1);

        lineEdit_mdp = new QLineEdit(tabAjouter);
        lineEdit_mdp->setObjectName("lineEdit_mdp");
        lineEdit_mdp->setEchoMode(QLineEdit::Password);

        grid_ajouter->addWidget(lineEdit_mdp, 12, 1, 1, 1);


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

        label_search_id_equipe = new QLabel(groupSearch);
        label_search_id_equipe->setObjectName("label_search_id_equipe");

        vSearch->addWidget(label_search_id_equipe);

        search_id_equipe = new QLineEdit(groupSearch);
        search_id_equipe->setObjectName("search_id_equipe");

        vSearch->addWidget(search_id_equipe);

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


        vLayout_sidebar->addWidget(groupSearch);

        groupSort = new QGroupBox(sidebarListe);
        groupSort->setObjectName("groupSort");
        vSort = new QVBoxLayout(groupSort);
        vSort->setObjectName("vSort");
        sort_salaire = new QRadioButton(groupSort);
        sort_salaire->setObjectName("sort_salaire");

        vSort->addWidget(sort_salaire);

        sort_anciennete = new QRadioButton(groupSort);
        sort_anciennete->setObjectName("sort_anciennete");

        vSort->addWidget(sort_anciennete);

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

        btnAppliquerFiltreEmploye = new QPushButton(sidebarListe);
        btnAppliquerFiltreEmploye->setObjectName("btnAppliquerFiltreEmploye");

        vLayout_sidebar->addWidget(btnAppliquerFiltreEmploye);

        btnResetFiltre = new QPushButton(sidebarListe);
        btnResetFiltre->setObjectName("btnResetFiltre");

        vLayout_sidebar->addWidget(btnResetFiltre);

        verticalSpacer_liste = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayout_sidebar->addItem(verticalSpacer_liste);


        hLayout_liste->addWidget(sidebarListe);

        mainListe = new QFrame(tabListe);
        mainListe->setObjectName("mainListe");
        vLayout_tableArea = new QVBoxLayout(mainListe);
        vLayout_tableArea->setObjectName("vLayout_tableArea");
        table_employes = new QTableWidget(mainListe);
        if (table_employes->columnCount() < 12)
            table_employes->setColumnCount(12);
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
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        table_employes->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        table_employes->setObjectName("table_employes");
        table_employes->setColumnCount(12);

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
        spinBox_age_mod->setMinimum(18);
        spinBox_age_mod->setMaximum(120);

        grid_prefill->addWidget(spinBox_age_mod, 2, 1, 1, 1);

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
        doubleSpin_salaire_mod->setMaximum(1000000.000000000000000);

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
        spin_fourn_mod->setMaximum(1000000);

        grid_prefill->addWidget(spin_fourn_mod, 9, 1, 1, 1);

        label_id_equipe_mod = new QLabel(groupBox_prefill);
        label_id_equipe_mod->setObjectName("label_id_equipe_mod");

        grid_prefill->addWidget(label_id_equipe_mod, 10, 0, 1, 1);

        lineEdit_id_equipe_mod = new QLineEdit(groupBox_prefill);
        lineEdit_id_equipe_mod->setObjectName("lineEdit_id_equipe_mod");

        grid_prefill->addWidget(lineEdit_id_equipe_mod, 10, 1, 1, 1);

        label_mdp_mod = new QLabel(groupBox_prefill);
        label_mdp_mod->setObjectName("label_mdp_mod");

        grid_prefill->addWidget(label_mdp_mod, 11, 0, 1, 1);

        lineEdit_mdp_mod = new QLineEdit(groupBox_prefill);
        lineEdit_mdp_mod->setObjectName("lineEdit_mdp_mod");
        lineEdit_mdp_mod->setEchoMode(QLineEdit::Password);

        grid_prefill->addWidget(lineEdit_mdp_mod, 11, 1, 1, 1);


        vertical_modifier->addWidget(groupBox_prefill);

        btnModifierConfirm = new QPushButton(tabModifier);
        btnModifierConfirm->setObjectName("btnModifierConfirm");

        vertical_modifier->addWidget(btnModifierConfirm);

        tabWidget->addTab(tabModifier, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        vertical_statistiques = new QVBoxLayout(tabStatistiques);
        vertical_statistiques->setObjectName("vertical_statistiques");
        hStatsSummary = new QHBoxLayout();
        hStatsSummary->setObjectName("hStatsSummary");
        label_total_employes = new QLabel(tabStatistiques);
        label_total_employes->setObjectName("label_total_employes");

        hStatsSummary->addWidget(label_total_employes);

        label_masse_salariale = new QLabel(tabStatistiques);
        label_masse_salariale->setObjectName("label_masse_salariale");

        hStatsSummary->addWidget(label_masse_salariale);

        label_salaire_moyen = new QLabel(tabStatistiques);
        label_salaire_moyen->setObjectName("label_salaire_moyen");

        hStatsSummary->addWidget(label_salaire_moyen);


        vertical_statistiques->addLayout(hStatsSummary);

        groupTopChart = new QGroupBox(tabStatistiques);
        groupTopChart->setObjectName("groupTopChart");
        vTopChart = new QVBoxLayout(groupTopChart);
        vTopChart->setObjectName("vTopChart");
        frameStatsTopChart = new QFrame(groupTopChart);
        frameStatsTopChart->setObjectName("frameStatsTopChart");
        frameStatsTopChart->setMinimumHeight(280);
        frameStatsTopChart->setFrameShape(QFrame::StyledPanel);
        frameStatsTopChart->setFrameShadow(QFrame::Raised);

        vTopChart->addWidget(frameStatsTopChart);


        vertical_statistiques->addWidget(groupTopChart);

        hBottomCharts = new QHBoxLayout();
        hBottomCharts->setObjectName("hBottomCharts");
        groupLeftChart = new QGroupBox(tabStatistiques);
        groupLeftChart->setObjectName("groupLeftChart");
        vLeftChart = new QVBoxLayout(groupLeftChart);
        vLeftChart->setObjectName("vLeftChart");
        frameStatsLeftChart = new QFrame(groupLeftChart);
        frameStatsLeftChart->setObjectName("frameStatsLeftChart");
        frameStatsLeftChart->setMinimumHeight(250);
        frameStatsLeftChart->setFrameShape(QFrame::StyledPanel);
        frameStatsLeftChart->setFrameShadow(QFrame::Raised);

        vLeftChart->addWidget(frameStatsLeftChart);


        hBottomCharts->addWidget(groupLeftChart);

        groupRightChart = new QGroupBox(tabStatistiques);
        groupRightChart->setObjectName("groupRightChart");
        vRightChart = new QVBoxLayout(groupRightChart);
        vRightChart->setObjectName("vRightChart");
        frameStatsRightChart = new QFrame(groupRightChart);
        frameStatsRightChart->setObjectName("frameStatsRightChart");
        frameStatsRightChart->setMinimumHeight(250);
        frameStatsRightChart->setFrameShape(QFrame::StyledPanel);
        frameStatsRightChart->setFrameShadow(QFrame::Raised);

        vRightChart->addWidget(frameStatsRightChart);


        hBottomCharts->addWidget(groupRightChart);


        vertical_statistiques->addLayout(hBottomCharts);

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
        textEdit_export_messages->setReadOnly(false);
        textEdit_export_messages->setMaximumHeight(100);

        vMessagesExport->addWidget(textEdit_export_messages);


        vertical_export_pdf->addWidget(groupMessagesExport);

        verticalSpacer_export = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_export_pdf->addItem(verticalSpacer_export);

        tabWidget->addTab(tabExportPdf, QString());
        tabConnexion = new QWidget();
        tabConnexion->setObjectName("tabConnexion");
        vertical_connexion = new QVBoxLayout(tabConnexion);
        vertical_connexion->setSpacing(0);
        vertical_connexion->setContentsMargins(0, 0, 0, 0);
        vertical_connexion->setObjectName("vertical_connexion");
        hLogoConn = new QHBoxLayout();
        hLogoConn->setSpacing(12);
        hLogoConn->setObjectName("hLogoConn");
        hLogoConn->setContentsMargins(20, 20, -1, -1);
        logoLabelConn = new QLabel(tabConnexion);
        logoLabelConn->setObjectName("logoLabelConn");
        logoLabelConn->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.png")));
        logoLabelConn->setScaledContents(true);
        logoLabelConn->setMaximumWidth(80);
        logoLabelConn->setMaximumHeight(80);

        hLogoConn->addWidget(logoLabelConn);

        label_app_title = new QLabel(tabConnexion);
        label_app_title->setObjectName("label_app_title");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label_app_title->setFont(font);

        hLogoConn->addWidget(label_app_title);

        spacerLogoH = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLogoConn->addItem(spacerLogoH);


        vertical_connexion->addLayout(hLogoConn);

        spacerTop = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_connexion->addItem(spacerTop);

        hCenterConn = new QHBoxLayout();
        hCenterConn->setObjectName("hCenterConn");
        spacerLeftConn = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hCenterConn->addItem(spacerLeftConn);

        loginFormContainer = new QWidget(tabConnexion);
        loginFormContainer->setObjectName("loginFormContainer");
        loginFormContainer->setMinimumWidth(450);
        loginFormContainer->setMaximumWidth(550);
        vLoginForm = new QVBoxLayout(loginFormContainer);
        vLoginForm->setSpacing(20);
        vLoginForm->setObjectName("vLoginForm");
        vLoginForm->setContentsMargins(0, 0, 0, 0);
        label_login_title = new QLabel(loginFormContainer);
        label_login_title->setObjectName("label_login_title");
        label_login_title->setAlignment(Qt::AlignCenter);
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        label_login_title->setFont(font1);

        vLoginForm->addWidget(label_login_title);

        formConnexion = new QFormLayout();
        formConnexion->setSpacing(12);
        formConnexion->setObjectName("formConnexion");
        label_user_conn = new QLabel(loginFormContainer);
        label_user_conn->setObjectName("label_user_conn");

        formConnexion->setWidget(0, QFormLayout::LabelRole, label_user_conn);

        line_user_conn = new QLineEdit(loginFormContainer);
        line_user_conn->setObjectName("line_user_conn");
        line_user_conn->setMinimumHeight(40);

        formConnexion->setWidget(0, QFormLayout::FieldRole, line_user_conn);

        label_pass_conn = new QLabel(loginFormContainer);
        label_pass_conn->setObjectName("label_pass_conn");

        formConnexion->setWidget(1, QFormLayout::LabelRole, label_pass_conn);

        line_pass_conn = new QLineEdit(loginFormContainer);
        line_pass_conn->setObjectName("line_pass_conn");
        line_pass_conn->setEchoMode(QLineEdit::Password);
        line_pass_conn->setMinimumHeight(40);

        formConnexion->setWidget(1, QFormLayout::FieldRole, line_pass_conn);


        vLoginForm->addLayout(formConnexion);

        btnSeConnecter = new QPushButton(loginFormContainer);
        btnSeConnecter->setObjectName("btnSeConnecter");
        btnSeConnecter->setMinimumHeight(44);
        btnSeConnecter->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));

        vLoginForm->addWidget(btnSeConnecter);

        label_login_error = new QLabel(loginFormContainer);
        label_login_error->setObjectName("label_login_error");
        label_login_error->setAlignment(Qt::AlignCenter);
        label_login_error->setWordWrap(true);

        vLoginForm->addWidget(label_login_error);

        btnNavigateForgot = new QPushButton(loginFormContainer);
        btnNavigateForgot->setObjectName("btnNavigateForgot");

        vLoginForm->addWidget(btnNavigateForgot);


        hCenterConn->addWidget(loginFormContainer);

        spacerRightConn = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hCenterConn->addItem(spacerRightConn);


        vertical_connexion->addLayout(hCenterConn);

        spacerBottom = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_connexion->addItem(spacerBottom);

        tabWidget->addTab(tabConnexion, QString());
        tabMotPasseOublie = new QWidget();
        tabMotPasseOublie->setObjectName("tabMotPasseOublie");
        vertical_mdp_oublie = new QVBoxLayout(tabMotPasseOublie);
        vertical_mdp_oublie->setObjectName("vertical_mdp_oublie");
        groupFPStep1 = new QGroupBox(tabMotPasseOublie);
        groupFPStep1->setObjectName("groupFPStep1");
        formFP1 = new QFormLayout(groupFPStep1);
        formFP1->setObjectName("formFP1");
        label_user_identite_fp = new QLabel(groupFPStep1);
        label_user_identite_fp->setObjectName("label_user_identite_fp");

        formFP1->setWidget(0, QFormLayout::LabelRole, label_user_identite_fp);

        line_user_identite_fp = new QLineEdit(groupFPStep1);
        line_user_identite_fp->setObjectName("line_user_identite_fp");

        formFP1->setWidget(0, QFormLayout::FieldRole, line_user_identite_fp);

        btnValiderIdentite = new QPushButton(groupFPStep1);
        btnValiderIdentite->setObjectName("btnValiderIdentite");

        formFP1->setWidget(1, QFormLayout::SpanningRole, btnValiderIdentite);

        label_user_email_fp = new QLabel(groupFPStep1);
        label_user_email_fp->setObjectName("label_user_email_fp");

        formFP1->setWidget(2, QFormLayout::LabelRole, label_user_email_fp);

        line_user_email_fp = new QLineEdit(groupFPStep1);
        line_user_email_fp->setObjectName("line_user_email_fp");

        formFP1->setWidget(2, QFormLayout::FieldRole, line_user_email_fp);

        btnEnvoyerCode = new QPushButton(groupFPStep1);
        btnEnvoyerCode->setObjectName("btnEnvoyerCode");

        formFP1->setWidget(3, QFormLayout::SpanningRole, btnEnvoyerCode);


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

        tabWidget->addTab(tabMotPasseOublie, QString());

        verticalLayout->addWidget(tabWidget);

        stackedMain->addWidget(EmployeWidget);
        EquipeWidget = new QWidget();
        EquipeWidget->setObjectName("EquipeWidget");
        EquipeWidget->setGeometry(QRect(0, 0, 800, 600));
        statusbar = new QStatusBar(EquipeWidget);
        statusbar->setObjectName("statusbar");
        mainContainerLayout = new QVBoxLayout(EquipeWidget);
        mainContainerLayout->setSpacing(0);
        mainContainerLayout->setObjectName("mainContainerLayout");
        mainContainerLayout->setContentsMargins(0, 0, 0, 0);
        contentFrame = new QFrame(EquipeWidget);
        contentFrame->setObjectName("contentFrame");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(contentFrame->sizePolicy().hasHeightForWidth());
        contentFrame->setSizePolicy(sizePolicy);
        contentLayout = new QVBoxLayout(contentFrame);
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        topNavTabs = new QTabWidget(contentFrame);
        topNavTabs->setObjectName("topNavTabs");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(topNavTabs->sizePolicy().hasHeightForWidth());
        topNavTabs->setSizePolicy(sizePolicy1);
        topNavTabs->setMinimumSize(QSize(0, 50));
        topNavTabs->setMaximumSize(QSize(16777215, 50));
        tabAjouter1 = new QWidget();
        tabAjouter1->setObjectName("tabAjouter1");
        topNavTabs->addTab(tabAjouter1, QString());
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        topNavTabs->addTab(tabGestion, QString());
        tabSupprimer1 = new QWidget();
        tabSupprimer1->setObjectName("tabSupprimer1");
        topNavTabs->addTab(tabSupprimer1, QString());
        tabModifier1 = new QWidget();
        tabModifier1->setObjectName("tabModifier1");
        topNavTabs->addTab(tabModifier1, QString());
        tabStatistique = new QWidget();
        tabStatistique->setObjectName("tabStatistique");
        topNavTabs->addTab(tabStatistique, QString());
        tabSuggestion = new QWidget();
        tabSuggestion->setObjectName("tabSuggestion");
        topNavTabs->addTab(tabSuggestion, QString());
        tabPlanification = new QWidget();
        tabPlanification->setObjectName("tabPlanification");
        topNavTabs->addTab(tabPlanification, QString());

        contentLayout->addWidget(topNavTabs);

        stackedWidget = new QStackedWidget(contentFrame);
        stackedWidget->setObjectName("stackedWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy2);
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
        label_30 = new QLabel(addFormFrame);
        label_30->setObjectName("label_30");

        addFormLayout->setWidget(0, QFormLayout::LabelRole, label_30);

        lineEditNomEquipeAjout = new QLineEdit(addFormFrame);
        lineEditNomEquipeAjout->setObjectName("lineEditNomEquipeAjout");

        addFormLayout->setWidget(0, QFormLayout::FieldRole, lineEditNomEquipeAjout);

        label_31 = new QLabel(addFormFrame);
        label_31->setObjectName("label_31");

        addFormLayout->setWidget(1, QFormLayout::LabelRole, label_31);

        lineEditChefEquipeAjout = new QLineEdit(addFormFrame);
        lineEditChefEquipeAjout->setObjectName("lineEditChefEquipeAjout");

        addFormLayout->setWidget(1, QFormLayout::FieldRole, lineEditChefEquipeAjout);

        label_32 = new QLabel(addFormFrame);
        label_32->setObjectName("label_32");

        addFormLayout->setWidget(2, QFormLayout::LabelRole, label_32);

        comboBoxSpecialiteEquipeAjout = new QComboBox(addFormFrame);
        comboBoxSpecialiteEquipeAjout->addItem(QString());
        comboBoxSpecialiteEquipeAjout->addItem(QString());
        comboBoxSpecialiteEquipeAjout->addItem(QString());
        comboBoxSpecialiteEquipeAjout->addItem(QString());
        comboBoxSpecialiteEquipeAjout->addItem(QString());
        comboBoxSpecialiteEquipeAjout->setObjectName("comboBoxSpecialiteEquipeAjout");

        addFormLayout->setWidget(2, QFormLayout::FieldRole, comboBoxSpecialiteEquipeAjout);

        label_33 = new QLabel(addFormFrame);
        label_33->setObjectName("label_33");

        addFormLayout->setWidget(3, QFormLayout::LabelRole, label_33);

        comboBoxNbMembresEquipeAjout = new QComboBox(addFormFrame);
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->addItem(QString());
        comboBoxNbMembresEquipeAjout->setObjectName("comboBoxNbMembresEquipeAjout");

        addFormLayout->setWidget(3, QFormLayout::FieldRole, comboBoxNbMembresEquipeAjout);


        addLayout->addWidget(addFormFrame);

        addSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        addLayout->addItem(addSpacer);

        addActionLayout = new QHBoxLayout();
        addActionLayout->setObjectName("addActionLayout");
        addActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        addActionLayout->addItem(addActionSpacer);

        btnAjouterEquipe = new QPushButton(pageadd);
        btnAjouterEquipe->setObjectName("btnAjouterEquipe");
        btnAjouterEquipe->setMinimumWidth(200);

        addActionLayout->addWidget(btnAjouterEquipe);


        addLayout->addLayout(addActionLayout);

        stackedWidget->addWidget(pageadd);
        page_rech = new QWidget();
        page_rech->setObjectName("page_rech");
        rechLayout = new QVBoxLayout(page_rech);
        rechLayout->setSpacing(8);
        rechLayout->setObjectName("rechLayout");
        rechLayout->setContentsMargins(10, 10, 20, 10);
        rechTopLayout = new QHBoxLayout();
        rechTopLayout->setSpacing(8);
        rechTopLayout->setObjectName("rechTopLayout");
        lineEditRechercheEquipe = new QLineEdit(page_rech);
        lineEditRechercheEquipe->setObjectName("lineEditRechercheEquipe");

        rechTopLayout->addWidget(lineEditRechercheEquipe);

        btnFiltre = new QPushButton(page_rech);
        btnFiltre->setObjectName("btnFiltre");
        btnFiltre->setMaximumWidth(100);

        rechTopLayout->addWidget(btnFiltre);

        searchSpacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        rechTopLayout->addItem(searchSpacer);


        rechLayout->addLayout(rechTopLayout);

        rechMainLayout = new QHBoxLayout();
        rechMainLayout->setSpacing(8);
        rechMainLayout->setObjectName("rechMainLayout");
        frame_4 = new QFrame(page_rech);
        frame_4->setObjectName("frame_4");
        frame4Layout = new QVBoxLayout(frame_4);
        frame4Layout->setSpacing(12);
        frame4Layout->setObjectName("frame4Layout");
        label_7 = new QLabel(frame_4);
        label_7->setObjectName("label_7");

        frame4Layout->addWidget(label_7);

        btnTrier = new QPushButton(frame_4);
        btnTrier->setObjectName("btnTrier");

        frame4Layout->addWidget(btnTrier);

        comboBoxTriEquipe = new QComboBox(frame_4);
        comboBoxTriEquipe->addItem(QString());
        comboBoxTriEquipe->addItem(QString());
        comboBoxTriEquipe->addItem(QString());
        comboBoxTriEquipe->addItem(QString());
        comboBoxTriEquipe->setObjectName("comboBoxTriEquipe");

        frame4Layout->addWidget(comboBoxTriEquipe);

        sortOptionsLayout = new QHBoxLayout();
        sortOptionsLayout->setObjectName("sortOptionsLayout");
        checkBoxTriEquipeCroissant = new QCheckBox(frame_4);
        checkBoxTriEquipeCroissant->setObjectName("checkBoxTriEquipeCroissant");

        sortOptionsLayout->addWidget(checkBoxTriEquipeCroissant);

        checkBoxTriEquipeDecroissant = new QCheckBox(frame_4);
        checkBoxTriEquipeDecroissant->setObjectName("checkBoxTriEquipeDecroissant");

        sortOptionsLayout->addWidget(checkBoxTriEquipeDecroissant);


        frame4Layout->addLayout(sortOptionsLayout);

        frame4Spacer = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        frame4Layout->addItem(frame4Spacer);


        rechMainLayout->addWidget(frame_4);

        tableWidgetEquipe = new QTableWidget(page_rech);
        if (tableWidgetEquipe->columnCount() < 6)
            tableWidgetEquipe->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidgetEquipe->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidgetEquipe->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidgetEquipe->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidgetEquipe->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidgetEquipe->setHorizontalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidgetEquipe->setHorizontalHeaderItem(5, __qtablewidgetitem17);
        tableWidgetEquipe->setObjectName("tableWidgetEquipe");
        sizePolicy2.setHeightForWidth(tableWidgetEquipe->sizePolicy().hasHeightForWidth());
        tableWidgetEquipe->setSizePolicy(sizePolicy2);
        tableWidgetEquipe->setVerticalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOn);
        tableWidgetEquipe->setHorizontalScrollBarPolicy(Qt::ScrollBarPolicy::ScrollBarAlwaysOff);
        tableWidgetEquipe->setAutoScroll(false);
        tableWidgetEquipe->horizontalHeader()->setStretchLastSection(true);

        rechMainLayout->addWidget(tableWidgetEquipe);


        rechLayout->addLayout(rechMainLayout);

        stackedWidget->addWidget(page_rech);
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

        lineEditNomEquipeModif = new QLineEdit(modifFormFrame);
        lineEditNomEquipeModif->setObjectName("lineEditNomEquipeModif");

        modifFormLayout->setWidget(1, QFormLayout::FieldRole, lineEditNomEquipeModif);

        label_36 = new QLabel(modifFormFrame);
        label_36->setObjectName("label_36");

        modifFormLayout->setWidget(2, QFormLayout::LabelRole, label_36);

        lineEditChefEquipeModif = new QLineEdit(modifFormFrame);
        lineEditChefEquipeModif->setObjectName("lineEditChefEquipeModif");

        modifFormLayout->setWidget(2, QFormLayout::FieldRole, lineEditChefEquipeModif);

        label_37 = new QLabel(modifFormFrame);
        label_37->setObjectName("label_37");

        modifFormLayout->setWidget(3, QFormLayout::LabelRole, label_37);

        comboBoxSpecialiteEquipeModif = new QComboBox(modifFormFrame);
        comboBoxSpecialiteEquipeModif->addItem(QString());
        comboBoxSpecialiteEquipeModif->addItem(QString());
        comboBoxSpecialiteEquipeModif->addItem(QString());
        comboBoxSpecialiteEquipeModif->addItem(QString());
        comboBoxSpecialiteEquipeModif->addItem(QString());
        comboBoxSpecialiteEquipeModif->setObjectName("comboBoxSpecialiteEquipeModif");

        modifFormLayout->setWidget(3, QFormLayout::FieldRole, comboBoxSpecialiteEquipeModif);

        label_38 = new QLabel(modifFormFrame);
        label_38->setObjectName("label_38");

        modifFormLayout->setWidget(4, QFormLayout::LabelRole, label_38);

        comboBoxNbMembresEquipeModif = new QComboBox(modifFormFrame);
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->addItem(QString());
        comboBoxNbMembresEquipeModif->setObjectName("comboBoxNbMembresEquipeModif");

        modifFormLayout->setWidget(4, QFormLayout::FieldRole, comboBoxNbMembresEquipeModif);


        modifLayout->addWidget(modifFormFrame);

        modifSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        modifLayout->addItem(modifSpacer);

        modifActionLayout = new QHBoxLayout();
        modifActionLayout->setObjectName("modifActionLayout");
        modifActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        modifActionLayout->addItem(modifActionSpacer);

        btnModifierEquipe = new QPushButton(pagemodif);
        btnModifierEquipe->setObjectName("btnModifierEquipe");
        btnModifierEquipe->setMinimumWidth(200);

        modifActionLayout->addWidget(btnModifierEquipe);


        modifLayout->addLayout(modifActionLayout);

        stackedWidget->addWidget(pagemodif);
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

        lineEditIdEquipeSuppression = new QLineEdit(suppFormFrame);
        lineEditIdEquipeSuppression->setObjectName("lineEditIdEquipeSuppression");

        suppIdLayout->addWidget(lineEditIdEquipeSuppression);


        suppFormLayout->addLayout(suppIdLayout);

        suppSpacer = new QSpacerItem(20, 80, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        suppFormLayout->addItem(suppSpacer);

        suppActionLayout = new QHBoxLayout();
        suppActionLayout->setObjectName("suppActionLayout");
        suppActionSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        suppActionLayout->addItem(suppActionSpacer);

        btnSupprimerEquipe = new QPushButton(suppFormFrame);
        btnSupprimerEquipe->setObjectName("btnSupprimerEquipe");
        btnSupprimerEquipe->setMinimumWidth(200);

        suppActionLayout->addWidget(btnSupprimerEquipe);


        suppFormLayout->addLayout(suppActionLayout);


        suppLayout->addWidget(suppFormFrame);

        stackedWidget->addWidget(pagesupp);
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

        statsSecondRowLayout = new QHBoxLayout();
        statsSecondRowLayout->setObjectName("statsSecondRowLayout");
        objectifsGroup = new QGroupBox(page_stat);
        objectifsGroup->setObjectName("objectifsGroup");
        vboxLayout2 = new QVBoxLayout(objectifsGroup);
        vboxLayout2->setObjectName("vboxLayout2");
        listWidget_2 = new QListWidget(objectifsGroup);
        new QListWidgetItem(listWidget_2);
        listWidget_2->setObjectName("listWidget_2");

        vboxLayout2->addWidget(listWidget_2);


        statsSecondRowLayout->addWidget(objectifsGroup);

        evalGroup = new QGroupBox(page_stat);
        evalGroup->setObjectName("evalGroup");
        vboxLayout3 = new QVBoxLayout(evalGroup);
        vboxLayout3->setObjectName("vboxLayout3");
        plainTextEdit_3 = new QPlainTextEdit(evalGroup);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setReadOnly(true);

        vboxLayout3->addWidget(plainTextEdit_3);


        statsSecondRowLayout->addWidget(evalGroup);


        statLayout->addLayout(statsSecondRowLayout);

        exportLayout = new QHBoxLayout();
        exportLayout->setObjectName("exportLayout");
        exportSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        exportLayout->addItem(exportSpacer);

        btnExportEquipePdf = new QPushButton(page_stat);
        btnExportEquipePdf->setObjectName("btnExportEquipePdf");
        btnExportEquipePdf->setMaximumWidth(150);

        exportLayout->addWidget(btnExportEquipePdf);


        statLayout->addLayout(exportLayout);

        stackedWidget->addWidget(page_stat);
        sugg = new QWidget();
        sugg->setObjectName("sugg");
        frame_6 = new QFrame(sugg);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 10, 1271, 711));
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(frame_6);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(10, 260, 81, 51));
        label_17 = new QLabel(frame_6);
        label_17->setObjectName("label_17");
        label_17->setGeometry(QRect(530, 0, 331, 51));
        btnRechercherRecommandationEquipe = new QPushButton(frame_6);
        btnRechercherRecommandationEquipe->setObjectName("btnRechercherRecommandationEquipe");
        btnRechercherRecommandationEquipe->setGeometry(QRect(50, 580, 441, 41));
        checkBoxRequiertDisponibilite = new QCheckBox(frame_6);
        checkBoxRequiertDisponibilite->setObjectName("checkBoxRequiertDisponibilite");
        checkBoxRequiertDisponibilite->setGeometry(QRect(20, 460, 221, 51));
        label_18 = new QLabel(frame_6);
        label_18->setObjectName("label_18");
        label_18->setGeometry(QRect(10, 100, 141, 41));
        comboBoxSpecialiteRecommandation = new QComboBox(frame_6);
        comboBoxSpecialiteRecommandation->addItem(QString());
        comboBoxSpecialiteRecommandation->addItem(QString());
        comboBoxSpecialiteRecommandation->addItem(QString());
        comboBoxSpecialiteRecommandation->addItem(QString());
        comboBoxSpecialiteRecommandation->addItem(QString());
        comboBoxSpecialiteRecommandation->addItem(QString());
        comboBoxSpecialiteRecommandation->setObjectName("comboBoxSpecialiteRecommandation");
        comboBoxSpecialiteRecommandation->setGeometry(QRect(145, 100, 321, 44));
        label_19 = new QLabel(frame_6);
        label_19->setObjectName("label_19");
        label_19->setGeometry(QRect(10, 160, 571, 41));
        lineEditNbMembresMinRecommandation = new QLineEdit(frame_6);
        lineEditNbMembresMinRecommandation->setObjectName("lineEditNbMembresMinRecommandation");
        lineEditNbMembresMinRecommandation->setGeometry(QRect(10, 220, 584, 31));
        checkBoxUrgentRecommandation = new QCheckBox(frame_6);
        checkBoxUrgentRecommandation->setObjectName("checkBoxUrgentRecommandation");
        checkBoxUrgentRecommandation->setGeometry(QRect(20, 330, 101, 51));
        checkBoxEtatNormalRecommandation = new QCheckBox(frame_6);
        checkBoxEtatNormalRecommandation->setObjectName("checkBoxEtatNormalRecommandation");
        checkBoxEtatNormalRecommandation->setGeometry(QRect(140, 330, 121, 51));
        label_24 = new QLabel(frame_6);
        label_24->setObjectName("label_24");
        label_24->setGeometry(QRect(10, 380, 231, 51));
        listWidget_3 = new QListWidget(frame_6);
        new QListWidgetItem(listWidget_3);
        listWidget_3->setObjectName("listWidget_3");
        listWidget_3->setGeometry(QRect(730, 100, 531, 601));
        line_3 = new QFrame(frame_6);
        line_3->setObjectName("line_3");
        line_3->setGeometry(QRect(680, 50, 16, 661));
        line_3->setFrameShape(QFrame::VLine);
        label_25 = new QLabel(frame_6);
        label_25->setObjectName("label_25");
        label_25->setGeometry(QRect(920, 50, 121, 41));
        comboBoxDifficulteRecommandation = new QComboBox(frame_6);
        comboBoxDifficulteRecommandation->addItem(QString());
        comboBoxDifficulteRecommandation->addItem(QString());
        comboBoxDifficulteRecommandation->addItem(QString());
        comboBoxDifficulteRecommandation->addItem(QString());
        comboBoxDifficulteRecommandation->setObjectName("comboBoxDifficulteRecommandation");
        comboBoxDifficulteRecommandation->setGeometry(QRect(145, 380, 321, 44));
        stackedWidget->addWidget(sugg);
        page_planification = new QWidget();
        page_planification->setObjectName("page_planification");
        planLayout = new QVBoxLayout(page_planification);
        planLayout->setSpacing(8);
        planLayout->setObjectName("planLayout");
        planSearchLayout = new QHBoxLayout();
        planSearchLayout->setSpacing(4);
        planSearchLayout->setObjectName("planSearchLayout");
        lineEditRecherchePlanificationEquipe = new QLineEdit(page_planification);
        lineEditRecherchePlanificationEquipe->setObjectName("lineEditRecherchePlanificationEquipe");

        planSearchLayout->addWidget(lineEditRecherchePlanificationEquipe);

        btnRechercherPlanificationEquipe = new QPushButton(page_planification);
        btnRechercherPlanificationEquipe->setObjectName("btnRechercherPlanificationEquipe");
        btnRechercherPlanificationEquipe->setMinimumSize(QSize(120, 0));
        btnRechercherPlanificationEquipe->setMaximumSize(QSize(150, 16777215));

        planSearchLayout->addWidget(btnRechercherPlanificationEquipe);


        planLayout->addLayout(planSearchLayout);

        planContentLayout = new QHBoxLayout();
        planContentLayout->setSpacing(8);
        planContentLayout->setObjectName("planContentLayout");
        calendarWidget = new QCalendarWidget(page_planification);
        calendarWidget->setObjectName("calendarWidget");
        sizePolicy2.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy2);
        calendarWidget->setMinimumSize(QSize(400, 400));

        planContentLayout->addWidget(calendarWidget);

        taskFrame = new QFrame(page_planification);
        taskFrame->setObjectName("taskFrame");
        sizePolicy2.setHeightForWidth(taskFrame->sizePolicy().hasHeightForWidth());
        taskFrame->setSizePolicy(sizePolicy2);
        taskFrame->setMinimumSize(QSize(300, 400));
        taskLayout = new QVBoxLayout(taskFrame);
        taskLayout->setSpacing(4);
        taskLayout->setObjectName("taskLayout");
        taskLabel = new QLabel(taskFrame);
        taskLabel->setObjectName("taskLabel");

        taskLayout->addWidget(taskLabel);

        listWidget = new QListWidget(taskFrame);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName("listWidget");
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);

        taskLayout->addWidget(listWidget);


        planContentLayout->addWidget(taskFrame);


        planLayout->addLayout(planContentLayout);

        stackedWidget->addWidget(page_planification);

        contentLayout->addWidget(stackedWidget);


        mainContainerLayout->addWidget(contentFrame);

        stackedMain->addWidget(EquipeWidget);
        WidgetClient = new QWidget();
        WidgetClient->setObjectName("WidgetClient");
        WidgetClient->setGeometry(QRect(0, 0, 1000, 700));
        rootLayout = new QVBoxLayout(WidgetClient);
        rootLayout->setSpacing(0);
        rootLayout->setObjectName("rootLayout");
        rootLayout->setContentsMargins(0, 0, 0, 0);
        mainContentLayout = new QVBoxLayout();
        mainContentLayout->setObjectName("mainContentLayout");
        mainContentLayout->setContentsMargins(10, 10, 10, 10);
        contentLayout1 = new QHBoxLayout();
        contentLayout1->setObjectName("contentLayout1");
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

        verticalSpacer1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_sidebar->addItem(verticalSpacer1);

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


        contentLayout1->addWidget(grpRechercheFiltre);

        centerLayout = new QVBoxLayout();
        centerLayout->setObjectName("centerLayout");
        tabWidgetClient = new QTabWidget(WidgetClient);
        tabWidgetClient->setObjectName("tabWidgetClient");
        tabAjouter2 = new QWidget();
        tabAjouter2->setObjectName("tabAjouter2");
        vlAjouter = new QVBoxLayout(tabAjouter2);
        vlAjouter->setObjectName("vlAjouter");
        vlAjouter->setContentsMargins(20, 20, 20, 20);
        grpFormAjouter = new QGroupBox(tabAjouter2);
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

        btnConfirmerAjouter = new QPushButton(tabAjouter2);
        btnConfirmerAjouter->setObjectName("btnConfirmerAjouter");
        btnConfirmerAjouter->setMinimumHeight(48);
        btnConfirmerAjouter->setMinimumWidth(220);

        hboxLayout->addWidget(btnConfirmerAjouter);

        btnAnnulerAjouter = new QPushButton(tabAjouter2);
        btnAnnulerAjouter->setObjectName("btnAnnulerAjouter");
        btnAnnulerAjouter->setMinimumHeight(48);
        btnAnnulerAjouter->setMinimumWidth(160);

        hboxLayout->addWidget(btnAnnulerAjouter);


        vlAjouter->addLayout(hboxLayout);

        tabWidgetClient->addTab(tabAjouter2, QString());
        tabListeClients = new QWidget();
        tabListeClients->setObjectName("tabListeClients");
        verticalLayout_3 = new QVBoxLayout(tabListeClients);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tableClients = new QTableWidget(tabListeClients);
        tableClients->setObjectName("tableClients");
        tableClients->setAlternatingRowColors(true);
        tableClients->setSelectionBehavior(QAbstractItemView::SelectRows);

        verticalLayout_3->addWidget(tableClients);

        tabWidgetClient->addTab(tabListeClients, QString());
        tabSupprimer2 = new QWidget();
        tabSupprimer2->setObjectName("tabSupprimer2");
        vlSupprimer = new QVBoxLayout(tabSupprimer2);
        vlSupprimer->setObjectName("vlSupprimer");
        vlSupprimer->setContentsMargins(20, 20, 20, 20);
        lblSupprimerInfo = new QLabel(tabSupprimer2);
        lblSupprimerInfo->setObjectName("lblSupprimerInfo");
        lblSupprimerInfo->setWordWrap(true);

        vlSupprimer->addWidget(lblSupprimerInfo);

        grpClientASupprimer = new QGroupBox(tabSupprimer2);
        grpClientASupprimer->setObjectName("grpClientASupprimer");
        vboxLayout4 = new QVBoxLayout(grpClientASupprimer);
        vboxLayout4->setObjectName("vboxLayout4");
        lblSupprimerNom = new QLabel(grpClientASupprimer);
        lblSupprimerNom->setObjectName("lblSupprimerNom");
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        lblSupprimerNom->setFont(font2);

        vboxLayout4->addWidget(lblSupprimerNom);

        lblSupprimerDetails = new QLabel(grpClientASupprimer);
        lblSupprimerDetails->setObjectName("lblSupprimerDetails");

        vboxLayout4->addWidget(lblSupprimerDetails);


        vlSupprimer->addWidget(grpClientASupprimer);

        spacerItem2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlSupprimer->addItem(spacerItem2);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        spacerItem3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout1->addItem(spacerItem3);

        btnConfirmerSupprimer = new QPushButton(tabSupprimer2);
        btnConfirmerSupprimer->setObjectName("btnConfirmerSupprimer");
        btnConfirmerSupprimer->setMinimumHeight(48);
        btnConfirmerSupprimer->setMinimumWidth(260);

        hboxLayout1->addWidget(btnConfirmerSupprimer);

        btnAnnulerSupprimer = new QPushButton(tabSupprimer2);
        btnAnnulerSupprimer->setObjectName("btnAnnulerSupprimer");
        btnAnnulerSupprimer->setMinimumHeight(48);
        btnAnnulerSupprimer->setMinimumWidth(160);

        hboxLayout1->addWidget(btnAnnulerSupprimer);


        vlSupprimer->addLayout(hboxLayout1);

        tabWidgetClient->addTab(tabSupprimer2, QString());
        tabModifier2 = new QWidget();
        tabModifier2->setObjectName("tabModifier2");
        vlModifier = new QVBoxLayout(tabModifier2);
        vlModifier->setObjectName("vlModifier");
        vlModifier->setContentsMargins(20, 20, 20, 20);
        lblModifierInfo = new QLabel(tabModifier2);
        lblModifierInfo->setObjectName("lblModifierInfo");

        vlModifier->addWidget(lblModifierInfo);

        grpFormModifier = new QGroupBox(tabModifier2);
        grpFormModifier->setObjectName("grpFormModifier");
        formModifier1 = new QFormLayout(grpFormModifier);
        formModifier1->setObjectName("formModifier1");
        formModifier1->setHorizontalSpacing(20);
        formModifier1->setVerticalSpacing(14);
        label5 = new QLabel(grpFormModifier);
        label5->setObjectName("label5");

        formModifier1->setWidget(0, QFormLayout::LabelRole, label5);

        txtModifierNom = new QLineEdit(grpFormModifier);
        txtModifierNom->setObjectName("txtModifierNom");

        formModifier1->setWidget(0, QFormLayout::FieldRole, txtModifierNom);

        label6 = new QLabel(grpFormModifier);
        label6->setObjectName("label6");

        formModifier1->setWidget(1, QFormLayout::LabelRole, label6);

        cmbModifierType = new QComboBox(grpFormModifier);
        cmbModifierType->setObjectName("cmbModifierType");

        formModifier1->setWidget(1, QFormLayout::FieldRole, cmbModifierType);

        label7 = new QLabel(grpFormModifier);
        label7->setObjectName("label7");

        formModifier1->setWidget(2, QFormLayout::LabelRole, label7);

        txtModifierTel = new QLineEdit(grpFormModifier);
        txtModifierTel->setObjectName("txtModifierTel");

        formModifier1->setWidget(2, QFormLayout::FieldRole, txtModifierTel);

        label8 = new QLabel(grpFormModifier);
        label8->setObjectName("label8");

        formModifier1->setWidget(3, QFormLayout::LabelRole, label8);

        txtModifierEmail = new QLineEdit(grpFormModifier);
        txtModifierEmail->setObjectName("txtModifierEmail");

        formModifier1->setWidget(3, QFormLayout::FieldRole, txtModifierEmail);

        label9 = new QLabel(grpFormModifier);
        label9->setObjectName("label9");

        formModifier1->setWidget(4, QFormLayout::LabelRole, label9);

        cmbModifierStatut = new QComboBox(grpFormModifier);
        cmbModifierStatut->setObjectName("cmbModifierStatut");

        formModifier1->setWidget(4, QFormLayout::FieldRole, cmbModifierStatut);


        vlModifier->addWidget(grpFormModifier);

        spacerItem4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vlModifier->addItem(spacerItem4);

        hboxLayout2 = new QHBoxLayout();
        hboxLayout2->setObjectName("hboxLayout2");
        spacerItem5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout2->addItem(spacerItem5);

        btnConfirmerModifier = new QPushButton(tabModifier2);
        btnConfirmerModifier->setObjectName("btnConfirmerModifier");
        btnConfirmerModifier->setMinimumHeight(48);
        btnConfirmerModifier->setMinimumWidth(260);

        hboxLayout2->addWidget(btnConfirmerModifier);

        btnAnnulerModifier = new QPushButton(tabModifier2);
        btnAnnulerModifier->setObjectName("btnAnnulerModifier");
        btnAnnulerModifier->setMinimumHeight(48);
        btnAnnulerModifier->setMinimumWidth(160);

        hboxLayout2->addWidget(btnAnnulerModifier);


        vlModifier->addLayout(hboxLayout2);

        tabWidgetClient->addTab(tabModifier2, QString());
        tabStatistiques1 = new QWidget();
        tabStatistiques1->setObjectName("tabStatistiques1");
        verticalLayout_4 = new QVBoxLayout(tabStatistiques1);
        verticalLayout_4->setObjectName("verticalLayout_4");
        txtStatistiques = new QTextEdit(tabStatistiques1);
        txtStatistiques->setObjectName("txtStatistiques");
        txtStatistiques->setReadOnly(true);

        verticalLayout_4->addWidget(txtStatistiques);

        tabWidgetClient->addTab(tabStatistiques1, QString());
        tabAlertes = new QWidget();
        tabAlertes->setObjectName("tabAlertes");
        verticalLayout_7 = new QVBoxLayout(tabAlertes);
        verticalLayout_7->setObjectName("verticalLayout_7");
        txtAlertes = new QTextEdit(tabAlertes);
        txtAlertes->setObjectName("txtAlertes");
        txtAlertes->setReadOnly(true);

        verticalLayout_7->addWidget(txtAlertes);

        tabWidgetClient->addTab(tabAlertes, QString());
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
        QFont font3;
        font3.setPointSize(11);
        lblInfoStatut->setFont(font3);

        verticalLayout_general->addWidget(lblInfoStatut);

        lblInfoAlertes = new QLabel(grpInfoGenerales);
        lblInfoAlertes->setObjectName("lblInfoAlertes");
        lblInfoAlertes->setFont(font3);

        verticalLayout_general->addWidget(lblInfoAlertes);


        horizontalLayout_row1->addWidget(grpInfoGenerales);

        grpRetards = new QGroupBox(grpClientDetails);
        grpRetards->setObjectName("grpRetards");
        verticalLayout_retards = new QVBoxLayout(grpRetards);
        verticalLayout_retards->setObjectName("verticalLayout_retards");
        lblRetardsNombre = new QLabel(grpRetards);
        lblRetardsNombre->setObjectName("lblRetardsNombre");
        lblRetardsNombre->setFont(font3);

        verticalLayout_retards->addWidget(lblRetardsNombre);

        lblRetardsMoyen = new QLabel(grpRetards);
        lblRetardsMoyen->setObjectName("lblRetardsMoyen");
        lblRetardsMoyen->setFont(font3);

        verticalLayout_retards->addWidget(lblRetardsMoyen);

        lblRetardsTotal = new QLabel(grpRetards);
        lblRetardsTotal->setObjectName("lblRetardsTotal");
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        lblRetardsTotal->setFont(font4);

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
        lblRetoursNombre->setFont(font3);

        verticalLayout_retours->addWidget(lblRetoursNombre);

        lblRetoursTaux = new QLabel(grpRetoursQualite);
        lblRetoursTaux->setObjectName("lblRetoursTaux");
        lblRetoursTaux->setFont(font3);

        verticalLayout_retours->addWidget(lblRetoursTaux);

        lblRetoursDernier = new QLabel(grpRetoursQualite);
        lblRetoursDernier->setObjectName("lblRetoursDernier");
        lblRetoursDernier->setFont(font3);

        verticalLayout_retours->addWidget(lblRetoursDernier);


        horizontalLayout_row2->addWidget(grpRetoursQualite);

        grpPrix = new QGroupBox(grpClientDetails);
        grpPrix->setObjectName("grpPrix");
        verticalLayout_prix = new QVBoxLayout(grpPrix);
        verticalLayout_prix->setObjectName("verticalLayout_prix");
        lblPrixMoyen = new QLabel(grpPrix);
        lblPrixMoyen->setObjectName("lblPrixMoyen");
        lblPrixMoyen->setFont(font3);

        verticalLayout_prix->addWidget(lblPrixMoyen);

        lblPrixTotal = new QLabel(grpPrix);
        lblPrixTotal->setObjectName("lblPrixTotal");
        lblPrixTotal->setFont(font4);

        verticalLayout_prix->addWidget(lblPrixTotal);

        lblPrixRemise = new QLabel(grpPrix);
        lblPrixRemise->setObjectName("lblPrixRemise");
        lblPrixRemise->setFont(font3);

        verticalLayout_prix->addWidget(lblPrixRemise);


        horizontalLayout_row2->addWidget(grpPrix);


        verticalLayout_details->addLayout(horizontalLayout_row2);

        grpHistorique = new QGroupBox(grpClientDetails);
        grpHistorique->setObjectName("grpHistorique");
        horizontalLayout_historique = new QHBoxLayout(grpHistorique);
        horizontalLayout_historique->setObjectName("horizontalLayout_historique");
        lblClientDepuis = new QLabel(grpHistorique);
        lblClientDepuis->setObjectName("lblClientDepuis");
        lblClientDepuis->setFont(font3);

        horizontalLayout_historique->addWidget(lblClientDepuis);

        lblNombreCommandes = new QLabel(grpHistorique);
        lblNombreCommandes->setObjectName("lblNombreCommandes");
        lblNombreCommandes->setFont(font3);

        horizontalLayout_historique->addWidget(lblNombreCommandes);

        lblDerniereCommande = new QLabel(grpHistorique);
        lblDerniereCommande->setObjectName("lblDerniereCommande");
        lblDerniereCommande->setFont(font3);

        horizontalLayout_historique->addWidget(lblDerniereCommande);


        verticalLayout_details->addWidget(grpHistorique);

        verticalSpacer_info = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_details->addItem(verticalSpacer_info);


        verticalLayout_infos->addWidget(grpClientDetails);

        tabWidgetClient->addTab(tabInfosClient, QString());
        tabExportPDF = new QWidget();
        tabExportPDF->setObjectName("tabExportPDF");
        verticalLayout_export = new QVBoxLayout(tabExportPDF);
        verticalLayout_export->setSpacing(12);
        verticalLayout_export->setObjectName("verticalLayout_export");
        verticalLayout_export->setContentsMargins(15, 15, 15, 15);
        grpExportOptions = new QGroupBox(tabExportPDF);
        grpExportOptions->setObjectName("grpExportOptions");
        vExportOptions1 = new QVBoxLayout(grpExportOptions);
        vExportOptions1->setSpacing(10);
        vExportOptions1->setObjectName("vExportOptions1");
        btnExportListeClients = new QPushButton(grpExportOptions);
        btnExportListeClients->setObjectName("btnExportListeClients");
        btnExportListeClients->setMinimumHeight(58);

        vExportOptions1->addWidget(btnExportListeClients);

        btnExportStatistiques = new QPushButton(grpExportOptions);
        btnExportStatistiques->setObjectName("btnExportStatistiques");
        btnExportStatistiques->setMinimumHeight(58);

        vExportOptions1->addWidget(btnExportStatistiques);

        btnExportFicheClient = new QPushButton(grpExportOptions);
        btnExportFicheClient->setObjectName("btnExportFicheClient");
        btnExportFicheClient->setMinimumHeight(58);

        vExportOptions1->addWidget(btnExportFicheClient);


        verticalLayout_export->addWidget(grpExportOptions);

        grpParamsExport = new QGroupBox(tabExportPDF);
        grpParamsExport->setObjectName("grpParamsExport");
        formParamsExport = new QFormLayout(grpParamsExport);
        formParamsExport->setObjectName("formParamsExport");
        lblIdClient = new QLabel(grpParamsExport);
        lblIdClient->setObjectName("lblIdClient");

        formParamsExport->setWidget(0, QFormLayout::LabelRole, lblIdClient);

        lineEdit_id_export1 = new QLineEdit(grpParamsExport);
        lineEdit_id_export1->setObjectName("lineEdit_id_export1");

        formParamsExport->setWidget(0, QFormLayout::FieldRole, lineEdit_id_export1);


        verticalLayout_export->addWidget(grpParamsExport);

        grpMessagesExport = new QGroupBox(tabExportPDF);
        grpMessagesExport->setObjectName("grpMessagesExport");
        vMessagesExport1 = new QVBoxLayout(grpMessagesExport);
        vMessagesExport1->setObjectName("vMessagesExport1");
        textEdit_export_messages1 = new QTextEdit(grpMessagesExport);
        textEdit_export_messages1->setObjectName("textEdit_export_messages1");
        textEdit_export_messages1->setReadOnly(true);
        textEdit_export_messages1->setMinimumHeight(100);

        vMessagesExport1->addWidget(textEdit_export_messages1);


        verticalLayout_export->addWidget(grpMessagesExport);

        verticalSpacer_export1 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_export->addItem(verticalSpacer_export1);

        tabWidgetClient->addTab(tabExportPDF, QString());

        centerLayout->addWidget(tabWidgetClient);


        contentLayout1->addLayout(centerLayout);


        mainContentLayout->addLayout(contentLayout1);


        rootLayout->addLayout(mainContentLayout);

        stackedMain->addWidget(WidgetClient);
        LaboWidget = new QWidget();
        LaboWidget->setObjectName("LaboWidget");
        LaboWidget->setGeometry(QRect(0, 0, 900, 700));
        mainLayout = new QVBoxLayout(LaboWidget);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName("mainLayout");
        mainLayout->setContentsMargins(0, 0, 0, 0);
        topNavTabs1 = new QTabWidget(LaboWidget);
        topNavTabs1->setObjectName("topNavTabs1");
        sizePolicy1.setHeightForWidth(topNavTabs1->sizePolicy().hasHeightForWidth());
        topNavTabs1->setSizePolicy(sizePolicy1);
        topNavTabs1->setMinimumSize(QSize(0, 50));
        topNavTabs1->setMaximumSize(QSize(16777215, 50));
        tabAjouter3 = new QWidget();
        tabAjouter3->setObjectName("tabAjouter3");
        topNavTabs1->addTab(tabAjouter3, QString());
        tabGestion1 = new QWidget();
        tabGestion1->setObjectName("tabGestion1");
        topNavTabs1->addTab(tabGestion1, QString());
        tabSupprimer3 = new QWidget();
        tabSupprimer3->setObjectName("tabSupprimer3");
        topNavTabs1->addTab(tabSupprimer3, QString());
        tabModifier3 = new QWidget();
        tabModifier3->setObjectName("tabModifier3");
        topNavTabs1->addTab(tabModifier3, QString());
        tabStatistique1 = new QWidget();
        tabStatistique1->setObjectName("tabStatistique1");
        topNavTabs1->addTab(tabStatistique1, QString());
        tabGeolocalisation = new QWidget();
        tabGeolocalisation->setObjectName("tabGeolocalisation");
        topNavTabs1->addTab(tabGeolocalisation, QString());
        tabAIBot = new QWidget();
        tabAIBot->setObjectName("tabAIBot");
        topNavTabs1->addTab(tabAIBot, QString());

        mainLayout->addWidget(topNavTabs1);

        stackedWidget1 = new QStackedWidget(LaboWidget);
        stackedWidget1->setObjectName("stackedWidget1");
        sizePolicy2.setHeightForWidth(stackedWidget1->sizePolicy().hasHeightForWidth());
        stackedWidget1->setSizePolicy(sizePolicy2);
        pageadd1 = new QWidget();
        pageadd1->setObjectName("pageadd1");
        addLayout1 = new QVBoxLayout(pageadd1);
        addLayout1->setObjectName("addLayout1");
        addTitle1 = new QLabel(pageadd1);
        addTitle1->setObjectName("addTitle1");

        addLayout1->addWidget(addTitle1);

        addFormFrame1 = new QFrame(pageadd1);
        addFormFrame1->setObjectName("addFormFrame1");
        addFormLayout1 = new QFormLayout(addFormFrame1);
        addFormLayout1->setObjectName("addFormLayout1");
        label_id1 = new QLabel(addFormFrame1);
        label_id1->setObjectName("label_id1");

        addFormLayout1->setWidget(0, QFormLayout::LabelRole, label_id1);

        lineEdit_id1 = new QLineEdit(addFormFrame1);
        lineEdit_id1->setObjectName("lineEdit_id1");
        lineEdit_id1->setReadOnly(true);

        addFormLayout1->setWidget(0, QFormLayout::FieldRole, lineEdit_id1);

        label_nom1 = new QLabel(addFormFrame1);
        label_nom1->setObjectName("label_nom1");

        addFormLayout1->setWidget(1, QFormLayout::LabelRole, label_nom1);

        lineEdit_nom1 = new QLineEdit(addFormFrame1);
        lineEdit_nom1->setObjectName("lineEdit_nom1");

        addFormLayout1->setWidget(1, QFormLayout::FieldRole, lineEdit_nom1);

        label_type = new QLabel(addFormFrame1);
        label_type->setObjectName("label_type");

        addFormLayout1->setWidget(2, QFormLayout::LabelRole, label_type);

        comboBox_type = new QComboBox(addFormFrame1);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");

        addFormLayout1->setWidget(2, QFormLayout::FieldRole, comboBox_type);

        label_conformite = new QLabel(addFormFrame1);
        label_conformite->setObjectName("label_conformite");

        addFormLayout1->setWidget(3, QFormLayout::LabelRole, label_conformite);

        comboBox_conformite = new QComboBox(addFormFrame1);
        comboBox_conformite->addItem(QString());
        comboBox_conformite->addItem(QString());
        comboBox_conformite->setObjectName("comboBox_conformite");

        addFormLayout1->setWidget(3, QFormLayout::FieldRole, comboBox_conformite);

        label_adresse = new QLabel(addFormFrame1);
        label_adresse->setObjectName("label_adresse");

        addFormLayout1->setWidget(4, QFormLayout::LabelRole, label_adresse);

        lineEdit_adresse = new QLineEdit(addFormFrame1);
        lineEdit_adresse->setObjectName("lineEdit_adresse");

        addFormLayout1->setWidget(4, QFormLayout::FieldRole, lineEdit_adresse);

        label_espace = new QLabel(addFormFrame1);
        label_espace->setObjectName("label_espace");

        addFormLayout1->setWidget(5, QFormLayout::LabelRole, label_espace);

        spinBox_espace = new QSpinBox(addFormFrame1);
        spinBox_espace->setObjectName("spinBox_espace");
        spinBox_espace->setMaximum(10000);

        addFormLayout1->setWidget(5, QFormLayout::FieldRole, spinBox_espace);


        addLayout1->addWidget(addFormFrame1);

        addSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        addLayout1->addItem(addSpacer1);

        addActionLayout1 = new QHBoxLayout();
        addActionLayout1->setObjectName("addActionLayout1");
        addActionSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        addActionLayout1->addItem(addActionSpacer1);

        btnAjouterLabo = new QPushButton(pageadd1);
        btnAjouterLabo->setObjectName("btnAjouterLabo");
        btnAjouterLabo->setMinimumWidth(200);

        addActionLayout1->addWidget(btnAjouterLabo);


        addLayout1->addLayout(addActionLayout1);

        stackedWidget1->addWidget(pageadd1);
        page_rech1 = new QWidget();
        page_rech1->setObjectName("page_rech1");
        rechLayout1 = new QVBoxLayout(page_rech1);
        rechLayout1->setSpacing(8);
        rechLayout1->setObjectName("rechLayout1");
        rechLayout1->setContentsMargins(10, 10, 10, 10);
        rechTopLayout1 = new QHBoxLayout();
        rechTopLayout1->setObjectName("rechTopLayout1");
        lineEditRechercheLabo = new QLineEdit(page_rech1);
        lineEditRechercheLabo->setObjectName("lineEditRechercheLabo");

        rechTopLayout1->addWidget(lineEditRechercheLabo);

        btnRechercher = new QPushButton(page_rech1);
        btnRechercher->setObjectName("btnRechercher");

        rechTopLayout1->addWidget(btnRechercher);


        rechLayout1->addLayout(rechTopLayout1);

        rechMainLayout1 = new QHBoxLayout();
        rechMainLayout1->setObjectName("rechMainLayout1");
        frame_41 = new QFrame(page_rech1);
        frame_41->setObjectName("frame_41");
        frame_41->setMinimumSize(QSize(220, 0));
        frame_41->setMaximumSize(QSize(220, 16777215));
        frame4Layout1 = new QVBoxLayout(frame_41);
        frame4Layout1->setObjectName("frame4Layout1");
        label_71 = new QLabel(frame_41);
        label_71->setObjectName("label_71");

        frame4Layout1->addWidget(label_71);

        btnTrier1 = new QPushButton(frame_41);
        btnTrier1->setObjectName("btnTrier1");

        frame4Layout1->addWidget(btnTrier1);

        comboBoxTriLabo = new QComboBox(frame_41);
        comboBoxTriLabo->addItem(QString());
        comboBoxTriLabo->addItem(QString());
        comboBoxTriLabo->addItem(QString());
        comboBoxTriLabo->addItem(QString());
        comboBoxTriLabo->setObjectName("comboBoxTriLabo");

        frame4Layout1->addWidget(comboBoxTriLabo);

        sortOptionsLayout1 = new QHBoxLayout();
        sortOptionsLayout1->setObjectName("sortOptionsLayout1");
        checkBoxTriLaboCroissant = new QCheckBox(frame_41);
        checkBoxTriLaboCroissant->setObjectName("checkBoxTriLaboCroissant");

        sortOptionsLayout1->addWidget(checkBoxTriLaboCroissant);

        checkBoxTriLaboDecroissant = new QCheckBox(frame_41);
        checkBoxTriLaboDecroissant->setObjectName("checkBoxTriLaboDecroissant");

        sortOptionsLayout1->addWidget(checkBoxTriLaboDecroissant);


        frame4Layout1->addLayout(sortOptionsLayout1);

        line_export = new QFrame(frame_41);
        line_export->setObjectName("line_export");
        line_export->setFrameShape(QFrame::Shape::HLine);
        line_export->setFrameShadow(QFrame::Shadow::Sunken);

        frame4Layout1->addWidget(line_export);

        label_export = new QLabel(frame_41);
        label_export->setObjectName("label_export");

        frame4Layout1->addWidget(label_export);

        btnExportPDF = new QPushButton(frame_41);
        btnExportPDF->setObjectName("btnExportPDF");

        frame4Layout1->addWidget(btnExportPDF);

        frame4Spacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        frame4Layout1->addItem(frame4Spacer1);


        rechMainLayout1->addWidget(frame_41);

        tableWidgetLabo = new QTableWidget(page_rech1);
        if (tableWidgetLabo->columnCount() < 6)
            tableWidgetLabo->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidgetLabo->setHorizontalHeaderItem(0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidgetLabo->setHorizontalHeaderItem(1, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidgetLabo->setHorizontalHeaderItem(2, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidgetLabo->setHorizontalHeaderItem(3, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidgetLabo->setHorizontalHeaderItem(4, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidgetLabo->setHorizontalHeaderItem(5, __qtablewidgetitem23);
        tableWidgetLabo->setObjectName("tableWidgetLabo");
        sizePolicy2.setHeightForWidth(tableWidgetLabo->sizePolicy().hasHeightForWidth());
        tableWidgetLabo->setSizePolicy(sizePolicy2);
        tableWidgetLabo->horizontalHeader()->setStretchLastSection(true);

        rechMainLayout1->addWidget(tableWidgetLabo);


        rechLayout1->addLayout(rechMainLayout1);

        stackedWidget1->addWidget(page_rech1);
        pagesupp1 = new QWidget();
        pagesupp1->setObjectName("pagesupp1");
        suppLayout1 = new QVBoxLayout(pagesupp1);
        suppLayout1->setObjectName("suppLayout1");
        suppTitle1 = new QLabel(pagesupp1);
        suppTitle1->setObjectName("suppTitle1");

        suppLayout1->addWidget(suppTitle1);

        suppFormFrame1 = new QFrame(pagesupp1);
        suppFormFrame1->setObjectName("suppFormFrame1");
        suppFormLayout1 = new QVBoxLayout(suppFormFrame1);
        suppFormLayout1->setObjectName("suppFormLayout1");
        suppWarning1 = new QLabel(suppFormFrame1);
        suppWarning1->setObjectName("suppWarning1");

        suppFormLayout1->addWidget(suppWarning1);

        suppIdLayout1 = new QHBoxLayout();
        suppIdLayout1->setObjectName("suppIdLayout1");
        label_421 = new QLabel(suppFormFrame1);
        label_421->setObjectName("label_421");

        suppIdLayout1->addWidget(label_421);

        lineEditIdLaboSuppression = new QLineEdit(suppFormFrame1);
        lineEditIdLaboSuppression->setObjectName("lineEditIdLaboSuppression");

        suppIdLayout1->addWidget(lineEditIdLaboSuppression);


        suppFormLayout1->addLayout(suppIdLayout1);

        suppSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        suppFormLayout1->addItem(suppSpacer1);

        suppActionLayout1 = new QHBoxLayout();
        suppActionLayout1->setObjectName("suppActionLayout1");
        suppActionSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        suppActionLayout1->addItem(suppActionSpacer1);

        btnSupprimerLabo = new QPushButton(suppFormFrame1);
        btnSupprimerLabo->setObjectName("btnSupprimerLabo");
        btnSupprimerLabo->setMinimumWidth(200);

        suppActionLayout1->addWidget(btnSupprimerLabo);


        suppFormLayout1->addLayout(suppActionLayout1);


        suppLayout1->addWidget(suppFormFrame1);

        stackedWidget1->addWidget(pagesupp1);
        pagemodif1 = new QWidget();
        pagemodif1->setObjectName("pagemodif1");
        modifLayout1 = new QVBoxLayout(pagemodif1);
        modifLayout1->setObjectName("modifLayout1");
        modifTitle1 = new QLabel(pagemodif1);
        modifTitle1->setObjectName("modifTitle1");

        modifLayout1->addWidget(modifTitle1);

        modifFormFrame1 = new QFrame(pagemodif1);
        modifFormFrame1->setObjectName("modifFormFrame1");
        modifFormLayout1 = new QFormLayout(modifFormFrame1);
        modifFormLayout1->setObjectName("modifFormLayout1");
        label_modif_id1 = new QLabel(modifFormFrame1);
        label_modif_id1->setObjectName("label_modif_id1");

        modifFormLayout1->setWidget(0, QFormLayout::LabelRole, label_modif_id1);

        lineEdit_modif_id1 = new QLineEdit(modifFormFrame1);
        lineEdit_modif_id1->setObjectName("lineEdit_modif_id1");

        modifFormLayout1->setWidget(0, QFormLayout::FieldRole, lineEdit_modif_id1);

        label_351 = new QLabel(modifFormFrame1);
        label_351->setObjectName("label_351");

        modifFormLayout1->setWidget(1, QFormLayout::LabelRole, label_351);

        lineEditNomLaboModif = new QLineEdit(modifFormFrame1);
        lineEditNomLaboModif->setObjectName("lineEditNomLaboModif");

        modifFormLayout1->setWidget(1, QFormLayout::FieldRole, lineEditNomLaboModif);

        label_361 = new QLabel(modifFormFrame1);
        label_361->setObjectName("label_361");

        modifFormLayout1->setWidget(2, QFormLayout::LabelRole, label_361);

        comboBox_modif_type = new QComboBox(modifFormFrame1);
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->addItem(QString());
        comboBox_modif_type->setObjectName("comboBox_modif_type");

        modifFormLayout1->setWidget(2, QFormLayout::FieldRole, comboBox_modif_type);

        label_371 = new QLabel(modifFormFrame1);
        label_371->setObjectName("label_371");

        modifFormLayout1->setWidget(3, QFormLayout::LabelRole, label_371);

        comboBox_modif_conf = new QComboBox(modifFormFrame1);
        comboBox_modif_conf->addItem(QString());
        comboBox_modif_conf->addItem(QString());
        comboBox_modif_conf->setObjectName("comboBox_modif_conf");

        modifFormLayout1->setWidget(3, QFormLayout::FieldRole, comboBox_modif_conf);

        label_381 = new QLabel(modifFormFrame1);
        label_381->setObjectName("label_381");

        modifFormLayout1->setWidget(4, QFormLayout::LabelRole, label_381);

        lineEditAdresseLaboModif = new QLineEdit(modifFormFrame1);
        lineEditAdresseLaboModif->setObjectName("lineEditAdresseLaboModif");

        modifFormLayout1->setWidget(4, QFormLayout::FieldRole, lineEditAdresseLaboModif);


        modifLayout1->addWidget(modifFormFrame1);

        modifSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        modifLayout1->addItem(modifSpacer1);

        modifActionLayout1 = new QHBoxLayout();
        modifActionLayout1->setObjectName("modifActionLayout1");
        modifActionSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        modifActionLayout1->addItem(modifActionSpacer1);

        btnModifierLabo = new QPushButton(pagemodif1);
        btnModifierLabo->setObjectName("btnModifierLabo");
        btnModifierLabo->setMinimumWidth(200);

        modifActionLayout1->addWidget(btnModifierLabo);


        modifLayout1->addLayout(modifActionLayout1);

        stackedWidget1->addWidget(pagemodif1);
        page_stat1 = new QWidget();
        page_stat1->setObjectName("page_stat1");
        statLayout1 = new QVBoxLayout(page_stat1);
        statLayout1->setObjectName("statLayout1");
        statTitle1 = new QLabel(page_stat1);
        statTitle1->setObjectName("statTitle1");

        statLayout1->addWidget(statTitle1);

        statsContentLayout1 = new QHBoxLayout();
        statsContentLayout1->setObjectName("statsContentLayout1");
        performanceGroup1 = new QGroupBox(page_stat1);
        performanceGroup1->setObjectName("performanceGroup1");
        vboxLayout5 = new QVBoxLayout(performanceGroup1);
        vboxLayout5->setObjectName("vboxLayout5");
        plainTextEdit1 = new QPlainTextEdit(performanceGroup1);
        plainTextEdit1->setObjectName("plainTextEdit1");
        plainTextEdit1->setReadOnly(true);

        vboxLayout5->addWidget(plainTextEdit1);


        statsContentLayout1->addWidget(performanceGroup1);

        vitesseGroup1 = new QGroupBox(page_stat1);
        vitesseGroup1->setObjectName("vitesseGroup1");
        vboxLayout6 = new QVBoxLayout(vitesseGroup1);
        vboxLayout6->setObjectName("vboxLayout6");
        plainTextEdit_21 = new QPlainTextEdit(vitesseGroup1);
        plainTextEdit_21->setObjectName("plainTextEdit_21");
        plainTextEdit_21->setReadOnly(true);

        vboxLayout6->addWidget(plainTextEdit_21);


        statsContentLayout1->addWidget(vitesseGroup1);


        statLayout1->addLayout(statsContentLayout1);

        exportLayout1 = new QHBoxLayout();
        exportLayout1->setObjectName("exportLayout1");
        exportSpacer1 = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        exportLayout1->addItem(exportSpacer1);

        btnExportStatsLaboPdf = new QPushButton(page_stat1);
        btnExportStatsLaboPdf->setObjectName("btnExportStatsLaboPdf");

        exportLayout1->addWidget(btnExportStatsLaboPdf);


        statLayout1->addLayout(exportLayout1);

        stackedWidget1->addWidget(page_stat1);
        pageGeo = new QWidget();
        pageGeo->setObjectName("pageGeo");
        geoLayout = new QVBoxLayout(pageGeo);
        geoLayout->setObjectName("geoLayout");
        geoPlaceholder = new QLabel(pageGeo);
        geoPlaceholder->setObjectName("geoPlaceholder");
        geoPlaceholder->setAlignment(Qt::AlignCenter);

        geoLayout->addWidget(geoPlaceholder);

        stackedWidget1->addWidget(pageGeo);
        pageAI = new QWidget();
        pageAI->setObjectName("pageAI");
        aiLayout = new QVBoxLayout(pageAI);
        aiLayout->setObjectName("aiLayout");
        aiPlaceholder = new QLabel(pageAI);
        aiPlaceholder->setObjectName("aiPlaceholder");
        aiPlaceholder->setAlignment(Qt::AlignCenter);

        aiLayout->addWidget(aiPlaceholder);

        stackedWidget1->addWidget(pageAI);

        mainLayout->addWidget(stackedWidget1);

        stackedMain->addWidget(LaboWidget);
        CommandeWidget = new QWidget();
        CommandeWidget->setObjectName("CommandeWidget");
        CommandeWidget->setMinimumSize(QSize(600, 400));
        verticalLayout_cmd = new QVBoxLayout(CommandeWidget);
        verticalLayout_cmd->setObjectName("verticalLayout_cmd");
        label_cmd = new QLabel(CommandeWidget);
        label_cmd->setObjectName("label_cmd");
        label_cmd->setAlignment(Qt::AlignCenter);

        verticalLayout_cmd->addWidget(label_cmd);

        tabWidget_cmd = new QTabWidget(CommandeWidget);
        tabWidget_cmd->setObjectName("tabWidget_cmd");
        tabAjouter_cmd = new QWidget();
        tabAjouter_cmd->setObjectName("tabAjouter_cmd");
        verticalLayout_ajouter_cmd = new QVBoxLayout(tabAjouter_cmd);
        verticalLayout_ajouter_cmd->setObjectName("verticalLayout_ajouter_cmd");
        grid_ajouter_cmd = new QGridLayout();
        grid_ajouter_cmd->setObjectName("grid_ajouter_cmd");
        labelNumCommande = new QLabel(tabAjouter_cmd);
        labelNumCommande->setObjectName("labelNumCommande");

        grid_ajouter_cmd->addWidget(labelNumCommande, 0, 0, 1, 1);

        lineNumCommande = new QLineEdit(tabAjouter_cmd);
        lineNumCommande->setObjectName("lineNumCommande");

        grid_ajouter_cmd->addWidget(lineNumCommande, 0, 1, 1, 1);

        labelClient = new QLabel(tabAjouter_cmd);
        labelClient->setObjectName("labelClient");

        grid_ajouter_cmd->addWidget(labelClient, 1, 0, 1, 1);

        lineClient = new QLineEdit(tabAjouter_cmd);
        lineClient->setObjectName("lineClient");

        grid_ajouter_cmd->addWidget(lineClient, 1, 1, 1, 1);

        labelProduit = new QLabel(tabAjouter_cmd);
        labelProduit->setObjectName("labelProduit");

        grid_ajouter_cmd->addWidget(labelProduit, 2, 0, 1, 1);

        comboProduit = new QComboBox(tabAjouter_cmd);
        comboProduit->setObjectName("comboProduit");

        grid_ajouter_cmd->addWidget(comboProduit, 2, 1, 1, 1);

        labelQuantite = new QLabel(tabAjouter_cmd);
        labelQuantite->setObjectName("labelQuantite");

        grid_ajouter_cmd->addWidget(labelQuantite, 3, 0, 1, 1);

        spinQuantite = new QSpinBox(tabAjouter_cmd);
        spinQuantite->setObjectName("spinQuantite");

        grid_ajouter_cmd->addWidget(spinQuantite, 3, 1, 1, 1);

        labelPrix = new QLabel(tabAjouter_cmd);
        labelPrix->setObjectName("labelPrix");

        grid_ajouter_cmd->addWidget(labelPrix, 4, 0, 1, 1);

        spinPrix = new QDoubleSpinBox(tabAjouter_cmd);
        spinPrix->setObjectName("spinPrix");

        grid_ajouter_cmd->addWidget(spinPrix, 4, 1, 1, 1);

        labelStatut = new QLabel(tabAjouter_cmd);
        labelStatut->setObjectName("labelStatut");

        grid_ajouter_cmd->addWidget(labelStatut, 5, 0, 1, 1);

        comboStatut = new QComboBox(tabAjouter_cmd);
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->setObjectName("comboStatut");

        grid_ajouter_cmd->addWidget(comboStatut, 5, 1, 1, 1);

        labelDate = new QLabel(tabAjouter_cmd);
        labelDate->setObjectName("labelDate");

        grid_ajouter_cmd->addWidget(labelDate, 6, 0, 1, 1);

        lineDate = new QLineEdit(tabAjouter_cmd);
        lineDate->setObjectName("lineDate");

        grid_ajouter_cmd->addWidget(lineDate, 6, 1, 1, 1);


        verticalLayout_ajouter_cmd->addLayout(grid_ajouter_cmd);

        hButtonsAjouter_cmd = new QHBoxLayout();
        hButtonsAjouter_cmd->setObjectName("hButtonsAjouter_cmd");
        horizontalSpacer_ajouter = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hButtonsAjouter_cmd->addItem(horizontalSpacer_ajouter);

        btnAjouter_cmd = new QPushButton(tabAjouter_cmd);
        btnAjouter_cmd->setObjectName("btnAjouter_cmd");

        hButtonsAjouter_cmd->addWidget(btnAjouter_cmd);

        btnResetAjouter = new QPushButton(tabAjouter_cmd);
        btnResetAjouter->setObjectName("btnResetAjouter");

        hButtonsAjouter_cmd->addWidget(btnResetAjouter);


        verticalLayout_ajouter_cmd->addLayout(hButtonsAjouter_cmd);

        tabWidget_cmd->addTab(tabAjouter_cmd, QString());
        tabListe_cmd = new QWidget();
        tabListe_cmd->setObjectName("tabListe_cmd");
        hLayout_liste_cmd = new QHBoxLayout(tabListe_cmd);
        hLayout_liste_cmd->setObjectName("hLayout_liste_cmd");
        sidebarListe_cmd = new QFrame(tabListe_cmd);
        sidebarListe_cmd->setObjectName("sidebarListe_cmd");
        sidebarListe_cmd->setMinimumWidth(150);
        vLayoutSidebar = new QVBoxLayout(sidebarListe_cmd);
        vLayoutSidebar->setObjectName("vLayoutSidebar");
        labelFiltres = new QLabel(sidebarListe_cmd);
        labelFiltres->setObjectName("labelFiltres");

        vLayoutSidebar->addWidget(labelFiltres);

        checkFiltreTous = new QCheckBox(sidebarListe_cmd);
        checkFiltreTous->setObjectName("checkFiltreTous");
        checkFiltreTous->setChecked(true);

        vLayoutSidebar->addWidget(checkFiltreTous);

        checkFiltreAttente = new QCheckBox(sidebarListe_cmd);
        checkFiltreAttente->setObjectName("checkFiltreAttente");

        vLayoutSidebar->addWidget(checkFiltreAttente);

        checkFiltreConfirmee = new QCheckBox(sidebarListe_cmd);
        checkFiltreConfirmee->setObjectName("checkFiltreConfirmee");

        vLayoutSidebar->addWidget(checkFiltreConfirmee);

        checkFiltreExpedie = new QCheckBox(sidebarListe_cmd);
        checkFiltreExpedie->setObjectName("checkFiltreExpedie");

        vLayoutSidebar->addWidget(checkFiltreExpedie);

        checkFiltreLivree = new QCheckBox(sidebarListe_cmd);
        checkFiltreLivree->setObjectName("checkFiltreLivree");

        vLayoutSidebar->addWidget(checkFiltreLivree);

        verticalSpacer_sidebar = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayoutSidebar->addItem(verticalSpacer_sidebar);


        hLayout_liste_cmd->addWidget(sidebarListe_cmd);

        mainListe_cmd = new QFrame(tabListe_cmd);
        mainListe_cmd->setObjectName("mainListe_cmd");
        vLayoutMain = new QVBoxLayout(mainListe_cmd);
        vLayoutMain->setObjectName("vLayoutMain");
        tableCommandes = new QTableWidget(mainListe_cmd);
        if (tableCommandes->columnCount() < 6)
            tableCommandes->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(1, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(2, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(3, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(4, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(5, __qtablewidgetitem29);
        tableCommandes->setObjectName("tableCommandes");
        tableCommandes->setAlternatingRowColors(true);

        vLayoutMain->addWidget(tableCommandes);


        hLayout_liste_cmd->addWidget(mainListe_cmd);

        tabWidget_cmd->addTab(tabListe_cmd, QString());
        tabSupprimer_cmd = new QWidget();
        tabSupprimer_cmd->setObjectName("tabSupprimer_cmd");
        vertical_supprimer_cmd = new QVBoxLayout(tabSupprimer_cmd);
        vertical_supprimer_cmd->setObjectName("vertical_supprimer_cmd");
        formSuppr_cmd = new QFormLayout();
        formSuppr_cmd->setObjectName("formSuppr_cmd");
        labelIdSuppr = new QLabel(tabSupprimer_cmd);
        labelIdSuppr->setObjectName("labelIdSuppr");

        formSuppr_cmd->setWidget(0, QFormLayout::LabelRole, labelIdSuppr);

        lineIdSuppr = new QLineEdit(tabSupprimer_cmd);
        lineIdSuppr->setObjectName("lineIdSuppr");

        formSuppr_cmd->setWidget(0, QFormLayout::FieldRole, lineIdSuppr);


        vertical_supprimer_cmd->addLayout(formSuppr_cmd);

        btnSupprimerConfirm_cmd = new QPushButton(tabSupprimer_cmd);
        btnSupprimerConfirm_cmd->setObjectName("btnSupprimerConfirm_cmd");

        vertical_supprimer_cmd->addWidget(btnSupprimerConfirm_cmd);

        tabWidget_cmd->addTab(tabSupprimer_cmd, QString());
        tabModifier_cmd = new QWidget();
        tabModifier_cmd->setObjectName("tabModifier_cmd");
        vertical_modifier_cmd = new QVBoxLayout(tabModifier_cmd);
        vertical_modifier_cmd->setObjectName("vertical_modifier_cmd");
        formModifier_cmd = new QFormLayout();
        formModifier_cmd->setObjectName("formModifier_cmd");
        labelIdMod = new QLabel(tabModifier_cmd);
        labelIdMod->setObjectName("labelIdMod");

        formModifier_cmd->setWidget(0, QFormLayout::LabelRole, labelIdMod);

        lineIdMod = new QLineEdit(tabModifier_cmd);
        lineIdMod->setObjectName("lineIdMod");

        formModifier_cmd->setWidget(0, QFormLayout::FieldRole, lineIdMod);


        vertical_modifier_cmd->addLayout(formModifier_cmd);

        groupBox_prefill_cmd = new QGroupBox(tabModifier_cmd);
        groupBox_prefill_cmd->setObjectName("groupBox_prefill_cmd");
        gridPrefill = new QGridLayout(groupBox_prefill_cmd);
        gridPrefill->setObjectName("gridPrefill");
        labelStatutModif = new QLabel(groupBox_prefill_cmd);
        labelStatutModif->setObjectName("labelStatutModif");

        gridPrefill->addWidget(labelStatutModif, 0, 0, 1, 1);

        comboStatutModif = new QComboBox(groupBox_prefill_cmd);
        comboStatutModif->addItem(QString());
        comboStatutModif->addItem(QString());
        comboStatutModif->addItem(QString());
        comboStatutModif->addItem(QString());
        comboStatutModif->setObjectName("comboStatutModif");

        gridPrefill->addWidget(comboStatutModif, 0, 1, 1, 1);

        labelQuantiteModif = new QLabel(groupBox_prefill_cmd);
        labelQuantiteModif->setObjectName("labelQuantiteModif");

        gridPrefill->addWidget(labelQuantiteModif, 1, 0, 1, 1);

        spinQuantiteModif = new QSpinBox(groupBox_prefill_cmd);
        spinQuantiteModif->setObjectName("spinQuantiteModif");

        gridPrefill->addWidget(spinQuantiteModif, 1, 1, 1, 1);


        vertical_modifier_cmd->addWidget(groupBox_prefill_cmd);

        btnModifierConfirm_cmd = new QPushButton(tabModifier_cmd);
        btnModifierConfirm_cmd->setObjectName("btnModifierConfirm_cmd");

        vertical_modifier_cmd->addWidget(btnModifierConfirm_cmd);

        tabWidget_cmd->addTab(tabModifier_cmd, QString());
        tabRechercheTri = new QWidget();
        tabRechercheTri->setObjectName("tabRechercheTri");
        vertical_recherche_tri = new QVBoxLayout(tabRechercheTri);
        vertical_recherche_tri->setObjectName("vertical_recherche_tri");
        groupRecherche = new QGroupBox(tabRechercheTri);
        groupRecherche->setObjectName("groupRecherche");
        gridRecherche = new QGridLayout(groupRecherche);
        gridRecherche->setObjectName("gridRecherche");
        labelSearchDate = new QLabel(groupRecherche);
        labelSearchDate->setObjectName("labelSearchDate");

        gridRecherche->addWidget(labelSearchDate, 0, 0, 1, 1);

        dateSearchDebut = new QDateEdit(groupRecherche);
        dateSearchDebut->setObjectName("dateSearchDebut");
        dateSearchDebut->setCalendarPopup(true);

        gridRecherche->addWidget(dateSearchDebut, 0, 1, 1, 1);

        labelSearchDateTo = new QLabel(groupRecherche);
        labelSearchDateTo->setObjectName("labelSearchDateTo");

        gridRecherche->addWidget(labelSearchDateTo, 0, 2, 1, 1);

        dateSearchFin = new QDateEdit(groupRecherche);
        dateSearchFin->setObjectName("dateSearchFin");
        dateSearchFin->setCalendarPopup(true);

        gridRecherche->addWidget(dateSearchFin, 0, 3, 1, 1);

        labelSearchFournisseur = new QLabel(groupRecherche);
        labelSearchFournisseur->setObjectName("labelSearchFournisseur");

        gridRecherche->addWidget(labelSearchFournisseur, 1, 0, 1, 1);

        lineSearchFournisseur = new QLineEdit(groupRecherche);
        lineSearchFournisseur->setObjectName("lineSearchFournisseur");

        gridRecherche->addWidget(lineSearchFournisseur, 1, 1, 1, 3);

        labelSearchClient = new QLabel(groupRecherche);
        labelSearchClient->setObjectName("labelSearchClient");

        gridRecherche->addWidget(labelSearchClient, 2, 0, 1, 1);

        lineSearchClient = new QLineEdit(groupRecherche);
        lineSearchClient->setObjectName("lineSearchClient");

        gridRecherche->addWidget(lineSearchClient, 2, 1, 1, 3);


        vertical_recherche_tri->addWidget(groupRecherche);

        groupTri = new QGroupBox(tabRechercheTri);
        groupTri->setObjectName("groupTri");
        gridTri = new QGridLayout(groupTri);
        gridTri->setObjectName("gridTri");
        labelTriPar = new QLabel(groupTri);
        labelTriPar->setObjectName("labelTriPar");

        gridTri->addWidget(labelTriPar, 0, 0, 1, 1);

        comboTriPar = new QComboBox(groupTri);
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->setObjectName("comboTriPar");

        gridTri->addWidget(comboTriPar, 0, 1, 1, 1);

        horizontalSpacer_tri = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridTri->addItem(horizontalSpacer_tri, 0, 2, 1, 1);


        vertical_recherche_tri->addWidget(groupTri);

        hLayoutSearchButtons = new QHBoxLayout();
        hLayoutSearchButtons->setObjectName("hLayoutSearchButtons");
        horizontalSpacer_search = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutSearchButtons->addItem(horizontalSpacer_search);

        btnAppliquerRecherche = new QPushButton(tabRechercheTri);
        btnAppliquerRecherche->setObjectName("btnAppliquerRecherche");

        hLayoutSearchButtons->addWidget(btnAppliquerRecherche);

        btnReinitialiserRecherche = new QPushButton(tabRechercheTri);
        btnReinitialiserRecherche->setObjectName("btnReinitialiserRecherche");

        hLayoutSearchButtons->addWidget(btnReinitialiserRecherche);


        vertical_recherche_tri->addLayout(hLayoutSearchButtons);

        tableResultatsRecherche = new QTableWidget(tabRechercheTri);
        if (tableResultatsRecherche->columnCount() < 6)
            tableResultatsRecherche->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(0, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(1, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(2, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(3, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(4, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(5, __qtablewidgetitem35);
        tableResultatsRecherche->setObjectName("tableResultatsRecherche");
        tableResultatsRecherche->setAlternatingRowColors(true);

        vertical_recherche_tri->addWidget(tableResultatsRecherche);

        tabWidget_cmd->addTab(tabRechercheTri, QString());
        tabStatistiques_cmd = new QWidget();
        tabStatistiques_cmd->setObjectName("tabStatistiques_cmd");
        vertical_statistiques_cmd = new QVBoxLayout(tabStatistiques_cmd);
        vertical_statistiques_cmd->setObjectName("vertical_statistiques_cmd");
        groupCommandes = new QGroupBox(tabStatistiques_cmd);
        groupCommandes->setObjectName("groupCommandes");
        gridStatCommandes = new QGridLayout(groupCommandes);
        gridStatCommandes->setObjectName("gridStatCommandes");
        labelTotalCmd = new QLabel(groupCommandes);
        labelTotalCmd->setObjectName("labelTotalCmd");

        gridStatCommandes->addWidget(labelTotalCmd, 0, 0, 1, 1);

        lineTotalCmd = new QLineEdit(groupCommandes);
        lineTotalCmd->setObjectName("lineTotalCmd");
        lineTotalCmd->setReadOnly(true);

        gridStatCommandes->addWidget(lineTotalCmd, 0, 1, 1, 1);

        labelEnAttenteCmd = new QLabel(groupCommandes);
        labelEnAttenteCmd->setObjectName("labelEnAttenteCmd");

        gridStatCommandes->addWidget(labelEnAttenteCmd, 1, 0, 1, 1);

        lineEnAttenteCmd = new QLineEdit(groupCommandes);
        lineEnAttenteCmd->setObjectName("lineEnAttenteCmd");
        lineEnAttenteCmd->setReadOnly(true);

        gridStatCommandes->addWidget(lineEnAttenteCmd, 1, 1, 1, 1);


        vertical_statistiques_cmd->addWidget(groupCommandes);

        groupRevenue = new QGroupBox(tabStatistiques_cmd);
        groupRevenue->setObjectName("groupRevenue");
        gridStatRevenue = new QGridLayout(groupRevenue);
        gridStatRevenue->setObjectName("gridStatRevenue");
        labelRevenuTotal = new QLabel(groupRevenue);
        labelRevenuTotal->setObjectName("labelRevenuTotal");

        gridStatRevenue->addWidget(labelRevenuTotal, 0, 0, 1, 1);

        lineRevenuTotal = new QLineEdit(groupRevenue);
        lineRevenuTotal->setObjectName("lineRevenuTotal");
        lineRevenuTotal->setReadOnly(true);

        gridStatRevenue->addWidget(lineRevenuTotal, 0, 1, 1, 1);

        labelMoyenneCmd = new QLabel(groupRevenue);
        labelMoyenneCmd->setObjectName("labelMoyenneCmd");

        gridStatRevenue->addWidget(labelMoyenneCmd, 1, 0, 1, 1);

        lineMoyenneCmd = new QLineEdit(groupRevenue);
        lineMoyenneCmd->setObjectName("lineMoyenneCmd");
        lineMoyenneCmd->setReadOnly(true);

        gridStatRevenue->addWidget(lineMoyenneCmd, 1, 1, 1, 1);


        vertical_statistiques_cmd->addWidget(groupRevenue);

        groupPrixParMois = new QGroupBox(tabStatistiques_cmd);
        groupPrixParMois->setObjectName("groupPrixParMois");
        vLayoutPrixMois = new QVBoxLayout(groupPrixParMois);
        vLayoutPrixMois->setObjectName("vLayoutPrixMois");
        tablePrixParMois = new QTableWidget(groupPrixParMois);
        if (tablePrixParMois->columnCount() < 3)
            tablePrixParMois->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tablePrixParMois->setHorizontalHeaderItem(0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tablePrixParMois->setHorizontalHeaderItem(1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tablePrixParMois->setHorizontalHeaderItem(2, __qtablewidgetitem38);
        tablePrixParMois->setObjectName("tablePrixParMois");
        tablePrixParMois->setAlternatingRowColors(true);

        vLayoutPrixMois->addWidget(tablePrixParMois);


        vertical_statistiques_cmd->addWidget(groupPrixParMois);

        groupProduitsMostCommandes = new QGroupBox(tabStatistiques_cmd);
        groupProduitsMostCommandes->setObjectName("groupProduitsMostCommandes");
        vLayoutProduitsMost = new QVBoxLayout(groupProduitsMostCommandes);
        vLayoutProduitsMost->setObjectName("vLayoutProduitsMost");
        tableProduitsMostCommandes = new QTableWidget(groupProduitsMostCommandes);
        if (tableProduitsMostCommandes->columnCount() < 4)
            tableProduitsMostCommandes->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(3, __qtablewidgetitem42);
        tableProduitsMostCommandes->setObjectName("tableProduitsMostCommandes");
        tableProduitsMostCommandes->setAlternatingRowColors(true);

        vLayoutProduitsMost->addWidget(tableProduitsMostCommandes);


        vertical_statistiques_cmd->addWidget(groupProduitsMostCommandes);

        verticalSpacer_stats_cmd = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_statistiques_cmd->addItem(verticalSpacer_stats_cmd);

        tabWidget_cmd->addTab(tabStatistiques_cmd, QString());
        tabCalendrier = new QWidget();
        tabCalendrier->setObjectName("tabCalendrier");
        vertical_calendrier = new QVBoxLayout(tabCalendrier);
        vertical_calendrier->setObjectName("vertical_calendrier");
        groupCalendrier = new QGroupBox(tabCalendrier);
        groupCalendrier->setObjectName("groupCalendrier");
        vLayoutCalendrier = new QVBoxLayout(groupCalendrier);
        vLayoutCalendrier->setObjectName("vLayoutCalendrier");
        hLayoutCalendrierControls = new QHBoxLayout();
        hLayoutCalendrierControls->setObjectName("hLayoutCalendrierControls");
        labelMoisAnnee = new QLabel(groupCalendrier);
        labelMoisAnnee->setObjectName("labelMoisAnnee");

        hLayoutCalendrierControls->addWidget(labelMoisAnnee);

        comboMoisCalendrier = new QComboBox(groupCalendrier);
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->addItem(QString());
        comboMoisCalendrier->setObjectName("comboMoisCalendrier");

        hLayoutCalendrierControls->addWidget(comboMoisCalendrier);

        spinAnneeCalendrier = new QSpinBox(groupCalendrier);
        spinAnneeCalendrier->setObjectName("spinAnneeCalendrier");
        spinAnneeCalendrier->setMinimum(2020);
        spinAnneeCalendrier->setMaximum(2030);
        spinAnneeCalendrier->setValue(2026);

        hLayoutCalendrierControls->addWidget(spinAnneeCalendrier);

        horizontalSpacer_calendrier = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutCalendrierControls->addItem(horizontalSpacer_calendrier);

        btnAfficherCalendrier = new QPushButton(groupCalendrier);
        btnAfficherCalendrier->setObjectName("btnAfficherCalendrier");

        hLayoutCalendrierControls->addWidget(btnAfficherCalendrier);


        vLayoutCalendrier->addLayout(hLayoutCalendrierControls);

        calendarCommandes = new QCalendarWidget(groupCalendrier);
        calendarCommandes->setObjectName("calendarCommandes");
        calendarCommandes->setMinimumHeight(300);

        vLayoutCalendrier->addWidget(calendarCommandes);


        vertical_calendrier->addWidget(groupCalendrier);

        groupAlertes = new QGroupBox(tabCalendrier);
        groupAlertes->setObjectName("groupAlertes");
        vLayoutAlertes = new QVBoxLayout(groupAlertes);
        vLayoutAlertes->setObjectName("vLayoutAlertes");
        labelAlertesLegend = new QLabel(groupAlertes);
        labelAlertesLegend->setObjectName("labelAlertesLegend");
        labelAlertesLegend->setWordWrap(true);

        vLayoutAlertes->addWidget(labelAlertesLegend);

        listAlertes = new QListWidget(groupAlertes);
        listAlertes->setObjectName("listAlertes");
        listAlertes->setMinimumHeight(150);

        vLayoutAlertes->addWidget(listAlertes);


        vertical_calendrier->addWidget(groupAlertes);

        verticalSpacer_calendrier = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_calendrier->addItem(verticalSpacer_calendrier);

        tabWidget_cmd->addTab(tabCalendrier, QString());
        tabNotifications = new QWidget();
        tabNotifications->setObjectName("tabNotifications");
        vertical_notifications = new QVBoxLayout(tabNotifications);
        vertical_notifications->setObjectName("vertical_notifications");
        groupEmailConfig = new QGroupBox(tabNotifications);
        groupEmailConfig->setObjectName("groupEmailConfig");
        gridEmailConfig = new QGridLayout(groupEmailConfig);
        gridEmailConfig->setObjectName("gridEmailConfig");
        labelEmailDestinataire = new QLabel(groupEmailConfig);
        labelEmailDestinataire->setObjectName("labelEmailDestinataire");

        gridEmailConfig->addWidget(labelEmailDestinataire, 0, 0, 1, 1);

        lineEmailDestinataire = new QLineEdit(groupEmailConfig);
        lineEmailDestinataire->setObjectName("lineEmailDestinataire");

        gridEmailConfig->addWidget(lineEmailDestinataire, 0, 1, 1, 1);

        labelEmailCommande = new QLabel(groupEmailConfig);
        labelEmailCommande->setObjectName("labelEmailCommande");

        gridEmailConfig->addWidget(labelEmailCommande, 1, 0, 1, 1);

        comboEmailNotification = new QComboBox(groupEmailConfig);
        comboEmailNotification->addItem(QString());
        comboEmailNotification->addItem(QString());
        comboEmailNotification->addItem(QString());
        comboEmailNotification->addItem(QString());
        comboEmailNotification->setObjectName("comboEmailNotification");

        gridEmailConfig->addWidget(comboEmailNotification, 1, 1, 1, 1);

        checkEmailAutomatic = new QCheckBox(groupEmailConfig);
        checkEmailAutomatic->setObjectName("checkEmailAutomatic");
        checkEmailAutomatic->setChecked(false);

        gridEmailConfig->addWidget(checkEmailAutomatic, 2, 0, 1, 1);


        vertical_notifications->addWidget(groupEmailConfig);

        groupEmailManuel = new QGroupBox(tabNotifications);
        groupEmailManuel->setObjectName("groupEmailManuel");
        gridEmailManuel = new QGridLayout(groupEmailManuel);
        gridEmailManuel->setObjectName("gridEmailManuel");
        labelNumCommandeEmail = new QLabel(groupEmailManuel);
        labelNumCommandeEmail->setObjectName("labelNumCommandeEmail");

        gridEmailManuel->addWidget(labelNumCommandeEmail, 0, 0, 1, 1);

        lineNumCommandeEmail = new QLineEdit(groupEmailManuel);
        lineNumCommandeEmail->setObjectName("lineNumCommandeEmail");

        gridEmailManuel->addWidget(lineNumCommandeEmail, 0, 1, 1, 1);

        labelMessageEmail = new QLabel(groupEmailManuel);
        labelMessageEmail->setObjectName("labelMessageEmail");

        gridEmailManuel->addWidget(labelMessageEmail, 1, 0, 1, 1);

        textMessageEmail = new QTextEdit(groupEmailManuel);
        textMessageEmail->setObjectName("textMessageEmail");

        gridEmailManuel->addWidget(textMessageEmail, 1, 1, 1, 1);


        vertical_notifications->addWidget(groupEmailManuel);

        hLayoutEmailButtons = new QHBoxLayout();
        hLayoutEmailButtons->setObjectName("hLayoutEmailButtons");
        horizontalSpacer_email = new QSpacerItem(0, 0, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hLayoutEmailButtons->addItem(horizontalSpacer_email);

        btnEnvoyerEmail = new QPushButton(tabNotifications);
        btnEnvoyerEmail->setObjectName("btnEnvoyerEmail");

        hLayoutEmailButtons->addWidget(btnEnvoyerEmail);


        vertical_notifications->addLayout(hLayoutEmailButtons);

        groupHistoriqueEmails = new QGroupBox(tabNotifications);
        groupHistoriqueEmails->setObjectName("groupHistoriqueEmails");
        vLayoutHistoriqueEmails = new QVBoxLayout(groupHistoriqueEmails);
        vLayoutHistoriqueEmails->setObjectName("vLayoutHistoriqueEmails");
        tableHistoriqueEmails = new QTableWidget(groupHistoriqueEmails);
        if (tableHistoriqueEmails->columnCount() < 4)
            tableHistoriqueEmails->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(0, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(1, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(2, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(3, __qtablewidgetitem46);
        tableHistoriqueEmails->setObjectName("tableHistoriqueEmails");
        tableHistoriqueEmails->setAlternatingRowColors(true);

        vLayoutHistoriqueEmails->addWidget(tableHistoriqueEmails);


        vertical_notifications->addWidget(groupHistoriqueEmails);

        verticalSpacer_notifications = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_notifications->addItem(verticalSpacer_notifications);

        tabWidget_cmd->addTab(tabNotifications, QString());
        tabExportPdf_cmd = new QWidget();
        tabExportPdf_cmd->setObjectName("tabExportPdf_cmd");
        vertical_export_pdf_cmd = new QVBoxLayout(tabExportPdf_cmd);
        vertical_export_pdf_cmd->setObjectName("vertical_export_pdf_cmd");
        groupExportOptions_cmd = new QGroupBox(tabExportPdf_cmd);
        groupExportOptions_cmd->setObjectName("groupExportOptions_cmd");
        vLayoutExportOptions = new QVBoxLayout(groupExportOptions_cmd);
        vLayoutExportOptions->setObjectName("vLayoutExportOptions");
        checkExportTous = new QCheckBox(groupExportOptions_cmd);
        checkExportTous->setObjectName("checkExportTous");
        checkExportTous->setChecked(true);

        vLayoutExportOptions->addWidget(checkExportTous);

        checkExportFiltre = new QCheckBox(groupExportOptions_cmd);
        checkExportFiltre->setObjectName("checkExportFiltre");

        vLayoutExportOptions->addWidget(checkExportFiltre);


        vertical_export_pdf_cmd->addWidget(groupExportOptions_cmd);

        groupIdExport_cmd = new QGroupBox(tabExportPdf_cmd);
        groupIdExport_cmd->setObjectName("groupIdExport_cmd");
        hLayoutIdExport = new QHBoxLayout(groupIdExport_cmd);
        hLayoutIdExport->setObjectName("hLayoutIdExport");
        btnExportListeComplete_cmd = new QPushButton(groupIdExport_cmd);
        btnExportListeComplete_cmd->setObjectName("btnExportListeComplete_cmd");

        hLayoutIdExport->addWidget(btnExportListeComplete_cmd);

        btnExportRapport = new QPushButton(groupIdExport_cmd);
        btnExportRapport->setObjectName("btnExportRapport");

        hLayoutIdExport->addWidget(btnExportRapport);

        btnExportFiche = new QPushButton(groupIdExport_cmd);
        btnExportFiche->setObjectName("btnExportFiche");

        hLayoutIdExport->addWidget(btnExportFiche);


        vertical_export_pdf_cmd->addWidget(groupIdExport_cmd);

        groupMessagesExport_cmd = new QGroupBox(tabExportPdf_cmd);
        groupMessagesExport_cmd->setObjectName("groupMessagesExport_cmd");
        vLayoutMessagesExport = new QVBoxLayout(groupMessagesExport_cmd);
        vLayoutMessagesExport->setObjectName("vLayoutMessagesExport");
        lineExportMessages = new QLineEdit(groupMessagesExport_cmd);
        lineExportMessages->setObjectName("lineExportMessages");
        lineExportMessages->setReadOnly(true);

        vLayoutMessagesExport->addWidget(lineExportMessages);


        vertical_export_pdf_cmd->addWidget(groupMessagesExport_cmd);

        verticalSpacer_export_cmd = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_export_pdf_cmd->addItem(verticalSpacer_export_cmd);

        tabWidget_cmd->addTab(tabExportPdf_cmd, QString());

        verticalLayout_cmd->addWidget(tabWidget_cmd);

        stackedMain->addWidget(CommandeWidget);
        MachineWidget = new QWidget();
        MachineWidget->setObjectName("MachineWidget");
        MachineWidget->setGeometry(QRect(0, 0, 1200, 800));
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
        vboxLayout7 = new QVBoxLayout(groupBoxSearch);
        vboxLayout7->setObjectName("vboxLayout7");
        hboxLayout3 = new QHBoxLayout();
        hboxLayout3->setObjectName("hboxLayout3");
        label10 = new QLabel(groupBoxSearch);
        label10->setObjectName("label10");

        hboxLayout3->addWidget(label10);

        lineEditSearch = new QLineEdit(groupBoxSearch);
        lineEditSearch->setObjectName("lineEditSearch");

        hboxLayout3->addWidget(lineEditSearch);


        vboxLayout7->addLayout(hboxLayout3);

        hboxLayout4 = new QHBoxLayout();
        hboxLayout4->setObjectName("hboxLayout4");
        label11 = new QLabel(groupBoxSearch);
        label11->setObjectName("label11");

        hboxLayout4->addWidget(label11);

        comboCategory = new QComboBox(groupBoxSearch);
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->addItem(QString());
        comboCategory->setObjectName("comboCategory");

        hboxLayout4->addWidget(comboCategory);


        vboxLayout7->addLayout(hboxLayout4);

        hboxLayout5 = new QHBoxLayout();
        hboxLayout5->setObjectName("hboxLayout5");
        label12 = new QLabel(groupBoxSearch);
        label12->setObjectName("label12");

        hboxLayout5->addWidget(label12);

        comboState = new QComboBox(groupBoxSearch);
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->addItem(QString());
        comboState->setObjectName("comboState");

        hboxLayout5->addWidget(comboState);


        vboxLayout7->addLayout(hboxLayout5);

        hboxLayout6 = new QHBoxLayout();
        hboxLayout6->setObjectName("hboxLayout6");
        label13 = new QLabel(groupBoxSearch);
        label13->setObjectName("label13");

        hboxLayout6->addWidget(label13);

        lineEditLocation = new QLineEdit(groupBoxSearch);
        lineEditLocation->setObjectName("lineEditLocation");

        hboxLayout6->addWidget(lineEditLocation);


        vboxLayout7->addLayout(hboxLayout6);

        btnApplyFilter = new QPushButton(groupBoxSearch);
        btnApplyFilter->setObjectName("btnApplyFilter");
        btnApplyFilter->setMinimumHeight(35);

        vboxLayout7->addWidget(btnApplyFilter);


        leftLayout->addWidget(groupBoxSearch);

        groupBoxSort = new QGroupBox(leftPanel);
        groupBoxSort->setObjectName("groupBoxSort");
        vboxLayout8 = new QVBoxLayout(groupBoxSort);
        vboxLayout8->setObjectName("vboxLayout8");
        hboxLayout7 = new QHBoxLayout();
        hboxLayout7->setObjectName("hboxLayout7");
        label14 = new QLabel(groupBoxSort);
        label14->setObjectName("label14");

        hboxLayout7->addWidget(label14);

        comboSortBy = new QComboBox(groupBoxSort);
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->addItem(QString());
        comboSortBy->setObjectName("comboSortBy");

        hboxLayout7->addWidget(comboSortBy);


        vboxLayout8->addLayout(hboxLayout7);

        hboxLayout8 = new QHBoxLayout();
        hboxLayout8->setObjectName("hboxLayout8");
        radioCroissant = new QRadioButton(groupBoxSort);
        radioCroissant->setObjectName("radioCroissant");
        radioCroissant->setChecked(true);

        hboxLayout8->addWidget(radioCroissant);

        radioDecroissant = new QRadioButton(groupBoxSort);
        radioDecroissant->setObjectName("radioDecroissant");

        hboxLayout8->addWidget(radioDecroissant);


        vboxLayout8->addLayout(hboxLayout8);


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
        centerLayout_mach = new QVBoxLayout(centerPanel);
        centerLayout_mach->setObjectName("centerLayout_mach");
        centerLayout_mach->setContentsMargins(10, 10, 10, 10);
        tabWidget_mach = new QTabWidget(centerPanel);
        tabWidget_mach->setObjectName("tabWidget_mach");
        tabAjouter_mach = new QWidget();
        tabAjouter_mach->setObjectName("tabAjouter_mach");
        vboxLayout9 = new QVBoxLayout(tabAjouter_mach);
        vboxLayout9->setObjectName("vboxLayout9");
        labelAdd = new QLabel(tabAjouter_mach);
        labelAdd->setObjectName("labelAdd");
        labelAdd->setAlignment(Qt::AlignCenter);

        vboxLayout9->addWidget(labelAdd);

        frameAdd = new QFrame(tabAjouter_mach);
        frameAdd->setObjectName("frameAdd");
        frameAdd->setFrameShape(QFrame::StyledPanel);
        frameAdd->setFrameShadow(QFrame::Raised);
        formLayoutAdd = new QFormLayout(frameAdd);
        formLayoutAdd->setObjectName("formLayoutAdd");
        formLayoutAdd->setHorizontalSpacing(20);
        formLayoutAdd->setVerticalSpacing(12);
        label15 = new QLabel(frameAdd);
        label15->setObjectName("label15");

        formLayoutAdd->setWidget(0, QFormLayout::LabelRole, label15);

        editAddId = new QLineEdit(frameAdd);
        editAddId->setObjectName("editAddId");

        formLayoutAdd->setWidget(0, QFormLayout::FieldRole, editAddId);

        label16 = new QLabel(frameAdd);
        label16->setObjectName("label16");

        formLayoutAdd->setWidget(1, QFormLayout::LabelRole, label16);

        editAddNom = new QLineEdit(frameAdd);
        editAddNom->setObjectName("editAddNom");

        formLayoutAdd->setWidget(1, QFormLayout::FieldRole, editAddNom);

        label17 = new QLabel(frameAdd);
        label17->setObjectName("label17");

        formLayoutAdd->setWidget(2, QFormLayout::LabelRole, label17);

        comboAddCategorie = new QComboBox(frameAdd);
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->addItem(QString());
        comboAddCategorie->setObjectName("comboAddCategorie");

        formLayoutAdd->setWidget(2, QFormLayout::FieldRole, comboAddCategorie);

        label18 = new QLabel(frameAdd);
        label18->setObjectName("label18");

        formLayoutAdd->setWidget(3, QFormLayout::LabelRole, label18);

        editAddReference = new QLineEdit(frameAdd);
        editAddReference->setObjectName("editAddReference");

        formLayoutAdd->setWidget(3, QFormLayout::FieldRole, editAddReference);

        label19 = new QLabel(frameAdd);
        label19->setObjectName("label19");

        formLayoutAdd->setWidget(4, QFormLayout::LabelRole, label19);

        dateAddAchat = new QDateEdit(frameAdd);
        dateAddAchat->setObjectName("dateAddAchat");
        dateAddAchat->setCalendarPopup(true);

        formLayoutAdd->setWidget(4, QFormLayout::FieldRole, dateAddAchat);

        label20 = new QLabel(frameAdd);
        label20->setObjectName("label20");

        formLayoutAdd->setWidget(5, QFormLayout::LabelRole, label20);

        comboAddEtat = new QComboBox(frameAdd);
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->addItem(QString());
        comboAddEtat->setObjectName("comboAddEtat");

        formLayoutAdd->setWidget(5, QFormLayout::FieldRole, comboAddEtat);

        label21 = new QLabel(frameAdd);
        label21->setObjectName("label21");

        formLayoutAdd->setWidget(6, QFormLayout::LabelRole, label21);

        editAddLocalisation = new QLineEdit(frameAdd);
        editAddLocalisation->setObjectName("editAddLocalisation");

        formLayoutAdd->setWidget(6, QFormLayout::FieldRole, editAddLocalisation);


        vboxLayout9->addWidget(frameAdd);

        spacerItem6 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout9->addItem(spacerItem6);

        hboxLayout9 = new QHBoxLayout();
        hboxLayout9->setObjectName("hboxLayout9");
        spacerItem7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout9->addItem(spacerItem7);

        btnConfirmerAjouter_mach = new QPushButton(tabAjouter_mach);
        btnConfirmerAjouter_mach->setObjectName("btnConfirmerAjouter_mach");
        btnConfirmerAjouter_mach->setMinimumHeight(45);
        btnConfirmerAjouter_mach->setMinimumWidth(200);

        hboxLayout9->addWidget(btnConfirmerAjouter_mach);

        btnAnnulerAjouter_mach = new QPushButton(tabAjouter_mach);
        btnAnnulerAjouter_mach->setObjectName("btnAnnulerAjouter_mach");
        btnAnnulerAjouter_mach->setMinimumHeight(45);
        btnAnnulerAjouter_mach->setMinimumWidth(150);

        hboxLayout9->addWidget(btnAnnulerAjouter_mach);


        vboxLayout9->addLayout(hboxLayout9);

        tabWidget_mach->addTab(tabAjouter_mach, QString());
        tabListe_mach = new QWidget();
        tabListe_mach->setObjectName("tabListe_mach");
        vboxLayout10 = new QVBoxLayout(tabListe_mach);
        vboxLayout10->setObjectName("vboxLayout10");
        tableMachines = new QTableWidget(tabListe_mach);
        if (tableMachines->columnCount() < 7)
            tableMachines->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(0, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(1, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(2, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(3, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(4, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(5, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(6, __qtablewidgetitem53);
        tableMachines->setObjectName("tableMachines");
        tableMachines->setAlternatingRowColors(true);
        tableMachines->setSelectionBehavior(QAbstractItemView::SelectRows);

        vboxLayout10->addWidget(tableMachines);

        hboxLayout10 = new QHBoxLayout();
        hboxLayout10->setObjectName("hboxLayout10");
        btnExportPDF_mach = new QPushButton(tabListe_mach);
        btnExportPDF_mach->setObjectName("btnExportPDF_mach");
        btnExportPDF_mach->setMinimumHeight(35);

        hboxLayout10->addWidget(btnExportPDF_mach);

        btnRefresh = new QPushButton(tabListe_mach);
        btnRefresh->setObjectName("btnRefresh");
        btnRefresh->setMinimumHeight(35);

        hboxLayout10->addWidget(btnRefresh);

        spacerItem8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout10->addItem(spacerItem8);


        vboxLayout10->addLayout(hboxLayout10);

        tabWidget_mach->addTab(tabListe_mach, QString());
        tabSupprimer_mach = new QWidget();
        tabSupprimer_mach->setObjectName("tabSupprimer_mach");
        vboxLayout11 = new QVBoxLayout(tabSupprimer_mach);
        vboxLayout11->setObjectName("vboxLayout11");
        vboxLayout11->setContentsMargins(20, 20, 20, 20);
        label22 = new QLabel(tabSupprimer_mach);
        label22->setObjectName("label22");
        label22->setWordWrap(true);

        vboxLayout11->addWidget(label22);

        grpMachineASupprimer = new QGroupBox(tabSupprimer_mach);
        grpMachineASupprimer->setObjectName("grpMachineASupprimer");
        vboxLayout12 = new QVBoxLayout(grpMachineASupprimer);
        vboxLayout12->setObjectName("vboxLayout12");
        lblSupprimerNom_mach = new QLabel(grpMachineASupprimer);
        lblSupprimerNom_mach->setObjectName("lblSupprimerNom_mach");
        lblSupprimerNom_mach->setFont(font2);

        vboxLayout12->addWidget(lblSupprimerNom_mach);

        lblSupprimerDetails_mach = new QLabel(grpMachineASupprimer);
        lblSupprimerDetails_mach->setObjectName("lblSupprimerDetails_mach");

        vboxLayout12->addWidget(lblSupprimerDetails_mach);


        vboxLayout11->addWidget(grpMachineASupprimer);

        spacerItem9 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout11->addItem(spacerItem9);

        hboxLayout11 = new QHBoxLayout();
        hboxLayout11->setObjectName("hboxLayout11");
        spacerItem10 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout11->addItem(spacerItem10);

        btnConfirmerSupprimer_mach = new QPushButton(tabSupprimer_mach);
        btnConfirmerSupprimer_mach->setObjectName("btnConfirmerSupprimer_mach");
        btnConfirmerSupprimer_mach->setMinimumHeight(45);
        btnConfirmerSupprimer_mach->setMinimumWidth(250);

        hboxLayout11->addWidget(btnConfirmerSupprimer_mach);

        btnAnnulerSupprimer_mach = new QPushButton(tabSupprimer_mach);
        btnAnnulerSupprimer_mach->setObjectName("btnAnnulerSupprimer_mach");
        btnAnnulerSupprimer_mach->setMinimumHeight(45);
        btnAnnulerSupprimer_mach->setMinimumWidth(150);

        hboxLayout11->addWidget(btnAnnulerSupprimer_mach);


        vboxLayout11->addLayout(hboxLayout11);

        tabWidget_mach->addTab(tabSupprimer_mach, QString());
        tabModifier_mach = new QWidget();
        tabModifier_mach->setObjectName("tabModifier_mach");
        vboxLayout13 = new QVBoxLayout(tabModifier_mach);
        vboxLayout13->setObjectName("vboxLayout13");
        vboxLayout13->setContentsMargins(20, 20, 20, 20);
        label23 = new QLabel(tabModifier_mach);
        label23->setObjectName("label23");

        vboxLayout13->addWidget(label23);

        grpFormModifier_mach = new QGroupBox(tabModifier_mach);
        grpFormModifier_mach->setObjectName("grpFormModifier_mach");
        formLayout = new QFormLayout(grpFormModifier_mach);
        formLayout->setObjectName("formLayout");
        formLayout->setHorizontalSpacing(20);
        formLayout->setVerticalSpacing(12);
        label24 = new QLabel(grpFormModifier_mach);
        label24->setObjectName("label24");

        formLayout->setWidget(0, QFormLayout::LabelRole, label24);

        editModifierId = new QLineEdit(grpFormModifier_mach);
        editModifierId->setObjectName("editModifierId");
        editModifierId->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, editModifierId);

        label25 = new QLabel(grpFormModifier_mach);
        label25->setObjectName("label25");

        formLayout->setWidget(1, QFormLayout::LabelRole, label25);

        editModifierNom = new QLineEdit(grpFormModifier_mach);
        editModifierNom->setObjectName("editModifierNom");

        formLayout->setWidget(1, QFormLayout::FieldRole, editModifierNom);

        label26 = new QLabel(grpFormModifier_mach);
        label26->setObjectName("label26");

        formLayout->setWidget(2, QFormLayout::LabelRole, label26);

        comboModifierCategorie = new QComboBox(grpFormModifier_mach);
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->addItem(QString());
        comboModifierCategorie->setObjectName("comboModifierCategorie");

        formLayout->setWidget(2, QFormLayout::FieldRole, comboModifierCategorie);

        label27 = new QLabel(grpFormModifier_mach);
        label27->setObjectName("label27");

        formLayout->setWidget(3, QFormLayout::LabelRole, label27);

        editModifierReference = new QLineEdit(grpFormModifier_mach);
        editModifierReference->setObjectName("editModifierReference");

        formLayout->setWidget(3, QFormLayout::FieldRole, editModifierReference);

        label28 = new QLabel(grpFormModifier_mach);
        label28->setObjectName("label28");

        formLayout->setWidget(4, QFormLayout::LabelRole, label28);

        dateModifierAchat = new QDateEdit(grpFormModifier_mach);
        dateModifierAchat->setObjectName("dateModifierAchat");
        dateModifierAchat->setCalendarPopup(true);

        formLayout->setWidget(4, QFormLayout::FieldRole, dateModifierAchat);

        label29 = new QLabel(grpFormModifier_mach);
        label29->setObjectName("label29");

        formLayout->setWidget(5, QFormLayout::LabelRole, label29);

        comboModifierEtat = new QComboBox(grpFormModifier_mach);
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->addItem(QString());
        comboModifierEtat->setObjectName("comboModifierEtat");

        formLayout->setWidget(5, QFormLayout::FieldRole, comboModifierEtat);

        label30 = new QLabel(grpFormModifier_mach);
        label30->setObjectName("label30");

        formLayout->setWidget(6, QFormLayout::LabelRole, label30);

        editModifierLocalisation = new QLineEdit(grpFormModifier_mach);
        editModifierLocalisation->setObjectName("editModifierLocalisation");

        formLayout->setWidget(6, QFormLayout::FieldRole, editModifierLocalisation);


        vboxLayout13->addWidget(grpFormModifier_mach);

        spacerItem11 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout13->addItem(spacerItem11);

        hboxLayout12 = new QHBoxLayout();
        hboxLayout12->setObjectName("hboxLayout12");
        spacerItem12 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout12->addItem(spacerItem12);

        btnConfirmerModifier_mach = new QPushButton(tabModifier_mach);
        btnConfirmerModifier_mach->setObjectName("btnConfirmerModifier_mach");
        btnConfirmerModifier_mach->setMinimumHeight(45);
        btnConfirmerModifier_mach->setMinimumWidth(250);

        hboxLayout12->addWidget(btnConfirmerModifier_mach);

        btnAnnulerModifier_mach = new QPushButton(tabModifier_mach);
        btnAnnulerModifier_mach->setObjectName("btnAnnulerModifier_mach");
        btnAnnulerModifier_mach->setMinimumHeight(45);
        btnAnnulerModifier_mach->setMinimumWidth(150);

        hboxLayout12->addWidget(btnAnnulerModifier_mach);


        vboxLayout13->addLayout(hboxLayout12);

        tabWidget_mach->addTab(tabModifier_mach, QString());
        tabPanne = new QWidget();
        tabPanne->setObjectName("tabPanne");
        vboxLayout14 = new QVBoxLayout(tabPanne);
        vboxLayout14->setObjectName("vboxLayout14");
        vboxLayout14->setContentsMargins(20, 20, 20, 20);
        label31 = new QLabel(tabPanne);
        label31->setObjectName("label31");

        vboxLayout14->addWidget(label31);

        grpPanne = new QGroupBox(tabPanne);
        grpPanne->setObjectName("grpPanne");
        formLayout1 = new QFormLayout(grpPanne);
        formLayout1->setObjectName("formLayout1");
        formLayout1->setHorizontalSpacing(20);
        formLayout1->setVerticalSpacing(12);
        label32 = new QLabel(grpPanne);
        label32->setObjectName("label32");

        formLayout1->setWidget(0, QFormLayout::LabelRole, label32);

        comboPanneMachine = new QComboBox(grpPanne);
        comboPanneMachine->setObjectName("comboPanneMachine");

        formLayout1->setWidget(0, QFormLayout::FieldRole, comboPanneMachine);

        label33 = new QLabel(grpPanne);
        label33->setObjectName("label33");

        formLayout1->setWidget(1, QFormLayout::LabelRole, label33);

        datePanne = new QDateEdit(grpPanne);
        datePanne->setObjectName("datePanne");
        datePanne->setCalendarPopup(true);

        formLayout1->setWidget(1, QFormLayout::FieldRole, datePanne);

        label34 = new QLabel(grpPanne);
        label34->setObjectName("label34");

        formLayout1->setWidget(2, QFormLayout::LabelRole, label34);

        comboTypePanne = new QComboBox(grpPanne);
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->addItem(QString());
        comboTypePanne->setObjectName("comboTypePanne");

        formLayout1->setWidget(2, QFormLayout::FieldRole, comboTypePanne);

        label35 = new QLabel(grpPanne);
        label35->setObjectName("label35");

        formLayout1->setWidget(3, QFormLayout::LabelRole, label35);

        comboGravite = new QComboBox(grpPanne);
        comboGravite->addItem(QString());
        comboGravite->addItem(QString());
        comboGravite->addItem(QString());
        comboGravite->addItem(QString());
        comboGravite->setObjectName("comboGravite");

        formLayout1->setWidget(3, QFormLayout::FieldRole, comboGravite);

        label36 = new QLabel(grpPanne);
        label36->setObjectName("label36");

        formLayout1->setWidget(4, QFormLayout::LabelRole, label36);

        txtDescriptionPanne = new QTextEdit(grpPanne);
        txtDescriptionPanne->setObjectName("txtDescriptionPanne");
        txtDescriptionPanne->setMaximumHeight(100);

        formLayout1->setWidget(4, QFormLayout::FieldRole, txtDescriptionPanne);


        vboxLayout14->addWidget(grpPanne);

        spacerItem13 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vboxLayout14->addItem(spacerItem13);

        hboxLayout13 = new QHBoxLayout();
        hboxLayout13->setObjectName("hboxLayout13");
        spacerItem14 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout13->addItem(spacerItem14);

        btnSignalerPanne = new QPushButton(tabPanne);
        btnSignalerPanne->setObjectName("btnSignalerPanne");
        btnSignalerPanne->setMinimumHeight(45);
        btnSignalerPanne->setMinimumWidth(220);

        hboxLayout13->addWidget(btnSignalerPanne);

        btnAnnulerPanne = new QPushButton(tabPanne);
        btnAnnulerPanne->setObjectName("btnAnnulerPanne");
        btnAnnulerPanne->setMinimumHeight(45);
        btnAnnulerPanne->setMinimumWidth(150);

        hboxLayout13->addWidget(btnAnnulerPanne);


        vboxLayout14->addLayout(hboxLayout13);

        tabWidget_mach->addTab(tabPanne, QString());
        tabHistorique = new QWidget();
        tabHistorique->setObjectName("tabHistorique");
        vboxLayout15 = new QVBoxLayout(tabHistorique);
        vboxLayout15->setObjectName("vboxLayout15");
        tableHistorique = new QTableWidget(tabHistorique);
        if (tableHistorique->columnCount() < 6)
            tableHistorique->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(0, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(1, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(2, __qtablewidgetitem56);
        QTableWidgetItem *__qtablewidgetitem57 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(3, __qtablewidgetitem57);
        QTableWidgetItem *__qtablewidgetitem58 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(4, __qtablewidgetitem58);
        QTableWidgetItem *__qtablewidgetitem59 = new QTableWidgetItem();
        tableHistorique->setHorizontalHeaderItem(5, __qtablewidgetitem59);
        tableHistorique->setObjectName("tableHistorique");
        tableHistorique->setAlternatingRowColors(true);
        tableHistorique->setSelectionBehavior(QAbstractItemView::SelectRows);

        vboxLayout15->addWidget(tableHistorique);

        hboxLayout14 = new QHBoxLayout();
        hboxLayout14->setObjectName("hboxLayout14");
        btnExportHistorique = new QPushButton(tabHistorique);
        btnExportHistorique->setObjectName("btnExportHistorique");
        btnExportHistorique->setMinimumHeight(35);

        hboxLayout14->addWidget(btnExportHistorique);

        spacerItem15 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout14->addItem(spacerItem15);


        vboxLayout15->addLayout(hboxLayout14);

        tabWidget_mach->addTab(tabHistorique, QString());
        tabStatistiques_mach = new QWidget();
        tabStatistiques_mach->setObjectName("tabStatistiques_mach");
        vboxLayout16 = new QVBoxLayout(tabStatistiques_mach);
        vboxLayout16->setObjectName("vboxLayout16");
        grpStatsResume = new QGroupBox(tabStatistiques_mach);
        grpStatsResume->setObjectName("grpStatsResume");
        hboxLayout15 = new QHBoxLayout(grpStatsResume);
        hboxLayout15->setObjectName("hboxLayout15");
        groupBox = new QGroupBox(grpStatsResume);
        groupBox->setObjectName("groupBox");
        vboxLayout17 = new QVBoxLayout(groupBox);
        vboxLayout17->setObjectName("vboxLayout17");
        lblStatsTotalMachines = new QLabel(groupBox);
        lblStatsTotalMachines->setObjectName("lblStatsTotalMachines");
        lblStatsTotalMachines->setAlignment(Qt::AlignCenter);
        QFont font5;
        font5.setPointSize(24);
        font5.setBold(true);
        lblStatsTotalMachines->setFont(font5);

        vboxLayout17->addWidget(lblStatsTotalMachines);


        hboxLayout15->addWidget(groupBox);

        groupBox1 = new QGroupBox(grpStatsResume);
        groupBox1->setObjectName("groupBox1");
        vboxLayout18 = new QVBoxLayout(groupBox1);
        vboxLayout18->setObjectName("vboxLayout18");
        lblStatsEnService = new QLabel(groupBox1);
        lblStatsEnService->setObjectName("lblStatsEnService");
        lblStatsEnService->setAlignment(Qt::AlignCenter);
        lblStatsEnService->setFont(font5);

        vboxLayout18->addWidget(lblStatsEnService);


        hboxLayout15->addWidget(groupBox1);

        groupBox2 = new QGroupBox(grpStatsResume);
        groupBox2->setObjectName("groupBox2");
        vboxLayout19 = new QVBoxLayout(groupBox2);
        vboxLayout19->setObjectName("vboxLayout19");
        lblStatsEnPanne = new QLabel(groupBox2);
        lblStatsEnPanne->setObjectName("lblStatsEnPanne");
        lblStatsEnPanne->setAlignment(Qt::AlignCenter);
        lblStatsEnPanne->setFont(font5);

        vboxLayout19->addWidget(lblStatsEnPanne);


        hboxLayout15->addWidget(groupBox2);

        groupBox3 = new QGroupBox(grpStatsResume);
        groupBox3->setObjectName("groupBox3");
        vboxLayout20 = new QVBoxLayout(groupBox3);
        vboxLayout20->setObjectName("vboxLayout20");
        lblStatsMaintenance = new QLabel(groupBox3);
        lblStatsMaintenance->setObjectName("lblStatsMaintenance");
        lblStatsMaintenance->setAlignment(Qt::AlignCenter);
        lblStatsMaintenance->setFont(font5);

        vboxLayout20->addWidget(lblStatsMaintenance);


        hboxLayout15->addWidget(groupBox3);


        vboxLayout16->addWidget(grpStatsResume);

        txtStatistiques_mach = new QTextEdit(tabStatistiques_mach);
        txtStatistiques_mach->setObjectName("txtStatistiques_mach");
        txtStatistiques_mach->setReadOnly(true);

        vboxLayout16->addWidget(txtStatistiques_mach);

        hboxLayout16 = new QHBoxLayout();
        hboxLayout16->setObjectName("hboxLayout16");
        btnExportStats = new QPushButton(tabStatistiques_mach);
        btnExportStats->setObjectName("btnExportStats");
        btnExportStats->setMinimumHeight(35);

        hboxLayout16->addWidget(btnExportStats);

        spacerItem16 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        hboxLayout16->addItem(spacerItem16);


        vboxLayout16->addLayout(hboxLayout16);

        tabWidget_mach->addTab(tabStatistiques_mach, QString());

        centerLayout_mach->addWidget(tabWidget_mach);

        splitter->addWidget(centerPanel);

        machineLayout->addWidget(splitter);

        stackedMain->addWidget(MachineWidget);

        horizontalLayoutMain->addWidget(stackedMain);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar1 = new QStatusBar(MainWindow);
        statusbar1->setObjectName("statusbar1");
        MainWindow->setStatusBar(statusbar1);

        retranslateUi(MainWindow);

        topNavTabs->setCurrentIndex(0);
        tabWidgetClient->setCurrentIndex(0);
        topNavTabs1->setCurrentIndex(1);
        tabWidget_mach->setCurrentIndex(0);


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
"G\303\251rez efficacement vos employ\303\251s, \303\251quipes, clients, commandes, laboratoires et machines\n"
"depuis une interface moderne et intuitive.\n"
"\n"
"Optimisez votre production, suivez vos analyses qualit\303\251 et prenez des d\303\251cisions\n"
"\303\251clair\303\251es gr\303\242ce \303\240 nos outils de statistiques modernes.", nullptr));
        accueilMessage->setStyleSheet(QCoreApplication::translate("MainWindow", "font-size: 16px; color: #555; line-height: 1.6; margin: 30px 0;", nullptr));
        btnContinuer->setText(QCoreApplication::translate("MainWindow", "Commencer \342\206\222", nullptr));
        btnContinuer->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #2E7D32; color: white; font-size: 18px; font-weight: bold; border-radius: 8px; } QPushButton:hover { background-color: #1B5E20; }", nullptr));
        label_nom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_prenom->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_age->setText(QCoreApplication::translate("MainWindow", "\303\202ge", nullptr));
        label_spec->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        combo_spec->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        combo_spec->setItemText(1, QCoreApplication::translate("MainWindow", "Manager", nullptr));
        combo_spec->setItemText(2, QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        combo_spec->setItemText(3, QCoreApplication::translate("MainWindow", "Magasinier", nullptr));

        label_salaire->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        doubleSpin_salaire->setPrefix(QCoreApplication::translate("MainWindow", "\342\202\254 ", nullptr));
        label_anciennete->setText(QCoreApplication::translate("MainWindow", "Anciennet\303\251", nullptr));
        label_disp->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        combo_disp->setItemText(0, QCoreApplication::translate("MainWindow", "actif", nullptr));
        combo_disp->setItemText(1, QCoreApplication::translate("MainWindow", "suspendu", nullptr));

        label_heures->setText(QCoreApplication::translate("MainWindow", "Heures / semaine", nullptr));
        label_fourn->setText(QCoreApplication::translate("MainWindow", "Fournisseurs trait\303\251s", nullptr));
        label_id_equipe->setText(QCoreApplication::translate("MainWindow", "ID Equipe", nullptr));
        label_mdp->setText(QCoreApplication::translate("MainWindow", "Mot de passe", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("MainWindow", "Ajouter un employ\303\251", nullptr));
        groupSearch->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        label_search_id->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        search_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez ID...", nullptr));
        label_search_nom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        search_nom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez nom...", nullptr));
        label_search_id_equipe->setText(QCoreApplication::translate("MainWindow", "ID Equipe", nullptr));
        search_id_equipe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez ID equipe...", nullptr));
        label_search_spec->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        search_spec->setItemText(0, QCoreApplication::translate("MainWindow", "-- Tous --", nullptr));
        search_spec->setItemText(1, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        search_spec->setItemText(2, QCoreApplication::translate("MainWindow", "Manager", nullptr));
        search_spec->setItemText(3, QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        search_spec->setItemText(4, QCoreApplication::translate("MainWindow", "Magasinier", nullptr));

        groupSort->setTitle(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        sort_salaire->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        sort_anciennete->setText(QCoreApplication::translate("MainWindow", "Anciennet\303\251", nullptr));
        sort_heures->setText(QCoreApplication::translate("MainWindow", "Heures", nullptr));
        sort_fournisseurs->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        groupOrder->setTitle(QCoreApplication::translate("MainWindow", "Ordre", nullptr));
        order_asc->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        order_desc->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
        btnAppliquerFiltreEmploye->setText(QCoreApplication::translate("MainWindow", "Appliquer", nullptr));
        btnResetFiltre->setText(QCoreApplication::translate("MainWindow", "R\303\251initialiser", nullptr));
        QTableWidgetItem *___qtablewidgetitem = table_employes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = table_employes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = table_employes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = table_employes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "\303\202ge", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = table_employes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = table_employes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = table_employes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Anciennet\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = table_employes->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = table_employes->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Heures", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = table_employes->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Fournisseurs", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = table_employes->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "ID Equipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = table_employes->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "MDP (hach\303\251)", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("MainWindow", "Liste des employ\303\251s", nullptr));
        label_id_suppr->setText(QCoreApplication::translate("MainWindow", "ID Employ\303\251", nullptr));
        btnSupprimerConfirm->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("MainWindow", "Supprimer un employ\303\251", nullptr));
        label_id_mod->setText(QCoreApplication::translate("MainWindow", "ID Employ\303\251", nullptr));
        groupBox_prefill->setTitle(QCoreApplication::translate("MainWindow", "Modifier les donn\303\251es", nullptr));
        label_nom_mod->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        label_prenom_mod->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        label_age_mod->setText(QCoreApplication::translate("MainWindow", "\303\202ge", nullptr));
        label_spec_mod->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        combo_spec_mod->setItemText(0, QCoreApplication::translate("MainWindow", "Admin", nullptr));
        combo_spec_mod->setItemText(1, QCoreApplication::translate("MainWindow", "Manager", nullptr));
        combo_spec_mod->setItemText(2, QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        combo_spec_mod->setItemText(3, QCoreApplication::translate("MainWindow", "Magasinier", nullptr));

        label_salaire_mod->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        doubleSpin_salaire_mod->setPrefix(QCoreApplication::translate("MainWindow", "\342\202\254 ", nullptr));
        label_anciennete_mod->setText(QCoreApplication::translate("MainWindow", "Anciennet\303\251", nullptr));
        label_disp_mod->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        combo_disp_mod->setItemText(0, QCoreApplication::translate("MainWindow", "actif", nullptr));
        combo_disp_mod->setItemText(1, QCoreApplication::translate("MainWindow", "suspendu", nullptr));

        label_heures_mod->setText(QCoreApplication::translate("MainWindow", "Heures / semaine", nullptr));
        label_fourn_mod->setText(QCoreApplication::translate("MainWindow", "Fournisseurs trait\303\251s", nullptr));
        label_id_equipe_mod->setText(QCoreApplication::translate("MainWindow", "ID Equipe", nullptr));
        label_mdp_mod->setText(QCoreApplication::translate("MainWindow", "Nouveau mot de passe", nullptr));
        lineEdit_mdp_mod->setPlaceholderText(QCoreApplication::translate("MainWindow", "Laisser vide pour ne pas modifier", nullptr));
        btnModifierConfirm->setText(QCoreApplication::translate("MainWindow", "Mettre \303\240 jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("MainWindow", "Modifier un employ\303\251", nullptr));
        label_total_employes->setText(QCoreApplication::translate("MainWindow", "Nombre total d'employ\303\251s : 0", nullptr));
        label_masse_salariale->setText(QCoreApplication::translate("MainWindow", "Masse salariale totale : 0.00 \342\202\254", nullptr));
        label_salaire_moyen->setText(QCoreApplication::translate("MainWindow", "Salaire moyen : 0.00 \342\202\254", nullptr));
        groupTopChart->setTitle(QCoreApplication::translate("MainWindow", "Masse salariale par sp\303\251cialit\303\251", nullptr));
        groupLeftChart->setTitle(QCoreApplication::translate("MainWindow", "R\303\251partition des employ\303\251s par sp\303\251cialit\303\251", nullptr));
        groupRightChart->setTitle(QCoreApplication::translate("MainWindow", "Top employ\303\251s par fournisseurs trait\303\251s", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        groupExportOptions->setTitle(QCoreApplication::translate("MainWindow", "Options d'export", nullptr));
        btnExportListeComplete->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter la liste compl\303\250te des employ\303\251s (PDF)", nullptr));
        btnExportFicheEmploye->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213 Exporter la fiche d'un employ\303\251 par ID (PDF)", nullptr));
        groupIdExport->setTitle(QCoreApplication::translate("MainWindow", "Param\303\250tres d'export", nullptr));
        label_id_export->setText(QCoreApplication::translate("MainWindow", "ID Employ\303\251 (pour la fiche)", nullptr));
        groupMessagesExport->setTitle(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExportPdf), QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        label_app_title->setText(QCoreApplication::translate("MainWindow", "Smart Oil Press", nullptr));
        label_app_title->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        label_login_title->setText(QCoreApplication::translate("MainWindow", "Connexion ", nullptr));
        label_login_title->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #798777;", nullptr));
        label_user_conn->setText(QCoreApplication::translate("MainWindow", "  Username  ", nullptr));
        label_user_conn->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #2C2C2C; font-weight: bold;", nullptr));
        label_pass_conn->setText(QCoreApplication::translate("MainWindow", "  Mot de passe  ", nullptr));
        label_pass_conn->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #2C2C2C; font-weight: bold;", nullptr));
        btnSeConnecter->setText(QCoreApplication::translate("MainWindow", "Se connecter", nullptr));
        label_login_error->setText(QString());
        label_login_error->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #C62828; font-weight: bold;", nullptr));
        btnNavigateForgot->setText(QCoreApplication::translate("MainWindow", "Mot de passe oubli\303\251 ?", nullptr));
        btnNavigateForgot->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: transparent; color: #A2B29F; border: none; text-decoration: underline; font-size: 10pt; padding: 4px; } QPushButton:hover { color: #798777; }", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConnexion), QCoreApplication::translate("MainWindow", "Connexion", nullptr));
        groupFPStep1->setTitle(QCoreApplication::translate("MainWindow", "\303\211tape 1 \342\200\224 Demander code", nullptr));
        label_user_identite_fp->setText(QCoreApplication::translate("MainWindow", "Identifiant (Nom Prenom)", nullptr));
        btnValiderIdentite->setText(QCoreApplication::translate("MainWindow", "Valider identifiant", nullptr));
        label_user_email_fp->setText(QCoreApplication::translate("MainWindow", " Email ", nullptr));
        btnEnvoyerCode->setText(QCoreApplication::translate("MainWindow", "Envoyer code", nullptr));
        groupFPStep2->setTitle(QCoreApplication::translate("MainWindow", "\303\211tape 2 \342\200\224 R\303\251initialiser", nullptr));
        label_code_fp->setText(QCoreApplication::translate("MainWindow", "Code", nullptr));
        label_newpass_fp->setText(QCoreApplication::translate("MainWindow", "Nouveau mot de passe", nullptr));
        label_confirm_fp->setText(QCoreApplication::translate("MainWindow", "Confirmation", nullptr));
        btnResetPassword->setText(QCoreApplication::translate("MainWindow", "R\303\251initialiser", nullptr));
        btnBackToLogin->setText(QCoreApplication::translate("MainWindow", "Retour \303\240 Connexion", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMotPasseOublie), QCoreApplication::translate("MainWindow", "Mot de passe oubli\303\251", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabAjouter1), QCoreApplication::translate("MainWindow", "Ajouter une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabGestion), QCoreApplication::translate("MainWindow", "Liste des \303\251quipes", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSupprimer1), QCoreApplication::translate("MainWindow", "Supprimer une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabModifier1), QCoreApplication::translate("MainWindow", "Modifier une \303\251quipe", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabStatistique), QCoreApplication::translate("MainWindow", "Statistique", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabSuggestion), QCoreApplication::translate("MainWindow", "Suggestion", nullptr));
        topNavTabs->setTabText(topNavTabs->indexOf(tabPlanification), QCoreApplication::translate("MainWindow", "Planification", nullptr));
        addTitle->setText(QCoreApplication::translate("MainWindow", "Ajouter une \303\211quipe", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        lineEditNomEquipeAjout->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom de l'\303\251quipe", nullptr));
        label_31->setText(QCoreApplication::translate("MainWindow", "Chef:", nullptr));
        lineEditChefEquipeAjout->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez le nom du chef", nullptr));
        label_32->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251:", nullptr));
        comboBoxSpecialiteEquipeAjout->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner la sp\303\251cialit\303\251", nullptr));
        comboBoxSpecialiteEquipeAjout->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboBoxSpecialiteEquipeAjout->setItemText(2, QCoreApplication::translate("MainWindow", "Production", nullptr));
        comboBoxSpecialiteEquipeAjout->setItemText(3, QCoreApplication::translate("MainWindow", "Back-office", nullptr));
        comboBoxSpecialiteEquipeAjout->setItemText(4, QCoreApplication::translate("MainWindow", "M\303\251canique", nullptr));

        label_33->setText(QCoreApplication::translate("MainWindow", "Nombre de membres:", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner le nombre", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBoxNbMembresEquipeAjout->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

        btnAjouterEquipe->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        lineEditRechercheEquipe->setPlaceholderText(QCoreApplication::translate("MainWindow", "recherche des equipes par ID, NOM, sp\303\251cialit\303\251 ...", nullptr));
        btnFiltre->setText(QCoreApplication::translate("MainWindow", "filtre", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Tri des \303\251quipes", nullptr));
        btnTrier->setText(QCoreApplication::translate("MainWindow", "trier par", nullptr));
        comboBoxTriEquipe->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBoxTriEquipe->setItemText(1, QCoreApplication::translate("MainWindow", "Nom chef", nullptr));
        comboBoxTriEquipe->setItemText(2, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBoxTriEquipe->setItemText(3, QCoreApplication::translate("MainWindow", "Specialit\303\251", nullptr));

        checkBoxTriEquipeCroissant->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        checkBoxTriEquipeDecroissant->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidgetEquipe->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "ID \303\211quipe", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidgetEquipe->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidgetEquipe->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidgetEquipe->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "Membres", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidgetEquipe->horizontalHeaderItem(4);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Chef ", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidgetEquipe->horizontalHeaderItem(5);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "\303\251tat d' \303\251quipe", nullptr));
        modifTitle->setText(QCoreApplication::translate("MainWindow", "Modifier une \303\211quipe", nullptr));
        label_modif_id->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEdit_modif_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez l'ID de l'\303\251quipe", nullptr));
        label_35->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        lineEditNomEquipeModif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nouveau nom", nullptr));
        label_36->setText(QCoreApplication::translate("MainWindow", "Chef:", nullptr));
        lineEditChefEquipeModif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez le nouveau chef", nullptr));
        label_37->setText(QCoreApplication::translate("MainWindow", "Sp\303\251cialit\303\251:", nullptr));
        comboBoxSpecialiteEquipeModif->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner la sp\303\251cialit\303\251", nullptr));
        comboBoxSpecialiteEquipeModif->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboBoxSpecialiteEquipeModif->setItemText(2, QCoreApplication::translate("MainWindow", "Production", nullptr));
        comboBoxSpecialiteEquipeModif->setItemText(3, QCoreApplication::translate("MainWindow", "Back-office", nullptr));
        comboBoxSpecialiteEquipeModif->setItemText(4, QCoreApplication::translate("MainWindow", "M\303\251canique", nullptr));

        label_38->setText(QCoreApplication::translate("MainWindow", "Nombre de membres:", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner le nombre", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(1, QCoreApplication::translate("MainWindow", "1", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(2, QCoreApplication::translate("MainWindow", "2", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(3, QCoreApplication::translate("MainWindow", "3", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(4, QCoreApplication::translate("MainWindow", "4", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(5, QCoreApplication::translate("MainWindow", "5", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(6, QCoreApplication::translate("MainWindow", "6", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(7, QCoreApplication::translate("MainWindow", "7", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(8, QCoreApplication::translate("MainWindow", "8", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(9, QCoreApplication::translate("MainWindow", "9", nullptr));
        comboBoxNbMembresEquipeModif->setItemText(10, QCoreApplication::translate("MainWindow", "10", nullptr));

        btnModifierEquipe->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        suppTitle->setText(QCoreApplication::translate("MainWindow", "Supprimer une \303\211quipe", nullptr));
        suppWarning->setText(QCoreApplication::translate("MainWindow", "Attention: Cette action est irr\303\251versible", nullptr));
        label_42->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEditIdEquipeSuppression->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez l'ID de l'\303\251quipe \303\240 supprimer", nullptr));
        btnSupprimerEquipe->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        statTitle->setText(QCoreApplication::translate("MainWindow", "Statistiques et Performance", nullptr));
        performanceGroup->setTitle(QCoreApplication::translate("MainWindow", "Performance", nullptr));
        vitesseGroup->setTitle(QCoreApplication::translate("MainWindow", "Vitesse de Traitement", nullptr));
        objectifsGroup->setTitle(QCoreApplication::translate("MainWindow", "R\303\251ussites & Objectifs", nullptr));

        const bool __sortingEnabled = listWidget_2->isSortingEnabled();
        listWidget_2->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget_2->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "Missions r\303\251ussies", nullptr));
        listWidget_2->setSortingEnabled(__sortingEnabled);

        evalGroup->setTitle(QCoreApplication::translate("MainWindow", "Notes & \303\211valuations", nullptr));
        btnExportEquipePdf->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "cas:", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "Meilleures Recommandations", nullptr));
        btnRechercherRecommandationEquipe->setText(QCoreApplication::translate("MainWindow", "RECHERCHER", nullptr));
        checkBoxRequiertDisponibilite->setText(QCoreApplication::translate("MainWindow", "n\303\251cessite la diponibilit\303\251", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "sp\303\251cialit\303\251:", nullptr));
        comboBoxSpecialiteRecommandation->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la specialit\303\251 demand\303\251", nullptr));
        comboBoxSpecialiteRecommandation->setItemText(1, QCoreApplication::translate("MainWindow", "maintenace", nullptr));
        comboBoxSpecialiteRecommandation->setItemText(2, QCoreApplication::translate("MainWindow", "production", nullptr));
        comboBoxSpecialiteRecommandation->setItemText(3, QCoreApplication::translate("MainWindow", "backoffice", nullptr));
        comboBoxSpecialiteRecommandation->setItemText(4, QCoreApplication::translate("MainWindow", "m\303\251canique", nullptr));
        comboBoxSpecialiteRecommandation->setItemText(5, QString());

        label_19->setText(QCoreApplication::translate("MainWindow", "nombre minimum des individu de l'\303\251quipe :", nullptr));
        lineEditNbMembresMinRecommandation->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrer le nombre ici", nullptr));
        checkBoxUrgentRecommandation->setText(QCoreApplication::translate("MainWindow", "urgent", nullptr));
        checkBoxEtatNormalRecommandation->setText(QCoreApplication::translate("MainWindow", "\303\251tat normal", nullptr));
        label_24->setText(QCoreApplication::translate("MainWindow", "difficult\303\251 du cas :", nullptr));

        const bool __sortingEnabled1 = listWidget_3->isSortingEnabled();
        listWidget_3->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem1 = listWidget_3->item(0);
        ___qlistwidgetitem1->setText(QCoreApplication::translate("MainWindow", "Recommandations affich\303\251es ici", nullptr));
        listWidget_3->setSortingEnabled(__sortingEnabled1);

        label_25->setText(QCoreApplication::translate("MainWindow", "Resultat", nullptr));
        comboBoxDifficulteRecommandation->setItemText(0, QCoreApplication::translate("MainWindow", "selectionner la difficult\303\251 ici ", nullptr));
        comboBoxDifficulteRecommandation->setItemText(1, QCoreApplication::translate("MainWindow", "facile", nullptr));
        comboBoxDifficulteRecommandation->setItemText(2, QCoreApplication::translate("MainWindow", "Normal", nullptr));
        comboBoxDifficulteRecommandation->setItemText(3, QCoreApplication::translate("MainWindow", "Difficile", nullptr));

        lineEditRecherchePlanificationEquipe->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher des \303\251quipes par ID, NOM, CHEF, \303\211TAT...", nullptr));
        btnRechercherPlanificationEquipe->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        taskLabel->setText(QCoreApplication::translate("MainWindow", "Liste des T\303\242ches", nullptr));

        const bool __sortingEnabled2 = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(0);
        ___qlistwidgetitem2->setText(QCoreApplication::translate("MainWindow", "T\303\242ches planifi\303\251es affich\303\251es ici", nullptr));
        listWidget->setSortingEnabled(__sortingEnabled2);

        grpRechercheFiltre->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        lblNom->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        grpFiltres->setTitle(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        lblType->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        lblStatut->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        btnAppliquerFiltre->setText(QCoreApplication::translate("MainWindow", "Appliquer", nullptr));
        grpFormAjouter->setTitle(QCoreApplication::translate("MainWindow", "Nouveau Client", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nom *", nullptr));
        txtAjouterNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom complet", nullptr));
        label1->setText(QCoreApplication::translate("MainWindow", "Type *", nullptr));
        label2->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        txtAjouterTel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex: 98 123 456", nullptr));
        label3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        txtAjouterEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex: client@email.com", nullptr));
        label4->setText(QCoreApplication::translate("MainWindow", "Statut *", nullptr));
        btnConfirmerAjouter->setText(QCoreApplication::translate("MainWindow", "\342\234\223  Confirmer l'ajout", nullptr));
        btnConfirmerAjouter->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #6FA66F; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #7CB87C; } QPushButton:pressed { background-color: #5D945D; }", nullptr));
        btnAnnulerAjouter->setText(QCoreApplication::translate("MainWindow", "\342\234\225  Annuler", nullptr));
        btnAnnulerAjouter->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #B8B8B8; }", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabAjouter2), QCoreApplication::translate("MainWindow", "Ajouter un Client", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabListeClients), QCoreApplication::translate("MainWindow", "Liste des Clients", nullptr));
        lblSupprimerInfo->setText(QCoreApplication::translate("MainWindow", "\342\232\240  S\303\251lectionnez un client dans \"Liste des Clients\", puis confirmez la suppression. Cette action est irr\303\251versible.", nullptr));
        lblSupprimerInfo->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { background-color: #FDECEA; color: #C62828; border-radius: 4px; padding: 10px; font-size: 10pt; }", nullptr));
        grpClientASupprimer->setTitle(QCoreApplication::translate("MainWindow", "Client S\303\251lectionn\303\251", nullptr));
        lblSupprimerNom->setText(QCoreApplication::translate("MainWindow", "Aucun client s\303\251lectionn\303\251", nullptr));
        lblSupprimerNom->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { color: #3D4F3C; padding: 6px; }", nullptr));
        lblSupprimerDetails->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        lblSupprimerDetails->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { color: #666666; padding: 4px; }", nullptr));
        btnConfirmerSupprimer->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221  Confirmer la suppression", nullptr));
        btnConfirmerSupprimer->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #C97A7A; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #E08989; } QPushButton:pressed { background-color: #B86B6B; }", nullptr));
        btnAnnulerSupprimer->setText(QCoreApplication::translate("MainWindow", "\342\234\225  Annuler", nullptr));
        btnAnnulerSupprimer->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #B8B8B8; }", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabSupprimer2), QCoreApplication::translate("MainWindow", "Supprimer un Client", nullptr));
        lblModifierInfo->setText(QCoreApplication::translate("MainWindow", "\342\223\230  S\303\251lectionnez un client dans \"Liste des Clients\" puis modifiez ses informations ci-dessous.", nullptr));
        lblModifierInfo->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { background-color: #EAF0EA; color: #3D4F3C; border-radius: 4px; padding: 8px; font-size: 10pt; }", nullptr));
        grpFormModifier->setTitle(QCoreApplication::translate("MainWindow", "Modifier le Client S\303\251lectionn\303\251", nullptr));
        label5->setText(QCoreApplication::translate("MainWindow", "Nom *", nullptr));
        txtModifierNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom du client", nullptr));
        label6->setText(QCoreApplication::translate("MainWindow", "Type *", nullptr));
        label7->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        txtModifierTel->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex: 98 123 456", nullptr));
        label8->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        txtModifierEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Ex: client@email.com", nullptr));
        label9->setText(QCoreApplication::translate("MainWindow", "Statut *", nullptr));
        btnConfirmerModifier->setText(QCoreApplication::translate("MainWindow", "\342\234\223  Confirmer la modification", nullptr));
        btnConfirmerModifier->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #D4A520; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #E6C36A; } QPushButton:pressed { background-color: #B8901A; }", nullptr));
        btnAnnulerModifier->setText(QCoreApplication::translate("MainWindow", "\342\234\225  Annuler", nullptr));
        btnAnnulerModifier->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: #FFFFFF; border: none; border-radius: 5px; font-size: 12pt; font-weight: bold; } QPushButton:hover { background-color: #B8B8B8; }", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabModifier2), QCoreApplication::translate("MainWindow", "Modifier un Client", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabStatistiques1), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabAlertes), QCoreApplication::translate("MainWindow", "Alertes", nullptr));
        grpClientDetails->setTitle(QCoreApplication::translate("MainWindow", "D\303\251tails du Client S\303\251lectionn\303\251", nullptr));
        grpInfoGenerales->setTitle(QCoreApplication::translate("MainWindow", "Informations G\303\251n\303\251rales", nullptr));
        lblInfoStatut->setText(QCoreApplication::translate("MainWindow", "Statut : -", nullptr));
        lblInfoAlertes->setText(QCoreApplication::translate("MainWindow", "Alertes : -", nullptr));
        grpRetards->setTitle(QCoreApplication::translate("MainWindow", "Retards de Paiement", nullptr));
        lblRetardsNombre->setText(QCoreApplication::translate("MainWindow", "Nombre de retards : -", nullptr));
        lblRetardsMoyen->setText(QCoreApplication::translate("MainWindow", "Retard moyen : - jours", nullptr));
        lblRetardsTotal->setText(QCoreApplication::translate("MainWindow", "Montant en retard : - DT", nullptr));
        grpRetoursQualite->setTitle(QCoreApplication::translate("MainWindow", "Retours Qualit\303\251", nullptr));
        lblRetoursNombre->setText(QCoreApplication::translate("MainWindow", "Nombre de retours : -", nullptr));
        lblRetoursTaux->setText(QCoreApplication::translate("MainWindow", "Taux de retour : - %", nullptr));
        lblRetoursDernier->setText(QCoreApplication::translate("MainWindow", "Dernier retour : -", nullptr));
        grpPrix->setTitle(QCoreApplication::translate("MainWindow", "Prix et Facturation", nullptr));
        lblPrixMoyen->setText(QCoreApplication::translate("MainWindow", "Prix moyen commande : - DT", nullptr));
        lblPrixTotal->setText(QCoreApplication::translate("MainWindow", "CA total g\303\251n\303\251r\303\251 : - DT", nullptr));
        lblPrixRemise->setText(QCoreApplication::translate("MainWindow", "Remise accord\303\251e : - %", nullptr));
        grpHistorique->setTitle(QCoreApplication::translate("MainWindow", "Historique et Statistiques", nullptr));
        lblClientDepuis->setText(QCoreApplication::translate("MainWindow", "Client depuis : -", nullptr));
        lblNombreCommandes->setText(QCoreApplication::translate("MainWindow", "Nombre de commandes : -", nullptr));
        lblDerniereCommande->setText(QCoreApplication::translate("MainWindow", "Derni\303\250re commande : -", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabInfosClient), QCoreApplication::translate("MainWindow", "Infos Client", nullptr));
        grpExportOptions->setTitle(QCoreApplication::translate("MainWindow", "Options d'export", nullptr));
        btnExportListeClients->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204  Exporter la liste compl\303\250te des clients (PDF)", nullptr));
        btnExportListeClients->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #7A9E7E; color: #FFFFFF; border: none; border-radius: 5px; font-size: 13pt; font-weight: bold; text-align: center; }\n"
"QPushButton:hover { background-color: #8FB594; }\n"
"QPushButton:pressed { background-color: #6B8C6F; }", nullptr));
        btnExportStatistiques->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212  Exporter un rapport statistiques clients (PDF)", nullptr));
        btnExportStatistiques->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #7A9E7E; color: #FFFFFF; border: none; border-radius: 5px; font-size: 13pt; font-weight: bold; text-align: center; }\n"
"QPushButton:hover { background-color: #8FB594; }\n"
"QPushButton:pressed { background-color: #6B8C6F; }", nullptr));
        btnExportFicheClient->setText(QCoreApplication::translate("MainWindow", "\360\237\223\213  Exporter la fiche d'un client par ID (PDF)", nullptr));
        btnExportFicheClient->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #7A9E7E; color: #FFFFFF; border: none; border-radius: 5px; font-size: 13pt; font-weight: bold; text-align: center; }\n"
"QPushButton:hover { background-color: #8FB594; }\n"
"QPushButton:pressed { background-color: #6B8C6F; }", nullptr));
        grpParamsExport->setTitle(QCoreApplication::translate("MainWindow", "Param\303\250tres d'export", nullptr));
        lblIdClient->setText(QCoreApplication::translate("MainWindow", "ID Client (pour la fiche)", nullptr));
        grpMessagesExport->setTitle(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        tabWidgetClient->setTabText(tabWidgetClient->indexOf(tabExportPDF), QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabAjouter3), QCoreApplication::translate("MainWindow", "Ajouter un laboratoire", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabGestion1), QCoreApplication::translate("MainWindow", "Liste des laboratoires", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabSupprimer3), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabModifier3), QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabStatistique1), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabGeolocalisation), QCoreApplication::translate("MainWindow", "G\303\251olocalisation", nullptr));
        topNavTabs1->setTabText(topNavTabs1->indexOf(tabAIBot), QCoreApplication::translate("MainWindow", "Assistant IA", nullptr));
        addTitle1->setText(QCoreApplication::translate("MainWindow", "Ajouter un Laboratoire", nullptr));
        label_id1->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEdit_id1->setPlaceholderText(QCoreApplication::translate("MainWindow", "ID g\303\251n\303\251r\303\251 automatiquement", nullptr));
        label_nom1->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        lineEdit_nom1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom du laboratoire", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Type d'analyse:", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("MainWindow", "S\303\251lectionner le type", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("MainWindow", "Chimique", nullptr));
        comboBox_type->setItemText(2, QCoreApplication::translate("MainWindow", "Bact\303\251riologique", nullptr));
        comboBox_type->setItemText(3, QCoreApplication::translate("MainWindow", "Physique", nullptr));
        comboBox_type->setItemText(4, QCoreApplication::translate("MainWindow", "Biologique", nullptr));

        label_conformite->setText(QCoreApplication::translate("MainWindow", "Conformit\303\251:", nullptr));
        comboBox_conformite->setItemText(0, QCoreApplication::translate("MainWindow", "Oui", nullptr));
        comboBox_conformite->setItemText(1, QCoreApplication::translate("MainWindow", "Non", nullptr));

        label_adresse->setText(QCoreApplication::translate("MainWindow", "Adresse:", nullptr));
        lineEdit_adresse->setPlaceholderText(QCoreApplication::translate("MainWindow", "Adresse du laboratoire", nullptr));
        label_espace->setText(QCoreApplication::translate("MainWindow", "Espace (m\302\262):", nullptr));
        btnAjouterLabo->setText(QCoreApplication::translate("MainWindow", "Enregistrer", nullptr));
        lineEditRechercheLabo->setPlaceholderText(QCoreApplication::translate("MainWindow", "Rechercher par ID, Nom, Adresse, Type d'analyse...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        label_71->setText(QCoreApplication::translate("MainWindow", "Tri des laboratoires", nullptr));
        btnTrier1->setText(QCoreApplication::translate("MainWindow", "Trier par", nullptr));
        comboBoxTriLabo->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboBoxTriLabo->setItemText(1, QCoreApplication::translate("MainWindow", "Type d analyse", nullptr));
        comboBoxTriLabo->setItemText(2, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBoxTriLabo->setItemText(3, QCoreApplication::translate("MainWindow", "Conformite", nullptr));

        checkBoxTriLaboCroissant->setText(QCoreApplication::translate("MainWindow", "Croissant", nullptr));
        checkBoxTriLaboDecroissant->setText(QCoreApplication::translate("MainWindow", "D\303\251croissant", nullptr));
        label_export->setText(QCoreApplication::translate("MainWindow", "Export", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidgetLabo->horizontalHeaderItem(0);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "ID Laboratoire", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidgetLabo->horizontalHeaderItem(1);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidgetLabo->horizontalHeaderItem(2);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "Type d'analyse", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidgetLabo->horizontalHeaderItem(3);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Conformit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidgetLabo->horizontalHeaderItem(4);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidgetLabo->horizontalHeaderItem(5);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Espace", nullptr));
        suppTitle1->setText(QCoreApplication::translate("MainWindow", "Supprimer un Laboratoire", nullptr));
        suppWarning1->setText(QCoreApplication::translate("MainWindow", "Attention: Cette action est irr\303\251versible", nullptr));
        label_421->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEditIdLaboSuppression->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez l'ID du laboratoire \303\240 supprimer", nullptr));
        btnSupprimerLabo->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        modifTitle1->setText(QCoreApplication::translate("MainWindow", "Modifier un Laboratoire", nullptr));
        label_modif_id1->setText(QCoreApplication::translate("MainWindow", "ID:", nullptr));
        lineEdit_modif_id1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisissez l'ID du laboratoire", nullptr));
        label_351->setText(QCoreApplication::translate("MainWindow", "Nom:", nullptr));
        lineEditNomLaboModif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nouveau nom", nullptr));
        label_361->setText(QCoreApplication::translate("MainWindow", "Type d'analyse:", nullptr));
        comboBox_modif_type->setItemText(0, QCoreApplication::translate("MainWindow", "Chimique", nullptr));
        comboBox_modif_type->setItemText(1, QCoreApplication::translate("MainWindow", "Bact\303\251riologique", nullptr));
        comboBox_modif_type->setItemText(2, QCoreApplication::translate("MainWindow", "Physique", nullptr));
        comboBox_modif_type->setItemText(3, QCoreApplication::translate("MainWindow", "Biologique", nullptr));

        label_371->setText(QCoreApplication::translate("MainWindow", "Conformit\303\251:", nullptr));
        comboBox_modif_conf->setItemText(0, QCoreApplication::translate("MainWindow", "Oui", nullptr));
        comboBox_modif_conf->setItemText(1, QCoreApplication::translate("MainWindow", "Non", nullptr));

        label_381->setText(QCoreApplication::translate("MainWindow", "Adresse:", nullptr));
        lineEditAdresseLaboModif->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nouvelle adresse", nullptr));
        btnModifierLabo->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        statTitle1->setText(QCoreApplication::translate("MainWindow", "Statistiques et Performance des laboratoires", nullptr));
        performanceGroup1->setTitle(QCoreApplication::translate("MainWindow", "Taux de conformit\303\251", nullptr));
        plainTextEdit1->setPlaceholderText(QCoreApplication::translate("MainWindow", "Statistiques de conformit\303\251 des analyses...", nullptr));
        vitesseGroup1->setTitle(QCoreApplication::translate("MainWindow", "Analyses mensuelles", nullptr));
        plainTextEdit_21->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nombre d'analyses par mois...", nullptr));
        btnExportStatsLaboPdf->setText(QCoreApplication::translate("MainWindow", "Exporter PDF", nullptr));
        geoPlaceholder->setText(QCoreApplication::translate("MainWindow", "Page de g\303\251olocalisation des laboratoires", nullptr));
        aiPlaceholder->setText(QCoreApplication::translate("MainWindow", "Assistant IA - Chatbot intelligent", nullptr));
        label_cmd->setText(QCoreApplication::translate("MainWindow", "GESTION DES COMMANDES", nullptr));
        labelNumCommande->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de commande :", nullptr));
        labelClient->setText(QCoreApplication::translate("MainWindow", "Client :", nullptr));
        labelProduit->setText(QCoreApplication::translate("MainWindow", "Produit :", nullptr));
        labelQuantite->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 :", nullptr));
        labelPrix->setText(QCoreApplication::translate("MainWindow", "Prix unitaire :", nullptr));
        labelStatut->setText(QCoreApplication::translate("MainWindow", "Statut :", nullptr));
        comboStatut->setItemText(0, QCoreApplication::translate("MainWindow", "En attente", nullptr));
        comboStatut->setItemText(1, QCoreApplication::translate("MainWindow", "Confirm\303\251e", nullptr));
        comboStatut->setItemText(2, QCoreApplication::translate("MainWindow", "Exp\303\251di\303\251e", nullptr));
        comboStatut->setItemText(3, QCoreApplication::translate("MainWindow", "Livr\303\251e", nullptr));

        labelDate->setText(QCoreApplication::translate("MainWindow", "Date de commande :", nullptr));
        btnAjouter_cmd->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnResetAjouter->setText(QCoreApplication::translate("MainWindow", "R\303\251initialiser", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabAjouter_cmd), QCoreApplication::translate("MainWindow", "Ajouter une commande", nullptr));
        labelFiltres->setText(QCoreApplication::translate("MainWindow", "Filtres :", nullptr));
        labelFiltres->setStyleSheet(QCoreApplication::translate("MainWindow", "font-weight: bold;", nullptr));
        checkFiltreTous->setText(QCoreApplication::translate("MainWindow", "Tous", nullptr));
        checkFiltreAttente->setText(QCoreApplication::translate("MainWindow", "En attente", nullptr));
        checkFiltreConfirmee->setText(QCoreApplication::translate("MainWindow", "Confirm\303\251e", nullptr));
        checkFiltreExpedie->setText(QCoreApplication::translate("MainWindow", "Exp\303\251di\303\251e", nullptr));
        checkFiltreLivree->setText(QCoreApplication::translate("MainWindow", "Livr\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableCommandes->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableCommandes->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableCommandes->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Produit", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableCommandes->horizontalHeaderItem(3);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableCommandes->horizontalHeaderItem(4);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableCommandes->horizontalHeaderItem(5);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabListe_cmd), QCoreApplication::translate("MainWindow", "Liste des commandes", nullptr));
        labelIdSuppr->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de commande :", nullptr));
        btnSupprimerConfirm_cmd->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabSupprimer_cmd), QCoreApplication::translate("MainWindow", "Supprimer une commande", nullptr));
        labelIdMod->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de commande :", nullptr));
        groupBox_prefill_cmd->setTitle(QCoreApplication::translate("MainWindow", "Modifier les donn\303\251es", nullptr));
        labelStatutModif->setText(QCoreApplication::translate("MainWindow", "Nouveau statut :", nullptr));
        comboStatutModif->setItemText(0, QCoreApplication::translate("MainWindow", "En attente", nullptr));
        comboStatutModif->setItemText(1, QCoreApplication::translate("MainWindow", "Confirm\303\251e", nullptr));
        comboStatutModif->setItemText(2, QCoreApplication::translate("MainWindow", "Exp\303\251di\303\251e", nullptr));
        comboStatutModif->setItemText(3, QCoreApplication::translate("MainWindow", "Livr\303\251e", nullptr));

        labelQuantiteModif->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 :", nullptr));
        btnModifierConfirm_cmd->setText(QCoreApplication::translate("MainWindow", "Mettre \303\240 jour", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabModifier_cmd), QCoreApplication::translate("MainWindow", "Modifier une commande", nullptr));
        groupRecherche->setTitle(QCoreApplication::translate("MainWindow", "Recherche", nullptr));
        labelSearchDate->setText(QCoreApplication::translate("MainWindow", "Rechercher par date :", nullptr));
        labelSearchDateTo->setText(QCoreApplication::translate("MainWindow", "\303\240", nullptr));
        labelSearchFournisseur->setText(QCoreApplication::translate("MainWindow", "Rechercher par fournisseur :", nullptr));
        lineSearchFournisseur->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom du fournisseur", nullptr));
        labelSearchClient->setText(QCoreApplication::translate("MainWindow", "Rechercher par client :", nullptr));
        lineSearchClient->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom du client", nullptr));
        groupTri->setTitle(QCoreApplication::translate("MainWindow", "Tri", nullptr));
        labelTriPar->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboTriPar->setItemText(0, QCoreApplication::translate("MainWindow", "Montant (Croissant)", nullptr));
        comboTriPar->setItemText(1, QCoreApplication::translate("MainWindow", "Montant (D\303\251croissant)", nullptr));
        comboTriPar->setItemText(2, QCoreApplication::translate("MainWindow", "Date (R\303\251cente)", nullptr));
        comboTriPar->setItemText(3, QCoreApplication::translate("MainWindow", "Date (Ancien)", nullptr));
        comboTriPar->setItemText(4, QCoreApplication::translate("MainWindow", "Statut", nullptr));
        comboTriPar->setItemText(5, QCoreApplication::translate("MainWindow", "Client", nullptr));

        btnAppliquerRecherche->setText(QCoreApplication::translate("MainWindow", "Appliquer", nullptr));
        btnReinitialiserRecherche->setText(QCoreApplication::translate("MainWindow", "R\303\251initialiser", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableResultatsRecherche->horizontalHeaderItem(0);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableResultatsRecherche->horizontalHeaderItem(1);
        ___qtablewidgetitem31->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableResultatsRecherche->horizontalHeaderItem(2);
        ___qtablewidgetitem32->setText(QCoreApplication::translate("MainWindow", "Fournisseur", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableResultatsRecherche->horizontalHeaderItem(3);
        ___qtablewidgetitem33->setText(QCoreApplication::translate("MainWindow", "Montant", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableResultatsRecherche->horizontalHeaderItem(4);
        ___qtablewidgetitem34->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableResultatsRecherche->horizontalHeaderItem(5);
        ___qtablewidgetitem35->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabRechercheTri), QCoreApplication::translate("MainWindow", "Recherche & Tri", nullptr));
        groupCommandes->setTitle(QCoreApplication::translate("MainWindow", "Commandes", nullptr));
        labelTotalCmd->setText(QCoreApplication::translate("MainWindow", "Total :", nullptr));
        labelEnAttenteCmd->setText(QCoreApplication::translate("MainWindow", "En attente :", nullptr));
        groupRevenue->setTitle(QCoreApplication::translate("MainWindow", "Revenus", nullptr));
        labelRevenuTotal->setText(QCoreApplication::translate("MainWindow", "Total :", nullptr));
        labelMoyenneCmd->setText(QCoreApplication::translate("MainWindow", "Moyenne par commande :", nullptr));
        groupPrixParMois->setTitle(QCoreApplication::translate("MainWindow", "Prix par mois", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tablePrixParMois->horizontalHeaderItem(0);
        ___qtablewidgetitem36->setText(QCoreApplication::translate("MainWindow", "Mois", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tablePrixParMois->horizontalHeaderItem(1);
        ___qtablewidgetitem37->setText(QCoreApplication::translate("MainWindow", "Montant Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tablePrixParMois->horizontalHeaderItem(2);
        ___qtablewidgetitem38->setText(QCoreApplication::translate("MainWindow", "Nombre de commandes", nullptr));
        groupProduitsMostCommandes->setTitle(QCoreApplication::translate("MainWindow", "Produits les plus command\303\251s", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableProduitsMostCommandes->horizontalHeaderItem(0);
        ___qtablewidgetitem39->setText(QCoreApplication::translate("MainWindow", "Produit", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableProduitsMostCommandes->horizontalHeaderItem(1);
        ___qtablewidgetitem40->setText(QCoreApplication::translate("MainWindow", "Quantit\303\251 Totale", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableProduitsMostCommandes->horizontalHeaderItem(2);
        ___qtablewidgetitem41->setText(QCoreApplication::translate("MainWindow", "Nombre de commandes", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableProduitsMostCommandes->horizontalHeaderItem(3);
        ___qtablewidgetitem42->setText(QCoreApplication::translate("MainWindow", "Revenue", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabStatistiques_cmd), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
        groupCalendrier->setTitle(QCoreApplication::translate("MainWindow", "Visualisation des commandes", nullptr));
        labelMoisAnnee->setText(QCoreApplication::translate("MainWindow", "Mois/Ann\303\251e :", nullptr));
        comboMoisCalendrier->setItemText(0, QCoreApplication::translate("MainWindow", "Janvier", nullptr));
        comboMoisCalendrier->setItemText(1, QCoreApplication::translate("MainWindow", "F\303\251vrier", nullptr));
        comboMoisCalendrier->setItemText(2, QCoreApplication::translate("MainWindow", "Mars", nullptr));
        comboMoisCalendrier->setItemText(3, QCoreApplication::translate("MainWindow", "Avril", nullptr));
        comboMoisCalendrier->setItemText(4, QCoreApplication::translate("MainWindow", "Mai", nullptr));
        comboMoisCalendrier->setItemText(5, QCoreApplication::translate("MainWindow", "Juin", nullptr));
        comboMoisCalendrier->setItemText(6, QCoreApplication::translate("MainWindow", "Juillet", nullptr));
        comboMoisCalendrier->setItemText(7, QCoreApplication::translate("MainWindow", "Ao\303\273t", nullptr));
        comboMoisCalendrier->setItemText(8, QCoreApplication::translate("MainWindow", "Septembre", nullptr));
        comboMoisCalendrier->setItemText(9, QCoreApplication::translate("MainWindow", "Octobre", nullptr));
        comboMoisCalendrier->setItemText(10, QCoreApplication::translate("MainWindow", "Novembre", nullptr));
        comboMoisCalendrier->setItemText(11, QCoreApplication::translate("MainWindow", "D\303\251cembre", nullptr));

        btnAfficherCalendrier->setText(QCoreApplication::translate("MainWindow", "Afficher", nullptr));
        groupAlertes->setTitle(QCoreApplication::translate("MainWindow", "Alertes visuelles pour les commandes", nullptr));
        labelAlertesLegend->setText(QCoreApplication::translate("MainWindow", "<b>L\303\251gende :</b><br/>\360\237\224\264 Rouge: En attente<br/>\360\237\237\240 Orange: Confirm\303\251e<br/>\360\237\237\241 Jaune: Exp\303\251di\303\251e<br/>\360\237\237\242 Vert: Livr\303\251e", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabCalendrier), QCoreApplication::translate("MainWindow", "Calendrier", nullptr));
        groupEmailConfig->setTitle(QCoreApplication::translate("MainWindow", "Configuration des notifications par email", nullptr));
        labelEmailDestinataire->setText(QCoreApplication::translate("MainWindow", "Adresse email (destinataire) :", nullptr));
        lineEmailDestinataire->setPlaceholderText(QCoreApplication::translate("MainWindow", "exemple@example.com", nullptr));
        labelEmailCommande->setText(QCoreApplication::translate("MainWindow", "Envoyer email quand :", nullptr));
        comboEmailNotification->setItemText(0, QCoreApplication::translate("MainWindow", "Commande pr\303\252te pour l'envoi", nullptr));
        comboEmailNotification->setItemText(1, QCoreApplication::translate("MainWindow", "Commande confirm\303\251e", nullptr));
        comboEmailNotification->setItemText(2, QCoreApplication::translate("MainWindow", "Commande exp\303\251di\303\251e", nullptr));
        comboEmailNotification->setItemText(3, QCoreApplication::translate("MainWindow", "Commande livr\303\251e", nullptr));

        checkEmailAutomatic->setText(QCoreApplication::translate("MainWindow", "Activer notifications automatiques", nullptr));
        groupEmailManuel->setTitle(QCoreApplication::translate("MainWindow", "Envoi manuel", nullptr));
        labelNumCommandeEmail->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro de commande :", nullptr));
        lineNumCommandeEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le num\303\251ro", nullptr));
        labelMessageEmail->setText(QCoreApplication::translate("MainWindow", "Message personnalis\303\251 :", nullptr));
        btnEnvoyerEmail->setText(QCoreApplication::translate("MainWindow", "Envoyer notification", nullptr));
        groupHistoriqueEmails->setTitle(QCoreApplication::translate("MainWindow", "Historique des notifications", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableHistoriqueEmails->horizontalHeaderItem(0);
        ___qtablewidgetitem43->setText(QCoreApplication::translate("MainWindow", "Num\303\251ro Commande", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableHistoriqueEmails->horizontalHeaderItem(1);
        ___qtablewidgetitem44->setText(QCoreApplication::translate("MainWindow", "Destinataire", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableHistoriqueEmails->horizontalHeaderItem(2);
        ___qtablewidgetitem45->setText(QCoreApplication::translate("MainWindow", "Date/Heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableHistoriqueEmails->horizontalHeaderItem(3);
        ___qtablewidgetitem46->setText(QCoreApplication::translate("MainWindow", "Statut", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabNotifications), QCoreApplication::translate("MainWindow", "Notifications", nullptr));
        groupExportOptions_cmd->setTitle(QCoreApplication::translate("MainWindow", "Options d'export", nullptr));
        checkExportTous->setText(QCoreApplication::translate("MainWindow", "Exporter tous", nullptr));
        checkExportFiltre->setText(QCoreApplication::translate("MainWindow", "Exporter filtr\303\251s", nullptr));
        groupIdExport_cmd->setTitle(QCoreApplication::translate("MainWindow", "Param\303\250tres d'export", nullptr));
        btnExportListeComplete_cmd->setText(QCoreApplication::translate("MainWindow", "Liste compl\303\250te", nullptr));
        btnExportRapport->setText(QCoreApplication::translate("MainWindow", "Rapport", nullptr));
        btnExportFiche->setText(QCoreApplication::translate("MainWindow", "Fiche commande", nullptr));
        groupMessagesExport_cmd->setTitle(QCoreApplication::translate("MainWindow", "Messages", nullptr));
        tabWidget_cmd->setTabText(tabWidget_cmd->indexOf(tabExportPdf_cmd), QCoreApplication::translate("MainWindow", "Export PDF", nullptr));
        MachineWidget->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion Machines", nullptr));
        groupBoxSearch->setTitle(QCoreApplication::translate("MainWindow", "\360\237\224\215 Recherche et Filtres", nullptr));
        label10->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        lineEditSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom, r\303\251f\303\251rence\342\200\246", nullptr));
        label11->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie :", nullptr));
        comboCategory->setItemText(0, QCoreApplication::translate("MainWindow", "Toutes", nullptr));
        comboCategory->setItemText(1, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboCategory->setItemText(2, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboCategory->setItemText(3, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboCategory->setItemText(4, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboCategory->setItemText(5, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        label12->setText(QCoreApplication::translate("MainWindow", "\303\211tat :", nullptr));
        comboState->setItemText(0, QCoreApplication::translate("MainWindow", "Tous", nullptr));
        comboState->setItemText(1, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboState->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboState->setItemText(3, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboState->setItemText(4, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        label13->setText(QCoreApplication::translate("MainWindow", "Localisation :", nullptr));
        lineEditLocation->setPlaceholderText(QCoreApplication::translate("MainWindow", "Atelier, Ligne\342\200\246", nullptr));
        btnApplyFilter->setText(QCoreApplication::translate("MainWindow", "\342\234\205 Appliquer", nullptr));
        groupBoxSort->setTitle(QCoreApplication::translate("MainWindow", "\360\237\223\212 Tri", nullptr));
        label14->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboSortBy->setItemText(0, QCoreApplication::translate("MainWindow", "Nom", nullptr));
        comboSortBy->setItemText(1, QCoreApplication::translate("MainWindow", "Date d'achat", nullptr));
        comboSortBy->setItemText(2, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        comboSortBy->setItemText(3, QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        comboSortBy->setItemText(4, QCoreApplication::translate("MainWindow", "Localisation", nullptr));

        radioCroissant->setText(QCoreApplication::translate("MainWindow", "\342\254\206\357\270\217 Croissant", nullptr));
        radioDecroissant->setText(QCoreApplication::translate("MainWindow", "\342\254\207\357\270\217 D\303\251croissant", nullptr));
        btnScanQR->setText(QCoreApplication::translate("MainWindow", "\360\237\223\267 Scanner QR Code", nullptr));
        labelAdd->setText(QCoreApplication::translate("MainWindow", "<h2>Ajouter une nouvelle machine</h2>", nullptr));
        label15->setText(QCoreApplication::translate("MainWindow", "ID Machine *", nullptr));
        editAddId->setPlaceholderText(QCoreApplication::translate("MainWindow", "MCH-XXX", nullptr));
        label16->setText(QCoreApplication::translate("MainWindow", "Nom *", nullptr));
        editAddNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom de la machine", nullptr));
        label17->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie *", nullptr));
        comboAddCategorie->setItemText(0, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboAddCategorie->setItemText(1, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboAddCategorie->setItemText(2, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboAddCategorie->setItemText(3, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboAddCategorie->setItemText(4, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        label18->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        editAddReference->setPlaceholderText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        label19->setText(QCoreApplication::translate("MainWindow", "Date d'achat", nullptr));
        label20->setText(QCoreApplication::translate("MainWindow", "\303\211tat *", nullptr));
        comboAddEtat->setItemText(0, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboAddEtat->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboAddEtat->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboAddEtat->setItemText(3, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        label21->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        editAddLocalisation->setPlaceholderText(QCoreApplication::translate("MainWindow", "Atelier, Ligne...", nullptr));
        btnConfirmerAjouter_mach->setText(QCoreApplication::translate("MainWindow", "\342\234\223 Confirmer l'ajout", nullptr));
        btnConfirmerAjouter_mach->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #6FA66F; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerAjouter_mach->setText(QCoreApplication::translate("MainWindow", "\342\234\227 Annuler", nullptr));
        btnAnnulerAjouter_mach->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabAjouter_mach), QCoreApplication::translate("MainWindow", "Ajouter Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableMachines->horizontalHeaderItem(0);
        ___qtablewidgetitem47->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = tableMachines->horizontalHeaderItem(1);
        ___qtablewidgetitem48->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = tableMachines->horizontalHeaderItem(2);
        ___qtablewidgetitem49->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = tableMachines->horizontalHeaderItem(3);
        ___qtablewidgetitem50->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = tableMachines->horizontalHeaderItem(4);
        ___qtablewidgetitem51->setText(QCoreApplication::translate("MainWindow", "Date Achat", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = tableMachines->horizontalHeaderItem(5);
        ___qtablewidgetitem52->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = tableMachines->horizontalHeaderItem(6);
        ___qtablewidgetitem53->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        btnExportPDF_mach->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter PDF", nullptr));
        btnRefresh->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 Actualiser", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabListe_mach), QCoreApplication::translate("MainWindow", "Liste des Machines", nullptr));
        label22->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 S\303\251lectionnez une machine dans \"Liste des Machines\", puis confirmez la suppression. Cette action est irr\303\251versible.", nullptr));
        label22->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { background-color: #FDECEA; color: #C62828; border-radius: 4px; padding: 10px; }", nullptr));
        grpMachineASupprimer->setTitle(QCoreApplication::translate("MainWindow", "Machine S\303\251lectionn\303\251e", nullptr));
        lblSupprimerNom_mach->setText(QCoreApplication::translate("MainWindow", "Aucune machine s\303\251lectionn\303\251e", nullptr));
        lblSupprimerDetails_mach->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        btnConfirmerSupprimer_mach->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221 Confirmer la suppression", nullptr));
        btnConfirmerSupprimer_mach->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #C97A7A; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerSupprimer_mach->setText(QCoreApplication::translate("MainWindow", "\342\234\227 Annuler", nullptr));
        btnAnnulerSupprimer_mach->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabSupprimer_mach), QCoreApplication::translate("MainWindow", "Supprimer Machine", nullptr));
        label23->setText(QCoreApplication::translate("MainWindow", "\342\204\271\357\270\217 S\303\251lectionnez une machine dans \"Liste des Machines\" puis modifiez ses informations ci-dessous.", nullptr));
        label23->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { background-color: #EAF0EA; color: #3D4F3C; border-radius: 4px; padding: 8px; }", nullptr));
        grpFormModifier_mach->setTitle(QCoreApplication::translate("MainWindow", "Modifier la Machine S\303\251lectionn\303\251e", nullptr));
        label24->setText(QCoreApplication::translate("MainWindow", "ID Machine", nullptr));
        label25->setText(QCoreApplication::translate("MainWindow", "Nom *", nullptr));
        label26->setText(QCoreApplication::translate("MainWindow", "Cat\303\251gorie *", nullptr));
        comboModifierCategorie->setItemText(0, QCoreApplication::translate("MainWindow", "Presse", nullptr));
        comboModifierCategorie->setItemText(1, QCoreApplication::translate("MainWindow", "Moteur", nullptr));
        comboModifierCategorie->setItemText(2, QCoreApplication::translate("MainWindow", "Filtre", nullptr));
        comboModifierCategorie->setItemText(3, QCoreApplication::translate("MainWindow", "Capteur", nullptr));
        comboModifierCategorie->setItemText(4, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        label27->setText(QCoreApplication::translate("MainWindow", "R\303\251f\303\251rence", nullptr));
        label28->setText(QCoreApplication::translate("MainWindow", "Date d'achat", nullptr));
        label29->setText(QCoreApplication::translate("MainWindow", "\303\211tat *", nullptr));
        comboModifierEtat->setItemText(0, QCoreApplication::translate("MainWindow", "En service", nullptr));
        comboModifierEtat->setItemText(1, QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        comboModifierEtat->setItemText(2, QCoreApplication::translate("MainWindow", "Panne", nullptr));
        comboModifierEtat->setItemText(3, QCoreApplication::translate("MainWindow", "Hors service", nullptr));

        label30->setText(QCoreApplication::translate("MainWindow", "Localisation", nullptr));
        btnConfirmerModifier_mach->setText(QCoreApplication::translate("MainWindow", "\342\234\223 Confirmer la modification", nullptr));
        btnConfirmerModifier_mach->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #D4A520; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerModifier_mach->setText(QCoreApplication::translate("MainWindow", "\342\234\227 Annuler", nullptr));
        btnAnnulerModifier_mach->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabModifier_mach), QCoreApplication::translate("MainWindow", "Modifier Machine", nullptr));
        label31->setText(QCoreApplication::translate("MainWindow", "\360\237\224\247 S\303\251lectionnez une machine et d\303\251crivez la panne constat\303\251e.", nullptr));
        label31->setStyleSheet(QCoreApplication::translate("MainWindow", "QLabel { background-color: #FFF3E0; color: #E65100; border-radius: 4px; padding: 8px; }", nullptr));
        grpPanne->setTitle(QCoreApplication::translate("MainWindow", "D\303\251tails de la Panne", nullptr));
        label32->setText(QCoreApplication::translate("MainWindow", "Machine *", nullptr));
        label33->setText(QCoreApplication::translate("MainWindow", "Date de panne", nullptr));
        label34->setText(QCoreApplication::translate("MainWindow", "Type de panne *", nullptr));
        comboTypePanne->setItemText(0, QCoreApplication::translate("MainWindow", "M\303\251canique", nullptr));
        comboTypePanne->setItemText(1, QCoreApplication::translate("MainWindow", "\303\211lectrique", nullptr));
        comboTypePanne->setItemText(2, QCoreApplication::translate("MainWindow", "Hydraulique", nullptr));
        comboTypePanne->setItemText(3, QCoreApplication::translate("MainWindow", "Logicielle", nullptr));
        comboTypePanne->setItemText(4, QCoreApplication::translate("MainWindow", "Autre", nullptr));

        label35->setText(QCoreApplication::translate("MainWindow", "Gravit\303\251 *", nullptr));
        comboGravite->setItemText(0, QCoreApplication::translate("MainWindow", "Mineure", nullptr));
        comboGravite->setItemText(1, QCoreApplication::translate("MainWindow", "Moyenne", nullptr));
        comboGravite->setItemText(2, QCoreApplication::translate("MainWindow", "Majeure", nullptr));
        comboGravite->setItemText(3, QCoreApplication::translate("MainWindow", "Critique", nullptr));

        label36->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        txtDescriptionPanne->setPlaceholderText(QCoreApplication::translate("MainWindow", "D\303\251crivez la panne...", nullptr));
        btnSignalerPanne->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 Signaler la panne", nullptr));
        btnSignalerPanne->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #FF8F00; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        btnAnnulerPanne->setText(QCoreApplication::translate("MainWindow", "\342\234\227 Annuler", nullptr));
        btnAnnulerPanne->setStyleSheet(QCoreApplication::translate("MainWindow", "QPushButton { background-color: #A0A0A0; color: white; border-radius: 5px; font-weight: bold; }", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabPanne), QCoreApplication::translate("MainWindow", "Signaler Panne", nullptr));
        QTableWidgetItem *___qtablewidgetitem54 = tableHistorique->horizontalHeaderItem(0);
        ___qtablewidgetitem54->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem55 = tableHistorique->horizontalHeaderItem(1);
        ___qtablewidgetitem55->setText(QCoreApplication::translate("MainWindow", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem56 = tableHistorique->horizontalHeaderItem(2);
        ___qtablewidgetitem56->setText(QCoreApplication::translate("MainWindow", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem57 = tableHistorique->horizontalHeaderItem(3);
        ___qtablewidgetitem57->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem58 = tableHistorique->horizontalHeaderItem(4);
        ___qtablewidgetitem58->setText(QCoreApplication::translate("MainWindow", "Description", nullptr));
        QTableWidgetItem *___qtablewidgetitem59 = tableHistorique->horizontalHeaderItem(5);
        ___qtablewidgetitem59->setText(QCoreApplication::translate("MainWindow", "Technicien", nullptr));
        btnExportHistorique->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 Exporter Historique", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabHistorique), QCoreApplication::translate("MainWindow", "Historique Interventions", nullptr));
        grpStatsResume->setTitle(QCoreApplication::translate("MainWindow", "R\303\251sum\303\251", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Total Machines", nullptr));
        lblStatsTotalMachines->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox1->setTitle(QCoreApplication::translate("MainWindow", "En Service", nullptr));
        lblStatsEnService->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblStatsEnService->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #4CAF50;", nullptr));
        groupBox2->setTitle(QCoreApplication::translate("MainWindow", "En Panne", nullptr));
        lblStatsEnPanne->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblStatsEnPanne->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #F44336;", nullptr));
        groupBox3->setTitle(QCoreApplication::translate("MainWindow", "En Maintenance", nullptr));
        lblStatsMaintenance->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lblStatsMaintenance->setStyleSheet(QCoreApplication::translate("MainWindow", "color: #FF9800;", nullptr));
        btnExportStats->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Exporter Statistiques", nullptr));
        tabWidget_mach->setTabText(tabWidget_mach->indexOf(tabStatistiques_mach), QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
