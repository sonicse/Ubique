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

    //QString program = QString::fromUtf8("D:/тест/vlc.exe");
    QString program = QString::fromUtf8("/Встроенная память/Program Files/CorePlayer/player.exe");
    QStringList arguments;
    arguments << QString::fromLocal8Bit(m_pContentModel->getRef(index.row()).toUtf8());

    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
}
