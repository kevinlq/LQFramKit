#include "demogauge.h"
#include "ui_demogauge.h"

DemoGauge::DemoGauge(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DemoGauge)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),
            ui->widget,SLOT(setValue(int)));
    ui->widget->setValue(60);
}

DemoGauge::~DemoGauge()
{
    delete ui;
}
