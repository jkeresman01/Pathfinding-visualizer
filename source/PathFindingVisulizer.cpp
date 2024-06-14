#include "headers/BreadthFirstSearch.h"
#include "headers/GetSelectedNode.h"
#include "headers/DepthFirstSearch.h"
#include "headers/GetSelectedNode.h"
#include "headers/Global.h"
#include "headers/PathFindingVisulizer.h"
#include "headers/RecreatePath.h"
#include "headers/RecursiveBacktracking.h"

#include <ctime>

/*
 *
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 * NOT BAKED YET
 *
 */

PathFindingVisulizer::PathFindingVisulizer() 
    : m_window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), ""),
    m_start(nullptr), m_end(nullptr), m_currentScene(gc::tool::Scene::MENU),
    m_isTargetReached(false), m_numberOfVisitedNodes(0), m_algorithm(gc::tool::Algorithm::NOT_SELECTED)
{
    m_window.setPosition(sf::Vector2i(gc::screen::POSITION_X, gc::screen::POSITION_Y));
    m_window.setFramerateLimit(gc::tool::FRAMES_PER_SECOND);
    m_grid.setWindow(&m_window);
    m_menu.setWindow(&m_window);
    m_legend.setWindow(&m_window);
    srand(time(nullptr));
}

void PathFindingVisulizer::run()
{

    while (m_window.isOpen())
    {
        sf::Event event;
        while (m_window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }

            //------------------------      MENU LOGIC    ------------------------------------//

            if(m_currentScene == gc::tool::Scene::MENU)
            {
                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Down){
                    m_menu.moveDown();
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Up){
                    m_menu.moveUp();
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Return)
                {
                    if(m_menu.getSelectedItem() == gc::menu::MAZE_SOLVING)
                    {
                        m_currentScene = gc::tool::Scene::MAZE_SOLVING;
                        m_grid.restoreVisitedNodes();
                        m_grid.setOutline(false);
                        m_grid.createWalls();
                        m_mazeVisitedNodes.push(m_grid.getNodeAtPosition(0, 0));
                        m_numberOfVisitedNodes = 1;
                    }

                    if(event.type == sf::Event::KeyReleased and m_menu.getSelectedItem() == gc::menu::WALL_BUILDING)
                    {
                        m_currentScene = gc::tool::Scene::WALL_BUILDING;
                        m_grid.restoreVisitedNodes();
                        m_grid.removeWalls();
                        m_grid.setOutline(true);
                    }

                    if(event.type == sf::Event::KeyReleased and m_menu.getSelectedItem() == gc::menu::EXIT)
                    {
                        m_window.close();
                    }
                }
            }

            if(m_currentScene == gc::tool::Scene::WALL_BUILDING || m_currentScene == gc::tool::Scene::MAZE_SOLVING)
            {
                
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Enter)
                {
                    Node* currentSelectedCell = getSelectedNode(m_grid, &m_window);

                    if(currentSelectedCell != nullptr)
                    {
                        currentSelectedCell->setType(gc::node::WALL);
                    }
                }

                if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space)
                {

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        if(m_start != nullptr)
                        {
                            m_start->setType(gc::node::EMPTY);
                        }

                        m_start = getSelectedNode(m_grid, &m_window);

                        if(m_start != nullptr)
                        {
                            m_start->setType(gc::node::START);
                        }
                    }

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                    {
                        if(m_end != nullptr)
                        {
                            m_end->setType(gc::node::EMPTY);
                        }
                        m_end = getSelectedNode(m_grid, &m_window);

                        if(m_end != nullptr)
                        {
                            m_end->setType(gc::node::TARGET);
                        }
                    }

                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Escape)
                {
                    m_currentScene = gc::tool::Scene::MENU;

                    while (!m_bfsVisitedNodes.empty()) {
                        m_bfsVisitedNodes.pop();
                    }

                    while (!m_dfsVisitedNodes.empty()) {
                        m_dfsVisitedNodes.pop();
                    }

                    m_algorithm = gc::tool::Algorithm::NOT_SELECTED;
                    m_grid.restoreVisitedNodes();
                    m_isTargetReached = false;
                    m_isPathCreated = false;
                    m_numberOfVisitedNodes = 1;
                    m_start = nullptr;
                    m_end = nullptr;
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::R)
                {

                    while (!m_bfsVisitedNodes.empty()) {
                        m_bfsVisitedNodes.pop();
                    }

                    while (!m_dfsVisitedNodes.empty()) {
                        m_dfsVisitedNodes.pop();
                    }

                    m_algorithm = gc::tool::Algorithm::NOT_SELECTED;
                    m_grid.restoreVisitedNodes();
                    m_isTargetReached = false;
                    m_isPathCreated = false;
                    m_start = nullptr;
                    m_end = nullptr;
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::D)
                {
                    m_algorithm = gc::tool::Algorithm::DFS;
                    m_dfsVisitedNodes.push(m_start);
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::B)
                {
                    m_algorithm = gc::tool::Algorithm::BFS;
                    m_bfsVisitedNodes.push(m_start);
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::J)
                {
                    //DIJKSTA
                }
                
            }

        }


        //------------------------      LOGICAL LOGIC    ------------------------------------//


        //------------------------      DRAW STUFF    ------------------------------------//

        m_window.clear(sf::Color(3, 11, 28));

        if(m_currentScene == gc::tool::MENU)
        {
            m_menu.draw();
        }

        if(m_currentScene == gc::tool::MAZE_SOLVING)
        {
            if(m_numberOfVisitedNodes <= gc::grid::ROWS * gc::grid::COLUMNS)
            {
                drawMaze(m_grid, m_mazeVisitedNodes, m_numberOfVisitedNodes);
            }
            else 
            {
                if(!m_isTargetReached)
                {
                    if(m_algorithm == gc::tool::NOT_SELECTED)
                    {
                        m_grid.restoreVisitedNodes();
                    }

                    if(m_algorithm == gc::tool::DFS)
                    {
                        dfs(m_grid, m_start, m_window, m_isTargetReached);
                    }

                    if(m_algorithm == gc::tool::Algorithm::BFS)
                    {
                        bfs(m_grid, m_bfsVisitedNodes, m_isTargetReached);
                    }
                }
                else if(!m_isPathCreated)
                {
                    recreatePath(m_end, m_grid, &m_window);
                    m_isPathCreated = true;
                }
           }

            m_grid.draw();
            m_legend.draw();
        }

        if(m_currentScene == gc::tool::WALL_BUILDING)
        {
            m_grid.draw();
            m_legend.draw();

            if(!m_isTargetReached)
            {
                if(m_algorithm == gc::tool::DFS)
                {
                    dfs(m_grid, m_start, m_window, m_isTargetReached);
                }

                if(m_algorithm == gc::tool::Algorithm::BFS)
                {
                    bfs(m_grid, m_bfsVisitedNodes, m_isTargetReached);
                }
            }
            else if(!m_isPathCreated)
            {
                recreatePath(m_end, m_grid, &m_window);
                m_isPathCreated = true;
            }

        }

        m_window.display();

    }
}
