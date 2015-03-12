#include <pieces.h>
#include <QApplication>
#include <QDesktopWidget>
#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QTextStream>

QVector <Piece*> thePieces;
bool whoseTurn;
int tRow;
int tCol;
int **dummy;
bool clicked_icon[7];
bool status=true;
int flag = 0;


QTextStream out(stdout);
Piece::Piece(int ch, int row, int col, int c){
    child = ch;
    curRow = row;
    curCol = col;
    Color = c;
    isFirstMove = true;

    if((curRow>0 && curRow <9) || (curCol >0 && curCol<9)){
    if(child == -1)
        dummy[curRow][curCol] = 0;
    else
        dummy[curRow][curCol]=child;
    }
    QDesktopWidget *dp =  QApplication ::desktop();
    int x=dp->width()*3/4/8;
    int y=dp->height()*3/4/8;

    setFixedSize(x,y);

    if((curRow+curCol)%2)
        setStyleSheet("* { background-color: rgb(139,69,19) }");
    else
        setStyleSheet("* { background-color: rgb(255,211,155) }");


    switch(child){
        case 1 : if(Color)
                    setIcon(QIcon(":/chess pics/Chess-King-icon.png"));
                 else
                    setIcon(QIcon(":/chess pics/Chess-King-icon(white).png"));
                break;

        case 2 : if(Color)
                    setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
                 else
                    setIcon(QIcon(":/chess pics/Chess-Queen-icon(white).png"));
                break;

        case 3 : if(Color)
                    setIcon(QIcon(":/chess pics/Chess-Bishop-icon.png"));
                 else
                    setIcon(QIcon(":/chess pics/Chess-Bishop-icon(white).png"));
                break;

        case 4 : if(Color)
                    setIcon(QIcon(":/chess pics/Chess-Knight-icon.png"));
                 else
                    setIcon(QIcon(":/chess pics/Chess-Knight-icon(white).png"));
                break;

        case 5 : if(Color)
                    setIcon(QIcon(":/chess pics/Chess-Rook-icon.png"));
                 else
                    setIcon(QIcon(":/chess pics/Chess-Rook-icon(white).png"));
                break;

        case 6 : if(Color)
                    setIcon(QIcon(":/chess pics/Chess-Pawn-icon.png"));
                 else
                    setIcon(QIcon(":/chess pics/Chess-Pawn-icon(white).png"));
                break;
        default :
                 setIcon(QIcon(""));
    }

    setIconSize(QSize(x*2/3,y*2/3));
}

void Piece::show(){
    QMainWindow *mainWind = new QMainWindow;
    QDesktopWidget *dp =  QApplication ::desktop();
    int x=dp->width();
    int y=dp->height();
    int winx=x*3/4,winy=y*3/4;
    QWidget *centralwid=new QWidget;
    mainWind->setCentralWidget( centralwid);
    QHBoxLayout *hbox=new QHBoxLayout;
    centralwid->setLayout( hbox);
    QWidget *hwid=new QWidget;
    hwid->setFixedSize(winx,winy);

    hbox->addWidget(hwid);

    QGridLayout *grid= new QGridLayout;
    hwid->setLayout(grid);

    mainWind->resize(x,y);
    dummy =  new int*[9];
    for(int i=0;i<=8;i++)
        dummy[i] = new int[9];

    for(int i=1;i<=8;i++){
        thePieces.push_back(new Piece(6,2,i,0));
        thePieces.push_back(new Piece(6,7,i,1));
    }

    thePieces.push_back(new Piece(1,1,4,0));
    thePieces.push_back(new Piece(1,8,4,1));

    thePieces.push_back(new Piece(2,1,5,0));
    thePieces.push_back(new Piece(2,8,5,1));

    thePieces.push_back(new Piece(3,1,3,0));
    thePieces.push_back(new Piece(3,1,6,0));
    thePieces.push_back(new Piece(3,8,3,1));
    thePieces.push_back(new Piece(3,8,6,1));

    thePieces.push_back(new Piece(4,1,2,0));
    thePieces.push_back(new Piece(4,1,7,0));
    thePieces.push_back(new Piece(4,8,2,1));
    thePieces.push_back(new Piece(4,8,7,1));

    thePieces.push_back(new Piece(5,1,1,0));
    thePieces.push_back(new Piece(5,1,8,0));
    thePieces.push_back(new Piece(5,8,1,1));
    thePieces.push_back(new Piece(5,8,8,1));

    for(int i=3;i<=6;i++)
        for(int j=1;j<=8;j++)
            thePieces.push_back(new Piece(0,i,j));

    for(int i=0;i<thePieces.size();i++){
        grid->addWidget(thePieces.at(i),thePieces.at(i)->curRow,thePieces.at(i)->curCol);
    }

    takeTurns();

    for(int i=1;i<=8;i++){
        for(int j=1;j<=8;j++)
            out<<dummy[i][j]<<" ";
        out<<endl;
    }

    mainWind->show();
}

