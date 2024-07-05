#include <stack>

#include "Grid.h"
#include "Legend.h"
#include "Node.h"

namespace pfv
{

void dfs(Grid &t_grid,
         Node *t_currentNode,
         sf::RenderWindow &t_window,
         bool &t_isTargetReached,
         Legend &t_legend);
    
} // pfv

