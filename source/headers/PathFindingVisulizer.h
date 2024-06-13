#pragma once

#include "Global.h"
#include "Grid.h"
#include "Legend.h"
#include "Node.h"
#include "Menu.h"

#include <SFML/Graphics/RenderWindow.hpp>

class PathFindingVisulizer
{
    public:
        PathFindingVisulizer();
        void run();
        
    private:
        sf::RenderWindow m_window;
        gc::tool::Scene m_currentScene;
        Grid m_grid;
        Menu m_menu;
        Legend m_legend;
        Node *m_start;
        Node *m_end;;
};
