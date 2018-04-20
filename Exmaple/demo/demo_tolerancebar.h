#ifndef DEMO_TOLERANCEBAR_H
#define DEMO_TOLERANCEBAR_H

#include <QWidget>

namespace Ui {
class Demo_ToleranceBar;
}

class Demo_ToleranceBar : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_ToleranceBar(const QString &title,QWidget *parent = 0);
    ~Demo_ToleranceBar();

Q_SIGNALS:
    void signalValueChange(const int &value);

private:
    Ui::Demo_ToleranceBar *ui;
};

#endif // DEMO_TOLERANCEBAR_H
