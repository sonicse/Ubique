#ifndef ICONTENTSCREEN_H
#define ICONTENTSCREEN_H

#include <QSharedPointer>

typedef QSharedPointer <class IContentList> IContentListPtr;

class IContentScreen
{
public:
    virtual ~IContentScreen(){};
    virtual IContentListPtr GetContentList() const = 0;
    virtual void SetOnBack(QObject *pObj) = 0;
    virtual void SetOnRefresh(QObject *pObj) = 0;
    virtual void show() = 0;
};

typedef QSharedPointer <IContentScreen> IContentScreenPtr;

#endif // ICONTENTSCREEN_H
