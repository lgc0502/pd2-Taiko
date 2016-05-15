#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewindow.h"
#include "ui_gamewindow.h"
#include<QMediaPlayer>

QMediaPlayer *music=new QMediaPlayer();


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_2->setScaledContents(true);

    ui->easy->hide();
    ui->hard->hide();
    ui->re->hide();


    music->setMedia(QUrl("qrc:/music/videoplayback6.mp3"));
    music->play();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    ui->startButton->hide();
    ui->pushButton_2->hide();
    ui->easy->show();
    ui->hard->show();
    ui->re->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

void MainWindow::on_easy_clicked()
{
       music->stop();
       game=new gameWindow(this) ;
       game->show();
}

void MainWindow::on_hard_clicked()
{
    music->stop();
    hard=new hardWindow(this) ;
    hard->show();
}

void MainWindow::on_re_clicked()
{
    ui->easy->hide();
    ui->hard->hide();
    ui->re->hide();
    ui->pushButton_2->show();
    ui->startButton->show();
}
