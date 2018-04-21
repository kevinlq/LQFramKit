#ifndef IPADDRESSWIDGET_H
#define IPADDRESSWIDGET_H

#include <QWidget>

class QSpinBox;
class QLabel;
class QHBoxLayout;


class LQFORMWIDGETSHARED_EXPORT IpAddressWidget : public QWidget
{
    Q_OBJECT
public:
    explicit IpAddressWidget(QWidget *parent = 0);
    ~IpAddressWidget();

    /**
      @brief getIpAddress() 获取IP地址
    */
    QString getIpAddress ();

    void setSeparator (const QString &separator);

protected:
    bool eventFilter (QObject *obj, QEvent *event);


private:
    void init();

Q_SIGNALS:

private Q_SLOTS:

private:
    QHBoxLayout *m_pHMainLayout;    //主布局
    QSpinBox    *m_pSpinBox[4];     //IP数字输入框
    QLabel      *m_pLabel[3];       //.号
    QString     m_Separator;        //四个数字之间的间隔
};

#endif // IPADDRESSWIDGET_H
