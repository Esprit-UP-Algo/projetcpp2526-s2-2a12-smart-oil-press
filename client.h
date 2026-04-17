#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QList>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegularExpression>

// ==============================
// STRUCTURES DE DONNEES METIER
// ==============================

struct ClientStatsSummary
{
    int total        = 0;
    int actifs       = 0;
    int inactifs     = 0;
    int enAttente    = 0;
    int particuliers = 0;
    int entreprises  = 0;
    double caTotal   = 0.0;
    int nbCommandes  = 0;
};

struct ClientCommandeInfo
{
    int     idCommande   = 0;
    QString libelle;
    QString etat;
    double  montant      = 0.0;
    QString dateArrivage;
    QString dateSortie;
};

struct ClientAlerteInfo
{
    int     idClient  = 0;
    QString nomClient;
    int     nbRetards = 0;
};

struct ClientInfosDetail
{
    int     nbCommandes      = 0;
    double  montantTotal     = 0.0;
    double  montantMoyen     = 0.0;
    int     nbRetards        = 0;
    int     nbAnnulees       = 0;
    QString derniereCommande;
};

class Client {
    int     id;
    QString nom;
    QString type;
    QString tel;
    QString email;
    QString statut;

public:
    Client() {}
    Client(int id, QString nom, QString type, QString tel, QString email, QString statut);

    // Getters
    int     getId()     { return id; }
    QString getNom()    { return nom; }
    QString getType()   { return type; }
    QString getTel()    { return tel; }
    QString getEmail()  { return email; }
    QString getStatut() { return statut; }

    // Setters
    void setId(int i)         { id = i; }
    void setNom(QString n)    { nom = n; }
    void setType(QString t)   { type = t; }
    void setTel(QString t)    { tel = t; }
    void setEmail(QString e)  { email = e; }
    void setStatut(QString s) { statut = s; }

    static bool valider(const QString &nom,
                        const QString &tel,
                        const QString &email,
                        QString *errorMessage = nullptr);

    bool ajouter(QString *errorMessage = nullptr);
    bool supprimer(int id);
    bool modifier(QString *errorMessage = nullptr);
    QSqlQueryModel* afficher();

    // ==============================
    // METHODES STATISTIQUES METIER
    // ==============================
    static bool getStatsSummary(ClientStatsSummary *outStats, QString *errorMessage = nullptr);
    static bool getClientInfos(int idClient, ClientInfosDetail *outInfos, QString *errorMessage = nullptr);
    static bool getAlertes(QList<ClientAlerteInfo> *outAlertes, QString *errorMessage = nullptr);
    static bool getCommandesDuClient(int idClient, QList<ClientCommandeInfo> *outList, QString *errorMessage = nullptr);
};

#endif // CLIENT_H
