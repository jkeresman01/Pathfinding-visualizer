#include "headers/DepthFirstSearch.h"

void dfs(Grid &grid, Node* root, sf::RenderWindow* window, bool &is_target_reached){

    if(root->getState() == gc::node::State::TARGET){
        is_target_reached = true;
        return;
    }

    window->clear(sf::Color(3, 11, 28));
    grid.draw();
    window->display();

    auto neighbour = [&root, &grid](int x, int y){
        return grid.getNode(root->getGridIndex().first + x, root->getGridIndex().second + y);
    };

    if (root->getGridIndex().second > 0 and !neighbour(0, -1)->isVisited() and !root->isWallVisible(gc::wall::LEFT) and neighbour(0, -1)->getState() != gc::node::State::WALL){
        neighbour(0, -1)->setPredecessor(root);
        neighbour(0, -1)->setVisited(true);
        dfs(grid, neighbour(0, -1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (root->getGridIndex().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited() and !root->isWallVisible(gc::wall::BOTTOM) and neighbour(1, 0)->getState() != gc::node::State::WALL){ 
        neighbour(1, 0)->setPredecessor(root);
        neighbour(1, 0)->setVisited(true);
        dfs(grid, neighbour(1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (root->getGridIndex().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited() and !root->isWallVisible(gc::wall::RIGHT) and neighbour(0, 1)->getState() != gc::node::State::WALL){
        neighbour(0, 1)->setPredecessor(root);
        neighbour(0, 1)->setVisited(true);
        dfs(grid, neighbour(0, 1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (root->getGridIndex().first > 0 and !neighbour(-1, 0)->isVisited() and !root->isWallVisible(gc::wall::TOP) and neighbour(-1, 0)->getState() != gc::node::State::WALL){
        neighbour(-1, 0)->setPredecessor(root);
        neighbour(-1, 0)->setVisited(true);
        dfs(grid, neighbour(-1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }
}
