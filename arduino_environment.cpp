#include "arduino_environment.h"
#include "commande.h"
#include <QDebug>
#include <QRegularExpression>
#include <QDateTime>
#include <QThread>
#include <QSqlQuery>
#include <QSqlError>

// ---------------------------------------------------------------------------
// Constructor / Destructor
// ---------------------------------------------------------------------------

ArduinoEnvironment::ArduinoEnvironment()
    : m_serial(new QSerialPort())
    , m_isConnected(false)
    , m_buffer()
    , m_targetTemperature(28.0f)
{
    qDebug() << "[ArduinoEnv] Constructor: DHT11 sensor mode (temperature + humidity + fan)";
}

ArduinoEnvironment::~ArduinoEnvironment()
{
    disconnect();
    delete m_serial;
}

// ---------------------------------------------------------------------------
// Configuration - Temperature Threshold Management
// ---------------------------------------------------------------------------

float ArduinoEnvironment::getTargetTemperature() const
{
    return m_targetTemperature;
}

void ArduinoEnvironment::setTargetTemperature(float temp)
{
    m_targetTemperature = temp;
    qDebug() << "[ArduinoEnv] Target temperature updated to:" << m_targetTemperature << "°C";
}

// ---------------------------------------------------------------------------
// Port discovery and Connect/Disconnect
// ---------------------------------------------------------------------------

bool ArduinoEnvironment::findArduinoPort()
{
    const QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    qDebug() << "[ArduinoEnv] Scanning" << ports.size() << "ports...";

    for (const QSerialPortInfo &portInfo : ports) {
        qDebug() << "[ArduinoEnv] Testing port:" << portInfo.portName()
                 << "| Desc:" << portInfo.description()
                 << "| Manufacturer:" << portInfo.manufacturer();

        if (portInfo.hasVendorIdentifier() && portInfo.hasProductIdentifier()) {
            quint16 vid = portInfo.vendorIdentifier();
            quint16 pid = portInfo.productIdentifier();

            bool isOfficialUno = (vid == 0x2341 && (pid == 0x0043 || pid == 0x0001));
            bool isCH340Clone  = (vid == 0x1A86);
            bool isCP210x      = (vid == 0x10C4);
            bool isFTDI        = (vid == 0x0403);

            if (isOfficialUno || isCH340Clone || isCP210x || isFTDI) {
                m_portName = portInfo.portName();
                qDebug() << "[ArduinoEnv] ✅ Found by VID/PID on port:" << m_portName;
                return true;
            }
        }

        QString fullDescription = (portInfo.description() + " " + portInfo.manufacturer()).toLower();
        if (fullDescription.contains("arduino") ||
            fullDescription.contains("usb serial") ||
            fullDescription.contains("ch340") ||
            fullDescription.contains("ch341") ||
            fullDescription.contains("wch") ||
            fullDescription.contains("cp210") ||
            fullDescription.contains("ftdi")) {
            m_portName = portInfo.portName();
            qDebug() << "[ArduinoEnv] ✅ Found by description on port:" << m_portName;
            return true;
        }
    }

    qDebug() << "[ArduinoEnv] ❌ No Arduino found on any port.";
    return false;
}

int ArduinoEnvironment::connect()
{
    if (m_isConnected && m_serial && m_serial->isOpen()) {
        return 0;
    }

    if (!findArduinoPort()) {
        return -1;
    }

    if (m_serial->isOpen()) {
        m_serial->close();
    }

    QThread::msleep(500);

    m_serial->setPortName(m_portName);
    m_serial->setBaudRate(QSerialPort::Baud9600);
    m_serial->setDataBits(QSerialPort::Data8);
    m_serial->setParity(QSerialPort::NoParity);
    m_serial->setStopBits(QSerialPort::OneStop);
    m_serial->setFlowControl(QSerialPort::NoFlowControl);

    const int MAX_RETRIES = 3;
    for (int attempt = 0; attempt < MAX_RETRIES; ++attempt) {
        if (m_serial->open(QSerialPort::ReadWrite)) {
            m_isConnected = true;
            m_buffer.clear();

            qDebug() << "[ArduinoEnv] Connected on" << m_portName << "- waiting for Arduino reset...";
            QThread::msleep(2500);

            if (m_serial->waitForReadyRead(1000)) {
                QByteArray bootMsg = m_serial->readAll();
                qDebug() << "[ArduinoEnv] Boot message:" << bootMsg.trimmed();
            }
            qDebug() << "[ArduinoEnv] ✅ Arduino connected. Current threshold: " << m_targetTemperature << "°C";
            return 0;
        }
        qDebug() << "[ArduinoEnv] Attempt" << (attempt + 1) << "failed:" << m_serial->errorString();
        QThread::msleep(1000);
    }

    qDebug() << "[ArduinoEnv] Failed to open port after" << MAX_RETRIES << "attempts";
    m_isConnected = false;
    return 1;
}

