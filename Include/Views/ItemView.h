#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include <QWidget>
#include <QScopedPointer>

namespace Ui {
    class CItemView;
}

typedef QScopedPointer<Ui::CItemView> UiItemViewPtr;

class CItemView : public QWidget {
    Q_OBJECT
public:
    CItemView(QWidget *parent = 0);
    ~CItemView();

    //Methods
    void setTitle(const QString&);
    void setRef(const QString&);

protected:
    void changeEvent(QEvent *e);

private:
    UiItemViewPtr ui;
};

#endif // ITEMVIEW_H
