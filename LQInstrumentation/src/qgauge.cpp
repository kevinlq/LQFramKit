/*
 *   Copyright (C) 2016 by P. Sereno
 *   http://www.qt-italia.net
 */

#include "StdMain.h"

#include "qgauge.h"

QGauge::QGauge(QWidget *parent)
    : QWidget(parent)
{

   m_lcd = new QLCDNumber(this);
   setPrecision(0);
   setSteps(20);
   setBarSize(5);
   setMinimumSize(QSize(80,80));
   setMaximumSize(QSize(1024,1024));
   setStartAngle(225);
   setEndAngle(-45);
   setForeground(QColor(0, 166, 8));
   setBackground(Qt::black);
   setThresholdEnabled(false);
   setNumericIndicatorEnabled(true);
   int r,g,b;
   r=foreground().red();
   g=foreground().green();
   b=foreground().blue();
   QString style=QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
   m_lcd->setStyleSheet(style);
   m_lcd->setSegmentStyle(QLCDNumber::Flat);
   m_autodigits=true;
   setMinValue(0);
   setMaxValue(100);
   setDigitCount(5);
   setValue(0);
   setLabel("Speed");
   setUnits("Km/h");
   setThreshold(80);
   setCircularBarEnabled(true);
   setCoverGlassEnabled(true);
   setEnabled(true);
}

QGauge::~QGauge()
{
    delete m_lcd;
}

int QGauge::digits(int val)
{
    int digits = 0;
       if (val <= 0) digits = 1; // remove this line if '-' counts as a digit
       while (val) {
           val /= 10;
           digits++;
       }
       return digits;
}

void QGauge::setBarSize(int barSize)
{
    m_barSize = barSize;
    update();
}

void QGauge::setValue(double value)
{

    if(!isEnabled())
        return;

    if(value>m_maxValue)
    {
        m_value = m_maxValue;
        emit errorSignal(OutOfRange);
    }
    else
        if(value < m_minValue)
        {
            m_value = m_minValue;
            emit errorSignal(OutOfRange);
        }
        else
        {
            m_value = value;
            if(m_autodigits)
                m_lcd->setDigitCount(digits(value));
            if(m_lcd)
                m_lcd->display(m_value);
        }

    if(thresholdEnabled())
    {
        thresholdManager();

        if(value >= threshold())
        {
            QString style = QString("background-color: transparent; color: rgb(200,0,0);");
            m_lcd->setStyleSheet(style);
        }
        else
        {
            int r,g,b;
            r=foreground().red();
            g=foreground().green();
            b=foreground().blue();
            QString style = QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
            m_lcd->setStyleSheet(style);
        }
    }
    else
    {
        int r,g,b;
        r=foreground().red();
        g=foreground().green();
        b=foreground().blue();
        QString style = QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
        m_lcd->setStyleSheet(style);
    }
    update();
}

int QGauge::digitCount() const
{
    if(m_autodigits)
        return -1;

    if(m_lcd)
        return m_lcd->digitCount();
    else
        return 0;
}

void QGauge::setValue(int value)
{
   setValue((double)value);
   update();
}

void QGauge::setMinValue(double value)
{
   m_minValue = value;
   update();
}

void QGauge::setMinValue(int value)
{
  setMinValue((double)value);
}

void QGauge::setMaxValue(double value)
{
    if(value > m_minValue)
    {
        m_maxValue = value;
        update();
    }
    else
        emit errorSignal(MaxValueError);
}

void QGauge::setMaxValue(int value)
{
  setMaxValue((double)value);
}

void QGauge::setThreshold(double value)
{
    if(value > m_minValue && value < m_maxValue)
    {
        m_threshold = value;
        m_thresholdEnabled = true;
        update();
    }
    else
        emit errorSignal(ThresholdError);
}

void QGauge::setThreshold(int value)
{
  setThreshold((double)value);
}

void QGauge::setPrecision(int precision)
{
   m_precision = precision;
   update();
}

void QGauge::setLabel(QString label)
{
    m_label=label;
    update();
}

void QGauge::setUnits(QString units)
{
    m_units = units;
    update();
}

void QGauge::setDigitCount(int n_digits)
{
    if(n_digits>0)
    {
        if (m_lcd)
            m_lcd->setDigitCount(n_digits);
    }
    else
            m_autodigits = true;
}

void QGauge::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);

    int side = qMin(width(), height());
    m_lcd->setGeometry(width()/2-side/4,height()/2-side/6,side/2,side/3);
    update();
}

void QGauge::changeEvent(QEvent *event)
{
    Q_UNUSED(event);
    if(!isEnabled())
    {
        QString style = QString("background-color: transparent; color: rgb(200,200,200);");
        m_lcd->setStyleSheet(style);
        update();
    }
    else
        setValue(value());
}

void QGauge::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    int side = qMin(width(), height());
    painter.setViewport((width() - side) / 2, (height() - side) / 2,side, side);
    painter.setWindow(-50, -50, 100, 100);

    drawBackground(&painter);
    if(circularBarEnabled())
        drawCircularBar(&painter);

    drawTicks(&painter);
    if(coverGlassEnabled())
        drawCoverGlass(&painter);
    drawLabel(&painter);
    drawUnits(&painter);
    drawCrown(&painter);
    if(thresholdEnabled())
        drawThresholdLine(&painter);
}

void QGauge::setCoverGlassEnabled(bool enable)
{
    m_coverGlassEnabled = enable;
    update();
}

void QGauge::setSteps(int nSteps)
{
    if(nSteps>1)
    {
        m_steps = nSteps;
        update();
    }
    else
        nSteps = 1;
}

void QGauge::setStartAngle(int value)
{
    m_startAngle = value;
    update();
}

void QGauge::setEndAngle(int value)
{
    m_endAngle = value;
    update();
}

void QGauge::setForeground(QColor newForeColor)
{
    m_foreground = newForeColor;
    int r,g,b;
    r = foreground().red();
    g = foreground().green();
    b = foreground().blue();
    QString style = QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    m_lcd->setStyleSheet(style);
    update();
}

void QGauge::setBackground(QColor newBackColor)
{
    m_background = newBackColor;
    int r,g,b;
    r = foreground().red();
    g = foreground().green();
    b = foreground().blue();
    QString style = QString("background-color: transparent; color: rgb(%1,%2,%3);").arg(r).arg(g).arg(b);
    m_lcd->setStyleSheet(style);
    update();
}


void QGauge::thresholdManager()
{
    if(m_value > m_threshold)
     emit thresholdAlarm(true);
    else
     if(m_value < m_threshold)
      emit thresholdAlarm(false);
}

void QGauge::setThresholdEnabled(bool enable)
{
  m_thresholdEnabled = enable;
  update();
}

void QGauge::setNumericIndicatorEnabled(bool enable)
{
  m_numericIndicatorEnabled = enable;
  m_lcd->setVisible(enable);
  update();
}

void QGauge::setCircularBarEnabled(bool enable)
{
    m_circularBarEnabled = enable;
    update();
}
