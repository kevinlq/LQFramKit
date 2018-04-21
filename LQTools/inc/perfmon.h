#ifndef PERFMON_H
#define PERFMON_H

#include <QWidget>

class QMenu;
class QTimer;

#define MAX_CHANNEL 255


class LQTOOLSSHARED_EXPORT PerfMon : public QWidget
{
    Q_OBJECT
public:
    explicit PerfMon(QWidget *parent = 0);
    ~PerfMon();

protected:
    void paintEvent(QPaintEvent *);
    void contextMenuEvent(QContextMenuEvent *);

    QSize sizeHint() const
    {
        return QSize(320,320);
    }

    QSize minimumSizeHint() const
    {
        return QSize(200,200);
    }

private: // painting related functions go here
     void drawFrame(QPainter* painter);
     void drawBackground(QPainter* painter);
     void drawGraph(QPainter* painter);
     void drawSolidBackground(QPainter* painter);
     void drawLinearBackground(QPainter* painter);

public Q_SLOTS:

    void setUseContextMenu(bool use);

    void setChannelCount(int nCount);

    void setChannelColor(int nIndex,const QColor& clr);

    QColor getChannelColor(int nIndex);

    void addChannelData(int nIndex,qreal data);

    void setBackgroundColor(const QLinearGradient& bgGradient);

    void setBackgroundColor(const QColor& bgBrush);

    void setFrameColor(const QColor& clr);

    void setShowGrid(bool bShow);

    QString saveGraph();

    void setXIncrement(int nIncrement);

    void setChannelVisible(int nIndex,bool bShow);

    void setChannelText(int nIndex,const QString& strText);

    void setChannelText(const QStringList& strList);


private: // private variables
    int                     m_nChannelCount;
    QVector<QColor>         m_clrVec;
    QVector<qreal>          m_dataVec[MAX_CHANNEL];
    int                     m_nIncrement;
    bool                    m_bShowGrid;
    bool                    m_bUseGradient;
    bool                    m_bUseContextMenu;
    QColor                  m_bgClr;
    QLinearGradient         m_bgGradient;
    QColor                  m_frameClr;
    QVector<bool>           m_visibleVec;
    QVector<QString>        m_textVec;
    bool                    m_bUseText;

private:
    QMenu* contextMenu;
    QAction* saveGraphAct;
    QAction* frameClrAct;
    QAction* bgClrAct;
    QMenu*   channelColoringMenu;
    QTimer* updateTimer;

private:
    void initVariables();
    void initMessages();
    void initContextMenu();


private Q_SLOTS:
    void ActHandler();
    void ColoringHandler();
    void LoadChannelMenu();
    void UpdateSettings();
};

#endif // PERFMON_H
