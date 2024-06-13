#include "headers/PathFindingVisulizer.h"
#include "headers/Global.h"

#include <ctime>
#include <thread>

PathFindingVisulizer::PathFindingVisulizer() 
    : m_window(sf::VideoMode(gc::screen::WIDTH, gc::screen::HEIGHT), ""),
    m_start(nullptr), m_end(nullptr), m_currentScene(gc::tool::MENU)
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

            if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::Escape)
            {
                m_currentScene = gc::tool::Scene::MENU;
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
                    switch (m_menu.getSelectedItem()) 
                    { 
                        case gc::menu::MAZE_SOLVING:
                            m_currentScene = gc::tool::Scene::MAZE_SOLVING;
                            std::thread mazeDrawinf(drawMaze, );
                            break;

                        case gc::menu::WALL_BUILDING:
                            m_currentScene = gc::tool::Scene::WALL_BUILDING;
                            m_grid.restoreVisitedNodes();
                            m_grid.removeWalls();
                            break;

                        case gc::menu::EXIT:
                            m_window.close();
                            break;
                    }
                }


            //------------------------      LOGICAL LOGIC    ------------------------------------//
                if(m_currentScene == gc::tool::Scene::MAZE_SOLVING || m_currentScene == gc::tool::Scene::WALL_BUILDING)
                {
                    if(event.type == sf::Event::KeyReleased and event.key.code == sf::Keyboard::R){
                        m_grid.removeWalls();
                        m_grid.restoreVisitedNodes();
                    }

                }


            //------------------------      DRAW STUFF    ------------------------------------//

                m_window.clear();

                if(m_currentScene == gc::tool::MENU)
                {
                    m_menu.draw();
                }

                if(m_currentScene == gc::tool::MAZE_SOLVING)
                {
                    m_grid.draw();
                    m_legend.draw();
                }

                if(m_currentScene == gc::tool::WALL_BUILDING)
                {
                    m_grid.draw();
                    m_legend.draw();
                }

                m_window.display();
            }

        }
    }
}
