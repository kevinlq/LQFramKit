#ifndef DEMOGAUGE_H
#define DEMOGAUGE_H

#include <QDialog>

namespace Ui {
class DemoGauge;
}

class DemoGauge : public QDialog
{
    Q_OBJECT

public:
    explicit DemoGauge(QWidget *parent = 0);
    ~DemoGauge();

private:
    Ui::DemoGauge *ui;
};

#endif // DEMOGAUGE_H
