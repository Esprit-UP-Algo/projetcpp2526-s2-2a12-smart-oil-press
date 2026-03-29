#include "commande_widget.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

Ccommande::Ccommande()
    : m_idCommande(0)
    , m_quantite(0)
    , m_montantTotal(0.0)
    , m_idClient(0)
{
}

Ccommande::Ccommande(int idCommande, const QString &libelle, const QDate &dateArrivage,
                     const QDate &dateSortie, const QString &etat, int quantite,
                     double montantTotal, int idClient)
    : m_idCommande(idCommande)
    , m_libelle(libelle)
    , m_dateArrivage(dateArrivage)
    , m_dateSortie(dateSortie)
    , m_etat(etat)
    , m_quantite(quantite)
    , m_montantTotal(montantTotal)
    , m_idClient(idClient)
{
}

// Getters
int Ccommande::getIdCommande() const { return m_idCommande; }
QString Ccommande::getLibelle() const { return m_libelle; }
QDate Ccommande::getDateArrivage() const { return m_dateArrivage; }
QDate Ccommande::getDateSortie() const { return m_dateSortie; }
QString Ccommande::getEtat() const { return m_etat; }
int Ccommande::getQuantite() const { return m_quantite; }
double Ccommande::getMontantTotal() const { return m_montantTotal; }
int Ccommande::getIdClient() const { return m_idClient; }

// Setters
void Ccommande::setIdCommande(int id) { m_idCommande = id; }
void Ccommande::setLibelle(const QString &libelle) { m_libelle = libelle; }
void Ccommande::setDateArrivage(const QDate &date) { m_dateArrivage = date; }
void Ccommande::setDateSortie(const QDate &date) { m_dateSortie = date; }
void Ccommande::setEtat(const QString &etat) { m_etat = etat; }
void Ccommande::setQuantite(int quantite) { m_quantite = quantite; }
void Ccommande::setMontantTotal(double montant) { m_montantTotal = montant; }
void Ccommande::setIdClient(int id) { m_idClient = id; }

bool Ccommande::ajouter(const Ccommande &cmd)
{
    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM COMMANDE WHERE ID_COMMANDE = :id");
    checkQuery.bindValue(":id", cmd.getIdCommande());
    if (!checkQuery.exec() || !checkQuery.next()) {
        qDebug() << "Erreur vérification ID:" << checkQuery.lastError().text();
        return false;
    }

    bool exists = (checkQuery.value(0).toInt() > 0);
    QSqlQuery query;

    if (exists) {
        query.prepare("UPDATE COMMANDE SET "
                      "LIBELLE = :libelle, "
                      "DATE_ARRIVAGE = TO_DATE(:dateArr, 'YYYY-MM-DD'), "
                      "DATE_SORTIE = TO_DATE(:dateSort, 'YYYY-MM-DD'), "
                      "ETAT = :etat, "
                      "QUANTITE = :qte, "
                      "MONTANT_TOTAL = :montant, "
                      "ID_CLIENT = :idClient "
                      "WHERE ID_COMMANDE = :id");
    } else {
        query.prepare("INSERT INTO COMMANDE "
                      "(ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, QUANTITE, MONTANT_TOTAL, ID_CLIENT) "
                      "VALUES (:id, :libelle, TO_DATE(:dateArr,'YYYY-MM-DD'), TO_DATE(:dateSort,'YYYY-MM-DD'), :etat, :qte, :montant, :idClient)");
    }

    query.bindValue(":id",       cmd.getIdCommande());
    query.bindValue(":libelle",  cmd.getLibelle());
    query.bindValue(":dateArr",  cmd.getDateArrivage().toString("yyyy-MM-dd"));
    query.bindValue(":dateSort", cmd.getDateSortie().toString("yyyy-MM-dd"));
    query.bindValue(":etat",     cmd.getEtat());
    query.bindValue(":qte",      cmd.getQuantite());
    query.bindValue(":montant",  cmd.getMontantTotal());
    query.bindValue(":idClient", cmd.getIdClient());

    if (!query.exec()) {
        qDebug() << "Erreur ajouter/modifier commande:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Ccommande::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM COMMANDE WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Erreur suppression commande:" << query.lastError().text();
        return false;
    }
    return true;
}

