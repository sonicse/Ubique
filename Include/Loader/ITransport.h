#ifndef ITRANSPORT_H
#define ITRANSPORT_H

#include<QString>

class ITransport
{
public:
    virtual ~ITransport(){};
    virtual int Read(QString&) = 0;
};

#endif // ITRANSPORT_H
