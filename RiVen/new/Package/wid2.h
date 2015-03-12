#ifndef WID2_H
#define WID2_H

#include <QWidget>
#include <game.h>

namespace Ui {
class wid2;
}

class wid2 : public QWidget
{
    Q_OBJECT

public:
    explicit wid2(QWidget *par = 0);
    ~wid2();
    
private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::wid2 *ui;
    QWidget *parent;
    Game *a;
};

#endif // WID2_H
