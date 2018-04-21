#include "StdMain.h"
#include "gradientcombobox.h"

#include <QListWidget>
#include <QLabel>
#include <QPainter>
#include <QHBoxLayout>
#include <QDebug>
#include <QStylePainter>

/*渐变颜色数据结构*/
struct GradientData
{
    GradientData(const QString& name, const QColor& clr1, const QColor& clr2)
    {
        this->name = name;
        this->color1 = clr1;
        this->color2 = clr2;
    }
    GradientData(const GradientData& other)
    {
        this->name = other.name;
        this->color1 = other.color1;
        this->color2 = other.color2;
    }
    QString name;
    QColor color1;
    QColor color2;
};

typedef QList<GradientData> GradientDataList;

class GradientLabel : public QLabel
{
public:
    explicit GradientLabel(QWidget* parent = Q_NULLPTR);
    void setColors(const QColor& clr1, const QColor& clr2);

    QColor color1() const { return m_color1; }
    QColor color2() const { return m_color2; }

protected:
    void paintEvent(QPaintEvent *);

private:
    QColor m_color1;
    QColor m_color2;
};
GradientLabel::GradientLabel(QWidget *parent)
    : QLabel(parent)
{
}

void GradientLabel::setColors(const QColor &clr1, const QColor &clr2)
{
    m_color1 = clr1;
    m_color2 = clr2;
    update();
}

void GradientLabel::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    QLinearGradient lg(rect().topLeft(), rect().topRight());
    lg.setColorAt(0.0, m_color1);
    lg.setColorAt(1.0, m_color2);
    painter.setBrush(QBrush(lg));
    painter.drawRect(rect());
    QLabel::paintEvent(event);
}


class GradientWidgetItem : public QWidget
{
public:
    GradientWidgetItem(const GradientData& gradient,
                       QWidget* parent = Q_NULLPTR);

    QString name() const { return m_gradientData.name; }
    QColor color1() const { return m_gradientData.color1; }
    QColor color2() const { return m_gradientData.color2; }

private:
    GradientData m_gradientData;
};

GradientWidgetItem::GradientWidgetItem(const GradientData &gradient,
                                       QWidget* parent)
    : QWidget(parent)
    , m_gradientData(gradient)
{
    QHBoxLayout* layout = new QHBoxLayout;

    // the label's text will overlap with qlistwidgetitem's text, so comment it out
    QLabel* nameLabel = new QLabel(/*gradient.name, */this);
    nameLabel->setMinimumWidth(120);
    nameLabel->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum));
    GradientLabel* gLabel = new GradientLabel(this);
    gLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    gLabel->setColors(gradient.color1, gradient.color2);
    layout->addWidget(nameLabel);
    layout->addWidget(gLabel);
    layout->setSpacing(1);
    layout->setContentsMargins(2, 2, 2, 2);
    setLayout(layout);
}

class GradientComboBoxPrivate
{
public:
    GradientComboBoxPrivate(GradientComboBox* q);

    GradientComboBox* q_ptr;
    static GradientDataList sGradientList;
    QListWidget* gradientItemList;

    QMap<QListWidgetItem*, GradientWidgetItem*> listItem2GradientItemMap;
};

