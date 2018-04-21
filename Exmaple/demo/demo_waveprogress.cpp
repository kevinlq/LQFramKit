#include "LQInstrumenttationIncLib.h"

#include "demo_waveprogress.h"
#include "ui_demo_waveprogress.h"

Demo_WaveProgress::Demo_WaveProgress(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_WaveProgress)
{
    ui->setupUi(this);

    this->setWindowTitle (title);

    ui->horizontalSlider->setValue (0);
    ui->horizontalSlider->setRange (0,100);

    connect (ui->horizontalSlider,SIGNAL(valueChanged(int)),
             ui->widget,SLOT(slotValueChange(int)));
}

Demo_WaveProgress::~Demo_WaveProgress()
{
    delete ui;
}

void Demo_WaveProgress::on_comboBox_activated(int index)
{
    if (1 == index){
        ui->widget->setWaveText ("帅");
    }
}
