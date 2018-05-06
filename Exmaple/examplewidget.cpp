#include "examplewidget.h"
#include "ui_examplewidget.h"

#include <QTimer>
#include <QVBoxLayout>
#include <QSlider>
#include <QFile>

/*仪器仪表测试demo*/
#include "demo_qgauge.h"
#include "demo_qmeter.h"
#include "demo_compasswidget.h"
#include "demo_attitudemeter.h"
#include "demo_speedgauge.h"
#include "demo_airspeedwidget.h"
#include "demo_roundprogressbar.h"      //圆形进度条
#include "demo_colorprogressbar.h"      //多彩进入条
#include "demo_speedwatch.h"            //速度仪表3
#include "demo_waveprogress.h"          //浪波进度条

/*显示界面类测试demo*/
#include "demo_lineedit.h"              //个性化搜索框
#include "demo_customcombox.h"          //自定义ComBox
#include "demo_splashscreen.h"          //启动界面
#include "demo_startwidget.h"           //个性化启动界面
#include "LQFormWidgetIncLib.h"
//#include "nbaseswitchbutton.h"          //switch切换开关
#include "demo_messagebox.h"            //自定义消息框
#include "demo_rightdownmessagebox.h"   //右下角消息弹窗
#include "demo_drawprogressbar.h"       //导航进度条
#include "demo_ruler.h"                 //尺子
#include "demo_ipaddresswidget.h"       //IP地址输入框
#include "demo_msgnotify.h"             //消息弹窗提醒
#include "demo_navlistview.h"           //树状导航
#include "demo_tabwidget.h"             //tab窗口
#include "demo_tolerancebar.h"          //

/*辅助工具测试demo*/
#include "demo_perfmon.h"               //性能监测
#include "demo_imagebrowser.h"          //图片旋转缩放
#include "demo_zxing.h"                 //二维码测试

#include "CreateProjectFileForm.h"      //生成工程模板

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

    if ( m_pCreatePro != NULL )
    {
        delete m_pCreatePro;
        m_pCreatePro = NULL;
    }
}

void ExampleWidget::slotToleranceBarValue(const int &value)
{
    ui->textEdit->append (QString::number (value));
}

void ExampleWidget::slotTestSearchLineEdit(const QString &text)
{
    ui->textEdit->append("搜索的内容为:"+text+"\n");
}

void ExampleWidget::init()
{
    //    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setFocusPolicy(Qt::ClickFocus);
    this->setWindowTitle("控件测试集合");

    //加载控件样式
//    QFile file(":/image/css/style_demo.css");
//    file.open(QFile::ReadOnly);
//    QString qss = QString(file.readAll());
//    setStyleSheet(qss);

    ui->tabWidget->setCurrentIndex(0);

    initConnect ();

    m_pCreatePro = Q_NULLPTR;
}

void ExampleWidget::initConnect()
{
}

