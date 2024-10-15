# Sudoku Solver

Este projeto implementa diversos algoritmos de busca para resolver o quebra-cabeça Sudoku, incluindo busca cega e informada. O objetivo é comparar o desempenho entre os algoritmos utilizando métricas como o número de estados expandidos e o tempo de execução.

## Algoritmos Implementados

- **Busca sem informação (uninformed search):**
  - Breadth-First Search (BFS) - (B)
  - Iterative Deepening Search (DFS) - (I)
  - Uniform-Cost Search - (U)

- **Busca com informação (informed search):**
  - A* Search (A)
  - Greedy Best-First Search (G)

## Heurísticas

Para os algoritmos de busca informada (A* e Greedy Best-First), utilizamos diferentes heurísticas:

- **A\***: Utiliza a soma da quantidade de células vazias + número de conflitos em subgrids.
- **Greedy Best-First**: Utiliza apenas a quantidade de células vazias como heurística.

## Como Compilar e Executar

Para compilar o programa, você pode usar o seguinte comando no terminal:

`make`

Para Executar o programa, basta usar o seguinte comando no terminal:

`./bin/TP1 <algoritmo> <tabuleiro>`

Exemplo: 

`A 107006450 025340008 060001070 053000029 610009800 000602007 001093200 008000000 040078591`



