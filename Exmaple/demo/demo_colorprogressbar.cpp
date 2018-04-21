#include "LQInstrumenttationIncLib.h"

#include "demo_colorprogressbar.h"
#include "ui_demo_colorprogressbar.h"

Demo_ColorProgressBar::Demo_ColorProgressBar(const QString &title,
                                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_ColorProgressBar)
{
    ui->setupUi(this);

    this->setWindowTitle(title);

    init();
}

Demo_ColorProgressBar::~Demo_ColorProgressBar()
{
    delete ui;
}

void Demo_ColorProgressBar::init()
{
    ui->horizontalSlider_3->setRange(0,100);

    ui->widget->setDecimal(0);
    ui->widget->setBarBackGroundColor(QColor(237,237,250));
    ui->widget->setBarColor(QColor(100,120,10));
    ui->widget->setShowBarSplitLine(false);
    ui->widget->setValue(10);
    ui->widget->setTextColor(QColor(100,120,10));

    ui->widget_2->setDecimal(1);
    ui->widget_2->setBarBackGroundColor(QColor(237,237,250));
    ui->widget_2->setBarColor(QColor(102,140,234));
    ui->widget_2->setShowBarSplitLine(true);
    ui->widget_2->setBarSplitLineDelta(3);
    ui->widget_2->setBarSplitLineColor(QColor(242,242,242));
    ui->widget_2->setValue(30);
    ui->widget_2->setTextColor(QColor(102,140,234));

    ui->widget_3->setDecimal(1);
    ui->widget_3->setBarBackGroundColor(QColor(237,237,250));
    ui->widget_3->setBarColor(QColor(230,35,35));
    ui->widget_3->setShowBarSplitLine(true);
    ui->widget_3->setBarSplitLineDelta(5);
    ui->widget_3->setBarSplitLineColor(QColor(242,242,242));
    ui->widget_3->setValue(50);
    ui->widget_3->setTextColor(QColor(230,35,35));
}

void Demo_ColorProgressBar::on_horizontalSlider_3_valueChanged(int value)
{
    ui->widget->setValue(value);
    ui->widget_2->setValue(value);
    ui->widget_3->setValue(value);
}
