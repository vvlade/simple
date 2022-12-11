#ifndef MYITEM_HPP
#define MYITEM_HPP

#include "node.hpp"
#include <QGraphicsObject>

class MyItem : public QGraphicsObject
{
public:
    MyItem();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    Node* m_node;
};

#endif // MYITEM_HPP
