#pragma once

#include <queue>

#include "Grid.h"
#include "Node.h"

namespace pfv
{

void bfs(Grid &t_grid, std::queue<Node *> &t_visitedNodes,
         bool &t_isTargetReached);

} // namespace pfv
