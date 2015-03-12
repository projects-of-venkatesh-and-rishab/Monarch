#ifndef BOARD_H
#define BOARD_H

#include <QGridLayout>
#include <QWidget>
#include <QPushButton>
#include "board.h"
#include <QDialog>
#include <QLabel>
#include <QTime>
#include <qtimer.h>
class Button:public QPushButton{
    Q_OBJECT
public:
        int row,column;
        bool color;
private:
        bool is_present;
        int N;

public:
       Button(int r=0, int c=0,QWidget *parent=0,int n=0);
       void setcolor(bool);
public slots:
        void assignicon();
};

class Board :public Button{
    Q_OBJECT
private:
    QGridLayout* grid;
    int N;
    QLabel *l2;
    QLabel *l4,*moves;
    QVector <Button*> container;
    QVector <Button*> container1;
    QVector <int **> container_solution;
    int **q2;
    int r1,r2;
    int count_solution,tot_soln;
    int mode;
    int type;

public:
    Board(int,int,int type=0,int winx=0, int winy=0,QLabel *l=0);
    QGridLayout* returnGrid();
    void disable(int,int,bool);
    bool accept(int**,int,int);
    void solve_state(int**,int);
    void changeLabel(int);
    void update_score();
    void print_solution(int **);
public slots:
    void clear_board();
    void solutions();
    void next_solution();
};

#endif // BOARD_H
