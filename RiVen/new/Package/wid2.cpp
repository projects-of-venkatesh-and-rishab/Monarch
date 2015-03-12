#include "wid2.h"
#include "ui_wid2.h"
#include <QDesktopWidget>
#include <time.h>

wid2::wid2(QWidget* par) :
    QWidget(par),
    ui(new Ui::wid2)
{
    QDesktopWidget *desk = QApplication::desktop();

    int x = desk->width();
    int y = desk->height();

    parent = par;
    ui->setupUi(this);
    setLayout(ui->gridLayout_2);
    ui->pushButton_4->setFixedSize(x/5.4,y/15.36);
    ui->pushButton_5->setFixedSize(x/5.4,y/15.36);
    ui->pushButton_6->setFixedSize(x/5.4,y/15.36);
    setWindowTitle("Select The Level");
}

wid2::~wid2()
{
    delete ui;
}

void wid2::on_pushButton_5_clicked() // easy
{
    srand(time(0));
    int r =abs(rand())%3+7;
    a= new Game(r,0,1,this,parent);
    a->show();
}

void wid2::on_pushButton_4_clicked() // medium
{
    srand(time(0));
    int r =abs(rand())%5+8;
    a= new Game(r,0,2,this,parent);
    a->show();
}

void wid2::on_pushButton_6_clicked()
{
    srand(time(0));
    int r =abs(rand())%4+11;
    a= new Game(r,1,3,this,parent);
    a->show();
}
