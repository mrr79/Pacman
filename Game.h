#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include "Pac_Man.h"
#include "Ghost.h"

class Game: public QGraphicsView{

public:

    Game(int mapa[21][30], int points, int lifes, QWidget *parent = nullptr);

    static const uint LABYRINTH_WIDTH  = 21;
    static const uint LABYRINTH_HEIGHT = 31;


    void setPoints(int points);

    QPixmap m_labyrinthPixmap;
    QGraphicsPixmapItem* m_labyrinthPixmapItems[LABYRINTH_WIDTH][LABYRINTH_HEIGHT];
    QPixmap m_labyrinthPixmaps[32];

    QTimer *timer_points = new QTimer();
    QTimer *timer_lifes = new QTimer();
    QTimer *timer_level = new QTimer();


    Pac_Man *pac_man;

    QGraphicsTextItem *points_label;
    QGraphicsTextItem *lifes_label;
    QGraphicsTextItem *level_label;

    Pac_Man* get_pacman();

    QGraphicsScene * scene;
    void deleteghost();

private:
    void init_lab();
    void ghost_manager();


    int m_points;
    int m_lifes;
    int m_mapa[21][30];
    int pacmanX=0;
    int pacmanY=0;
    int jghost=0;
    int ighost=0;
    int jghost2;
    int ighost2;
    int jghost3;
    int ighost3;
    int jghost4;
    int ighost4;

};

#endif // LEVELS_H
