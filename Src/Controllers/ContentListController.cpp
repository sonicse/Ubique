#include "Include/Controllers/ContentListController.h"

//QT headers
#include <QDebug>

////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentListController::CContentListController(const IContentListPtr &pContentList)
    :QObject()
    ,m_pContentList(pContentList)
{
    m_pContentList->SetOnDblClick( this );
}

////////////////////////////////////////////////////////////////////////////////////
void CContentListController::SetContentModel(CContentModelPtr pContentModel)
{
    m_pContentModel = pContentModel;

    QObject::connect(m_pContentModel.data(), SIGNAL( OnChanged() ), SLOT( OnModelChanged() ));
    OnModelChanged();
}

////////////////////////////////////////////////////////////////////////////////////
void CContentListController::OnModelChanged()
{
    m_pContentList->SetContentListModel( m_pContentModel );
}

////////////////////////////////////////////////////////////////////////////////////
void CContentListController::OnDblClick()
{
    qDebug() << "item doubleclicked";
}
