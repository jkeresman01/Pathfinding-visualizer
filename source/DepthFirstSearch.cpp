#include "headers/DepthFirstSearch.h"

void dfs(Grid &grid, Node *current_node, sf::RenderWindow *window, bool &is_target_reached){

    if(current_node->getState() == gc::node::State::TARGET){
        is_target_reached = true;
        return;
    }

    window->clear(sf::Color(3, 11, 28));
    grid.draw();
    window->display();

    auto neighbour = [&current_node, &grid](int x, int y){
        return grid.getNodeAtPosition(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
    };

    if (current_node->getGridIndex().second > 0 and !neighbour(0, -1)->isVisited() 
        and !current_node->isWallVisible(gc::wall::LEFT) and neighbour(0, -1)->getState() != gc::node::State::WALL){
        neighbour(0, -1)->setPredecessor(current_node);
        neighbour(0, -1)->setVisited(true);
        dfs(grid, neighbour(0, -1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (current_node->getGridIndex().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited() 
        and !current_node->isWallVisible(gc::wall::BOTTOM) and neighbour(1, 0)->getState() != gc::node::State::WALL){ 
        neighbour(1, 0)->setPredecessor(current_node);
        neighbour(1, 0)->setVisited(true);
        dfs(grid, neighbour(1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited() 
        and !current_node->isWallVisible(gc::wall::RIGHT) and neighbour(0, 1)->getState() != gc::node::State::WALL){
        neighbour(0, 1)->setPredecessor(current_node);
        neighbour(0, 1)->setVisited(true);
        dfs(grid, neighbour(0, 1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (current_node->getGridIndex().first > 0 and !neighbour(-1, 0)->isVisited()
        and !current_node->isWallVisible(gc::wall::TOP) and neighbour(-1, 0)->getState() != gc::node::State::WALL){
        neighbour(-1, 0)->setPredecessor(current_node);
        neighbour(-1, 0)->setVisited(true);
        dfs(grid, neighbour(-1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }
}
