#ifndef MESSAGEWIDGET_H
#define MESSAGEWIDGET_H

#include <QWidget>

#include "../lqformwidget_global.h"

class MessageTitle;
class QVBoxLayout;
class QLabel;
class QTimer;

class LQFORMWIDGETSHARED_EXPORT MessageWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MessageWidget(QWidget *parent = 0);
    ~MessageWidget();
    //显示消息
    void showMsg(const QString &iconPath,
                 const QString &title,
                 const QString &content);
    void showMessage();
signals:

public slots:
    void slot_MyMove();
    void slot_myState();
    void slot_myClose();

private:
    void initForm();
    void initLayout();
    void initConnect();

protected:
    void paintEvent (QPaintEvent*);

private:
    MessageTitle *m_pTitle;
    QLabel *m_pContentLabel;
    QTimer *m_pTimerShow;
    QTimer *m_pTimerStay;
    QTimer *m_pTimerClose;
    QLabel *m_pIconLabel;

    int m_time_count;
    int m_desktop_height;
    float m_transparent;
    QPoint m_normal_point;
    QRect m_desk_rect;

    QVBoxLayout *m_pMainLayout;

};

#endif // MESSAGEWIDGET_H
