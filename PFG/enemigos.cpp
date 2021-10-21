#include "enemigos.h"

enemigos::enemigos(int x, int y, char t)
{
    px = x;
    py = y;
    Vx = 10;
    this->type = t;

    objeto = new object(Vx,0,0);

    banMove = false;
    banIdle = false;
    banAttack = false;
    banDeath = false;
    banD = true;

    if(this->type == 'b'){
        for(int d = 0; d < 8; d++){
            sprite[d] = 0;
            pos[d] = true;
        }
    }
    else{
        for(int d = 0; d < 3; d++){
            spriteHm[d] = 0;
            posHm[d] = true;
        }
    }
    setPos(px,py);
}

void enemigos::ataque()
{
    Attack = new QTimer();
    connect(Attack, SIGNAL(timeout()), this, SLOT(EnemigoAttack()));
    Attack->start(250);
}

void enemigos::mover()
{
    Move = new QTimer();
    connect(Move,SIGNAL(timeout()), this, SLOT(movimiento()));
    Move->start(200);
}

void enemigos::muerte()
{
    EnemigoD = new QTimer(this);
    connect(EnemigoD,SIGNAL(timeout()), this, SLOT(HuesosDeath()));
    EnemigoD->start(300);
}

void enemigos::idle()
{
    Idle = new QTimer();
    connect(Idle, SIGNAL(timeout()), this, SLOT(HuesosIdle()));
    Idle->start(700);
}

void enemigos::movimiento() //Se debe de mover hacia donde se encuentre el jugador
{
    switch (type) {
    case 'b':
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
        break;

    case 'm':
        if(move == 'D'){
            setPixmap(QPixmap(HammerRight[spriteHm[0]]).scaled(tam,tam));
            px += Vx;
            if(spriteHm[0] == 7) posHm[0] = false;
            if(spriteHm[0] == 0) posHm[0] = true;
            spriteHm[0] += (2*posHm[0])-1;
        }
        else if(move == 'A'){
            setPixmap(QPixmap(HammerLeft[spriteHm[1]]).scaled(tam,tam));
            px -= Vx;
            if(spriteHm[1] == 7) posHm[1] = false;
            if(spriteHm[1] == 0) posHm[1] = true;
            spriteHm[1] += (2*posHm[1])-1;
        }
        break;
    }

    setPos(px,py);
}

void enemigos::HuesosIdle() //Se podría tener en cuenta un tiempo para que se quede quieto
{
    if(Id == 0){
        this->banIdle = true;
        std::uniform_int_distribution<int> I(1,2);
        Id = I(*QRandomGenerator::global());
    }

    if(Id == 1){ //Derecha
        this->move = 'D';
        setPixmap(QPixmap(HIdle[sprite[5]]).scaled(tam,tam));
    }
    else if(Id == 2){ //Izquierda
        QTransform tr;
        tr.rotate(180,Qt::YAxis);
        this->move = 'A';
        setPixmap(QPixmap(HIdle[sprite[5]]).scaled(tam,tam).transformed(tr,Qt::SmoothTransformation));
    }


    if(sprite[5] == 3){
        sprite[5] = 0;
        Id = 0;
        this->banIdle = false;
        this->banMove = true;
        this->mover();
        delete Idle;
    }
    else sprite[5] += (2*pos[5])-1;
}

void enemigos::EnemigoAttack()
{

    switch (type) {
    case 'b':
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
        break;

    case 'm':
        if(move == 'D'){
            setPixmap(QPixmap(HammerAttack[spriteHm[2]]).scaled(tam,tam));
            spriteHm[2] += (2*posHm[2])-1;
            if(spriteHm[2] == 9){
                spriteHm[2] = 0;
                setPixmap(QPixmap(HammerAttack[spriteHm[2]]).scaled(tam,tam));
                this->Attack->stop();
                this->banAttack = false;
                this->banMove = true;
                mover();
                delete this->Attack;
            }
        }
        else if(move == 'A'){
            QTransform tr;
            tr.rotate(180,Qt::YAxis);
            setPixmap(QPixmap(HammerAttack[spriteHm[2]]).scaled(tam,tam).transformed(tr));
            spriteHm[2] += (2*posHm[2])-1;
            if(spriteHm[2] == 9){
                spriteHm[2] = 0;
                setPixmap(QPixmap(HammerAttack[spriteHm[2]]).scaled(tam,tam).transformed(tr));
                this->Attack->stop();
                this->banAttack = false;
                this->banMove = true;
                mover();
                delete this->Attack;
            }
        }
        break;
    }

}

void enemigos::HuesosDeath()
{
    if(move == 'D'){
        setPixmap(QPixmap(Death[sprite[6]]).scaled(tam,tam));
        sprite[6] += (2*pos[6])-1;
        if(sprite[6] == 7){
            sprite[6] = 0;
            this->banDeath = true;
            EnemigoD->stop();
            delete EnemigoD;
        }
    }
    else if(move == 'A'){
        QTransform tr;
        tr.rotate(180,Qt::YAxis);
        setPixmap(QPixmap(Death[sprite[6]]).scaled(tam,tam).transformed(tr));
        sprite[6] += (2*pos[6])-1;
        if(sprite[6] == 7){
            sprite[6] = 0;
            this->banDeath = true;
            EnemigoD->stop();
            delete EnemigoD;
        }
    }
}

enemigos::~enemigos()
{
    delete objeto;
}

