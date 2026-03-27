#ifndef TEAM_REPOSITORY_H
#define TEAM_REPOSITORY_H

#include <QString>
#include <QVector>

class Team {
private:
    int m_id;
    QString m_name;
    QString m_specialty;
    int m_members;
    QString m_status;
    QString m_rate;

public:
    Team();
    Team(int id, const QString &name, const QString &specialty, int members,
         const QString &status, const QString &rate);

    int getId() const;
    QString getName() const;
    QString getSpecialty() const;
    int getMembers() const;
    QString getStatus() const;
    QString getRate() const;

    void setId(int id);
    void setName(const QString &name);
    void setSpecialty(const QString &specialty);
    void setMembers(int members);
    void setStatus(const QString &status);
    void setRate(const QString &rate);
};

bool initializeTeamRepositoryConnection();
void closeTeamRepositoryConnection();

bool insertTeamRecord(const Team &team);
QVector<Team> getAllTeamsRecord();
bool updateTeamRecord(const Team &team);
bool deleteTeamRecord(int id);
bool teamNameExists(const QString &name, int excludeId = -1);
QString teamRepoLastError();

#endif // TEAM_REPOSITORY_H
