/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-11-11
Email:kevinlq0912@163.com
QQ:2313828706
Version:V1.0
Description:自定义弹出消息框界面
**************************************************/
//#include "messagewidget.h"
//#include "messagetitle.h"
#include "messageWidget/messagewidget.h"
#include "messageWidget/messagetitle.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

#include <QApplication>
#include <QDesktopWidget>
#include <QBitmap>
#include <QPainter>

MessageWidget::MessageWidget(QWidget *parent)
    : QWidget(parent)
{
    initForm ();
    initLayout ();
    initConnect ();
}

MessageWidget::~MessageWidget()
{
}

/*
 * 显示消息，外部调用
*/
void MessageWidget::showMsg(const QString &iconPath,
                            const QString &title,
                            const QString &content)
{
    Q_ASSERT_X(iconPath != "","iconPath","iconPath is can not empty!");

    QPixmap pixmap(iconPath);
    m_pIconLabel->setPixmap (pixmap);
    m_pTitle->setTitleText (" "+title);
    m_pContentLabel->setText (" "+content);
    this->showMessage();
}

void MessageWidget::showMessage()
{
    m_time_count = 0;
    m_transparent = 1.0;
    m_desktop_height = QApplication::desktop ()->height ();
    m_pTimerShow->stop ();
    m_pTimerStay->stop ();
    m_pTimerClose->stop ();
    setWindowOpacity (1);

    QDesktopWidget *desktop = QApplication::desktop ();
    m_desk_rect = desktop->availableGeometry ();
    m_normal_point.setX (m_desk_rect.width () - rect ().width ());
    m_normal_point.setY (m_desk_rect.height () - rect ().height ());
    move(m_normal_point.x (),m_normal_point.y ());

    showNormal ();
    m_pTimerShow->start (5);
}

void MessageWidget::slot_MyMove()
{
    m_desktop_height--;
    move (m_normal_point.x (),m_desktop_height);
    if (m_desktop_height <= m_normal_point.y ())
    {
        m_pTimerShow->stop ();
        m_pTimerStay->start (1000);
    }
}

void MessageWidget::slot_myState()
{
    m_time_count++;
    if (m_time_count >= 4)
    {
        m_pTimerStay->stop ();
        m_pTimerClose->start (100);
    }
}

void MessageWidget::slot_myClose()
{
    m_transparent -= 0.1;
    if (m_transparent <= 0.0)
    {
        m_pTimerClose->stop ();
        this->close ();
    }else
    {
        setWindowOpacity (m_transparent);
    }
}

void MessageWidget::initForm()
{
    setFixedSize (300,180);
    setWindowFlags (Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    m_pTitle = new MessageTitle(this);

    m_pContentLabel = new QLabel;
    m_pIconLabel = new QLabel;

    m_pTimerShow = new QTimer(this);
    m_pTimerStay = new QTimer(this);
    m_pTimerClose = new QTimer(this);

    m_time_count = 0;
    m_transparent = 1.0;
    m_desktop_height = QApplication::desktop ()->height ();

    m_pIconLabel->setFixedSize (64,64);
    m_pContentLabel->setWordWrap (true);
    m_pContentLabel->setAlignment (Qt::AlignTop);

}

/*
 * 初始化布局
*/
void MessageWidget::initLayout()
{
    QVBoxLayout *v_layout = new QVBoxLayout();
    v_layout->addWidget (m_pIconLabel);
    v_layout->addStretch ();

    QVBoxLayout *v_layout2 = new QVBoxLayout();
    QSpacerItem *spacerItem = new QSpacerItem(20,20,QSizePolicy::Minimum,QSizePolicy::Minimum);
    v_layout2->addSpacerItem (spacerItem);
    v_layout2->addWidget (m_pContentLabel);

    QHBoxLayout *h_layout = new QHBoxLayout();
    h_layout->addLayout (v_layout);
    h_layout->addLayout (v_layout2);
    QMargins margins = h_layout->contentsMargins ();
    margins.setTop (20);
    margins.setLeft (10);
    margins.setRight (10);
    h_layout->setContentsMargins (margins);

    m_pMainLayout = new QVBoxLayout;
    m_pMainLayout->setMargin (0);
    m_pMainLayout->addWidget (m_pTitle);
    m_pMainLayout->addLayout (h_layout);
    setLayout (m_pMainLayout);

}

//初始化信号和槽的连接
void MessageWidget::initConnect()
{
    connect (m_pTimerShow,SIGNAL(timeout()),this,SLOT(slot_MyMove()));
    connect (m_pTimerStay,SIGNAL(timeout()),this,SLOT(slot_myState()));
    connect (m_pTimerClose,SIGNAL(timeout()),this,SLOT(slot_myClose()));
    connect (m_pTitle,SIGNAL(signal_Close()),this,SLOT(close()));
}

void MessageWidget::paintEvent(QPaintEvent *)
{
    QBitmap bitmap(this->size());
    bitmap.fill(Qt::white);
    QPainter painter(this);
    painter.setBrush(QBrush(QColor(250, 240, 230)));
    painter.setPen(QPen(QBrush(QColor(55, 135, 215)), 6));
    painter.drawRoundedRect(bitmap.rect(), 5, 5);
    setMask(bitmap);
}
