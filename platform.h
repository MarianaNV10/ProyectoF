#ifndef PLATFORM_H
#define PLATFORM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>

class platform: public QGraphicsItem
{
public:
    platform(int _x, int _y, int _width, int _height);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosX() const {return posX;}
    int getPosY() const {return posY;}
    int getWidth() const {return width;}
    int getHeight() const {return height;}

private:
    int posX, posY, width, height;
};

#endif // PLATFORM_H
