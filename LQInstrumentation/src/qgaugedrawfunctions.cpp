/*
 *   Copyright (C) 2016 by P. Sereno
 *   http://www.qt-italia.net
 */

#include "StdMain.h"
#include "qgauge.h"


#define PI 3.1415926535


void QGauge::drawCrown(QPainter *painter)
{
    painter->save();
    QRectF rectangle(-47, -47, 94, 94);
    int startAngle = 30 * 16;
    int spanAngle = 390 * 16;
    QLinearGradient linearGrad(QPointF(-47, -47), QPointF(94, 94));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(0.3, QColor(60,60,60,250));
    QPen pen;
    QBrush brush=QBrush(linearGrad);
    pen.setBrush(brush);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->drawArc(rectangle, startAngle, spanAngle);
    painter->restore();
}

void QGauge::drawCoverGlass(QPainter *painter)
{
    painter->save();
    QLinearGradient linearGrad(QPointF(-15, -45), QPointF(90, 75));
    linearGrad.setColorAt(0, QColor(255,255,255,30));
    linearGrad.setColorAt(0.3, QColor(120,120,120,20));
    QBrush brush=QBrush(linearGrad);
    QPen pen;
    pen = QColor(0,0,0,0);
    pen.setBrush(brush);
    pen.setWidth(0);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawEllipse(-45,-45,90,90);
    painter->restore();
}

void QGauge::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setBrush(m_background);
    painter->drawEllipse(-45, -45, 90, 90);
    painter->restore();
}

void QGauge::drawTicks(QPainter *painter)
{
    painter->save();
    QPen pen=QPen(background());
    pen.setWidth(1);
    painter->setPen(pen);
    int nSteps=m_steps;
    painter->rotate(-m_startAngle) ;
    double angleStep=(-m_endAngle+m_startAngle)/m_steps;
    for ( int i=0; i<=nSteps;i++ )
    {        
        painter->drawLine(30,0,40,0 );
        painter->rotate( angleStep );
    }
    painter->restore();

    painter->save();
    pen.setWidth(1);
    painter->setPen(pen);
    double spanAngle=m_endAngle-m_startAngle;
    painter->drawArc(-28,-28,56,56, m_startAngle*16, spanAngle*16);
    painter->restore();
}

void QGauge::drawThresholdLine(QPainter *painter)
{
    QPen pen;

    double thresholdAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_threshold-m_minValue) );
    pen.setWidth(2);
    if(isEnabled())
        pen.setColor(Qt::red);
    else
        pen.setColor(Qt::gray);
    painter->setPen(pen);
    painter->drawArc(-40,-40,80,80,(int)thresholdAngle*16,(int)(-thresholdAngle+m_endAngle)*16);

}

void QGauge::drawCircularBar(QPainter *painter)
{
    painter->save();
    double valueAngle = ( m_startAngle+((m_endAngle-m_startAngle)/(m_maxValue-m_minValue))*(m_value-m_minValue));
    QRadialGradient haloGradientw(0, 0, 49, 0, 0);
    QColor color;

    if(isEnabled())
        color = foreground();
    else
        color=Qt::gray;

    haloGradientw.setColorAt(0.7, color);
    haloGradientw.setColorAt(0.9, Qt::black);
    QBrush brush=QBrush(haloGradientw);
    QPen pen = QPen(brush,barSize());
    painter->setPen(pen);
    painter->drawArc(-35,-35,70,70,(int)(m_startAngle*16),(int)((valueAngle-m_startAngle)*16));

    painter->restore();
}


void QGauge::drawLabel(QPainter *painter)
{
    painter->save();

    QRectF labelRect=QRectF(-15,20,30,20);

    if(isEnabled())
    {
        painter->setBrush(m_foreground);
        painter->setPen(m_foreground);
    }
    else
    {
        painter->setBrush(Qt::gray);
        painter->setPen(Qt::gray);
    }

    painter->drawText(labelRect,Qt::AlignCenter, m_label);
    painter->restore();
}

void QGauge::drawUnits(QPainter *painter)
{
    painter->save();

    QRectF unitsRect=QRectF(-20,-30,40,20);

    if(isEnabled())
    {
        painter->setBrush(m_foreground);
        painter->setPen(m_foreground);
    }
    else
    {
        painter->setBrush(Qt::gray);
        painter->setPen(Qt::gray);
    }

    painter->drawText(unitsRect,Qt::AlignCenter, m_units);
    painter->restore();
}

