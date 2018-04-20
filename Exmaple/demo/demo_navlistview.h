#ifndef DEMO_NAVLISTVIEW_H
#define DEMO_NAVLISTVIEW_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class Demo_NavListView;
}

class Demo_NavListView : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_NavListView(const QString &title = "",QWidget *parent = 0);
    ~Demo_NavListView();

private:
    void initForm();

private:
    Ui::Demo_NavListView *ui;
};

#endif // DEMO_NAVLISTVIEW_H
