#ifndef GRADIENTCOMBOBOX_H
#define GRADIENTCOMBOBOX_H

#include <QComboBox>

class QListWidgetItem;
class GradientComboBoxPrivate;
class LQFORMWIDGETSHARED_EXPORT GradientComboBox : public QComboBox
{
    Q_OBJECT
public:
    explicit GradientComboBox(QWidget* parent = Q_NULLPTR);
    ~GradientComboBox();

    void setCurrentIndex(int index);
    int currentIndex() const;

    QString currentName() const;
    QColor currentColor1() const;
    QColor currentColor2() const;

    static QPair<QColor, QColor> colorPair(int index);

    void showPopup();
    void hidePopup();

protected:
    void paintEvent(QPaintEvent *e);
    void resizeEvent(QResizeEvent* e);
    QSize minimumSizeHint() const;

private slots:
    void onActivated(int index);

private:
    GradientComboBoxPrivate* d_ptr;
    Q_DISABLE_COPY(GradientComboBox)
};
#endif // GRADIENTCOMBOBOX_H
