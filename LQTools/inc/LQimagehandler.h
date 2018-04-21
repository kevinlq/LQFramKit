#ifndef LQIMAGEBROWSER_IMAGEHANDLER_H
#define LQIMAGEBROWSER_IMAGEHANDLER_H

#include <QWidget>
#include <QPixmap>


class LQTOOLSSHARED_EXPORT LQImageHandler : public QWidget
{
    Q_OBJECT
public:
    explicit LQImageHandler(QWidget *parent = 0);
    ~LQImageHandler();

    void setPixmap(const QPixmap &pixmap);

    void showOriginalSize();                    //原始大小显示
    void showSuitableSize();                    //合适大小显示
    void zoomIn();
    void zoomOut();
    void clockwise90();
    void anticlockwise90();

private:
    void ariseScale(int rate);
//    bool isInPixmap(QPoint pos);

Q_SIGNALS:
    void percentageChanged(double percentage);
    void rightButtonClicked();

protected:
    void paintEvent(QPaintEvent *event);
    void wheelEvent(QWheelEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

public Q_SLOTS:

private:
    QPixmap m_pixmap;

    //缩放
    double m_scale;               //缩放比例
    double m_percentage;          //缩放百分比

    //移动
    QPoint m_pressPoint;                //鼠标按下点的坐标
    double m_originX;
    double m_originY;
    double m_basicX;
    double m_basicY;

    int m_suitableWidth;
    int m_suitableHeight;
};

#endif // LQIMAGEBROWSER_IMAGEHANDLER_H
