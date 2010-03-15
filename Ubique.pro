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
    Include/Loader/XmlParser.h
SOURCES += Src/Controllers/ContentScreenController.cpp \
    Src/main.cpp \
    Src/Models/ContentModel.cpp \
    Src/Controllers/ContentListController.cpp \
    Src/Views/ContentScreen.cpp \
    Src/Views/ContentList.cpp \
    Src/Loader/NetworkTransport.cpp \
    Src/Loader/XmlParser.cpp
FORMS += Resources/ContentScreen.ui

QT += network \
    xml
