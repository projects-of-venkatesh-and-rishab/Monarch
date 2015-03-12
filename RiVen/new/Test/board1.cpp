#include <board.h>
#include <QTextStream>
#include <math.h>
#include <QDesktopWidget>
#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QString>
#include <time.h>
#include <QtGui>
#include <QMessageBox>
#include <wid2.h>

Board *b;
int score;
int **q1;
int counter=1;

Button::Button(int r, int c,QWidget *parent,int n):QPushButton(parent){
    N = n;
    is_present=false;
    row=r;
    column=c;
}

void Button::assignicon(){
    if(!is_present){
        ++score;

        b->changeLabel(score);
        if(b->accept(q1,row,column)){
            q1[row][column] = 1;
            counter++;
            if(counter==N){
                QMessageBox *abc= new QMessageBox;
                abc->setText("Level Completed..;)");
                b->update_score();
                abc->show();
            }
            setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
        }

        else{
            q1[row][column] = 2;
            b->disable(row,column,false);
            setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
            setStyleSheet("* { background-color: rgb(180,0,0) }");
        }

    }

    else{
        if(q1[row][column] == 2){
            b->disable(row,column,true);
            q1[row][column] = 0;

        }
        if(q1[row][column]==1)
            counter--;

        if(color)
            setStyleSheet("* { background-color: rgb(255,211,155) }");
        else
            setStyleSheet("* { background-color: rgb(139,69,19) }");

        setIcon(QIcon(""));
        q1[row][column] = 0;
    }

    is_present = !is_present;
}

void Button::setcolor(bool c){
    color = c;
}

Board::Board(int n, int m,int t, int winx,int winy,QLabel *label1):Button(0,0,0,N){
    mode = m;
    N = n;
    type=t;

    q1 = new int*[N+1];
    for(int i=0;i<=N;i++)
        q1[i] = new int[N+1];

    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            q1[i][j] = 0;

    q2 = new int*[N+1];
    for(int i=0;i<=N;i++)
        q2[i] = new int[N+1];

    for(int i=0;i<=N;i++)
        for(int j=0;j<=N;j++)
            q2[i][j] = 0;

    srand(time(0));
    r1=rand()%N+1;
    r2=rand()%N+1;

    q1[r1][r2]=1;
    q2[r1][r2]=1;



    grid =new QGridLayout;
    int count =0,alter=0;
    b = this;
    l2= new QLabel("0");
    l4= new QLabel("0");
    moves=label1;

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){
            Button *btn = new Button(i,j,0,N);
            btn->setFixedSize(winx/N,winy/N);
            count++;

            if(alter){
                btn->setStyleSheet("* { background-color: rgb(139,69,19) }");
                btn->setcolor(false);
                if((count)%N || N%2)
                    alter=!alter;
            }

            else{
                btn->setStyleSheet("* { background-color: rgb(255,211,155) }");
                btn->setcolor(true);
                if((count)%N || N%2)
                    alter = !alter;
            }

            if(i==r1 && j==r2){
                btn->setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
                btn->setEnabled(false);
            }

            grid->addWidget(btn,i,j);
            container.push_back(btn);
            container.push_back(btn);

            btn->connect(btn,SIGNAL(clicked()),btn,SLOT(assignicon()));
            btn->setIconSize(QSize((winx/N)*2/3,(winy/N)*2/3));
        }
 }

QGridLayout* Board::returnGrid(){   return grid; }

void Board::disable(int r, int c, bool b){
    for(int i=0;i<container.size();i++){
        if(!(container.at(i)->row == r && container.at(i)->column == c) && (!(container.at(i)->row == r1 && container.at(i)->column == r2)))
            container.at(i)->setEnabled(b);
    }
}

