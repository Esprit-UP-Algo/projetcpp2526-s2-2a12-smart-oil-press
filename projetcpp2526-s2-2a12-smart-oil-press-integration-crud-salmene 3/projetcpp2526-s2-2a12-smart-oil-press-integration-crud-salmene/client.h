#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client {
    int id;
    QString nom;
    QString type;
    QString tel;
    QString email;
    QString statut;

public:
    Client(){}
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

    // CRUD methods (queries go HERE, not behind buttons!)
    bool ajouter();
    bool supprimer(int id);
    bool modifier();
    QSqlQueryModel* afficher();
};

#endif // CLIENT_H