GradientDataList GradientComboBoxPrivate::sGradientList =
        GradientDataList()<< GradientData(QObject::tr("Fifty shades of grey"), QColor(189,195,199), QColor(44,62,80))
                          << GradientData(QObject::tr("Dusk"), QColor(255,216,155), QColor(25,84,123))
                          << GradientData(QObject::tr("Miami Dolphins"), QColor(77,160,176), QColor(211,157,56))
                          << GradientData(QObject::tr("Superman"), QColor(0,153,247), QColor(241,23,18))
                          << GradientData(QObject::tr("Timber"), QColor(252,0,255), QColor(0,219,222))
                          << GradientData(QObject::tr("Lizard"), QColor(48,67,82), QColor(215,210,204))
                          << GradientData(QObject::tr("Ukraine"), QColor(0,79,249), QColor(255,249,76))
                          << GradientData(QObject::tr("Starfall"), QColor(240,194,123), QColor(75,18,72))
                          << GradientData(QObject::tr("Kyoto"), QColor(194,21,0), QColor(255,197,0))
                          << GradientData(QObject::tr("Miaka"), QColor(252,53,76), QColor(10,191,188))
                          << GradientData(QObject::tr("Calm Darya"), QColor(95,44,130), QColor(73,160,157))
                          << GradientData(QObject::tr("Mantle"), QColor(36,198,220), QColor(81,74,157))
                          << GradientData(QObject::tr("Opa"), QColor(61,126,170), QColor(255,228,122))
                          << GradientData(QObject::tr("Horizon"), QColor(0,57,115), QColor(229,229,190))
                          << GradientData(QObject::tr("Rose Water"), QColor(229,93,135), QColor(95,195,228))
                          << GradientData(QObject::tr("Harmonic Energy"), QColor(22,160,133), QColor(244,208,63))
                          << GradientData(QObject::tr("Purple Paradise"), QColor(29,43,100), QColor(248,205,218))
                          << GradientData(QObject::tr("Aqua Marine"), QColor(26,41,128), QColor(38,208,206))
                          << GradientData(QObject::tr("Calm Darya"), QColor(95,44,130), QColor(73,160,157))
                          << GradientData(QObject::tr("Bora Bora"), QColor(43,192,228), QColor(234,236,198))
                          << GradientData(QObject::tr("Winter"), QColor(230,218,218), QColor(39,64,70))
                          << GradientData(QObject::tr("Bright Vault"), QColor(0,210,255), QColor(146,141,171))
                          << GradientData(QObject::tr("Sunset"), QColor(11,72,107), QColor(245,98,23))
                          << GradientData(QObject::tr("Sherbert"), QColor(247,157,0), QColor(100,243,140))
                          << GradientData(QObject::tr("Deep Sea Space"), QColor(44,62,80), QColor(76,161,175))
                          << GradientData(QObject::tr("Transfile"), QColor(22,191,253), QColor(203,48,102))
                          << GradientData(QObject::tr("Ali"), QColor(255,75,31), QColor(31,221,255))
                          << GradientData(QObject::tr("Alihossein"), QColor(247,255,0), QColor(219,54,164))
                          << GradientData(QObject::tr("Christmas"), QColor(47,115,54), QColor(170,58,56))
                          << GradientData(QObject::tr("Minnesota Vikings"), QColor(86,20,176), QColor(219,214,92))
                          << GradientData(QObject::tr("Pizelex"), QColor(17,67,87), QColor(242,148,146))
                          << GradientData(QObject::tr("Netflix"), QColor(142,14,0), QColor(31,28,24))
                          << GradientData(QObject::tr("Green and Blue"), QColor(194,229,156), QColor(100,179,244))
                          << GradientData(QObject::tr("Fresh Turboscent"), QColor(241,242,181), QColor(19,80,88))
                          << GradientData(QObject::tr("Purple Bliss"), QColor(54,0,51), QColor(11,135,147))
                          << GradientData(QObject::tr("Martini"), QColor(253,252,71), QColor(36,254,65))
                          << GradientData(QObject::tr("Shore"), QColor(112,225,245), QColor(255,209,148))
                          << GradientData(QObject::tr("Earthly"), QColor(100,145,115), QColor(219,213,164))
                          << GradientData(QObject::tr("Titanium"), QColor(40,48,72), QColor(133,147,152))
                          << GradientData(QObject::tr("Sun on the Horizon"), QColor(252,234,187), QColor(248,181,0))
                          << GradientData(QObject::tr("Grapefruit Sunset"), QColor(233,100,67), QColor(144,78,149))
                          << GradientData(QObject::tr("Politics"), QColor(33,150,243), QColor(244,67,54))
                          << GradientData(QObject::tr("Sweet Morning"), QColor(255,95,109), QColor(255,195,113))
                          << GradientData(QObject::tr("Forest"), QColor(90,63,55), QColor(44,119,68))
                          << GradientData(QObject::tr("Back to the Future"), QColor(192,36,37), QColor(240,203,53))
                          << GradientData(QObject::tr("Dark Knight"), QColor(186,139,2), QColor(24,24,24))
                          << GradientData(QObject::tr("Green to dark"), QColor(106,145,19), QColor(20,21,23))
                          << GradientData(QObject::tr("Virgin America"), QColor(123,67,151), QColor(220,36,48))
                          << GradientData(QObject::tr("Turquoise flow"), QColor(19,106,138), QColor(38,120,113))
                          << GradientData(QObject::tr("Portrait"), QColor(142,158,171), QColor(238,242,243))
                          << GradientData(QObject::tr("Flickr"), QColor(255,0,132), QColor(51,0,27))
                          << GradientData(QObject::tr("Predawn"), QColor(255,161,127), QColor(0,34,62))
                          << GradientData(QObject::tr("Crazy Orange I"), QColor(211,131,18), QColor(168,50,121))
                          << GradientData(QObject::tr("ServQuick"), QColor(72,85,99), QColor(41,50,60))
                          << GradientData(QObject::tr("Cheer Up Emo Kid"), QColor(85,98,112), QColor(255,107,107))
                          << GradientData(QObject::tr("Man of Steel"), QColor(120,2,6), QColor(6,17,97))
                          << GradientData(QObject::tr("Moor"), QColor(97,97,97), QColor(155,197,195))
                          << GradientData(QObject::tr("Forever Lost"), QColor(93,65,87), QColor(168,202,186))
                          << GradientData(QObject::tr("Dracula"), QColor(220,36,36), QColor(74,86,157))
                          << GradientData(QObject::tr("Moss"), QColor(19,78,94), QColor(113,178,128))
                          << GradientData(QObject::tr("Lemon Twist"), QColor(60,165,92), QColor(181,172,73))
                          << GradientData(QObject::tr("Frozen"), QColor(64,59,74), QColor(231,233,187))
                          << GradientData(QObject::tr("Emerald Water"), QColor(52,143,80), QColor(86,180,211))
                          << GradientData(QObject::tr("Mirage"), QColor(22,34,42), QColor(58,96,115))
                          << GradientData(QObject::tr("Shroom Haze"), QColor(92,37,141), QColor(67,137,162))
                          << GradientData(QObject::tr("Venice Blue"), QColor(8,80,120), QColor(133,216,206));

