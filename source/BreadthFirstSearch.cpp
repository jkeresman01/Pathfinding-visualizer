#include "headers/BreadthFirstSearch.h"
#include "headers/Global.h"
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

void bfs(Grid &grid, std::queue<Node*>& visited_nodes, bool &is_target_reached){

    Node* current_node = visited_nodes.front();
    visited_nodes.pop();

    if(current_node->getState() == gc::node::State::TARGET){
        is_target_reached = true;
        return;
    }

    auto neighbour = [&current_node, &grid](int x, int y){
        return grid.getNode(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
    };

    if (current_node->getGridIndex().second > 0 and !neighbour(0, -1)->isVisited() and !current_node->isWallVisible(gc::wall::LEFT) and neighbour(0, -1)->getState() != gc::node::State::WALL){
        neighbour(0, -1)->setVisited(true);
        neighbour(0, -1)->setParent(current_node);
        visited_nodes.push(neighbour(0, -1));
    }

    if (current_node->getGridIndex().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited() and !current_node->isWallVisible(gc::wall::BOTTOM) and neighbour(1, 0)->getState() != gc::node::State::WALL){ 
        neighbour(1, 0)->setVisited(true);
        neighbour(1, 0)->setParent(current_node);
        visited_nodes.push(neighbour(1, 0));
    }

    if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited() and !current_node->isWallVisible(gc::wall::RIGHT) and neighbour(0, 1)->getState() != gc::node::State::WALL){
        neighbour(0, 1)->setVisited(true);
        neighbour(0, 1)->setParent(current_node);
        visited_nodes.push(neighbour(0, 1));
    }

    if (current_node->getGridIndex().first > 0 and !neighbour(-1, 0)->isVisited() and !current_node->isWallVisible(gc::wall::TOP) and neighbour(-1, 0)->getState() != gc::node::State::WALL){
        neighbour(-1, 0)->setVisited(true);
        neighbour(-1, 0)->setParent(current_node);
        visited_nodes.push(neighbour(-1, 0));
    }

}

void recreatePath(Node* &current_node){
    current_node->setState(gc::node::PATH);
    current_node = current_node->getParent();
    std::this_thread::sleep_for(100ms);
}