Piece* Piece::findPiece(int row, int col){
    Piece* curPiece,*tempPiece = new Piece(-1,-1,-1,-1);

    for(int i=0;i<thePieces.size();i++){
        curPiece = thePieces.at(i);

        if(curPiece->curRow == row && curPiece->curCol == col){
            return curPiece;
        }
    }

    return tempPiece;
}

bool Piece::intersectsPieces(int destRow, int destCol,int child){
    /*while(tempRow != destRow && tempCol != destCol){        //condition notvalid in case of moving from 0,0 to 0,2
        if(tempRow < destRow)
            tempRow++;
        else if(tempRow > destRow)
            tempRow--;

        if(tempCol < destCol)
            tempCol++;
        else if(tempCol > destCol)
            tempCol--;

        if(findPiece(tempRow,tempCol)->curRow != -1)                                                        // somthing should be done here
            return true;
    }*/

    switch(child){
    case 1:
        return true;
    case 2:
        if(curCol==destCol)
        for(int i=1;i<8;i++){
            int j=curCol;
            if(findPiece(i,j)->curRow!=-1){
                return false;
            }
           }
        else if (curRow==destRow)
        for(int j=1;j<8;j++){
            int i=curRow;
            if(findPiece(i,j)->curRow!=-1){
                return false;
            }
           }
        else if(destRow<curRow && destCol<curCol)
        for(int i=curRow-1,j=curCol-1;i>=1&&j>=1;i--,j--)
                if(findPiece(i,j)->curRow!=-1)
                    return false;

        else if(destRow<curRow && destCol>curCol)
        for(int i=curRow-1,j=curCol+1;i>=1&&j<=8;i--,j++)
                if(findPiece(i,j)->curRow!=-1)
                    return false;

        else if(destRow>curRow && destCol<curCol)
        for(int i=curRow+1,j=curCol-1;i<=8&&j>=1;i++,j--)
                if(findPiece(i,j)->curRow!=-1)
                    return false;

        else if(destRow>curRow && destCol>curCol)        for(int i=curRow+1,j=curCol+1;i<=8 &&j<=8;i++,j++)
                if(findPiece(i,j)->curRow!=-1)
                    return false;
        return true;

    case 3:
        if(destRow<curRow && destCol<curCol)
                for(int i=curRow-1,j=curCol-1;i>=1&&j>=1;i--,j--)
                        if(findPiece(i,j)->curRow!=-1)
                            return false;

                else if(destRow<curRow && destCol>curCol)
                for(int i=curRow-1,j=curCol+1;i>=1&&j<=8;i--,j++)
                        if(findPiece(i,j)->curRow!=-1)
                            return false;

                else if(destRow>curRow && destCol<curCol)
                for(int i=curRow+1,j=curCol-1;i<=8&&j>=1;i++,j--)
                        if(findPiece(i,j)->curRow!=-1)
                            return false;

                else if(destRow>curRow && destCol>curCol)
                for(int i=curRow+1,j=curCol+1;i<=8 &&j<=8;i++,j++)
                        if(findPiece(i,j)->curRow!=-1)
                            return false;
                return true;




    case 4:
        return true;

    case 5:
        if(curCol==destCol)
        for(int i=1;i<8;i++){
            int j=curCol;
            if(findPiece(i,j)->curRow!=-1){
                return false;
            }
           }
        else if (curRow==destRow)
        for(int j=1;j<8;j++){
            int i=curRow;
            if(findPiece(i,j)->curRow!=-1){
                return false;
            }
        }
        return true;
        case 6:
        if(Color){
            for(int i = curRow;i<=curRow+2;i++)
                if(findPiece(i,curCol)->curCol!=-1)
                    return false;
        }
        else
            for(int i = curRow;i>=curRow-2;i--)

\                if(findPiece(i,curCol)->curCol!=-1)  \                  return false;

    }
    return true;
}

