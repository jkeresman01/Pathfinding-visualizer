#pragma once

#include "Grid.h"
#include "Node.h"

#include <queue>

void bfs(Grid &t_grid,
         std::queue<Node*> &t_visitedNodes,
         bool &t_isTargetReached);
