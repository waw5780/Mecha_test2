#include "main_test_model.h"

namespace TestModel {
MainTestModel::MainTestModel(
    QObject *parent)
    : QObject(parent)
{
    m_feederMinimumViewModel = new ViewModels::FeederMinimumFindTabViewModel;
    m_feederPerformanceViewModel = new ViewModels::FeederPerforManceTestTabViewModel;
    m_mainControlModel = new DeviceControl::MainControlModel();
    m_nowFeederRate = 0;
    m_startPercent = m_feederMinimumViewModel->getFirstStep();
    m_feederStepCount = 0;

    connect(m_mainControlModel, &DeviceControl::MainControlModel::nowWeightChanged, this,
            &MainTestModel::testWeightChanged);

    m_firstTimer = new QTimer(this);
    m_firstTimer->setTimerType(Qt::TimerType::PreciseTimer);
    m_firstTimer->setSingleShot(true);
    connect(m_firstTimer, &QTimer::timeout, this, &MainTestModel::feederMinimumTestFirstStepFinished);

    m_secondTimer = new QTimer(this);
    m_secondTimer->setTimerType(Qt::TimerType::PreciseTimer);
    m_secondTimer->setSingleShot(true);
    connect(m_secondTimer, &QTimer::timeout, this, &MainTestModel::feederMinimumTestSecondStepFinished);

    m_finalTimer = new QTimer(this);
    m_finalTimer->setTimerType(Qt::TimerType::PreciseTimer);
    m_finalTimer->setSingleShot(true);
    connect(m_finalTimer, &QTimer::timeout, this, &MainTestModel::feederMinimumTestFinalStepFinished);

    m_performanceTimer = new QTimer(this);
    m_performanceTimer->setTimerType(Qt::TimerType::PreciseTimer);
    m_performanceTimer->setSingleShot(true);
    connect(m_performanceTimer, &QTimer::timeout, this,
            &MainTestModel::feederPerformanceTestFirst);

    m_feederList.append(m_feederMinimumViewModel->getMiniFeeder1Test());
    m_feederList.append(m_feederMinimumViewModel->getMiniFeeder2Test());
    m_feederList.append(m_feederMinimumViewModel->getMiniFeeder3Test());
    m_feederList.append(m_feederMinimumViewModel->getMiniFeeder4Test());
    m_feederList.append(m_feederMinimumViewModel->getMiniFeeder5Test());
    m_feederList.append(m_feederMinimumViewModel->getMiniFeeder6Test());

    m_feederPerformanceList.append(m_feederPerformanceViewModel->getFeeder1Test());
    m_feederPerformanceList.append(m_feederPerformanceViewModel->getFeeder2Test());
    m_feederPerformanceList.append(m_feederPerformanceViewModel->getFeeder3Test());
    m_feederPerformanceList.append(m_feederPerformanceViewModel->getFeeder4Test());
    m_feederPerformanceList.append(m_feederPerformanceViewModel->getFeeder5Test());
    m_feederPerformanceList.append(m_feederPerformanceViewModel->getFeeder6Test());

    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep1());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep2());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep3());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep4());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep5());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep6());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep7());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep8());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep9());
    m_feederPerformanceStepList.append(m_feederPerformanceViewModel->getStep10());

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 11; j++) {
            m_feederTestSaver[i][j] = 0;
        }
    }

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                m_feederPerformanceSaver[i][j][k] = 0;
            }
        }
    }
}
MainTestModel::~MainTestModel()
{
}
void MainTestModel::testWeightChanged(double weight)
{
    m_nowWeight = weight;
    qDebug() << m_nowWeight;
}
void MainTestModel::feederMinimumTestStart(QVector<bool> feederList)
{
    if (feederList.at(m_feederIndex) == true) {
        feederMinimumTestFirst(m_feederIndex);
    } else {
        // emit fisrtTestFinished();
        // todo update
    }
}
void MainTestModel::feederMinimumTestFirst(int feederIndex)
{
    m_nowFeederRate += 5;
    m_nowWeight = m_mainControlModel->getScaleWeight();
    m_mainControlModel->feederOn(feederIndex, m_startPercent + m_nowFeederRate);
    m_firstTimer->setInterval(60000); // 60sec
    m_firstTimer->start();
}

void MainTestModel::feederMinimumTestFirstStepFinished()
{
    double oldWeight = m_nowWeight;
    m_nowWeight = m_mainControlModel->getScaleWeight();

    // if (weight > target)
    if (m_nowWeight - oldWeight > m_feederMinimumViewModel->getTargetGramPerMin()) {
        m_nowFeederRate -= 5.5;
        feederMinimumTestsecond(m_feederIndex);
    } else {
        feederMinimumTestFirst(m_feederIndex);
    }
}

void MainTestModel::feederMinimumTestsecond(int feederIndex)
{
    m_nowFeederRate += 0.5;
    m_nowWeight = m_mainControlModel->getScaleWeight();
    m_mainControlModel->feederOn(feederIndex, m_startPercent + m_nowFeederRate);
    m_secondTimer->setInterval(60000); // 60sec
    m_secondTimer->start();
}

