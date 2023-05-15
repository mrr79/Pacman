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

    bool isSafe(int x, int y, int n, int m, vector<vector<int>> &maze, vector<vector<int>> &visited);

    void solve(vector<vector<int>> &maze, int n, int m, int x, int y, string path, vector<string> &ans,
               vector<vector<int>> &visited);

public:
    std::vector<std::string> possiblePaths(std::vector<std::vector<int>> &maze, int eq, int ye);
};


#endif //PROYECTO_2_DATOS_LL_BACKTRACKING_H
