#include "Ghost.h"
#include <QTimer>
#include <cmath>
#include <QDebug>
#include <iostream>


Ghost::Ghost(char mapa[21][30],int pac_man_x, int pac_man_y)
{
    setPixmap(QPixmap(":/Images/ghost1.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move, &QTimer::timeout, this, &Ghost::moveWithoutArgs);
    timer_move->setInterval(500); // Signal every 50 milliseconds
    timer_move->setSingleShot(true); // Set the timer to run only once
    QTimer::singleShot(3000, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer

    position_x = pac_man_x / 30;
    position_y = pac_man_y / 30;

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
    move(pac_man_x, pac_man_y);
}

void Ghost::move(int pac_man_x, int pac_man_y)
{
    std::cout << "entra a move y" << std::endl;
    // Calculate the direction towards the Pac-Man
    int dx = pac_man_x - x();
    int dy = pac_man_y - y();
    int abs_dx = abs(dx);
    int abs_dy = abs(dy);

    // Move towards the Pac-Man in the x direction
    if (abs_dx >= abs_dy) {
        if (dx > 0 && mapa[position_x][position_y + 1] != 'X') {
            setPos(x() + speed, y());
            position_y++;
        } else if (dx < 0 && mapa[position_x][position_y - 1] != 'X') {
            setPos(x() - speed, y());
            position_y--;
        }
    }

    // Move towards the Pac-Man in the y direction
    if (abs_dy >= abs_dx) {
        if (dy > 0 && mapa[position_x + 1][position_y] != 'X') {
            setPos(x(), y() + speed);
            position_x++;
        } else if (dy < 0 && mapa[position_x - 1][position_y] != 'X') {
            setPos(x(), y() - speed);
            position_x--;
        }
    }
}
