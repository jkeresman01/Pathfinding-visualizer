#include "headers/BreadthFirstSearch.h"
#include "headers/Global.h"

void bfs(Grid &t_grid, std::queue<Node*> &t_visitedNodes, bool &t_isTargetReached)
{

    Node *currentNode = t_visitedNodes.front();
    t_visitedNodes.pop();

    if(currentNode->getType() == gc::node::TARGET)
    {
        t_isTargetReached = true;
        return;
    }

    auto neighbour = [&currentNode, &t_grid](int x, int y)
    {
        return t_grid.getNodeAtPosition(currentNode->getGridPosition().first + x, currentNode->getGridPosition().second + y);
    };

    if (currentNode->getGridPosition().second > 0 and !neighbour(0, -1)->isVisited() 
        and !currentNode->isWallVisible(gc::wall::LEFT) and neighbour(0, -1)->getType() != gc::node::WALL)
    {
        neighbour(0, -1)->setVisited(true);
        neighbour(0, -1)->setPredecessor(currentNode);
        t_visitedNodes.push(neighbour(0, -1));
    }

    if (currentNode->getGridPosition().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited() 
        and !currentNode->isWallVisible(gc::wall::BOTTOM) and neighbour(1, 0)->getType() != gc::node::WALL)
    { 
        neighbour(1, 0)->setVisited(true);
        neighbour(1, 0)->setPredecessor(currentNode);
        t_visitedNodes.push(neighbour(1, 0));
    }

    if (currentNode->getGridPosition().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited() 
        and !currentNode->isWallVisible(gc::wall::RIGHT) and neighbour(0, 1)->getType() != gc::node::WALL)
    {
        neighbour(0, 1)->setVisited(true);
        neighbour(0, 1)->setPredecessor(currentNode);
        t_visitedNodes.push(neighbour(0, 1));
    }

    if (currentNode->getGridPosition().first > 0 and !neighbour(-1, 0)->isVisited() 
        and !currentNode->isWallVisible(gc::wall::TOP) and neighbour(-1, 0)->getType() != gc::node::WALL)
    {
        neighbour(-1, 0)->setVisited(true);
        neighbour(-1, 0)->setPredecessor(currentNode);
        t_visitedNodes.push(neighbour(-1, 0));
    }
}
