#include <iostream>
#include <vector>
#include <sstream>
#include <chrono>
#include "../include/sudokuSolver.hpp"
#include "../include/sudokuUtils.hpp"

using namespace std;
using namespace chrono;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: " << argv[0] << " <algoritmo> <tabuleiro>" << endl;
        return 1;
    }

    char algorithm = argv[1][0];
    string board = argv[2];

    vector<Cell> sudoku = createSudoku(board);
    assignNeighbors(sudoku);

    vector<Cell> aux = sudoku;

    if (algorithm == 'b' || algorithm == 'B') {
        int bfsStates = 0;
        auto start = high_resolution_clock::now();
        solveSudokuBFS(aux, bfsStates);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << bfsStates << " " << duration.count() << endl;
        printSolution(aux);
    } else if (algorithm == 'i' || algorithm == 'I') {
        int idsStates = 0;
        auto start = high_resolution_clock::now();
        aux = sudoku;
        if (solveSudokuIDS(aux, idsStates)) {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << idsStates << " " << duration.count() << endl;
            printSolution(aux);
        }
    } else if (algorithm == 'u' || algorithm == 'U') {
        aux = sudoku;
        int ucsStates = 0;
        auto start = high_resolution_clock::now();
        if (solveSudokuUCS(aux, ucsStates)) {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << ucsStates << " " << duration.count() << endl;
            printSolution(aux);
        }
    } else if(algorithm == 'a' || algorithm == 'A') {
        aux = sudoku; 
        int aStates = 0;
        auto start = high_resolution_clock::now();
        if (solveSudokuAStar(aux, aStates)) {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << aStates << " " << duration.count() << endl;
            printSolution(aux);
        }
    } else if(algorithm == 'g' || algorithm == 'G') {
        aux = sudoku; 
        int gStates = 0;
        auto start = high_resolution_clock::now();
        if (solveSudokuGreedy(aux, gStates)) {
            auto stop = high_resolution_clock::now();
            auto duration = duration_cast<milliseconds>(stop - start);
            cout << gStates << " " << duration.count() << endl;
            printSolution(aux);
        }
    } 
    else {
        cout << "Algoritmo inválido. Por favor, escolha 'b' para BFS, 'd' para DFS, 'u' para UCS, 'A' para A* ou 'G' para Greedy" << endl;
        return 1;
    }

    return 0;
}
