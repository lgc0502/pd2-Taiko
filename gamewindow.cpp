#include "gamewindow.h"
#include "ui_gamewindow.h"
//#include"scorewindow.h"
#include<QTimer>
#include<QDateTime>
#include<QObject>
#include<stdlib.h>
#include<time.h>
#include<QKeyEvent>
#include<QDebug>
#include<QMediaPlayer>
#include<QPixmap>

QMediaPlayer *bgmusic =new QMediaPlayer();
QMediaPlayer *music_1 =new QMediaPlayer();
QMediaPlayer *scoremusic =new QMediaPlayer();
QMediaPlayer *drumluffy =new QMediaPlayer();
QTimer *timer=new QTimer();

gameWindow::gameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::gameWindow)
{
    ui->setupUi(this);

    bgmusic->setMedia(QUrl("qrc:/music/videoplayback_8_.mp3"));
    music_1->setMedia(QUrl("qrc:/music/videoplayback6.mp3"));
    scoremusic->setMedia(QUrl("qrc:/music/videoplayback_5_.mp3"));
    drumluffy->setMedia(QUrl("qrc:/musicdrum/Gomu_Gomu_Nonew.mp3"));

    bgmusic->play();

    ui->scorewin->hide();
    ui->scorescore->hide();
  //  ui->label_3->hide();
    ui->pushButton_2->hide();
     ui->pushButton_3->hide();

    ui->label->setScaledContents(true);
    ui->drum1->setScaledContents(true);
    ui->drum2->setScaledContents(true);
    ui->drum3->setScaledContents(true);
    ui->drum4->setScaledContents(true);
    ui->drum5->setScaledContents(true);
    ui->drum6->setScaledContents(true);
    ui->scorewin->setScaledContents(true);
    ui->scorescore->setScaledContents(true);


   // ui->right_place->setScaledContents(true);

    v=3;
    y=525;
    score_num=0;
    count_time=3000;
    x1=(rand()%2000)+1200;
    x2=(rand()%2000)+1200;
    x3=(rand()%2000)+1200;
    x4=(rand()%2000)+1200;
    x5=(rand()%2000)+1200;
    x6=(rand()%2000)+1200;


    //QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movedrum1()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movedrum2()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movedrum3()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movedrum4()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movedrum5()));
    connect(timer,SIGNAL(timeout()),this,SLOT(movedrum6()));



    timer->start(10);


}
void gameWindow::keyPressEvent(QKeyEvent *event){

    if(x1>=30&&x1<=120){
        if(event->key()==Qt::Key_F){
            score_num++;
            x1=(rand()%2000)+1200;
            ui->drum1->move(x1,y);
            QString score_text;
            score_text=QString::number(score_num);
            ui->scorenum->setText(score_text);
        }
    }
    if(x2>=30&&x2<=120){
        if(event->key()==Qt::Key_J){
            score_num++;
            x2=(rand()%2000)+1200;
            ui->drum2->move(x2,y);
            QString score_text;
            score_text=QString::number(score_num);
            ui->scorenum->setText(score_text);
        }
    }
    if(x3>=30&&x3<=120){
        if(event->key()==Qt::Key_F){
            score_num++;
            x3=(rand()%2000)+1200;
            ui->drum3->move(x3,y);
            QString score_text;
            score_text=QString::number(score_num);
            ui->scorenum->setText(score_text);
        }
    }
    if(x4>=30&&x4<=120){
        if(event->key()==Qt::Key_J){
            score_num++;
            x4=(rand()%2000)+1200;
            ui->drum4->move(x4,y);
            QString score_text;
            score_text=QString::number(score_num);
            ui->scorenum->setText(score_text);
        }
    }
    if(x5>=30&&x5<=120){
        if(event->key()==Qt::Key_F){
            score_num++;
            x5=(rand()%2000)+1200;
            ui->drum5->move(x5,y);
            QString score_text;
            score_text=QString::number(score_num);
            ui->scorenum->setText(score_text);
        }
    }
    if(x6>=30&&x6<=120){
        if(event->key()==Qt::Key_J){
            score_num++;
            x6=(rand()%2000)+1200;
            ui->drum6->move(x6,y);
            QString score_text;
            score_text=QString::number(score_num);
            ui->scorenum->setText(score_text);
        }
    }

}

