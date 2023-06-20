#pragma once

#include <QObject>
#include <QWidget>
#include <QDockWidget>
#include <qabstractitemmodel.h>
#include <QTreeView>

class HierarchyObject
{
public:
    explicit HierarchyObject(const QList<QVariant> &data, HierarchyObject *parentItem = nullptr);

    ~HierarchyObject();

    void appendChild(HierarchyObject *child);

    HierarchyObject *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    HierarchyObject *parentItem();

private:
    QList<HierarchyObject *> m_childItems;
    QList<QVariant> m_itemData;
    HierarchyObject *m_parentItem;
};

class HierarchyModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit HierarchyModel(const QString &data, QObject *parent = nullptr);

    ~HierarchyModel();

    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

private:
    void setupModelData(const QStringList &lines, HierarchyObject *parent);

    HierarchyObject *rootItem;
};

class Hierarchy : public QWidget
{
    Q_OBJECT
public:
    explicit Hierarchy(QWidget *parent = nullptr);
    QDockWidget* Dock() const;
private:
    QDockWidget* dock;
    HierarchyModel* model;
    QTreeView* treeView;

signals:

};

