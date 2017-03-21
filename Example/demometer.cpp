#include "demometer.h"
#include "ui_demometer.h"

DemoMeter::DemoMeter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DemoMeter)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider,SIGNAL(sliderMoved(int)),
            ui->widget,SLOT(setValue(int)));

    ui->widget->setValue(50);
}

DemoMeter::~DemoMeter()
{
    delete ui;
}
