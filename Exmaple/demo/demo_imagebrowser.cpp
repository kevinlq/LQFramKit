#include "../LQTools/inc/LQToolsIncLib.h"
#include "demo_imagebrowser.h"
#include "ui_demo_imagebrowser.h"

#include <QFileDialog>



Demo_ImageBrowser::Demo_ImageBrowser(const QString &title,
                                     QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Demo_ImageBrowser)
{
    ui->setupUi(this);

    this->setWindowTitle(title);

    connect(ui->openButton, SIGNAL(clicked(bool)),
            this, SLOT(openButtonClicked()));
    connect(ui->originalSizeButton, SIGNAL(clicked(bool)),
            this, SLOT(originalSizeButtonClicked(bool)));
    connect(ui->zoomInButton, SIGNAL(clicked(bool)),
            this, SLOT(zoomInButtonClicked()));
    connect(ui->zoomOutButton, SIGNAL(clicked(bool)),
            this, SLOT(zoomOutButtonClicked()));
    connect(ui->clockwise90Button, SIGNAL(clicked(bool)),
            this, SLOT(clockwise90ButtonClicked()));
    connect(ui->anticlockwiseButton, SIGNAL(clicked(bool)),
            this, SLOT(anticlockwise90ButtonClicked()));
    connect(ui->imageHandler, SIGNAL(percentageChanged(double)),
            this, SLOT(slotPercentageChanged(double)));
}

Demo_ImageBrowser::~Demo_ImageBrowser()
{
    delete ui;
}

void Demo_ImageBrowser::setPixmap(const QPixmap &pixmap)
{
    ui->imageHandler->setPixmap(pixmap);
}

void Demo_ImageBrowser::resizeEvent(QResizeEvent *event)
{
    originalSizeButtonClicked(false);
    ui->originalSizeButton->setChecked(false);
    QWidget::resizeEvent(event);
}

void Demo_ImageBrowser::openButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,\
                                                    tr("Open Image"), "../",\
                                                    tr("Image Files (*.png *.jpg *.bmp)"));
    if( !fileName.isEmpty() )
    {
        QPixmap pixmap(fileName);
        setPixmap(pixmap);
    }
}

void Demo_ImageBrowser::originalSizeButtonClicked(bool checked)
{
    if( checked )
    {
        ui->imageHandler->showOriginalSize();
        ui->originalSizeButton->setText(tr("suitable size"));
    }
    else
    {
        ui->imageHandler->showSuitableSize();
        ui->originalSizeButton->setText(tr("original size"));
    }
}

void Demo_ImageBrowser::zoomInButtonClicked()
{
    ui->imageHandler->zoomIn();
}

void Demo_ImageBrowser::zoomOutButtonClicked()
{
    ui->imageHandler->zoomOut();
}

void Demo_ImageBrowser::clockwise90ButtonClicked()
{
    ui->imageHandler->clockwise90();
}

void Demo_ImageBrowser::anticlockwise90ButtonClicked()
{
    ui->imageHandler->anticlockwise90();
}

void Demo_ImageBrowser::slotPercentageChanged(double percentage)
{
    int value = percentage*100;
    QString percentageStr = QString("%1%").arg(value);
    ui->percentageLabel->setText( percentageStr );
}

