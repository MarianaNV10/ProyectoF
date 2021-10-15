#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QString>
#include <QPalette>
#include <QImage>
#include <vector>
#include <qdebug.h>
#include <math.h>
#include "levels.h"
#include "platform.h"
#include "spike.h"
#include "player.h"
#include "guyattack.h"
#include "enemigos.h"
#include "hammerattack.h"
#include "bills.h"
#include "billsattack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    void setup_interfaz();
    void inicio();
    void setup_resorces();
    void setup_enemies();
    void cargar_niveles(int Nivel);
    void validateAttackGuy();
    void validatePlayerMove();
    void validateBillsMove();
    void validateHammerAttack();
    void clean_levels();
    void CollisionEnemy();
    void keyPressEvent(QKeyEvent *i);
    ~MainWindow();

public slots:

    void detectC();

private slots:
    void on_iniciarsesion_clicked();

    void on_registrarse_clicked();

    void on_cancelar_clicked();

    void on_aceptar_clicked();

    void on_nuevapartida_clicked();

    void on_oneplayer_clicked();

    void on_multiplayer_clicked();

private:

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    player *player1;
    bills *jefe1;
    QGraphicsLineItem *lineUp,*lineDown,*lineRight,*lineLeft;

    QList<platform*> walls;
    QList<spike*> spikes;
    QList<guyattack*> ataque;
    QList<enemigos*> enemigosH;
    QList<hammerattack*> ataqueHammer;
    QList<billsattack*> ataquebills;
    QString posx,posy,width, height, WallType;
    QStringList list;

    QTimer *collisions;

    QPalette palette;

    int H=0, W=0;
    int X, Y, tamX, tamY;
    int numNivel = 0;
    bool iniciars = false, registro = false;
};
#endif // MAINWINDOW_H
