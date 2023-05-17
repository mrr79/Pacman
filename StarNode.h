//
// Created by mrr on 12/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_STARNODE_H
#define PROYECTO_2_DATOS_LL_STARNODE_H

/**
 * @brief Clase que representa un nodo en una lista enlazada.
 */

class StarNode {
public:
    /**
     * @brief Constructor de la clase StarNode.
     * @param value1 Valor del primer elemento del nodo.
     * @param value2 Valor del segundo elemento del nodo.
     * @return no retorna nada.
     */
    StarNode(int value1, int value2);
    /**
     * @brief Devuelve el valor de un elemento del nodo según su índice.
     * @param index Índice del elemento.
     * @return Valor del elemento del nodo.
     */
    int getNode(int index) const;
    /**
     * @brief Devuelve el siguiente nodo en la lista.
     * @param ningun parammetro de entrada.
     * @return Puntero al siguiente nodo.
     */
    StarNode* getNext() const;
    /**
     * @brief Establece el siguiente nodo en la lista.
     * @param nextNode Puntero al siguiente nodo.
     * @return no retorna nada.
     */
    void setNext(StarNode* nextNode);
    /**
    * @brief Devuelve el valor del primer elemento del nodo (coordenada X).
    * @param ningun parametro de entrada.
    * @return Valor del primer elemento del nodo.
    */
    int getNodeX();
    /**
     * @brief Devuelve el valor del segundo elemento del nodo (coordenada Y).
     * @param ningun parametro de entrada.
     * @return Valor del segundo elemento del nodo.
     */
    int getNodeY();
private:
    int value1;
    int value2;
    StarNode* next;
};


#endif //PROYECTO_2_DATOS_LL_STARNODE_H
