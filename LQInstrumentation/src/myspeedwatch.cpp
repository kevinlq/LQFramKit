/****************************************************************************
**
** Year    		: 2017-05-30
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	: 初始版本来源于网络，本人修改了部分bug,添加了一些接口
** If you have any questions , please contact me
**
****************************************************************************/
#include "StdMain.h"

#include "myspeedwatch.h"



mySpeedWatch::mySpeedWatch(QWidget *parent): QWidget(parent)
{
    m_value = 0;
    m_minValue = 0;
    m_maxValue = 100;
    m_precision = 0;
    m_units = "km/h";
    m_title = QStringLiteral("时速表");
    m_scaleMajor = 10;
    m_scaleMinor = 10;
    m_startAngle = 60;
    m_endAngle = 60;
    m_crownColor = QColor(160,160,160);
    m_foreground = QColor(255,255,255);
    m_background = QColor(65,65,65);
    m_numericIndicatorEnabled = true;
    //setMinimumSize(QSize(80, 80));
    resize(400, 400);
}

mySpeedWatch::~mySpeedWatch()
{
    //
}

void mySpeedWatch::setValue(double value)
{
    if(value > m_maxValue){
        m_value = m_maxValue;
    }
    else if(value < m_minValue){
        m_value = m_minValue;
    }
    else{
        m_value = value;
    }
    update();
}

void mySpeedWatch::setValue(int value)
{
    setValue ((double)value);
    update();
}

void mySpeedWatch::setMinValue(int value)
{
    if (value < m_maxValue)
    {
        m_minValue = value;
        update();
    }
}

void mySpeedWatch::setMaxValue(int value)
{
    if(value > m_minValue)
    {
        m_maxValue = value;
        update();
    }
}

void mySpeedWatch::setPrecision(int precision)
{
    if (precision <= 3)
    {
        m_precision = precision;
        update();
    }
}

void mySpeedWatch::setUnits(const QString &units)
{
    m_units = units;
    update();
}

void mySpeedWatch::setTitle(const QString &title)
{
    m_title = title;
    update();
}

void mySpeedWatch::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing); 	/* 使用反锯齿(如果可用) */
    painter.translate(width() / 2, height() / 2);	/* 坐标变换为窗体中心 */
    int side = qMin(width(), height());
    painter.scale(side / 200.0, side / 200.0);		/* 比例缩放 */
    painter.setPen(Qt::NoPen);
    
    drawCrown(&painter);							/* 画边框 */
    drawBackground(&painter);						/* 画背景 */
    drawScaleNum(&painter);							/* 画刻度值 */
    drawScale(&painter);							/* 画刻度线 */
    drawTitle(&painter);							/* 画单位 */

    if(m_numericIndicatorEnabled)
        drawNumericValue(&painter);					/* 画数字显示 */
    drawIndicator(&painter);						/* 画指针 */
}

void mySpeedWatch::drawCrown(QPainter *painter)
{
    painter->save();
    int radius = 100;
    QLinearGradient lg1(0, -radius, 0, radius);
    lg1.setColorAt(0, QColor(255, 255, 255));
    lg1.setColorAt(1, QColor(166, 166, 166));
    painter->setBrush(lg1);
    painter->drawEllipse(-radius, -radius, radius << 1, radius << 1);
    painter->restore();
}

void mySpeedWatch::drawBackground(QPainter *painter)
{
    painter->save();
    painter->setBrush(m_background);
    painter->drawEllipse(-92, -92, 184, 184);
    painter->restore();
}

void mySpeedWatch::drawScaleNum(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foreground);
    double startRad = (360 - m_startAngle - 90) * (3.14 / 180);
    double deltaRad = (360 - m_startAngle - m_endAngle) * (3.14 / 180) / m_scaleMajor;
    double sina,cosa;
    int x, y;
    QFontMetricsF fm(this->font());
    double w, h, tmpVal;
    QString str;

    for (int i = 0; i <= m_scaleMajor; i++)
    {
        sina = sin(startRad - i * deltaRad);
        cosa = cos(startRad - i * deltaRad);

        tmpVal = 1.0 * i *((m_maxValue - m_minValue) / m_scaleMajor) + m_minValue;

        str = QString( "%1" ).arg(tmpVal);
        w = fm.size(Qt::TextSingleLine,str).width();
        h = fm.size(Qt::TextSingleLine,str).height();
        x = 82 * cosa - w / 2;
        y = -82 * sina + h / 4;
        painter->drawText(x, y, str);
    }
    painter->restore();
}

