#include "headers/Dijkstra.h"

namespace pfv
{

void dijkstra(Grid &t_grid,
             std::priority_queue<Node*, std::vector<Node*>, NodeComp> &t_visitedNodes,
             bool &t_isTargetReached)
{

    Node *currentNode = t_visitedNodes.top();

    if(!t_visitedNodes.empty())
    {
        t_visitedNodes.pop();
    }

    if(currentNode->getType() == node::TARGET)
    {
        t_isTargetReached = true;
        return;
    }

    auto neighbour = [&currentNode, &t_grid](uint32_t x, uint32_t y)
    {
        return t_grid.getNodeAtPosition(currentNode->getGridPosition().first  + x,
                                        currentNode->getGridPosition().second + y);
    };

    if (currentNode->getGridPosition().second > 0 and !neighbour(0, -1)->isVisited() and 
       !currentNode->isWallVisible(wall::LEFT) and neighbour(0, -1)->getType() != node::WALL)
    {
        neighbour(0, -1)->setVisited(true);
        neighbour(0, -1)->setPredecessor(currentNode);
        neighbour(0, -1)->setDistance(currentNode->getDistance() + 1);
        t_visitedNodes.push(neighbour(0, -1));
    }

    if (currentNode->getGridPosition().first < grid::ROWS - 1 and !neighbour(1, 0)->isVisited() and 
       !currentNode->isWallVisible(wall::BOTTOM) and neighbour(1, 0)->getType() != node::WALL)
    { 
        neighbour(1, 0)->setVisited(true);
        neighbour(1, 0)->setPredecessor(currentNode);
        neighbour(1, 0)->setDistance(currentNode->getDistance() + 1);
        t_visitedNodes.push(neighbour(1, 0));
    }

    if (currentNode->getGridPosition().second < grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited() and 
       !currentNode->isWallVisible(wall::RIGHT) and neighbour(0, 1)->getType() != node::WALL)
    {
        neighbour(0, 1)->setVisited(true);
        neighbour(0, 1)->setPredecessor(currentNode);
        neighbour(0, 1)->setDistance(currentNode->getDistance() + 1);
        t_visitedNodes.push(neighbour(0, 1));
    }

    if (currentNode->getGridPosition().first > 0 and !neighbour(-1, 0)->isVisited() and 
       !currentNode->isWallVisible(wall::TOP) and neighbour(-1, 0)->getType() != node::WALL)
    {
        neighbour(-1, 0)->setVisited(true);
        neighbour(-1, 0)->setPredecessor(currentNode);
        neighbour(-1, 0)->setDistance(currentNode->getDistance() + 1);
        t_visitedNodes.push(neighbour(-1, 0));
    }
}
    
} // pfv

