#ifndef MAIN_TEST_MODEL_H
#define MAIN_TEST_MODEL_H

#include <QObject>
#include <models/main_control_model.h>
#include <feeder_minimum_find_tab_view_model.h>
#include <feeder_performance_test_tab_view_model.h>

namespace TestModel {

class MainTestModel : public QObject
{
    Q_OBJECT
public:
    explicit MainTestModel(
        QObject *parent = 0);
    ~MainTestModel();

    void feederMinimumTestStart(QVector<bool> feederList);
    void feederMinimumTestFirst(int feederIndex);
    void feederMinimumTestsecond(int feederIndex);
    void feederMinimumTestFinal(int feederIndex);
    void feederMinimumTestSave(int feederIndex, double feederPer, int feederStep,
                               double feederWiehgt);
    void feederMinimumTestStop();

    void feederPerformanceTestStart();
    void feederPerformanceTestFirst();
    void feederPerformanceTestSecond();
    void feederPerformanceTestSave(int feederIndex, int feederStep, int feederStepCount,
                                   double weight);
    void feederPerformanceTestStop();

public slots:
    void testWeightChanged(double weight);
    void feederMinimumTestFirstStepFinished();
    void feederMinimumTestSecondStepFinished();
    void feederMinimumTestFinalStepFinished();
private:
    int m_feederIndex = 0;
    int m_feederStep = 0;
    double m_startWeight;
    double m_nowFeederRate;
    double m_startPercent;
    double m_nowWeight;
    QTimer *m_firstTimer;
    QTimer *m_secondTimer;
    QTimer *m_finalTimer;
    QTimer *m_performanceTimer;
    int m_feederStepCount;
    DeviceControl::MainControlModel *m_mainControlModel;
    QVector<bool> m_feederList;
    QVector<bool> m_feederPerformanceList;
    QVector<double> m_feederPerformanceStepList;
    QVector<int> testIndexList;
    QVector<double> testStepList;
    double m_feederTestSaver[6][11];
    double m_feederPerformanceSaver[6][10][10];
    DeviceControl::MainControlModel *mainControlModel;
    ViewModels::FeederMinimumFindTabViewModel *m_feederMinimumViewModel;
    ViewModels::FeederPerforManceTestTabViewModel *m_feederPerformanceViewModel;
};
}
#endif // MAIN_TEST_MODEL_H
