
#include <QDesktopWidget>
#include <QPropertyAnimation>
#include <QApplication>
#include <QDebug>
#include <QTimer>

//#include "notifymanager.h"
#include "msgNotify/notifymanager.h"

const int RIGHT = 10;
const int BOTTOM = 10;

const int HEIGHT = 60;
const int WIDTH = 300;

const int SPACE = 20;

NotifyManager::NotifyManager(QObject *parent): QObject(parent),
    maxCount(6),
    displayTime(10 * 1000)
{

}

void NotifyManager::notify(const QString &title, const QString &body,
                           const QString &icon, const QString url)
{
    dataQueue.enqueue(NotifyData(icon, title, body, url));
    showNext();
}

void NotifyManager::setMaxCount(int count)
{
    maxCount = count;
}

void NotifyManager::setDisplayTime(int ms)
{
    displayTime = ms;
}

// 调整所有提醒框的位置
void NotifyManager::rearrange()
{
    QDesktopWidget *desktop = QApplication::desktop();
    QRect desktopRect = desktop->availableGeometry();
    QPoint bottomRignt = desktopRect.bottomRight();

    QList<Notify*>::iterator i;
    for (i = notifyList.begin(); i != notifyList.end(); ++i) {
        int index = notifyList.indexOf((*i));

        QPoint pos = bottomRignt -
                QPoint(WIDTH + RIGHT,
                       (HEIGHT + SPACE) * (index + 1) - SPACE + BOTTOM);
        QPropertyAnimation *animation = new QPropertyAnimation((*i), "pos", this);
        animation->setStartValue((*i)->pos());
        animation->setEndValue(pos);
        animation->setDuration(300);
        animation->start();

        connect(animation, &QPropertyAnimation::finished, this, [animation, this](){
            animation->deleteLater();
        });
    }
}


void NotifyManager::showNext()
{
    if(notifyList.size() >= maxCount || dataQueue.isEmpty()) {
        return;
    }

    NotifyData data = dataQueue.dequeue();
    Notify *notify = new Notify(this->displayTime);
    notify->setIcon(data.icon);
    notify->setTitle(data.title);
    notify->setBody(data.body);
    notify->setUrl(data.url);

    notify->setFixedSize(WIDTH, HEIGHT);

    QDesktopWidget *desktop = QApplication::desktop();
    QRect desktopRect = desktop->availableGeometry();

    // 计算提醒框的位置
    QPoint bottomRignt = desktopRect.bottomRight();
    QPoint pos = bottomRignt - QPoint(notify->width() + RIGHT, (HEIGHT + SPACE) * (notifyList.size() + 1) - SPACE + BOTTOM);


    notify->move(pos);
    notify->showGriant();
    notifyList.append(notify);

    connect(notify, &Notify::disappeared, this, [notify, this](){
        this->notifyList.removeAll(notify);
        this->rearrange();

        // 如果列表是满的，重排完成后显示
        if(this->notifyList.size() == this->maxCount - 1){
            QTimer::singleShot(300, this, [this]{
               this->showNext();
            });
        } else {
            this->showNext();
        }
        notify->deleteLater();
    });
}

