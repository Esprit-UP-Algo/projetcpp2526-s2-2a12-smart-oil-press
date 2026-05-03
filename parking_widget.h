#ifndef PARKING_WIDGET_H
#define PARKING_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QTimer>
#include <QDateTime>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include "Arduino.h"

class ParkingWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ParkingWidget(QWidget *parent = nullptr);
    ~ParkingWidget();
    void setArduino(Arduino *arduino);

private slots:
    void onConnectClicked();
    void onSendDisplayClicked();
    void onOpenBarrierClicked();
    void onCloseBarrierClicked();
    void onSerialDataReady();
    void resetStatusDisplay();
    void loadHistory();

private:
    // ── UI helpers ────────────────────────────────────────────
    void setupUI();
    void setStatusGranted(const QString &name);
    void setStatusDenied();
    void setStatusIdle();
    void appendLog(const QString &msg, const QString &colorClass = "neutral");

    // ── Arduino helpers ───────────────────────────────────────
    void sendToArduino(const QString &cmd);
    void processLine(const QString &line);

    // ── Database helpers ──────────────────────────────────────
    QSqlDatabase getDatabase();          // ← declaration added here
    void saveToDatabase(const QString &uid,
                        const QString &name,
                        const QString &statut);

    // ── Widgets ───────────────────────────────────────────────
    QPushButton *m_btnConnect      = nullptr;
    QLabel      *m_lblConnStatus   = nullptr;
    QLabel      *m_lblStatus       = nullptr;
    QLabel      *m_lblClientName   = nullptr;
    QLabel      *m_lblLastUID      = nullptr;
    QLineEdit   *m_editMessage     = nullptr;
    QPushButton *m_btnSendDisplay  = nullptr;
    QPushButton *m_btnOpenBarrier  = nullptr;
    QPushButton *m_btnCloseBarrier = nullptr;
    QTextEdit   *m_logEdit         = nullptr;
    QTextEdit   *m_historyEdit     = nullptr;

    // ── State ─────────────────────────────────────────────────
    Arduino    *m_arduino    = nullptr;
    QTimer     *m_resetTimer = nullptr;
    QByteArray  m_buffer;
    QString     m_lastUID;
};

#endif // PARKING_WIDGET_H
