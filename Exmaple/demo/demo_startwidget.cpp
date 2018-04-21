#include "LQFormWidgetIncLib.h"

#include "demo_startwidget.h"
#include "ui_demo_startwidget.h"


Demo_StartWidget::Demo_StartWidget(const QString &title,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_StartWidget)
{
    ui->setupUi(this);

    setWindowTitle (title);

    m_pStartWidget = new LQStartWidget;

    m_pStartWidget->setLoadText ("程序正在加载插件");
    m_pStartWidget->setLoadTime (6);
    m_pStartWidget->setStartShow ();

    connect (m_pStartWidget,SIGNAL(signalLoadFinish()),
             this,SIGNAL(signalShow()));

}

Demo_StartWidget::~Demo_StartWidget()
{
    delete ui;
    if (m_pStartWidget != Q_NULLPTR){
        m_pStartWidget->deleteLater ();
        m_pStartWidget = Q_NULLPTR;
    }
}
