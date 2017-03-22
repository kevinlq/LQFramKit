#ifndef DEMO_PERFMON_H
#define DEMO_PERFMON_H

#include <QDialog>

class QTimer;
class PerfMon;

namespace Ui {
class Demo_PerfMon;
}

class Demo_PerfMon : public QDialog
{
    Q_OBJECT

public:
    explicit Demo_PerfMon(const QString &title,QWidget *parent = 0);
    ~Demo_PerfMon();

private:
    void init();

private Q_SLOTS:
    void slotUpdateData();

private:
    Ui::Demo_PerfMon *ui;

    QTimer  *m_pUpdateTimer;

    PerfMon *m_pPerfMon;
};

#endif // DEMO_PERFMON_H
