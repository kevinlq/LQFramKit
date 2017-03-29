#ifndef MESSAGETITLE_H
#define MESSAGETITLE_H

#include <QWidget>

#include "../lqformwidget_global.h"

class QLabel;
class QPushButton;
class QHBoxLayout;

class LQFORMWIDGETSHARED_EXPORT MessageTitle : public QWidget
{
    Q_OBJECT
public:
    explicit MessageTitle(QWidget *parent = 0);
    ~MessageTitle();

    void setTitleText(const QString &);

signals:
    void signal_Close();

public slots:

private:
    void initForm();
    void initLayout();
    void initConnect();

protected:
    void paintEvent (QPaintEvent*);

private:
    QLabel *m_pTitleLabel;
    QPushButton *m_pPbnClose;
    QHBoxLayout *m_pLayout;
};

#endif // MESSAGETITLE_H
