# Pathfinding-visualizer #
..... Not baked yet.

Hi I wrote visualization tool for path finding algorithms(BFS, DFS, Dijkstra, A*). I am usingn them for maze solving.

## Maze ##
A maze is a type of puzzle involving a collection of paths, usually where a player has to find a route from start to finish.
There is a huge variety of algorithms based on graph theory for generating mazes (Randomized DFS, Iterative randomized Kruskal's algorithm, Iterative randomized Prim's algorithm...)
For this purpose I'am using variation of Randomized DFS (Recursive Backtracking).

Algorithm:
* Choose the initial cell, mark it as visited and push it to the stack
* While the stack is not empty
  * Pop a cell from the stack and make it a current cell
  * If the current cell has any neighbours which have not been visited
    * Push the current cell to the stack
    * Choose one of the unvisited neighbours
    * Destroy the wall between the current cell and the chosen cell
    * Mark the chosen cell as visited and push it to the stack
   
