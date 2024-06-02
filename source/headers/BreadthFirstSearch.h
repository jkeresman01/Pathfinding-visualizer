#pragma once

#include "Grid.h"
#include "Node.h"

#include <queue>

void bfs(Grid &grid,
         std::queue<Node*>& visited_nodes,
         bool &is_target_reached);
