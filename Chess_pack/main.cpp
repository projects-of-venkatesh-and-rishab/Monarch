#include <QApplication>
#include <pieces.h>
int main(int argc,char**argv){
    QApplication app(argc,argv);
    Piece p;
    p.show();
    return app.exec();
}
