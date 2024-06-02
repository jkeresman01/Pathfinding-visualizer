#include "headers/Grid.h"

#include <algorithm>

#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>

Grid::Grid(sf::RenderWindow *t_window){
    this->m_Window = t_window;
    this->m_Grid = new Node[gc::grid::ROWS * gc::grid::COLUMNS];
    initilazeNodes();
}

void Grid::initilazeNodes(){
    for(int i = 0; i < gc::grid::ROWS; ++i){
        for(int j = 0; j < gc::grid::COLUMNS; ++j){
            m_Grid[gc::grid::COLUMNS * i + j].setWindow(m_Window);
            m_Grid[gc::grid::COLUMNS * i + j].setGridIndex(i, j);
            m_Grid[gc::grid::COLUMNS * i + j].setPosition(
                    gc::node::START_POSITION_X + (j * gc::node::WIDTH), 
                    gc::node::START_POSITION_Y + (i * gc::node::HEIGHT));
        }
    } 
}

void Grid::restoreVisitedNodes(){
    std::for_each(m_Grid, m_Grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){ n.setVisited(false);});
}

Grid::~Grid(){
    delete[] m_Grid;
}

void Grid::draw(){
    std::for_each(m_Grid, m_Grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){if(n.isVisible()) n.draw();});
}

void Grid::removeWalls(){
    std::for_each(m_Grid, m_Grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n) {
            n.destroyAllWalls();
            n.setOutline();
    });
}

Node* Grid::getNodeAtPosition(int t_position_x, int t_position_y){
    return &m_Grid[gc::grid::COLUMNS * t_position_x + t_position_y];
}

