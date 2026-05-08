#include "parking_widget.h"
#include <QSerialPort>
#include <QGroupBox>
#include <QSplitter>
#include <QScrollBar>

// ============================================================
ParkingWidget::ParkingWidget(QWidget *parent) : QWidget(parent)
{
    setupUI();
    m_resetTimer = new QTimer(this);
    m_resetTimer->setSingleShot(true);
    connect(m_resetTimer, &QTimer::timeout, this, &ParkingWidget::resetStatusDisplay);
}

ParkingWidget::~ParkingWidget() {}

// ============================================================
void ParkingWidget::setupUI()
{
    QVBoxLayout *main = new QVBoxLayout(this);
    main->setSpacing(10);
    main->setContentsMargins(16, 16, 16, 16);

    QLabel *title = new QLabel("Parking Smart OilPress — Contrôle Accès RFID");
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet(
        "font-size:15px; font-weight:600; padding:8px;"
        "background:#E8EAF6; border-radius:8px; color:#1A237E;");
    main->addWidget(title);

    QGroupBox *gbConn = new QGroupBox("Connexion Arduino");
    QHBoxLayout *connLay = new QHBoxLayout(gbConn);
    m_btnConnect = new QPushButton("Connecter Arduino");
    m_btnConnect->setStyleSheet(
        "QPushButton{background:#1565C0;color:white;border-radius:6px;padding:5px 14px;font-weight:600;}"
        "QPushButton:hover{background:#1976D2;}");
    m_lblConnStatus = new QLabel("Non connecté");
    m_lblConnStatus->setStyleSheet("color:#C62828; font-weight:600;");
    connLay->addWidget(m_btnConnect);
    connLay->addWidget(m_lblConnStatus);
    connLay->addStretch();
    connect(m_btnConnect, &QPushButton::clicked, this, &ParkingWidget::onConnectClicked);
    main->addWidget(gbConn);

    QGroupBox *gbStatus = new QGroupBox("État du Parking");
    QVBoxLayout *stLay = new QVBoxLayout(gbStatus);
    m_lblStatus = new QLabel("En attente de scan...");
    m_lblStatus->setAlignment(Qt::AlignCenter);
    m_lblStatus->setStyleSheet("font-size:20px; font-weight:700; color:#616161; padding:10px;");
    m_lblClientName = new QLabel("");
    m_lblClientName->setAlignment(Qt::AlignCenter);
    m_lblClientName->setStyleSheet("font-size:14px; color:#424242;");
    m_lblLastUID = new QLabel("UID: —");
    m_lblLastUID->setAlignment(Qt::AlignCenter);
    m_lblLastUID->setStyleSheet("font-size:11px; color:#9E9E9E; font-family:monospace;");
    stLay->addWidget(m_lblStatus);
    stLay->addWidget(m_lblClientName);
    stLay->addWidget(m_lblLastUID);
    main->addWidget(gbStatus);

    QGroupBox *gbSend = new QGroupBox("Qt → Arduino (commandes envoyées)");
    QGridLayout *sendLay = new QGridLayout(gbSend);
    sendLay->addWidget(new QLabel("Message LCD :"), 0, 0);
    m_editMessage = new QLineEdit("Bonjour!");
    sendLay->addWidget(m_editMessage, 0, 1);
    m_btnSendDisplay = new QPushButton("Envoyer au LCD");
    m_btnSendDisplay->setStyleSheet(
        "QPushButton{background:#2E7D32;color:white;border-radius:5px;padding:4px 12px;}"
        "QPushButton:hover{background:#388E3C;}");
    sendLay->addWidget(m_btnSendDisplay, 0, 2);
    m_btnOpenBarrier = new QPushButton("Ouvrir Barrière");
    m_btnOpenBarrier->setStyleSheet(
        "QPushButton{background:#1565C0;color:white;border-radius:5px;padding:4px 12px;}"
        "QPushButton:hover{background:#1976D2;}");
    m_btnCloseBarrier = new QPushButton("Fermer Barrière");
    m_btnCloseBarrier->setStyleSheet(
        "QPushButton{background:#C62828;color:white;border-radius:5px;padding:4px 12px;}"
        "QPushButton:hover{background:#D32F2F;}");
    sendLay->addWidget(m_btnOpenBarrier,  1, 0);
    sendLay->addWidget(m_btnCloseBarrier, 1, 1);
    connect(m_btnSendDisplay,  &QPushButton::clicked, this, &ParkingWidget::onSendDisplayClicked);
    connect(m_btnOpenBarrier,  &QPushButton::clicked, this, &ParkingWidget::onOpenBarrierClicked);
    connect(m_btnCloseBarrier, &QPushButton::clicked, this, &ParkingWidget::onCloseBarrierClicked);
    main->addWidget(gbSend);

    QSplitter *splitter = new QSplitter(Qt::Horizontal);

    QGroupBox *gbLog = new QGroupBox("Journal temps réel (Arduino → Qt)");
    QVBoxLayout *logLay = new QVBoxLayout(gbLog);
    m_logEdit = new QTextEdit;
    m_logEdit->setReadOnly(true);
    m_logEdit->setMaximumHeight(150);
    m_logEdit->setStyleSheet(
        "background:#212121; color:#E0E0E0; font-family:monospace; font-size:12px;"
        "border-radius:6px; padding:4px;");
    logLay->addWidget(m_logEdit);

    QGroupBox *gbHist = new QGroupBox("Historique base de données (ACCES_PARKING)");
    QVBoxLayout *histLay = new QVBoxLayout(gbHist);
    m_historyEdit = new QTextEdit;
    m_historyEdit->setReadOnly(true);
    m_historyEdit->setMaximumHeight(150);
    m_historyEdit->setStyleSheet(
        "background:#1A237E; color:#E8EAF6; font-family:monospace; font-size:12px;"
        "border-radius:6px; padding:4px;");
    QPushButton *btnRefresh = new QPushButton("Actualiser historique");
    btnRefresh->setStyleSheet("background:#3949AB; color:white; border-radius:4px; padding:3px 10px;");
    connect(btnRefresh, &QPushButton::clicked, this, &ParkingWidget::loadHistory);
    histLay->addWidget(m_historyEdit);
    histLay->addWidget(btnRefresh);

    splitter->addWidget(gbLog);
    splitter->addWidget(gbHist);
    main->addWidget(splitter);

    setStatusIdle();
}

