//
// Created by mrr on 12/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_STARLIST_H
#define PROYECTO_2_DATOS_LL_STARLIST_H

#include "StarNode.h"
/**
 * @brief Clase que representa una lista enlazada de nodos de estrellas.
 */
class StarList {
public:
    /**
    * @brief Constructor de la clase StarList.
    * @param ningun parammetro de entrada.
    * @return no retorna nada
    */
    StarList();
/**
     * @brief Agrega un nuevo nodo al final de la lista.
     * @param new_node Puntero al nodo que se va a agregar.
     * @return no retorna nada
     */
    void append(StarNode* new_node);
/**
     * @brief Devuelve el número de elementos en la lista.
     * @param ningun parammetro de entrada.
     * @return Número de elementos en la lista.
     */
    int size() const;
    /**
     * @brief Devuelve el puntero al primer nodo de la lista.
     * @param ningun parammetro de entrada.
     * @return Puntero al primer nodo de la lista.
     */
    StarNode* getHead() const;
    /**
     * @brief Imprime los elementos de la lista.
     * @param ningun parammetro de entrada.
     * @return no retorna nada
     */
    void printList() const;
    /**
     * @brief Elimina el primer nodo de la lista.
     * @param ningun parammetro de entrada.
     * @return no retorna nada.
     */
    void removeHead();
    /**
     * @brief Verifica si la lista está vacía.
     * @param ningun parammetro de entrada.
     * @return `true` si la lista está vacía, `false` en caso contrario.
     */
    bool isEmpty() const;
    /**
    * @brief Devuelve un nodo aleatorio de la lista.
    * @param ningun parammetro de entrada.
    * @return Puntero al nodo seleccionado aleatoriamente, o nullptr si la lista está vacía.
    */
    StarNode *getRandomNode() const;
    /**
     * @brief Elimina todos los nodos de la lista.
     * @param ningun parammetro de entrada.
     * @return no retorna nada.
     */
    void clear();
private:
    StarNode* head;
    int listSize;


};


#endif //PROYECTO_2_DATOS_LL_STARLIST_H
