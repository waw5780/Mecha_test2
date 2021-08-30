#include "main_control_model.h"

namespace DeviceControl {
MainControlModel::MainControlModel(QObject *parent) : QObject(parent)
{
    m_scale = new Devices::Scale();
    m_scale->setSerialPort();
    m_weight = m_scale->getWeight();

    m_grbl = new Devices::Grbl();
    // m_grbl->setSerialPort();


    connect(m_scale, &Devices::Scale::weightChanged, this, &MainControlModel::weightChanged);
    connect(m_grbl, &Devices::Grbl::powderGasChanged, this, &MainControlModel::gasChanged);
    connect(m_grbl, &Devices::Grbl::feederChanged, this, &MainControlModel::feederChanged);
}

void MainControlModel::weightChanged(double weight)
{
    m_nowWeight = m_scale->getWeight();
    emit MainControlModel::nowWeightChanged(weight);
}
void MainControlModel::gasChanged(double gas)
{
    emit MainControlModel::nowGasChanged(gas);
}
void MainControlModel::feederChanged(QVector<double> feederValues)
{
    for (int i = 0; i < feederValues.size(); i++) {
        if (feederValues.at(i) > 0) {
            emit nowFeedersIndexChanged(i + 1);
            emit nowFeedersPercentChanged(feederValues.at(i));
            break;
        }
    }
}
double MainControlModel::getScaleWeight()
{
    return m_scale->getWeight();
}

void MainControlModel::splitterOn()
{
    // m_grbl->writeSerial(QString("$E81 O1"));
    qDebug() << "Splitter On";
}
void MainControlModel::spliiterOff()
{
    m_grbl->writeSerial(QString("$E81 O0"));
}
void MainControlModel::feederOn(int feederIndex, double vibration)
{
    // m_grbl->writeSerial(QString("$E91 S%1 P%2").arg(feederIndex + 1).arg(vibration, 0, 'f', 1));
    qDebug() << "Feeder On";
}
void MainControlModel::feederOff(int feederIndex, double vibration)
{
    // m_grbl->writeSerial(QString("$E91 S%1 P%2").arg(feederIndex + 1).arg(vibration));
    qDebug() << "Feeder Off";
}
void MainControlModel::feederAllOff(double vibration)
{
    m_grbl->writeSerial(QString("$E91 S1 P%1").arg(vibration));
    m_grbl->writeSerial(QString("$E91 S2 P%1").arg(vibration));
    m_grbl->writeSerial(QString("$E91 S3 P%1").arg(vibration));
    m_grbl->writeSerial(QString("$E91 S4 P%1").arg(vibration));
    m_grbl->writeSerial(QString("$E91 S5 P%1").arg(vibration));
    m_grbl->writeSerial(QString("$E91 S6 P%1").arg(vibration));
}
void MainControlModel::powderGasOn(double gas)
{
    emit isGasChanged(true); // gas on , off status out
    //m_grbl->writeSerial(QString("$E72 S1 Q%1").arg(gas, 0, 'f', 1));
    qDebug() << gas;
}
void MainControlModel::powderGasOff(const double gas)
{
    emit isGasChanged(false); // gas on , off status out
    // m_grbl->writeSerial(QString("$E72 S1 Q%1").arg(gas));
    qDebug() << gas;
}
void MainControlModel::feederCleaningOn()
{
    powderGasOn(5);
    splitterOn();
    for (int i = 0; i < 6; i++) {
        feederOn(i, 80);
    }
}
void MainControlModel::feederCleaningOff()
{
    powderGasOff();
    spliiterOff();
    for (int i = 0; i < 6; i++) {
        feederOff(i);
    }
}
void MainControlModel::feederReset()
{
    m_grbl->writeSerial("$E90 WR");
}
}
