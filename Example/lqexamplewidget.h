#ifndef LQEXAMPLEWIDGET_H
#define LQEXAMPLEWIDGET_H

#include <QWidget>

namespace Ui {
class LQExampleWidget;
}

class LQExampleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LQExampleWidget(QWidget *parent = 0);
    ~LQExampleWidget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::LQExampleWidget *ui;
};

#endif // LQEXAMPLEWIDGET_H
