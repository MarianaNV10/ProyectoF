#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    H = 708;
    W = 0;

    setup_resorces();
    player1 = new theguy();
//    player1->setKeys('L');

    numNivel=1;
    cargar_niveles(numNivel);

    collisions = new QTimer(this);
    connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
    collisions->start(25);
}

void MainWindow::setup_resorces()
{
    scene = new QGraphicsScene(this);

    scene->setSceneRect(W,0,1280-3,H);
    ui->graphicsView->setScene(scene);

    setWindowTitle("Gehrin");

    //para ponerle color a la letra al menubar
//    palette.setColor(ui->menubar->foregroundRole(), QColor(21,165,169));
//    ui->menubar->setPalette(palette);


    //Lineas de la escena
    lineUp = new QGraphicsLineItem(0,0,5120,0);
    lineDown = new QGraphicsLineItem(0,708,5120,708);
    lineRight = new QGraphicsLineItem(1280,0,1280,708);
    lineLeft = new QGraphicsLineItem(0,0,0,708);
}

void MainWindow::limpiar_niveles()
{
    for(int m = 0; m < walls.size(); m++){
        scene->removeItem(walls.at(m));
        scene->removeItem(spikes.at(m));
    }
    walls.clear();
    spikes.clear();
}

void MainWindow::cargar_niveles(int Nivel)
{
    QVector<QString> nivel;

    limpiar_niveles();

    if(Nivel == 1){ //Nivel 1

        scene->setBackgroundBrush(QPixmap(":/Imagenes/Fondos/Nivel1.jpeg"));

        //establece las posiciones del jugador dentro del nivel
        player1->setPosX(0);
        player1->setPosY(622);
        player1->setPos(0,622);
        scene->addItem(player1);

        //Aparición del jugador en la escena
        player1->getSpown()->start(300);

        nivel = LOne();

        for(int i = 0; i < nivel.size(); i++){
            list = nivel[i].split(',');
            for(int m = 0; m < list.size(); m++){
                switch (m) {
                case 0:
                    posx = list[m];
                    break;

                case 1:
                    posy = list[m];
                    break;

                case 2:
                    width = list[m];
                    break;

                case 3:
                    height = list[m];
                    break;

                case 4:
                    WallType = list[m];
                    break;
                }
            }

            X = posx.toInt();
            Y = posy.toInt();
            tamX = width.toInt();
            tamY = height.toInt();

            walls.push_back(new platform(X,Y,tamX,tamY));
            scene->addItem(walls.back());
        }
    }
    else if(Nivel == 2){ //Nivel 2

        //posicion del jugador en la escena

        scene->setBackgroundBrush(QPixmap(":/Imagenes/Fondos/Nivel2.jpeg"));
        nivel = LTwo();

        for(int i = 0; i < nivel.size(); i++){
            list = nivel[i].split(',');
            for(int m = 0; m < list.size(); m++){
                switch (m) {
                case 0:
                    posx = list[m];
                    break;

                case 1:
                    posy = list[m];
                    break;

                case 2:
                    width = list[m];
                    break;

                case 3:
                    height = list[m];
                    break;

                case 4:
                    WallType = list[m];
                    break;
                }
            }

            X = posx.toInt();
            Y = posy.toInt();
            tamX = width.toInt();
            tamY = height.toInt();

            if(WallType == 'F'){
                walls.push_back(new platform(X,Y,tamX,tamY));
                scene->addItem(walls.back());
            }else{
                spikes.push_back(new spike(X,Y,tamX,tamY));
                scene->addItem(spikes.back());
            }
        }
    }
    else{ //Nivel 3

    }
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{

    if(i->key() == Qt::Key_W){
        if(player1->getJump() == false){
            player1->walkPlayer('W');
        }
    }

    if(i->key() == Qt::Key_D){
        for(int i = 0; i < walls.size(); i++){
            if(player1->collidesWithItem(lineRight) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                player1->cinematica();
                break;
            }
        }
        player1->walkPlayer('D');
    }

    if(i->key() == Qt::Key_A){
        for(int i = 0; i < walls.size(); i++){
            if(player1->collidesWithItem(lineLeft) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                player1->cinematica();
                break;
            }
        }
        player1->walkPlayer('A');
    }
}

void MainWindow::detectC()
{
    if(player1->getJump()){
        for(int m = 0; m < walls.size(); m++){
            if(player1->getJumpDown()){ //organizar esta parte cuando el personaje va subiendo y choca con una plataforma
                if(player1->collidesWithItem(walls.at(m)) && player1->getPosY()){
                    player1->getLeap()->stop();
                    player1->setPosY(walls.at(m)->getPosY()-48);
                    player1->setPos(player1->getPosX(),player1->getPosY());
                    player1->setAy(11);
                    player1->setJump(false);
                    player1->setJumpUp(false);
                    player1->setJumpDown(false);
                    player1->setJumpP(false);
                    delete player1->getLeap();
                    break;
                }
            }
            else{
                if(player1->collidesWithItem(lineUp)){
                    player1->setAy(-1);
                }

                if(player1->getJumpUp() && player1->collidesWithItem(walls.at(m))){
//                    qDebug() << "Muro: " << walls.at(m)->getPosY()+walls.at(m)->getHeight() << endl;
//                    qDebug() << "Jugador: " << player1->getPosY()+50
                    player1->setAy(-1);
                }
            }
        }

        if(player1->collidesWithItem(lineLeft)){
            player1->setJumpP(false);
        }

        if(player1->collidesWithItem(lineDown)){
            //Cuando toque está linea colocar al jugardor en una posición adecuada según el nivel
            player1->setPosX(0);
            player1->setPosY(624);
            player1->setPos(0,624);
            player1->getLeap()->stop();
            player1->setAy(11);
            player1->setJump(false);
            player1->setJumpUp(false);
            player1->setJumpDown(false);
            player1->setJumpP(false);
            delete player1->getLeap();
        }
    }
    else{ //Revisar lo de caida libre
        for(int m = 0; m < walls.size(); m ++){
            if(player1->collidesWithItem(walls.at(m)) == false){
                if(m+1 == walls.size() && player1->getJumpDown() == false){
                    player1->setAy(-1);
                    player1->walkPlayer('W');
                }
            }
            else{
                break;
            }
        }

        if(player1->collidesWithItem(lineRight)){
            if(W < 5120){
                W += 1280;
                //qDebug() << W;
                scene->setSceneRect(W,0,1280-3,H);
                lineRight->setLine(W+1280,0,W+1280,708);
                lineLeft->setLine(W,0,W,708);
            }
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

