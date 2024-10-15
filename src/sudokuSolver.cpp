#include "../include/sudokuSolver.hpp"
#include "../include/sudokuUtils.hpp"
#include "../include/heuristics.hpp"
#include <queue>
#include <climits>

void solveSudokuBFS(std::vector<Cell>& sudoku, int& states) {
    std::queue<std::vector<Cell>> q;
    q.push(sudoku);
    states = 0;

    while (!q.empty()) {
        auto currentSudoku = q.front();
        q.pop();

        int nextIndex = -1;
        for (int i = 0; i < 81; i++) {
            if (currentSudoku[i].value == 0) {
                nextIndex = i;
                break;
            }
        }

        if(nextIndex == -1) {
            sudoku = currentSudoku;
            return;
        }

        for (int value = 1; value <= 9; value++) {
            if (isValid(currentSudoku, nextIndex, value)) {
                currentSudoku[nextIndex].value = value;
                sudoku = currentSudoku;
                q.push(currentSudoku);
                states++;
            }
        }
    }
}

bool solveSudokuDFS(std::vector<Cell>& sudoku, int depth, int& states) {
    if (depth == 0) {
        return false;
    }

    bool isComplete = true;
    for (const auto& cell : sudoku) {
        if (cell.value == 0) {
            isComplete = false;
            break;
        }
    }
    if (isComplete) {
        return true;
    }

    int nextIndex = -1;
    for (int i = 0; i < 81; i++) {
        if (sudoku[i].value == 0) {
            nextIndex = i;
            break;
        }
    }

    for (int value = 1; value <= 9; value++) {
        if (isValid(sudoku, nextIndex, value)) {
            sudoku[nextIndex].value = value;
            states++;
            if (solveSudokuDFS(sudoku, depth - 1, states)) {
                return true;
            }
            sudoku[nextIndex].value = 0;
        }
    }

    return false;
}

bool solveSudokuIDS(std::vector<Cell>& sudoku, int& states) {
    for (int depth = 1; depth <= 81; ++depth) {
        if (solveSudokuDFS(sudoku, depth, states)) {
            return true;
        }
    }
    return false;
}

bool solveSudokuUCS(std::vector<Cell>& sudoku, int& states) {
    struct State {
        std::vector<Cell> state;
        int cost;

        bool operator<(const State& other) const {
            return cost > other.cost;
        }
    };

    std::priority_queue<State> pq;
    pq.push({sudoku, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        bool isComplete = true;
        for (const auto& cell : current.state) {
            if (cell.value == 0) {
                isComplete = false;
                break;
            }
        }
        if (isComplete) {
            sudoku = current.state;
            return true;
        }

        int nextIndex = -1;
        int minCost = INT_MAX;
        for (int i = 0; i < 81; i++) {
            if (current.state[i].value == 0) {
                nextIndex = i;
                break;
            }
        }

        for (int value = 1; value <= 9; value++) {
            if (isValid(current.state, nextIndex, value)) {
                states++;
                std::vector<Cell> newState = current.state;
                newState[nextIndex].value = value;
                pq.push({newState, current.cost + 1});
            }
        }
    }

    return false;
}

bool solveSudokuAStar(std::vector<Cell>& sudoku, int& states) {
    struct State {
        std::vector<Cell> state;
        int cost;
        int estimatedCost;

        bool operator<(const State& other) const {
            return (cost + estimatedCost) > (other.cost + other.estimatedCost);
        }
    };

    std::priority_queue<State> pq;
    pq.push({sudoku, 0, 0});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        bool isComplete = true;
        for (const auto& cell : current.state) {
            if (cell.value == 0) {
                isComplete = false;
                break;
            }
        }
        if (isComplete) {
            sudoku = current.state;
            return true;
        }

        int nextIndex = -1;
        int minHeuristic = INT_MAX;
        for (int i = 0; i < 81; i++) {
            if (current.state[i].value == 0) {
                int h = heuristic2(current.state, i);
                if (h < minHeuristic) {
                    minHeuristic = h;
                    nextIndex = i;
                }
            }
        }

        for (int value = 1; value <= 9; ++value) {
            if (isValid(current.state, nextIndex, value)) {
                states++;
                std::vector<Cell> newState = current.state;
                newState[nextIndex].value = value;
                int newCost = current.cost;
                int newHeuristic = heuristic2(newState, nextIndex);
                pq.push({newState, newCost, newHeuristic});
            }
        }
    }

    return false;
}

bool solveSudokuGreedy(std::vector<Cell>& sudoku, int& states) {
    int minHeuristic = INT_MAX;
    int nextIndex = -1;
    for (int i = 0; i < 81; i++) {
        if (sudoku[i].value == 0) {
            int h = combinedHeuristic(sudoku, i);
            if(h < minHeuristic) {
                minHeuristic = h;
                nextIndex = i;
            }
        }
    }

    if(nextIndex == -1) {
        return true;
    }

    for(int value = 1; value <= 9; value++) {
        if(isValid(sudoku, nextIndex, value)) {
            sudoku[nextIndex].value = value;
            states++;
            if(solveSudokuGreedy(sudoku, states)) {
                return true;
            }
            sudoku[nextIndex].value = 0;
        }
    }

    return false;
}
