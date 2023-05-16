//
// Created by henry on 14/05/23.
//

#ifndef PROYECTO_2_DATOS_LL_BACKTRACKING_H
#define PROYECTO_2_DATOS_LL_BACKTRACKING_H
#include <vector>
#include <string>
#include<bits/stdc++.h>
using namespace std;

extern int backtrack_x;
extern int backtrack_y;

class Backtracking {
#include <vector>
#include <string>

/**
 * @brief Verifica si una posición en el laberinto es segura.
 *
 * Esta función verifica si una posición dada en el laberinto cumple con las condiciones de seguridad. La posición se considera segura si se encuentra dentro de los límites del laberinto, no ha sido visitada previamente y su valor en el laberinto es 1, 9, 11, 12, 13 o 14 (cualquier opcion menos 0).
 *
 * @param x La coordenada x de la posición a verificar.
 * @param y La coordenada y de la posición a verificar.
 * @param n El número total de filas del laberinto.
 * @param m El número total de columnas del laberinto.
 * @param maze El laberinto representado como una matriz de enteros.
 * @param visited Una matriz de enteros que indica qué posiciones han sido visitadas en el laberinto.
 * @return true si la posición es segura, false en caso contrario.
 */
    bool isSafe(int x, int y, int n, int m, vector<vector<int>> &maze, vector<vector<int>> &visited);

/**
 * @brief Resuelve el laberinto utilizando el algoritmo de backtracking.
 *
 * Esta función resuelve el laberinto utilizando el algoritmo de backtracking. Recibe el laberinto, sus dimensiones, la posición inicial, una cadena que representa el camino actual, un vector para almacenar las soluciones encontradas y una matriz que indica las posiciones visitadas.
 *
 * @param maze El laberinto representado como una matriz de enteros.
 * @param n El número total de filas del laberinto.
 * @param m El número total de columnas del laberinto.
 * @param x La coordenada x de la posición actual.
 * @param y La coordenada y de la posición actual.
 * @param path El camino actual en el laberinto.
 * @param ans Un vector que almacenará las soluciones encontradas.
 * @param visited Una matriz de enteros que indica qué posiciones han sido visitadas en el laberinto.
 */
    void solve(vector<vector<int>> &maze, int n, int m, int x, int y, string path, vector<string> &ans,
               vector<vector<int>> &visited);

public:
    /**
 * @brief Encuentra todos los caminos posibles en el laberinto desde una posición de inicio hasta una posición de fin.
 *
 * Esta función encuentra todos los caminos posibles en el laberinto desde una posición de inicio hasta una posición de fin. Recibe el laberinto, las coordenadas de la posición de inicio y las coordenadas de la posición de fin. Devuelve un vector que contiene todos los caminos encontrados.
 *
 * @param maze El laberinto representado como una matriz de enteros.
 * @param eq La coordenada x de la posición de inicio.
 * @param ye La coordenada y de la posición de inicio.
 * @return Un vector que contiene todos los caminos posibles desde la posición de inicio hasta la posición de fin.
 */
    std::vector<std::string> possiblePaths(std::vector<std::vector<int>> &maze, int eq, int ye);
};


#endif //PROYECTO_2_DATOS_LL_BACKTRACKING_H
