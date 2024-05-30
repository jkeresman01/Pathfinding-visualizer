#include "headers/Grid.h"
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Time.hpp>
#include <algorithm>

Grid::Grid(sf::RenderWindow* window){
    this->m_Window = window;
    this->m_Grid = new Node[gc::grid::ROWS * gc::grid::COLUMNS];
    initilaze_nodes();
}

Grid::~Grid(){
    delete[] m_Grid;
}

void Grid::draw(){
    std::for_each(m_Grid, m_Grid + gc::grid::ROWS * gc::grid::COLUMNS, [](Node &n){ n.draw();});
}

void Grid::initilaze_nodes(){
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

Node* Grid::getNode(int position_x, int position_y){
    return &m_Grid[gc::grid::COLUMNS * position_x + position_y];
}

