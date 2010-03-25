//QT headers
#include <QtGui>

//Headers
#include "Include/Controllers/ContentScreenController.h"
#include "Include/Models/ContentModel.h"
#include "Include/Views/Qml/QmlView.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //Create View
    IViewPtr view = IViewPtr( new CQmlView() );

    //Create Content Model
    CContentModelPtr pContentModel(new CContentModel());

    //Create Content Controller
    CContentScreenControllerPtr pContentScreenController( new CContentScreenController( view->GetContentScreen() ) );
    pContentScreenController->SetContentModel( pContentModel );

    view->GetContentScreen()->show();

    return app.exec();
}
