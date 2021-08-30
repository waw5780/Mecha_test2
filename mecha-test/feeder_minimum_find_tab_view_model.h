#pragma once

#include <QObject>

namespace ViewModels {

class FeederMinimumFindTabViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double initPer READ initPer WRITE setInitPer NOTIFY initPerChanged)
    Q_PROPERTY(double firstStep READ getFirstStep WRITE setFirstStep NOTIFY firstStepChanged)
    Q_PROPERTY(double secondStep READ getSecondStep WRITE setSecondStep NOTIFY secondStepChanged)
    Q_PROPERTY(double minimumRange READ getMinimumRange WRITE setMinimumRange NOTIFY
               minimumRangeChanged)
    Q_PROPERTY(double targetGramPerMin READ getTargetGramPerMin WRITE setTargetGramPerMin NOTIFY
               targetGramPerMinChanged)
    Q_PROPERTY(int findCount READ getFindCount WRITE setFindCount NOTIFY findCountChanged)
    Q_PROPERTY(int findSec READ getFindSec WRITE setFindSec NOTIFY findSecChanged)
    Q_PROPERTY(int finalFindCount READ getFinalFindCount WRITE setFinalFindCount NOTIFY
               finalFindCountChanged)
    Q_PROPERTY(bool miniFeeder1Test READ getMiniFeeder1Test WRITE setMiniFeeder1Test NOTIFY
               miniFeeder1TestChanged)
    Q_PROPERTY(bool miniFeeder2Test READ getMiniFeeder2Test WRITE setMiniFeeder2Test NOTIFY
               miniFeeder2TestChanged)
    Q_PROPERTY(bool miniFeeder3Test READ getMiniFeeder3Test WRITE setMiniFeeder3Test NOTIFY
               miniFeeder3TestChanged)
    Q_PROPERTY(bool miniFeeder4Test READ getMiniFeeder4Test WRITE setMiniFeeder4Test NOTIFY
               miniFeeder4TestChanged)
    Q_PROPERTY(bool miniFeeder5Test READ getMiniFeeder5Test WRITE setMiniFeeder5Test NOTIFY
               miniFeeder5TestChanged)
    Q_PROPERTY(bool miniFeeder6Test READ getMiniFeeder6Test WRITE setMiniFeeder6Test NOTIFY
               miniFeeder6TestChanged)

public:
    explicit FeederMinimumFindTabViewModel(QObject *parent = 0);
    ~FeederMinimumFindTabViewModel();

    double initPer() const;
    void setInitPer(double newInitPer);

    double getFirstStep() const;
    void setFirstStep(double newFirstStep);

    double getSecondStep() const;
    void setSecondStep(double newSecondStep);

    double getMinimumRange() const;
    void setMinimumRange(double newMinimumRange);

    double getTargetGramPerMin() const;
    void setTargetGramPerMin(double newTargetGramPerMin);

    int getFindCount() const;
    void setFindCount(double newFindCount);

    int getFindSec() const;
    void setFindSec(double newFindSec);

    int getFinalFindCount() const;
    void setFinalFindCount(double newFinalFindCount);

    bool getMiniFeeder1Test() const;
    void setMiniFeeder1Test(bool newMiniFeeder1Test);

    bool getMiniFeeder2Test() const;
    void setMiniFeeder2Test(bool newMiniFeeder2Test);

    bool getMiniFeeder3Test() const;
    void setMiniFeeder3Test(bool newMiniFeeder3Test);

    bool getMiniFeeder4Test() const;
    void setMiniFeeder4Test(bool newMiniFeeder4Test);

    bool getMiniFeeder5Test() const;
    void setMiniFeeder5Test(bool newMiniFeeder5Test);

    bool getMiniFeeder6Test() const;
    void setMiniFeeder6Test(bool newMiniFeeder6Test);

signals:
    void initPerChanged();
    void firstStepChanged();
    void secondStepChanged();
    void minimumRangeChanged();
    void targetGramPerMinChanged();
    void findCountChanged();
    void findSecChanged();
    void finalFindCountChanged();
    void miniFeeder1TestChanged();
    void miniFeeder2TestChanged();
    void miniFeeder3TestChanged();
    void miniFeeder4TestChanged();
    void miniFeeder5TestChanged();
    void miniFeeder6TestChanged();

public slots:
private:
    double m_initPer;
    double m_firstStep;
    double m_secondStep;
    double m_minimumRange;
    double m_targetGramPerMin;
    int m_findCount;
    int m_findSec;
    int m_finalFindCount;
    bool m_miniFeeder1Test;
    bool m_miniFeeder2Test;
    bool m_miniFeeder3Test;
    bool m_miniFeeder4Test;
    bool m_miniFeeder5Test;
    bool m_miniFeeder6Test;
};
}
