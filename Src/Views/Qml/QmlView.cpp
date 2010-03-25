#include "Include/Views/Qml/QmlView.h"

#include <QDebug>
#include <QAbstractListModel>

////////////////////////////////////////////////////////////////////////////////////
//ctor

CQmlView::CQmlView()
    : QObject()
    ,m_view(new QDeclarativeView)
{
    m_context = m_view->rootContext();
    m_context->setContextProperty("view", this );

    m_view->setSource(QUrl(":Qml/Qml.qml"));
}

////////////////////////////////////////////////////////////////////////////////////
//dtor
CQmlView::~CQmlView()
{
    qDebug() << "~CQmlView() called";
}

////////////////////////////////////////////////////////////////////////////////////
IContentScreenPtr CQmlView::GetContentScreen() const
{
    //return m_pContentList;
    return IContentScreenPtr(this);
}

////////////////////////////////////////////////////////////////////////////////////
IContentListPtr CQmlView::GetContentList() const
{
    //return m_pContentList;
    return IContentListPtr(this);
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlView::SetOnBack(QObject *pObj)
{
//    QObject::connect(ui->BackButton, SIGNAL(clicked()), pObj, SLOT(OnBack()));
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlView::SetOnRefresh(QObject *pObj)
{
//    QObject::connect(ui->RefreshButton, SIGNAL(clicked()), pObj, SLOT(OnRefresh()));
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlView::show()
{
    m_view->show();
//    QWidget::show();
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlView::SetContentListModel(const CContentModelPtr &pContentModel)
{
    Q_ASSERT( pContentModel );
    Q_ASSERT( m_context );

    m_pContentModel = pContentModel;
    m_context->setContextProperty("contentModel", static_cast<QAbstractListModel *>( pContentModel.data() ));
}

////////////////////////////////////////////////////////////////////////////////////
void CQmlView::SetOnDblClick(QObject *pObj)
{
    QObject::connect(this, SIGNAL(doubleClicked ( int )), pObj, SLOT(onDoubleClicked(int)) );
}

void CQmlView::onRefresh()
{
    emit refreshModel();
}

void CQmlView::onDoubleClicked(int index)
{
    emit doubleClicked(index);
}
