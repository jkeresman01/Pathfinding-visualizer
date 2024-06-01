#pragma once
#include "Global.h"
#include "Node.h"
#include <SFML/Graphics/RenderWindow.hpp>

class Grid{
    private:
        sf::RenderWindow* m_Window;
        Node* m_Grid;

    private:
        void initilazeNodes();

    public:
        Grid(sf::RenderWindow* window);
        ~Grid();
        void restoreVisitedNodes();
        void draw();
        void removeWalls();
        Node* getNode(int position_x, int position_y);
};
