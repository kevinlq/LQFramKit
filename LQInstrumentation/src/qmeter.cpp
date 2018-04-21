/*
 *   Copyright (C) 2016 by P. Sereno
 *   http://www.qt-italia.net
 */

 #include "StdMain.h"

#include "qmeter.h"


QMeter::QMeter(QWidget *parent)
    : QWidget(parent)
{
   m_precision=0;	
   m_steps=10;
   m_thresholdFlag=false;
   m_foreground=QColor(Qt::black);
   m_background=QColor(Qt::white);

   m_foreground=QColor(Qt::white);
   m_background=QColor(Qt::black);

   m_thresholdEnabled=true;
   m_numericIndicatorEnabled=true;
   setMinValue(0);
   setMaxValue(100);
   setValue(0);
   setStartAngle(225);
   setEndAngle(-45);
   setMinimumSize(QSize(80,80));
   setLabel("speed");
   setUnits("km/h");
   setThreshold(80);
   setEnableValidWindow(false);
   setBeginValidValue(40.0);
   setEndValidValue(50.0);
   setEnableWarningWindow(false);
   setBeginWarningValue(30.0);
   setEndWarningValue(60.0);

   // Needle animation parameters
   m_valAnimation.setTargetObject(this);
   m_valAnimation.setPropertyName("value");
   m_valAnimation.setDuration(1000);
}

QMeter::~QMeter()
{
}

void QMeter::setValue(double value)
{
    if(value>m_maxValue)
    {
    	m_value=m_maxValue;
    	emit errorSignal(OutOfRange);
    }
    else	
      if(value<m_minValue)
      {
        m_value=m_minValue;	
        emit errorSignal(OutOfRange);	
      }
      else      
          m_value=value;

    if(m_thresholdEnabled)
     thresholdManager();    
    update();
}

void QMeter::setValue(int value)
{
   setValue((double)value);
   update();
}

void QMeter::setMinValue(double value)
{
   m_minValue=value;
   update();
}

void QMeter::setMinValue(int value)
{
  setMinValue((double)value);
}


void QMeter::setMaxValue(double value)
{
	if(value > m_minValue)
	{
    	m_maxValue=value;
   		update();
   	}
   	else
   		emit errorSignal(MaxValueError);
}

void QMeter::setMaxValue(int value)
{
  setMaxValue((double)value);
}


void QMeter::setThreshold(double value)
{
	if(value > m_minValue && value < m_maxValue)
	{
    	m_threshold=value;
   		update();
   	}
   	else
   		emit errorSignal(ThresholdError);
}

void QMeter::setThreshold(int value)
{
  setThreshold((double)value);
}

void QMeter::setPrecision(int precision)
{
   m_precision=precision;
   update();
}

void QMeter::setPrecisionNumeric(int precision)
{
   m_precisionNumeric=precision;
   update();
}

void QMeter::setUnits(QString units)
{
  m_units=units;
  update(); 
}

void QMeter::setLabel(QString label)
{
    m_label=label;
}

void QMeter::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
	QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    int side = qMin(width(), height());

    painter.setViewport((width() - side) / 2, (height() - side) / 2,side, side);
    painter.setWindow(-50, -50, 100, 100);

    drawBackground(&painter);
    drawCoverGlass(&painter);
    drawTicks(&painter);
    drawScale(&painter);
    drawUnits(&painter);
    drawThresholdLine(&painter);
    drawWarningWindow((&painter));
    drawValidWindow(&painter);
    drawNeedle(&painter);
    drawNumericValue(&painter);
    drawLabel(&painter);
    drawCrown(&painter);
}

void QMeter::setSteps(int nSteps)
{
	m_steps=nSteps;
	update();
}

void QMeter::setStartAngle(double value)
{
	m_startAngle=value;
	update();
}

void QMeter::setEndAngle(double value)
{
	m_endAngle=value;
	update();
}

void QMeter::setForeground(QColor newForeColor)
{
	m_foreground=newForeColor;
	update();
}

void QMeter::setBackground(QColor newBackColor)
{
	m_background=newBackColor;
	update();
}


void QMeter::thresholdManager()
{
	if(m_value > m_threshold && !m_thresholdFlag)
	{
  	 m_thresholdFlag=true;
  	 emit thresholdAlarm(m_thresholdFlag);    
  	}
	else
	 if(m_value < m_threshold && m_thresholdFlag)
	 {
  	  m_thresholdFlag=false;
  	  emit thresholdAlarm(m_thresholdFlag);    
	 }    
}

void QMeter::setThresholdEnabled(bool enable)
{
  m_thresholdEnabled=enable;
  update();
}

void QMeter::setNumericIndicatorEnabled(bool enable)
{
  m_numericIndicatorEnabled=enable;
  update();
}

void QMeter::setValueWithSpringEffect(int value)
{
    m_valAnimation.setStartValue(m_value);
    m_valAnimation.setEndValue((double)value);
    m_valAnimation.setEasingCurve(QEasingCurve::OutBack);
    m_valAnimation.start();
}

void QMeter::setBeginValidValue(double beginValue)
{
    m_beginValidValue=beginValue;
    update();
}

void QMeter::setEndValidValue(double endValue)
{
    m_endValidValue=endValue;
    update();
}

void QMeter::setEnableValidWindow(bool enable)
{
    m_enableValidWindow=enable;
    update();
}

void QMeter::setBeginWarningValue(double beginValue)
{
    m_beginWarningValue=beginValue;
    update();

}

void QMeter::setEndWarningValue(double endValue)
{
    m_endWarningValue=endValue;
    update();

}

void QMeter::setEnableWarningWindow(bool enable)
{
    m_enableWarningWindow=enable;
    update();
}


#include "moc_qmeter.cpp"
