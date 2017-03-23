#include "examplewidget.h"
#include "ui_examplewidget.h"

#include <QTimer>
#include <QVBoxLayout>
#include <QSlider>

/*仪器仪表测试demo*/
#include "demo_qgauge.h"
#include "demo_qmeter.h"
#include "demo_compasswidget.h"
#include "demo_attitudemeter.h"
#include "demo_speedgauge.h"
#include "demo_airspeedwidget.h"
#include "demo_roundprogressbar.h"  //圆形进度条
#include "demo_colorprogressbar.h"  //多彩进入条

/*显示界面类测试demo*/
#include "demo_lineedit.h"          //个性化搜索框
#include "demo_customcombox.h"      //自定义ComBox

/*辅助工具测试demo*/
#include "demo_perfmon.h"           //性能监测
#include "demo_imagebrowser.h"      //图片旋转缩放

ExampleWidget::ExampleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExampleWidget)
{
    ui->setupUi(this);

    init();
}

ExampleWidget::~ExampleWidget()
{
    delete ui;
}

void ExampleWidget::slotTestSearchLineEdit(const QString &text)
{
    ui->textEdit->append("搜索的内容为:"+text+"\n");
}

void ExampleWidget::init()
{
    this->setFocusPolicy(Qt::ClickFocus);
    this->setWindowTitle("控件测试集合");

    initConnect ();
}

void ExampleWidget::initConnect()
{
}

void ExampleWidget::on_pushButton_clicked()
{
    Demo_compassWidget *comWidget = new Demo_compassWidget("指南针demo");
    comWidget->show();

    QTimer::singleShot(10000,comWidget,SLOT(deleteLater()));
    ui->textEdit->append("指南针界面已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_2_clicked()
{
    Demo_qmeter *meter = new Demo_qmeter("仪表盘1demo");
    meter->show();

    QTimer::singleShot(20000,meter,SLOT(deleteLater()));
    ui->textEdit->append("仪表盘1已经启动，20秒后将关闭!");
}

void ExampleWidget::on_pushButton_3_clicked()
{
    Demo_qgauge *gauge = new Demo_qgauge("仪表盘2demo");
    gauge->show();

    QTimer::singleShot(10000,gauge,SLOT(deleteLater()));
    ui->textEdit->append("仪表盘2已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_4_clicked()
{
    Demo_lineEdit *search = new Demo_lineEdit("搜索框demo");
    search->show();
    connect(search,SIGNAL(signalSearchContent(QString)),
            this,SLOT(slotTestSearchLineEdit(QString)));

    QTimer::singleShot(10000,search,SLOT(deleteLater()));
    ui->textEdit->append("自定义搜索框已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_5_clicked()
{
    Demo_AttitudeMeter *attitudeMeter = new Demo_AttitudeMeter("姿势仪表demo");
    attitudeMeter->show();

    QTimer::singleShot(10000,attitudeMeter,SLOT(deleteLater()));
    ui->textEdit->append("姿势仪表已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_6_clicked()
{
    Demo_PerfMon *perfmon = new Demo_PerfMon("性能监测demo");
    perfmon->show ();

    QTimer::singleShot (30000,perfmon,SLOT(deleteLater()));
    ui->textEdit->append ("性能监测界面已经启动，30秒之后将关闭!");
}

void ExampleWidget::on_pushButton_7_clicked()
{
    Demo_SpeedGauge *speed = new Demo_SpeedGauge("速度仪表1demo");
    speed->show();

    QTimer::singleShot (20000,speed,SLOT(deleteLater()));
    ui->textEdit->append ("速度仪表1已经启动，20秒之后将关闭!");
}

void ExampleWidget::on_pushButton_8_clicked()
{
    Demo_AirSpeedWidget *airspeed = new Demo_AirSpeedWidget("速度仪表2demo");
    airspeed->show();

    QTimer::singleShot(15000,airspeed,SLOT(deleteLater()));
    ui->textEdit->append ("速度仪表2已经启动，15秒之后将关闭!");
}

void ExampleWidget::on_pushButton_9_clicked()
{
    Demo_ImageBrowser *image = new Demo_ImageBrowser("图片旋转缩放demo");
    image->show();

    QTimer::singleShot(20000,image,SLOT(deleteLater()));
    ui->textEdit->append("图片旋转缩放已经启动，20秒之后将关闭!");
}

void ExampleWidget::on_pushButton_10_clicked()
{
    Demo_RoundProgressBar *round = new Demo_RoundProgressBar("圆形进度条demo");
    round->show();

    QTimer::singleShot(15000,round,SLOT(deleteLater()));
    ui->textEdit->append("圆形进度条已经启动，15秒后将关闭!");
}

void ExampleWidget::on_pushButton_11_clicked()
{
    Demo_ColorProgressBar *color = new Demo_ColorProgressBar("多彩进度条demo");
    color->show();

    QTimer::singleShot(15000,color,SLOT(deleteLater()));
    ui->textEdit->append("多彩进度条已经启动，15秒后将关闭!");
}

void ExampleWidget::on_pushButton_12_clicked()
{
    Demo_CustomComBox *combox = new Demo_CustomComBox("自定义ComBoxdemo");
    combox->show();

    QTimer::singleShot(10000,combox,SLOT(deleteLater()));
    ui->textEdit->append("自定义ComBox已经启动,10秒后将关闭!");
}

void ExampleWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    qApp->exit(0);
}
