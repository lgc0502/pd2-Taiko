#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gamewindow.h"
//#include"scorewindow.h"
#include"hardwindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_startButton_clicked();

    void on_pushButton_2_clicked();

    void on_easy_clicked();

    void on_hard_clicked();

    //void on_pushButton_clicked();

    void on_re_clicked();

private:
    Ui::MainWindow *ui;
    gameWindow *game;
    hardWindow *hard;
};

#endif // MAINWINDOW_H
