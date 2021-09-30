#ifndef THEGUY_H
#define THEGUY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QString>
#include <QTimer>
#include <stdlib.h>
#include <math.h>
#include <qdebug.h>

static constexpr float T = 0.2;
static constexpr float g = 10;

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
    float getAy() const {return Ay;}
    bool getJumpUp() const {return mJumpUp;}
    bool getJumpDown() const {return mJumpDown;}
    bool getJump() const {return mJump;}
    QTimer *getSpown() const {return Spown;}
    QTimer *getDeath() const {return Death;}
    QTimer *getLeap() const {return Jump;}


    void setPosX(float value) {posX = value;}
    void setPosY(float value) {posY = value;}
    void setVx(float value) {Vx = value;}
    void setAy(float value) {Ay = value;}
    void setKeys(short value) {keys = value;}
    void setJump(bool jump) {mJump = jump;}
    void setJumpUp(bool jumpUp) {mJumpUp = jumpUp;}
    void setJumpDown(bool jumpDown) {mJumpDown = jumpDown;}
    void setJumpP(bool jumpP) {mJumpP = jumpP;}

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

    float posX, posY, Vx, Ay, Vy;
    short mMove[9], keys = 'a', cont = 0;
    char l, ant;
    bool mCurrentImag[9], mMoveX, mMoveY, mJump, mDeath, ban;
    bool mJumpUp, mJumpDown, mJumpP;
    unsigned int mVidas;



};

#endif // THEGUY_H
