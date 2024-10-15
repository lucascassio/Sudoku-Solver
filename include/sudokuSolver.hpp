#ifndef SUDOKU_SOLVER_HPP
#define SUDOKU_SOLVER_HPP

#include <vector>
#include "cell.hpp"

void solveSudokuBFS(std::vector<Cell>& sudoku, int& states);
bool solveSudokuDFS(std::vector<Cell>& sudoku, int depth, int& states);
bool solveSudokuIDS(std::vector<Cell>& sudoku, int& states);
bool solveSudokuUCS(std::vector<Cell>& sudoku, int& states);
bool solveSudokuAStar(std::vector<Cell>& sudoku, int& states);
bool solveSudokuGreedy(std::vector<Cell>& sudoku, int& states);

#endif // SUDOKU_SOLVER_HPP
