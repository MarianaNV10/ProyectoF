#ifndef GUYATTACK_H
#define GUYATTACK_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include <QGraphicsScene>
#include <QString>

class guyattack: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:

    QString Attack[4] = {":/Imagenes/The guy sprites/Ataque/Ataque1.png",":/Imagenes/The guy sprites/Ataque/Ataque2.png",":/Imagenes/The guy sprites/Ataque/Ataque3.png",":/Imagenes/The guy sprites/Ataque/Ataque4.png"};
    QTimer *aguy;
    int range, px,py, spt, tam = 25;
    bool pos;

public slots:

    void sprites();

public:
    guyattack(int _x, int _y);
    ~guyattack();
    QTimer *getAguy() const;
};

#endif // GUYATTACK_H
