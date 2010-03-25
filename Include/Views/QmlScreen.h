#ifndef QMLSCREEN_H
#define QMLSCREEN_H

#include <QWidget>
#include <QDeclarativeComponent>
#include <QDeclarativeView>

#include "Include/Views/IContentScreen.h"

class QDeclarativeView;

class CQmlScreen : public QWidget
        ,public IContentScreen
{
Q_OBJECT
public:
    //ctor
    explicit CQmlScreen(QDeclarativeView *view);
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
    QDeclarativeView *m_view;
    QDeclarativeComponent component;
    QObject *m_object;
};

#endif // QMLSCREEN_H
