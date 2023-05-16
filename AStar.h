//
// Created by mrr on 11/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_ASTAR_H
#define PROYECTO_2_DATOS_LL_ASTAR_H


#pragma once
#include <bits/stdc++.h>
#include "StarNode.h"
#include "StarList.h"

using namespace std;

#define ROW 21
#define COL 30

typedef pair<int, int> Pair;
typedef pair<double, pair<int, int>> pPair;

struct cell {
    int parent_i, parent_j;
    double f, g, h;
};
extern bool ejecutar;
class AStar {
public:
/**
 * @brief Toma los resutados del algoritmo y los convierte en una lista tipo StarList.
 *
 * @param int grid[ROW][COL]
 * @return La lista con las celdas para llegar al destino.
 */
    StarList getPath();

    /**
 * @brief Busca el mejor camino entre el destino y el inicio, usando el Algoritmo Astar
 *
 * @param int grid[ROW][COL]: la matriz
 * @param Pair src: desde donde se inicia la ruta.
 * @param Pair dest donde se finaliza la ruta.
 * @return En caso de encontrar la celda de destino o de no poder alcanzarla, la función imprime mensajes informativos.
 */
    void aStarSearch(int grid[][COL], Pair src, Pair dest);

private:
    int grid[ROW][COL];
    Pair src, dest;
    /**
 * @brief Verifica si el punto de origen y el punto de destino están dentro del rango válido de la matriz.
 *
 * @param int row fila en la matriz
 * @param int col columna en la matriz
 * @return True si el origen y destino estan en el rango de la matriz, si no, la búsqueda no puede continuar y se imprime un mensaje correspondiente
 */
    bool isValid(int row, int col);
    /**
* @brief Verifica si el punto de origen y el punto de destino son celdas validas en la matriz, es decir, no son 0.
*
* @param int grid[ROW][COL]: la matriz
* @param int row fila en la matriz
* @param int col columna en la matriz
* @return True si el origen y destino estan en el rango de la matriz, si no, la búsqueda no puede continuar y se imprime un mensaje correspondiente
*/
    bool isUnBlocked(int grid[][COL], int row, int col);
    /**
* @brief Verifica si el punto de destino es el inidicado, basandose en las coordenadas del destino en la matriz y comparandolas con las encontradas por el algoritmo.
*
* @param int Pair dest el destino final de busqueda
* @param int row fila en la matriz
* @param int col columna en la matriz
* @return True si el destino encontrado es el destino final, false si no es el destino final y lo sigue buscando.
*/
    bool isDestination(int row, int col, Pair dest);
    /**
* @brief calcula la heuristica (pitagoras) de cada celda de la matriz y el destino, para encontrar el mejor camnio a este.
*
* @param int Pair dest el destino final de busqueda
* @param int row fila en la matriz
* @param int col columna en la matriz
* @return El valor de la heuristica de tipo double..
*/
    double calculateHValue(int row, int col, Pair dest);
    /**
* @brief traza el camino desde el destino hasta la fuente utilizando el stack Path y muestra el camino en forma de mensajes de impresión.
     * También almacena el camino en la lista pathList para su posterior uso.
* @param int Pair dest coordenadas del destino final de busqueda
* @param cell cellDetails[][COL] coordenadas de la celda padre.
* @return El valor de la heuristica de tipo double..
*/
    void tracePath(cell cellDetails[][COL], Pair dest);
    StarList pathList;
};


#endif //PROYECTO_2_DATOS_LL_ASTAR_H
