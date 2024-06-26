#pragma once

#include <queue>

#include "Grid.h"
#include "Node.h"

void bfs(Grid &t_grid,
         std::queue<Node*> &t_visitedNodes,
         bool &t_isTargetReached);
