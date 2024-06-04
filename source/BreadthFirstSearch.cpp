#include "headers/BreadthFirstSearch.h"
#include "headers/Global.h"

void bfs(Grid &t_grid, std::queue<Node*> &t_visitedNodes, bool &t_isTargetReached)
{

    Node *current_node = t_visitedNodes.front();
    t_visitedNodes.pop();

    if(current_node->getState() == gc::node::State::TARGET)
    {
        t_isTargetReached = true;
        return;
    }

    auto neighbour = [&current_node, &t_grid](int x, int y)
    {
        return t_grid.getNodeAtPosition(current_node->getGridPosition().first + x, current_node->getGridPosition().second + y);
    };

    if (current_node->getGridPosition().second > 0 
        and !neighbour(0, -1)->isVisited() 
        and !current_node->isWallVisible(gc::wall::LEFT) 
        and neighbour(0, -1)->getState() != gc::node::State::WALL)
    {
        neighbour(0, -1)->setVisited(true);
        neighbour(0, -1)->setPredecessor(current_node);
        t_visitedNodes.push(neighbour(0, -1));
    }

    if (current_node->getGridPosition().first < gc::grid::ROWS - 1
        and !neighbour(1, 0)->isVisited() 
        and !current_node->isWallVisible(gc::wall::BOTTOM) 
        and neighbour(1, 0)->getState() != gc::node::State::WALL)
    { 
        neighbour(1, 0)->setVisited(true);
        neighbour(1, 0)->setPredecessor(current_node);
        t_visitedNodes.push(neighbour(1, 0));
    }

    if (current_node->getGridPosition().second < gc::grid::COLUMNS - 1
        and !neighbour(0, 1)->isVisited() 
        and !current_node->isWallVisible(gc::wall::RIGHT) 
        and neighbour(0, 1)->getState() != gc::node::State::WALL)
    {
        neighbour(0, 1)->setVisited(true);
        neighbour(0, 1)->setPredecessor(current_node);
        t_visitedNodes.push(neighbour(0, 1));
    }

    if (current_node->getGridPosition().first > 0 
        and !neighbour(-1, 0)->isVisited() 
        and !current_node->isWallVisible(gc::wall::TOP) 
        and neighbour(-1, 0)->getState() != gc::node::State::WALL)
    {
        neighbour(-1, 0)->setVisited(true);
        neighbour(-1, 0)->setPredecessor(current_node);
        t_visitedNodes.push(neighbour(-1, 0));
    }

}
