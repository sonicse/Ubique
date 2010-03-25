#include "Include/Views/Widget/ContentScreen.h"

//Qt headers
#include <QDebug>

//Generated header
#include "Ui_ContentScreen.h"

#include "Include/Views/Widget/ContentList.h"

////////////////////////////////////////////////////////////////////////////////////
//ctor
CContentScreen::CContentScreen(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UiContentScreen)
{
    ui->setupUi( this );

    m_pContentList = IContentListPtr(new CContentList(ui->listView) );
}

////////////////////////////////////////////////////////////////////////////////////
//dtor
CContentScreen::~CContentScreen()
{
    qDebug() << "~CContentScreen() called";
}

////////////////////////////////////////////////////////////////////////////////////
IContentListPtr CContentScreen::GetContentList() const
{
    return m_pContentList;
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreen::SetOnBack(QObject *pObj)
{
    QObject::connect(ui->BackButton, SIGNAL(clicked()), pObj, SLOT(OnBack()));
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreen::SetOnRefresh(QObject *pObj)
{
    QObject::connect(ui->RefreshButton, SIGNAL(clicked()), pObj, SLOT(OnRefresh()));
}

////////////////////////////////////////////////////////////////////////////////////
void CContentScreen::show()
{
    QWidget::show();
}
