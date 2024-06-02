#include "headers/DepthFirstSearch.h"

void dfs(Grid &grid, Node *node, sf::RenderWindow *window, bool &is_target_reached){

    if(node->getState() == gc::node::State::TARGET){
        is_target_reached = true;
        return;
    }

    window->clear(sf::Color(3, 11, 28));
    grid.draw();
    window->display();

    auto neighbour = [&node, &grid](int x, int y){
        return grid.getNodeAtPosition(node->getGridIndex().first + x, node->getGridIndex().second + y);
    };

    if (node->getGridIndex().second > 0 and !neighbour(0, -1)->isVisited() and !node->isWallVisible(gc::wall::LEFT) and neighbour(0, -1)->getState() != gc::node::State::WALL){
        neighbour(0, -1)->setPredecessor(node);
        neighbour(0, -1)->setVisited(true);
        dfs(grid, neighbour(0, -1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (node->getGridIndex().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited() and !node->isWallVisible(gc::wall::BOTTOM) and neighbour(1, 0)->getState() != gc::node::State::WALL){ 
        neighbour(1, 0)->setPredecessor(node);
        neighbour(1, 0)->setVisited(true);
        dfs(grid, neighbour(1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (node->getGridIndex().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited() and !node->isWallVisible(gc::wall::RIGHT) and neighbour(0, 1)->getState() != gc::node::State::WALL){
        neighbour(0, 1)->setPredecessor(node);
        neighbour(0, 1)->setVisited(true);
        dfs(grid, neighbour(0, 1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (node->getGridIndex().first > 0 and !neighbour(-1, 0)->isVisited() and !node->isWallVisible(gc::wall::TOP) and neighbour(-1, 0)->getState() != gc::node::State::WALL){
        neighbour(-1, 0)->setPredecessor(node);
        neighbour(-1, 0)->setVisited(true);
        dfs(grid, neighbour(-1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }
}
