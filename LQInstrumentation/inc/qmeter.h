/*
 *   Copyright (C) 2016 by P. Sereno
 *   http://www.qt-italia.net
 */

#ifndef QMETER_H
#define QMETER_H

 
#include <Qt>
#include <QWidget>
#include <QPropertyAnimation>

class QColor;


class LQINSTRUMENTATIONSHARED_EXPORT QMeter : public QWidget
{
 Q_OBJECT
	Q_ENUMS(errorCode);
	Q_PROPERTY(double value READ value WRITE setValue);
	Q_PROPERTY(double minValue READ minValue WRITE setMinValue);
	Q_PROPERTY(double maxValue READ maxValue WRITE setMaxValue);
	Q_PROPERTY(double threshold READ threshold WRITE setThreshold);
	Q_PROPERTY(int precision READ precision WRITE setPrecision);
    Q_PROPERTY(int precisionNumeric READ precisionNumeric WRITE setPrecisionNumeric);
	Q_PROPERTY(QString units READ units WRITE setUnits);
    Q_PROPERTY(QString label READ label WRITE setLabel);
    Q_PROPERTY(int steps READ steps WRITE setSteps);
	Q_PROPERTY(double startAngle READ startAngle WRITE setStartAngle);
	Q_PROPERTY(double endAngle READ endAngle WRITE setEndAngle);	
	Q_PROPERTY(QColor foreground READ foreground WRITE setForeground);
	Q_PROPERTY(QColor background READ background WRITE setBackground);
	Q_PROPERTY(bool enableThreshold READ enableThreshold WRITE setThresholdEnabled);
    Q_PROPERTY(double beginValidValue READ beginValidValue WRITE setBeginValidValue);
    Q_PROPERTY(double endValidValue READ endValidValue WRITE setEndValidValue);
    Q_PROPERTY(bool enableValidWindow READ enableValidWindow WRITE setEnableValidWindow);
    Q_PROPERTY(double beginWarningValue READ beginWarningValue WRITE setBeginWarningValue);
    Q_PROPERTY(double endWarningValue READ endWarningValue WRITE setEndWarningValue);
    Q_PROPERTY(bool enableWarningWindow READ enableWarningWindow WRITE setEnableWarningWindow);
	Q_PROPERTY(bool enableNumericIndicator READ enableNumericIndicator WRITE setNumericIndicatorEnabled);
	
public: 

    enum ErrorCode {MaxValueError=1,MinValueError,ThresholdError,TargetError,PrecisionError,ColorError,UnitsEmpty,OutOfRange};
    QMeter(QWidget *parent = 0);
    ~QMeter();
    double value() const { return m_value; }
    double minValue() const { return m_minValue; }
    double maxValue() const { return m_maxValue; }
    double threshold() const { return m_threshold; }
    double beginValidValue() const { return m_beginValidValue; }
    double endValidValue() const { return m_endValidValue; }
    double beginWarningValue() const { return m_beginWarningValue; }
    double endWarningValue() const { return m_endWarningValue; }
    int precision() const { return m_precision; }
    int precisionNumeric() const { return m_precisionNumeric; }
    QString units()const { return m_units; }
    QString label()const { return m_label; }
    int steps() const { return m_steps; }
    double startAngle() const { return m_startAngle; }
    double endAngle() const { return m_endAngle; }
    QColor foreground() const { return m_foreground; }
    QColor background() const { return m_background; }
    bool enableThreshold() const { return m_thresholdEnabled; }
    bool enableValidWindow() const { return m_enableValidWindow; }
    bool enableWarningWindow() const { return m_enableWarningWindow; }
    bool enableNumericIndicator() const { return m_numericIndicatorEnabled; }

signals:

    void errorSignal(int);	            
    void thresholdAlarm(bool);

public slots:

	void setValue(double);
	void setValue(int);	
	void setMinValue(double);
	void setMinValue(int);	
	void setMaxValue(double);	
	void setMaxValue(int);		
	void setThreshold(double);
	void setThreshold(int);		
    void setPrecision(int);
    void setPrecisionNumeric(int);  	
	void setUnits(QString);
    void setLabel(QString);
	void setSteps(int);	
	void setStartAngle(double);	
	void setEndAngle(double);	
	void setForeground(QColor);
	void setBackground(QColor);
    void setThresholdEnabled(bool);
    void setNumericIndicatorEnabled(bool);
    void setValueWithSpringEffect(int value);
    void setBeginValidValue(double);
    void setEndValidValue(double);
    void setEnableValidWindow(bool);
    void setBeginWarningValue(double);
    void setEndWarningValue(double);
    void setEnableWarningWindow(bool);

protected:

    double m_value;
    double m_maxValue, m_minValue;
    int m_precision;
    int m_precisionNumeric;
    void thresholdManager();

    void paintEvent(QPaintEvent *event);        
    void drawCrown(QPainter *painter);
    void drawBackground(QPainter *painter);
    void drawTicks(QPainter *painter);
    void drawScale(QPainter *painter);
    void drawUnits(QPainter *painter);
    void drawNeedle(QPainter *painter);
    void drawThresholdLine(QPainter *painter);
    void drawNumericValue(QPainter *painter);
    void drawCoverGlass(QPainter *painter);
    void drawLabel(QPainter *painter);
    void drawValidWindow(QPainter *painter);
    void drawWarningWindow(QPainter *painter);
    
	QString m_units;
    QString m_label;
	int m_steps;
	double m_startAngle,m_endAngle;
	double m_threshold;
    bool m_thresholdFlag;
    bool m_enableValidWindow;
    double m_beginValidValue, m_endValidValue;    
    bool m_enableWarningWindow;
    double m_beginWarningValue, m_endWarningValue;
	bool m_thresholdEnabled;
	bool m_numericIndicatorEnabled;
	QColor m_foreground;
	QColor m_background;
    QPropertyAnimation m_valAnimation;
};

#endif