void gameWindow::movedrum6()
{
    if(count_time==0){
        ui->drum6->move(1200,y);
    }
    else{
        x6=x6-v;
        if(x6<-100){
            x6=(rand()%2000)+1200;
            ui->drum6->move(x6,y);
        }
        else{
            ui->drum6->move(x6,y);
        }
    }
}
void gameWindow::movedrum5()
{
    if(count_time==0){
        ui->drum5->move(1200,y);
    }
    else{
        x5=x5-v;
        if(x5<-100){
            x5=(rand()%2000)+1200;
            ui->drum5->move(x5,y);
        }
        else{
            ui->drum5->move(x5,y);
        }
    }
}
void gameWindow::movedrum4()
{
    if(count_time==0){
        ui->drum4->move(1200,y);
    }
    else{
        x4=x4-v;
        if(x4<-100){
            x4=(rand()%2000)+1200;
            ui->drum4->move(x4,y);
        }
        else{
            ui->drum4->move(x4,y);
        }
    }
}
void gameWindow::movedrum3()
{
    if(count_time==0){
        ui->drum3->move(1200,y);
    }
    else{
        x3=x3-v;
        if(x3<-100){
            x3=(rand()%2000)+1200;
            ui->drum3->move(x3,y);
        }
        else{
            ui->drum3->move(x3,y);
        }
    }
}
void gameWindow::movedrum2()
{
    if(count_time==0){
        ui->drum2->move(1200,y);
    }
    else{
        x2=x2-v;
        if(x2<-100){
            x2=(rand()%2000)+1200;
            ui->drum2->move(x2,y);
        }
        else{
            ui->drum2->move(x2,y);
        }
    }
}
void gameWindow::movedrum1()
{

        x1=x1-v;

        if(x1<-100){
            x1=(rand()%2000)+1200;
            ui->drum1->move(x1,y);
        }
        else{
            ui->drum1->move(x1,y);
        }

}

void gameWindow::showTime()
{
    count_time--;
    if(count_time<0){
        timer->stop();
        gameWindow::showscore();
    }

    if(count_time>=0){
        QString time_text;
        time_text=QString::number(count_time/100);
        ui->clock->setText(time_text);
    }
}

void gameWindow::showscore(){

    bgmusic->stop();
    scoremusic->play();
    ui->clock->hide();
    ui->drum1->hide();
    ui->drum2->hide();
    ui->drum3->hide();
    ui->drum4->hide();
    ui->drum5->hide();
    ui->drum6->hide();
    ui->label->hide();
   // ui->label_2->hide();
   // ui->label_4->hide();
    ui->pushButton->hide();
  //  ui->right_place->hide();
    ui->scorenum->hide();
    ui->scorewin->show();
  //  ui->label_3->show();
    ui->pushButton_2->show();
     ui->pushButton_3->show();


    QString score_text;
    score_text=QString::number(score_num);
    ui->scorescore->setText(score_text);
    ui->scorescore->show();

}

gameWindow::~gameWindow()
{
    delete ui;
}


void gameWindow::on_pushButton_clicked()
{
    this->close();
    music_1->play();
    bgmusic->stop();

}

void gameWindow::on_pushButton_2_clicked()
{
   count_time=3000;
   score_num=0;
   timer->start();
   ui->scorewin->hide();
   ui->pushButton_2->hide();
   ui->scorescore->hide();
   ui->clock->show();
    ui->drum1->show();
    ui->drum2->show();
    ui->drum3->show();
    ui->drum4->show();
    ui->drum5->show();
    ui->drum6->show();
    ui->label->show();
    ui->pushButton->show();

    QString score_text;
    score_text=QString::number(score_num);
    ui->scorenum->setText(score_text);
    ui->scorenum->show();
    ui->pushButton_3->hide();
    scoremusic->stop();
    bgmusic->play();

}

void gameWindow::on_pushButton_3_clicked()
{
    this->close();
    scoremusic->stop();
    music_1->play();
}
