#include "player.h"

player::player(char k)
{   
    keyplayer = k;
    mDeath = false;
    mJump = false;
    mJumpUp = false;
    mJumpDown = false;
    ban = false; //Para saber si el personaje se puede mover o no
    banAttack = false;

    Vx = 20;
    Vy = 20;
    Ay = 11;


    if(keyplayer == 'g'){
        for(int f = 0; f < 9; f++){
            mMoveG[f] = 0;
            mPosG[f] = true;
        }
        Spown = new QTimer(this);
        connect(Spown, SIGNAL(timeout()), this, SLOT(updateSpown()));
    }
    else if(keyplayer == 's'){ //keyplayer = 's'
        ban = true;
        for(int f = 0; f < 8; f++){
            mMoveS[f] = 0;
            mPosS[f] = true;
        }
    }

    objeto = new object(Vx,0,0);
}

void player::walkPlayer(short a)
{
    if(keyplayer == 'g'){
        walkGuy(a);
    }
    else if(keyplayer == 's'){
        walkSteven(a);
    }
}

void player::walkGuy(short a) //se va a mover con W,A,D -> salta con E
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
                if(mMoveG[1] == 2){
                    mPosG[1] = false;
                }
                else if(mMoveG[1] == 0){
                    mPosG[1] = true;
                }
                mMoveG[1] += (2*mPosG[1])-1;
                setPixmap(QPixmap(mGMoveLeft[mMoveG[1]]).scaled(tam,tam));
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
                if(mMoveG[0] == 2){
                    mPosG[0] = false;
                }
                else if(mMoveG[0] == 0){
                    mPosG[0] = true;
                }
                mMoveG[0] += (2*mPosG[0])-1;
                setPixmap(QPixmap(mGMoveRight[mMoveG[0]]).scaled(tam,tam));
            }
            else if(mJumpP == false) mJumpP = true;
            break;

        case 'T':
            if(banAttack == false){
                this->banAttack = true;
                Attack = new QTimer(this);
                connect(Attack, SIGNAL(timeout()), this, SLOT(updateAttack()));
                Attack->start(100);
            }
            break;
        }
    }
}

void player::walkSteven(short a) //Va a moverse con I,J,L -> salta con B
{
    if(ban){
        switch(a){

        case 'I':

            if(mJump == false){
                mJump = true;
                Jump = new QTimer();
                connect(Jump,SIGNAL(timeout()),this,SLOT(jump()));
                Jump->start(80); //cambiar el tiempo
            }

            break;

        case 'J':

            if(l == 'L'){
                ant = l;
                if(mJump){
                    if(mJumpUp) mJumpUp = false;
                    if(mJumpDown) mJumpDown = false;
                }
            }

            l = 'J';

            if(mJump == false){
                if(mMoveS[1] == 2){
                    mPosS[1] = false;
                }
                else if(mMoveS[1] == 0){
                    mPosS[1] = true;
                }
                mMoveS[1] += (2*mPosS[1])-1;
                setPixmap(QPixmap(mSMoveLeft[mMoveS[1]]).scaled(tam,tam));
            }
            else if(mJumpP == false) mJumpP = true;

            break;

        case 'L':

            if(l == 'J'){
                ant = l;
                if(mJump){
                    if(mJumpUp) mJumpUp = false;
                    if(mJumpDown) mJumpDown = false;
                }
            }

            l = 'L';

            if(mJump == false){
                if(mMoveS[0] == 2){
                    mPosS[0] = false;
                }
                else if(mMoveS[0] == 0){
                    mPosS[0] = true;
                }
                mMoveS[0] += (2*mPosS[0])-1;
                setPixmap(QPixmap(mSMoveRight[mMoveS[0]]).scaled(tam,tam));
            }
            else if(mJumpP == false) mJumpP = true;
            break;

        case 'T':
            if(this->banAttack == false){
                this->banAttack = true;
                Attack = new QTimer(this);
                connect(Attack, SIGNAL(timeout()), this, SLOT(updateAttack()));
                Attack->start(100);
            }
            break;
        }
    }
}

void player::stevenA(){
    setPixmap(QPixmap(mSMoveRight[mMoveS[0]]).scaled(tam,tam));
}

