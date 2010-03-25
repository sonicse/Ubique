#ifndef CONTENTSCREENCONTROLLER_H
#define CONTENTSCREENCONTROLLER_H

//QT headers
#include <QObject>
#include <QSharedPointer>

#include "Include/Models/ContentModel.h"
#include "Include/Controllers/ContentListController.h"
#include "Include/Views/IContentScreen.h"

typedef QSharedPointer <CContentModel> CContentModelPtr;
typedef QSharedPointer <CContentListController> CContentListControllerPtr;
//typedef QSharedPointer <IContentScreen> IContentScreenPtr;

class CContentScreenController : public QObject
{
Q_OBJECT
public:
    explicit CContentScreenController(IContentScreenPtr pContentScreen);

    //Methods
    void SetContentModel(CContentModelPtr pContentModel);

signals:

public slots:
    void OnBack();
    void OnRefresh();

private:
    //Variables
    CContentModelPtr m_pContentModel;
    CContentListControllerPtr m_pContentListController;
    IContentScreenPtr m_pContentScreen;
};

typedef QSharedPointer <CContentScreenController> CContentScreenControllerPtr;

#endif // CONTENTSCREENCONTROLLER_H
