#include <button.h>
#include <QTextStream>
#include <math.h>


Button::Button(int r, int c,QWidget *parent):QPushButton(parent){
    is_present=false;
    row=r;
    column=c;
}

void Button::assignicon(){
    int N;
    for(N=0;N<container.size();N++);
    N = sqrt(N);

    QTextStream out(stdout);

    if(!is_present){
        if(check(row,column)){
            valueAt(row,column)->is_present = true;
            setIcon(QIcon("../Package/Venky/chess pics/Black_King.bmp"));
        }
        else{
            setIcon(QIcon("../Package/Venky/chess pics/Black_King.bmp"));
            setStyleSheet("* { background-color: rgb(180,0,0) }");
        }
    }

    else{
        setIcon(QIcon(""));
        if(color)
            setStyleSheet("* { background-color: rgb(255,255,255) }");
        else
            setStyleSheet("* { background-color: rgb(0,0,0) }");
        valueAt(row,column)->is_present = false;
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++)
            out<<valueAt(i,j)->is_present;
        out<<endl;
    }

    is_present = !is_present;
}

void Button::setcolor(bool c){
    color = c;
}

bool Button::check(int r, int c){

    int N;
    for(N=0;N<container.size();N++);
    N = sqrt(N);

    QTextStream out(stdout);

    // checking rows
    for(int i=1;i<=N;i++){
        if(valueAt(r,i)->is_present){
            out<<"1"<<endl;
            return false;
        }
    }

    //checking coloumn
    for(int i=1;i<=N;i++){
        if(valueAt(i,c)->is_present){
            out<<"2"<<endl;
            return false;
        }
    }

    //4th quadrant
    for(int i=r, j=c;i<=N && j<=N;i++,j++){
            if(valueAt(i,j)->is_present){
                out<<"3"<<endl;
                return false;
            }
    }

    //2nd Quad
    for(int i=r, j=c;i>0 && j>0;i--,j--){
            if(valueAt(i,j)->is_present){
                out<<""<<endl;
                return false;
            }
    }

    //3rd Quad
    for(int i=r, j=c;i<=N && j>0;i++,j--){
            if(valueAt(i,j)->is_present){
                out<<"5"<<endl;
                return false;
            }
    }

    //1st Quad
    for(int i=r, j=c;i>0 && j<=N;i--,j++){
            if(valueAt(i,j)->is_present){
                out<<"6"<<endl;
                return false;
            }
    }

    return true;
}

Button* Button::valueAt(int r, int c){
    for(int i=0;container.at(i)->row == r && container.at(i)->column == c;i++)
        return container.at(i);
    return NULL;
}
