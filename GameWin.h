//
// Created by henry on 15/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_GAMEWIN_H
#define PROYECTO_2_DATOS_LL_GAMEWIN_H


#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>

class GameWin: public QGraphicsView{
public:
    GameWin(QWidget * parent=0);
    QGraphicsScene * scene;
    QGraphicsTextItem *pointsf_label;
};


#endif //PROYECTO_2_DATOS_LL_GAMEWIN_H
