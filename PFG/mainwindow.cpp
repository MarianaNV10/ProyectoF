#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    H = 708;
    W = 0;

    // para el inicio del juego
    setup_interfaz();
    inicio();

    reproducir = new QSound(":/Imagenes/Audio/Intro.wav");
    reproducir->play();
    reproducir->setLoops(QSound::Infinite);
}

void MainWindow::setup_interfaz() // Función para la creación de los recursos usados en la interfaz con el usuario
{
    scene = new QGraphicsScene(this);
    setMaximumSize(800,600);
    setMaximumSize(800,600);
    ui->graphicsView->setGeometry(0,0,800,600);
    scene->setSceneRect(0,0,ui->graphicsView->width()-3,ui->graphicsView->height()-3);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(QPixmap(":/Imagenes/Interfaz/fondoinicio.jpg"));
    setWindowTitle("Gehrin");

    //para ponerle color a la letra al menubar
    palette.setColor(ui->menubar->foregroundRole(), QColor(21,165,169));
    ui->menubar->setPalette(palette);
}

void MainWindow::inicio() // Función para la interfaz con el usuario
{
    ui->inicio->show();

    ui->inicio->setGeometry(80,300,ui->inicio->width(),ui->inicio->height());
    ui->dificultad->setGeometry(80,300,ui->dificultad->width(),ui->dificultad->height());
    ui->Partida->setGeometry(80,300,ui->Partida->width(),ui->Partida->height());
    ui->modojuego->setGeometry(80,300,ui->modojuego->width(),ui->modojuego->height());
    ui->usuario->setGeometry(80,300,ui->usuario->width(),ui->usuario->height());
    ui->personaje->setGeometry(80,300,ui->personaje->width(),ui->personaje->height());
    ui->instruccion->setGeometry(610,300,ui->instruccion->width(),ui->instruccion->height());
    ui->nota->setGeometry(540,300,ui->nota->width(),ui->nota->height());
    ui->Muertes->setGeometry(40,0,ui->Muertes->width(),ui->Muertes->height());

    ui->inicio->setStyleSheet("QGroupBox {border: transparent}");
    ui->dificultad->setStyleSheet("QGroupBox {border: transparent}");
    ui->Partida->setStyleSheet("QGroupBox {border: transparent}");
    ui->modojuego->setStyleSheet("QGroupBox {border: transparent}");
    ui->usuario->setStyleSheet("QGroupBox {border: transparent}");
    ui->personaje->setStyleSheet("QGroupBox {border: transparent}");
    ui->nota->setStyleSheet("QGroupBox {border: transparent}");
    ui->Muertes->setStyleSheet("QGroupBox {border: transparent}");

    palette.setColor(ui->iniciarsesion->foregroundRole(), QColor(0,0,0));
    ui->iniciarsesion->setPalette(palette);
    ui->registrarse->setPalette(palette);
    ui->Partida->setPalette(palette);
    ui->dificultad->setPalette(palette);
    ui->modojuego->setPalette(palette);
    ui->usuario->setPalette(palette);
    ui->personaje->setPalette(palette);
    ui->instruccion->setPalette(palette);
    ui->nota->setPalette(palette);

    ui->dificultad->hide();
    ui->modojuego->hide();
    ui->Partida->hide();
    ui->usuario->hide();
    ui->personaje->hide();
    ui->instruccion->hide();
    ui->nota->hide();
    ui->baile->hide();
    ui->Muertes->hide();
}

void MainWindow::setup_resorces() // Función para establecer los recursos de las dimensiones del juego
{
    if(cambionivel == false){scene = new QGraphicsScene(this);}
    setMinimumSize(1283,750);
    setMaximumSize(1283,750);
    setGeometry(30,30,1283,750); //en general para el juego //1283
    ui->graphicsView->setGeometry(0,0,1280,711);

    scene->setSceneRect(W,0,ui->graphicsView->width()-3,H-3);
    ui->graphicsView->setScene(scene);

    ui->inicio->hide();
    ui->dificultad->hide();
    ui->modojuego->hide();
    ui->Partida->hide();
    ui->usuario->hide();
    ui->personaje->hide();
    ui->instruccion->hide();
    ui->nota->hide();
    ui->baile->hide();

    //Lineas de la escena
    lineUp = new QGraphicsLineItem(0,0,5120,0);
    lineDown = new QGraphicsLineItem(0,708,5120,708);
    lineRight = new QGraphicsLineItem(W+1280,0,W+1280,708);
    lineLeft = new QGraphicsLineItem(W,0,W,708);
}

void MainWindow::setup_enemies() // Función que permite la creación de los enemigos que se encuentran en cada nivel
{
    switch (numNivel) {
    case 1:
        for(int p = 0; p < walls.size(); p++){
            if(walls.at(p)->getPosX() != 0){
                if((walls.at(p)->getPosX() == 779 && walls.at(p)->getPosY() == 348) || (walls.at(p)->getPosX() == 1067 && walls.at(p)->getPosY() == 449) ||
                    (walls.at(p)->getPosX() == 1780 && walls.at(p)->getPosY() == 372) || (walls.at(p)->getPosX() == 2508 && walls.at(p)->getPosY() == 372) ||
                    (walls.at(p)->getPosX() == 2032 && walls.at(p)->getPosY() == 224)){

                    if(walls.at(p)->getPosX() == 2032 && walls.at(p)->getPosY() == 224){
                        enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+81,walls.at(p)->getPosY()-64,'b'));
                        scene->addItem(enemigosH.at(enemigosH.size()-1));
                        enemigosH.at(enemigosH.size()-1)->idle();
                        enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+369,walls.at(p)->getPosY()-64,'m'));
                        scene->addItem(enemigosH.at(enemigosH.size()-1));
                        enemigosH.at(enemigosH.size()-1)->setMove('D');
                        enemigosH.at(enemigosH.size()-1)->setBanMove(true);
                        enemigosH.at(enemigosH.size()-1)->mover();
                        enemigosH.at(enemigosH.size()-1)->setBanD(true);
                    }
                    else{
                        enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+0.5*walls.at(p)->getWidth(),walls.at(p)->getPosY()-64,'b'));
                        scene->addItem(enemigosH.at(enemigosH.size()-1));
                        enemigosH.at(enemigosH.size()-1)->idle();
                    }
                }
                else if((walls.at(p)->getPosX() == 1139 && walls.at(p)->getPosY() == 200) || (walls.at(p)->getPosX() == 3376 && walls.at(p)->getPosY() == 416) ||
                        (walls.at(p)->getPosX() == 2032 && walls.at(p)->getPosY() == 224)){

                    enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+0.5*walls.at(p)->getWidth(),walls.at(p)->getPosY()-64,'m'));
                    scene->addItem(enemigosH.at(enemigosH.size()-1));
                    enemigosH.at(enemigosH.size()-1)->setMove('D');
                    enemigosH.at(enemigosH.size()-1)->setBanMove(true);
                    enemigosH.at(enemigosH.size()-1)->mover();
                    enemigosH.at(enemigosH.size()-1)->setBanD(true);
                }
            }
        }
        break;

    case 2:

        for(int p = 0; p < walls.size(); p++){
            if((walls.at(p)->getPosX() == 1294 && walls.at(p)->getPosY() == 424) || (walls.at(p)->getPosX() == 1674 && walls.at(p)->getPosY() == 424) ||
                (walls.at(p)->getPosX() == 2059 && walls.at(p)->getPosY() == 424) || (walls.at(p)->getPosX() == 3554 && walls.at(p)->getPosY() == 566)){
                if(walls.at(p)->getPosX() == 3554 && walls.at(p)->getPosY() == 566){
                    enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+74,walls.at(p)->getPosY()-64,'b'));
                    enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+218,walls.at(p)->getPosY()-64,'b'));
                    scene->addItem(enemigosH.at(enemigosH.size()-1));
                    scene->addItem(enemigosH.at(enemigosH.size()-2));
                    enemigosH.at(enemigosH.size()-1)->idle();
                    enemigosH.at(enemigosH.size()-2)->idle();
                }
                else{
                    enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+0.5*walls.at(p)->getWidth(),walls.at(p)->getPosY()-64,'b'));
                    scene->addItem(enemigosH.at(enemigosH.size()-1));
                    enemigosH.at(enemigosH.size()-1)->idle();
                }
            }
            else if((walls.at(p)->getPosX() == 416 && walls.at(p)->getPosY() == 541) || (walls.at(p)->getPosX() == 2418 && walls.at(p)->getPosY() == 348) ||
                    (walls.at(p)->getPosX() == 3534 && walls.at(p)->getPosY() == 218)){
                enemigosH.push_back(new enemigos(walls.at(p)->getPosX()+0.5*walls.at(p)->getWidth(),walls.at(p)->getPosY()-64,'m'));
                scene->addItem(enemigosH.at(enemigosH.size()-1));
                enemigosH.at(enemigosH.size()-1)->setMove('D');
                enemigosH.at(enemigosH.size()-1)->setBanMove(true);
                enemigosH.at(enemigosH.size()-1)->mover();
                enemigosH.at(enemigosH.size()-1)->setBanD(true);
            }
        }
        break;
    }

}

void MainWindow::Dificultad() // Función que establece la vida de los enemigos acorde a la dificultad del juego
{
    for(int e = 0; e < enemigosH.size(); e++){
        if(dificultad == 'f'){enemigosH.at(e)->setVidas(10);}
        else if(dificultad == 'n'){enemigosH.at(e)->setVidas(20);}
        else{enemigosH.at(e)->setVidas(30);}
    }
}

void MainWindow::clean_levels() //Función que permite limpiar los recursos que se usan en los diferentes niveles
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
        scene->removeItem(ataque.at(b));
        ataque.erase(ataque.begin()+b);
        b--;
    }
    for(int b = 0; b < ataque2.size(); b++){
        scene->removeItem(ataque2.at(b));
        ataque2.erase(ataque2.begin()+b);
        b--;
    }
    for(int h = 0; h < enemigosH.size(); h++){
        scene->removeItem(enemigosH.at(h));
        enemigosH.erase(enemigosH.begin()+h);
        h--;
    }
    for(int hm = 0; hm < ataqueHammer.size();hm++){
        scene->removeItem(ataqueHammer.at(hm));
        ataqueHammer.erase(ataqueHammer.begin()+hm);
        hm--;
    }
    for(int ab = 0; ab < ataquebills.size(); ab++){
        scene->removeItem(ataquebills.at(ab));
        ataquebills.erase(ataquebills.begin()+ab);
        ab--;
    }
    walls.clear();
    spikes.clear();
    ataque.clear();
    ataque2.clear();
    enemigosH.clear();
    ataqueHammer.clear();
    ataquebills.clear();
}

