#include "Ghost.h"
#include <QTimer>
#include <cmath>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QRandomGenerator>
#include <QCoreApplication>
#include <QThread>
#include <thread>
#include "AStar.h"
#include "Game.h"

Ghost::Ghost(int mapa[21][30], int j, int i)

{
    setPixmap(QPixmap(":/Images/ghost1.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move, &QTimer::timeout, this, &Ghost::moveWithoutArgs);
    timer_move->setInterval(500); // Signal every 50 milliseconds

    timer_move->setSingleShot(false); // Set the timer to run only once
    QTimer::singleShot(3000, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer

    position_x = j;//13
    position_y =i;//0 o 1
    std::cout << "ghost inicial en matriz X: " << position_x<< std::endl;
    std::cout << "ghost inicial en matriz Y: " << position_y<< std::endl;

    set_mapa(mapa);


    //Pac_Man* pacman = m_game->get_pacman();
    //QObject::connect(pacman, SIGNAL(posicion_actualizada(int, int)),
                     //this, SLOT(actualizar_posicion_pacman(int, int)));
//move2();
}


void Ghost::set_mapa(int mapa[21][30])
{
    std::cout << "entra a set mapa" << std::endl;
    for (int i = 0;i < 21;i++){
        for(int j = 0;j < 30;j++){
            this->mapa[i][j] = mapa[i][j];
            qDebug() << mapa[i][j];
        }
    }
}

void Ghost::moveWithoutArgs()
{

    move();
}


void Ghost::move(){
    //move2();
    std::cout << "ENTRA A MOVE DE GHOST" << std::endl;
    int dest_x = 29; // la posición X a la que debe llegar el Ghost
    int dest_y = position_y; // la posición Y se mantiene igual
    bool obstacle_found = false; // variable para determinar si se encuentra un obstáculo
    std::cout << "ghost inicial en move X: " << position_x<< std::endl;
    std::cout << "ghost inicial en move Y: " << position_y<< std::endl;
    //position_x
    //move2();
    // mover hacia la derecha hasta encontrar un obstáculo o llegar a dest_x
    while (position_x < dest_x && !obstacle_found) {
        if (mapa[position_y][position_x + 1 ] == 0) {
            obstacle_found = true;
            if (search){
                AStar astar;
                //Pair src = make_pair(11,19);//PROblema en source

                Pair src = make_pair(position_y,position_x);//PROblema en source
                Pair dest = make_pair(pac_man_x, pac_man_y);
                std::cout << "GHOST CALCULADO Y: " << position_y<< std::endl;
                std::cout << "GHOST CALCULADO X:  " << position_x<< std::endl;
                std::cout << "PACMAN CALCULADO Y: " << pac_man_y<< std::endl;
                std::cout << "PACMAN CALCULADO X: " << pac_man_x<< std::endl;
                astar.aStarSearch(mapa, src, dest);;
                StarList pathList = astar.getPath();
                search= false;
            }

        } else {
            setPos(x() + speed, y());
            position_x++;
            //llego= false;
            QCoreApplication::processEvents(); // para actualizar la ventana
            QThread::msleep(300); // para darle una pausa al movimiento
        }
        //llego= true;
    }

    // si no hay obstáculo, mover hacia abajo hasta encontrar un obstáculo o llegar a dest_y
    while (position_y < dest_y && !obstacle_found) {
        if (mapa[position_y + 1][position_x] == 0) {
            obstacle_found = true;
        } else {
            setPos(x(), y() + speed);
            position_y++;
            QCoreApplication::processEvents(); // para actualizar la ventana
            QThread::msleep(300); // para darle una pausa al movimiento
        }
    }
//    std::cout << "ghost ACTUAL en matriz X: " << position_x<< std::endl;
//    std::cout << "ghost ACTUAL en matriz Y: " << position_y<< std::endl;
    //int pac_man_x = pacman->getActPacmanX(); // obtener el valor de act_pacman_x
    //int pac_man_y = pacman->getActPacmanY();
    //std::cout << "PACMAN X EN GHOST " << pac_man_x<< std::endl;
    //std::cout << "PACMAN Y EN GHOST: " << pac_man_y<< std::endl;

}




void Ghost::chasePacMan(Pac_Man* pac_man) {

}
void Ghost::actualizar_posicion_pacman(int x, int y) {

    pac_man_y=y;
    pac_man_x=x;
    std::cout << "PACMAN X EN GHOST ANTES " << pac_man_x<< std::endl;
    std::cout << "PACMAN Y EN GHOST: ANTES " << pac_man_y<< std::endl;
    if (pac_man_y !=0 || pac_man_y!=0){
        search= true;
    }


}
void Ghost::move2() {
    //std::cout << "mapita" << mapa<< std::endl;

}