#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Global.h"
#include "Node.h"

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
        void setOutline(bool t_isOutlineVisible);

        Node* getNodeAtPosition(uint32_t t_positionX, uint32_t t_positionY);
        Node* getSelectedNode();

    private:
        void initNodes();

        void setWindowNodes(sf::RenderWindow *t_window);

    private:
        sf::RenderWindow *m_window;

        Node *m_grid;
};
