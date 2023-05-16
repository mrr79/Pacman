//
// Created by henry on 15/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_GAMEOVER_H
#define PROYECTO_2_DATOS_LL_GAMEOVER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class GameOver: public QGraphicsView{
public:
    GameOver(QWidget * parent=0);
    QGraphicsScene * scene;
};


#endif //PROYECTO_2_DATOS_LL_GAMEOVER_H
