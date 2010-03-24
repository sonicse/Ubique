HEADERS += Include/Controllers/ContentScreenController.h \
    Include/Models/ContentModel.h \
    Include/Controllers/ContentListController.h \
    Include/Views/IContentScreen.h \
    Include/Views/IContentList.h \
    Include/Views/ContentScreen.h \
    Include/Views/ContentList.h \
    Include/Loader/IDataLoader.h \
    Include/Loader/DataLoader.h \
    Include/Loader/ITransport.h \
    Include/Loader/NetworkTransport.h \
    Include/DataTypes.h \
    Include/Loader/IParser.h \
    Include/Loader/XmlParser.h \
    Include/Views/ItemViewDelegate.h \
    Include/Views/ItemView.h \
    Include/Views/QmlScreen.h
SOURCES += Src/Controllers/ContentScreenController.cpp \
    Src/main.cpp \
    Src/Models/ContentModel.cpp \
    Src/Controllers/ContentListController.cpp \
    Src/Views/ContentScreen.cpp \
    Src/Views/ContentList.cpp \
    Src/Loader/NetworkTransport.cpp \
    Src/Loader/XmlParser.cpp \
    Src/Views/ItemViewDelegate.cpp \
    Src/Views/ItemView.cpp \
    Src/Views/QmlScreen.cpp
FORMS += Resources/ContentScreen.ui \
    Resources/ItemView.ui
QT += network \
    xml \
    declarative

