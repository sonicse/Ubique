#ifndef ICONTENTLIST_H
#define ICONTENTLIST_H

#include <QSharedPointer>

//XXX:
#include <QDebug>

typedef QSharedPointer <class CContentModel> CContentModelPtr;
typedef QSharedPointer <const class CContentModel> CContentModelConstPtr;

class IContentList
{
public:
    virtual ~IContentList(){};
    virtual void SetContentListModel(const CContentModelPtr&) = 0;
    virtual void SetOnDblClick(QObject *pObj) = 0;
};

typedef QSharedPointer <IContentList> IContentListPtr;

#endif // ICONTENTLIST_H
