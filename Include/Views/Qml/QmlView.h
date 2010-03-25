#ifndef QMLVIEW_H
#define QMLVIEW_H

#include <QObject>
#include <QDeclarativeView>
#include <QDeclarativeContext>

#include "Include/Views/IView.h"
#include "Include/Views/IContentScreen.h"
#include "Include/Views/IContentList.h"

class CQmlView : public QObject
        ,public IView
        ,public IContentScreen
        ,public IContentList
{
Q_OBJECT
public:
    //ctor
    CQmlView();
    //dtor
    virtual ~CQmlView();

    //Implementation IView interface
    //{
    IContentScreenPtr GetContentScreen() const;
    //}

    //Implementation IContentScreen interface
    //{
    virtual IContentListPtr GetContentList() const;
    virtual void SetOnBack(QObject *pObj);
    virtual void SetOnRefresh(QObject *pObj);
    virtual void show();
    //}

    //Implementation IContentList interface
    //{
    virtual void SetContentListModel(const CContentModelPtr&);
    virtual void SetOnDblClick(QObject *pObj);
    //}


signals:
    void refreshModel();
    void doubleClicked(int index);

public slots:
    void onRefresh();
    void onDoubleClicked(int);

private:
    QDeclarativeView *m_view;
    QDeclarativeContext *m_context;
    CContentModelPtr m_pContentModel;
};

#endif // QMLVIEW_H
