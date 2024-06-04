#include "headers/DepthFirstSearch.h"

void dfs(Grid &t_grid, Node *t_currentNode, sf::RenderWindow *t_window, bool &t_isTargetReached){

    if(t_currentNode->getState() == gc::node::State::TARGET)
    {
        t_isTargetReached = true;
        return;
    }

    t_window->clear(sf::Color(3, 11, 28));
    t_grid.draw();
    t_window->display();

    auto neighbour = [&t_currentNode, &t_grid](int x, int y)
    {
        return t_grid.getNodeAtPosition(t_currentNode->getGridPosition().first + x, t_currentNode->getGridPosition().second + y);
    };

    if (t_currentNode->getGridPosition().second > 0
        and !neighbour(0, -1)->isVisited() 
        and !t_currentNode->isWallVisible(gc::wall::LEFT) 
        and neighbour(0, -1)->getState() != gc::node::State::WALL)
    {
        neighbour(0, -1)->setPredecessor(t_currentNode);
        neighbour(0, -1)->setVisited(true);
        dfs(t_grid, neighbour(0, -1), t_window, t_isTargetReached);
        if(t_isTargetReached){ return; };
    }

    if (t_currentNode->getGridPosition().first < gc::grid::ROWS - 1
        and !neighbour(1, 0)->isVisited() 
        and !t_currentNode->isWallVisible(gc::wall::BOTTOM) 
        and neighbour(1, 0)->getState() != gc::node::State::WALL)
    { 
        neighbour(1, 0)->setPredecessor(t_currentNode);
        neighbour(1, 0)->setVisited(true);
        dfs(t_grid, neighbour(1, 0), t_window, t_isTargetReached);
        if(t_isTargetReached) { return; };
    }

    if (t_currentNode->getGridPosition().second < gc::grid::COLUMNS - 1
        and !neighbour(0, 1)->isVisited() 
        and !t_currentNode->isWallVisible(gc::wall::RIGHT) 
        and neighbour(0, 1)->getState() != gc::node::State::WALL)
    {
        neighbour(0, 1)->setPredecessor(t_currentNode);
        neighbour(0, 1)->setVisited(true);
        dfs(t_grid, neighbour(0, 1), t_window, t_isTargetReached);
        if(t_isTargetReached) { return; };
    }

    if (t_currentNode->getGridPosition().first > 0
        and !neighbour(-1, 0)->isVisited()
        and !t_currentNode->isWallVisible(gc::wall::TOP) 
        and neighbour(-1, 0)->getState() != gc::node::State::WALL)
    {
        neighbour(-1, 0)->setPredecessor(t_currentNode);
        neighbour(-1, 0)->setVisited(true);
        dfs(t_grid, neighbour(-1, 0), t_window, t_isTargetReached);
        if(t_isTargetReached) { return; };
    }

}
