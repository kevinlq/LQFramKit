#ifndef DRAWPROGRESSBAR_H
#define DRAWPROGRESSBAR_H

#define RECT_WIDTH      40   //第一个圆中心点到左边界的距离
#define iMaxNum          5   //定义最大阶段数
#include <QWidget>

class QPushButton;

#include <lqformwidget_global.h>

class LQFORMWIDGETSHARED_EXPORT DrawProgressBar : public QWidget
{
	Q_OBJECT

public:
	DrawProgressBar(QWidget *parent = 0);
	~DrawProgressBar();
	void setValue(int value);

private:
	void init();
	void drawBackground(QPainter* painter);      //绘制整个背景颜色
	void drawBarBackground(QPainter* painter);   //绘制灰色的导航条：包括灰色的圆，灰色的长条矩形和灰色的text
	void drawBlueBar(QPainter* painter);         //绘制蓝色信息：圆、长条和本文
	void drawBarNumber(QPainter* painter);       //绘制数字
	
	//绘制多边形测试用
	void drawPolygonTest(QPainter* painter);

protected:
	void paintEvent(QPaintEvent *event);
	QSize sizeHint() const
	{
		return QSize(800,600);
	}
	
private:
    int m_value;            //设置当前值大小
	int iBigRadius;        //灰色的圆半径
	int iSmallRadius;      //蓝色的圆半径

    int rectHight;          //连接两圆之间矩形的高度
    int rectWidth;          //连接两圆之间矩形的宽度
    int rectBlueHight;      //定义蓝色矩形的高度比灰色少2

	QStringList strlist;    //显示进度条下方的文本
	QStringList str_list2;  //显示在进度条上方，椭圆形中文本

};

#endif // DRAWPROGRESSBAR_H
