#include "Include/Controllers/ContentListController.h"

//QT headers
#include <QDebug>
#include <QProcess>

////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentListController::CContentListController(const IContentListPtr &pContentList)
    :QObject()
    ,m_pContentList(pContentList)
{
    //Q_ASSERT( m_pContentList.data() );
    m_pContentList->SetOnDblClick( this );
}

////////////////////////////////////////////////////////////////////////////////////
void CContentListController::SetContentModel(CContentModelPtr pContentModel)
{
    Q_ASSERT( pContentModel.data() );

    m_pContentModel = pContentModel;

    QObject::connect(m_pContentModel.data(), SIGNAL( OnChanged() ), SLOT( OnModelChanged() ));
    OnModelChanged();
}

////////////////////////////////////////////////////////////////////////////////////
void CContentListController::OnModelChanged()
{
    //Q_ASSERT( m_pContentList.data() );

    m_pContentList->SetContentListModel( m_pContentModel );
}

////////////////////////////////////////////////////////////////////////////////////
void CContentListController::onDoubleClicked(int index)
{
    qDebug() << "item doubleclicked";

    QString program = QString::fromUtf8("C:/Program Files/VideoLAN/VLC/vlc.exe");
    //QString program = QString::fromUtf8("/Встроенная память/Program Files/CorePlayer/player.exe");
    QStringList arguments;
    arguments << QString::fromLocal8Bit(m_pContentModel->getRef(index).toUtf8());

    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
}
