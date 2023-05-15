#ifndef PAC_MAN_H
#define PAC_MAN_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "StarList.h"
#include "StarNode.h"
extern int pointsR;
extern bool poder_activo;
extern int poder_x;
extern int poder_y;
class Pac_Man: public QObject , public  QGraphicsPixmapItem{
     Q_OBJECT
public:
    Pac_Man(int mapa[21][30], int points, int lifes, QGraphicsTextItem *points_label, QGraphicsScene *scene,int j, int i);
    void set_points(int points);
    void set_lifes(int lifes);
    void random_location();
    bool super_dot = false;
    int speed = 30;
    //int points = 0;
    char direcction = 'R';
    void keyPressEvent(QKeyEvent *event);
    void set_points_label(QGraphicsTextItem *points_label);
    void set_mapa(int mapa[21][30]);

    int act_pacman_x;
    int act_pacman_y;
    int points_count = 0;

    int getActPacmanX();
    int getActPacmanY();
    bool cazar = false;
    void setActPacmanX(int m);
    void setActPacmanY(int n);
    StarList lista_random;



    QTimer *timer_animation = new QTimer;

    void set_values(int mapa[21][30], int points, int lifes, QGraphicsTextItem* points_label, QGraphicsScene* scene);
public slots:
    void check_collision();
    void move();
    void check_points();
    void animation_R();
    void animation_L();
    void animation_U();
    void animation_D();


private:
    QGraphicsTextItem *points_label;
    QGraphicsScene* scene;
    int mapa[21][30];
    int lifes;

    int points;
    int m;
    int n;

signals:
    void pacman_posicion_actualizada(int x, int y);
};

#endif // PAC_MAN_H
