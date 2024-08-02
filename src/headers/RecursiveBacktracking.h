#include "Grid.h"

#include <stack>

#include <SFML/Graphics/RenderWindow.hpp>

namespace pfv
{

void drawMaze(Grid &grid, std::stack<Node *> &visitedNodes, uint32_t &numberOfVisitedNodes);

} // namespace pfv
