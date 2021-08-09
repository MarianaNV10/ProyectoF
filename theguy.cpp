#include "theguy.h"

theguy::theguy()
{
    Spown = new QTimer(this);
    Death = new QTimer(this);

    Spown->stop();
    Death->stop();

    mMoveX = false;
    mMoveY = false;
    mJump = false; //Cuando el personaje salte no cambie las imagenes a mostar sino que solo muestre la de salto

    Vx = 0;
    Vy = 0;
    Ax = 0;
    Ay = 0;

    for(int f = 0; f < 9; f++){
        mMove[f] = 0;
        mCurrentImag[f] = true;
    }

    connect(Spown, SIGNAL(timeout()), this, SLOT(updateSpown()));
    connect(Death,SIGNAL(timeout()),this,SLOT(updateDeath()));
}

void theguy::walkPlayer(short a)
{
    switch(a){
    case 'W':

        if(mMoveX){
            if(mMove[6] == 1){
                mCurrentImag[6] = false;
            }
            else if(mMove[6] == 0){
                mCurrentImag[6] = true;
            }

            mMove[6] += (2*mCurrentImag[6])-1;
            setPixmap(QPixmap(mJumpRight[mMove[6]]).scaled(50,50));
        }
        else{
            if(mMoveY){
                if(mMove[7] == 1){
                    mCurrentImag[7] = false;
                }
                else if(mMove[7] == 0){
                    mCurrentImag[7] = true;
                }

                mMove[7] += (2*mCurrentImag[7])-1;
                setPixmap(QPixmap(mJumpLeft[mMove[7]]).scaled(50,50));
            }
        }

        break;

    case 'A':

        if(mMove[1] == 2){
            mCurrentImag[1] = false;
        }
        else if(mMove[1] == 0){
            mCurrentImag[1] = true;
        }

        mMove[1] += (2*mCurrentImag[1])-1;
        setPixmap(QPixmap(mMoveLeft[mMove[1]]).scaled(50,50));

        break;

    case 'D':

        if(mMove[0] == 2){
            mCurrentImag[0] = false;
        }
        else if(mMove[0] == 0){
            mCurrentImag[0] = true;
        }

        mMove[0] += (2*mCurrentImag[0])-1;
        setPixmap(QPixmap(mMoveRight[mMove[0]]).scaled(50,50));
        break;
    }
}

void theguy::updateSpown()
{
    setPixmap(QPixmap(mSpown[mMove[8]]).scaled(50,50));

    if(mMove[8] == 5){
        Spown->stop();
    }

    mMove[8] += (2*mCurrentImag[8])-1;
}

void theguy::updateDeath()
{
    if(mMoveX){
        setPixmap(QPixmap(mDeathRight[mMove[4]]).scaled(50,50));

        if(mMove[4] == 4){
            Spown->stop();
        }

        mMove[4] += (2*mCurrentImag[4])-1;
    }
    else{
        if(mMoveY){
            setPixmap(QPixmap(mDeathLeft[mMove[5]]).scaled(50,50));

            if(mMove[5] == 4){
                Spown->stop();
            }

            mMove[5] += (2*mCurrentImag[5])-1;
        }
    }
}

QTimer *theguy::getDeath() const
{
    return Death;
}

QTimer *theguy::getSpown() const
{
    return Spown;
}

