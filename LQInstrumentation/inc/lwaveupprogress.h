#ifndef LWAVEUPPROGRESS_H
#define LWAVEUPPROGRESS_H

#include <QWidget>


typedef enum PercentStyle{
    percentStyleRect = 0,       //矩形
    percentStyleCircle,         //圆形
    percentStyleEllipse         //椭圆
}P_STYLE;

struct LWavePrivateData;


class LQINSTRUMENTATIONSHARED_EXPORT LWaveUpProgress : public QWidget
{
    Q_OBJECT
public:
    explicit LWaveUpProgress(QWidget *parent = 0);
    ~LWaveUpProgress();

    void setWaveText(const QString &str);

private:
    /**
     * @brief  :   drawValue() 绘制波浪核心函数
     * @param  :   painter 指针
     * @return :   none
     */
    void drawValue(QPainter *painter);

protected:
    virtual void paintEvent (QPaintEvent *event);

Q_SIGNALS:

public Q_SLOTS:
    void slotTimeOut();

    /**
     * @brief  :   slotValueChange() 改变当前波纹值
     * @param  :   value 泊位值
     * @return :   none
     */
    void slotValueChange(int value);

private:
    LWavePrivateData    *d_ptr;
};

#endif // LWAVEUPPROGRESS_H
