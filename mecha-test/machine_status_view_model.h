#ifndef MACHINE_STATUS_VIEW_MODEL_H
#define MACHINE_STATUS_VIEW_MODEL_H

#include <QObject>
#include <models/main_control_model.h>
#include <iostream>

namespace ViewModels {

class MachineStatus : public QObject
{
    Q_OBJECT
public:
    explicit MachineStatus(QObject *parent = nullptr);
    ~MachineStatus();


signals:
public slots:
    void isGasChanged(bool gasOn);
private:
    DeviceControl::MainControlModel *m_mainControlModel;
    bool m_isGasOn;
};
}

#endif // MACHINE_STATUS_VIEW_MODEL_H
