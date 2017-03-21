#ifndef DEMOMETER_H
#define DEMOMETER_H

#include <QDialog>

namespace Ui {
class DemoMeter;
}

class DemoMeter : public QDialog
{
    Q_OBJECT

public:
    explicit DemoMeter(QWidget *parent = 0);
    ~DemoMeter();

private:
    Ui::DemoMeter *ui;
};

#endif // DEMOMETER_H
