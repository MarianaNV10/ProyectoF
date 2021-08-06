#include "platform.h"

platform::platform(int _x, int _y, int _width, int _height)
{
   posX = _x;
   posY = _y;
   width = _width;
   height = _height;
}

QRectF platform::boundingRect() const
{
     return QRectF(posX,posY,width,height);
}

void platform::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    painter->setPen(QColor(208,117,37,20));
//    painter->drawRect(boundingRect());
}
