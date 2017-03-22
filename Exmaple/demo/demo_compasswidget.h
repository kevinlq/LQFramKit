#ifndef DEMO_COMPASSWIDGET_H
#define DEMO_COMPASSWIDGET_H

#include <QWidget>

namespace Ui {
class Demo_compassWidget;
}

class Demo_compassWidget : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_compassWidget(const QString &title = "",
                                QWidget *parent = 0);
    ~Demo_compassWidget();

private slots:
    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::Demo_compassWidget *ui;
};

#endif // DEMO_COMPASSWIDGET_H
