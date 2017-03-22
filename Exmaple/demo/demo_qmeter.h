#ifndef DEMO_QMETER_H
#define DEMO_QMETER_H

#include <QWidget>

namespace Ui {
class Demo_qmeter;
}

class Demo_qmeter : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_qmeter(const QString &title = "",
                         QWidget *parent = 0);
    ~Demo_qmeter();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::Demo_qmeter *ui;
};

#endif // DEMO_QMETER_H
