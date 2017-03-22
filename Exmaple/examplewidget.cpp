#include "examplewidget.h"
#include "ui_examplewidget.h"

#include <QTimer>
#include <QVBoxLayout>
#include <QSlider>

#include "demo_qgauge.h"
#include "demo_qmeter.h"
#include "demo_compasswidget.h"
#include "demo_attitudemeter.h"

#include "demo_lineedit.h"

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
    ui->textEdit->append("指南针界面已经启动，10秒后将关闭!\r\n");
}

void ExampleWidget::on_pushButton_2_clicked()
{
    Demo_qmeter *meter = new Demo_qmeter("仪表盘1demo");
    meter->show();

    QTimer::singleShot(10000,meter,SLOT(deleteLater()));
    ui->textEdit->append("仪表盘1已经启动，10秒后将关闭!\r\n");
}

void ExampleWidget::on_pushButton_3_clicked()
{
    Demo_qgauge *gauge = new Demo_qgauge("仪表盘2demo");
    gauge->show();

    QTimer::singleShot(10000,gauge,SLOT(deleteLater()));
    ui->textEdit->append("仪表盘2已经启动，10秒后将关闭!\r\n");
}

void ExampleWidget::on_pushButton_4_clicked()
{
    Demo_lineEdit *search = new Demo_lineEdit("搜索框demo");
    search->show();
    connect(search,SIGNAL(signalSearchContent(QString)),
            this,SLOT(slotTestSearchLineEdit(QString)));

    QTimer::singleShot(10000,search,SLOT(deleteLater()));
    ui->textEdit->append("自定义搜索框已经启动，10秒后将关闭!\r\n");
}

void ExampleWidget::on_pushButton_5_clicked()
{
    Demo_AttitudeMeter *attitudeMeter = new Demo_AttitudeMeter("姿势仪表demo");
    attitudeMeter->show();

    QTimer::singleShot(10000,attitudeMeter,SLOT(deleteLater()));
    ui->textEdit->append("姿势仪表已经启动，10秒后将关闭!\r\n");
}
