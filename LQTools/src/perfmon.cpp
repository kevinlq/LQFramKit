/****************************************************************************
**
** Year    		: 2017-03-22
** Author  		: KevinLi
** E-Mail  		: kevinlq0912@163.com
** QQ      		: 2313828706
** Version 		: V1.0
** Description	: 本控件来自与网络，本人收藏而来。具体出处不详
**                该控件实现了一个简单的性能监控器，模仿windows系统的性能监控器
** If you have any questions , please contact me
**
****************************************************************************/
#include "lqtools_global.h"

#include "perfmon.h"

#include <QMenu>
#include <QTimer>
#include <QColorDialog>
#include <QContextMenuEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QFileDialog>

PerfMon::PerfMon(QWidget *parent) :
    QWidget(parent)
{
    initVariables();
    initContextMenu();
    initMessages();
}

PerfMon::~PerfMon()
{
}

void PerfMon::initVariables()
{
    m_bUseGradient = false;
    m_bUseContextMenu = true;
    m_bgClr = Qt::black;
    m_frameClr = Qt::green;
    m_nIncrement = 5;
    m_nChannelCount = 0;
    m_bUseText = false;

    updateTimer = new QTimer(this);
    updateTimer->setInterval(3000);
    updateTimer->start();

}
void PerfMon::initMessages()
{
    if(m_bUseContextMenu)
    {
        connect(contextMenu,SIGNAL(aboutToShow()),this,SLOT(LoadChannelMenu()));
    }
    connect(updateTimer,SIGNAL(timeout()),this,SLOT(UpdateSettings()));
}

void PerfMon::initContextMenu()
{
    if(!m_bUseContextMenu)
    {
        return ;
    }
    contextMenu = new QMenu(tr("Context Menu"),this);

    saveGraphAct = new QAction(tr("export Graph"),this);
    frameClrAct = new QAction(tr("frame color"),this);
    bgClrAct = new QAction(tr("background color"),this);

    channelColoringMenu = new QMenu(tr("channel coloring"),this);

    contextMenu->addAction(saveGraphAct);
    contextMenu->addAction(frameClrAct);
    contextMenu->addAction(bgClrAct);
    contextMenu->addMenu(channelColoringMenu);

    connect(saveGraphAct,SIGNAL(triggered()),this,SLOT(ActHandler()));
    connect(frameClrAct,SIGNAL(triggered()),this,SLOT(ActHandler()));
    connect(bgClrAct,SIGNAL(triggered()),this,SLOT(ActHandler()));

}

void PerfMon::ActHandler()
{

    QAction* who = qobject_cast<QAction*>(sender());

    if(who == saveGraphAct)
    {
        this->saveGraph();
        return ;

    }

    if(who == frameClrAct)
    {
        QColor clr = QColorDialog::getColor();

        if(clr.isValid())
        {
            this->setFrameColor(clr);
        }
        return ;

    }


    if(who == bgClrAct)
    {

        QColor clr = QColorDialog::getColor();
        if(clr.isValid())
        {
            this->setBackgroundColor(clr);
        }
    }

}

void PerfMon::ColoringHandler()
{
    QAction *who = qobject_cast<QAction*>(sender());
    int index = who->property("ID").toInt();

    QColor clr = QColorDialog::getColor();

    if(clr.isValid())
    {
        QPixmap pixmap(32,32);
        pixmap.fill(clr);
        who->setIcon(pixmap);
        this->setChannelColor(index,clr);
    }
}

void PerfMon::UpdateSettings()
{
        int dataCount = width()/m_nIncrement+100;
        for(int i = 0;i < m_nChannelCount;i++)
        {
            if(m_dataVec[i].count()>dataCount)
            {
                m_dataVec[i].remove(dataCount,m_dataVec[i].count()-dataCount);
            }
        }

}
void PerfMon::contextMenuEvent(QContextMenuEvent *e)
{
    if(!m_bUseContextMenu)
    {
        return ;
    }
    contextMenu->exec(e->globalPos());
    e->accept();
}

void PerfMon::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter painter(this);

    drawBackground(&painter);
    drawFrame(&painter);
    drawGraph(&painter);

    painter.end();

}

void PerfMon::drawBackground(QPainter *painter)
{
    painter->save();
    if(this->m_bUseGradient)
    {
        drawLinearBackground(painter);
    }else{
        drawSolidBackground(painter);
    }
    painter->restore();
}

void PerfMon::drawSolidBackground(QPainter *painter)
{
    painter->save();

    QBrush bgBrush(m_bgClr);
    painter->setBrush(bgBrush);
    painter->drawRect(this->rect());
    painter->restore();
}

void PerfMon::drawLinearBackground(QPainter *painter)
{
    painter->save();
    painter->setBrush(m_bgGradient);
    painter->drawRect(this->rect());
    painter->restore();
}

