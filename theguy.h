#ifndef THEGUY_H
#define THEGUY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QString>
#include <QTimer>
#include <stdlib.h>

const float T = 0.1;
const float g = 9.8;

class theguy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    theguy();
    void walkPlayer(short a);
    void cinematica();

    float getPosX() const {return posX;}
    float getPosY() const {return posY;}
    float getVx() const {return Vx;}
    float getVy() const {return Vy;}
    float getAx() const {return Ax;}
    float getAy() const {return Ay;}
    bool getMoveX() const {return mMoveX;}
    bool getMoveY() const {return mMoveY;}
    bool getJump() const {return mJump;}
    QTimer *getSpown() const {return Spown;}
    QTimer *getDeath() const {return Death;}


    void setPosX(float value) {posX = value;}
    void setPosY(float value) {posY = value;}
    void setVx(float value) {Vx = value;}
    void setVy(float value) {Vy = value;}
    void setAx(float value) {Ax = value;}
    void setAy(float value) {Ay = value;}
    void setMoveX(bool moveX) {mMoveX = moveX;}
    void setMoveY(bool moveY) {mMoveY = moveY;}
    void setKeys(short value) {keys = value;}


public slots:

    void updateSpown();
    void updateDeath();
    void jump();

private:

    QString mMoveRight[3] = {":/Imagenes/The guy sprites/Movimiento/Derecha2.png",":/Imagenes/The guy sprites/Movimiento/Derecha3.png",":/Imagenes/The guy sprites/Movimiento/Derecha4.png"};
    QString mMoveLeft[3] = {":/Imagenes/The guy sprites/Movimiento/Izquierda2.png",":/Imagenes/The guy sprites/Movimiento/Izquierda3.png",":/Imagenes/The guy sprites/Movimiento/Izquierda4.png"};
    QString mAttackRight[4] = {":/Imagenes/The guy sprites/Ataque/Ataque_derecha1.png",":/Imagenes/The guy sprites/Ataque/Ataque_derecha2.png"};
    QString mAttackLeft[4] = {":/Imagenes/The guy sprites/Ataque/Ataque_izquierda1.png",":/Imagenes/The guy sprites/Ataque/Ataque_izquierda2.png"};
    QString mDeathRight[5] = {":/Imagenes/The guy sprites/Muerte/Muerte_derecha1.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha2.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha3.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha4.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha5.png"};
    QString mDeathLeft[5] = {":/Imagenes/The guy sprites/Muerte/Muerte_izquierda1.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda2.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda3.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda4.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda5.png"};
    QString mJumpRight[2] = {":/Imagenes/The guy sprites/Salto/Salto_derecha1.png",":/Imagenes/The guy sprites/Salto/Salto_derecha2.png"};
    QString mJumpLeft[2] = {":/Imagenes/The guy sprites/Salto/Salto_izquierda1.png",":/Imagenes/The guy sprites/Salto/Salto_izquierda2.png"};
    QString mSpown[6] = {":/Imagenes/The guy sprites/Spown/Spown1.png",":/Imagenes/The guy sprites/Spown/Spown2.png",":/Imagenes/The guy sprites/Spown/Spown3.png",":/Imagenes/The guy sprites/Spown/Spown4.png",":/Imagenes/The guy sprites/Spown/Spown5.png",":/Imagenes/The guy sprites/Spown/Spown6.png"};

    QTimer *Spown;
    QTimer *Death;
    QTimer *Jump;

    float posX, posY, Vx, Vy, Ax, Ay, _Y;
    short mMove[9], keys = 'a', cont = 0;
    char l, ant;
    bool mCurrentImag[9], mMoveX, mMoveY, mJump, mDeath, ban;
    bool mJumpUp, mJumpDown;
    unsigned int mVidas;



};

#endif // THEGUY_H
