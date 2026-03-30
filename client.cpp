#include "client.h"

Client::Client(int id, QString nom, QString type, QString tel, QString email, QString statut)
{
    this->id     = id;
    this->nom    = nom;
    this->type   = type;
    this->tel    = tel;
    this->email  = email;
    this->statut = statut;
}

// CREATE
bool Client::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (ID, NOM, TYPE, TEL, EMAIL, STATUT) "
                  "VALUES (:id, :nom, :type, :tel, :email, :statut)");
    query.bindValue(":id",     id);
    query.bindValue(":nom",    nom);
    query.bindValue(":type",   type);
    query.bindValue(":tel",    tel);
    query.bindValue(":email",  email);
    query.bindValue(":statut", statut);
    return query.exec();
}

// DELETE
bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE ID = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// UPDATE
bool Client::modifier()
{
    QSqlQuery query;
    query.prepare("UPDATE CLIENT SET NOM=:nom, TYPE=:type, TEL=:tel, "
                  "EMAIL=:email, STATUT=:statut WHERE ID=:id");
    query.bindValue(":nom",    nom);
    query.bindValue(":type",   type);
    query.bindValue(":tel",    tel);
    query.bindValue(":email",  email);
    query.bindValue(":statut", statut);
    query.bindValue(":id",     id);
    return query.exec();
}

// READ
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM CLIENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Statut"));
    return model;
}
