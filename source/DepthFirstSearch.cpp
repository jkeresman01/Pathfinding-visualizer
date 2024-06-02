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

    if (root->getGridIndex().second > 0 && !neighbour(0, -1)->isVisited() and neighbour(0, -1)->getState() != gc::node::State::WALL){
        neighbour(0, -1)->setParent(root);
        neighbour(0, -1)->setVisited(true);
        dfs(grid, neighbour(0, -1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (root->getGridIndex().first < gc::grid::ROWS - 1 && !neighbour(1, 0)->isVisited() and neighbour(1, 0)->getState() != gc::node::State::WALL){
        neighbour(1, 0)->setParent(root);
        neighbour(1, 0)->setVisited(true);
        dfs(grid, neighbour(1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (root->getGridIndex().second < gc::grid::COLUMNS - 1 && !neighbour(0, 1)->isVisited() and neighbour(0, 1)->getState() != gc::node::State::WALL){
        neighbour(0, 1)->setParent(root);
        neighbour(0, 1)->setVisited(true);
        dfs(grid, neighbour(0, 1), window, is_target_reached);
        if(is_target_reached) return;
    }

    if (root->getGridIndex().first > 0 && !neighbour(-1, 0)->isVisited() and neighbour(-1, 0)->getState() != gc::node::State::WALL){
        neighbour(-1, 0)->setParent(root);
        neighbour(-1, 0)->setVisited(true);
        dfs(grid, neighbour(-1, 0), window, is_target_reached);
        if(is_target_reached) return;
    }
}
