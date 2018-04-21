#include "StdMain.h"

#include "compasswidget.h"

#include <QVBoxLayout>

#include "qcgaugewidget.h"

CompassWidget::CompassWidget(QWidget *parent)
    : QWidget(parent)
{
    init();
}

CompassWidget::~CompassWidget()
{
}

void CompassWidget::setCurrentValue(int value)
{
    m_pCompassNeedle->setCurrentValue(value);
}

void CompassWidget::init()
{
    m_pCompassGauge = new QcGaugeWidget;

    m_pCompassGauge->addBackground(99);
    QcBackgroundItem *bkg1 = m_pCompassGauge->addBackground(92);
    bkg1->clearrColors();
    bkg1->addColor(0.1,Qt::black);
    bkg1->addColor(1.0,Qt::white);

    QcBackgroundItem *bkg2 = m_pCompassGauge->addBackground(88);
    bkg2->clearrColors();
    bkg2->addColor(0.1,Qt::white);
    bkg2->addColor(1.0,Qt::black);

    QcLabelItem *w = m_pCompassGauge->addLabel(80);
    w->setText("W");
    w->setAngle(0);
    w->setColor(Qt::white);

    QcLabelItem *n = m_pCompassGauge->addLabel(80);
    n->setText("N");
    n->setAngle(90);
    n->setColor(Qt::white);

    QcLabelItem *e = m_pCompassGauge->addLabel(80);
    e->setText("E");
    e->setAngle(180);
    e->setColor(Qt::white);

    QcLabelItem *s = m_pCompassGauge->addLabel(80);
    s->setText("S");
    s->setAngle(270);
    s->setColor(Qt::white);

    QcDegreesItem *deg = m_pCompassGauge->addDegrees(70);
    deg->setStep(5);
    deg->setMaxDegree(270);
    deg->setMinDegree(-75);
    deg->setColor(Qt::white);
    m_pCompassNeedle = m_pCompassGauge->addNeedle(60);
    m_pCompassNeedle->setNeedle(QcNeedleItem::CompassNeedle);
    m_pCompassNeedle->setValueRange(0,360);
    m_pCompassNeedle->setMaxDegree(360);
    m_pCompassNeedle->setMinDegree(0);
    m_pCompassGauge->addBackground(7);
    m_pCompassGauge->addGlass(88);

    m_pMainLayout = new QVBoxLayout(this);
    m_pMainLayout->addWidget(m_pCompassGauge);
}

#include "moc_compasswidget.cpp"
