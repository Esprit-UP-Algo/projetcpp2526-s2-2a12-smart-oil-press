#ifndef COMMANDE_H
#define COMMANDE_H

#include <QDate>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QString>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Ccommande
{
public:
    Ccommande();
    Ccommande(int idCommande, const QString &libelle, const QDate &dateArrivage,
              const QDate &dateSortie, const QString &etat, int quantite,
              double montantTotal, int idClient);

    // Getters
    int getIdCommande() const;
    QString getLibelle() const;
    QDate getDateArrivage() const;
    QDate getDateSortie() const;
    QString getEtat() const;
    int getQuantite() const;
    double getMontantTotal() const;
    int getIdClient() const;
    double getSeulTemperature() const;
    float getTemperature() const;
    float getHumidite() const;
    QString getAlerte() const;
    QString getConditions() const;

    // Setters
    void setIdCommande(int id);
    void setLibelle(const QString &libelle);
    void setDateArrivage(const QDate &date);
    void setDateSortie(const QDate &date);
    void setEtat(const QString &etat);
    void setQuantite(int quantite);
    void setMontantTotal(double montant);
    void setIdClient(int id);
    void setSeulTemperature(double seul);
    void setTemperature(float temp);
    void setHumidite(float humid);
    void setAlerte(const QString &alerte);
    void setConditions(const QString &conditions);

    // CRUD Operations
    static bool ajouter(const Ccommande &cmd);
    static bool supprimer(int id);
    static bool modifier(int id, const Ccommande &newCmd);
    static Ccommande getById(int id);
    static QVector<Ccommande> getAll();

    // Recherche avancée
    static QVector<Ccommande> rechercher(const QDate &debut, const QDate &fin,
                                         const QString &etat, int idClient,
                                         const QString &nomClient = QString(),
                                         const QString &fournisseur = QString());

    // Clients
    static bool clientExists(int idClient);
    static QVector<QPair<int, QString>> getClientList();
    static QVector<int> getClientIds();

    // Arduino threshold management
    static double getSeulByCommandeId(int idCommande, bool *ok = nullptr);
    static bool setSeulByCommandeId(int idCommande, double seul);
    static QVector<int> getAllCommandeIds();

    // Statistiques
    static int getTotalCommandes();
    static double getMontantTotalGlobal();
    static double getMoyenneMontant();
    static QMap<QString, double> getMontantParMois();
    static QMap<QString, int> getNbCommandesParMois();
    static QMap<QString, int> getNbCommandesParEtat();
    static QVector<QPair<QString, int>> getProduitsPlusCommandes(int limit = 10);
    static QVector<QPair<QString, double>> getProduitsPlusRentables(int limit = 10);

    static QString normalizeEtatKey(const QString &etat);
    static QStringList getEtatCandidates(const QString &etatInput);
    
    // ✅ Enregistrer données capteur pour une commande spécifique
    static bool enregistrerDonneesCapteur(int idCommande, float temperature, 
                                          float humidite, const QString &alerte,
                                          const QString &conditions);

private:
    int m_idCommande;
    QString m_libelle;
    QDate m_dateArrivage;
    QDate m_dateSortie;
    QString m_etat;
    int m_quantite;
    double m_montantTotal;
    int m_idClient;
    double m_seulTemperature;
    float m_temperature;
    float m_humidite;
    QString m_alerte;
    QString m_conditions;
};

#endif // COMMANDE_H