void PerfMon::drawFrame(QPainter *painter)
{
    painter->save();
    QPen framePen(m_frameClr);
    framePen.setStyle(Qt::DotLine);
    painter->setPen(framePen);
    painter->drawRect(rect());

    qreal yIncrement=(qreal)height()/10;
    qreal xIncrement=(qreal)width()/10;
    qreal startX=0;
    qreal startY=0;

    for(int i=0;i<10;i++)
    {

        // draw horizontal lines
        QPointF leftPot(0,startY);
        QPointF rightPot(width(),startY);
        startY+=yIncrement;
        painter->drawLine(leftPot,rightPot);

        // draw vertical lines
        QPointF topPot(startX,0);
        QPointF bottomPot(startX,height());
        startX+=xIncrement;
        painter->drawLine(topPot,bottomPot);
    }

    painter->restore();
}

void PerfMon::drawGraph(QPainter *painter)
{
    painter->save();


    for(int i = 0;i<m_nChannelCount;i++)
    {
        // check to see if there's a need to draw specified data channel
        if(!m_visibleVec.at(i))
        {
            continue ;
        }

        // customize specified channel's graph color

        painter->setPen(QPen(m_clrVec.at(i)));

        QVector<qreal> dataVec = m_dataVec[i];


        QVector<QPointF> potVec;
        qreal startX = width();
        for(int j = 0;j < dataVec.count();j++)
        {
               qreal yValue = dataVec.at(j);
               qreal y = yValue*((qreal)height()/100);
               QPointF pot(startX,height()-y);

               //
               if(j<(dataVec.count()-1))
               {
                   qreal yNextValue=dataVec.at(j+1);
                   qreal yNext=yNextValue*((qreal)height()/100);
                   QPointF nextPot(startX-m_nIncrement,height()-yNext);
                   potVec.push_back(nextPot);
               }

               //

               startX-=m_nIncrement;

               //
               potVec.push_back(pot);
        }
        painter->drawLines(potVec);
    }

    painter->restore();
}

void PerfMon::setChannelCount(int nCount)
{
    m_nChannelCount=nCount;
    m_clrVec.resize(nCount);
    for(int i=0;i<nCount;i++)
    {
        m_visibleVec.push_back(true);
    }

    update();
}

void PerfMon::setChannelColor(int nIndex, const QColor &clr)
{
    if(nIndex>=m_nChannelCount)
    {
        return ;
    }
    m_clrVec[nIndex]=clr;
    update();

}

QColor PerfMon::getChannelColor(int nIndex)
{
    if(nIndex>=0&&nIndex<m_nChannelCount)
    {
       return m_clrVec.at(nIndex);
    }
    return m_clrVec.at(0);
}

void PerfMon::addChannelData(int nIndex,qreal data)
{

     m_dataVec[nIndex].push_front(data);
     update();
}

void PerfMon::setBackgroundColor(const QLinearGradient &bgGradient)
{
    m_bUseGradient=true;
    m_bgGradient=bgGradient;
    update();
}
void PerfMon::setBackgroundColor(const QColor &clr)
{
    m_bUseGradient=false;
    m_bgClr=clr;
    update();
}

void PerfMon::setFrameColor(const QColor &clr)
{
    m_frameClr=clr;
    update();
}

void PerfMon::setShowGrid(bool bShow)
{
    m_bShowGrid=bShow;
    update();
}

QString PerfMon::saveGraph()
{
    QString strPicPath=QFileDialog::getSaveFileName(this,tr("Export Image"),".");

    if(strPicPath.isEmpty())
    {
        return QString();
    }
    QFileInfo fInfo(strPicPath);
    if(fInfo.suffix().toLower()!="png")
    {
        strPicPath+=".png";
    }

    QPixmap pixmap=QPixmap::grabWidget(this,this->rect());
    pixmap.save(strPicPath,"PNG");

    return strPicPath;

}

void PerfMon::setXIncrement(int nIncrement)
{
    m_nIncrement=nIncrement;
    update();
}

void PerfMon::setChannelVisible(int nIndex,bool bShow)
{
    m_visibleVec[nIndex]=bShow;
    update();
}

void PerfMon::setChannelText(int nIndex, const QString &strText)
{
    if(!m_bUseText)
    {
      m_bUseText=true;
      m_textVec.resize(m_nChannelCount);
  }
    m_textVec[nIndex]=strText;
    update();
}

void PerfMon::setChannelText(const QStringList &strList)
{
    if(!m_bUseText)
    {
      m_bUseText=true;
      m_textVec.resize(m_nChannelCount);
  }
    for(int i=0;i<m_nChannelCount;i++)
    {
        m_textVec[i]=strList.at(i);
    }
    update();

}

void PerfMon::setUseContextMenu(bool use)
{
    m_bUseContextMenu=use;
    update();
}

void PerfMon::LoadChannelMenu()
{

    this->channelColoringMenu->clear();
    for(int i=0;i<m_nChannelCount;i++)
    {
        QPixmap actPixmap(32,32);
        actPixmap.fill(m_clrVec.at(i));

        //
        QString strText;

        if(!m_bUseText)
        {
            strText=tr("Channel %1").arg(i+1);
        }else{
            strText=m_textVec.at(i);
        }
        QAction* channelAct=new QAction(QIcon(actPixmap),strText,this);
        channelColoringMenu->addAction(channelAct);
        channelAct->setProperty("ID",QVariant(i));
        connect(channelAct,SIGNAL(triggered()),this,SLOT(ColoringHandler()));
    }

}

#include "moc_perfmon.cpp"
