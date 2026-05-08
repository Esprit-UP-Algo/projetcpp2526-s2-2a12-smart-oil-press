#ifndef ARDUINO_H
#define ARDUINO_H

#include <QByteArray>
#include <QDebug>
#include <QString>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

class Arduino
{
public:
    Arduino();

    int connect_arduino();
    int close_arduino();
    void write_to_arduino(const QByteArray &d);
    QByteArray read_from_arduino();
    QSerialPort *getserial();
    QString getarduino_port_name() const;

private:
    QSerialPort *serial = nullptr;
    static const quint16 arduino_uno_vendor_id = 9025;
    static const quint16 arduino_uno_product_id = 67;
    QString arduino_port_name;
    bool arduino_is_available = false;
    QByteArray data;
};

#endif // ARDUINO_H
