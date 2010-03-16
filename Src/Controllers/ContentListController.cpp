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
void CContentListController::OnDblClick(const QModelIndex &index)
{
    qDebug() << "item doubleclicked";

    //QString program = "C:/Program Files/VideoLAN/VLC/vlc.exe";
    QString program = "/Встроенная память/Program Files/CorePlayer/player.exe";
    QStringList arguments;
    arguments << m_pContentModel->getRef(index.row());

    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
}
