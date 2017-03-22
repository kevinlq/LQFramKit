#include "examplewidget.h"
#include "ui_examplewidget.h"

#include <QTimer>

#include "qmeter.h"

ExampleWidget::ExampleWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExampleWidget)
{
    ui->setupUi(this);

    init();
}

ExampleWidget::~ExampleWidget()
{
    delete ui;
}

void ExampleWidget::slotTestSearchLineEdit(const QString &text)
{
    ui->textEdit->append("搜索的内容为:"+text+"\n");
}

void ExampleWidget::init()
{
    this->setFocusPolicy(Qt::ClickFocus);

    initConnect ();
}

void ExampleWidget::initConnect()
{
    connect (ui->horizontalSlider,SIGNAL(sliderMoved(int)),
             ui->Meter_widget,SLOT(setValue(int)));
    connect (ui->horizontalSlider,SIGNAL(sliderMoved(int)),
             ui->qgauge_widget,SLOT(setValue(int)));

    connect(ui->lineEdit,&SearchLineEdit::signalSearchContent,
            this,&ExampleWidget::slotTestSearchLineEdit);
}

