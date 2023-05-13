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
#include "StarNode.h"

Ghost::Ghost(int mapa[21][30], int j, int i)

{
    setPixmap(QPixmap(":/Images/ghost1.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move, &QTimer::timeout, this, &Ghost::move);
    timer_move->setInterval(500); // Signal every 50 milliseconds

    timer_move->setSingleShot(false); // Set the timer to run only once
    QTimer::singleShot(3000, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer

    position_x = j;//13
    position_y =i;//0 o 1
    std::cout << "ghost inicial en matriz X: " << position_x<< std::endl;
    std::cout << "ghost inicial en matriz Y: " << position_y<< std::endl;

    set_mapa(mapa);

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
    std::cout << "ENTRA A MOVE DE GHOST" << std::endl;
    if (!pathList.isEmpty()) {
        int new_x = pathList.getHead()->getNodeX();// primer x en la ruta
        int new_y = pathList.getHead()->getNodeY();// primer y en la ruta
        setPos(new_x, new_y);// // pacman ahi (creo que estan al reves)
        pathList.removeHead();// quito el primeer elemento de la lista o sea tood el par porque ya lo use
    }
    if (pathList.isEmpty()){
        std::cout << "LISTA VACIA" << std::endl;
        chasePacMan();
        route_completed= true;
        searching=true;


    }

}

void Ghost::chasePacMan() { //para calcular
    if (route_completed== true && searching== true){
        std::cout << "ENTRA A CHASE DE GHOST" << std::endl;
        AStar astar;
        Pair src = make_pair(position_y,position_x);//PROblema en source
        Pair dest = make_pair(pac_man_x, pac_man_y);
        astar.aStarSearch(mapa, src, dest);
        pathList = astar.getPath();//lista con la ruta
        route_completed= false;// ya hice ruta pero no la he completado
        searching= false;// ya no tengo que buscar.
        while (!pathList.isEmpty() ) {
            move();
            //route_completed= true;
            //searching=true;
        }

    }
}

void Ghost::move2(){// ignorar
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
                astar.aStarSearch(mapa, src, dest);
                std::cout << "PRINT EN GHOST DE LISTA " << std::endl;
                StarList pathList = astar.getPath();
                std::cout << "PRINT HEAD EN GHOST DE LISTA " << std::endl;
                pathList.getHead();
                std::cout << "PRINT size EN GHOST DE LISTA " << std::endl;
                pathList.size();
                std::cout << "PRINT head en X EN GHOST DE LISTA " << std::endl;
                pathList.getHead()->getNodeX();

                //pathList.printList();
                //pathList.getHead();
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
//hacer dos metodos uno paa validacion y otro para calculo y en validacion se mueve: en validacion es
// recorrer la lista y ponerlo a moverse  y hasta que la lista sea 0 se vuelva a calcular.










    /*std::cout << "GHOST CALCULADO Y: " << position_y<< std::endl;
    std::cout << "GHOST CALCULADO X:  " << position_x<< std::endl;
    std::cout << "PACMAN CALCULADO Y: " << pac_man_y<< std::endl;
    std::cout << "PACMAN CALCULADO X: " << pac_man_x<< std::endl;*/
    //astar.aStarSearch(mapa, src, dest);
    //StarList pathList = astar.getPath();
    //std::cout << "PRINT HEAD EN GHOST DE LISTA " << std::endl;
    //pathList.getHead();
    //std::cout << "PRINT size EN GHOST DE LISTA " << std::endl;
    //pathList.size();



void Ghost::actualizar_posicion_pacman(int x, int y) {

    pac_man_y=y;
    pac_man_x=x;
    std::cout << "PACMAN X EN GHOST ANTES " << pac_man_x<< std::endl;
    std::cout << "PACMAN Y EN GHOST: ANTES " << pac_man_y<< std::endl;
    if (pac_man_y !=0 || pac_man_y!=0){
        search= true;
    }


}