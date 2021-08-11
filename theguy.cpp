#include "theguy.h"

theguy::theguy()
{
    Spown = new QTimer(this);
    Death = new QTimer(this);

    Spown->stop();
    Death->stop();

    mMoveX = false;
    mMoveY = false;
    mDeath = false;
    mJump = false;
    mJumpUp = false;
    mJumpDown = false;
    ban = false; //Para saber cuando puede empezar a moverse

    Vx = 20;
    Vy = 0;
    Ax = 0;
    Ay = 10;

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
                Jump->start(100);
            }

            break;

        case 'A':

            l = 'A';

            if(mJump == false){
                if(mMove[1] == 2){
                    mCurrentImag[1] = false;
                }
                else if(mMove[1] == 0){
                    mCurrentImag[1] = true;
                }
                mMove[1] += (2*mCurrentImag[1])-1;
                setPixmap(QPixmap(mMoveLeft[mMove[1]]).scaled(50,50));
            }
            break;

        case 'D':

            l = 'D';

            if(mJump == false){
                if(mMove[0] == 2){
                    mCurrentImag[0] = false;
                }
                else if(mMove[0] == 0){
                    mCurrentImag[0] = true;
                }
                mMove[0] += (2*mCurrentImag[0])-1;
                setPixmap(QPixmap(mMoveRight[mMove[0]]).scaled(50,50));
            }
            break;
        }
    }
}

void theguy::cinematica()
{
       if(mJump){
           if(Ay >= -10){
               posY -= (Ay*abs(Ay))*0.5;
               Ay -= 1;
           }
           else{
               Ay = 10;
               mJump = false;
               Jump->stop();
               delete Jump;
           }
       }
       if(l == 'D') posX += Vx;
       if(l == 'A') posX -= Vx;

       setPos(posX,posY);
}

void theguy::updateSpown()
{
    setPixmap(QPixmap(mSpown[mMove[8]]).scaled(50,50));

    if(mMove[8] == 5){
        Spown->stop();
        ban = true;
    }

    mMove[8] += (2*mCurrentImag[8])-1;
}

void theguy::updateDeath()
{
    if(l == 'D' || l == 'L'){
        setPixmap(QPixmap(mDeathRight[mMove[4]]).scaled(50,50));

        if(mMove[4] == 4){
            Spown->stop();
        }

        mMove[4] += (2*mCurrentImag[4])-1;
    }
    else if(l == 'A' || l == 'J'){

        setPixmap(QPixmap(mDeathLeft[mMove[5]]).scaled(50,50));

        if(mMove[5] == 4){
            Spown->stop();
        }

        mMove[5] += (2*mCurrentImag[5])-1;
    }
}

void theguy::jump() //Revisar bien esta parte
{
    if(l == 'D'){
        if(Ay > 0 && mJumpUp == false){
            setPixmap(QPixmap(mJumpRight[1]).scaled(50,50));
            mJumpUp = true;
        }

        if(Ay < 0 && mJumpDown == false){
            setPixmap(QPixmap(mJumpRight[0]).scaled(50,50));
            mJumpDown = true;
        }
    }

    if(l == 'A'){
        if(Ay > 0 && mJumpUp == false){
            setPixmap(QPixmap(mJumpLeft[1]).scaled(50,50));
            mJumpUp = true;
        }
        if(Ay < 0 && mJumpDown == false){
            setPixmap(QPixmap(mJumpLeft[0]).scaled(50,50));
        }
    }

    cinematica();
}
