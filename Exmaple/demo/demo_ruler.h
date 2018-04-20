#ifndef DEMO_RULER_H
#define DEMO_RULER_H

#include <QDialog>

class QAction;

namespace Ui {
class Demo_Ruler;
}

class Demo_Ruler : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_Ruler(const QString &title = "",
                        QWidget *parent = 0);
    ~Demo_Ruler();

private:
    void init();

private Q_SLOTS:
    void slotOnMove(const QPoint &p);

    void slotOnOrn();

    void slotOnAlign();

protected:
    void keyReleaseEvent (QKeyEvent *e);

private:
    Ui::Demo_Ruler *ui;
    QString m_title;

    QAction *m_pActionOrn;
    QAction *m_pActionAlign;
};

#endif // DEMO_RULER_H
