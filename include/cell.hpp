#ifndef CELL_HPP
#define CELL_HPP

#include <vector>
#include "iostream"

using namespace std;

struct Cell {
    int value;
    int index;
    std::vector<int> neighbors;
};

#endif // CELL_HPP