// ============================================================
void ParkingWidget::setArduino(Arduino *arduino)
{
    m_arduino = arduino;

    // Connect readyRead immediately so we catch data even when
    // the Arduino was auto-connected at startup by MainWindow
    if (m_arduino && m_arduino->getserial()) {
        connect(m_arduino->getserial(), &QSerialPort::readyRead,
                this, &ParkingWidget::onSerialDataReady, Qt::UniqueConnection);
        qDebug() << "[ParkingWidget] readyRead signal connected in setArduino()";
    }
}

// ============================================================
//  Helper: get a valid open DB connection, reconnecting if needed
// ============================================================
QSqlDatabase ParkingWidget::getDatabase()
{
    // Try the named connection first
    if (QSqlDatabase::contains("qt_sql_default_connection")) {
        QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
        if (db.isOpen()) return db;
        if (db.open()) {
            qDebug() << "[ParkingWidget] DB reconnected successfully.";
            return db;
        }
    }
    // Fall back to the default connection
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) db.open();
    return db;
}

// ============================================================
void ParkingWidget::onConnectClicked()
{
    if (!m_arduino) return;
    int ret = m_arduino->connect_arduino();
    if (ret == 0) {
        m_lblConnStatus->setText("Connecté : " + m_arduino->getarduino_port_name());
        m_lblConnStatus->setStyleSheet("color:#2E7D32; font-weight:600;");
        connect(m_arduino->getserial(), &QSerialPort::readyRead,
                this, &ParkingWidget::onSerialDataReady, Qt::UniqueConnection);
        appendLog("Arduino connecté sur " + m_arduino->getarduino_port_name(), "info");
        loadHistory();
    } else {
        m_lblConnStatus->setText("Arduino introuvable");
        m_lblConnStatus->setStyleSheet("color:#C62828; font-weight:600;");
        appendLog("Connexion échouée.", "danger");
    }
}

void ParkingWidget::onSendDisplayClicked()
{
    QString msg = m_editMessage->text().trimmed();
    if (msg.isEmpty()) return;
    sendToArduino("DISPLAY:" + msg);
    appendLog("[Qt→Arduino] DISPLAY:" + msg, "info");
}

void ParkingWidget::onOpenBarrierClicked()
{
    sendToArduino("BARRIER:OPEN");
    appendLog("[Qt→Arduino] BARRIER:OPEN — barrière ouverte depuis Qt", "info");
}

