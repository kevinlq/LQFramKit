#include "LQFormWidgetIncLib.h"

#include "demo_customcombox.h"
#include "ui_demo_customcombox.h"

Demo_CustomComBox::Demo_CustomComBox(const QString &title,
                                     QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_CustomComBox)
{
    ui->setupUi(this);

    setWindowTitle(title);
}

Demo_CustomComBox::~Demo_CustomComBox()
{
    delete ui;
}
