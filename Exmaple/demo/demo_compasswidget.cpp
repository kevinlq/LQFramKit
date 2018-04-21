#include "LQInstrumenttationIncLib.h"
#include "demo_compasswidget.h"
#include "ui_demo_compasswidget.h"

Demo_compassWidget::Demo_compassWidget(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_compassWidget)
{
    ui->setupUi(this);

    this->setWindowTitle(title);

    ui->horizontalSlider->setRange(0,360);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider->setSingleStep(10);
}

Demo_compassWidget::~Demo_compassWidget()
{
    delete ui;
}

void Demo_compassWidget::on_horizontalSlider_sliderMoved(int position)
{
    ui->widget->setCurrentValue(position);
}
