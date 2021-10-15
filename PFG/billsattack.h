#ifndef BILLSATTACK_H
#define BILLSATTACK_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QRandomGenerator>
#include <QString>
#include <QTimer>

class billsattack: public QObject, public QGraphicsPixmapItem
{

    Q_OBJECT

private:

    QString flama[2] = {":/Imagenes/Bills Sprites/Ataque/Ataque3.png", ":/Imagenes/Bills Sprites/Ataque/Ataque4.png"};

    QTimer *time;

    int px, py, V, pyo;
    int cont = 0, sprite;
    float T;

public slots:

    void calculos();

public:
    billsattack(int x, int y);
    QTimer *getTime() const {return time;}
};

#endif // BILLSATTACK_H
