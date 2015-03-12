ifndef BUTTON_H
#define BUTTON_H

#include <QVector>

class Game{
private:
    QVector <Piece*> thePieces;
    bool whoseTurn;

    void createPieces();

};

#endif // BUTTON_H
