#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "PfvConstants.h"
#include "Wall.h"

namespace pfv
{

class Node
{
  public:
    Node();
    ~Node();

    void render(sf::RenderWindow &window) const;

    void destroyWall(wall::Position wallPosition);

    bool isVisited() const;
    bool isVisible() const;
    bool isWallVisible(wall::Position wallPosition) const;

    void setOutline(bool isOutlineVisible);
    void setVisible(bool isVisible);
    void setVisited(bool isVisited);

    void setType(const node::Type &type);
    void setGridIndex(float positionX, float positionY);
    void setPosition(float positionX, float positionY);
    void setDistance(uint32_t distance);
    void setPredecessor(Node *predecessor);

    Node *getPredecessor() const;
    uint32_t getDistance() const;
    std::pair<int, int> getGridPosition() const;
    node::Type getType() const;

  private:
    void createWalls();
    void destroyWalls();

  private:
    sf::RectangleShape m_node;
    Wall *m_walls;
    Node *m_predecessor;
    std::pair<int, int> m_gridPosition;
    uint32_t m_distance;
    node::Type m_type;

    bool m_isVisited;
    bool m_isVisible;
};

} // namespace pfv
