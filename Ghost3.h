//
// Created by henry on 15/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_GHOST3_H
#define PROYECTO_2_DATOS_LL_GHOST3_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "Pac_Man.h"
#include "Game.h"
#include "StarNode.h"
#include "StarList.h"

class Ghost3:public QObject , public  QGraphicsPixmapItem{
Q_OBJECT
public:
    Ghost3(int mapa[21][30],int j,int i);
    void random_location();

    Pac_Man* getPacman();
    void set_mapa(int mapa[21][30]);
    //StarNode head;
    StarList lista_randomg;

public slots:
    //void move(int pac_man_x, int pac_man_y);
    void move();
    void chasePacMan();

public slots:
    void actualizar_posicion_pacman3(int x, int y);
    void check_collision();

private:
    int speed=30;
    int position_x3;
    int position_y3;
    int mapa[21][30];

    int pac_man_x; // Declare pac_man_x as a private member variable
    int pac_man_y;
    int j;
    int i;
    bool search=false;

    StarList pathList;
    int new_GX;
    int new_GY;
    bool searching;
    bool route_completed;

};


#endif //PROYECTO_2_DATOS_LL_GHOST3_H
