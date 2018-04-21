#include "LQInstrumenttationIncLib.h"

#include "demo_speedwatch.h"
#include "ui_demo_speedwatch.h"

Demo_SpeedWatch::Demo_SpeedWatch(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_SpeedWatch)
{
    ui->setupUi(this);

    this->setWindowTitle (title);
}

Demo_SpeedWatch::~Demo_SpeedWatch()
{
    delete ui;
}

void Demo_SpeedWatch::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setValue (value);
}
