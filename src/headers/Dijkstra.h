#pragma once

#include <queue>
#include <vector>

#include "Grid.h"
#include "Node.h"
#include "NodeComparator.h"

namespace pfv
{

void dijkstra(Grid &grid, std::priority_queue<Node *, std::vector<Node *>, NodeComp> &visited_nodes,
              bool &isTargetReached);

} // namespace pfv
