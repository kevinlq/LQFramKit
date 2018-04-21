#ifndef SPEEDGAUGEWIDGET_H
#define SPEEDGAUGEWIDGET_H

#include <QWidget>

class QcGaugeWidget;
class QcNeedleItem;
class QVBoxLayout;

class LQINSTRUMENTATIONSHARED_EXPORT SpeedGaugeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SpeedGaugeWidget(QWidget *parent = 0);
    ~SpeedGaugeWidget();

    void setCurrentValue(int value);

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
    QcGaugeWidget   *m_pSpeedGauge;
    QcNeedleItem    *m_pSpeedNeedle;
    QVBoxLayout     *m_pMainLayout;
};

#endif // SPEEDGAUGEWIDGET_H
