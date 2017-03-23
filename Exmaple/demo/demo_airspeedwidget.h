#ifndef DEMO_AIRSPEEDWIDGET_H
#define DEMO_AIRSPEEDWIDGET_H

#include <QDialog>

namespace Ui {
class Demo_AirSpeedWidget;
}

class Demo_AirSpeedWidget : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_AirSpeedWidget(const QString &title ="",
                                 QWidget *parent = 0);
    ~Demo_AirSpeedWidget();

private slots:
    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Demo_AirSpeedWidget *ui;
};

#endif // DEMO_AIRSPEEDWIDGET_H
