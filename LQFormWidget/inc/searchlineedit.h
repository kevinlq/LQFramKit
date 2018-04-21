/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2016-03-11
Email:kevinlq0912@163.com
QQ:936563422
Version:V1.0
Description:自定义搜索框的实现
**************************************************/
#ifndef SEARCHLINEEDIT_H
#define SEARCHLINEEDIT_H
#include <QLineEdit>
#include <QWidget>
class QToolButton;
class QHBoxLayout;
class QWidget;


class LQFORMWIDGETSHARED_EXPORT SearchLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    SearchLineEdit(QWidget *parent = 0);
    ~SearchLineEdit();

    void initForm();
    void initConnect();
    void translator();
protected:
    virtual void focusInEvent(QFocusEvent * event);
    virtual void focusOutEvent(QFocusEvent * event);

private Q_SLOTS:
    void slotSendSearchContent();
Q_SIGNALS:
    void signalSearchContent(const QString &test);

private:
    QToolButton *m_tbnSearch;
    QHBoxLayout *m_mainLayout;
};

#endif // SEARCHLINEEDIT_H
