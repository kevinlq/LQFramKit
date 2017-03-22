#ifndef DEMO_LINEEDIT_H
#define DEMO_LINEEDIT_H

#include <QWidget>

namespace Ui {
class Demo_lineEdit;
}

class Demo_lineEdit : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_lineEdit(const QString &title ="",
                           QWidget *parent = 0);
    ~Demo_lineEdit();

Q_SIGNALS:
    void signalSearchContent(const QString&);

private:
    Ui::Demo_lineEdit *ui;
};

#endif // DEMO_LINEEDIT_H
