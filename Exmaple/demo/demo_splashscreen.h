#ifndef DEMO_SPLASHSCREEN_H
#define DEMO_SPLASHSCREEN_H

#include <QWidget>

namespace Ui {
class Demo_SplashScreen;
}

class Demo_SplashScreen : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_SplashScreen(const QString &title = "",
                               QWidget *parent = 0);
    ~Demo_SplashScreen();

    void showWidget();

private:
    Ui::Demo_SplashScreen *ui;
};

#endif // DEMO_SPLASHSCREEN_H
