#ifndef EXAMPLEWIDGET_H
#define EXAMPLEWIDGET_H

#include <QWidget>

class CreateProjectFileForm;

namespace Ui {
class ExampleWidget;
}

class ExampleWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExampleWidget(QWidget *parent = 0);
    ~ExampleWidget();

private Q_SLOTS:
    void slotToleranceBarValue(const int &value);

private slots:
    void slotTestSearchLineEdit(const QString &text);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_26_clicked();
    
    void on_pushButton_27_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_29_clicked();

protected:
    virtual void closeEvent(QCloseEvent *event);

private:
    void init();

    void initConnect();

private:
    Ui::ExampleWidget *ui;

    CreateProjectFileForm   *m_pCreatePro;
};

#endif // EXAMPLEWIDGET_H
