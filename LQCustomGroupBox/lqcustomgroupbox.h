#ifndef LQCUSTOMGROUPBOX_H
#define LQCUSTOMGROUPBOX_H

#include "lqcustomgroupbox_global.h"
#include <QGroupBox>
#include <QWidget>

class LQCUSTOMGROUPBOXSHARED_EXPORT LQCustomGroupBox :public QGroupBox
{

public:
    LQCustomGroupBox(QWidget *parent = 0);
    ~LQCustomGroupBox();
};

#endif // LQCUSTOMGROUPBOX_H
