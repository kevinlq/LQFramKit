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
    void slotTestSearchLineEdit(const QString &text);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::ExampleWidget *ui;

    void init();

    void initConnect();
};

#endif // EXAMPLEWIDGET_H
