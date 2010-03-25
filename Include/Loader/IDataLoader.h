#ifndef IDATALOADER_H
#define IDATALOADER_H

#include <QSharedPointer>

#include "Include/DataTypes.h"

class IDataLoader
{
public:
    virtual ~IDataLoader(){};
    virtual int GetContentData( LeafPtr ) = 0;
};

typedef QSharedPointer <IDataLoader> IDataLoaderPtr;

#endif // IDATALOADER_H
