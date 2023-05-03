#include "Ghost.h"
#include <QTimer>
#include <cmath>
#include <QDebug>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <QRandomGenerator>

Ghost::Ghost(char mapa[21][30],int pac_man_x, int pac_man_y, int j, int i)
{
    setPixmap(QPixmap(":/Images/ghost1.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move, &QTimer::timeout, this, &Ghost::moveWithoutArgs);
    timer_move->setInterval(500); // Signal every 50 milliseconds
    timer_move->setSingleShot(false); // Set the timer to run only once
    QTimer::singleShot(3000, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer

    position_x = j;
    position_y =i;

    set_mapa(mapa);
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
    std::cout << "entra a move sin args" << std::endl;
    // Call move() with the stored values of pac_man_x and pac_man_y
    move();
}


void Ghost::move(){

        // Calculate the valid directions (i.e., not towards a wall)
        bool can_move_right = (mapa[position_x][position_y + 1] != 'X');
        bool can_move_left = (mapa[position_x][position_y - 1] != 'X');
        bool can_move_down = (mapa[position_x + 1][position_y] != 'X');
        bool can_move_up = (mapa[position_x - 1][position_y] != 'X');
        QVector<QPoint> valid_directions;
        if (can_move_right) valid_directions.append(QPoint(1, 0));
        if (can_move_left) valid_directions.append(QPoint(-1, 0));
        if (can_move_down) valid_directions.append(QPoint(0, 1));
        if (can_move_up) valid_directions.append(QPoint(0, -1));

        // Choose a random valid direction (or don't move if there are no valid directions)
        QPoint chosen_direction(0, 0);
        if (valid_directions.size() > 0) {
            QRandomGenerator generator;
            int random_index = generator.bounded(valid_directions.size());
            chosen_direction = valid_directions[random_index];
        }

        // Move in the chosen direction (or don't move if the next position is a wall)
        int next_x = position_x + chosen_direction.x();
        int next_y = position_y + chosen_direction.y();
        if (mapa[next_x][next_y] != 'X') {
            setPos(x() + speed * chosen_direction.x(), y() + speed * chosen_direction.y());
            position_x = next_x;
            position_y = next_y;
        }

        // If the ghost can't move in any direction without hitting a wall, wait a random amount of time before trying again
        if (valid_directions.size() == 0) {
            QRandomGenerator generator;
            QTimer::singleShot(generator.bounded(1000) + 500, this, SLOT(move()));
        }

}
