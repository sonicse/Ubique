#include "Include/Models/ContentModel.h"


////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentModel::CContentModel()
    : QAbstractListModel()
{
    QHash<int, QByteArray> roleNames;
    roleNames.insert(1023, "title");
    roleNames.insert(1024, "ref");
    setRoleNames(roleNames);

    ContentItemPtr pItem = ContentItemPtr(new ContentItem("empty", ""));
    m_list.push_back(pItem);

    LoadData();
}

////////////////////////////////////////////////////////////////////////////////////
LeafConstPtr CContentModel::GetCurrentLeaf() const
{
    return &m_list;
}

////////////////////////////////////////////////////////////////////////////////////
LeafPtr CContentModel::GetCurrentLeaf()
{
    return &m_list;
}

////////////////////////////////////////////////////////////////////////////////////
int CContentModel::rowCount( const QModelIndex  &parent ) const
{
    return m_list.size();
}

////////////////////////////////////////////////////////////////////////////////////
QVariant CContentModel::data( const QModelIndex &index, int role) const
{
    if( !index.isValid() )
    {
        return QVariant();
    }

    switch(role)
    {
    case(1023): //Title
        {
            return getTitle( index.row() );
        }

    case(1024): //Ref
        {
            return getRef( index.row() );
        }
    }

    return QVariant();
}

////////////////////////////////////////////////////////////////////////////////////
QString CContentModel::getTitle(int idx) const
{
    return m_list[idx]->m_title;
}

////////////////////////////////////////////////////////////////////////////////////
QString CContentModel::getRef(int idx) const
{
    return m_list[idx]->m_href;
}

void CContentModel::LoadData()
{
    m_loader.GetContentData( GetCurrentLeaf() );

    emit OnChanged();
};

void CContentModel::Refresh()
{
    LoadData();
};
