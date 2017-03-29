#ifndef DEMO_RIGHTDOWNMESSAGEBOX_H
#define DEMO_RIGHTDOWNMESSAGEBOX_H

#include <QDialog>

class MessageWidget;

namespace Ui {
class Demo_RightDownMessageBox;
}

class Demo_RightDownMessageBox : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_RightDownMessageBox(const QString &title = "",
                                      QWidget *parent = 0);
    ~Demo_RightDownMessageBox();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Demo_RightDownMessageBox *ui;

    MessageWidget   *m_pMessageBox;
};

#endif // DEMO_RIGHTDOWNMESSAGEBOX_H
