#include "Include/Views/QmlList.h"

#include <QDeclarativeContext>

////////////////////////////////////////////////////////////////////////////////////
//ctor
CQmlList::CQmlList(QDeclarativeContext *context)
    :QObject()
    ,m_context( context )
{
}

////////////////////////////////////////////////////////////////////////////////////
//dtor
CQmlList::~CQmlList()
{
    qDebug() << "~CQmlList() called";
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlList::SetContentListModel(const CContentModelPtr &pContentModel)
{
    m_pContentModel = pContentModel;

    if( m_context )
    {
        //m_pListView->setModel( m_pContentModel.data() );

        m_context->setContextProperty("contentModel",  (QObject*)m_pContentModel.data() );
    }
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlList::SetOnDblClick(QObject *pObj)
{
    //QObject::connect(m_pListView, SIGNAL(doubleClicked ( const QModelIndex & )), pObj, SLOT(OnDblClick(const QModelIndex &)) );
}
