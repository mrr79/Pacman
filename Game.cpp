#include "Game.h"
#include "Blocks.h"
#include "Ghost.h"
#include "Dots.h"
#include "Ghost2.h"
#include "Ghost3.h"
#include "Ghost4.h"
#include "Dificulties_Window.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <iostream>

Game::Game(int mapa[21][30], int points, int lifes, QWidget *parent) :
        m_points(points), m_lifes(lifes), QGraphicsView(parent)
{
    memcpy(m_mapa, mapa, sizeof(m_mapa));


    //Creation and configuration of the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,870,620);
    scene->setBackgroundBrush(QBrush(QImage(":/Images/back.png")));
    QFont font("Arial", 15, QFont::Helvetica);

    init_lab();

    pac_man = new Pac_Man(m_mapa, m_points, m_lifes, points_label, scene,pacmanX/30,pacmanY/30);
    pac_man->set_values(mapa, points, lifes, points_label, scene);
//Creacion de los fantasmas
    if (nivel == 1){
        Ghost *ghost = new Ghost(m_mapa,jghost, ighost);
        ghost->setPos(jghost*30, ighost*30); // set ghost position
        scene->addItem(ghost);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost, SLOT(actualizar_posicion_pacman(int, int)));

    }
    else if (nivel == 2){
        Ghost *ghost = new Ghost(m_mapa,jghost, ighost);
        ghost->setPos(jghost*30, ighost*30); // set ghost position
        scene->addItem(ghost);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost, SLOT(actualizar_posicion_pacman(int, int)));

        Ghost2 *ghost2 = new Ghost2(m_mapa,jghost2, ighost2);
        ghost2->setPos(jghost2*30, ighost2*30); // set ghost position
        scene->addItem(ghost2);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost2, SLOT(actualizar_posicion_pacman2(int, int)));

    }
    else if (nivel == 3){
        Ghost *ghost = new Ghost(m_mapa,jghost, ighost);
        ghost->setPos(jghost*30, ighost*30); // set ghost position
        scene->addItem(ghost);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost, SLOT(actualizar_posicion_pacman(int, int)));

        Ghost2 *ghost2 = new Ghost2(m_mapa,jghost2, ighost2);
        ghost2->setPos(jghost2*30, ighost2*30); // set ghost position
        scene->addItem(ghost2);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost2, SLOT(actualizar_posicion_pacman2(int, int)));

        Ghost3 *ghost3 = new Ghost3(m_mapa,jghost2, ighost2);
        ghost3->setPos(jghost3*30, ighost3*30); // set ghost position
        scene->addItem(ghost3);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost3, SLOT(actualizar_posicion_pacman3(int, int)));

    }
    else if (nivel == 4){
        Ghost *ghost = new Ghost(m_mapa,jghost, ighost);
        ghost->setPos(jghost*30, ighost*30); // set ghost position
        scene->addItem(ghost);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost, SLOT(actualizar_posicion_pacman(int, int)));

        Ghost2 *ghost2 = new Ghost2(m_mapa,jghost2, ighost2);
        ghost2->setPos(jghost2*30, ighost2*30); // set ghost position
        scene->addItem(ghost2);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost2, SLOT(actualizar_posicion_pacman2(int, int)));

        Ghost3 *ghost3 = new Ghost3(m_mapa,jghost2, ighost2);
        ghost3->setPos(jghost3*30, ighost3*30); // set ghost position
        scene->addItem(ghost3);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost3, SLOT(actualizar_posicion_pacman3(int, int)));

        Ghost4 *ghost4 = new Ghost4(m_mapa,jghost4, ighost4);
        ghost4->setPos(jghost4*30, ighost4*30); // set ghost position
        scene->addItem(ghost4);
        connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost4, SLOT(actualizar_posicion_pacman4(int, int)));

    }


    QTimer *col = new QTimer();
    connect(col,SIGNAL(timeout()),pac_man,SLOT(check_collision()));
    col->start(100);


    connect(timer_points, SIGNAL(timeout()),pac_man, SLOT(check_points()));
    timer_points->start(500);

    points_label = new QGraphicsTextItem("Points: " + QString::number(0));
    points_label->setFont(font);
    points_label->setDefaultTextColor(Qt::red);

    lifes_label = new QGraphicsTextItem("Lifes: " + QString::number(0));
    lifes_label->setFont(font);
    lifes_label->setDefaultTextColor(Qt::red);

    level_label = new QGraphicsTextItem("Level: " + QString::number(0));
    level_label->setFont(font);
    level_label->setDefaultTextColor(Qt::red);

    scene->addItem(pac_man);
    //scene->addItem(ghost);
    scene->addItem(points_label);

    scene->addItem(lifes_label);

    scene->addItem(level_label);



    points_label->setPos(720,590);
    lifes_label->setPos(650,590);
    level_label->setPos(570,590);

    //ghost->setPos(810,30);

    pac_man->set_points_label(points_label);
    pac_man->set_lifes_label(lifes_label);
    pac_man->set_level_label(level_label);
    pac_man->set_mapa(mapa);
    pac_man->setFlag(QGraphicsItem::ItemIsFocusable);
    pac_man->setFocus();
    pac_man->setPos(pacmanX,pacmanY);

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(870,620);

}

void Game::init_lab()
{

    int index = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m_labyrinthPixmaps[index] = m_labyrinthPixmap.copy(i * 30, j * 30, 30, 30);
            index++;
        }
    }
    for (int i = 0; i < 21; i++)
    {
        for (int j = 0; j < int(31); j++)
        {
            if (m_mapa[i][j] == 0){
                Block *block = new Block();
                block->setPos(j*30, i*30);
                scene->addItem(block);

            }
            else if (m_mapa[i][j] == 1){
                Dot *dot = new Dot();
                dot->setPos((j*30)+10, (i*30)+10);
                scene->addItem(dot);
            }
            else if (m_mapa[i][j] == 9) // if character is 'P', add pacman
            {
                pacmanX=(j*30);// posicion en pantalla
                pacmanY=i*30;

            }
            else if (m_mapa[i][j] == 11) // if character is '1', add ghost
            {
                jghost =j;
                ighost=i;

            }
            else if (m_mapa[i][j] == 12) // if character is '1', add ghost
            {
                jghost2 =j;
                ighost2 =i;

            }
            else if (m_mapa[i][j] == 13) // if character is '13', add ghost
            {
                jghost3 =j;
                ighost3 =i;

            }
            else if (m_mapa[i][j] == 14) // if character is '14', add ghost
            {
                jghost4 =j;
                ighost4 =i;

            }
            }

        }

    }
Pac_Man* Game::get_pacman() {
    return pac_man;
}

