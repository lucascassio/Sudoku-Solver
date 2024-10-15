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

- `<algoritmo>`: Escolha o algoritmo de busca para resolver o Sudoku:
  - B: BFS (Breadth-First Search)
  - I: IDS (Iterative Deepening Search)
  - U: UCS (Uniform Cost Search)
  - A: A* (A-Star Search)
  - G: Greedy Search

- `<tabuleiro>`: Forneça o tabuleiro do Sudoku como uma string de números, onde cada número representa uma célula do tabuleiro. Use números 0 para representar células vazias. Certifique-se de colocar o tabuleiro entre aspas duplas e cada bloco do tabuleiro entre um espaço.

## Exemplo de uso

Para resolver um Sudoku usando o algoritmo A*:

  ./bin/TP1 A "800700000 003600005 070090200 050007090 000045700 000100034 001000068 008500010 090000400"

Isso imprimirá a solução do Sudoku, juntamente com o número de estados explorados e o tempo de execução em milissegundos.
