/********************************************************************************
** Form generated from reading UI file 'commande_widget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDE_WIDGET_H
#define UI_COMMANDE_WIDGET_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *tabAjouter;
    QVBoxLayout *verticalLayout_ajouter;
    QGridLayout *grid_ajouter;
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
    QCheckBox *checkFiltreAttente;
    QCheckBox *checkFiltreConfirmee;
    QCheckBox *checkFiltreExpedie;
    QCheckBox *checkFiltreLivree;
    QSpacerItem *verticalSpacer_sidebar;
    QFrame *mainListe;
    QVBoxLayout *vLayoutMain;
    QTableWidget *tableCommandes;
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
    QLabel *labelStatutModif;
    QComboBox *comboStatutModif;
    QLabel *labelQuantiteModif;
    QSpinBox *spinQuantiteModif;
    QPushButton *btnModifierConfirm;
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
    QWidget *tabStatistiques;
    QVBoxLayout *vertical_statistiques;
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
    QSpacerItem *verticalSpacer_stats;
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
    QWidget *tabExportPdf;
    QVBoxLayout *vertical_export_pdf;
    QGroupBox *groupExportOptions;
    QVBoxLayout *vLayoutExportOptions;
    QCheckBox *checkExportTous;
    QCheckBox *checkExportFiltre;
    QGroupBox *groupIdExport;
    QHBoxLayout *hLayoutIdExport;
    QPushButton *btnExportListeComplete;
    QPushButton *btnExportRapport;
    QPushButton *btnExportFiche;
    QGroupBox *groupMessagesExport;
    QVBoxLayout *vLayoutMessagesExport;
    QLineEdit *lineExportMessages;
    QSpacerItem *verticalSpacer_export;

    void setupUi(QWidget *CommandeWidget)
    {
        if (CommandeWidget->objectName().isEmpty())
            CommandeWidget->setObjectName("CommandeWidget");
        CommandeWidget->setMinimumSize(QSize(600, 400));
        verticalLayout = new QVBoxLayout(CommandeWidget);
        verticalLayout->setObjectName("verticalLayout");
        label = new QLabel(CommandeWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(CommandeWidget);
        tabWidget->setObjectName("tabWidget");
        tabAjouter = new QWidget();
        tabAjouter->setObjectName("tabAjouter");
        verticalLayout_ajouter = new QVBoxLayout(tabAjouter);
        verticalLayout_ajouter->setObjectName("verticalLayout_ajouter");
        grid_ajouter = new QGridLayout();
        grid_ajouter->setObjectName("grid_ajouter");
        labelNumCommande = new QLabel(tabAjouter);
        labelNumCommande->setObjectName("labelNumCommande");

        grid_ajouter->addWidget(labelNumCommande, 0, 0, 1, 1);

        lineNumCommande = new QLineEdit(tabAjouter);
        lineNumCommande->setObjectName("lineNumCommande");

        grid_ajouter->addWidget(lineNumCommande, 0, 1, 1, 1);

        labelClient = new QLabel(tabAjouter);
        labelClient->setObjectName("labelClient");

        grid_ajouter->addWidget(labelClient, 1, 0, 1, 1);

        lineClient = new QLineEdit(tabAjouter);
        lineClient->setObjectName("lineClient");

        grid_ajouter->addWidget(lineClient, 1, 1, 1, 1);

        labelProduit = new QLabel(tabAjouter);
        labelProduit->setObjectName("labelProduit");

        grid_ajouter->addWidget(labelProduit, 2, 0, 1, 1);

        comboProduit = new QComboBox(tabAjouter);
        comboProduit->setObjectName("comboProduit");

        grid_ajouter->addWidget(comboProduit, 2, 1, 1, 1);

        labelQuantite = new QLabel(tabAjouter);
        labelQuantite->setObjectName("labelQuantite");

        grid_ajouter->addWidget(labelQuantite, 3, 0, 1, 1);

        spinQuantite = new QSpinBox(tabAjouter);
        spinQuantite->setObjectName("spinQuantite");

        grid_ajouter->addWidget(spinQuantite, 3, 1, 1, 1);

        labelPrix = new QLabel(tabAjouter);
        labelPrix->setObjectName("labelPrix");

        grid_ajouter->addWidget(labelPrix, 4, 0, 1, 1);

        spinPrix = new QDoubleSpinBox(tabAjouter);
        spinPrix->setObjectName("spinPrix");

        grid_ajouter->addWidget(spinPrix, 4, 1, 1, 1);

        labelStatut = new QLabel(tabAjouter);
        labelStatut->setObjectName("labelStatut");

        grid_ajouter->addWidget(labelStatut, 5, 0, 1, 1);

        comboStatut = new QComboBox(tabAjouter);
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->addItem(QString());
        comboStatut->setObjectName("comboStatut");

        grid_ajouter->addWidget(comboStatut, 5, 1, 1, 1);

        labelDate = new QLabel(tabAjouter);
        labelDate->setObjectName("labelDate");

        grid_ajouter->addWidget(labelDate, 6, 0, 1, 1);

        lineDate = new QLineEdit(tabAjouter);
        lineDate->setObjectName("lineDate");

        grid_ajouter->addWidget(lineDate, 6, 1, 1, 1);


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

        checkFiltreAttente = new QCheckBox(sidebarListe);
        checkFiltreAttente->setObjectName("checkFiltreAttente");

        vLayoutSidebar->addWidget(checkFiltreAttente);

        checkFiltreConfirmee = new QCheckBox(sidebarListe);
        checkFiltreConfirmee->setObjectName("checkFiltreConfirmee");

        vLayoutSidebar->addWidget(checkFiltreConfirmee);

        checkFiltreExpedie = new QCheckBox(sidebarListe);
        checkFiltreExpedie->setObjectName("checkFiltreExpedie");

        vLayoutSidebar->addWidget(checkFiltreExpedie);

        checkFiltreLivree = new QCheckBox(sidebarListe);
        checkFiltreLivree->setObjectName("checkFiltreLivree");

        vLayoutSidebar->addWidget(checkFiltreLivree);

        verticalSpacer_sidebar = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vLayoutSidebar->addItem(verticalSpacer_sidebar);


        hLayout_liste->addWidget(sidebarListe);

        mainListe = new QFrame(tabListe);
        mainListe->setObjectName("mainListe");
        vLayoutMain = new QVBoxLayout(mainListe);
        vLayoutMain->setObjectName("vLayoutMain");
        tableCommandes = new QTableWidget(mainListe);
        if (tableCommandes->columnCount() < 6)
            tableCommandes->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableCommandes->setObjectName("tableCommandes");
        tableCommandes->setAlternatingRowColors(true);

        vLayoutMain->addWidget(tableCommandes);


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
        labelStatutModif = new QLabel(groupBox_prefill);
        labelStatutModif->setObjectName("labelStatutModif");

        gridPrefill->addWidget(labelStatutModif, 0, 0, 1, 1);

        comboStatutModif = new QComboBox(groupBox_prefill);
        comboStatutModif->addItem(QString());
        comboStatutModif->addItem(QString());
        comboStatutModif->addItem(QString());
        comboStatutModif->addItem(QString());
        comboStatutModif->setObjectName("comboStatutModif");

        gridPrefill->addWidget(comboStatutModif, 0, 1, 1, 1);

        labelQuantiteModif = new QLabel(groupBox_prefill);
        labelQuantiteModif->setObjectName("labelQuantiteModif");

        gridPrefill->addWidget(labelQuantiteModif, 1, 0, 1, 1);

        spinQuantiteModif = new QSpinBox(groupBox_prefill);
        spinQuantiteModif->setObjectName("spinQuantiteModif");

        gridPrefill->addWidget(spinQuantiteModif, 1, 1, 1, 1);


        vertical_modifier->addWidget(groupBox_prefill);

        btnModifierConfirm = new QPushButton(tabModifier);
        btnModifierConfirm->setObjectName("btnModifierConfirm");

        vertical_modifier->addWidget(btnModifierConfirm);

        tabWidget->addTab(tabModifier, QString());
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableResultatsRecherche->setHorizontalHeaderItem(5, __qtablewidgetitem11);
        tableResultatsRecherche->setObjectName("tableResultatsRecherche");
        tableResultatsRecherche->setAlternatingRowColors(true);

        vertical_recherche_tri->addWidget(tableResultatsRecherche);

        tabWidget->addTab(tabRechercheTri, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        vertical_statistiques = new QVBoxLayout(tabStatistiques);
        vertical_statistiques->setObjectName("vertical_statistiques");
        groupCommandes = new QGroupBox(tabStatistiques);
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


        vertical_statistiques->addWidget(groupCommandes);

        groupRevenue = new QGroupBox(tabStatistiques);
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


        vertical_statistiques->addWidget(groupRevenue);

        groupPrixParMois = new QGroupBox(tabStatistiques);
        groupPrixParMois->setObjectName("groupPrixParMois");
        vLayoutPrixMois = new QVBoxLayout(groupPrixParMois);
        vLayoutPrixMois->setObjectName("vLayoutPrixMois");
        tablePrixParMois = new QTableWidget(groupPrixParMois);
        if (tablePrixParMois->columnCount() < 3)
            tablePrixParMois->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tablePrixParMois->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tablePrixParMois->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tablePrixParMois->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        tablePrixParMois->setObjectName("tablePrixParMois");
        tablePrixParMois->setAlternatingRowColors(true);

        vLayoutPrixMois->addWidget(tablePrixParMois);


        vertical_statistiques->addWidget(groupPrixParMois);

        groupProduitsMostCommandes = new QGroupBox(tabStatistiques);
        groupProduitsMostCommandes->setObjectName("groupProduitsMostCommandes");
        vLayoutProduitsMost = new QVBoxLayout(groupProduitsMostCommandes);
        vLayoutProduitsMost->setObjectName("vLayoutProduitsMost");
        tableProduitsMostCommandes = new QTableWidget(groupProduitsMostCommandes);
        if (tableProduitsMostCommandes->columnCount() < 4)
            tableProduitsMostCommandes->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableProduitsMostCommandes->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        tableProduitsMostCommandes->setObjectName("tableProduitsMostCommandes");
        tableProduitsMostCommandes->setAlternatingRowColors(true);

        vLayoutProduitsMost->addWidget(tableProduitsMostCommandes);


        vertical_statistiques->addWidget(groupProduitsMostCommandes);

        verticalSpacer_stats = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_statistiques->addItem(verticalSpacer_stats);

        tabWidget->addTab(tabStatistiques, QString());
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

        tabWidget->addTab(tabCalendrier, QString());
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
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableHistoriqueEmails->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        tableHistoriqueEmails->setObjectName("tableHistoriqueEmails");
        tableHistoriqueEmails->setAlternatingRowColors(true);

        vLayoutHistoriqueEmails->addWidget(tableHistoriqueEmails);


        vertical_notifications->addWidget(groupHistoriqueEmails);

        verticalSpacer_notifications = new QSpacerItem(0, 0, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        vertical_notifications->addItem(verticalSpacer_notifications);

        tabWidget->addTab(tabNotifications, QString());
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

        btnExportRapport = new QPushButton(groupIdExport);
        btnExportRapport->setObjectName("btnExportRapport");

        hLayoutIdExport->addWidget(btnExportRapport);

        btnExportFiche = new QPushButton(groupIdExport);
        btnExportFiche->setObjectName("btnExportFiche");

        hLayoutIdExport->addWidget(btnExportFiche);


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


        retranslateUi(CommandeWidget);

        QMetaObject::connectSlotsByName(CommandeWidget);
    } // setupUi

    void retranslateUi(QWidget *CommandeWidget)
    {
        label->setText(QCoreApplication::translate("CommandeWidget", "GESTION DES COMMANDES", nullptr));
        labelNumCommande->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro de commande :", nullptr));
        labelClient->setText(QCoreApplication::translate("CommandeWidget", "Client :", nullptr));
        labelProduit->setText(QCoreApplication::translate("CommandeWidget", "Produit :", nullptr));
        labelQuantite->setText(QCoreApplication::translate("CommandeWidget", "Quantit\303\251 :", nullptr));
        labelPrix->setText(QCoreApplication::translate("CommandeWidget", "Prix unitaire :", nullptr));
        labelStatut->setText(QCoreApplication::translate("CommandeWidget", "Statut :", nullptr));
        comboStatut->setItemText(0, QCoreApplication::translate("CommandeWidget", "En attente", nullptr));
        comboStatut->setItemText(1, QCoreApplication::translate("CommandeWidget", "Confirm\303\251e", nullptr));
        comboStatut->setItemText(2, QCoreApplication::translate("CommandeWidget", "Exp\303\251di\303\251e", nullptr));
        comboStatut->setItemText(3, QCoreApplication::translate("CommandeWidget", "Livr\303\251e", nullptr));

        labelDate->setText(QCoreApplication::translate("CommandeWidget", "Date de commande :", nullptr));
        btnAjouter->setText(QCoreApplication::translate("CommandeWidget", "Ajouter", nullptr));
        btnResetAjouter->setText(QCoreApplication::translate("CommandeWidget", "R\303\251initialiser", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAjouter), QCoreApplication::translate("CommandeWidget", "Ajouter une commande", nullptr));
        labelFiltres->setText(QCoreApplication::translate("CommandeWidget", "Filtres :", nullptr));
        labelFiltres->setStyleSheet(QCoreApplication::translate("CommandeWidget", "font-weight: bold;", nullptr));
        checkFiltreTous->setText(QCoreApplication::translate("CommandeWidget", "Tous", nullptr));
        checkFiltreAttente->setText(QCoreApplication::translate("CommandeWidget", "En attente", nullptr));
        checkFiltreConfirmee->setText(QCoreApplication::translate("CommandeWidget", "Confirm\303\251e", nullptr));
        checkFiltreExpedie->setText(QCoreApplication::translate("CommandeWidget", "Exp\303\251di\303\251e", nullptr));
        checkFiltreLivree->setText(QCoreApplication::translate("CommandeWidget", "Livr\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableCommandes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableCommandes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CommandeWidget", "Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableCommandes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CommandeWidget", "Produit", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableCommandes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CommandeWidget", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableCommandes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CommandeWidget", "Statut", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableCommandes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("CommandeWidget", "Date", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabListe), QCoreApplication::translate("CommandeWidget", "Liste des commandes", nullptr));
        labelIdSuppr->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro de commande :", nullptr));
        btnSupprimerConfirm->setText(QCoreApplication::translate("CommandeWidget", "Supprimer", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabSupprimer), QCoreApplication::translate("CommandeWidget", "Supprimer une commande", nullptr));
        labelIdMod->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro de commande :", nullptr));
        groupBox_prefill->setTitle(QCoreApplication::translate("CommandeWidget", "Modifier les donn\303\251es", nullptr));
        labelStatutModif->setText(QCoreApplication::translate("CommandeWidget", "Nouveau statut :", nullptr));
        comboStatutModif->setItemText(0, QCoreApplication::translate("CommandeWidget", "En attente", nullptr));
        comboStatutModif->setItemText(1, QCoreApplication::translate("CommandeWidget", "Confirm\303\251e", nullptr));
        comboStatutModif->setItemText(2, QCoreApplication::translate("CommandeWidget", "Exp\303\251di\303\251e", nullptr));
        comboStatutModif->setItemText(3, QCoreApplication::translate("CommandeWidget", "Livr\303\251e", nullptr));

        labelQuantiteModif->setText(QCoreApplication::translate("CommandeWidget", "Quantit\303\251 :", nullptr));
        btnModifierConfirm->setText(QCoreApplication::translate("CommandeWidget", "Mettre \303\240 jour", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabModifier), QCoreApplication::translate("CommandeWidget", "Modifier une commande", nullptr));
        groupRecherche->setTitle(QCoreApplication::translate("CommandeWidget", "Recherche", nullptr));
        labelSearchDate->setText(QCoreApplication::translate("CommandeWidget", "Rechercher par date :", nullptr));
        labelSearchDateTo->setText(QCoreApplication::translate("CommandeWidget", "\303\240", nullptr));
        labelSearchFournisseur->setText(QCoreApplication::translate("CommandeWidget", "Rechercher par fournisseur :", nullptr));
        lineSearchFournisseur->setPlaceholderText(QCoreApplication::translate("CommandeWidget", "Entrez le nom du fournisseur", nullptr));
        labelSearchClient->setText(QCoreApplication::translate("CommandeWidget", "Rechercher par client :", nullptr));
        lineSearchClient->setPlaceholderText(QCoreApplication::translate("CommandeWidget", "Entrez le nom du client", nullptr));
        groupTri->setTitle(QCoreApplication::translate("CommandeWidget", "Tri", nullptr));
        labelTriPar->setText(QCoreApplication::translate("CommandeWidget", "Trier par :", nullptr));
        comboTriPar->setItemText(0, QCoreApplication::translate("CommandeWidget", "Montant (Croissant)", nullptr));
        comboTriPar->setItemText(1, QCoreApplication::translate("CommandeWidget", "Montant (D\303\251croissant)", nullptr));
        comboTriPar->setItemText(2, QCoreApplication::translate("CommandeWidget", "Date (R\303\251cente)", nullptr));
        comboTriPar->setItemText(3, QCoreApplication::translate("CommandeWidget", "Date (Ancien)", nullptr));
        comboTriPar->setItemText(4, QCoreApplication::translate("CommandeWidget", "Statut", nullptr));
        comboTriPar->setItemText(5, QCoreApplication::translate("CommandeWidget", "Client", nullptr));

        btnAppliquerRecherche->setText(QCoreApplication::translate("CommandeWidget", "Appliquer", nullptr));
        btnReinitialiserRecherche->setText(QCoreApplication::translate("CommandeWidget", "R\303\251initialiser", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableResultatsRecherche->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableResultatsRecherche->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("CommandeWidget", "Client", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableResultatsRecherche->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("CommandeWidget", "Fournisseur", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableResultatsRecherche->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("CommandeWidget", "Montant", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableResultatsRecherche->horizontalHeaderItem(4);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("CommandeWidget", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableResultatsRecherche->horizontalHeaderItem(5);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("CommandeWidget", "Statut", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRechercheTri), QCoreApplication::translate("CommandeWidget", "Recherche & Tri", nullptr));
        groupCommandes->setTitle(QCoreApplication::translate("CommandeWidget", "Commandes", nullptr));
        labelTotalCmd->setText(QCoreApplication::translate("CommandeWidget", "Total :", nullptr));
        labelEnAttenteCmd->setText(QCoreApplication::translate("CommandeWidget", "En attente :", nullptr));
        groupRevenue->setTitle(QCoreApplication::translate("CommandeWidget", "Revenus", nullptr));
        labelRevenuTotal->setText(QCoreApplication::translate("CommandeWidget", "Total :", nullptr));
        labelMoyenneCmd->setText(QCoreApplication::translate("CommandeWidget", "Moyenne par commande :", nullptr));
        groupPrixParMois->setTitle(QCoreApplication::translate("CommandeWidget", "Prix par mois", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tablePrixParMois->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("CommandeWidget", "Mois", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tablePrixParMois->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("CommandeWidget", "Montant Total", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tablePrixParMois->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("CommandeWidget", "Nombre de commandes", nullptr));
        groupProduitsMostCommandes->setTitle(QCoreApplication::translate("CommandeWidget", "Produits les plus command\303\251s", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableProduitsMostCommandes->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("CommandeWidget", "Produit", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableProduitsMostCommandes->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("CommandeWidget", "Quantit\303\251 Totale", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableProduitsMostCommandes->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("CommandeWidget", "Nombre de commandes", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableProduitsMostCommandes->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("CommandeWidget", "Revenue", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("CommandeWidget", "Statistiques", nullptr));
        groupCalendrier->setTitle(QCoreApplication::translate("CommandeWidget", "Visualisation des commandes", nullptr));
        labelMoisAnnee->setText(QCoreApplication::translate("CommandeWidget", "Mois/Ann\303\251e :", nullptr));
        comboMoisCalendrier->setItemText(0, QCoreApplication::translate("CommandeWidget", "Janvier", nullptr));
        comboMoisCalendrier->setItemText(1, QCoreApplication::translate("CommandeWidget", "F\303\251vrier", nullptr));
        comboMoisCalendrier->setItemText(2, QCoreApplication::translate("CommandeWidget", "Mars", nullptr));
        comboMoisCalendrier->setItemText(3, QCoreApplication::translate("CommandeWidget", "Avril", nullptr));
        comboMoisCalendrier->setItemText(4, QCoreApplication::translate("CommandeWidget", "Mai", nullptr));
        comboMoisCalendrier->setItemText(5, QCoreApplication::translate("CommandeWidget", "Juin", nullptr));
        comboMoisCalendrier->setItemText(6, QCoreApplication::translate("CommandeWidget", "Juillet", nullptr));
        comboMoisCalendrier->setItemText(7, QCoreApplication::translate("CommandeWidget", "Ao\303\273t", nullptr));
        comboMoisCalendrier->setItemText(8, QCoreApplication::translate("CommandeWidget", "Septembre", nullptr));
        comboMoisCalendrier->setItemText(9, QCoreApplication::translate("CommandeWidget", "Octobre", nullptr));
        comboMoisCalendrier->setItemText(10, QCoreApplication::translate("CommandeWidget", "Novembre", nullptr));
        comboMoisCalendrier->setItemText(11, QCoreApplication::translate("CommandeWidget", "D\303\251cembre", nullptr));

        btnAfficherCalendrier->setText(QCoreApplication::translate("CommandeWidget", "Afficher", nullptr));
        groupAlertes->setTitle(QCoreApplication::translate("CommandeWidget", "Alertes visuelles pour les commandes", nullptr));
        labelAlertesLegend->setText(QCoreApplication::translate("CommandeWidget", "<b>L\303\251gende :</b><br/>\360\237\224\264 Rouge: En attente<br/>\360\237\237\240 Orange: Confirm\303\251e<br/>\360\237\237\241 Jaune: Exp\303\251di\303\251e<br/>\360\237\237\242 Vert: Livr\303\251e", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabCalendrier), QCoreApplication::translate("CommandeWidget", "Calendrier", nullptr));
        groupEmailConfig->setTitle(QCoreApplication::translate("CommandeWidget", "Configuration des notifications par email", nullptr));
        labelEmailDestinataire->setText(QCoreApplication::translate("CommandeWidget", "Adresse email (destinataire) :", nullptr));
        lineEmailDestinataire->setPlaceholderText(QCoreApplication::translate("CommandeWidget", "exemple@example.com", nullptr));
        labelEmailCommande->setText(QCoreApplication::translate("CommandeWidget", "Envoyer email quand :", nullptr));
        comboEmailNotification->setItemText(0, QCoreApplication::translate("CommandeWidget", "Commande pr\303\252te pour l'envoi", nullptr));
        comboEmailNotification->setItemText(1, QCoreApplication::translate("CommandeWidget", "Commande confirm\303\251e", nullptr));
        comboEmailNotification->setItemText(2, QCoreApplication::translate("CommandeWidget", "Commande exp\303\251di\303\251e", nullptr));
        comboEmailNotification->setItemText(3, QCoreApplication::translate("CommandeWidget", "Commande livr\303\251e", nullptr));

        checkEmailAutomatic->setText(QCoreApplication::translate("CommandeWidget", "Activer notifications automatiques", nullptr));
        groupEmailManuel->setTitle(QCoreApplication::translate("CommandeWidget", "Envoi manuel", nullptr));
        labelNumCommandeEmail->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro de commande :", nullptr));
        lineNumCommandeEmail->setPlaceholderText(QCoreApplication::translate("CommandeWidget", "Entrez le num\303\251ro", nullptr));
        labelMessageEmail->setText(QCoreApplication::translate("CommandeWidget", "Message personnalis\303\251 :", nullptr));
        btnEnvoyerEmail->setText(QCoreApplication::translate("CommandeWidget", "Envoyer notification", nullptr));
        groupHistoriqueEmails->setTitle(QCoreApplication::translate("CommandeWidget", "Historique des notifications", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableHistoriqueEmails->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("CommandeWidget", "Num\303\251ro Commande", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableHistoriqueEmails->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("CommandeWidget", "Destinataire", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableHistoriqueEmails->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("CommandeWidget", "Date/Heure", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableHistoriqueEmails->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("CommandeWidget", "Statut", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabNotifications), QCoreApplication::translate("CommandeWidget", "Notifications", nullptr));
        groupExportOptions->setTitle(QCoreApplication::translate("CommandeWidget", "Options d'export", nullptr));
        checkExportTous->setText(QCoreApplication::translate("CommandeWidget", "Exporter tous", nullptr));
        checkExportFiltre->setText(QCoreApplication::translate("CommandeWidget", "Exporter filtr\303\251s", nullptr));
        groupIdExport->setTitle(QCoreApplication::translate("CommandeWidget", "Param\303\250tres d'export", nullptr));
        btnExportListeComplete->setText(QCoreApplication::translate("CommandeWidget", "Liste compl\303\250te", nullptr));
        btnExportRapport->setText(QCoreApplication::translate("CommandeWidget", "Rapport", nullptr));
        btnExportFiche->setText(QCoreApplication::translate("CommandeWidget", "Fiche commande", nullptr));
        groupMessagesExport->setTitle(QCoreApplication::translate("CommandeWidget", "Messages", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExportPdf), QCoreApplication::translate("CommandeWidget", "Export PDF", nullptr));
        (void)CommandeWidget;
    } // retranslateUi

};

namespace Ui {
    class CommandeWidget: public Ui_CommandeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDE_WIDGET_H
