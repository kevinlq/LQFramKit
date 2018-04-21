#include "LQFormWidgetIncLib.h"

#include "demo_ipaddresswidget.h"
#include "ui_demo_ipaddresswidget.h"

#include <QMessageBox>

Demo_IpAddressWidget::Demo_IpAddressWidget(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_IpAddressWidget)
{
    ui->setupUi(this);

    this->setWindowTitle (title);
}

Demo_IpAddressWidget::~Demo_IpAddressWidget()
{
    delete ui;
}

void Demo_IpAddressWidget::on_pushButton_clicked()
{
    QString ip = ui->widget->getIpAddress ();
    if (ip.isEmpty ())
    {
        QMessageBox::information( this, tr("Error"), tr("The IP address is illegal") );
    }else
    {
        QMessageBox::information(this, tr("IP Address"), ip);
    }
}
