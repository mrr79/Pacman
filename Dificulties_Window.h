#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Game.h"
extern bool nivel1;
extern int vidas;
extern int puntos;
extern int nivel;

class Dificulties_Window: public QGraphicsView{
Q_OBJECT

public:

  Dificulties_Window(QWidget * parent=0);

  //Game dificulties
  void classic();
  void hard();
  void normal();
  void easy();


  QGraphicsScene * scene;
private:
  int width = 800;
  int height = 600;
  Game *level_1;
  Game *level_2;
  Game *level_3;
  Game *level_4;

public slots:
    void checkwin();

};

#endif // MAIN_WINDOW_H
