#pragma once

#include "Global.h"
#include "Node.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Grid{
    public:
        Grid(sf::RenderWindow* t_window);
        ~Grid();
        void draw();
        void removeWalls();
        void restoreVisitedNodes();
        Node* getNodeAtPosition(int t_position_x, int t_position_y);

    private:
        void initilazeNodes();

    private:
        sf::RenderWindow* m_Window;
        Node* m_Grid;

};
