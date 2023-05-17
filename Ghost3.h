//
// Created by henry on 15/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_GHOST3_H
#define PROYECTO_2_DATOS_LL_GHOST3_H


#include <QGraphicsPixmapItem>
#include <QObject>
#include "Pac_Man.h"
#include "Game.h"
#include "StarNode.h"
#include "StarList.h"
/**
 * @brief Clase que representa un fantasma 3 en el juego.
 * Este fantasma es el fantasa de color celeste y se mueve ppersiguiendo al pacman o al poder usando el algoritmo A*.
 *
 * Esta clase hereda de QObject y QGraphicsPixmapItem, y representa un fantasma en el juego.
 */
class Ghost3:public QObject , public  QGraphicsPixmapItem{
Q_OBJECT
public:
    /**
     * @brief Constructor de la clase Ghost.
     * @param mapa Matriz que representa el mapa del juego.
     * @param j Posición horizontal inicial del fantasma en la matriz.
     * @param i Posición vertical inicial del fantasma en la matriz.
     * @return no retorna nada.
     */
    Ghost3(int mapa[21][30],int j,int i);
    /**
 * @brief Establece la matriz del mapa del juego.
 * @param mapa Matriz que representa el mapa del juego.
 * @return no retorna nada pero hace el set de la matriz para ejecutar los movimientos sobre esta.
 */
    void random_location();

    Pac_Man* getPacman();
    /**
     * @brief Establece la matriz del mapa del juego.
     * @param mapa Matriz que representa el mapa del juego.
     * @return no retorna nada pero hace el set de la matriz para ejecutar los movimientos sobre esta.
     */
    void set_mapa(int mapa[21][30]);
    //StarNode head;
    StarList lista_randomg;

public slots:
    /**
        * @brief Mueve el fantasma en el juego.
        * @param no tiene parametros de entrada.
        * @return no retorna nada pero genera el movmiento del fantasma en la pantalla basandose en la matriz con las direcciones generadas por A*.
        */
    void move();

    /**
     * @brief Realiza el seguimiento del personaje principal (Pac-Man).
     * @param no tiene parametros de entrada.
     * @return no retorna nada pero ejecuta el algoritmo A* para decidir los movimeintos del fantasma.
     */
    void chasePacMan();

public slots:
    /**
 * @brief Actualiza la posición del Pac-Man en el fantasma.
 * @param x Posición horizontal del Pac-Man en la matriz.
 * @param y Posición vertical del Pac-Man en la matriz.
 * @return no retorna nada.
 */
    void actualizar_posicion_pacman3(int x, int y);
    /**
* @brief Verifica si hay colisiones con otros elementos en el juego.
*
* Esta función comprueba si el fantasma colisiona con otros elementos en el juego, como los SuperDots.
* En caso de colisión, realiza las acciones correspondientes.
* @param no tiene parametros de entrada.
* @return no retorna nada pero verfiica si el fantasma roba el poder.
*/
    void check_collision();

private:
    int speed=30;
    int position_x3;
    int position_y3;
    int mapa[21][30];

    int pac_man_x; // Declare pac_man_x as a private member variable
    int pac_man_y;
    int j;
    int i;
    bool search=false;

    StarList pathList;
    int new_GX;
    int new_GY;
    bool searching;
    bool route_completed;

};


#endif //PROYECTO_2_DATOS_LL_GHOST3_H
