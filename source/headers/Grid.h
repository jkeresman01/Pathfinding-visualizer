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
        void resetDistanceValues();
        void setWindow(sf::RenderWindow *t_window);
        void setOutline(const bool t_isOutlineVisible);
        Node* getNodeAtPosition(const int t_positionX, const int t_positionY);
        Node* getSelectedNode();

    private:
        void initilazeNodes();

    private:
        sf::RenderWindow *m_window;
        Node *m_grid;

};
