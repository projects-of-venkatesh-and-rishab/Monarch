#include "wid1.h"
#include "ui_wid1.h"
#include <QDesktopWidget>
#include <QMessageBox>
wid1::wid1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::wid1)
{
    QDesktopWidget *desk = QApplication::desktop();

    int x = desk->width();
    int y = desk->height();

    ui->setupUi(this);
    resize(x/3.4,y/2.1);
    setLayout(ui->gridLayout);
    ui->pushButton->setFixedSize(x/5.4,y/15.36);
    ui->pushButton_2->setFixedSize(x/5.4,y/15.36);
    ui->pushButton_3->setFixedSize(x/5.4,y/15.36);
    setWindowTitle("RiVen");
}

wid1::~wid1()
{
    delete ui;
}

void wid1::on_pushButton_clicked()
{
    a = new wid2(this);
    a->show();
}
void wid1::go_off(){
    close();
}

void wid1::on_pushButton_2_clicked()
{
    QMessageBox *a= new QMessageBox;
    a->setText("The Riven Game is all about Easy(Nqueen),Medium(Nqueen),Hard(Super Queen)\nRules:\n\n\n\n(i)In Easy and Medium Mode A Queen will be placed in random place and \n  the user has to arrange the remaining queens in NxN chess board and \n  see to it that there are no clashes between the queens placed \n\n\n\n (ii)In Hard Mode A Queen will be placed in random place on the board and \n the Superqueen will have the power of queen and also knight . Arrange N superqueeens in the board and see to it that there are no clashes between the Superqueens placed ");
    a->show();
}

void wid1::on_pushButton_3_clicked()
{
    connect(ui->pushButton_3,SIGNAL(clicked()),qApp,SLOT(quit()));
}
