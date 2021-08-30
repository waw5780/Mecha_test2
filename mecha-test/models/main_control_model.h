#pragma once

#include "devices/scale.h"
#include "devices/grbl.h"
#include <QObject>

namespace DeviceControl {
class MainControlModel : public QObject
{
    Q_OBJECT
public:
    explicit MainControlModel(QObject *parent = 0);

    void splitterOn();
    void spliiterOff();
    void feederOn(int feederIndex, double vibration);
    void feederOff(int feederIndex, double vibration = 0);
    void feederAllOff(double vibration = 0);
    void powderGasOn(double gas);
    void powderGasOff(const double gas = 0.0);
    void feederCleaningOn();
    void feederCleaningOff();
    void feederReset();
    double getScaleWeight();

    double m_nowWeight;
signals:
    void nowWeightChanged(double weight);
    void nowGasChanged(double gas);
    void nowFeedersChanged(int feederIndex);
    void nowFeedersIndexChanged(int feederIndex);
    void nowFeedersPercentChanged(double feederPercent);
    void isGasChanged(bool gasOn);
public slots:
    void weightChanged(double weight);
    void gasChanged(double gas);
    void feederChanged(QVector<double> feederValues);
private:
    Devices::Scale *m_scale;
    Devices::Grbl *m_grbl;
    double m_weight;
};
}
