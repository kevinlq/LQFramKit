#ifndef CRULER_H
#define CRULER_H

#include <QWidget>
#include <QTextOption>

class LQTOOLSSHARED_EXPORT CRuler : public QWidget
{
    Q_OBJECT
public:
    explicit CRuler(QWidget *parent = 0);
    void setOrientation(Qt::Orientation orn);
    QSize sizeHint() const;

signals:
    void moved(const QPoint &);

private:
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*e);
    void mouseMoveEvent(QMouseEvent*e);
    void mouseReleaseEvent(QMouseEvent*e);

private:
    double m_pixmm;
    QBrush m_brush;
    QTextOption m_to;
    QPoint m_pos;
    int m_widthmm, m_heightmm;
    int m_width, m_height;
    Qt::Orientation m_orn;
};

#endif // CRULER_H
