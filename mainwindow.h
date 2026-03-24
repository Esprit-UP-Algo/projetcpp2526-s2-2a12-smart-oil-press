#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QFrame>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// ── QtCharts ──
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QAreaSeries>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>

#include "connection.h"

// ==============================
// CLASS Ccommande
// ==============================
class Ccommande
{
public:
    Ccommande();
    Ccommande(int idCommande, const QString &libelle, const QDate &dateArrivage,
              const QDate &dateSortie, const QString &etat, int quantite,
              double montantTotal, int idClient);

    int getIdCommande() const;
    QString getLibelle() const;
    QDate getDateArrivage() const;
    QDate getDateSortie() const;
    QString getEtat() const;
    int getQuantite() const;
    double getMontantTotal() const;
    int getIdClient() const;

    void setIdCommande(int id);
    void setLibelle(const QString &libelle);
    void setDateArrivage(const QDate &date);
    void setDateSortie(const QDate &date);
    void setEtat(const QString &etat);
    void setQuantite(int quantite);
    void setMontantTotal(double montant);
    void setIdClient(int id);

    static bool ajouter(const Ccommande &cmd);
    static bool supprimer(int id);
    static bool modifier(int id, const Ccommande &newCmd);
    static Ccommande getById(int id);
    static QVector<Ccommande> getAll();

    static QVector<Ccommande> rechercher(const QDate &debut, const QDate &fin,
                                         const QString &etat, int idClient,
                                         const QString &nomClient = QString(),
                                         const QString &fournisseur = QString());

    static bool clientExists(int idClient);
    static QVector<QPair<int,QString>> getClientList();
    static QVector<int> getClientIds();

    static int getTotalCommandes();
    static double getMontantTotalGlobal();
    static double getMoyenneMontant();
    static QMap<QString, double> getMontantParMois();
    static QMap<QString, int> getNbCommandesParMois();
    static QMap<QString, int> getNbCommandesParEtat();
    static QVector<QPair<QString, int>> getProduitsPlusCommandes(int limit = 10);
    static QVector<QPair<QString, double>> getProduitsPlusRentables(int limit = 10);

private:
    int m_idCommande;
    QString m_libelle;
    QDate m_dateArrivage;
    QDate m_dateSortie;
    QString m_etat;
    int m_quantite;
    double m_montantTotal;
    int m_idClient;
};

// ==============================
// CLASS MainWindow
// ==============================
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnCommande_clicked();
    void on_btnEquipe_clicked();
    void on_btnClient_clicked();
    void on_btnLaboratoire_clicked();
    void on_btnFournisseur_clicked();
    void on_btnMachine_clicked();

    void onAjouterCommande();
    void onSupprimerCommande();
    void onModifierCommande();

    void onApplySearch();
    void onResetSearch();
    void refreshTableCommandes();
    void onApplySorting();

    void updateStatistics();

    // QCharts
    void buildChartMontantParMois();
    void buildChartNbCommandesParMois();
    void buildChartRepartitionEtat();
    void buildChartTop10Produits();
    void refreshAllCharts();

    void onDisplayCalendar();
    void refreshCalendarAlerts();
    void onSendEmailNotification();
    void exportPDF();
    void onEnableEmailNotification(bool enabled);
    void onResetAjouter();

    // Réponse de l'API Brevo
    void onBrevoReplyFinished(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;
    void loadStylesheet();

    QVector<Ccommande> m_lastSearchResults;
    bool m_searchActive = false;
    QVector<Ccommande> m_currentDisplayedOrders;

    // Pointeurs vers les QChartView
    QChartView *m_chartViewMontant  = nullptr;
    QChartView *m_chartViewNbCmds   = nullptr;
    QChartView *m_chartViewEtat     = nullptr;
    QChartView *m_chartViewProduits = nullptr;

    // Gestionnaire réseau
    QNetworkAccessManager *m_networkManager;

    void setupConnections();
    void loadClients();
    void showMessage(const QString &title, const QString &message);

    QVector<Ccommande> sortCommands(const QVector<Ccommande>& list, int sortIndex);
    void applySortingAndDisplay(const QVector<Ccommande>& source);

    QString buildHtmlListeComplete(const QVector<Ccommande>& orders);
    QString buildHtmlRapport(const QVector<Ccommande>& orders);
    QString buildHtmlFicheCommande(const Ccommande& cmd);

    void updateCalendarColors(int month, int year);
    QColor getColorForEtat(const QString &etat) const;
    int getPriorityForEtat(const QString &etat) const;

    // Envoi d'email via Brevo
    void sendEmailViaBrevo(const QString &to, const QString &subject, const QString &htmlBody);
};

#endif // MAINWINDOW_H