void Board::clear_board(){
    counter=1;
    for(int i=0;i<container.size();i++){
        if(!(container.at(i)->row == r1 && container.at(i)->column == r2)){
            container.at(i)->setEnabled(true);
            container.at(i)->setIcon(QIcon(""));

            if(container.at(i)->color)
                container.at(i)->setStyleSheet("* { background-color: rgb(255,211,155) }");
            else
                container.at(i)->setStyleSheet("* { background-color: rgb(139,69,19) }");
        }
    }

    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++)
            if(q1[i][j] && (!(i == r1 && j == r2)))
                q1[i][j]=0;
}

void Board::solutions(){
    tot_soln = 0;
    solve_state (q2, 1);
    count_solution = 1;

    QDesktopWidget *dp1 =  QApplication ::desktop();
    QGridLayout *dgrid = new  QGridLayout;
    int count1 =0,alter1=0;
    int x1=dp1->width();
    int y1=dp1->height();
    int winx=x1*3/4,winy=y1*3/4;

    QMainWindow *d1= new QMainWindow;
    QWidget *d2= new QWidget;
    QWidget *d3= new QWidget;
    QWidget *d4= new QWidget;
    QLabel *l1=  new QLabel("<b><h1>Solution no:</h1></b>");
    QLabel *l3=  new QLabel("<b><h1>Total Solutions:</h1></b>");

  //  QPushButton *p1= new QPushButton("Back");
    QPushButton *p2= new QPushButton("Next");
    QHBoxLayout *h1 = new QHBoxLayout;
    QHBoxLayout *h2 = new QHBoxLayout;
    QHBoxLayout *h3 = new QHBoxLayout;
    QHBoxLayout *h4 = new QHBoxLayout;
    QVBoxLayout *v1= new QVBoxLayout;

    int **temp= container_solution.at(0);
    d2->setFixedSize(winx,winy);
    for(int i=1;i<=N;i++)
        for(int j=1;j<=N;j++){     
            Button *dbtn = new Button(i,j,0,N);
            dbtn->setFixedSize(winx/N,winy/N);
            count1++;
            if(alter1){
                dbtn->setStyleSheet("* { background-color: rgb(139,69,19) }");
                dbtn->setcolor(false);
                if((count1)%N || N%2)
                    alter1=!alter1;
            }
            else{
                dbtn->setStyleSheet("* { background-color: rgb(255,211,155) }");
                dbtn->setcolor(true);
                if((count1)%N || N%2)
                    alter1 = !alter1;
            }
            if(temp[i][j]==1)
                dbtn->setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
            dbtn->setEnabled(false);
            dgrid->addWidget(dbtn,i,j);
            container1.push_back(dbtn);
            container1.push_back(dbtn);
            dbtn->setIconSize(QSize((winx/N)*2/3,(winy/N)*2/3));
        }

    connect(p2,SIGNAL(clicked()),b,SLOT(next_solution()));

    QString str = QString::number(tot_soln-1);
    str.prepend("<b><h1>");
    str.append("</h1></b>");
    l4->setText(str);
    str = QString::number(count_solution);
    str.prepend("<b><h1>");
    str.append("</h1></b>");
    l2->setText(str);

    h1->addWidget(l1);
    h1->addWidget(l2);
    h1->addWidget(l3);
    h1->addWidget(l4);

    //h2->addWidget(p1);
    h2->addWidget(p2);

    d3->setLayout(dgrid);

    h3->addWidget(d3);

    v1->addLayout(h1);
    v1->addLayout(h3);
    v1->addLayout(h2);

    d4->setLayout(v1);
    h4->addWidget(d4);
    d2->setLayout(h4);

    d1->setWindowTitle("Solutions");
    d1->setCentralWidget(d2);

    d1->show();
}

void Board::changeLabel(int x){
       QString str=QString::number(x);
       str.prepend("<b><h1>");
       str.append("</h1></b>");
       moves->setText(str);
}


void Board::print_solution(int **state)
{
    if((q2[r1][r2] && state[r1][r2])==1){
        ++tot_soln;

        int i,j,**temp;
        temp = new int*[N+1];
        for(int i=0;i<=N;i++)
            temp[i] = new int[N+1];

        for(i=1;i<=N;++i)
            for(j=1;j<=N;++j)
                temp[i][j]=state[i][j];

        container_solution.push_back(temp);
    }
}

