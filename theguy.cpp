#include "theguy.h"

theguy::theguy()
{
    Spown = new QTimer(this);
    Death = new QTimer(this);

    mMoveX = false;
    mMoveY = false;

    for(int f = 0; f < 9; f++){
        mMove[f] = 0;
        mCurrentImag[f] = true;
    }

    connect(Spown, SIGNAL(timeout()), this, SLOT(updateSpown()));
}

void theguy::updateSpown()
{
    setPixmap(QPixmap(mSpown[mMove[8]]).scaled(35,35));

    if(mMove[8] == 5){
        Spown->stop();
    }

    mMove[8] += (2*mCurrentImag[8])-1;
}

void theguy::updateDeath()
{
    if(mMoveX){
        setPixmap(QPixmap(mDeathRight[mMove[4]]).scaled(35,35));

        if(mMove[4] == 4){
            Spown->stop();
        }

        mMove[4] += (2*mCurrentImag[4])-1;
    }
    else{
        if(mMoveY){
            setPixmap(QPixmap(mDeathLeft[mMove[5]]).scaled(35,35));

            if(mMove[5] == 4){
                Spown->stop();
            }

            mMove[5] += (2*mCurrentImag[5])-1;
        }
    }
}
