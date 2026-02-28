#ifndef CCOMMANDE_H
#define CCOMMANDE_H

#include <QString>
#include <QDate>
#include <QVector>
#include <QMap>
#include <QPair>

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

    // Setters
    void setIdCommande(int id);
    void setLibelle(const QString &libelle);
    void setDateArrivage(const QDate &date);
    void setDateSortie(const QDate &date);
    void setEtat(const QString &etat);
    void setQuantite(int quantite);
    void setMontantTotal(double montant);
    void setIdClient(int id);

    // CRUD statiques
    static bool ajouter(const Ccommande &cmd);
    static bool supprimer(int id);
    static bool modifier(int id, const Ccommande &newCmd);
    static Ccommande getById(int id);
    static QVector<Ccommande> getAll();

    // Recherche avancée (avec nom client et fournisseur)
    static QVector<Ccommande> rechercher(const QDate &debut, const QDate &fin,
                                         const QString &etat, int idClient,
                                         const QString &nomClient = QString(),
                                         const QString &fournisseur = QString());

    // Utilitaires clients
    static bool clientExists(int idClient);
    static QVector<QPair<int,QString>> getClientList();
    static QVector<int> getClientIds();

    // Statistiques
    static int getTotalCommandes();
    static double getMontantTotalGlobal();
    static double getMoyenneMontant();
    static QMap<QString, double> getMontantParMois();
    static QMap<QString, int> getNbCommandesParMois();
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

#endif // CCOMMANDE_H