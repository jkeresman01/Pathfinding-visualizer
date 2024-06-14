# Pathfinding-visualizer #

Hi I wrote visualization tool for path finding algorithms (BFS, DFS, Dijkstra).

Tool is build using SFML: https://www.sfml-dev.org/documentation/2.6.1/ 

Upon starting the application you will be presented with the menu where you caN choose between one of these modes:
- Maze solving
- Wall building
  
***

AVAILABLE OPTIONS:

`<r>` - Will reset the grid so that you can have fresh start

`<d>` - Will start Depth first search algorithm

`<b>` -  Will start Breadth first search algorithm

`<j>`- will start Dijkstra's algorithm



`<Space + left click>`     - position the start node

`<Space + right click>`    - position the start node

`<Enter + left click>`     - put walls around the grid



.... Presing ESC at any time will move you back to the start menu.


***
## Maze solving ##
A maze is a type of puzzle involving a collection of paths, usually where a player has to find a route from start to finish.
There is a huge variety of algorithms based on graph theory for generating mazes (Randomized DFS, Iterative randomized Kruskal's algorithm, Iterative randomized Prim's algorithm...)
For this purpose I'am using variation of Randomized DFS (Recursive Backtracking).


![maze](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/e251d24c-4272-4bcb-b9e9-289fa0650ac9)

## Wall building ##

In this mode you can build walls and see how algorithms go around them in order to find the shortest path.

![cpp](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/95befe9d-0665-430b-baf5-eae45ccf43cb)


Example with no walls:

![bfs](https://github.com/jkeresman01/Pathfinding-visualizer/assets/165517653/607efa2a-ca2d-4521-9142-38d5c21ca8cf)


Example with some random walls:

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
g++ -c *cpp -I<sfml-install-path>/include
```

You must then link the compiled file to the SFML libraries in order to get the final executable.
```
g++ *.o -o find-path -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```
You can now execute the compiled program:
```
./find-path
```
## Usefull resources ##


