#pragma once
#include "Global.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Tile{
    private:
        sf::RenderWindow* m_Winodw;;
        sf::RectangleShape m_Tile;
        gc::TILE::TYPE m_Type;
        bool m_isVisted; 

    public:
        Tile(sf::RenderWindow* window);
        gc::TILE::TYPE getType();
        void draw();
        void setType(gc::TILE::TYPE);
        void move(float position_x, float position_y);
        bool isVisited();
};