void Piece::capturePieces(int row,int col){
    Piece* curPiece;
    int index = -1;

    for(int i=0;i<thePieces.size();i++){
        curPiece = thePieces.at(i);

        if(curPiece->curRow == row && curPiece->curCol ==col){                                              // somthing should be done here
            index = i;
        }
    }

    if(index != -1)
        thePieces.erase(thePieces.begin()+ index);
}

void Piece::takeTurns(){
    out<<"take turns"<<endl;

    if(whoseTurn){
        for(int i=0;i<thePieces.size();i++)
            if(thePieces.at(i)->Color!`=whoseTurn){
                connect(thePieces.at(i),SIGNAL(clicked()),thePieces.at(i),SLOT(toMovePiece()));
                out<<"connected"<<endl;
            }
            else{
                disconnect(thePieces.at(i),0,0,0);
                out<<"disconnected"<<endl;
            }
    }
    else{
        for(int i=0;i<thePieces.size();i++)
            if(thePieces.at(i)->Color!=whoseTurn){
                connect(thePieces.at(i),SIGNAL(clicked()),thePieces.at(i),SLOT(toMovePiece()));
                out<<"connected"<<endl;
            }
            else{
                disconnect(thePieces.at(i),0,0,0);
                out<<"disconnected"<<endl;
            }
    }
    whoseTurn = !whoseTurn;
    out<<whoseTurn;
}

void Piece::toMovePiece(){
    out<<"toMovePiece";
    if(status){
        out<<"first";
           tRow=curRow;
\\
           tCol=curCol;
           status=!status;
    }
    else{
        out<<"second";
           if(movePiece(curRow,curCol,tRow,tCol,child)){
               out<<"move returns true"<<endl;
               status=!status;
           }
    }

}

bool Piece::movePiece(int pieceRow, int pieceCol, int destRow, int destCol,int child){
    Piece* tempPiece;
    tempPiece = findPiece(pieceRow,pieceCol);

    //if(tempPiece->curRow == -1)                                                                         // somthing should be done here
      //  return false;
    if(whoseTurn != tempPiece->Color)                                                              // somthing should be done here
        return false;
    else if(pieceRow == destRow && pieceCol == destCol)                                                 // somthing should be done here
        return false;
    else if(findPiece(destRow,destCol)->Color == tempPiece->Color)                                      // somthing should be done here
        return false;
    else if(intersectsPieces(destRow,destCol,child) && !tempPiece->canHop)                  // somthing should be done here
        return false;
    else if(!tempPiece->isMoveLegal(destRow,destCol,child))                                                   // somthing should be done here
        return false;

    capturePieces(destRow,destCol);
   // theBoard->setPiece(tempPiece->curRow,tempPiece->curCol,destRow,destRow);

    tempPiece->curRow = destRow;
    tempPiece->curCol = destCol;
    for(int i=0;i<thePieces.size();i++)
        if(thePieces.at(i)->curRow == destRow && thePieces.at(i)->curCol == destCol)
            tempPiece = thePieces.at(i);

    switch(child){
    case 1 : if(Color)
                tempPiece->setIcon(QIcon(":/chess pics/Chess-King-icon.png"));
             else
                tempPiece->setIcon(QIcon(":/chess pics/Chess-King-icon(white).png"));
            break;

    case 2 : if(Color)
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Queen-icon.png"));
             else
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Queen-icon(white).png"));
            break;

    case 3 : if(Color)
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Bishop-icon.png"));
             else
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Bishop-icon(white).png"));
            break;

    case 4 : if(Color)
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Knight-icon.png"));
             else
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Knight-icon(white).png"));
            break;

    case 5 : if(Color)
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Rook-icon.png"));
             else
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Rook-icon(white).png"));
            break;

    case 6 : if(Color)
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Pawn-icon.png"));
             else
                tempPiece->setIcon(QIcon(":/chess pics/Chess-Pawn-icon(white).png"));
            break;
    default :
             setIcon(QIcon(""));

    }

    setIcon(QIcon(""));
    return true;
}


/*void Piece::pmoves(){
    QDesktopWidget *dp =  QApplication ::desktop();
    int x=dp->width()*3/4/8;
    int y=dp->height()*3/4/8;

    if(child){
        tRow = curRow;
        tCol = curCol;
    }
    switch(child){
    case 1:
        for(int i=curRow-1;i<=curRow+1;i++)
            for(int j=curCol-1;j<=curCol+1;j++)
                if(i>=1 && i<=8 && j>=1 && j<=8)
                    if(!(i==curRow && j==curCol))
                        for(int k=0;k<thePieces.size();k++)
                            if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                                if(!status){
                                    clicked_icon[i] = false;
                                    for(int k=0;k<thePieces.size();k++)
                                        if(thePieces.at(k)->curRow==tRow && thePieces.at(k)->curCol==tCol){
                                            if(status && !dummy[i][j]){
                                               clicked_icon[1]=false;
                                               thePieces.at(k)->setIcon(QIcon(""));
                                               status = ! status;
                                            }
                                        }
                                }
                                if(status && !dummy[i][j]){
                                   clicked_icon[1]=false;
                                   thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                                   thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                                }
                                else if(!clicked_icon[1] && dummy[i][j]){
                                    clicked_icon[1] = true;
                                    thePieces.at(k)->setIcon(QIcon(""));
                                }
                           }
                    flag=!flag;
            break;
    case 2://queen
    {
        for(int i=curRow-1,j=curCol-1;i>1&&j>=1;i--,j--)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                else if(flag)
                    thePieces.at(k)->setIcon(QIcon(" "));

           }
        for(int i=curRow-1,j=curCol+1;i>=1&&j<=8;i--,j++)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        for(int i=curRow+1,j=curCol-1;i<=8&&j>=1;i++,j--)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }


        for(int i=curRow+1,j=curCol+1;i<=8&&j<=8;i++,j++)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        for(int i=1;i<=8;i++){
            int j=curCol;
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }

                else if(flag)
                    thePieces.at(k)->setIcon(QIcon(" "));
                 }}

        for(int j=1;j<=8;j++){
            int i=curRow;
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        }
        flag=!flag;
        break;


    case 3://bishop
        for(int i=curRow-1,j=curCol-1;i>1&&j>=1;i--,j--)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        for(int i=curRow-1,j=curCol+1;i>=1&&j<=8;i--,j++)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        for(int i=curRow+1,j=curCol-1;i<=8&&j>=1;i++,j--)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        for(int i=curRow+1,j=curCol+1;i<=8&&j<=8;i++,j++)
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }
        flag=!flag;
        break;
case 4://knight
        int i,j;
                if(curRow+1<=8 && curCol+2<=8){
                   i=curRow+1;
                   j=curCol+2;
                   for(int k=0;k<thePieces.size();k++)
                       if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                          if(!flag && !thePieces.at(k)){
                           thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                           thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                       }
                           else if(flag)
                               thePieces.at(k)->setIcon(QIcon(" "));

                      }


                }
                if(curRow+1<=8 && curCol-2>0 ){
                    i=curRow+1;
                    j=curCol-2;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                }


                if(curRow-1>0 && curCol+2<=8 ){
                    i=curRow-1;
                    j=curCol+2;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                }


                if(curRow-1>0 && curCol-2>0 ){
                    i=curRow-1;
                    j=curCol-2;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                }

                if(curRow+2<=8 && curCol+1<=8 ){
                    i=curRow+2;
                    j=curCol+1;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                }


                if(curRow+2<=8 && curCol-1>0 ){
                    i=curRow+2;
                    j=curCol-1;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                }

                if(curRow-2>0 && curCol+1<=8 ){
                    i=curRow-2;
                    j=curCol+1;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                        }


                if(curRow-2>0 && curCol-1>0 ){
                    i=curRow-2;
                    j=curCol-1;
                    for(int k=0;k<thePieces.size();k++)
                        if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                           if(!flag && !thePieces.at(k)){
                            thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(k)->setIcon(QIcon(" "));

                       }

                }
                flag=!flag;

                break;
        case 5://Rook
        for(int i=1;i<=8;i++){
            j=curCol;
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                    if(status && dummy[i][j]){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        }
        for(int j=1;j<=8;j++){
            i=curRow;
            for(int k=0;k<thePieces.size();k++)
                if(thePieces.at(k)->curRow==i && thePieces.at(k)->curCol==j){
                   if(!flag && !thePieces.at(k)){
                    thePieces.at(k)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                    thePieces.at(k)->setIconSize(QSize(x*1/4,y*1/4));
                }
                    else if(flag)
                        thePieces.at(k)->setIcon(QIcon(" "));

               }

        }
        flag=!flag;
        break;


        case 6:
            int r,c;
            if(Color){
                int r=curRow-1;
                int c=curCol;
                for(int i=0;i<thePieces.size();i++)
                    if(thePieces.at(i)->curRow==r && thePieces.at(i)->curCol==c){
                        if(!dummy[i][j]){
                        status=false;
                        thePieces.at(i)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                        thePieces.at(i)->setIconSize(QSize(x*1/4,y*1/4));
                    }
                        else if(status)
                            thePieces.at(i)->setIcon(QIcon(" "));

                   }

                if(isFirstMove)
                {
                    for(int i=0;i<thePieces.size();i++)
                        if(thePieces.at(i)->curRow==r-1 && thePieces.at(i)->curCol==c){
                           if(!flag && !thePieces.at(i)){
                            thePieces.at(i)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(i)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(i)->setIcon(QIcon(" "));

                       }


                }

            }
            else
            {
                int r=curRow+1;
                int c=curCol;
                for(int i=0;i<thePieces.size();i++)
                    if(thePieces.at(i)->curRow==r && thePieces.at(i)->curCol==c){
                       if(!flag && !thePieces.at(i)){
                        thePieces.at(i)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                        thePieces.at(i)->setIconSize(QSize(x*1/4,y*1/4));
                    }
                        else if(flag)
                            thePieces.at(i)->setIcon(QIcon(" "));

                   }

                    }
                if(isFirstMove)
                {
                    for(int i=0;i<thePieces.size();i++)
                        if(thePieces.at(i)->curRow==r+1 && thePieces.at(i)->curCol==c){
                           if(!flag && !thePieces.at(i)){
                            thePieces.at(i)->setIcon(QIcon(":/chess pics/20130512060738772_easyicon_net_64.png"));
                            thePieces.at(i)->setIconSize(QSize(x*1/4,y*1/4));
                        }
                            else if(flag)
                                thePieces.at(i)->setIcon(QIcon(" "));

                       }


                }


            }
        flag=!flag;
    }

}

bool Piece::isGameover(){
    bool foundWhiteKing = false;
    bool foundBlackKing = false;
    Piece* curPiece;

    for(int i=0;i<thePieces.size();i++){
        curPiece = thePieces.at(i);                                                                         //should chek out the contdiotions as well
        if(curPiece->Icon == ic.White_King)
            foundWhiteKing = true;
        else if(curPiece->Icon == ic.Black_King)
            foundBlackKing = true;
    }

    if(foundBlackKing)                                                                                     // somthing should be done here
        return true;
    else if(foundWhiteKing)                                                                                // somthing should be done here
        return true;
    else
        return false;
}
*/

bool Piece::isMoveLegal(int newRow, int newCol, int child){
    switch(child){
        case 1:
            if(isFirstMove && (abs(curCol-newCol) == 1 || abs(curRow - newRow) == 1)){
                isFirstMove = false;
                return true;
            }

            else if(abs(curCol-newCol) == 1 || abs(curRow - newRow) == 1){
                isFirstMove = false;
                return true;
            }
            return false;
            //End of King

        case 2:
            if((newRow == curRow || newCol == curCol || abs(newRow - newCol) == 0)){
                return true;
            }
            return false;
            //End of Queen

        case 3:
            if(abs(newRow - newCol) == 0){
                return true;
            }

            return false;
            //End of Bishop

        case 4:
            if((abs(curCol - newCol) == 2 && abs(curRow - newRow) == 1) || (abs(curCol - newCol) == 1 && abs(curRow - newRow) == 2)){
                return true;
            }

            return false;
            //End of knight

        case 5:
            if(isFirstMove && (curCol == newCol || curRow == newRow)){
                isFirstMove = false;
                return true;
            }

            else if(curCol == newCol || curRow == newRow){
                isFirstMove = false;
                return true;
            }

            return false;
            //End of King

        case 6:
            if(isFirstMove && curCol == newCol && newRow - curRow == 2){
                isFirstMove = false;
                return true;
            }

            else if(curCol == newCol && newRow - curRow == 1){
                isFirstMove = false;
                return true;
            }
            return false;
            //End of Pawn
    }

    return false;
}
