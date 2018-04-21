#include "LQInstrumenttationIncLib.h"

#include "demo_qmeter.h"
#include "ui_demo_qmeter.h"

Demo_qmeter::Demo_qmeter(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_qmeter)
{
    ui->setupUi(this);

    this->setWindowTitle(title);

    ui->horizontalSlider->setRange(0,100);
}

Demo_qmeter::~Demo_qmeter()
{
    delete ui;
}

void Demo_qmeter::on_horizontalSlider_sliderMoved(int position)
{
    ui->widget->setValue(position);
}
