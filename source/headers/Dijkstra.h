#pragma once

#include "Grid.h"
#include "Node.h"
#include "NodeComparator.h"

#include <queue>
#include <vector>

void dijkstra(Grid &t_grid,
              std::priority_queue<Node*, std::vector<Node*>, NodeComp> &t_visited_nodes,
              bool &t_isTargetReached);
