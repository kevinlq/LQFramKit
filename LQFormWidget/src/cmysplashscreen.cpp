#include "StdMain.h"
#include "cmysplashscreen.h"

#include <QTime>
#include <QTimer>

#define PROGRESS_STYLE  "QProgressBar {"\
    "color:white;border:none;"\
    "background:rgb(68,69,73);font:30px;"\
    "text-align:center;}"\
    "QProgressBar::chunk{"\
    "background-color: rgb(0, 160, 230);}"

CMySplashScreen::CMySplashScreen(QPixmap& pixmap,int time) :
    QSplashScreen(pixmap),
    elapseTime(time)
{
    ProgressBar = new QProgressBar(this);
    //设置进度条的位置
    ProgressBar->setGeometry(0,pixmap.height()-50,pixmap.width(),30);
    //设置进度条的样式
    ProgressBar->setStyleSheet(PROGRESS_STYLE);
    //设置进度条的样式
    ProgressBar->setRange(0, 100);
    //设置进度条的当前进度
    ProgressBar->setValue(0);

    generateAscendRandomNumber();
    setProgress();
}

CMySplashScreen::~CMySplashScreen()
{

}

void CMySplashScreen::setProgress()
{
    int tempTime = elapseTime/100;
    for(int i = 0;i < 100;i++)
    {
       QTimer::singleShot(i*tempTime, this, SLOT(slotUpdateProgress()));
    }
    QTimer::singleShot(elapseTime, this, SLOT(close()));

}

void CMySplashScreen::slotUpdateProgress()
{
    static int num = 0;
    ProgressBar->setValue(numbersList[num]);
    num++;
}

void CMySplashScreen::generateAscendRandomNumber()
{
    int i;
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    //生成100个大小在[0,100]之间的随机数
    for(i=0;i<100;i++)
    {
        numbersList.append(qrand()%101);
    }
    //递增排序
    qSort(numbersList.begin(),numbersList.end());
}

#include "moc_cmysplashscreen.cpp"
