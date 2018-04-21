#ifndef AIRSPEEDGAUGEWIDGET_H
#define AIRSPEEDGAUGEWIDGET_H

#include <QWidget>

class QcGaugeWidget;
class QcNeedleItem;
class QVBoxLayout;

class LQINSTRUMENTATIONSHARED_EXPORT AirSpeedGaugeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AirSpeedGaugeWidget(QWidget *parent = 0);
    ~AirSpeedGaugeWidget();

    void setCurrentValue(int value);

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
    QcGaugeWidget  *m_pAirspeedGauge;
    QcNeedleItem   *m_pAirspeedNeedle;

    QVBoxLayout    *m_pMainLayout;
};

#endif // AIRSPEEDGAUGEWIDGET_H
