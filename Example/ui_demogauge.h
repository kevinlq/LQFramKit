/********************************************************************************
** Form generated from reading UI file 'demogauge.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOGAUGE_H
#define UI_DEMOGAUGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qgauge.h"

QT_BEGIN_NAMESPACE

class Ui_DemoGauge
{
public:
    QVBoxLayout *verticalLayout;
    QGauge *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DemoGauge)
    {
        if (DemoGauge->objectName().isEmpty())
            DemoGauge->setObjectName(QStringLiteral("DemoGauge"));
        DemoGauge->resize(357, 352);
        DemoGauge->setStyleSheet(QStringLiteral("background-color: rgb(56, 56, 56);"));
        verticalLayout = new QVBoxLayout(DemoGauge);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QGauge(DemoGauge);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(300, 300));
        QFont font;
        font.setPointSize(7);
        widget->setFont(font);

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSlider = new QSlider(DemoGauge);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimumSize(QSize(0, 20));
        horizontalSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"    border: 1px solid #999999;\n"
"    height: 20px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"	background: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(60, 162, 160, 255), stop:0.531579 rgba(0, 58, 185, 255), stop:0.973684 rgba(54, 129, 160, 255));\n"
"    border: 1px solid #5c5c5c;\n"
"    width: 18px;\n"
"    margin: -2px 0; /* handle is placed by default on the contents rect of the groove. Expand outside the groove */\n"
"    border-radius: 3px;\n"
"}"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DemoGauge);

        QMetaObject::connectSlotsByName(DemoGauge);
    } // setupUi

    void retranslateUi(QDialog *DemoGauge)
    {
        DemoGauge->setWindowTitle(QApplication::translate("DemoGauge", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DemoGauge: public Ui_DemoGauge {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOGAUGE_H
