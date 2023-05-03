#include "Ghost.h"
#include <QTimer>
#include <cmath>

Ghost::Ghost(int pac_man_x, int pac_man_y)
{
    setPixmap(QPixmap(":/Images/ghost1.png"));

    QTimer *timer_move = new QTimer;
    connect(timer_move,SIGNAL(timeout()),this,SLOT(move(pac_man_x, pac_man_y))); //conect method that repeats the method everytime it recives the signal
    timer_move->setInterval(500); // Signal every 50 milliseconds
    timer_move->setSingleShot(true); // Set the timer to run only once
    QTimer::singleShot(3000, timer_move, SLOT(start())); // Wait for 3 seconds and then start the timer
}

void Ghost::move(int pac_man_x, int pac_man_y)
{
    int distance_x = pac_man_x - position_x;
    int distance_y = pac_man_y - position_y;
    double distance = sqrt(distance_x * distance_x + distance_y * distance_y);

    if (distance_x < 0) {
        setPos(x() - speed, y());
        position_y--;
    } else if (distance_x > 0) {
        setPos(x() + speed, y());
        position_y++;
    } else if (distance_y < 0) {
        setPos(x(), y() - speed);
        position_x--;
    } else if (distance_y > 0) {
        setPos(x(), y() + speed);
        position_x++;
    }
}

