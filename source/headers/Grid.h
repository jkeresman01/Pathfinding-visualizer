#pragma once

#include "Global.h"
#include "Node.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Grid
{
    public:
        Grid(sf::RenderWindow *t_window);
        ~Grid();
        void draw();
        void removeWalls();
        void restoreVisitedNodes();
        Node *getNodeAtPosition(int t_positionX, int t_positionY);

    private:
        void initilazeNodes();

    private:
        sf::RenderWindow *m_window;
        Node *m_grid;

};
