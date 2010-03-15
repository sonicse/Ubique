#ifndef IPARSER_H
#define IPARSER_H

//Qt headers
#include <QSharedPointer>

#include "Include/DataTypes.h"

class IParser
{
public:
    virtual ~IParser(){};
    virtual int Parse(const QString&, Leaf&) = 0;
};

typedef QSharedPointer <IParser> IParserPtr;

#endif // IPARSER_H
