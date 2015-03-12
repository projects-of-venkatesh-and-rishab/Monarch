#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QWidget>
#include "board.h"

class Button:public QPushButton{
    Q_OBJECT
private:
        int row,column;
        bool color;
        bool is_present;      
protected:
        static QVector <Button*> container;
public:
       Button(int r=0,int c=0,QWidget *parent=0);
       void setcolor(bool);
       bool check(int,int);
       Button* valueAt(int,int);
public slots:
        void assignicon();
};

static QVector<Button*> Button::container.at(1) = {new Button*};

#endif // BUTTON_H
