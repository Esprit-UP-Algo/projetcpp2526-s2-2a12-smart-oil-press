#include "email_sender.h"
#include "smtpclient.h"
#include "mimemessage.h"
#include "mimetext.h"
#include "emailaddress.h"

#include <QString>
#include <QtGlobal>

namespace {
const QString kSmtpHost = "smtp.gmail.com";
const int kSmtpPort = 587;
}

EmailSender::EmailSender(QObject *parent)
    : QObject(parent)
{
}

void EmailSender::sendResetCode(const QString &toEmail, const QString &code)
{
    const QString recipient = toEmail.trimmed();
    if (recipient.isEmpty()) {
        emit emailSent(false, "Email destinataire invalide.");
        return;
    }

    const QString smtpEmail = qEnvironmentVariable("SMTP_EMAIL").trimmed();
    QString smtpPassword = qEnvironmentVariable("SMTP_PASS").trimmed();
    smtpPassword.remove(' ');

    if (smtpEmail.isEmpty() || smtpPassword.isEmpty()) {
        emit emailSent(false, "Variables d'environnement SMTP_EMAIL / SMTP_PASS manquantes.");
        return;
    }

    MimeMessage message;
    message.setSender(EmailAddress(smtpEmail, "Gestion MDP"));
    message.addRecipient(EmailAddress(recipient));
    message.setSubject("Code de reinitialisation du mot de passe");

    MimeText text;
    text.setText(
        QString(
            "Bonjour,\n\n"
            "Votre code de reinitialisation est : %1\n\n"
            "Ce code expire dans quelques minutes.\n")
            .arg(code));
    message.addPart(&text);

    SmtpClient smtp(kSmtpHost, kSmtpPort, SmtpClient::TlsConnection);

    smtp.connectToHost();
    if (!smtp.waitForReadyConnected(15000)) {
        emit emailSent(
            false,
            QString("Connexion SMTP echouee (code %1): %2")
                .arg(smtp.getResponseCode())
                .arg(smtp.getResponseText()));
        return;
    }

    smtp.login(smtpEmail, smtpPassword);
    if (!smtp.waitForAuthenticated(15000)) {
        emit emailSent(
            false,
            QString("Authentification SMTP echouee (code %1): %2")
                .arg(smtp.getResponseCode())
                .arg(smtp.getResponseText()));
        return;
    }

    smtp.sendMail(message);
    if (!smtp.waitForMailSent(15000)) {
        emit emailSent(
            false,
            QString("Envoi de l'email echoue (code %1): %2")
                .arg(smtp.getResponseCode())
                .arg(smtp.getResponseText()));
        return;
    }

    smtp.quit();
    emit emailSent(true, QString("Code envoye avec succes a %1.").arg(recipient));
}
