#ifndef TEST_H
#define TEST_H

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QHideEvent>
class temp : public QPushButton{
    Q_OBJECT
public:
    QPushButton *bt;
    bool summa;

    temp(QWidget* wid){
        summa = false;
        bt = new QPushButton(wid);
        bt->setStyleSheet("* { background-color: rgb(0,0,0) }");
        connect(bt,SIGNAL(clicked()),this,SLOT(assign()));
    }

public slots:
    void assign(){
        if(!summa)
            bt->setIcon(QIcon("../Package/Venky/chess pics/Black_King.bmp"));
        else
            bt->setIcon(QIcon(""));
        summa = !summa;
    }
};

#endif // TEST_H
