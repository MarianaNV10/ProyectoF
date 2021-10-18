#ifndef SRAY_H
#define SRAY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QVector>
#include <QLabel>

class sray: public QObject, public QGraphicsPixmapItem //71 movimientos
{

    Q_OBJECT

private:

    QString move[5] = {":/Imagenes/Dj_Sray/DjSprey.png",":/Imagenes/Dj_Sray/DjSprey_Down.png",":/Imagenes/Dj_Sray/DJSprey_Left.png",":/Imagenes/Dj_Sray/DjSprey_Right.png",":/Imagenes/Dj_Sray/DjSprey_Up.png"};
    QString movements[71] = {"Down","Up","Left","Right","Up","Left","Down","Down","Up","Right","Down","Down","Down",
                                  "Up","Left","Down","Down","Up","Up","Up","Down","Up","Down","Down","Up","Down","Up",
                                  "Right","Left","Right","Left","Up","Up","Up","Up","Up","Up","Left","Up","Down","Down",
                                  "Right","Down","Right","Rigth","Up","Right","Left","Left","Down","Left","Up","Up","Up",
                                  "Down","Down","Down","Left","Left","Left","Right","Right","Right","Up","Left","Right","Down",
                                  "Up","Down","Left","Right"};

    QString secuencias[28] = {"1","1","1","1","4","5","4","2","4","4","4","4","4","4","4","4","3","3","3","3","1","1","1","1",
                              "1","1","1","1"};

    int contM = 0, contS = 0;
    QTimer *time;
    QLabel *objeto;

public:
    sray(int x, int y, QLabel *obj);
    void label();
};

#endif // SRAY_H
