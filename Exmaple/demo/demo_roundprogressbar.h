#ifndef DEMO_ROUNDPROGRESSBAR_H
#define DEMO_ROUNDPROGRESSBAR_H

#include <QDialog>

namespace Ui {
class Demo_RoundProgressBar;
}

class Demo_RoundProgressBar : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_RoundProgressBar(const QString &title = "",
                                   QWidget *parent = 0);
    ~Demo_RoundProgressBar();

private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
    void connectToSlider(class QRoundProgressBar* bar);

private:
    Ui::Demo_RoundProgressBar *ui;
};

#endif // DEMO_ROUNDPROGRESSBAR_H
