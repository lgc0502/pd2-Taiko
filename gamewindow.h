#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
//#include"scorewindow.h"

namespace Ui {
class gameWindow;
}

class gameWindow : public QMainWindow
{

    Q_OBJECT

public:
    void keyPressEvent(QKeyEvent *event=0);

    explicit gameWindow(QWidget *parent = 0);
    ~gameWindow();
//    scoreWindow *score;

private slots:
    void movedrum1();
    void movedrum2();
    void movedrum3();
    void movedrum4();
    void movedrum5();
    void movedrum6();

    void showTime();

    void showscore();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::gameWindow *ui;
    int count_time;
    int x1,x2,x3,x4,x5,x6;
    int a;
    int v,y;
    int score_num;
    gameWindow *game;



};

#endif // GAMEWINDOW_H
