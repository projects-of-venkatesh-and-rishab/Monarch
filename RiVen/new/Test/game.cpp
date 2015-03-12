#include <game.h>
#include <board.h>
#include <QFile>
#include <QTextStream>
Game::Game(int N,int m,int type, QWidget *parent,QWidget *par):QMainWindow(parent){
    widparent = par;
    dp =  QApplication ::desktop();
    int x=dp->width();
    int y=dp->height();
    int winx=x*3/4,winy=y*3/4;

    vboxwid=new QWidget;
    setCentralWidget( vboxwid);
    vbox=new QHBoxLayout;
    v_box2 = new QVBoxLayout;
    vboxwid->setLayout(v_box2);
    wid=new QWidget;
    wid->setFixedSize(winx,winy);


    b1=new QPushButton;
    b2= new QPushButton;
    b1->setFixedSize(x/9.1,x/9.1);
    b2->setFixedSize(x/9.1,x/9.1);
    b1->setIconSize(QSize(x/9.1,x/9.1));
    b2->setIconSize(QSize(x/9.1,x/9.1));
    b1->setIcon(QIcon(":/chess pics/clear.png"));
    b2->setIcon(QIcon(":/chess pics/help.png"));

    vbox->addWidget(b1);
    vbox->addWidget(wid);
    vbox->addWidget(b2);

    QTextStream out(stdout);
    QFile file("E:/new/easy.txt");
    out<<"file trying";
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    out<<"file opend";
    QTextStream in(&file);

    QString hs;

    for(int i=0;i<type;i++){
        hs = in.readLine();
    }

    if(hs.toInt()==-1)
        hs=QString::number(0);

    hs.append("</h1>");
    hs.prepend("<h1>");

    l1= new QLabel("<b><h1>Moves : </h1></b>");
    l2= new QLabel("<b><h1>Best:</h1></b> ");
    l3=  new QLabel("<h1>0</h1>");
    l4=  new QLabel(hs);


    Board *b=new Board(N,m,type,winx,winy,l3);
    grid = b->returnGrid();
    wid->setLayout(grid);


    //v_box1= new QVBoxLayout;
    //v_box1->addWidget(b1);
    //v_box1->addWidget(b2);

    //vbox->addLayout(v_box1);

    v_boxh= new QHBoxLayout;
    v_boxh->addWidget(l1);
    v_boxh->addWidget(l3);
    v_boxh->addSpacing(650);
    v_boxh->addWidget(l2);
    v_boxh->addWidget(l4);


    v_box2->addLayout(vbox);
    v_box2->addLayout(v_boxh);
    connect(b1,SIGNAL(clicked()),b,SLOT(clear_board()));
    connect(b2,SIGNAL(clicked()),b,SLOT(solutions()));

    //vboxwid->setStyleSheet("background-image: url(:/chess pics/bg1.jpg)");

    resize(x,y);
    widparent->hide();
}

Game::~Game(){
    widparent->close();
}