GradientComboBoxPrivate::GradientComboBoxPrivate(GradientComboBox* q) : q_ptr(q)
{
    gradientItemList = new QListWidget(q_ptr);
    gradientItemList->setAlternatingRowColors(true);
    q_ptr->connect(q_ptr, SIGNAL(activated(int)), q_ptr, SLOT(onActivated(int)));

    for (int i = 0; i < sGradientList.size(); ++i) {
        const GradientData& gd = sGradientList.at(i);
        QListWidgetItem* listItem = new QListWidgetItem;
        listItem->setText(gd.name);

        GradientWidgetItem* gwi = new GradientWidgetItem(gd, gradientItemList);
        gradientItemList->addItem(listItem);
        gradientItemList->setItemWidget(listItem, gwi);

        listItem2GradientItemMap.insert(listItem, gwi);
    }

    // setModel & setView call order matters
    q_ptr->setModel(gradientItemList->model());
    q_ptr->setView(gradientItemList);

    // set default row
    gradientItemList->setCurrentRow(0);
}

/*自定义combox类实现*/
GradientComboBox::GradientComboBox(QWidget* parent) : QComboBox(parent)
{
    d_ptr = new GradientComboBoxPrivate(this);
}

GradientComboBox::~GradientComboBox()
{
    delete d_ptr;
    d_ptr = Q_NULLPTR;
}