void ArduinoEnvironment::disconnect()
{
    if (m_serial && m_serial->isOpen()) {
        m_serial->close();
    }
    m_isConnected = false;
    m_buffer.clear();
    qDebug() << "[ArduinoEnv] Disconnected";
}

bool ArduinoEnvironment::isConnected() const
{
    return m_isConnected && m_serial && m_serial->isOpen();
}

QString ArduinoEnvironment::getPortName() const
{
    return m_portName;
}

// ---------------------------------------------------------------------------
// Send Commands to Arduino
// ---------------------------------------------------------------------------

bool ArduinoEnvironment::sendCommand(const QString &cmd, QString *errorMessage)
{
    if (!isConnected()) {
        if (errorMessage) *errorMessage = "Arduino non connecte";
        qDebug() << "[ArduinoEnv] sendCommand FAILED: Not connected";
        return false;
    }

    if (cmd.isEmpty()) {
        if (errorMessage) *errorMessage = "Commande vide";
        return false;
    }

    QByteArray command = cmd.left(1).toUpper().toUtf8();
    qDebug() << "[ArduinoEnv] Sending command:" << command;
    
    qint64 written = m_serial->write(command);
    m_serial->flush();

    if (written < 0) {
        if (errorMessage) *errorMessage = "Echec envoi commande";
        return false;
    }

    if (!m_serial->waitForBytesWritten(1000)) {
        if (errorMessage) *errorMessage = "Echec envoi commande (timeout)";
        return false;
    }

    qDebug() << "[ArduinoEnv] ✓ Command sent successfully";
    return true;
}

bool ArduinoEnvironment::stopFan(QString *errorMessage)
{
    return sendCommand("S", errorMessage);
}

bool ArduinoEnvironment::resumeAutoMode(QString *errorMessage)
{
    return sendCommand("R", errorMessage);
}

// ---------------------------------------------------------------------------
// Read Raw Data from Arduino
// ---------------------------------------------------------------------------

QString ArduinoEnvironment::readRawData()
{
    if (!isConnected()) {
        qDebug() << "[ArduinoEnv] readRawData: not connected";
        return QString();
    }

    qint64 bytesAvailable = m_serial->bytesAvailable();
    if (bytesAvailable > 0) {
        QByteArray newData = m_serial->readAll();
        m_buffer.append(newData);
        qDebug() << "[ArduinoEnv] Read" << bytesAvailable << "bytes, buffer now" << m_buffer.size() << "bytes";
    } else {
        if (!m_serial->waitForReadyRead(2000)) {
            qDebug() << "[ArduinoEnv] Timeout: no data available after 2s";
            return QString();
        }
        m_buffer.append(m_serial->readAll());
    }

    QString data = QString::fromUtf8(m_buffer);
    
    int fanPos = data.indexOf("Fan:");
    if (fanPos < 0) {
        if (data.size() > 200) {
            m_buffer.clear();
        }
        return QString();
    }

    int tempPos = data.indexOf("Temperature:", fanPos);
    int humPos  = data.indexOf("Humidity:", fanPos);
    int speedPos = data.indexOf("Fan Speed:", fanPos);

    if (tempPos < 0 || humPos < 0 || speedPos < 0) {
        if (m_buffer.size() > 500) {
            m_buffer.clear();
        }
        return QString();
    }

    int rpmLineEnd = data.indexOf('\n', speedPos);
    if (rpmLineEnd < 0) {
        return QString();
    }

    rpmLineEnd++;
    QString completePacket = data.mid(fanPos, rpmLineEnd - fanPos);
    m_buffer = m_buffer.mid(rpmLineEnd);

    qDebug() << "[ArduinoEnv] ✅ Complete packet extracted:" << completePacket.left(80);
    return completePacket;
}