void ParkingWidget::onCloseBarrierClicked()
{
    sendToArduino("BARRIER:CLOSE");
    appendLog("[Qt→Arduino] BARRIER:CLOSE — barrière fermée depuis Qt", "neutral");
}

void ParkingWidget::sendToArduino(const QString &cmd)
{
    if (m_arduino && m_arduino->getserial() && m_arduino->getserial()->isOpen()) {
        m_arduino->write_to_arduino((cmd + "\n").toLatin1());
    } else {
        appendLog("Erreur: Arduino non connecté.", "danger");
    }
}

void ParkingWidget::onSerialDataReady()
{
    if (!m_arduino || !m_arduino->getserial()) return;
    m_buffer += m_arduino->getserial()->readAll();
    while (m_buffer.contains('\n')) {
        int idx = m_buffer.indexOf('\n');
        QString line = QString::fromLatin1(m_buffer.left(idx)).trimmed();
        m_buffer = m_buffer.mid(idx + 1);
        if (!line.isEmpty()) processLine(line);
    }
}

void ParkingWidget::processLine(const QString &line)
{
    qDebug() << "[ParkingWidget] processLine received:" << line;

    if (line.startsWith("ACCESS_GRANTED:")) {
        QString name = line.mid(15).trimmed();
        setStatusGranted(name);
        saveToDatabase(m_lastUID, name, "AUTORISE");
        appendLog("[" + QDateTime::currentDateTime().toString("hh:mm:ss") +
                  "] ACCÈS AUTORISÉ — " + name, "success");
        sendToArduino("DISPLAY:Bienvenue " + name.left(10));
        m_resetTimer->start(5000);
    } else if (line == "ACCESS_DENIED") {
        setStatusDenied();
        saveToDatabase(m_lastUID, "", "REFUSE");
        appendLog("[" + QDateTime::currentDateTime().toString("hh:mm:ss") +
                  "] ACCÈS REFUSÉ — carte inconnue", "danger");
        m_resetTimer->start(4000);
    } else if (line.startsWith("UID:")) {
        m_lastUID = line.mid(4).trimmed();
        m_lblLastUID->setText("UID : " + m_lastUID);
        appendLog("Carte détectée UID: " + m_lastUID, "neutral");
    } else if (line == "PARKING_READY") {
        appendLog("Système parking prêt.", "info");
    }
}

// ============================================================
void ParkingWidget::saveToDatabase(const QString &uid, const QString &name, const QString &statut)
{
    QSqlDatabase db = getDatabase();
    if (!db.isOpen()) {
        appendLog("Erreur DB: base de données non connectée.", "danger");
        return;
    }

    QSqlQuery q(db);
    q.prepare(
        "INSERT INTO ACCES_PARKING (UID_CARTE, NOM_CLIENT, STATUT, HORODATAGE) "
        "VALUES (:uid, :nom, :statut, SYSDATE)"
    );
    q.bindValue(":uid",    uid.isEmpty() ? "INCONNU" : uid);
    // FIX: Qt 6 — correct way to pass NULL for a QString column
    q.bindValue(":nom",    name.isEmpty()
                    ? QVariant(QMetaType(QMetaType::QString))
                    : QVariant(name));
    q.bindValue(":statut", statut);

    if (!q.exec()) {
        QString err = q.lastError().text();
        qDebug() << "[ParkingWidget] DB insert error:" << err;
        appendLog("Erreur DB (INSERT): " + err.left(80), "danger");
    } else {
        appendLog("Enregistré en base: " + statut + " — " + uid, "info");
        loadHistory();
    }
}

