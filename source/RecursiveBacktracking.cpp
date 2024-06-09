#include "headers/RecursiveBacktracking.h"

#include <stack>

#include <SFML/Audio.hpp>
#include <SFML/Audio/Sound.hpp>

void drawMaze(Grid &t_grid, std::stack<Node*> &t_visitedNodes, int &t_numberOfVisitedNodes)
{
    Node *currentNode = t_visitedNodes.top();

    auto neighbour = [&currentNode, &t_grid](int x, int y)
    {
        return t_grid.getNodeAtPosition(currentNode->getGridPosition().first + x, currentNode->getGridPosition().second + y);
    };

    std::vector<gc::maze::Direction> posible_directions;
    if (currentNode->getGridPosition().second > 0 and !neighbour(0, -1)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::LEFT);
    }

    if (currentNode->getGridPosition().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::BOTTOM);
    }

    if (currentNode->getGridPosition().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::RIGHT);
    }

    if (currentNode->getGridPosition().first > 0 and !neighbour(-1, 0)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::TOP);
    }

    if (posible_directions.empty())
    {
        t_visitedNodes.pop();
        return;
    }

    int nextDirection = posible_directions[rand() % posible_directions.size()];
    Node *nextNode;

    if(nextDirection == gc::maze::Direction::LEFT)
    {
        currentNode->destroyWall(gc::wall::LEFT);
        nextNode = neighbour(0, -1);
        nextNode->setVisible(true);
        nextNode->destroyWall(gc::wall::RIGHT);
    }

    if(nextDirection == gc::maze::Direction::RIGHT)
    {
        currentNode->destroyWall(gc::wall::RIGHT);
        nextNode = neighbour(0, 1);
        nextNode->setVisible(true);
        nextNode->destroyWall(gc::wall::LEFT);
    }

    if(nextDirection == gc::maze::Direction::TOP)
    {
        currentNode->destroyWall(gc::wall::TOP);
        nextNode = neighbour(-1, 0);
        nextNode->setVisible(true);
        nextNode->destroyWall(gc::wall::BOTTOM);
    }

    if(nextDirection == gc::maze::Direction::BOTTOM)
    {
        currentNode->destroyWall(gc::wall::BOTTOM);
        nextNode = neighbour(1, 0);
        nextNode->setVisible(true);
        nextNode->destroyWall(gc::wall::TOP);
    }

    nextNode->setVisited(true);
    t_visitedNodes.push(nextNode);
    t_numberOfVisitedNodes++;

}
