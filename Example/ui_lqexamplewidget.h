/********************************************************************************
** Form generated from reading UI file 'lqexamplewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LQEXAMPLEWIDGET_H
#define UI_LQEXAMPLEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LQExampleWidget
{
public:
    QGroupBox *groupBox;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *LQExampleWidget)
    {
        if (LQExampleWidget->objectName().isEmpty())
            LQExampleWidget->setObjectName(QStringLiteral("LQExampleWidget"));
        LQExampleWidget->resize(577, 301);
        groupBox = new QGroupBox(LQExampleWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 531, 191));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(13, 18, 101, 31));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(120, 20, 101, 31));

        retranslateUi(LQExampleWidget);

        QMetaObject::connectSlotsByName(LQExampleWidget);
    } // setupUi

    void retranslateUi(QWidget *LQExampleWidget)
    {
        LQExampleWidget->setWindowTitle(QApplication::translate("LQExampleWidget", "Form", 0));
        groupBox->setTitle(QApplication::translate("LQExampleWidget", "\346\265\213\350\257\225", 0));
        pushButton->setText(QApplication::translate("LQExampleWidget", "\346\261\275\350\275\246\344\273\252\350\241\250\346\235\2771", 0));
        pushButton_2->setText(QApplication::translate("LQExampleWidget", "\346\261\275\350\275\246\344\273\252\350\241\250\346\235\2772", 0));
    } // retranslateUi

};

namespace Ui {
    class LQExampleWidget: public Ui_LQExampleWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LQEXAMPLEWIDGET_H
