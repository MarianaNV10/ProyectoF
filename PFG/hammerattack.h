#ifndef HAMMERATTACK_H
#define HAMMERATTACK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QTimer>
#include <qdebug.h>
#include "object.h"

class hammerattack: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QString martillo = ":/Imagenes/Hammer/Ataque/martillo.png";
    QTimer *tiro;
    object *objeto;
    int damage = 0;
    int px, py, tam = 32, vel = 0;
    char side;

public slots:

    void lanzamiento();

public:
    hammerattack(int x, int y, char d);
    void parabola();
    ~hammerattack() {delete objeto;}
    int getDamage() const {return damage;}
    QTimer *getTiro() const {return tiro;}
    char getSide() const {return side;}
    void setSide(char value) {side = value;}
};

#endif // HAMMERATTACK_H