// ---------------------------------------------------------------------------
// Parse Sensor Data
// ---------------------------------------------------------------------------

bool ArduinoEnvironment::parseSensorData(const QString &rawData, EnvSensorData *outData)
{
    if (!outData || rawData.isEmpty()) {
        return false;
    }

    outData->isValid      = false;
    outData->temperature  = 0.0f;
    outData->humidity     = 0.0f;
    outData->fanRPM       = 0;
    outData->fanRunning   = false;
    outData->fanMode      = "UNKNOWN";

    bool gotTemp = false;
    bool gotHum  = false;

    const QStringList lines = rawData.split('\n', Qt::SkipEmptyParts);

    for (const QString &rawLine : lines) {
        QString line = rawLine.trimmed();
        if (line.isEmpty()) continue;

        if (line.startsWith("Temperature:", Qt::CaseInsensitive)) {
            QRegularExpression re(R"(Temperature:\s*([\d.]+)[°°]?C?)", QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionMatch m = re.match(line);
            if (m.hasMatch()) {
                outData->temperature = m.captured(1).toFloat();
                gotTemp = true;
                qDebug() << "[ArduinoEnv] Parsed temp:" << outData->temperature;
            }
        }
        else if (line.startsWith("Humidity:", Qt::CaseInsensitive)) {
            QRegularExpression re(R"(Humidity:\s*([\d.]+)%)", QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionMatch m = re.match(line);
            if (m.hasMatch()) {
                outData->humidity = m.captured(1).toFloat();
                gotHum = true;
                qDebug() << "[ArduinoEnv] Parsed hum:" << outData->humidity;
            }
        }
        else if (line.startsWith("Fan Speed:", Qt::CaseInsensitive)) {
            QRegularExpression re(R"(Fan Speed:\s*([\d.]+)\s*RPM)", QRegularExpression::CaseInsensitiveOption);
            QRegularExpressionMatch m = re.match(line);
            if (m.hasMatch()) {
                outData->fanRPM = static_cast<int>(m.captured(1).toFloat());
                qDebug() << "[ArduinoEnv] Parsed RPM:" << outData->fanRPM;
            }
        }
        else if (line.startsWith("Fan:", Qt::CaseInsensitive)) {
            if (line.contains("ON", Qt::CaseInsensitive)) {
                outData->fanRunning = true;
                outData->fanMode    = line.contains("auto", Qt::CaseInsensitive) ? "AUTO" : "MANUEL";
            } else {
                outData->fanRunning = false;
                outData->fanMode    = "OFF";
            }
            qDebug() << "[ArduinoEnv] Fan state:" << outData->fanMode;
        }
    }

    outData->isValid    = gotTemp && gotHum;
    outData->timestamp  = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    return outData->isValid;
}

// ---------------------------------------------------------------------------
// Complete Reading with Auto-Reconnection
// ---------------------------------------------------------------------------

bool ArduinoEnvironment::readSensorData(EnvSensorData *outData, QString *errorMessage)
{
    if (!outData) {
        if (errorMessage) *errorMessage = "Pointeur outData nul";
        return false;
    }

    if (!isConnected()) {
        qDebug() << "[ArduinoEnv] Not connected, attempting reconnect...";
        if (connect() != 0) {
            if (errorMessage) *errorMessage = "Arduino non connecte";
            return false;
        }
    }

    QString rawData = readRawData();

    if (rawData.isEmpty()) {
        if (errorMessage) *errorMessage = "Aucune donnee recue";
        return false;
    }

    if (!parseSensorData(rawData, outData)) {
        if (errorMessage) *errorMessage = "Donnees incompletes ou invalides";
        return false;
    }

    return true;
}

// ---------------------------------------------------------------------------
// Record Sensor Data for Single Commande (NEW - Primary method for UI)
// ---------------------------------------------------------------------------

bool ArduinoEnvironment::recordSensorDataForSingleCommande(
    int idCommande,
    const EnvSensorData &data,
    QString *errorMessage)
{
    qDebug() << "[ArduinoEnv] =========================================";
    qDebug() << "[ArduinoEnv] recordSensorDataForSingleCommande() CALLED";
    qDebug() << "[ArduinoEnv] ID Commande: " << idCommande;
    qDebug() << "[ArduinoEnv] =========================================";
    
    if (idCommande <= 0) {
        QString err = "ID commande invalide";
        if (errorMessage) *errorMessage = err;
        qDebug() << "[ArduinoEnv] ❌ " << err;
        return false;
    }
    
    if (!data.isValid) {
        if (errorMessage) *errorMessage = "Données capteur invalides";
        qDebug() << "[ArduinoEnv] ❌ Données invalides";
        return false;
    }
    
    // Déterminer le niveau d'alerte
    QString alertLevel = "NORMAL";
    if (data.temperature > 35 || data.humidity > 75) {
        alertLevel = "CRITICAL";
    } else if (data.temperature > 30 || data.humidity > 65) {
        alertLevel = "WARNING";
    }
    
    // Formater les conditions de stockage
    QString storageConditions = QString("T=%1°C | H=%2% | Fan=%3 RPM (%4)")
        .arg(data.temperature, 0, 'f', 1)
        .arg(data.humidity, 0, 'f', 1)
        .arg(data.fanRPM)
        .arg(data.fanMode);
    
    qDebug() << "[ArduinoEnv] 📊 Données à enregistrer:";
    qDebug() << "[ArduinoEnv]   - Température: " << data.temperature << "°C";
    qDebug() << "[ArduinoEnv]   - Humidité: " << data.humidity << "%";
    qDebug() << "[ArduinoEnv]   - Fan: " << data.fanRPM << "RPM (" << data.fanMode << ")";
    qDebug() << "[ArduinoEnv]   - Alert Level: " << alertLevel;
    
    // Enregistrer pour la commande
    if (Ccommande::enregistrerDonneesCapteur(idCommande, data.temperature, data.humidity, 
                                              alertLevel, storageConditions)) {
        qDebug() << "[ArduinoEnv] ✅ Commande" << idCommande << "enregistrée avec succès";
        
        // Log to history
        logCommandToDatabase(
            "SENSOR_DATA_SINGLE",
            QString("ID_Commande=%1").arg(idCommande),
            true,
            QString("Température: %1°C, Humidité: %2%, Alert: %3")
                .arg(data.temperature, 0, 'f', 1)
                .arg(data.humidity, 0, 'f', 1)
                .arg(alertLevel),
            data.temperature,
            m_targetTemperature
        );
        
        return true;
    } else {
        QString err = QString("Échec d'enregistrement pour commande %1").arg(idCommande);
        if (errorMessage) *errorMessage = err;
        qDebug() << "[ArduinoEnv] ❌ " << err;
        
        logCommandToDatabase(
            "SENSOR_DATA_SINGLE",
            QString("ID_Commande=%1").arg(idCommande),
            false,
            "Échec d'enregistrement en base de données",
            data.temperature,
            m_targetTemperature
        );
        
        return false;
    }
}

// ---------------------------------------------------------------------------
// Record Sensor Data for Search Results (Legacy - kept for batch operations)
// ---------------------------------------------------------------------------

bool ArduinoEnvironment::recordSensorDataForSearchResults(
    const QDate &debut, 
    const QDate &fin,
    const QString &etat, 
    int idClient,
    const QString &nomClient,
    const QString &fournisseur,
    const EnvSensorData &data, 
    QString *errorMessage)
{
    qDebug() << "[ArduinoEnv] =========================================";
    qDebug() << "[ArduinoEnv] recordSensorDataForSearchResults() CALLED";
    qDebug() << "[ArduinoEnv] Critères de recherche:";
    qDebug() << "[ArduinoEnv]   - Période:" << debut.toString() << "→" << fin.toString();
    qDebug() << "[ArduinoEnv]   - État:" << (etat.isEmpty() ? "Tous" : etat);
    qDebug() << "[ArduinoEnv]   - ID Client:" << (idClient <= 0 ? "Tous" : QString::number(idClient));
    qDebug() << "[ArduinoEnv]   - Nom Client:" << (nomClient.isEmpty() ? "Tous" : nomClient);
    qDebug() << "[ArduinoEnv]   - Fournisseur:" << (fournisseur.isEmpty() ? "Tous" : fournisseur);
    qDebug() << "[ArduinoEnv] =========================================";
    
    if (!data.isValid) {
        if (errorMessage) *errorMessage = "Données capteur invalides";
        qDebug() << "[ArduinoEnv] ❌ Données invalides";
        return false;
    }
    
    QVector<Ccommande> searchResults = Ccommande::rechercher(
        debut, fin, etat, idClient, nomClient, fournisseur
    );
    
    if (searchResults.isEmpty()) {
        QString err = "Aucune commande trouvée avec les critères spécifiés";
        if (errorMessage) *errorMessage = err;
        qDebug() << "[ArduinoEnv] ⚠️" << err;
        return false;
    }
    
    qDebug() << "[ArduinoEnv] 📋 Résultats:" << searchResults.size() << "commande(s) trouvée(s)";
    
    QStringList idsTrouves;
    for (const Ccommande &cmd : searchResults) {
        idsTrouves.append(QString::number(cmd.getIdCommande()));
    }
    qDebug() << "[ArduinoEnv] IDs concernés:" << idsTrouves.join(", ");
    
    QString alertLevel = "NORMAL";
    if (data.temperature > 35 || data.humidity > 75) {
        alertLevel = "CRITICAL";
    } else if (data.temperature > 30 || data.humidity > 65) {
        alertLevel = "WARNING";
    }
    
    QString storageConditions = QString("T=%1°C | H=%2% | Fan=%3 RPM (%4)")
        .arg(data.temperature, 0, 'f', 1)
        .arg(data.humidity, 0, 'f', 1)
        .arg(data.fanRPM)
        .arg(data.fanMode);
    
    int successCount = 0;
    QStringList failedIds;
    
    for (const Ccommande &cmd : searchResults) {
        int idCommande = cmd.getIdCommande();
        
        if (Ccommande::enregistrerDonneesCapteur(idCommande, data.temperature, data.humidity, 
                                                  alertLevel, storageConditions)) {
            successCount++;
            qDebug() << "[ArduinoEnv] ✅ Commande" << idCommande << "enregistrée";
        } else {
            failedIds.append(QString::number(idCommande));
            qDebug() << "[ArduinoEnv] ❌ Échec commande" << idCommande;
        }
        QThread::msleep(50);
    }
    
    qDebug() << "[ArduinoEnv] 📊 BILAN: ✅" << successCount << "/" << searchResults.size() << "commandes";
    
    if (!failedIds.isEmpty()) {
        qDebug() << "[ArduinoEnv] ❌ Échecs IDs:" << failedIds.join(", ");
        if (errorMessage) {
            *errorMessage = QString("%1 commande(s) sur %2 ont échoué. IDs: %3")
                .arg(failedIds.size())
                .arg(searchResults.size())
                .arg(failedIds.join(", "));
        }
    }
    
    logCommandToDatabase(
        "SENSOR_DATA_BATCH",
        QString("Recherche: Période=%1→%2, État=%3")
            .arg(debut.toString("yyyy-MM-dd"))
            .arg(fin.toString("yyyy-MM-dd"))
            .arg(etat.isEmpty() ? "TOUS" : etat),
        (successCount > 0),
        QString("Température: %1°C, Humidité: %2% - %3/%4 commandes mises à jour")
            .arg(data.temperature, 0, 'f', 1)
            .arg(data.humidity, 0, 'f', 1)
            .arg(successCount)
            .arg(searchResults.size()),
        data.temperature,
        m_targetTemperature
    );
    
    return successCount > 0;
}

// ---------------------------------------------------------------------------
// Command History - log to HIS_COMMANDE
// ---------------------------------------------------------------------------

void ArduinoEnvironment::logCommandToDatabase(const QString &typeCommande, 
                                               const QString &parametres, 
                                               bool success, 
                                               const QString &resultat, 
                                               float tempActuelle, 
                                               float tempCible)
{
    qDebug() << "[ArduinoEnv] Logging command:"
             << "| Type:" << typeCommande
             << "| Params:" << parametres
             << "| Success:" << success
             << "| Result:" << resultat
             << "| Temp Actuelle:" << tempActuelle
             << "| Temp Cible:" << tempCible;
}