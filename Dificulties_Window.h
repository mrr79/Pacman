#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

class Dificulties_Window: public QGraphicsView{
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

};

#endif // MAIN_WINDOW_H
