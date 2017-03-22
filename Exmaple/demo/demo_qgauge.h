#ifndef DEMO_QGAUGE_H
#define DEMO_QGAUGE_H

#include <QWidget>

namespace Ui {
class Demo_qgauge;
}

class Demo_qgauge : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_qgauge(const QString &title ="",
                         QWidget *parent = 0);
    ~Demo_qgauge();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::Demo_qgauge *ui;
};

#endif // DEMO_QGAUGE_H
