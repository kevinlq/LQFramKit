#include "demo_tolerancebar.h"
#include "ui_demo_tolerancebar.h"

Demo_ToleranceBar::Demo_ToleranceBar(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_ToleranceBar)
{
    ui->setupUi(this);

    setWindowTitle (title);

    connect (ui->widget,SIGNAL(signalSendValue(int)),
             this,SIGNAL(signalValueChange(int)));
}

Demo_ToleranceBar::~Demo_ToleranceBar()
{
    delete ui;
}
