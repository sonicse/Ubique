HEADERS += Include/Controllers/ContentScreenController.h \
    Include/Models/ContentModel.h \
    Include/Controllers/ContentListController.h \
    Include/Views/IContentScreen.h \
    Include/Views/IContentList.h \
    Include/Views/Widget/ContentScreen.h \
    Include/Views/Widget/ContentList.h \
    Include/Loader/IDataLoader.h \
    Include/Loader/DataLoader.h \
    Include/Loader/ITransport.h \
    Include/Loader/NetworkTransport.h \
    Include/DataTypes.h \
    Include/Loader/IParser.h \
    Include/Loader/XmlParser.h \
    Include/Views/Widget/ItemViewDelegate.h \
    Include/Views/Widget/ItemView.h \
    Include/Views/Qml/QmlView.h \
    Include/Views/IView.h
SOURCES += Src/Controllers/ContentScreenController.cpp \
    Src/main.cpp \
    Src/Models/ContentModel.cpp \
    Src/Controllers/ContentListController.cpp \
    Src/Views/Widget/ContentScreen.cpp \
    Src/Views/Widget/ContentList.cpp \
    Src/Loader/NetworkTransport.cpp \
    Src/Loader/XmlParser.cpp \
    Src/Views/Widget/ItemViewDelegate.cpp \
    Src/Views/Widget/ItemView.cpp \
    Src/Views/Qml/QmlView.cpp
FORMS += Resources/ContentScreen.ui \
    Resources/ItemView.ui
QT += network \
    xml \
    declarative
