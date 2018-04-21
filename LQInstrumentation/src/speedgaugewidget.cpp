#include "StdMain.h"

#include "speedgaugewidget.h"

#include "qcgaugewidget.h"

#include <QVBoxLayout>

SpeedGaugeWidget::SpeedGaugeWidget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

SpeedGaugeWidget::~SpeedGaugeWidget()
{
}

void SpeedGaugeWidget::setCurrentValue(int value)
{
    m_pSpeedNeedle->setCurrentValue(value);
}

void SpeedGaugeWidget::init()
{
    m_pSpeedGauge = new QcGaugeWidget(this);
    m_pSpeedGauge->addBackground(99);
    QcBackgroundItem *bkg1 = m_pSpeedGauge->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,Qt::black);
    bkg1->addColor(1.0,Qt::white);

    QcBackgroundItem *bkg2 = m_pSpeedGauge->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::gray);
    bkg2->addColor(1.0,Qt::darkGray);

    m_pSpeedGauge->addArc(55);
    m_pSpeedGauge->addDegrees(65)->setValueRange(0,80);
    m_pSpeedGauge->addColorBand(50);

    m_pSpeedGauge->addValues(80)->setValueRange(0,80);

    m_pSpeedGauge->addLabel(70)->setText("Km/h");
    QcLabelItem *lab = m_pSpeedGauge->addLabel(40);
    lab->setText("0");
    m_pSpeedNeedle = m_pSpeedGauge->addNeedle(60);
    m_pSpeedNeedle->setLabel(lab);
    m_pSpeedNeedle->setColor(Qt::white);
    m_pSpeedNeedle->setValueRange(0,80);
    m_pSpeedGauge->addBackground(7);
    m_pSpeedGauge->addGlass(88);

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->addWidget(m_pSpeedGauge);

    setLayout(m_pMainLayout);
}

#include "moc_speedgaugewidget.cpp"
