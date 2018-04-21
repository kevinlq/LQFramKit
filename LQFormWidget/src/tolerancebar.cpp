#include "StdMain.h"
#include "tolerancebar.h"

#include <QPainter>
#include <QMouseEvent>

struct TolerDataPrivate{
    int     i_val;
    int     i_num;
    float   f_WR;
    float   f_HR;
    bool    b_pressed;
    int     i_painterWidth;
    int     i_painterHeight;
};

ToleranceBar::ToleranceBar(QWidget *parent) :
    QWidget(parent)
{
    init ();
}

ToleranceBar::~ToleranceBar()
{
}

void ToleranceBar::init()
{
    d = new TolerDataPrivate;

    d->i_val = 0;
    d->i_num = 12;
    d->i_painterHeight = 150;
    d->i_painterWidth = 510;
    d->f_WR = (this->width() * 1.0) / d->i_painterWidth;
    d->f_HR = (this->height() * 1.0) / d->i_painterHeight;
    d->b_pressed = false;
}

void ToleranceBar::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setWindow(0, 0, d->i_painterWidth, d->i_painterHeight);
    painter.setRenderHint(QPainter::Antialiasing);

    //绘制多边形
    QPolygon poly1,poly2;
    //添加三个点
    poly1 << QPoint(0,d->i_painterHeight - 10)
          << QPoint((d->i_painterWidth-10),d->i_painterHeight-10)
          << QPoint((d->i_painterWidth-10),0) ;
    painter.setBrush(QColor(40, 40, 40));
    painter.setPen(QPen(Qt::black, 5));
    painter.drawPolygon(poly1);


    poly2 << QPoint(0,d->i_painterHeight - 10)
          << QPoint((d->i_painterWidth - 10) * d->i_val / d->i_num,d->i_painterHeight - 10)
          << QPoint((d->i_painterWidth-10)*d->i_val/d->i_num,
                    ((d->i_painterHeight-10)*(d->i_num - d->i_val)/d->i_num)) ;
    //渐变色
    QLinearGradient linGrad( 0, 50,(d->i_painterWidth - 10), 50);
    linGrad.setColorAt(0, Qt::green);
    //    linGrad.setColorAt(0, Qt::yellow);
    linGrad.setColorAt(1, Qt::red);
    linGrad.setSpread(QGradient::PadSpread);
    painter.setPen(QPen(Qt::black, 5));
    painter.setBrush(linGrad);
    painter.drawPolygon(poly2);
    painter.setBrush(QColor(40, 40, 40));
    painter.setPen(QPen(Qt::black, 5));
    QFont font = painter.font() ;
    font.setPointSize(18);
    painter.setFont(font);

    //绘制刻度线
    int i = 1;
    for (i = 1; i < d->i_num; i++)
    {
        painter.setPen(QPen(Qt::black, 5));
        painter.drawLine((d->i_painterWidth - 10)*i/d->i_num,
                         (d->i_painterHeight + 1 - 10)*(d->i_num - i)/d->i_num,
                         (d->i_painterWidth - 10)*i/d->i_num, (d->i_painterHeight-10));
        painter.setPen(QPen(Qt::red, 5));
    }
}

void ToleranceBar::mousePressEvent(QMouseEvent *qevent)
{
    d->f_WR = (this->width() * 1.0)/d->i_painterWidth;
    d->f_HR = (this->height() * 1.0)/d->i_painterHeight;
    float x = qevent->x()/d->f_WR;
    float y = qevent->y()/d->f_HR;

    if (qevent->button() == Qt::LeftButton)
    {
        float p =((d->i_painterHeight-10)*((d->i_painterWidth-10)-x)/(d->i_painterWidth-10));
        if(y > (p) && y<(d->i_painterHeight-10) && x < (d->i_painterWidth-10))
        {
            double T = x;
            d->i_val = ((T * d->i_num)/(d->i_painterWidth - 10)) + 1;

            emit signalSendValue (d->i_val);

            d->b_pressed = true;
            update();
        }
    }
}

void ToleranceBar::mouseMoveEvent(QMouseEvent *qevent)
{
    d->f_WR = (this->width()*1.0)/d->i_painterWidth;
    d->f_HR = (this->height()*1.0)/d->i_painterHeight;

    float x = qevent->x()/d->f_WR;
    float y = qevent->y()/d->f_HR;

    if (d->b_pressed)
    {
        float p =((d->i_painterHeight - 10)*((d->i_painterWidth-10)-x)/(d->i_painterWidth-10));

        if(y >(p) && y<(d->i_painterHeight-10) && x < (d->i_painterWidth-10))
        {
            double T = x;
            d->i_val = ((T*d->i_num)/(d->i_painterWidth-10))+1;

            emit signalSendValue (d->i_val);

            update();
        }
    }
}

void ToleranceBar::mouseReleaseEvent(QMouseEvent *qevent)
{
    Q_UNUSED(qevent);

    d->b_pressed = false;
}

#include "moc_tolerancebar.cpp"
