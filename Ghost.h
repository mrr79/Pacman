#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Pac_Man.h"
#include "Game.h"

class Ghost:public QObject , public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ghost(int mapa[21][30],int j,int i);

    Pac_Man* getPacman();
    void set_mapa(int mapa[21][30]);
public slots:
    //void move(int pac_man_x, int pac_man_y);
    void move();
    void moveWithoutArgs();
    void chasePacMan(Pac_Man* pac_man);
public slots:
    void actualizar_posicion_pacman(int x, int y);

private:
    int speed=30;
    int position_x;
    int position_y;
    int mapa[21][30];

    int pac_man_x; // Declare pac_man_x as a private member variable
    int pac_man_y;
    int j;
    int i;
    bool llego;

};


#endif // GHOST_H
