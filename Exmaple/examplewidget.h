#ifndef EXAMPLEWIDGET_H
#define EXAMPLEWIDGET_H

#include <QWidget>

namespace Ui {
class ExampleWidget;
}

class ExampleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExampleWidget(QWidget *parent = 0);
    ~ExampleWidget();

private slots:

private:
    Ui::ExampleWidget *ui;

    void init();

    void initConnect();
};

#endif // EXAMPLEWIDGET_H
