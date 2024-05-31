#include "headers/BreadthFirstSearch.h"
#include "headers/Global.h"

void bfs(Grid &grid, std::queue<Node*>& q_nodes){

    Node* current_node = q_nodes.front();
    q_nodes.pop();

    if(current_node->getState() == gc::node::State::TARGET){
        return;
    }

    auto neighbour = [&current_node, &grid](int x, int y){
        return grid.getNode(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
    };

    if (current_node->getGridIndex().second > 0 && !neighbour(0, -1)->isVisited() && !current_node->isWallVisible(gc::wall::LEFT)){
        neighbour(0, -1)->setVisited(true);
        q_nodes.push(neighbour(0, -1));
    }

     if (current_node->getGridIndex().first < gc::grid::ROWS - 1 && !neighbour(1, 0)->isVisited() && !current_node->isWallVisible(gc::wall::BOTTOM)){
        neighbour(1, 0)->setVisited(true);
        q_nodes.push(neighbour(1, 0));
    }

     if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 && !neighbour(-1, 0)->isVisited() and !current_node->isWallVisible(gc::wall::TOP)){
         neighbour(-1, 0)->setVisited(true);
         q_nodes.push(neighbour(-1, 0));
    }

    if (current_node->getGridIndex().first > 0 && !neighbour(0, 1)->isVisited() && !current_node->isWallVisible(gc::wall::RIGHT)){
        neighbour(0, 1)->setVisited(true);
        q_nodes.push(neighbour(0, 1));
    }
    
}
