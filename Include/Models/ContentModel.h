#ifndef CONTENTMODEL_H
#define CONTENTMODEL_H

//Qt headers
#include <QObject>
#include <QSharedPointer>
#include <QAbstractListModel>
#include <QVariant>

#include "Include/DataTypes.h"

//XXX:test
#include "Include/Loader/DataLoader.h"
#include "Include/Loader/NetworkTransport.h"
#include "Include/Loader/XmlParser.h"


class CContentModel : public QAbstractListModel
{
Q_OBJECT
public:
    //ctor
    CContentModel();
    //dtor
    ~CContentModel(){};

    //Methods
    LeafConstPtr GetCurrentLeaf() const;
    LeafPtr GetCurrentLeaf();

    //Implemention of QAbstractItemModel abstract class
    //{
    virtual int rowCount(const QModelIndex  &parent = QModelIndex()) const;
    virtual QVariant data (const QModelIndex &index, int role = Qt::DisplayRole) const;
    //}

    QString getTitle(int idx) const;
    QString getRef(int idx) const;

signals:
    void OnChanged();    

public slots:
    void Refresh();

private:
    //Methods
    void LoadData();

    //Variables
    Leaf m_list;
    CDataLoader<CNetworkTransport, CXmlParser> m_loader;
};

typedef QSharedPointer <CContentModel> CContentModelPtr;
typedef QSharedPointer <const CContentModel> CContentModelConstPtr;

#endif // CONTENTMODEL_H
