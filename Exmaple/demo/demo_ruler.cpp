#include "LQToolsIncLib.h"

#include "demo_ruler.h"

#include "ui_demo_ruler.h"

#include <QAction>
#include <QKeyEvent>

Demo_Ruler::Demo_Ruler(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_Ruler), m_title(title)
{
    ui->setupUi(this);

    init ();
}

Demo_Ruler::~Demo_Ruler()
{
    delete ui;
}

void Demo_Ruler::init()
{
    setWindowTitle (m_title);
    setWindowOpacity (1);
    setWindowFlags (Qt::FramelessWindowHint);
    setAttribute (Qt::WA_TranslucentBackground);

    ui->widget->setOrientation(Qt::Horizontal);

    m_pActionOrn = new QAction(this);
    m_pActionOrn->setText (QString ("垂直"));
    connect (m_pActionOrn,SIGNAL(triggered(bool)),SLOT(slotOnOrn()));

    m_pActionAlign = new QAction(this);
    m_pActionAlign->setText (QString ("对齐"));
    connect (m_pActionAlign,SIGNAL(toggled(bool)),this,SLOT(slotOnAlign()));

    addAction (m_pActionOrn);
    addAction (m_pActionAlign);
    this->setContextMenuPolicy (Qt::ActionsContextMenu);

    resize (ui->widget->sizeHint ());

    connect (ui->widget,SIGNAL(moved(QPoint)),
             this,SLOT(slotOnMove(QPoint)));
}

void Demo_Ruler::slotOnMove(const QPoint &p)
{
    this->move (this->pos () + p);
}

void Demo_Ruler::slotOnOrn()
{
    if ( QString("垂直") == m_pActionOrn->text ())
    {
        ui->widget->setOrientation (Qt::Vertical);
        m_pActionOrn->setText (QString ("水平"));
    }else{
        ui->widget->setOrientation (Qt::Horizontal);
        m_pActionOrn->setText (QString ("垂直"));
    }

    resize (ui->widget->sizeHint ());

    update ();
}

void Demo_Ruler::slotOnAlign()
{
    m_pActionOrn->text () == QString("垂直") ? move (0,pos().y ()):
                                             move(pos().x (),0);
}

void Demo_Ruler::keyReleaseEvent(QKeyEvent *e)
{
    QPoint p = pos();
    if (e->key() == Qt::Key_Left) p += QPoint(-1,0);
    else if (e->key() == Qt::Key_Right) p += QPoint(1,0);
    else if (e->key() == Qt::Key_Up) p += QPoint(0,-1);
    else if (e->key() == Qt::Key_Down) p += QPoint(0,1);
    move(p);
}