bool Ccommande::modifier(int id, const Ccommande &newCmd)
{
    QSqlQuery query;
    query.prepare("UPDATE COMMANDE SET "
                  "LIBELLE = :libelle, "
                  "DATE_ARRIVAGE = TO_DATE(:dateArr, 'YYYY-MM-DD'), "
                  "DATE_SORTIE = TO_DATE(:dateSort, 'YYYY-MM-DD'), "
                  "ETAT = :etat, "
                  "QUANTITE = :qte, "
                  "MONTANT_TOTAL = :montant, "
                  "ID_CLIENT = :idClient "
                  "WHERE ID_COMMANDE = :id");

    query.bindValue(":libelle",  newCmd.getLibelle());
    query.bindValue(":dateArr",  newCmd.getDateArrivage().toString("yyyy-MM-dd"));
    query.bindValue(":dateSort", newCmd.getDateSortie().toString("yyyy-MM-dd"));
    query.bindValue(":etat",     newCmd.getEtat());
    query.bindValue(":qte",      newCmd.getQuantite());
    query.bindValue(":montant",  newCmd.getMontantTotal());
    query.bindValue(":idClient", newCmd.getIdClient());
    query.bindValue(":id",       id);

    if (!query.exec()) {
        qDebug() << "Erreur modification commande:" << query.lastError().text();
        return false;
    }
    return true;
}

Ccommande Ccommande::getById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                  "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM COMMANDE WHERE ID_COMMANDE = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        return Ccommande(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        );
    }
    return Ccommande();
}

QVector<Ccommande> Ccommande::getAll()
{
    QVector<Ccommande> list;
    QSqlQuery query("SELECT ID_COMMANDE, LIBELLE, DATE_ARRIVAGE, DATE_SORTIE, ETAT, "
                    "QUANTITE, MONTANT_TOTAL, ID_CLIENT FROM COMMANDE ORDER BY ID_COMMANDE");
    while (query.next()) {
        list.append(Ccommande(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toDate(),
            query.value(3).toDate(),
            query.value(4).toString(),
            query.value(5).toInt(),
            query.value(6).toDouble(),
            query.value(7).toInt()
        ));
    }
    return list;
}

QVector<QPair<int, QString>> Ccommande::getClientList()
{
    QVector<QPair<int, QString>> clients;
    QSqlQuery q;
    if (!q.exec("SELECT ID_CLIENT, NOM_CLIENT FROM CLIENT ORDER BY NOM_CLIENT")) {
        qDebug() << "Erreur getClientList:" << q.lastError().text();
        return clients;
    }
    while (q.next()) {
        clients.append(qMakePair(q.value(0).toInt(), q.value(1).toString()));
    }
    return clients;
}

bool Ccommande::clientExists(int idClient)
{
    QSqlQuery q;
    q.prepare("SELECT COUNT(*) FROM CLIENT WHERE ID_CLIENT = :id");
    q.bindValue(":id", idClient);
    if (q.exec() && q.next()) {
        return q.value(0).toInt() > 0;
    }
    return false;
}

QVector<int> Ccommande::getClientIds()
{
    QVector<int> ids;
    QSqlQuery q("SELECT ID_CLIENT FROM CLIENT ORDER BY ID_CLIENT");
    while (q.next()) {
        ids.append(q.value(0).toInt());
    }
    return ids;
}

QVector<Ccommande> Ccommande::rechercher(const QDate &debut, const QDate &fin,
                                         const QString &etat, int idClient,
                                         const QString &nomClient,
                                         const QString &fournisseur)
{
    QVector<Ccommande> results;
    QString sql = "SELECT c.ID_COMMANDE, c.LIBELLE, c.DATE_ARRIVAGE, c.DATE_SORTIE, "
                  "c.ETAT, c.QUANTITE, c.MONTANT_TOTAL, c.ID_CLIENT "
                  "FROM COMMANDE c";

    if (!nomClient.isEmpty()) {
        sql += " JOIN CLIENT cl ON c.ID_CLIENT = cl.ID_CLIENT";
    }

    sql += " WHERE 1=1";

    if (debut.isValid())  sql += " AND c.DATE_ARRIVAGE >= TO_DATE(:debut, 'YYYY-MM-DD')";
    if (fin.isValid())    sql += " AND c.DATE_ARRIVAGE <= TO_DATE(:fin, 'YYYY-MM-DD')";
    if (!etat.isEmpty())  sql += " AND c.ETAT = :etat";
    if (idClient > 0)     sql += " AND c.ID_CLIENT = :idClient";
    if (!nomClient.isEmpty()) sql += " AND cl.NOM_CLIENT LIKE :nomClient";
    if (!fournisseur.isEmpty()) sql += " AND c.LIBELLE LIKE :fournisseur";

    QSqlQuery query;
    query.prepare(sql);

    if (debut.isValid())  query.bindValue(":debut",    debut.toString("yyyy-MM-dd"));
    if (fin.isValid())    query.bindValue(":fin",      fin.toString("yyyy-MM-dd"));
    if (!etat.isEmpty())  query.bindValue(":etat",     etat);
    if (idClient > 0)     query.bindValue(":idClient", idClient);
    if (!nomClient.isEmpty()) query.bindValue(":nomClient", "%" + nomClient + "%");
    if (!fournisseur.isEmpty()) query.bindValue(":fournisseur", "%" + fournisseur + "%");

    if (query.exec()) {
        while (query.next()) {
            results.append(Ccommande(
                query.value(0).toInt(),
                query.value(1).toString(),
                query.value(2).toDate(),
                query.value(3).toDate(),
                query.value(4).toString(),
                query.value(5).toInt(),
                query.value(6).toDouble(),
                query.value(7).toInt()
            ));
        }
    } else {
        qDebug() << "Erreur recherche avancée:" << query.lastError().text();
    }
    return results;
}

