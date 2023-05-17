//
// Created by henry on 15/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_GAMEOVER_H
#define PROYECTO_2_DATOS_LL_GAMEOVER_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
/**
 * @brief Clase que representa la pantalla de fin de juego.
 *
 * Esta clase hereda de QWidget y muestra la pantalla de fin de juego.
 */
class GameOver: public QGraphicsView{
public:
    /**
     * @brief Constructor de la clase GameOver.
     * @param parent Puntero al objeto QWidget padre.
     * @return no retorna nada pero genera la ventana de game over
     */
    GameOver(QWidget * parent=0);
    QGraphicsScene * scene;
};


#endif //PROYECTO_2_DATOS_LL_GAMEOVER_H
