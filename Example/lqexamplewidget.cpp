#include "lqexamplewidget.h"
#include "ui_lqexamplewidget.h"

#include <QTimer>

#include "demometer.h"
#include "demogauge.h"

LQExampleWidget::LQExampleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LQExampleWidget)
{
    ui->setupUi(this);
}

LQExampleWidget::~LQExampleWidget()
{
    delete ui;
}

void LQExampleWidget::on_pushButton_clicked()
{
    DemoMeter meter;
    meter.exec();
}

void LQExampleWidget::on_pushButton_2_clicked()
{
    DemoGauge gaute;
    gaute.exec();
}
