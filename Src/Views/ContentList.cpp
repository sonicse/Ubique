#include "Include/Views/ContentList.h"

//Qt headers
#include <QListView>
#include <QDebug>
#include <QListWidgetItem>

#include "Include/Models/ContentModel.h"

////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentList::CContentList(QListView *pListView)
    :QObject()
    ,m_pListView(pListView)
{
}

////////////////////////////////////////////////////////////////////////////////////
//dtor
CContentList::~CContentList()
{
    qDebug() << "~CContentList() called";
}

////////////////////////////////////////////////////////////////////////////////////
void CContentList::SetContentListModel(const CContentModelPtr &pContentModel)
{
    m_pContentModel = pContentModel;

    if( m_pListView )
    {
        m_pListView->setModel( m_pContentModel.data() );
    }
}

////////////////////////////////////////////////////////////////////////////////////
void CContentList::SetOnDblClick(QObject *pObj)
{
    QObject::connect(m_pListView, SIGNAL(doubleClicked ( const QModelIndex & )), pObj, SLOT(OnDblClick()) );
}
