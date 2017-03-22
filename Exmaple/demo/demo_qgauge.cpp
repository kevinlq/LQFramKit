#include "demo_qgauge.h"
#include "ui_demo_qgauge.h"

Demo_qgauge::Demo_qgauge(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_qgauge)
{
    ui->setupUi(this);
    this->setWindowTitle(title);

    ui->horizontalSlider->setRange(0,100);
}

Demo_qgauge::~Demo_qgauge()
{
    delete ui;
}

void Demo_qgauge::on_horizontalSlider_sliderMoved(int position)
{
    ui->widget->setValue(position);
}
