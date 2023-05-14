#include "Pac_Man.h"
#include "Dots.h"
#include "SuperDot.h"
#include "Ghost.h"
#include "Utils.h"
#include "qgraphicsscene.h"
#include <QTimer>
#include <QKeyEvent>
#include <QDebug>
#include <iostream>

int cycle = 0;

Pac_Man::Pac_Man(int mapa[21][30], int points, int lifes, QGraphicsTextItem *points_label, QGraphicsScene *sceneint,int j, int i)
{

    this->points = points;
    this->lifes = lifes;
    this->points_label = points_label;
    this->scene = scene;
    this->act_pacman_x=j;
    this->act_pacman_y=i;

    std::cout << "PAcman inicial en matriz X TIENE QUE SER 10 O 15: " << act_pacman_x<< std::endl;
    std::cout << "PAcman inicial en matriz Y TIENE QUE SER 10 O 15: " << act_pacman_y<< std::endl;



    setPixmap(QPixmap(":/Images/pac_man_0R.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move,SIGNAL(timeout()),this,SLOT(move())); //conect method that repeats the method everytime it recives the signal
    timer_move->start(500); //Signal every 50 miliseconds


    connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_R())); //conect method that repeats the method everytime it recives the signal
    timer_animation->start(150); //Signal every 50 miliseconds
}

void Pac_Man::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Up){
        direcction = 'U';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_U())); //conect method that repeats the method everytime it recives the signal
    }
    if (event->key() == Qt::Key_Down){
        direcction = 'D';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_D())); //conect method that repeats the method everytime it recives the signal
    }
    if (event->key() == Qt::Key_Left){
        direcction = 'L';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_L())); //conect method that repeats the method everytime it recives the signal
    }
    if (event->key() == Qt::Key_Right){
        direcction = 'R';
        cycle = 0;
        connect(timer_animation,SIGNAL(timeout()),this,SLOT(animation_R())); //conect method that repeats the method everytime it recives the signal
    }
}

void Pac_Man::set_points_label(QGraphicsTextItem *points_label)
{
    this->points_label = points_label;
}

void Pac_Man::set_mapa(int mapa[21][30])
{
    for (int i = 0;i < 21;i++){
        for(int j = 0;j < 30;j++){
            this->mapa[i][j] = mapa[i][j];
            qDebug() << mapa[i][j];
        }
    }
}

void Pac_Man::set_values(int mapa[21][30], int points, int lifes, QGraphicsTextItem* points_label, QGraphicsScene* scene) {
    this->points = points;
    this->lifes = lifes;
    this->points_label = points_label;
    this->scene = scene;
}

int pointsR;

void Pac_Man::check_collision()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); //List of the colliding items
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Dot)){
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            points += 10;
            pointsR = points;
            points_label->setPlainText("Points: " + QString::number(points));

            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(SuperDot)){
            scene->removeItem(colliding_items[i]);
            delete colliding_items[i];
            super_dot = true;
            return;
        }
        else if (typeid(*(colliding_items[i])) == typeid(Ghost)){
            //
            // scene->removeItem(this);
            //lifes--;
            return;
        }
    }
}

void Pac_Man::check_points() {
    if (points % 200 == 0) {

        //SuperDot *super_dot = new SuperDot();
        //scene->addItem(super_dot);
        //super_dot->setPos(420, 600 / 2);
    }
}


void Pac_Man::move()
{
    if (direcction == 'R'){
        if (x() < 810 && mapa[act_pacman_x][act_pacman_y + 1] != 0){
            setPos(x() + speed,y());
            act_pacman_y++;
        }
    }
    else if (direcction == 'L'){
        if (x() > 30 && mapa[act_pacman_x][act_pacman_y - 1] != 0){
            setPos(x() - speed,y());
            act_pacman_y--;
        }
    }
    else if (direcction == 'U'){
        if (y() > 30 && mapa[act_pacman_x - 1][act_pacman_y] != 0){
            setPos(x(),y() - speed);
            act_pacman_x--;
        }
    }
    else if (direcction == 'D'){
        if (y() < 570 && mapa[act_pacman_x + 1][act_pacman_y] != 0){
            setPos(x(),y() + speed);
            act_pacman_x++;
        }
    }
    act_pacman_x = y() / 30;// posicion del pacman en el mapa
    act_pacman_y = x() / 30;
    std::cout << "PACMAN X:" << act_pacman_x << std::endl;
    std::cout << "PACMAN Y:" << act_pacman_y << std::endl;// COORDENADAS DE PACMAN EN Ela matriz
    emit pacman_posicion_actualizada(act_pacman_x, act_pacman_y);

}
void Pac_Man::setActPacmanX(int m) {
    act_pacman_x = m;
    std::cout << "PACMAN X EN SETTER:" << act_pacman_x << std::endl;// COORDENADAS DE PACMAN EN Ela matriz
}

void Pac_Man::setActPacmanY(int n) {
    act_pacman_y = n;
    std::cout << "PACMAN Y EN SETTER:" << act_pacman_y << std::endl;// COORDENADAS DE PACMAN EN Ela matriz
}

int Pac_Man::getActPacmanX() {
    return act_pacman_x;
    //std::cout << "X PACMAN EN get" << act_pacman_x << std::endl;
}

int Pac_Man::getActPacmanY() {
    return act_pacman_y;
    //std::cout << "Y PACMAN EN get" << act_pacman_y<< std::endl;
}

void Pac_Man::animation_R()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0R.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1R.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}

void Pac_Man::animation_L()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0L.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1L.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}

void Pac_Man::animation_U()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0U.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1U.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}

void Pac_Man::animation_D()
{
    if (cycle == 0){
        setPixmap(QPixmap(":/Images/pac_man_0D.png"));
        cycle++;
    }

    else if (cycle == 1){
        setPixmap(QPixmap(":/Images/pac_man_1D.png"));
        cycle++;
    }

    else if (cycle == 2){
        setPixmap(QPixmap(":/Images/pac_man_2.png"));
        cycle = 0;
    }
}



