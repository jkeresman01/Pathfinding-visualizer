#include "headers/PathFindingVisulizer.h"

#include <ctime>

#include "headers/BreadthFirstSearch.h"
#include "headers/Dijkstra.h"
#include "headers/DepthFirstSearch.h"
#include "headers/PfvConstants.h"
#include "headers/RecreatePath.h"
#include "headers/RecursiveBacktracking.h"

namespace pfv
{

PathFindingVisulizer::PathFindingVisulizer() 
    : m_window(sf::VideoMode(screen::WIDTH, screen::HEIGHT), ""),
    m_start(nullptr),
    m_end(nullptr),
    m_currentScene(app::Scene::MENU),
    m_isGridResetDone(false),
    m_isTargetReached(false),
    m_numberOfVisitedNodes(0),
    m_algorithm(app::Algorithm::NOT_SELECTED)
{
    m_window.setPosition(sf::Vector2i(screen::POSITION_X, screen::POSITION_Y));
    m_window.setFramerateLimit(app::FRAMES_PER_SECOND);

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


            if(m_currentScene == app::Scene::MENU)
            {
                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Down){
                    m_menu.moveDown();
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Up){
                    m_menu.moveUp();
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Return)
                {
                    if(m_menu.getSelectedItem() == menu::MAZE_SOLVING)
                    {
                        m_currentScene = app::Scene::MAZE_SOLVING;
                        m_grid.restoreVisitedNodes();
                        m_grid.setOutline(false);
                        m_grid.createWalls();
                        m_mazeVisitedNodes.push(m_grid.getNodeAtPosition(0, 0));
                        m_numberOfVisitedNodes = 1;
                    }

                    if(event.type == sf::Event::KeyReleased and m_menu.getSelectedItem() == menu::WALL_BUILDING)
                    {
                        m_currentScene = app::Scene::WALL_BUILDING;
                        m_grid.restoreVisitedNodes();
                        m_grid.removeWalls();
                        m_grid.setOutline(true);
                    }

                    if(event.type == sf::Event::KeyReleased and m_menu.getSelectedItem() == menu::EXIT)
                    {
                        m_window.close();
                    }
                }
            }

            if(m_currentScene == app::Scene::WALL_BUILDING or m_currentScene == app::Scene::MAZE_SOLVING)
            {
                
                if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) and event.type == sf::Event::KeyPressed and 
                    event.key.code == sf::Keyboard::Enter and m_currentScene == app::WALL_BUILDING)
                {
                    Node* currentSelectedCell = m_grid.getSelectedNode();

                    if(currentSelectedCell != nullptr)
                    {
                        currentSelectedCell->setType(node::WALL);
                    }
                }

                if(event.type == sf::Event::KeyPressed and event.key.code == sf::Keyboard::Space)
                {

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
                    {
                        if(m_start != nullptr)
                        {
                            m_start->setType(node::EMPTY);
                        }

                        m_start = m_grid.getSelectedNode();

                        if(m_start != nullptr)
                        {
                            m_start->setType(node::START);
                        }
                    }

                    if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Right))
                    {
                        if(m_end != nullptr)
                        {
                            m_end->setType(node::EMPTY);
                        }
                        m_end = m_grid.getSelectedNode();

                        if(m_end != nullptr)
                        {
                            m_end->setType(node::TARGET);
                        }
                    }

                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Escape)
                {
                    m_currentScene = app::Scene::MENU;

                    while (!m_bfsVisitedNodes.empty()) {
                        m_bfsVisitedNodes.pop();
                    }

                    while (!m_dfsVisitedNodes.empty()) {
                        m_dfsVisitedNodes.pop();
                    }

                    while (!m_dijsktraVisitedNodes.empty()) {
                        m_dijsktraVisitedNodes.pop();
                    }

                    m_algorithm = app::Algorithm::NOT_SELECTED;

                    m_grid.restoreVisitedNodes();
                    m_grid.resetDistanceValues();

                    m_isTargetReached = false;
                    m_isPathCreated = false;

                    m_numberOfVisitedNodes = 1;

                    m_start = nullptr;
                    m_end = nullptr;
                    m_isGridResetDone = false;
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::R)
                {

                    while (!m_bfsVisitedNodes.empty()) {
                        m_bfsVisitedNodes.pop();
                    }

                    while (!m_dfsVisitedNodes.empty()) {
                        m_dfsVisitedNodes.pop();
                    }

                    while (!m_dijsktraVisitedNodes.empty()) {
                        m_dijsktraVisitedNodes.pop();
                    }

                    m_algorithm = app::Algorithm::NOT_SELECTED;

                    m_grid.restoreVisitedNodes();
                    m_grid.resetDistanceValues();

                    m_isTargetReached = false;
                    m_isPathCreated = false;

                    m_start = nullptr;
                    m_end = nullptr;
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::D and 
                   m_start != nullptr and m_end != nullptr)
                {
                    m_algorithm = app::Algorithm::DFS;
                    m_dfsVisitedNodes.push(m_start);
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::B and 
                   m_start != nullptr and m_end != nullptr)
                {
                    m_algorithm = app::Algorithm::BFS;
                    m_bfsVisitedNodes.push(m_start);
                }

                if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::J and 
                   m_start != nullptr and m_end != nullptr)
                {
                    m_algorithm = app::Algorithm::DIJKSTRA;
                    m_start->setDistance(0);
                    m_dijsktraVisitedNodes.push(m_start);
                }
            }

        }


        m_window.clear(sf::Color(3, 11, 28));

        if(m_currentScene == app::MENU)
        {
            m_menu.draw();
        }

        if(m_currentScene == app::MAZE_SOLVING)
        {
            if(m_numberOfVisitedNodes <= grid::ROWS * grid::COLUMNS)
            {
                drawMaze(m_grid, m_mazeVisitedNodes, m_numberOfVisitedNodes);
            }
            else if(!m_isGridResetDone)
            {
                m_grid.restoreVisitedNodes();
                m_isGridResetDone = true;
            }
        }

        if(m_currentScene == app::WALL_BUILDING)
        {
            m_grid.draw();
            m_legend.draw();
        }
 
        if(m_currentScene == app::WALL_BUILDING or m_currentScene == app::MAZE_SOLVING)
        {
            if(!m_isTargetReached)
            {
                if(m_algorithm == app::DFS)
                {
                    dfs(m_grid, m_start, m_window, m_isTargetReached, m_legend);
                }

                if(m_algorithm == app::Algorithm::BFS)
                {
                    bfs(m_grid, m_bfsVisitedNodes, m_isTargetReached);
                }

                if(m_algorithm == app::Algorithm::DIJKSTRA)
                {
                    dijkstra(m_grid, m_dijsktraVisitedNodes, m_isTargetReached);
                }
            }
            else if (!m_isPathCreated) 
            {
                recreatePath(&m_window, m_legend, m_end, m_grid);
                m_isPathCreated = true;
            }

            m_grid.draw();
            m_legend.draw();
        }

       m_window.display();

    }
}
    
} // pfv

