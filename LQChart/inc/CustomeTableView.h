#ifndef CUSTOMETABLEVIEW_H
#define CUSTOMETABLEVIEW_H

#include <QWidget>
#include <QDialog>
#include <QStyledItemDelegate>
#include <QAbstractTableModel>

typedef struct FileRecord
{
    bool bChecked = false;
    QString strFilePath = "";
} fileRecord;

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    TableModel(QObject *parent = Q_NULLPTR);

    void updateData(const QList<FileRecord> &recordList);

    virtual int rowCount(const QModelIndex &parent) const;
    virtual int columnCount(const QModelIndex &parent) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role);
    virtual QVariant data(const QModelIndex &index, int role) const;
    virtual QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<FileRecord> m_recordList;
};

class CheckBoxDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:
    CheckBoxDelegate(QObject * parent = Q_NULLPTR);
    ~CheckBoxDelegate();

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);
};

class LQCHARTSHARED_EXPORT CustomeTableView : public QDialog
{
    Q_OBJECT
public:
    explicit CustomeTableView(QWidget *parent = nullptr);
    ~CustomeTableView();

};

#endif // CUSTOMETABLEVIEW_H
