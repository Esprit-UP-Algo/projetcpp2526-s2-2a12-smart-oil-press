#ifndef OAUTH2_HELPER_H
#define OAUTH2_HELPER_H

#include <QString>
#include <QJsonObject>
#include <QNetworkAccessManager>

class OAuth2Helper
{
public:
    OAuth2Helper();
    
    // Load service account from JSON file
    bool loadServiceAccount(const QString &jsonFilePath);
    
    // Get access token (synchronously or asynchronously)
    QString getAccessToken();
    
private:
    QJsonObject m_serviceAccount;
    QString m_cachedAccessToken;
    QDateTime m_tokenExpiry;
    QNetworkAccessManager m_networkManager;
    
    // Generate JWT token from service account
    QString generateJWT();
    
    // Request access token using JWT
    QString requestAccessToken(const QString &jwt);
};

#endif // OAUTH2_HELPER_H
