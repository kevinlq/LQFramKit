#include "demo_rightdownmessagebox.h"
#include "ui_demo_rightdownmessagebox.h"

#include "messageWidget/messagewidget.h"

Demo_RightDownMessageBox::Demo_RightDownMessageBox(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_RightDownMessageBox)
{
    ui->setupUi(this);

    setWindowTitle (title);

    m_pMessageBox = new MessageWidget;
}

Demo_RightDownMessageBox::~Demo_RightDownMessageBox()
{
    delete ui;

    m_pMessageBox->deleteLater ();
    m_pMessageBox = Q_NULLPTR;
}

void Demo_RightDownMessageBox::on_pushButton_clicked()
{
    QString title,content;

    if( (!ui->lineEdit->text ().isEmpty ()) &&
            (!ui->lineEdit_2->text ().isEmpty ()))
    {
        title = ui->lineEdit->text ();
        content = ui->lineEdit_2->text ();
    }
    m_pMessageBox->showMsg (":/image/RightMessageBox/title.png",title,content);
}
