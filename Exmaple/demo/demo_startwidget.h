#ifndef DEMO_STARTWIDGET_H
#define DEMO_STARTWIDGET_H

#include <QDialog>

class LQStartWidget;

namespace Ui {
class Demo_StartWidget;
}

class Demo_StartWidget : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_StartWidget(const QString &title = "",
                              QWidget *parent = 0);
    ~Demo_StartWidget();

Q_SIGNALS:
    void signalShow();

private:
    Ui::Demo_StartWidget *ui;
    LQStartWidget *m_pStartWidget;
};

#endif // DEMO_STARTWIDGET_H
