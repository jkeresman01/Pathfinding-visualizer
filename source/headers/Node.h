#pragma once

#include "Global.h"
#include "Wall.h"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>

class Node{
    public:
        Node();
        ~Node();
        void draw();
        bool isVisited();
        bool isVisible();
        bool isWallVisible(gc::wall::Position t_wall_position);
        Node* getPredecessor();
        gc::node::State getState();
        std::pair<int, int> getGridIndex();
        void setVisited(bool t_is_visited);
        void destroyWall(gc::wall::Position t_wall_position);
        void recreateAllWalls();
        void destroyAllWalls();
        void setPredecessor(Node* t_predecessor);
        void setOutline();
        void setVisible(bool t_is_visible);
        void setState(gc::node::State type);
        void setGridIndex(float t_position_x, float t_position_y);
        void setPosition(float t_position_x, float t_position_y);
        void setWindow(sf::RenderWindow* t_window);

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

};
