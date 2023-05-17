#ifndef LEVELS_H
#define LEVELS_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPixmap>
#include "Pac_Man.h"
#include "Ghost.h"
/**
 * @brief Clase que configura el comportamiento generla del juego y anade los elementos a la pantalla principal del mismo.
 */
class Game: public QGraphicsView{

public:
/**
 * @brief Constructor de la clase Game.
 * @param mapa Matriz de tamaño 21x30 que representa el mapa del juego.
 * @param points Puntos iniciales del jugador.
 * @param lifes Vidas iniciales del jugador.
 * @param parent Puntero al objeto QWidget padre.
 * @return no retorna nada pero genra la pantalla de juego.
 */
    Game(int mapa[21][30], int points, int lifes, QWidget *parent = nullptr);

    static const uint LABYRINTH_WIDTH  = 21;
    static const uint LABYRINTH_HEIGHT = 31;


    void setPoints(int points);

    QPixmap m_labyrinthPixmap;
    QGraphicsPixmapItem* m_labyrinthPixmapItems[LABYRINTH_WIDTH][LABYRINTH_HEIGHT];
    QPixmap m_labyrinthPixmaps[32];

    QTimer *timer_points = new QTimer();
    QTimer *timer_lifes = new QTimer();
    QTimer *timer_level = new QTimer();


    Pac_Man *pac_man;

    QGraphicsTextItem *points_label;
    QGraphicsTextItem *lifes_label;
    QGraphicsTextItem *level_label;
/**
 * @brief Obtiene el objeto Pac-Man del juego.
 * @param ningun parametro de entrada.
 * @return Puntero al objeto Pac-Man.
 */
    Pac_Man* get_pacman();

    QGraphicsScene * scene;
    void deleteghost();

private:
/**
 * @brief Inicializa el laberinto del juego.
 *
 * Este método crea y configura los elementos del laberinto, como bloques y puntos, según los valores de la matriz m_mapa.
 * También establece la posición inicial del Pac-Man y los fantasmas.
 * @param ningun parammetro de entrada.
 * @return no retorna nada pero genera las posiciones iniciales de los objetos en pantalla.
 */
    void init_lab();

    int m_points;
    int m_lifes;
    int m_mapa[21][30];
    int pacmanX=0;
    int pacmanY=0;
    int jghost=0;
    int ighost=0;
    int jghost2;
    int ighost2;
    int jghost3;
    int ighost3;
    int jghost4;
    int ighost4;

};

#endif // LEVELS_H
