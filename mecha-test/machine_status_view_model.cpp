#include "machine_status_view_model.h"

namespace ViewModels {
MachineStatus::MachineStatus(QObject *parent) : QObject(parent)
{
    m_isGasOn = false;

    m_mainControlModel = new DeviceControl::MainControlModel;
    connect(m_mainControlModel, &DeviceControl::MainControlModel::isGasChanged, this,
            &MachineStatus::isGasChanged);
}
MachineStatus::~MachineStatus() {}

void MachineStatus::isGasChanged(bool gasOn)
{
    m_isGasOn = gasOn;
    qDebug() << m_isGasOn;
}

}
