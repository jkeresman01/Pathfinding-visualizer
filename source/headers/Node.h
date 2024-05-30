#pragma once
#include "Global.h"
#include "Wall.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Node{
    private:
        sf::RenderWindow* m_Window;;
        sf::RectangleShape m_Node;
        gc::node::State m_State;
        std::pair<int, int> m_GridIndex;
        bool m_IsVisited;
        Wall walls[4];

    public:
        Node();
        void draw();
        bool isVisited();
        gc::node::State getState();
        std::pair<int, int> getGridIndex();
        void setColor(sf::Color color);
        void setState(gc::node::State type);
        void setGridIndex(float position_x, float position_y);
        void setPosition(float position_x, float position_y);
        void setWindow(sf::RenderWindow* window);
};
