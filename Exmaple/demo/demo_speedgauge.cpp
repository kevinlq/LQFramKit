#include "LQInstrumenttationIncLib.h"
#include "demo_speedgauge.h"
#include "ui_demo_speedgauge.h"

Demo_SpeedGauge::Demo_SpeedGauge(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_SpeedGauge)
{
    ui->setupUi(this);

    this->setWindowTitle(title);
}

Demo_SpeedGauge::~Demo_SpeedGauge()
{
    delete ui;
}

void Demo_SpeedGauge::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setCurrentValue(value);
}
