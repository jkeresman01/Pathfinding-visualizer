#pragma once

#include <queue>

#include "Grid.h"
#include "Node.h"

namespace pfv
{

void bfs(Grid &grid, std::queue<Node *> &visitedNodes, bool &isTargetReached);

} // namespace pfv
