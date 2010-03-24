#ifndef NETWORKTRANSPORT_H
#define NETWORKTRANSPORT_H

#include <QObject>
#include <QString>
#include <QScopedPointer>
#include <QNetworkAccessManager>
#include <QNetworkReply>

//XXX: sync
#include <QEventLoop>

#include "Include/Loader/ITransport.h"

typedef QScopedPointer<QNetworkAccessManager> QNetworkAccessManagerPtr;

class CNetworkTransport : public QObject
        ,public ITransport
{
    Q_OBJECT
public:
    CNetworkTransport();
    virtual ~CNetworkTransport();

    //Implemention of ITransport interface
    virtual int Read(QString&);

signals:

public slots:
    void replyFinished(QNetworkReply*);

private:
    //Methods

    //Variables
    QNetworkAccessManagerPtr   m_pManager;
    QString m_answer;

    //XXX: sync
    QEventLoop loop;
    QNetworkReply::NetworkError err;
};

#endif // NETWORKTRANSPORT_H
