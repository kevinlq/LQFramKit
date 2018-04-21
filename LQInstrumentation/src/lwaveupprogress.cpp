#include "StdMain.h"

#include "lwaveupprogress.h"


typedef struct LWavePrivateData{
    P_STYLE percentStyle;
    int value;
    int minValue;
    int maxValue;
    int waterDensity;
    double waterHeight;
    double offset;
    int borderWidth;
    QColor usedColr;
    QString strText;
    QTimer *timer;
}P_Data;

LWaveUpProgress::LWaveUpProgress(QWidget *parent)
    : QWidget(parent),d_ptr(new LWavePrivateData)
{
    d_ptr->percentStyle = percentStyleCircle;
    d_ptr->value = 45;
    d_ptr->minValue = 0;
    d_ptr->maxValue = 100;
    d_ptr->waterDensity = 2;
    d_ptr->waterHeight = 0.02;
    d_ptr->offset = 0;
    d_ptr->borderWidth = 2;
    d_ptr->usedColr = Qt::blue;
    d_ptr->strText = QString::number (d_ptr->value)+"%";
    d_ptr->timer = new QTimer(this);

    connect (d_ptr->timer,SIGNAL(timeout()),
             this,SLOT(slotTimeOut()));
    d_ptr->timer->start (100);
}

LWaveUpProgress::~LWaveUpProgress()
{
}

void LWaveUpProgress::setWaveText(const QString &str)
{
    if (str.isEmpty ())
        return;
    if (d_ptr)
        d_ptr->strText = str;
}

void LWaveUpProgress::drawValue(QPainter *painter)
{
    int height = this->height ();
    int width = this->width ();
    int side = qMin(height,width);

    //起始坐标和结束坐标
    int startX = d_ptr->borderWidth;
    int startY = d_ptr->borderWidth;
    int endX = width - d_ptr->borderWidth;
    int endY = height - d_ptr->borderWidth;

    if ( d_ptr->percentStyle == percentStyleCircle){
        side = side - d_ptr->borderWidth * 2;
        startX = (width - side) / 2;
        startY = (height - side) / 2;
        endX = (width + side) / 2;
        endY = (height + side) / 2;
    }

    //计算当前值所占百分比
    double percent = 1 - (double)(d_ptr->value - d_ptr->minValue)/
            (d_ptr->maxValue - d_ptr->minValue);
    //正弦曲线公式 y = A * sin(ωx + φ) + k
    //w 表示周期，可以理解为水波的密度，值越大密度越大
    double w = d_ptr->waterDensity * M_PI / endX;

    //A 表示振幅,可以理解为水波的高度
    double A = endY * d_ptr->waterHeight;

    //K表示y轴偏移，可以理解为进度，取值高度的进度百分比
    double k = endY * percent;

    //重新计算图形区域
    if ( d_ptr->percentStyle == percentStyleCircle){
        k = (side * percent) + startY;
    }

    //第一条和第二条波浪路径集合
    QPainterPath waterPath1;
    QPainterPath waterPath2;

    //移动到左上角起始点
    waterPath1.moveTo (startX,endY);
    waterPath2.moveTo (startX,endY);

    d_ptr->offset += 0.6;
    if ( d_ptr->offset > (endX / 2)){
        d_ptr->offset = 0;
    }

    for (int x = startX; x <= endX; x++){
        //第一条波浪Y轴
        double waterY1 = (double)(A * sin(w * x + d_ptr->offset)) + k;
        //第二条波浪线Y轴
        double waterY2 = (double)(A * sin(w * x + d_ptr->offset + (endX / 2 * w))) + k;

        //如果当前值为最小值,则Y轴为右下角Y轴
        if (d_ptr->value == d_ptr->minValue){
            waterY1 = endY;
            waterY2 = endY;
        }

        //如果当前值为最大值,则Y轴为右上角Y轴
        if (d_ptr->value == d_ptr->maxValue){
            waterY1 = startY;
            waterY2 = startY;
        }

        //将两个点连接成线
        waterPath1.lineTo (x,waterY1);
        waterPath2.lineTo (x,waterY2);
    }

    //移动到右下角结束点，整体形成一个闭合路径
    waterPath1.lineTo (endX,endY);
    waterPath2.lineTo (endX,endY);

    //大路径
    QPainterPath bigPath;
    if (d_ptr->percentStyle == percentStyleRect){
        bigPath.addRect (startX,startY,endX,endY);
    }else if (d_ptr->percentStyle == percentStyleCircle){
        bigPath.addEllipse (startX,startY,side,side);
    }else if (d_ptr->percentStyle == percentStyleEllipse){
        bigPath.addEllipse (startX,startY,width - d_ptr->borderWidth * 2,
                            height - d_ptr->borderWidth * 2);
    }

    //新路径，用大路径减去波浪区域的路径，形成遮罩效果
    QPainterPath path;
    QColor waterColor1 = d_ptr->usedColr;
    waterColor1.setAlpha (100);
    QColor waterColor2 = d_ptr->usedColr;
    waterColor2.setAlpha (200);

    painter->save ();
    painter->setPen (Qt::NoPen);

    //第一条波浪挖去后的路径
    path = bigPath.intersected (waterPath1);
    painter->setBrush (waterColor1);
    painter->drawPath (path);

    //第二条波浪挖去后的路径
    path = bigPath.intersected (waterPath2);
    painter->setBrush (waterColor2);
    painter->drawPath (path);

    painter->restore ();
}

void LWaveUpProgress::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint (QPainter::Antialiasing);

    this->drawValue (&painter);

    //绘制百分比文字
    painter.setPen (QColor(255,255,255));
    QFont font;
    font.setFamily ("Microsoft YaHei");
    font.setPointSize (40);
    font.setBold (true);
    painter.setFont (font);

    //计算文字位置
    int textWidth = this->width () / 2 - 45;
    int textHeight = this->height () / 2;

    if (d_ptr->value < 50){
        textHeight = textHeight + 40;
    }


    painter.drawText (textWidth,textHeight,d_ptr->strText);
}

void LWaveUpProgress::slotTimeOut()
{
    d_ptr->offset += 0.4;

    update ();
}

void LWaveUpProgress::slotValueChange(int value)
{
    if (value < 0 || value > 100)
        return;
    d_ptr->value = value;

    update ();
}

#include "moc_lwaveupprogress.cpp"
