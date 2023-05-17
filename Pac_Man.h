#ifndef PAC_MAN_H
#define PAC_MAN_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "StarList.h"
#include "StarNode.h"
extern int pointsR;
extern bool poder_activo;
extern int poder_x;
extern int poder_y;

/**
 * @brief Clase que configura el comportamiento del pacman, personaje del jugador en el juego.
 */
class Pac_Man: public QObject , public  QGraphicsPixmapItem{
     Q_OBJECT
public:
    Pac_Man(int mapa[21][30], int points, int lifes, QGraphicsTextItem *points_label, QGraphicsScene *scene,int j, int i);
    void set_points(int points);
    void set_lifes(int lifes);
    /**
 * @brief Genera una ubicación aleatoria para el Pac-Man.
 *
 * Esta función selecciona una ubicación aleatoria dentro de la lista de nodos aleatorios.
 * La posición x e y del nodo seleccionado se asignan a las variables poder_x y poder_y respectivamente.
 * Luego, se establece la posición del Pac-Man en la escena utilizando las coordenadas poder_x y poder_y multiplicadas por 30.
     * @param ningun parammetro de entrada.
 * @return no retorna nada
 */
    void random_location();
    /**
 * @brief Inicia el servidor de socket para recibir mensajes entrantes.
 *
 * Esta función crea un socket, configura la dirección y el puerto, y escucha conexiones entrantes.
 * Una vez que se establece una conexión, se procesan los mensajes recibidos y se realiza la acción correspondiente.
 * Los mensajes deben tener el formato "giro_x,giro_y,giro_z", donde los valores de giro_x, giro_y y giro_z son números en punto flotante.
 * Basándose en los valores recibidos, se establece la dirección de movimiento del Pac-Man.
 * También se actualizan valores del juego como el puntaje.
 * Finalmente, se envía una respuesta al cliente y se cierran los sockets.
 * @param ningun parammetro de entrada.
 * @return no retorna nada
 */
    void SocketServer();
    bool super_dot = false;
    int speed = 30;
    bool app = false;
    //int points = 0;
    char direcction = 'R';
    /**
 * @brief Maneja el evento de presionar una tecla.
 * @param event Puntero al evento de teclado.
 * @return no retorna nada.

 */
    void keyPressEvent(QKeyEvent *event);
    /**
 * @brief Establece el elemento de texto para mostrar los puntos del Pac-Man.
 * @param points_label Puntero al elemento de texto para mostrar los puntos.
     * @return no retorna nada.
 */
    void set_points_label(QGraphicsTextItem *points_label);
    /**
 * @brief Establece el elemento de texto para mostrar las vidas del Pac-Man.
 * @param lifes_label Puntero al elemento de texto para mostrar las vidas.
     * @return no retorna nada.
 */
    void set_lifes_label(QGraphicsTextItem *lifes_label);
    /**
 * @brief Establece el elemento de texto para mostrar el nivel actual del Pac-Man.
 * @param level_label Puntero al elemento de texto para mostrar el nivel.
     * @return no retorna nada.
 */
    void set_level_label(QGraphicsTextItem *level_label);
/**
 * @brief Establece el mapa del juego para el Pac-Man.
 * @param mapa Matriz que representa el mapa del juego.
 * @return no retorna nada.
 * Esta función establece el mapa del juego para el Pac-Man, permitiendo que el personaje tenga conocimiento
 * sobre el entorno en el que se encuentra.
 */
    void set_mapa(int mapa[21][30]);

    int act_pacman_x;

    int act_pacman_y;
    int points_count = 0;
    /**
 * @brief Obtiene la coordenada y actual del Pac-Man en el mapa.
 *
 * @return Coordenada y actual del Pac-Man.
 * @return no retorna nada.
 */
    int getActPacmanX();
    /**
 * @brief Obtiene la coordenada x actual del Pac-Man en el mapa.
 *
 * @return Coordenada x actual del Pac-Man.
 * @return no retorna nada.
 */
    int getActPacmanY();
    /**
 * @brief Establece la coordenada x actual del Pac-Man en el mapa.
 *
 * @param m Coordenada x actual del Pac-Man.
 * @return no retorna nada.
 */
    void setActPacmanX(int m);

