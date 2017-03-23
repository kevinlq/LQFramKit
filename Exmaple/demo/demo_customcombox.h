#ifndef DEMO_CUSTOMCOMBOX_H
#define DEMO_CUSTOMCOMBOX_H

#include <QDialog>

namespace Ui {
class Demo_CustomComBox;
}

class Demo_CustomComBox : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_CustomComBox(const QString &title,
                               QWidget *parent = 0);
    ~Demo_CustomComBox();

private:
    Ui::Demo_CustomComBox *ui;
};

#endif // DEMO_CUSTOMCOMBOX_H
