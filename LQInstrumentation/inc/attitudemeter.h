#ifndef ATTITUDEMETER_H
#define ATTITUDEMETER_H

#include <QWidget>


#include "qcgaugewidget.h"

class QVBoxLayout;

class LQINSTRUMENTATIONSHARED_EXPORT AttitudeMeter : public QWidget
{
    Q_OBJECT
public:
    explicit AttitudeMeter(QWidget *parent = 0);
    ~AttitudeMeter();

    void setCurrentValue(int value);

    void setCurrentPitch(int value);

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
    QcGaugeWidget   *m_pAttitudeGauge;
    QcNeedleItem    *m_pAttitudeNeedle;
    QcAttitudeMeter *m_pAttMeter;

    QVBoxLayout     *m_pMainLayout;
};

#endif // ATTITUDEMETER_H
