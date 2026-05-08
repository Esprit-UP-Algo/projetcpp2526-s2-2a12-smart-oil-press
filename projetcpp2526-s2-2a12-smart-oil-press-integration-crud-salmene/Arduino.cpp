#include "Arduino.h"

Arduino::Arduino()
    : serial(new QSerialPort)
{
}

int Arduino::connect_arduino()
{
    arduino_is_available = false;
    arduino_port_name.clear();

    const QList<QSerialPortInfo> ports = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &serialPortInfo : ports) {
        const bool hasKnownIds =
            serialPortInfo.hasVendorIdentifier()
            && serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id
            && serialPortInfo.hasProductIdentifier()
            && serialPortInfo.productIdentifier() == arduino_uno_product_id;

        const QString descriptor =
            (serialPortInfo.description() + " " + serialPortInfo.manufacturer()).toLower();
        const bool looksLikeArduino =
            descriptor.contains("arduino")
            || descriptor.contains("usb serial")
            || descriptor.contains("ch340")
            || descriptor.contains("wch");

        if (hasKnownIds || looksLikeArduino) {
            arduino_is_available = true;
            arduino_port_name = serialPortInfo.portName();
            break;
        }
    }

    if (!arduino_is_available) {
        return -1;
    }

    if (serial->isOpen()) {
        return 0;
    }

    serial->setPortName(arduino_port_name);
    if (!serial->open(QSerialPort::ReadWrite)) {
        return 1;
    }

    serial->setBaudRate(QSerialPort::Baud9600);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    return 0;
}

int Arduino::close_arduino()
{
    if (serial && serial->isOpen()) {
        serial->close();
        return 0;
    }
    return 1;
}

void Arduino::write_to_arduino(const QByteArray &d)
{
    if (serial && serial->isWritable()) {
        serial->write(d);
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}

QByteArray Arduino::read_from_arduino()
{
    if (serial && serial->isReadable()) {
        data = serial->readAll();
        return data;
    }
    return QByteArray();
}

QSerialPort *Arduino::getserial()
{
    return serial;
}

QString Arduino::getarduino_port_name() const
{
    return arduino_port_name;
}
