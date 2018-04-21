#include "drawprogressbar/drawprogressbar.h"
#include <QPainter>
#include <QDebug>

DrawProgressBar::DrawProgressBar(QWidget *parent)
    : QWidget(parent)
{
    this->init();
}

DrawProgressBar::~DrawProgressBar()
{
}

void DrawProgressBar::setValue(int value)
{
    if (m_value != value)
    {
        if (value < 0 && value > iMaxNum)
        {
            return;
        }
        else
        {
            m_value = value;
        }
    }

    update();
}

void DrawProgressBar::init()
{
    m_value = 0;

    iBigRadius = 18;
    iSmallRadius = 14;

    rectHight = 4;      //定义矩形的高度
    rectWidth = 125;    //定义矩形的宽度
    rectBlueHight = 2;

    strlist << QStringLiteral("创建订单") << QStringLiteral("审核订单") << QStringLiteral("生产")
            << QStringLiteral("配送") << QStringLiteral("签收");

//    QRect myrect = rect();
    //qDebug()<<"rect size = "<<myrect;

    str_list2 << QStringLiteral("已发货") << QStringLiteral("运输中")
              << QStringLiteral("派件中") << QStringLiteral("已签收")
              << QStringLiteral("已评价");
    update();
}

void DrawProgressBar::drawBackground(QPainter* painter)
{
    painter->save();

    painter->setBrush(QColor(241,241,241));
    painter->setPen(Qt::NoPen);
    painter->drawRoundRect(rect(), 0, 0);
    painter->restore();

}

void DrawProgressBar::drawBarBackground(QPainter* painter)
{
    for (int i = 0; i < iMaxNum; i++)
    {
        //绘制灰色圆
        painter->save();
        painter->setPen(QColor(100,100,100));
        painter->setBrush(QColor(100,100,100));
        QPointF pot(RECT_WIDTH + i*(iBigRadius + rectWidth), height()/2);
        painter->drawEllipse(pot, iBigRadius, iBigRadius);
        painter->restore();


        //绘制灰色的矩形-比圆少一个
        if (i > 0)
        {
            painter->save();
            painter->setPen(QColor(100,100,100));
            painter->setBrush(QColor(100,100,100));
            painter->drawRect(RECT_WIDTH + iBigRadius/2 + (i-1)*(rectWidth + iBigRadius), height()/2 - rectHight/2, rectWidth, rectHight);
            painter->restore();
        }

        //绘制圆形下的文本-灰色
        painter->save();
        painter->setPen(QColor(100,100,100));
        QFont ft;
        ft.setPointSize(12);
        painter->setFont(ft);
        qreal textWidth = fontMetrics().width(strlist[i]);
        //qreal textHeight = fontMetrics().height();
        QPointF textPot(RECT_WIDTH - iBigRadius/2 - textWidth/2 + i*(rectWidth + iBigRadius), height()/2 + iBigRadius/2 + 35);//iBigRadius/2表示灰色圆半径，35为向下偏移量
        painter->drawText(textPot, strlist[i]);
        painter->restore();
    }

}

