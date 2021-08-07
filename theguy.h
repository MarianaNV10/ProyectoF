#ifndef THEGUY_H
#define THEGUY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QString>
#include <QTimer>

class theguy: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

public:

    theguy();

public slots:

    void updateSpown();
    void updateDeath();

private:

    QString mMoveRight[4] = {":/Imagenes/The guy sprites/Movimiento/Derecha1.png",":/Imagenes/The guy sprites/Movimiento/Derecha2.png",":/Imagenes/The guy sprites/Movimiento/Derecha3.png",":/Imagenes/The guy sprites/Movimiento/Derecha4.png"};
    QString mMoveLeft[4] = {":/Imagenes/The guy sprites/Movimiento/Izquierda1.png",":/Imagenes/The guy sprites/Movimiento/Izquierda2.png",":/Imagenes/The guy sprites/Movimiento/Izquierda3.png",":/Imagenes/The guy sprites/Movimiento/Izquierda4.png"};
    QString mAttackRight[4] = {":/Imagenes/The guy sprites/Ataque/Ataque_derecha1.png",":/Imagenes/The guy sprites/Ataque/Ataque_derecha2.png"};
    QString mAttackLeft[4] = {":/Imagenes/The guy sprites/Ataque/Ataque_izquierda1.png",":/Imagenes/The guy sprites/Ataque/Ataque_izquierda2.png"};
    QString mDeathRight[5] = {":/Imagenes/The guy sprites/Muerte/Muerte_derecha1.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha2.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha3.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha4.png",":/Imagenes/The guy sprites/Muerte/Muerte_derecha5.png"};
    QString mDeathLeft[5] = {":/Imagenes/The guy sprites/Muerte/Muerte_izquierda1.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda2.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda3.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda4.png",":/Imagenes/The guy sprites/Muerte/Muerte_izquierda5.png"};
    QString mJumpRight[3] = {":/Imagenes/The guy sprites/Salto/Salto_derecha1.png",":/Imagenes/The guy sprites/Salto/Salto_derecha2.png",":/Imagenes/The guy sprites/Salto/Salto_derecha3.png"};
    QString mJumpLeft[3] = {":/Imagenes/The guy sprites/Salto/Salto_izquierda1.png",":/Imagenes/The guy sprites/Salto/Salto_izquierda2.png",":/Imagenes/The guy sprites/Salto/Salto_izquierda3.png"};
    QString mSpown[6] = {":/Imagenes/The guy sprites/Spown/Spown1.png",":/Imagenes/The guy sprites/Spown/Spown2.png",":/Imagenes/The guy sprites/Spown/Spown3.png",":/Imagenes/The guy sprites/Spown/Spown4.png",":/Imagenes/The guy sprites/Spown/Spown5.png",":/Imagenes/The guy sprites/Spown/Spown6.png"};

    QTimer *Spown;
    QTimer *Death;

    float posX, posY, Vx, Vy, Ax, Ay;
    short mMove[9], mMoveX, mMoveY;
    bool mCurrentImag[9];
    int mPastImage = -1;



};

#endif // THEGUY_H
