//
// Created by henry on 15/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_GAMEWIN_H
#define PROYECTO_2_DATOS_LL_GAMEWIN_H


#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
/**
 * @brief Clase que representa la pantalla de fin de juego si se gana el mismo.
 *
 * Esta clase hereda de QWidget y muestra la pantalla de fin de juego si el jugador ha comppletado con exito toods los niveles.
 */

class GameWin: public QGraphicsView{
public:
    /**
 * @brief Constructor de la clase GameWin.
 * @param parent Puntero al objeto QWidget padre.
 * @return no retorna nada pero genera la ventana cuando se gana el juego.
 */
    GameWin(QWidget * parent=0);
    QGraphicsScene * scene;
    QGraphicsTextItem *pointsf_label;
};


#endif //PROYECTO_2_DATOS_LL_GAMEWIN_H
