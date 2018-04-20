#ifndef MYTABWIDGET_H
#define MYTABWIDGET_H

#include <QTabWidget>
#include "../lqformwidget_global.h"

class LQFORMWIDGETSHARED_EXPORT MyTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    explicit MyTabWidget(QWidget *parent = 0);
    ~MyTabWidget();
};

#endif // MYTABWIDGET_H
