#include "Grid.h"

#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

void drawMaze(Grid &t_grid,
              std::stack<Node*> &t_visitedNodes,
              int &t_numberOfVisitedNodes);
    
