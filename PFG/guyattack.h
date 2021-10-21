#ifndef GUYATTACK_H
#define GUYATTACK_H

#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QTimer>
#include <QString>

class guyattack: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    QString Attack[4] = {":/Imagenes/The guy sprites/Ataque/Ataque1.png",":/Imagenes/The guy sprites/Ataque/Ataque2.png",":/Imagenes/The guy sprites/Ataque/Ataque3.png",":/Imagenes/The guy sprites/Ataque/Ataque4.png"};
    QString AttackS[3] = {":/Imagenes/Steven Sprites/Ataque/Ataque1.png",":/Imagenes/Steven Sprites/Ataque/Ataque2.png",":/Imagenes/Steven Sprites/Ataque/Ataque3.png"};
    QTimer *aguy;
    char side, keyplayer = 'n';
    int range = 100, px,py, spt, tam = 25, cont = 0, vel = 15;
    int damage = 5;
    bool pos, ban;

public slots:

    void sprites();

public:
    guyattack(int _x, int _y, char lado, char k);
    QTimer *getAguy() const {return aguy;}
    bool getBan() const {return ban;}
    int getDamage() const {return damage;}
    void setBan(bool value) {ban = value;}
    ~guyattack();
};

#endif // GUYATTACK_H
