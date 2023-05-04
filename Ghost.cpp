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

Ghost::Ghost(char mapa[21][30], int j, int i)

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

}


void Ghost::set_mapa(char mapa[21][30])
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
    //std::cout << "entra a move sin args" << std::endl;
    // Call move() with the stored values of pac_man_x and pac_man_y
    move();
}


void Ghost::move(){
    std::cout << "ENTRA A MOVE DE GHOST" << std::endl;
    int dest_x = 29; // la posición X a la que debe llegar el Ghost
    int dest_y = position_y; // la posición Y se mantiene igual
    bool obstacle_found = false; // variable para determinar si se encuentra un obstáculo

    // mover hacia la derecha hasta encontrar un obstáculo o llegar a dest_x
    while (position_x < dest_x && !obstacle_found) {
        if (mapa[position_y][position_x + 1] == 'X') {
            obstacle_found = true;
        } else {
            setPos(x() + speed, y());
            position_x++;
            QCoreApplication::processEvents(); // para actualizar la ventana
            QThread::msleep(300); // para darle una pausa al movimiento
        }
    }

    // si no hay obstáculo, mover hacia abajo hasta encontrar un obstáculo o llegar a dest_y
    while (position_y < dest_y && !obstacle_found) {
        if (mapa[position_y + 1][position_x] == 'X') {
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
    std::cout << "bella: " << pac_man_y<< std::endl;
}
void Ghost::actualizar_posicion_pacman(int x, int y) {
    std::cout << "La posición actual de Pac-Man es (" << x << ", " << y << ")" << std::endl;
}