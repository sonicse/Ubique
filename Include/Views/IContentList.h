#ifndef ICONTENTLIST_H
#define ICONTENTLIST_H

#include <QSharedPointer>

//XXX:
#include <QDebug>

#include "Include/Models/ContentModel.h"

class IContentList
{
public:
    virtual ~IContentList(){};
    virtual void SetContentListModel(const CContentModelPtr&) = 0;
    virtual void SetOnDblClick(QObject *pObj) = 0;
};

//typedef QSharedPointer <IContentList> IContentListPtr;
typedef IContentList* IContentListPtr;

#endif // ICONTENTLIST_H
