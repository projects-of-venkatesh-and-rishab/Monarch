#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QDesktopWidget>
#include <QApplication>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QWidget>

class Game:public QMainWindow{
private:
    QHBoxLayout *vbox,*v_boxh;
    QWidget *wid,*vboxwid,*widparent;
    QGridLayout *grid;
    QDesktopWidget *dp;
    QVBoxLayout *v_box1,*v_box2;
    QPushButton *b1;
    QPushButton *b2;
    QLabel *l1,*l2,*l3,*l4,*l5;

public:
    Game(int, int, int type = 0, QWidget *parent=0, QWidget* p=0);
    ~Game();
};

#endif // GAME_H
