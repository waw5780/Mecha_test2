#ifndef MAIN_VIEW_MODEL_H
#define MAIN_VIEW_MODEL_H

#include <QObject>
#include <models/main_control_model.h>
#include <machine_status_view_model.h>
#include <models/main_test_model.h>

namespace ViewModels {

class MainViewModel : public QObject
{
    Q_OBJECT
    // Q_PROPERTY(ViewModels::MachineStatus *machineStatus READ machineStatus CONSTANT)
    Q_PROPERTY(QString nowTest READ getNowTest WRITE setNowTest NOTIFY nowTestChanged)
    Q_PROPERTY(int nowFeederNum READ getNowFeederNum WRITE setNowFeederNum NOTIFY nowFeederNumChanged)
    Q_PROPERTY(double nowFeederPer READ getNowFeederPer WRITE setNowFeederPer NOTIFY
               nowFeederPerChanged)
    Q_PROPERTY(double nowScaleWeight READ getNowScaleWeight WRITE setNowScaleWeight NOTIFY
               nowScaleWeightChanged)
    Q_PROPERTY(double nowGas READ getNowGas WRITE setNowGas NOTIFY nowGasChanged)
    Q_PROPERTY(double powderGas READ getPowderGas WRITE setPowderGas NOTIFY powderGasChanged)
    Q_PROPERTY(bool nowGasOn READ nowGasOn CONSTANT)
    // Q_PROPERTY(bool isGasOn READ isGasOn WRITE setIsGasOn NOTIFY isGasOnChanged)

public:
    explicit MainViewModel(QObject *parent = 0);
    ~MainViewModel();

    QString getNowTest() const;
    void setNowTest(QString newNowTest);

    int getNowFeederNum() const;
    void setNowFeederNum(int newNowFeederNum);

    double getNowFeederPer() const;
    void setNowFeederPer(double newNowFeederPer);

    double getNowScaleWeight() const;
    void setNowScaleWeight(double newNowScaleWeight);

    double getNowGas() const;
    void setNowGas(double newNowGas);

    double getPowderGas() const;
    void setPowderGas(double newPowderGas);

    bool nowGasOn() const;

    // bool isGasOn() const;
    // void SetIsGasOn(bool newIsGasOn);

    // ViewModels::MachineStatus *machineStatus() const;

signals:
    void nowTestChanged();
    void nowFeederNumChanged();
    void nowFeederPerChanged();
    void nowScaleWeightChanged();
    void nowGasChanged();
    void powderGasChanged();
    // void isGasOnChanged();

public slots:
    // void gasOn(double gas) const;
    // void gasOff() const;
    // void feederCleaningOn() const;
    // void feederCleaningOff() const;
    // void feederReset() const;

    void gasOnRequest() const;
    void gasOffRequest() const;
    void feederCleaningOnRequest() const;
    void feederCleaningOffRequest() const;
    void feederResetRequest() const;
    void isGasOn(bool gasOn);
    void start();
private:
    QString m_nowTest;
    int m_nowFeederNum;
    double m_nowFeederPer;
    double m_nowScaleWeight;
    double m_nowGas;
    double m_powderGas;
    bool m_isGasOn;
    bool m_nowGasOn;
    DeviceControl::MainControlModel *m_mainControl;
    TestModel::MainTestModel *m_mainTestModel;
    // ViewModels::MachineStatus *m_machineStatus;
};
}

#endif // MAIN_VIEW_MODEL_H
