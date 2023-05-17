#ifndef DOTS_H
#define DOTS_H

#include <QGraphicsPixmapItem>
#include <QObject>
/**
 * @brief Clase que representa graficamente los caminos del juego
 */
class Dot:public QGraphicsPixmapItem{
public:
    /**
* @brief Crea la imagen de los puntos que indica los caminos.
*
* @param no necesita
* @return una imagen
*/
    Dot();
};
#endif // DOTS_H
