#ifndef HEURISTICS_HPP
#define HEURISTICS_HPP

#include <vector>
#include "cell.hpp"

int heuristic1(std::vector<Cell>& sudoku, int index);
int heuristic2(std::vector<Cell>& sudoku, int index);
float combinedHeuristic(std::vector<Cell>& sudoku, int index);

#endif // HEURISTICS_HPP
