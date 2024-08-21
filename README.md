# Pathfinding Visualizer #

This tool is designed to visualize various pathfinding algorithms including BFS, DFS, and Dijkstra's algorithm. 

It's built using the SFML library. You can learn more about SFML here: [SFML Documentation](https://www.sfml-dev.org/documentation/2.6.1/).

Upon starting the application, you'll be presented with a menu where you can choose between the following modes:
- Maze Solving
- Wall Building

## Available Options ##

| Key Combination            | Description                                      |
|----------------------------|--------------------------------------------------|
| `<R>`                      | Reset the grid                                   |
| `<D>`                      | Start Depth First Search algorithm               |
| `<B>`                      | Start Breadth First Search algorithm             |
| `<J>`                      | Start Dijkstra's algorithm                       |
| `Space + Left Mouse Click` | Position the start node                          |
| `Space + Right Mouse Click`| Position the end node                            |
| `Enter + Left Mouse Click` | Put walls around the grid                        |
| `ESC`                      | Return to the start menu                         |


## Maze Solving ##
A maze is a puzzle that involves navigating through a network of paths to find a route from start to finish. There are numerous algorithms for generating mazes based on graph theory, such as Randomized DFS, Iterative Randomized Kruskal's Algorithm, and Iterative Randomized Prim's Algorithm.

For this tool, a variation of Randomized DFS (Recursive Backtracking) is used. Once your maze is generated, you can start testing out the pathfinding algorithms.

![maze](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/e251d24c-4272-4bcb-b9e9-289fa0650ac9)

## Wall Building ##
In this mode, you can build walls and observe how different algorithms navigate around them to find the shortest path.

![cpp](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/95befe9d-0665-430b-baf5-eae45ccf43cb)

### Example with No Walls ###
![bfs](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/607efa2a-ca2d-4521-9142-38d5c21ca8cf)

### Example with Random Walls ###
![wall](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/3859c0ab-3664-4077-bc69-f9b7bd8adbb6)


## Starting the application ##

If the version of SFML that you want to install is available in the official repository, then install it using your package manager.

For example, on Debian, Ubuntu you would do:
```
sudo apt-get install libsfml-dev
```

Now you will need to compile the program:
```
g++ -c *cpp
```

In case you installed SFML to a non-standard path, you'll need to tell the compiler where to find the SFML headers:
```
g++ -std=c++17 -c *cpp -I<sfml-install-path>/include
```

You must then link the compiled file to the SFML libraries in order to get the final executable.
```
g++ *.o -o find-path -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```
You can now execute the compiled program:
```
./find-path
```

## Useful Resources ##

| Resource                    | Link                                                                                      |
|-----------------------------|-------------------------------------------------------------------------------------------|
| Maze Generation Algorithms  | [Wikipedia: Maze Generation Algorithm](https://en.wikipedia.org/wiki/Maze_generation_algorithm) |
| Dijkstra's Algorithm        | [Wikipedia: Dijkstra's Algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)        |


