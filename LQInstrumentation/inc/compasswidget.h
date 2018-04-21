#ifndef COMPASSWIDGET_H
#define COMPASSWIDGET_H

#include <QWidget>


class QcGaugeWidget;
class QcNeedleItem;
class QVBoxLayout;

class LQINSTRUMENTATIONSHARED_EXPORT CompassWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CompassWidget(QWidget *parent = 0);
    ~CompassWidget();

    void setCurrentValue(int value);

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
    QcGaugeWidget   *m_pCompassGauge;
    QcNeedleItem    *m_pCompassNeedle;

    QVBoxLayout     *m_pMainLayout;
};

#endif // COMPASSWIDGET_H
