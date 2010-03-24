//QT headers
#include <QtGui>
//QML
#include <QDeclarativeEngine>

//Headers
#include "Include/Controllers/ContentScreenController.h"
#include "Include/Models/ContentModel.h"
#include "Include/Views/IContentScreen.h"
//#include "Include/Views/ContentScreen.h"
#include "Include/Views/QmlScreen.h"

//XXX:test
#include "Include/Loader/DataLoader.h"
#include "Include/Loader/NetworkTransport.h"
#include "Include/Loader/XmlParser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //QML View
    QDeclarativeEngine *engine = new QDeclarativeEngine();

    //Create View
    IContentScreenPtr pContentScreen = IContentScreenPtr(new CQmlScreen(engine));
    //Create Content Model
    CContentModelPtr pContentModel(new CContentModel());

    //XXX: test
    CDataLoader<CNetworkTransport, CXmlParser> loader;
    loader.GetContentData(pContentModel->GetCurrentLeaf());


    //Create Content Controller
    CContentScreenControllerPtr pContentScreenController( new CContentScreenController( pContentScreen ) );
    pContentScreenController->SetContentModel( pContentModel );

    pContentScreen->show();

    return app.exec();
}
