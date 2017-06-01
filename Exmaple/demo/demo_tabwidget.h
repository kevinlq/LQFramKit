#ifndef DEMO_TABWIDGET_H
#define DEMO_TABWIDGET_H

#include <QWidget>

class MyTabWidget;

namespace Ui {
class Demo_tabwidget;
}

class Demo_tabwidget : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_tabwidget(const QString &title = "",QWidget *parent = 0);
    ~Demo_tabwidget();

private:
    Ui::Demo_tabwidget *ui;
    MyTabWidget *m_ptabWidget;
};

#endif // DEMO_TABWIDGET_H
