#include "Grid.h"
#include "Node.h"
#include "Legend.h"

#include <stack>

void dfs(Grid &t_grid,
         Node *t_currentNode,
         sf::RenderWindow &t_window,
         bool &t_isTargetReached,
         Legend &t_legend);

