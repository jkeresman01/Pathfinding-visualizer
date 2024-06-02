#include "Grid.h"
#include "Node.h"
#include <stack>

void dfs(Grid &grid,
         Node* root,
         sf::RenderWindow* window,
         bool &is_target_reached);

void recreatePath(Node* &current_node);
