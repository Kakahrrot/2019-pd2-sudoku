#ifndef SUDOKU_H
#define SUDOKU_H

/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class Sudoku {
  public:
    static const int size = 9;
    Sudoku();

    // generate
    static Sudoku generate();

    // transform
    void setmap(int map[][size]);
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve
    void solve();
    void solve_inverse();
    void print_map();
  private:
    int get_position();
    int get_position(int *p);
    bool check(int row, int col, int n);
    int map[size][size];

};

#endif // SUDOKU_H
