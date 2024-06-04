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
        bool isVisited();
        bool isVisible();
        bool isWallVisible(gc::wall::Position t_wallPosition);
        void destroyWall(gc::wall::Position t_wallPosition);
        void destroyAllWalls();
        void recreateAllWalls();
        void setOutline();
        void setVisible(bool t_isVisible);
        void setVisited(bool t_isVisited);
        void setState(gc::node::State t_type);
        void setGridIndex(float t_positionX, float t_positionY);
        void setPosition(float t_positionX, float t_positionY);
        void setWindow(sf::RenderWindow *t_window);
        void setPredecessor(Node *t_predecessor);
        Node* getPredecessor();
        gc::node::State getState();
        std::pair<int, int> getGridPosition();

    private:
        sf::RenderWindow *m_window;;
        sf::RectangleShape m_node;
        sf::Texture m_texture;
        gc::node::State m_state;
        std::pair<int, int> m_gridPosition;
        Wall *m_walls;
        Node *m_predecessor;
        bool m_isVisited;
        bool m_isVisible;

};
