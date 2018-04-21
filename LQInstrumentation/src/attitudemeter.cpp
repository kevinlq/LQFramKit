#include "StdMain.h"

#include "attitudemeter.h"

#include <QVBoxLayout>

AttitudeMeter::AttitudeMeter(QWidget *parent)
    : QWidget(parent)
{
    init();
}

AttitudeMeter::~AttitudeMeter()
{
}

void AttitudeMeter::setCurrentValue(int value)
{
    m_pAttitudeNeedle->setCurrentValue( 90 - value);
    m_pAttMeter->setCurrentRoll(value);
}

void AttitudeMeter::setCurrentPitch(int value)
{
    m_pAttMeter->setCurrentPitch(value);
}

void AttitudeMeter::init()
{
    m_pAttitudeGauge = new QcGaugeWidget;
    m_pAttitudeGauge->addBackground(99);
    QcBackgroundItem *bkg = m_pAttitudeGauge->addBackground(92);
    bkg->clearrColors();
    bkg->addColor(0.1,Qt::black);
    bkg->addColor(1.0,Qt::white);
    m_pAttMeter = m_pAttitudeGauge->addAttitudeMeter(88);

    m_pAttitudeNeedle = m_pAttitudeGauge->addNeedle(70);
    m_pAttitudeNeedle->setMinDegree(0);
    m_pAttitudeNeedle->setMaxDegree(180);
    m_pAttitudeNeedle->setValueRange(0,180);
    m_pAttitudeNeedle->setCurrentValue(90);
    m_pAttitudeNeedle->setColor(Qt::white);
    m_pAttitudeNeedle->setNeedle(QcNeedleItem::AttitudeMeterNeedle);
    m_pAttitudeGauge->addGlass(80);

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->addWidget(m_pAttitudeGauge);

    setLayout(m_pMainLayout);
}


#include "moc_attitudemeter.cpp"
