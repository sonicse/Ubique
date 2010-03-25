#include "Include/Views/QmlScreen.h"

////////////////////////////////////////////////////////////////////////////////////
//ctor
CQmlScreen::CQmlScreen(QDeclarativeView *view)
    : QWidget()
    , m_view(view)
    , m_component(engine, QUrl("Qml/qml.qml"))
{
    m_object = m_component.create();
}


////////////////////////////////////////////////////////////////////////////////////
//dtor
CQmlScreen::~CQmlScreen()
{
    qDebug() << "~CQmlScreen() called";
}

////////////////////////////////////////////////////////////////////////////////////
IContentListPtr CQmlScreen::GetContentList() const
{
    //return m_pContentList;
    return IContentListPtr();
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlScreen::SetOnBack(QObject *pObj)
{
    //QObject::connect(ui->BackButton, SIGNAL(clicked()), pObj, SLOT(OnBack()));
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlScreen::SetOnRefresh(QObject *pObj)
{
    //QObject::connect(ui->RefreshButton, SIGNAL(clicked()), pObj, SLOT(OnRefresh()));
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreen::show()
{
    Q_ASSERT( m_view );

    n_view->show();
}
