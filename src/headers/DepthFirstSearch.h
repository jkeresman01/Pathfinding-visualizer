#include <stack>

#include "Grid.h"
#include "Legend.h"
#include "Node.h"

namespace pfv
{

void dfs(Grid &grid, Node *currentNode, sf::RenderWindow &window, bool &isTargetReached,
         Legend &legend);

} // namespace pfv
