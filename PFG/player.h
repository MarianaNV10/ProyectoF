#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QString>
#include <QTimer>
#include <stdlib.h>
#include <math.h>
#include <qdebug.h>
#include "object.h"

static constexpr float T = 0.2;
static constexpr float g = 10;
static constexpr unsigned int tam = 50;

class player: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QString mGMoveRight[3] = {":/Imagenes/The guy sprites/Movimiento/Derecha2.png",":/Imagenes/The guy sprites/Movimiento/Derecha3.png",":/Imagenes/The guy sprites/Movimiento/Derecha4.png"};
    QString mGMoveLeft[3] = {":/Imagenes/The guy sprites/Movimiento/Izquierda2.png",":/Imagenes/The guy sprites/Movimiento/Izquierda3.png",":/Imagenes/The guy sprites/Movimiento/Izquierda4.png"};
    QString mGAttackRight[2] = {":/Imagenes/The guy sprites/Ataque/Ataque_derecha1.png",":/Imagenes/The guy sprites/Ataque/Ataque_derecha2.png"};
    QString mGAttackLeft[2] = {":/Imagenes/The guy sprites/Ataque/Ataque_izquierda1.png",":/Imagenes/The guy sprites/Ataque/Ataque_izquierda2.png"};
    QString mGDeathRight[5] = {":/Imagenes/The guy sprites/Muerte/Muerte_derecha1.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha2.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha3.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha4.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha5.png"};
    QString mGDeathLeft[5] = {":/Imagenes/The guy sprites/Muerte/Muerte_izquierda1.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda2.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda3.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda4.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda5.png"};
    QString mGJumpRight[2] = {":/Imagenes/The guy sprites/Salto/Salto_derecha1.png",":/Imagenes/The guy sprites/Salto/Salto_derecha2.png"};
    QString mGJumpLeft[2] = {":/Imagenes/The guy sprites/Salto/Salto_izquierda1.png",":/Imagenes/The guy sprites/Salto/Salto_izquierda2.png"};
    QString mGSpown[6] = {":/Imagenes/The guy sprites/Spown/Spown1.png",":/Imagenes/The guy sprites/Spown/Spown2.png",":/Imagenes/The guy sprites/Spown/Spown3.png",":/Imagenes/The guy sprites/Spown/Spown4.png",":/Imagenes/The guy sprites/Spown/Spown5.png",":/Imagenes/The guy sprites/Spown/Spown6.png"};

    QString mSMoveRight[3] = {":/Imagenes/Steven Sprites/Movimiento/stevenU.png",":/Imagenes/Steven Sprites/Movimiento/stevenU_derecha2.png",":/Imagenes/Steven Sprites/Movimiento/stevenU_derecha3.png"};
    QString mSMoveLeft[3] = {":/Imagenes/Steven Sprites/Movimiento/stevenU_izquierdas.png",":/Imagenes/Steven Sprites/Movimiento/stevenU_izquierda2.png",":/Imagenes/Steven Sprites/Movimiento/stevenU_izquierda3.png"};
    QString mSAttackRight[3] = {":/Imagenes/Steven Sprites/Ataque/Ataque_derecha1.png",":/Imagenes/Steven Sprites/Ataque/Ataque_derecha2.png",":/Imagenes/Steven Sprites/Ataque/Ataque_derecha3.png"};
    QString mSAttackLeft[3] = {":/Imagenes/Steven Sprites/Ataque/Ataque_izquierda1.png",":/Imagenes/Steven Sprites/Ataque/Ataque_izquierda2.png",":/Imagenes/Steven Sprites/Ataque/Ataque_izquierda3.png"};
    QString mSDeathRight[5] = {":/Imagenes/Steven Sprites/Muerte/muerte_derecha1.png",":/Imagenes/Steven Sprites/Muerte/muerte_derecha2.png",":/Imagenes/Steven Sprites/Muerte/muerte_derecha3.png",":/Imagenes/Steven Sprites/Muerte/muerte_derecha4.png",":/Imagenes/Steven Sprites/Muerte/muerte_derecha5.png"};
    QString mSDeathLeft[5] = {":/Imagenes/Steven Sprites/Muerte/muerte_izquierda1.png",":/Imagenes/Steven Sprites/Muerte/muerte_izquierda2.png",":/Imagenes/Steven Sprites/Muerte/muerte_izquierda3.png",":/Imagenes/Steven Sprites/Muerte/muerte_izquierda4.png",":/Imagenes/Steven Sprites/Muerte/muerte_izquierda5.png"};
    QString mSJumpRight[5] = {":/Imagenes/Steven Sprites/Salto/salto_derecha1.png",":/Imagenes/Steven Sprites/Salto/salto_derecha2.png",":/Imagenes/Steven Sprites/Salto/salto_derecha4.png",":/Imagenes/Steven Sprites/Salto/salto_derecha3.png",":/Imagenes/Steven Sprites/Salto/salto_derecha5.png"};
    QString mSJumpLeft[5] = {":/Imagenes/Steven Sprites/Salto/salto_izquierda1.png",":/Imagenes/Steven Sprites/Salto/salto_izquierda2.png",":/Imagenes/Steven Sprites/Salto/salto_izquierda4.png",":/Imagenes/Steven Sprites/Salto/salto_izquierda3.png",":/Imagenes/Steven Sprites/Salto/salto_izquierda5.png"};


    QTimer *Spown, *Death, *Jump, *Attack;

    object *objeto;

    float Vx, Ay, Vy, k = 0.7;
    int pX,pY;
    int mMuerte = 0;
    short mMoveG[9], mMoveS[8], cont = 0;
    char l = 'n', ant, keyplayer = 'n';
    bool mPosG[9], mPosS[8], mJump, mDeath, ban, banAttack;
    bool mJumpUp, mJumpDown, mJumpP;

public slots:

    void updateSpown();
    void updateDeath();
    void updateAttack();
    void jump();

public:
    player(char k);
    void walkPlayer(short a);
    void walkGuy(short a);
    void walkSteven(short a);
    void stevenA();
    void cinematica();
    ~player();

    int getPX() const {return pX;}
    int getPY() const {return pY;}
    float getVx() const {return Vx;}
    float getAy() const {return Ay;}
    bool getJumpUp() const {return mJumpUp;}
    bool getJumpDown() const {return mJumpDown;}
    bool getJump() const {return mJump;}
    bool getmDeath() const {return mDeath;}
    int getMuerte() const {return mMuerte;}
    char getLado() const {return l;}
    char getKeyplayer() const {return keyplayer;}
    QTimer *getSpown() const {return Spown;}
    QTimer *getDeath() const {return Death;}
    QTimer *getLeap() const {return Jump;}
    object *getObjeto() const {return objeto;}


    void setPX(int value) {pX = value;}
    void setPY(int value) {pY = value;}
    void setVx(float value) {Vx = value;}
    void setAy(float value) {Ay = value;}
    void setJump(bool jump) {mJump = jump;}
    void setJumpUp(bool jumpUp) {mJumpUp = jumpUp;}
    void setJumpDown(bool jumpDown) {mJumpDown = jumpDown;}
    void setJumpP(bool jumpP) {mJumpP = jumpP;}
    void setMuerte(int muerte) {mMuerte = muerte;}
    void setBan(bool value) {ban = value;}
};

#endif // PLAYER_H
