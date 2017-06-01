#include "tabWidget/mytabwidget.h"

#include <QTabBar>
#include "tabWidget/customtabstyle.h"

MyTabWidget::MyTabWidget(QWidget *parent)
    :QTabWidget(parent)
{
    setTabPosition(QTabWidget::West);

    tabBar()->setStyle(new CustomTabStyle);
}

MyTabWidget::~MyTabWidget()
{
}
