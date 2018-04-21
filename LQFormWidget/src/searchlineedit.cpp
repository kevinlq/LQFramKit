/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-11
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:自定义搜索框的实现
**************************************************/

#include "StdMain.h"

#include "searchlineedit.h"

#include <QLineEdit>
#include <QToolButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QFocusEvent>
#include <QApplication>
#include <QClipboard>

SearchLineEdit::SearchLineEdit(QWidget *parent)
    :QLineEdit(parent)
{
    this->initForm();
    this->initConnect();
    this->translator();
}

SearchLineEdit::~SearchLineEdit()
{
}

void SearchLineEdit::initForm()
{
    this->setFixedSize(260,24);
    this->setContextMenuPolicy(Qt::CustomContextMenu);

    m_tbnSearch = new QToolButton(this);

    m_tbnSearch->setFixedSize(25,24);
    m_tbnSearch->setAutoRaise(true);
    m_tbnSearch->setCursor(Qt::PointingHandCursor);
    m_tbnSearch->setStyleSheet("QToolButton{border-image:url(:/image/search_dark.png);"
                               "background:transparent;}");

    m_mainLayout = new QHBoxLayout();
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_tbnSearch);

    //设置文本边框，防止文本覆盖按钮
    setTextMargins(0,0,20,0);
    setContentsMargins(0,0,0,0);
    m_mainLayout->setContentsMargins(2,2,4,0);
    this->setLayout(m_mainLayout);

    setStyleSheet("height:24px;border:1px ;border-radius:6px;"
                  "background-color:#E1DDDD");
}

void SearchLineEdit::initConnect()
{
    connect(m_tbnSearch,SIGNAL(clicked(bool)),
            this,SLOT(slotSendSearchContent()));
    connect(this,SIGNAL(returnPressed()),this,SLOT(slotSendSearchContent()));
}

//翻译控件
void SearchLineEdit::translator()
{
    setPlaceholderText(QString("请输入要查找的内容"));
    setToolTip(QString("查找内容"));
    m_tbnSearch->setToolTip(QString("查找"));
}

void SearchLineEdit::focusInEvent(QFocusEvent *event)
{
    QLineEdit::focusInEvent(event);

    this->clear();
    this->setPlaceholderText("");
    setStyleSheet("height:24px;border:1px ;border-radius:6px;"
                  "background-color:#FFFFFF");
    m_tbnSearch->setStyleSheet("QToolButton{border-image:url(:/image/search_dark.png);"
                               "background:transparent;}");

}

void SearchLineEdit::focusOutEvent(QFocusEvent *event)
{
    QLineEdit::focusOutEvent(event);
    setPlaceholderText(QString("请输入要查找的内容"));
    setStyleSheet("height:24px;border:1px ;border-radius:6px;"
                  "background-color:#CCC7C7");
    m_tbnSearch->setStyleSheet("QToolButton{border-image:url(:/image/search_dark.png);"
                               "background:transparent;}");
}

void SearchLineEdit::slotSendSearchContent()
{
    QString str = "";
    if (this->text().isEmpty())
        str = this->placeholderText();
    else
        str = this->text();
#ifdef DEBUG_OUT
    qDebug()<<"search content:"<<str;
#endif
    emit signalSearchContent(str);
}

#include "moc_searchlineedit.cpp"

