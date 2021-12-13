#include "StdMain.h"
#include "CustomeTableView.h"

#include <QTableView>
#include <QHeaderView>
#include <QEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QHBoxLayout>

#define CHECK_BOX_COLUMN 0
#define File_PATH_COLUMN 1


TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void TableModel::updateData(const QList<FileRecord> &recordList)
{
    m_recordList = recordList;

    beginResetModel();
    endResetModel();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_recordList.count();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;

    int nColumn = index.column();
    FileRecord record = m_recordList.at(index.row());
    switch (role)
    {
    case Qt::DisplayRole:
    {
        if (nColumn == File_PATH_COLUMN)
        {
            record.strFilePath = value.toString();

            m_recordList.replace(index.row(), record);
            emit dataChanged(index, index);
            return true;
        }
    }
    case Qt::CheckStateRole:
    case Qt::UserRole:
    {
        if (nColumn == CHECK_BOX_COLUMN)
        {
            record.bChecked = value.toBool();

            m_recordList.replace(index.row(), record);
            emit dataChanged(index, index);
            return true;
        }
    }
    default:
        return false;
    }
    return false;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int nRow = index.row();
    int nColumn = index.column();
    FileRecord record = m_recordList.at(nRow);

    switch (role)
    {
    case Qt::TextColorRole:
        return QColor(Qt::blue);
    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    case Qt::DisplayRole:
    {
        if (nColumn == File_PATH_COLUMN)
            return record.strFilePath;
        return "";
    }
    case Qt::UserRole:
    {
        if (nColumn == CHECK_BOX_COLUMN)
            return record.bChecked;
    }
    default:
        return QVariant();
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role)
    {
    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    case Qt::DisplayRole:
    {
        if (orientation == Qt::Horizontal)
        {
            if (section == CHECK_BOX_COLUMN)
                return QStringLiteral("状态");

            if (section == File_PATH_COLUMN)
                return QStringLiteral("文件路径");
        }
    }
    default:
        return QVariant();
    }

    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return QAbstractItemModel::flags(index);

    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;

    return flags;
}

CheckBoxDelegate::CheckBoxDelegate(QObject *parent)
    : QStyledItemDelegate(parent)
{

}

CheckBoxDelegate::~CheckBoxDelegate()
{

}

void CheckBoxDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyleOptionViewItem viewOption(option);
    initStyleOption(&viewOption, index);
    if (option.state.testFlag(QStyle::State_HasFocus))
        viewOption.state = viewOption.state ^ QStyle::State_HasFocus;

    QStyledItemDelegate::paint(painter, viewOption, index);

    if (index.column() == CHECK_BOX_COLUMN)
    {
        bool data = index.model()->data(index, Qt::UserRole).toBool();

        QStyleOptionButton checkBoxStyle;
        checkBoxStyle.state = data ? QStyle::State_On : QStyle::State_Off;
        checkBoxStyle.state |= QStyle::State_Enabled;
        checkBoxStyle.iconSize = QSize(20, 20);
        checkBoxStyle.rect = option.rect;

        QCheckBox checkBox;
        QApplication::style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &checkBoxStyle, painter, &checkBox);
    }
}

bool CheckBoxDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    QRect decorationRect = option.rect;

    QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
    if (event->type() == QEvent::MouseButtonPress && decorationRect.contains(mouseEvent->pos()))
    {
        if (index.column() == CHECK_BOX_COLUMN)
        {
            bool data = model->data(index, Qt::UserRole).toBool();
            model->setData(index, !data, Qt::UserRole);
        }
    }

    return QStyledItemDelegate::editorEvent(event, model, option, index);
}


CustomeTableView::CustomeTableView(QWidget *parent) : QDialog(parent)
{
    QTableView *pTableView = new QTableView(this);
    TableModel *pModel = new TableModel(this);
    CheckBoxDelegate *pDelegate = new CheckBoxDelegate(this);

    // 设置单行选中、最后一列拉伸、表头不高亮、无边框等
    pTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    pTableView->horizontalHeader()->setStretchLastSection(true);
    pTableView->horizontalHeader()->setHighlightSections(false);
    pTableView->verticalHeader()->setVisible(false);
    pTableView->setShowGrid(false);
    pTableView->setFrameShape(QFrame::NoFrame);
    pTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    pTableView->setModel(pModel);
    pTableView->setItemDelegate(pDelegate);

    // 加载数据、更新界面
    QList<FileRecord> recordList;
    for (int i = 0; i < 5; ++i)
    {
        FileRecord record;
        record.bChecked = false;
        record.strFilePath = QString("C:/Qt/Qt6.2.0/6.2.0/%1").arg(i + 1);
        recordList.append(record);
    }

    pModel->updateData(recordList);

    QVBoxLayout *pLayout = new QVBoxLayout;
    pLayout->addWidget(pTableView);

    setLayout(pLayout);
}

CustomeTableView::~CustomeTableView()
{
}



#include "moc_CustomeTableView.cpp"
