#include "LQInstrumenttationIncLib.h"
#include "demo_attitudemeter.h"
#include "ui_demo_attitudemeter.h"

Demo_AttitudeMeter::Demo_AttitudeMeter(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_AttitudeMeter)
{
    ui->setupUi(this);

    this->setWindowTitle(title);

    ui->horizontalSlider->setMinimum(-100);
    ui->horizontalSlider->setMaximum(100);
    ui->horizontalSlider->setSingleStep(1);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setPageStep(10);

    ui->verticalSlider->setMinimum(-100);
    ui->verticalSlider->setMaximum(100);
    ui->verticalSlider->setSingleStep(1);
    ui->verticalSlider->setValue(0);
    ui->verticalSlider->setPageStep(10);
}

Demo_AttitudeMeter::~Demo_AttitudeMeter()
{
    delete ui;
}

void Demo_AttitudeMeter::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setCurrentValue(value);
}

void Demo_AttitudeMeter::on_verticalSlider_valueChanged(int value)
{
    ui->widget->setCurrentPitch(value);
    ui->label->setText(QString::number(value));
}
