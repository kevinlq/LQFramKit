#include "demo_msgnotify.h"
#include "ui_demo_msgnotify.h"

#include "msgNotify/notifymanager.h"

Demo_MsgNotify::Demo_MsgNotify(const QString &title, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Demo_MsgNotify)
{
    ui->setupUi(this);

    this->setWindowTitle(title);

    m_mang = new NotifyManager(this);
}

Demo_MsgNotify::~Demo_MsgNotify()
{
    delete ui;
}

void Demo_MsgNotify::on_pushButton_clicked()
{
    m_mang->notify("新消息","你中了800W大奖",
                   ":/image/message.png",
                   "https://github.com/kevinlq");
}
