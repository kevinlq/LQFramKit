/*************************************************
Copyright:kevin
Author:Kevin LiQi
Date:2015-11-27
Email:kevinlq0912@163.com
QQ:936563422
Description:自定义实现一个消息框
**************************************************/
#ifndef MSGBOXBASE_H
#define MSGBOXBASE_H

#include <QDialog>
class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class QLabel;
class QWidget;


class LQFORMWIDGETSHARED_EXPORT MsgBoxBase : public QDialog
{
    Q_OBJECT
public:
    explicit MsgBoxBase(QWidget *parent = 0);

    //定义显示消息的类别函数
    void showMessageError(const QString &msg);      //显示错误消息框
    int showMessageQuestion(const QString &msg);    //显示询问消息框
    void showMessageInfo(const QString &msg);       //显示提示消息框
    
signals:
    
    void signalsClose();
public slots:

protected:
    QPoint dragPosition;                            //记录当前窗体的位置

    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
private:
    void initForm();                                //样式初始化
    void initWidget();                              //窗体初始化

    void initTitleWidet();                          //顶部标题栏初始化
    void initBodyWidget();                          //中间消息内容初始化
    void initBottomWidet();                         //底部按钮初始化

    void initLayout();                              //布局初始化
    void initConnect();                             //信号和槽初始化

    void loadSeyleFile();                           //加载样式表文件

private:
    QWidget *m_widgetTitle;                         //顶部标题栏窗体
    QLabel *m_labelWinIcon;                         //顶部标题栏图标
    QLabel *m_lableWinTitle;                        //顶部标题栏文字
    QPushButton *m_pbnClose;                        //顶部标题栏关闭按钮
    QHBoxLayout *m_horLayoutTitle;                  //顶部水平布局

    QWidget *m_widgetBody;                          //中间窗体
    QLabel *m_labelIcon;                            //中间标题
    QLabel *m_labelContent;                         //中间提示图标
    QHBoxLayout *m_horLayoutBody;                   //中间布局

    QWidget *m_widgetButton;                        //底部窗体
    QPushButton *m_pbnOk;                           //确定按钮
    QPushButton *m_pbnCancel;                       //取消按钮
    QHBoxLayout *m_horLayoutBtn;                    //底部水平布局

    QVBoxLayout *m_verLayoutGlobal;                 //整体垂直布局
    
};

#endif // MSGBOXBASE_H
