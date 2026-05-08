#include "oauth2_helper.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDateTime>
#include <QDebug>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>
#include <QEventLoop>
#include <QTimer>
#include <QCryptographicHash>

// For base64 encoding
#include <QByteArray>

// For OpenSSL/JWT signing (if available)
#ifdef HAVE_OPENSSL
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/sha.h>
#else
#define OPENSSL_NOT_AVAILABLE 1
#endif

OAuth2Helper::OAuth2Helper()
{
}

bool OAuth2Helper::loadServiceAccount(const QString &jsonFilePath)
{
    QFile file(jsonFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open service account file:" << jsonFilePath;
        return false;
    }
    
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
    file.close();
    
    if (!doc.isObject()) {
        qWarning() << "Invalid JSON service account file";
        return false;
    }
    
    m_serviceAccount = doc.object();
    return true;
}

QString OAuth2Helper::generateJWT()
{
#ifndef HAVE_OPENSSL
    qWarning() << "[OAuth2] OpenSSL not available. JWT signing not supported.";
    qWarning() << "[OAuth2] Please install OpenSSL or use simple API key authentication instead.";
    return "";
#else
    // Create header
    QJsonObject header;
    header["alg"] = "RS256";
    header["typ"] = "JWT";
    QJsonDocument headerDoc(header);
    QString encodedHeader = QString::fromUtf8(
        headerDoc.toJson(QJsonDocument::Compact)
            .toBase64(QByteArray::Base64UrlEncoding)
            .replace("=", "")
    );
    
    // Create payload
    QDateTime now = QDateTime::currentDateTimeUtc();
    QJsonObject payload;
    payload["iss"] = m_serviceAccount["client_email"];
    payload["scope"] = "https://www.googleapis.com/auth/cloud-platform";
    payload["aud"] = "https://oauth2.googleapis.com/token";
    payload["exp"] = now.addSecs(3600).toSecsSinceEpoch();
    payload["iat"] = now.toSecsSinceEpoch();
    
    QJsonDocument payloadDoc(payload);
    QString encodedPayload = QString::fromUtf8(
        payloadDoc.toJson(QJsonDocument::Compact)
            .toBase64(QByteArray::Base64UrlEncoding)
            .replace("=", "")
    );
    
    // Create signature
    QString message = encodedHeader + "." + encodedPayload;
    QString privateKeyStr = m_serviceAccount["private_key"].toString();
    
    BIO *keyBio = BIO_new_mem_buf(privateKeyStr.toUtf8().data(), -1);
    EVP_PKEY *pkey = PEM_read_bio_PrivateKey(keyBio, nullptr, nullptr, nullptr);
    BIO_free(keyBio);
    
    if (!pkey) {
        qWarning() << "Failed to parse private key";
        return "";
    }
    
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    EVP_SignInit(ctx, EVP_sha256());
    EVP_SignUpdate(ctx, message.toUtf8().data(), message.length());
    
    unsigned char signature[1000];
    unsigned int sig_len;
    EVP_SignFinal(ctx, signature, &sig_len, pkey);
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(pkey);
    
    QString encodedSignature = QString::fromUtf8(
        QByteArray(reinterpret_cast<char*>(signature), sig_len)
            .toBase64(QByteArray::Base64UrlEncoding)
            .replace("=", "")
    );
    
    return message + "." + encodedSignature;
#endif
}

QString OAuth2Helper::requestAccessToken(const QString &jwt)
{
    QNetworkRequest request(QUrl("https://oauth2.googleapis.com/token"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    
    QUrlQuery query;
    query.addQueryItem("grant_type", "urn:ietf:params:oauth:grant-type:jwt-bearer");
    query.addQueryItem("assertion", jwt);
    
    QNetworkReply *reply = m_networkManager.post(request, query.toString(QUrl::FullyEncoded).toUtf8());
    
    // Wait for response (blocking)
    QEventLoop loop;
    QTimer timeout;
    timeout.setSingleShot(true);
    
    QObject::connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
                     &loop, &QEventLoop::quit);
    QObject::connect(reply, &QNetworkReply::finished, &loop, &QEventLoop::quit);
    QObject::connect(&timeout, &QTimer::timeout, &loop, &QEventLoop::quit);
    
    timeout.start(10000); // 10 second timeout
    loop.exec();
    
    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << "OAuth token request error:" << reply->errorString();
        reply->deleteLater();
        return "";
    }
    
    QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
    reply->deleteLater();
    
    if (doc.isObject()) {
        QJsonObject obj = doc.object();
        if (obj.contains("access_token")) {
            return obj["access_token"].toString();
        }
    }
    
    qWarning() << "Failed to get access token from response";
    return "";
}

QString OAuth2Helper::getAccessToken()
{
    // Return cached token if still valid
    if (!m_cachedAccessToken.isEmpty() && 
        QDateTime::currentDateTimeUtc() < m_tokenExpiry) {
        return m_cachedAccessToken;
    }
    
    // Generate new token
    QString jwt = generateJWT();
    if (jwt.isEmpty()) {
        return "";
    }
    
    m_cachedAccessToken = requestAccessToken(jwt);
    m_tokenExpiry = QDateTime::currentDateTimeUtc().addSecs(3500); // Expire in 58 minutes
    
    return m_cachedAccessToken;
}
