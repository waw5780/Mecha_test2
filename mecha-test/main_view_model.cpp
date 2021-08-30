#include "main_view_model.h"
#include "devices/scale.h"
#include <iostream>

namespace ViewModels {
MainViewModel::MainViewModel(QObject *parent) : QObject(parent)
{
    m_nowTest = "No Test";
    m_nowFeederNum = 0;
    m_nowFeederPer = 0;
    m_nowScaleWeight = 0;
    m_nowGas = 0;
    m_powderGas = 3.0;
    m_isGasOn = false;
    m_nowGasOn = false;

    m_mainControl = new DeviceControl::MainControlModel();
    m_mainTestModel = new TestModel::MainTestModel();
    // m_machineStatus = new ViewModels::MachineStatus();
    connect(m_mainControl, &DeviceControl::MainControlModel::nowWeightChanged, this,
            &MainViewModel::setNowScaleWeight);
    connect(m_mainControl, &DeviceControl::MainControlModel::nowGasChanged, this,
            &MainViewModel::setNowGas);
    connect(m_mainControl, &DeviceControl::MainControlModel::nowFeedersIndexChanged, this,
            &MainViewModel::setNowFeederNum);
    connect(m_mainControl, &DeviceControl::MainControlModel::nowFeedersPercentChanged, this,
            &MainViewModel::setNowFeederPer);
    connect(m_mainControl, &DeviceControl::MainControlModel::isGasChanged, this,
            &MainViewModel::isGasOn);
    // connect(m_machineStatus, &MachineStatus::isGasOnChanged, this, &MainViewModel::SetIsGasOn);
}

MainViewModel::~MainViewModel() {}

//ViewModels::MachineStatus *MainViewModel::machineStatus() const
//{
//    return m_machineStatus;
//}

QString MainViewModel::getNowTest() const
{
    return m_nowTest;
}
void MainViewModel::setNowTest(QString newNowTest)
{
    if (m_nowTest != newNowTest) {
        m_nowTest = newNowTest;
        emit nowTestChanged();
    }
}

int MainViewModel::getNowFeederNum() const
{
    return m_nowFeederNum;
}
void MainViewModel::setNowFeederNum(int newNowFeederNum)
{
    if (m_nowFeederNum != newNowFeederNum) {
        m_nowFeederNum = newNowFeederNum;
        emit nowFeederNumChanged();
    }
}

double MainViewModel::getNowFeederPer() const
{
    return m_nowFeederPer;
}
void MainViewModel::setNowFeederPer(double newNowFeederPer)
{
    if (m_nowFeederPer != newNowFeederPer) {
        m_nowFeederPer = newNowFeederPer;
        emit nowFeederPerChanged();
    }
}

double MainViewModel::getNowScaleWeight() const
{
    return m_nowScaleWeight;
}
void MainViewModel::setNowScaleWeight(double newNowScaleWeight)
{
    if (m_nowScaleWeight != newNowScaleWeight) {
        m_nowScaleWeight = newNowScaleWeight;
        emit nowScaleWeightChanged();
    }
}

double MainViewModel::getNowGas() const
{
    return m_nowGas;
}
void MainViewModel::setNowGas(double newNowGas)
{
    if (m_nowGas != newNowGas) {
        m_nowGas = newNowGas;
        emit nowGasChanged();
    }
}

double MainViewModel::getPowderGas() const
{
    return m_powderGas;
}
void MainViewModel::setPowderGas(double newPowderGas)
{
    if (m_powderGas != newPowderGas) {
        m_powderGas = newPowderGas;
        emit powderGasChanged();
    }
}
void MainViewModel::isGasOn(bool gasOn)
{
    m_isGasOn = gasOn;
    m_nowGasOn = gasOn;
    qDebug() << gasOn;
}
void MainViewModel::start()
{
    m_mainTestModel->feederPerformanceTestStart();
}

bool MainViewModel::nowGasOn() const
{
    std::cout << m_isGasOn << std::endl;
    return m_isGasOn;
}
//bool MainViewModel::isGasOn() const
//{
//    return m_isGasOn;
//}
//void MainViewModel::SetIsGasOn(bool newIsGasOn)
//{
//    if (m_isGasOn != newIsGasOn) {
//        m_isGasOn = newIsGasOn;
//        emit isGasOnChanged();
//    }
//}

void MainViewModel::gasOnRequest() const
{
    qDebug() << getPowderGas();
    m_mainControl->powderGasOn(getPowderGas());
}
void MainViewModel::gasOffRequest() const
{
    qDebug() << "gas off";
    m_mainControl->powderGasOff();
}

void MainViewModel::feederCleaningOnRequest() const
{
    qDebug() << "feeder cleaning on request call";
    // emit feederCleaningOn();
}
void MainViewModel::feederCleaningOffRequest() const
{
    qDebug() << "feeder cleaning off requset";
    // emit feederCleaningOff();
}

void MainViewModel::feederResetRequest() const
{
    qDebug() << "feeder reset requset call";
    // emit feederReset();
}
}
