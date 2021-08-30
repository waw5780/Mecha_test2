#ifndef FEEDER_PERFORMANCE_TEST_TAB_VIEW_MODEL_H
#define FEEDER_PERFORMANCE_TEST_TAB_VIEW_MODEL_H

#include <QObject>

namespace ViewModels {

class FeederPerforManceTestTabViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double step1 READ getStep1 WRITE setStep1 NOTIFY step1Changed)
    Q_PROPERTY(double step2 READ getStep2 WRITE setStep2 NOTIFY step2Changed)
    Q_PROPERTY(double step3 READ getStep3 WRITE setStep3 NOTIFY step3Changed)
    Q_PROPERTY(double step4 READ getStep4 WRITE setStep4 NOTIFY step4Changed)
    Q_PROPERTY(double step5 READ getStep5 WRITE setStep5 NOTIFY step5Changed)
    Q_PROPERTY(double step6 READ getStep6 WRITE setStep6 NOTIFY step6Changed)
    Q_PROPERTY(double step7 READ getStep7 WRITE setStep7 NOTIFY step7Changed)
    Q_PROPERTY(double step8 READ getStep8 WRITE setStep8 NOTIFY step8Changed)
    Q_PROPERTY(double step9 READ getStep9 WRITE setStep9 NOTIFY step9Changed)
    Q_PROPERTY(double step10 READ getStep10 WRITE setStep10 NOTIFY step10Changed)
    Q_PROPERTY(int stepTime READ getStepTime WRITE setStepTime NOTIFY stepTimeChanged)
    Q_PROPERTY(int stepCount READ getStepCount WRITE setStepCount NOTIFY stepCountChanged)
    Q_PROPERTY(bool feeder1Test READ getFeeder1Test WRITE setFeeder1Test NOTIFY feeder1TestChanged)
    Q_PROPERTY(bool feeder2Test READ getFeeder2Test WRITE setFeeder2Test NOTIFY feeder2TestChanged)
    Q_PROPERTY(bool feeder3Test READ getFeeder3Test WRITE setFeeder3Test NOTIFY feeder3TestChanged)
    Q_PROPERTY(bool feeder4Test READ getFeeder4Test WRITE setFeeder4Test NOTIFY feeder4TestChanged)
    Q_PROPERTY(bool feeder5Test READ getFeeder5Test WRITE setFeeder5Test NOTIFY feeder5TestChanged)
    Q_PROPERTY(bool feeder6Test READ getFeeder6Test WRITE setFeeder6Test NOTIFY feeder6TestChanged)

public:
    explicit FeederPerforManceTestTabViewModel(QObject *parent = 0);
    ~FeederPerforManceTestTabViewModel();

    double getStep1() const;
    void setStep1(double newStep1);

    double getStep2() const;
    void setStep2(double newStep1);

    double getStep3() const;
    void setStep3(double newStep1);

    double getStep4() const;
    void setStep4(double newStep1);

    double getStep5() const;
    void setStep5(double newStep1);

    double getStep6() const;
    void setStep6(double newStep1);

    double getStep7() const;
    void setStep7(double newStep1);

    double getStep8() const;
    void setStep8(double newStep1);

    double getStep9() const;
    void setStep9(double newStep1);

    double getStep10() const;
    void setStep10(double newStep1);

    int getStepTime() const;
    void setStepTime(int newStepTime);

    int getStepCount() const;
    void setStepCount(int newStepCount);

    bool getFeeder1Test() const;
    void setFeeder1Test(bool newFeeder1Test);

    bool getFeeder2Test() const;
    void setFeeder2Test(bool newFeeder2Test);

    bool getFeeder3Test() const;
    void setFeeder3Test(bool newFeeder3Test);

    bool getFeeder4Test() const;
    void setFeeder4Test(bool newFeeder4Test);

    bool getFeeder5Test() const;
    void setFeeder5Test(bool newFeeder5Test);

    bool getFeeder6Test() const;
    void setFeeder6Test(bool newFeeder6Test);

signals:
    void step1Changed();
    void step2Changed();
    void step3Changed();
    void step4Changed();
    void step5Changed();
    void step6Changed();
    void step7Changed();
    void step8Changed();
    void step9Changed();
    void step10Changed();
    void stepTimeChanged();
    void stepCountChanged();
    void feeder1TestChanged();
    void feeder2TestChanged();
    void feeder3TestChanged();
    void feeder4TestChanged();
    void feeder5TestChanged();
    void feeder6TestChanged();

public slots:
private:
    double m_step1;
    double m_step2;
    double m_step3;
    double m_step4;
    double m_step5;
    double m_step6;
    double m_step7;
    double m_step8;
    double m_step9;
    double m_step10;
    int m_stepTime;
    int m_stepCount;
    bool m_feeder1Test;
    bool m_feeder2Test;
    bool m_feeder3Test;
    bool m_feeder4Test;
    bool m_feeder5Test;
    bool m_feeder6Test;

};
}

#endif // FEEDER_PERFORMANCE_TEST_TAB_VIEW_MODEL_H
