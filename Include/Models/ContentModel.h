#ifndef CONTENTMODEL_H
#define CONTENTMODEL_H

//Qt headers
#include <QObject>
#include <QSharedPointer>
#include <QAbstractListModel>
#include <QVariant>

#include "Include/DataTypes.h"

class CContentModel : public QAbstractListModel
{
Q_OBJECT
public:
    CContentModel();
    ~CContentModel(){};

    //Methods
    LeafConstPtr GetCurrentLeaf() const;
    LeafPtr GetCurrentLeaf();

    //Implemention of QAbstractItemModel abstract class
    //{
    virtual int rowCount(const QModelIndex  &parent = QModelIndex()) const;
    virtual QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const;
    //}

    QString getTitle(int idx);
    QString getRef(int idx);

signals:
    void OnChanged();    

public slots:


private:
    Leaf m_list;
};

typedef QSharedPointer <CContentModel> CContentModelPtr;
typedef QSharedPointer <const CContentModel> CContentModelConstPtr;

#endif // CONTENTMODEL_H
