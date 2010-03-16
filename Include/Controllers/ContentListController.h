#ifndef CONTENTLISTCONTROLLER_H
#define CONTENTLISTCONTROLLER_H

#include <QObject>
#include <QSharedPointer>

#include "Include/Models/ContentModel.h"
#include "Include/Views/IContentList.h"

typedef QSharedPointer<CContentModel> CContentModelPtr;
typedef QSharedPointer<IContentList> IContentListPtr;

class CContentListController : public QObject
{
Q_OBJECT
public:
    explicit CContentListController(const IContentListPtr &pContentList);

    //Methods
    void SetContentModel(CContentModelPtr pContentModel);

signals:

public slots:
    void OnModelChanged();
    void OnDblClick(const QModelIndex &);


private:
    //Variables
    CContentModelPtr m_pContentModel;
    IContentListPtr m_pContentList;
};

typedef QSharedPointer<CContentListController> CContentListControllerPtr;

#endif // CONTENTLISTCONTROLLER_H
