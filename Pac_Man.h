#ifndef PAC_MAN_H
#define PAC_MAN_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class Pac_Man: public QObject , public  QGraphicsPixmapItem{
     Q_OBJECT
public:

    Pac_Man(char mapa[21][30], int points, int lifes, QGraphicsTextItem *points_label, QGraphicsScene *scene);
    void set_points(int points);
    void set_lifes(int lifes);

    bool super_dot = false;
    int speed = 30;
    //int points = 0;
    char direcction = 'R';
    void keyPressEvent(QKeyEvent *event);
    void set_points_label(QGraphicsTextItem *points_label);
    void set_mapa(char mapa[21][30]);

    int position_x = 10;
    int position_y = 14;

    QTimer *timer_animation = new QTimer;

    void set_values(char mapa[21][30], int points, int lifes, QGraphicsTextItem* points_label, QGraphicsScene* scene);
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
    char mapa[21][30];
    int lifes;

    int points;
};

#endif // PAC_MAN_H
