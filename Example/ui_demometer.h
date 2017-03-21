/********************************************************************************
** Form generated from reading UI file 'demometer.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEMOMETER_H
#define UI_DEMOMETER_H

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
#include "qmeter.h"

QT_BEGIN_NAMESPACE

class Ui_DemoMeter
{
public:
    QVBoxLayout *verticalLayout;
    QMeter *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *DemoMeter)
    {
        if (DemoMeter->objectName().isEmpty())
            DemoMeter->setObjectName(QStringLiteral("DemoMeter"));
        DemoMeter->resize(318, 346);
        DemoMeter->setStyleSheet(QStringLiteral("background-color: rgb(56, 56, 56);"));
        verticalLayout = new QVBoxLayout(DemoMeter);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget = new QMeter(DemoMeter);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(300, 300));

        verticalLayout->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalSlider = new QSlider(DemoMeter);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout->addWidget(horizontalSlider);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DemoMeter);

        QMetaObject::connectSlotsByName(DemoMeter);
    } // setupUi

    void retranslateUi(QDialog *DemoMeter)
    {
        DemoMeter->setWindowTitle(QApplication::translate("DemoMeter", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class DemoMeter: public Ui_DemoMeter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEMOMETER_H
