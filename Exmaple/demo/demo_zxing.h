#ifndef DEMO_ZXING_H
#define DEMO_ZXING_H

#include <QDialog>

#define QRBUFSIZ 20480

typedef bool (*fpGetQrStr)(const char*, char*, int);

namespace Ui {
class Demo_Zxing;
}

class Demo_Zxing : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_Zxing(const QString &title = "",
                        QWidget *parent = 0);
    ~Demo_Zxing();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Demo_Zxing *ui;

    QString m_fileName;
    fpGetQrStr GetQrStr;
};

#endif // DEMO_ZXING_H
