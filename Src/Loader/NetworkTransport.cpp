#include "Include/Loader/NetworkTransport.h"

//Qt headers
//#include <QNetworkAccessManager>
//#include <QNetworkReply>
#include <QDebug>

////////////////////////////////////////////////////////////////////////////////////
//ctor
CNetworkTransport::CNetworkTransport()
    :m_pManager(new QNetworkAccessManager)
{
    connect(m_pManager.data(), SIGNAL(finished(QNetworkReply*)),
            SLOT(replyFinished(QNetworkReply*)));
}

////////////////////////////////////////////////////////////////////////////////////
//ctor
CNetworkTransport::~CNetworkTransport()
{
    qDebug() << "destroy object: " << objectName();
}

////////////////////////////////////////////////////////////////////////////////////
int CNetworkTransport::Read(QString &data)
{
    m_pManager->get( QNetworkRequest(QUrl("http://work.sonicse.operaunite.com/media_player_11/playlist/asx/") ));

    loop.exec();

    data = m_answer;

    return err ? 1 : 0;
}

////////////////////////////////////////////////////////////////////////////////////
void CNetworkTransport::replyFinished(QNetworkReply *reply)
{
    qDebug() << "request finished" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if( reply->error() )
    {
        qDebug() << "error: " << reply->errorString();
    }

    //Redirect behavior
    QUrl redirection = reply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
    if (redirection.isValid())
    {
        QUrl newUrl = reply->url().resolved(redirection);
        m_pManager->get(QNetworkRequest(newUrl));
    }
    else
    {
        //Response
        m_answer = QString::fromUtf8(reply->readAll());

        //XXX: sync
        err = reply->error();
        loop.exit();
    }

    reply->deleteLater();
}
