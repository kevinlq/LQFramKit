/*
 *   Copyright (C) 2016 by P. Sereno
 *   http://www.qt-italia.net
 */

#include "StdMain.h"
#include "qmeter.h"



#define PI 3.1415926535


void QMeter::drawCrown(QPainter *painter)
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

void QMeter::drawBackground(QPainter *painter)
{
	painter->setBrush(m_background);
	painter->drawEllipse(-45, -45, 90, 90);
}

void QMeter::drawTicks(QPainter *painter)
{
	painter->save();
    QPen pen=QPen(m_foreground);
    pen.setWidth(0);
    painter->setPen(pen);
	int nSteps=m_steps;
	painter->rotate(-m_startAngle) ;	
	double angleStep=(-m_endAngle+m_startAngle)/m_steps;
    for ( int i=0; i<=nSteps;i++ )
	{
        painter->drawLine(28,0,30,0 );
        painter->rotate( angleStep/1 );
	}		
	painter->restore();	

    pen.setWidth(0);
    painter->setPen(pen);
    double spanAngle=m_endAngle-m_startAngle;
    painter->drawArc(-28,-28,56,56, m_startAngle*16, spanAngle*16);
}


void QMeter::drawScale(QPainter *painter)
{
	painter->save();
	painter->setPen(m_foreground);
    double startRad=m_startAngle*PI/180.0;
    startRad+=PI/2;
    double deltaRad=(m_endAngle-m_startAngle)/(m_steps)*(PI/180);
	double sina,cosa;
	for ( int i=0; i<=m_steps; i++ ) 
	{
		sina=sin((double)(startRad+i*deltaRad));
		cosa=cos((double)(startRad+i*deltaRad));			
		double tmpVal=i*((m_maxValue-m_minValue)/m_steps);
		tmpVal+=m_minValue;
		QString str = QString( "%1" ).arg(tmpVal,0,'f',m_precision);
		QFontMetricsF fm( this->font() );
		double w=fm.size(Qt::TextSingleLine,str).width();
		double h=fm.size(Qt::TextSingleLine,str).height();
        int x=(int)((38*sina)-(w/2));
        int y=(int)((38*cosa)+(h/4));
		painter->drawText(x,y,str);	
	}		
	painter->restore();	
}

void QMeter::drawUnits(QPainter *painter)
{
	painter->setPen(m_foreground);
	painter->setBrush(m_foreground);
    painter->setPen(m_foreground);
    QRectF labelRect=QRectF(-15,-20,30,10);
    painter->drawText(labelRect,Qt::AlignCenter, m_units);
}

void QMeter::drawNumericValue(QPainter *painter)
{
    if(!enableNumericIndicator())
        return;
    painter->save();
    QString str = QString( "%1" ).arg(m_value,0,'f',m_precisionNumeric);
    QFont f=font();
    QFontMetricsF fm( f );
	QColor color;
	
	if(!m_thresholdFlag)
     color=Qt::white;
	else
	 color=Qt::red;

    QRectF labelRect=QRectF(-15,25,30,10);

    painter->setPen(color);
    QFont font = painter->font();
    int pointSize=font.pointSize();
    pointSize++;
    pointSize++;
    font.setPointSize(pointSize);
    font.setBold(true);
    painter->setFont(font);
    painter->drawText(labelRect,Qt::AlignCenter, str);

    painter->restore();
}

void QMeter::drawNeedle(QPainter *painter)
{
	painter->save();

	painter->rotate(-90.0); 
	QPolygon pts;
    pts.setPoints( 3, -2,0,  2,0,  0,30 );
    QPolygon shadow;
    shadow.setPoints(3, -1,0, 1,0, 0,29);
	int degRotate=0;

    degRotate = (int)( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_value-m_minValue) );	 
	 
	painter->rotate( -degRotate );
    QRadialGradient haloGradient(0, 0, 20, 0, 0);
    haloGradient.setColorAt(0.0, QColor(255,120,120));
    haloGradient.setColorAt(1.0, QColor(200,20,20));
    QColor color=QColor(Qt::darkRed);
    color.setAlpha(90);
    painter->setPen(color);
	painter->setBrush(haloGradient);
	painter->drawConvexPolygon( pts );

    painter->setBrush(QColor(255,120,120));
    painter->drawConvexPolygon( shadow );

	painter->restore();
	
    // draw needle hat
    QLinearGradient linearGrad(QPointF(-7, -7), QPointF(14, 14));
    linearGrad.setColorAt(0, Qt::white);
    linearGrad.setColorAt(1, Qt::black);
    painter->setPen(Qt::NoPen);
    painter->setBrush(linearGrad);
    painter->drawEllipse(-7, -7, 14, 14);
}

void QMeter::drawThresholdLine(QPainter *painter)
{
    if(!enableThreshold())
        return;

    painter->save();
    QPen pen;
    double thresholdAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_threshold-m_minValue) );
    pen.setWidth(3);

    pen.setColor(Qt::green);
    painter->setPen(pen);
    painter->drawArc(-25,-25,50,50,(int)m_startAngle*16,(int)(thresholdAngle-m_startAngle)*16);

    pen.setColor(Qt::red);
    painter->setPen(pen);
    painter->drawArc(-25,-25,50,50,(int)thresholdAngle*16,(int)(-thresholdAngle+m_endAngle)*16);
    painter->restore();
}

void QMeter::drawCoverGlass(QPainter *painter)
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

void QMeter::drawLabel(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foreground);
    painter->setBrush(m_foreground);
    painter->setPen(m_foreground);

    QFontMetricsF fm( this->font() );
    double w=fm.size(Qt::TextSingleLine,m_label).width();

    QRectF labelRect=QRectF(-20,15,40,10);

    if(w>labelRect.width())
    {
        QFont font = painter->font();
        int pointSize=font.pointSize();
        pointSize--;
        font.setPointSize(pointSize);
        setFont(font);
    }

    painter->drawText(labelRect,Qt::AlignCenter, m_label);
    painter->restore();
}

void QMeter::drawWarningWindow(QPainter *painter)
{
    if(enableWarningWindow())
    {

        QPen pen;

        double beginAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_beginWarningValue-m_minValue) );
        double endAngle =( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_endWarningValue-m_minValue) );

        pen.setWidth(2);

        pen.setColor(Qt::yellow);
        painter->setPen(pen);
        if(beginAngle>endAngle)
            painter->drawArc(-25,-25,50,50,(int)endAngle*16,(int)(beginAngle-endAngle)*16);
        else
            painter->drawArc(-25,-25,50,50,(int)beginAngle*16,(int)(endAngle-beginAngle)*16);
    }
}

void QMeter::drawValidWindow(QPainter *painter)
{
    if(enableValidWindow())
    {
        QPen pen;

        double beginAngle = ( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_beginValidValue-m_minValue) );
        double endAngle =( m_startAngle+(m_endAngle-m_startAngle)/(m_maxValue-m_minValue)*(m_endValidValue-m_minValue) );

        pen.setWidth(2);

        pen.setColor(Qt::green);
        painter->setPen(pen);
        if(beginAngle>endAngle)
            painter->drawArc(-25,-25,50,50,(int)endAngle*16,(int)(beginAngle-endAngle)*16);
        else
            painter->drawArc(-25,-25,50,50,(int)beginAngle*16,(int)(endAngle-beginAngle)*16);
    }
}
