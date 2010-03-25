#ifndef IVIEW_H
#define IVIEW_H

#include <QSharedPointer>

#include "Include/Views/IContentScreen.h"

class IView
{
public:
    virtual ~IView(){};
    virtual IContentScreenPtr GetContentScreen() const = 0;
};

//typedef QSharedPointer <IView> IViewPtr;
typedef IView* IViewPtr;


#endif // IVIEW_H