/** return true if placing a queen on [row][col] is acceptable
else return false */
bool Board::accept(int **state, int row, int col)
{

    int i,j;

    /* check the column */
    for (i=1; i<=N; ++i)
    {
        if (state[row][i])
            return false;
    }

    /* check the row */
    for (i=1; i<=N; ++i)
    {
        if (state[i][col])
            return false;
    }

    /* check the upper left diagnol */
    for (i = row, j = col; i > 0 && j > 0; i--, j--)
    {
        if (state[i][j])
            return false;
    }

    /* check the lower left diagnol */
    for (i = row, j = col; i <= N && j > 0; ++i, --j)
    {
        if (state[i][j])
            return false;
    }

    /* check the upper right diagnol */
    for (i = row, j = col; i > 0 && j <= N; i--, ++j)
    {
        if (state[i][j])
            return false;
    }

    /* check the lower right diagnol */
    for (i = row, j = col; i <= N && j <= N; ++i, ++j)
    {
        if (state[i][j])
            return false;
    }

    if(mode){
        if(row+1<=N && col+2<=N && state[row+1][col+2])
            return false;

        if(row+1<=N && col-2>0 && state[row+1][col-2])
            return false;

        if(row-1>0 && col+2<=N && state[row-1][col+2])
            return false;

        if(row-1>0 && col-2>0 && state[row-1][col-2])
            return false;

        if(row+2<=N && col+1<=N && state[row+2][col+1])
            return false;

        if(row+2<=N && col-1>0 && state[row+2][col-1])
            return false;

        if(row-2>0 && col+1<=N && state[row-2][col+1])
            return false;

        if(row-2>0 && col-1>0 && state[row-2][col-1])
            return false;
    }

    /* return true if all tests passed */
    return true;
}

void Board::solve_state(int **state, int row)
{
    int i;

    /* if all queens have been placed at non conflicting positions */
    if (row == N+1)
    {
        print_solution(state);
        return;
    }

    /* Place queens on all positions in a given row and
    check if the state is acceptable
    Continue the process till all possibilities found */
    for(i=1; i<=N; ++i)
    {
        if(accept(state, row, i))
        {
            state[row][i] = 1;
            solve_state(state, row+1);
        }
        state[row][i] = 0;
    }
}

void Board::next_solution(){
    count_solution++;
    if(count_solution<tot_soln){

        int **temp;

        QString str = QString::number(count_solution);
        str.prepend("<b><h1>");
        str.append("</h1></b>");
        l2->setText(str);

        temp = container_solution.at(count_solution);
        if(count_solution<=container1.size()){
            for(int i=0;i<container1.size();i++){
                container1.at(i)->setEnabled(false);
                container1.at(i)->setIcon(QIcon(""));

                if(container1.at(i)->color)
                    container1.at(i)->setStyleSheet("* { background-color: rgb(255,211,155) }");
                else
                    container1.at(i)->setStyleSheet("* { background-color: rgb(139,69,19) }");
            }

            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    if(temp[i][j])

            for(int k=0;k<container1.size();k++){
                if(container1.at(k)->row == i && container1.at(k)->column == j)
                    container1.at(k)->setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
            }
        }
    }
}

void Board::update_score(){
    QFile file("E:/new/easy.txt");
    QTextStream out(stdout);
    out<<"File opening";
    file.open(QIODevice::ReadOnly | QIODevice :: Text);
    out<<"file opened";
    QTextStream in(&file);
    QString s[3];

    for(int i=0;i<3;i++)
        s[i] = in.readLine();
    file.close();
    file.open(QIODevice::WriteOnly | QIODevice :: Truncate |QIODevice :: Text);
    if(s[type-1].toInt()==-1 || score<s[type-1].toInt()){
        s[type-1]=QString::number(score);
        QTextStream out(&file);
        for(int i=0;i<3;i++)
            out<<s[i]<<"\n";

    }
}
