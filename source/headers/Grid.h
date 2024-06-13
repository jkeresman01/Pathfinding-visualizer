#pragma once

#include "Global.h"
#include "Node.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Grid
{
    public:
        Grid();
        ~Grid();
        void draw();
        void removeWalls();
        void createWalls();
        void restoreVisitedNodes();
        void setWindow(sf::RenderWindow *t_window);
        Node* getNodeAtPosition(const int t_positionX, const int t_positionY);

    private:
        void initilazeNodes();

    private:
        sf::RenderWindow *m_window;
        Node *m_grid;

};
