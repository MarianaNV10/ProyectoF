#ifndef HUESOS_H
#define HUESOS_H

#include <QObject>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QString>
#include <QTransform>
#include "object.h"

class enemigos: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QString Right[5] = {":/Imagenes/Huesos Sprites/Caminar/Caminar_derecha.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_derecha2.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_derecha3.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_derecha4.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_derecha5.png"};
    QString Left[5] = {":/Imagenes/Huesos Sprites/Caminar/Caminar_izquierda.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_izquierda2.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_izquierda3.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_izquierda4.png",":/Imagenes/Huesos Sprites/Caminar/Caminar_izquierda5.png"};
    QString AttackRM1[4] = {":/Imagenes/Huesos Sprites/Ataque/Ataque_derecha.png",":/Imagenes/Huesos Sprites/Ataque/Ataque_derecha2.png",":/Imagenes/Huesos Sprites/Ataque/Ataque_derecha3.png",":/Imagenes/Huesos Sprites/Ataque/Ataque_derecha4.png"};
    QString AttackLM1[3] = {":/Imagenes/Huesos Sprites/Ataque/Ataque_izquierda4.png",":/Imagenes/Huesos Sprites/Ataque/Ataque_izquierda3.png",":/Imagenes/Huesos Sprites/Ataque/Ataque_izquierda2.png"};
    QString AttackM2[6] = {":/Imagenes/Huesos Sprites/Ataque/Ataque1.png",":/Imagenes/Huesos Sprites/Ataque/Ataque2.png",":/Imagenes/Huesos Sprites/Ataque/Ataque3.png",":/Imagenes/Huesos Sprites/Ataque/Ataque4.png",":/Imagenes/Huesos Sprites/Ataque/Ataque5.png",":/Imagenes/Huesos Sprites/Ataque/Ataque6.png"};
    QString HIdle[4] = {":/Imagenes/Huesos Sprites/Frente/Frente1.png",":/Imagenes/Huesos Sprites/Frente/Frente2.png",":/Imagenes/Huesos Sprites/Frente/Frente3.png",":/Imagenes/Huesos Sprites/Frente/Frente4.png"};
    QString Death[7] = {":/Imagenes/Huesos Sprites/Muerte/Muerte1.png",":/Imagenes/Huesos Sprites/Muerte/Muerte2.png",":/Imagenes/Huesos Sprites/Muerte/Muerte3.png",":/Imagenes/Huesos Sprites/Muerte/Muerte4.png",":/Imagenes/Huesos Sprites/Muerte/Muerte5.png",":/Imagenes/Huesos Sprites/Muerte/Muerte6.png",":/Imagenes/Huesos Sprites/Muerte/Muerte7.png"};
    QString Win[2] = {":/Imagenes/Huesos Sprites/Win/win1.png",":/Imagenes/Huesos Sprites/Win/win2.png"};

    QString HammerRight[8] = {":/Imagenes/Hammer/Movimiento/hammer_bro_der1.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der2.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der3.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der4.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der5.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der6.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der7.png",":/Imagenes/Hammer/Movimiento/hammer_bro_der8.png"};
    QString HammerLeft[8] = {":/Imagenes/Hammer/Movimiento/hammer_bro_izq.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq2.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq3.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq4.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq5.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq6.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq7.png",":/Imagenes/Hammer/Movimiento/hammer_bro_izq8.png"};
    QString HammerAttack[9] = {":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der1.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der2.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der3.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der4.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der5.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der6.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der7.png",":/Imagenes/Hammer/Ataque/hammer_bro_ataque_der8.png"};

    QTimer *Move, *Idle, *Attack, *EnemigoD, *EnemigoW;

    object *objeto;

    unsigned int Vidas = 0, tam = 65;
    float k = 0.7; //Constante de restitución
    int px, py, Vx, rango = 50, At = 0, Id = 0, radioHmm = 500;
    short sprite[8], spriteHm[3];
    bool pos[8], posHm[3], banMove, banIdle, banAttack, banD, banAttackHammer, banDeath;
    char move = 'n', type = 'n';

public slots:

    void movimiento();
    void HuesosIdle();
    void EnemigoAttack();
    //void HuesosWin();
    void HuesosDeath();


public:
    enemigos(int x, int y, char t);
    void ataque();
    void mover();
    void muerte();
    void idle();
    ~enemigos();

    int getPx() const {return px;}
    int getPy() const {return py;}
    int getVx() const {return Vx;}
    int getRango() const {return rango;}
    int getRadioHmm() const {return radioHmm;}
    unsigned int getVidas() const {return Vidas;}
    char getmMove() const {return move;}
    char getType() const {return type;}
    bool getBanMove() const {return banMove;}
    bool getBanIdle() const {return banIdle;}
    bool getBanAttack() const {return banAttack;}
    bool getBanD() const {return banD;}
    bool getBanDeath() const {return banDeath;}
    QTimer *getMove() const {return Move;}
    QTimer *getIdle() const {return Idle;}
    QTimer *getAttack() const {return Attack;}
    QTimer *getEnemigoD() const {return EnemigoD;}
    QTimer *getEnemigoW() const {return EnemigoW;}
    object *getObjeto() const {return objeto;}

    void setPx(int value) {px = value;}
    void setPy(int value) {py = value;}
    void setVx(int value) {Vx = value;}
    void setVidas(unsigned int value) {Vidas = value;}
    void setIdle(QTimer *value) {Idle = value;}
    void setMove(char value) {move = value;}
    void setBanMove(bool value) {banMove = value;}
    void setBanIdle(bool value) {banIdle = value;}
    void setBanAttack(bool value) {banAttack = value;}
    void setBanD(bool value) {banD = value;}
    void setBanDeath(bool value) {banDeath = value;}
};

#endif // HUESOS_H
