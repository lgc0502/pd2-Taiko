#include "drum.h"
#include<QTimer>
#include<QGraphicsScene>

drum::drum()
{
    setPixmap(QPixmap(":/new/prefix1/drum-7.png"));

    QTimer * timer= new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void drum::move()
{
    setPos(x()-10,y());
}
