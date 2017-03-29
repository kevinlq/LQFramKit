//#include "messagetitle.h"
#include "messageWidget/messagetitle.h"

/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-11-11
Email:kevinlq0912@163.com
QQ:2313828706
Version:V1.0
Description:自定义消息框标题栏
**************************************************/
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPainter>

MessageTitle::MessageTitle(QWidget *parent)
    : QWidget(parent)
{
    initForm ();
    initLayout ();
    initConnect ();
}

MessageTitle::~MessageTitle()
{
}

void MessageTitle::setTitleText(const QString &text)
{
    m_pTitleLabel->setText (text);
}

void MessageTitle::initForm()
{
    setFixedHeight (30);

    m_pTitleLabel = new QLabel();

    m_pPbnClose = new QPushButton();
    m_pPbnClose->setToolTip ("关闭");
    m_pPbnClose->setIcon (QIcon(":/image/button_close.png"));

    QFont title_font = m_pTitleLabel->font ();
    title_font.setBold (true);
    m_pTitleLabel->setFont (title_font);
}

void MessageTitle::initLayout()
{
    m_pLayout = new QHBoxLayout;

    m_pLayout->addWidget (m_pTitleLabel);
    m_pLayout->addStretch ();
    m_pLayout->addWidget (m_pPbnClose);
    m_pLayout->setMargin (0);
    setLayout (m_pLayout);
}

void MessageTitle::initConnect()
{
    connect (m_pPbnClose,SIGNAL(clicked(bool)),this,SIGNAL(signal_Close()));
}

void MessageTitle::paintEvent(QPaintEvent *)
{
    QLinearGradient linear(rect().topLeft(), rect().bottomRight());
    linear.setColorAt(0, QColor(55, 135, 215));
    linear.setColorAt(0.5, QColor(140, 120, 185));
    linear.setColorAt(1, QColor(55, 135, 215));

    QPainter painter(this);
    painter.setBrush(QBrush(linear));
    painter.setPen(Qt::NoPen);
    painter.drawRect(rect());


}
