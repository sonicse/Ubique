#ifndef CONTENTSCREEN_H
#define CONTENTSCREEN_H

#include <QWidget>
#include <QSharedPointer>
#include <QScopedPointer>

#include "Include/Views/IContentScreen.h"

namespace Ui
{
    class UiContentScreen;
}

typedef QScopedPointer<Ui::UiContentScreen> UiContentScreenPtr;
//typedef QSharedPointer<class IContentList> IContentListPtr;
typedef QSharedPointer<class CContentList> CContentListPtr;

class CContentScreen : public QWidget
        ,public IContentScreen
{
    Q_OBJECT
public:
    //ctor
    explicit CContentScreen(QWidget *parent = 0);
    //dtor
    virtual ~CContentScreen();

    //Implementation IContentScreen interface
    virtual IContentListPtr GetContentList() const;
    virtual void SetOnBack(QObject *pObj);
    virtual void SetOnRefresh(QObject *pObj);
    virtual void show();

signals:
    void OnBack();

public slots:

private:
    UiContentScreenPtr ui;
    IContentListPtr m_pContentList;
};

#endif // CONTENTSCREEN_H
