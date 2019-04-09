#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include "sudoku.h"
using namespace std;
int main() {
    Sudoku su;
    int m[Sudoku::size][Sudoku::size] = {0};
//	ifstream fin("map", ios::in);
    for(int i = 0; i < Sudoku::size; i++)
        for(int j = 0; j < Sudoku::size; j++)
            cin >> m[i][j];
    su.setmap(m);
    //su.print_map();
    su.solve_plus();
}
