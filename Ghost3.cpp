#include "Ghost3.h"
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

Ghost3::Ghost3(int mapa[21][30], int j, int i)

{
    setPixmap(QPixmap(":/Images/ghost3.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move, &QTimer::timeout, this, &Ghost3::move);
    timer_move->setInterval(500); // Signal every 50 milliseconds

    timer_move->setSingleShot(false); // Set the timer to run only once
    QTimer::singleShot(3000, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer

    QTimer *collision_timer = new QTimer(this);
    collision_timer->setInterval(500);

    // Conectar la señal timeout() del QTimer al slot check_collision():
    connect(collision_timer, SIGNAL(timeout()), this, SLOT(check_collision()));

    // Iniciar el QTimer:
    collision_timer->start();

    position_x3 = j;//13
    position_y3 =i;//0 o 1
    std::cout << "Ghost3 inicial en matriz X: " << position_x3<< std::endl;
    std::cout << "Ghost3 inicial en matriz Y: " << position_y3<< std::endl;

    set_mapa(mapa);
    for (int i = 15; i < 25; i++) {
        for (int j = 0; j < 5; j++) {
            if (mapa[i][19] != 0) {
                StarNode *node = new StarNode(19, i);
                lista_randomg.append(node);
            }
        }
    }

}


void Ghost3::set_mapa(int mapa[21][30])
{
    std::cout << "entra a set mapa" << std::endl;
    for (int i = 0;i < 21;i++){
        for(int j = 0;j < 30;j++){
            this->mapa[i][j] = mapa[i][j];
            qDebug() << mapa[i][j];
        }
    }
}

void Ghost3::move(){
    std::cout << "ENTRA A MOVE DE Ghost3" << std::endl;
    if (!pathList.isEmpty()) {
        int new_x = pathList.getHead()->getNodeX();// primer x en la ruta
        int new_y = pathList.getHead()->getNodeY();// primer y en la ruta
        position_y3 = pathList.getHead()->getNodeX();
        position_x3 = pathList.getHead()->getNodeY();
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

void Ghost3::chasePacMan() { //para calcular
    if (route_completed== true && searching== true){
        std::cout << "ENTRA A CHASE DE Ghost3" << std::endl;
        AStar astar2;
        Pair src = make_pair(position_y3,position_x3);//PROblema en source
        Pair dest;
        if (poder_activo == true){
            dest = make_pair(1, 1);
        } else{
            dest = make_pair(pac_man_x, pac_man_y);
        }

        astar2.aStarSearch(mapa, src, dest);
        pathList = astar2.getPath();//lista con la ruta
        route_completed= false;// ya hice ruta pero no la he completado
        searching= false;// ya no tengo que buscar.
        move();

    }
}


void Ghost3::actualizar_posicion_pacman3(int x, int y) {

    pac_man_y=y;
    pac_man_x=x;
    std::cout << "PACMAN X EN Ghost3 ANTES " << pac_man_x<< std::endl;
    std::cout << "PACMAN Y EN Ghost3: ANTES " << pac_man_y<< std::endl;
    if (pac_man_y !=0 || pac_man_y!=0){
        search= true;
    }


}
void Ghost3::check_collision()
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

void Ghost3::random_location(){
    poder_x = lista_randomg.getRandomNode()->getNodeX();
    poder_y = lista_randomg.getRandomNode()->getNodeY();
    position_y3 = poder_x;
    position_x3 = poder_y;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    pathList.clear();
    setPos(poder_x*30, poder_y*30);
    move();

}