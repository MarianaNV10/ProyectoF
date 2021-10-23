#include "billsattack.h"

billsattack::billsattack(int x, int y)
{
    px = x;
    pyo = y;

    V = 60;
    T = 0.1;

    std::uniform_int_distribution<int> s(1,2);
    sprite = s(*QRandomGenerator::global());

    setPixmap(QPixmap(flama[sprite-1]));
    setPos(px,pyo);

    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(calculos()));
    time->start(25);
}

void billsattack::calculos()
{
    py = pyo+cont*T*V;
    setPixmap(QPixmap(flama[sprite-1]));
    setPos(px,py);
    cont++;
}
