#include "spike.h"

spike::spike(int _x, int _y, int _width, int _height)
{
    posX = _x;
    posY = _y;
    width = _width;
    height = _height;
}

QRectF spike::boundingRect() const
{
    return QRectF(posX,posY,width,height);
}

void spike::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setPen(QColor(19,154,129,20));
//    painter->drawRect(boundingRect());
}
