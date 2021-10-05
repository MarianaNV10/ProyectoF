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
    player1 = new player('g');
    //player1 = new player('s');

    numNivel = 1;
    cargar_niveles(numNivel);

    collisions = new QTimer(this);
    connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
    collisions->start(25);
}

void MainWindow::setup_resorces()
{
    scene = new QGraphicsScene(this);

    scene->setSceneRect(W,0,ui->graphicsView->width()-3,H);
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

void MainWindow::clean_levels()
{
    for(int m = 0; m < walls.size(); m++){
        scene->removeItem(walls.at(m));
        walls.erase(walls.begin()+m);
        m -= 1;
    }
    for(int f = 0; f < spikes.size(); f++){
        scene->removeItem(spikes.at(f));
        spikes.erase(spikes.begin()+f);
        f -= 1;
    }
    for(int b = 0; b < ataque.size(); b++){
        ataque.erase(ataque.begin()+b);
        b--;
    }
    walls.clear();
    spikes.clear();
    ataque.clear();
}

void MainWindow::cargar_niveles(int Nivel)
{
    QVector<QString> nivel;

    clean_levels();

    if(Nivel == 1){ //Nivel 1

        scene->setBackgroundBrush(QPixmap(":/Imagenes/Fondos/Nivel1.jpeg"));

        //establece las posiciones del jugador dentro del nivel
        player1->setPX(0);
        player1->setPY(623);
        player1->setPos(player1->getPX(),player1->getPY());
        scene->addItem(player1);

        //Aparición del jugador en la escena
        player1->getSpown()->start(250);
        //player1->stevenA();

        //Enemigo a Escena
        enemigoH = new huesos(150,607);
        enemigoH->setPos(150,607);
        scene->addItem(enemigoH);

        enemigoH->setIdle(new QTimer);
        connect(enemigoH->getIdle(), SIGNAL(timeout()), enemigoH, SLOT(HuesosIdle()));
        enemigoH->getIdle()->start(500);

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

void MainWindow::validateAttackGuy()
{
    if(!ataque.empty()){
        for(int it = 0; it < ataque.size(); it++){
            for(int p = 0; p < walls.size(); p++){
                if((ataque.at(it)->collidesWithItem(walls.at(p))) || (ataque.at(it)->collidesWithItem(lineLeft)) || (ataque.at(it)->collidesWithItem(lineRight))){
                    ataque.at(it)->getAguy()->stop();
                    if(ataque.at(it)->scene() == scene){
                        scene->removeItem(ataque.at(it));
                    }
                    ataque.erase(ataque.begin()+it);
                    break;
                }
            }
        }
    }
}

void MainWindow::validatePlayerMove()
{
    if(player1->getJump()){
        for(int m = 0; m < walls.size(); m++){

            if(player1->getJumpUp() && player1->collidesWithItem(walls.at(m))){ //Revisar esta parte
//                player1->setPY(player1->getPY()+15);
//                player1->setPos(player1->getPX(),player1->getPY());
                player1->setAy(-1);
//                    qDebug() << "Muro: " << walls.at(m)->getPosY()+walls.at(m)->getHeight() << endl;
//                    qDebug() << "Jugador: " << 21+player1->getPY() << endl;

            }

            if(player1->getJumpDown() && player1->collidesWithItem(walls.at(m))){
                player1->getLeap()->stop();
                player1->setPY(walls.at(m)->getPosY()-49);
                player1->setPos(player1->getPX(),player1->getPY());
                player1->setAy(11);
                player1->setJump(false);
                player1->setJumpUp(false);
                player1->setJumpDown(false);
                player1->setJumpP(false);
                //delete player1->getLeap();
                break;
            }

            if(player1->collidesWithItem(lineUp)){
                player1->setAy(-1);
            }
        }

        if(player1->collidesWithItem(lineLeft)){
            player1->setJumpP(false);
        }

        if(player1->collidesWithItem(lineDown)){
            //Cuando toque está linea colocar al jugador en una posición adecuada según el nivel
            player1->setPX(0);
            player1->setPY(623); //ORGANIZAR ESTA PARTE EN UNA POSICION ADECUADA A DONDE SE ENCUENTRE EL JUGADOR
            player1->setPos(0,623);
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
            if(W+1280 < 5120){
                W += 1280;
                scene->setSceneRect(W,0,ui->graphicsView->width()-3,H);
                lineRight->setLine(W+1280,0,W+1280,708);
                lineLeft->setLine(W,0,W,708);
            }
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent *i)
{

    if(i->key() == Qt::Key_W || i->key() == Qt::Key_I){
        if(player1->getJump() == false){
            player1->walkPlayer('W');
            //player1->walkPlayer('I');
        }
    }

    if(i->key() == Qt::Key_D || i->key() == Qt::Key_L){
        for(int i = 0; i < walls.size(); i++){
            if(player1->collidesWithItem(lineRight) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                player1->cinematica();
                break;
            }
        }
        player1->walkPlayer('D');
        //player1->walkPlayer('L');
    }

    if(i->key() == Qt::Key_A || i->key() == Qt::Key_J){
        for(int i = 0; i < walls.size(); i++){
            if(player1->collidesWithItem(lineLeft) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                player1->cinematica();
                break;
            }
        }
        player1->walkPlayer('A');
        //player1->walkPlayer('J');
    }

    if(i->key() == Qt::Key_Space){
        player1->walkPlayer('T');
        ataque.push_back(new guyattack(player1->getPX(), player1->getPY(), player1->getLado(),'g'));
        //ataque.push_back(new guyattack(player1->getPX(), player1->getPY(), player1->getLado(),'s'));
        scene->addItem(ataque.at(ataque.size()-1));
        ataque.at(ataque.size()-1)->getAguy()->start(75);
    }
}

void MainWindow::detectC()
{
    validateAttackGuy();
    validatePlayerMove();
}

MainWindow::~MainWindow()
{
    clean_levels();
    delete ui;
    delete scene;
    delete player1;
    delete enemigoH;
    delete collisions;
}

