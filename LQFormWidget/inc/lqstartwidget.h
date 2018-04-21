#ifndef LQSTARTWIDGET_H
#define LQSTARTWIDGET_H

#include <QWidget>

class QGridLayout;
class QLabel;
class QTimer;

class LQFORMWIDGETSHARED_EXPORT LQStartWidget : public QWidget
{
    Q_OBJECT
public:
    explicit LQStartWidget(QWidget *parent = 0);
    ~LQStartWidget();

    /**
      @breif:设置加载文本
    */
    void setLoadText(const QString &title);

    /**
      @breif:设置加载时间
    */
    void setLoadTime(int count);

    void setStartShow();

private:
    void init();

    void initWidget();

protected:
    virtual void mousePressEvent (QMouseEvent *event);

    virtual void mouseMoveEvent (QMouseEvent *event);

    virtual void paintEvent (QPaintEvent *event);

Q_SIGNALS:
    void signalLoadFinish();

private Q_SLOTS:
    void slotLoading();

    void slotCountShow();

private:
    QGridLayout *m_pGridLayout;
    QLabel  *m_pLabelNum;
    QLabel  *m_pLabelLoadText;

    QPoint  m_pWindowPos;
    QPoint  m_pMousePos;
    QPoint  m_pDPos;

    QImage  *m_pImage;

    QTimer  *m_pLoadTime;
    QTimer  *m_pCountTime;

    int     m_w;
    int     m_h;
    int     m_dig;

    int     m_count;
};

#endif // LQSTARTWIDGET_H
