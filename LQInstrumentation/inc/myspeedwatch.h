#ifndef MYSPEEDWATCH_H
#define MYSPEEDWATCH_H

#include <QWidget>

class LQINSTRUMENTATIONSHARED_EXPORT mySpeedWatch: public QWidget
{
    Q_OBJECT

public:     
    explicit mySpeedWatch(QWidget *parent = 0);
    ~mySpeedWatch();

    double value() const {return m_value;}
    int minValue() const {return m_minValue;}
    int maxValue() const {return m_maxValue;}
    int precision() const {return m_precision;}
    QString units()const {return m_units;}
    QString title() const {return m_title;}
    int scaleMajor() const {return m_scaleMajor;}
    int scaleMinor() const {return m_scaleMinor;}
    int startAngle() const {return m_startAngle;}
    int endAngle() const { return m_endAngle;}
    QColor crownColor() const {return m_crownColor;}
    QColor foreground() const {return m_foreground;}
    QColor background() const {return m_background;}
    bool isNumericIndicatorEnabled() const {return m_numericIndicatorEnabled;}

public Q_SLOTS:
    void setValue(double);
    void setValue (int);
    void setMinValue(int);
    void setMaxValue(int);
    void setPrecision(int);
    void setUnits(const QString &);
    void setTitle(const QString &);
    void setScaleMajor(int);
    void setScaleMinor(int);
    void setStartAngle(int);
    void setEndAngle(int);
    void setCrownColor(QColor);
    void setForeground(QColor);
    void setBackground(QColor);
    void setNumericIndicatorEnabled(bool);

protected:
    void thresholdManager();
    void paintEvent(QPaintEvent *);

    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawScaleNum(QPainter *painter);
    void drawTitle(QPainter *painter);
    void drawIndicator(QPainter *painter);
    void drawNumericValue(QPainter *painter);

private:
    double m_value;
    int m_maxValue, m_minValue;
    int m_precision;
    QString m_units;
    QString m_title;
    int m_scaleMajor;
    int m_scaleMinor;
    int m_startAngle,m_endAngle;

    QColor m_crownColor;
    QColor m_foreground;
    QColor m_background;

    bool m_numericIndicatorEnabled;
};

#endif //MYSPEEDWATCH_H
