#include "Include/Views/QmlScreen.h"

#include <QDebug>
#include <QDeclarativeEngine>
#include <QDeclarativeContext>

#include "Include/Views/QmlList.h"

////////////////////////////////////////////////////////////////////////////////////
//ctor
CQmlScreen::CQmlScreen(QDeclarativeEngine *engine)
    : QWidget()
    , m_engine(engine)
    , m_component(engine, QUrl(":Qml.qml"))
{
    m_context = new QDeclarativeContext(m_engine->rootContext());
    m_object = m_component.create(m_context);

    m_pContentList = IContentListPtr( new CQmlList(m_context) );
}


////////////////////////////////////////////////////////////////////////////////////
//dtor
CQmlScreen::~CQmlScreen()
{
    qDebug() << "~CQmlScreen() called";

    delete m_context;
}

////////////////////////////////////////////////////////////////////////////////////
IContentListPtr CQmlScreen::GetContentList() const
{
    Q_ASSERT( m_pContentList.data() );
    return m_pContentList;
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
void CQmlScreen::show()
{
    //QWidget::show();
}
