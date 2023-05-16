//
// Created by henry on 15/05/23.
//

#include "GameWin.h"
#include "Pac_Man.h"
#include <QLabel>
#include <QGraphicsProxyWidget>
#include <QPushButton>

GameWin::GameWin(QWidget *parent) {
    //Creation of the scene
    QGraphicsScene *scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 870, 620);
    pointsf_label = new QGraphicsTextItem("Final Points: " + QString::number(pointsR));
    pointsf_label->setDefaultTextColor(Qt::black);
    scene->addItem(pointsf_label);
    pointsf_label->setPlainText("Final Points: " + QString::number(pointsR));
    QFont font("Arial", 20, QFont::Helvetica);
    pointsf_label->setFont(font);
    scene->setBackgroundBrush(QBrush(QImage(":/Images/GW.png")));
    setScene(scene);
    show();
}