#include "feeder_minimum_find_tab_view_model.h"
#include <iostream>

using namespace std;

namespace ViewModels {
FeederMinimumFindTabViewModel::FeederMinimumFindTabViewModel(QObject *parent) : QObject(parent)
{
    m_initPer = 0.5;
    m_firstStep = 5;
    m_secondStep = 0.5;
    m_minimumRange = 1;
    m_targetGramPerMin = 0.02;
    m_findCount = 3;
    m_findSec = 300;
    m_finalFindCount = 10;
    m_miniFeeder1Test = true;
    m_miniFeeder2Test = true;
    m_miniFeeder3Test = true;
    m_miniFeeder4Test = false;
    m_miniFeeder5Test = true;
    m_miniFeeder6Test = true;
}

FeederMinimumFindTabViewModel::~FeederMinimumFindTabViewModel() {}

double FeederMinimumFindTabViewModel::initPer() const
{
    return m_initPer;
}
void FeederMinimumFindTabViewModel::setInitPer(double newInitPer)
{
    if (m_initPer != newInitPer) {
        m_initPer = newInitPer;
        emit initPerChanged();
    }
}

double FeederMinimumFindTabViewModel::getFirstStep() const
{
    return m_firstStep;
}
void FeederMinimumFindTabViewModel::setFirstStep(double newFirstStep)
{
    if (m_firstStep != newFirstStep) {
        m_firstStep = newFirstStep;
        emit firstStepChanged();
    }
}

double FeederMinimumFindTabViewModel::getSecondStep() const
{
    return m_secondStep;
}
void FeederMinimumFindTabViewModel::setSecondStep(double newSecondStep)
{
    if (m_secondStep != newSecondStep) {
        m_secondStep = newSecondStep;
        emit secondStepChanged();
    }
}

double FeederMinimumFindTabViewModel::getMinimumRange() const
{
    return m_minimumRange;
}
void FeederMinimumFindTabViewModel::setMinimumRange(double newMinimumRange)
{
    if (m_minimumRange != newMinimumRange) {
        m_minimumRange = newMinimumRange;
        emit minimumRangeChanged();
    }
}

double FeederMinimumFindTabViewModel::getTargetGramPerMin() const
{
    return m_targetGramPerMin;
}
void FeederMinimumFindTabViewModel::setTargetGramPerMin(double newTargetGramPerMin)
{
    if (m_targetGramPerMin != newTargetGramPerMin) {
        m_targetGramPerMin = newTargetGramPerMin;
        emit targetGramPerMinChanged();
    }
}

int FeederMinimumFindTabViewModel::getFindCount() const
{
    return m_findCount;
}
void FeederMinimumFindTabViewModel::setFindCount(double newFindCount)
{
    if (m_findCount != newFindCount) {
        m_findCount = newFindCount;
        emit findCountChanged();
    }
}

int FeederMinimumFindTabViewModel::getFindSec() const
{
    return m_findSec;
}
void FeederMinimumFindTabViewModel::setFindSec(double newFindSec)
{
    if (m_findSec != newFindSec) {
        m_findSec = newFindSec;
        emit findSecChanged();
    }
}

int FeederMinimumFindTabViewModel::getFinalFindCount() const
{
    return m_finalFindCount;
}
void FeederMinimumFindTabViewModel::setFinalFindCount(double newFinalFindCount)
{
    if (m_finalFindCount != newFinalFindCount) {
        m_finalFindCount = newFinalFindCount;
        emit finalFindCountChanged();
    }
}

bool FeederMinimumFindTabViewModel::getMiniFeeder1Test() const
{
    return m_miniFeeder1Test;
}
void FeederMinimumFindTabViewModel::setMiniFeeder1Test(bool newMiniFeeder1Test)
{
    if (m_miniFeeder1Test != newMiniFeeder1Test) {
        m_miniFeeder1Test = newMiniFeeder1Test;
        emit miniFeeder1TestChanged();
    }
}

bool FeederMinimumFindTabViewModel::getMiniFeeder2Test() const
{
    return m_miniFeeder2Test;
}
void FeederMinimumFindTabViewModel::setMiniFeeder2Test(bool newMiniFeeder2Test)
{
    if (m_miniFeeder2Test != newMiniFeeder2Test) {
        m_miniFeeder2Test = newMiniFeeder2Test;
        emit miniFeeder2TestChanged();
    }
}

bool FeederMinimumFindTabViewModel::getMiniFeeder3Test() const
{
    return m_miniFeeder3Test;
}
void FeederMinimumFindTabViewModel::setMiniFeeder3Test(bool newMiniFeeder3Test)
{
    if (m_miniFeeder3Test != newMiniFeeder3Test) {
        m_miniFeeder3Test = newMiniFeeder3Test;
        emit miniFeeder3TestChanged();
    }
}

bool FeederMinimumFindTabViewModel::getMiniFeeder4Test() const
{
    return m_miniFeeder4Test;
}
void FeederMinimumFindTabViewModel::setMiniFeeder4Test(bool newMiniFeeder4Test)
{
    if (m_miniFeeder4Test != newMiniFeeder4Test) {
        m_miniFeeder4Test = newMiniFeeder4Test;
        emit miniFeeder4TestChanged();
    }
}

bool FeederMinimumFindTabViewModel::getMiniFeeder5Test() const
{
    return m_miniFeeder5Test;
}
void FeederMinimumFindTabViewModel::setMiniFeeder5Test(bool newMiniFeeder5Test)
{
    if (m_miniFeeder5Test != newMiniFeeder5Test) {
        m_miniFeeder5Test = newMiniFeeder5Test;
        emit miniFeeder5TestChanged();
    }
}

bool FeederMinimumFindTabViewModel::getMiniFeeder6Test() const
{
    return m_miniFeeder6Test;
}
void FeederMinimumFindTabViewModel::setMiniFeeder6Test(bool newMiniFeeder6Test)
{
    if (m_miniFeeder6Test != newMiniFeeder6Test) {
        m_miniFeeder6Test = newMiniFeeder6Test;
        emit miniFeeder6TestChanged();
    }
}
}
