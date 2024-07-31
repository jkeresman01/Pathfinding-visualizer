#include "headers/RecursiveBacktracking.h"

namespace pfv
{

void drawMaze(Grid &grid, std::stack<Node *> &visitedNodes,
              std::uint32_t &numberOfVisitedNodes)
{
    Node *currentNode = visitedNodes.top();

    auto neighbour = [&currentNode, &grid](uint32_t x, uint32_t y) {
        return grid.getNodeAtPosition(
            currentNode->getGridPosition().first + x,
            currentNode->getGridPosition().second + y);
    };

    std::vector<maze::Direction> possibleDirections;
    if (currentNode->getGridPosition().second > 0 and
        !neighbour(0, -1)->isVisited())
    {
        possibleDirections.push_back(maze::Direction::LEFT);
    }

    if (currentNode->getGridPosition().first < grid::ROWS - 1 and
        !neighbour(1, 0)->isVisited())
    {
        possibleDirections.push_back(maze::Direction::BOTTOM);
    }

    if (currentNode->getGridPosition().second < grid::COLUMNS - 1 and
        !neighbour(0, 1)->isVisited())
    {
        possibleDirections.push_back(maze::Direction::RIGHT);
    }

    if (currentNode->getGridPosition().first > 0 and
        !neighbour(-1, 0)->isVisited())
    {
        possibleDirections.push_back(maze::Direction::TOP);
    }

    if (possibleDirections.empty())
    {
        visitedNodes.pop();
        return;
    }

    maze::Direction nextDirection =
        possibleDirections[rand() % possibleDirections.size()];
    Node *nextNode;

    if (nextDirection == maze::Direction::LEFT)
    {
        currentNode->destroyWall(wall::LEFT);
        nextNode = neighbour(0, -1);
        nextNode->setVisible(true);
        nextNode->destroyWall(wall::RIGHT);
    }

    if (nextDirection == maze::Direction::RIGHT)
    {
        currentNode->destroyWall(wall::RIGHT);
        nextNode = neighbour(0, 1);
        nextNode->setVisible(true);
        nextNode->destroyWall(wall::LEFT);
    }

    if (nextDirection == maze::Direction::TOP)
    {
        currentNode->destroyWall(wall::TOP);
        nextNode = neighbour(-1, 0);
        nextNode->setVisible(true);
        nextNode->destroyWall(wall::BOTTOM);
    }

    if (nextDirection == maze::Direction::BOTTOM)
    {
        currentNode->destroyWall(wall::BOTTOM);
        nextNode = neighbour(1, 0);
        nextNode->setVisible(true);
        nextNode->destroyWall(wall::TOP);
    }

    nextNode->setVisited(true);
    visitedNodes.push(nextNode);
    numberOfVisitedNodes++;
}

} // namespace pfv
