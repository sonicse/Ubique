#ifndef CONTENTLIST_H
#define CONTENTLIST_H

#include <QObject>
#include <QScopedPointer>

#include "Include/Views/IContentList.h"
#include "Include/Views/Widget/ItemViewDelegate.h"

typedef QScopedPointer< CItemViewDelegate > CItemViewDelegatePtr;

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
    CItemViewDelegatePtr m_delegate;
    CContentModelPtr m_pContentModel;
};

#endif // CONTENTLIST_H
