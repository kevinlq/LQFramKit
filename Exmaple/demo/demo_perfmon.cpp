#include "../LQTools/inc/LQToolsIncLib.h"

#include "demo_perfmon.h"
#include "ui_demo_perfmon.h"

#include <QTimer>


#define CHANNEL_COUNT 2

Demo_PerfMon::Demo_PerfMon(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_PerfMon)
{
    ui->setupUi(this);

    this->init ();

    this->setWindowTitle (title);
}

Demo_PerfMon::~Demo_PerfMon()
{
    delete ui;
}

void Demo_PerfMon::init()
{
    m_pUpdateTimer = new QTimer(this);
    m_pUpdateTimer->setInterval (200);

    m_pPerfMon = new PerfMon(this);

    ui->verticalLayout->addWidget (m_pPerfMon);

    connect (m_pUpdateTimer,SIGNAL(timeout()),
             this,SLOT(slotUpdateData()));
    m_pUpdateTimer->start ();

    m_pPerfMon->setChannelCount (CHANNEL_COUNT);
    m_pPerfMon->setChannelColor (0,Qt::red);
    m_pPerfMon->setChannelColor (1,Qt::green);
}

void Demo_PerfMon::slotUpdateData()
{
    for(int cIndex = 0;cIndex < CHANNEL_COUNT;cIndex++)
    {
        m_pPerfMon->addChannelData(cIndex,qrand()%100);
    }
}
