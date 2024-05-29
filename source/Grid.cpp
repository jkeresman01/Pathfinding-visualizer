#include "headers/Grid.h"

Grid::Grid(sf::RenderWindow* window){
    this->m_Window = window;
    initilaze_tiles();
}

Grid::~Grid(){
    for(int i = 0; i < gc::grid::ROWS; ++i){
        for(int j = 0; j < gc::grid::COLUMNS; ++j){
                delete m_Grid[i][j];
        }
    }
}

void Grid::draw(){
    for(int i = 0; i < gc::grid::ROWS; ++i){
        for(int j = 0; j < gc::grid::COLUMNS; ++j){
                m_Grid[i][j]->draw();
        }
    }
}

void Grid::initilaze_tiles(){
    for(int i = 0; i < gc::grid::ROWS; ++i){
        for(int j = 0; j < gc::grid::COLUMNS; ++j){
            m_Grid[i][j] = new Tile(m_Window);
            m_Grid[i][j]->setPosition(
                    gc::tile::START_POSITION_X + (j * gc::tile::WIDTH), 
                    gc::tile::START_POSITION_Y + (i * gc::tile::HEIGHT));
        }
    } 
}
