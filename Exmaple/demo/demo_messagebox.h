#ifndef DEMO_MESSAGEBOX_H
#define DEMO_MESSAGEBOX_H

#include <QDialog>

class MsgBoxBase;

namespace Ui {
class Demo_MessageBox;
}

class Demo_MessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_MessageBox(const QString &title,
                             QWidget *parent = 0);
    ~Demo_MessageBox();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Demo_MessageBox *ui;

    MsgBoxBase  *m_pMsgBox;
};

#endif // DEMO_MESSAGEBOX_H
