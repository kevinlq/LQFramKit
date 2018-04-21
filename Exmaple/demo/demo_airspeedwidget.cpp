#include "LQInstrumenttationIncLib.h"

#include "demo_airspeedwidget.h"
#include "ui_demo_airspeedwidget.h"

Demo_AirSpeedWidget::Demo_AirSpeedWidget(const QString &title,
                                         QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_AirSpeedWidget)
{
    ui->setupUi(this);

    this->setWindowTitle(title);
}

Demo_AirSpeedWidget::~Demo_AirSpeedWidget()
{
    delete ui;
}

void Demo_AirSpeedWidget::on_horizontalSlider_valueChanged(int value)
{
    ui->widget->setCurrentValue(value);
}