void MainTestModel::feederMinimumTestSecondStepFinished()
{
    double oldWeight = m_nowWeight;
    m_nowWeight = m_mainControlModel->getScaleWeight();

    // if (weight > target)
    if (m_nowWeight - oldWeight > m_feederMinimumViewModel->getTargetGramPerMin()) {
        feederMinimumTestFinal(m_feederIndex);
    } else {
        feederMinimumTestsecond(m_feederIndex);
    }
}

void MainTestModel::feederMinimumTestFinal(int feederIndex)
{
    m_nowWeight = m_mainControlModel->getScaleWeight();
    m_mainControlModel->feederOn(feederIndex, m_startPercent + m_nowFeederRate);
    m_finalTimer->setInterval(600000); // 600sec
    m_finalTimer->start();
}

void MainTestModel::feederMinimumTestFinalStepFinished()
{
    double oldWeight = m_nowWeight;
    m_nowWeight = m_mainControlModel->getScaleWeight();
    m_feederStepCount += 1;
    if (m_feederStepCount == m_feederMinimumViewModel->getFinalFindCount()) {
        feederMinimumTestSave(m_feederIndex, m_startPercent + m_nowFeederRate, m_feederStepCount,
                              m_nowWeight - oldWeight);
    } else {
        feederMinimumTestSave(m_feederIndex, m_startPercent + m_nowFeederRate, m_feederStepCount,
                              m_nowWeight - oldWeight);
        feederMinimumTestFinal(m_feederIndex);
    }
}

void MainTestModel::feederMinimumTestSave(int feederIndex, double feederPer, int feederStep,
                                          double feederWiehgt)
{
    m_feederTestSaver[feederIndex][feederStep] = feederWiehgt;
    m_feederTestSaver[feederIndex][10] = feederPer;
}


void MainTestModel::feederPerformanceTestStart()
{
    qDebug() << m_mainControlModel->getScaleWeight();
    for (int i = 0; i < 6; i++) {
        if (m_feederPerformanceList.at(i) == true) {
            testIndexList.append(i);
        }
    }

    for (int i = 0; i < 10; i++) {
        if (m_feederPerformanceStepList.at(i) > 0) {
            testStepList.append(m_feederPerformanceStepList.at(i));
        }
    }

    m_feederIndex = 0;
    m_feederStep = 0;
    m_feederStepCount = 0;
    m_nowWeight = -1;
    qDebug() << m_feederPerformanceList;
    m_mainControlModel->splitterOn();
    feederPerformanceTestFirst();
}

void MainTestModel::feederPerformanceTestFirst()
{
    if (m_nowWeight != -1) {
        m_mainControlModel->feederOff(m_feederIndex, m_feederStep);
        double oldWeight = m_nowWeight;
        m_nowWeight = m_mainControlModel->m_nowWeight;
        double weight = m_nowWeight - oldWeight;
        qDebug() << weight;
        feederPerformanceTestSave(m_feederIndex, m_feederStep, m_feederStepCount, weight);
        m_feederStepCount += 1;
        if (m_feederPerformanceViewModel->getStepCount() == m_feederStepCount) {
            m_feederStepCount = 0;
            m_feederStep += 1;
            if (testStepList.size() == m_feederStep) {
                m_feederStep = 0;
                m_feederIndex += 1;
                if (testIndexList.size() == m_feederIndex) {
                    // Test finish
                }
            }
        }
    }
    feederPerformanceTestSecond();
}

void MainTestModel::feederPerformanceTestSecond()
{
    int testIndex = testIndexList.at(m_feederIndex);
    double testStep = testStepList.at(m_feederStep);

    m_nowWeight = m_mainControlModel->m_nowWeight;
    qDebug() << m_nowWeight;
    m_mainControlModel->feederOn(testIndex, testStep);
    qDebug() << m_feederPerformanceViewModel->getStepTime();
    m_performanceTimer->setInterval((m_feederPerformanceViewModel->getStepTime()) * 1000);
    m_performanceTimer->start();
}

void MainTestModel::feederPerformanceTestSave(int feederIndex, int feederStep,
                                              int feederStepCount, double weight)
{
    m_feederPerformanceSaver[feederIndex][feederStep][feederStepCount] = weight;
    qDebug() << m_feederPerformanceSaver;
}
//void MainTestModel::feederPerformanceTestFirst(int feederIndex, QVector<double> feederStepList)
//{
//    if (feederStepList.at(m_feederStep) > 0) {
//        m_nowWeight = m_mainControlModel->getWeight();
//        m_mainControlModel->feederOn(feederIndex, feederStepList.at(m_feederStep));
//        m_performanceTimer->setInterval(m_feederPerformanceViewModel->getStepTime());
//        m_performanceTimer->start();
//    }
//}
//void MainTestModel::feederPerformanceTestFirstFinished()
//{
//    double oldWeight = m_nowWeight;
//    m_nowWeight = m_mainControlModel->getWeight();
//    m_feederStepCount += 1;
//    if (m_feederStepCount == m_feederPerformanceViewModel->getStepCount()) {
//        feederPerformanceTestSave();
//    }
//    else {

//    }
//}
//void MainTestModel::feederPerformanceTestSave()
//{
//    int testIndex =
//}
}