void mySpeedWatch::drawScale(QPainter *painter)
{
    painter->save();
    painter->rotate(m_startAngle);
    int steps = (m_scaleMajor * m_scaleMinor);
    double angleStep = (360.0 - m_startAngle - m_endAngle) / steps;
    painter->setPen(m_foreground);
    QPen pen = painter->pen();
    for (int i = 0; i <= steps; i++)
    {
        if (i % m_scaleMinor == 0)
        {
            pen.setWidth(1);
            painter->setPen(pen);
            painter->drawLine(0, 62, 0, 72);
        }
        else
        {
            pen.setWidth(0);
            painter->setPen(pen);
            painter->drawLine(0, 67, 0, 72);
        }
        painter->rotate(angleStep);
    }
    painter->restore();
}

void mySpeedWatch::drawTitle(QPainter *painter)
{
    painter->save();
    painter->setPen(m_foreground);
    painter->setBrush(m_foreground);
    QString str(m_title);
    QFontMetricsF fm(this->font());
    double w = fm.size(Qt::TextSingleLine,str).width();
    painter->drawText(-w / 2, -30, str);
    painter->restore();
}

void mySpeedWatch::drawNumericValue(QPainter *painter)
{
    QString str  =  QString("%1 %2").arg(m_value, 0, 'f', m_precision).arg(m_units);
    QFontMetricsF fm(font());
    double w = fm.size(Qt::TextSingleLine,str).width();
    painter->setPen(m_foreground);
    painter->drawText(-w / 2, 42, str);
}

void mySpeedWatch::drawIndicator(QPainter *painter)
{
    painter->save();
    QPolygon pts;
    pts.setPoints(3, -2,0, 2,0, 0,60);	/* (-2,0)/(2,0)/(0,60) */

    painter->rotate(m_startAngle);
    double degRotate =  (360.0 - m_startAngle - m_endAngle)/(m_maxValue - m_minValue)*(m_value - m_minValue);

    //画指针
    painter->rotate(degRotate);
    QRadialGradient haloGradient(0, 0, 60, 0, 0);
    haloGradient.setColorAt(0, QColor(60,60,60));
    haloGradient.setColorAt(1, QColor(160,160,160));
    painter->setPen(Qt::white);
    painter->setBrush(haloGradient);
    painter->drawConvexPolygon(pts);
    painter->restore();

    //画中心点
    QColor niceBlue(150, 150, 200);
    QConicalGradient coneGradient(0, 0, -90.0);
    coneGradient.setColorAt(0.0, Qt::darkGray);
    coneGradient.setColorAt(0.2, niceBlue);
    coneGradient.setColorAt(0.5, Qt::white);
    coneGradient.setColorAt(1.0, Qt::darkGray);
    painter->setPen(Qt::NoPen);
    painter->setBrush(coneGradient);
    painter->drawEllipse(-5, -5, 10, 10);
}

void mySpeedWatch::setScaleMajor(int scale)
{
    m_scaleMajor = scale;
    update();
}

void mySpeedWatch::setScaleMinor(int scale)
{
    m_scaleMinor = scale;
    update();
}

void mySpeedWatch::setStartAngle(int value)
{
    m_startAngle = value;
    update();
}

void mySpeedWatch::setEndAngle(int value)
{
    m_endAngle = value;
    update();
}

void mySpeedWatch::setCrownColor(QColor newColor)
{
    m_crownColor = newColor;
    update();
}

void mySpeedWatch::setForeground(QColor newForeColor)
{
    m_foreground = newForeColor;
    update();
}

void mySpeedWatch::setBackground(QColor newBackColor)
{
    m_background = newBackColor;
    update();
}

void mySpeedWatch::setNumericIndicatorEnabled(bool enable)
{
    m_numericIndicatorEnabled = enable;
    update();
}

#include "moc_myspeedwatch.cpp"
