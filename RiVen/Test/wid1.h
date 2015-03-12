#ifndef WID1_H
#define WID1_H
#include <wid2.h>
#include <QWidget>

namespace Ui {
class wid1;
}

class wid1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit wid1(QWidget *parent = 0);
    void go_off();
    ~wid1();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::wid1 *ui;
    wid2 *a;
};

#endif // WID1_H
