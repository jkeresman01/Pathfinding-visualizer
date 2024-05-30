#include "Grid.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <stack>

void drawMaze(Grid &grid, std::stack<Node*>& visited_nodes, int &visited_count);
    
