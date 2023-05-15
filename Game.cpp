#include "Game.h"
#include "Blocks.h"
#include "Ghost.h"
#include "Dots.h"
#include "Ghost2.h"
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

    Ghost *ghost = new Ghost(m_mapa,jghost, ighost);
    ghost->setPos(jghost*30, ighost*30); // set ghost position
                std::cout << "j ghost: " << jghost<< std::endl;
               std::cout << "i ghost: deberia ser 28 o 29: " << ighost<< std::endl;
    scene->addItem(ghost);

    Ghost2 *ghost2 = new Ghost2(m_mapa,jghost2, ighost2);
    ghost2->setPos(jghost2*30, ighost2*30); // set ghost position
    std::cout << "j ghost: " << jghost2<< std::endl;
    std::cout << "i ghost: deberia ser 28 o 29: " << ighost2<< std::endl;
    scene->addItem(ghost2);

    connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost, SLOT(actualizar_posicion_pacman(int, int)));
    connect(pac_man, SIGNAL(pacman_posicion_actualizada(int, int)), ghost2, SLOT(actualizar_posicion_pacman2(int, int)));

    //Ghost *ghost = new Ghost();

    QTimer *col = new QTimer();
    connect(col,SIGNAL(timeout()),pac_man,SLOT(check_collision()));
    col->start(100);


    connect(timer_points, SIGNAL(timeout()),pac_man, SLOT(check_points()));
    timer_points->start(500);

    points_label = new QGraphicsTextItem("Points: " + QString::number(0));
    points_label->setFont(font);
    points_label->setDefaultTextColor(Qt::red);

    scene->addItem(pac_man);
    //scene->addItem(ghost);
    scene->addItem(points_label);

    points_label->setPos(720,590);
   //ghost->setPos(810,30);

    pac_man->set_points_label(points_label);
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
                std::cout << "j pacman: " << pacmanX/30<< std::endl;//coordenadas de la matriz
                std::cout << "i pacman: " << pacmanY/30<< std::endl;
            }
            else if (m_mapa[i][j] == 11) // if character is '1', add ghost
            {
                //Ghost *ghost = new Ghost(m_mapa,pac_man->act_pacman_x,pac_man->act_pacman_y);
                jghost =j;
                ighost=i;
//                std::cout << "j ghost: " << j<< std::endl;
//                std::cout << "i ghost: " << i<< std::endl;
                //ghost->move(pacmanX,pacmanY);
            }
            else if (m_mapa[i][j] == 12) // if character is '1', add ghost
            {
                //Ghost *ghost = new Ghost(m_mapa,pac_man->act_pacman_x,pac_man->act_pacman_y);
                jghost2 =j;
                ighost2 =i;
//                std::cout << "j ghost: " << j<< std::endl;
//                std::cout << "i ghost: " << i<< std::endl;
                //ghost->move(pacmanX,pacmanY);
            }
            }

        }

    }
Pac_Man* Game::get_pacman() {
    return pac_man;
}

