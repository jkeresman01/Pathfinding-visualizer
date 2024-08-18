#include "headers/DepthFirstSearch.h"

namespace pfv
{

void dfs(Grid &grid, Node *currentNode, sf::RenderWindow &window, bool &isTargetReached,
         Legend &legend)
{
    if (currentNode->getType() == node::Type::TARGET)
    {
        isTargetReached = true;
        return;
    }

    window.clear(sf::Color(3, 11, 28));
    legend.render(window);
    grid.render(window);
    window.display();

    auto neighbour = [&currentNode, &grid](uint32_t x, uint32_t y) {
        return grid.getNodeAtPosition(currentNode->getGridPosition().first + x,
                                      currentNode->getGridPosition().second + y);
    };

    if (currentNode->getGridPosition().second > 0 and !neighbour(0, -1)->isVisited() and
        !currentNode->isWallVisible(wall::LEFT) and neighbour(0, -1)->getType() != node::Type::WALL)
    {
        neighbour(0, -1)->setPredecessor(currentNode);
        neighbour(0, -1)->setVisited(true);

        dfs(grid, neighbour(0, -1), window, isTargetReached, legend);

        if (isTargetReached)
        {
            return;
        }
    }

    if (currentNode->getGridPosition().first < grid::ROWS - 1 and !neighbour(1, 0)->isVisited() and
        !currentNode->isWallVisible(wall::BOTTOM) and
        neighbour(1, 0)->getType() != node::Type::WALL)
    {
        neighbour(1, 0)->setPredecessor(currentNode);
        neighbour(1, 0)->setVisited(true);

        dfs(grid, neighbour(1, 0), window, isTargetReached, legend);

        if (isTargetReached)
        {
            return;
        }
    }

    if (currentNode->getGridPosition().second < grid::COLUMNS - 1 and
        !neighbour(0, 1)->isVisited() and !currentNode->isWallVisible(wall::RIGHT) and
        neighbour(0, 1)->getType() != node::Type::WALL)
    {
        neighbour(0, 1)->setPredecessor(currentNode);
        neighbour(0, 1)->setVisited(true);

        dfs(grid, neighbour(0, 1), window, isTargetReached, legend);

        if (isTargetReached)
        {
            return;
        }
    }

    if (currentNode->getGridPosition().first > 0 and !neighbour(-1, 0)->isVisited() and
        !currentNode->isWallVisible(wall::TOP) and neighbour(-1, 0)->getType() != node::Type::WALL)
    {
        neighbour(-1, 0)->setPredecessor(currentNode);
        neighbour(-1, 0)->setVisited(true);

        dfs(grid, neighbour(-1, 0), window, isTargetReached, legend);

        if (isTargetReached)
        {
            return;
        }
    }
}

} // namespace pfv