void DrawProgressBar::drawBlueBar(QPainter* painter)
{
    if (m_value > iMaxNum || m_value < 1)
    {
        return;
    }

    QPointF pt;
    for (int i = 0; i < m_value; i++)
    {
        //绘制蓝色的圆
        painter->save();
        painter->setPen(QColor(100,185,255));
        painter->setBrush(QColor(100,185,255));
        pt = QPointF(RECT_WIDTH + i*(rectWidth + iBigRadius), height()/2);
        painter->drawEllipse(pt, iSmallRadius, iSmallRadius);
        painter->restore();

        //绘制长条-蓝色-比圆少一个
        painter->save();
        painter->setPen(QColor(100,185,255));
        painter->setBrush(QColor(100,185,255));
        if (m_value == 1)
        {
            painter->drawRect(RECT_WIDTH + iBigRadius/2, height()/2 - rectBlueHight/2, rectWidth/2, rectBlueHight);
        }

        if (i > 0)
        {
            if (m_value == iMaxNum)
            {
                painter->drawRect(RECT_WIDTH + iBigRadius/2 + (i-1)*(rectWidth + iBigRadius), height()/2 - rectBlueHight/2, rectWidth, rectBlueHight);
            }
            else
            {
                painter->drawRect(RECT_WIDTH + iBigRadius/2 + (i-1)*(rectWidth + iBigRadius), height()/2 - rectBlueHight/2, rectWidth + rectWidth*2/3, rectBlueHight);
            }
        }
        painter->restore();

        //绘制圆形下的文本-蓝色
        painter->save();
        painter->setPen(QColor(100,185,255));
        QFont ft;
        ft.setPointSize(12);
        painter->setFont(ft);
        qreal textWidth = fontMetrics().width(strlist[i]);
        //qreal textHeight = fontMetrics().height();
        QPointF textPot(RECT_WIDTH - iBigRadius/2 - textWidth/2 + i*(rectWidth + iBigRadius), height()/2 + iBigRadius/2 + 35);//iBigRadius/2表示灰色圆半径，35为向下偏移量
        painter->drawText(textPot, strlist[i]);
        painter->restore();


        //绘制进度条上方的图形及文本
        QColor color = QColor(24,189,155);
        //绘制椭圆
        painter->save();
        painter->setPen(color);
        painter->setBrush(color);
        QRect rect(RECT_WIDTH - 78/2 + (m_value - 1)*(rectWidth + iBigRadius), height()/2 - 60,78,25);
        painter->drawRoundedRect(rect, 10,10);
        painter->restore();
        //文本
        painter->save();
        painter->setPen(Qt::white);
        ft.setPointSize(10);
        ft.setBold(true);
        painter->setFont(ft);
        qreal textWidth2=fontMetrics().width(str_list2[i]);
        qreal textHeight2=fontMetrics().height();
        QPointF textPt(RECT_WIDTH - textWidth2/2 - 1 + (m_value - 1)*(rectWidth + iBigRadius), height()/2 - 60 + 25/2+ textHeight2/2);
        painter->drawText(textPt, str_list2[i]);
        painter->restore();
        //绘制三角形
        painter->save();
        painter->setPen(color);
        painter->setBrush(color);
        QPointF firstPt(RECT_WIDTH + (m_value - 1)*(rectWidth + iBigRadius) - 10, height()/2 - 60 + 25);
        QPointF secondPt(RECT_WIDTH + 20 + (m_value - 1)*(rectWidth + iBigRadius) - 10, height()/2 - 60 + 25);
        QPointF thiirdPt(RECT_WIDTH + 10 + (m_value - 1)*(rectWidth + iBigRadius) - 10, height()/2 - 60 + 25 + 10);
        QPolygonF polygon;
        polygon << firstPt << secondPt << thiirdPt;
        painter->drawPolygon(polygon);

        painter->restore();
    }

}

void DrawProgressBar::drawBarNumber(QPainter* painter)
{
    painter->save();
    painter->setPen(Qt::white);

    for (int i = 1; i < iMaxNum + 1; i++)
    {
        QString str = QString("%1").arg(i);

        qreal textWidth=fontMetrics().width(str);
        qreal textHeight=fontMetrics().height();
        QFont ft;
        ft.setPointSize(12);
        painter->setFont(ft);
        QPointF pt(RECT_WIDTH - textWidth/2 + (i -1)*(rectWidth + iBigRadius), height()/2 + textHeight/2);
        painter->drawText(pt, str);
    }

    painter->restore();
}

void DrawProgressBar::drawPolygonTest(QPainter* painter)
{
    QColor color = QColor(24,189,155);
    //绘制椭圆
    painter->save();
    painter->setPen(color);
    painter->setBrush(color);

    QRect rect(21,55,78,25);
    painter->drawRoundedRect(rect, 10,10);
    painter->restore();

    //绘制椭圆图形及文本
    painter->save();
    painter->setPen(Qt::white);
    QFont ft;
    ft.setPointSize(10);
    ft.setBold(true);
    painter->setFont(ft);
    qreal textWidth=fontMetrics().width(str_list2[0]);
    qreal textHeight=fontMetrics().height();
    QPointF textPt(60 - textWidth/2, 55 + 25/2 + textHeight/2);
    painter->drawText(textPt, str_list2[0]);
    painter->restore();

    //绘制三角形
    painter->save();
    painter->setPen(color);
    painter->setBrush(color);
    QPolygonF polygon;
    polygon << QPointF(50,80) << QPointF(70,80) << QPointF(60,90);
    painter->drawPolygon(polygon);

    painter->restore();
}

void DrawProgressBar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter;
    painter.begin(this);
    painter.setRenderHint(QPainter::Antialiasing);

    drawBackground(&painter);
    drawBarBackground(&painter);
    drawBlueBar(&painter);
    drawBarNumber(&painter);
}
