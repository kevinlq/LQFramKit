#include "LQFormWidgetIncLib.h"

#include "demo_tabwidget.h"
#include "ui_demo_tabwidget.h"


Demo_tabwidget::Demo_tabwidget(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_tabwidget)
{
    ui->setupUi(this);

    this->setWindowTitle (title);
}

Demo_tabwidget::~Demo_tabwidget()
{
    delete ui;
}
