#include "sray.h"

sray::sray(int x, int y, QLabel *obj)
{
    px = x;
    py = y;
    setPixmap(QPixmap(move[0]).scaled(tam,tam));
    setPos(x,y);

    objeto = obj;

    label();
}

void sray::label()
{
    timeL = new QTimer();
    connect(timeL, SIGNAL(timeout()), this, SLOT(labelmove()));
    timeL->start(600);
}

void sray::tiempo()
{
    time = new QTimer();
    connect(time, SIGNAL(timeout()), this, SLOT(Atiempo()));
    time->start(50);
}

void sray::baile()
{
    bandance = true;
    if(contS < 28){
        pos = secuencias[contS].toInt();
        for(int i = 0; i < pos; i++){
            std::uniform_int_distribution<int> Fila(1,4);
            dato = Fila(*QRandomGenerator::global());
            if(dato == 1) smoves.push_back("Up");
            else if(dato == 2) smoves.push_back("Down");
            else if(dato == 3) smoves.push_back("Right");
            else smoves.push_back("Left");
        }
    }
    contS += 1;
    pos = 0;
}

void sray::labelmove()
{
    if(bandance == false){
        baile();
    }

    if(l < smoves.size()){
        xl = px+100;
        yl = py-25;
        objeto->show();
        objeto->setText(smoves.at(l));

        objeto->setGeometry(xl,yl,objeto->width(),objeto->height());
        tiempo();

        if(banaudio){
            banaudio = false;
            audio->pause();
            delete audio;
        }

        if(smoves.at(l) == "Down"){
            audio = new QMediaPlayer();
            audio->setMedia(QUrl("qrc:/Imagenes/Audio/Down.mp3"));
            audio->play();
            banaudio = true;
            setPixmap(QPixmap(move[1]).scaled(tam,tam));
        }
        else if(smoves.at(l) == "Up"){
            audio = new QMediaPlayer();
            audio->setMedia(QUrl("qrc:/Imagenes/Audio/Up.mp3"));
            audio->play();
            banaudio = true;
            setPixmap(QPixmap(move[4]).scaled(tam,tam));
        }
        else if(smoves.at(l) == "Left"){
            audio = new QMediaPlayer();
            audio->setMedia(QUrl("qrc:/Imagenes/Audio/Left.mp3"));
            audio->play();
            banaudio = true;
            setPixmap(QPixmap(move[2]).scaled(tam,tam));
        }
        else{
            banaudio = true;
            audio = new QMediaPlayer();
            audio->setMedia(QUrl("qrc:/Imagenes/Audio/Right.mp3"));
            audio->play();
            setPixmap(QPixmap(move[3]).scaled(tam,tam));
        }

        l += 1;
    }
    else{
        bandance = false;
        banmove = true;
        l = 0;
        timeL->stop();
        delete timeL;
    }
}

void sray::Atiempo()
{
    if(contM == 6){
        contM = 0;
        objeto->hide();
        time->stop();
        delete time;
    }
    else{

        xl += 10;
        yl -= 20;
        objeto->setGeometry(xl,yl,objeto->width(),objeto->height());
        contM++;
    }
}





















