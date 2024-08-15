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

    void render(sf::RenderWindow &window) const;

    void removeWalls();
    void createWalls();
    void restoreVisitedNodes();
    void resetDistanceValues();

    void setOutline(bool isOutlineVisible);

    Node *getNodeAtPosition(uint32_t positionX, uint32_t positionY) const;
    Node *getSelectedNode(sf::RenderWindow &window) const;

  private:
    Node *m_grid;
};

} // namespace pfv
