#ifndef DEMO_MSGNOTIFY_H
#define DEMO_MSGNOTIFY_H

#include <QWidget>
class NotifyManager;

namespace Ui {
class Demo_MsgNotify;
}

class Demo_MsgNotify : public QWidget
{
    Q_OBJECT

public:
    explicit Demo_MsgNotify(const QString &title = "",QWidget *parent = 0);
    ~Demo_MsgNotify();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Demo_MsgNotify *ui;
    NotifyManager *m_mang;
};

#endif // DEMO_MSGNOTIFY_H
