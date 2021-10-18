#ifndef SRAY_H
#define SRAY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QLabel>
#include <QRandomGenerator>
#include <QDebug>

class sray: public QObject, public QGraphicsPixmapItem //71 movimientos
{

    Q_OBJECT

private:

    QString move[5] = {":/Imagenes/Dj_Sray/DjSprey.png",":/Imagenes/Dj_Sray/DjSprey_Down.png",":/Imagenes/Dj_Sray/DJSprey_Left.png",":/Imagenes/Dj_Sray/DjSprey_Right.png",":/Imagenes/Dj_Sray/DjSprey_Up.png"};

    QString secuencias[28] = {"1","1","1","1","4","5","4","2","4","4","4","4","4","4","4","4","3","3","3","3","1","1","1","1",
                              "1","1","1","1"};

    QVector<QString> smoves;

    int contM = 0, contS = 0, pos = 0, l = 0;
    int px, py, tam = 250;
    int xl, yl, dato;
    bool bandance = false, banmove = false;
    QTimer *time, *timeL;
    QLabel *objeto;
    QString info;

public slots:

    void labelmove();
    void Atiempo();

public:
    sray(int x, int y, QLabel *obj);
    void label();
    void tiempo();
    void baile();
    ~sray() {delete objeto;}

    QVector<QString> getSmoves() const {return smoves;}
    bool getBanmove() const {return banmove;}

    void setBanmove(bool value) {banmove = value;}
    void setSmoves(const QVector<QString> &value) {smoves = value;}
};

#endif // SRAY_H