void GradientComboBox::setCurrentIndex(int index)
{
    d_ptr->gradientItemList->setCurrentRow(index);
    QListWidgetItem* currItem = d_ptr->gradientItemList->currentItem();
    GradientWidgetItem* gwi = d_ptr->listItem2GradientItemMap.value(currItem);
    if (gwi)
        setCurrentText(gwi->name());
}

int GradientComboBox::currentIndex() const
{
    return d_ptr->gradientItemList->currentRow();
}

QString GradientComboBox::currentName() const
{
    QListWidgetItem* currItem = d_ptr->gradientItemList->currentItem();
    if (!currItem)
        return QString();

    return d_ptr->listItem2GradientItemMap.value(currItem)->name();
}

QColor GradientComboBox::currentColor1() const
{
    QListWidgetItem* currItem = d_ptr->gradientItemList->currentItem();
    if (!currItem)
        return QColor();

    return d_ptr->listItem2GradientItemMap.value(currItem)->color1();
}

QColor GradientComboBox::currentColor2() const
{
    QListWidgetItem* currItem = d_ptr->gradientItemList->currentItem();
    if (!currItem)
        return QColor();

    return d_ptr->listItem2GradientItemMap.value(currItem)->color2();
}

QPair<QColor, QColor> GradientComboBox::colorPair(int index)
{
    if (0 <= index && index < GradientComboBoxPrivate::sGradientList.size())
        return qMakePair(GradientComboBoxPrivate::sGradientList.at(index).color1, GradientComboBoxPrivate::sGradientList.at(index).color2);
    else
        return qMakePair(QColor(), QColor());
}

void GradientComboBox::showPopup()
{
    QComboBox::showPopup();
    QRect qRect(view()->geometry());
    int xPos = qRect.width() - d_ptr->gradientItemList->width();
    int yPos = qRect.height() - d_ptr->gradientItemList->height();
    d_ptr->gradientItemList->move(xPos, yPos);
    d_ptr->gradientItemList->doItemsLayout();
    d_ptr->gradientItemList->setVisible(true);
}

void GradientComboBox::hidePopup()
{
    QComboBox::hidePopup();
    d_ptr->gradientItemList->setVisible(false);
    int currRow = d_ptr->gradientItemList->currentRow();
    emit currentIndexChanged(currRow);
}

void GradientComboBox::paintEvent(QPaintEvent *e)
{
    QListWidgetItem* item = d_ptr->gradientItemList->currentItem();
    if (!item) {
        QComboBox::paintEvent(e);
        return;
    }

    QStylePainter painter(this);
    painter.setPen(palette().color(QPalette::Text));

    // draw the combobox frame, focusrect and selected etc.
    QStyleOptionComboBox opt;
    initStyleOption(&opt);
    painter.drawComplexControl(QStyle::CC_ComboBox, opt);

    GradientWidgetItem* gwi = d_ptr->listItem2GradientItemMap.value(item);

    QRect gradientRect(QPoint(125, 2), QPoint(width() - 20, height() - 4));
    QLinearGradient lg(gradientRect.topLeft(), gradientRect.topRight());
    lg.setColorAt(0.0, gwi->color1());
    lg.setColorAt(1.0, gwi->color2());
    painter.setBrush(QBrush(lg));
    painter.drawRect(gradientRect);

    // draw the icon and text
    painter.drawControl(QStyle::CE_ComboBoxLabel, opt);
}

void GradientComboBox::resizeEvent(QResizeEvent* e)
{
    QComboBox::resizeEvent(e);

    QRect qRect(view()->geometry());
    int xPos = qRect.width() - d_ptr->gradientItemList->width();
    int yPos = qRect.height() - d_ptr->gradientItemList->height();
    d_ptr->gradientItemList->move(xPos, yPos);
}

QSize GradientComboBox::minimumSizeHint() const
{
    return QSize(240, 20);
}

void GradientComboBox::onActivated(int index)
{
    d_ptr->gradientItemList->setCurrentRow(index);
    update();
}

#include "moc_gradientcombobox.cpp"
