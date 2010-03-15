#ifndef XMLPARSER_H
#define XMLPARSER_H

/*
    Класс - парсер xml данных приходящих с сервера

    Замечание: Возможна оптимизация работы: 1. if()else if() else заменить на map<string, functor>.
                                            2. Рекурсивный вызов фунций заменить схему вызова.
*/

//TODO: возможна оптимизация работы (см. выше).

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