int Ccommande::getTotalCommandes()
{
    QSqlQuery query("SELECT COUNT(*) FROM COMMANDE");
    if (query.next()) return query.value(0).toInt();
    return 0;
}

double Ccommande::getMontantTotalGlobal()
{
    QSqlQuery query("SELECT SUM(MONTANT_TOTAL) FROM COMMANDE");
    if (query.next()) return query.value(0).toDouble();
    return 0.0;
}

double Ccommande::getMoyenneMontant()
{
    QSqlQuery query("SELECT AVG(MONTANT_TOTAL) FROM COMMANDE");
    if (query.next()) return query.value(0).toDouble();
    return 0.0;
}

QMap<QString, double> Ccommande::getMontantParMois()
{
    QMap<QString, double> moisMap;
    QSqlQuery query("SELECT TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') AS MOIS, SUM(MONTANT_TOTAL) "
                    "FROM COMMANDE GROUP BY TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') ORDER BY MOIS");
    while (query.next()) {
        moisMap.insert(query.value(0).toString(), query.value(1).toDouble());
    }
    return moisMap;
}

QMap<QString, int> Ccommande::getNbCommandesParMois()
{
    QMap<QString, int> moisMap;
    QSqlQuery query("SELECT TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') AS MOIS, COUNT(*) "
                    "FROM COMMANDE GROUP BY TO_CHAR(DATE_ARRIVAGE, 'YYYY-MM') ORDER BY MOIS");
    while (query.next()) {
        moisMap.insert(query.value(0).toString(), query.value(1).toInt());
    }
    return moisMap;
}

QMap<QString, int> Ccommande::getNbCommandesParEtat()
{
    QMap<QString, int> result;
    QSqlQuery query("SELECT ETAT, COUNT(*) FROM COMMANDE GROUP BY ETAT");
    while (query.next()) {
        result.insert(query.value(0).toString(), query.value(1).toInt());
    }
    return result;
}

QVector<QPair<QString, int>> Ccommande::getProduitsPlusCommandes(int limit)
{
    QVector<QPair<QString, int>> produits;
    QSqlQuery query;
    query.prepare("SELECT LIBELLE, SUM(QUANTITE) AS QTE_TOTALE FROM COMMANDE "
                  "GROUP BY LIBELLE ORDER BY QTE_TOTALE DESC");
    if (!query.exec()) {
        qDebug() << "Erreur produits plus commandés:" << query.lastError().text();
        return produits;
    }
    int count = 0;
    while (query.next() && count < limit) {
        produits.append(qMakePair(query.value(0).toString(), query.value(1).toInt()));
        ++count;
    }
    return produits;
}

QVector<QPair<QString, double>> Ccommande::getProduitsPlusRentables(int limit)
{
    QVector<QPair<QString, double>> produits;
    QSqlQuery query;
    query.prepare("SELECT LIBELLE, SUM(MONTANT_TOTAL) AS MONTANT_TOTAL FROM COMMANDE "
                  "GROUP BY LIBELLE ORDER BY MONTANT_TOTAL DESC");
    if (!query.exec()) {
        qDebug() << "Erreur produits plus rentables:" << query.lastError().text();
        return produits;
    }
    int count = 0;
    while (query.next() && count < limit) {
        produits.append(qMakePair(query.value(0).toString(), query.value(1).toDouble()));
        ++count;
    }
    return produits;
}
