#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "PfvConstants.h"
#include "Wall.h"

namespace pfv
{

class Node
{
  public:
    Node();
    ~Node();

    void draw();

    bool isVisited() const;
    bool isVisible() const;
    bool isWallVisible(const wall::Position &wallPosition) const;

    void destroyWall(const wall::Position &wallPosition);

    void setOutline(bool isOutlineVisible);
    void setVisible(bool isVisible);
    void setVisited(bool isVisited);

    void setType(const node::Type &type);

    void setGridIndex(float positionX, float positionY);
    void setPosition(float positionX, float positionY);

    void setDistance(uint32_t distance);
    void setPredecessor(Node *predecessor);
    void setWindow(sf::RenderWindow *window);

    Node *getPredecessor() const;
    uint32_t getDistance() const;
    std::pair<int, int> getGridPosition() const;
    node::Type getType() const;

  private:
    void drawWalls();
    void rotateWalls();
    void destroyWalls();
    void createWalls();

    void setWallPosition(float positionX, float positionY);
    void setWindowWalls(sf::RenderWindow *window);

  private:
    sf::RenderWindow *m_window;
    sf::RectangleShape m_node;
    sf::Texture m_texture;

    Wall *m_walls;
    Node *m_predecessor;

    std::pair<int, int> m_gridPosition;
    uint32_t m_distance;

    node::Type m_type;

    bool m_isVisited;
    bool m_isVisible;
};

} // namespace pfv
