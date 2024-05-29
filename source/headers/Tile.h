#pragma once
#include "Global.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Tile{
    private:
        sf::RenderWindow* m_Window;;
        sf::RectangleShape m_Tile;
        gc::tile::Type m_Type;
        bool m_isVisted; 

    public:
        Tile(sf::RenderWindow* window);
        gc::tile::Type getType();
        void draw();
        void setType(gc::tile::Type type);
        void setPosition(float position_x, float position_y);
        void setWindow(sf::RenderWindow* window);
        bool isVisited();
};
