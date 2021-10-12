#include "huesos.h"

huesos::huesos(int x, int y)
{
    px = x;
    py = y;
    Vx = 10;

    banMove = false;
    banIdle = false;
    banAttack = false;

    for(int d = 0; d < 8; d++){
        sprite[d] = 0;
        pos[d] = true;
    }
}

void huesos::ataque()
{
    Attack = new QTimer(this);
    connect(Attack, SIGNAL(timeout()), this, SLOT(HuesosAttack()));
    Attack->start(250);
}

void huesos::mover()
{
    Move = new QTimer(this);
    connect(Move,SIGNAL(timeout()), this, SLOT(movimiento()));
    Move->start(200);
}

void huesos::idle()
{
    Idle = new QTimer(this);
    connect(Idle, SIGNAL(timeout()), this, SLOT(HuesosIdle()));
    Idle->start(500);
}

void huesos::movimiento() //Se debe de mover hacia donde se encuentre el jugador
{
    if(move == 'D'){
        setPixmap(QPixmap(Right[sprite[0]]).scaled(tam,tam));
        px += Vx;
        if(sprite[0] == 4) pos[0] = false;
        if(sprite[0] == 0) pos[0] = true;
        sprite[0] += (2*pos[0])-1;
    }
    else if(move == 'A'){
        setPixmap(QPixmap(Left[sprite[1]]).scaled(tam,tam));
        px -= Vx;
        if(sprite[1] == 4) pos[1] = false;
        if(sprite[1] == 0) pos[1] = true;
        sprite[1] += (2*pos[1])-1;
    }
    setPos(px,py);
}

void huesos::HuesosIdle() //Se podría tener en cuenta un tiempo para que se quede quieto
{
    if(Id == 0){
        this->banIdle = true;
        std::uniform_int_distribution<int> I(1,2);
        Id = I(*QRandomGenerator::global());
    }

    if(Id == 1){ //Derecha
        setPixmap(QPixmap(HIdle[sprite[5]]).scaled(tam,tam));
    }
    else if(Id == 2){ //Izquierda
        QTransform tr;
        tr.rotate(180,Qt::YAxis);
        setPixmap(QPixmap(HIdle[sprite[5]]).scaled(tam,tam).transformed(tr,Qt::SmoothTransformation));
    }


    if(sprite[5] == 3){
        sprite[5] = 0;
        Id = 0;
        this->banIdle = false;
//        move = 'A';
//        ataque();
//        delete Idle;
    }
    else sprite[5] += (2*pos[5])-1;
}

void huesos::HuesosAttack()
{
    if(At == 0){
        std::uniform_int_distribution<int> A(1,2);
        At = A(*QRandomGenerator::global());
    }

    if(At == 1){ //Modo 1
        if(move == 'D'){
            setPixmap(QPixmap(AttackRM1[sprite[3]]).scaled(tam,tam));
            if(sprite[3] == 3){
                sprite[3] = 0;
                At = 0;
                this->banAttack = false;
                delete this->Attack;
            }
            else sprite[3] += (2*pos[3])-1;
        }
        else if(move == 'A'){
            setPixmap(QPixmap(AttackLM1[sprite[2]]).scaled(tam,tam));
            if(sprite[2] == 2){
                sprite[2] = 0;
                At = 0;
                this->banAttack = false;
                delete this->Attack;
            }
            else sprite[2] += (2*pos[2])-1;
        }
    }
    else if(At == 2){
        setPixmap(QPixmap(AttackM2[sprite[4]]).scaled(tam,tam));
        if(sprite[4] == 5){
            sprite[4] = 0;
            At = 0;
            this->banAttack = false;
            delete this->Attack;
        }
        else sprite[4] += (2*pos[4])-1;
    }
}
