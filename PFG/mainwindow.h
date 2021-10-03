#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QString>
#include <QPalette>
#include <vector>
#include <qdebug.h>
#include "levels.h"
#include "platform.h"
#include "spike.h"
#include "theguy.h"
#include "guyattack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setup_resorces();
    void cargar_niveles(int Nivel);
    void limpiar_niveles();
    void personaje(int p);
    void keyPressEvent(QKeyEvent *i);
    ~MainWindow();

public slots:

    void detectC();

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    theguy *player1;
    QGraphicsLineItem *lineUp,*lineDown,*lineRight,*lineLeft;

    QList<platform*> walls;
    QList<spike*> spikes;
    QList<guyattack*> ataque;


    QString posx,posy,width, height, WallType;
    QStringList list;

    QTimer *collisions;

    QPalette palette;

    int H=0, W=0;
    int X, Y, tamX, tamY;
    int numNivel = 0;
};
#endif // MAINWINDOW_H