void player::cinematica()
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

           if(keyplayer == 'g'){
               if(l == 'D' && mJumpP == true) pX += 12;
               if(l == 'A' && mJumpP == true) pX -= 12;
           }
           else if(keyplayer == 's'){
               if(l == 'L' && mJumpP == true) pX += 12;
               if(l == 'J' && mJumpP == true) pX -= 12;
           }
       }
       else{
           if(keyplayer == 'g'){
               if(l == 'D') pX += Vx;
               if(l == 'A') pX -= Vx;
           }
           else if(keyplayer == 's'){
               if(l == 'L') pX += Vx;
               if(l == 'J') pX -= Vx;
           }
       }

       setPos(pX,pY);
}

void player::updateSpown()
{
    setPixmap(QPixmap(mGSpown[mMoveG[8]]).scaled(tam,tam));

    if(mMoveG[8] == 5){
        Spown->stop();
        ban = true;
    }

    mMoveG[8] += (2*mPosG[8])-1;
}

void player::updateAttack()
{

    switch (keyplayer) {
    case 'g':

        if(l == 'D'){
            setPixmap(QPixmap(mGAttackRight[mMoveG[2]]).scaled(tam,tam));
            mMoveG[2] += (2*mPosG[2])-1;
            if(mMoveG[2] == 2){
                Attack->stop();
                mMoveG[2] = 0;
                this->banAttack = false;
                delete Attack;
            }
        }

        if(l == 'A'){
            setPixmap(QPixmap(mGAttackLeft[mMoveG[3]]).scaled(tam,tam));
            mMoveG[3] += (2*mPosG[3])-1;
            if(mMoveG[3] == 2){
                Attack->stop();
                mMoveG[3] = 0;
                this->banAttack = false;
                delete Attack;
            }
        }
        break;

    case 's':

        if(l == 'L'){
            setPixmap(QPixmap(mSAttackRight[mMoveS[2]]).scaled(tam,tam));
            mMoveS[2] += (2*mPosS[2])-1;
            if(mMoveS[2] == 3){
                Attack->stop();
                mMoveS[2] = 0;
                this->banAttack = false;
                delete Attack;
            }
        }

        if(l == 'J'){
            setPixmap(QPixmap(mSAttackLeft[mMoveS[3]]).scaled(tam,tam));
            mMoveS[3] += (2*mPosS[3])-1;
            if(mMoveS[3] == 3){
                Attack->stop();
                mMoveS[3] = 0;
                this->banAttack = false;
                delete Attack;
            }
        }
        break;
    }
}

void player::jump()
{

    switch (keyplayer) {
    case 'g':

        if(l == 'D'){
            if(Ay > 0 && mJumpUp == false){
                setPixmap(QPixmap(mGJumpRight[1]).scaled(tam,tam));
                mJumpUp = true;
            }

            if(Ay < 0 && mJumpDown == false){
                setPixmap(QPixmap(mGJumpRight[0]).scaled(tam,tam));
                mJumpDown = true;
                mJumpUp = false;
            }

        }

        if(l == 'A'){
            if(Ay > 0 && mJumpUp == false){
                setPixmap(QPixmap(mGJumpLeft[1]).scaled(tam,tam));
                mJumpUp = true;
            }
            if(Ay < 0 && mJumpDown == false){
                setPixmap(QPixmap(mGJumpLeft[0]).scaled(tam,tam));
                mJumpDown = true;
                mJumpUp = false;
            }
        }
        break;

    case 's':

        if(l == 'L'){
            if(Ay > 0 && mJumpUp == false){
                setPixmap(QPixmap(mSJumpRight[1]).scaled(tam,tam));
                mJumpUp = true;
            }

            if(Ay < 0 && mJumpDown == false){
                setPixmap(QPixmap(mSJumpRight[0]).scaled(tam,tam));
                mJumpDown = true;
                mJumpUp = false;
            }

        }

        if(l == 'J'){
            if(Ay > 0 && mJumpUp == false){
                setPixmap(QPixmap(mSJumpLeft[1]).scaled(tam,tam));
                mJumpUp = true;
            }
            if(Ay < 0 && mJumpDown == false){
                setPixmap(QPixmap(mSJumpLeft[0]).scaled(tam,tam));
                mJumpDown = true;
                mJumpUp = false;
            }
        }
        break;
    }

    cinematica();
}

player::~player()
{
    delete objeto;
}

