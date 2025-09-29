#include <iostream>
#include "sudoku.h"

int main(int argc, char* argv[]) {

    Sudoku puzzle(argv[1]);
    puzzle.solve();
    puzzle.print();

    return 0;
}
