#include "hierarchy.h"

HierarchyObject::HierarchyObject(const QList<QVariant> &data, HierarchyObject *parent)
    : m_itemData(data), m_parentItem(parent)
{}

HierarchyObject::~HierarchyObject()
{
    qDeleteAll(m_childItems);
}

void HierarchyObject::appendChild(HierarchyObject *item)
{
    m_childItems.append(item);
}

HierarchyObject *HierarchyObject::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.at(row);
}

int HierarchyObject::childCount() const
{
    return m_childItems.count();
}

int HierarchyObject::row() const
{
    if (m_parentItem)
        return m_parentItem->m_childItems.indexOf(const_cast<HierarchyObject*>(this));

    return 0;
}

int HierarchyObject::columnCount() const
{
    return m_itemData.count();
}

QVariant HierarchyObject::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
        return QVariant();
    return m_itemData.at(column);
}

HierarchyObject *HierarchyObject::parentItem()
{
    return m_parentItem;
}

// HieararchModel

HierarchyModel::HierarchyModel(const QString &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new HierarchyObject({tr("GameObject")});

    //setupModelData(data.split('\n'), rootItem);
}

HierarchyModel::~HierarchyModel()
{
    delete rootItem;
}

QModelIndex HierarchyModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    HierarchyObject *childItem = static_cast<HierarchyObject*>(index.internalPointer());
    HierarchyObject *parentItem = childItem->parentItem();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int HierarchyModel::rowCount(const QModelIndex &parent) const
{
    HierarchyObject *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<HierarchyObject*>(parent.internalPointer());

    return parentItem->childCount();
}

int HierarchyModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<HierarchyObject*>(parent.internalPointer())->columnCount();
    return rootItem->columnCount();
}

QVariant HierarchyModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    HierarchyObject *item = static_cast<HierarchyObject*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags HierarchyModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}

QVariant HierarchyModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex HierarchyModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    HierarchyObject *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<HierarchyObject*>(parent.internalPointer());

    HierarchyObject *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}


// Hieararchy

Hierarchy::Hierarchy(QWidget *parent) : QWidget{parent}
{
    dock = new QDockWidget(tr("Hierarchy"), parent);
    dock->setAllowedAreas(Qt::AllDockWidgetAreas);

    model = new HierarchyModel("test", this);

    treeView = new QTreeView(this);
    treeView->setModel(model);

    dock->setWidget(treeView);
}

QDockWidget* Hierarchy::Dock() const
{
    return dock;
}
