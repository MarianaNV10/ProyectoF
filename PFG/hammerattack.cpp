#include "hammerattack.h"

hammerattack::hammerattack(int x, int y, char d)
{

    px = x;
    py = y+tam-6;
    vel = 18;
    side = d;
    objeto = new object(vel,px,py);
    setPixmap(QPixmap(martillo).scaled(tam,tam));
    setPos(x,py);
}

void hammerattack::parabola()
{
    tiro = new QTimer();
    connect(tiro,SIGNAL(timeout()), this, SLOT(lanzamiento()));
    tiro->start(100);
}

void hammerattack::lanzamiento()
{
    //setPixmap(QPixmap(martillo).scaled(tam,tam));
    objeto->parabolico(&px,&py,side);
    setPos(px,py);
}

