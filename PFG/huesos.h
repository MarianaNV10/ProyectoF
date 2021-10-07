#ifndef HUESOS_H
#define HUESOS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QTimer>
#include <QString>
#include <QTransform>

class huesos: public QObject, public QGraphicsPixmapItem
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

    QTimer *Move, *Idle, *Attack, *HuesosD, *HuesosW;

    unsigned int Vidas = 0, tam = 65;
    int px, py, Vx, rango = 50, At = 0, Id = 0;
    short sprite[8];
    bool pos[8], banMove, banIdle, banAttack;
    char move = 'n';

public slots:

    void movimiento();
    void HuesosIdle();
    void HuesosAttack();
    //void HuesosWin();
    //void HuesosDeath();

public:
    huesos(int x, int y);
    void ataque();
    void mover();
    void idle();
    //void validarespacio();
    //~huesos();

    int getPx() const {return px;}
    int getPy() const {return py;}
    int getVx() const {return Vx;}
    int getRango() const {return rango;}
    unsigned int getVidas() const {return Vidas;}
    char getmMove() const {return move;}
    bool getBanMove() const {return banMove;}
    bool getBanIdle() const {return banIdle;}
    bool getBanAttack() const {return banAttack;}
    QTimer *getMove() const {return Move;}
    QTimer *getIdle() const {return Idle;}
    QTimer *getAttack() const {return Attack;}
    QTimer *getHuesosD() const {return HuesosD;}
    QTimer *getHuesosW() const {return HuesosW;}

    void setPx(int value) {px = value;}
    void setPy(int value) {py = value;}
    void setVx(int value) {Vx = value;}
    void setVidas(unsigned int value) {Vidas = value;}
    void setIdle(QTimer *value) {Idle = value;}
    void setMove(char value) {move = value;}
    void setBanMove(bool value) {banMove = value;}
    void setBanIdle(bool value) {banIdle = value;}
    void setBanAttack(bool value) {banAttack = value;}
};

#endif // HUESOS_H
