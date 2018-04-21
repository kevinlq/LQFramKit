#include "QZXing/inc/QZxingIncLib.h"

#include "demo_zxing.h"
#include "ui_demo_zxing.h"

#include <QFileDialog>

Demo_Zxing::Demo_Zxing(const QString &title, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_Zxing)
{
    ui->setupUi(this);

    if(!title.isEmpty ())
        setWindowTitle (title);
}

Demo_Zxing::~Demo_Zxing()
{
    delete ui;
}

void Demo_Zxing::on_pushButton_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this,
                                              tr("二维码打开文件"),
                                              "./",
                                              tr("任何文件(*.*)"
                                                 ";;文本文件(*.png)")
                                              );
    if(m_fileName.isEmpty() == false)
    {
        ui->lineEdit->setText(m_fileName);
        QImage img;        //加载图像
        if(!(img.load(m_fileName)))
        {
            return;
        }
        img = img.scaled(ui->label->width(),ui->label->height(),Qt::KeepAspectRatio);
        ui->label->setPixmap(QPixmap::fromImage(img));

        QZXing decoder(QZXing::DecoderFormat_None);
        QString qrmsg = decoder.decodeImage(img);
        ui->textEdit->setText(tr(">> %1").arg(qrmsg));
    }
}
