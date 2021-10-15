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

    QString bspown[3] = {":/Imagenes/Bills Sprites/Spown/Spown1.png",":/Imagenes/Bills Sprites/Spown/Spown3.png",":/Imagenes/Bills Sprites/Spown/Spown2.png"};
    QString bdeath[4] = {":/Imagenes/Bills Sprites/Muerte/Muerte1.png",":/Imagenes/Bills Sprites/Muerte/Muerte2.png",":/Imagenes/Bills Sprites/Muerte/Muerte3.png",":/Imagenes/Bills Sprites/Muerte/Muerte4.png"};
    QString bmove[5] = {":/Imagenes/Bills Sprites/batalla/batalla1.png",":/Imagenes/Bills Sprites/batalla/batalla2.png",":/Imagenes/Bills Sprites/batalla/batalla3.png",":/Imagenes/Bills Sprites/batalla/batalla4.png",":/Imagenes/Bills Sprites/batalla/batalla5.png"};
    QString battack[2] = {":/Imagenes/Bills Sprites/Ataque/Ataque1.png",":/Imagenes/Bills Sprites/Ataque/Ataque2.png"};

    QTimer *mSpown, *mDeath, *mMove, *mAttack;

    int px, py, vy, range = 600, tam = 250;
    short sprite[4];
    bool pos[4];
    bool banSpown, banDeath, banMove, banAttack;

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
    ~bills(){delete mMove;}
    //void randomMove();

    int getRange() const {return range;}
    int getPx() const {return px;}
    int getPy() const {return py;}
    bool getBanSpown() const {return banSpown;}
    bool getBanDeath() const {return banDeath;}
    bool getBanMove() const {return banMove;}
    bool getBanAttack() const {return banAttack;}
    QTimer *getSpown() const {return mSpown;}
    QTimer *getDeath() const {return mDeath;}
    QTimer *getMove() const {return mMove;}
    QTimer *getAttack() const {return mAttack;}

    void setBanSpown(bool value) {banSpown = value;}
    void setBanDeath(bool value) {banDeath = value;}
    void setBanMove(bool value) {banMove = value;}
    void setBanAttack(bool value) {banAttack = value;}
    void setVy(int value) {vy = value;}
};

#endif // BILLS_H
