#ifndef QMLLIST_H
#define QMLLIST_H

#include <QObject>

#include "Include/Views/IContentList.h"

class QDeclarativeContext;

class CQmlList : public QObject
        ,public IContentList
{
Q_OBJECT
public:
    //ctor
    explicit CQmlList(QDeclarativeContext *context);
    //dtor
    ~CQmlList();

    //Implementation of IContentList interface
    //{
    virtual void SetContentListModel(const CContentModelPtr&);
    virtual void SetOnDblClick(QObject *pObj);
    //}


signals:

public slots:

private:
    QDeclarativeContext *m_context;

    CContentModelPtr m_pContentModel;
};

#endif // QMLLIST_H
