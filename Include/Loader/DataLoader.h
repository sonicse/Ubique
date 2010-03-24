#ifndef DATALOADER_H
#define DATALOADER_H

//Qt headers
#include <QScopedPointer>

#include "Include/Loader/IDataLoader.h"

template<class Transport, class Parser>
class CDataLoader : public IDataLoader
{
typedef QScopedPointer<Parser> ParserPtr;
typedef QScopedPointer<Transport> TransportPtr;

public:
    //ctor
    CDataLoader()
        :m_pParser(new Parser())
        ,m_pTransport(new Transport())
    {
    }

    //Implemention of IDataLoader interface
    virtual int GetContentData( LeafPtr pLeaf)
    {
        int res = 1;
    //    CDataBufferPtr buffer;
        QString buffer;
        res = m_pTransport->Read(buffer);
        if( res == 0 )
        {
            res = m_pParser->Parse(buffer, *pLeaf);
        }
        return res;
    }

//variables
private:
    ParserPtr		m_pParser;
    TransportPtr	m_pTransport;


};

#endif // DATALOADER_H
