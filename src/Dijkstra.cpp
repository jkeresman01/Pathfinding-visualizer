#include "headers/Dijkstra.h"

namespace pfv
{

void dijkstra(Grid &grid, std::priority_queue<Node *, std::vector<Node *>, NodeComp> &visitedNodes,
              bool &isTargetReached)
{

    Node *currentNode = visitedNodes.top();

    if (!visitedNodes.empty())
    {
        visitedNodes.pop();
    }

    if (currentNode->getType() == node::TARGET)
    {
        isTargetReached = true;
        return;
    }

    auto neighbour = [&currentNode, &grid](uint32_t x, uint32_t y) {
        return grid.getNodeAtPosition(currentNode->getGridPosition().first + x,
                                      currentNode->getGridPosition().second + y);
    };

    if (currentNode->getGridPosition().second > 0 and !neighbour(0, -1)->isVisited() and
        !currentNode->isWallVisible(wall::LEFT) and neighbour(0, -1)->getType() != node::Type::WALL)
    {
        neighbour(0, -1)->setVisited(true);
        neighbour(0, -1)->setPredecessor(currentNode);
        neighbour(0, -1)->setDistance(currentNode->getDistance() + 1);
        visitedNodes.push(neighbour(0, -1));
    }

    if (currentNode->getGridPosition().first < grid::ROWS - 1 and !neighbour(1, 0)->isVisited() and
        !currentNode->isWallVisible(wall::BOTTOM) and
        neighbour(1, 0)->getType() != node::Type::WALL)
    {
        neighbour(1, 0)->setVisited(true);
        neighbour(1, 0)->setPredecessor(currentNode);
        neighbour(1, 0)->setDistance(currentNode->getDistance() + 1);
        visitedNodes.push(neighbour(1, 0));
    }

    if (currentNode->getGridPosition().second < grid::COLUMNS - 1 and
        !neighbour(0, 1)->isVisited() and !currentNode->isWallVisible(wall::RIGHT) and
        neighbour(0, 1)->getType() != node::Type::WALL)
    {
        neighbour(0, 1)->setVisited(true);
        neighbour(0, 1)->setPredecessor(currentNode);
        neighbour(0, 1)->setDistance(currentNode->getDistance() + 1);
        visitedNodes.push(neighbour(0, 1));
    }

    if (currentNode->getGridPosition().first > 0 and !neighbour(-1, 0)->isVisited() and
        !currentNode->isWallVisible(wall::TOP) and neighbour(-1, 0)->getType() != node::Type::WALL)
    {
        neighbour(-1, 0)->setVisited(true);
        neighbour(-1, 0)->setPredecessor(currentNode);
        neighbour(-1, 0)->setDistance(currentNode->getDistance() + 1);
        visitedNodes.push(neighbour(-1, 0));
    }
}

} // namespace pfv
