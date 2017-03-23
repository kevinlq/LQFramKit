#ifndef DEMO_COLORPROGRESSBAR_H
#define DEMO_COLORPROGRESSBAR_H

#include <QDialog>

namespace Ui {
class Demo_ColorProgressBar;
}

class Demo_ColorProgressBar : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_ColorProgressBar(const QString &title ="",
                                   QWidget *parent = 0);
    ~Demo_ColorProgressBar();
private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

    void on_horizontalSlider_3_valueChanged(int value);

private:

private:
    Ui::Demo_ColorProgressBar *ui;
};

#endif // DEMO_COLORPROGRESSBAR_H
