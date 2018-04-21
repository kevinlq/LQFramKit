#ifndef TOLERANCEBAR_H
#define TOLERANCEBAR_H

#include <QWidget>


struct TolerDataPrivate;

class LQFORMWIDGETSHARED_EXPORT ToleranceBar : public QWidget
{
    Q_OBJECT
public:
    explicit ToleranceBar(QWidget *parent = 0);
    ~ToleranceBar();

private:
    void init();

Q_SIGNALS:
    void signalSendValue(const int &value);
    
public Q_SLOTS:

protected:
    void mousePressEvent(QMouseEvent * qevent);

    void mouseMoveEvent(QMouseEvent *qevent);

    void mouseReleaseEvent(QMouseEvent *qevent);

    void paintEvent(QPaintEvent *);

private:
    TolerDataPrivate *d;
};

#endif // TOLERANCEBAR_H
