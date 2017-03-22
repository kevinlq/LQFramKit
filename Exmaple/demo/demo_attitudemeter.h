#ifndef DEMO_ATTITUDEMETER_H
#define DEMO_ATTITUDEMETER_H

#include <QWidget>

namespace Ui {
class Demo_AttitudeMeter;
}

class Demo_AttitudeMeter : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_AttitudeMeter(const QString &title = "",QWidget *parent = 0);
    ~Demo_AttitudeMeter();

private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_verticalSlider_valueChanged(int value);

private:
    Ui::Demo_AttitudeMeter *ui;
};

#endif // DEMO_ATTITUDEMETER_H
