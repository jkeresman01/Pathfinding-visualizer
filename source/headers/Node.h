#pragma once

#include "Global.h"
#include "Wall.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Node{
    private:
        sf::RenderWindow* m_Window;;
        sf::RectangleShape m_Node;
        sf::Texture m_Texture;
        gc::node::State m_State;
        std::pair<int, int> m_GridIndex;
        Wall* m_Walls;
        Node* m_Predecessor;
        bool m_IsVisited;
        bool m_IsVisible;

    public:
        Node();
        ~Node();
        void draw();
        bool isVisited();
        bool isVisible();
        bool isWallVisible(gc::wall::Position wall_position);
        Node* getPredecessor();
        gc::node::State getState();
        std::pair<int, int> getGridIndex();
        void setVisited(bool is_visited);
        void destroyWall(gc::wall::Position wall_position);
        void recreateAllWalls();
        void destroyAllWalls();
        void setPredecessor(Node* parent);
        void setOutline();
        void setVisible(bool is_visible);
        void setState(gc::node::State type);
        void setGridIndex(float position_x, float position_y);
        void setPosition(float position_x, float position_y);
        void setWindow(sf::RenderWindow* window);
};
