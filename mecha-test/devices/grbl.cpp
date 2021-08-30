#include "grbl.h"

namespace Devices {
Grbl::Grbl(QObject *parent) : QObject(parent)
{
    m_statusCount = 0;
}

Grbl::~Grbl()
{
}

void Grbl::setSerialPort()
{
    m_serialPort = new QSerialPort();
    m_serialPort->setPortName("/dev/ttySAC0");
    m_serialPort->setBaudRate(115200);
    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if (m_serialPort->open(QIODevice::ReadWrite) == false)
        qDebug() << m_serialPort->errorString();
    else {
        qDebug() << "grbl Connected";
        connect(m_serialPort, SIGNAL(error(QSerialPort::SerialPortError)), this,
                SLOT(serialPortError(QSerialPort::SerialPortError)));
        connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(handleReadyRead()));
    }
    boardReset();
    releaseAlarm();
    setStatusTimer();
}

void Grbl::setStatusTimer()
{
    m_statusTimer = new QTimer();
    m_statusTimer->setInterval(100);
    connect(m_statusTimer,
            SIGNAL(timeout()),
            this,
            SLOT(timerStatus()));
    m_statusTimer->start();
}

void Grbl::timerStatus()
{
    if (m_serialPort->isRequestToSend()) {
        if (m_statusCount == 5) {
            emit connectionStatus(true);
            m_statusCount = 100;
        }
        if (m_statusCount < 5) {
            writeSerial("?", true);
            m_statusCount++;
        }
    }
}

void Grbl::boardReset()
{
    writeSerial(QString(char(0x18)), true);
    m_statusCount = 0;
    emit connectionStatus(false);
}

void Grbl::releaseAlarm()
{
    writeSerial("$X");
}

void Grbl::writeSerial(QString data, bool isRealTime)
{
    QByteArray writeData = (isRealTime ?  data : data + "\n").toLatin1();
    const qint64 bytesWritten = m_serialPort->write(writeData);
    if (bytesWritten == -1) {
        qDebug() << QObject::tr("Failed to write the data to port %1, error: %2")
                 .arg(m_serialPort->portName())
                 .arg(m_serialPort->errorString());
    } else if (bytesWritten != writeData.size()) {
        qDebug() << QObject::tr("Failed to write all the data to port %1, error: %2")
                 .arg(m_serialPort->portName())
                 .arg(m_serialPort->errorString());
    }
}

int Grbl::convertControllerByteToInt(QByteArray byteArray, int statusBit)
{
    QByteArray sumByteArray;
    for (auto iter = byteArray.begin(); iter != byteArray.end(); iter++) {
        sumByteArray += QByteArray::number((uchar) * iter, 2)
                        .mid(iter == byteArray.begin() ? 1 + statusBit : 1);
    }
    return sumByteArray.toInt(Q_NULLPTR, 2);
}

double Grbl::convertIntToPercentage(int value, int precision)
{
    return (double) value / precision;
}

void Grbl::handleReadyRead()
{
    while (m_serialPort->canReadLine()) {
        QByteArray response = m_serialPort->readLine().trimmed();
        if (!response.isEmpty()) {
            QString responseString = QString::fromLatin1(response);
//            qDebug() << responseString;
            if (responseString.contains("error")) {
                emit errorOccur();
            } else if (responseString.at(0) == '<') {
                m_statusCount = 0;
                static QRegExp gasReg("\\|G");
                static QRegExp feederReg("\\|F");
                if (gasReg.indexIn(responseString) != -1) {
                    int index = gasReg.pos(0) + gasReg.matchedLength();
                    emit powderGasChanged(
                        (double) convertControllerByteToInt(response.mid(index, 2)) / 10
                    );
                } else if (feederReg.indexIn(responseString) != -1) {
                    int index = feederReg.pos(0) + feederReg.matchedLength();
                    QVector<double> feederValues;
                    for (int feederIndex = 0; feederIndex < 6; feederIndex++) {
                        feederValues.append(
                            convertIntToPercentage(
                                convertControllerByteToInt(
                                    response.mid(index + 3 * feederIndex, 3), 5), 100));
                    }
                    emit feederChanged(feederValues);
                }
            } else {
                static QRegExp alarmReg("ALARM:(\\d+)");
                if (alarmReg.indexIn(responseString) != -1) {
                    emit alarmOccur();
                }
            }
        }
    }
}

void Grbl::serialPortError(QSerialPort::SerialPortError error)
{
    qDebug() << "grbl port error";
    qDebug() << error;
}

}
