#include "headers/RecursiveBacktracking.h"
#include <stack>

void drawMaze(Grid &grid, std::stack<Node*>& visited_nodes, int &visited_count){
    Node* current_node = visited_nodes.top();

    auto neighbour = [&current_node, &grid](int x, int y){
        return grid.getNode(current_node->getGridIndex().first + x, current_node->getGridIndex().second + y);
    };

    std::vector<Node*> neighbours;
    if (current_node->getGridIndex().second > 0 && !neighbour(0, -1)->isVisited()){
        neighbours.push_back(neighbour(0, -1));
    }

    if (current_node->getGridIndex().first < gc::grid::ROWS - 1 && !neighbour(1, 0)->isVisited()){
        neighbours.push_back(neighbour(1, 0));
    }

    if (current_node->getGridIndex().second < gc::grid::COLUMNS - 1 && !neighbour(0, 1)->isVisited()){
        neighbours.push_back(neighbour(0, 1));
    }

    if (current_node->getGridIndex().first > 0 && !neighbour(-1, 0)->isVisited()){
        neighbours.push_back(neighbour(-1, 0));
    }


    if(neighbours.empty()){
        visited_nodes.pop();
    }else {
        Node* next_node = neighbours[rand() % neighbours.size()];
        next_node->setState(gc::node::State::VISITED);
        visited_nodes.push(next_node);
        visited_count++;
    }

}
