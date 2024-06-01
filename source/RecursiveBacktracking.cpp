#include "headers/RecursiveBacktracking.h"
#include <stack>

void drawMaze(Grid &grid, std::stack<Node*>& visited_nodes, int &visited_count){
    Node* current_node = visited_nodes.top();

    auto neighbour = [&current_node, &grid](int x, int y){
        return grid.getNode(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
    };

    std::vector<gc::wall::Position> posible_directions;
    if (current_node->getGridIndex().second > 0 && !neighbour(0, -1)->isVisited()){
        posible_directions.push_back(gc::wall::Position::LEFT);
    }

    if (current_node->getGridIndex().first < gc::grid::ROWS - 1 && !neighbour(1, 0)->isVisited()){
        posible_directions.push_back(gc::wall::Position::BOTTOM);
    }

    if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 && !neighbour(0, 1)->isVisited()){
        posible_directions.push_back(gc::wall::Position::RIGHT);
    }

    if (current_node->getGridIndex().first > 0 && !neighbour(-1, 0)->isVisited()){
        posible_directions.push_back(gc::wall::Position::TOP);
    }

    if (posible_directions.empty()){
        visited_nodes.pop();
        return;
    }

    int next_direction = posible_directions[rand() % posible_directions.size()];
    Node* next_node;

    if(next_direction == gc::wall::Position::LEFT){
        current_node->destroyWall(gc::wall::LEFT);
        next_node = neighbour(0, -1);
        next_node->destroyWall(gc::wall::RIGHT);
    }

    if(next_direction == gc::wall::Position::RIGHT){
        current_node->destroyWall(gc::wall::RIGHT);
        next_node = neighbour(0, 1);
        next_node->destroyWall(gc::wall::LEFT);
    }

    if(next_direction == gc::wall::Position::TOP){
        current_node->destroyWall(gc::wall::TOP);
        next_node = neighbour(-1, 0);
        next_node->destroyWall(gc::wall::BOTTOM);
    }

    if(next_direction == gc::wall::Position::BOTTOM){
        current_node->destroyWall(gc::wall::BOTTOM);
        next_node = neighbour(1, 0);
        next_node->destroyWall(gc::wall::TOP);
    }

    next_node->setVisited(true);
    visited_nodes.push(next_node);
    visited_count++;

}