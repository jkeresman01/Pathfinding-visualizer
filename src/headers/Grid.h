#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "Node.h"
#include "PfvConstants.h"

namespace pfv
{

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

    void setWindow(sf::RenderWindow *window);
    void setOutline(bool isOutlineVisible);

    Node *getNodeAtPosition(uint32_t positionX, uint32_t positionY);
    Node *getSelectedNode();

  private:
    void initNodes();

    void setWindowNodes(sf::RenderWindow *window);

  private:
    sf::RenderWindow *m_window;

    Node *m_grid;
};

} // namespace pfv
