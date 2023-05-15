//
// Created by henry on 14/05/23.
//

#include "Ghost2.h"
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
#include "SuperDot.h"
#include "Dificulties_Window.h"

Ghost2::Ghost2(int mapa[21][30], int j, int i)

{
    setPixmap(QPixmap(":/Images/ghost2.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move, &QTimer::timeout, this, &Ghost2::move);
    timer_move->setInterval(500); // Signal every 50 milliseconds

    timer_move->setSingleShot(false); // Set the timer to run only once
    QTimer::singleShot(100, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer

    QTimer *collision_timer = new QTimer(this);
    collision_timer->setInterval(500);

    // Conectar la señal timeout() del QTimer al slot check_collision():
    connect(collision_timer, SIGNAL(timeout()), this, SLOT(check_collision()));

    // Iniciar el QTimer:
    collision_timer->start();

    position_x = j;//13
    position_y =i;//0 o 1
    std::cout << "Ghost2 inicial en matriz X: " << position_x<< std::endl;
    std::cout << "Ghost2 inicial en matriz Y: " << position_y<< std::endl;

    set_mapa(mapa);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (mapa[i][j] != 0) {
                StarNode *node = new StarNode(j, i);
                lista_randomg.append(node);
            }
        }
    }

}


void Ghost2::set_mapa(int mapa[21][30])
{
    std::cout << "entra a set mapa" << std::endl;
    for (int i = 0;i < 21;i++){
        for(int j = 0;j < 30;j++){
            this->mapa[i][j] = mapa[i][j];
            qDebug() << mapa[i][j];
        }
    }
}

void Ghost2::moveWithoutArgs()
{

    move();
}
void Ghost2::move(){
    std::cout << "ENTRA A MOVE DE Ghost2" << std::endl;
    if (!pathList.isEmpty()) {
        int new_x = pathList.getHead()->getNodeX();// primer x en la ruta
        int new_y = pathList.getHead()->getNodeY();// primer y en la ruta
        position_y = pathList.getHead()->getNodeX();
        position_x = pathList.getHead()->getNodeY();
        setPos(new_y*30, new_x*30);// // pacman ahi (creo que estan al reves)
        pathList.removeHead();// quito el primeer elemento de la lista o sea to el par porque ya lo use
    }
    if (pathList.isEmpty()){
        if (nivel1 == true){
            std::cout << "LISTA VACIA" << std::endl;
            chasePacMan();
            route_completed= true;
            searching=true;
        }
        else{
            std::cout << "LISTA VACIA" << std::endl;
            chasePacMan();
            route_completed= true;
            searching=true;
        }


    }
}

void Ghost2::chasePacMan() { //para calcular
    if (route_completed== true && searching== true){
        std::cout << "ENTRA A CHASE DE Ghost2" << std::endl;
        AStar astar;
        Pair src = make_pair(position_y,position_x);//PROblema en source
        Pair dest;
        if (poder_activo == true){
            dest = make_pair(poder_x, poder_y);
        } else{
            dest = make_pair(pac_man_x, pac_man_y);
        }

        astar.aStarSearch(mapa, src, dest);
        pathList = astar.getPath();//lista con la ruta
        route_completed= false;// ya hice ruta pero no la he completado
        searching= false;// ya no tengo que buscar.
        move();

    }
}

void Ghost2::move2(){// ignorar
    //move2();
    std::cout << "ENTRA A MOVE DE Ghost2" << std::endl;
    int dest_x = 29; // la posición X a la que debe llegar el Ghost2
    int dest_y = position_y; // la posición Y se mantiene igual
    bool obstacle_found = false; // variable para determinar si se encuentra un obstáculo
    std::cout << "Ghost2 inicial en move X: " << position_x<< std::endl;
    std::cout << "Ghost2 inicial en move Y: " << position_y<< std::endl;
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
                std::cout << "Ghost2 CALCULADO Y: " << position_y<< std::endl;
                std::cout << "Ghost2 CALCULADO X:  " << position_x<< std::endl;
                std::cout << "PACMAN CALCULADO Y: " << pac_man_y<< std::endl;
                std::cout << "PACMAN CALCULADO X: " << pac_man_x<< std::endl;
                astar.aStarSearch(mapa, src, dest);
                std::cout << "PRINT EN Ghost2 DE LISTA " << std::endl;
                StarList pathList = astar.getPath();
                std::cout << "PRINT HEAD EN Ghost2 DE LISTA " << std::endl;
                pathList.getHead();
                std::cout << "PRINT size EN Ghost2 DE LISTA " << std::endl;
                pathList.size();
                std::cout << "PRINT head en X EN Ghost2 DE LISTA " << std::endl;
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
//    std::cout << "Ghost2 ACTUAL en matriz X: " << position_x<< std::endl;
//    std::cout << "Ghost2 ACTUAL en matriz Y: " << position_y<< std::endl;
    //int pac_man_x = pacman->getActPacmanX(); // obtener el valor de act_pacman_x
    //int pac_man_y = pacman->getActPacmanY();
    //std::cout << "PACMAN X EN Ghost2 " << pac_man_x<< std::endl;
    //std::cout << "PACMAN Y EN Ghost2: " << pac_man_y<< std::endl;

}

void Ghost2::actualizar_posicion_pacman2(int x, int y) {

    pac_man_y=y;
    pac_man_x=x;
    std::cout << "PACMAN X EN Ghost2 ANTES " << pac_man_x<< std::endl;
    std::cout << "PACMAN Y EN Ghost2: ANTES " << pac_man_y<< std::endl;
    if (pac_man_y !=0 || pac_man_y!=0){
        search= true;
    }


}
void Ghost2::check_collision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); //List of the colliding items
    for (int i = 0, n = colliding_items.size(); i < n; ++i){

        if (typeid(*(colliding_items[i])) == typeid(SuperDot)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            poder_activo = false;
            std::cout << "PODER ROBADOOOOOOOOOOOOOOOOO" << std::endl;
        }
    }
}

void Ghost2::random_location(){
    poder_x = lista_randomg.getRandomNode()->getNodeX();
    poder_y = lista_randomg.getRandomNode()->getNodeY();
    position_y = poder_x;
    position_x = poder_y;
    pathList.clear();
    move();
    setPos(poder_x*30, poder_y*30);

}