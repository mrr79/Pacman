#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include "Game.h"
extern bool nivel1;
extern bool nivel2;
extern bool nivel3;
extern bool nivel4;
extern bool win;
extern bool loose;

extern int vidas;
extern int puntos;
extern int nivel;
/**
 * @brief Clase que crea las instancias del jeugo en los diferentes niveles y sus condiciones de puntos y vidas.
 */
class Dificulties_Window: public QGraphicsView{
Q_OBJECT

public:
/**
 * @brief Constructor de la clase Dificulties que crea la escena y configura los botones para cada nivel de dificultad.
 * @param parent Puntero al widget padre.
 * @return una pantalla.
 */
  Dificulties_Window(QWidget * parent=0);

  //Game dificulties
    /**
@brief Esta función inicia el nivel normal del juego.
Esta función crea una matriz que representa el mapa del nivel, inicializa las variables de puntos y vidas y muestra la ventana del nivel. 21x30 elementos,
donde cada elemento representa una celda del mapa y su contenido. Los 0 son los obstaculos, los 1 los camninos, el 9 la posicion inical del pacman, el 11 la del fantasma 1y 12 la del fantasma 2, el 13 la del fantasma 3 y 14 la del fantasma 4.
@param Ninguno
@return No retorna ningún valor.
*/
  void classic();
    /**
@brief Esta función inicia el nivel normal del juego.
Esta función crea una matriz que representa el mapa del nivel, inicializa las variables de puntos y vidas y muestra la ventana del nivel. 21x30 elementos,
 donde cada elemento representa una celda del mapa y su contenido. Los 0 son los obstaculos, los 1 los camninos, el 9 la posicion inical del pacman, el 11 la del fantasma 1y 12 la del fantasma 2, el 13 la del fantasma 3.
@param Ninguno
@return No retorna ningún valor.
 */
  void hard();
    /**
  @brief Esta función inicia el nivel normal del juego.
  Esta función crea una matriz que representa el mapa del nivel, inicializa las variables de puntos y vidas y muestra la ventana del nivel. 21x30 elementos,
   donde cada elemento representa una celda del mapa y su contenido. Los 0 son los obstaculos, los 1 los camninos, el 9 la posicion inical del pacman, el 11 la del fantasma 1y 12 la del fantasma 2.
  @param Ninguno
  @return No retorna ningún valor.
   */
  void normal();
/**
@brief Esta función inicia el nivel fácil del juego.
Esta función crea una matriz que representa el mapa del nivel, inicializa las variables de puntos y vidas y muestra la ventana del nivel. 21x30 elementos,
 donde cada elemento representa una celda del mapa y su contenido. Los 0 son los obstaculos, los 1 los camninos, el 9 la posicion inical del pacman, y 11 la del fantasma 1.
@param Ninguno
@return No retorna ningún valor.
 */
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
/**
* @brief Esta función verifica si se ha ganado o perdido el juego y realiza acciones correspondientes.
 * Si pierde: se elimina el objeto actual y se crea un nuevo objeto "GameOver" y se muestra la ventana.
 * Si gana: Se cierra la ventana actual, se elimina el objeto actual, se crea un "GameWin" y se muestra la ventana.
 * @param Ninguno.
 * @return No retorna ningún valor.
 */

    void checkwin();

};

#endif // MAIN_WINDOW_H
