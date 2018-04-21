#include "LQToolsIncLib.h"

#include "cruler.h"

#include <QPainter>
#include <QDebug>
#include <QLinearGradient>
#include <QMouseEvent>
#include <QApplication>

#ifdef Q_OS_WIN
//#pragma comment(lib, "coredll.lib")
#include <qt_windows.h>
#endif

CRuler::CRuler(QWidget *parent) :
    QWidget(parent)
{
    m_orn = (Qt::Orientation)-1;
    HDC hdc = GetDC(0);
    m_widthmm = GetDeviceCaps(hdc, HORZSIZE);
    m_heightmm = GetDeviceCaps(hdc, VERTSIZE);
    m_width = GetDeviceCaps(hdc, HORZRES);
    m_height = GetDeviceCaps(hdc, VERTRES);
    m_pixmm = m_width * 1.0 / m_widthmm;

    QFont f = qApp->font();
    f.setPixelSize(m_pixmm*4);
    qApp->setFont(f);
    resize(sizeHint());
}

void CRuler::setOrientation(Qt::Orientation orn)
{
    if (m_orn != orn) {
        m_orn = orn;
        if (m_orn == Qt::Horizontal) {
            m_to.setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            QLinearGradient linearGradient(0,0,0,m_pixmm * 30);
            linearGradient.setColorAt(0.0,QColor(100,100,100,180));
            linearGradient.setColorAt(0.1,QColor(200,200,200,180));
            linearGradient.setColorAt(0.5,QColor(255,255,255,180));
            linearGradient.setColorAt(0.9,QColor(200,200,200,180));
            linearGradient.setColorAt(1.0,QColor(100,100,100,180));
            m_brush = QBrush(linearGradient);
        }
        else {
            QLinearGradient linearGradient(0,0,m_pixmm * 30,0);
            linearGradient.setColorAt(0.0,QColor(100,100,100,180));
            linearGradient.setColorAt(0.1,QColor(200,200,200,180));
            linearGradient.setColorAt(0.5,QColor(255,255,255,180));
            linearGradient.setColorAt(0.9,QColor(200,200,200,180));
            linearGradient.setColorAt(1.0,QColor(100,100,100,180));
            m_brush = QBrush(linearGradient);
        }
    }
    update();
}

QSize CRuler::sizeHint() const
{
    return m_orn == Qt::Horizontal ? QSize(m_width, m_pixmm * 30) : QSize(m_pixmm * 30, m_height);
}

void CRuler::paintEvent(QPaintEvent *)
{
    QPixmap bmp = QPixmap(sizeHint());
    QPainter paint(&bmp);
    paint.fillRect(rect(), m_brush);

    if (m_orn == Qt::Horizontal)
    {
        for (int i = 0; i < m_widthmm; i++)
        {
            paint.drawLine(QPointF(i*m_pixmm + 0.5, 0),
                           QPointF(i*m_pixmm + 0.5,
                                   (i%10==0 ? 5 : (i%5==0 ? 4 : 3))*m_pixmm));
            if (i > 0 && i%10==0)
                paint.drawText(QRectF(i*m_pixmm + 0.5-19, 6*m_pixmm, 40, 20),
                               QString::number(i/10), m_to);
        }
        paint.drawText(QRectF(0, 6*m_pixmm, 40, 20), "0cm");

        for (int i = 0; i < m_width; i+=5)
        {
            paint.drawLine(QPointF(i, m_pixmm * 100),
                           QPointF(i, (30 -(i%100==0 ? 5 : (i%50==0 ? 4 : 3)))*m_pixmm));

            if (i > 0 && i%100==0)
                paint.drawText(QRectF(i-19, 21*m_pixmm, 40, 20),
                               QString::number(i), m_to);
        }
        paint.drawText(QRectF(0, 21*m_pixmm, 40, 20), "0pix");
    }
    else
    {
        m_to.setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        for (int i = 0; i < m_height; i++)
        {
            paint.drawLine(QPointF(0, i*m_pixmm + 0.5),
                           QPointF((i%10==0 ? 5 : (i%5==0 ? 4 : 3))*m_pixmm,
                                   i*m_pixmm + 0.5));
            if (i > 0 && i%10==0)
                paint.drawText(QRectF(6*m_pixmm, i*m_pixmm + 0.5-9, 40, 20),
                               QString::number(i/10), m_to);
        }
        paint.drawText(QRectF(6*m_pixmm, 0, 40, 20), "0cm");

        m_to.setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        for (int i = 0; i < m_height; i+=5)
        {
            paint.drawLine(QPointF(m_pixmm * 100, i),
                           QPointF((30 -(i%100==0 ? 5 : (i%50==0 ? 4 : 3)))*m_pixmm, i));

            if (i > 0 && i%100==0)
                paint.drawText(QRectF(15*m_pixmm, i-9, 9*m_pixmm, 20),
                               QString::number(i), m_to);
        }

        paint.drawText(QRectF(15*m_pixmm,
                              0, 9*m_pixmm, 20), "0pix", m_to);
    }

    QPainter painter(this);
    painter.drawPixmap(0,0,bmp);
}

void CRuler::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
        m_pos = e->pos();
}

void CRuler::mouseMoveEvent(QMouseEvent *e)
{
    if (m_pos.isNull())
        return;
    if ((e->pos()-m_pos).manhattanLength() > 0)
        emit moved(e->pos()-m_pos);
}

void CRuler::mouseReleaseEvent(QMouseEvent *e)
{
    Q_UNUSED(e);

    m_pos = QPoint();
}

#include "moc_cruler.cpp"
