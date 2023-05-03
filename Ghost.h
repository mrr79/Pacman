#ifndef GHOST_H
#define GHOST_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Ghost:public QObject , public  QGraphicsPixmapItem{
    Q_OBJECT
public:
    Ghost(int pac_man_x, int pac_man_y);
public slots:
    void move(int pac_man_x, int pac_man_y);
private:
    int speed=30;
    int position_x;
    int position_y;
};

#endif // GHOST_H
