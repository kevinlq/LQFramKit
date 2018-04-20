#include "demo_drawprogressbar.h"
#include "ui_demo_drawprogressbar.h"

Demo_DrawProgressbar::Demo_DrawProgressbar(const QString &title,
                                           QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_DrawProgressbar)
{
    ui->setupUi(this);

    this->setWindowTitle (title);

    ui->widget->setValue (ui->lineEdit->text ().toInt ());
}

Demo_DrawProgressbar::~Demo_DrawProgressbar()
{
    delete ui;
}

void Demo_DrawProgressbar::on_pushButton_clicked()
{
    int value = ui->lineEdit->text ().toInt ();
    ui->widget->setValue (value);
}
