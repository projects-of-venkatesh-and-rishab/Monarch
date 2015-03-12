#ifndef PIECES_H
#define PIECES_H

#include <QPushButton>

class Piece:public QPushButton{
    Q_OBJECT
protected:
    int child;                  //Empty = 0, King = 1, Queen = 2, Bishop = 3, Knight = 4, Rook = 5,Pawn = 6
    int curRow;
    int curCol;
    int Color;
    bool canHop;
    bool isFirstMove;
    Piece* findPiece(int, int);
    bool intersectsPieces( int, int,int);
    void capturePieces(int, int);

public:
    Piece(int ch = -1, int row = -1, int col = -1, int c = -1);
    void takeTurns();
    bool isMoveLegal(int, int, int);
    bool movePiece(int, int, int, int,int);
    //bool isGameover();
    virtual void show();

private slots:
    void toMovePiece();

};

#endif // PIECES_H
