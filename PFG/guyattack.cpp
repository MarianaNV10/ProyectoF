#include "guyattack.h"

guyattack::guyattack(int _x, int _y, char lado)
{
    aguy = new QTimer(this);

    side = lado;
    px = _x+tam;
    py = _y+tam-5;
    spt = 0;
    pos = true;
    ban = false;
    connect(aguy,SIGNAL(timeout()),this,SLOT(sprites()));
}

void guyattack::sprites()
{
    if(cont < range){
        if(spt == 3) pos = false;
        if(spt == 0) pos = true;

        if(side == 'D'){
            setPixmap(QPixmap(Attack[spt]).scaled(tam,tam));
            setPos(px,py);
            px += vel;
        }

        if(side == 'A'){
            QTransform rm;
            rm.rotate(180,Qt::YAxis);
            setPixmap(QPixmap(Attack[spt]).scaled(tam,tam).transformed(rm,Qt::SmoothTransformation));
            setPos(px,py);
            px -= vel;
        }

        spt += (2*pos)-1;
        cont++;
    }
}

guyattack::~guyattack()
{
    delete aguy;
}
