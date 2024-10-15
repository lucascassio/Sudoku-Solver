#ifndef SUDOKU_UTILS_HPP
#define SUDOKU_UTILS_HPP

#include <vector>
#include <string>
#include <sstream>
#include "cell.hpp"

std::vector<Cell> createSudoku(const std::string& input_str);
void assignNeighbors(std::vector<Cell>& sudoku);
bool isValid(const std::vector<Cell>& sudoku, int index, int value);
void printSolution(const std::vector<Cell>& sudoku);


#endif // SUDOKU_UTILS_HPP
