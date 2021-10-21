#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsLineItem>
#include <QRandomGenerator>
#include <QDesktopWidget>
#include <QKeyEvent>
#include <QMessageBox>
#include <QString>
#include <QPalette>
#include <QImage>
#include <qdebug.h>
#include <QMediaPlayer>
#include <QSound>

//Librerias propias
#include "levels.h"
#include "platform.h"
#include "spike.h"
#include "player.h"
#include "guyattack.h"
#include "enemigos.h"
#include "hammerattack.h"
#include "bills.h"
#include "billsattack.h"
#include "sray.h"

#include <fstream>

using namespace std;

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
    void Dificultad();
    void cargar_niveles(int Nivel);
    void clean_levels();
    void changeLevel();
    void validateAttackGuy();
    void validateAttackOneP();
    void validateAttackMultiP();
    void validatePlayerMove();
    void validateOnePMove();
    void validateMultiPMove();
    void validateBillsMove();
    void validateBMOneP();
    void validateBMMultiP();
    void validateHammerAttack();
    void validateHammerOneP();
    void validateHammerMultiP();
    void validateSrayMove();
    void validarmovimientosoneplayer(QKeyEvent *i);
    void validarmovimientosMultiP(QKeyEvent *i);
    void CollisionEnemy();
    void collisionEnemyOneP();
    void collisionEnemyMultiP();
    void escribirArchivo(QString nom, QString modoj, int nivel, char dif, char tipo, int x, int y, int Vidas, char tipo1, int x1, int y1, int Vidas1);
    void leerArchivo();
    void ActualizarArchivo();
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
    void on_instruccion_clicked();
    void on_regresar_clicked();
    void on_devolver_clicked();
    void on_selectguy_clicked();
    void on_selectsteven_clicked();
    void on_facil_clicked();
    void on_normal_clicked();
    void on_dificil_clicked();
    void on_cargarpartida_clicked();
    void on_actionGuardar_Partida_triggered();
    void on_actionPausar_triggered();
    void on_actionReanudar_triggered();
    void on_actionSalir_triggered();
    void on_actionInstrucciones_triggered();

private:

    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    player *player1;
    bills *jefe1;
    sray *jefe2;
    QGraphicsLineItem *lineUp,*lineDown,*lineRight,*lineLeft;

    QMediaPlayer *audio;
    QSound *reproducir;

    //OnePlayer
    QVector<QString> playermoves;
    QList<guyattack*> ataque;

    //MultiPlayer

    QList<player*> Jugadores;
    QList<guyattack*> ataque2; //steven
    QVector<QString> playermoves2;

    //Plataformas y Enemigos
    QList<platform*> walls;
    QList<spike*> spikes;
    QList<enemigos*> enemigosH;
    QList<hammerattack*> ataqueHammer;
    QList<billsattack*> ataquebills;


    QString posx,posy,width, height, WallType;
    QStringList list;

    QTimer *collisions;

    QPalette palette;

    char dificultad;
    int H=0, W=0;
    int X, Y, tamX, tamY;
    int numNivel = 0;
    bool iniciars = false, registro = false, onep = false, multip = false, banU = false;
    bool banDe = false, banDe2 = false, banUsuarioViejo = false, Guardar = false;
    bool banCargarP = false, cambionivel = false;
};
#endif // MAINWINDOW_H
