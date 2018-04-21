#include "StdMain.h"

#include "airspeedgaugewidget.h"

#include "qcgaugewidget.h"

#include <QVBoxLayout>

AirSpeedGaugeWidget::AirSpeedGaugeWidget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

AirSpeedGaugeWidget::~AirSpeedGaugeWidget()
{
}

void AirSpeedGaugeWidget::setCurrentValue(int value)
{
    m_pAirspeedNeedle->setCurrentValue(value);
}

void AirSpeedGaugeWidget::init()
{
    m_pAirspeedGauge = new QcGaugeWidget(this);
    m_pAirspeedGauge->addArc(55);
    m_pAirspeedGauge->addDegrees(65)->setValueRange(0,100);
    QcColorBand *clrBand = m_pAirspeedGauge->addColorBand(50);
    clrBand->setValueRange(0,100);
    m_pAirspeedGauge->addValues(80)->setValueRange(0,100);
    m_pAirspeedGauge->addLabel(70)->setText("Km/h");
    QcLabelItem *lab = m_pAirspeedGauge->addLabel(40);
    lab->setText("0");
    m_pAirspeedNeedle = m_pAirspeedGauge->addNeedle(60);
    m_pAirspeedNeedle->setLabel(lab);
    m_pAirspeedNeedle->setColor(Qt::blue);
    m_pAirspeedNeedle->setValueRange(0,100);
    m_pAirspeedGauge->addBackground(7);

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->addWidget(m_pAirspeedGauge);

    setLayout(m_pMainLayout);
}


#include "moc_airspeedgaugewidget.cpp"
