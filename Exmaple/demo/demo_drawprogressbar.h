#ifndef DEMO_DRAWPROGRESSBAR_H
#define DEMO_DRAWPROGRESSBAR_H

#include <QDialog>

namespace Ui {
class Demo_DrawProgressbar;
}

class Demo_DrawProgressbar : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_DrawProgressbar(const QString &title = "",
                                  QWidget *parent = 0);
    ~Demo_DrawProgressbar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Demo_DrawProgressbar *ui;
};

#endif // DEMO_DRAWPROGRESSBAR_H
