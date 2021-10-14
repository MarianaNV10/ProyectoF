#include "hammerattack.h"

hammerattack::hammerattack(int x, int y, char d)
{

    px = x;
    py = y+tam-6;
    //qDebug() << 708-py << endl;
    vel = 30;
    side = d;
    objeto = new object(vel,px,py);
    setPixmap(QPixmap(martillo).scaled(tam,tam));
    setPos(px,py);
}

void hammerattack::parabola()
{
    tiro = new QTimer();
    connect(tiro,SIGNAL(timeout()), this, SLOT(lanzamiento()));
    tiro->start(30);
}

void hammerattack::lanzamiento()
{
    QTransform tr;
    tr.rotate(-angulo);
    setPixmap(QPixmap(martillo).scaled(tam,tam).transformed(tr));
    objeto->parabolico(&px,&py,side);
    setPos(px,py);
    angulo += 45;
}

