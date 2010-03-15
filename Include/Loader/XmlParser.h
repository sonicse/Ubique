#ifndef XMLPARSER_H
#define XMLPARSER_H

/*
    ����� - ������ xml ������ ���������� � �������

    ���������: �������� ����������� ������: 1. if()else if() else �������� �� map<string, functor>.
                                            2. ����������� ����� ������ �������� ����� ������.
*/

//TODO: �������� ����������� ������ (��. ����).

//Qt header
#include <QObject>
#include <QXmlStreamReader>

#include "Include/Loader/IParser.h"

class CXmlParser : public QObject
        ,public IParser
        ,public QXmlStreamReader
{
    Q_OBJECT
public:
    CXmlParser();

    //Implemention of IParser interface
    //{
    virtual int Parse(const QString &buffer, Leaf& leaf);
    //}

private:
    //Methods
    void readUnknownElement();
    void readAsx( Leaf& leaf );
    void readTitle( QString &title );
    void readEntry( ContentItemPtr &pItem );
    void readRef( QString &href );
};

#endif // XMLPARSER_H
