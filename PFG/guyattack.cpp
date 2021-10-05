#include "guyattack.h"

guyattack::guyattack(int _x, int _y, char lado, char k)
{
    aguy = new QTimer(this);

    keyplayer = k;
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
        if(keyplayer == 'g'){
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
        else{
            if(spt == 2) pos = false;
            if(spt == 0) pos = true;

            if(side == 'L'){
                setPixmap(QPixmap(AttackS[spt]).scaled(tam,tam));
                setPos(px,py);
                px += vel;
            }

            if(side == 'J'){
                QTransform rm;
                rm.rotate(180,Qt::YAxis);
                setPixmap(QPixmap(AttackS[spt]).scaled(tam,tam).transformed(rm,Qt::SmoothTransformation));
                setPos(px,py);
                px -= vel;
            }

            spt += (2*pos)-1;
            cont++;
        }
    }
}

guyattack::~guyattack()
{
    delete aguy;
}
