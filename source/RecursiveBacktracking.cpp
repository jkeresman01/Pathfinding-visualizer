#include "headers/RecursiveBacktracking.h"

#include <stack>

void drawMaze(Grid &t_grid, std::stack<Node*> &t_visitedNodess, int &t_numberOfVisitedNodes)
{
    Node *current_node = t_visitedNodess.top();

    auto neighbour = [&current_node, &t_grid](int x, int y)
    {
        return t_grid.getNodeAtPosition(current_node->getGridPosition().first + x, current_node->getGridPosition().second + y);
    };

    std::vector<gc::maze::Direction> posible_directions;
    if (current_node->getGridPosition().second > 0 and !neighbour(0, -1)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::LEFT);
    }

    if (current_node->getGridPosition().first < gc::grid::ROWS - 1 and !neighbour(1, 0)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::BOTTOM);
    }

    if (current_node->getGridPosition().second < gc::grid::COLUMNS - 1 and !neighbour(0, 1)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::RIGHT);
    }

    if (current_node->getGridPosition().first > 0 and !neighbour(-1, 0)->isVisited())
    {
        posible_directions.push_back(gc::maze::Direction::TOP);
    }

    if (posible_directions.empty())
    {
        t_visitedNodess.pop();
        return;
    }

    int next_direction = posible_directions[rand() % posible_directions.size()];
    Node *next_node;

    if(next_direction == gc::maze::Direction::LEFT)
    {
        current_node->destroyWall(gc::wall::LEFT);
        next_node = neighbour(0, -1);
        next_node->setVisible(true);
        next_node->destroyWall(gc::wall::RIGHT);
    }

    if(next_direction == gc::maze::Direction::RIGHT)
    {
        current_node->destroyWall(gc::wall::RIGHT);
        next_node = neighbour(0, 1);
        next_node->setVisible(true);
        next_node->destroyWall(gc::wall::LEFT);
    }

    if(next_direction == gc::maze::Direction::TOP)
    {
        current_node->destroyWall(gc::wall::TOP);
        next_node = neighbour(-1, 0);
        next_node->setVisible(true);
        next_node->destroyWall(gc::wall::BOTTOM);
    }

    if(next_direction == gc::maze::Direction::BOTTOM)
    {
        current_node->destroyWall(gc::wall::BOTTOM);
        next_node = neighbour(1, 0);
        next_node->setVisible(true);
        next_node->destroyWall(gc::wall::TOP);
    }

    next_node->setVisited(true);
    t_visitedNodess.push(next_node);
    t_numberOfVisitedNodes++;

}
