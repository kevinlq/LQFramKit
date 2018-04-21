#include "LQFormWidgetIncLib.h"

#include "demo_splashscreen.h"
#include "ui_demo_splashscreen.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QTimer>

#define LOAD_TIME   2000

Demo_SplashScreen::Demo_SplashScreen(const QString &title,
                                     QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_SplashScreen)
{
    ui->setupUi(this);

    setWindowTitle(title);
}

Demo_SplashScreen::~Demo_SplashScreen()
{
    delete ui;
}

void Demo_SplashScreen::showWidget()
{
    QPixmap pixmap(":/image/start/Splashscreen.png");
    pixmap.scaled(QApplication::desktop()->availableGeometry().size()
                  ,Qt::KeepAspectRatio);
    CMySplashScreen *splash = new CMySplashScreen(pixmap,LOAD_TIME);
    splash->setDisabled(true);
    splash->show();

    QTimer::singleShot(LOAD_TIME,this,SLOT(show()));
}

