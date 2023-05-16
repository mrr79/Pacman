//
// Created by henry on 15/05/23.
//

#include "GameWin.h"
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QPushButton>

GameWin::GameWin(QWidget *parent) {
    //Creation of the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 870, 620);
    int width = 870;
    int height = 620;
    scene->setBackgroundBrush(QBrush(QImage(":/Images/GO.png")));
    setScene(scene);
    show();
}