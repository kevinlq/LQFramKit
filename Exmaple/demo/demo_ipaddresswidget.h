#ifndef DEMO_IPADDRESSWIDGET_H
#define DEMO_IPADDRESSWIDGET_H

#include <QDialog>

namespace Ui {
class Demo_IpAddressWidget;
}

class Demo_IpAddressWidget : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_IpAddressWidget(const QString &title =""
                                  ,QWidget *parent = 0);
    ~Demo_IpAddressWidget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Demo_IpAddressWidget *ui;
};

#endif // DEMO_IPADDRESSWIDGET_H
