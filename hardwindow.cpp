#include "hardwindow.h"
#include "ui_hardwindow.h"
#include<QTimer>
#include<QObject>
#include<QDateTime>
#include<stdlib.h>
#include<time.h>
#include<QKeyEvent>
#include<QDebug>
#include<QMediaPlayer>
#include<QPixmap>

QTimer *timer1=new QTimer();
QMediaPlayer *bgmusic1 =new QMediaPlayer();
QMediaPlayer *hmusic_1 =new QMediaPlayer();
QMediaPlayer *hscoremusic =new QMediaPlayer();

hardWindow::hardWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::hardWindow)
{
    ui->setupUi(this);

    bgmusic1->setMedia(QUrl("qrc:/music/videoplayback_8_.mp3"));
    hmusic_1->setMedia(QUrl("qrc:/music/videoplayback6.mp3"));
    hscoremusic->setMedia(QUrl("qrc:/music/videoplayback_5_.mp3"));
    bgmusic1->play();

    ui->label->setGeometry(0,0,1400,700);
    ui->label_2->setGeometry(0,0,1400,700);
    ui->label_3->setGeometry(0,0,1400,700);
    ui->label_4->setGeometry(0,0,1400,700);
    ui->label_5->setGeometry(0,0,1400,700);
    ui->label_6->setGeometry(0,0,1400,700);
    ui->label_7->setGeometry(0,0,1400,700);
    ui->label_8->setGeometry(0,0,1400,700);
    ui->label_9->setGeometry(0,0,1400,700);


    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
    ui->label_3->setScaledContents(true);
    ui->label_4->setScaledContents(true);
    ui->label_5->setScaledContents(true);
    ui->label_6->setScaledContents(true);
    ui->label_7->setScaledContents(true);
    ui->label_8->setScaledContents(true);
    ui->label_9->setScaledContents(true);
    ui->label_10->setScaledContents(true);
    ui->hdrum1->setScaledContents(true);
    ui->hdrum2->setScaledContents(true);
    ui->hdrum3->setScaledContents(true);
    ui->hdrum4->setScaledContents(true);
    ui->hdrum5->setScaledContents(true);
    ui->hdrum6->setScaledContents(true);
    ui->flower->setScaledContents(true);


    ui->label->show();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->label_10->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

    pix=1;
    contime=3000;
    y=210;
    hscore_num=0;
    h1=(rand()%2000)+1400;
    h2=(rand()%2000)+1400;
    h3=(rand()%2000)+1400;
    h4=(rand()%2000)+1400;
    h5=(rand()%2000)+1400;
    h6=(rand()%2000)+1400;
    fx=(rand()%1400);
    fy=0;
    v1=(rand()%3)+2;
    v2=(rand()%3)+2;
    v3=(rand()%3)+2;
    v4=(rand()%3)+2;
    v5=(rand()%3)+2;
    v6=(rand()%3)+2;

    ui->hdrum1->move(h1,500);
    ui->hdrum2->move(h2,500);
    ui->hdrum3->move(h3,500);
    ui->hdrum4->move(h4,500);
    ui->hdrum5->move(h5,500);
    ui->hdrum6->move(h6,500);

    connect(timer1,SIGNAL(timeout()),this,SLOT(showpicture()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(showhardtime()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(movedrum1()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(movedrum2()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(movedrum3()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(movedrum4()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(movedrum5()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(movedrum6()));
    connect(timer1,SIGNAL(timeout()),this,SLOT(moveflower()));

    timer1->start(10);

}

void hardWindow::keyPressEvent(QKeyEvent *event){

    if(h1>=80&&h1<=150){
        if(event->key()==Qt::Key_F){
            hscore_num++;
            h1=(rand()%2000)+1400;
            ui->hdrum1->move(h1,y);
            QString hscore_text;
            hscore_text=QString::number(hscore_num);
            ui->hscorenum->setText(hscore_text);
        }
    }
    if(h2>=80&&h2<=150){
        if(event->key()==Qt::Key_J){
           hscore_num++;
            h2=(rand()%2000)+1400;
            ui->hdrum2->move(h2,y);
            QString hscore_text;
            hscore_text=QString::number(hscore_num);
            ui->hscorenum->setText(hscore_text);
        }
    }
    if(h3>=80&&h3<=150){
        if(event->key()==Qt::Key_F){
            hscore_num++;
            h3=(rand()%2000)+1400;
            ui->hdrum3->move(h3,y);
            QString hscore_text;
            hscore_text=QString::number(hscore_num);
            ui->hscorenum->setText(hscore_text);
        }
    }
    if(h4>=80&&h4<=150){
        if(event->key()==Qt::Key_J){
            hscore_num++;
            h4=(rand()%2000)+1400;
            ui->hdrum4->move(h4,y);
            QString hscore_text;
            hscore_text=QString::number(hscore_num);
            ui->hscorenum->setText(hscore_text);
        }
    }
    if(h5>=80&&h5<=150){
        if(event->key()==Qt::Key_F){
            hscore_num++;
            h5=(rand()%2000)+1400;
            ui->hdrum5->move(h5,y);
            QString hscore_text;
            hscore_text=QString::number(hscore_num);
            ui->hscorenum->setText(hscore_text);
        }
    }
    if(h6>=80&&h6<=150){
        if(event->key()==Qt::Key_J){
            hscore_num++;
            h6=(rand()%2000)+1400;
            ui->hdrum6->move(h6,y);
            QString hscore_text;
            hscore_text=QString::number(hscore_num);
            ui->hscorenum->setText(hscore_text);
        }
    }

}
void hardWindow::showpicture(){
    if((contime%50)==0){
        pix++;
        showpicture1();
    }
}
void hardWindow::showpicture1(){
    if((pix%9)==1){
        ui->label->show();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==2){
        ui->label->hide();
        ui->label_2->show();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==3){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->show();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==4){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->show();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==5){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->show();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==6){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->show();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==7){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->show();
        ui->label_8->hide();
        ui->label_9->hide();
    }
    if((pix%9)==8){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->show();
        ui->label_9->hide();
    }
    if((pix%9)==0){
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->label_8->hide();
        ui->label_9->show();
    }

}
void hardWindow::showhardtime(){

    contime--;
    if(contime<0){
        timer1->stop();
        hardWindow::hshowscore();
    }

    if(contime>=0){
        QString time_text;
        time_text=QString::number(contime/100);
        ui->hclock->setText(time_text);
    }
}
void hardWindow::moveflower(){
    if(contime==0){
        ui->flower->move(1400,-100);
    }
    else{

              fy=fy+5;
              if(fy==700){
                  fx=(rand()%1000);
                  ui->flower->move(fx,-100);

              }
              else{
                  ui->flower->move(fx,fy);
              }

    }
}
void hardWindow::hshowscore(){
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->label_8->hide();
    ui->label_9->hide();
    ui->hdrum1->hide();
    ui->hdrum2->hide();
    ui->hdrum3->hide();
    ui->hdrum4->hide();
    ui->hdrum5->hide();
    ui->hdrum6->hide();
    ui->hscorenum->hide();
    ui->flower->hide();
    ui->hclock->hide();
    ui->pushButton->hide();
    ui->label_10->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();
    QString hscore_text;
    hscore_text=QString::number(hscore_num);
    ui->score_score->setText(hscore_text);
    bgmusic1->stop();
    hscoremusic->play();


}

void hardWindow::movedrum1(){

    if(contime==0){
        ui->hdrum1->move(1400,y);
    }
    else{
        h1=h1-v1;
        if(h1<-100){
            h1=(rand()%600)+1400;
            ui->hdrum1->move(h1,y);
            v1=(rand()%3)+2;
        }
        else{
            ui->hdrum1->move(h1,y);
        }
    }
}
void hardWindow::movedrum2(){

    if(contime==0){
        ui->hdrum2->move(1400,y);
    }
    else{
        h2=h2-v2;
        if(h2<-100){
            h2=(rand()%600)+1400;
            ui->hdrum2->move(h2,y);
            v2=(rand()%3)+2;
        }
        else{
            ui->hdrum2->move(h2,y);
        }
    }
}
void hardWindow::movedrum3(){

    if(contime==0){
        ui->hdrum3->move(1400,y);
    }
    else{
        h3=h3-v3;
        if(h3<-100){
            h3=(rand()%600)+1400;
            ui->hdrum3->move(h3,y);
            v3=(rand()%3)+2;
        }
        else{
            ui->hdrum1->move(h3,y);
        }
    }
}
void hardWindow::movedrum4(){

    if(contime==0){
        ui->hdrum4->move(1400,y);
    }
    else{
        h4=h4-v4;
        if(h4<-100){
            h4=(rand()%600)+1400;
            ui->hdrum4->move(h4,y);
            v4=(rand()%3)+2;
        }
        else{
            ui->hdrum4->move(h4,y);
        }
    }
}
void hardWindow::movedrum5(){

    if(contime==0){
        ui->hdrum5->move(1400,y);
    }
    else{
        h5=h5-v5;
        if(h5<-100){
            h5=(rand()%600)+1400;
            ui->hdrum5->move(h5,y);
            v5=(rand()%3)+2;
        }
        else{
            ui->hdrum5->move(h5,y);
        }
    }
}
void hardWindow::movedrum6(){

    if(contime==0){
        ui->hdrum6->move(1400,y);
    }
    else{
        h6=h6-v6;
        if(h6<-100){
            h6=(rand()%600)+1400;
            ui->hdrum6->move(h6,y);
            v6=(rand()%3)+2;
        }
        else{
            ui->hdrum6->move(h6,y);
        }
    }
}

hardWindow::~hardWindow()
{
    delete ui;
}

void hardWindow::on_pushButton_clicked()
{
    bgmusic1->stop();
    hmusic_1->play();
    this->close();
}

void hardWindow::on_pushButton_3_clicked()
{
    hscoremusic->stop();
    this->close();
}

void hardWindow::on_pushButton_2_clicked()
{
    contime=3000;
    hscore_num=0;
    timer1->start();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    ui->label_4->show();
    ui->label_5->show();
    ui->label_6->show();
    ui->label_7->show();
    ui->label_8->show();
    ui->label_9->show();
    ui->hdrum1->show();
    ui->hdrum2->show();
    ui->hdrum3->show();
    ui->hdrum4->show();
    ui->hdrum5->show();
    ui->hdrum6->show();
    QString hscore_text;
    hscore_text=QString::number(hscore_num);
    ui->score_score->setText(hscore_text);
    ui->hscorenum->show();
    ui->flower->show();
    ui->hclock->show();
    ui->pushButton->show();
    ui->label_10->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->score_score->hide();

    bgmusic1->play();
    hscoremusic->stop();
}