    /**
 * @brief Establece la coordenada y actual del Pac-Man en el mapa.
 *
 * @param n Coordenada y actual del Pac-Man.
 * @return no retorna nada.
 */
    void setActPacmanY(int n);
    StarList lista_random;



    QTimer *timer_animation = new QTimer;
/**
 * @brief Establece los valores iniciales para el Pac-Man.
 * @param mapa Matriz que representa el mapa del juego.
 * @param points Puntos iniciales del Pac-Man.
 * @param lifes Vidas iniciales del Pac-Man.
 * @param points_label Puntero al elemento de texto para mostrar los puntos.
 * @param scene Puntero a la escena del juego.
 * @return no retorna nada.
 */
    void set_values(int mapa[21][30], int points, int lifes, QGraphicsTextItem* points_label, QGraphicsScene* scene);
public slots:
    /**
 * @brief Verifica las colisiones del Pac-Man con otros elementos del juego.
 *
 * Esta función comprueba las colisiones del Pac-Man con otros elementos del juego, como puntos, superpuntos(poderes) y fantasmas.
 * Actualiza los puntos, vidas y realiza acciones específicas dependiendo del tipo de colisión.
     * @param ningun parammetro de entrada.
 * @return no retorna nada
 */
    void check_collision();
/**
 * @brief Mueve al Pac-Man en la dirección especificada.
 *
 * Esta función mueve al Pac-Man en la dirección especificada por la variable `direcction`.
 * Verifica los límites del mapa y las colisiones con los obstáculos antes de realizar el movimiento.
 * Actualiza las coordenadas `act_pacman_x` y `act_pacman_y` para reflejar la posición actual del Pac-Man en el mapa.
 * Emite una señal `pacman_posicion_actualizada` con las nuevas coordenadas del Pac-Man para que los fantasmas las puedan usar.
 * @param ningun parammetro de entrada.
 * @return no retorna nada
 */
    void move();
    /**
 * @brief Verifica los puntos del Pac-Man y realiza acciones en función de ellos.
 *
 * Esta función verifica los puntos del Pac-Man y realiza acciones específicas según los puntos alcanzados,
 * como cambiar de nivel o determinar la victoria o derrota del juego.
 * @param ningun parammetro de entrada.
 * @return no retorna nada
 */
    void check_points();
/**
 * @brief Realiza la animación del Pac-Man en la dirección derecha.
 *
 * Esta función realiza la animación del Pac-Man en la dirección derecha, cambiando las imágenes del sprite en ciclos.
 * Actualiza el pixmap del Pac-Man con la imagen correspondiente a cada ciclo.
 * @param ningun parammetro de entrada.
 * @return no retorna nada.
 */
    void animation_R();
    /**
 * @brief Realiza la animación del Pac-Man en la dirección izquerda.
 *
 * Esta función realiza la animación del Pac-Man en la dirección izquierda, cambiando las imágenes del sprite en ciclos.
 * Actualiza el pixmap del Pac-Man con la imagen correspondiente a cada ciclo.
 * @param ningun parammetro de entrada.
 * @return no retorna nada.
 */
    void animation_L();
    /**
 * @brief Realiza la animación del Pac-Man en la dirección arriba.
 *
 * Esta función realiza la animación del Pac-Man en la dirección arriba, cambiando las imágenes del sprite en ciclos.
 * Actualiza el pixmap del Pac-Man con la imagen correspondiente a cada ciclo.
 * @param ningun parammetro de entrada.
 * @return no retorna nada.
 */
    void animation_U();
    /**
 * @brief Realiza la animación del Pac-Man en la dirección abajo.
 *
 * Esta función realiza la animación del Pac-Man en la dirección abajo, cambiando las imágenes del sprite en ciclos.
 * Actualiza el pixmap del Pac-Man con la imagen correspondiente a cada ciclo.
 * @param ningun parammetro de entrada.
 * @return no retorna nada.
 */
    void animation_D();


private:
    QGraphicsTextItem *points_label;
    QGraphicsTextItem *lifes_label;
    QGraphicsTextItem *level_label;
    QGraphicsScene* scene;
    int mapa[21][30];
    int lifes;
    int points;
    int m;
    int n;

signals:
    void pacman_posicion_actualizada(int x, int y);
};

#endif // PAC_MAN_H
