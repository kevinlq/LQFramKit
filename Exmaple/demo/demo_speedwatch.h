#ifndef DEMO_SPEEDWATCH_H
#define DEMO_SPEEDWATCH_H

#include <QWidget>

namespace Ui {
class Demo_SpeedWatch;
}

class Demo_SpeedWatch : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_SpeedWatch(const QString &title = "",QWidget *parent = 0);
    ~Demo_SpeedWatch();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Demo_SpeedWatch *ui;
};

#endif // DEMO_SPEEDWATCH_H
