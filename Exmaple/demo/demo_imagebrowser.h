#ifndef DEMO_IMAGEBROWSER_H
#define DEMO_IMAGEBROWSER_H

#include <QDialog>

namespace Ui {
class Demo_ImageBrowser;
}

class Demo_ImageBrowser : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_ImageBrowser(const QString &title,
                               QWidget *parent = 0);
    ~Demo_ImageBrowser();

    void setPixmap(const QPixmap &pixmap);

protected:
    virtual void resizeEvent(QResizeEvent *event);

private Q_SLOTS:
    void openButtonClicked();

    void originalSizeButtonClicked(bool checked);

    void zoomInButtonClicked();

    void zoomOutButtonClicked();

    void clockwise90ButtonClicked();

    void anticlockwise90ButtonClicked();

    void slotPercentageChanged(double percentage);

private:
    Ui::Demo_ImageBrowser *ui;

    QPixmap m_pixmap;
};

#endif // DEMO_IMAGEBROWSER_H
