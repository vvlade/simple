#include "myitem.hpp"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QWidget>

MyItem::MyItem() {
    setFlag(GraphicsItemFlag::ItemIsMovable);
}

QRectF MyItem::boundingRect() const {
    return QRectF(0, 0, 100, 100);
}

void MyItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget)

    QBrush redBrush(Qt::red);
    QPen blackPen(Qt::black);
    blackPen.setWidth(3);

    QRectF rect = boundingRect();

    painter->setPen(blackPen);
    painter->fillRect(rect, redBrush);
    painter->drawRect(rect);
}
