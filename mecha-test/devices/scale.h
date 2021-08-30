#pragma once
#include <QObject>
#include <QDirIterator>
#include <QtSerialPort/QSerialPort>
#include <QTimer>
#include <QDebug>
#include <iostream>

namespace Devices {
class Scale: public QObject
{
    Q_OBJECT
public:
    explicit Scale(QObject *parent = nullptr);
    ~Scale();

    double getWeight();

signals:
    void weightChanged(double weight);
    void serialPortErrorHappen();
public slots:
    void setSerialPort();
    void requestScale();
    void serialPortError(QSerialPort::SerialPortError error);
    void handleReadyRead();
    void habdleRetryTimer();
private:
    QSerialPort *m_serialPort;
    QTimer *m_timer;
    double m_weight;
    QTimer *m_retryTimer;
};
}