void MainWindow::changeLevel() //Función para cambiar de niveles
{
    if(numNivel == 1){
        if(jefe1->getVida() == 0){
            cambionivel = true;

            if(jefe1->scene() == scene){scene->removeItem(jefe1);}
            ui->Muertes->hide();

            collisions->stop();
            delete collisions;
            delete lineDown;
            delete lineLeft;
            delete lineRight;
            delete lineUp;

            W = 0;
            numNivel = 2;

            if(onep){
                char tipo;
                tipo = player1->getKeyplayer();
                int muerte = player1->getMuerte();
                if(player1->getKeyplayer() == 'g'){
                    ui->Muertes->show();
                    ui->muertesguy->display(player1->getMuerte());
                    ui->muertessteven->hide();
                    ui->msteven->hide();
                }
                else{
                    ui->Muertes->show();
                    ui->muertessteven->display(player1->getMuerte());
                    ui->mguy->hide();
                    ui->muertesguy->hide();
                }
                delete player1;
                player1 = new player(tipo);
                player1->setMuerte(muerte);
            }
            else{
                int muertes, muertes2;
                ui->Muertes->show();
                ui->muertesguy->display(Jugadores.at(0)->getMuerte());
                ui->muertessteven->display(Jugadores.at(1)->getMuerte());
                muertes = Jugadores.at(0)->getMuerte();
                muertes2 = Jugadores.at(1)->getMuerte();

                for(int j = 0; j < Jugadores.size(); j++){
                    scene->removeItem(Jugadores.at(j));
                    Jugadores.erase(Jugadores.begin()+j);
                    j--;
                }
                Jugadores.push_back(new player('g'));
                Jugadores.at(Jugadores.size()-1)->setMuerte(muertes);
                Jugadores.push_back(new player('s'));
                Jugadores.at(Jugadores.size()-1)->setMuerte(muertes2);
            }

            setup_resorces();
            cargar_niveles(numNivel);
            Guardar = true;
            ActualizarArchivo();

            collisions = new QTimer(this);
            connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
            collisions->start(50);
            setup_enemies();
            Dificultad();
            cambionivel = false;
        }
    }
    else if(numNivel == 2){
        if(onep){
            if(player1->getPX() >= 4937 && player1->getPX() < 5120){
                cambionivel = true;
                ui->Muertes->hide();

                collisions->stop();
                delete collisions;
                delete lineDown;
                delete lineLeft;
                delete lineRight;
                delete lineUp;

                W = 0;
                numNivel = 3;

                if(onep){
                    char tipo;
                    tipo = player1->getKeyplayer();
                    int muerte = player1->getMuerte();
                    if(player1->getKeyplayer() == 'g'){
                        ui->Muertes->show();
                        ui->muertesguy->display(player1->getMuerte());
                        ui->muertessteven->hide();
                        ui->msteven->hide();
                    }
                    else{
                        ui->Muertes->show();
                        ui->muertessteven->display(player1->getMuerte());
                        ui->mguy->hide();
                        ui->muertesguy->hide();
                    }
                    delete player1;
                    player1 = new player(tipo);
                    player1->setMuerte(muerte);
                }
                else{
                    int muertes, muertes2;
                    ui->Muertes->show();
                    ui->muertesguy->display(Jugadores.at(0)->getMuerte());
                    ui->muertessteven->display(Jugadores.at(1)->getMuerte());
                    muertes = Jugadores.at(0)->getMuerte();
                    muertes2 = Jugadores.at(1)->getMuerte();

                    for(int j = 0; j < Jugadores.size(); j++){
                        scene->removeItem(Jugadores.at(j));
                        Jugadores.erase(Jugadores.begin()+j);
                        j--;
                    }
                    Jugadores.push_back(new player('g'));
                    Jugadores.at(Jugadores.size()-1)->setMuerte(muertes);
                    Jugadores.push_back(new player('s'));
                    Jugadores.at(Jugadores.size()-1)->setMuerte(muertes2);
                }

                setup_resorces();
                cargar_niveles(numNivel);
                Guardar = true;
                ActualizarArchivo();

                collisions = new QTimer(this);
                connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
                collisions->start(50);
                setup_enemies();
                Dificultad();
                cambionivel = false;
            }
        }
    }
}

