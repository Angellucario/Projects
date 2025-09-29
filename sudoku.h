#ifndef SUDOKU_H
#define SUDOKU_H

class Sudoku {
public:
    int board[9][9];

    Sudoku(const char* filename);
    void solve();
    bool isValid(int row, int column, int number);
    bool solveHelper(int row, int column);
    void print();
};

#endif
