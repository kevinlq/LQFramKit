#ifndef CMYSPLASHSCREEN_H
#define CMYSPLASHSCREEN_H

#include <QSplashScreen>
#include <QPixmap>
#include <QProgressBar>
#include <QList>
#include <QtGlobal>


class LQFORMWIDGETSHARED_EXPORT CMySplashScreen: public QSplashScreen
{
     Q_OBJECT

public:
    /*************************************************
      Function:CMySplashScreen
      Description:构造函数
      Input:pixmap-启动界面的图片，time-启动界面停留的时间
      Output:无
      Return:无
      Others:无
    *************************************************/
     CMySplashScreen(QPixmap& pixmap,int time);
     ~CMySplashScreen();

private:
     //进度条
     QProgressBar *ProgressBar;
     //随机数列表
     QList<int> numbersList;
     //启动界面停留的时间
     int elapseTime;

private:
     /*************************************************
       Function:setProgress
       Description:设置进度条
       Input:无
       Output:无
       Return:无
       Others:无
     *************************************************/
     void setProgress();
     /*************************************************
       Function:generateAscendRandomNumber
       Description:生成递增的随机数
       Input:无
       Output:无
       Return:无
       Others:无
     *************************************************/
     void generateAscendRandomNumber();

private slots:    
     /*************************************************
       Function:updateProgress
       Description:更新进度条
       Input:无
       Output:无
       Return:无
       Others:无
     *************************************************/
     void slotUpdateProgress();
};

#endif // CMYSPLASHSCREEN_H
