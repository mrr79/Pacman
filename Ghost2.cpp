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
#include "Backtracking.h"
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
    for (int i = 15; i < 25; i++) {
        for (int j = 0; j < 5; j++) {
            if (mapa[i][19] != 0) {
                StarNode *node = new StarNode(19, i);
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

void Ghost2::move(){
    if (poder_activo == true){
        backtrack_y= 1;
        backtrack_x = 1;

    } else {
        backtrack_y= pac_man_x;
        backtrack_x = pac_man_y;
    }

    if (paths.empty()) {
        chasePacMan();
        cout << "El vector paths está vacío." << endl;
    } else {
        cout << "El vector paths no está vacío." << endl;
        string path = paths[(paths.size()-1)];
        std::cout << "CONTADOR " << contador<< std::endl;
        std::cout << "siixe " << path.size()<< std::endl;

        if (contador == path.size()){
            std::cout << "ESTOY TRISTE " << std::endl;
            contador = 0;
            paths.clear();
        }else{
            std::cout << "ESTOY FELIZ " << std::endl;
            char direction = path[contador];
            contador = contador + 1;

            std::cout << "CONTADOR " << contador<< std::endl;
            std::cout << "DIRECCION " << direction<< std::endl;

            if (direction == 'U') {
                position_y = position_y-1;
                setPos(position_x*30, position_y*30);
            }
            else if (direction == 'D'){
                position_y = position_y+1;
                setPos(position_x*30, position_y*30);
            }
            else if (direction == 'L'){
                position_x = position_x-1;
                setPos(position_x*30, position_y*30);
            }
            else if (direction == 'R'){
                position_x = position_x+1;
                setPos(position_x*30, position_y*30);
            }
        }
    }

}

void Ghost2::chasePacMan() { //para calcular
    vector<vector<int>> maze(21, vector<int>(30));
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 30; j++) {
            maze[i][j] = mapa[i][j];
        }
    }
    //llama a conseguir los caminos
    Backtracking Bt;
    paths=Bt.possiblePaths(maze,position_y,position_x); //EL primer valor es para abajo y el segundo hacia la derecha
    //vector<string> paths = possiblePaths(maze, 0, 0);


    //imprime los caminos
    cout << "camino:" << paths[0] << endl;

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
    std::this_thread::sleep_for(std::chrono::seconds(5));
    setPos(position_y*30, position_x*30);
    contador = 0;
    paths.clear();

}