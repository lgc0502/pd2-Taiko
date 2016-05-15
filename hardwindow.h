#ifndef HARDWINDOW_H
#define HARDWINDOW_H

#include <QMainWindow>

namespace Ui {
class hardWindow;
}

class hardWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit hardWindow(QWidget *parent = 0);
    void keyPressEvent(QKeyEvent *event=0);
    ~hardWindow();

private slots:
    void showpicture();
    void showhardtime();
    void showpicture1();
    void movedrum1();
    void movedrum2();
    void movedrum3();
    void movedrum4();
    void movedrum5();
    void movedrum6();
    void moveflower();
    void hshowscore();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::hardWindow *ui;
    hardWindow *hard;
    int pix;
    int contime;
    int y;
    int fx,fy;
    int h1,h2,h3,h4,h5,h6;
    int v1,v2,v3,v4,v5,v6;
    int hscore_num;
};

#endif // HARDWINDOW_H
