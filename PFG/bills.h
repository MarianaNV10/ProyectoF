#ifndef BILLS_H
#define BILLS_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QTimer>

class bills: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QString bspown[3] = {":/Imagenes/Bills_Sprites/Spown/Spown1.png",":/Imagenes/Bills_Sprites/Spown/Spown3.png",":/Imagenes/Bills_Sprites/Spown/Spown2.png"};
    QString bdeath[4] = {":/Imagenes/Bills_Sprites/Muerte/Muerte1.png",":/Imagenes/Bills_Sprites/Muerte/Muerte2.png",":/Imagenes/Bills_Sprites/Muerte/Muerte3.png",":/Imagenes/Bills_Sprites/Muerte/Muerte4.png"};
    QString bmove[5] = {":/Imagenes/Bills_Sprites/batalla/batalla1.png",":/Imagenes/Bills_Sprites/batalla/batalla2.png",":/Imagenes/Bills_Sprites/batalla/batalla3.png",":/Imagenes/Bills_Sprites/batalla/batalla4.png",":/Imagenes/Bills_Sprites/batalla/batalla5.png"};
    QString battack[2] = {":/Imagenes/Bills_Sprites/Ataque/Ataque1.png",":/Imagenes/Bills_Sprites/Ataque/Ataque2.png"};

    QTimer *mSpown, *mDeath, *mMove, *mAttack;

    int px, py, vy, range = 900, tam = 250, vida = 25;
    short sprite[4];
    bool pos[4];
    bool banSpown, banDeath, banMove, banAttack, banDis;

public slots:

    void billsSpown();
    void billsMove();
    void billsAttack();
    void billsDeath();

public:
    bills(int x, int y);
    void spown();
    void movement();
    void attack();
    void death();
    //void randomMove();

    int getRange() const {return range;}
    int getPx() const {return px;}
    int getPy() const {return py;}
    int getVida() const {return vida;}
    bool getBanSpown() const {return banSpown;}
    bool getBanDeath() const {return banDeath;}
    bool getBanMove() const {return banMove;}
    bool getBanAttack() const {return banAttack;}
    bool getBanDis() const {return banDis;}
    QTimer *getSpown() const {return mSpown;}
    QTimer *getDeath() const {return mDeath;}
    QTimer *getMove() const {return mMove;}
    QTimer *getAttack() const {return mAttack;}

    void setBanSpown(bool value) {banSpown = value;}
    void setBanDeath(bool value) {banDeath = value;}
    void setBanMove(bool value) {banMove = value;}
    void setBanAttack(bool value) {banAttack = value;}
    void setVy(int value) {vy = value;}
    void setVida(int value) {vida = value;}
    void setBanDis(bool value) {banDis = value;}
};

#endif // BILLS_H
