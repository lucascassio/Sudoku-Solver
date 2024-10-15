CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/heuristics.o $(OBJ)/sudokuUtils.o $(OBJ)/sudokuSolver.o $(OBJ)/main.o
HDRS = $(INC)/heuristics.hpp $(INC)/cell.hpp $(INC)/sudokuSolver.hpp $(INC)/sudokuUtils.hpp
CFLAGS = -I$(INC) -c -std=c++17

EXE = $(BIN)/TP1

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/heuristics.o: $(HDRS) $(SRC)/heuristics.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/heuristics.o $(SRC)/heuristics.cpp

$(OBJ)/sudokuSolver.o: $(HDRS) $(SRC)/sudokuSolver.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sudokuSolver.o $(SRC)/sudokuSolver.cpp

$(OBJ)/sudokuUtils.o: $(HDRS) $(SRC)/sudokuUtils.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/sudokuUtils.o $(SRC)/sudokuUtils.cpp

clean:
	rm -f $(EXE) $(OBJS) ./bin/gmon.out ./bin/TP1