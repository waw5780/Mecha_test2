#include "scale.h"

namespace Devices {
Scale::Scale(QObject *parent) : QObject(parent)
{
    m_weight = 0;
    m_retryTimer = new QTimer();
    m_retryTimer->setInterval(3000);
    connect(m_retryTimer, &QTimer::timeout, this, &Scale::habdleRetryTimer);

    m_timer = new QTimer();
    m_timer->setInterval(50);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(requestScale()));
}

Scale::~Scale() {}

void Scale::habdleRetryTimer()
{
    if (m_serialPort->error() != QSerialPort::SerialPortError::NoError) {
        setSerialPort();
    }
}

void Scale::setSerialPort()
{
    QDirIterator iterDir("/dev", QStringList() << "ttyUSB*", QDir::System);
    QString portName;
    while (iterDir.hasNext()) {
        portName = iterDir.next();
        break;
    }
    m_serialPort = new QSerialPort();
    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(19200);

    if (m_serialPort->open(QIODevice::ReadWrite) == false) {
        qDebug() << m_serialPort->errorString();
        qDebug() << "Scale Error";
    } else {
        qDebug() << "Scale connected";
        connect(m_serialPort, SIGNAL(error(QSerialPort::SerialPortError)), this,
                SLOT(serialPortError(QSerialPort::SerialPortError)));
        connect(m_serialPort, SIGNAL(readyRead()), this, SLOT(handleReadyRead()));
        m_timer->start();
    }
}

double Scale::getWeight()
{
    return m_weight;
}

void Scale::requestScale()
{
    m_serialPort->write("Q\r\n");
}

void Scale::handleReadyRead()
{
    while (m_serialPort->canReadLine()) {
        QByteArray response = m_serialPort->readLine().trimmed();
        if (!response.isEmpty()) {
            m_weight = QString::fromLatin1(response).mid(4, 8).toDouble();
            emit weightChanged(m_weight);
        }
    }
}

void Scale::serialPortError(QSerialPort::SerialPortError error)
{
    qDebug() << error;
    emit serialPortErrorHappen();
}
}
