#include "Include/Models/ContentModel.h"


////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentModel::CContentModel()
    : QAbstractListModel()
{
    ContentItemPtr pItem = ContentItemPtr(new ContentItem("empty", ""));
    m_list.push_back(pItem);

    emit OnChanged();
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

    return ( role == Qt::DisplayRole )
            ? m_list[index.row()]->m_title
            : QVariant();
}
