#include "guyattack.h"

guyattack::guyattack(int _x, int _y)
{
    aguy = new QTimer(this);

    px = _x;
    py = _y;
    setPos(px+tam,py+tam-5);
    spt = 0;
    pos = true;
    connect(aguy,SIGNAL(timeout()),this,SLOT(sprites()));
}

QTimer *guyattack::getAguy() const
{
    return aguy;
}

void guyattack::sprites()
{
    if(spt == 3) pos = false;
    if(spt == 0) pos = true;
    setPixmap(QPixmap(Attack[spt]).scaled(tam,tam));
    spt += (2*pos)-1;
}

guyattack::~guyattack()
{
    delete aguy;
}
