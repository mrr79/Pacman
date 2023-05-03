#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Ghost:public QObject , public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ghost(char mapa[21][30],int pac_man_x, int pac_man_y);

    void set_mapa(char mapa[21][30]);
public slots:
    void move(int pac_man_x, int pac_man_y);
    void moveWithoutArgs();

private:
    int speed=30;
    int position_x;
    int position_y;
    char mapa[21][30];

    int pac_man_x; // Declare pac_man_x as a private member variable
    int pac_man_y;
};


#endif // GHOST_H
