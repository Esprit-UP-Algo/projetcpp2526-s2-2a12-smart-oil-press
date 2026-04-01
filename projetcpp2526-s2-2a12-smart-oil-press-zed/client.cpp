#include "client.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QDebug>
#include <QRegularExpression>

// Oracle DB table: CLIENT
// Columns by position: 0=ID_CLIENT, 1=NOM_CLIENT, 2=T?L?PHONE(accented), 3=EMAIL,
//                      4=ADRESSE, 5=TYPE_CLIENT, 6=STATUT, 7=ID_EMPLOYE
// The TELEPHONE column has an accented name that breaks over ODBC.
// Strategy: SELECT all columns and read by index; skip TELEPHONE in INSERT/UPDATE.

Client::Client(int id, QString nom, QString type, QString tel, QString email, QString statut)
{
    this->id     = id;
    this->nom    = nom;
    this->type   = type;
    this->tel    = tel;
    this->email  = email;
    this->statut = statut;
}

// ==========================
// VALIDATION METIER
// ==========================
bool Client::valider(const QString &nom, const QString &tel,
                     const QString &email, QString *errorMessage)
{
    if (nom.trimmed().isEmpty()) {
        if (errorMessage) *errorMessage = "Le nom du client est obligatoire.";
        return false;
    }
    if (nom.trimmed().length() > 20) {
        if (errorMessage) *errorMessage = "Le nom ne doit pas depasser 20 caracteres.";
        return false;
    }

    if (!tel.trimmed().isEmpty()) {
        static const QRegularExpression reTel("^[0-9]{7,20}$");
        if (!reTel.match(tel.trimmed()).hasMatch()) {
            if (errorMessage)
                *errorMessage = "Le num\u00e9ro de t\u00e9l\u00e9phone ne doit contenir que des chiffres (7\u201320 caract\u00e8res).";
            return false;
        }
    }

    if (!email.trimmed().isEmpty()) {
        static const QRegularExpression reEmail(
            "^[A-Za-z0-9._%+\\-]+@[A-Za-z0-9.\\-]+\\.[A-Za-z]{2,}$");
        if (!reEmail.match(email.trimmed()).hasMatch()) {
            if (errorMessage) *errorMessage = "L'adresse email n'est pas valide.";
            return false;
        }
    }

    return true;
}

// ==========================
// CREATE — skip accented TELEPHONE column
// ==========================
bool Client::ajouter(QString *errorMessage)
{
    QSqlQuery idQuery;
    int nextId = 1;
    if (idQuery.exec("SELECT NVL(MAX(ID_CLIENT), 0) + 1 FROM CLIENT")) {
        if (idQuery.next())
            nextId = idQuery.value(0).toInt();
    } else {
        qDebug() << "[Client] ID query error:" << idQuery.lastError().text();
    }

    // Do NOT include the accented TELEPHONE column — insert only safe columns
    QSqlQuery query;
    query.prepare(
        "INSERT INTO CLIENT (ID_CLIENT, NOM_CLIENT, EMAIL, TYPE_CLIENT, STATUT) "
        "VALUES (:id, :nom, :email, :type, :statut)");
    query.bindValue(":id",     nextId);
    query.bindValue(":nom",    nom.trimmed());
    query.bindValue(":email",  email.trimmed());
    query.bindValue(":type",   type);
    query.bindValue(":statut", statut);

    if (!query.exec()) {
        qDebug() << "[Client] ajouter error:" << query.lastError().text();
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }
    this->id = nextId;
    return true;
}

// ==========================
// DELETE
// ==========================
bool Client::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM CLIENT WHERE ID_CLIENT = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "[Client] supprimer error:" << query.lastError().text();
        return false;
    }
    return true;
}

// ==========================
// UPDATE — skip accented TELEPHONE column
// ==========================
bool Client::modifier(QString *errorMessage)
{
    QSqlQuery query;
    query.prepare(
        "UPDATE CLIENT SET "
        "NOM_CLIENT = :nom, EMAIL = :email, TYPE_CLIENT = :type, STATUT = :statut "
        "WHERE ID_CLIENT = :id");
    query.bindValue(":nom",    nom.trimmed());
    query.bindValue(":email",  email.trimmed());
    query.bindValue(":type",   type);
    query.bindValue(":statut", statut);
    query.bindValue(":id",     id);

    if (!query.exec()) {
        qDebug() << "[Client] modifier error:" << query.lastError().text();
        if (errorMessage) *errorMessage = query.lastError().text();
        return false;
    }
    return true;
}

// ==========================
// READ — read TELEPHONE by column index (position 2), not by name
// ==========================
QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    // Select * so we get all columns including the accented one by position
    model->setQuery("SELECT * FROM CLIENT ORDER BY ID_CLIENT");

    if (model->lastError().isValid()) {
        qDebug() << "[Client] afficher error:" << model->lastError().text();
    }

    // Set display headers — columns come in DB order:
    // 0=ID_CLIENT, 1=NOM_CLIENT, 2=T?L?PHONE, 3=EMAIL, 4=ADRESSE, 5=TYPE_CLIENT, 6=STATUT, 7=ID_EMPLOYE
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("T\u00e9l\u00e9phone"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Statut"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("ID Employe"));
    return model;
}