void ExampleWidget::on_pushButton_clicked()
{
    Demo_compassWidget *comWidget = new Demo_compassWidget("指南针demo");
    comWidget->setWindowModality(Qt::ApplicationModal);
    comWidget->show();

    QTimer::singleShot(10000,comWidget,SLOT(deleteLater()));
    ui->textEdit->append("指南针界面已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_2_clicked()
{
    Demo_qmeter *meter = new Demo_qmeter("仪表盘1demo");
    meter->setWindowModality(Qt::ApplicationModal);
    meter->show();

    QTimer::singleShot(20000,meter,SLOT(deleteLater()));
    ui->textEdit->append("仪表盘1已经启动，20秒后将关闭!");
}

void ExampleWidget::on_pushButton_3_clicked()
{
    Demo_qgauge *gauge = new Demo_qgauge("仪表盘2demo");
    gauge->setWindowModality(Qt::ApplicationModal);
    gauge->show();

    QTimer::singleShot(10000,gauge,SLOT(deleteLater()));
    ui->textEdit->append("仪表盘2已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_4_clicked()
{
    Demo_lineEdit *search = new Demo_lineEdit("搜索框demo");
    search->setWindowModality(Qt::ApplicationModal);
    search->show();
    connect(search,SIGNAL(signalSearchContent(QString)),
            this,SLOT(slotTestSearchLineEdit(QString)));

    QTimer::singleShot(10000,search,SLOT(deleteLater()));
    ui->textEdit->append("自定义搜索框已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_5_clicked()
{
    Demo_AttitudeMeter *attitudeMeter = new Demo_AttitudeMeter("姿势仪表demo");
    attitudeMeter->setWindowModality(Qt::ApplicationModal);
    attitudeMeter->show();

    QTimer::singleShot(10000,attitudeMeter,SLOT(deleteLater()));
    ui->textEdit->append("姿势仪表已经启动，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_6_clicked()
{
    Demo_PerfMon *perfmon = new Demo_PerfMon("性能监测demo");
    perfmon->setWindowModality(Qt::ApplicationModal);
    perfmon->show ();

    QTimer::singleShot (30000,perfmon,SLOT(deleteLater()));
    ui->textEdit->append ("性能监测界面已经启动，30秒之后将关闭!");
}

void ExampleWidget::on_pushButton_7_clicked()
{
    Demo_SpeedGauge *speed = new Demo_SpeedGauge("速度仪表1demo");
    speed->setWindowModality(Qt::ApplicationModal);
    speed->show();

    QTimer::singleShot (20000,speed,SLOT(deleteLater()));
    ui->textEdit->append ("速度仪表1已经启动，20秒之后将关闭!");
}

void ExampleWidget::on_pushButton_8_clicked()
{
    Demo_AirSpeedWidget *airspeed = new Demo_AirSpeedWidget("速度仪表2demo");
    airspeed->setWindowModality(Qt::ApplicationModal);
    airspeed->show();

    QTimer::singleShot(15000,airspeed,SLOT(deleteLater()));
    ui->textEdit->append ("速度仪表2已经启动，15秒之后将关闭!");
}

void ExampleWidget::on_pushButton_9_clicked()
{
    Demo_ImageBrowser *image = new Demo_ImageBrowser("图片旋转缩放demo");
    image->setWindowModality(Qt::ApplicationModal);
    image->show();

    QTimer::singleShot(20000,image,SLOT(deleteLater()));
    ui->textEdit->append("图片旋转缩放已经启动，20秒之后将关闭!");
}

void ExampleWidget::on_pushButton_10_clicked()
{
    Demo_RoundProgressBar *round = new Demo_RoundProgressBar("圆形进度条demo");
    round->setWindowModality(Qt::ApplicationModal);
    round->show();

    QTimer::singleShot(15000,round,SLOT(deleteLater()));
    ui->textEdit->append("圆形进度条已经启动，15秒后将关闭!");
}

void ExampleWidget::on_pushButton_11_clicked()
{
    Demo_ColorProgressBar *color = new Demo_ColorProgressBar("多彩进度条demo");
    color->setWindowModality(Qt::ApplicationModal);
    color->show();

    QTimer::singleShot(15000,color,SLOT(deleteLater()));
    ui->textEdit->append("多彩进度条已经启动，15秒后将关闭!");
}

void ExampleWidget::on_pushButton_12_clicked()
{
    Demo_CustomComBox *combox = new Demo_CustomComBox("自定义ComBoxdemo");
    combox->setWindowModality(Qt::ApplicationModal);
    combox->show();

    QTimer::singleShot(10000,combox,SLOT(deleteLater()));
    ui->textEdit->append("自定义ComBox已经启动,10秒后将关闭!");
}

void ExampleWidget::closeEvent(QCloseEvent *event)
{
    Q_UNUSED(event);

    qApp->exit(0);
}

void ExampleWidget::on_pushButton_13_clicked()
{
    Demo_SplashScreen *splash = new Demo_SplashScreen("启动界面demo");
    splash->showWidget();

    QTimer::singleShot(20000,splash,SLOT(deleteLater()));
    ui->textEdit->append("启动界面已经启动，20秒后将关闭!");
}
void ExampleWidget::on_pushButton_14_clicked()
{
    NBaseSwitchButton *switchBtn = new NBaseSwitchButton;
    switchBtn->setWindowModality(Qt::ApplicationModal);
    switchBtn->show ();

    QTimer::singleShot (8000,switchBtn,SLOT(deleteLater()));
    ui->textEdit->append ("switch切换开关已经启动，8秒后即将关闭!");
}

void ExampleWidget::on_pushButton_15_clicked()
{
    Demo_MessageBox *msg = new Demo_MessageBox("自定义消息框demo");
    msg->setWindowModality(Qt::ApplicationModal);
    msg->show ();

    QTimer::singleShot (18000,msg,SLOT(deleteLater()));
    ui->textEdit->append ("消息框测试界面已经启动，18秒后将关闭");
}

void ExampleWidget::on_pushButton_16_clicked()
{
    Demo_RightDownMessageBox *msg = new Demo_RightDownMessageBox("右下角消息弹窗demo");
    msg->setWindowModality(Qt::ApplicationModal);
    msg->show ();

    QTimer::singleShot (15000,msg,SLOT(deleteLater()));
    ui->textEdit->append ("右下角消息弹窗已经启动，15秒后将关闭");
}


void ExampleWidget::on_pushButton_17_clicked()
{
    Demo_Zxing *zxing = new Demo_Zxing("二维码识别测试demo");
    zxing->setWindowModality (Qt::ApplicationModal);
    zxing->show ();

    QTimer::singleShot (20000,zxing,SLOT(deleteLater()));
    ui->textEdit->append ("二维码识别测试界面已经运行");
}

void ExampleWidget::on_pushButton_18_clicked()
{
    //
}

void ExampleWidget::on_pushButton_19_clicked()
{
    Demo_StartWidget *start = new Demo_StartWidget("超炫启动界面demo");
    start->setWindowModality (Qt::ApplicationModal);
    connect (start,SIGNAL(signalShow()),start,SLOT(show()));

    QTimer::singleShot (20000,start,SLOT(deleteLater()));
    ui->textEdit->append ("超炫启动界面已经加载，20秒后将关闭");
}

void ExampleWidget::on_pushButton_20_clicked()
{
    Demo_DrawProgressbar *draw = new Demo_DrawProgressbar("导航进度条demo");
    draw->setWindowModality (Qt::ApplicationModal);
    draw->show ();

    QTimer::singleShot (15000,draw,SLOT(deleteLater()));
    ui->textEdit->append ("进度导航条窗体已经加载，15秒后将关闭");
}

void ExampleWidget::on_pushButton_21_clicked()
{
    Demo_Ruler *ruler = new Demo_Ruler("尺子demo");
    ruler->setWindowModality (Qt::ApplicationModal);
    ruler->show ();

    QTimer::singleShot (15000,ruler,SLOT(deleteLater()));
    ui->textEdit->append ("尺子界面已经启动，15秒之后将关闭!");
}

void ExampleWidget::on_pushButton_22_clicked()
{
    Demo_IpAddressWidget *ipAddress = new Demo_IpAddressWidget("IP地址输入框demo");
    ipAddress->show ();

    QTimer::singleShot (20000,ipAddress,SLOT(deleteLater()));
    ui->textEdit->append ("IP地址输入框已经启动，20秒之后将关闭");
}

void ExampleWidget::on_pushButton_23_clicked()
{
    Demo_MsgNotify *notify = new Demo_MsgNotify("消息弹窗demo");
    notify->show();

    QTimer::singleShot(10000,notify,SLOT(deleteLater()));
    ui->textEdit->append("消息弹窗已经启动，10秒后将关闭");
}

void ExampleWidget::on_pushButton_24_clicked()
{
    Demo_SpeedWatch *speed = new Demo_SpeedWatch("速度仪表3demo");
    speed->setWindowModality (Qt::ApplicationModal);
    speed->show ();

    QTimer::singleShot (10000,speed,SLOT(deleteLater()));
    ui->textEdit->append ("速度仪表3已经启动，10秒后将关闭");
}

void ExampleWidget::on_pushButton_25_clicked()
{
    Demo_NavListView *nav = new Demo_NavListView("树状导航");
    nav->setWindowModality (Qt::ApplicationModal);
    nav->show ();

    QTimer::singleShot (10000,nav,SLOT(deleteLater()));
    ui->textEdit->append ("树状导航界面已经启动，10秒后将关闭");
}

void ExampleWidget::on_pushButton_26_clicked()
{
    Demo_tabwidget *tab = new Demo_tabwidget("tab窗体demo");
    tab->setWindowModality (Qt::ApplicationModal);
    tab->show ();

    QTimer::singleShot (10000,tab,SLOT(deleteLater()));
    ui->textEdit->append ("tab窗体已经运行，10秒后将关闭");
}

void ExampleWidget::on_pushButton_27_clicked()
{
    Demo_ToleranceBar *bar = new Demo_ToleranceBar("Tolerance Bar demo");
    bar->setWindowModality (Qt::ApplicationModal);
    bar->show ();

    QTimer::singleShot (10000,bar,SLOT(deleteLater()));
    ui->textEdit->append ("Tolerance Bar 已经运行，10秒后关闭");

    connect (bar,SIGNAL(signalValueChange(int)),
             this,SLOT(slotToleranceBarValue(int)));
}

void ExampleWidget::on_pushButton_28_clicked()
{
    Demo_WaveProgress *wave = new Demo_WaveProgress("wave demo");
    wave->setWindowModality (Qt::ApplicationModal);
    wave->show ();

    QTimer::singleShot (10000,wave,SLOT(deleteLater()));
    ui->textEdit->append ("波浪进度条已经运行，10秒后将关闭!");
}

void ExampleWidget::on_pushButton_29_clicked()
{
    if ( m_pCreatePro == Q_NULLPTR)
    {
        m_pCreatePro = new CreateProjectFileForm;
    }

    m_pCreatePro->show ();
}
