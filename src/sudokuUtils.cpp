#include "../include/sudokuUtils.hpp"

using namespace std;

vector<Cell> createSudoku(const string& inputStr) {
    stringstream ss(inputStr);
    vector<Cell> sudoku;
    for (int i = 0; i < 81; i++) {
        char cellValue;
        ss >> cellValue;
        if (cellValue == ' ') {
            ss >> cellValue; // Pula o espaço entre os blocos
        }
        int value = cellValue - '0'; // Convertendo char para int
        Cell cell = {value, i, {}};
        sudoku.push_back(cell);
    }
    return sudoku;
}

void assignNeighbors(vector<Cell>& sudoku) {
    for (int i = 0; i < 81; i++) {
        Cell& cell = sudoku[i];
        int row = i / 9;
        int col = i % 9;
        for (int k = 0; k < 9; k++) {
            // Mesma linha
            if (k != col) {
                cell.neighbors.push_back(row * 9 + k);
            }
            // Mesma coluna
            if (k != row) {
                cell.neighbors.push_back(k * 9 + col);
            }
        }
        // Vizinhos do bloco
        int blockStartRow = (row / 3) * 3;
        int blockStartCol = (col / 3) * 3;
        for (int rowOffset = 0; rowOffset < 3; ++rowOffset) {
            for (int colOffset = 0; colOffset < 3; ++colOffset) {
                int blockRow = blockStartRow + rowOffset;
                int blockCol = blockStartCol + colOffset;
                if (blockRow != row && blockCol != col) {
                    cell.neighbors.push_back(blockRow * 9 + blockCol);
                }
            }
        }
    }
}

bool isValid(const vector<Cell>& sudoku, int index, int value) {
    for (auto neighbor : sudoku[index].neighbors) {
        if (sudoku[neighbor].value == value) {
            return false; // Valor já existe no vizinho
        }
    }
    return true;
}

void printSolution(const vector<Cell>& sudoku) {
    for (int i = 0; i < 81; i++) {
        cout << sudoku[i].value;
        if (i % 9 == 8) {
            cout << " ";
        }
    }
    cout << endl;
}
