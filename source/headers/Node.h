#pragma once

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "Global.h"
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
        bool isWallVisible(const wall::Position t_wallPosition) const;

        void destroyWall(const wall::Position t_wallPosition);

        void destroyWalls();
        void createWalls();

        void setOutline(bool t_isOutlineVisible);
        void setVisible(bool t_isVisible);
        void setVisited(bool t_isVisited);

        void setType(const node::Type &t_type);

        void setGridIndex(float t_positionX, float t_positionY);
        void setPosition(float t_positionX, float t_positionY);

        void setDistance(uint32_t t_distance);
        void setPredecessor(Node *t_predecessor);
        void setWindow(sf::RenderWindow *t_window);

        Node* getPredecessor() const;
        uint32_t getDistance() const;
        std::pair<int, int> getGridPosition() const;
        node::Type getType() const;

    private:
        void drawWalls();
        void rotateWalls();

        void setWallPosition(float t_positionX, float t_positionY);
        void setWindowWalls(sf::RenderWindow *t_window);

    private:
        sf::RenderWindow *m_window;;
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

} // pfv