// ============================================================
void ParkingWidget::loadHistory()
{
    m_historyEdit->clear();

    QSqlDatabase db = getDatabase();
    if (!db.isOpen()) {
        m_historyEdit->setHtml(
            "<span style='color:#EF5350;'>"
            "Base de données non connectée.<br>"
            "Vérifiez qu'Oracle XE est démarré."
            "</span>");
        return;
    }

    QSqlQuery q(db);
    bool ok = q.exec(
        "SELECT ID_ACCES, UID_CARTE, NOM_CLIENT, STATUT, "
        "TO_CHAR(HORODATAGE,'DD/MM/YY HH24:MI:SS') AS H "
        "FROM ("
        "  SELECT ID_ACCES, UID_CARTE, NOM_CLIENT, STATUT, HORODATAGE "
        "  FROM ACCES_PARKING ORDER BY HORODATAGE DESC"
        ") WHERE ROWNUM <= 10"
    );

    if (!ok) {
        QString err = q.lastError().text();
        qDebug() << "[ParkingWidget] loadHistory error:" << err;

        if (err.contains("ORA-00942") || err.contains("table or view does not exist")) {
            m_historyEdit->setHtml(
                "<span style='color:#FF9800;'>"
                "Table ACCES_PARKING introuvable.<br>"
                "Exécutez <b>create_acces_parking.sql</b> dans Oracle SQL Developer."
                "</span>");
        } else if (err.contains("ORA-03114") || err.contains("ORA-03135")) {
            m_historyEdit->setHtml(
                "<span style='color:#EF5350;'>"
                "Connexion Oracle perdue (ORA-03114/03135).<br>"
                "Vérifiez qu'Oracle XE est démarré, puis relancez l'application."
                "</span>");
        } else {
            m_historyEdit->setHtml(
                "<span style='color:#EF5350;'>Erreur DB: " +
                err.left(120).toHtmlEscaped() + "</span>");
        }
        return;
    }

    QString html =
        "<table width='100%' cellspacing='0' cellpadding='4' "
        "style='font-family:monospace; font-size:12px; color:#E8EAF6;'>"
        "<tr style='background:#3949AB;'>"
        "<th align='left'>ID</th>"
        "<th align='left'>UID Carte</th>"
        "<th align='left'>Client</th>"
        "<th align='left'>Statut</th>"
        "<th align='left'>Date / Heure</th>"
        "</tr>";

    int rowCount = 0;
    while (q.next()) {
        rowCount++;
        QString statut = q.value("STATUT").toString();
        QString client = q.value("NOM_CLIENT").toString();
        QString uid    = q.value("UID_CARTE").toString();
        QString id     = q.value("ID_ACCES").toString();
        QString heure  = q.value("H").toString();

        QString statutColor = (statut == "AUTORISE") ? "#4CAF50" : "#EF5350";
        QString rowBg = (rowCount % 2 == 0) ? "background:#283593;" : "background:#1A237E;";

        html += "<tr style='" + rowBg + "'>"
                "<td>" + id.toHtmlEscaped() + "</td>"
                "<td>" + uid.toHtmlEscaped() + "</td>"
                "<td>" + (client.isEmpty()
                    ? "<i style='color:#9E9E9E;'>Inconnu</i>"
                    : client.toHtmlEscaped()) + "</td>"
                "<td style='color:" + statutColor + "; font-weight:bold;'>"
                    + statut.toHtmlEscaped() + "</td>"
                "<td>" + heure.toHtmlEscaped() + "</td>"
                "</tr>";
    }

    if (rowCount == 0) {
        html += "<tr><td colspan='5' align='center' "
                "style='color:#9E9E9E; padding:12px;'>"
                "Aucun enregistrement trouvé</td></tr>";
    }

    html += "</table>";
    m_historyEdit->setHtml(html);
}

// ============================================================
void ParkingWidget::setStatusGranted(const QString &name)
{
    m_lblStatus->setText("ACCÈS AUTORISÉ");
    m_lblStatus->setStyleSheet("font-size:20px; font-weight:700; color:#2E7D32; padding:10px;");
    m_lblClientName->setText("Bienvenue, " + name + " !");
    setStyleSheet("background:#E8F5E9; border-radius:10px;");
}

void ParkingWidget::setStatusDenied()
{
    m_lblStatus->setText("ACCÈS REFUSÉ");
    m_lblStatus->setStyleSheet("font-size:20px; font-weight:700; color:#C62828; padding:10px;");
    m_lblClientName->setText("Carte non reconnue.");
    setStyleSheet("background:#FFEBEE; border-radius:10px;");
}

void ParkingWidget::setStatusIdle()
{
    m_lblStatus->setText("En attente de scan...");
    m_lblStatus->setStyleSheet("font-size:20px; font-weight:700; color:#616161; padding:10px;");
    m_lblClientName->setText("");
    setStyleSheet("");
}

void ParkingWidget::resetStatusDisplay() { setStatusIdle(); }

void ParkingWidget::appendLog(const QString &msg, const QString &colorClass)
{
    QString color = "#9E9E9E";
    if (colorClass == "success") color = "#4CAF50";
    else if (colorClass == "danger")  color = "#EF5350";
    else if (colorClass == "info")    color = "#42A5F5";
    m_logEdit->append("<span style='color:" + color + ";'>" + msg.toHtmlEscaped() + "</span>");
    m_logEdit->verticalScrollBar()->setValue(m_logEdit->verticalScrollBar()->maximum());
}