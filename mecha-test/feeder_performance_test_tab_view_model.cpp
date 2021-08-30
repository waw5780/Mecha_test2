#include "feeder_performance_test_tab_view_model.h"

namespace ViewModels {
FeederPerforManceTestTabViewModel::FeederPerforManceTestTabViewModel(QObject *parent) : QObject(
        parent)
{
    m_step1 = 10;
    m_step2 = 20;
    m_step3 = 30;
    m_step4 = 40;
    m_step5 = 0;
    m_step6 = 0;
    m_step7 = 0;
    m_step8 = 0;
    m_step9 = 0;
    m_step10 = 0;
    m_stepTime = 300;
    m_stepCount = 10;
    m_feeder1Test = true;
    m_feeder2Test = false;
    m_feeder3Test = true;
    m_feeder4Test = true;
    m_feeder5Test = true;
    m_feeder6Test = true;
}

FeederPerforManceTestTabViewModel::~FeederPerforManceTestTabViewModel() {}

double FeederPerforManceTestTabViewModel::getStep1() const
{
    return m_step1;
}
void FeederPerforManceTestTabViewModel::setStep1(double newStep1)
{
    if (m_step1 != newStep1) {
        m_step1 = newStep1;
        emit step1Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep2() const
{
    return m_step2;
}
void FeederPerforManceTestTabViewModel::setStep2(double newStep2)
{
    if (m_step2 != newStep2) {
        m_step2 = newStep2;
        emit step2Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep3() const
{
    return m_step3;
}
void FeederPerforManceTestTabViewModel::setStep3(double newStep3)
{
    if (m_step3 != newStep3) {
        m_step3 = newStep3;
        emit step3Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep4() const
{
    return m_step4;
}
void FeederPerforManceTestTabViewModel::setStep4(double newStep4)
{
    if (m_step4 != newStep4) {
        m_step4 = newStep4;
        emit step4Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep5() const
{
    return m_step5;
}
void FeederPerforManceTestTabViewModel::setStep5(double newStep5)
{
    if (m_step5 != newStep5) {
        m_step5 = newStep5;
        emit step5Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep6() const
{
    return m_step6;
}
void FeederPerforManceTestTabViewModel::setStep6(double newStep6)
{
    if (m_step6 != newStep6) {
        m_step6 = newStep6;
        emit step6Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep7() const
{
    return m_step7;
}
void FeederPerforManceTestTabViewModel::setStep7(double newStep7)
{
    if (m_step7 != newStep7) {
        m_step7 = newStep7;
        emit step7Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep8() const
{
    return m_step8;
}
void FeederPerforManceTestTabViewModel::setStep8(double newStep8)
{
    if (m_step8 != newStep8) {
        m_step8 = newStep8;
        emit step8Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep9() const
{
    return m_step9;
}
void FeederPerforManceTestTabViewModel::setStep9(double newStep9)
{
    if (m_step9 != newStep9) {
        m_step9 = newStep9;
        emit step9Changed();
    }
}

double FeederPerforManceTestTabViewModel::getStep10() const
{
    return m_step10;
}
void FeederPerforManceTestTabViewModel::setStep10(double newStep10)
{
    if (m_step10 != newStep10) {
        m_step10 = newStep10;
        emit step10Changed();
    }
}

int FeederPerforManceTestTabViewModel::getStepTime() const
{
    return m_stepTime;
}
void FeederPerforManceTestTabViewModel::setStepTime(int newStepTime)
{
    if (m_stepTime != newStepTime) {
        m_stepTime = newStepTime;
        emit stepTimeChanged();
    }
}

int FeederPerforManceTestTabViewModel::getStepCount() const
{
    return m_stepCount;
}
void FeederPerforManceTestTabViewModel::setStepCount(int newStepCount)
{
    if (m_stepCount != newStepCount) {
        m_stepCount = newStepCount;
        emit stepCountChanged();
    }
}

bool FeederPerforManceTestTabViewModel::getFeeder1Test() const
{
    return m_feeder1Test;
}
void FeederPerforManceTestTabViewModel::setFeeder1Test(bool newFeeder1Test)
{
    if (m_feeder1Test != newFeeder1Test) {
        m_feeder1Test = newFeeder1Test;
        emit feeder1TestChanged();
    }
}

bool FeederPerforManceTestTabViewModel::getFeeder2Test() const
{
    return m_feeder2Test;
}
void FeederPerforManceTestTabViewModel::setFeeder2Test(bool newFeeder2Test)
{
    if (m_feeder2Test != newFeeder2Test) {
        m_feeder2Test = newFeeder2Test;
        emit feeder2TestChanged();
    }
}

bool FeederPerforManceTestTabViewModel::getFeeder3Test() const
{
    return m_feeder3Test;
}
void FeederPerforManceTestTabViewModel::setFeeder3Test(bool newFeeder3Test)
{
    if (m_feeder3Test != newFeeder3Test) {
        m_feeder3Test = newFeeder3Test;
        emit feeder3TestChanged();
    }
}

bool FeederPerforManceTestTabViewModel::getFeeder4Test() const
{
    return m_feeder4Test;
}
void FeederPerforManceTestTabViewModel::setFeeder4Test(bool newFeeder4Test)
{
    if (m_feeder4Test != newFeeder4Test) {
        m_feeder4Test = newFeeder4Test;
        emit feeder4TestChanged();
    }
}

bool FeederPerforManceTestTabViewModel::getFeeder5Test() const
{
    return m_feeder5Test;
}
void FeederPerforManceTestTabViewModel::setFeeder5Test(bool newFeeder5Test)
{
    if (m_feeder5Test != newFeeder5Test) {
        m_feeder5Test = newFeeder5Test;
        emit feeder5TestChanged();
    }
}

bool FeederPerforManceTestTabViewModel::getFeeder6Test() const
{
    return m_feeder6Test;
}
void FeederPerforManceTestTabViewModel::setFeeder6Test(bool newFeeder6Test)
{
    if (m_feeder6Test != newFeeder6Test) {
        m_feeder6Test = newFeeder6Test;
        emit feeder6TestChanged();
    }
}
}
