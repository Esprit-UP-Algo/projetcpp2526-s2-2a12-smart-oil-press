#ifndef EMAILSENDER_H
#define EMAILSENDER_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QHostAddress>

class EmailSender : public QObject
{
    Q_OBJECT
public:
    explicit EmailSender(QObject *parent = nullptr);
    bool sendEmail(const QString &to, const QString &subject, const QString &body,
                   const QString &from, const QString &smtpServer, int port,
                   const QString &username, const QString &password);

signals:
    void finished(bool success, const QString &errorMessage);

private slots:
    void onConnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *socket;
    QString m_to, m_subject, m_body, m_from, m_username, m_password;
    enum State { Init, Helo, AuthLogin, User, Pass, MailFrom, RcptTo, Data, Body, Quit };
    State state;
    QString response;
    bool sendCommand(const QString &cmd);
    void processResponse(const QString &line);
    QString encodeBase64(const QString &text);
};

#endif // EMAILSENDER_H