#pragma once

#include <stack>
#include <vector>
#include <queue>

#include <SFML/Graphics/RenderWindow.hpp>

#include "Grid.h"
#include "Legend.h"
#include "Node.h"
#include "NodeComparator.h"
#include "Menu.h"
#include "PfvConstants.h"

namespace pfv
{

class PathFindingVisulizer
{
    public:
        PathFindingVisulizer();

        void run();
        
    private:
        sf::RenderWindow m_window;

        app::Scene m_currentScene;
        app::Algorithm m_algorithm;

        Grid m_grid;
        Menu m_menu;
        Legend m_legend;

        Node *m_start;
        Node *m_end;

        std::stack<Node*> m_mazeVisitedNodes;
        std::stack<Node*> m_dfsVisitedNodes;
        std::queue<Node*> m_bfsVisitedNodes;
        std::priority_queue<Node*,
                            std::vector<Node*>,
                            NodeComp> m_dijsktraVisitedNodes;

        uint32_t m_numberOfVisitedNodes;

        bool m_isMazeFinised;
        bool m_isTargetReached;
        bool m_isPathCreated;
        bool m_isGridResetDone;
};
    
} // pfv
