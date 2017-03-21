#include <QApplication>

#include "examplewidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);

    ExampleWidget widget;
    widget.show ();

    int ret = app.exec ();
    return ret;
}

