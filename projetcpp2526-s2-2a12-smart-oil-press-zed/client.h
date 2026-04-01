#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QRegularExpression>

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

    // Validation metier — retourne true si valide, sinon errorMessage est rempli
    static bool valider(const QString &nom,
                        const QString &tel,
                        const QString &email,
                        QString *errorMessage = nullptr);

    // CRUD methods — all SQL lives here, never behind buttons
    bool ajouter(QString *errorMessage = nullptr);
    bool supprimer(int id);
    bool modifier(QString *errorMessage = nullptr);
    QSqlQueryModel* afficher();
};

#endif // CLIENT_H
