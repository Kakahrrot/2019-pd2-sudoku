#include <iostream>
#include "sudoku.h"
int main() {
    Sudoku su = Sudoku:: generate();
    //su.print_map(Sudoku::generate().map);
    su.print_map();

}
