#include "bills.h"

bills::bills(int x, int y)
{
    this->px = x;
    this->py = y;
    this->vy = 20;

    this->banSpown = false;
    this->banDeath = false;
    this->banMove = false;
    this->banAttack = false;

    for(int h = 0; h < 4; h++){
        sprite[h] = 0;
        pos[h] = true;
    }
    //setPixmap(QPixmap(bspown[1]).scaled(tam,tam));
    setPos(px,py);
}

void bills::spown()
{
    this->mSpown = new QTimer();
    connect(mSpown,SIGNAL(timeout()), this, SLOT(billsSpown()));
    mSpown->start(250);
}

void bills::movement()
{
    this->mMove = new QTimer();
    connect(mMove,SIGNAL(timeout()), this, SLOT(billsMove()));
    mMove->start(350);
}

void bills::attack()
{
    this->mAttack = new QTimer();
    connect(mAttack,SIGNAL(timeout()), this, SLOT(billsAttack()));
    mAttack->start(450);
}

void bills::death()
{
    this->mDeath = new QTimer();
    connect(mDeath,SIGNAL(timeout()), this, SLOT(billsDeath()));
    mDeath->start(250);
}

void bills::billsSpown()
{
    setPixmap(QPixmap(bspown[sprite[0]]).scaled(tam,tam));
    sprite[0] += (2*pos[0])-1;
    if(sprite[0] == 2) pos[0] = false;
    if(sprite[0] == 0){
        pos[0] = true;
        mSpown->stop();
        delete mSpown;
    }
}

void bills::billsMove()
{
    setPixmap(QPixmap(bmove[sprite[2]]).scaled(tam,tam));
    sprite[2] += (2*pos[2])-1;
    py += vy;
    setPos(px,py);
    if(sprite[2] == 4) pos[2] = false;
    if(sprite[2] == 0){
        pos[2] = true;
//        mMove->stop();
//        delete mMove;
    }
}

void bills::billsAttack()
{
    setPixmap(QPixmap(battack[sprite[3]]).scaled(tam,tam));
    sprite[3] += (2*pos[3])-1;
    if(sprite[3] == 2){
        sprite[3] = 0;
        mAttack->stop();
        delete mAttack;
    }
}

void bills::billsDeath()
{
    setPixmap(QPixmap(bdeath[sprite[1]]).scaled(tam,tam));
    sprite[1] += (2*pos[1])-1;
    if(sprite[1] == 4){
        sprite[1] = 0;
        mDeath->stop();
        delete mDeath;
    }
}



















