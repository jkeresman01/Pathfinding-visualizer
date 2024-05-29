#pragma once
#include "Global.h"
#include "Tile.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Grid{
    private:
        sf::RenderWindow* m_Window;
        Tile* m_Grid[gc::grid::ROWS][gc::grid::COLUMNS];

    private:
        void initilaze_tiles();

    public:
        Grid(sf::RenderWindow* window);
        ~Grid();
        void draw();
};