void MainWindow::cargar_niveles(int Nivel) //Función que permite el montaje de los Niveles
{
    QVector<QString> nivel;

    clean_levels();

    if(Nivel == 1){ //Nivel 1

        scene->setBackgroundBrush(QPixmap(":/Imagenes/Fondos/Nivel1.jpeg"));

        reproducir->stop();
        delete reproducir;

        reproducir = new QSound(":/Imagenes/Audio/Nivel1.wav");
        reproducir->play();
        reproducir->setLoops(QSound::Infinite);

        if(onep){
            if(banCargarP == false){
                player1->setPX(0);
                player1->setPY(623);
            }
            player1->setPos(player1->getPX(),player1->getPY());
            scene->addItem(player1);

            if(player1->getKeyplayer() == 'g'){
                player1->getSpown()->start(250);
            }
            else if(player1->getKeyplayer() == 's'){
                player1->stevenA();
            }
        }
        else if(multip){
            for(int l = 0; l < Jugadores.size(); l++){
                if(Jugadores.at(l)->getKeyplayer() == 'g'){
                    if(banCargarP == false){
                        Jugadores.at(l)->setPX(0);
                        Jugadores.at(l)->setPY(623);
                    }
                    Jugadores.at(l)->setPos(Jugadores.at(l)->getPX(),Jugadores.at(l)->getPY());
                    scene->addItem(Jugadores.at(l));
                    Jugadores.at(l)->getSpown()->start(250);
                }
                else if(Jugadores.at(l)->getKeyplayer() == 's'){
                    if(banCargarP == false){
                        Jugadores.at(l)->setPX(100);
                        Jugadores.at(l)->setPY(623);
                    }
                    Jugadores.at(l)->setPos(Jugadores.at(l)->getPX(),Jugadores.at(l)->getPY());
                    scene->addItem(Jugadores.at(l));
                    Jugadores.at(l)->stevenA();
                }
            }
        }

        //Jefe final nivel 1
        jefe1 = new bills(4799,311); //4799 311   370, 414
        scene->addItem(jefe1);
        jefe1->setBanSpown(true);
        jefe1->spown();

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

        scene->setBackgroundBrush(QPixmap(":/Imagenes/Fondos/Nivel2.jpeg"));

        reproducir->stop();
        delete reproducir;

        reproducir = new QSound(":/Imagenes/Audio/Nivel2.wav");
        reproducir->play();
        reproducir->setLoops(QSound::Infinite);

        if(onep){
            if(banCargarP == false){
                player1->setPX(0);
                player1->setPY(592);
            }
            player1->setPos(player1->getPX(),player1->getPY());
            scene->addItem(player1);
            if(player1->getKeyplayer() == 'g'){ //The guy
                player1->getSpown()->start(250);
            }
            else if(player1->getKeyplayer() == 's'){ //Steven
                player1->stevenA();
            }
        }
        else if(multip){
            for(int l = 0; l < Jugadores.size(); l++){
                if(Jugadores.at(l)->getKeyplayer() == 'g'){
                    if(banCargarP == false){
                        Jugadores.at(l)->setPX(0);
                        Jugadores.at(l)->setPY(592);
                    }
                    Jugadores.at(l)->setPos(Jugadores.at(l)->getPX(),Jugadores.at(l)->getPY());
                    scene->addItem(Jugadores.at(l));
                    Jugadores.at(l)->getSpown()->start(250);
                }
                else if(Jugadores.at(l)->getKeyplayer() == 's'){
                    if(banCargarP == false){
                        Jugadores.at(l)->setPX(55);
                        Jugadores.at(l)->setPY(592);
                    }
                    Jugadores.at(l)->setPos(Jugadores.at(l)->getPX(),Jugadores.at(l)->getPY());
                    scene->addItem(Jugadores.at(l));
                    Jugadores.at(l)->stevenA();
                }
            }
        }

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

        scene->setBackgroundBrush(QPixmap(":/Imagenes/Fondos/Nivel3.jpeg"));

        reproducir->stop();
        delete reproducir;

        reproducir = new QSound(":/Imagenes/Audio/VS_Dj_Sray.wav");
        reproducir->play();
        reproducir->setLoops(QSound::Infinite);

        if(onep){
            if(banCargarP == false){
                player1->setPX(350);
                player1->setPY(607);
            }
            player1->setPos(player1->getPX(),player1->getPY());
            scene->addItem(player1);
            if(player1->getKeyplayer() == 'g'){ //The guy
                player1->getSpown()->start(250);
            }
            else if(player1->getKeyplayer() == 's'){ //Steven
                player1->stevenA();
            }
        }
        else if(multip){
            for(int l = 0; l < Jugadores.size(); l++){
                if(Jugadores.at(l)->getKeyplayer() == 'g'){
                    if(banCargarP == false){
                        Jugadores.at(l)->setPX(300);
                        Jugadores.at(l)->setPY(607);
                    }
                    Jugadores.at(l)->setPos(Jugadores.at(l)->getPX(),Jugadores.at(l)->getPY());
                    scene->addItem(Jugadores.at(l));
                    Jugadores.at(l)->getSpown()->start(250);
                }
                else if(Jugadores.at(l)->getKeyplayer() == 's'){
                    if(banCargarP == false){
                        Jugadores.at(l)->setPX(359);
                        Jugadores.at(l)->setPY(607);
                    }
                    Jugadores.at(l)->setPos(Jugadores.at(l)->getPX(),Jugadores.at(l)->getPY());
                    scene->addItem(Jugadores.at(l));
                    Jugadores.at(l)->stevenA();
                }
            }
        }

        jefe2 = new sray(850,406,ui->baile);
        scene->addItem(jefe2);

        nivel = LThree();

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

    if(banCargarP) banCargarP = false;
}

void MainWindow::CollisionEnemy() //Función que valida las colisiones de los enemigos con su entorno
{
    if(onep){collisionEnemyOneP();}
    else if(multip){collisionEnemyMultiP();}
}

void MainWindow::collisionEnemyOneP() //Función que valida las colisiones de los enemigos con su entorno -> 1 Jugador
{
    for(int h = 0; h < enemigosH.size(); h++){
        if(enemigosH.at(h)->getBanDeath()){
            scene->removeItem(enemigosH.at(h));
            enemigosH.erase(enemigosH.begin()+h);
            h -= 1;
            break;
        }
        else{
            if(enemigosH.at(h)->getBanD() && enemigosH.at(h)->getBanIdle() == false && !enemigosH.empty()){
                for(int i = 0; i < walls.size(); i++){
                    if(player1->collidesWithItem(walls.at(i)) && enemigosH.at(h)->collidesWithItem(walls.at(i)) && enemigosH.at(h)->getBanDeath() == false){
                        if(abs(player1->getPX()-enemigosH.at(h)->getPx()) <= enemigosH.at(h)->getRango() && enemigosH.at(h)->getType() == 'b'){
                            if(player1->collidesWithItem(enemigosH.at(h))){
                                player1->setMuerte(player1->getMuerte()+1);
                                if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
                                else{ui->muertessteven->display(player1->getMuerte());}
                                player1->setPX(player1->getObjeto()->rebote(player1->getPX(),enemigosH.at(h)->getVx(),100,player1->getLado()));
                                player1->setPos(player1->getPX(),player1->getPY());
                            }
                            if(enemigosH.at(h)->getBanAttack() == false){
                                enemigosH.at(h)->setBanAttack(true);
                                enemigosH.at(h)->ataque();
                            }
                        }
                        else{
                            if(player1->getPX() < enemigosH.at(h)->getPx()){
                                enemigosH.at(h)->setMove('A');
                                if(enemigosH.at(h)->getBanMove() == false){
                                    enemigosH.at(h)->setBanMove(true);
                                    enemigosH.at(h)->mover();
                                }
                            }
                            else if(player1->getPX() > enemigosH.at(h)->getPx()){
                                enemigosH.at(h)->setMove('D');
                                if(enemigosH.at(h)->getBanMove() == false){
                                    enemigosH.at(h)->setBanMove(true);
                                    enemigosH.at(h)->mover();
                                }
                            }
                        }
                    }
                    else{
                        if(enemigosH.at(h)->getType() == 'm'){
                            if(pow(pow(player1->getPX()-enemigosH.at(h)->getPx(),2)+pow(player1->getPY()-enemigosH.at(h)->getPy(),2),0.5) <= enemigosH.at(h)->getRadioHmm() && ataqueHammer.empty()){
                                if(player1->getPX() < enemigosH.at(h)->getPx()) ataqueHammer.push_back(new hammerattack(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy(), 'A'));
                                else ataqueHammer.push_back(new hammerattack(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy(), 'D'));
                                scene->addItem(ataqueHammer.at(ataqueHammer.size()-1));
                                ataqueHammer.at(ataqueHammer.size()-1)->parabola();
                                ataqueHammer.at(ataqueHammer.size()-1)->setEnemigo(h);
                            }
                        }
                        if((player1->collidesWithItem(walls.at(i)) || enemigosH.at(h)->collidesWithItem(walls.at(i))) && (enemigosH.at(h)->getBanMove())){
                            if(enemigosH.at(h)->collidesWithItem(walls.at(i))){
                                if(enemigosH.at(h)->getPx()+65 >= walls.at(i)->getPosX()+walls.at(i)->getWidth()){
                                    enemigosH.at(h)->setMove('A');
                                }

                                if(enemigosH.at(h)->getPx() <= walls.at(i)->getPosX()){
                                    enemigosH.at(h)->setMove('D');
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::collisionEnemyMultiP() //Función que valida las colisiones de los enemigos con su entorno -> 2 Jugadores
{
    for(int j = 0; j < Jugadores.size(); j++){
        for(int h = 0; h < enemigosH.size(); h++){
            if(enemigosH.at(h)->getBanDeath()){
                scene->removeItem(enemigosH.at(h));
                enemigosH.erase(enemigosH.begin()+h);
                h -= 1;
                break;
            }
            else{
                if(enemigosH.at(h)->getBanD() && enemigosH.at(h)->getBanIdle() == false && !enemigosH.empty()){
                    for(int i = 0; i < walls.size(); i++){
                        if(Jugadores.at(j)->collidesWithItem(walls.at(i)) && enemigosH.at(h)->collidesWithItem(walls.at(i)) && enemigosH.at(h)->getBanDeath() == false){
                            if(abs(Jugadores.at(j)->getPX()-enemigosH.at(h)->getPx()) <= enemigosH.at(h)->getRango() && enemigosH.at(h)->getType() == 'b'){
                                if(Jugadores.at(j)->collidesWithItem(enemigosH.at(h))){
                                    Jugadores.at(j)->setMuerte(Jugadores.at(j)->getMuerte()+1);
                                    if(Jugadores.at(j)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(j)->getMuerte());}
                                    else{ui->muertessteven->display(Jugadores.at(j)->getMuerte());}
                                    Jugadores.at(j)->setPX(Jugadores.at(j)->getObjeto()->rebote(Jugadores.at(j)->getPX(),enemigosH.at(h)->getVx(),100,Jugadores.at(j)->getLado()));
                                    Jugadores.at(j)->setPos(Jugadores.at(j)->getPX(),Jugadores.at(j)->getPY());
                                }
                                if(enemigosH.at(h)->getBanAttack() == false){
                                    enemigosH.at(h)->setBanAttack(true);
                                    enemigosH.at(h)->ataque();
                                }
                            }
                            else{
                                if(Jugadores.at(j)->getPX() < enemigosH.at(h)->getPx()){
                                    enemigosH.at(h)->setMove('A');
                                    if(enemigosH.at(h)->getBanMove() == false){
                                        enemigosH.at(h)->setBanMove(true);
                                        enemigosH.at(h)->mover();
                                    }
                                }
                                else if(Jugadores.at(j)->getPX() > enemigosH.at(h)->getPx()){
                                    enemigosH.at(h)->setMove('D');
                                    if(enemigosH.at(h)->getBanMove() == false){
                                        enemigosH.at(h)->setBanMove(true);
                                        enemigosH.at(h)->mover();
                                    }
                                }
                            }
                        }
                        else{
                            if(enemigosH.at(h)->getType() == 'm'){
                                if(pow(pow(Jugadores.at(j)->getPX()-enemigosH.at(h)->getPx(),2)+pow(Jugadores.at(j)->getPY()-enemigosH.at(h)->getPy(),2),0.5) <= enemigosH.at(h)->getRadioHmm() && ataqueHammer.empty()){
                                    if(Jugadores.at(j)->getPX() < enemigosH.at(h)->getPx()) ataqueHammer.push_back(new hammerattack(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy(), 'A'));
                                    else ataqueHammer.push_back(new hammerattack(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy(), 'D'));
                                    scene->addItem(ataqueHammer.at(ataqueHammer.size()-1));
                                    ataqueHammer.at(ataqueHammer.size()-1)->parabola();
                                    ataqueHammer.at(ataqueHammer.size()-1)->setEnemigo(h);
                                }
                            }
                            if((Jugadores.at(j)->collidesWithItem(walls.at(i)) || enemigosH.at(h)->collidesWithItem(walls.at(i))) && (enemigosH.at(h)->getBanMove())){
                                if(enemigosH.at(h)->collidesWithItem(walls.at(i))){
                                    if(enemigosH.at(h)->getPx()+65 >= walls.at(i)->getPosX()+walls.at(i)->getWidth()){
                                        enemigosH.at(h)->setMove('A');
                                    }

                                    if(enemigosH.at(h)->getPx() <= walls.at(i)->getPosX()){
                                        enemigosH.at(h)->setMove('D');
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::validarmovimientosoneplayer(QKeyEvent *i) //Función para validar las teclas presionadas -> 1 Jugador
{

    if(player1->getKeyplayer() == 'g'){
        if(i->key() == Qt::Key_W){
            if(player1->getJump() == false){
                if(numNivel == 3){
                    if(jefe2->getBanmove()){
                        if(playermoves.size() < jefe2->getSmoves().size()){
                            playermoves.push_back("Up");
                        }
                    }
                }
                else {player1->walkPlayer('W');}
            }
        }

        if(i->key() == Qt::Key_D){
            for(int i = 0; i < walls.size(); i++){
                if(!enemigosH.empty() && (numNivel == 1 || numNivel == 2)){
                    for(int h = 0; h < enemigosH.size(); h++){
                        if(player1->collidesWithItem(lineRight) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false && player1->collidesWithItem(enemigosH.at(h)) == false){
                            QList<QGraphicsItem*> items = player1->collidingItems();
                            if(items.size() < 2){
                                player1->cinematica();
                            }
                            break;
                        }
                        else{
                            if(player1->collidesWithItem(enemigosH.at(h))){
                                player1->setPX(player1->getObjeto()->rebote(player1->getPX(),enemigosH.at(h)->getVx(),10,player1->getLado()));
                                player1->setPos(player1->getPX(),player1->getPY());
                                break;
                            }
                        }
                    }
                }
                else{
                    if(numNivel == 3){
                        if(jefe2->getBanmove()){
                            if(playermoves.size() < jefe2->getSmoves().size()){
                                playermoves.push_back("Right");
                            }
                        }
                    }
                    if(player1->collidesWithItem(lineRight) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                        QList<QGraphicsItem*> items = player1->collidingItems();
                        if(items.size() < 2){
                            player1->cinematica();
                        }
                        break;
                    }
                }
            }
            player1->walkPlayer('D');
        }

        if(i->key() == Qt::Key_A){
            for(int i = 0; i < walls.size(); i++){
                if(!enemigosH.empty() && (numNivel == 1 || numNivel == 2)){
                    for(int h = 0; h < enemigosH.size(); h++){
                        if(player1->collidesWithItem(lineLeft) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false && player1->collidesWithItem(enemigosH.at(h)) == false){
                            QList<QGraphicsItem*> items = player1->collidingItems();
                            if(items.size() < 2){
                                player1->cinematica();
                            }
                            break;
                        }
                        else{
                            if(player1->collidesWithItem(enemigosH.at(h))){
                                player1->setPX(player1->getObjeto()->rebote(player1->getPX(),enemigosH.at(h)->getVx(),10,player1->getLado()));
                                player1->setPos(player1->getPX(),player1->getPY());
                                break;
                            }
                        }
                    }
                }
                else{
                    if(numNivel == 3){
                        if(jefe2->getBanmove()){
                            if(playermoves.size() < jefe2->getSmoves().size()){
                                playermoves.push_back("Left");
                            }
                        }
                    }
                    if(player1->collidesWithItem(lineLeft) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                        QList<QGraphicsItem*> items = player1->collidingItems();
                        if(items.size() < 2){
                            player1->cinematica();
                        }
                        break;
                    }
                }
            }
            player1->walkPlayer('A');
        }

        if(i->key() == Qt::Key_E){
            player1->walkPlayer('T');
            ataque.push_back(new guyattack(player1->getPX(), player1->getPY(), player1->getLado(),'g'));
            scene->addItem(ataque.at(ataque.size()-1));
            ataque.at(ataque.size()-1)->getAguy()->start(75);
        }

        if(i->key() == Qt::Key_S){
            if(numNivel == 3){
                if(jefe2->getBanmove()){
                    if(playermoves.size() < jefe2->getSmoves().size()){
                        playermoves.push_back("Down");
                    }
                }
            }
        }
    }
    else if(player1->getKeyplayer() == 's'){

        if(i->key() == Qt::Key_I){
            if(player1->getJump() == false){
                if(numNivel == 3){
                    if(jefe2->getBanmove()){
                        if(playermoves.size() < jefe2->getSmoves().size()){
                            playermoves.push_back("Up");
                        }
                    }
                }
                else {player1->walkPlayer('I');}
            }
        }

        if(i->key() == Qt::Key_L){
            for(int i = 0; i < walls.size(); i++){
                if(!enemigosH.empty()){
                    for(int h = 0; h < enemigosH.size(); h++){
                        if(player1->collidesWithItem(lineRight) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false && player1->collidesWithItem(enemigosH.at(h)) == false){
                            QList<QGraphicsItem*> items = player1->collidingItems();
                            if(items.size() < 2){
                                player1->cinematica();
                            }
                            break;
                        }
                        else{
                            if(player1->collidesWithItem(enemigosH.at(h))){
                                player1->setPX(player1->getObjeto()->rebote(player1->getPX(),enemigosH.at(h)->getVx(),10,player1->getLado()));
                                player1->setPos(player1->getPX(),player1->getPY());
                                break;
                            }
                        }
                    }
                }
                else{
                    if(numNivel == 3){
                        if(jefe2->getBanmove()){
                            if(playermoves.size() < jefe2->getSmoves().size()){
                                playermoves.push_back("Right");
                            }
                        }
                    }
                    if(player1->collidesWithItem(lineRight) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                        QList<QGraphicsItem*> items = player1->collidingItems();
                        if(items.size() < 2){
                            player1->cinematica();
                        }
                        break;
                    }
                }
            }
            player1->walkPlayer('L');
        }

        if(i->key() == Qt::Key_J){
            for(int i = 0; i < walls.size(); i++){
                if(!enemigosH.empty()){
                    for(int h = 0; h < enemigosH.size(); h++){
                        if(player1->collidesWithItem(lineLeft) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false && player1->collidesWithItem(enemigosH.at(h)) == false){
                            QList<QGraphicsItem*> items = player1->collidingItems();
                            if(items.size() < 2){
                                player1->cinematica();
                            }
                            break;
                        }
                        else{
                            if(player1->collidesWithItem(enemigosH.at(h))){
                                player1->setPX(player1->getObjeto()->rebote(player1->getPX(),enemigosH.at(h)->getVx(),10,player1->getLado()));
                                player1->setPos(player1->getPX(),player1->getPY());
                                break;
                            }
                        }
                    }
                }
                else{
                    if(numNivel == 3){
                        if(jefe2->getBanmove()){
                            if(playermoves.size() < jefe2->getSmoves().size()){
                                playermoves.push_back("Left");
                            }
                        }
                    }
                    if(player1->collidesWithItem(lineLeft) == false && player1->collidesWithItem(walls.at(i)) && player1->getJump() == false){
                        QList<QGraphicsItem*> items = player1->collidingItems();
                        if(items.size() < 2){
                            player1->cinematica();
                        }
                        break;
                    }
                }
            }
            player1->walkPlayer('J');
        }

        if(i->key() == Qt::Key_O){
            player1->walkPlayer('T');
            ataque.push_back(new guyattack(player1->getPX(), player1->getPY(), player1->getLado(),'s'));
            scene->addItem(ataque.at(ataque.size()-1));
            ataque.at(ataque.size()-1)->getAguy()->start(75);
        }

        if(i->key() == Qt::Key_K){
            if(numNivel == 3){
                if(jefe2->getBanmove()){
                    if(playermoves.size() < jefe2->getSmoves().size()){
                        playermoves.push_back("Down");
                    }
                }
            }
        }


    }
}

void MainWindow::validarmovimientosMultiP(QKeyEvent *i) //Función para validar las teclas presionadas -> 2 Jugadores
{
    if(i->key() == Qt::Key_W){
        if(Jugadores.at(0)->getJump() == false){
            if(numNivel == 3){
                if(jefe2->getBanmove()){
                    if(playermoves.size() < jefe2->getSmoves().size()){
                        playermoves.push_back("Up");
                    }
                }
            }
            else{
                Jugadores.at(0)->walkPlayer('W');
            }
        }
    }

    if(i->key() == Qt::Key_D){
        for(int i = 0; i < walls.size(); i++){
            if(!enemigosH.empty() && (numNivel == 1 || numNivel == 2)){
                for(int h = 0; h < enemigosH.size(); h++){
                    if(Jugadores.at(0)->collidesWithItem(lineRight) == false && Jugadores.at(0)->collidesWithItem(walls.at(i)) && Jugadores.at(0)->getJump() == false && Jugadores.at(0)->collidesWithItem(enemigosH.at(h)) == false){
                        QList<QGraphicsItem*> items = Jugadores.at(0)->collidingItems();
                        if(items.size() < 2){
                            Jugadores.at(0)->cinematica();
                        }
                        break;
                    }
                    else{
                        if(Jugadores.at(0)->collidesWithItem(enemigosH.at(h))){
                            Jugadores.at(0)->setPX(Jugadores.at(0)->getObjeto()->rebote(Jugadores.at(0)->getPX(),enemigosH.at(h)->getVx(),10,Jugadores.at(0)->getLado()));
                            Jugadores.at(0)->setPos(Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY());
                            break;
                        }
                    }
                }
            }
            else{
                if(numNivel == 3){
                    if(jefe2->getBanmove()){
                        if(playermoves.size() < jefe2->getSmoves().size()){
                            playermoves.push_back("Right");
                        }
                    }
                }
                if(Jugadores.at(0)->collidesWithItem(lineRight) == false && Jugadores.at(0)->collidesWithItem(walls.at(i)) && Jugadores.at(0)->getJump() == false){
                    QList<QGraphicsItem*> items = Jugadores.at(0)->collidingItems();
                    if(items.size() < 2){
                        Jugadores.at(0)->cinematica();
                    }
                    break;
                }
            }
        }
        Jugadores.at(0)->walkPlayer('D');
    }

    if(i->key() == Qt::Key_A){
        for(int i = 0; i < walls.size(); i++){
            if(!enemigosH.empty() && (numNivel == 1 || numNivel == 2)){
                for(int h = 0; h < enemigosH.size(); h++){
                    if(Jugadores.at(0)->collidesWithItem(lineLeft) == false && Jugadores.at(0)->collidesWithItem(walls.at(i)) && Jugadores.at(0)->getJump() == false && Jugadores.at(0)->collidesWithItem(enemigosH.at(h)) == false){
                        QList<QGraphicsItem*> items = Jugadores.at(0)->collidingItems();
                        if(items.size() < 2){
                            Jugadores.at(0)->cinematica();
                        }
                        break;
                    }
                    else{
                        if(Jugadores.at(0)->collidesWithItem(enemigosH.at(h))){
                            Jugadores.at(0)->setPX(Jugadores.at(0)->getObjeto()->rebote(Jugadores.at(0)->getPX(),enemigosH.at(h)->getVx(),10,Jugadores.at(0)->getLado()));
                            Jugadores.at(0)->setPos(Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY());
                            break;
                        }
                    }
                }
            }
            else{
                if(numNivel == 3){
                    if(jefe2->getBanmove()){
                        if(playermoves.size() < jefe2->getSmoves().size()){
                            playermoves.push_back("Left");
                        }
                    }
                }
                if(Jugadores.at(0)->collidesWithItem(lineLeft) == false && Jugadores.at(0)->collidesWithItem(walls.at(i)) && Jugadores.at(0)->getJump() == false){
                    QList<QGraphicsItem*> items = Jugadores.at(0)->collidingItems();
                    if(items.size() < 2){
                        Jugadores.at(0)->cinematica();
                    }
                    break;
                }
            }
        }
        Jugadores.at(0)->walkPlayer('A');
    }

    if(i->key() == Qt::Key_E){
        Jugadores.at(0)->walkPlayer('T');
        ataque.push_back(new guyattack(Jugadores.at(0)->getPX(), Jugadores.at(0)->getPY(), Jugadores.at(0)->getLado(),'g'));
        scene->addItem(ataque.at(ataque.size()-1));
        ataque.at(ataque.size()-1)->getAguy()->start(75);
    }

    if(i->key() == Qt::Key_S){
        if(numNivel == 3){
            if(jefe2->getBanmove()){
                if(playermoves.size() < jefe2->getSmoves().size()){
                    playermoves.push_back("Down");
                }
            }
        }
    }

    if(i->key() == Qt::Key_I){
        if(Jugadores.at(1)->getJump() == false){
            if(numNivel == 3){
                if(jefe2->getBanmove()){
                    if(playermoves2.size() < jefe2->getSmoves().size()){
                        playermoves2.push_back("Up");
                    }
                }
            }
            else{Jugadores.at(1)->walkPlayer('I');}
        }
    }

    if(i->key() == Qt::Key_L){
        for(int i = 0; i < walls.size(); i++){
            if(!enemigosH.empty()){
                for(int h = 0; h < enemigosH.size(); h++){
                    if(Jugadores.at(1)->collidesWithItem(lineRight) == false && Jugadores.at(1)->collidesWithItem(walls.at(i)) && Jugadores.at(1)->getJump() == false && Jugadores.at(1)->collidesWithItem(enemigosH.at(h)) == false){
                        QList<QGraphicsItem*> items = Jugadores.at(1)->collidingItems();
                        if(items.size() < 2){
                            Jugadores.at(1)->cinematica();
                        }
                        break;
                    }
                    else{
                        if(Jugadores.at(1)->collidesWithItem(enemigosH.at(h))){
                            Jugadores.at(1)->setPX(Jugadores.at(1)->getObjeto()->rebote(Jugadores.at(1)->getPX(),enemigosH.at(h)->getVx(),10,Jugadores.at(1)->getLado()));
                            Jugadores.at(1)->setPos(Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY());
                            break;
                        }
                    }
                }
            }
            else{
                if(numNivel == 3){
                    if(jefe2->getBanmove()){
                        if(playermoves2.size() < jefe2->getSmoves().size()){
                            playermoves2.push_back("Right");
                        }
                    }
                }
                if(Jugadores.at(1)->collidesWithItem(lineRight) == false && Jugadores.at(1)->collidesWithItem(walls.at(i)) && Jugadores.at(1)->getJump() == false){
                    QList<QGraphicsItem*> items = Jugadores.at(1)->collidingItems();
                    if(items.size() < 2){
                        Jugadores.at(1)->cinematica();
                    }
                    break;
                }
            }
        }
        Jugadores.at(1)->walkPlayer('L');
    }

    if(i->key() == Qt::Key_J){
        for(int i = 0; i < walls.size(); i++){
            if(!enemigosH.empty()){
                for(int h = 0; h < enemigosH.size(); h++){
                    if(Jugadores.at(1)->collidesWithItem(lineLeft) == false && Jugadores.at(1)->collidesWithItem(walls.at(i)) && Jugadores.at(1)->getJump() == false && Jugadores.at(1)->collidesWithItem(enemigosH.at(h)) == false){
                        QList<QGraphicsItem*> items = Jugadores.at(1)->collidingItems();
                        if(items.size() < 2){
                            Jugadores.at(1)->cinematica();
                        }
                        break;
                    }
                    else{
                        if(Jugadores.at(1)->collidesWithItem(enemigosH.at(h))){
                            Jugadores.at(1)->setPX(Jugadores.at(1)->getObjeto()->rebote(Jugadores.at(1)->getPX(),enemigosH.at(h)->getVx(),10,Jugadores.at(1)->getLado()));
                            Jugadores.at(1)->setPos(Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY());
                            break;
                        }
                    }
                }
            }
            else{
                if(numNivel == 3){
                    if(jefe2->getBanmove()){
                        if(playermoves2.size() < jefe2->getSmoves().size()){
                            playermoves2.push_back("Left");
                        }
                    }
                }
                if(Jugadores.at(1)->collidesWithItem(lineLeft) == false && Jugadores.at(1)->collidesWithItem(walls.at(i)) && Jugadores.at(1)->getJump() == false){
                    QList<QGraphicsItem*> items = Jugadores.at(1)->collidingItems();
                    if(items.size() < 2){
                        Jugadores.at(1)->cinematica();
                    }
                    break;
                }
            }
        }
        Jugadores.at(1)->walkPlayer('J');
    }

    if(i->key() == Qt::Key_O){
        Jugadores.at(1)->walkPlayer('T');
        ataque2.push_back(new guyattack(Jugadores.at(1)->getPX(), Jugadores.at(1)->getPY(), Jugadores.at(1)->getLado(),'s'));
        scene->addItem(ataque2.at(ataque2.size()-1));
        ataque2.at(ataque2.size()-1)->getAguy()->start(75);
    }

    if(i->key() == Qt::Key_K){
        if(numNivel == 3){
            if(jefe2->getBanmove()){
                if(playermoves2.size() < jefe2->getSmoves().size()){
                    playermoves2.push_back("Down");
                }
            }
        }
    }
}

void MainWindow::validateAttackGuy() //Función para validar el ataque del jugador
{
    if(onep){validateAttackOneP();}
    else if(multip){
        validateAttackOneP();
        validateAttackMultiP();
    }
}

void MainWindow::validateAttackOneP() //Función para validar el ataque del jugador en modo 1 Jugador
{
    if(!ataque.empty()){
        if(!enemigosH.empty()){
            for(int h = 0; h < enemigosH.size(); h++){
                for(int it = 0; it < ataque.size(); it++){

                    if(ataque.at(it)->collidesWithItem(enemigosH.at(h))){
                        ataque.at(it)->getAguy()->stop();
                        enemigosH.at(h)->setVidas(enemigosH.at(h)->getVidas()-ataque.at(it)->getDamage());
                        if(enemigosH.at(h)->getVidas() == 0){
                            enemigosH.at(h)->setBanD(false);
                            if(enemigosH.at(h)->getBanMove()){
                                enemigosH.at(h)->setBanMove(false);
                                enemigosH.at(h)->getMove()->stop();
                                enemigosH.at(h)->setPx(enemigosH.at(h)->getObjeto()->rebote(enemigosH.at(h)->getPx(),enemigosH.at(h)->getVx(),0,enemigosH.at(h)->getmMove()));
                                enemigosH.at(h)->setPos(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy());
                                delete enemigosH.at(h)->getMove();
                            }
                            if(enemigosH.at(h)->getBanAttack()){
                                enemigosH.at(h)->setBanAttack(false);
                                if(enemigosH.at(h)->getType() == 'b'){
                                    enemigosH.at(h)->getAttack()->stop();
                                    enemigosH.at(h)->setPx(enemigosH.at(h)->getObjeto()->rebote(enemigosH.at(h)->getPx(),enemigosH.at(h)->getVx(),0,enemigosH.at(h)->getmMove()));
                                    enemigosH.at(h)->setPos(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy());
                                    delete enemigosH.at(h)->getAttack();
                                }
                                else if(enemigosH.at(h)->getType() == 'm'){
                                    enemigosH.at(h)->setPx(enemigosH.at(h)->getObjeto()->rebote(enemigosH.at(h)->getPx(),enemigosH.at(h)->getVx(),0,enemigosH.at(h)->getmMove()));
                                    enemigosH.at(h)->setPos(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy());
                                }
                            }
                            if(enemigosH.at(h)->getType() == 'b') enemigosH.at(h)->muerte();
                            else enemigosH.at(h)->setBanDeath(true);
                        }

                        if(ataque.at(it)->scene() == scene){
                            scene->removeItem(ataque.at(it));
                        }
                        ataque.erase(ataque.begin()+it);
                        it -= 1;
                        break;
                    }
                }
            }
        }

        for(int it = 0; it < ataque.size(); it++){
            if(numNivel == 1){
                if(ataque.at(it)->collidesWithItem(jefe1) && jefe1->scene() == scene){
                    ataque.at(it)->getAguy()->stop();
                    if(jefe1->getVida() == 0 && jefe1->getBanDeath() == false){
                        if(jefe1->getBanMove()){
                            jefe1->setBanMove(false);
                            jefe1->getMove()->stop();
                            delete jefe1->getMove();
                        }
                        else if(jefe1->getBanAttack()){
                            jefe1->setBanAttack(false);
                            jefe1->getAttack()->stop();
                            delete jefe1->getAttack();
                        }
                        jefe1->setBanDeath(true);
                        jefe1->death();
                    }
                    else if(jefe1->getVida() > 0){
                        jefe1->setVida(jefe1->getVida()-ataque.at(it)->getDamage());
                    }

                    if(ataque.at(it)->scene() == scene){
                        scene->removeItem(ataque.at(it));
                    }
                    ataque.erase(ataque.begin()+it);
                    it -= 1;
                    break;
                }
            }
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

void MainWindow::validateAttackMultiP() //Función para validar el ataque del jugador en modo 2 Jugadores
{
    if(!ataque2.empty()){
        if(!enemigosH.empty()){
            for(int h = 0; h < enemigosH.size(); h++){
                for(int it = 0; it < ataque2.size(); it++){
                    if(ataque2.at(it)->collidesWithItem(enemigosH.at(h))){ //Cuando el jugador ataque2 al enemigo -> RECORDAR QUE DEPENDE DE LA DIFICULTAD
                        //Se le resta vida y acorde a la vida se elimina o no
                        ataque2.at(it)->getAguy()->stop();
                        enemigosH.at(h)->setVidas(enemigosH.at(h)->getVidas()-ataque2.at(it)->getDamage());
                        if(enemigosH.at(h)->getVidas() == 0){
                            enemigosH.at(h)->setBanD(false);
                            if(enemigosH.at(h)->getBanMove()){
                                enemigosH.at(h)->setBanMove(false);
                                enemigosH.at(h)->getMove()->stop();
                                enemigosH.at(h)->setPx(enemigosH.at(h)->getObjeto()->rebote(enemigosH.at(h)->getPx(),enemigosH.at(h)->getVx(),0,enemigosH.at(h)->getmMove()));
                                enemigosH.at(h)->setPos(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy());
                                delete enemigosH.at(h)->getMove();
                            }
                            if(enemigosH.at(h)->getBanAttack()){
                                enemigosH.at(h)->setBanAttack(false);
                                if(enemigosH.at(h)->getType() == 'b'){
                                    enemigosH.at(h)->getAttack()->stop();
                                    enemigosH.at(h)->setPx(enemigosH.at(h)->getObjeto()->rebote(enemigosH.at(h)->getPx(),enemigosH.at(h)->getVx(),0,enemigosH.at(h)->getmMove()));
                                    enemigosH.at(h)->setPos(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy());
                                    delete enemigosH.at(h)->getAttack();
                                }
                                else if(enemigosH.at(h)->getType() == 'm'){
                                    enemigosH.at(h)->setPx(enemigosH.at(h)->getObjeto()->rebote(enemigosH.at(h)->getPx(),enemigosH.at(h)->getVx(),0,enemigosH.at(h)->getmMove()));
                                    enemigosH.at(h)->setPos(enemigosH.at(h)->getPx(),enemigosH.at(h)->getPy());
                                }
                            }
                            if(enemigosH.at(h)->getType() == 'b') enemigosH.at(h)->muerte();
                            else enemigosH.at(h)->setBanDeath(true);
                        }

                        if(ataque2.at(it)->scene() == scene){
                            scene->removeItem(ataque2.at(it));
                        }
                        ataque2.erase(ataque2.begin()+it);
                        it -= 1;
                        break;
                    }
                }
            }
        }

        for(int it = 0; it < ataque2.size(); it++){
            if(numNivel == 1){
                if(ataque2.at(it)->collidesWithItem(jefe1) && jefe1->scene() == scene){
                    ataque2.at(it)->getAguy()->stop();
                    if(jefe1->getVida() == 0 && jefe1->getBanDeath() == false){
                        if(jefe1->getBanMove()){
                            jefe1->setBanMove(false);
                            jefe1->getMove()->stop();
                            delete jefe1->getMove();
                        }
                        else if(jefe1->getBanAttack()){
                            jefe1->setBanAttack(false);
                            jefe1->getAttack()->stop();
                            delete jefe1->getAttack();
                        }
                        jefe1->setBanDeath(true);
                        jefe1->death();
                    }
                    else if(jefe1->getVida() > 0){
                        jefe1->setVida(jefe1->getVida()-ataque2.at(it)->getDamage());
                    }

                    if(ataque2.at(it)->scene() == scene){
                        scene->removeItem(ataque2.at(it));
                    }
                    ataque2.erase(ataque2.begin()+it);
                    it -= 1;
                    break;
                }
            }

            for(int p = 0; p < walls.size(); p++){
                if((ataque2.at(it)->collidesWithItem(walls.at(p))) || (ataque2.at(it)->collidesWithItem(lineLeft)) || (ataque2.at(it)->collidesWithItem(lineRight))){
                    ataque2.at(it)->getAguy()->stop();
                    if(ataque2.at(it)->scene() == scene){
                        scene->removeItem(ataque2.at(it));
                    }
                    ataque2.erase(ataque2.begin()+it);
                    break;
                }
            }
        }
    }
}

void MainWindow::validatePlayerMove() //Función para validar los movimientos del jugador
{
    if(onep){validateOnePMove();}
    else if(multip){validateMultiPMove();}
}

void MainWindow::validateOnePMove() //Función para validar los movimientos del jugador en modo 1 Jugador
{
    if(player1->getJump()){
        for(int m = 0; m < walls.size(); m++){

            if(player1->getJumpUp() && player1->collidesWithItem(walls.at(m))){ //Revisar esta parte
                player1->setAy(-1);
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

        if(numNivel == 2){
            for(int p = 0; p < spikes.size(); p++){
                if(player1->collidesWithItem(spikes.at(p))){
                    player1->setMuerte(player1->getMuerte()+1);
                    if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
                    else{ui->muertessteven->display(player1->getMuerte());}

                    player1->setPX(player1->getPX()-100);
                    player1->setPos(player1->getPX(),player1->getPY());
                }
            }
        }

        if(player1->collidesWithItem(lineLeft)){
            player1->setJumpP(false);
        }

        if(player1->collidesWithItem(lineRight)){
            if(W+1280 < 5120){
                W += 1280;
                scene->setSceneRect(W,0,ui->graphicsView->width()-3,H);
                lineRight->setLine(W+1280,0,W+1280,708);
                //lineLeft->setLine(W,0,W,708);
            }
        }

        if(player1->collidesWithItem(lineDown)){
            player1->setMuerte(player1->getMuerte()+1);
            if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
            else{ui->muertessteven->display(player1->getMuerte());}

            if(numNivel == 1){
                if(W == 0){
                    player1->setPX(0);
                    player1->setPY(623);
                    player1->setPos(player1->getPX(),player1->getPY());
                }
                else if(W == 1280){
                    player1->setPX(1458);
                    player1->setPY(623);
                    player1->setPos(player1->getPX(),player1->getPY());
                }
                else if(W == 2560){
                    player1->setPX(2648);
                    player1->setPY(623);
                    player1->setPos(player1->getPX(),player1->getPY());
                }
                player1->getLeap()->stop();
                player1->setAy(11);
                player1->setJump(false);
                player1->setJumpUp(false);
                player1->setJumpDown(false);
                player1->setJumpP(false);
                delete player1->getLeap();
            }
        }
    }
    else{ //Parte de la caída libre del personaje
        for(int m = 0; m < walls.size(); m ++){
            if(player1->collidesWithItem(walls.at(m)) == false){
                if(m+1 == walls.size() && player1->getJumpDown() == false){
                    player1->setAy(-1);
                    if(player1->getKeyplayer() == 'g') player1->walkPlayer('W');
                    else if(player1->getKeyplayer() == 's') player1->walkPlayer('I');
                }
            }
            else{
                break;
            }
        }

        if(numNivel == 2){
            for(int p = 0; p < spikes.size(); p++){
                if(player1->collidesWithItem(spikes.at(p))){
                    player1->setMuerte(player1->getMuerte()+1);
                    if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
                    else{ui->muertessteven->display(player1->getMuerte());}
                    player1->setPX(player1->getPX()-100);
                    player1->setPos(player1->getPX(),player1->getPY());
                }
            }
        }


        if(player1->collidesWithItem(lineRight)){
            if(numNivel == 1 || numNivel == 2){
                if(W+1280 < 5120){
                    W += 1280;
                    scene->setSceneRect(W,0,ui->graphicsView->width()-3,H);
                    lineRight->setLine(W+1280,0,W+1280,708);
                    lineLeft->setLine(W,0,W,708);
                }
            }
        }
    }
}

void MainWindow::validateMultiPMove() //Función para validar los movimientos del jugador en modo 2 Jugadores
{
    for(int s = 0; s < Jugadores.size(); s++){
        if(Jugadores.at(s)->getJump()){

            for(int m = 0; m < walls.size(); m++){
                if(Jugadores.at(s)->getJumpUp() && Jugadores.at(s)->collidesWithItem(walls.at(m))){ //Revisar esta parte
                    Jugadores.at(s)->setAy(-1);
                }

                if(Jugadores.at(s)->getJumpDown() && Jugadores.at(s)->collidesWithItem(walls.at(m))){
                    Jugadores.at(s)->getLeap()->stop();
                    Jugadores.at(s)->setPY(walls.at(m)->getPosY()-49);
                    Jugadores.at(s)->setPos(Jugadores.at(s)->getPX(),Jugadores.at(s)->getPY());
                    Jugadores.at(s)->setAy(11);
                    Jugadores.at(s)->setJump(false);
                    Jugadores.at(s)->setJumpUp(false);
                    Jugadores.at(s)->setJumpDown(false);
                    Jugadores.at(s)->setJumpP(false);
                    //delete Jugadores.at(s)->getLeap();
                    break;
                }

                if(Jugadores.at(s)->collidesWithItem(lineUp)){
                    Jugadores.at(s)->setAy(-1);
                }
            }

            if(numNivel == 2){
                for(int p = 0; p < spikes.size(); p++){
                    if(Jugadores.at(0)->collidesWithItem(spikes.at(p))){
                        Jugadores.at(0)->setMuerte(Jugadores.at(0)->getMuerte()+1);
                        if(Jugadores.at(0)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(0)->getMuerte());}
                        else{ui->muertessteven->display(Jugadores.at(0)->getMuerte());}
                        if(spikes.at(p)->getPosX() == 1128){
                            Jugadores.at(0)->setPX(1089);
                            Jugadores.at(0)->setPY(427);
                            Jugadores.at(0)->setPos(Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY());
                        }
                        else{
                            Jugadores.at(0)->setPX(Jugadores.at(0)->getPX()-100);
                            Jugadores.at(0)->setPos(Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY());
                        }
                    }

                    if(Jugadores.at(1)->collidesWithItem(spikes.at(p))){
                        Jugadores.at(1)->setMuerte(Jugadores.at(1)->getMuerte()+1);
                        if(Jugadores.at(1)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(1)->getMuerte());}
                        else{ui->muertessteven->display(Jugadores.at(1)->getMuerte());}
                        if(spikes.at(p)->getPosX() == 1128){
                            Jugadores.at(1)->setPX(1089);
                            Jugadores.at(1)->setPY(427);
                        }
                        else{
                            Jugadores.at(1)->setPX(Jugadores.at(1)->getPX()-100);
                            Jugadores.at(1)->setPos(Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY());
                        }
                    }
                }
            }

            if(Jugadores.at(s)->collidesWithItem(lineLeft)){
                Jugadores.at(s)->setJumpP(false);
            }

            if(Jugadores.at(0)->collidesWithItem(lineRight) && Jugadores.at(1)->collidesWithItem(lineRight)){
                if(W+1280 < 5120){
                    W += 1280;
                    scene->setSceneRect(W,0,ui->graphicsView->width()-3,H);
                    lineRight->setLine(W+1280,0,W+1280,708);
                    //lineLeft->setLine(W,0,W,708);
                }
            }

            if(Jugadores.at(s)->collidesWithItem(lineDown)){
                if(numNivel == 1){
                    Jugadores.at(s)->setMuerte(Jugadores.at(s)->getMuerte()+1);
                    if(Jugadores.at(s)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(s)->getMuerte());}
                    else{ui->muertessteven->display(Jugadores.at(s)->getMuerte());}
                    if(W == 0){
                        Jugadores.at(s)->setPX(0);
                        Jugadores.at(s)->setPY(623);
                        Jugadores.at(s)->setPos(Jugadores.at(s)->getPX(),Jugadores.at(s)->getPY());
                    }
                    else if(W == 1280){
                        Jugadores.at(s)->setPX(1458);
                        Jugadores.at(s)->setPY(623);
                        Jugadores.at(s)->setPos(Jugadores.at(s)->getPX(),Jugadores.at(s)->getPY());
                    }
                    else if(W == 2560){
                        Jugadores.at(s)->setPX(2648);
                        Jugadores.at(s)->setPY(623);
                        Jugadores.at(s)->setPos(Jugadores.at(s)->getPX(),Jugadores.at(s)->getPY());
                    }
                    Jugadores.at(s)->getLeap()->stop();
                    Jugadores.at(s)->setAy(11);
                    Jugadores.at(s)->setJump(false);
                    Jugadores.at(s)->setJumpUp(false);
                    Jugadores.at(s)->setJumpDown(false);
                    Jugadores.at(s)->setJumpP(false);
                    delete Jugadores.at(s)->getLeap();
                }
            }
        }
        else{ //Parte de la caída libre del personaje
            for(int m = 0; m < walls.size(); m ++){
                if(Jugadores.at(s)->collidesWithItem(walls.at(m)) == false){
                    if(m+1 == walls.size() && Jugadores.at(s)->getJumpDown() == false){
                        Jugadores.at(s)->setAy(-1);
                        if(Jugadores.at(s)->getKeyplayer() == 'g') Jugadores.at(s)->walkPlayer('W');
                        else if(Jugadores.at(s)->getKeyplayer() == 's') Jugadores.at(s)->walkPlayer('I');
                    }
                }
                else{
                    break;
                }
            }

            if(numNivel == 2){
                for(int p = 0; p < spikes.size(); p++){
                    if(Jugadores.at(0)->collidesWithItem(spikes.at(p))){
                        Jugadores.at(0)->setMuerte(Jugadores.at(0)->getMuerte()+1);
                        if(spikes.at(p)->getPosX() == 1128){
                            Jugadores.at(0)->setPX(1089);
                            Jugadores.at(0)->setPY(427);
                            Jugadores.at(0)->setPos(Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY());
                        }
                        else{
                            Jugadores.at(0)->setPX(Jugadores.at(0)->getPX()-100);
                            Jugadores.at(0)->setPos(Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY());
                        }
                    }

                    if(Jugadores.at(1)->collidesWithItem(spikes.at(p))){
                        Jugadores.at(1)->setMuerte(Jugadores.at(1)->getMuerte()+1);
                        if(spikes.at(p)->getPosX() == 1128){
                            Jugadores.at(1)->setPX(1089);
                            Jugadores.at(1)->setPY(427);
                        }
                        else{
                            Jugadores.at(1)->setPX(Jugadores.at(1)->getPX()-100);
                            Jugadores.at(1)->setPos(Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY());
                        }
                    }
                }
            }
            if(Jugadores.at(0)->collidesWithItem(lineRight) && Jugadores.at(1)->collidesWithItem(lineRight)){
                if(numNivel == 1 || numNivel == 2){
                    if(W+1280 < 5120){
                        W += 1280;
                        scene->setSceneRect(W,0,ui->graphicsView->width()-3,H);
                        lineRight->setLine(W+1280,0,W+1280,708);
                        lineLeft->setLine(W,0,W,708);
                    }
                }
            }
        }
    }
}

void MainWindow::validateBillsMove() //Función para validar el movimiento y ataque de Bills
{
    if(onep) {validateBMOneP();}
    else if(multip) {validateBMMultiP();}
}

void MainWindow::validateBMOneP() //Función para validar el movimiento y ataque de Bills en modo 1 jugador
{
    if(jefe1->scene() == scene){
        if(jefe1->collidesWithItem(lineUp)){
            jefe1->setVy(20);
        }

        for(int i = 0; i < walls.size(); i++){
            if(jefe1->collidesWithItem(walls.at(i))){
                jefe1->setVy(-20);
            }
        }

        if(jefe1->getBanDis() == true){
            if(jefe1->scene() == scene) scene->removeItem(jefe1);
        }
        else{
            if(pow(pow(player1->getPX()-jefe1->getPx(),2)+pow(player1->getPY()-jefe1->getPy(),2),0.5) <= jefe1->getRange()){
                if(ataquebills.empty() && jefe1->getBanAttack() == false && jefe1->getBanSpown() == false && jefe1->getBanDeath() == false){
                    jefe1->getMove()->stop();
                    delete jefe1->getMove();
                    jefe1->setBanAttack(true);
                    jefe1->attack();
                    ataquebills.push_back(new billsattack(player1->getPX(),0));
                    scene->addItem(ataquebills.at(ataquebills.size()-1));
                }
            }

            if(!ataquebills.empty() && jefe1->getBanDeath() == false){ //REVISAR ESTA PARTE
                for(int b = 0; b < ataquebills.size(); b++){
                    for(int w = 0; w < walls.size(); w++){
                        if(ataquebills.at(b)->collidesWithItem(player1) || ataquebills.at(b)->collidesWithItem(walls.at(w))){
                            if(ataquebills.at(b)->collidesWithItem(player1)){
                                player1->setMuerte(player1->getMuerte()+1);
                                if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
                                else{ui->muertessteven->display(player1->getMuerte());}
                            }
                            ataquebills.at(b)->getTime()->stop();
                            delete ataquebills.at(b)->getTime();
                            scene->removeItem(ataquebills.at(b));
                            ataquebills.erase(ataquebills.begin()+b);
                            b--;
                            break;
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::validateBMMultiP() //Función para validar el movimiento y ataque de Bills en modo 2 jugadores
{
    if(jefe1->scene() == scene){
        if(jefe1->collidesWithItem(lineUp)){
            jefe1->setVy(20);
        }

        for(int i = 0; i < walls.size(); i++){
            if(jefe1->collidesWithItem(walls.at(i))){
                jefe1->setVy(-20);
            }
        }
    }

    for(int s = 0; s < Jugadores.size(); s++){
        if(jefe1->scene() == scene){
            if(jefe1->getBanDis() == true){
                if(jefe1->scene() == scene) scene->removeItem(jefe1);
                //delete jefe1;
            }
            else{
                int alt;
                std::uniform_int_distribution<int> Alt(1,2);
                alt = Alt(*QRandomGenerator::global());
                if(alt == 1){
                    if(pow(pow(Jugadores.at(0)->getPX()-jefe1->getPx(),2)+pow(Jugadores.at(0)->getPY()-jefe1->getPy(),2),0.5) <= jefe1->getRange()){
                        if(ataquebills.empty() && jefe1->getBanAttack() == false && jefe1->getBanSpown() == false && jefe1->getBanDeath() == false){
                            jefe1->getMove()->stop();
                            delete jefe1->getMove();
                            jefe1->setBanAttack(true);
                            jefe1->attack();
                            ataquebills.push_back(new billsattack(Jugadores.at(0)->getPX(),0));
                            scene->addItem(ataquebills.at(ataquebills.size()-1));
                        }
                    }
                }
                else if(alt == 2){
                    if(pow(pow(Jugadores.at(1)->getPX()-jefe1->getPx(),2)+pow(Jugadores.at(1)->getPY()-jefe1->getPy(),2),0.5) <= jefe1->getRange()){
                        if(ataquebills.empty() && jefe1->getBanAttack() == false && jefe1->getBanSpown() == false && jefe1->getBanDeath() == false){
                            jefe1->getMove()->stop();
                            delete jefe1->getMove();
                            jefe1->setBanAttack(true);
                            jefe1->attack();
                            ataquebills.push_back(new billsattack(Jugadores.at(1)->getPX(),0));
                            scene->addItem(ataquebills.at(ataquebills.size()-1));
                        }
                    }
                }

                if(!ataquebills.empty() && jefe1->getBanDeath() == false){
                    for(int b = 0; b < ataquebills.size(); b++){
                        for(int w = 0; w < walls.size(); w++){
                            if(ataquebills.at(b)->collidesWithItem(Jugadores.at(s)) || ataquebills.at(b)->collidesWithItem(walls.at(w))){
                                if(ataquebills.at(b)->collidesWithItem(Jugadores.at(s))){
                                    Jugadores.at(s)->setMuerte(Jugadores.at(s)->getMuerte()+1);
                                    if(Jugadores.at(s)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(s)->getMuerte());}
                                    else{ui->muertessteven->display(Jugadores.at(s)->getMuerte());}
                                }
                                ataquebills.at(b)->getTime()->stop();
                                delete ataquebills.at(b)->getTime();
                                scene->removeItem(ataquebills.at(b));
                                ataquebills.erase(ataquebills.begin()+b);
                                b--;
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::validateHammerAttack()//Función para validar el ataque de hammer
{
    if(onep){validateHammerOneP();}
    else if(multip){validateHammerMultiP();}
}

void MainWindow::validateHammerOneP() //Función para validar el ataque de hammer para el modo 1 jugador
{
    if(!ataqueHammer.empty()){
        for(int a = 0; a < ataqueHammer.size(); a++){
            for(int w = 0; w < walls.size(); w++){
                if(ataqueHammer.at(a)->collidesWithItem(lineDown) || ataqueHammer.at(a)->collidesWithItem(walls.at(w)) || ataqueHammer.at(a)->collidesWithItem(player1)){
                    if(ataqueHammer.at(a)->collidesWithItem(player1)){
                        player1->setMuerte(player1->getMuerte()+1);
                        if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
                        else{ui->muertessteven->display(player1->getMuerte());}
                    }
                    ataqueHammer.at(a)->getTiro()->stop();
                    scene->removeItem(ataqueHammer.at(a));
                    delete ataqueHammer.at(a)->getTiro();
                    ataqueHammer.erase(ataqueHammer.begin()+a);
                    a--;
                    break;
                }
            }
        }
    }
}

void MainWindow::validateHammerMultiP() //Función para validar el ataque de hammer para el modo 2 jugadores
{
    if(!ataqueHammer.empty()){
        for(int a = 0; a < ataqueHammer.size(); a++){
            for(int w = 0; w < walls.size(); w++){
                if(ataqueHammer.at(a)->collidesWithItem(lineDown) || ataqueHammer.at(a)->collidesWithItem(walls.at(w)) || ataqueHammer.at(a)->collidesWithItem(Jugadores.at(0)) || ataqueHammer.at(a)->collidesWithItem(Jugadores.at(1))){
                    if(ataqueHammer.at(a)->collidesWithItem(Jugadores.at(0))){
                        Jugadores.at(0)->setMuerte(Jugadores.at(0)->getMuerte()+1);
                        if(Jugadores.at(0)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(0)->getMuerte());}
                        else{ui->muertessteven->display(Jugadores.at(0)->getMuerte());}
                    }
                    if(ataqueHammer.at(a)->collidesWithItem(Jugadores.at(1))){
                        Jugadores.at(1)->setMuerte(Jugadores.at(1)->getMuerte()+1);
                        if(Jugadores.at(1)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(1)->getMuerte());}
                        else{ui->muertessteven->display(Jugadores.at(1)->getMuerte());}
                    }
                    ataqueHammer.at(a)->getTiro()->stop();
                    scene->removeItem(ataqueHammer.at(a));
                    delete ataqueHammer.at(a)->getTiro();
                    ataqueHammer.erase(ataqueHammer.begin()+a);
                    a--;
                    break;
                }
            }
        }
    }
}

void MainWindow::validateSrayMove() //Función para las validaciones para los movimientos del nivel 3
{
    if(onep){
        if(playermoves.size() == jefe2->getSmoves().size() && jefe2->getBanmove()){
            QVector<QString> jefemoves = jefe2->getSmoves();
            for(int i = 0; i < playermoves.size(); i++){
                if(playermoves.at(i) != jefemoves.at(i)){
                    player1->setMuerte(player1->getMuerte()+1);
                    if(player1->getKeyplayer() == 'g'){ui->muertesguy->display(player1->getMuerte());}
                    else{ui->muertessteven->display(player1->getMuerte());}
                    banDe = true;
                }
            }
            playermoves.clear();
            if(banDe){
                jefe2->setContS(0);
                banDe = false;
            }
            jefe2->setBanmove(false);
            jefemoves.clear();
            jefe2->setSmoves(jefemoves);
            jefe2->label();
        }
    }
    else if(multip){
        if(playermoves.size() == jefe2->getSmoves().size() && jefe2->getBanmove() && playermoves2.size() == jefe2->getSmoves().size()){
            QVector<QString> jefemoves = jefe2->getSmoves();
            for(int i = 0; i < playermoves.size(); i++){
                if(playermoves.at(i) != jefemoves.at(i)){
                    Jugadores.at(i)->setMuerte(Jugadores.at(i)->getMuerte()+1);
                    if(Jugadores.at(i)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(i)->getMuerte());}
                    else{ui->muertessteven->display(Jugadores.at(i)->getMuerte());}
                    banDe = true;
                }
                if(playermoves2.at(i) != jefemoves.at(i)){
                    Jugadores.at(i)->setMuerte(Jugadores.at(i)->getMuerte()+1);
                    if(Jugadores.at(i)->getKeyplayer() == 'g'){ui->muertesguy->display(Jugadores.at(i)->getMuerte());}
                    else{ui->muertessteven->display(Jugadores.at(i)->getMuerte());}
                    banDe2 = true;
                }
            }
            playermoves.clear();
            if(banDe || banDe2){
                jefe2->setContS(0);
                banDe = false;
                banDe2 = false;
            }
            jefe2->setBanmove(false);
            jefemoves.clear();
            jefe2->setSmoves(jefemoves);
            jefe2->label();
        }
    }

}

void MainWindow::detectC() // Función que detecta las colisiones del juego y cambio de nivel
{
    validateAttackGuy();
    validatePlayerMove();
    CollisionEnemy();
    if(numNivel == 1) validateBillsMove();
    if(numNivel == 3) validateSrayMove();
    validateHammerAttack();
    changeLevel();
}

void MainWindow::keyPressEvent(QKeyEvent *i) //Función que valida las teclas presionadas
{
    if(onep) validarmovimientosoneplayer(i);
    else if(multip) validarmovimientosMultiP(i);
}

void MainWindow::escribirArchivo(QString nom, QString modoj, int nivel, char dif, char tipo, int x, int y, int Vidas, char tipo1 = 'n', int x1 = -1, int y1 = -1, int Vidas1 = -1) //Función que permite escribir los datos del usuario en el archivo.
{
    ofstream archivo;
    archivo.open("juego.txt",ios::out | ios::app);
    if(onep){
        archivo << nom.toStdString() << "," << modoj.toStdString() <<"," << tipo << "," << nivel << "," << dif << "," << x << "," << y << "," << Vidas << endl;
    }
    else if(multip){
        archivo << nom.toStdString() << "," << modoj.toStdString() <<"," << nivel << "," << dif << "," << tipo << "," << x << "," << y << "," << Vidas << "," << tipo1 << "," << x1 << "," << y1 << "," << Vidas1 << endl;
    }
    archivo.close();
}

void MainWindow::leerArchivo() //Función que permite leer la información de un usuario
{
    ifstream tempo;
    char dato[100];
    char *puntero;
    string info;

    tempo.open("juego.txt", ios::in);
    tempo.getline(dato, sizeof(dato));
    while(!tempo.eof() && banU == false){
        puntero = strtok(dato,",");
        info = puntero;
        if(ui->nombre->text() == puntero){
            banU = true;
            puntero = strtok(NULL,",");
            info = puntero;
            if(info == "Onep"){
                onep = true;
                for(int o = 0; o < 6; o++){
                    if(o == 5){
                        puntero = strtok(NULL,"\n");
                        player1->setMuerte(atoi(puntero));
                    }
                    else{
                        puntero = strtok(NULL,",");
                        info = puntero;
                        if(o == 0){
                            if(*info.c_str() == 's') player1 = new player('s');
                            else if(*info.c_str() == 'g') player1 = new player('g');
                        }
                        else if(o == 1){
                            if(info == "1") numNivel = 1;
                            else if(info == "2") numNivel = 2;
                            else numNivel = 3;
                        }
                        else if(o == 2){
                            if(info == "f") dificultad = 'f';
                            else if(info == "n") dificultad = 'n';
                            else dificultad = 'd';
                        }
                        else if(o == 3){
                            player1->setPX(atoi(puntero));
                            if(atoi(puntero) >= 0 && atoi(puntero) < 1280) {W = 0;}
                            else if(atoi(puntero) >= 1280 && atoi(puntero) < 2560) {W = 1280;}
                            else if(atoi(puntero) >= 2560 && atoi(puntero) < 3840) {W = 2560;}
                            else {W = 3840;}
                        }
                        else if(o == 4){player1->setPY(atoi(puntero));}
                    }
                }
            }
            else if(info == "Multip"){
                multip = true;
                puntero = strtok(NULL,",");
                info = puntero;
                if(info == "1") numNivel = 1;
                else if(info == "2") numNivel = 2;
                else numNivel = 3;

                puntero = strtok(NULL,",");
                info = puntero;
                if(info == "f") dificultad = 'f';
                else if(info == "n") dificultad = 'n';
                else dificultad = 'd';

                for(int s = 0; s < 8; s++){
                    puntero = strtok(NULL,",");
                    info = puntero;
                    if(s == 0 || s == 4){
                        if(info == "g"){Jugadores.push_back(new player('g'));}
                        else if(info == "s"){Jugadores.push_back(new player('s'));}
                    }
                    else if(s == 1 || s == 5){
                        Jugadores.at(Jugadores.size()-1)->setPX(atoi(puntero));
                        if(atoi(puntero) >= 0 && atoi(puntero) < 1280) {W = 0;}
                        else if(atoi(puntero) >= 1280 && atoi(puntero) < 2560) {W = 1280;}
                        else if(atoi(puntero) >= 2560 && atoi(puntero) < 3840) {W = 2560;}
                        else {W = 3840;}
                    }
                    else if(s == 2 || s == 6) Jugadores.at(Jugadores.size()-1)->setPY(atoi(puntero));
                    else if(s == 3 || s == 7) Jugadores.at(Jugadores.size()-1)->setMuerte(atoi(puntero));
                }
            }

        }
        tempo.getline(dato, sizeof(dato));
    }
    tempo.close();
}

void MainWindow::ActualizarArchivo() // Función permite actualizar el archivo donde se guarda la información de todos los usuarios del juego.
{
    ifstream original;
    ofstream temporal;
    char linea[1000];
    char *puntero;
    string datos;

    original.open("juego.txt", ios::in);
    temporal.open("temporal.txt", ios::out);
    original.getline(linea,sizeof (linea));
    while(!original.eof()){
        datos = strtok(linea,"\n");
        puntero = strtok(linea,",");
        if(ui->nombre->text() != puntero){
            temporal << datos << endl;
        }
        original.getline(linea,sizeof (linea));
    }

    original.close();
    temporal.close();

    remove("juego.txt");
    rename("temporal.txt", "juego.txt");

    if(Guardar){
        if(onep){escribirArchivo(ui->nombre->text(),"Onep",numNivel,dificultad,player1->getKeyplayer(),player1->getPX(),player1->getPY(),player1->getMuerte());}
        else if(multip){escribirArchivo(ui->nombre->text(), "Multip", numNivel, dificultad, 'g', Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY(), Jugadores.at(0)->getMuerte(),'s',Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY(), Jugadores.at(0)->getMuerte());}
        Guardar = false;
    }
}

void MainWindow::on_iniciarsesion_clicked() //Botón de ingreso al juego
{
    ui->inicio->hide();
    ui->usuario->show();
    iniciars = true;
}

void MainWindow::on_registrarse_clicked() //Botón de registro en el sistema
{
    ui->inicio->hide();
    ui->usuario->show();
    registro = true;
}

void MainWindow::on_cancelar_clicked()
{
    if(ui->nombre->isModified()){
        ui->nombre->clear();
    }
    ui->usuario->hide();
    ui->inicio->show();

    iniciars = false;
    registro = false;
}

void MainWindow::on_aceptar_clicked() //Botón de Aceptar -> Valida el usuario ingresado
{
    if(iniciars){
        if(ui->nombre->isModified()){
            if(ui->nombre->text().length() > 3){

                ifstream tempo;
                char dato[100];
                char *puntero;

                tempo.open("juego.txt", ios::in);
                tempo.getline(dato, sizeof(dato));
                while(!tempo.eof() && banU == false){
                    puntero = strtok(dato,",");
                    if(ui->nombre->text() == puntero){
                        banU = true;
                        banUsuarioViejo = true;
                    }
                    tempo.getline(dato, sizeof(dato));
                }
                tempo.close();

                if(banU){
                    banU = false;
                    ui->usuario->hide();
                    ui->Partida->show();
                    ui->instruccion->show();
                }
                else{
                    QMessageBox message;
                    message.setWindowTitle("Error");
                    message.setText("No se encontró el nombre de usuario ingresado.");
                    message.exec();
                }
            }
            else{
                QMessageBox message;
                message.setWindowTitle("Error");
                message.setText("El nombre de usuario debe tener mínimo 4 letras.");
                message.exec();
            }
        }
        else{
            QMessageBox message;
            message.setWindowTitle("Error");
            message.setText("Debe llenar el campo Nombre Usuario");
            message.exec();
        }
    }
    else{
        if(ui->nombre->isModified()){
            if(ui->nombre->text().length() > 3){
                ifstream tempo;
                char dato[100];
                char *puntero;

                tempo.open("juego.txt", ios::in);
                tempo.getline(dato, sizeof(dato));
                while(!tempo.eof() && banU == false){
                    puntero = strtok(dato,",");
                    if(ui->nombre->text() == puntero){
                        banU = true;
                    }
                    tempo.getline(dato, sizeof(dato));
                }
                tempo.close();

                if(banU){
                    banU = false;
                    QMessageBox message;
                    message.setWindowTitle("Error");
                    message.setText("El nombre ya se encuentra registrado. Intente con uno nuevo.");
                    message.exec();
                }else{
                    ui->usuario->hide();
                    ui->Partida->show();
                    ui->cargarpartida->setEnabled(false);
                }
            }
            else{
                QMessageBox message;
                message.setWindowTitle("Error");
                message.setText("El nombre de usuario debe tener mínimo 4 letras.");
                message.exec();
            }
        }
        else{
            QMessageBox message;
            message.setWindowTitle("Error");
            message.setText("Debe llenar el campo Nombre Usuario");
            message.exec();
        }
    }
}

void MainWindow::on_cargarpartida_clicked()
{
    leerArchivo();
    banCargarP = true;

    if(onep){
        if(player1->getKeyplayer() == 'g'){
            ui->Muertes->show();
            ui->muertesguy->display(player1->getMuerte());
            ui->muertessteven->hide();
            ui->msteven->hide();
        }
        else{
            ui->Muertes->show();
            ui->muertessteven->display(player1->getMuerte());
            ui->mguy->hide();
            ui->muertesguy->hide();
        }
    }
    else{
        ui->Muertes->show();
        ui->muertesguy->display(Jugadores.at(0)->getMuerte());
        ui->muertessteven->display(Jugadores.at(1)->getMuerte());
    }

    setup_resorces();
    cargar_niveles(numNivel);

    collisions = new QTimer(this);
    connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
    collisions->start(50);
    setup_enemies();
    Dificultad();
}


void MainWindow::on_nuevapartida_clicked()
{
    ui->Partida->hide();
    ui->modojuego->show();
    ui->instruccion->show();
    if(banUsuarioViejo == false) numNivel = 1;
    else if(banUsuarioViejo){
        ActualizarArchivo();
        numNivel = 1;
    }
}

void MainWindow::on_oneplayer_clicked() //Botón modo de juego 1 Jugador
{
    ui->modojuego->hide();
    ui->dificultad->show();
    this->onep = true;
}

void MainWindow::on_multiplayer_clicked() // Botón modo de juego 2 Jugadores
{
    ui->modojuego->hide();
    ui->instruccion->hide();
    ui->dificultad->show();
    this->multip = true;
}

void MainWindow::on_instruccion_clicked()
{
    ui->instruccion->hide();
    ui->nota->show();
}

void MainWindow::on_regresar_clicked()
{
    ui->nota->hide();
    ui->instruccion->show();
}

void MainWindow::on_devolver_clicked()
{
    ui->personaje->hide();
    ui->dificultad->show();
}

void MainWindow::on_selectguy_clicked() //Función que permite ejecutar el juego en modo 1 Jugador con el personaje The Guy
{
    player1 = new player('g');
    ui->personaje->hide();
    ui->instruccion->hide();
    delete scene;

    setup_resorces();
    cargar_niveles(numNivel);

    if(onep) escribirArchivo(ui->nombre->text(),"Onep",numNivel,dificultad,player1->getKeyplayer(), player1->getPX(),player1->getPY(),player1->getMuerte());

    collisions = new QTimer(this);
    connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
    collisions->start(50);
    setup_enemies();
    Dificultad();
    ui->Muertes->show();
    ui->muertesguy->display(player1->getMuerte());
    ui->muertessteven->hide();
    ui->msteven->hide();
}

void MainWindow::on_selectsteven_clicked() //Función que permite ejecutar el juego en modo 1 Jugador con el personaje Steven
{
    ui->personaje->hide();
    ui->instruccion->hide();
    delete scene;

    player1 = new player('s');

    setup_resorces();
    cargar_niveles(numNivel);

    if(onep) escribirArchivo(ui->nombre->text(),"Onep",numNivel,dificultad,player1->getKeyplayer(), player1->getPX(),player1->getPY(),player1->getMuerte());

    collisions = new QTimer(this);
    connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
    collisions->start(50);
    setup_enemies();
    Dificultad();
    ui->Muertes->show();
    ui->muertessteven->display(player1->getMuerte());
    ui->mguy->hide();
    ui->muertesguy->hide();
}

void MainWindow::on_facil_clicked() // Botón de dificultad -> Fácil
{
    dificultad = 'f';
    ui->dificultad->hide();
    if(onep) ui->personaje->show();
    else if(multip){
        ui->instruccion->hide();
        delete scene;
        Jugadores.push_back(new player('g'));
        Jugadores.push_back(new player('s'));

        setup_resorces();
        cargar_niveles(numNivel);

        escribirArchivo(ui->nombre->text(), "Multip", numNivel, 'f', 'g', Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY(), Jugadores.at(0)->getMuerte(),'s',Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY(), Jugadores.at(0)->getMuerte());

        collisions = new QTimer(this);
        connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
        collisions->start(50);
        setup_enemies();
        Dificultad();
        ui->Muertes->show();
        ui->muertesguy->display(Jugadores.at(0)->getMuerte());
        ui->muertessteven->display(Jugadores.at(1)->getMuerte());
    }
}

void MainWindow::on_normal_clicked() // Botón de dificultad -> Normal
{
    dificultad = 'n';
    ui->dificultad->hide();
    if(onep) ui->personaje->show();
    else if(multip){
        ui->instruccion->hide();
        delete scene;
        Jugadores.push_back(new player('g'));
        Jugadores.push_back(new player('s'));

        setup_resorces();
        cargar_niveles(numNivel);

        escribirArchivo(ui->nombre->text(), "Multip", numNivel, 'n', 'g', Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY(), Jugadores.at(0)->getMuerte(),'s',Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY(), Jugadores.at(0)->getMuerte());

        collisions = new QTimer(this);
        connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
        collisions->start(50);
        setup_enemies();
        Dificultad();
        ui->Muertes->show();
        ui->muertesguy->display(Jugadores.at(0)->getMuerte());
        ui->muertessteven->display(Jugadores.at(1)->getMuerte());
    }
}

void MainWindow::on_dificil_clicked() // Botón de dificultad -> Difícil
{
    dificultad = 'd';
    ui->dificultad->hide();
    if(onep) ui->personaje->show();
    else if(multip){
        ui->instruccion->hide();
        delete scene;
        Jugadores.push_back(new player('g'));
        Jugadores.push_back(new player('s'));

        setup_resorces();
        cargar_niveles(numNivel);

        escribirArchivo(ui->nombre->text(), "Multip", numNivel, 'd', 'g', Jugadores.at(0)->getPX(),Jugadores.at(0)->getPY(), Jugadores.at(0)->getMuerte(),'s',Jugadores.at(1)->getPX(),Jugadores.at(1)->getPY(), Jugadores.at(0)->getMuerte());

        collisions = new QTimer(this);
        connect(collisions, SIGNAL(timeout()), this, SLOT(detectC()));
        collisions->start(50);
        setup_enemies();
        Dificultad();
        ui->Muertes->show();
        ui->muertesguy->display(Jugadores.at(0)->getMuerte());
        ui->muertessteven->display(Jugadores.at(1)->getMuerte());
    }
}

void MainWindow::on_actionGuardar_Partida_triggered() // Función para Guardar la partida del Jugador
{
    Guardar = true;
    ActualizarArchivo();
}

void MainWindow::on_actionSalir_triggered() // Función que permite salir del entorno de Juego
{
    reproducir->stop();
    QApplication::exit();
}

MainWindow::~MainWindow()
{
    clean_levels();
    delete ui;
    delete scene;
    if(numNivel == 3) delete jefe2;
    if(onep){delete player1;}
    delete reproducir;
    delete collisions;
    delete lineDown;
    delete lineLeft;
    delete lineRight;
    delete lineUp;
    delete reproducir;
    if(multip){
        for(int i = 0; i < Jugadores.size(); i++){
            Jugadores.erase(Jugadores.begin()+i);
            i -= 1;
        }
    }
}

