#include <QApplication>

#include "lqexamplewidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    LQExampleWidget widget;
    widget.show();

    int ret = app.exec();

    return ret;
}

