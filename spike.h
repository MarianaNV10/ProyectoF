#ifndef SPIKE_H
#define SPIKE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPen>

class spike: public QGraphicsItem
{
public:
    spike(int _x, int _y, int _width, int _height);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosX() const {return posX;}
    int getPosY() const {return posY;}
    int getWidth() const {return width;}
    int getHeight() const {return height;}


private:
    int posX, posY, width, height;
};

#endif // SPIKE_H
