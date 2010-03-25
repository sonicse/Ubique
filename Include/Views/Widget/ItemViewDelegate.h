#ifndef ITEMVIEWDELEGATE_H
#define ITEMVIEWDELEGATE_H

//Qt header
#include <QAbstractItemDelegate>

#include "Include/Views/Widget/ItemView.h"
#include "Include/Models/ContentModel.h"

class CItemViewDelegate : public QAbstractItemDelegate
{
Q_OBJECT
public:
    explicit CItemViewDelegate(QObject *parent = 0);
    ~CItemViewDelegate();

    //Implemention of QAbstractItemDelegate
    //{
    void paint( QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index ) const;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    //}

    void setModel(const CContentModelPtr &pContentModel);

signals:

public slots:

private:
    CItemView *m_item;
    CContentModelPtr m_model;
};

#endif // ITEMVIEWDELEGATE_H
