#ifndef EMAIL_SENDER_H
#define EMAIL_SENDER_H

#include <QObject>
#include <QString>
#include "smtpclient.h"
#include "mimemessage.h"
#include "mimetext.h"
#include "emailaddress.h"

class EmailSender : public QObject
{
    Q_OBJECT
public:
    explicit EmailSender(QObject *parent = nullptr);

    // Envoie le code de reinitialisation
    void sendResetCode(const QString &toEmail, const QString &code);

signals:
    void emailSent(bool success, const QString &msg);
};

#endif // EMAIL_SENDER_H
