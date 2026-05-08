#ifndef ARDUINO_ENVIRONMENT_H
#define ARDUINO_ENVIRONMENT_H

#include <QByteArray>
#include <QString>
#include <QVector>
#include <QDate>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

struct EnvSensorData {
    float temperature = 0.0f;
    float humidity = 0.0f;
    int fanRPM = 0;
    bool fanRunning = false;
    QString fanMode;
    QString timestamp;
    bool isValid = false;
};

class ArduinoEnvironment
{
public:
    ArduinoEnvironment();
    ~ArduinoEnvironment();

    // Connexion / déconnexion
    int connect();
    void disconnect();
    bool isConnected() const;
    QString getPortName() const;

    // Configuration
    float getTargetTemperature() const;
    void setTargetTemperature(float temp);
    bool stopFan(QString *errorMessage = nullptr);
    bool resumeAutoMode(QString *errorMessage = nullptr);
    bool sendCommand(const QString &cmd, QString *errorMessage = nullptr);
    
    // Lecture des données
    QString readRawData();
    bool parseSensorData(const QString &data, EnvSensorData *outData);
    bool readSensorData(EnvSensorData *outData, QString *errorMessage = nullptr);
    
    // Enregistrement pour une seule commande par ID
    bool recordSensorDataForSingleCommande(
        int idCommande,
        const EnvSensorData &data,
        QString *errorMessage = nullptr
    );

    // Enregistrement pour les résultats de recherche
    bool recordSensorDataForSearchResults(
        const QDate &debut, 
        const QDate &fin,
        const QString &etat, 
        int idClient,
        const QString &nomClient,
        const QString &fournisseur,
        const EnvSensorData &data, 
        QString *errorMessage = nullptr
    );

    // Accès
    QByteArray& getBuffer() { return m_buffer; }
    void clearBuffer() { m_buffer.clear(); }
    QSerialPort* getSerial() { return m_serial; }

private:
    bool findArduinoPort();
    void logCommandToDatabase(const QString &typeCommande, 
                              const QString &parametres, 
                              bool success, 
                              const QString &resultat, 
                              float tempActuelle = -1.0f, 
                              float tempCible = -1.0f);

    QSerialPort *m_serial;
    QString m_portName;
    bool m_isConnected;
    QByteArray m_buffer;
    float m_targetTemperature;
};

#endif // ARDUINO_ENVIRONMENT_H