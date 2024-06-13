#pragma once

#include "Global.h"
#include "Wall.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Node
{
    public:
        Node();
        ~Node();
        void draw();
        bool isVisited() const;
        bool isVisible() const;
        bool isWallVisible(const gc::wall::Position t_wallPosition) const;
        void destroyWall(const gc::wall::Position t_wallPosition);
        void destroyAllWalls();
        void recreateAllWalls();
        void setOutline(const bool t_isOutlineVisible);
        void setVisible(const bool t_isVisible);
        void setVisited(const bool t_isVisited);
        void setType(const gc::node::Type t_type);
        void setGridIndex(const float t_positionX, const float t_positionY);
        void setPosition(const float t_positionX, const float t_positionY);
        void setWindow(sf::RenderWindow *t_window);
        void setPredecessor(Node *t_predecessor);
        Node* getPredecessor() const;
        gc::node::Type getType() const;
        std::pair<int, int> getGridPosition() const;

    private:
        sf::RenderWindow *m_window;;
        sf::RectangleShape m_node;
        sf::Texture m_texture;
        gc::node::Type m_type;
        std::pair<int, int> m_gridPosition;
        Wall *m_walls;
        Node *m_predecessor;
        bool m_isVisited;
        bool m_isVisible;

};
