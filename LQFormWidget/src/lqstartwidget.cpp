/****************************************************************************
**
** Year    		: 2017-04-04
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	: 超炫动画启动效果
**                来源：CSDN liujunpen/  本人加以修改
** If you have any questions , please contact me
**
****************************************************************************/
#include "StdMain.h"
#include "lqstartwidget.h"

#include <QGridLayout>
#include <QLabel>
#include <QTimer>
#include <QPainter>
#include <QImage>

#include <QMouseEvent>
#include <QDebug>

LQStartWidget::LQStartWidget(QWidget *parent) : QWidget(parent)
{
    initWidget ();

    init ();
}

LQStartWidget::~LQStartWidget()
{
    if (m_pLoadTime != Q_NULLPTR){
        m_pLoadTime->deleteLater ();
        m_pLoadTime = Q_NULLPTR;
    }
    if (m_pCountTime != Q_NULLPTR){
        m_pCountTime->deleteLater ();
        m_pCountTime = Q_NULLPTR;
    }
}

void LQStartWidget::setLoadText(const QString &title)
{
    if (! title.isEmpty ())
        m_pLabelLoadText->setText (title);
}

void LQStartWidget::setLoadTime(int count)
{
    if (m_count != count)
        m_count = count;
    m_pLabelNum->setText (QString::number (m_count));
}

void LQStartWidget::setStartShow()
{
    m_pCountTime->start ();
    m_pLoadTime->start ();

    this->show ();
}

void LQStartWidget::init()
{
    //设置窗体标题栏隐藏并设置位于顶层
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint  | Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    m_w = this->width ();
    m_h = this->height ();

    m_pLoadTime = new QTimer(this);
    connect (m_pLoadTime,SIGNAL(timeout()),
             this,SLOT(slotLoading()));
    m_pLoadTime->setInterval (6);

    m_pCountTime = new QTimer(this);
    connect (m_pCountTime,SIGNAL(timeout()),
             this,SLOT(slotCountShow()));
    m_pCountTime->setInterval (1111);

    m_dig = 0;
    m_count = 6;
    m_pLabelNum->setText (QString::number (m_count));
}

void LQStartWidget::initWidget()
{
    m_pGridLayout = new QGridLayout(this);
    m_pGridLayout->setSpacing (0);
    m_pGridLayout->setContentsMargins (11,11,11,11);

    m_pLabelNum = new QLabel(this);
    QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(m_pLabelNum->sizePolicy().hasHeightForWidth());
    m_pLabelNum->setSizePolicy (sizePolicy);
    m_pLabelNum->setAlignment (Qt::AlignCenter);
    m_pLabelNum->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                 "font: 75 50pt \"\346\245\267\344\275\223\";\n"
                                                 "background-color: rgb(55, 55, 55);"));

    m_pLabelLoadText = new QLabel(this);
    m_pLabelLoadText->setText (QString("程序加载中"));
    m_pLabelLoadText->setMinimumSize (0,40);
    m_pLabelLoadText->setMaximumHeight (40);
    m_pLabelLoadText->setAlignment (Qt::AlignHCenter|Qt::AlignTop);
    m_pLabelLoadText->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
                                                      "font: 75 14pt \"\346\245\267\344\275\223\";\n"
                                                      "background-color: rgb(55, 55, 55);"));

    m_pGridLayout->setContentsMargins (70,70,70,70);
    m_pGridLayout->addWidget (m_pLabelNum,1,0,1,1);
    m_pGridLayout->addWidget (m_pLabelLoadText,2,0,1,1);
    setLayout (m_pGridLayout);

    setStyleSheet ("QLabel{color:rgb(255,255,255);font:75 50pt \"楷体\";background-color:rgb(55,55,55)}");

    resize (300,300);
}

void LQStartWidget::mousePressEvent(QMouseEvent *event)
{
    m_pWindowPos = this->pos ();
    m_pMousePos = event->globalPos ();
    m_pDPos = m_pMousePos - m_pWindowPos;
}

void LQStartWidget::mouseMoveEvent(QMouseEvent *event)
{
    this->move (event->globalPos () - m_pDPos);
}

void LQStartWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    //开启反锯齿
    painter.setRenderHint (QPainter::Antialiasing,true);

    QPixmap pixmap;
    pixmap.load (":/image/intiloading.png");
    painter.translate (m_w/2,m_h/2);
    painter.rotate (m_dig);
    painter.translate (-m_w/2,-m_h/2);
    painter.drawPixmap (0,0,m_w,m_h,pixmap);

    m_dig++;
    if (m_dig >= 360){
        m_dig = 0;
    }
}

void LQStartWidget::slotLoading()
{
    update ();
}

void LQStartWidget::slotCountShow()
{
    m_count--;
    m_pLabelNum->setText (QString::number (m_count));
    if (m_count <= 0){
        emit signalLoadFinish ();
        if (m_pLoadTime->isActive ())
            m_pLoadTime->stop ();
        if (m_pCountTime->isActive ())
            m_pCountTime->stop ();
        this->close ();
    }
}

#include "moc_lqstartwidget.cpp"
