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

class AStar {
public:
    void setGrid(int grid[ROW][COL]);
    void setSource(int row, int col);
    void setDestination(int row, int col);
    void findPath();
    StarList getPath();

    void aStarSearch(int grid[][COL], Pair src, Pair dest);

private:
    int grid[ROW][COL];
    Pair src, dest;
    bool isValid(int row, int col);
    bool isUnBlocked(int grid[][COL], int row, int col);
    bool isDestination(int row, int col, Pair dest);
    double calculateHValue(int row, int col, Pair dest);
    void tracePath(cell cellDetails[][COL], Pair dest);
    StarList pathList;
};


#endif //PROYECTO_2_DATOS_LL_ASTAR_H
