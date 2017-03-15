#include "lqcustomgroupbox.h"

#define STYLE"\
QGroupBox{\
border: 2px solid gray; \
    border-radius: 3px; }\
QGroupBox::title {\
    background-color: transparent;\
    subcontrol-position: top left; \
padding:2 13px;\
}\
"


LQCustomGroupBox::LQCustomGroupBox(QWidget *parent)
    :QGroupBox(parent)
{
}

LQCustomGroupBox::~LQCustomGroupBox()
{
}

void LQCustomGroupBox::init()
{
    setStyleSheet (STYLE);
}
