#include "theguy.h"

theguy::theguy()
{
    Spown = new QTimer(this);
    Death = new QTimer(this);

    mMoveX = false;
    mMoveY = false;
    mDeath = false;
    mJump = false;
    mJumpUp = false;
    mJumpDown = false;
    ban = false; //Para saber si el personaje se puede mover o no

    Vx = 20;
    Vy = 20;
    Ay = 11;

    for(int f = 0; f < 9; f++){
        mMove[f] = 0;
        mCurrentImag[f] = true;
    }
    connect(Spown, SIGNAL(timeout()), this, SLOT(updateSpown()));
    connect(Death,SIGNAL(timeout()),this,SLOT(updateDeath()));
}

void theguy::walkPlayer(short a)
{
    if(ban){
        switch(a){

        case 'W':

            if(mJump == false){
                mJump = true;
                Jump = new QTimer(this);
                connect(Jump,SIGNAL(timeout()),this,SLOT(jump()));
                Jump->start(80); //cambiar el tiempo
            }

            break;

        case 'A':

            if(l == 'D'){
                ant = l;
                if(mJump){
                    if(mJumpUp) mJumpUp = false;
                    if(mJumpDown) mJumpDown = false;
                }
            }

            l = 'A';

            if(mJump == false){
                if(mMove[1] == 2){
                    mCurrentImag[1] = false;
                }
                else if(mMove[1] == 0){
                    mCurrentImag[1] = true;
                }
                mMove[1] += (2*mCurrentImag[1])-1;
                setPixmap(QPixmap(mMoveLeft[mMove[1]]).scaled(tam,tam));
            }
            else if(mJumpP == false) mJumpP = true;

            break;

        case 'D':

            if(l == 'A'){
                ant = l;
                if(mJump){
                    if(mJumpUp) mJumpUp = false;
                    if(mJumpDown) mJumpDown = false;
                }
            }

            l = 'D';

            if(mJump == false){
                if(mMove[0] == 2){
                    mCurrentImag[0] = false;
                }
                else if(mMove[0] == 0){
                    mCurrentImag[0] = true;
                }
                mMove[0] += (2*mCurrentImag[0])-1;
                setPixmap(QPixmap(mMoveRight[mMove[0]]).scaled(tam,tam));
            }
            else if(mJumpP == false) mJumpP = true;
            break;

        case 'T':
            Attack = new QTimer(this);
            connect(Attack, SIGNAL(timeout()), this, SLOT(updateAttack()));
            Attack->start(100);
            break;
        }
    }
}

void theguy::cinematica()
{
       if(mJump){
           if(Ay > -1){
               pY -= (Ay*abs(Ay))*0.5;
               Ay -= 1;
           }
           else{
               pY += (Vy*g*T)*0.5;
               //pY -= (Ay*abs(Ay))*0.5;
               //Ay  -= 1;
           }

           if(l == 'D' && mJumpP == true) pX += 12;
           if(l == 'A' && mJumpP == true) pX -= 12;
       }
       else{
           if(l == 'D') pX += Vx;
           if(l == 'A') pX -= Vx;
       }

       setPos(pX,pY);
}

void theguy::updateSpown()
{
    setPixmap(QPixmap(mSpown[mMove[8]]).scaled(tam,tam));

    if(mMove[8] == 5){
        Spown->stop();
        ban = true;
    }

    mMove[8] += (2*mCurrentImag[8])-1;
}

void theguy::updateDeath()
{
    if(l == 'D'){
        setPixmap(QPixmap(mDeathRight[mMove[4]]).scaled(tam,tam));

        if(mMove[4] == 4){
            Spown->stop();
        }

        mMove[4] += (2*mCurrentImag[4])-1;
    }
    else if(l == 'A'){

        setPixmap(QPixmap(mDeathLeft[mMove[5]]).scaled(tam,tam));

        if(mMove[5] == 4){
            Spown->stop();
        }

        mMove[5] += (2*mCurrentImag[5])-1;
    }
}

void theguy::updateAttack()
{
    if(l == 'D'){
        setPixmap(QPixmap(mAttackRight[mMove[2]]).scaled(tam,tam));
        mMove[2] += (2*mCurrentImag[2])-1;
        if(mMove[2] == 2){
            Attack->stop();
            mMove[2] = 0;
            delete Attack;
        }
    }

    if(l == 'A'){
        setPixmap(QPixmap(mAttackLeft[mMove[3]]).scaled(tam,tam));
        mMove[3] += (2*mCurrentImag[3])-1;
        if(mMove[3] == 2){
            Attack->stop();
            mMove[3] = 0;
            delete Attack;
        }
    }
}

void theguy::jump()
{
    if(l == 'D'){
        if(Ay > 0 && mJumpUp == false){
            setPixmap(QPixmap(mJumpRight[1]).scaled(tam,tam));
            mJumpUp = true;
        }

        if(Ay < 0 && mJumpDown == false){
            setPixmap(QPixmap(mJumpRight[0]).scaled(tam,tam));
            mJumpDown = true;
            mJumpUp = false;
        }

    }

    if(l == 'A'){
        if(Ay > 0 && mJumpUp == false){
            setPixmap(QPixmap(mJumpLeft[1]).scaled(tam,tam));
            mJumpUp = true;
        }
        if(Ay < 0 && mJumpDown == false){
            setPixmap(QPixmap(mJumpLeft[0]).scaled(tam,tam));
            mJumpDown = true;
            mJumpUp = false;
        }
    }
    cinematica();
}

theguy::~theguy()
{
    delete Spown;
    delete Death;
    delete Jump;
}

