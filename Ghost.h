#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include "Pac_Man.h"
#include "Game.h"

class Ghost:public QObject , public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ghost(char mapa[21][30],int pac_man_x, int pac_man_y,int j,int i, Game* game);

    Pac_Man* getPacman();
    void set_mapa(char mapa[21][30]);
public slots:
    //void move(int pac_man_x, int pac_man_y);
    void move();
    void moveWithoutArgs();
    void chasePacMan(Pac_Man* pac_man);


private:
    int speed=30;
    int position_x;
    int position_y;
    char mapa[21][30];

    int pac_man_x; // Declare pac_man_x as a private member variable
    int pac_man_y;
    int j;
    int i;

    Pac_Man *pacman;
    Game *m_game;
};


#endif // GHOST_H
