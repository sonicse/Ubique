#include "Include/Loader/XmlParser.h"

//Qt headers
#include <QDebug>
#include <QStringRef>

////////////////////////////////////////////////////////////////////////////////////
//ctor
CXmlParser::CXmlParser()
    : QObject()
{
}

////////////////////////////////////////////////////////////////////////////////////
int CXmlParser::Parse(const QString &buffer, Leaf& leaf)
{
    leaf.clear();

    addData( buffer );

    while( !atEnd() )
    {
        readNext();

        if( isStartElement()
            && name() == "asx" )
        {
            readAsx( leaf );
        }
    }

    //Errors
    if( hasError() )
    {
          return 1;
    }

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////
void CXmlParser::readUnknownElement()
{
    Q_ASSERT(isStartElement());

    while( !atEnd() )
    {
        readNext();

        if( isEndElement() ) break;

        if (isStartElement())
            readUnknownElement();
    }
}

////////////////////////////////////////////////////////////////////////////////////
void CXmlParser::readAsx( Leaf& leaf )
{
    Q_ASSERT( isStartElement() && name() == "asx" );

    QStringRef version = attributes().value("version");
    qDebug() << "version: " << version;

    QString title;

    while( !atEnd() )
    {
        readNext();

        if( isEndElement() ) break;

        if( isStartElement() )
        {
            if( name() == "title")
            {
                readTitle( title );
            }
            else if( name() == "entry")
            {
                ContentItemPtr pItem;
                readEntry( pItem );
                leaf.push_back(pItem);
            }
            else
            {
                readUnknownElement();
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
void CXmlParser::readTitle( QString &title )
{
    Q_ASSERT(isStartElement() && name() == "title");

    title = readElementText();
    qDebug() << "Title: " << title;

    if( isEndElement() ) return;

    while( !atEnd() )
    {
        readNext();

        if( isEndElement() ) break;

        if( isStartElement() )
        {
            readUnknownElement();
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////
void CXmlParser::readEntry( ContentItemPtr &pItem )
{
    Q_ASSERT(isStartElement() && name() == "entry");

    QString title;
    QString href;

    while( !atEnd() )
    {
        readNext();

        if( isEndElement() ) break;

        if( isStartElement() )
        {
            if( name() == "title")
            {
                readTitle( title );
            }
            else if( name() == "ref")
            {
                readRef( href );
            }
            else
            {
                readUnknownElement();
            }
        }
    }

    pItem = ContentItemPtr( new ContentItem(title, href) );
}

////////////////////////////////////////////////////////////////////////////////////
void CXmlParser::readRef( QString &href )
{
    Q_ASSERT(isStartElement() && name() == "ref");

    href = attributes().value("href").toString();
    qDebug() << "href: " << href;

    if( isEndElement() ) return;

    while( !atEnd() )
    {
        readNext();

        if( isEndElement() ) break;

        if( isStartElement() )
        {
            readUnknownElement();
        }
    }
}
