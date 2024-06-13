#include "Grid.h"

#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

void drawMaze(Grid &t_grid,
              std::stack<Node*> &t_visitedNodes,
              uint32_t &t_numberOfVisitedNodes);
    
