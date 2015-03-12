#include <QApplication>
#include <game.h>
#include "wid1.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Game ab(7);
    wid1 ab;
    ab.show();
    return a.exec();
}
