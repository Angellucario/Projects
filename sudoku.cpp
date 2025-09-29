#include "sudoku.h"
#include <iostream>
#include <fstream>

Sudoku::Sudoku(const char* filename) {
    std::ifstream file(filename);
    char comma;
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            file >> board[row][col];
            if (col != 8) {
                file >> comma;
            }
        }
    }
}

bool Sudoku::isValid(int row, int col, int number) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == number) return false;
        if (board[i][col] == number) return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int r = startRow; r < startRow + 3; ++r) {
        for (int c = startCol; c < startCol + 3; ++c) {
            if (board[r][c] == number) return false;
        }
    }

    return true;
}

bool Sudoku::solveHelper(int row, int col) {
    if (row == 9) return true;
    if (col == 9) return solveHelper(row + 1, 0);
    if (board[row][col] != 0) return solveHelper(row, col + 1);

    for (int number = 1; number <= 9; ++number) {
        if (isValid(row, col, number)) {
            board[row][col] = number;
            if (solveHelper(row, col + 1)) {
                return true;
            }
            board[row][col] = 0;
        }
    }

    return false;
}

void Sudoku::solve() {
    solveHelper(0, 0);
}

void Sudoku::print() {
    for (int row = 0; row < 9; ++row) {
        for (int col = 0; col < 9; ++col) {
            std::cout << board[row][col];
            if (col != 8) {
                std::cout << ",";
            }
        }
        std::cout << std::endl;
    }
}
