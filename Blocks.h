#ifndef BLOCKS_H
#define BLOCKS_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Block:public QGraphicsPixmapItem{
public:
    /**
 * @brief Crea los bloques de obstaculos.
 *
 * @param no necesita
 * @return una imagen
 */
    Block();
};

#endif // BLOCKS_H
