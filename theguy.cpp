#include "theguy.h"

theguy::theguy()
{
    Spown = new QTimer(this);
    Death = new QTimer(this);
    Jump = new QTimer(this);

    Spown->stop();
    Death->stop();
    Jump->stop();

    mMoveX = false;
    mMoveY = false;
    mDeath = false;
    mJump = false; //Cuando el personaje salte no cambie las imagenes a mostar sino que solo muestre la de salto
    ban = false; //Para saber cuando puede empezar a moverse

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
    if(ban){
        if(keys == 'L'){

            switch(a){

            case 'W':

                if(mJump == false){
                    mJump = true;
                    connect(Jump,SIGNAL(timeout()),this, SLOT(jump()));
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
        else if(keys == 'R'){ //Organizar la parte cuando salta

            switch(a){

            case 'I':

                mJump = true;

                if(l == 'I'){

                    if(mMove[6] == 1){
                        mCurrentImag[6] = false;
                    }
                    else if(mMove[6] == 0){
                        mCurrentImag[6] = true;
                    }

                    mMove[6] += (2*mCurrentImag[6])-1;
                    setPixmap(QPixmap(mJumpRight[mMove[6]]).scaled(50,50));
                }
                else if(l == 'J'){

                    if(mMove[7] == 1){
                        mCurrentImag[7] = false;
                    }
                    else if(mMove[7] == 0){
                        mCurrentImag[7] = true;
                    }

                    mMove[7] += (2*mCurrentImag[7])-1;
                    setPixmap(QPixmap(mJumpLeft[mMove[7]]).scaled(50,50));
                }

                break;

            case 'J':

                l = 'J';
                if(mMove[1] == 2){
                    mCurrentImag[1] = false;
                }
                else if(mMove[1] == 0){
                    mCurrentImag[1] = true;
                }

                mMove[1] += (2*mCurrentImag[1])-1;
                setPixmap(QPixmap(mMoveLeft[mMove[1]]).scaled(50,50));

                break;

            case 'L':

                l = 'L';
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
    }
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
    if(keys == 'L'){

        if(l == 'D'){
            if(mMove[6] == 1){
                mMove[6] = 0;
                mJump = false;
                Jump->stop();
            }

            setPixmap(QPixmap(mJumpRight[mMove[6]]).scaled(50,50));
            mMove[6] += (2*mCurrentImag[6])-1;
        }
        else if(l == 'A'){
            if(mMove[7] == 1){
                mMove[7] = 0;
                mJump = false;
                Jump->stop();
            }
            setPixmap(QPixmap(mJumpLeft[mMove[7]]).scaled(50,50));
            mMove[7] += (2*mCurrentImag[7])-1;
        }
    }
    else if(keys == 'R'){

    }
}
