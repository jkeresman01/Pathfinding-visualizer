#pragma once

#include <queue>
#include <vector>

#include "Grid.h"
#include "Node.h"
#include "NodeComparator.h"

namespace pfv 
{
    
void dijkstra(Grid &t_grid,
              std::priority_queue<Node*, std::vector<Node*>, NodeComp> &t_visited_nodes,
              bool &t_isTargetReached);

} // pfv
