#include "Include/Views/ItemViewDelegate.h"

#include<QPainter>

////////////////////////////////////////////////////////////////////////////////////
//ctor
CItemViewDelegate::CItemViewDelegate(QObject *parent)
    : QAbstractItemDelegate(parent)
    , m_item(new CItemView())
{
}

////////////////////////////////////////////////////////////////////////////////////
//dtor
CItemViewDelegate::~CItemViewDelegate()
{
    delete m_item;
}

////////////////////////////////////////////////////////////////////////////////////
void CItemViewDelegate::paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QPixmap pixmap(m_item->size());

    if( m_model )
    {
        m_item->setTitle( m_model->getTitle(index.row()) );
        m_item->setRef( m_model->getRef(index.row()) );
    }

    m_item->render(&pixmap);

    QRect source(0.0, 0.0, m_item->size().width(), m_item->size().height());

    painter->drawPixmap(option.rect, pixmap, source);

    //m_item->render(painter, option.rect.topLeft(), QRegion(), QWidget::DrawChildren);
}

////////////////////////////////////////////////////////////////////////////////////
QSize CItemViewDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    return m_item->size();
}

void CItemViewDelegate::setModel(const CContentModelPtr &pContentModel)
{
    m_model = pContentModel;
}
