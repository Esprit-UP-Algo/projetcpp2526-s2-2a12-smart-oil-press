#include "team_repository.h"

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

Team::Team()
    : m_id(0), m_name(""), m_specialty(""), m_members(0), m_status(""), m_rate("") {}

Team::Team(int id, const QString &name, const QString &specialty, int members,
           const QString &status, const QString &rate)
    : m_id(id), m_name(name), m_specialty(specialty), m_members(members),
      m_status(status), m_rate(rate) {}

int Team::getId() const { return m_id; }
QString Team::getName() const { return m_name; }
QString Team::getSpecialty() const { return m_specialty; }
int Team::getMembers() const { return m_members; }
QString Team::getStatus() const { return m_status; }
QString Team::getRate() const { return m_rate; }
void Team::setId(int id) { m_id = id; }
void Team::setName(const QString &name) { m_name = name; }
void Team::setSpecialty(const QString &specialty) { m_specialty = specialty; }
void Team::setMembers(int members) { m_members = members; }
void Team::setStatus(const QString &status) { m_status = status; }
void Team::setRate(const QString &rate) { m_rate = rate; }

namespace {
QString g_teamRepoLastError;
constexpr const char *kTeamRepoConnectionName = "equipe_module_connection";

QSqlDatabase teamRepoDatabaseHandle()
{
    if (QSqlDatabase::contains(kTeamRepoConnectionName)) {
        return QSqlDatabase::database(kTeamRepoConnectionName);
    }

    return QSqlDatabase::addDatabase("QODBC", kTeamRepoConnectionName);
}

bool ensureConnectionConfig(QSqlDatabase &db)
{
    if (!db.isValid()) {
        g_teamRepoLastError = "Invalid database handle";
        return false;
    }

    db.setDatabaseName("Source_Projet2A");
    db.setUserName("SMARTOIL");
    db.setPassword("1234");
    return true;
}

bool ensureOpenDb(QSqlDatabase &db)
{
    if (!initializeTeamRepositoryConnection()) {
        return false;
    }

    db = QSqlDatabase::database(kTeamRepoConnectionName);
    if (!db.isValid() || !db.isOpen()) {
        g_teamRepoLastError = "Database not connected";
        return false;
    }
    return true;
}
}

bool initializeTeamRepositoryConnection()
{
    QSqlDatabase db = teamRepoDatabaseHandle();
    if (!ensureConnectionConfig(db)) {
        return false;
    }

    if (db.isOpen()) {
        g_teamRepoLastError.clear();
        return true;
    }

    if (!db.open()) {
        g_teamRepoLastError = db.lastError().text();
        qDebug() << "Erreur de connexion:" << g_teamRepoLastError;
        return false;
    }

    g_teamRepoLastError.clear();
    qDebug() << "Connexion a la base de donnees reussie";
    return true;
}

void closeTeamRepositoryConnection()
{
    if (!QSqlDatabase::contains(kTeamRepoConnectionName)) {
        return;
    }

    QSqlDatabase db = QSqlDatabase::database(kTeamRepoConnectionName);
    if (db.isOpen()) {
        db.close();
    }
}

bool insertTeamRecord(const Team &team)
{
    QSqlDatabase db;
    if (!ensureOpenDb(db)) {
        return false;
    }

    QSqlQuery query(db);
    query.prepare("INSERT INTO EQUIPE (ID_EQUIPE, NOM_EQUIPE, SPECIALITE, NBRE_MEMBRES, ETAT, RATE) "
                  "VALUES (:id, :nom, :spec, :membres, :etat, :rate)");

    query.bindValue(":id", team.getId());
    query.bindValue(":nom", team.getName());
    query.bindValue(":spec", team.getSpecialty());
    query.bindValue(":membres", team.getMembers());
    query.bindValue(":etat", team.getStatus());
    query.bindValue(":rate", team.getRate());

    if (!query.exec()) {
        g_teamRepoLastError = query.lastError().text();
        return false;
    }

    g_teamRepoLastError.clear();
    return true;
}

QVector<Team> getAllTeamsRecord()
{
    QVector<Team> result;
    QSqlDatabase db;
    if (!ensureOpenDb(db)) {
        return result;
    }

    QSqlQuery query(db);
    query.prepare("SELECT ID_EQUIPE, NOM_EQUIPE, SPECIALITE, NBRE_MEMBRES, ETAT, RATE FROM EQUIPE ORDER BY ID_EQUIPE");

    if (!query.exec()) {
        g_teamRepoLastError = query.lastError().text();
        return result;
    }

    while (query.next()) {
        result.append(Team(
            query.value(0).toInt(),
            query.value(1).toString(),
            query.value(2).toString(),
            query.value(3).toInt(),
            query.value(4).toString(),
            query.value(5).toString()
        ));
    }

    g_teamRepoLastError.clear();
    return result;
}

bool updateTeamRecord(const Team &team)
{
    QSqlDatabase db;
    if (!ensureOpenDb(db)) {
        return false;
    }

    QSqlQuery query(db);
    query.prepare("UPDATE EQUIPE SET NOM_EQUIPE = :nom, SPECIALITE = :spec, NBRE_MEMBRES = :membres, ETAT = :etat, RATE = :rate "
                  "WHERE ID_EQUIPE = :id");

    query.bindValue(":nom", team.getName());
    query.bindValue(":spec", team.getSpecialty());
    query.bindValue(":membres", team.getMembers());
    query.bindValue(":etat", team.getStatus());
    query.bindValue(":rate", team.getRate());
    query.bindValue(":id", team.getId());

    if (!query.exec()) {
        g_teamRepoLastError = query.lastError().text();
        return false;
    }

    g_teamRepoLastError.clear();
    return true;
}

bool deleteTeamRecord(int id)
{
    QSqlDatabase db;
    if (!ensureOpenDb(db)) {
        return false;
    }

    QSqlQuery query(db);
    query.prepare("DELETE FROM EQUIPE WHERE ID_EQUIPE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        g_teamRepoLastError = query.lastError().text();
        return false;
    }

    g_teamRepoLastError.clear();
    return true;
}

bool teamNameExists(const QString &name, int excludeId)
{
    QSqlDatabase db;
    if (!ensureOpenDb(db)) {
        return false;
    }

    const QString trimmedName = name.trimmed();
    if (trimmedName.isEmpty()) {
        g_teamRepoLastError.clear();
        return false;
    }

    QSqlQuery query(db);
    if (excludeId >= 0) {
        query.prepare("SELECT 1 FROM EQUIPE WHERE UPPER(TRIM(NOM_EQUIPE)) = UPPER(TRIM(:name)) AND ID_EQUIPE <> :excludeId");
        query.bindValue(":excludeId", excludeId);
    } else {
        query.prepare("SELECT 1 FROM EQUIPE WHERE UPPER(TRIM(NOM_EQUIPE)) = UPPER(TRIM(:name))");
    }
    query.bindValue(":name", trimmedName);

    if (!query.exec()) {
        g_teamRepoLastError = query.lastError().text();
        return false;
    }

    g_teamRepoLastError.clear();
    return query.next();
}

QString teamRepoLastError()
{
    return g_teamRepoLastError;
}
