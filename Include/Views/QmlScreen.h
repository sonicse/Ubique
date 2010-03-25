#ifndef QMLSCREEN_H
#define QMLSCREEN_H

#include <QWidget>
#include <QDeclarativeComponent>

#include "Include/Views/IContentScreen.h"

class QDeclarativeEngine;

class CQmlScreen : public QWidget
        ,public IContentScreen
{
Q_OBJECT
public:
    //ctor
    explicit CQmlScreen(QDeclarativeEngine *engine);
    //dtor
    virtual ~CQmlScreen();

    //Implementation IContentScreen interface
    //{
    virtual IContentListPtr GetContentList() const;
    virtual void SetOnBack(QObject *pObj);
    virtual void SetOnRefresh(QObject *pObj);
    virtual void show();
    //}

signals:

public slots:

private:
    //Variables
    QDeclarativeEngine *m_engine;
    QDeclarativeContext *m_context;
    QDeclarativeComponent m_component;
    QObject *m_object;

    IContentListPtr m_pContentList;
};

#endif // QMLSCREEN_H
