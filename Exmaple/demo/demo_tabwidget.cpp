#include "demo_tabwidget.h"
#include "ui_demo_tabwidget.h"

#include "mytabwidget.h"

Demo_tabwidget::Demo_tabwidget(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_tabwidget)
{
    ui->setupUi(this);

    this->setWindowTitle (title);

    //m_ptabWidget = new MyTabWidget(this);
}

Demo_tabwidget::~Demo_tabwidget()
{
    delete ui;
}
