#include "LQFormWidgetIncLib.h"

#include "demo_messagebox.h"
#include "ui_demo_messagebox.h"



Demo_MessageBox::Demo_MessageBox(const QString &title,
                                 QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_MessageBox)
{
    ui->setupUi(this);

    setWindowTitle (title);

    m_pMsgBox = new MsgBoxBase;
}

Demo_MessageBox::~Demo_MessageBox()
{
    delete ui;
}

void Demo_MessageBox::on_pushButton_clicked()
{
    m_pMsgBox->showMessageError ("这是一个错误消息框");
}

void Demo_MessageBox::on_pushButton_2_clicked()
{
    int ret = m_pMsgBox->showMessageQuestion ("您是否要?");
    if (ret)
        m_pMsgBox->showMessageInfo ("你选择了要");
    else
        m_pMsgBox->showMessageInfo ("您选择了不要!");
}

void Demo_MessageBox::on_pushButton_3_clicked()
{
    m_pMsgBox->showMessageInfo ("你今天的运气很好，适合出门!");
}
