//
// Created by henry on 14/05/23.
//

#include "Backtracking.h"
#include <iostream>



bool Backtracking::isSafe(int x, int y, int n, int m, vector<vector<int>> &maze, vector<vector<int>> &visited) {
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && visited[x][y] == 0 && maze[x][y] == 1) {
        return true;
    }
    else {
        return false;
    }
}

void Backtracking::solve(vector<vector<int>> &maze, int n, int m, int x, int y, string path, vector<string> &ans, vector<vector<int>> &visited) {
    cout << "entra a solve:" << endl;
    if (x == 1 && y == 1) {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    cout << "Current position: (" << x << "," << y << ")" << endl;

//Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, m, maze, visited)) {
        path.push_back('D');
        cout << "Going Down" << endl;
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    } else {
        cout << "Not safe to move Down" << endl;
    }

//Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, m, maze, visited)) {
        path.push_back('R');
        cout << "Going Right" << endl;
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    } else {
        cout << "Not safe to move Right" << endl;
    }

//Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, m, maze, visited)) {
        path.push_back('U');
        cout << "Going Up" << endl;
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    } else {
        cout << "Not safe to move Right" << endl;
    }

    //Left
    newx = x;
    newy = y - 1;
    //revisa si es factible ir hacia izquierda
    if (isSafe(newx, newy, n, m, maze, visited)) {
        path.push_back('L');
        cout << "Going Left" << endl;
        solve(maze, n, m, newx, newy, path, ans, visited);
        //backtracking, elimina la ultima decision tomada para devolverse
        path.pop_back();
    } else {
        // imprime que no es seguro moverse en esa direccion
        cout << "Not safe to move Left" << endl;
    }
}

vector<string> Backtracking::possiblePaths(vector<vector<int>> &maze, int eq, int ye) {
    //tamano del tablero
    int n = maze.size();
    int m = maze[0].size();
    vector<string> ans;  //guarda todos los caminos
    //si hay errores en la posiciones de salida o fin devuelve nulo
    if(maze[0][0] == 0 || maze[n-1][m-1]==0){
        return ans;
    }
    //posicion inicial del fantasma
    int x =eq;
    int y =ye;
    //guarda donde ya se visito
    vector<vector<int>> visited(n,vector<int>(m,0));

    string path = "";
    //llama a resolver por primera vez
    solve(maze,n,m,x,y,path,ans,visited);

    //retorna los caminos
    sort(ans.begin(),ans.end());

    return ans;
}

void solve(vector<vector<int>> &vector1, int n, int m, int x, int y, string basicString, vector<string> vector2,
           vector<vector<int>> vector3) {

}
