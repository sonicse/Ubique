#ifndef CONTENTLIST_H
#define CONTENTLIST_H

#include "Include/Views/IContentList.h"

#include <QObject>

class QListView;

class CContentList : public QObject
        ,public IContentList
{
Q_OBJECT
public:
    //ctor
    explicit CContentList(QListView *pListView);
    //dtor
    ~CContentList();

    virtual void SetContentListModel(const CContentModelPtr&);
    virtual void SetOnDblClick(QObject *pObj);

signals:

public slots:

private:
    void SetListData();

private:
    QListView *m_pListView;
    CContentModelPtr m_pContentModel;
};

#endif // CONTENTLIST_H
