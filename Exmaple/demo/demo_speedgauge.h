#ifndef DEMO_SPEEDGAUGE_H
#define DEMO_SPEEDGAUGE_H

#include <QDialog>

namespace Ui {
class Demo_SpeedGauge;
}

class Demo_SpeedGauge : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_SpeedGauge(const QString &title ="",QWidget *parent = 0);
    ~Demo_SpeedGauge();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Demo_SpeedGauge *ui;
};

#endif // DEMO_SPEEDGAUGE_H
