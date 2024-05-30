#pragma once
#include "Global.h"
#include "Node.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Grid{
    private:
        sf::RenderWindow* m_Window;
        Node* m_Grid;

    private:
        void initilaze_nodes();

    public:
        Grid(sf::RenderWindow* window);
        ~Grid();
        void draw();
        Node getNode(int position_x, int position_y);
};
