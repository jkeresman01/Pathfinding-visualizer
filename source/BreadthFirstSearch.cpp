#include "headers/BreadthFirstSearch.h"
#include "headers/Global.h"
#include <chrono>
#include <thread>

using namespace std::chrono_literals;

void bfs(Grid &grid, std::queue<Node*>& visited_nodes, bool is_target_reached){

    Node* current_node = visited_nodes.front();
    visited_nodes.pop();

    if(current_node->getState() == gc::node::State::TARGET){
        is_target_reached = true;
        return;
    }

    auto neighbour = [&current_node, &grid](int x, int y){
        return grid.getNode(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
    };

    if (current_node->getGridIndex().second > 0 && !neighbour(0, -1)->isVisited() && !current_node->isWallVisible(gc::wall::LEFT)){
        neighbour(0, -1)->setVisited(true);
        visited_nodes.push(neighbour(0, -1));
    }

    if (current_node->getGridIndex().first < gc::grid::ROWS - 1 && !neighbour(1, 0)->isVisited() && !current_node->isWallVisible(gc::wall::BOTTOM)){
        neighbour(1, 0)->setVisited(true);
        visited_nodes.push(neighbour(1, 0));
    }

    if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 && !neighbour(0, 1)->isVisited() && !current_node->isWallVisible(gc::wall::RIGHT)){
        neighbour(0, 1)->setVisited(true);
        visited_nodes.push(neighbour(0, 1));
    }

    if (current_node->getGridIndex().first > 0 && !neighbour(-1, 0)->isVisited() and !current_node->isWallVisible(gc::wall::TOP)){
        neighbour(-1, 0)->setVisited(true);
        visited_nodes.push(neighbour(-1, 0));
    }

    std::this_thread::sleep_for(20ms);

}
