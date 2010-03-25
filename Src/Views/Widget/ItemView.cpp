#include "Include/Views/Widget/ItemView.h"

#include "ui_ItemView.h"

CItemView::CItemView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CItemView)
{
    ui->setupUi(this);
}

CItemView::~CItemView()
{
}

void CItemView::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void CItemView::setTitle(const QString &title)
{
    ui->labelTitle->setText(title);
}

void CItemView::setRef(const QString &ref)
{
    ui->labelRef->setText(ref);
}
