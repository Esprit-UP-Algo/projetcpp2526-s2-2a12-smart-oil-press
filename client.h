#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client {
    int     id;
    QString nom;
    QString type;
    QString tel;
    QString email;
    QString statut;
    QString adresse;

public:
    Client() : id(0) {}
    Client(int id, QString nom, QString type, QString tel,
           QString email, QString statut, QString adresse = "");

    // Getters
    int     getId()      { return id; }
    QString getNom()     { return nom; }
    QString getType()    { return type; }
    QString getTel()     { return tel; }
    QString getEmail()   { return email; }
    QString getStatut()  { return statut; }
    QString getAdresse() { return adresse; }

    // Setters
    void setId(int i)          { id = i; }
    void setNom(QString n)     { nom = n; }
    void setType(QString t)    { type = t; }
    void setTel(QString t)     { tel = t; }
    void setEmail(QString e)   { email = e; }
    void setStatut(QString s)  { statut = s; }
    void setAdresse(QString a) { adresse = a; }

    // CRUD — ALL SQL queries go here, never behind buttons
    bool            ajouter();
    bool            supprimer(int id);
    bool            modifier();
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString nom, QString type, QString statut);
};

#endif // CLIENT_H
