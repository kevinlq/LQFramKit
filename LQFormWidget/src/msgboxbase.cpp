/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-11-27
Email:kevinlq0912@163.com
QQ:936563422
Description:自定义实现一个消息框
**************************************************/

#include "StdMain.h"

#include "msgboxbase.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>
#include <QPixmap>
#include <QStyleOption>
#include <QMouseEvent>

MsgBoxBase::MsgBoxBase(QWidget *parent) :
    QDialog(parent)
{
    this->initForm();
    this->initWidget();
    this->initLayout();
    this->initConnect();
    this->loadSeyleFile();
}

//错误消息提示框
void MsgBoxBase::showMessageError(const QString &msg)
{
    m_lableWinTitle->setText(QString("错误"));
    m_labelContent->setText(msg);
    m_pbnCancel->setVisible(false);     //取消按钮不可见
    this->exec();
}

/**
 * @Function:       showMessageQuestion(const QString &msg)
 * @Description:    显示询问消息框
 * @Calls:          外部调用
 * @Input:          msg:消息内容
 * @Output:         无
 * @Return:         0(Accepted)
 *                  1(Rejected)
 * @Others:         调用方式说明：通过返回值来判断用户是按下了确认按钮还是取消按钮
 *                  按下确认按钮：返回值1
 *                  按下取消按钮：返回值0
 */
int MsgBoxBase::showMessageQuestion(const QString &msg)
{
    m_lableWinTitle->setText(QString("询问"));
    m_labelContent->setText(msg);
    m_pbnCancel->setVisible(true);      //取消按钮可见

    return this->exec();
}

//提示消息框
void MsgBoxBase::showMessageInfo(const QString &msg)
{
    m_lableWinTitle->setText(QString("提示"));
    m_labelContent->setText(msg);
    m_pbnCancel->setVisible(false);     //取消按钮不可见
    this->exec();
}

//界面样式初始化
void MsgBoxBase::initForm()
{
    this->setFixedSize(340,155);
    this->setObjectName("msgBox");
    this->setWindowFlags(Qt::FramelessWindowHint);
}

//界面初始化
void MsgBoxBase::initWidget()
{
    this->initTitleWidet();
    this->initBodyWidget();
    this->initBottomWidet();
}

//顶部标题栏初始化
void MsgBoxBase::initTitleWidet()
{
    //标题栏控件初始化
    m_widgetTitle = new QWidget(this);
    m_widgetTitle->setFixedHeight(20);

    m_labelWinIcon = new QLabel(this);
    m_labelWinIcon->setAlignment(Qt::AlignCenter);

    m_lableWinTitle = new QLabel(this);

    m_pbnClose = new QPushButton(this);
    m_pbnClose->setFocusPolicy(Qt::NoFocus);
    m_pbnClose->setIcon(style()->standardPixmap(QStyle::SP_DialogCloseButton));

    //设置对象名称，方面在样式表中设置样式
    m_widgetTitle->setObjectName("widgetTitle");
    m_labelWinIcon->setObjectName("labelWinIcon");
    m_lableWinTitle->setObjectName("labelWinTitle");
    m_pbnClose->setObjectName("btnClose");

    m_labelWinIcon->setPixmap(style()->standardPixmap(QStyle::SP_DesktopIcon));
}

//中间消息框初始化
void MsgBoxBase::initBodyWidget()
{
    m_widgetBody = new QWidget(this);
    m_labelIcon = new QLabel(this);
    m_labelContent = new QLabel(this);
    m_labelContent->setWordWrap(true);

    m_widgetBody->setObjectName("widgetBody");
    m_labelIcon->setObjectName("labelIcon");
    m_labelContent->setObjectName("labelContent");

    m_labelIcon->setPixmap(style()->standardPixmap(QStyle::SP_MessageBoxInformation));
}

//底部按钮初始化
void MsgBoxBase::initBottomWidet()
{
    m_widgetButton = new QWidget(this);

    m_pbnOk = new QPushButton(this);
    m_pbnOk->setFocusPolicy(Qt::NoFocus);
    m_pbnOk->setText(QString("确定"));

    m_pbnCancel = new QPushButton(this);
    m_pbnCancel->setFocusPolicy(Qt::NoFocus);
    m_pbnCancel->setText(QString("取消"));

    m_widgetButton->setObjectName("widgetButton");
    m_pbnOk->setObjectName("btnCancel");
    m_pbnCancel->setObjectName("btnOk");
}

void MsgBoxBase::initLayout()
{
    //标题栏布局管理
    m_horLayoutTitle = new QHBoxLayout(m_widgetTitle);
    m_horLayoutTitle->setContentsMargins(10,0,0,0);
    m_horLayoutTitle->setSpacing(4);
    m_horLayoutTitle->addWidget(m_labelWinIcon,0,Qt::AlignCenter);
    m_horLayoutTitle->addWidget(m_lableWinTitle,4,Qt::AlignLeft);
    m_horLayoutTitle->addWidget(m_pbnClose,0,Qt::AlignLeft);

    //中间消息内容布局
    m_horLayoutBody = new QHBoxLayout(m_widgetBody);
    m_horLayoutBody->setContentsMargins(10,10,10,10);
    m_horLayoutBody->setSpacing(10);
    m_horLayoutBody->addWidget(m_labelIcon,1,Qt::AlignCenter);
    m_horLayoutBody->addWidget(m_labelContent,5);

    //底部按钮布局
    m_horLayoutBtn = new QHBoxLayout(m_widgetButton);
    m_horLayoutBtn->setContentsMargins(10,5,10,5);
    m_horLayoutBtn->setSpacing(10);
    m_horLayoutBtn->addStretch();
    m_horLayoutBtn->addWidget(m_pbnCancel,0,Qt::AlignCenter);
    m_horLayoutBtn->addWidget(m_pbnOk,0,Qt::AlignCenter);

    //全局布局
    m_verLayoutGlobal = new QVBoxLayout(this);
    m_verLayoutGlobal->setContentsMargins(2,1,2,1);
    m_verLayoutGlobal->setSpacing(0);
    m_verLayoutGlobal->addWidget(m_widgetTitle);
    m_verLayoutGlobal->addWidget(m_widgetBody,3);
    m_verLayoutGlobal->addWidget(m_widgetButton);
}

void MsgBoxBase::initConnect()
{
    connect(m_pbnClose,SIGNAL(clicked()),this,SLOT(close()));
    connect(m_pbnOk,SIGNAL(clicked()),this,SLOT(accept()));
    connect(m_pbnCancel,SIGNAL(clicked()),this,SLOT(reject()));
}

void MsgBoxBase::loadSeyleFile()
{
    // 加载样式表文件
    QFile file(":image/message.css");
    file.open(QIODevice::ReadOnly);
    this->setStyleSheet(file.readAll());
    file.close();
}


void MsgBoxBase::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        dragPosition = e->globalPos() - frameGeometry().topLeft();
        e->accept();
    }
}

void MsgBoxBase::mouseMoveEvent(QMouseEvent *e)
{
    if (e->buttons() == Qt::LeftButton)
    {
        this->move(e->globalPos() - dragPosition);
        e->accept();
    }
}

#include "moc_msgboxbase.cpp"
