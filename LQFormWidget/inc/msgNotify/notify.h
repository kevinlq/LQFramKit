#ifndef NOTIFY_H
#define NOTIFY_H

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>

class Notify : public QWidget
{
    Q_OBJECT
public:
    explicit Notify(int displayTime, QWidget *parent = 0);

    void setIcon(const QString &value);

    void setTitle(const QString &value);

    void setBody(const QString &value);

    void setUrl(const QString &value);

    void showGriant();

Q_SIGNALS:
    void disappeared();

private:

    int displayTime;

    QString icon;
    QString title;
    QString body;
    QString url;

    QLabel *backgroundLabel;
    QLabel *iconLabel;
    QLabel *titleLabel;
    QLabel *bodyLabel;

    QPushButton *closeBtn;

    void hideGriant();

    void mousePressEvent(QMouseEvent *event);
};

#endif // NOTIFY_H
