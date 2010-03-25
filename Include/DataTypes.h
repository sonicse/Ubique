#ifndef DATATYPES_H
#define DATATYPES_H

#include <QString>
#include <QVector>
#include <QSharedPointer>


struct ContentItem
{
    ContentItem(){};
    ContentItem(const QString &title, const QString &href):m_title(title),m_href(href){};

    QString m_title;
    QString m_href;
} ;

typedef QSharedPointer<ContentItem> ContentItemPtr;
typedef QVector<ContentItemPtr> Leaf;
typedef Leaf* LeafPtr;
typedef const Leaf* LeafConstPtr;


#endif // DATATYPES_H
