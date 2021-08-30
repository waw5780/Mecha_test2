#pragma once

#include <QObject>
#include <QSerialPort>
#include <QTimer>
#include <QDebug>
#include <QVector>
#include <QRegExp>

namespace Devices {
class Grbl : public QObject
{
    Q_OBJECT
public:
    explicit Grbl(QObject *parent = nullptr);
    ~Grbl();
    void writeSerial(QString data, bool isRealTime = false);
    void boardReset();
    void releaseAlarm();
    void setSerialPort();
signals:
    void errorOccur();
    void alarmOccur();
    void connectionStatus(bool isError);
    void powderGasChanged(double gas);
    void feederChanged(QVector<double> feederValues);
public slots:
    void handleReadyRead();
    void serialPortError(QSerialPort::SerialPortError error);
    void timerStatus();
private:
    QSerialPort *m_serialPort;
    void setStatusTimer();
    int m_statusCount;
    QTimer *m_statusTimer;

    int convertControllerByteToInt(QByteArray byteArray, int statusBit = 0);
    double convertIntToPercentage(int value, int precision);
};
}
