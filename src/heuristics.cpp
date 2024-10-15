#include "../include/heuristics.hpp"
#include "../include/sudokuUtils.hpp"

int heuristic1(std::vector<Cell>& sudoku, int index) {
    int count = 0;
    Cell currentCell = sudoku[index];
    for (auto neighborIndex : currentCell.neighbors) {
        if (sudoku[neighborIndex].value == 0) {
            count++;
        }
    }
    return count;
}

int heuristic2(std::vector<Cell>& sudoku, int index) {
    int count = 0;
    for(int i = 1; i <= 9; i++) {
        if(isValid(sudoku, index, i)) {
            count++;
        }
    }

    return count;
}

float combinedHeuristic(std::vector<Cell>& sudoku, int index) {
    double weight1 = 0.2;
    double weight2 = 0.8;

    int h1 = heuristic1(sudoku, index);
    int h2 = heuristic2(sudoku, index);

    return weight1 * h1 + weight2 * h2;
}
