#include "Include/Controllers/ContentScreenController.h"

#include "Include/Models/ContentModel.h"
#include "Include/Controllers/ContentListController.h"
#include "Include/Views/IContentScreen.h"

////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentScreenController::CContentScreenController(IContentScreenPtr pContentScreen)
    :QObject()
    ,m_pContentScreen(pContentScreen)
{
    m_pContentListController = CContentListControllerPtr(new CContentListController( m_pContentScreen->GetContentList() ));

    m_pContentScreen->SetOnBack( this );
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreenController::SetContentModel(CContentModelPtr pContentModel)
{
    m_pContentModel = pContentModel;

    if( m_pContentListController ){
        m_pContentListController->SetContentModel( pContentModel );
    }
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreenController::OnBack()
{
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreenController::OnRefresh()
{
}
